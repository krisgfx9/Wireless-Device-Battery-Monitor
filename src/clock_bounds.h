#pragma once
#include <windows.h>

namespace clock_bounds {
// Non-blocking: returns a recent rectangle and schedules a background UIA refresh.
bool TryGet(HWND taskbar, const RECT& bar, RECT& clock);
void Invalidate();
}
