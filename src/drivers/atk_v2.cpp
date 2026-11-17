// VXE R1 NK / ATK NK NANO NearLink protocol over either the Nano receiver or USB-C.
// Wireless receiver: 373B:1216. Direct wired mouse: 373B:124C.
// Both expose the same 64-byte 0xff05 HID collection; try the directly connected
// mouse first so an idle receiver cannot supply a stale reading while wired.
#include "drivers.h"
#include "atk_v2_protocol.h"

namespace {

struct AtkV2Device {
    USHORT pid;
    const wchar_t* connection;
};

constexpr AtkV2Device kDevices[] = {
    { 0x124C, L"USB-C wired" },
    { 0x1216, L"2.4 GHz receiver" },
};

bool IsAtkV2Collection(const HidColl& c) {
    return c.iface == 2 && c.page() == 0xFF05 && c.usage() == 0x0001 &&
           c.inLen() == AtkV2::kReportSize && c.outLen() == AtkV2::kReportSize;
}

bool QueryV2(HidDev& dev, BYTE command, std::vector<BYTE>& payload) {
    dev.Flush();
    const auto request = AtkV2::BuildFrame(command, 2, 1, AtkV2::kTargetMouse);
    if (!dev.Write(request, 500)) return false;

    const ULONGLONG deadline = GetTickCount64() + 700;
    while (GetTickCount64() < deadline) {
        const int left = static_cast<int>(deadline - GetTickCount64());
        std::vector<BYTE> reply;
        if (dev.Read(reply, left) < 0) return false;
        if (AtkV2::DecodeReply(reply, command, payload)) return true;
        // Ignore unsolicited battery/event reports and replies to other commands.
    }
    return false;
}

}  // namespace

void PollAtkV2(PollContext& ctx) {
    constexpr USHORT kVid = 0x373B;

    // Claim both known product IDs when their dedicated interface is present. This
    // prevents the legacy Kysona driver from probing their other vendor interfaces.
    for (const auto& device : kDevices) {
        const auto collections = ctx.Find(kVid, device.pid, IsAtkV2Collection);
        if (collections.empty()) continue;
        ctx.Claim(kVid, device.pid);

        // Prefer the active USB-C device. If it is present but does not answer, try
        // the receiver as a fallback; only one successful source is ever published.
        for (const HidColl* collection : collections) {
            HidDev dev;
            if (!dev.Open(*collection)) continue;

            std::vector<BYTE> battery;
            if (!QueryV2(dev, AtkV2::kBatteryCommand, battery) || battery.empty() ||
                battery[0] > 100) continue;

            DeviceStatus status;
            status.key = L"atk-v2:373B:VXE-R1-NK";
            status.name = L"VXE R1 NK";
            status.kind = DeviceKind::Mouse;
            status.via = device.connection;
            status.percent = battery[0];
            if (battery.size() >= 3) {
                const int mv = battery[1] | (battery[2] << 8);
                if (mv >= 1000 && mv <= 6000) status.millivolts = mv;
            }

            // Charging is supplementary: a device that answers battery but not the
            // charging query must still keep its percentage visible in the taskbar.
            std::vector<BYTE> charging;
            if (QueryV2(dev, AtkV2::kChargingCommand, charging) && !charging.empty())
                status.charging = charging[0] == 1 || charging[0] == 0x3B;

            ctx.Add(status, kVid, device.pid);
            return;
        }
    }
}
