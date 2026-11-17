// MCHOSE M7 Ultra on the 5253:1020 receiver or 5253:0031 USB cable, collection
// FF01:0001 (interface 2).
// Read-only protocol: https://github.com/alexfrih/mchose-linux/blob/main/PROTOCOL.md
// Feature report 11, command 06: XOR all 20 payload bytes with FF, including padding.
// Reply (including report ID): [2..3] mouse VID, [4..5] mouse PID, [10] link flags,
// [11] percent, [12] charge status (0 = discharging, 1 = charging, 2 = full), all inverted.
// Verified on M7 Ultra: mouse identity 5253:0031, flags 09 / percent 49 (73%) over the receiver,
// and flags 00 / percent 3D (61%) over USB. Only the verified mouse identity and active link are accepted.
#include "drivers.h"

namespace {

bool ReadBattery(HidDev& d, bool wired, int& percent, bool& charging) {
    std::vector<BYTE> req(21, 0xFF);
    req[0] = 0x11;
    req[1] = 0x06 ^ 0xFF;
    // Retry empty/stale replies after idle, with a fixed limit and a gap between transactions.
    for (int attempt = 0; attempt < 6; ++attempt) {
        if (attempt) Sleep(50);
        if (!d.SetFeature(req)) return false;
        Sleep(50);
        std::vector<BYTE> r;
        if (!d.GetFeature(0x11, r)) return false;
        if (r.size() < 21 || r[0] != 0x11 || (r[1] ^ 0xFF) != 0x06) continue;
        USHORT vid = (r[2] ^ 0xFF) | ((r[3] ^ 0xFF) << 8);
        USHORT pid = (r[4] ^ 0xFF) | ((r[5] ^ 0xFF) << 8);
        if (vid != 0x5253 || pid != 0x0031) continue;
        BYTE flags = r[10] ^ 0xFF;
        if (wired ? (flags & 7) != 0 : ((flags & 7) != 1 || !(flags & 8))) return false;
        int pct = r[11] ^ 0xFF, charge = r[12] ^ 0xFF;
        if (pct > 100 || charge > 2) continue;
        percent = pct;
        charging = charge == 1;
        return true;
    }
    return false;
}

}  // namespace

void PollMchose(PollContext& ctx) {
    constexpr USHORT vid = 0x5253, receiverPid = 0x1020, wiredPid = 0x0031;
    for (USHORT pid : { wiredPid, receiverPid }) {
        if (ctx.IsClaimed(vid, pid)) continue;
        bool wired = pid == wiredPid;
        for (const HidColl* c : ctx.Find(vid, pid, [](const HidColl& c) {
                 return c.iface == 2 && c.page() == 0xFF01 && c.usage() == 1 && c.featLen() == 65;
             })) {
            HidDev d;
            if (!d.OpenFeatureOnly(*c)) continue;
            int percent = -1;
            bool charging = false;
            if (!ReadBattery(d, wired, percent, charging)) continue;
            DeviceStatus s;
            s.key = L"mchose:m7ultra";
            s.name = L"MCHOSE M7 Ultra";
            s.kind = DeviceKind::Mouse;
            s.via = wired ? L"USB cable" : L"2.4 GHz receiver";
            s.percent = percent;
            s.charging = charging;
            s.graceSec = 1800;
            ctx.Add(s, vid, pid);
            if (wired) ctx.Claim(vid, receiverPid);
            break;
        }
    }
}
