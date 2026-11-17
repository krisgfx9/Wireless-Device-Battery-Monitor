#include "../src/drivers/g435_protocol.h"

#include <array>
#include <cassert>
#include <cstdint>
#include <cstdio>

int main() {
    static constexpr std::uint8_t check[] = "123456789";
    assert(G435::Crc16Xmodem(check, sizeof(check) - 1) == 0x31C3);

    const std::array<std::uint8_t, 1> body = { 0x01 };
    auto frame = G435::Frame(0x84, body.data(), body.size());
    assert(frame[0] == 0x84 && frame[1] == 1 && frame[4] == 0x01);
    std::uint16_t crc = frame[2] | (frame[3] << 8);
    frame[2] = frame[3] = 0;
    assert(G435::Crc16Xmodem(frame.data(), frame.size()) == crc);

    std::array<std::uint8_t, 64> reply{};
    reply[0] = 0x00;
    reply[1] = 0x07;
    reply[2] = 0x00;
    reply[3] = 0x06;
    reply[5] = 0x00;
    reply[6] = 0xC4;
    reply[7] = 0x0E;  // 3780 mV
    assert(G435::ParseMilliVolts(reply.data(), reply.size()) == 3780);
    assert(G435::Percent(3780) == 51);
    assert(G435::Percent(4200) == 100);
    assert(G435::Percent(3400) == 0);

    const std::array<std::uint8_t, 6> realtekReply = { 0x06, 0x80, 0x00, 0xC4, 0x0E, 0x00 };
    assert(G435::ParseRealtekMilliVolts(realtekReply.data(), realtekReply.size()) == 3780);
    assert(G435::RealtekPercent(3780) == 46);
    assert(G435::ParseRealtekMilliVolts(nullptr, realtekReply.size()) == -1);

    reply[6] = 0x00;
    reply[7] = 0x00;
    assert(G435::ParseMilliVolts(reply.data(), reply.size()) == -1);
    assert(G435::ParseMilliVolts(nullptr, reply.size()) == -1);

    std::puts("G435 protocol tests passed");
    return 0;
}
