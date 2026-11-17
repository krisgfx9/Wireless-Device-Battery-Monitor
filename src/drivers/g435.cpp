// Logitech G435 LIGHTSPEED headset (046D:0ACB). Unlike other Logitech devices this one does not
// speak HID++: its vendor collection (0xFFC0:0001, report 6) talks to a Realtek ALC4021 bridge
// that must be put into "bootloader" mode before "PA" commands are forwarded to the Airoha/Audiowise
// radio SoC. Battery is read with the OTA GET_BATTERY command and returned as millivolts.
//
// Every read stops audio and microphone for about 0.6 s (a dongle firmware limitation, no way to
// avoid it), so the battery is queried at most once every 15 minutes and the last value is reused
// in between. GET_BATTERY must never be the first command of a session: sent first it can hang the
// dongle until it is unplugged. The session always leaves the bootloader, even on error.
// Protocol: github.com/deddroid/logitech-g435-battery (docs/PROTOCOL.md), endes' research.
#include "drivers.h"
#include "g435_protocol.h"

#include <map>

namespace {

constexpr USHORT kG435Vid = 0x046D;
constexpr USHORT kG435Pid = 0x0ACB;
constexpr ULONGLONG kMinIntervalMs = 15ULL * 60 * 1000;
constexpr BYTE kReportId = 0x06;
constexpr BYTE kCatOta = 0x06;
constexpr BYTE kCatWireless = 0x0E;
constexpr BYTE kRemoteGetConnect = 0xE3;
constexpr BYTE kRemoteSetMode = 0xE1;

enum class QueryKind { Battery, RemoteConnect, RemoteSetMode };

// Writes a bridge message as an output report (zero-padded by HidDev to the 515-byte report).
bool WriteBridge(HidDev& d, const std::vector<BYTE>& msg) {
    d.Flush();
    return d.Write(msg);
}

// Waits for a bridge ack on the input endpoint, skipping volume-key reports (report id 3).
bool ReadAck(HidDev& d, BYTE& ack) {
    ULONGLONG end = GetTickCount64() + 800;
    std::vector<BYTE> r;
    while ((LONGLONG)end - (LONGLONG)GetTickCount64() > 0) {
        int left = (int)((LONGLONG)end - (LONGLONG)GetTickCount64());
        if (d.Read(r, left) < 2) return false;
        if (r[0] == kReportId) {
            ack = r[1];
            return true;
        }
    }
    return false;
}

bool Bridge(HidDev& d, const std::vector<BYTE>& msg, BYTE& ack) {
    if (!WriteBridge(d, msg)) return false;
    return ReadAck(d, ack);
}

// Discards feature replies queued right after entering the bootloader.
void Drain(HidDev& d) {
    for (int i = 0; i < 16; i++) {
        std::vector<BYTE> buf;
        if (!d.GetFeature(kReportId, buf) || buf.size() < 2 || buf[1] == 0xFF) break;
    }
}

// Sends a "PA" command through the bridge and polls feature reports until the target reply
// matches. Returns true and sets `result` when found.
bool Query(HidDev& d, BYTE& seq, BYTE category, BYTE len, std::initializer_list<BYTE> payload,
           QueryKind kind, int& result) {
    auto cmd = G435::BuildCommand(category, seq, len, payload);
    seq = (BYTE)(seq % 127 + 1);

    std::vector<BYTE> msg = { kReportId, 0x04, 0x03, (BYTE)(cmd.size() & 0xFF), (BYTE)(cmd.size() >> 8) };
    msg.insert(msg.end(), cmd.begin(), cmd.end());

    BYTE ack = 0;
    if (!Bridge(d, msg, ack)) return false;

    ULONGLONG end = GetTickCount64() + 1500;
    while ((LONGLONG)end - (LONGLONG)GetTickCount64() > 0) {
        std::vector<BYTE> buf;
        if (!d.GetFeature(kReportId, buf)) return false;
        if (buf.size() > 1 && buf[1] != 0xFF) {
            if (kind == QueryKind::Battery) {
                int mv = 0;
                if (G435::ParseBattery(buf.data(), buf.size(), mv)) {
                    result = mv;
                    return true;
                }
            } else if (kind == QueryKind::RemoteConnect) {
                int v = 0;
                if (G435::ParseRemoteValue(buf.data(), buf.size(), kRemoteGetConnect, v)) {
                    result = v;
                    return true;
                }
            } else {  // RemoteSetMode: any non-empty reply confirms the command was processed
                result = 0;
                return true;
            }
        }
        Sleep(30);
    }
    return false;
}

// RAII: always leaves the bootloader, even when a query fails or times out.
struct BootloaderGuard {
    HidDev& d;
    bool active = false;
    ~BootloaderGuard() {
        if (!active) return;
        BYTE ack = 0;
        Bridge(d, std::vector<BYTE>{ kReportId, 0x08, 0x03 }, ack);
    }
};

struct Cached {
    ULONGLONG at = 0;
    DeviceStatus status;
    bool valid = false;
};
std::map<USHORT, Cached> g_cache;

}  // namespace

