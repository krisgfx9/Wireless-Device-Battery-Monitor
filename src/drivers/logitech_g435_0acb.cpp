// G435 046D:0ACB, Realtek bridge on FFC0:0001 (report 6).
// Protocol: https://github.com/deddroid/logitech-g435-battery/blob/main/docs/PROTOCOL.md
// Adapted from deddroid's MIT-licensed implementation; see docs/g435-acb-MIT-LICENSE.txt.
// Only connection/battery queries and temporary command routing are used; no firmware writes.
// The bridge session interrupts audio/microphone briefly. Cache for 15 minutes, including errors,
// rather than interrupting every poll. Manual refresh bypasses the cache; removal invalidates it.
#include "drivers.h"
#include "logitech_g435_0adf.h"

namespace {
constexpr USHORT kVid = 0x046D, kPid = 0x0ACB;
constexpr ULONGLONG kPollIntervalMs = 15 * 60 * 1000;

bool Bridge(HidDev& d, BYTE op, const std::vector<BYTE>& body = {}) {
    std::vector<BYTE> out = { 6, op, 3 };
    out.insert(out.end(), body.begin(), body.end());
    d.Flush();
    if (!d.Write(out, 200)) return false;
    std::vector<BYTE> r;
    return d.Read(r, 200) >= 2 && r[0] == 6 && (r[1] == 0x5A || r[1] == 0xFE);
}

struct Session {
    HidDev& d;
    ULONGLONG end = GetTickCount64() + 3000;
    BYTE seq = 0;
    // Even a lost enter acknowledgement must not leave the bridge in its service mode.
    ~Session() { Bridge(d, 8); }

    template <class Parse>
    int Query(BYTE cat, BYTE len, std::initializer_list<BYTE> payload, Parse parse) {
        if (GetTickCount64() >= end) return -1;
        auto cmd = G435Adf::Pa(cat, ++seq, len, payload);
        std::vector<BYTE> body = { (BYTE)cmd.size(), 0 };
        body.insert(body.end(), cmd.begin(), cmd.end());
        if (!Bridge(d, 4, body)) return -1;
        ULONGLONG until = GetTickCount64() + 500;
        while (GetTickCount64() < until && GetTickCount64() < end) {
            std::vector<BYTE> r;
            if (!d.GetFeature(6, r)) return -1;
            int value = parse(r, seq);
            if (value >= 0) return value;
            Sleep(20);
        }
        return -1;
    }
};

int Battery(const std::vector<BYTE>& r, BYTE seq) {
    for (size_t i = 0; i + 7 <= r.size(); ++i)
        if (r[i] == 7 && r[i + 1] == 0 && r[i + 2] == 6 &&
            r[i + 3] == (BYTE)(seq | 0x80) && r[i + 4] == 0)
            return r[i + 5] | (r[i + 6] << 8);
    return -1;
}

int ReadBattery(HidDev& d, bool& off) {
    off = false;
    Session session{ d };
    if (!Bridge(d, 1)) return -1;
    // Drain stale feature replies before issuing commands.
    for (int i = 0; i < 16; ++i) {
        std::vector<BYTE> r;
        if (!d.GetFeature(6, r)) return -1;
        if (r.size() < 2 || r[1] == 0xFF) break;
    }
    // GET_BATTERY must NEVER be the first SoC command: older firmware can hang.
    int connected = session.Query(0x0E, 1, { 0xE3 }, [](const std::vector<BYTE>& r, BYTE) {
        for (size_t i = 0; i + 4 <= r.size(); ++i)
            if (r[i] == 2 && r[i + 1] == 0 && r[i + 2] == 0xE3 && r[i + 3] <= 1)
                return (int)r[i + 3];
        return -1;
    });
    if (connected != 1) {
        off = connected == 0;
        return -1;
    }
    int mv = session.Query(6, 1, { 0, 0x31 }, Battery);
    if (mv >= 2500 && mv <= 4600) return mv;
    if (mv < 0) return -1;
    // An implausible voltage means the dongle answered instead of the headset.
    int routed = session.Query(0x0E, 2, { 0xE1, 1 }, [](const std::vector<BYTE>& r, BYTE seq) {
        for (size_t i = 0; i + 5 <= r.size(); ++i)
            if (r[i] == 3 && r[i + 1] == 0 && r[i + 2] == 0x0E &&
                r[i + 3] == (BYTE)(seq | 0x80) && r[i + 4] == 0) return 0;
        return -1;
    });
    if (routed < 0) return -1;
    mv = session.Query(6, 1, { 0, 0x31 }, Battery);
    return mv >= 2500 && mv <= 4600 ? mv : -1;
}
}  // namespace

void PollLogitechG435Acb(PollContext& ctx) {
    static std::wstring path;
    static ULONGLONG next = 0;
    static DeviceStatus cached;
    if (ctx.IsClaimed(kVid, kPid)) return;
    auto colls = ctx.Find(kVid, kPid, [](const HidColl& c) {
        return c.page() == 0xFFC0 && c.usage() == 1 && c.inLen() >= 2 &&
               c.outLen() == 515 && c.featLen() == 64;
    });
    if (colls.empty()) {
        path.clear();
        next = 0;
        return;
    }
    if (!ctx.forceRefresh && path == colls[0]->path && GetTickCount64() < next) {
        ctx.Add(cached, kVid, kPid);
        return;
    }
    DeviceStatus s;
    s.key = L"g435:0ACB";
    s.name = L"Logitech G435";
    s.kind = DeviceKind::Headset;
    s.via = L"2.4 GHz receiver";
    s.detail = L"Updates every 15 min or on Refresh now; reading briefly interrupts audio";
    HidDev d;
    bool off = false;
    int mv = d.Open(*colls[0]) ? ReadBattery(d, off) : -1;
    s.connected = !off;
    if (mv >= 0) {
        s.millivolts = mv;
        s.percent = G435Adf::Percent(mv);
    } else if (!off) {
        s.detail += L"; battery query failed";
    }
    cached = s;
    path = colls[0]->path;
    next = GetTickCount64() + kPollIntervalMs;
    ctx.Add(s, kVid, kPid);
}
