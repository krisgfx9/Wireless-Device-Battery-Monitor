#pragma once
// ATK / VXE NearLink 0xff05 transport helpers.
// Protocol details are documented by the community ATK Control project:
// https://github.com/NasirA1991/atk-control (protocol.py).
// Requests are 64-byte report-ID 0x08 frames with a leading additive checksum.
// Replies use marker 0x72 directly after the report ID and carry no leading checksum.

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <vector>

namespace AtkV2 {

constexpr uint8_t kReportId = 0x08;
constexpr uint8_t kMarker = 0x72;
constexpr uint8_t kEventStatus = 0x73;
constexpr uint8_t kTargetDongle = 0;
constexpr uint8_t kTargetMouse = 1;
constexpr uint8_t kBatteryCommand = 0x07;
constexpr uint8_t kChargingCommand = 0x0F;
constexpr std::size_t kReportSize = 64;

// Build a complete HID output report. paramLength and commandLength are part
// of the vendor frame header; the battery query uses (2, 1), target mouse.
inline std::vector<uint8_t> BuildFrame(uint8_t command, uint8_t paramLength,
                                       uint8_t commandLength, uint8_t target) {
    std::vector<uint8_t> report(kReportSize, 0);
    report[0] = kReportId;
    report[2] = kMarker;
    report[3] = paramLength;
    report[5] = target;
    report[6] = command;
    report[7] = commandLength;
    unsigned sum = 0;
    for (std::size_t i = 2; i < report.size(); ++i) sum += report[i];
    report[1] = static_cast<uint8_t>(sum & 0xFF);
    return report;
}

// Extract command data from a matching 0xff05 input report. Unsolicited
// events and malformed/negative replies are ignored.
inline bool DecodeReply(const std::vector<uint8_t>& raw, uint8_t command,
                        std::vector<uint8_t>& payload) {
    payload.clear();
    if (raw.empty()) return false;
    std::size_t offset = raw[0] == kReportId ? 1 : 0;
    if (raw.size() < offset + 7) return false;
    const uint8_t* frame = raw.data() + offset;
    const std::size_t size = raw.size() - offset;
    if (frame[0] != kMarker || frame[1] == kEventStatus ||
        frame[1] == 0xFF || frame[4] != command) return false;
    const std::size_t length = std::min<size_t>(frame[5], size - 6);
    payload.assign(frame + 6, frame + 6 + length);
    return true;
}

}  // namespace AtkV2
