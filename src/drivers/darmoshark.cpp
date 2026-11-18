// Darmoshark M3 over USB cable (248A:FF12) or its Telink 2.4 GHz receiver (248A:FF30).
// Protocol reference:
// https://github.com/Barba2k2/darmoshark-m3-configurator/blob/main/PROTOCOL.md
// Cable and receiver share the 008C:0001 collection (33/33/1001); report 51 command 06 carries
// battery at [11]. Byte [12] is observed but not treated as a confirmed charging flag.
#include "drivers.h"

#include <algorithm>

namespace {
constexpr USHORT kVid = 0x248A;
constexpr USHORT kReceiver = 0xFF30;
constexpr USHORT kCable = 0xFF12;
constexpr BYTE kFeature = 0x51;
constexpr BYTE kBond = 0x03;
constexpr BYTE kIdentify = 0x06;
constexpr USHORT kStatusLength = 21;
constexpr ULONGLONG kReceiverTimeoutMs = 1000;
constexpr ULONGLONG kFirstAttemptMs = 300;
constexpr ULONGLONG kQueryTimeoutMs = 500;
constexpr ULONGLONG kCableTimeoutMs = 200;

const wchar_t* kKey = L"darmoshark:m3";

bool IsStatusCollection(const HidColl& c, bool cable) {
    return c.iface == (cable ? 2 : 1) && c.page() == 0x008C && c.usage() == 1 &&
           c.inLen() == 33 && c.outLen() == 33 && c.featLen() == 1001;
}

USHORT ReadId(const std::vector<BYTE>& reply, size_t offset) {
    return static_cast<USHORT>(reply[offset] | (reply[offset + 1] << 8));
}

bool DecodeIdentify(const std::vector<BYTE>& reply, int& percent) {
    if (reply.size() < 12 || reply[0] != kFeature || reply[1] != kIdentify || reply[2] != 1 ||
        ReadId(reply, 4) != kVid || ReadId(reply, 6) != kCable || reply[11] > 100)
        return false;
    percent = reply[11];
    return true;
}

// Receiver path: bond clears a stale identify reply, then identify returns battery. Input ACK
// 54 E4 02 means no RF link (mouse off / asleep) — do not publish a cached percentage.
bool QueryReceiver(HidDev& device, BYTE opcode, std::vector<BYTE>& reply, ULONGLONG receiverDeadline) {
    const auto start = GetTickCount64();
    if (start >= receiverDeadline) return false;
    const auto deadline = (std::min)(receiverDeadline, start + kQueryTimeoutMs);

    device.Flush();
    if (GetTickCount64() >= deadline || !device.SetFeature({kFeature, opcode})) return false;

    std::vector<BYTE> input;
    for (auto now = GetTickCount64(); now < deadline; now = GetTickCount64()) {
        const auto waitMs = static_cast<int>((std::min)(20ULL, deadline - now));
        if (device.Read(input, waitMs) >= 3 &&
            input[0] == 0x54 && input[1] == 0xE4 && input[2] == 2) return false;
        if (GetTickCount64() >= deadline) return false;
        if (device.GetFeature(kFeature, reply) && reply.size() >= 12 &&
            reply[0] == kFeature && reply[1] == opcode) return GetTickCount64() < deadline;
    }
    return false;
}

int ReadReceiverBattery(HidDev& device, ULONGLONG deadline) {
    std::vector<BYTE> reply;
    if (!QueryReceiver(device, kBond, reply, deadline) ||
        ReadId(reply, 3) != kVid || ReadId(reply, 5) != kCable || !reply[7]) return -1;
    int percent = -1;
    if (!QueryReceiver(device, kIdentify, reply, deadline) || !DecodeIdentify(reply, percent)) return -1;
    return percent;
}

// Cable path: feature 51/06 is answered on the control pipe; no receiver ACK stream. Bond is a
// dongle-side command and is not used here. Report 51 is 21 bytes; the collection max is 1001.
bool ReadCableBattery(HidDev& device, int& percent) {
    std::vector<BYTE> request(kStatusLength, 0);
    request[0] = kFeature;
    request[1] = kIdentify;
    const auto deadline = GetTickCount64() + kCableTimeoutMs;
    if (!device.SetFeature(request)) return false;
    do {
        Sleep(10);
        std::vector<BYTE> reply;
        if (device.GetFeature(kFeature, reply) && DecodeIdentify(reply, percent)) return true;
    } while (GetTickCount64() < deadline);
    return false;
}

DeviceStatus MakeStatus(bool cable, int percent) {
    DeviceStatus status;
    status.key = kKey;
    status.name = L"Darmoshark M3";
    status.kind = DeviceKind::Mouse;
    status.via = cable ? L"USB cable" : L"2.4 GHz receiver";
    status.percent = percent;
    // Visual transport hints for the taskbar widget; charging stays unset (byte 12 unconfirmed).
    status.usbConnected = cable;
    status.wirelessLink = !cable;
    return status;
}
}  // namespace

void PollDarmoshark(PollContext& ctx) {
    if (ctx.IsClaimed(kVid, kCable) || ctx.IsClaimed(kVid, kReceiver)) return;

    // USB first: a live cable reading must not fall back to the receiver's cached RF state.
    for (const HidColl* coll : ctx.Find(kVid, kCable, [](const HidColl& c) { return IsStatusCollection(c, true); })) {
        ctx.Claim(kVid, kCable);
        HidColl status = *coll;
        status.caps.FeatureReportByteLength = kStatusLength;
        HidDev device;
        int percent = -1;
        if (device.OpenFeatureOnly(status) && ReadCableBattery(device, percent)) {
            ctx.Claim(kVid, kReceiver);  // skip RF probe while the mouse is on the cable
            ctx.Add(MakeStatus(true, percent), kVid, kCable);
            return;
        }
        // Cable collection present but unread: do not publish a receiver reading as current.
        ctx.Claim(kVid, kReceiver);
        return;
    }

    for (const HidColl* coll : ctx.Find(kVid, kReceiver, [](const HidColl& c) { return IsStatusCollection(c, false); })) {
        const auto deadline = GetTickCount64() + kReceiverTimeoutMs;
        HidDev device;
        if (!device.Open(*coll)) continue;

        const auto firstDeadline = (std::min)(deadline, GetTickCount64() + kFirstAttemptMs);
        int percent = ReadReceiverBattery(device, firstDeadline);
        if (percent < 0 && GetTickCount64() < deadline) percent = ReadReceiverBattery(device, deadline);
        if (percent < 0) continue;

        ctx.Add(MakeStatus(false, percent), kVid, kReceiver);
        return;
    }
}
