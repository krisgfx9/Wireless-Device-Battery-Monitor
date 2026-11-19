// 4-tier Linux fallback battery poller and diagnostic dump:
//   Tier 1: /sys/class/power_supply/*
//   Tier 2: UPower D-Bus (org.freedesktop.UPower)
//   Tier 3: BlueZ D-Bus (org.bluez)
//   Tier 4: Standard HID Battery Descriptor fallback (PollGenericHid)

#include "power_linux.h"

#ifndef __linux__

void PollGenericHid(PollContext&) {}
void PollLinuxPower(PollContext&) {}
std::wstring DumpLinuxPower() { return {}; }

#else

#include "../hid.h"
#include "../platform_compat.h"

#if __has_include(<gio/gio.h>)
#include <gio/gio.h>
#define HAVE_GIO_DBUS 1
#else
#define HAVE_GIO_DBUS 0
#endif

#if __has_include(<linux/hidraw.h>)
#include <linux/hidraw.h>
#include <sys/ioctl.h>
#define HAVE_LINUX_HIDRAW 1
#else
#define HAVE_LINUX_HIDRAW 0
#endif

#include <fcntl.h>
#include <unistd.h>

#include <algorithm>
#include <cctype>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cwctype>
#include <filesystem>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>

namespace fs = std::filesystem;

