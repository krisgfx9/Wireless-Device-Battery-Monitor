#pragma once
// A small transparent strip on the taskbar, just left of the notification area, showing
// "[icon] 30%  [icon] 93%". A layered child of Shell_TrayWnd or Shell_SecondaryTrayWnd.
#include <windows.h>
#include <string>
#include <vector>
#include "devices.h"

struct WidgetItem {
    DeviceKind kind = DeviceKind::Other;
    int  percent  = -1;     // -1 = unknown
    std::wstring text;      // shown instead of the percentage when set (coarse levels like "Low")
    bool charging = false;
    bool dim      = false;  // asleep / stale value
    bool low      = false;
    bool bluetooth = false;  // picks the Bluetooth icon when the device type is unknown
};

namespace widget {
// Selects a taskbar by the monitor identity returned by taskbars::Enumerate().
// Clicks are reported by posting `clickMsg` to `notifyWnd`.
bool Create(HINSTANCE inst, HWND notifyWnd, UINT clickMsg, bool lightTheme, const std::wstring& taskbarId);
void Destroy();
bool Alive();
void SetItems(const std::vector<WidgetItem>& items, const std::wstring& tooltip);
void SetLightTheme(bool light);
// Draws a rounded plate in the taskbar's colours behind the text (kept across Create/Destroy).
void SetBackground(bool on);
// Re-checks the taskbar layout and moves the widget if needed; call about once a second.
// Returns false when the taskbar it was attached to is gone.
bool Reposition();
}
