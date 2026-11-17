// Run the production driver against a simulated feature-report transport.
#include "../src/drivers/drivers.h"

#include <cassert>
#include <cstdio>

namespace {
std::vector<std::vector<BYTE>> replies;
int opens = 0, requests = 0, reads = 0;
bool openOk = true, setOk = true, getOk = true;

HidColl Receiver() {
    HidColl c;
    c.vid = 0x5253;
    c.pid = 0x1020;
    c.iface = 2;
    c.caps.UsagePage = 0xFF01;
    c.caps.Usage = 1;
    c.caps.FeatureReportByteLength = 65;
    return c;
}

// First 21 bytes captured from the M7 Ultra at 73%, discharging.
std::vector<BYTE> Status(BYTE percent = 73, BYTE charge = 0, BYTE flags = 9) {
    std::vector<BYTE> r = { 0x11, 0xF9, 0xAC, 0xAD, 0xCE, 0xFF, 0xFD,
                           0xFA, 0xF8, 0xFF, 0xF6, 0xB6, 0xFF, 0xB6,
                           0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
    r[10] = flags ^ 0xFF;
    r[11] = percent ^ 0xFF;
    r[12] = charge ^ 0xFF;
    return r;
}

PollContext Poll(std::vector<std::vector<BYTE>> frames) {
    replies = std::move(frames);
    requests = reads = 0;
    PollContext ctx;
    ctx.colls = { Receiver() };
    PollMchose(ctx);
    return ctx;
}
}  // namespace

bool HidDev::OpenFeatureOnly(const HidColl& c) {
    ++opens;
    c_ = c;
    if (!openOk) return false;
    h_ = reinterpret_cast<HANDLE>(1);
    return true;
}
void HidDev::Close() { h_ = INVALID_HANDLE_VALUE; }
bool HidDev::SetFeature(const std::vector<BYTE>& data) {
    ++requests;
    assert(data.size() == 21 && data[0] == 0x11 && data[1] == 0xF9);
    for (size_t i = 2; i < data.size(); ++i) assert(data[i] == 0xFF);
    return setOk;
}
bool HidDev::GetFeature(BYTE id, std::vector<BYTE>& out) {
    ++reads;
    assert(id == 0x11);
    if (!getOk) return false;
    if (replies.empty()) out.assign(65, 0);
    else {
        out = replies.front();
        replies.erase(replies.begin());
    }
    return true;
}

int main() {
    auto ctx = Poll({ Status() });
    assert(ctx.out.size() == 1 && ctx.IsClaimed(0x5253, 0x1020));
    const auto& s = ctx.out[0];
    assert(s.name == L"MCHOSE M7 Ultra" && s.key == L"mchose:m7ultra");
    assert(s.percent == 73 && !s.charging && s.kind == DeviceKind::Mouse);
    assert(s.via == L"2.4 GHz receiver" && s.graceSec == 1800);
    assert(requests == 1 && reads == 1);
    for (BYTE percent : { 0, 100 }) {
        ctx = Poll({ Status(percent, 1) });
        assert(ctx.out.size() == 1 && ctx.out[0].percent == percent && ctx.out[0].charging);
    }
    ctx = Poll({ Status(100, 2) });
    assert(ctx.out.size() == 1 && ctx.out[0].percent == 100 && !ctx.out[0].charging);

    // Ignore short, unrelated, invalid and empty replies; do not clamp corrupt percentages.
    auto wrongReport = Status(), wrongCommand = Status();
    wrongReport[0] = 0x12;
    wrongCommand[1] = 0xFC;
    ctx = Poll({ { 0x11, 0xF9 }, wrongReport, wrongCommand, Status(101), {}, Status(42) });
    assert(ctx.out.size() == 1 && ctx.out[0].percent == 42 && requests == 6);
    ctx = Poll({ Status(20, 0xFF) });
    assert(ctx.out.empty() && ctx.claimed.empty() && requests == 6);
    ctx = Poll({});
    assert(ctx.out.empty() && ctx.claimed.empty() && requests == 6);

    // A disconnected receiver or sleeping link must not publish a stale percentage.
    for (BYTE flags : { 1, 6, 7 }) {
        ctx = Poll({ Status(73, 0, flags) });
        assert(ctx.out.empty() && ctx.claimed.empty());
    }
    auto otherModel = Status(), otherVendor = Status(), emptyIdentity = Status();
    otherModel[4] = 0xB0 ^ 0xFF;  // L7 Pro shares the receiver PID
    otherVendor[2] = 0;
    emptyIdentity[2] = emptyIdentity[3] = 0xFF;
    for (auto r : { otherModel, otherVendor, emptyIdentity }) {
        ctx = Poll({ r });
        assert(ctx.out.empty() && ctx.claimed.empty());
    }
    ctx = Poll({ emptyIdentity, Status() });
    assert(ctx.out.size() == 1 && requests == 2);

    opens = 0;
    ctx = {};
    for (int field = 0; field < 6; ++field) {
        auto c = Receiver();
        switch (field) {
        case 0: c.vid = 0x1234; break;
        case 1: c.pid = 0x1021; break;
        case 2: c.iface = 1; break;
        case 3: c.caps.UsagePage = 0xFF0B; break;
        case 4: c.caps.Usage = 0x10; break;
        case 5: c.caps.FeatureReportByteLength = 61; break;
        }
        ctx.colls.push_back(c);
    }
    PollMchose(ctx);
    assert(opens == 0 && ctx.out.empty());
    ctx.colls = { Receiver() };
    ctx.Claim(0x5253, 0x1020);
    PollMchose(ctx);
    assert(opens == 0);

    openOk = false;
    ctx = Poll({ Status() });
    assert(ctx.out.empty() && requests == 0);
    openOk = true;
    setOk = false;
    ctx = Poll({ Status() });
    assert(ctx.out.empty() && requests == 1 && reads == 0);
    setOk = true;
    getOk = false;
    ctx = Poll({ Status() });
    assert(ctx.out.empty() && requests == 1 && reads == 1);
    std::puts("MCHOSE driver tests passed (battery, charging, identity, filtering, retries, failures).");
}