namespace {

std::string TrimStr(std::string s) {
    size_t a = 0, b = s.size();
    while (a < b && std::isspace((unsigned char)s[a])) ++a;
    while (b > a && std::isspace((unsigned char)s[b - 1])) --b;
    return s.substr(a, b - a);
}

std::wstring TrimWideStr(std::wstring s) {
    size_t a = 0, b = s.size();
    while (a < b && std::iswspace((wint_t)s[a])) ++a;
    while (b > a && std::iswspace((wint_t)s[b - 1])) --b;
    return s.substr(a, b - a);
}

std::string ToLowerStr(std::string s) {
    for (char& c : s) c = (char)std::tolower((unsigned char)c);
    return s;
}

std::wstring ToLowerWide(std::wstring s) {
    for (wchar_t& c : s) c = (wchar_t)std::towlower((wint_t)c);
    return s;
}

bool StartsWithIgnoreCase(const std::string& s, const char* prefix) {
    size_t n = std::strlen(prefix);
    if (s.size() < n) return false;
    for (size_t i = 0; i < n; ++i) {
        if (std::tolower((unsigned char)s[i]) != std::tolower((unsigned char)prefix[i]))
            return false;
    }
    return true;
}

bool ReadFileLine(const fs::path& p, std::string& out) {
    std::ifstream f(p);
    if (!f.is_open()) return false;
    if (!std::getline(f, out)) return false;
    out = TrimStr(out);
    return true;
}

std::string ReadSysfsAttr(const fs::path& dir, const char* name) {
    std::string val;
    if (ReadFileLine(dir / name, val)) return val;
    return {};
}

std::map<std::string, std::string> ReadUeventMap(const fs::path& ueventFile) {
    std::map<std::string, std::string> m;
    std::ifstream f(ueventFile);
    std::string line;
    while (std::getline(f, line)) {
        line = TrimStr(line);
        auto eq = line.find('=');
        if (eq != std::string::npos) {
            m[line.substr(0, eq)] = line.substr(eq + 1);
        }
    }
    return m;
}

bool IsHexChar(char c) {
    return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
}

// Extracts a normalized 12-hex-digit uppercase MAC (e.g. "AABBCCDDEEFF") if present in `s`.
std::string ExtractNormalizedMac(const std::string& s) {
    // 1. Check for XX:XX:XX:XX:XX:XX or XX-XX-XX-XX-XX-XX pattern.
    if (s.size() >= 17) {
        for (size_t i = 0; i + 17 <= s.size(); ++i) {
            char sep = s[i + 2];
            if (sep != ':' && sep != '-') continue;
            bool ok = true;
            std::string hex;
            hex.reserve(12);
            for (int part = 0; part < 6; ++part) {
                size_t pos = i + (size_t)part * 3;
                if (part > 0 && s[pos - 1] != sep) { ok = false; break; }
                if (!IsHexChar(s[pos]) || !IsHexChar(s[pos + 1])) { ok = false; break; }
                hex.push_back((char)std::toupper((unsigned char)s[pos]));
                hex.push_back((char)std::toupper((unsigned char)s[pos + 1]));
            }
            if (ok && hex.size() == 12) return hex;
        }
    }
    // 2. Check if the string (or suffix after colon) is exactly 12 hex digits.
    auto check12 = [](const std::string& sub) -> std::string {
        if (sub.size() != 12) return {};
        std::string hex;
        hex.reserve(12);
        for (char c : sub) {
            if (!IsHexChar(c)) return {};
            hex.push_back((char)std::toupper((unsigned char)c));
        }
        return hex;
    };
    if (auto h = check12(s); !h.empty()) return h;
    auto colon = s.rfind(':');
    if (colon != std::string::npos && colon + 13 == s.size()) {
        if (auto h = check12(s.substr(colon + 1)); !h.empty()) return h;
    }
    return {};
}

bool ParseVidPidFromHidId(const std::string& hidId, USHORT& vid, USHORT& pid) {
    unsigned bus = 0, v = 0, p = 0;
    if (std::sscanf(hidId.c_str(), "%x:%x:%x", &bus, &v, &p) == 3 && v != 0 && p != 0) {
        vid = (USHORT)v;
        pid = (USHORT)p;
        return true;
    }
    return false;
}

bool ParseVidPidFromModalias(const std::string& modalias, USHORT& vid, USHORT& pid) {
    // e.g. "usb:v046DpC548d..." or "bluetooth:v05ACp0265d..."
    auto vpos = modalias.find(":v");
    if (vpos == std::string::npos || vpos + 11 > modalias.size()) return false;
    if (modalias[vpos + 6] != 'p') return false;
    unsigned v = 0, p = 0;
    if (std::sscanf(modalias.c_str() + vpos + 2, "%4x", &v) == 1 &&
        std::sscanf(modalias.c_str() + vpos + 7, "%4x", &p) == 1 && v != 0 && p != 0) {
        vid = (USHORT)v;
        pid = (USHORT)p;
        return true;
    }
    return false;
}

bool ParseVidPidFromPath(const std::string& text, USHORT& vid, USHORT& pid) {
    // Looks for BBBB:VVVV:PPPP (such as 0003:046D:C548 or 0005:054C:0CE6)
    for (size_t i = 0; i + 14 <= text.size(); ++i) {
        if (text[i + 4] == ':' && text[i + 9] == ':') {
            unsigned b = 0, v = 0, p = 0;
            if (std::sscanf(text.c_str() + i, "%4x:%4x:%4x", &b, &v, &p) == 3 && v != 0 && p != 0) {
                vid = (USHORT)v;
                pid = (USHORT)p;
                return true;
            }
        }
    }
    return false;
}

// Walks device and up to 4 parent directories in sysfs to find HID_ID/HID_NAME/HID_UNIQ or USB idVendor/idProduct.
void InspectSysfsDeviceAncestry(const fs::path& psyDir,
                                USHORT& vid,
                                USHORT& pid,
                                std::string& hidName,
                                std::string& hidUniq) {
    std::error_code ec;
    fs::path devPath = fs::canonical(psyDir / "device", ec);
    if (ec) devPath = psyDir / "device";

    fs::path cur = devPath;
    for (int depth = 0; depth < 5 && !cur.empty(); ++depth) {
        auto uev = ReadUeventMap(cur / "uevent");
        if (!vid && !pid) {
            auto itId = uev.find("HID_ID");
            if (itId != uev.end()) ParseVidPidFromHidId(itId->second, vid, pid);
        }
        if (!vid && !pid) {
            auto itMod = uev.find("MODALIAS");
            if (itMod != uev.end()) ParseVidPidFromModalias(itMod->second, vid, pid);
        }
        if (!vid && !pid) {
            std::string mod = ReadSysfsAttr(cur, "modalias");
            if (!mod.empty()) ParseVidPidFromModalias(mod, vid, pid);
        }
        if (hidName.empty()) {
            auto itNm = uev.find("HID_NAME");
            if (itNm != uev.end()) hidName = TrimStr(itNm->second);
        }
        if (hidUniq.empty()) {
            auto itUq = uev.find("HID_UNIQ");
            if (itUq != uev.end()) hidUniq = TrimStr(itUq->second);
        }
        if (!vid && !pid) {
            std::string vStr = ReadSysfsAttr(cur, "idVendor");
            std::string pStr = ReadSysfsAttr(cur, "idProduct");
            if (!vStr.empty() && !pStr.empty()) {
                unsigned v = 0, p = 0;
                if (std::sscanf(vStr.c_str(), "%x", &v) == 1 &&
                    std::sscanf(pStr.c_str(), "%x", &p) == 1 && v && p) {
                    vid = (USHORT)v;
                    pid = (USHORT)p;
                }
            }
        }
        if (hidName.empty()) {
            std::string prod = ReadSysfsAttr(cur, "product");
            if (!prod.empty()) hidName = prod;
        }
        if (hidUniq.empty()) {
            std::string uniq = ReadSysfsAttr(cur, "uniq");
            if (!uniq.empty()) hidUniq = uniq;
        }
        fs::path parent = cur.parent_path();
        if (parent == cur || parent == "/sys" || parent == "/sys/devices") break;
        cur = parent;
    }
}

bool IsAlreadyInOut(const PollContext& ctx,
                    USHORT vid,
                    USHORT pid,
                    const std::string& macNorm,
                    const std::string& serial,
                    const std::string& nativePath,
                    const std::wstring& candidateName) {
    if (vid != 0 && pid != 0 && ctx.IsClaimed(vid, pid)) return true;

    std::wstring candLower = TrimWideStr(ToLowerWide(candidateName));
    std::string serialLower = TrimStr(ToLowerStr(serial));
    std::string nativeLower = TrimStr(ToLowerStr(nativePath));

    for (const auto& existing : ctx.out) {
        std::string keyUtf8 = WideToUtf8(existing.key);
        std::string keyLower = ToLowerStr(keyUtf8);

        if (!macNorm.empty()) {
            std::string existMac = ExtractNormalizedMac(keyUtf8);
            if (!existMac.empty() && existMac == macNorm) return true;
        }
        if (!serialLower.empty() && serialLower.size() >= 4) {
            if (keyLower.find(serialLower) != std::string::npos) return true;
        }
        if (!nativeLower.empty() && nativeLower.size() >= 3) {
            if (keyLower.find(nativeLower) != std::string::npos) return true;
        }
        if (!candLower.empty()) {
            std::wstring existLower = TrimWideStr(ToLowerWide(existing.name));
            if (existLower == candLower) return true;
            if (vid != 0 && existing.vid == vid && existLower.size() >= 5 && candLower.size() >= 5) {
                if (existLower.find(candLower) != std::wstring::npos ||
                    candLower.find(existLower) != std::wstring::npos)
                    return true;
            }
        }
    }
    return false;
}

bool IsSystemPowerSupply(const std::string& entryName,
                         const std::string& type,
                         const std::string& scope) {
    if (StartsWithIgnoreCase(type, "Mains") || StartsWithIgnoreCase(type, "USB") ||
        StartsWithIgnoreCase(type, "UPS"))
        return true;
    if (StartsWithIgnoreCase(scope, "System")) return true;

    if (!StartsWithIgnoreCase(scope, "Device")) {
        const char* sysPrefixes[] = {
            "BAT", "AC", "ADP", "ucsi", "macsmc", "CMB", "sbs-", "bq27", "axp", "cw2015", "max17"
        };
        for (const char* pfx : sysPrefixes) {
            if (StartsWithIgnoreCase(entryName, pfx)) return true;
        }
    }
    return false;
}

int CoarseCapacityLevel(const std::string& levelText) {
    if (StartsWithIgnoreCase(levelText, "Full")) return 100;
    if (StartsWithIgnoreCase(levelText, "High")) return 75;
    if (StartsWithIgnoreCase(levelText, "Normal")) return 50;
    if (StartsWithIgnoreCase(levelText, "Low")) return 20;
    if (StartsWithIgnoreCase(levelText, "Critical")) return 5;
    return -1;
}

std::string CombineVendorModel(const std::string& vendor, const std::string& model) {
    std::string v = TrimStr(vendor);
    std::string m = TrimStr(model);
    if (v.empty()) return m;
    if (m.empty()) return v;
    if (StartsWithIgnoreCase(m, v.c_str())) return m;
    return v + " " + m;
}

// ---- Tier 1: /sys/class/power_supply/* ---------------------------------------------------------

void PollSysfsPowerSupply(PollContext& ctx) {
    std::error_code ec;
    fs::directory_iterator it("/sys/class/power_supply", ec), end;
    if (ec) return;

    for (; it != end; it.increment(ec)) {
        if (ec) break;
        fs::path dir = it->path();
        std::string entryName = dir.filename().string();

        std::string type = ReadSysfsAttr(dir, "type");
        std::string scope = ReadSysfsAttr(dir, "scope");
        if (IsSystemPowerSupply(entryName, type, scope)) continue;

        std::string present = ReadSysfsAttr(dir, "present");
        if (present == "0") continue;
        std::string online = ReadSysfsAttr(dir, "online");
        if (online == "0") continue;

        int percent = -1;
        std::string capStr = ReadSysfsAttr(dir, "capacity");
        if (!capStr.empty()) {
            try {
                percent = Clamp100(std::stoi(capStr));
            } catch (...) {
                percent = -1;
            }
        }
        std::string capLevel = ReadSysfsAttr(dir, "capacity_level");
        std::wstring levelText;
        if (percent < 0 && !capLevel.empty() && !StartsWithIgnoreCase(capLevel, "Unknown")) {
            percent = CoarseCapacityLevel(capLevel);
            if (percent >= 0) levelText = Utf8ToWide(capLevel);
        }
        if (percent < 0) continue;

        std::string status = ReadSysfsAttr(dir, "status");
        bool charging = StartsWithIgnoreCase(status, "Charging");
        bool full = StartsWithIgnoreCase(status, "Full");

        int millivolts = 0;
        std::string vnowStr = ReadSysfsAttr(dir, "voltage_now");
        if (!vnowStr.empty()) {
            try {
                long long uv = std::stoll(vnowStr);
                if (uv > 0) millivolts = (int)(uv / 1000);
            } catch (...) {
            }
        }

        std::string modelName = ReadSysfsAttr(dir, "model_name");
        std::string manufacturer = ReadSysfsAttr(dir, "manufacturer");
        std::string serialNumber = ReadSysfsAttr(dir, "serial_number");

        USHORT vid = 0, pid = 0;
        std::string hidName, hidUniq;
        InspectSysfsDeviceAncestry(dir, vid, pid, hidName, hidUniq);
        if (!vid && !pid) {
            ParseVidPidFromPath(entryName, vid, pid);
            if (!vid && !pid) {
                std::error_code ec2;
                fs::path real = fs::canonical(dir, ec2);
                if (!ec2) ParseVidPidFromPath(real.string(), vid, pid);
            }
        }

        std::string displayUtf8 = CombineVendorModel(manufacturer, modelName);
        if (displayUtf8.empty()) displayUtf8 = hidName;
        if (displayUtf8.empty()) displayUtf8 = entryName;
        std::wstring name = TrimWideStr(Utf8ToWide(displayUtf8));
        if (name.empty()) name = L"Wireless device";

        std::string macNorm = ExtractNormalizedMac(hidUniq);
        if (macNorm.empty()) macNorm = ExtractNormalizedMac(serialNumber);
        if (macNorm.empty()) macNorm = ExtractNormalizedMac(entryName);

        std::string stableSerial = !serialNumber.empty() ? serialNumber : (!hidUniq.empty() ? hidUniq : entryName);
        if (IsAlreadyInOut(ctx, vid, pid, macNorm, stableSerial, entryName, name)) continue;

        DeviceStatus s;
        s.key = L"sysfs:" + Utf8ToWide(stableSerial);
        s.name = name;
        s.via = L"Kernel";
        s.percent = percent;
        s.levelText = levelText;
        s.charging = charging;
        s.full = full;
        s.millivolts = millivolts;
        s.connected = true;
        s.vid = vid;
        s.kind = (vid && pid) ? KindFromCollections(ctx.colls, vid, pid) : DeviceKind::Other;
        if (s.kind == DeviceKind::Other) s.kind = GuessKind(s.name);

        if (vid && pid) {
            ctx.Add(s, vid, pid);
        } else {
            ctx.out.push_back(std::move(s));
        }
    }
}

#if HAVE_GIO_DBUS

std::string DictGetString(GVariant* dict, const char* key) {
    if (!dict) return {};
    GVariant* v = g_variant_lookup_value(dict, key, G_VARIANT_TYPE_STRING);
    if (!v) return {};
    const gchar* str = g_variant_get_string(v, nullptr);
    std::string out = str ? TrimStr(str) : std::string();
    g_variant_unref(v);
    return out;
}

uint32_t DictGetUint32(GVariant* dict, const char* key, uint32_t def = 0) {
    if (!dict) return def;
    GVariant* v = g_variant_lookup_value(dict, key, G_VARIANT_TYPE_UINT32);
    if (!v) return def;
    uint32_t out = g_variant_get_uint32(v);
    g_variant_unref(v);
    return out;
}

int DictGetByte(GVariant* dict, const char* key, int def = -1) {
    if (!dict) return def;
    GVariant* v = g_variant_lookup_value(dict, key, G_VARIANT_TYPE_BYTE);
    if (!v) return def;
    int out = (int)g_variant_get_byte(v);
    g_variant_unref(v);
    return out;
}

double DictGetDouble(GVariant* dict, const char* key, double def = -1.0) {
    if (!dict) return def;
    GVariant* v = g_variant_lookup_value(dict, key, G_VARIANT_TYPE_DOUBLE);
    if (!v) return def;
    double out = g_variant_get_double(v);
    g_variant_unref(v);
    return out;
}

bool DictGetBool(GVariant* dict, const char* key, bool def = false) {
    if (!dict) return def;
    GVariant* v = g_variant_lookup_value(dict, key, G_VARIANT_TYPE_BOOLEAN);
    if (!v) return def;
    bool out = g_variant_get_boolean(v) != FALSE;
    g_variant_unref(v);
    return out;
}

// ---- Tier 2: UPower D-Bus (org.freedesktop.UPower) ---------------------------------------------

bool IsPeripheralUPowerType(uint32_t type, bool isPresent, bool powerSupply, const std::string& nativePath) {
    // Skip laptop/system batteries and line power.
    if (type == 1 || type == 2 || type == 3) return false;
    if (powerSupply && IsSystemPowerSupply(nativePath, "", "System")) return false;
    switch (type) {
        case 4:   // MediaPlayer
        case 5:   // Mouse
        case 6:   // Keyboard
        case 7:   // Phone
        case 12:  // GamingInput
        case 16:  // Speakers
        case 17:  // Headset
        case 19:  // Headphones
            return true;
        default:
            return isPresent && type != 0;
    }
}

DeviceKind KindFromUPowerType(uint32_t type, const std::wstring& name) {
    switch (type) {
        case 5: return DeviceKind::Mouse;
        case 6: return DeviceKind::Keyboard;
        case 7: return DeviceKind::Phone;
        case 12: return DeviceKind::Gamepad;
        case 4:
        case 16:
        case 17:
        case 19:
            return DeviceKind::Headset;
        default:
            return GuessKind(name);
    }
}

void PollUPowerDbus(PollContext& ctx) {
    GDBusConnection* bus = g_bus_get_sync(G_BUS_TYPE_SYSTEM, nullptr, nullptr);
    if (!bus) return;

    GVariant* reply = g_dbus_connection_call_sync(
        bus,
        "org.freedesktop.UPower",
        "/org/freedesktop/UPower",
        "org.freedesktop.UPower",
        "EnumerateDevices",
        nullptr,
        G_VARIANT_TYPE("(ao)"),
        G_DBUS_CALL_FLAGS_NONE,
        2000,
        nullptr,
        nullptr);
    if (!reply) {
        g_object_unref(bus);
        return;
    }

    GVariant* paths = g_variant_get_child_value(reply, 0);
    GVariantIter iter;
    g_variant_iter_init(&iter, paths);
    const gchar* objPath = nullptr;

    while (g_variant_iter_next(&iter, "&o", &objPath)) {
        if (!objPath) continue;
        GVariant* propReply = g_dbus_connection_call_sync(
            bus,
            "org.freedesktop.UPower",
            objPath,
            "org.freedesktop.DBus.Properties",
            "GetAll",
            g_variant_new("(s)", "org.freedesktop.UPower.Device"),
            G_VARIANT_TYPE("(a{sv})"),
            G_DBUS_CALL_FLAGS_NONE,
            2000,
            nullptr,
            nullptr);
        if (!propReply) continue;

        GVariant* props = g_variant_get_child_value(propReply, 0);
        uint32_t type = DictGetUint32(props, "Type", 0);
        bool isPresent = DictGetBool(props, "IsPresent", true);
        bool powerSupply = DictGetBool(props, "PowerSupply", false);
        std::string nativePath = DictGetString(props, "NativePath");

        if (isPresent && IsPeripheralUPowerType(type, isPresent, powerSupply, nativePath)) {
            double pctDouble = DictGetDouble(props, "Percentage", -1.0);
            int percent = pctDouble >= 0.0 ? Clamp100((int)(pctDouble + 0.5)) : -1;
            if (percent >= 0) {
                uint32_t state = DictGetUint32(props, "State", 0);
                std::string vendor = DictGetString(props, "Vendor");
                std::string model = DictGetString(props, "Model");
                std::string serial = DictGetString(props, "Serial");
                double voltageV = DictGetDouble(props, "Voltage", 0.0);

                std::string displayUtf8 = CombineVendorModel(vendor, model);
                if (displayUtf8.empty()) displayUtf8 = !nativePath.empty() ? nativePath : "UPower device";
                std::wstring name = TrimWideStr(Utf8ToWide(displayUtf8));

                USHORT vid = 0, pid = 0;
                ParseVidPidFromPath(nativePath, vid, pid);

                std::string macNorm = ExtractNormalizedMac(serial);
                if (macNorm.empty()) macNorm = ExtractNormalizedMac(nativePath);

                if (!IsAlreadyInOut(ctx, vid, pid, macNorm, serial, nativePath, name)) {
                    DeviceStatus s;
                    std::string keyId = !serial.empty() ? serial : (!nativePath.empty() ? nativePath : objPath);
                    s.key = L"upower:" + Utf8ToWide(keyId);
                    s.name = name;
                    s.via = L"UPower";
                    s.percent = percent;
                    s.charging = (state == 1);
                    s.full = (state == 4);
                    if (voltageV > 0.0) s.millivolts = (int)(voltageV * 1000.0 + 0.5);
                    s.connected = true;
                    s.vid = vid;
                    s.kind = KindFromUPowerType(type, s.name);
                    if (vid && pid) {
                        ctx.Add(s, vid, pid);
                    } else {
                        ctx.out.push_back(std::move(s));
                    }
                }
            }
        }

        g_variant_unref(props);
        g_variant_unref(propReply);
    }

    g_variant_unref(paths);
    g_variant_unref(reply);
    g_object_unref(bus);
}

// ---- Tier 3: BlueZ D-Bus (org.bluez) -----------------------------------------------------------

DeviceKind KindFromBluezIcon(const std::string& icon, const std::wstring& name) {
    if (icon == "input-mouse") return DeviceKind::Mouse;
    if (icon == "input-keyboard") return DeviceKind::Keyboard;
    if (icon == "input-gaming" || icon == "input-joystick") return DeviceKind::Gamepad;
    if (icon == "audio-headset" || icon == "audio-headphones" || icon == "audio-card")
        return DeviceKind::Headset;
    if (icon == "phone") return DeviceKind::Phone;
    if (icon == "audio-input-microphone") return DeviceKind::Microphone;
    return GuessKind(name);
}

void PollBluezDbus(PollContext& ctx) {
    GDBusConnection* bus = g_bus_get_sync(G_BUS_TYPE_SYSTEM, nullptr, nullptr);
    if (!bus) return;

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
        return;
    }

