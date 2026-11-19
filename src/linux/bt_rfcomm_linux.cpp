// Linux Bluetooth RFCOMM battery pollers for Samsung Galaxy Buds and Nothing Ear / CMF Buds.
//
// Uses BlueZ D-Bus (org.bluez GetManagedObjects) to discover connected earbuds and opens a
// non-blocking AF_BLUETOOTH / BTPROTO_RFCOMM socket directly via <sys/socket.h> without requiring
// libbluetooth-dev headers. Protocol framing and CRC verification are shared with Windows via
// src/drivers/galaxy_buds_protocol.h and src/drivers/nothing_ear_protocol.h.

#include "../drivers/drivers.h"
#include "../drivers/galaxy_buds_protocol.h"
#include "../drivers/nothing_ear_protocol.h"
#include "../platform_compat.h"

#ifndef __linux__

void PollGalaxyBuds(PollContext&) {}
void PollNothingEar(PollContext&) {}

#else

#if __has_include(<gio/gio.h>)
#include <gio/gio.h>
#define HAVE_GIO_DBUS 1
#else
#define HAVE_GIO_DBUS 0
#endif

#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/socket.h>
#include <unistd.h>

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cwctype>
#include <map>
#include <mutex>
#include <string>
#include <vector>

#ifndef AF_BLUETOOTH
#define AF_BLUETOOTH 31
#endif
#ifndef PF_BLUETOOTH
#define PF_BLUETOOTH AF_BLUETOOTH
#endif
#ifndef BTPROTO_RFCOMM
#define BTPROTO_RFCOMM 3
#endif
#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 0
#endif

namespace galaxy_buds {
using Status = GalaxyBuds::Status;
inline bool ParsePacket(const std::uint8_t* data, std::size_t size, bool legacy, Status& out) {
    return GalaxyBuds::FindStatus(data, size, legacy, out);
}
}  // namespace galaxy_buds

namespace nothing_ear {
using Status = NothingEar::Status;
inline bool ParseBattery(const std::uint8_t* data, std::size_t size, Status& out) {
    return NothingEar::FindStatus(data, size, out);
}
}  // namespace nothing_ear

