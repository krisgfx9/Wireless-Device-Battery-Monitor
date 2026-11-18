#pragma once
// Apple "proximity pairing" BLE advertisement (manufacturer data, company 0x004C), sent by AirPods
// and Beats while out of the case or with the lid open. Layout as used by OpenPods and
// AirPodsDesktop:
//   [0] 0x07 type   [1] remaining length   [2] 0x01   [3..4] model id (big endian)
//   [5] status: bit 0x20 set = left bud broadcasts, so the next byte's high nibble is the left bud
//   [6] bud levels, one nibble each   [7] high nibble: charging (bit0/bit1 buds, bit2 case), low: case
// Levels are 0..10 (x10 %), 15 = unknown (bud in the closed case, or not connected).
// Kept independent of Win32 so captured frames can be checked without AirPods.
#include <cstddef>
#include <cstdint>

namespace Apple {

struct PodsBattery {
    std::uint16_t model = 0;
    int left = -1, right = -1, box = -1;  // percent, -1 = unknown
    bool chargingLeft = false, chargingRight = false, chargingBox = false;
};

inline int Level(unsigned nibble) { return nibble <= 10 ? (int)nibble * 10 : -1; }

inline bool DecodeProximityPairing(const std::uint8_t* d, std::size_t n, PodsBattery& out) {
    if (!d || n < 8 || d[0] != 0x07 || d[1] + 2u != n) return false;
    PodsBattery b;
    b.model = (std::uint16_t)((d[3] << 8) | d[4]);
    bool leftFirst = d[5] & 0x20;
    unsigned hi = d[6] >> 4, lo = d[6] & 0x0F, flags = d[7] >> 4;
    b.left = Level(leftFirst ? hi : lo);
    b.right = Level(leftFirst ? lo : hi);
    b.box = Level(d[7] & 0x0F);
    b.chargingLeft = flags & (leftFirst ? 1 : 2);
    b.chargingRight = flags & (leftFirst ? 2 : 1);
    b.chargingBox = flags & 4;
    if (b.left < 0 && b.right < 0 && b.box < 0) return false;
    out = b;
    return true;
}

}  // namespace Apple
