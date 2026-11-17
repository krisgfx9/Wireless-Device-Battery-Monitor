// Exercise the real SteelSeries driver with the Arctis Pro Wireless DAC's Windows HID framing.
#include "../src/drivers/drivers.h"

#include <cstdio>
#include <cstdlib>

namespace {
void Check(bool condition, const char* expression, int line) {
    if (!condition) {
        std::fprintf(stderr, "Check failed: %s (line %d)\n", expression, line);
        std::exit(EXIT_FAILURE);
    }
}
#define CHECK(condition) Check((condition), #condition, __LINE__)

BYTE connection = 0x04;
int battery = 2;
bool statusTimeout = false;
std::vector<BYTE> pending;
int opens = 0;
int batteryQueries = 0;

HidColl Dac() {
    HidColl c;
    c.path = L"arctis-dac";
    c.vid = 0x1038;
    c.pid = 0x1290;
    c.iface = 0;
    c.caps.UsagePage = 0xFF00;
    c.caps.Usage = 1;
    c.caps.InputReportByteLength = 33;
    c.caps.OutputReportByteLength = 33;
    return c;
}

PollContext PollDac() {
    PollContext ctx;
    ctx.colls = { Dac() };
    PollSteelSeries(ctx);
    return ctx;
}
}  // namespace

// The DAC only replies when the unnumbered report ID (0) precedes the command.
// HidDev::Read has already removed that byte from input reports.
bool HidDev::Open(const HidColl& c) {
    c_ = c;
    h_ = reinterpret_cast<HANDLE>(1);
    ++opens;
    return true;
}
void HidDev::Close() { h_ = INVALID_HANDLE_VALUE; }
void HidDev::Flush() { pending.clear(); }
bool HidDev::Write(const std::vector<BYTE>& data, int) {
    if (data == std::vector<BYTE>{ 0x00, 0x41, 0xAA } && !statusTimeout) pending = { connection, 0x02 };
    if (data == std::vector<BYTE>{ 0x00, 0x40, 0xAA }) {
        ++batteryQueries;
        if (battery >= 0) pending = { (BYTE)battery };
    }
    return true;
}
int HidDev::Read(std::vector<BYTE>& out, int timeoutMs) {
    CHECK(timeoutMs > 0 && timeoutMs <= 1000);
    out = pending;
    pending.clear();
    return out.empty() ? -1 : (int)out.size();
}
std::wstring Hex4(USHORT v) {
    wchar_t text[8];
    swprintf(text, 8, L"%04X", v);
    return text;
}
int Clamp100(int v) { return v < 0 ? 0 : v > 100 ? 100 : v; }
int MapTo100(int v, int lo, int hi) { return Clamp100((v - lo) * 100 / (hi - lo)); }

int main() {
    // A connected DAC must produce a visible headset and the reported battery level.
    auto ctx = PollDac();
    CHECK(ctx.out.size() == 1);
    CHECK(ctx.out[0].connected && ctx.out[0].percent == 50);
    CHECK(ctx.out[0].kind == DeviceKind::Headset);
    CHECK(ctx.out[0].key == L"steelseries:1290");
    CHECK(ctx.IsClaimed(0x1038, 0x1290));

    // All five hardware levels, including an empty battery, remain connected.
    const int expected[] = { 0, 25, 50, 75, 100 };
    for (int raw = 0; raw <= 4; ++raw) {
        battery = raw;
        ctx = PollDac();
        CHECK(ctx.out.size() == 1 && ctx.out[0].connected);
        CHECK(ctx.out[0].percent == expected[raw]);
    }

    // A receiver with the headset switched off must stay hidden and skip the battery query.
    connection = 0x02;
    batteryQueries = 0;
    ctx = PollDac();
    CHECK(ctx.out.size() == 1 && !ctx.out[0].connected && ctx.out[0].percent == -1);
    CHECK(batteryQueries == 0);

    // A failed status query leaves the fallback available; never invent a connection or level.
    statusTimeout = true;
    ctx = PollDac();
    CHECK(ctx.out.empty() && ctx.claimed.empty());
    statusTimeout = false;

    // A confirmed connection with no battery reply retains an unknown level.
    connection = 0x04;
    battery = -1;
    ctx = PollDac();
    CHECK(ctx.out.size() == 1 && ctx.out[0].connected && ctx.out[0].percent == -1);

    // Only query this DAC's writable control interface, and respect existing claims.
    opens = 0;
    ctx = {};
    auto audio = Dac();
    audio.iface = 1;
    auto readOnly = Dac();
    readOnly.caps.OutputReportByteLength = 0;
    auto unrelated = Dac();
    unrelated.vid = 0x1234;
    ctx.colls = { audio, readOnly, unrelated };
    PollSteelSeries(ctx);
    CHECK(opens == 0 && ctx.out.empty());
    ctx.colls = { Dac() };
    ctx.Claim(0x1038, 0x1290);
    PollSteelSeries(ctx);
    CHECK(opens == 0);
    std::puts("SteelSeries driver tests passed (DAC framing, five levels, offline, timeouts, filtering).");
}
