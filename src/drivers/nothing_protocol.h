#pragma once
// Nothing / CMF earbuds and headphones: battery frames on the "Nothing X" RFCOMM link.
// Kept independent of Win32 so captured frames can be checked without the earbuds.
//
// Frame (little-endian):  55 [ctrl lo][ctrl hi] [cmd] [dir] [len lo][len hi] [seq] [payload...] [crc lo][crc hi]
//   ctrl  = 0x0160 on requests; bit 0x20 set = the frame ends with a CRC
//   dir   = C0 GET, F0 SET (host -> device); 40 response, 70 ack (device -> host)
//   crc   = CRC-16/ARC (poly 0xA001 reflected, init 0xFFFF) over everything before it
// Battery: GET command 0x07 with an empty payload (a read, nothing is changed). Reply payload:
//   [count] then `count` pairs of [component][level], level bits 0..6 = percent, bit 7 = charging
//   component 01 = both earbuds, 02 = left, 03 = right, 04 = case, 06 = headphones
// The case is only reported while it is open or charging, or while an earbud sits in it.
// Sources: EarA (github.com/oneydef/eara, eara/protocol.py; tested on the Nothing Ear (a)) and
// nothing-ear (github.com/pedrordgs/nothing-ear, src/bluetooth/protocol.rs, src/battery/parser.rs).
#include <cstddef>
#include <cstdint>
#include <vector>

namespace Nothing {

constexpr std::uint8_t kSof = 0x55;
constexpr std::uint8_t kCmdBattery = 0x07;
constexpr std::uint8_t kDirGet = 0xC0;
constexpr std::uint8_t kDirSet = 0xF0;

struct Status {
    int left = -1;  // -1 = not reported
    int right = -1;
    int caseLevel = -1;
    int headset = -1;
    bool leftCharging = false, rightCharging = false, caseCharging = false, headsetCharging = false;
};

inline std::uint16_t Crc16Arc(const std::uint8_t* data, std::size_t size) {
    std::uint16_t crc = 0xFFFF;
    for (std::size_t i = 0; i < size; i++) {
        crc ^= data[i];
        for (int b = 0; b < 8; b++) crc = (crc & 1) ? (std::uint16_t)((crc >> 1) ^ 0xA001) : (std::uint16_t)(crc >> 1);
    }
    return crc;
}

// The 10-byte "GET battery" request.
inline std::vector<std::uint8_t> BatteryRequest(std::uint8_t seq) {
    std::vector<std::uint8_t> f = { kSof, 0x60, 0x01, kCmdBattery, kDirGet, 0x00, 0x00, seq };
    std::uint16_t crc = Crc16Arc(f.data(), f.size());
    f.push_back((std::uint8_t)(crc & 0xFF));
    f.push_back((std::uint8_t)(crc >> 8));
    return f;
}

// Fills `out` from a battery payload. Returns true when at least one level was found.
inline bool ParseBattery(const std::uint8_t* p, std::size_t size, Status& out) {
    if (!size) return false;
    Status s;
    bool any = false;
    for (std::size_t i = 0; i < p[0]; i++) {
        std::size_t o = 1 + i * 2;
        if (o + 1 >= size) break;
        int level = p[o + 1] & 0x7F;
        bool charging = (p[o + 1] & 0x80) != 0;
        if (level > 100) continue;
        switch (p[o]) {
            case 0x01: s.left = s.right = level; s.leftCharging = s.rightCharging = charging; break;
            case 0x02: s.left = level; s.leftCharging = charging; break;
            case 0x03: s.right = level; s.rightCharging = charging; break;
            case 0x04: s.caseLevel = level; s.caseCharging = charging; break;
            case 0x06: s.headset = level; s.headsetCharging = charging; break;
            default: continue;
        }
        any = true;
    }
    if (any) out = s;
    return any;
}

// Scans a received byte stream for battery frames sent by the device and keeps the last valid one.
inline bool FindBattery(const std::uint8_t* data, std::size_t size, Status& out) {
    bool found = false;
    for (std::size_t i = 0; data && i + 8 <= size; i++) {
        if (data[i] != kSof) continue;
        const std::uint8_t* f = data + i;
        unsigned ctrl = f[1] | (f[2] << 8);
        std::size_t len = f[5] | (f[6] << 8);
        std::size_t crcSize = (ctrl & 0x20) ? 2 : 0;
        std::size_t total = 8 + len + crcSize;
        if (total > size - i) continue;
        if (crcSize && Crc16Arc(f, total - 2) != (std::uint16_t)(f[total - 2] | (f[total - 1] << 8))) continue;
        if (f[3] != kCmdBattery || f[4] == kDirGet || f[4] == kDirSet) continue;  // not a battery reply
        if (ParseBattery(f + 8, len, out)) found = true;
        i += total - 1;
    }
    return found;
}

}  // namespace Nothing
