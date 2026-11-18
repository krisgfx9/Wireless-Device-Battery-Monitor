#include "../src/taskbar_layout.h"
#include <cassert>

int main() {
    assert(TaskbarFreePosition(800, 100, 0, 1000, 2, {}) == 800);
    // Weather and a speed widget, deliberately in the opposite order to placement.
    const std::vector<RECT> occupied{{660, 0, 760, 48}, {780, 0, 900, 48}};
    assert(TaskbarFreePosition(800, 100, 0, 1000, 2, occupied) == 558);
    assert(TaskbarFreePosition(800, 100, 600, 1000, 2, occupied) == INT_MIN);
    assert(TaskbarFreePosition(558, 100, 0, 1000, 2, occupied) == 558);
    // Secondary display to the left of the primary, including a DPI-scaled gap.
    assert(TaskbarFreePosition(-200, 100, -1920, 0, 4, {{-220, 0, -80, 48}}) == -324);
    assert(TaskbarFreePosition(100, 100, 0, 1000, 2, {{90, 0, 220, 48}}, true) == 222);
    assert(TaskbarFreePosition(900, 100, 0, 1000, 2, {{900, 0, 1000, 48}}, true) == INT_MIN);
    assert(TaskbarFreePosition(800, 100, 0, 1000, 2, {{850, 0, 850, 48}}) == 800);
    // A widget closing returns the strip to its preferred position on the next pass.
    assert(TaskbarFreePosition(800, 100, 0, 1000, 2, {}) == 800);
    // Vertical taskbar: use weather/speed window heights, rather than their widths.
    const std::vector<RECT> vertical{{0, 460, 58, 550}, {0, 600, 58, 680}};
    assert(TaskbarFreePosition(590, 100, 0, 1000, 2, vertical, false, true) == 358);
    assert(TaskbarFreePosition(590, 100, 400, 1000, 2, vertical, false, true) == INT_MIN);
    // The screenshot's narrow gap above the tray cannot hold the battery column and weather.
    assert(TaskbarFreePosition(0, 118, 0, 450, 2, {{0, 72, 58, 98}}, false, true) == INT_MIN);
    assert(TaskbarFreePosition(590, 100, 0, 1000, 2, {}, false, true) == 590);
    assert(TaskbarFreePosition(-410, 100, -1000, 0, 4, {{1900, -420, 1958, -320}}, false, true) == -524);
}
