#include "../src/drivers/atk_v2_protocol.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

int main() {
    const auto request = AtkV2::BuildFrame(AtkV2::kBatteryCommand, 2, 1, AtkV2::kTargetMouse);
    assert(request.size() == 64);
    assert(request[0] == 0x08);
    assert(request[2] == 0x72);
    assert(request[3] == 2);
    assert(request[5] == 1);
    assert(request[6] == 0x07);
    assert(request[7] == 1);

    unsigned checksum = 0;
    for (size_t i = 2; i < request.size(); ++i) checksum += request[i];
    assert(request[1] == static_cast<uint8_t>(checksum & 0xFF));

    // R1 NK example: 82% and 4038 mV (0x0FC6, little endian).
    std::vector<uint8_t> reply(64, 0);
    reply[0] = 0x08;
    reply[1] = 0x72;
    reply[2] = 0x00;
    reply[3] = 0x02;
    reply[5] = 0x07;
    reply[6] = 0x03;
    reply[7] = 0x52;
    reply[8] = 0xC6;
    reply[9] = 0x0F;

    std::vector<uint8_t> payload;
    assert(AtkV2::DecodeReply(reply, AtkV2::kBatteryCommand, payload));
    assert(payload.size() == 3);
    assert(payload[0] == 82);
    assert((payload[1] | (payload[2] << 8)) == 4038);

    // Unsolicited events and mismatched command replies must not be accepted.
    reply[2] = AtkV2::kEventStatus;
    assert(!AtkV2::DecodeReply(reply, AtkV2::kBatteryCommand, payload));
    reply[2] = 0x00;
    assert(!AtkV2::DecodeReply(reply, AtkV2::kChargingCommand, payload));

    // The same reply format is accepted when the HID backend omits report ID.
    reply.erase(reply.begin());
    assert(AtkV2::DecodeReply(reply, AtkV2::kBatteryCommand, payload));
    std::cout << "ATK/VXE 0xff05 protocol tests passed\n";
}