// Reads the battery once from an already-open device. Fills connected, percent and millivolts;
// the caller owns discovery, caching and the name/kind/via/key fields.
void G435ReadBattery(HidDev& d, DeviceStatus& s) {
    // Enter the bootloader. Once the write reaches the device it may already have stopped the
    // audio, so the guard leaves the bootloader on every path from here on, even if no ack arrives.
    if (!WriteBridge(d, std::vector<BYTE>{ kReportId, 0x01, 0x03 })) return;
    BootloaderGuard guard{ d, true };
    BYTE ack = 0;
    if (!ReadAck(d, ack)) return;
    Drain(d);

    BYTE seq = 1;
    int connected = -1;
    Query(d, seq, kCatWireless, 1, { kRemoteGetConnect }, QueryKind::RemoteConnect, connected);
    if (connected == 0) {
        s.connected = false;
        return;
    }

    int mv = -1;
    Query(d, seq, kCatOta, 1, { 0x00, 0x31 }, QueryKind::Battery, mv);
    if (G435::IsPlausible(mv)) {
        s.millivolts = mv;
        s.percent = G435::Percent(mv);
        return;
    }

    // Mode 0 (the dongle answers GET_BATTERY itself with garbage) is the default after plugging
    // in; switch to remote mode 1 and ask again.
    int ignored = 0;
    Query(d, seq, kCatWireless, 2, { kRemoteSetMode, 0x01 }, QueryKind::RemoteSetMode, ignored);
    mv = -1;
    Query(d, seq, kCatOta, 1, { 0x00, 0x31 }, QueryKind::Battery, mv);
    if (G435::IsPlausible(mv)) {
        s.millivolts = mv;
        s.percent = G435::Percent(mv);
    } else {
        s.percent = -1;
    }
}

void PollG435(PollContext& ctx) {
    if (ctx.IsClaimed(kG435Vid, kG435Pid)) return;
    auto colls = ctx.Find(kG435Vid, kG435Pid, [](const HidColl& c) {
        return c.page() == 0xFFC0 && c.usage() == 0x0001 && c.inLen() == 8 && c.outLen() == 515 && c.featLen() == 64;
    });
    if (colls.empty()) return;

    Cached& cache = g_cache[kG435Pid];
    if (cache.valid && GetTickCount64() - cache.at < kMinIntervalMs) {
        ctx.Add(cache.status, kG435Vid, kG435Pid);
        return;
    }

    HidDev d;
    if (!d.Open(*colls[0])) return;

    DeviceStatus s;
    s.key = L"g435:" + Hex4(kG435Pid);
    s.name = L"Logitech G435";
    s.kind = DeviceKind::Headset;
    s.via = L"2.4 GHz receiver";

    G435ReadBattery(d, s);

    cache = { GetTickCount64(), s, true };
    ctx.Add(s, kG435Vid, kG435Pid);
}
