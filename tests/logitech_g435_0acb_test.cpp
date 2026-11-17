// Simulated report-6 transport. Never opens real hardware.
#include "../src/drivers/logitech_g435_0acb.cpp"
#ifdef NDEBUG
#undef NDEBUG  // Keep the checks active in optimized test builds, including Zig.
#endif
#include <cassert>
#include <cstdio>

namespace {
std::vector<std::vector<BYTE>> writes;
std::vector<BYTE> feature;
bool failEnter = false, failFeature = false, headsetOff = false, wrongMode = false;
int opens = 0, millivolts = 4146;
void Reset() {
    writes.clear();
    feature.clear();
    failEnter = failFeature = headsetOff = wrongMode = false;
    millivolts = 4146;
}
}
bool HidDev::Open(const HidColl& c) { c_ = c; ++opens; return true; }
void HidDev::Close() {}
void HidDev::Flush() {}
bool HidDev::Write(const std::vector<BYTE>& w, int) {
    writes.push_back(w);
    assert(w[0] == 6 && w[2] == 3);
    if (w[1] == 4) {
        assert(w[3] == w.size() - 5 && w[4] == 0 && w[5] == 0x50 && w[6] == 0x41);
        BYTE cat = w[7], seq = w[8];
        if (cat == 0x0E && w[10] == 0xE3) feature = { 6, 2, 0, 0xE3, (BYTE)!headsetOff };
        else if (cat == 0x0E && w[10] == 0xE1) {
            assert(w[11] == 1);
            wrongMode = false;
            feature = { 6, 3, 0, 0x0E, (BYTE)(seq | 0x80), 0 };
        } else {
            assert(cat == 6 && w[10] == 0 && w[11] == 0x31);
            assert(writes.size() >= 3);  // battery is never the first command
            int mv = wrongMode ? 210 : millivolts;
            feature = { 6, 7, 0, 6, (BYTE)(seq | 0x80), 0, (BYTE)mv, (BYTE)(mv >> 8)};
        }
    }
    return !(failEnter && w[1] == 1);
}
int HidDev::Read(std::vector<BYTE>& r, int) { r = { 6, 0x5A }; return 2; }
bool HidDev::GetFeature(BYTE id, std::vector<BYTE>& r) {
    assert(id == 6);
    if (failFeature) return false;
    r = feature.empty() ? std::vector<BYTE>{ 6, 0xFF } : feature;
    feature.clear();
    return true;
}

int main() {
    HidDev d;
    bool off = false;
    Reset();
    assert(ReadBattery(d, off) == 4146 && !off);
    assert(writes.size() == 4 && writes.back()[1] == 8);
    Reset(); wrongMode = true;
    assert(ReadBattery(d, off) == 4146);
    assert(writes.size() == 6 && writes.back()[1] == 8);
    Reset(); headsetOff = true;
    assert(ReadBattery(d, off) == -1 && off);
    assert(writes.size() == 3 && writes.back()[1] == 8);
    Reset(); failEnter = true;
    assert(ReadBattery(d, off) == -1 && writes.back()[1] == 8);
    Reset(); failFeature = true;
    assert(ReadBattery(d, off) == -1 && writes.back()[1] == 8);
    assert(Battery({ 6, 7, 0, 6, 0x82, 0, 0x32, 0x10 }, 2) == 4146);
    assert(Battery({ 6, 7, 0, 6, 0x81, 0, 0x32, 0x10 }, 2) == -1);
    assert(Battery({ 6, 7, 0, 6, 0x82, 0, 0x32 }, 2) == -1);

    Reset();
    HidColl c;
    c.vid = 0x046D;
    c.pid = 0x0ACB;
    c.path = L"test";
    c.caps.UsagePage = 0xFFC0; c.caps.Usage = 1;
    c.caps.InputReportByteLength = 8; c.caps.OutputReportByteLength = 515;
    c.caps.FeatureReportByteLength = 64;
    PollContext ctx;
    ctx.colls = { c };
    PollLogitechG435Acb(ctx);
    assert(ctx.out.size() == 1 && ctx.out[0].percent == 95 && ctx.IsClaimed(c.vid, c.pid));
    auto count = writes.size();
    millivolts = 3800;
    ctx.claimed.clear();
    ctx.out.clear();
    PollLogitechG435Acb(ctx);
    assert(writes.size() == count && ctx.out[0].percent == 95);
    // Manual refresh obtains a changed value even while the automatic cache is valid.
    ctx.claimed.clear();
    ctx.out.clear();
    ctx.forceRefresh = true;
    PollLogitechG435Acb(ctx);
    assert(writes.size() == count + 4 && ctx.out[0].percent == 55 && ctx.out[0].millivolts == 3800);
    count = writes.size();
    ctx.claimed.clear();
    ctx.out.clear();
    ctx.forceRefresh = false;
    PollLogitechG435Acb(ctx);
    assert(writes.size() == count && ctx.out[0].percent == 55);

    // Manual refresh also bypasses a cached offline result.
    ctx.claimed.clear();
    ctx.out.clear();
    ctx.forceRefresh = true;
    headsetOff = true;
    PollLogitechG435Acb(ctx);
    assert(!ctx.out[0].connected);
    headsetOff = false;
    ctx.claimed.clear();
    ctx.out.clear();
    PollLogitechG435Acb(ctx);
    assert(ctx.out[0].connected && ctx.out[0].percent == 55);
    ctx.forceRefresh = false;
    count = writes.size();
    PollContext absent;
    PollLogitechG435Acb(absent);
    ctx.claimed.clear();
    ctx.out.clear();
    PollLogitechG435Acb(ctx);
    assert(writes.size() > count);  // unplug/replug invalidates cache
    int before = opens;
    ctx.claimed.clear();
    ctx.out.clear(); ctx.colls[0].caps.UsagePage = 0xFFC3;
    PollLogitechG435Acb(ctx);
    assert(opens == before && ctx.out.empty());
    std::puts("logitech_g435_0acb_test: ok");
}