    GVariant* objects = g_variant_get_child_value(reply, 0);
    GVariantIter objIter;
    g_variant_iter_init(&objIter, objects);
    const gchar* objPath = nullptr;
    GVariant* ifaces = nullptr;

    while (g_variant_iter_next(&objIter, "{&o@a{sa{sv}}}", &objPath, &ifaces)) {
        GVariant* dev1 = g_variant_lookup_value(ifaces, "org.bluez.Device1", G_VARIANT_TYPE("a{sv}"));
        GVariant* bat1 = g_variant_lookup_value(ifaces, "org.bluez.Battery1", G_VARIANT_TYPE("a{sv}"));

        if (dev1 && bat1) {
            bool connected = DictGetBool(dev1, "Connected", false);
            int pct = DictGetByte(bat1, "Percentage", -1);
            if (connected && pct >= 0 && pct <= 100) {
                std::string address = DictGetString(dev1, "Address");
                std::string alias = DictGetString(dev1, "Alias");
                std::string devName = DictGetString(dev1, "Name");
                std::string icon = DictGetString(dev1, "Icon");
                std::string modalias = DictGetString(dev1, "Modalias");

                std::string displayUtf8 = !alias.empty() ? alias : (!devName.empty() ? devName : address);
                if (displayUtf8.empty()) displayUtf8 = "Bluetooth device";
                std::wstring name = TrimWideStr(Utf8ToWide(displayUtf8));

                USHORT vid = 0, pid = 0;
                ParseVidPidFromModalias(modalias, vid, pid);

                std::string macNorm = ExtractNormalizedMac(address);
                if (!IsAlreadyInOut(ctx, vid, pid, macNorm, address, "", name)) {
                    DeviceStatus s;
                    s.key = L"bluez:" + Utf8ToWide(!address.empty() ? address : (objPath ? objPath : ""));
                    s.name = name;
                    s.via = L"Bluetooth";
                    s.percent = Clamp100(pct);
                    s.connected = true;
                    s.vid = vid;
                    s.kind = KindFromBluezIcon(icon, s.name);
                    if (vid && pid) {
                        ctx.Add(s, vid, pid);
                    } else {
                        ctx.out.push_back(std::move(s));
                    }
                }
            }
        }

        if (dev1) g_variant_unref(dev1);
        if (bat1) g_variant_unref(bat1);
        g_variant_unref(ifaces);
    }

