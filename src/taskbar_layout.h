#pragma once
#include <windows.h>
#include <climits>
#include <vector>

// Screen coordinates; move toward the task buttons until the whole strip fits.
inline int TaskbarFreePosition(int position, int length, int minPosition, int maxEnd, int gap,
                               const std::vector<RECT>& occupied, bool rtl = false, bool vertical = false) {
    for (size_t pass = 0; pass <= occupied.size(); ++pass) {
        bool moved = false;
        for (const auto& r : occupied) {
            int start = vertical ? r.top : r.left;
            int end = vertical ? r.bottom : r.right;
            if (end <= start || position >= end + gap || position + length + gap <= start) continue;
            position = rtl ? end + gap : start - length - gap;
            moved = true;
        }
        if (position < minPosition || position > maxEnd - length) return INT_MIN;
        if (!moved) return position;
    }
    return INT_MIN;
}
