#pragma once
// Pure (I/O-free) parts of the Logitech G435 protocol: "PA" command framing, reply parsing and
// the voltage -> percentage curve. Kept independent of Win32 so captured frames and the error
// handling can be checked without the headset.
// Protocol: github.com/deddroid/logitech-g435-battery (docs/PROTOCOL.md), endes' research.
#include <cstddef>
#include <cstdint>
#include <initializer_list>
#include <vector>

namespace G435 {

// Voltage -> % for the G435 Li-Po cell (4200 mV = 100 %, 3400 mV = 0 %), piecewise-linear.
inline int Percent(int mv) {
    static const int v[] = { 4200, 4150, 4100, 4050, 4000, 3950, 3900, 3850, 3800, 3750, 3700, 3650, 3600, 3550, 3500, 3400 };
    static const int p[] = { 100, 95, 90, 85, 80, 75, 70, 62, 55, 45, 35, 25, 15, 10, 5, 0 };
    constexpr int n = 16;
    if (mv >= v[0]) return p[0];
    for (int i = 1; i < n; i++) {
        if (mv >= v[i]) {
            int span = v[i - 1] - v[i];
            return p[i] + (p[i - 1] - p[i]) * (mv - v[i]) / (span ? span : 1);
        }
    }
    return p[n - 1];
}

// Whether a GET_BATTERY value is a plausible Li-Po voltage (the dongle returns garbage in mode 0).
inline bool IsPlausible(int mv) { return mv >= 2500 && mv <= 4600; }

// GET_BATTERY reply: 07 00 06 <seq|80> 00 <mV lo> <mV hi>. Returns millivolts.
inline bool ParseBattery(const std::uint8_t* data, std::size_t size, int& millivolts) {
    if (!data) return false;
    for (std::size_t i = 0; i + 7 <= size; i++)
        if (data[i] == 0x07 && data[i + 1] == 0x00 && data[i + 2] == 0x06 && (data[i + 3] & 0x80) && data[i + 4] == 0x00) {
            millivolts = (int)(data[i + 5] | (data[i + 6] << 8));
            return true;
        }
    return false;
}

// Wireless-category "get" reply: 02 00 <cmd> <value>. Returns the value.
inline bool ParseRemoteValue(const std::uint8_t* data, std::size_t size, std::uint8_t cmd, int& value) {
    if (!data) return false;
    for (std::size_t i = 0; i + 4 <= size; i++)
        if (data[i] == 0x02 && data[i + 1] == 0x00 && data[i + 2] == cmd) {
            value = (int)data[i + 3];
            return true;
        }
    return false;
}

// Builds a "PA" command: 50 41 <category> <seq> <len> <payload...>.
inline std::vector<std::uint8_t> BuildCommand(std::uint8_t category, std::uint8_t seq, std::uint8_t len,
                                              std::initializer_list<std::uint8_t> payload) {
    std::vector<std::uint8_t> cmd = { 0x50, 0x41, category, seq, len };
    cmd.insert(cmd.end(), payload);
    return cmd;
}

}  // namespace G435
