#pragma once

#include <array>
#include <cstddef>
#include <cstdint>

namespace G435 {

constexpr std::size_t kReportSize = 64;

inline std::uint16_t Crc16Xmodem(const std::uint8_t* data, std::size_t size) {
    std::uint16_t crc = 0;
    for (std::size_t i = 0; i < size; ++i) {
        crc ^= static_cast<std::uint16_t>(data[i]) << 8;
        for (int bit = 0; bit < 8; ++bit)
            crc = (crc & 0x8000) ? static_cast<std::uint16_t>((crc << 1) ^ 0x1021) : static_cast<std::uint16_t>(crc << 1);
    }
    return crc;
}

inline std::array<std::uint8_t, kReportSize> Frame(std::uint8_t command, const std::uint8_t* body, std::size_t bodySize) {
    std::array<std::uint8_t, kReportSize> frame{};
    if (bodySize > kReportSize - 4) return frame;
    frame[0] = command;
    frame[1] = static_cast<std::uint8_t>(bodySize);
    for (std::size_t i = 0; i < bodySize; ++i) frame[4 + i] = body[i];
    std::uint16_t crc = Crc16Xmodem(frame.data(), frame.size());
    frame[2] = static_cast<std::uint8_t>(crc);
    frame[3] = static_cast<std::uint8_t>(crc >> 8);
    return frame;
}

inline int ParseMilliVolts(const std::uint8_t* data, std::size_t size) {
    for (std::size_t i = 0; data && i + 7 < size; ++i) {
        if (data[i] != 0x00 || data[i + 1] != 0x07 || data[i + 2] != 0x00 || data[i + 3] != 0x06 || data[i + 5] != 0x00) continue;
        int mv = data[i + 6] | (data[i + 7] << 8);
        if (mv >= 2500 && mv <= 4500) return mv;
    }
    return -1;
}

inline int Percent(int mv) {
    static constexpr int volts[] = { 4200, 4150, 4100, 4050, 4000, 3950, 3900, 3850, 3800, 3750, 3700, 3650, 3600, 3550, 3500, 3400 };
    static constexpr int percents[] = { 100, 95, 90, 85, 80, 75, 70, 62, 55, 45, 35, 25, 15, 10, 5, 0 };
    if (mv >= volts[0]) return 100;
    if (mv <= volts[15]) return 0;
    for (int i = 0; i < 15; ++i) {
        if (mv >= volts[i + 1]) {
            int span = volts[i] - volts[i + 1];
            int rise = (mv - volts[i + 1]) * (percents[i] - percents[i + 1]);
            return percents[i + 1] + (rise + span / 2) / span;
        }
    }
    return -1;
}

inline int ParseRealtekMilliVolts(const std::uint8_t* data, std::size_t size) {
    for (std::size_t i = 0; data && i + 4 < size; ++i) {
        if (data[i] != 0x06 || data[i + 1] != 0x80 || data[i + 2] != 0x00) continue;
        int mv = data[i + 3] | (data[i + 4] << 8);
        if (mv >= 3000 && mv <= 4500) return mv;
    }
    return -1;
}

inline int RealtekPercent(int mv) {
    static constexpr int volts[] = { 4200, 4100, 4000, 3900, 3800, 3750, 3700, 3650, 3600, 3500, 3300 };
    static constexpr int percents[] = { 100, 90, 80, 65, 50, 40, 30, 20, 10, 5, 0 };
    if (mv >= volts[0]) return 100;
    if (mv <= volts[10]) return 0;
    for (int i = 0; i < 10; ++i) {
        if (mv >= volts[i + 1]) {
            int span = volts[i] - volts[i + 1];
            int rise = (mv - volts[i + 1]) * (percents[i] - percents[i + 1]);
            return percents[i + 1] + (rise + span / 2) / span;
        }
    }
    return -1;
}

}  // namespace G435