    g_variant_unref(objects);
    g_variant_unref(reply);
    g_object_unref(bus);
}

#endif  // HAVE_GIO_DBUS

// ---- Tier 4: Standard HID Battery Descriptor fallback (PollGenericHid) -------------------------

struct HidBatteryField {
    bool isFeature = false;
    BYTE reportId = 0;
    int bitOffset = 0;
    int bitSize = 8;
    int logicalMin = 0;
    int logicalMax = 100;
};

bool IsBatteryHidUsage(USHORT page, USHORT usage) {
    // Generic Device Controls (0x06) Battery Strength (0x20),
    // Battery System (0x85) Absolute State Of Charge (0x65) / Remaining Capacity (0x66),
    // or Power Device (0x84).
    return (page == 0x06 && usage == 0x20) ||
           (page == 0x85 && (usage == 0x65 || usage == 0x66));
}

unsigned ReadHidItemUnsigned(const unsigned char* p, int n) {
    unsigned v = 0;
    for (int i = 0; i < n; ++i) v |= ((unsigned)p[i]) << (8 * i);
    return v;
}

int ReadHidItemSigned(const unsigned char* p, int n) {
    if (n == 1) return (int)(int8_t)p[0];
    if (n == 2) return (int)(int16_t)(p[0] | (p[1] << 8));
    if (n == 4) return (int)(int32_t)(p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24));
    return 0;
}