namespace {

struct sockaddr_rc {
    sa_family_t rc_family;
    std::uint8_t rc_bdaddr[6];
    std::uint8_t rc_channel;
};

constexpr ULONGLONG kCacheTtlMs = 60000;  // 60s cache

struct CachedEntry {
    DeviceStatus status;
    ULONGLONG timestampMs = 0;
    std::uint8_t channel = 0;
};

std::mutex g_cacheMu;
std::map<std::string, CachedEntry> g_budsCache;
std::map<std::string, CachedEntry> g_nothingCache;

struct BluezAudioDevice {
    std::wstring name;
    std::string address;          // "AA:BB:CC:DD:EE:FF"
    std::string addrHex;          // "AABBCCDDEEFF"
    std::uint8_t bdaddr[6]{};     // little-endian (reversed) for sockaddr_rc
    std::vector<std::string> uuids;
};

[[maybe_unused]] std::string ToLowerAscii(std::string s) {
    for (char& c : s) c = (char)std::tolower((unsigned char)c);
    return s;
}

std::wstring ToLowerWideStr(std::wstring s) {
    for (wchar_t& c : s) c = (wchar_t)std::towlower((wint_t)c);
    return s;
}

// Parses "AA:BB:CC:DD:EE:FF" into reversed bdaddr_t bytes and 12-char uppercase hex string.
[[maybe_unused]] bool ParseBdAddr(const std::string& addrStr, std::uint8_t outBdaddr[6], std::string& outHex) {
    unsigned int b[6] = {};
    if (std::sscanf(addrStr.c_str(), "%2x:%2x:%2x:%2x:%2x:%2x",
                    &b[0], &b[1], &b[2], &b[3], &b[4], &b[5]) != 6)
        return false;
    char hexBuf[16];
    std::snprintf(hexBuf, sizeof(hexBuf), "%02X%02X%02X%02X%02X%02X",
                  b[0], b[1], b[2], b[3], b[4], b[5]);
    outHex = hexBuf;
    // BlueZ kernel bdaddr_t is little-endian (reversed octet order).
    for (int i = 0; i < 6; ++i) {
        outBdaddr[5 - i] = (std::uint8_t)(b[i] & 0xFF);
    }
    return true;
}

bool HasUuid(const BluezAudioDevice& d, const char* uuidLower) {
    for (const auto& u : d.uuids) {
        if (u == uuidLower) return true;
    }
    return false;
}

bool LooksLikeNothingEar(const BluezAudioDevice& d) {
    if (HasUuid(d, "aeac4a03-dff5-498f-843a-34487cf133eb")) return true;
    std::wstring n = ToLowerWideStr(d.name);
    if (n.find(L"nothing") != std::wstring::npos &&
        (n.find(L"ear") != std::wstring::npos || n.find(L"buds") != std::wstring::npos))
        return true;
    return n.find(L"ear (") != std::wstring::npos ||
           n.find(L"ear 3a") != std::wstring::npos ||
           n.find(L"cmf buds") != std::wstring::npos;
}

bool LooksLikeGalaxyBuds(const BluezAudioDevice& d) {
    if (HasUuid(d, "2e73a4ad-332d-41fc-90e2-16bef06523f2") ||
        HasUuid(d, "00001102-0000-1000-8000-00805f9b34fd"))
        return true;
    if (LooksLikeNothingEar(d)) return false;
    std::wstring n = ToLowerWideStr(d.name);
    return n.find(L"buds") != std::wstring::npos;
}

std::vector<BluezAudioDevice> EnumerateConnectedBluezDevices() {
    std::vector<BluezAudioDevice> out;
#if HAVE_GIO_DBUS
    GDBusConnection* bus = g_bus_get_sync(G_BUS_TYPE_SYSTEM, nullptr, nullptr);
    if (!bus) return out;

    GVariant* reply = g_dbus_connection_call_sync(
        bus,
        "org.bluez",
        "/",
        "org.freedesktop.DBus.ObjectManager",
        "GetManagedObjects",
        nullptr,
        G_VARIANT_TYPE("(a{oa{sa{sv}}})"),
        G_DBUS_CALL_FLAGS_NONE,
        2000,
        nullptr,
        nullptr);
    if (!reply) {
        g_object_unref(bus);
        return out;
    }

    GVariant* objects = g_variant_get_child_value(reply, 0);
    GVariantIter objIter;
    g_variant_iter_init(&objIter, objects);
    const gchar* objPath = nullptr;
    GVariant* ifaces = nullptr;

    while (g_variant_iter_next(&objIter, "{&o@a{sa{sv}}}", &objPath, &ifaces)) {
        GVariant* dev1 = g_variant_lookup_value(ifaces, "org.bluez.Device1", G_VARIANT_TYPE("a{sv}"));
        if (dev1) {
            bool connected = false;
            if (GVariant* vConn = g_variant_lookup_value(dev1, "Connected", G_VARIANT_TYPE_BOOLEAN)) {
                connected = g_variant_get_boolean(vConn) != FALSE;
                g_variant_unref(vConn);
            }
            if (connected) {
                std::string addr, alias, name;
                if (GVariant* vAddr = g_variant_lookup_value(dev1, "Address", G_VARIANT_TYPE_STRING)) {
                    const gchar* s = g_variant_get_string(vAddr, nullptr);
                    if (s) addr = s;
                    g_variant_unref(vAddr);
                }
                if (GVariant* vAlias = g_variant_lookup_value(dev1, "Alias", G_VARIANT_TYPE_STRING)) {
                    const gchar* s = g_variant_get_string(vAlias, nullptr);
                    if (s) alias = s;
                    g_variant_unref(vAlias);
                }
                if (GVariant* vName = g_variant_lookup_value(dev1, "Name", G_VARIANT_TYPE_STRING)) {
                    const gchar* s = g_variant_get_string(vName, nullptr);
                    if (s) name = s;
                    g_variant_unref(vName);
                }

                BluezAudioDevice d;
                d.address = addr;
                std::string chosenName = !alias.empty() ? alias : name;
                d.name = Utf8ToWide(chosenName);
                if (ParseBdAddr(addr, d.bdaddr, d.addrHex) && !d.name.empty()) {
                    if (GVariant* vUuids = g_variant_lookup_value(dev1, "UUIDs", G_VARIANT_TYPE_STRING_ARRAY)) {
                        GVariantIter uIter;
                        g_variant_iter_init(&uIter, vUuids);
                        const gchar* uStr = nullptr;
                        while (g_variant_iter_next(&uIter, "&s", &uStr)) {
                            if (uStr) d.uuids.push_back(ToLowerAscii(uStr));
                        }
                        g_variant_unref(vUuids);
                    }
                    out.push_back(std::move(d));
                }
            }
            g_variant_unref(dev1);
        }
        g_variant_unref(ifaces);
    }

    g_variant_unref(objects);
    g_variant_unref(reply);
    g_object_unref(bus);
#endif
    return out;
}

bool WaitFd(int fd, short events, int timeoutMs) {
    struct pollfd pfd{fd, events, 0};
    int r = ::poll(&pfd, 1, timeoutMs);
    if (r <= 0) return false;
    if (pfd.revents & (POLLERR | POLLHUP | POLLNVAL)) return false;
    return (pfd.revents & events) != 0;
}

int ConnectRfcommChannel(const std::uint8_t bdaddr[6], std::uint8_t channel, int timeoutMs) {
    int fd = ::socket(PF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);
    if (fd < 0) return -1;

    int flags = ::fcntl(fd, F_GETFL, 0);
    if (flags >= 0) ::fcntl(fd, F_SETFL, flags | O_NONBLOCK);

    sockaddr_rc sa{};
    sa.rc_family = AF_BLUETOOTH;
    std::memcpy(sa.rc_bdaddr, bdaddr, 6);
    sa.rc_channel = channel;

    int r = ::connect(fd, reinterpret_cast<struct sockaddr*>(&sa), sizeof(sa));
    if (r < 0) {
        if (errno != EINPROGRESS && errno != EAGAIN) {
            ::close(fd);
            return -1;
        }
        if (!WaitFd(fd, POLLOUT, timeoutMs)) {
            ::close(fd);
            return -1;
        }
        int soErr = 0;
        socklen_t len = sizeof(soErr);
        if (::getsockopt(fd, SOL_SOCKET, SO_ERROR, &soErr, &len) < 0 || soErr != 0) {
            ::close(fd);
            return -1;
        }
    }
    return fd;
}

std::vector<std::uint8_t> CandidateChannels(std::uint8_t preferred,
                                            std::initializer_list<std::uint8_t> defaults) {
    std::vector<std::uint8_t> chans;
    if (preferred >= 1 && preferred <= 30) chans.push_back(preferred);
    for (std::uint8_t c : defaults) {
        if (std::find(chans.begin(), chans.end(), c) == chans.end())
            chans.push_back(c);
    }
    return chans;
}

bool QueryGalaxyBudsRfcomm(const BluezAudioDevice& dev,
                           std::uint8_t& ioChannel,
                           galaxy_buds::Status& outStatus) {
    bool preferLegacy = HasUuid(dev, "00001102-0000-1000-8000-00805f9b34fd");
    auto channels = CandidateChannels(ioChannel, {1, 2, 3, 4, 5, 6});

    for (std::uint8_t ch : channels) {
        int fd = ConnectRfcommChannel(dev.bdaddr, ch, 600);
        if (fd < 0) continue;

        std::vector<std::uint8_t> buf;
        ULONGLONG deadline = GetTickCount64() + 1200;
        bool found = false;

        while (!found && buf.size() < 8192) {
            ULONGLONG now = GetTickCount64();
            if (now >= deadline) break;
            if (!WaitFd(fd, POLLIN, (int)(deadline - now))) break;

            std::uint8_t chunk[512];
            ssize_t n = ::recv(fd, chunk, sizeof(chunk), 0);
            if (n <= 0) break;
            buf.insert(buf.end(), chunk, chunk + n);
            found = galaxy_buds::ParsePacket(buf.data(), buf.size(), preferLegacy, outStatus) ||
                    galaxy_buds::ParsePacket(buf.data(), buf.size(), !preferLegacy, outStatus);
        }
        ::close(fd);
        if (found) {
            ioChannel = ch;
            return true;
        }
    }
    return false;
}

bool QueryNothingEarRfcomm(const BluezAudioDevice& dev,
                           std::uint8_t& ioChannel,
                           nothing_ear::Status& outStatus) {
    auto channels = CandidateChannels(ioChannel, {1, 2, 3, 4, 5, 6});
    auto query = NothingEar::BuildBatteryQuery(1);

    for (std::uint8_t ch : channels) {
        int fd = ConnectRfcommChannel(dev.bdaddr, ch, 600);
        if (fd < 0) continue;

        bool found = false;
        if (::send(fd, query.data(), query.size(), MSG_NOSIGNAL) == (ssize_t)query.size()) {
            std::vector<std::uint8_t> buf;
            ULONGLONG deadline = GetTickCount64() + 1000;
            while (!found && buf.size() < 4096) {
                ULONGLONG now = GetTickCount64();
                if (now >= deadline) break;
                if (!WaitFd(fd, POLLIN, (int)(deadline - now))) break;

                std::uint8_t chunk[512];
                ssize_t n = ::recv(fd, chunk, sizeof(chunk), 0);
                if (n <= 0) break;
                buf.insert(buf.end(), chunk, chunk + n);
                found = nothing_ear::ParseBattery(buf.data(), buf.size(), outStatus);
            }
        }
        ::close(fd);
        if (found) {
            ioChannel = ch;
            return true;
        }
    }
    return false;
}

std::wstring Pct(int v) { return v >= 0 ? std::to_wstring(v) + L"%" : L"-"; }

}  // namespace

