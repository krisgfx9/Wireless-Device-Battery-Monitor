#include "../src/drivers/apple_protocol.h"

#include <cassert>
#include <cstdio>
#include <vector>

int main() {
    // AirPods Pro (0x0E20), left bud broadcasting: left 80 %, right 90 %, case 50 %, right charging.
    std::vector<std::uint8_t> f = { 0x07, 0x19, 0x01, 0x0E, 0x20, 0x2B, 0x89, 0x25, 0x00 };
    f.resize(27);
    Apple::PodsBattery b;
    assert(Apple::DecodeProximityPairing(f.data(), f.size(), b));
    assert(b.model == 0x0E20 && b.left == 80 && b.right == 90 && b.box == 50);
    assert(!b.chargingLeft && b.chargingRight && !b.chargingBox);

    // Same frame broadcast by the right bud: nibbles and charging bits swap sides.
    f[5] = 0x0B;
    assert(Apple::DecodeProximityPairing(f.data(), f.size(), b));
    assert(b.left == 90 && b.right == 80 && b.chargingLeft && !b.chargingRight);

    // Buds in the closed case: unknown buds, case level only.
    f[6] = 0xFF;
    f[7] = 0x47;
    assert(Apple::DecodeProximityPairing(f.data(), f.size(), b));
    assert(b.left < 0 && b.right < 0 && b.box == 70 && b.chargingBox);

    // Nothing known, wrong type and wrong length are rejected.
    f[7] = 0x0F;
    assert(!Apple::DecodeProximityPairing(f.data(), f.size(), b));
    f[7] = 0x47;
    f[0] = 0x10;
    assert(!Apple::DecodeProximityPairing(f.data(), f.size(), b));
    f[0] = 0x07;
    assert(!Apple::DecodeProximityPairing(f.data(), f.size() - 1, b));

    std::puts("Apple proximity pairing tests passed.");
    return 0;
}