// Scans a raw HID report descriptor for battery strength / state-of-charge fields.
[[maybe_unused]] std::vector<HidBatteryField> FindBatteryFieldsInDescriptor(const unsigned char* d, size_t n) {
    std::vector<HidBatteryField> fields;
    USHORT usagePage = 0;
    int reportSize = 0, reportCount = 0, reportId = 0;
    int logicalMin = 0, logicalMax = 100;
    std::vector<USHORT> usages;
    USHORT usageMin = 0, usageMax = 0;
    bool hasRange = false;
    std::map<std::pair<bool, int>, int> bitPos;  // (isFeature, reportId) -> bit offset

    size_t i = 0;
    while (i < n) {
        unsigned char prefix = d[i++];
        int size = prefix & 3;
        if (size == 3) size = 4;
        if (i + (size_t)size > n) break;
        unsigned uval = ReadHidItemUnsigned(d + i, size);
        int sval = ReadHidItemSigned(d + i, size);
        i += (size_t)size;

        int type = (prefix >> 2) & 3;
        int tag = (prefix >> 4) & 0x0F;
        if (type == 1) {  // Global
            if (tag == 0) usagePage = (USHORT)uval;
            else if (tag == 1) logicalMin = sval;
            else if (tag == 2) logicalMax = sval;
            else if (tag == 7) reportSize = (int)uval;
            else if (tag == 8) reportId = (int)uval;
            else if (tag == 9) reportCount = (int)uval;
        } else if (type == 2) {  // Local
            if (tag == 0) usages.push_back((USHORT)uval);
            else if (tag == 1) { usageMin = (USHORT)uval; hasRange = true; }
            else if (tag == 2) { usageMax = (USHORT)uval; hasRange = true; }
        } else if (type == 0) {  // Main
            if (tag == 8 || tag == 0x0B) {  // Input (8) or Feature (0x0B)
                bool isFeat = (tag == 0x0B);
                int& offset = bitPos[{isFeat, reportId}];
                for (int k = 0; k < reportCount; ++k) {
                    USHORT u = 0;
                    if (!usages.empty()) {
                        u = usages[std::min((size_t)k, usages.size() - 1)];
                    } else if (hasRange) {
                        u = (USHORT)std::min((int)usageMax, (int)usageMin + k);
                    }
                    if (IsBatteryHidUsage(usagePage, u) && reportSize > 0 && reportSize <= 16) {
                        HidBatteryField bf;
                        bf.isFeature = isFeat;
                        bf.reportId = (BYTE)reportId;
                        bf.bitOffset = offset;
                        bf.bitSize = reportSize;
                        bf.logicalMin = logicalMin;
                        bf.logicalMax = logicalMax;
                        fields.push_back(bf);
                    }
                    offset += reportSize;
                }
            }
            usages.clear();
            hasRange = false;
        }
    }
    return fields;
}

