// Include the implementation to check its private layout without adding a public test API.
#include <windows.h>
#include <cwchar>
static DWORD testAlignment = 1;
static LSTATUS WINAPI TestRegGetValueW(HKEY, LPCWSTR, LPCWSTR value, DWORD, LPDWORD, PVOID data, LPDWORD) {
    if (wcscmp(value, L"TaskbarAl") != 0) return ERROR_FILE_NOT_FOUND;
    *static_cast<DWORD*>(data) = testAlignment;
    return ERROR_SUCCESS;
}
#define RegGetValueW TestRegGetValueW
#include "../src/widget.cpp"
#undef RegGetValueW
#include <cassert>

int main() {
    g_items = {{DeviceKind::Mouse, 60}, {DeviceKind::Keyboard, 100}};
    int width = 0, height = 0;
    // Each monitor uses its own orientation, regardless of the primary taskbar.
    g_vertical = false;
    auto column = Layout(60, 1080, width, height);
    assert(width == 60 && height > 0 && height < 1080);
    assert(column[0].py < column[1].py && column[1].py < column[2].py);
    assert(column[2].py < column[3].py);

    g_vertical = true;
    auto row = Layout(1920, 48, width, height);
    assert(height == 48 && width > 0 && width < 1920);
    assert(row[0].px == INT_MIN && row[2].px == INT_MIN);

    // A secondary taskbar can rotate and become narrower while the app is running.
    column = Layout(48, 1920, width, height);
    assert(width == 48 && height > 0 && height < 1920);
    assert(column[0].py < column[2].py);

    // Synthetic taskbar coordinates keep real desktop windows out of this placement check.
    RECT bar{100000, 100000, 100060, 101200};
    Span span;
    span.bar = reinterpret_cast<HWND>(1);
    span.measured = span.hasTasks = true;
    span.start = {100000, 100350, 100060, 100400};
    span.tasksTop = 100410;
    span.tasksBottom = 100800;
    span.widgets = {100000, 100020, 100060, 100060};
    g_spans = {span};
    assert(FreeStripPosition(span.bar, bar, 100820, 100, false, true) == 100062);

    testAlignment = 0;
    assert(FreeStripPosition(span.bar, bar, 100820, 100, false, true) == 100820);
    testAlignment = 1;
    g_spans[0].start.top = 100120;  // no space between weather and Start: keep the tray position
    assert(FreeStripPosition(span.bar, bar, 100820, 100, false, true) == 100820);
    assert(FreeStripPosition(span.bar, bar, 100780, 100, false, true) == INT_MIN);
    g_spans[0].start = {};  // unknown button bounds: do not guess where the top gap ends
    assert(FreeStripPosition(span.bar, bar, 100820, 100, false, true) == 100820);
}
