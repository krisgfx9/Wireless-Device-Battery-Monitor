#include "../src/bluetooth_refresh.h"

#include <cassert>

int main() {
    constexpr unsigned minute = 60000;
    constexpr std::uint64_t first = 1, second = 2;
    BluetoothRefresh refresh;
    DeviceStatus reading;
    reading.bluetoothAddress = first;
    reading.kind = DeviceKind::Headset;
    assert(BluetoothBatteryPending(reading));

    // A Bluetooth property can be missing, invalid, or still hold an old reading.
    refresh.ConnectionChanged(first, true, 100);
    assert(refresh.NextWait({}, 100, 150, minute) == 950);
    assert(refresh.NextWait({reading}, 1100, 1150, minute) == 1950);
    reading.percent = 255;
    assert(refresh.NextWait({reading}, 3100, 3150, minute) == minute);
    assert(refresh.NextWait({}, 3200, 3200, minute) == minute);

    // Only a live reading from the connecting device cancels its retries. Zero is valid.
    refresh.ConnectionChanged(first, true, 4000);
    refresh.ConnectionChanged(second, true, 4500);
    reading.percent = 0;
    assert(!BluetoothBatteryPending(reading));
    reading.asleep = true;
    assert(refresh.NextWait({reading}, 4500, 4500, minute) == 500);
    reading.asleep = false;
    reading.connected = false;
    DeviceStatus disconnected = reading;
    disconnected.percent = -1;
    assert(!BluetoothBatteryPending(disconnected));
    assert(refresh.NextWait({reading}, 4700, 4700, minute) == 300);
    reading.connected = true;
    assert(refresh.NextWait({reading}, 5000, 5000, minute) == 500);
    refresh.ConnectionChanged(second, false, 5300);
    assert(refresh.NextWait({}, 5300, 5300, minute) == minute);

    // A slow scan can pass both deadlines. Run one follow-up without queueing another.
    refresh.ConnectionChanged(first, true, 6000);
    assert(refresh.NextWait({}, 6000, 9500, minute) == 0);
    assert(refresh.NextWait({}, 9500, 9600, minute) == minute);

    // Reconnecting gets a new retry window. Duplicate connect notifications keep its deadline.
    refresh.ConnectionChanged(first, true, 10000);
    refresh.ConnectionChanged(first, false, 10100);
    refresh.ConnectionChanged(first, true, 10200);
    refresh.ConnectionChanged(first, true, 10300);
    assert(refresh.NextWait({}, 10300, 10300, minute) == 900);
    assert(refresh.NextWait({reading}, 11200, 11200, minute) == minute);
}