int ExtractFieldValue(const std::vector<BYTE>& buf, bool numbered, const HidBatteryField& bf) {
    size_t payloadStart = numbered ? 1 : 0;
    size_t byteIdx = payloadStart + (size_t)(bf.bitOffset / 8);
    int bitShift = bf.bitOffset % 8;
    if (byteIdx >= buf.size()) return -1;
    unsigned raw = buf[byteIdx];
    if (bf.bitSize + bitShift > 8 && byteIdx + 1 < buf.size()) {
        raw |= ((unsigned)buf[byteIdx + 1]) << 8;
    }
    unsigned mask = (bf.bitSize >= 16) ? 0xFFFFu : ((1u << bf.bitSize) - 1u);
    int val = (int)((raw >> bitShift) & mask);

    if (bf.logicalMax > bf.logicalMin && bf.logicalMax != 100 && val > 100) {
        return Clamp100((val - bf.logicalMin) * 100 / (bf.logicalMax - bf.logicalMin));
    }
    if (val >= 0 && val <= 100) return val;
    if (bf.logicalMax > bf.logicalMin && val >= bf.logicalMin && val <= bf.logicalMax) {
        return Clamp100((val - bf.logicalMin) * 100 / (bf.logicalMax - bf.logicalMin));
    }
    return -1;
}

