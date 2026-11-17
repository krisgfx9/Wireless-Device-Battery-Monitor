#pragma once
// A small transparent strip on the taskbar, just left of the notification area, showing
// "[icon] 30%  [icon] 93%". Implemented as a layered child window of the taskbar (Shell_TrayWnd).
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
    std::wstring name;       // for the hover flyout
    std::wstring status;     // second line in the flyout, e.g. "Charging · Bluetooth"
};

namespace widget {
// Where the widget sits: right of the Windows app icons (by the tray, the default) or left of them.
// `slot` picks among the free spots on that side, counted outward from the tray / the icons,
// stepping past other apps' taskbar items (0 = the closest free spot).
enum Side : int { SideRight = 0, SideLeft = 1 };

// Creates the widget on the primary taskbar. Clicks are reported by posting `clickMsg` to `notifyWnd`;
// a click-and-hold drag that drops it in a new spot posts `movedMsg` with wParam = side, lParam = slot.
bool Create(HINSTANCE inst, HWND notifyWnd, UINT clickMsg, UINT movedMsg, bool lightTheme);
// Sets the spot (also before Create); moves the widget there.
void SetPlacement(int side, int slot);
// False when the left side cannot be used (Windows 10 taskbar, or icons aligned left).
bool LeftSideAvailable();
void Destroy();
bool Alive();
// The devices to show; hovering the widget lists them in a flyout.
void SetItems(const std::vector<WidgetItem>& items);
void SetLightTheme(bool light);
// Re-checks the taskbar layout and moves the widget if needed; call about once a second.
// Returns false when the taskbar it was attached to is gone.
bool Reposition();
}
