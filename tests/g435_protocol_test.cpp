#include "../src/drivers/g435_protocol.h"

#include <cassert>
#include <cstdio>
#include <cstdint>
#include <vector>

int main() {
    // Command framing: 50 41 <category> <seq> <len> <payload...>.
    {
        auto cmd = G435::BuildCommand(0x06, 2, 1, { 0x00, 0x31 });
        const std::vector<std::uint8_t> expect = { 0x50, 0x41, 0x06, 0x02, 0x01, 0x00, 0x31 };
        assert(cmd == expect);
    }
    {
        auto cmd = G435::BuildCommand(0x0E, 1, 1, { 0xE3 });
        const std::vector<std::uint8_t> expect = { 0x50, 0x41, 0x0E, 0x01, 0x01, 0xE3 };
        assert(cmd == expect);
    }
    {
        auto cmd = G435::BuildCommand(0x0E, 3, 2, { 0xE1, 0x01 });
        const std::vector<std::uint8_t> expect = { 0x50, 0x41, 0x0E, 0x03, 0x02, 0xE1, 0x01 };
        assert(cmd == expect);
    }

    // GET_BATTERY reply captured from a 046d:0acb dongle: 07 00 06 <seq|80> 00 <lo> <hi>.
    const std::vector<std::uint8_t> battery4146 = {
        0x06, 0x50, 0x49, 0x01, 0xC8, 0x75, 0x48, 0x0D, 0x00, 0x07, 0x00,
        0x06, 0x82, 0x00, 0x32, 0x10, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
    };
    int mv = 0;
    assert(G435::ParseBattery(battery4146.data(), battery4146.size(), mv));
    assert(mv == 4146);

    // Same reply in remote mode 0: the dongle answers GET_BATTERY itself with garbage (210 mV).
    const std::vector<std::uint8_t> batteryGarbage = {
        0x06, 0x50, 0x49, 0x01, 0xC0, 0xD6, 0x43, 0x00, 0x00, 0x07, 0x00,
        0x06, 0x82, 0x00, 0xD2, 0x00, 0x00, 0x00, 0xFF, 0xFF
    };
    assert(G435::ParseBattery(batteryGarbage.data(), batteryGarbage.size(), mv));
    assert(mv == 210);
    assert(!G435::IsPlausible(mv));

    // Short and null buffers never produce a reading.
    const std::vector<std::uint8_t> shortReport = { 0x06, 0x50, 0x49 };
    assert(!G435::ParseBattery(shortReport.data(), shortReport.size(), mv));
    assert(!G435::ParseBattery(nullptr, 19, mv));

    // Wireless "get" reply: 02 00 <cmd> <value>.
    const std::vector<std::uint8_t> connect = {
        0x06, 0x50, 0x49, 0x0E, 0xC7, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0xE3, 0x01, 0xFF, 0xFF
    };
    int value = -1;
    assert(G435::ParseRemoteValue(connect.data(), connect.size(), 0xE3, value));
    assert(value == 1);
    assert(!G435::ParseRemoteValue(connect.data(), connect.size(), 0xE0, value));
    assert(!G435::ParseRemoteValue(nullptr, 4, 0xE3, value));

    // Voltage plausibility bounds.
    assert(!G435::IsPlausible(2499));
    assert(G435::IsPlausible(2500));
    assert(G435::IsPlausible(4600));
    assert(!G435::IsPlausible(4601));

    // Voltage -> percent curve (4200 mV = 100 %, 3400 mV = 0 %).
    assert(G435::Percent(4300) == 100);
    assert(G435::Percent(4200) == 100);
    assert(G435::Percent(4146) == 94);
    assert(G435::Percent(3780) == 51);
    assert(G435::Percent(3400) == 0);
    assert(G435::Percent(3300) == 0);

    std::puts("G435 protocol tests passed (framing, parsing, voltage bounds, percent curve).");
    return 0;
}
