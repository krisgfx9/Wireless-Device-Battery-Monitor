// Exercise the G435 read sequence with a simulated HID transport; no USB writes or hardware needed.
#include "../src/drivers/drivers.h"
#include "../src/drivers/g435_protocol.h"

#include <cassert>
#include <cstdio>
#include <vector>

namespace {

// Mock transport state (single device).
std::vector<std::vector<BYTE>> written;       // every Write payload (report id + bridge op + body)
std::vector<std::vector<BYTE>> readQueue;     // input reports to return, FIFO
std::vector<std::vector<BYTE>> featureQueue;  // feature reports to return, FIFO; empty vector = failure
std::vector<bool> writeOk;                    // per-Write success flag (default true when empty)
int flushCount = 0;
int getFeatureCount = 0;

void Reset() {
    written.clear();
    readQueue.clear();
    featureQueue.clear();
    writeOk.clear();
    flushCount = 0;
    getFeatureCount = 0;
}

HidColl Collection() {
    HidColl c;
    c.path = L"g435";
    c.vid = 0x046D;
    c.pid = 0x0ACB;
    c.caps.UsagePage = 0xFFC0;
    c.caps.Usage = 0x0001;
    c.caps.InputReportByteLength = 8;
    c.caps.OutputReportByteLength = 515;
    c.caps.FeatureReportByteLength = 64;
    return c;
}

std::vector<BYTE> Ack() { return { 0x06, 0x5A }; }
std::vector<BYTE> EmptyFeature() { return { 0x06, 0xFF, 0xFF, 0xFF }; }
std::vector<BYTE> ConnectReply(int v) { return { 0x06, 0x50, 0x49, 0x02, 0x00, 0xE3, (BYTE)v }; }
std::vector<BYTE> BatteryReply(int mv) {
    return { 0x06, 0x50, 0x49, 0x07, 0x00, 0x06, 0x82, 0x00, (BYTE)(mv & 0xFF), (BYTE)(mv >> 8) };
}
std::vector<BYTE> SetModeReply() { return { 0x06, 0x03, 0x00, 0x0E, 0x82, 0x00 }; }
std::vector<BYTE> IncompleteFeature() { return { 0x06, 0x50, 0x49 }; }

bool WroteEnter() {
    for (auto& w : written)
        if (w.size() >= 3 && w[0] == 0x06 && w[1] == 0x01 && w[2] == 0x03) return true;
    return false;
}
bool WroteExit() {
    for (auto& w : written)
        if (w.size() >= 3 && w[0] == 0x06 && w[1] == 0x08 && w[2] == 0x03) return true;
    return false;
}
int SendCount(BYTE category) {
    int n = 0;
    for (auto& w : written)
        if (w.size() >= 8 && w[0] == 0x06 && w[1] == 0x04 && w[2] == 0x03 && w[7] == category) n++;
    return n;
}

}  // namespace

// Stand-in HID transport. The production driver is linked unchanged; only the Win32 calls below
// are replaced.
bool HidDev::Open(const HidColl& c) {
    c_ = c;
    h_ = reinterpret_cast<HANDLE>(1);
    overlapped_ = true;
    return true;
}
void HidDev::Close() { h_ = INVALID_HANDLE_VALUE; }
void HidDev::Flush() { ++flushCount; }
bool HidDev::Write(const std::vector<BYTE>& data, int timeoutMs) {
    (void)timeoutMs;
    written.push_back(data);
    bool ok = true;
    if (!writeOk.empty()) {
        ok = writeOk.front();
        writeOk.erase(writeOk.begin());
    }
    return ok;
}
int HidDev::Read(std::vector<BYTE>& out, int timeoutMs) {
    (void)timeoutMs;
    if (readQueue.empty()) return -1;
    out = readQueue.front();
    readQueue.erase(readQueue.begin());
    return (int)out.size();
}
bool HidDev::GetFeature(BYTE reportId, std::vector<BYTE>& out) {
    (void)reportId;
    ++getFeatureCount;
    if (featureQueue.empty()) return false;
    out = featureQueue.front();
    featureQueue.erase(featureQueue.begin());
    return !out.empty();
}

