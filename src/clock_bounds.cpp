#include "clock_bounds.h"
#include <uiautomation.h>
#include <memory>
#include <new>

namespace {

// POD state has no teardown dependency on a callback still finishing during process exit.
SRWLOCK g_lock = SRWLOCK_INIT;
HWND g_taskbar = nullptr;
RECT g_bar{}, g_clock{};
ULONGLONG g_generation = 0, g_requested = 0, g_completed = 0;
bool g_pending = false, g_valid = false;

struct Request { HWND taskbar; RECT bar; ULONGLONG generation; };
template<class T> struct ComPtr {
    T* p = nullptr;
    ~ComPtr() { if (p) p->Release(); }
};

bool ReadClock(const Request& request, RECT& clock) {
    ComPtr<IUIAutomation2> automation;
    if (FAILED(CoCreateInstance(__uuidof(CUIAutomation8), nullptr, CLSCTX_INPROC_SERVER,
                                __uuidof(IUIAutomation2), (void**)&automation.p))) return false;
    automation.p->put_ConnectionTimeout(1000);
    automation.p->put_TransactionTimeout(1000);

    ComPtr<IUIAutomationElement> root;
    if (FAILED(automation.p->ElementFromHandle(request.taskbar, &root.p))) return false;
    ComPtr<IUIAutomationCondition> byClass, byId, condition;
    VARIANT value{};
    value.vt = VT_BSTR;
    value.bstrVal = SysAllocString(L"SystemTray.OmniButton");
    if (!value.bstrVal) return false;
    HRESULT hr = automation.p->CreatePropertyCondition(UIA_ClassNamePropertyId, value, &byClass.p);
    VariantClear(&value);
    if (FAILED(hr)) return false;
    value.vt = VT_BSTR;
    value.bstrVal = SysAllocString(L"SystemTrayIcon");
    if (!value.bstrVal) return false;
    hr = automation.p->CreatePropertyCondition(UIA_AutomationIdPropertyId, value, &byId.p);
    VariantClear(&value);
    if (FAILED(hr) || FAILED(automation.p->CreateAndCondition(byClass.p, byId.p, &condition.p))) return false;

    // On secondary taskbars this is the clock. Do not guess if the provider exposes
    // multiple matching controls (for example after a shell customization).
    ComPtr<IUIAutomationElementArray> matches;
    if (FAILED(root.p->FindAll(TreeScope_Descendants, condition.p, &matches.p))) return false;
    int count = 0;
    if (FAILED(matches.p->get_Length(&count)) || count != 1) return false;
    ComPtr<IUIAutomationElement> element;
    if (FAILED(matches.p->GetElement(0, &element.p))) return false;
    BOOL offscreen = TRUE;
    RECT currentBar{};
    return SUCCEEDED(element.p->get_CurrentIsOffscreen(&offscreen)) && !offscreen &&
           SUCCEEDED(element.p->get_CurrentBoundingRectangle(&clock)) &&
           GetWindowRect(request.taskbar, &currentBar) && EqualRect(&currentBar, &request.bar) &&
           clock.left >= request.bar.left && clock.right <= request.bar.right && clock.right > clock.left &&
           clock.top >= request.bar.top && clock.bottom <= request.bar.bottom && clock.bottom > clock.top;
}

void CALLBACK Refresh(PTP_CALLBACK_INSTANCE, void* context) {
    std::unique_ptr<Request> request(static_cast<Request*>(context));
    RECT clock{};
    bool valid = false;
    // All COM objects are created, used and released on this MTA worker, never on the UI thread.
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);
    if (SUCCEEDED(hr)) {
        valid = ReadClock(*request, clock);
        CoUninitialize();
    }
    AcquireSRWLockExclusive(&g_lock);
    if (g_taskbar == request->taskbar && g_generation == request->generation) {
        g_clock = clock;
        g_valid = valid;
        g_completed = GetTickCount64();
    }
    g_pending = false;
    ReleaseSRWLockExclusive(&g_lock);
}
}

namespace clock_bounds {
bool TryGet(HWND taskbar, const RECT& bar, RECT& clock) {
    // Primary taskbars use TrayNotifyWnd; their generic SystemTrayIcon controls
    // also include other icons, so the UIA clock lookup is restricted to secondary bars.
    wchar_t name[64]{};
    if (!GetClassNameW(taskbar, name, ARRAYSIZE(name)) || lstrcmpW(name, L"Shell_SecondaryTrayWnd")) return false;
    AcquireSRWLockExclusive(&g_lock);
    const ULONGLONG now = GetTickCount64();
    if (g_taskbar != taskbar || !EqualRect(&g_bar, &bar)) {
        g_taskbar = taskbar;
        g_bar = bar;
        ++g_generation;
        g_requested = 0;
        g_valid = false;
    }
    bool available = g_valid && now - g_completed <= 3000;
    if (available) clock = g_clock;
    if (!g_pending && (!g_requested || now - g_requested >= 1000)) {
        g_requested = now;
        auto* request = new (std::nothrow) Request{taskbar, bar, g_generation};
        if (request) {
            g_pending = true;
            if (!TrySubmitThreadpoolCallback(Refresh, request, nullptr)) {
                g_pending = false;
                delete request;
            }
        }
    }
    ReleaseSRWLockExclusive(&g_lock);
    return available;
}

void Invalidate() {
    AcquireSRWLockExclusive(&g_lock);
    g_taskbar = nullptr;
    ++g_generation;
    g_requested = 0;
    g_valid = false;
    ReleaseSRWLockExclusive(&g_lock);
}
}
