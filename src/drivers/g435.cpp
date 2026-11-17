// Logitech G435 LIGHTSPEED receivers use vendor battery bridges, not the HID++ protocol
// handled by logitech.cpp. Reads are cached because querying can briefly interrupt audio.
#include "drivers.h"

#include <algorithm>
#include <array>
#include <atomic>
#include <initializer_list>
#include <map>
#include <vector>

#include "g435_protocol.h"

namespace {

constexpr USHORT kLogitech = 0x046D;
constexpr USHORT kG435RealtekReceiver = 0x0ACB;
constexpr USHORT kG435HoltekReceiver = 0x0ADF;
constexpr BYTE kRealtekReport = 0x06;
constexpr ULONGLONG kRealtekReadMs = 30ull * 60 * 1000;
constexpr ULONGLONG kRealtekRetryMs = 5ull * 60 * 1000;
constexpr ULONGLONG kHoltekReadMs = 5ull * 60 * 1000;

std::atomic<bool> gForceRealtekRead{ false };
std::atomic<bool> gForceHoltekRead{ false };

bool SendRealtek(HidDev& dev, std::initializer_list<BYTE> frame) {
    std::vector<BYTE> report = { kRealtekReport, 4, 3, 0, static_cast<BYTE>(frame.size()) };
    report.insert(report.end(), frame.begin(), frame.end());
    return dev.SetFeature(report);
}

int ReadRealtekBattery(HidDev& dev) {
    std::vector<BYTE> report;
    if (!dev.SetFeature({ kRealtekReport, 1, 3, 0, 0, 0, 0 })) return 0;
    Sleep(250);
    dev.GetFeature(kRealtekReport, report);

    int millivolts = 0;
    if (SendRealtek(dev, { 0x50, 0x41, 0x0E, 0x00, 0x02, 0xE1, 0x01 })) {
        Sleep(150);
        if (SendRealtek(dev, { 0x50, 0x41, 0x06, 0x00, 0x01, 0x00, 0x31 })) {
            ULONGLONG end = GetTickCount64() + 800;
            while (!millivolts && GetTickCount64() < end) {
                if (dev.GetFeature(kRealtekReport, report) && report.size() > 1) {
                    int value = G435::ParseRealtekMilliVolts(report.data() + 1, report.size() - 1);
                    if (value > 0) millivolts = value;
                }
                if (!millivolts) Sleep(30);
            }
        }
        SendRealtek(dev, { 0x50, 0x41, 0x0E, 0x00, 0x02, 0xE1, 0x00 });
        Sleep(50);
    }

    dev.SetFeature({ kRealtekReport, 8, 3, 0, 0, 0, 0 });
    Sleep(100);
    return millivolts >= 3000 && millivolts <= 4500 ? millivolts : 0;
}

void PollRealtekG435(PollContext& ctx) {
    static bool attempted = false;
    static int lastMillivolts = 0;
    static ULONGLONG lastAttempt = 0;
    static bool hasReading = false;

    if (ctx.IsClaimed(kLogitech, kG435RealtekReceiver)) return;
    auto collections = ctx.Find(kLogitech, kG435RealtekReceiver, [](const HidColl& c) { return c.page() == 0xFFC0 && c.featLen() == 64; });
    if (collections.empty()) {
        attempted = hasReading = false;
        lastMillivolts = 0;
        return;
    }
    ctx.Claim(kLogitech, kG435RealtekReceiver);

    ULONGLONG now = GetTickCount64();
    ULONGLONG interval = hasReading ? kRealtekReadMs : kRealtekRetryMs;
    if (gForceRealtekRead.exchange(false) || !attempted || now - lastAttempt >= interval) {
        HidDev dev;
        if (dev.Open(*collections[0])) {
            int millivolts = ReadRealtekBattery(dev);
            attempted = true;
            lastAttempt = GetTickCount64();
            hasReading = millivolts >= 3000 && millivolts <= 4500;
            if (hasReading) lastMillivolts = millivolts;
        }
    }
    if (!hasReading) return;

    DeviceStatus status;
    status.key = L"g435:" + Hex4(kG435RealtekReceiver);
    status.name = L"Logitech G435";
    status.via = L"LIGHTSPEED receiver";
    status.kind = DeviceKind::Headset;
    status.millivolts = lastMillivolts;
    status.percent = G435::RealtekPercent(lastMillivolts);
    ctx.out.push_back(status);
}

struct CachedStatus {
    DeviceStatus status;
    ULONGLONG nextAttempt = 0;
    bool valid = false;
};

using Report = std::array<std::uint8_t, G435::kReportSize>;

bool SendAndDrain(HidDev& dev, const Report& frame, int waitMs, std::vector<std::vector<BYTE>>* replies = nullptr) {
    std::vector<BYTE> report(dev.coll().outLen(), 0);
    if (report.size() < G435::kReportSize + 1) return false;
    std::copy(frame.begin(), frame.end(), report.begin() + 1);
    if (!dev.Write(report)) return false;

    ULONGLONG end = GetTickCount64() + waitMs;
    std::vector<BYTE> input;
    while ((LONGLONG)end - (LONGLONG)GetTickCount64() > 0) {
        int left = static_cast<int>((LONGLONG)end - (LONGLONG)GetTickCount64());
        int n = dev.Read(input, left);
        if (n > 0 && replies) replies->push_back(input);
        if (n < 0) break;
    }
    return true;
}

Report MakeSessionInit() {
    static constexpr std::uint8_t body[] = {
        0x50, 0x41, 0x06, 0x01, 0x0D, 0x00, 0x25, 0x34, 0x12, 0x5A,
        0x5A, 0x01, 0x00, 0x00, 0x00, 0xF0, 0x00, 0x00, 0x00,
    };
    return G435::Frame(0x80, body, sizeof(body));
}

bool ReadBattery(HidDev& dev, int& mv) {
    static constexpr std::uint8_t enter[] = { 0x01 };
    static constexpr std::uint8_t leave[] = { 0x02 };
    dev.Flush();
    if (!SendAndDrain(dev, G435::Frame(0x84, enter, sizeof(enter)), 50)) return false;
    if (!SendAndDrain(dev, G435::Frame(0x85, enter, sizeof(enter)), 50)) {
        SendAndDrain(dev, G435::Frame(0x85, leave, sizeof(leave)), 50);
        return false;
    }

    std::uint8_t seq = 2;
    auto sendPa = [&](BYTE category, BYTE length, std::initializer_list<std::uint8_t> payload, int waitMs,
                      std::vector<std::vector<BYTE>>* replies = nullptr) {
        std::array<std::uint8_t, 5 + 2> body{};
        body[0] = 0x50;
        body[1] = 0x41;
        body[2] = category;
        body[3] = seq++;
        body[4] = length;
        std::size_t i = 5;
        for (std::uint8_t byte : payload) body[i++] = byte;
        return SendAndDrain(dev, G435::Frame(0x80, body.data(), i), waitMs, replies);
    };

    bool ready = SendAndDrain(dev, MakeSessionInit(), 450);
    if (ready) ready = sendPa(0x0E, 0x01, { 0xE0 }, 120);
    if (ready) ready = sendPa(0x0E, 0x02, { 0xE1, 0x01 }, 120);
    if (ready) ready = sendPa(0x0E, 0x01, { 0xE0 }, 120);
    std::vector<std::vector<BYTE>> replies;
    if (ready) ready = sendPa(0x06, 0x01, { 0x00, 0x31 }, 250, &replies);
    bool closed = SendAndDrain(dev, G435::Frame(0x85, leave, sizeof(leave)), 50);
    if (!ready || !closed) return false;

    for (const auto& reply : replies) {
        int value = G435::ParseMilliVolts(reply.data(), reply.size());
        if (value >= 0) {
            mv = value;
            return true;
        }
    }
    return false;
}

}  // namespace

