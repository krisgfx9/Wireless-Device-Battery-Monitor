#include "taskbars.h"
#include <algorithm>
#include <cwchar>

namespace taskbars {
std::vector<Entry> Enumerate() {
    std::vector<Entry> result;
    for (const wchar_t* name : {L"Shell_TrayWnd", L"Shell_SecondaryTrayWnd"}) {
        for (HWND bar = nullptr; (bar = FindWindowExW(nullptr, bar, name, nullptr));) {
            MONITORINFOEXW monitor{};
            monitor.cbSize = sizeof(monitor);
            RECT bounds{};
            if (!GetMonitorInfoW(MonitorFromWindow(bar, MONITOR_DEFAULTTONULL), &monitor) ||
                !GetWindowRect(bar, &bounds) || bounds.right <= bounds.left || bounds.bottom <= bounds.top) continue;
            // EDD_GET_DEVICE_INTERFACE_NAME returns the monitor's persistent device interface.
            // This survives DISPLAYn renumbering and Explorer/taskbar HWND recreation.
            DISPLAY_DEVICEW display{};
            display.cb = sizeof(display);
            std::wstring id = monitor.szDevice;
            if (EnumDisplayDevicesW(monitor.szDevice, 0, &display, EDD_GET_DEVICE_INTERFACE_NAME) && display.DeviceID[0])
                id = display.DeviceID;
            result.push_back({bar, id, monitor.szDevice, (monitor.dwFlags & MONITORINFOF_PRIMARY) != 0});
        }
    }
    std::sort(result.begin(), result.end(), [](const Entry& a, const Entry& b) {
        return a.primary != b.primary ? a.primary : a.device < b.device;
    });
    return result;
}

const Entry* Find(const std::vector<Entry>& entries, const std::wstring& id) {
    for (const auto& entry : entries) {
        if (id.empty() ? entry.primary : !_wcsicmp(entry.id.c_str(), id.c_str()))
            return &entry;
    }
    return nullptr;
}

static std::wstring Label(const Entry& entry, size_t index) {
    std::wstring display = entry.device.substr(entry.device.find_last_of(L'\\') + 1);
    return L"Taskbar " + std::to_wstring(index + 1) + L" - " + display + (entry.primary ? L" (Primary)" : L"");
}

HMENU CreateMenu(const std::vector<Entry>& entries, const std::wstring& selectedId, UINT firstCommand) {
    HMENU menu = CreatePopupMenu();
    if (!menu) return nullptr;
    const Entry* selected = Find(entries, selectedId);
    for (size_t i = 0; i < entries.size(); ++i) {
        AppendMenuW(menu, MF_STRING, firstCommand + (UINT)i, Label(entries[i], i).c_str());
        if (&entries[i] == selected)
            CheckMenuRadioItem(menu, firstCommand, firstCommand + (UINT)i, firstCommand + (UINT)i, MF_BYCOMMAND);
    }
    if (entries.empty()) AppendMenuW(menu, MF_STRING | MF_GRAYED, 0, L"No taskbars available");
    return menu;
}
}