std::wstring Hex4(USHORT v) {
    wchar_t text[8];
    swprintf(text, 8, L"%04X", v);
    return text;
}

int main() {
    // Happy path: enter, connect=1, battery 4146 mV, leave.
    {
        Reset();
        readQueue = { Ack(), Ack(), Ack(), Ack() };
        featureQueue = { EmptyFeature(), ConnectReply(1), BatteryReply(4146) };
        HidDev d;
        assert(d.Open(Collection()));
        DeviceStatus s;
        G435ReadBattery(d, s);
        assert(s.connected && s.percent == G435::Percent(4146) && s.millivolts == 4146);
        assert(WroteEnter() && WroteExit());
        assert(SendCount(0x0E) == 1 && SendCount(0x06) == 1);
    }

    // Case 1: ACK timeout on enter. The write reaches the device but no ack arrives; the guard
    // still leaves the bootloader and no query runs.
    {
        Reset();
        readQueue = {};  // no ack for enter (nor for the exit attempt)
        HidDev d;
        assert(d.Open(Collection()));
        DeviceStatus s;
        G435ReadBattery(d, s);
        assert(s.connected && s.percent == -1);
        assert(WroteEnter() && WroteExit());
        assert(SendCount(0x0E) == 0 && SendCount(0x06) == 0);
        assert(getFeatureCount == 0);
    }

    // Case 6: enter write fails -> no bootloader entered, no exit, no later operations.
    {
        Reset();
        writeOk.push_back(false);
        HidDev d;
        assert(d.Open(Collection()));
        DeviceStatus s;
        G435ReadBattery(d, s);
        assert(s.connected && s.percent == -1);
        assert(WroteEnter() && !WroteExit());
        assert(SendCount(0x0E) == 0 && SendCount(0x06) == 0);
        assert(getFeatureCount == 0);
    }

    // Case 2: incomplete feature report for GET_BATTERY -> retry, still unknown, leave.
    {
        Reset();
        readQueue = { Ack(), Ack(), Ack(), Ack(), Ack(), Ack() };
        featureQueue = { EmptyFeature(), ConnectReply(1), IncompleteFeature(), {}, SetModeReply(), {} };
        HidDev d;
        assert(d.Open(Collection()));
        DeviceStatus s;
        G435ReadBattery(d, s);
        assert(s.connected && s.percent == -1);
        assert(WroteEnter() && WroteExit());
        assert(SendCount(0x06) == 2);  // initial battery read + retry
    }

    // Case 3: invalid voltage (mode 0 garbage, 210 mV) -> set mode 1 and retry -> unknown, leave.
    {
        Reset();
        readQueue = { Ack(), Ack(), Ack(), Ack(), Ack(), Ack() };
        featureQueue = { EmptyFeature(), ConnectReply(1), BatteryReply(210), SetModeReply(), BatteryReply(210) };
        HidDev d;
        assert(d.Open(Collection()));
        DeviceStatus s;
        G435ReadBattery(d, s);
        assert(s.connected && s.percent == -1 && s.millivolts == 0);
        assert(WroteEnter() && WroteExit());
        assert(SendCount(0x06) == 2);  // initial + retry
        assert(SendCount(0x0E) == 2);  // connect status + set mode
    }

    // Case 4: GET_BATTERY fails (GetFeature error) -> retry -> unknown, leave.
    {
        Reset();
        readQueue = { Ack(), Ack(), Ack(), Ack(), Ack(), Ack() };
        featureQueue = { EmptyFeature(), ConnectReply(1), {}, SetModeReply(), {} };
        HidDev d;
        assert(d.Open(Collection()));
        DeviceStatus s;
        G435ReadBattery(d, s);
        assert(s.connected && s.percent == -1);
        assert(WroteEnter() && WroteExit());
        assert(SendCount(0x06) == 2);
    }

    std::puts("G435 driver tests passed (happy path, ACK timeout, enter failure, incomplete/invalid/failed battery).");
    return 0;
}
