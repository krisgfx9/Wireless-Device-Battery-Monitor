#include "widget.h"

#include <commctrl.h>
#include <dwmapi.h>
#include <uiautomation.h>
#include <algorithm>
#include <atomic>
#include <climits>

namespace {

HWND g_wnd, g_taskbar, g_notify, g_rebar;
UINT g_clickMsg, g_movedMsg;
bool g_light, g_hover;
int g_side = widget::SideRight, g_slot = 0;

// Click-and-hold dragging.
constexpr UINT_PTR kHoldTimer = 1;
constexpr UINT kHoldMs = 300;
bool g_pressed, g_dragging;
POINT g_pressAt;   // screen
int g_grabDx;      // cursor x minus the widget's left edge when the drag began
std::vector<WidgetItem> g_items;
RECT g_lastTray{}, g_lastBar{};
int g_lastW = -1, g_lastDpi = 0, g_lastLeft = INT_MIN;
SIZE g_size{};

const wchar_t* kClass = L"WirelessBatteryWidget";

int Dpi() {
    UINT d = g_taskbar ? GetDpiForWindow(g_taskbar) : 0;
    return d ? (int)d : 96;
}
int Px(int v) { return MulDiv(v, Dpi(), 96); }

wchar_t Glyph(DeviceKind k, bool bluetooth) {
    switch (k) {
        case DeviceKind::Headset:  return 0xE7F6;  // Headphone
        case DeviceKind::Mouse:    return 0xE962;  // Mouse
        case DeviceKind::Keyboard: return 0xE765;  // KeyboardClassic
        case DeviceKind::Gamepad:  return 0xE7FC;  // Game
        default:                   return bluetooth ? 0xE702 : 0xE772;  // Bluetooth / Devices
    }
}
constexpr wchar_t kBolt = 0xE945;            // LightningBolt
constexpr wchar_t kBatteryUnknown = 0xE996;  // shown when there is nothing to display

// Creates a font, falling back when the preferred face is not installed (GDI would silently substitute).
HFONT MakeFont(int px, int weight, const wchar_t* face, const wchar_t* fallback) {
    for (const wchar_t* f : { face, fallback }) {
        HFONT h = CreateFontW(-px, 0, 0, 0, weight, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS,
                              ANTIALIASED_QUALITY, DEFAULT_PITCH, f);
        HDC dc = CreateCompatibleDC(nullptr);
        HGDIOBJ o = SelectObject(dc, h);
        wchar_t got[LF_FACESIZE] = {};
        GetTextFaceW(dc, LF_FACESIZE, got);
        SelectObject(dc, o);
        DeleteDC(dc);
        if (!_wcsicmp(got, f) || f == fallback) return h;
        DeleteObject(h);
    }
    return nullptr;
}

// Grayscale coverage mask of a string, cropped to its ink bounds.
struct Mask {
    int w = 0, h = 0;
    std::vector<BYTE> a;
};

Mask RenderMask(const std::wstring& s, HFONT font) {
    Mask m;
    HDC dc = CreateCompatibleDC(nullptr);
    HGDIOBJ of = SelectObject(dc, font);
    SIZE sz;
    GetTextExtentPoint32W(dc, s.c_str(), (int)s.size(), &sz);
    int W = sz.cx + 8, H = sz.cy + 8;
    BITMAPINFO bi{};
    bi.bmiHeader = { sizeof(BITMAPINFOHEADER), W, -H, 1, 32, BI_RGB };
    void* bits = nullptr;
    HBITMAP bmp = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    HGDIOBJ ob = SelectObject(dc, bmp);
    memset(bits, 0, (size_t)W * H * 4);
    SetBkMode(dc, TRANSPARENT);
    SetTextColor(dc, RGB(255, 255, 255));
    TextOutW(dc, 4, 4, s.c_str(), (int)s.size());
    GdiFlush();
    auto* p = static_cast<DWORD*>(bits);
    int x0 = W, y0 = H, x1 = -1, y1 = -1;
    for (int y = 0; y < H; y++)
        for (int x = 0; x < W; x++)
            if (p[y * W + x] & 0xFF) { x0 = std::min(x0, x); x1 = std::max(x1, x); y0 = std::min(y0, y); y1 = std::max(y1, y); }
    if (x1 >= 0) {
        m.w = x1 - x0 + 1;
        m.h = y1 - y0 + 1;
        m.a.resize((size_t)m.w * m.h);
        for (int y = 0; y < m.h; y++)
            for (int x = 0; x < m.w; x++) m.a[y * m.w + x] = (BYTE)(p[(y0 + y) * W + x0 + x] & 0xFF);
    }
    SelectObject(dc, ob);
    SelectObject(dc, of);
    DeleteObject(bmp);
    DeleteDC(dc);
    return m;
}

struct Rgb { int r, g, b; };

struct Canvas {
    int w, h;
    std::vector<DWORD> px;  // premultiplied BGRA
    Canvas(int w_, int h_) : w(w_), h(h_), px((size_t)w_ * h_, 0) {}
    void Blend(int x, int y, Rgb c, int a) {  // source-over, a = 0..255
        if (x < 0 || y < 0 || x >= w || y >= h || a <= 0) return;
        DWORD d = px[y * w + x];
        int inv = 255 - a;
        int da = d >> 24, dr = (d >> 16) & 255, dg = (d >> 8) & 255, db = d & 255;
        int oa = a + da * inv / 255;
        int orr = c.r * a / 255 + dr * inv / 255;
        int og = c.g * a / 255 + dg * inv / 255;
        int ob = c.b * a / 255 + db * inv / 255;
        px[y * w + x] = ((DWORD)oa << 24) | ((DWORD)orr << 16) | ((DWORD)og << 8) | (DWORD)ob;
    }
    void Draw(const Mask& m, int x, int y, Rgb c, int alpha) {
        for (int j = 0; j < m.h; j++)
            for (int i = 0; i < m.w; i++) Blend(x + i, y + j, c, m.a[j * m.w + i] * alpha / 255);
    }
};

struct Piece { Mask m; Rgb color; int alpha; int gapAfter; };

std::vector<Piece> Layout(int& width) {
    Rgb fg = g_light ? Rgb{ 0, 0, 0 } : Rgb{ 255, 255, 255 };
    Rgb red = g_light ? Rgb{ 196, 30, 40 } : Rgb{ 255, 90, 90 };
    Rgb charge = g_light ? Rgb{ 0, 120, 212 } : Rgb{ 96, 205, 255 };
    HFONT icons = MakeFont(Px(16), FW_NORMAL, L"Segoe Fluent Icons", L"Segoe MDL2 Assets");
    HFONT bolt = MakeFont(Px(11), FW_NORMAL, L"Segoe Fluent Icons", L"Segoe MDL2 Assets");
    HFONT text = MakeFont(Px(13), FW_NORMAL, L"Segoe UI Variable Text", L"Segoe UI");

    std::vector<Piece> out;
    if (g_items.empty()) out.push_back({ RenderMask(std::wstring(1, kBatteryUnknown), icons), fg, 110, 0 });
    for (size_t i = 0; i < g_items.size(); i++) {
        const auto& it = g_items[i];
        int a = it.dim ? 120 : 255;
        Rgb tc = it.low ? red : fg;
        out.push_back({ RenderMask(std::wstring(1, Glyph(it.kind, it.bluetooth)), icons), fg, a, Px(5) });
        std::wstring t = !it.text.empty() ? it.text : it.percent >= 0 ? std::to_wstring(it.percent) + L"%" : L"?";
        out.push_back({ RenderMask(t, text), tc, a, it.charging ? Px(2) : 0 });
        if (it.charging) out.push_back({ RenderMask(std::wstring(1, kBolt), bolt), charge, a, 0 });
        out.back().gapAfter = i + 1 < g_items.size() ? Px(14) : 0;
    }
    DeleteObject(icons);
    DeleteObject(bolt);
    DeleteObject(text);

    width = Px(8) * 2;
    for (auto& p : out) width += p.m.w + p.gapAfter;
    return out;
}

void Paint() {
    if (!g_wnd) return;
    RECT bar;
    GetClientRect(g_taskbar, &bar);
    int H = bar.bottom - bar.top;
    int W = 0;
    auto pieces = Layout(W);
    if (W <= 0 || H <= 0) return;
    Canvas cv(W, H);

    // Nearly transparent background so the whole strip receives mouse input,
    // plus a rounded hover highlight like the system tray icons have.
    for (auto& p : cv.px) p = 0x01000000;
    if (g_hover || g_dragging) {
        int inset = Px(4), r = Px(4);
        Rgb hc = g_light ? Rgb{ 0, 0, 0 } : Rgb{ 255, 255, 255 };
        int ha = g_dragging ? (g_light ? 45 : 55) : (g_light ? 20 : 26);
        for (int y = inset; y < H - inset; y++)
            for (int x = 0; x < W; x++) {
                int dx = x < r ? r - x : (x >= W - r ? x - (W - r - 1) : 0);
                int dy = y < inset + r ? inset + r - y : (y >= H - inset - r ? y - (H - inset - r - 1) : 0);
                if (dx * dx + dy * dy <= r * r) cv.Blend(x, y, hc, ha);
            }
    }

    int x = Px(8);
    for (auto& p : pieces) {
        cv.Draw(p.m, x, (H - p.m.h) / 2, p.color, p.alpha);
        x += p.m.w + p.gapAfter;
    }

    HDC screen = GetDC(nullptr);
    HDC mem = CreateCompatibleDC(screen);
    BITMAPINFO bi{};
    bi.bmiHeader = { sizeof(BITMAPINFOHEADER), W, -H, 1, 32, BI_RGB };
    void* bits = nullptr;
    HBITMAP bmp = CreateDIBSection(mem, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    memcpy(bits, cv.px.data(), (size_t)W * H * 4);
    HGDIOBJ ob = SelectObject(mem, bmp);
    g_size = { W, H };
    SIZE sz{ W, H };
    POINT src{ 0, 0 };
    BLENDFUNCTION bf{ AC_SRC_OVER, 0, 255, AC_SRC_ALPHA };
    UpdateLayeredWindow(g_wnd, screen, nullptr, &sz, mem, &src, 0, &bf, ULW_ALPHA);
    SelectObject(mem, ob);
    DeleteObject(bmp);
    DeleteDC(mem);
    ReleaseDC(nullptr, screen);
    g_lastW = -1;  // force a re-position with the new size
}

// ---- Where the Windows app icons are (UI Automation) -----------------------------------------
// On Windows 11 the Start button, search, Task View and the running apps are XAML inside the taskbar,
// with no windows of their own, so their extent is read by UI Automation (as Narrator sees them).
// That runs on its own thread, only when asked: once when the widget is created, when a drag
// starts and when the side is changed (the widget hugs the tray or the screen edge, so the icons
// only bound the free room and need no watching; ~20 ms of CPU a look). UIA calls into Explorer, and our UI thread shares input
// with the taskbar, so it must never wait on Explorer. Values are screen x, INT_MIN = unknown.

std::atomic<int> g_iconsL{ INT_MIN }, g_iconsR{ INT_MIN }, g_widgetsL{ INT_MIN }, g_widgetsR{ INT_MIN };
std::atomic<bool> g_measureOn{ false };
HANDLE g_measureKick;

const CLSID kClsidCUIAutomation = { 0xff48dba4, 0x60ef, 0x4201, { 0xaa, 0x87, 0x54, 0x10, 0x3e, 0xef, 0x59, 0x4e } };
const IID kIidIUIAutomation = { 0x30cbe57d, 0xd9d0, 0x452a, { 0xab, 0x13, 0x7a, 0xc5, 0xac, 0x48, 0x25, 0xee } };
constexpr PROPERTYID kPropBoundingRect = 30001, kPropControlType = 30003, kPropAutomationId = 30011, kPropClassName = 30012;
constexpr CONTROLTYPEID kButton = 50000;

IUIAutomationCondition* StrCondition(IUIAutomation* uia, PROPERTYID id, const wchar_t* s) {
    VARIANT v;
    VariantInit(&v);
    v.vt = VT_BSTR;
    v.bstrVal = SysAllocString(s);
    IUIAutomationCondition* c = nullptr;
    uia->CreatePropertyCondition(id, v, &c);
    VariantClear(&v);
    return c;
}

IUIAutomationCondition* Or(IUIAutomation* uia, IUIAutomationCondition* a, IUIAutomationCondition* b) {
    IUIAutomationCondition* c = nullptr;
    if (a && b) uia->CreateOrCondition(a, b, &c);
    if (a) a->Release();
    if (b) b->Release();
    return c;
}

template <class F> void EachFound(IUIAutomationElement* under, IUIAutomationCondition* cond, F f) {
    IUIAutomationElementArray* all = nullptr;
    if (!under || !cond || FAILED(under->FindAll(TreeScope_Descendants, cond, &all)) || !all) return;
    int n = 0;
    all->get_Length(&n);
    for (int i = 0; i < n; i++) {
        IUIAutomationElement* e = nullptr;
        if (SUCCEEDED(all->GetElement(i, &e)) && e) {
            f(e);
            e->Release();
        }
    }
    all->Release();
}

DWORD WINAPI MeasureThread(LPVOID) {
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    IUIAutomation* uia = nullptr;
    CoCreateInstance(kClsidCUIAutomation, nullptr, CLSCTX_INPROC_SERVER, kIidIUIAutomation, (void**)&uia);
    IUIAutomationCondition *wanted = nullptr, *taskList = nullptr, *button = nullptr;
    if (uia) {
        wanted = Or(uia, Or(uia, Or(uia, Or(uia, StrCondition(uia, kPropAutomationId, L"WidgetsButton"),
                                             StrCondition(uia, kPropAutomationId, L"StartButton")),
                                        StrCondition(uia, kPropAutomationId, L"TaskViewButton")),
                                StrCondition(uia, kPropAutomationId, L"SearchButton")),
                    StrCondition(uia, kPropClassName, L"Taskbar.TaskListButtonAutomationPeer"));
        taskList = StrCondition(uia, kPropClassName, L"MSTaskListWClass");
        VARIANT v;
        VariantInit(&v);
        v.vt = VT_I4;
        v.lVal = kButton;
        uia->CreatePropertyCondition(kPropControlType, v, &button);
    }
    for (;;) {
        HWND bar = g_measureOn ? FindWindowW(L"Shell_TrayWnd", nullptr) : nullptr;
        IUIAutomationElement* root = nullptr;
        if (uia && bar && SUCCEEDED(uia->ElementFromHandle(bar, &root)) && root) {
            int lo = INT_MAX, hi = INT_MIN, widgetsL = INT_MIN, widgetsR = INT_MIN;
            auto add = [&](IUIAutomationElement* e) {
                RECT r;
                if (FAILED(e->get_CurrentBoundingRectangle(&r)) || r.right <= r.left) return;
                BSTR id = nullptr;
                e->get_CurrentAutomationId(&id);
                bool isWidgets = id && !wcscmp(id, L"WidgetsButton");
                SysFreeString(id);
                if (isWidgets) { widgetsL = r.left; widgetsR = r.right; return; }
                lo = std::min(lo, (int)r.left);
                hi = std::max(hi, (int)r.right);
            };
            EachFound(root, wanted, add);
            if (hi <= lo) {  // Windows 10: the running apps are buttons in the MSTaskListWClass toolbar
                IUIAutomationElement* list = nullptr;
                if (taskList && SUCCEEDED(root->FindFirst(TreeScope_Descendants, taskList, &list)) && list) {
                    EachFound(list, button, add);
                    list->Release();
                }
            }
            root->Release();
            g_iconsL = hi > lo ? lo : INT_MIN;
            g_iconsR = hi > lo ? hi : INT_MIN;
            g_widgetsL = widgetsL;
            g_widgetsR = widgetsR;
        }
        WaitForSingleObject(g_measureKick, INFINITE);
    }
}

void StartMeasuring() {
    g_measureOn = true;
    static bool started = false;
    if (started) {  // a new taskbar (Explorer restarted) or a new side: look again
        SetEvent(g_measureKick);
        return;
    }
    started = true;
    g_measureKick = CreateEventW(nullptr, FALSE, FALSE, nullptr);
    if (HANDLE t = CreateThread(nullptr, 0, MeasureThread, nullptr, 0, nullptr)) {
        SetThreadPriority(t, THREAD_PRIORITY_BELOW_NORMAL);
        CloseHandle(t);
    }
}

// ---- Free spots ---------------------------------------------------------------------------------
// Other things that sit on the taskbar: child windows of Shell_TrayWnd put there by other apps
// (taskbar widgets such as system monitors or media players), and Windows 10's "News and interests"
// (DynamicContent). Explorer's own children (task list, XAML bridge, Start...) are skipped.
// Everything below is in taskbar client coordinates.
struct ObstacleScan {
    DWORD explorerPid;
    int barH;
    std::vector<RECT> rects;
};

BOOL CALLBACK CollectObstacle(HWND h, LPARAM lp) {
    auto* s = reinterpret_cast<ObstacleScan*>(lp);
    if (h == g_wnd || GetParent(h) != g_taskbar || !IsWindowVisible(h)) return TRUE;
    DWORD pid = 0;
    GetWindowThreadProcessId(h, &pid);
    if (pid == s->explorerPid) {
        wchar_t cls[64] = {};
        GetClassNameW(h, cls, 64);
        if (wcsncmp(cls, L"DynamicContent", 14) != 0) return TRUE;
    }
    RECT r;
    if (!GetWindowRect(h, &r) || r.right <= r.left || r.bottom <= r.top) return TRUE;
    POINT tl{ r.left, r.top }, br{ r.right, r.bottom };
    ScreenToClient(g_taskbar, &tl);
    ScreenToClient(g_taskbar, &br);
    if (br.y <= 0 || tl.y >= s->barH) return TRUE;  // not actually in the bar
    s->rects.push_back({ tl.x, tl.y, br.x, br.y });
    return TRUE;
}

int ToClientX(int screenX) {
    POINT p{ screenX, 0 };
    ScreenToClient(g_taskbar, &p);
    return p.x;
}

struct Spot { int side, slot, x; };

// Free spots in [lo, hi) for a strip `w` wide. The right side hugs the right end of each free run,
// counted from `hi` leftward (outward from the tray); the left side hugs the left end, counted from
// `lo` rightward (from the screen edge). Spot x is the strip's left edge.
void SpotsIn(int lo, int hi, int w, int gap, int side, const std::vector<RECT>& obstacles, std::vector<Spot>& out) {
    std::vector<RECT> in;
    for (const RECT& r : obstacles)
        if (r.right > lo && r.left < hi) in.push_back(r);
    int slot = 0;
    if (side == widget::SideRight) {
        std::sort(in.begin(), in.end(), [](const RECT& a, const RECT& b) { return a.right > b.right; });
        int cur = hi;
        auto run = [&](int from) {  // free run [from, cur)
            if (cur - from >= w + 2 * gap) out.push_back({ side, slot++, cur - gap - w });
        };
        for (const RECT& r : in) {
            if (r.right < cur) run(std::max((int)r.right, lo));
            cur = std::min(cur, (int)r.left);
            if (cur <= lo) return;
        }
        run(lo);
    } else {
        std::sort(in.begin(), in.end(), [](const RECT& a, const RECT& b) { return a.left < b.left; });
        int cur = lo;
        auto run = [&](int to) {  // free run [cur, to)
            if (to - cur >= w + 2 * gap) out.push_back({ side, slot++, cur + gap });
        };
        for (const RECT& r : in) {
            if (r.left > cur) run(std::min((int)r.left, hi));
            cur = std::max(cur, (int)r.right);
            if (cur >= hi) return;
        }
        run(hi);
    }
}

bool LeftUsable() {
    if (g_rebar) return false;  // Windows 10: the task buttons fill the space left of the tray
    int l = g_iconsL;
    return l != INT_MIN;
}

// Every spot on both sides, right side first.
std::vector<Spot> AllSpots(int w) {
    std::vector<Spot> out;
    if (!g_taskbar) return out;
    RECT bar;
    GetClientRect(g_taskbar, &bar);
    ObstacleScan s{};
    GetWindowThreadProcessId(g_taskbar, &s.explorerPid);
    s.barH = bar.bottom;
    EnumChildWindows(g_taskbar, CollectObstacle, reinterpret_cast<LPARAM>(&s));
    int gap = Px(2);

    RECT tr;
    HWND tray = FindWindowExW(g_taskbar, nullptr, L"TrayNotifyWnd", nullptr);
    int trayL = tray && GetWindowRect(tray, &tr) ? ToClientX(tr.left) : bar.right;
    int iconsL = g_iconsL, iconsR = g_iconsR, widgetsL = g_widgetsL, widgetsR = g_widgetsR;
    // Windows 11's Widgets button (weather) is XAML too: far left with centred icons, else near the tray.
    if (widgetsL != INT_MIN && widgetsR > widgetsL) s.rects.push_back({ ToClientX(widgetsL), 0, ToClientX(widgetsR), s.barH });
    int rightLo = iconsR != INT_MIN && !g_rebar ? ToClientX(iconsR) : 0;
    SpotsIn(rightLo, trayL, w, gap, widget::SideRight, s.rects, out);
    if (LeftUsable()) SpotsIn(0, ToClientX(iconsL), w, gap, widget::SideLeft, s.rects, out);
    return out;
}

// The x to stand at for the chosen side and slot: that spot, or the farthest one on the side when
// fewer spots are free now, or the other side, or (nothing free anywhere) just left of the tray.
int ChosenX(int w) {
    auto spots = AllSpots(w);
    const Spot* best = nullptr;
    for (int pass = 0; pass < 2 && !best; pass++) {
        int side = pass == 0 ? g_side : (g_side == widget::SideRight ? widget::SideLeft : widget::SideRight);
        for (const Spot& s : spots)
            if (s.side == side && (!best || s.slot <= g_slot)) best = &s;
    }
    if (best) return best->x;
    RECT tr, bar;
    GetClientRect(g_taskbar, &bar);
    HWND tray = FindWindowExW(g_taskbar, nullptr, L"TrayNotifyWnd", nullptr);
    int trayL = tray && GetWindowRect(tray, &tr) ? ToClientX(tr.left) : bar.right;
    return trayL - w - Px(2);
}

// ---- Hover flyout -------------------------------------------------------------------------------
// A Windows 11 style flyout above the widget listing every device: acrylic backdrop (DWM transient
// window material), 8 px rounded corners and the system border and shadow, Segoe UI Variable type,
// and a thin bar per battery. Drawn into a premultiplied 32-bit bitmap so text keeps its alpha on
// the acrylic. Windows 10 (no system backdrop) gets an opaque fill instead.

HWND g_fly;
bool g_flyBackdrop;  // DWM draws the acrylic; we leave the background transparent
int g_flyOutside;    // hide-timer ticks the pointer has been off both widget and flyout
constexpr UINT_PTR kShowTimer = 2, kHideTimer = 3;
constexpr UINT kShowDelayMs = 400;
const wchar_t* kFlyClass = L"WirelessBatteryFlyout";

#ifndef DWMWA_USE_IMMERSIVE_DARK_MODE
#define DWMWA_USE_IMMERSIVE_DARK_MODE 20
#endif
constexpr DWORD kDwmCornerPreference = 33, kDwmSystemBackdrop = 38;
constexpr int kCornerRound = 2, kBackdropTransient = 3;

// Text cell of one line (baseline kept, not cropped to ink), ellipsized to maxW.
Mask TextMask(const std::wstring& s, HFONT font, int maxW) {
    Mask m;
    HDC dc = CreateCompatibleDC(nullptr);
    HGDIOBJ of = SelectObject(dc, font);
    TEXTMETRICW tm;
    GetTextMetricsW(dc, &tm);
    SIZE sz;
    GetTextExtentPoint32W(dc, s.c_str(), (int)s.size(), &sz);
    int W = std::max(1, std::min((int)sz.cx, maxW)), H = tm.tmHeight;
    BITMAPINFO bi{};
    bi.bmiHeader = { sizeof(BITMAPINFOHEADER), W, -H, 1, 32, BI_RGB };
    void* bits = nullptr;
    HBITMAP bmp = CreateDIBSection(dc, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
    HGDIOBJ ob = SelectObject(dc, bmp);
    memset(bits, 0, (size_t)W * H * 4);
    SetBkMode(dc, TRANSPARENT);
    SetTextColor(dc, RGB(255, 255, 255));
    RECT r{ 0, 0, W, H };
    std::wstring copy = s;
    DrawTextW(dc, copy.data(), (int)copy.size(), &r, DT_SINGLELINE | DT_NOPREFIX | DT_END_ELLIPSIS | DT_LEFT | DT_TOP);
    GdiFlush();
    m.w = W;
    m.h = H;
    m.a.resize((size_t)W * H);
    auto* p = static_cast<DWORD*>(bits);
    for (int i = 0; i < W * H; i++) m.a[i] = (BYTE)(p[i] & 0xFF);
    SelectObject(dc, ob);
    SelectObject(dc, of);
    DeleteObject(bmp);
    DeleteDC(dc);
    return m;
}

void FillRound(Canvas& cv, int x, int y, int w, int h, int r, Rgb c, int a) {
    for (int j = 0; j < h; j++)
        for (int i = 0; i < w; i++) {
            int dx = i < r ? r - i : (i >= w - r ? i - (w - r - 1) : 0);
            int dy = j < r ? r - j : (j >= h - r ? j - (h - r - 1) : 0);
            int d2 = dx * dx + dy * dy;
            if (d2 > r * r) continue;
            // soften the edge pixel
            int edge = (r > 0 && d2 > (r - 1) * (r - 1)) ? a / 2 : a;
            cv.Blend(x + i, y + j, c, edge);
        }
}

struct FlyColors { Rgb bg, text, secondary, track, fill, low, charge; int trackA; };

FlyColors Colors() {
    // Fluent tokens: TextFillColorPrimary / Secondary, ControlStrongFill for the rail, accent for the value.
    if (g_light)
        return { { 243, 243, 243 }, { 26, 26, 26 }, { 93, 93, 93 }, { 0, 0, 0 }, { 0, 95, 184 }, { 196, 43, 28 },
                 { 0, 95, 184 }, 40 };
    return { { 44, 44, 44 }, { 255, 255, 255 }, { 200, 200, 200 }, { 255, 255, 255 }, { 96, 205, 255 },
             { 255, 153, 164 }, { 96, 205, 255 }, 45 };
}

// Renders the flyout; returns its size.
SIZE RenderFlyout(std::vector<DWORD>& out) {
    FlyColors c = Colors();
    int pad = Px(16), rowH = Px(52), rowGap = Px(4), iconCol = Px(32), barH = Px(4);
    int W = Px(320);
    HFONT title = MakeFont(Px(14), FW_SEMIBOLD, L"Segoe UI Variable Text Semibold", L"Segoe UI");
    HFONT body = MakeFont(Px(14), FW_NORMAL, L"Segoe UI Variable Text", L"Segoe UI");
    HFONT strong = MakeFont(Px(14), FW_SEMIBOLD, L"Segoe UI Variable Text Semibold", L"Segoe UI");
    HFONT caption = MakeFont(Px(12), FW_NORMAL, L"Segoe UI Variable Small", L"Segoe UI");
    HFONT icons = MakeFont(Px(20), FW_NORMAL, L"Segoe Fluent Icons", L"Segoe MDL2 Assets");
    HFONT bolt = MakeFont(Px(12), FW_NORMAL, L"Segoe Fluent Icons", L"Segoe MDL2 Assets");

    Mask head = TextMask(L"Wireless devices", title, W - 2 * pad);
    int headH = head.h + Px(12);
    int n = (int)g_items.size();
    int H = pad + headH + (n ? n * rowH + (n - 1) * rowGap : Px(24)) + pad;
    Canvas cv(W, H);
    if (!g_flyBackdrop)
        for (auto& p : cv.px) p = 0xFF000000u | ((DWORD)c.bg.r << 16) | ((DWORD)c.bg.g << 8) | (DWORD)c.bg.b;

    cv.Draw(head, pad, pad, c.text, 255);
    int y = pad + headH;
    if (!n) {
        Mask none = TextMask(L"No devices with battery info found", body, W - 2 * pad);
        cv.Draw(none, pad, y, c.secondary, 255);
    }
    for (const auto& it : g_items) {
        int a = it.dim ? 160 : 255;
        // icon, vertically centred on the two text lines
        Mask ic = RenderMask(std::wstring(1, Glyph(it.kind, it.bluetooth)), icons);
        cv.Draw(ic, pad + (Px(20) - ic.w) / 2, y + Px(6) + (Px(34) - ic.h) / 2, c.text, a);

        int tx = pad + iconCol, right = W - pad;
        std::wstring pct = !it.text.empty() ? it.text : it.percent >= 0 ? std::to_wstring(it.percent) + L"%" : L"?";
        Mask pm = TextMask(pct, strong, W);
        int px = right - pm.w;
        Mask bm;
        if (it.charging) {
            bm = RenderMask(std::wstring(1, kBolt), bolt);
            px -= bm.w + Px(4);
        }
        Rgb pc = it.low ? c.low : c.text;
        cv.Draw(pm, px, y + Px(4), pc, a);
        if (it.charging) cv.Draw(bm, right - bm.w, y + Px(4) + (pm.h - bm.h) / 2, c.charge, a);

        Mask nm = TextMask(it.name.empty() ? L"Device" : it.name, body, px - tx - Px(8));
        cv.Draw(nm, tx, y + Px(4), c.text, a);
        if (!it.status.empty()) {
            Mask sm = TextMask(it.status, caption, right - tx);
            cv.Draw(sm, tx, y + Px(4) + nm.h + Px(1), c.secondary, a);
        }

        // battery bar: rail + value
        int by = y + rowH - barH - Px(4), bw = right - tx;
        FillRound(cv, tx, by, bw, barH, barH / 2, c.track, c.trackA);
        if (it.percent >= 0) {
            int fw = std::max(barH, bw * std::min(it.percent, 100) / 100);
            FillRound(cv, tx, by, fw, barH, barH / 2, it.low ? c.low : c.fill, a);
        }
        y += rowH + rowGap;
    }
    for (HFONT f : { title, body, strong, caption, icons, bolt }) DeleteObject(f);
    out.swap(cv.px);
    return { W, H };
}

std::vector<DWORD> g_flyPx;
SIZE g_flySize{};

void PlaceFlyout() {
    if (!g_fly || !g_wnd) return;
    RECT w, bar;
    GetWindowRect(g_wnd, &w);
    GetWindowRect(g_taskbar, &bar);
    MONITORINFO mi{ sizeof(mi) };
    GetMonitorInfoW(MonitorFromWindow(g_taskbar, MONITOR_DEFAULTTOPRIMARY), &mi);
    int gap = Px(12);
    int x = (w.left + w.right) / 2 - g_flySize.cx / 2;
    x = std::max((int)mi.rcWork.left + gap, std::min(x, (int)mi.rcWork.right - gap - (int)g_flySize.cx));
    bool top = bar.top <= mi.rcMonitor.top && bar.bottom < mi.rcMonitor.bottom;  // taskbar at the top
    int y = top ? bar.bottom + gap : bar.top - gap - g_flySize.cy;
    SetWindowPos(g_fly, HWND_TOPMOST, x, y, g_flySize.cx, g_flySize.cy, SWP_NOACTIVATE);
}

void RefreshFlyout() {
    if (!g_fly || !IsWindowVisible(g_fly)) return;
    g_flySize = RenderFlyout(g_flyPx);
    PlaceFlyout();
    InvalidateRect(g_fly, nullptr, FALSE);
}

LRESULT CALLBACK FlyProc(HWND h, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_PAINT: {
            PAINTSTRUCT ps;
            HDC dc = BeginPaint(h, &ps);
            int W = g_flySize.cx, H = g_flySize.cy;
            if (W > 0 && H > 0 && g_flyPx.size() == (size_t)W * H) {
                HDC mem = CreateCompatibleDC(dc);
                BITMAPINFO bi{};
                bi.bmiHeader = { sizeof(BITMAPINFOHEADER), W, -H, 1, 32, BI_RGB };
                void* bits = nullptr;
                HBITMAP bmp = CreateDIBSection(mem, &bi, DIB_RGB_COLORS, &bits, nullptr, 0);
                memcpy(bits, g_flyPx.data(), (size_t)W * H * 4);
                HGDIOBJ ob = SelectObject(mem, bmp);
                BitBlt(dc, 0, 0, W, H, mem, 0, 0, SRCCOPY);
                SelectObject(mem, ob);
                DeleteObject(bmp);
                DeleteDC(mem);
            }
            EndPaint(h, &ps);
            return 0;
        }
        case WM_ERASEBKGND:
            return 1;
        case WM_MOUSEACTIVATE:
            return MA_NOACTIVATE;
        case WM_NCHITTEST:
            return HTCLIENT;
    }
    return DefWindowProcW(h, msg, wp, lp);
}

void ApplyFlyoutTheme() {
    if (!g_fly) return;
    BOOL dark = !g_light;
    DwmSetWindowAttribute(g_fly, DWMWA_USE_IMMERSIVE_DARK_MODE, &dark, sizeof(dark));
}

void ShowFlyout() {
    if (!g_wnd || g_dragging) return;
    if (!g_fly) {
        static bool registered = false;
        if (!registered) {
            WNDCLASSEXW wc{ sizeof(wc) };
            wc.lpfnWndProc = FlyProc;
            wc.hInstance = GetModuleHandleW(nullptr);
            wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
            wc.lpszClassName = kFlyClass;
            registered = RegisterClassExW(&wc) != 0;
        }
        g_fly = CreateWindowExW(WS_EX_TOOLWINDOW | WS_EX_TOPMOST | WS_EX_NOACTIVATE, kFlyClass, L"Wireless devices", WS_POPUP,
                                0, 0, 1, 1, nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);
        if (!g_fly) return;
        int corner = kCornerRound;
        DwmSetWindowAttribute(g_fly, kDwmCornerPreference, &corner, sizeof(corner));
        int backdrop = kBackdropTransient;
        g_flyBackdrop = SUCCEEDED(DwmSetWindowAttribute(g_fly, kDwmSystemBackdrop, &backdrop, sizeof(backdrop)));
        if (g_flyBackdrop) {
            MARGINS m{ -1, -1, -1, -1 };
            DwmExtendFrameIntoClientArea(g_fly, &m);
        }
    }
    ApplyFlyoutTheme();
    g_flySize = RenderFlyout(g_flyPx);
    PlaceFlyout();
    InvalidateRect(g_fly, nullptr, FALSE);
    ShowWindow(g_fly, SW_SHOWNOACTIVATE);
    SetTimer(g_wnd, kHideTimer, 100, nullptr);
}

void HideFlyout() {
    if (g_wnd) {
        KillTimer(g_wnd, kShowTimer);
        KillTimer(g_wnd, kHideTimer);
    }
    if (g_fly) ShowWindow(g_fly, SW_HIDE);
}

bool CursorIn(HWND h) {
    if (!h || !IsWindowVisible(h)) return false;
    POINT c;
    RECT r;
    GetCursorPos(&c);
    GetWindowRect(h, &r);
    return PtInRect(&r, c) != 0;
}

// ---- Window -------------------------------------------------------------------------------------

void BeginDrag() {
    g_dragging = true;
    KillTimer(g_wnd, kHoldTimer);
    HideFlyout();
    RECT r;
    GetWindowRect(g_wnd, &r);
    POINT c;
    GetCursorPos(&c);
    g_grabDx = c.x - r.left;
    g_measureOn = true;
    SetEvent(g_measureKick);  // fresh icon positions for the drop
    Paint();
}

void DragTo(POINT c) {
    RECT bar;
    GetClientRect(g_taskbar, &bar);
    POINT p{ c.x - g_grabDx, 0 };
    ScreenToClient(g_taskbar, &p);
    int x = std::max(0, std::min((int)p.x, (int)bar.right - (int)g_size.cx));
    SetWindowPos(g_wnd, HWND_TOP, x, 0, g_size.cx, g_size.cy, SWP_NOACTIVATE);
}

void Drop() {
    RECT r;
    GetWindowRect(g_wnd, &r);
    int x = ToClientX(r.left);
    const Spot* best = nullptr;
    auto spots = AllSpots(g_size.cx);
    for (const Spot& s : spots)
        if (!best || std::abs(s.x - x) < std::abs(best->x - x)) best = &s;
    if (best) {
        g_side = best->side;
        g_slot = best->slot;
        PostMessageW(g_notify, g_movedMsg, (WPARAM)g_side, (LPARAM)g_slot);
    }
    g_dragging = false;
    g_lastW = -1;  // snap into the spot
    Paint();
    widget::Reposition();
}

LRESULT CALLBACK WidgetProc(HWND h, UINT msg, WPARAM wp, LPARAM lp) {
    switch (msg) {
        case WM_MOUSEMOVE: {
            if (!g_hover) {
                g_hover = true;
                TRACKMOUSEEVENT t{ sizeof(t), TME_LEAVE, h, 0 };
                TrackMouseEvent(&t);
                Paint();
                if (!g_dragging) widget::Reposition();
                if (!g_pressed && !g_dragging && !(g_fly && IsWindowVisible(g_fly))) SetTimer(h, kShowTimer, kShowDelayMs, nullptr);
            }
            POINT c;
            GetCursorPos(&c);
            if (g_pressed && !g_dragging &&
                (abs(c.x - g_pressAt.x) > GetSystemMetrics(SM_CXDRAG) || abs(c.y - g_pressAt.y) > GetSystemMetrics(SM_CYDRAG)))
                BeginDrag();
            if (g_dragging) DragTo(c);
            return 0;
        }
        case WM_MOUSELEAVE:
            g_hover = false;
            if (!g_dragging) {
                Paint();
                widget::Reposition();
            }
            return 0;
        case WM_LBUTTONDOWN:
            HideFlyout();
            g_pressed = true;
            GetCursorPos(&g_pressAt);
            SetCapture(h);
            SetTimer(h, kHoldTimer, kHoldMs, nullptr);
            return 0;
        case WM_TIMER:
            if (wp == kHoldTimer && g_pressed && !g_dragging) BeginDrag();
            if (wp == kShowTimer) {
                KillTimer(h, kShowTimer);
                g_flyOutside = 0;
                if (!g_pressed && !g_dragging && CursorIn(g_wnd)) ShowFlyout();
            }
            if (wp == kHideTimer) {
                // Hide once the pointer has been off both the widget and the flyout for ~300 ms
                // (crossing the gap between them should not close it).
                if (CursorIn(g_wnd) || CursorIn(g_fly)) g_flyOutside = 0;
                else if (++g_flyOutside >= 3) HideFlyout();
            }
            return 0;
        case WM_LBUTTONUP: {
            bool wasDragging = g_dragging;
            g_pressed = false;
            KillTimer(h, kHoldTimer);
            if (wasDragging) Drop();  // before releasing capture, so WM_CAPTURECHANGED sees no drag
            else PostMessageW(g_notify, g_clickMsg, 0, 0);
            if (GetCapture() == h) ReleaseCapture();
            return 0;
        }
        case WM_CAPTURECHANGED:
            if (g_dragging && (HWND)lp != h) {  // capture taken away (Esc, focus change): drop where it is
                g_pressed = false;
                Drop();
            }
            return 0;
        case WM_RBUTTONUP:
            HideFlyout();
            if (!g_dragging) PostMessageW(g_notify, g_clickMsg, 0, 0);
            return 0;
        case WM_MOUSEACTIVATE:
            return MA_NOACTIVATE;
    }
    return DefWindowProcW(h, msg, wp, lp);
}

}  // namespace

namespace widget {

bool Create(HINSTANCE inst, HWND notifyWnd, UINT clickMsg, UINT movedMsg, bool lightTheme) {
    Destroy();
    g_taskbar = FindWindowW(L"Shell_TrayWnd", nullptr);
    if (!g_taskbar || !FindWindowExW(g_taskbar, nullptr, L"TrayNotifyWnd", nullptr)) { g_taskbar = nullptr; return false; }
    RECT tb;
    GetWindowRect(g_taskbar, &tb);
    if (tb.bottom - tb.top > tb.right - tb.left) { g_taskbar = nullptr; return false; }  // vertical taskbar: use tray icons
    // Windows 11's taskbar is a XAML island; on Windows 10 the task buttons live in ReBarWindow32
    // and have to be narrowed so they never slide under the widget.
    g_rebar = FindWindowExW(g_taskbar, nullptr, L"Windows.UI.Composition.DesktopWindowContentBridge", nullptr)
                  ? nullptr
                  : FindWindowExW(g_taskbar, nullptr, L"ReBarWindow32", nullptr);
    g_notify = notifyWnd;
    g_clickMsg = clickMsg;
    g_movedMsg = movedMsg;
    g_light = lightTheme;
    StartMeasuring();

    static bool registered = false;
    if (!registered) {
        WNDCLASSEXW wc{ sizeof(wc) };
        wc.lpfnWndProc = WidgetProc;
        wc.hInstance = inst;
        wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
        wc.lpszClassName = kClass;
        registered = RegisterClassExW(&wc) != 0;
    }
    g_wnd = CreateWindowExW(WS_EX_LAYERED | WS_EX_NOACTIVATE, kClass, L"", WS_CHILD | WS_CLIPSIBLINGS, 0, 0, 1, 1,
                            g_taskbar, nullptr, inst, nullptr);
    if (!g_wnd) { g_taskbar = nullptr; return false; }

    g_lastDpi = Dpi();
    Paint();
    g_lastW = -1;
    Reposition();
    ShowWindow(g_wnd, SW_SHOWNOACTIVATE);
    return true;
}

void Destroy() {
    if (g_rebar && IsWindow(g_rebar) && g_taskbar && IsWindow(g_taskbar)) {
        // Let Explorer lay the task buttons out again over the full width.
        RECT r;
        GetClientRect(g_taskbar, &r);
        PostMessageW(g_taskbar, WM_SIZE, SIZE_RESTORED, MAKELPARAM(r.right, r.bottom));
    }
    g_rebar = nullptr;
    if (g_fly) { DestroyWindow(g_fly); g_fly = nullptr; }
    if (g_wnd) { DestroyWindow(g_wnd); g_wnd = nullptr; }
    g_taskbar = nullptr;
    g_hover = g_pressed = g_dragging = false;
    g_measureOn = false;
}

void SetPlacement(int side, int slot) {
    g_side = side == SideLeft ? SideLeft : SideRight;
    g_slot = std::max(0, slot);
    g_lastW = -1;
    if (g_wnd) StartMeasuring();  // fresh icon positions for the new side
    Reposition();
}

bool LeftSideAvailable() { return !g_rebar; }

bool Alive() { return g_wnd && IsWindow(g_wnd) && g_taskbar && IsWindow(g_taskbar); }

void SetItems(const std::vector<WidgetItem>& items) {
    g_items = items;
    Paint();
    Reposition();
    RefreshFlyout();
}

void SetLightTheme(bool light) {
    g_light = light;
    Paint();
    ApplyFlyoutTheme();
    RefreshFlyout();
}

bool Reposition() {
    if (!Alive()) return false;
    if (g_dragging) return true;  // the pointer places it while dragging
    if (Dpi() != g_lastDpi) { g_lastDpi = Dpi(); Paint(); }
    HWND tray = FindWindowExW(g_taskbar, nullptr, L"TrayNotifyWnd", nullptr);
    if (!tray) return true;
    RECT tr, bar;
    GetWindowRect(tray, &tr);
    GetWindowRect(g_taskbar, &bar);
    // The chosen side and spot, stepping past other apps' taskbar items.
    int left = ChosenX(g_size.cx);

    // Windows 10: Explorer re-expands the task buttons on its own layout passes; narrow them again.
    if (g_rebar && IsWindow(g_rebar)) {
        RECT rr;
        GetWindowRect(g_rebar, &rr);
        POINT tl{ rr.left, rr.top };
        ScreenToClient(g_taskbar, &tl);
        if (tl.x + (rr.right - rr.left) > left && left > tl.x)
            MoveWindow(g_rebar, tl.x, tl.y, left - tl.x, rr.bottom - rr.top, TRUE);
    }

    // Keep us above the taskbar's own content (our sibling windows).
    bool covered = GetWindow(g_wnd, GW_HWNDPREV) != nullptr;
    if (!covered && EqualRect(&tr, &g_lastTray) && EqualRect(&bar, &g_lastBar) && g_lastW == g_size.cx &&
        g_lastLeft == left)
        return true;
    g_lastTray = tr;
    g_lastBar = bar;
    g_lastW = g_size.cx;
    g_lastLeft = left;
    SetWindowPos(g_wnd, HWND_TOP, left, 0, g_size.cx, g_size.cy, SWP_NOACTIVATE | SWP_SHOWWINDOW);
    return true;
}

}  // namespace widget
