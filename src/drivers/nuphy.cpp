// NuPhy WH80 over USB (19F5:A011), hardware-tested.
// Source: https://drive.nuphy.io/static/js/main.b3fb29e0.js, NuPhyIO SDK
// getBatteryState(0): GetFunc (05), offset 0020, one byte. Only this GET is sent.
// Unnumbered 64-byte reports on usage 0001:0000, interface 1:
//   55 05 00 21 01 20 00 00 ... -> AA 05 00 checksum 01 20 00 00 value ...
// Checksum is the low byte of the sum of bytes 4..63. Value: bit 7 charging,
// bits 0..6 percentage (WH80 reports in 10% steps). WH80 Bluetooth/receiver untested.
//
// VSPO! GEAR Gaming Keyboard Ver.2 (80% JIS, "VSPO 80HE JIS" in its web driver) uses the same
// vendor id, collection and GetFunc battery byte.
// Source: https://vspogear-keyboard.app/ (product table; getBattery() reads GetFunc byte 32 of the
// active profile, bit 7 charging, bits 0..6 percentage). On the 2.4G receiver (19F5:8F10) the
// query above was hardware-tested: AA 05 00 70 01 20 00 00 4F -> 79%, and offsets 0020/0060/00A0/
// 00E0 (profiles 0..3) all returned the same live level, so profile 0 is enough. On the USB cable
// (19F5:A022, same collection) the reply was 64 = 100% without the charging bit while 2.4G read
// 78% just before and 77% just after, so the cable level is not used. Over Bluetooth it uses the
// WH80's id 19F5:324A and the Windows battery level (generic.cpp), not this driver.
#include "drivers.h"

#include <algorithm>

namespace {
bool BatteryReply(const std::vector<BYTE>& r, int& percent, bool& charging) {
    if (r.size() != 64 || r[0] != 0xAA || r[1] != 0x05 || r[2] != 0 || r[4] != 1 ||
        r[5] != 0x20 || r[6] != 0 || r[7] != 0) return false;
    unsigned sum = 0;
    for (size_t i = 4; i < r.size(); ++i) sum += r[i];
    if ((sum & 0xFF) != r[3] || (r[8] & 0x7F) > 100) return false;
    percent = r[8] & 0x7F;
    charging = (r[8] & 0x80) != 0;
    return true;
}

struct NuphyProduct {
    USHORT pid;
    const wchar_t* key;
    const wchar_t* name;
    const wchar_t* via;
    bool cableFixedFull;  // the reply always says 100%, no charging flag, while the cable is attached
};

// The cable entry of a keyboard comes before its receiver, so a keyboard that answers on both
// is reported once, as wired.
constexpr NuphyProduct kNuphyProducts[] = {
    { 0xA011, L"nuphy:WH80", L"NuPhy WH80", L"USB cable", false },
    { 0xA022, L"vspo:keyboard-v2", L"VSPO! GEAR Gaming Keyboard Ver.2", L"USB cable", true },
    { 0x8F10, L"vspo:keyboard-v2", L"VSPO! GEAR Gaming Keyboard Ver.2", L"2.4 GHz receiver", false },
};
}  // namespace

void PollNuphy(PollContext& ctx) {
    constexpr USHORT vid = 0x19F5;
    for (const NuphyProduct& p : kNuphyProducts) {
        const USHORT pid = p.pid;
        if (ctx.IsClaimed(vid, pid)) continue;
        if (std::any_of(ctx.out.begin(), ctx.out.end(), [&](const DeviceStatus& s) { return s.key == p.key; })) continue;
        bool found = false;
        for (const HidColl* c : ctx.Find(vid, pid, [](const HidColl& c) {
            return c.iface == 1 && c.page() == 1 && c.usage() == 0 && c.inLen() == 65 && c.outLen() == 65;
        })) {
            HidDev d;
            if (!d.Open(*c)) continue;
            d.Flush();
            if (!d.Write({ 0, 0x55, 0x05, 0, 0x21, 1, 0x20, 0, 0 }, 400)) continue;
            const ULONGLONG end = GetTickCount64() + 400;
            for (;;) {
                int left = (int)((LONGLONG)end - (LONGLONG)GetTickCount64());
                std::vector<BYTE> r;
                if (left <= 0 || d.Read(r, left) < 0) break;
                DeviceStatus s;
                if (!BatteryReply(r, s.percent, s.charging)) continue;
                if (p.cableFixedFull) {
                    // The level is not real on the cable: show the last known level as charging
                    // (the cable and receiver share one key), like other cable-powered devices.
                    s.percent = -1;
                    s.charging = true;
                }
                s.key = p.key;
                s.name = p.name;
                s.kind = DeviceKind::Keyboard;
                s.via = p.via;
                ctx.Add(s, vid, pid);
                found = true;
                break;
            }
            if (found) break;
        }
    }
}
