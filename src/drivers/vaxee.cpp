// VAXEE wireless mice (VID 3057): XE / XE-S / XE V2 / AX / E1 / Sora and ZYGEN NP-01 family, on the
// 2.4 GHz receivers (1001, 1002, 2001, 2002; the 4K receiver is a VXD02) or plugged in by cable.
// Every command is a feature report with report id 0E on the vendor collection (usage page FF05, usage 01):
//   request  [0E][A5][cmd][rw][len][data...]   rw: 01 = read, 02 = write (this driver only ever reads)
//   response [0E][A5][cmd][status][len][data...]   status: 01 = data, 03 = ack; data starts at byte 5
//   cmd 0F = wireless link (receiver only)  -> [5] = 0 when the mouse is off or out of range
//   cmd 0A = mouse product id (receiver only) -> [5..6] little endian
//   cmd 0B = battery  -> [5] = 0..20, in 5 % steps
//   cmd 10 = charging -> [5] != 0 (also answered over the cable)
// The reply can take more than 100 ms, so the reply is polled rather than the request resent.
// Reference: github.com/ToooAir/mousepulse (MIT, protocol read from VAXEE's web driver),
// github.com/ryanlewis/mousebatt and github.com/stuffz/mouse-battery-monitor.
#include <algorithm>

#include "drivers.h"

namespace {

constexpr USHORT kVaxeeVid = 0x3057;
constexpr BYTE kReportId = 0x0E;
constexpr BYTE kHeader = 0xA5;
constexpr BYTE kRead = 0x01;
constexpr BYTE kCmdMousePid = 0x0A;
constexpr BYTE kCmdBattery = 0x0B;
constexpr BYTE kCmdWireless = 0x0F;
constexpr BYTE kCmdCharging = 0x10;

bool IsReceiver(USHORT pid) { return pid == 0x1001 || pid == 0x1002 || pid == 0x2001 || pid == 0x2002; }

const wchar_t* ModelName(USHORT mousePid) {
    switch (mousePid) {
        case 0x1003: return L"VAXEE XE Wireless";
        case 0x1004: return L"ZYGEN NP-01S Wireless";
        case 0x1005: return L"VAXEE AX Wireless";
        case 0x1006: return L"ZYGEN NP-01 Wireless";
        case 0x1007: return L"VAXEE XE-S Wireless";
        case 0x1008: return L"VAXEE XE-S-L Wireless";
        case 0x1009: return L"VAXEE x NINJUTSO Sora Wireless";
        case 0x1010: return L"VAXEE E1 Wireless";
        case 0x1011: return L"ZYGEN NP-01S V2 Wireless";
        case 0x1012: return L"VAXEE XE V2 Wireless";
        case 0x1013: return L"ZYGEN NP-01S Ergo Wireless";
        case 0x1014: return L"VAXEE NP-01S V3 Wireless";
        case 0x1015: return L"VAXEE NP-01 Ergo Wireless";
        default: return nullptr;
    }
}

// Sends a read of `cmd` and waits for the matching reply (at most ~600 ms in total).
bool Query(HidDev& d, BYTE cmd, BYTE len, std::vector<BYTE>& rx) {
    size_t size = d.coll().featLen();
    std::vector<BYTE> tx(size, 0);
    tx[0] = kReportId;
    tx[1] = kHeader;
    tx[2] = cmd;
    tx[3] = kRead;
    tx[4] = len;
    if (!d.SetFeature(tx)) return false;
    ULONGLONG end = GetTickCount64() + 600;
    do {
        Sleep(100);
        rx.assign(size, 0);
        rx[0] = kReportId;
        if (!d.GetFeature(kReportId, rx) || rx.size() < 7) return false;
        if (rx[1] == kHeader && rx[2] == cmd && rx[3] == 0x01) return true;
    } while (GetTickCount64() < end);
    return false;
}

bool IsVendorColl(const HidColl& c) { return c.page() == 0xFF05 && c.usage() == 0x01 && c.featLen() >= 8; }

}  // namespace

void PollVaxee(PollContext& ctx) {
    std::vector<std::wstring> seenNames;
    // Cabled mice first: with the cable plugged in, the mouse talks over USB and its receiver goes silent.
    std::vector<std::pair<USHORT, USHORT>> products = ctx.Products(kVaxeeVid);
    std::stable_sort(products.begin(), products.end(), [](const auto& a, const auto& b) {
        return IsReceiver(a.second) < IsReceiver(b.second);
    });
    for (auto [vid, pid] : products) {
        for (const HidColl* c : ctx.Find(vid, pid, IsVendorColl)) {
            HidDev d;
            if (!d.OpenFeatureOnly(*c) && !d.Open(*c)) continue;
            std::vector<BYTE> r;
            bool receiver = IsReceiver(pid);
            USHORT mousePid = pid;
            DeviceStatus s;
            s.key = L"vaxee:" + Hex4(pid);
            s.kind = DeviceKind::Mouse;
            s.via = receiver ? L"Vaxee receiver" : L"USB cable";

            if (receiver) {
                if (!Query(d, kCmdWireless, 1, r)) continue;
                if (r[5] == 0) {  // receiver answers, but the mouse is off or out of range
                    s.name = L"VAXEE wireless mouse";
                    s.connected = false;
                    ctx.Add(s, vid, pid);
                    break;
                }
                if (Query(d, kCmdMousePid, 2, r)) mousePid = (USHORT)(r[5] | (r[6] << 8));
            }
            const wchar_t* model = ModelName(mousePid);
            s.name = model ? model : L"VAXEE wireless mouse";

            if (!Query(d, kCmdBattery, 1, r) || r[5] > 20) continue;
            s.percent = Clamp100(r[5] * 5);
            if (Query(d, kCmdCharging, 1, r)) s.charging = r[5] != 0;

            // Mouse on the cable and its receiver both plugged in: report the mouse once.
            bool dup = false;
            for (auto& n : seenNames) dup |= n == s.name;
            if (!dup) {
                seenNames.push_back(s.name);
                ctx.Add(s, vid, pid);
            } else {
                ctx.Claim(vid, pid);
            }
            break;
        }
    }
}
