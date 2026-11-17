// Razer BlackShark V3 / V3 Pro headsets (1532:0576/0577 V3 Pro, 0579/057A V3), interface 5; V3 X further down.
// 64-byte output report 02: [02][00][60][00 00][00][size][00 00][dir][class][sub][argc][args]..
// [62] = XOR of bytes 0..61. GET battery = class 21 -> reply args [level %][charging].
// The headset drops its 2.4 GHz link if the battery is queried every few seconds, so it is asked at
// most once every 5 minutes and the last reading is reused in between.
// Protocol from OpenRazer PR #2794 (docs/v3_pro_protocol.md) and github.com/ReedME/omarchy-blackshark-v3.
#include "drivers.h"

#include <map>

namespace {

constexpr ULONGLONG kMinIntervalMs = 5 * 60 * 1000;

std::vector<BYTE> Packet(BYTE dir, BYTE cls) {
    std::vector<BYTE> b(64, 0);
    b[0] = 0x02;
    b[2] = 0x60;
    b[6] = 0x04;  // data size: dir, class, sub, argc
    b[9] = dir;
    b[10] = cls;
    BYTE crc = 0;
    for (int i = 0; i < 62; i++) crc ^= b[i];
    b[62] = crc;
    return b;
}

bool Get(HidDev& d, BYTE cls, std::vector<BYTE>& reply) {
    if (!d.Write(Packet(0x80, cls))) return false;
    ULONGLONG end = GetTickCount64() + 600;
    while ((LONGLONG)end - (LONGLONG)GetTickCount64() > 0) {
        int left = (int)((LONGLONG)end - (LONGLONG)GetTickCount64());
        if (d.Read(reply, left) < 15) return false;
        if (reply[0] == 0x02 && reply[2] == 0x60 && reply[10] == cls) return true;
    }
    return false;
}

struct Cached { ULONGLONG at = 0; DeviceStatus status; bool valid = false; };
std::map<USHORT, Cached> g_cache;

const wchar_t* Name(USHORT pid) { return (pid == 0x0576 || pid == 0x0577) ? L"Razer BlackShark V3 Pro" : L"Razer BlackShark V3"; }

// BlackShark V3 X (1532:057D HyperSpeed dongle, 057C cable): a different protocol on interface 0.
// 64-byte feature report 07: [07][status][txid][00 00 00][argc][class][cmd][args].. [62] = XOR of 3..60.
// Battery = class 07 cmd 80 -> args[1] is the level %; cmd 84 -> args[1] is charging.
// Status 02 = success, 01 = busy; anything else (e.g. headset off) is a failure.
// Protocol from OpenRazer PR #2899, verified on a 057D dongle.
bool V3xGet(HidDev& d, BYTE cmd, BYTE& value) {
    static BYTE txid = 0x40;
    for (int attempt = 0; attempt < 4; attempt++) {
        std::vector<BYTE> req(64, 0);
        req[0] = 0x07;
        req[2] = ++txid;
        req[6] = 0x02;
        req[7] = 0x07;
        req[8] = cmd;
        BYTE crc = 0;
        for (int i = 3; i <= 60; i++) crc ^= req[i];
        req[62] = crc;
        if (!d.SetFeature(req)) return false;
        Sleep(60);
        std::vector<BYTE> r;
        if (!d.GetFeature(0x07, r) || r.size() < 63) continue;
        if (r[2] != txid || r[7] != 0x07 || r[8] != cmd || r[6] < 2) continue;
        if (r[1] != 0x02 && r[1] != 0x01) return false;
        value = r[10];
        return true;
    }
    return false;
}

void PollBlackSharkV3X(PollContext& ctx) {
    for (USHORT pid : { (USHORT)0x057D, (USHORT)0x057C }) {
        if (ctx.IsClaimed(0x1532, pid)) continue;
        auto colls = ctx.Find(0x1532, pid, [](const HidColl& c) { return c.iface == 0 && c.featLen() >= 64; });
        if (colls.empty()) continue;
        Cached& cache = g_cache[pid];
        if (cache.valid && GetTickCount64() - cache.at < kMinIntervalMs) {
            ctx.Add(cache.status, 0x1532, pid);
            continue;
        }
        HidDev d;
        if (!d.OpenFeatureOnly(*colls[0])) continue;
        BYTE level = 0, charging = 0;
        if (!V3xGet(d, 0x80, level) || level > 100) continue;
        V3xGet(d, 0x84, charging);
        DeviceStatus s;
        s.key = L"blackshark:" + Hex4(pid);
        s.name = L"Razer BlackShark V3 X";
        s.kind = DeviceKind::Headset;
        s.via = pid == 0x057D ? L"2.4 GHz receiver" : L"USB cable";
        s.percent = level;
        s.charging = charging == 1;
        cache = { GetTickCount64(), s, true };
        ctx.Add(s, 0x1532, pid);
    }
}

}  // namespace

void PollRazerHeadsets(PollContext& ctx) {
    PollBlackSharkV3X(ctx);
    for (USHORT pid : { (USHORT)0x0576, (USHORT)0x0577, (USHORT)0x0579, (USHORT)0x057A }) {
        if (ctx.IsClaimed(0x1532, pid)) continue;
        auto colls = ctx.Find(0x1532, pid, [](const HidColl& c) { return c.iface == 5 && c.outLen() >= 64 && c.inLen() >= 15; });
        if (colls.empty()) continue;
        Cached& cache = g_cache[pid];
        if (cache.valid && GetTickCount64() - cache.at < kMinIntervalMs) {
            ctx.Add(cache.status, 0x1532, pid);
            continue;
        }
        HidDev d;
        if (!d.Open(*colls[0])) continue;
        // Handshake the headset expects before reads (init, charging state on both links).
        d.Write(Packet(0x00, 0x02));
        d.Write(Packet(0x00, 0x2A));
        d.Write(Packet(0x80, 0x2A));
        Sleep(250);
        d.Flush();
        std::vector<BYTE> r;
        if (!Get(d, 0x21, r) || r[13] > 100) continue;
        DeviceStatus s;
        s.key = L"blackshark:" + Hex4(pid);
        s.name = Name(pid);
        s.kind = DeviceKind::Headset;
        s.via = L"2.4 GHz receiver";
        s.percent = r[13];
        s.charging = r[14] != 0;
        cache = { GetTickCount64(), s, true };
        ctx.Add(s, 0x1532, pid);
    }
}
