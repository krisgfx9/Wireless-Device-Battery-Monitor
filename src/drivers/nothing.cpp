// Nothing and CMF earbuds / headphones (Nothing Ear (a), Ear (1) / (2) / (3), Ear (open), Headphone (1),
// CMF Buds ...). Windows shows no battery level for them, so they are asked directly over the RFCOMM
// link the Nothing X app uses: service {aeac4a03-dff5-498f-843a-34487cf133eb} (looked up over SDP),
// falling back to channel 15. One read-only "GET battery" request is sent; frame format in
// nothing_protocol.h. Only paired devices that Windows reports as connected and whose name starts
// with "Nothing Ear", "Nothing Headphone" or "CMF" are tried. The link takes one client at a time,
// so if another app holds it the earbuds are skipped for that poll.
#include <winsock2.h>
#include <ws2bth.h>

#include "drivers.h"
#include "nothing_protocol.h"

#include <setupapi.h>
#include <initguid.h>
#include <devpkey.h>

#include <cwchar>
#include <cwctype>

namespace {

// {aeac4a03-dff5-498f-843a-34487cf133eb}
const GUID kNothingLink = { 0xaeac4a03, 0xdff5, 0x498f, { 0x84, 0x3a, 0x34, 0x48, 0x7c, 0xf1, 0x33, 0xeb } };
constexpr ULONG kNothingChannel = 15;

const DEVPROPKEY kIsConnected = { { 0x83DA6326, 0x97A6, 0x4088, { 0x94, 0x53, 0xA1, 0x92, 0x3F, 0x57, 0x3B, 0x29 } }, 15 };

struct Earbuds { std::wstring name; std::wstring addrText; ULONGLONG addr; };

bool LooksLikeNothing(const std::wstring& name) {
    std::wstring n = name;
    for (auto& ch : n) ch = towlower(ch);
    for (const wchar_t* prefix : { L"nothing ear", L"nothing headphone", L"cmf buds", L"cmf headphone" })
        if (n.compare(0, wcslen(prefix), prefix) == 0) return true;
    return false;
}

std::vector<Earbuds> FindConnectedNothing() {
    std::vector<Earbuds> out;
    HDEVINFO di = SetupDiGetClassDevsW(nullptr, L"BTHENUM", nullptr, DIGCF_ALLCLASSES | DIGCF_PRESENT);
    if (di == INVALID_HANDLE_VALUE) return out;
    SP_DEVINFO_DATA dd{ sizeof(dd) };
    for (DWORD i = 0; SetupDiEnumDeviceInfo(di, i, &dd); i++) {
        wchar_t inst[512];
        if (!SetupDiGetDeviceInstanceIdW(di, &dd, inst, 512, nullptr)) continue;
        // The device node itself: BTHENUM\DEV_<12 hex digits address>\...
        if (_wcsnicmp(inst, L"BTHENUM\\DEV_", 12) != 0) continue;
        std::wstring hex(inst + 12, wcsnlen(inst + 12, 12));
        if (hex.size() != 12) continue;
        wchar_t* end = nullptr;
        ULONGLONG addr = wcstoull(hex.c_str(), &end, 16);
        if (!addr || *end) continue;

        DEVPROPTYPE t;
        DEVPROP_BOOLEAN conn = DEVPROP_FALSE;
        if (!SetupDiGetDevicePropertyW(di, &dd, &kIsConnected, &t, (PBYTE)&conn, sizeof(conn), nullptr, 0) ||
            t != DEVPROP_TYPE_BOOLEAN || conn == DEVPROP_FALSE)
            continue;  // never page a device that is not connected (it would only time out)
        wchar_t name[256] = {};
        if (!SetupDiGetDevicePropertyW(di, &dd, &DEVPKEY_Device_FriendlyName, &t, (PBYTE)name, sizeof(name) - sizeof(wchar_t),
                                       nullptr, 0) ||
            t != DEVPROP_TYPE_STRING)
            continue;
        if (!LooksLikeNothing(name)) continue;
        out.push_back({ name, hex, addr });
    }
    SetupDiDestroyDeviceInfoList(di);
    return out;
}

bool StartWinsock() {
    static bool ok = [] {
        WSADATA wsa;
        return WSAStartup(MAKEWORD(2, 2), &wsa) == 0;
    }();
    return ok;
}

// Waits until `s` is readable (read) or connected (write). Returns false on timeout or error.
bool WaitSocket(SOCKET s, bool forWrite, int timeoutMs) {
    fd_set set, err;
    FD_ZERO(&set);
    FD_ZERO(&err);
    FD_SET(s, &set);
    FD_SET(s, &err);
    timeval tv{ timeoutMs / 1000, (timeoutMs % 1000) * 1000 };
    int r = select(0, forWrite ? nullptr : &set, forWrite ? &set : nullptr, &err, &tv);
    return r > 0 && FD_ISSET(s, &set) && !FD_ISSET(s, &err);
}

// Connects (by service UUID, or by channel when `service` is null), asks for the battery and waits
// for the reply. A single deadline covers the whole exchange.
bool ReadBattery(ULONGLONG addr, const GUID* service, Nothing::Status& st) {
    SOCKET s = socket(AF_BTH, SOCK_STREAM, BTHPROTO_RFCOMM);
    if (s == INVALID_SOCKET) return false;
    u_long nonBlocking = 1;
    ioctlsocket(s, FIONBIO, &nonBlocking);
    SOCKADDR_BTH sa{};
    sa.addressFamily = AF_BTH;
    sa.btAddr = addr;
    if (service) sa.serviceClassId = *service;  // Windows looks the RFCOMM channel up over SDP
    else sa.port = kNothingChannel;
    bool found = false;
    if (connect(s, (sockaddr*)&sa, sizeof(sa)) == 0 || (WSAGetLastError() == WSAEWOULDBLOCK && WaitSocket(s, true, 4000))) {
        std::vector<std::uint8_t> req = Nothing::BatteryRequest(1);
        if (send(s, (const char*)req.data(), (int)req.size(), 0) == (int)req.size()) {
            std::vector<std::uint8_t> buf;
            ULONGLONG deadline = GetTickCount64() + 3000;
            while (!found && buf.size() < 8192) {
                ULONGLONG now = GetTickCount64();
                if (now >= deadline || !WaitSocket(s, false, (int)(deadline - now))) break;
                char chunk[512];
                int n = recv(s, chunk, sizeof(chunk), 0);
                if (n <= 0) break;
                buf.insert(buf.end(), chunk, chunk + n);
                found = Nothing::FindBattery(buf.data(), buf.size(), st);
            }
        }
    }
    closesocket(s);
    return found;
}

std::wstring Pct(int v) { return v >= 0 ? std::to_wstring(v) + L"%" : L"-"; }

}  // namespace