void PollGalaxyBuds(PollContext& ctx) {
    auto devices = EnumerateConnectedBluezDevices();
    ULONGLONG now = GetTickCount64();

    for (const auto& d : devices) {
        if (!LooksLikeGalaxyBuds(d)) continue;

        std::uint8_t preferredChan = 0;
        {
            std::lock_guard<std::mutex> lock(g_cacheMu);
            auto it = g_budsCache.find(d.addrHex);
            if (it != g_budsCache.end()) {
                preferredChan = it->second.channel;
                if (now - it->second.timestampMs < kCacheTtlMs) {
                    ctx.out.push_back(it->second.status);
                    continue;
                }
            }
        }

        galaxy_buds::Status st;
        if (!QueryGalaxyBudsRfcomm(d, preferredChan, st)) {
            // Fall back to cached reading if within grace window (180s).
            std::lock_guard<std::mutex> lock(g_cacheMu);
            auto it = g_budsCache.find(d.addrHex);
            if (it != g_budsCache.end() && now - it->second.timestampMs < 180000) {
                ctx.out.push_back(it->second.status);
            }
            continue;
        }

        DeviceStatus s;
        s.key = L"galaxybuds:" + Utf8ToWide(d.addrHex);
        s.name = d.name;
        s.via = L"Bluetooth";
        s.kind = DeviceKind::Headset;
        if (st.left >= 0 && st.right >= 0) s.percent = st.left < st.right ? st.left : st.right;
        else s.percent = st.left >= 0 ? st.left : st.right;
        s.detail = L"L " + Pct(st.left) + L", R " + Pct(st.right);
        if (st.caseLevel >= 0) s.detail += L", case " + Pct(st.caseLevel);
        s.graceSec = 180;

        {
            std::lock_guard<std::mutex> lock(g_cacheMu);
            g_budsCache[d.addrHex] = {s, now, preferredChan};
        }
        ctx.out.push_back(std::move(s));
    }
}