int TryReadHidCollectionBattery(const HidColl& c) {
    std::vector<HidBatteryField> fields;
#if HAVE_LINUX_HIDRAW
    std::string devNode = WideToUtf8(c.path);
    int fd = ::open(devNode.c_str(), O_RDONLY | O_CLOEXEC);
    if (fd >= 0) {
        int descSize = 0;
        if (ioctl(fd, HIDIOCGRDESCSIZE, &descSize) == 0 && descSize > 0) {
            hidraw_report_descriptor rd{};
            rd.size = (unsigned)descSize;
            if (ioctl(fd, HIDIOCGRDESC, &rd) == 0) {
                fields = FindBatteryFieldsInDescriptor(rd.value, rd.size);
            }
        }
        ::close(fd);
    }
#endif

    HidDev dev;
    if (!dev.OpenFeatureOnly(c) && !dev.OpenReadOnly(c)) return -1;

    // 1. Try descriptor-parsed battery fields first.
    for (const auto& bf : fields) {
        if (bf.isFeature && c.featLen() > 0) {
            std::vector<BYTE> buf;
            if (dev.GetFeature(bf.reportId, buf)) {
                int pct = ExtractFieldValue(buf, bf.reportId != 0, bf);
                if (pct >= 0 && pct <= 100) return pct;
            }
        } else if (!bf.isFeature && c.inLen() > 0) {
            std::vector<BYTE> buf;
            if (dev.Read(buf, 30) > 0) {
                if (bf.reportId == 0 || (!buf.empty() && buf[0] == bf.reportId)) {
                    int pct = ExtractFieldValue(buf, bf.reportId != 0, bf);
                    if (pct >= 0 && pct <= 100) return pct;
                }
            }
        }
    }

    // 2. Fallback for explicit power/battery usage pages (0x84, 0x85, 0x06): probe feature report.
    if (c.featLen() >= 2) {
        for (int rid = 0; rid <= 4; ++rid) {
            std::vector<BYTE> buf;
            if (dev.GetFeature((BYTE)rid, buf) && buf.size() >= 2) {
                BYTE v = buf[1];
                if (v >= 1 && v <= 100) return (int)v;
            }
        }
    }
    return -1;
}

}  // namespace

void PollGenericHid(PollContext& ctx) {
    // Never probe Digitizers (page 0x0D) to avoid disturbing drawing tablets.
    std::set<std::pair<USHORT, USHORT>> digitizers;
    for (const auto& c : ctx.colls) {
        if (c.page() == 0x0D) digitizers.insert({c.vid, c.pid});
    }

    for (const auto& c : ctx.colls) {
        if (ctx.IsClaimed(c.vid, c.pid)) continue;
        if (digitizers.count({c.vid, c.pid})) continue;
        if (c.page() != 0x84 && c.page() != 0x85 && c.page() != 0x06) continue;
        if (!c.featLen() && !c.inLen()) continue;

        std::wstring name = HidProduct(c);
        if (name.empty()) name = L"Wireless device";
        if (IsAlreadyInOut(ctx, c.vid, c.pid, "", "", "", name)) continue;

        int pct = TryReadHidCollectionBattery(c);
        if (pct < 0) continue;

        DeviceStatus s;
        s.name = name;
        s.key = L"hid:" + Hex4(c.vid) + L":" + Hex4(c.pid);
        s.via = L"HID";
        s.kind = KindFromCollections(ctx.colls, c.vid, c.pid);
        if (s.kind == DeviceKind::Other) s.kind = GuessKind(s.name);
        s.percent = pct;
        s.connected = true;
        ctx.Add(s, c.vid, c.pid);
    }
}

void PollLinuxPower(PollContext& ctx) {
    // Tier 1: /sys/class/power_supply/*
    PollSysfsPowerSupply(ctx);

#if HAVE_GIO_DBUS
    // Tier 2: UPower D-Bus (org.freedesktop.UPower)
    PollUPowerDbus(ctx);

    // Tier 3: BlueZ D-Bus (org.bluez)
    PollBluezDbus(ctx);
#endif

    // Tier 4: Standard HID Battery Descriptor fallback
    PollGenericHid(ctx);
}

