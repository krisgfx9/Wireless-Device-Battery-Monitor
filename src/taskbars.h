#pragma once
#include <windows.h>
#include <string>
#include <vector>

namespace taskbars {
struct Entry {
    HWND window = nullptr;
    std::wstring id;       // monitor interface identity; independent of menu order
    std::wstring device;   // current Windows display name, e.g. \\.\DISPLAY2
    bool primary = false;
};

// Only actual Explorer taskbar windows, primary first, then display-name order.
std::vector<Entry> Enumerate();
// An empty ID selects the primary taskbar.
const Entry* Find(const std::vector<Entry>& entries, const std::wstring& id);
HMENU CreateMenu(const std::vector<Entry>& entries, const std::wstring& selectedId, UINT firstCommand);
}