void PollNothingEar(PollContext& ctx) {
    auto devices = EnumerateConnectedBluezDevices();
    ULONGLONG now = GetTickCount64();

    for (const auto& d : devices) {
        if (!LooksLikeNothingEar(d)) continue;

        std::uint8_t preferredChan = 0;
        {
            std::lock_guard<std::mutex> lock(g_cacheMu);
            auto it = g_nothingCache.find(d.addrHex);
            if (it != g_nothingCache.end()) {
                preferredChan = it->second.channel;
                if (now - it->second.timestampMs < kCacheTtlMs) {
                    ctx.out.push_back(it->second.status);
                    continue;
                }
            }
        }

        nothing_ear::Status st;
        if (!QueryNothingEarRfcomm(d, preferredChan, st)) {
            std::lock_guard<std::mutex> lock(g_cacheMu);
            auto it = g_nothingCache.find(d.addrHex);
            if (it != g_nothingCache.end() && now - it->second.timestampMs < 180000) {
                ctx.out.push_back(it->second.status);
            }
            continue;
        }

        DeviceStatus s;
        s.key = L"nothingear:" + Utf8ToWide(d.addrHex);
        s.name = d.name;
        s.via = L"Bluetooth";
        s.kind = DeviceKind::Headset;
        if (st.left >= 0 && st.right >= 0) s.percent = st.left < st.right ? st.left : st.right;
        else s.percent = st.left >= 0 ? st.left : st.right;
        s.charging = st.leftCharging || st.rightCharging;
        s.detail = L"L " + Pct(st.left) + L", R " + Pct(st.right);
        if (st.caseLevel >= 0) s.detail += L", case " + Pct(st.caseLevel);
        s.graceSec = 180;

        {
            std::lock_guard<std::mutex> lock(g_cacheMu);
            g_nothingCache[d.addrHex] = {s, now, preferredChan};
        }
        ctx.out.push_back(std::move(s));
    }
}

#endif  // __linux__