void PollHoltekG435(PollContext& ctx) {
    static std::map<std::wstring, CachedStatus> cache;

    for (const auto& c : ctx.colls) {
        if (c.vid != kLogitech || c.pid != kG435HoltekReceiver || c.page() != 0xFF00 || c.inLen() < 65 || c.outLen() < 65) continue;
        ctx.Claim(c.vid, c.pid);

        CachedStatus& cached = cache[c.path];
        ULONGLONG now = GetTickCount64();
        if (!gForceHoltekRead.exchange(false) && now < cached.nextAttempt) {
            if (cached.valid) ctx.out.push_back(cached.status);
            break;
        }

        cached.nextAttempt = now + kHoltekReadMs;
        HidDev dev;
        int mv = -1;
        if (dev.Open(c) && ReadBattery(dev, mv)) {
            cached.status.key = L"logi:g435";
            cached.status.name = L"Logitech G435";
            cached.status.via = L"2.4 GHz receiver";
            cached.status.kind = DeviceKind::Headset;
            cached.status.millivolts = mv;
            cached.status.percent = G435::Percent(mv);
            cached.status.asleep = false;
            cached.valid = true;
        } else if (cached.valid) {
            cached.status.asleep = true;
        }

        if (cached.valid) ctx.out.push_back(cached.status);
        break;
    }
}

void G435RequestRead() {
    gForceRealtekRead = true;
    gForceHoltekRead = true;
}

void PollG435(PollContext& ctx) {
    PollRealtekG435(ctx);
    PollHoltekG435(ctx);
}