void PollNothing(PollContext& ctx) {
    std::vector<Earbuds> list = FindConnectedNothing();
    if (list.empty() || !StartWinsock()) return;
    for (const Earbuds& b : list) {
        Nothing::Status st;
        if (!ReadBattery(b.addr, &kNothingLink, st) && !ReadBattery(b.addr, nullptr, st)) continue;
        DeviceStatus s;
        s.key = L"nothing:" + b.addrText;
        s.name = b.name;  // the same name the Bluetooth fallback uses, so it skips these earbuds
        s.via = L"Bluetooth";
        s.kind = DeviceKind::Headset;
        if (st.headset >= 0) {
            s.percent = st.headset;
            s.charging = st.headsetCharging;
        } else {
            // The tray shows the lower of the two earbuds; the tooltip lists all three parts.
            if (st.left >= 0 && st.right >= 0) s.percent = st.left < st.right ? st.left : st.right;
            else s.percent = st.left >= 0 ? st.left : st.right;
            s.charging = st.leftCharging || st.rightCharging;
            s.detail = L"L " + Pct(st.left) + L", R " + Pct(st.right);
            if (st.caseLevel >= 0) s.detail += L", case " + Pct(st.caseLevel);
        }
        s.graceSec = 180;  // a busy link should not make them flicker
        ctx.out.push_back(s);
    }
}