std::wstring DumpLinuxPower() {
    std::ostringstream os;

    // 1. /sys/class/power_supply
    os << "\n--- Linux power_supply (/sys/class/power_supply) ---\n";
    std::error_code ec;
    fs::directory_iterator it("/sys/class/power_supply", ec), end;
    if (ec) {
        os << "  (not available)\n";
    } else {
        int count = 0;
        for (; it != end; it.increment(ec)) {
            if (ec) break;
            ++count;
            fs::path dir = it->path();
            std::string name = dir.filename().string();
            std::string type = ReadSysfsAttr(dir, "type");
            std::string scope = ReadSysfsAttr(dir, "scope");
            std::string status = ReadSysfsAttr(dir, "status");
            std::string cap = ReadSysfsAttr(dir, "capacity");
            std::string vnow = ReadSysfsAttr(dir, "voltage_now");
            std::string model = ReadSysfsAttr(dir, "model_name");
            std::string mfr = ReadSysfsAttr(dir, "manufacturer");
            std::string serial = ReadSysfsAttr(dir, "serial_number");
            USHORT vid = 0, pid = 0;
            std::string hidName, hidUniq;
            InspectSysfsDeviceAncestry(dir, vid, pid, hidName, hidUniq);

            os << "  " << name << ": type=" << type
               << " scope=" << (scope.empty() ? "-" : scope)
               << " status=" << (status.empty() ? "-" : status)
               << " capacity=" << (cap.empty() ? "-" : cap + "%");
            if (!vnow.empty()) os << " voltage_now=" << vnow;
            if (!mfr.empty() || !model.empty()) os << " model=\"" << CombineVendorModel(mfr, model) << "\"";
            if (!serial.empty()) os << " serial=\"" << serial << "\"";
            if (vid || pid) {
                char hexBuf[16];
                std::snprintf(hexBuf, sizeof(hexBuf), "%04X:%04X", vid, pid);
                os << " id=" << hexBuf;
            }
            if (!hidName.empty()) os << " hid_name=\"" << hidName << "\"";
            if (!hidUniq.empty()) os << " hid_uniq=\"" << hidUniq << "\"";
            os << "\n";
        }
        if (count == 0) os << "  (none)\n";
    }

#if HAVE_GIO_DBUS
    GDBusConnection* bus = g_bus_get_sync(G_BUS_TYPE_SYSTEM, nullptr, nullptr);
    if (bus) {
        // 2. UPower
        os << "\n--- Linux UPower (org.freedesktop.UPower) ---\n";
        GVariant* upReply = g_dbus_connection_call_sync(
            bus, "org.freedesktop.UPower", "/org/freedesktop/UPower",
            "org.freedesktop.UPower", "EnumerateDevices",
            nullptr, G_VARIANT_TYPE("(ao)"), G_DBUS_CALL_FLAGS_NONE, 2000, nullptr, nullptr);
        if (!upReply) {
            os << "  (service unavailable)\n";
        } else {
            GVariant* paths = g_variant_get_child_value(upReply, 0);
            GVariantIter iter;
            g_variant_iter_init(&iter, paths);
            const gchar* objPath = nullptr;
            int count = 0;
            while (g_variant_iter_next(&iter, "&o", &objPath)) {
                if (!objPath) continue;
                GVariant* propReply = g_dbus_connection_call_sync(
                    bus, "org.freedesktop.UPower", objPath,
                    "org.freedesktop.DBus.Properties", "GetAll",
                    g_variant_new("(s)", "org.freedesktop.UPower.Device"),
                    G_VARIANT_TYPE("(a{sv})"), G_DBUS_CALL_FLAGS_NONE, 2000, nullptr, nullptr);
                if (!propReply) continue;
                ++count;
                GVariant* props = g_variant_get_child_value(propReply, 0);
                uint32_t type = DictGetUint32(props, "Type", 0);
                uint32_t state = DictGetUint32(props, "State", 0);
                double pct = DictGetDouble(props, "Percentage", -1.0);
                bool present = DictGetBool(props, "IsPresent", false);
                std::string vendor = DictGetString(props, "Vendor");
                std::string model = DictGetString(props, "Model");
                std::string serial = DictGetString(props, "Serial");
                std::string nativePath = DictGetString(props, "NativePath");

                os << "  " << objPath << ": type=" << type
                   << " state=" << state
                   << " present=" << (present ? "true" : "false")
                   << " pct=" << (int)(pct + 0.5) << "%"
                   << " model=\"" << CombineVendorModel(vendor, model) << "\""
                   << " native=\"" << nativePath << "\"";
                if (!serial.empty()) os << " serial=\"" << serial << "\"";
                os << "\n";

                g_variant_unref(props);
                g_variant_unref(propReply);
            }
            if (count == 0) os << "  (none)\n";
            g_variant_unref(paths);
            g_variant_unref(upReply);
        }

        // 3. BlueZ
        os << "\n--- Linux BlueZ (org.bluez) ---\n";
        GVariant* bzReply = g_dbus_connection_call_sync(
            bus, "org.bluez", "/",
            "org.freedesktop.DBus.ObjectManager", "GetManagedObjects",
            nullptr, G_VARIANT_TYPE("(a{oa{sa{sv}}})"),
            G_DBUS_CALL_FLAGS_NONE, 2000, nullptr, nullptr);
        if (!bzReply) {
            os << "  (service unavailable)\n";
        } else {
            GVariant* objects = g_variant_get_child_value(bzReply, 0);
            GVariantIter objIter;
            g_variant_iter_init(&objIter, objects);
            const gchar* objPath = nullptr;
            GVariant* ifaces = nullptr;
            int count = 0;
            while (g_variant_iter_next(&objIter, "{&o@a{sa{sv}}}", &objPath, &ifaces)) {
                GVariant* dev1 = g_variant_lookup_value(ifaces, "org.bluez.Device1", G_VARIANT_TYPE("a{sv}"));
                GVariant* bat1 = g_variant_lookup_value(ifaces, "org.bluez.Battery1", G_VARIANT_TYPE("a{sv}"));
                if (dev1) {
                    ++count;
                    std::string addr = DictGetString(dev1, "Address");
                    std::string alias = DictGetString(dev1, "Alias");
                    bool conn = DictGetBool(dev1, "Connected", false);
                    std::string icon = DictGetString(dev1, "Icon");
                    int pct = bat1 ? DictGetByte(bat1, "Percentage", -1) : -1;
                    os << "  " << (objPath ? objPath : "") << ": addr=" << addr
                       << " name=\"" << alias << "\""
                       << " connected=" << (conn ? "true" : "false")
                       << " icon=" << (icon.empty() ? "-" : icon)
                       << " battery=" << (pct >= 0 ? std::to_string(pct) + "%" : "n/a")
                       << "\n";
                }
                if (dev1) g_variant_unref(dev1);
                if (bat1) g_variant_unref(bat1);
                g_variant_unref(ifaces);
            }
            if (count == 0) os << "  (none)\n";
            g_variant_unref(objects);
            g_variant_unref(bzReply);
        }

        g_object_unref(bus);
    }
#endif

    return Utf8ToWide(os.str());
}

#endif  // __linux__
