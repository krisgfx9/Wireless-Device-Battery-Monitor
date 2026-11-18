#include <windows.h>
#include <atomic>
#include <cstdio>
#include <cstdlib>
// Use the actual widget implementation and Win32 windows; substitute only discovery
// and the host rendering, so the test never touches a real MyFinder or captures its UI.
static HWND fixtureHost;
static std::atomic<bool> goodFrame{true};
static std::atomic<bool> darkGlyphs{false};
BOOL FixturePrintWindow(HWND, HDC dc, UINT) {
    RECT r{0,0,640,24}; FillRect(dc,&r,(HBRUSH)GetStockObject(darkGlyphs ? WHITE_BRUSH : BLACK_BRUSH));
    if (!goodFrame.load()) return FALSE;
    for (int x=500;x<=620;x+=24) {
        RECT glyph{x,6,x+8,18};FillRect(dc,&glyph,(HBRUSH)GetStockObject(darkGlyphs ? BLACK_BRUSH : WHITE_BRUSH));
    }
    return TRUE;
}
HWND FixtureFindWindow(LPCWSTR cls,LPCWSTR title) {
    if (cls && wcscmp(cls,L"MyFinderApp")==0) return fixtureHost;
    return FindWindowW(cls,title);
}
#define PrintWindow FixturePrintWindow
#define FindWindowW FixtureFindWindow
#include "../src/widget.cpp"
#undef FindWindowW
#undef PrintWindow
void Check(bool ok,const char* message) {
    std::printf("%s: %s\n",ok ? "PASS" : "FAIL",message);std::fflush(stdout);
    if (!ok) std::exit(1);
}
void Pump(int ms) {
    auto end=GetTickCount64()+ms;
    while(GetTickCount64()<end) {
        MSG m;while(PeekMessageW(&m,nullptr,0,0,PM_REMOVE)){TranslateMessage(&m);DispatchMessageW(&m);} Sleep(5);
    }
}
int main() {
    HINSTANCE inst=GetModuleHandleW(nullptr);
    fixtureHost=CreateWindowExW(WS_EX_TOOLWINDOW,L"STATIC",L"MyFinder test host",WS_POPUP,
                               -5000,-5000,640,24,nullptr,nullptr,inst,nullptr);
    Check(fixtureHost!=nullptr,"fixture host created");ShowWindow(fixtureHost,SW_SHOWNOACTIVATE);
    HWND notify=CreateWindowExW(WS_EX_TOOLWINDOW,L"STATIC",L"Fixture notification owner",WS_POPUP,
                               -5000,-5000,1,1,nullptr,nullptr,inst,nullptr);
    Check(notify!=nullptr,"separate application owner created");
    widget::SetMyFinder(true);widget::Create(inst,notify,WM_APP+3,false);
    Pump(1700);widget::Reposition();HWND panel=g_wnd;
    Check(panel && IsWindowVisible(panel),"initial valid layout shows strip");
    RECT fixed{};GetWindowRect(panel,&fixed);
    Check(SendMessageW(panel,WM_NCHITTEST,0,0)==HTCLIENT,"field never reports a titlebar hit");
    SendMessageW(panel,WM_NCLBUTTONDBLCLK,HTCAPTION,0);
    for(WPARAM command:{SC_MAXIMIZE,SC_MINIMIZE,SC_RESTORE,SC_MOVE,SC_SIZE})SendMessageW(panel,WM_SYSCOMMAND,command,0);
    RECT afterCommands{};GetWindowRect(panel,&afterCommands);
    Check(EqualRect(&fixed,&afterCommands)&&IsWindowVisible(panel),"titlebar double-click and system commands cannot resize/hide field");
    RECT initial{};GetWindowRect(panel,&initial);
    Pump(2200);widget::Reposition();RECT refreshed{};GetWindowRect(panel,&refreshed);
    Check(EqualRect(&initial,&refreshed),"independent popup keeps a stable anchor");
    SetWindowPos(fixtureHost,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
    Pump(160);
    Check(!FinderAboveStrip(), "background guard repairs host raise");
    Check(Px(16)==16,"24px MyFinder uses 16px icons regardless of monitor DPI");
    SetWindowPos(fixtureHost,nullptr,0,0,640,36,SWP_NOMOVE|SWP_NOZORDER|SWP_NOACTIVATE);
    Check(Px(16)==24,"icons follow MyFinder height on a larger bar");
    SetWindowPos(fixtureHost,nullptr,0,0,640,24,SWP_NOMOVE|SWP_NOZORDER|SWP_NOACTIVATE);
    ShowOwnedPopups(fixtureHost,FALSE);
    Check(IsWindowVisible(panel),"opening host popups does not hide strip");
    HWND menu=CreateWindowExW(WS_EX_TOOLWINDOW,L"STATIC",L"Fixture menu",WS_POPUP,
                             -5000,-5000,100,100,fixtureHost,nullptr,inst,nullptr);
    Check(menu!=nullptr,"fixture menu created");ShowWindow(menu,SW_SHOWNOACTIVATE);
    SetWindowPos(menu,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
    widget::Reposition();
    Check(GetWindow(panel,GW_OWNER)==nullptr,"GPU field has an independent input queue");
    HWND peer=CreateWindowExW(WS_EX_TOOLWINDOW,L"STATIC",L"Companion strip",WS_POPUP,
                             -5000,-5000,80,24,fixtureHost,nullptr,inst,nullptr);
    ShowWindow(peer,SW_SHOWNOACTIVATE);
    HWND before=GetWindow(panel,GW_HWNDPREV);
    widget::Reposition();
    Check(GetWindow(panel,GW_HWNDPREV)==before,"companion strips do not compete for immediate adjacency");
    DestroyWindow(peer);
    DestroyWindow(menu);
    bool repairedRepeatedly=true;
    for(int i=0;i<12;++i) {
        SetWindowPos(fixtureHost,HWND_TOP,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
        Pump(20);
        for(HWND p=GetWindow(panel,GW_HWNDPREV);p;p=GetWindow(p,GW_HWNDPREV)) if(p==fixtureHost)repairedRepeatedly=false;
    }
    Check(repairedRepeatedly,"repeated raises repair through direct native events");
    SetWindowPos(fixtureHost,HWND_TOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
    widget::Reposition();Pump(160);Check((GetWindowLongPtrW(panel,GWL_EXSTYLE)&WS_EX_TOPMOST),"strip follows topmost host band");
    SetWindowPos(fixtureHost,HWND_NOTOPMOST,0,0,0,0,SWP_NOMOVE|SWP_NOSIZE|SWP_NOACTIVATE);
    widget::Reposition();Pump(160);Check(!(GetWindowLongPtrW(panel,GWL_EXSTYLE)&WS_EX_TOPMOST),"strip leaves topmost band with host");
    darkGlyphs=true;Pump(1300);widget::Reposition();Check(g_light,"dark MyFinder glyphs produce dark strip glyphs");
    widget::SetLightTheme(false);Check(g_light,"Windows dark theme cannot override MyFinder glyph color");
    darkGlyphs=false;Pump(1300);widget::Reposition();Check(!g_light,"light MyFinder glyphs produce light strip glyphs");
    goodFrame=false;Pump(1300);widget::Reposition();
    Check(IsWindowVisible(panel),"temporary failed frame keeps last good layout");
    Pump(3800);widget::Reposition();Check(IsWindowVisible(panel),"visible unchanged host keeps its last valid alignment");
    goodFrame=true;Pump(1500);widget::Reposition();Check(IsWindowVisible(panel),"valid layout recovers");
    ShowWindow(fixtureHost,SW_HIDE);widget::Reposition();
    Pump(450);widget::Reposition();Check(!IsWindowVisible(panel),"sustained host hide hides strip");
    widget::Destroy();Check(!IsWindow(panel),"destroy releases strip window");
    DestroyWindow(notify);DestroyWindow(fixtureHost);std::puts("Visibility lifecycle: all checks passed");
}
