// Checks the Nothing battery request and the reply parser without earbuds.
#include "../src/drivers/nothing_protocol.h"

#include <cstdio>
#include <vector>

static int failures = 0;
#define CHECK(cond)                                                    \
    do {                                                               \
        if (!(cond)) {                                                 \
            std::printf("FAIL %s:%d: %s\n", __FILE__, __LINE__, #cond); \
            failures++;                                                \
        }                                                              \
    } while (0)

// Builds a device -> host frame with a CRC (ctrl 0x0160, CRC flag 0x20 set).
static std::vector<std::uint8_t> Reply(std::uint8_t cmd, std::uint8_t dir, const std::vector<std::uint8_t>& payload) {
    std::vector<std::uint8_t> f = { 0x55, 0x60, 0x01, cmd, dir, (std::uint8_t)payload.size(), 0x00, 0x01 };
    f.insert(f.end(), payload.begin(), payload.end());
    std::uint16_t crc = Nothing::Crc16Arc(f.data(), f.size());
    f.push_back((std::uint8_t)(crc & 0xFF));
    f.push_back((std::uint8_t)(crc >> 8));
    return f;
}

int main() {
    // Request layout: 55 60 01 07 C0 00 00 seq crc crc, CRC-16/ARC over the first 8 bytes.
    auto req = Nothing::BatteryRequest(1);
    CHECK(req.size() == 10);
    CHECK(req[0] == 0x55 && req[1] == 0x60 && req[2] == 0x01 && req[3] == 0x07 && req[4] == 0xC0);
    CHECK(req[5] == 0 && req[6] == 0 && req[7] == 1);
    CHECK(Nothing::Crc16Arc(req.data(), 8) == (std::uint16_t)(req[8] | (req[9] << 8)));
    // CRC-16/ARC check value for "123456789" with init 0xFFFF (CRC-16/MODBUS) is 0x4B37.
    const std::uint8_t check[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
    CHECK(Nothing::Crc16Arc(check, sizeof(check)) == 0x4B37);

    // Left 90%, right 80% charging, case 100%.
    {
        auto f = Reply(0x07, 0x40, { 3, 0x02, 90, 0x03, 0x80 | 80, 0x04, 100 });
        Nothing::Status st;
        CHECK(Nothing::FindBattery(f.data(), f.size(), st));
        CHECK(st.left == 90 && !st.leftCharging);
        CHECK(st.right == 80 && st.rightCharging);
        CHECK(st.caseLevel == 100 && !st.caseCharging);
        CHECK(st.headset == -1);
    }
    // Both earbuds reported as one component (01); no case.
    {
        auto f = Reply(0x07, 0x40, { 1, 0x01, 55 });
        Nothing::Status st;
        CHECK(Nothing::FindBattery(f.data(), f.size(), st));
        CHECK(st.left == 55 && st.right == 55 && st.caseLevel == -1);
    }
    // Headphones (06).
    {
        auto f = Reply(0x07, 0x40, { 1, 0x06, 0x80 | 42 });
        Nothing::Status st;
        CHECK(Nothing::FindBattery(f.data(), f.size(), st));
        CHECK(st.headset == 42 && st.headsetCharging && st.left == -1);
    }
    // Other frames before the reply, the reply split around noise, and a corrupted copy are handled.
    {
        auto other = Reply(0x1E, 0x40, { 0x05 });  // ANC state, ignored
        auto good = Reply(0x07, 0x40, { 2, 0x02, 70, 0x03, 65 });
        auto bad = good;
        bad[9] ^= 0xFF;  // CRC no longer matches
        std::vector<std::uint8_t> stream = { 0x00, 0x55, 0x12 };
        stream.insert(stream.end(), other.begin(), other.end());
        stream.insert(stream.end(), bad.begin(), bad.end());
        stream.insert(stream.end(), good.begin(), good.end());
        Nothing::Status st;
        CHECK(Nothing::FindBattery(stream.data(), stream.size(), st));
        CHECK(st.left == 70 && st.right == 65);
        // Only the corrupted copy: nothing found.
        Nothing::Status none;
        CHECK(!Nothing::FindBattery(bad.data(), bad.size(), none));
        // Truncated frame: nothing found yet.
        CHECK(!Nothing::FindBattery(good.data(), good.size() - 1, none));
    }
    // Our own request echoed back (direction GET) is not taken as a reply.
    {
        Nothing::Status st;
        CHECK(!Nothing::FindBattery(req.data(), req.size(), st));
    }
    // Levels above 100 are ignored; an empty list finds nothing.
    {
        auto f = Reply(0x07, 0x40, { 1, 0x02, 0x7F });
        Nothing::Status st;
        CHECK(!Nothing::FindBattery(f.data(), f.size(), st));
        auto e = Reply(0x07, 0x40, { 0 });
        CHECK(!Nothing::FindBattery(e.data(), e.size(), st));
    }

    if (failures) return 1;
    std::printf("nothing_protocol_test: all passed\n");
    return 0;
}
