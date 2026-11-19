// Linux entry point: a StatusNotifierItem (system tray) + floating taskbar widget app built with GTK4/GIO.
//
// 1:1 GUI and menu parity with src/main.cpp (Windows). The polling logic and all vendor drivers are
// shared; only the presentation layer and settings storage ($XDG_CONFIG_HOME/wireless-battery/config.ini) differ.
#include "../platform_compat.h"
#include "../alert_rules.h"
#include "../brands.h"
#include "../device_aliases.h"
#include "../devices.h"
#include "../hid.h"
#include "../history_model.h"
#include "../i18n.h"
#include "../json_output.h"
#include "../labels.h"
#include "ui_linux.h"

#include <gtk/gtk.h>

#include <algorithm>
#include <atomic>
#include <chrono>
#include <climits>
#include <condition_variable>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <cwchar>
#include <map>
#include <mutex>
#include <set>
#include <string>
#include <thread>
#include <vector>

#include <cairo/cairo.h>
#include <unistd.h>

namespace i18n {
void Load();
void Reload();
std::vector<Language> Languages();
std::wstring Current();
void Choose(const std::wstring& code);
bool IsRtl();
void OpenFolder();
const wchar_t* Tr(const wchar_t* en);
std::wstring Tr(const std::wstring& en);
std::wstring Fmt(const wchar_t* en, std::initializer_list<std::pair<const wchar_t*, std::wstring>> args);
}  // namespace i18n

namespace brands {
inline Accent AccentFor(const DeviceStatus& s) { return BrandOf(s); }
inline BrandColor ColorFor(Accent a, bool lightTaskbar = false) { return AccentColor(a, lightTaskbar); }
}  // namespace brands

namespace {

const char* kAppId = "com.github.krisgfx9.WirelessBattery";
const char* kSniPath = "/org/kde/StatusNotifierItem";
const char* kMenuPath = "/Menu";
constexpr int kPollIntervals[] = { 30, 60, 120, 300, 600, 900, 1800, 3600 };
constexpr int kPollIntervalCount = sizeof(kPollIntervals) / sizeof(kPollIntervals[0]);
constexpr int kLowBattery = 15;
constexpr int kIconSize = 64;

struct MenuNode {
    int id = 0;
    int parent = 0;
    std::string label;
    std::string action;
    GVariant* actionParam = nullptr;
    bool separator = false;
    bool toggle = false;
    bool checked = false;
    bool submenu = false;
    bool enabled = true;
};

struct State {
    GtkApplication* app = nullptr;
    GDBusConnection* conn = nullptr;
    GVariant* pixmap = nullptr;           // a(iiay), cached for SNI property reads
    std::string tooltip = "BatteryHub";
    std::vector<DeviceStatus> devices;
    std::map<std::wstring, int> lastKnownPct;
    std::vector<MenuNode> menuNodes;      // com.canonical.dbusmenu tree (id 0 is the root)
    int menuRevision = 0;
    std::mutex mu;
    std::condition_variable cv;
    std::vector<DeviceStatus> pending;
    std::atomic<bool> stop{ false };
    std::atomic<int> pollSeconds{ 60 };
    bool wake = false;
    std::set<std::wstring> hidden;
    std::vector<std::wstring> order;
    aliases::AliasMap aliases;
    std::map<std::wstring, int> alertOverrides;
    std::map<std::wstring, bool> alertLatches;
    bool useBrandAccents = true;
    bool hideLastKnown = false;
    bool showDisconnectedDevices = false;
    bool recordHistory = true;
    bool wantWidget = false;
    bool widgetBackground = false;
    bool stacked = false;
    bool autostart = false;
    bool demo = false;
    bool openHistoryOnStart = false;
};
State g;

// 1:1 DemoDevices() from src/main.cpp lines 995-1030
std::vector<DeviceStatus> DemoDevices() {
    auto make = [](const wchar_t* key, const wchar_t* name, DeviceKind kind, int pct, unsigned short vid, bool charging) {
        DeviceStatus s;
        s.key = key;
        s.name = name;
        s.kind = kind;
        s.percent = pct;
        s.vid = vid;
        s.charging = charging;
        s.via = L"demo";
        return s;
    };
    std::vector<DeviceStatus> devices = {
        make(L"razer:demo", L"Razer DeathAdder V3 Pro", DeviceKind::Mouse, 78, 0x1532, false),
        make(L"demo:logi", L"Logitech G PRO X 2 LIGHTSPEED", DeviceKind::Headset, 64, 0x046D, false),
        make(L"steelseries:demo", L"SteelSeries Arctis Nova 7", DeviceKind::Headset, 55, 0, false),
        make(L"hsc:1b1c:0a6b", L"Corsair HS80 RGB Wireless", DeviceKind::Headset, 81, 0x1B1C, false),
        make(L"hyperx:demo", L"HyperX Cloud III Wireless", DeviceKind::Headset, 47, 0, false),
        make(L"rog:demo", L"ROG Harpe Ace", DeviceKind::Mouse, 90, 0, false),
        make(L"zowie:demo", L"ZOWIE EC2-CW", DeviceKind::Mouse, 66, 0x04A5, false),
        make(L"bt:demo-ps", L"Wireless Controller", DeviceKind::Gamepad, 38, 0x054C, false),
        make(L"xbox:demo", L"Xbox Wireless Controller", DeviceKind::Gamepad, 72, 0x045E, false),
        make(L"bt:demo-buds", L"Galaxy Buds3 Pro", DeviceKind::Headset, 59, 0, false),
        make(L"airpods:demo", L"AirPods Pro", DeviceKind::Headset, 85, 0, false),
        make(L"jabra:demo", L"Jabra Evolve2 65", DeviceKind::Headset, 23, 0x0B0E, false),
        make(L"jbl:demo", L"JBL Quantum 910", DeviceKind::Headset, 70, 0x0ECB, false),
        make(L"coolermaster:demo", L"Cooler Master MM712", DeviceKind::Mouse, 12, 0x2516, false),
        make(L"steam:demo", L"Steam Controller", DeviceKind::Gamepad, 50, 0x28DE, true),
        make(L"bt:demo-plain", L"Bluetooth Headphones", DeviceKind::Headset, 100, 0, true),
    };
    DeviceStatus offline = make(L"demo:offline-receiver", L"Offline wireless headset", DeviceKind::Headset, -1, 0, false);
    offline.via = L"2.4 GHz receiver";
    offline.connected = false;
    devices.push_back(offline);
    return devices;
}

void ClearMenuNodes() {
    for (auto& n : g.menuNodes) {
        if (n.actionParam) {
            g_variant_unref(n.actionParam);
            n.actionParam = nullptr;
        }
    }
    g.menuNodes.clear();
}

std::wstring DeviceDisplayName(const DeviceStatus& s) {
    return aliases::DisplayName(g.aliases, s.key, s.name);
}

void OpenUrl(const char* url) {
    if (!url || !*url) return;
    pid_t pid = fork();
    if (pid == 0) {
        execlp("xdg-open", "xdg-open", url, static_cast<char*>(nullptr));
        _exit(0);
    }
}

// ---- settings (GKeyFile under $XDG_CONFIG_HOME) ------------------------------------------------

std::string ConfigPath() {
    return std::string(g_get_user_config_dir()) + "/wireless-battery/config.ini";
}

bool IsSafeIniKey(const std::string& s) {
    if (s.empty()) return false;
    for (unsigned char c : s) {
        if (!(std::isalnum(c) || c == '-' || c == '_' || c == '.' || c == ':')) return false;
    }
    return true;
}

std::string EncodeConfigKey(const std::wstring& key) {
    std::string utf8 = WideToUtf8(key);
    if (IsSafeIniKey(utf8)) return utf8;
    return battery_history::HexKey(key);
}

std::wstring DecodeConfigKey(const std::string& raw) {
    std::wstring decoded;
    if (battery_history::UnhexKey(raw, decoded)) return decoded;
    return Utf8ToWide(raw);
}

void LoadSettings() {
    g_autoptr(GKeyFile) kf = g_key_file_new();
    g_key_file_load_from_file(kf, ConfigPath().c_str(), G_KEY_FILE_NONE, nullptr);

    g_autofree gchar** hidden = g_key_file_get_string_list(kf, "general", "hidden", nullptr, nullptr);
    if (hidden) {
        for (int i = 0; hidden[i]; i++) g.hidden.insert(Utf8ToWide(hidden[i]));
    }
    g_autofree gchar** orderList = g_key_file_get_string_list(kf, "general", "order", nullptr, nullptr);
    if (orderList) {
        for (int i = 0; orderList[i]; i++) g.order.push_back(Utf8ToWide(orderList[i]));
    }
    g.hideLastKnown = g_key_file_get_boolean(kf, "general", "hide-last-known", nullptr) != FALSE;
    g.showDisconnectedDevices = g_key_file_get_boolean(kf, "general", "show-disconnected", nullptr) != FALSE;
    if (g_key_file_has_key(kf, "general", "record-history", nullptr)) {
        g.recordHistory = g_key_file_get_boolean(kf, "general", "record-history", nullptr) != FALSE;
    } else {
        g.recordHistory = true;
    }
    g.wantWidget = g_key_file_get_boolean(kf, "general", "taskbar-widget", nullptr) != FALSE;
    g.widgetBackground = g_key_file_get_boolean(kf, "general", "widget-background", nullptr) != FALSE;
    g.stacked = g_key_file_get_boolean(kf, "general", "stacked-layout", nullptr) != FALSE;
    g.autostart = g_key_file_get_boolean(kf, "general", "autostart", nullptr) != FALSE;
    if (g_key_file_has_key(kf, "general", "brand-accents", nullptr)) {
        g.useBrandAccents = g_key_file_get_boolean(kf, "general", "brand-accents", nullptr) != FALSE;
    } else {
        g.useBrandAccents = true;
    }
    if (g_key_file_has_key(kf, "general", "poll-seconds", nullptr)) {
        int ps = g_key_file_get_integer(kf, "general", "poll-seconds", nullptr);
        g.pollSeconds = std::clamp(ps, 30, 24 * 60 * 60);
    }

    // Load [aliases]
    g.aliases.clear();
    if (g_key_file_has_group(kf, "aliases")) {
        gsize len = 0;
        g_autofree gchar** keys = g_key_file_get_keys(kf, "aliases", &len, nullptr);
        if (keys) {
            for (gsize i = 0; i < len && g.aliases.size() < aliases::kMaxAliases; ++i) {
                g_autofree gchar* val = g_key_file_get_string(kf, "aliases", keys[i], nullptr);
                if (!val) continue;
                std::wstring devKey = DecodeConfigKey(keys[i]);
                std::wstring alias = aliases::Trim(Utf8ToWide(val));
                if (!devKey.empty() && devKey.size() <= aliases::kMaxDeviceKeyLength && aliases::ValidName(alias)) {
                    g.aliases[devKey] = alias;
                }
            }
        }
    }

    // Load [alerts]
    g.alertOverrides.clear();
    if (g_key_file_has_group(kf, "alerts")) {
        gsize len = 0;
        g_autofree gchar** keys = g_key_file_get_keys(kf, "alerts", &len, nullptr);
        if (keys) {
            for (gsize i = 0; i < len; ++i) {
                GError* err = nullptr;
                int thr = g_key_file_get_integer(kf, "alerts", keys[i], &err);
                if (err) {
                    g_error_free(err);
                    continue;
                }
                std::wstring devKey = DecodeConfigKey(keys[i]);
                if (!devKey.empty() && alerts::ValidOverride(thr)) {
                    g.alertOverrides[devKey] = thr;
                }
            }
        }
    }
}

void SaveSettings() {
    g_autoptr(GKeyFile) kf = g_key_file_new();
    g_key_file_load_from_file(kf, ConfigPath().c_str(), G_KEY_FILE_NONE, nullptr);

    std::vector<std::string> items;
    for (const auto& k : g.hidden) items.push_back(WideToUtf8(k));
    std::vector<const char*> ptrs;
    for (const auto& s : items) ptrs.push_back(s.c_str());
    if (ptrs.empty()) g_key_file_remove_key(kf, "general", "hidden", nullptr);
    else g_key_file_set_string_list(kf, "general", "hidden", ptrs.data(), ptrs.size());

    if (g.order.size() > 64) g.order.resize(64);
    std::vector<std::string> orderItems;
    for (const auto& k : g.order) orderItems.push_back(WideToUtf8(k));
    std::vector<const char*> orderPtrs;
    for (const auto& s : orderItems) orderPtrs.push_back(s.c_str());
    if (orderPtrs.empty()) g_key_file_remove_key(kf, "general", "order", nullptr);
    else g_key_file_set_string_list(kf, "general", "order", orderPtrs.data(), orderPtrs.size());

    g_key_file_set_boolean(kf, "general", "hide-last-known", g.hideLastKnown);
    g_key_file_set_boolean(kf, "general", "show-disconnected", g.showDisconnectedDevices);
    g_key_file_set_boolean(kf, "general", "record-history", g.recordHistory);
    g_key_file_set_boolean(kf, "general", "taskbar-widget", g.wantWidget);
    g_key_file_set_boolean(kf, "general", "widget-background", g.widgetBackground);
    g_key_file_set_boolean(kf, "general", "stacked-layout", g.stacked);
    g_key_file_set_boolean(kf, "general", "autostart", g.autostart);
    g_key_file_set_boolean(kf, "general", "brand-accents", g.useBrandAccents);
    g_key_file_set_integer(kf, "general", "poll-seconds", g.pollSeconds.load());

    // Save [aliases]
    g_key_file_remove_group(kf, "aliases", nullptr);
    size_t aliasCount = 0;
    for (const auto& [devKey, alias] : g.aliases) {
        if (aliasCount >= aliases::kMaxAliases) break;
        if (devKey.empty() || devKey.size() > aliases::kMaxDeviceKeyLength || !aliases::ValidName(alias)) continue;
        std::string k = EncodeConfigKey(devKey);
        std::string v = WideToUtf8(alias);
        g_key_file_set_string(kf, "aliases", k.c_str(), v.c_str());
        ++aliasCount;
    }

    // Save [alerts]
    g_key_file_remove_group(kf, "alerts", nullptr);
    for (const auto& [devKey, thr] : g.alertOverrides) {
        if (devKey.empty() || !alerts::ValidOverride(thr)) continue;
        std::string k = EncodeConfigKey(devKey);
        g_key_file_set_integer(kf, "alerts", k.c_str(), thr);
    }

    std::string path = ConfigPath();
    g_autofree gchar* dir = g_path_get_dirname(path.c_str());
    if (dir) g_mkdir_with_parents(dir, 0700);
    g_key_file_save_to_file(kf, path.c_str(), nullptr);
}

std::string DesktopPath() {
    return std::string(g_get_user_config_dir()) + "/autostart/wireless-battery.desktop";
}

void ApplyAutostart(bool on) {
    std::string path = DesktopPath();
    if (!on) { unlink(path.c_str()); return; }
    g_autofree gchar* dir = g_path_get_dirname(path.c_str());
    if (dir) g_mkdir_with_parents(dir, 0700);
    g_autofree gchar* exe = g_file_read_link("/proc/self/exe", nullptr);
    if (!exe) return;
    std::string content =
        "[Desktop Entry]\nType=Application\nName=BatteryHub\n"
        "Comment=Show battery levels of wireless devices in the tray\n"
        "Exec=\"" + std::string(exe) + "\"\nNoDisplay=true\nX-GNOME-Autostart-enabled=true\n";
    g_file_set_contents(path.c_str(), content.c_str(), (gssize)content.size(), nullptr);
}

// ---- icon rendering (Cairo -> SNI pixmap) ------------------------------------------------------

GVariant* RenderPixmap(int pct, bool charging, bool dim, bool low, Accent accent = Accent::None) {
    const int S = kIconSize;
    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, S, S);
    cairo_t* cr = cairo_create(surface);
    cairo_set_source_rgba(cr, 0, 0, 0, 0);
    cairo_paint(cr);

    bool useBrand = g.useBrandAccents && accent != Accent::None;
    BrandColor bc = brands::ColorFor(accent, false);
    double brandR = bc.r / 255.0;
    double brandG = bc.g / 255.0;
    double brandB = bc.b / 255.0;

    std::string text = pct < 0 ? "?" : std::string(pct >= 100 ? "99" : std::to_string(pct));
    double r = low && !charging ? 0.95 : (charging ? 0.25 : 0.94);
    double gr = low && !charging ? 0.25 : (charging ? 0.72 : 0.96);
    double b = low && !charging ? 0.28 : (charging ? 1.00 : 0.98);
    double alpha = dim ? 0.45 : 1.0;

    if (useBrand && !low && !charging) {
        cairo_pattern_t* glow = cairo_pattern_create_radial(S * 0.5, S * 0.45, 2.0, S * 0.5, S * 0.45, S * 0.45);
        cairo_pattern_add_color_stop_rgba(glow, 0.0, brandR, brandG, brandB, 0.25 * alpha);
        cairo_pattern_add_color_stop_rgba(glow, 1.0, brandR, brandG, brandB, 0.0);
        cairo_set_source(cr, glow);
        cairo_paint(cr);
        cairo_pattern_destroy(glow);
    }

    double fontSize = text.size() >= 3 ? 28 : (text.size() == 2 ? 38 : 46);
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size(cr, fontSize);
    cairo_text_extents_t ext{};
    cairo_text_extents(cr, text.c_str(), &ext);
    cairo_set_source_rgba(cr, r, gr, b, alpha);
    cairo_move_to(cr, (S - ext.width) / 2 - ext.x_bearing, S * 0.48 - (ext.height / 2 + ext.y_bearing));
    cairo_show_text(cr, text.c_str());

    // Level bar.
    int barH = 7, barY = S - barH - 2;
    int fill = pct < 0 ? 0 : std::max(1, (pct * (S - 8)) / 100);
    cairo_set_source_rgba(cr, 1, 1, 1, 0.22);
    cairo_rectangle(cr, 4, barY, S - 8, barH);
    cairo_fill(cr);

    double barR = charging ? 0.20 : (low ? 0.95 : (useBrand ? brandR : 0.20));
    double barG = charging ? 0.70 : (low ? 0.25 : (useBrand ? brandG : 0.80));
    double barB = charging ? 1.00 : (low ? 0.30 : (useBrand ? brandB : 0.45));
    cairo_set_source_rgba(cr, barR, barG, barB, alpha);
    cairo_rectangle(cr, 4, barY, fill, barH);
    cairo_fill(cr);
    cairo_destroy(cr);

    cairo_surface_flush(surface);
    unsigned char* data = cairo_image_surface_get_data(surface);
    int stride = cairo_image_surface_get_stride(surface);
    GByteArray* bytes = g_byte_array_new();
    for (int y = 0; y < S; y++) {
        const guint32* row = (const guint32*)(data + y * stride);
        for (int x = 0; x < S; x++) {
            guint32 p = row[x];  // native-endian ARGB32
            guint8 a = (p >> 24) & 0xFF, rr = (p >> 16) & 0xFF, gg = (p >> 8) & 0xFF, bb = p & 0xFF;
            guint8 px[4] = { a, rr, gg, bb };  // SNI wants A,R,G,B bytes
            g_byte_array_append(bytes, px, 4);
        }
    }
    cairo_surface_destroy(surface);

    GVariant* flat = g_variant_new_from_data(
        G_VARIANT_TYPE("ay"), bytes->data, bytes->len, TRUE,
        +[](gpointer p) { g_byte_array_unref(static_cast<GByteArray*>(p)); }, bytes);
    GVariant* item = g_variant_new("(ii@ay)", S, S, flat);
    GVariant* arr = g_variant_new_array(G_VARIANT_TYPE("(iiay)"), &item, 1);
    return g_variant_ref_sink(arr);
}

// ---- presentation state (1:1 with src/main.cpp) -----------------------------------------------

std::wstring StatusText(const DeviceStatus& s) {
    if (!s.connected) return i18n::Tr(L"off / not connected");
    std::wstring t;
    auto lastIt = g.lastKnownPct.find(s.key);
    int lastPct = lastIt != g.lastKnownPct.end() ? lastIt->second : -1;
    if (!s.levelText.empty() && s.percent >= 0) t = i18n::Tr(s.levelText);
    else if (s.percent >= 0) t = std::to_wstring(s.percent) + L"%";
    else if (lastPct >= 0) t = i18n::Fmt(L"{percent}% (last known)", { { L"percent", std::to_wstring(lastPct) } });
    else t = i18n::Tr(L"unknown");
    if (!s.detail.empty() && s.percent >= 0) t += L" (" + s.detail + L")";
    if (s.full || (s.charging && s.percent >= 100)) t += std::wstring(L", ") + i18n::Tr(L"fully charged");
    else if (s.charging) t += std::wstring(L", ") + i18n::Tr(L"charging");
    if (s.asleep) t += std::wstring(L", ") + i18n::Tr(L"asleep");
    return t;
}

bool IsEntryHidden(const DeviceStatus& s) {
    if (g.hidden.count(s.key)) return true;
    if (g.showDisconnectedDevices && !s.connected) return false;
    return g.hideLastKnown && (s.asleep || s.percent < 0);
}

bool IsShown(const DeviceStatus& s) {
    return (s.connected || g.showDisconnectedDevices) && !IsEntryHidden(s);
}

int KindOrder(DeviceKind k) {
    switch (k) {
        case DeviceKind::Headset: return 0;
        case DeviceKind::Mouse: return 1;
        case DeviceKind::Keyboard: return 2;
        case DeviceKind::Gamepad: return 3;
        case DeviceKind::Phone: return 4;
        default: return 5;
    }
}

// OrderedEntries(shownOnly) matching src/main.cpp lines 558-574
std::vector<const DeviceStatus*> OrderedDevices(bool shownOnly) {
    std::vector<const DeviceStatus*> list;
    for (const auto& s : g.devices) {
        if (!shownOnly) {
            if (!s.connected && !g.showDisconnectedDevices) continue;
            list.push_back(&s);
        } else if (IsShown(s)) {
            list.push_back(&s);
        }
    }
    auto rank = [](const DeviceStatus* d) {
        auto it = std::find(g.order.begin(), g.order.end(), d->key);
        return it == g.order.end() ? INT_MAX : static_cast<int>(it - g.order.begin());
    };
    std::stable_sort(list.begin(), list.end(), [&](const DeviceStatus* a, const DeviceStatus* b) {
        int ra = rank(a), rb = rank(b);
        if (ra != rb) return ra < rb;
        int ka = KindOrder(a->kind), kb = KindOrder(b->kind);
        if (ka != kb) return ka < kb;
        std::wstring na = DeviceDisplayName(*a), nb = DeviceDisplayName(*b);
        return na != nb ? na < nb : a->key < b->key;
    });
    return list;
}

void EmitSignal(const char* name) {
    if (!g.conn) return;
    g_dbus_connection_emit_signal(g.conn, nullptr, kSniPath, "org.kde.StatusNotifierItem", name, nullptr, nullptr);
}

void SendLowBatteryNotification(const DeviceStatus& s) {
    std::string title = WideToUtf8(i18n::Tr(L"Low battery"));
    std::string body = WideToUtf8(i18n::Fmt(L"{name} is at {percent}%", {
        { L"name", DeviceDisplayName(s) },
        { L"percent", std::to_wstring(s.percent) }
    }));

    bool sentDbus = false;
    if (g.conn) {
        GVariantBuilder actions;
        g_variant_builder_init(&actions, G_VARIANT_TYPE("as"));
        GVariantBuilder hints;
        g_variant_builder_init(&hints, G_VARIANT_TYPE("a{sv}"));
        g_variant_builder_add(&hints, "{sv}", "urgency", g_variant_new_byte(1));

        GError* err = nullptr;
        GVariant* reply = g_dbus_connection_call_sync(
            g.conn,
            "org.freedesktop.Notifications",
            "/org/freedesktop/Notifications",
            "org.freedesktop.Notifications",
            "Notify",
            g_variant_new("(susss@as@a{sv}i)",
                          "BatteryHub",
                          (guint32)0,
                          "battery-caution-symbolic",
                          title.c_str(),
                          body.c_str(),
                          g_variant_builder_end(&actions),
                          g_variant_builder_end(&hints),
                          5000),
            nullptr,
            G_DBUS_CALL_FLAGS_NONE,
            1500,
            nullptr,
            &err);
        if (reply) {
            g_variant_unref(reply);
            sentDbus = true;
        }
        if (err) g_error_free(err);
    }

    if (g.app && !sentDbus) {
        g_autoptr(GNotification) notif = g_notification_new(title.c_str());
        g_notification_set_body(notif, body.c_str());
        g_notification_set_priority(notif, G_NOTIFICATION_PRIORITY_HIGH);
        std::string notifId = "low-battery-" + battery_history::HexKey(s.key);
        g_application_send_notification(G_APPLICATION(g.app), notifId.c_str(), notif);
    }
}

// ---- com.canonical.dbusmenu -------------------------------------------------------------------

const MenuNode* FindNode(int id) {
    if (id == 0) return nullptr;  // root
    if (id < 0 || (size_t)id > g.menuNodes.size()) return nullptr;
    return &g.menuNodes[id - 1];
}

void AddMenuProperties(GVariantBuilder& props, const MenuNode* n) {
    if (!n) {
        g_variant_builder_add(&props, "{sv}", "children-display", g_variant_new_string("submenu"));
        return;
    }
    if (n->separator) {
        g_variant_builder_add(&props, "{sv}", "type", g_variant_new_string("separator"));
        return;
    }
    g_variant_builder_add(&props, "{sv}", "label", g_variant_new_string(n->label.c_str()));
    g_variant_builder_add(&props, "{sv}", "enabled", g_variant_new_boolean(n->enabled ? TRUE : FALSE));
    g_variant_builder_add(&props, "{sv}", "visible", g_variant_new_boolean(TRUE));
    if (n->submenu) {
        g_variant_builder_add(&props, "{sv}", "type", g_variant_new_string("standard"));
        g_variant_builder_add(&props, "{sv}", "children-display", g_variant_new_string("submenu"));
        if (n->toggle) {
            g_variant_builder_add(&props, "{sv}", "toggle-type", g_variant_new_string("checkmark"));
            g_variant_builder_add(&props, "{sv}", "toggle-state", g_variant_new_int32(n->checked ? 1 : 0));
        }
        return;
    }
    g_variant_builder_add(&props, "{sv}", "type", g_variant_new_string(n->toggle ? "checkbox" : "standard"));
    if (n->toggle) {
        g_variant_builder_add(&props, "{sv}", "toggle-type", g_variant_new_string("checkmark"));
        g_variant_builder_add(&props, "{sv}", "toggle-state", g_variant_new_int32(n->checked ? 1 : 0));
    }
}

GVariant* BuildLayout(int id, int depth) {
    GVariantBuilder props;
    g_variant_builder_init(&props, G_VARIANT_TYPE("a{sv}"));
    AddMenuProperties(props, FindNode(id));
    GVariantBuilder children;
    g_variant_builder_init(&children, G_VARIANT_TYPE("av"));
    if (depth != 0) {
        for (const auto& n : g.menuNodes)
            if (n.parent == id)
                g_variant_builder_add(&children, "v", BuildLayout(n.id, depth > 0 ? depth - 1 : -1));
    }
    GVariant* layout = g_variant_new("(ia{sv}av)", id, &props, &children);
    g_variant_builder_clear(&props);
    g_variant_builder_clear(&children);
    return g_variant_ref_sink(layout);
}

int AddMenuNode(int parent, const std::string& label, const std::string& action,
                bool separator = false, bool toggle = false, bool checked = false,
                bool submenu = false, GVariant* param = nullptr, bool enabled = true) {
    MenuNode n;
    n.id = (int)g.menuNodes.size() + 1;
    n.parent = parent;
    n.label = label;
    n.action = action;
    n.actionParam = param ? g_variant_ref_sink(param) : nullptr;
    n.separator = separator;
    n.toggle = toggle;
    n.checked = checked;
    n.submenu = submenu;
    n.enabled = enabled;
    int id = n.id;
    g.menuNodes.push_back(std::move(n));
    return id;
}

// 1:1 Menu Layout matching src/main.cpp ShowMenu() lines 809-933
void RebuildMenu() {
    if (!g.app) return;
    ClearMenuNodes();

    auto all = OrderedDevices(false);
    auto shown = OrderedDevices(true);

    if (all.empty()) {
        AddMenuNode(0, WideToUtf8(i18n::Tr(L"No devices with battery info found")), "",
                    false, false, false, false, nullptr, false);
    } else {
        AddMenuNode(0, WideToUtf8(i18n::Tr(L"Point at a device to show, hide or move it")), "",
                    false, false, false, false, nullptr, false);
    }

    for (const auto* s : all) {
        const std::wstring& k = s->key;
        std::string keyUtf8 = WideToUtf8(k);
        bool isHidden = g.hidden.count(k) != 0;
        auto pos = std::find(shown.begin(), shown.end(), s);
        bool canLeft = pos != shown.end() && pos != shown.begin();
        bool canRight = pos != shown.end() && (pos + 1) != shown.end();

        std::wstring line = DeviceDisplayName(*s) + L":  " + StatusText(*s) + L"   [" + i18n::Tr(s->via) + L"]";
        int devSubId = AddMenuNode(0, WideToUtf8(line), "", false, true, !isHidden, true);

        // 1. Show in the tray / Show on the taskbar
        std::wstring showLbl = g.wantWidget ? i18n::Tr(L"Show on the taskbar") : i18n::Tr(L"Show in the tray");
        AddMenuNode(devSubId, WideToUtf8(showLbl), "toggle-device", false, true, !isHidden, false,
                    g_variant_new_string(keyUtf8.c_str()));

        AddMenuNode(devSubId, "", "", true);

        // 2. Move up / Move down (or Move left / Move right in widget mode)
        std::wstring movePrevLbl = g.wantWidget ? i18n::Tr(L"Move left") : i18n::Tr(L"Move up");
        std::wstring moveNextLbl = g.wantWidget ? i18n::Tr(L"Move right") : i18n::Tr(L"Move down");
        AddMenuNode(devSubId, WideToUtf8(movePrevLbl), "move-device", false, false, false, false,
                    g_variant_new("(si)", keyUtf8.c_str(), -1), canLeft);
        AddMenuNode(devSubId, WideToUtf8(moveNextLbl), "move-device", false, false, false, false,
                    g_variant_new("(si)", keyUtf8.c_str(), +1), canRight);

        AddMenuNode(devSubId, "", "", true);

        // 3. Rename device... & Reset to original name
        AddMenuNode(devSubId, WideToUtf8(i18n::Tr(L"Rename device...")), "rename-device", false, false, false, false,
                    g_variant_new_string(keyUtf8.c_str()));
        AddMenuNode(devSubId, WideToUtf8(i18n::Tr(L"Reset to original name")), "reset-device-name",
                    false, false, false, false, g_variant_new_string(keyUtf8.c_str()),
                    g.aliases.count(k) != 0);

        // 4. Battery alerts submenu -> Use default (15%), Disable notifications, separator, 5%..40%
        int alertSubId = AddMenuNode(devSubId, WideToUtf8(i18n::Tr(L"Battery alerts")), "", false, false, false, true);
        int selectedThreshold = alerts::OverrideFor(g.alertOverrides, k);
        AddMenuNode(alertSubId, WideToUtf8(i18n::Tr(L"Use default (15%)")), "set-alert", false, true,
                    selectedThreshold == alerts::kUseDefault, false,
                    g_variant_new("(si)", keyUtf8.c_str(), alerts::kUseDefault));
        AddMenuNode(alertSubId, WideToUtf8(i18n::Tr(L"Disable notifications")), "set-alert", false, true,
                    selectedThreshold == alerts::kDisabled, false,
                    g_variant_new("(si)", keyUtf8.c_str(), alerts::kDisabled));
        AddMenuNode(alertSubId, "", "", true);
        for (int i = 0; i < alerts::kThresholdCount; ++i) {
            int level = alerts::kThresholds[i];
            std::string lvlLabel = std::to_string(level) + "%";
            AddMenuNode(alertSubId, lvlLabel, "set-alert", false, true,
                        selectedThreshold == level, false,
                        g_variant_new("(si)", keyUtf8.c_str(), level));
        }

        // 5. Battery history...
        AddMenuNode(devSubId, WideToUtf8(i18n::Tr(L"Battery history...")), "show-device-history",
                    false, false, false, false, g_variant_new_string(keyUtf8.c_str()));
    }

    // Root toggles & options matching Windows order
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Hide last known / asleep devices")),
                "toggle-last-known", false, true, g.hideLastKnown);
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Show disconnected devices")),
                "toggle-show-disconnected", false, true, g.showDisconnectedDevices);
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Record battery history")),
                "toggle-record-history", false, true, g.recordHistory);

    AddMenuNode(0, "", "", true);

    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Show on the taskbar (icon + percentage)")),
                "set-mode-widget", false, true, g.wantWidget);
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Show as tray icons")),
                "set-mode-tray", false, true, !g.wantWidget);
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Background behind taskbar text (for transparent taskbars)")),
                "toggle-widget-bg", false, true, g.widgetBackground, false, nullptr, g.wantWidget);
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Icons above percentages (narrower)")),
                "toggle-stacked", false, true, g.stacked, false, nullptr, g.wantWidget);
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Brand colors (Razer green, Logitech blue, ...)")),
                "toggle-brand-accents", false, true, g.useBrandAccents);

    AddMenuNode(0, "", "", true);

    // Language submenu -> Automatic + all i18n::Languages() (including O'zbekcha) + Add your own language...
    i18n::Reload();
    auto langs = i18n::Languages();
    std::wstring currentLang = i18n::Current();
    int langMenuId = AddMenuNode(0, WideToUtf8(i18n::Tr(L"Language")), "", false, false, false, true);
    AddMenuNode(langMenuId, WideToUtf8(i18n::Tr(L"Automatic")), "set-lang", false, true,
                currentLang.empty(), false, g_variant_new_string(""));
    AddMenuNode(langMenuId, "", "", true);
    for (const auto& l : langs) {
        bool selected = !currentLang.empty() && wcscasecmp(l.code.c_str(), currentLang.c_str()) == 0;
        AddMenuNode(langMenuId, WideToUtf8(l.name), "set-lang", false, true, selected, false,
                    g_variant_new_string(WideToUtf8(l.code).c_str()));
    }
    AddMenuNode(langMenuId, "", "", true);
    AddMenuNode(langMenuId, WideToUtf8(i18n::Tr(L"Add your own language...")), "lang-open-folder");

    // Check battery every -> 30 s, 1 min, 2 min, 5 min, 10 min, 15 min, 30 min, 60 min
    int pollMenuId = AddMenuNode(0, WideToUtf8(i18n::Tr(L"Check battery every")), "", false, false, false, true);
    int curPoll = g.pollSeconds.load();
    for (int i = 0; i < kPollIntervalCount; ++i) {
        int s = kPollIntervals[i];
        std::wstring label = s < 60
            ? i18n::Fmt(L"{seconds} s", { { L"seconds", std::to_wstring(s) } })
            : i18n::Fmt(L"{minutes} min", { { L"minutes", std::to_wstring(s / 60) } });
        AddMenuNode(pollMenuId, WideToUtf8(label), "set-poll-interval", false, true,
                    curPoll == s, false, g_variant_new_int32(s));
    }

    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Refresh now")), "refresh");
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Start at login")),
                "toggle-autostart", false, true, g.autostart);
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Request support for a device...")), "show-report");
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Support the project...")), "open-support");

    AddMenuNode(0, "", "", true);
    AddMenuNode(0, WideToUtf8(i18n::Tr(L"Exit")), "quit");

    g.menuRevision++;
    if (g.conn)
        g_dbus_connection_emit_signal(g.conn, nullptr, kMenuPath, "com.canonical.dbusmenu",
                                      "LayoutUpdated", g_variant_new("(ii)", g.menuRevision, 0), nullptr);
}

void RecomputePresentation() {
    int pct = -1;
    bool charging = false, dim = false, low = false, any = false;
    Accent accent = Accent::None;
    std::string tip = "BatteryHub";

    auto visiblePtrs = OrderedDevices(true);
    std::vector<DeviceStatus> visibleDevices;
    visibleDevices.reserve(visiblePtrs.size());

    for (const auto* s : visiblePtrs) {
        visibleDevices.push_back(*s);
        any = true;
        int effThr = alerts::EffectiveThreshold(g.alertOverrides, s->key);
        int lowCutoff = effThr > 0 ? effThr : kLowBattery;
        if (s->percent >= 0) {
            pct = s->percent;
            accent = brands::AccentFor(*s);
        } else {
            dim = true;
        }
        charging |= s->charging;
        if (s->percent >= 0 && s->percent <= lowCutoff && !s->charging) low = true;
        if (tip != "BatteryHub") tip += "\n";
        else tip = "";
        tip += WideToUtf8(DeviceDisplayName(*s)) + ": " + WideToUtf8(StatusText(*s));
    }
    if (!any) {
        pct = -1;
        tip = "BatteryHub\n" + WideToUtf8(i18n::Tr(L"No devices with battery info found"));
    }
    if (g.pixmap) g_variant_unref(g.pixmap);
    g.pixmap = RenderPixmap(pct, charging, dim, low, accent);
    g.tooltip = tip;
    RebuildMenu();
    EmitSignal("NewIcon");
    EmitSignal("NewToolTip");
    EmitSignal("NewStatus");

    if (g.app) {
        UpdateLinuxWidgetWindow(
            g.app, g.wantWidget, visibleDevices, g.aliases,
            g.useBrandAccents, g.widgetBackground, g.stacked, g.demo);
    }
}

void ApplyResults() {
    {
        std::lock_guard<std::mutex> lock(g.mu);
        g.devices.swap(g.pending);
    }
    for (const auto& s : g.devices) {
        if (s.percent >= 0) g.lastKnownPct[s.key] = s.percent;
    }
    if (g.recordHistory && !g.demo) {
        RecordLinuxBatteryHistory(g.devices);
    }

    for (const auto& s : g.devices) {
        if (g.hidden.count(s.key)) continue;
        int threshold = alerts::EffectiveThreshold(g.alertOverrides, s.key);
        bool& warned = g.alertLatches[s.key];
        if (alerts::ShouldNotify(s, threshold, warned)) {
            SendLowBatteryNotification(s);
        }
    }
    if (g.alertLatches.size() > 256) {
        g.alertLatches.erase(g.alertLatches.begin());
    }

    RecomputePresentation();

    if (g.openHistoryOnStart && g.app) {
        g.openHistoryOnStart = false;
        std::wstring initialKey = g.devices.empty() ? std::wstring() : g.devices.front().key;
        ShowLinuxBatteryHistoryWindow(g.app, g.devices, g.aliases, initialKey, g.demo);
    }
}

// ---- SNI D-Bus interfaces ---------------------------------------------------------------------

static const char* kSniXml =
    "<node><interface name='org.kde.StatusNotifierItem'>"
    "<property name='Id' type='s' access='read'/>"
    "<property name='Category' type='s' access='read'/>"
    "<property name='Status' type='s' access='read'/>"
    "<property name='Title' type='s' access='read'/>"
    "<property name='IconName' type='s' access='read'/>"
    "<property name='IconPixmap' type='a(iiay)' access='read'/>"
    "<property name='ToolTip' type='(sa(iiay)ss)' access='read'/>"
    "<property name='Menu' type='o' access='read'/>"
    "<property name='ItemIsMenu' type='b' access='read'/>"
    "<signal name='NewIcon'/><signal name='NewToolTip'/><signal name='NewStatus'/>"
    "</interface></node>";

static const char* kAppXml =
    "<node><interface name='com.github.krisgfx9.WirelessBattery'>"
    "<method name='Quit'/>"
    "</interface></node>";

static const char* kMenuXml =
    "<node><interface name='com.canonical.dbusmenu'>"
    "<method name='GetLayout'>"
    "<arg type='i' name='parentId' direction='in'/>"
    "<arg type='i' name='recursionDepth' direction='in'/>"
    "<arg type='as' name='propertyNames' direction='in'/>"
    "<arg type='(ia{sv}av)' name='layout' direction='out'/>"
    "</method>"
    "<method name='GetGroupProperties'>"
    "<arg type='ai' name='ids' direction='in'/>"
    "<arg type='as' name='propertyNames' direction='in'/>"
    "<arg type='a(ia{sv})' name='properties' direction='out'/>"
    "</method>"
    "<method name='GetProperty'>"
    "<arg type='i' name='id' direction='in'/>"
    "<arg type='s' name='name' direction='in'/>"
    "<arg type='v' name='value' direction='out'/>"
    "</method>"
    "<method name='Event'>"
    "<arg type='i' name='id' direction='in'/>"
    "<arg type='s' name='eventId' direction='in'/>"
    "<arg type='v' name='data' direction='in'/>"
    "<arg type='u' name='timestamp' direction='in'/>"
    "</method>"
    "<method name='AboutToShow'><arg type='i' name='id' direction='in'/>"
    "<arg type='b' name='needUpdate' direction='out'/></method>"
    "<signal name='LayoutUpdated'><arg type='i' name='revision'/>"
    "<arg type='i' name='parent'/></signal>"
    "<property name='Revision' type='i' access='read'/>"
    "<property name='TextDirection' type='s' access='read'/>"
    "</interface></node>";

static GVariant* sni_get_property(GDBusConnection*, const gchar*, const gchar*, const gchar*,
                                  const gchar* name, GError**, gpointer) {
    if (!strcmp(name, "Id")) return g_variant_new_string("wireless-battery");
    if (!strcmp(name, "Category")) return g_variant_new_string("SystemServices");
    if (!strcmp(name, "Title")) return g_variant_new_string("BatteryHub");
    if (!strcmp(name, "IconName")) return g_variant_new_string("battery-good-symbolic");
    if (!strcmp(name, "IconPixmap"))
        return g.pixmap ? g_variant_ref(g.pixmap) : RenderPixmap(-1, false, true, false);
    if (!strcmp(name, "ToolTip")) {
        GVariant* px = g.pixmap ? g_variant_ref(g.pixmap) : RenderPixmap(-1, false, true, false);
        return g_variant_new("(s@a(iiay)ss)", "", px, "BatteryHub", g.tooltip.c_str());
    }
    if (!strcmp(name, "Menu")) return g_variant_new_object_path(kMenuPath);
    if (!strcmp(name, "ItemIsMenu")) return g_variant_new_boolean(TRUE);
    if (!strcmp(name, "Status")) {
        bool low = false;
        for (const auto& s : g.devices) {
            int thr = alerts::EffectiveThreshold(g.alertOverrides, s.key);
            int cutoff = thr > 0 ? thr : kLowBattery;
            low |= (s.percent >= 0 && s.percent <= cutoff && !s.charging);
        }
        return g_variant_new_string(low ? "NeedsAttention" : (g.devices.empty() ? "Passive" : "Active"));
    }
    return nullptr;
}

static void app_method_call(GDBusConnection*, const gchar*, const gchar*, const gchar*, const gchar* method,
                            GVariant*, GDBusMethodInvocation* inv, gpointer) {
    if (!strcmp(method, "Quit")) {
        g_dbus_method_invocation_return_value(inv, nullptr);
        g_application_quit(G_APPLICATION(g.app));
    } else g_dbus_method_invocation_return_error(inv, G_DBUS_ERROR, G_DBUS_ERROR_UNKNOWN_METHOD, "Unknown method");
}

static void dbusmenu_method_call(GDBusConnection*, const gchar*, const gchar*, const gchar*,
                                 const gchar* method, GVariant* params,
                                 GDBusMethodInvocation* inv, gpointer) {
    if (!strcmp(method, "GetLayout")) {
        int parent = 0, depth = 0;
        GVariant* names = nullptr;
        g_variant_get(params, "(ii@as)", &parent, &depth, &names);
        GVariantBuilder ret;
        g_variant_builder_init(&ret, G_VARIANT_TYPE("((ia{sv}av))"));
        g_variant_builder_add_value(&ret, BuildLayout(parent, depth));
        g_dbus_method_invocation_return_value(inv, g_variant_builder_end(&ret));
        g_variant_unref(names);
        return;
    }
    if (!strcmp(method, "GetGroupProperties")) {
        GVariant* ids = nullptr, *names = nullptr;
        g_variant_get(params, "(@ai@as)", &ids, &names);
        GVariantBuilder ret, out;
        g_variant_builder_init(&out, G_VARIANT_TYPE("a(ia{sv})"));
        GVariantIter it;
        g_variant_iter_init(&it, ids);
        gint id = 0;
        while (g_variant_iter_next(&it, "i", &id)) {
            GVariantBuilder props;
            g_variant_builder_init(&props, G_VARIANT_TYPE("a{sv}"));
            AddMenuProperties(props, FindNode(id));
            g_variant_builder_add(&out, "(ia{sv})", id, &props);
            g_variant_builder_clear(&props);
        }
        g_variant_builder_init(&ret, G_VARIANT_TYPE("(a(ia{sv}))"));
        g_variant_builder_add_value(&ret, g_variant_builder_end(&out));
        g_dbus_method_invocation_return_value(inv, g_variant_builder_end(&ret));
        g_variant_unref(ids);
        g_variant_unref(names);
        return;
    }
    if (!strcmp(method, "GetProperty")) {
        int id = 0;
        const char* name = nullptr;
        g_variant_get(params, "(i&s)", &id, &name);
        GVariantBuilder props;
        g_variant_builder_init(&props, G_VARIANT_TYPE("a{sv}"));
        AddMenuProperties(props, FindNode(id));
        GVariant* dict = g_variant_builder_end(&props);
        GVariant* value = g_variant_lookup_value(dict, name, nullptr);
        if (value) {
            GVariantBuilder ret;
            g_variant_builder_init(&ret, G_VARIANT_TYPE("(v)"));
            g_variant_builder_add(&ret, "v", value);
            g_dbus_method_invocation_return_value(inv, g_variant_builder_end(&ret));
            g_variant_unref(value);
        } else {
            g_dbus_method_invocation_return_error(inv, G_DBUS_ERROR, G_DBUS_ERROR_INVALID_ARGS,
                                                  "No such property: %s", name);
        }
        g_variant_unref(dict);
        return;
    }
    if (!strcmp(method, "Event")) {
        int id = 0;
        const char* event = nullptr;
        GVariant* data = nullptr;
        guint32 timestamp = 0;
        if (g_variant_is_of_type(params, G_VARIANT_TYPE("(isvu)"))) {
            g_variant_get(params, "(i&s@vu)", &id, &event, &data, &timestamp);
        } else {
            g_variant_get(params, "(i&s@v)", &id, &event, &data);
        }
        const MenuNode* node = FindNode(id);
        if (node && node->enabled && !node->action.empty() && !strcmp(event, "clicked")) {
            g_action_group_activate_action(G_ACTION_GROUP(g.app), node->action.c_str(), node->actionParam);
        }
        if (data) g_variant_unref(data);
        g_dbus_method_invocation_return_value(inv, nullptr);
        return;
    }
    if (!strcmp(method, "AboutToShow")) {
        g_dbus_method_invocation_return_value(inv, g_variant_new("(b)", FALSE));
        return;
    }
    g_dbus_method_invocation_return_error(inv, G_DBUS_ERROR, G_DBUS_ERROR_UNKNOWN_METHOD, "Unknown method");
}

static GVariant* dbusmenu_get_property(GDBusConnection*, const gchar*, const gchar*, const gchar*,
                                       const gchar* name, GError**, gpointer) {
    if (!strcmp(name, "Revision")) return g_variant_new_int32(g.menuRevision);
    if (!strcmp(name, "TextDirection")) return g_variant_new_string(i18n::IsRtl() ? "rtl" : "ltr");
    return nullptr;
}

static GDBusInterfaceVTable sniVtable = { nullptr, sni_get_property, nullptr };
static GDBusInterfaceVTable appVtable = { app_method_call, nullptr, nullptr };
static GDBusInterfaceVTable dbusmenuVtable = { dbusmenu_method_call, dbusmenu_get_property, nullptr };

void RegisterInterfaces(GDBusConnection* conn) {
    GError* error = nullptr;
    GDBusNodeInfo* node = g_dbus_node_info_new_for_xml(kSniXml, &error);
    if (error) { g_warning("SNI XML: %s", error->message); g_error_free(error); return; }
    g_dbus_connection_register_object(conn, kSniPath, node->interfaces[0], &sniVtable, nullptr, nullptr, &error);
    if (error) { g_warning("Register SNI object: %s", error->message); g_error_free(error); }
    g_dbus_node_info_unref(node);

    node = g_dbus_node_info_new_for_xml(kAppXml, &error);
    if (error) { g_warning("App XML: %s", error->message); g_error_free(error); return; }
    g_dbus_connection_register_object(conn, kSniPath, node->interfaces[0], &appVtable, nullptr, nullptr, &error);
    if (error) { g_warning("Register app object: %s", error->message); g_error_free(error); }
    g_dbus_node_info_unref(node);

    node = g_dbus_node_info_new_for_xml(kMenuXml, &error);
    if (error) { g_warning("Menu XML: %s", error->message); g_error_free(error); return; }
    g_dbus_connection_register_object(conn, kMenuPath, node->interfaces[0], &dbusmenuVtable, nullptr, nullptr, &error);
    if (error) { g_warning("Register menu object: %s", error->message); g_error_free(error); }
    g_dbus_node_info_unref(node);
}

void OnBusAcquired(GDBusConnection* conn, const gchar*, gpointer) {
    g.conn = conn;
    RegisterInterfaces(conn);
    const char* watchers[] = { "org.kde.StatusNotifierWatcher", "org.freedesktop.StatusNotifierWatcher" };
    for (auto w : watchers) {
        GError* error = nullptr;
        GVariant* reply = g_dbus_connection_call_sync(conn, w, "/StatusNotifierWatcher", w,
                                                      "RegisterStatusNotifierItem",
                                                      g_variant_new("(s)", kSniPath), nullptr,
                                                      G_DBUS_CALL_FLAGS_NONE, -1, nullptr, &error);
        if (reply) { g_variant_unref(reply); if (error) g_error_free(error); break; }
        if (error) g_error_free(error);
    }
    RecomputePresentation();
}

// ---- actions -----------------------------------------------------------------------------------

void OnRefresh(GSimpleAction*, GVariant*, gpointer) {
    { std::lock_guard<std::mutex> lock(g.mu); g.wake = true; }
    g.cv.notify_all();
}

void OnQuitAction(GSimpleAction*, GVariant*, gpointer) {
    if (g.app) g_application_quit(G_APPLICATION(g.app));
}

void OnShowHistory(GSimpleAction*, GVariant*, gpointer) {
    std::wstring key = g.devices.empty() ? std::wstring() : g.devices.front().key;
    ShowLinuxBatteryHistoryWindow(g.app, g.devices, g.aliases, key, g.demo);
}

void OnShowDeviceHistory(GSimpleAction*, GVariant* param, gpointer) {
    std::wstring key;
    if (param) {
        const char* s = g_variant_get_string(param, nullptr);
        if (s) key = Utf8ToWide(s);
    }
    ShowLinuxBatteryHistoryWindow(g.app, g.devices, g.aliases, key, g.demo);
}

void OnShowReport(GSimpleAction*, GVariant*, gpointer) {
    ShowLinuxReportWindow(g.app);
}

void OnOpenSupport(GSimpleAction*, GVariant*, gpointer) {
    OpenUrl("https://github.com/sponsors/krisgfx9");
}

void OnToggleBrandAccents(GSimpleAction* action, GVariant*, gpointer) {
    g.useBrandAccents = !g.useBrandAccents;
    g_simple_action_set_state(action, g_variant_new_boolean(g.useBrandAccents));
    SaveSettings();
    RecomputePresentation();
}

void OnToggleLastKnown(GSimpleAction* action, GVariant*, gpointer) {
    g.hideLastKnown = !g.hideLastKnown;
    g_simple_action_set_state(action, g_variant_new_boolean(g.hideLastKnown));
    SaveSettings();
    RecomputePresentation();
}

void OnToggleShowDisconnected(GSimpleAction* action, GVariant*, gpointer) {
    g.showDisconnectedDevices = !g.showDisconnectedDevices;
    g_simple_action_set_state(action, g_variant_new_boolean(g.showDisconnectedDevices));
    SaveSettings();
    RecomputePresentation();
}

void OnToggleRecordHistory(GSimpleAction* action, GVariant*, gpointer) {
    g.recordHistory = !g.recordHistory;
    g_simple_action_set_state(action, g_variant_new_boolean(g.recordHistory));
    SaveSettings();
    RecomputePresentation();
}

void OnSetModeWidget(GSimpleAction*, GVariant*, gpointer) {
    g.wantWidget = true;
    SaveSettings();
    RecomputePresentation();
}

void OnSetModeTray(GSimpleAction*, GVariant*, gpointer) {
    g.wantWidget = false;
    SaveSettings();
    RecomputePresentation();
}

void OnToggleWidgetBg(GSimpleAction* action, GVariant*, gpointer) {
    g.widgetBackground = !g.widgetBackground;
    g_simple_action_set_state(action, g_variant_new_boolean(g.widgetBackground));
    SaveSettings();
    RecomputePresentation();
}

void OnToggleStacked(GSimpleAction* action, GVariant*, gpointer) {
    g.stacked = !g.stacked;
    g_simple_action_set_state(action, g_variant_new_boolean(g.stacked));
    SaveSettings();
    RecomputePresentation();
}

void OnToggleAutostart(GSimpleAction* action, GVariant*, gpointer) {
    g.autostart = !g.autostart;
    g_simple_action_set_state(action, g_variant_new_boolean(g.autostart));
    SaveSettings();
    ApplyAutostart(g.autostart);
    RecomputePresentation();
}

void OnToggleDevice(GSimpleAction*, GVariant* param, gpointer) {
    if (!param) return;
    const char* keyStr = g_variant_get_string(param, nullptr);
    if (!keyStr) return;
    std::wstring key = Utf8ToWide(keyStr);
    if (!g.hidden.erase(key)) g.hidden.insert(key);
    SaveSettings();
    RecomputePresentation();
}

// 1:1 MoveEntry(key, dir) from src/main.cpp lines 793-807
void OnMoveDevice(GSimpleAction*, GVariant* param, gpointer) {
    if (!param) return;
    const char* keyStr = nullptr;
    gint32 dir = 0;
    g_variant_get(param, "(&si)", &keyStr, &dir);
    if (!keyStr || dir == 0) return;
    std::wstring key = Utf8ToWide(keyStr);

    auto list = OrderedDevices(true);
    auto pos = std::find_if(list.begin(), list.end(), [&](const DeviceStatus* d) { return d->key == key; });
    if (pos == list.end()) return;
    ptrdiff_t i = pos - list.begin(), j = i + dir;
    if (j < 0 || j >= static_cast<ptrdiff_t>(list.size())) return;
    std::swap(list[i], list[j]);

    std::vector<std::wstring> newOrder;
    for (const auto* d : list) newOrder.push_back(d->key);
    for (const auto& k : g.order) {
        if (std::find(newOrder.begin(), newOrder.end(), k) == newOrder.end()) {
            newOrder.push_back(k);
        }
    }
    g.order = std::move(newOrder);
    SaveSettings();
    RecomputePresentation();
}

void OnRenameDevice(GSimpleAction*, GVariant* param, gpointer) {
    if (!param) return;
    const char* keyStr = g_variant_get_string(param, nullptr);
    if (!keyStr) return;
    std::wstring key = Utf8ToWide(keyStr);
    std::wstring originalName = key;
    for (const auto& s : g.devices) {
        if (s.key == key) {
            originalName = s.name;
            break;
        }
    }
    std::wstring currentAlias;
    auto it = g.aliases.find(key);
    if (it != g.aliases.end()) currentAlias = it->second;

    ShowLinuxRenameDialog(g.app, key, originalName, currentAlias, [key, originalName](const std::wstring& newAlias) {
        std::wstring trimmed = aliases::Trim(newAlias);
        if (trimmed.empty() || trimmed == originalName) {
            g.aliases.erase(key);
        } else if (aliases::ValidName(trimmed)) {
            if (g.aliases.count(key) || g.aliases.size() < aliases::kMaxAliases) {
                g.aliases[key] = trimmed;
            }
        }
        SaveSettings();
        RecomputePresentation();
    });
}

void OnResetDeviceName(GSimpleAction*, GVariant* param, gpointer) {
    if (!param) return;
    const char* keyStr = g_variant_get_string(param, nullptr);
    if (!keyStr) return;
    std::wstring key = Utf8ToWide(keyStr);
    if (!g.aliases.erase(key)) return;
    SaveSettings();
    RecomputePresentation();
}

void OnSetAlert(GSimpleAction*, GVariant* param, gpointer) {
    if (!param) return;
    const char* keyStr = nullptr;
    gint32 threshold = alerts::kUseDefault;
    g_variant_get(param, "(&si)", &keyStr, &threshold);
    if (!keyStr) return;
    std::wstring key = Utf8ToWide(keyStr);
    if (threshold == alerts::kUseDefault) {
        g.alertOverrides.erase(key);
    } else if (alerts::ValidOverride(threshold)) {
        g.alertOverrides[key] = threshold;
    } else {
        return;
    }
    g.alertLatches.erase(key);
    SaveSettings();
    RecomputePresentation();
    { std::lock_guard<std::mutex> lock(g.mu); g.wake = true; }
    g.cv.notify_all();
}

void OnSetPollInterval(GSimpleAction*, GVariant* param, gpointer) {
    if (!param) return;
    gint32 seconds = 60;
    g_variant_get(param, "i", &seconds);
    g.pollSeconds = std::clamp<int>(seconds, 30, 24 * 60 * 60);
    SaveSettings();
    RecomputePresentation();
    { std::lock_guard<std::mutex> lock(g.mu); g.wake = true; }
    g.cv.notify_all();
}

void OnSetLanguage(GSimpleAction*, GVariant* param, gpointer) {
    if (!param) return;
    const char* codeStr = g_variant_get_string(param, nullptr);
    i18n::Choose(Utf8ToWide(codeStr ? codeStr : ""));
    RecomputePresentation();
}

void OnOpenLangFolder(GSimpleAction*, GVariant*, gpointer) {
    i18n::OpenFolder();
}

const GActionEntry kActions[] = {
    { "refresh", OnRefresh, nullptr, nullptr, nullptr, {} },
    { "quit", OnQuitAction, nullptr, nullptr, nullptr, {} },
    { "show-history", OnShowHistory, nullptr, nullptr, nullptr, {} },
    { "show-device-history", OnShowDeviceHistory, "s", nullptr, nullptr, {} },
    { "show-report", OnShowReport, nullptr, nullptr, nullptr, {} },
    { "open-support", OnOpenSupport, nullptr, nullptr, nullptr, {} },
    { "toggle-brand-accents", OnToggleBrandAccents, nullptr, "true", nullptr, {} },
    { "toggle-last-known", OnToggleLastKnown, nullptr, "false", nullptr, {} },
    { "toggle-show-disconnected", OnToggleShowDisconnected, nullptr, "false", nullptr, {} },
    { "toggle-record-history", OnToggleRecordHistory, nullptr, "true", nullptr, {} },
    { "set-mode-widget", OnSetModeWidget, nullptr, nullptr, nullptr, {} },
    { "set-mode-tray", OnSetModeTray, nullptr, nullptr, nullptr, {} },
    { "toggle-widget-bg", OnToggleWidgetBg, nullptr, "false", nullptr, {} },
    { "toggle-stacked", OnToggleStacked, nullptr, "false", nullptr, {} },
    { "toggle-autostart", OnToggleAutostart, nullptr, "false", nullptr, {} },
    { "toggle-device", OnToggleDevice, "s", nullptr, nullptr, {} },
    { "move-device", OnMoveDevice, "(si)", nullptr, nullptr, {} },
    { "rename-device", OnRenameDevice, "s", nullptr, nullptr, {} },
    { "reset-device-name", OnResetDeviceName, "s", nullptr, nullptr, {} },
    { "set-alert", OnSetAlert, "(si)", nullptr, nullptr, {} },
    { "set-poll-interval", OnSetPollInterval, "i", nullptr, nullptr, {} },
    { "set-lang", OnSetLanguage, "s", nullptr, nullptr, {} },
    { "lang-open-folder", OnOpenLangFolder, nullptr, nullptr, nullptr, {} },
};

gboolean PushResults(gpointer) {
    ApplyResults();
    return G_SOURCE_REMOVE;
}

void OnActivate(GApplication*) {
    if (g.openHistoryOnStart) {
        std::wstring key = g.devices.empty() ? std::wstring() : g.devices.front().key;
        ShowLinuxBatteryHistoryWindow(g.app, g.devices, g.aliases, key, g.demo);
    }
}

// ---- worker ------------------------------------------------------------------------------------

void Worker() {
    while (!g.stop) {
        std::vector<DeviceStatus> result = g.demo ? DemoDevices() : PollAllDevices();
        {
            std::lock_guard<std::mutex> lock(g.mu);
            g.pending = std::move(result);
        }
        g_main_context_invoke(nullptr, PushResults, nullptr);
        std::unique_lock<std::mutex> lock(g.mu);
        int waitSec = g.pollSeconds.load();
        g.cv.wait_for(lock, std::chrono::seconds(waitSec), [&] { return g.stop || g.wake; });
        g.wake = false;
    }
}

// ---- CLI ---------------------------------------------------------------------------------------

int ListToConsole(bool dump) {
    if (dump) {
        std::wstring s = DumpHidCollections();
        std::string u = WideToUtf8(s);
        fwrite(u.c_str(), 1, u.size(), stdout);
        return 0;
    }
    auto list = g.demo ? DemoDevices() : PollAllDevices();
    if (list.empty()) printf("No devices with battery info found.\n");
    for (const auto& s : list) {
        Accent accent = brands::AccentFor(s);
        std::wstring brandTag = (accent != Accent::None)
            ? (L"{" + std::wstring(StyleOf(accent).name) + L"}  ")
            : L"";
        std::wstring line = s.name + L"  [" + s.via + L"]  " + brandTag + StatusText(s);
        if (s.millivolts) line += L", " + std::to_wstring(s.millivolts) + L" mV";
        line += L"   (" + s.key + L")\n";
        std::string u = WideToUtf8(line);
        fwrite(u.c_str(), 1, u.size(), stdout);
    }
    return 0;
}

int ListJson() {
    std::string out = DevicesToJson(g.demo ? DemoDevices() : PollAllDevices());
    fwrite(out.data(), 1, out.size(), stdout);
    return 0;
}

int QuitRunning() {
    GError* error = nullptr;
    GDBusConnection* conn = g_bus_get_sync(G_BUS_TYPE_SESSION, nullptr, &error);
    if (!conn) { fprintf(stderr, "Cannot connect to session bus: %s\n", error->message); g_error_free(error); return 1; }
    GVariant* reply = g_dbus_connection_call_sync(conn, kAppId, kSniPath,
                                                  "com.github.krisgfx9.WirelessBattery", "Quit",
                                                  nullptr, nullptr, G_DBUS_CALL_FLAGS_NONE, 3000, nullptr, &error);
    if (!reply) { fprintf(stderr, "Is BatteryHub running? %s\n", error->message); g_error_free(error); }
    else g_variant_unref(reply);
    g_object_unref(conn);
    return 0;
}

}  // namespace

int main(int argc, char** argv) {
    std::vector<char*> filteredArgv;
    filteredArgv.push_back(argv[0]);

    bool wantList = false, wantJson = false, wantDump = false, wantQuit = false;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--help") || !strcmp(argv[i], "-h")) {
            printf("Usage: wireless-battery [option]\n"
                   "  (no option)  Run the tray app\n"
                   "  --history    Open the GTK4 Battery History & Insights window\n"
                   "  --demo       Use 17 sample devices of every brand for UI preview\n"
                   "  --list       Print devices and battery levels, then exit\n"
                   "  --json       Print a JSON array of devices and battery levels, then exit\n"
                   "  --dump       Print all HID collections and devices, then exit\n"
                   "  --quit       Ask a running instance to quit\n"
                   "  -h, --help   Show this help\n");
            return 0;
        }
        if (!strcmp(argv[i], "--demo")) {
            g.demo = true;
            continue;
        }
        if (!strcmp(argv[i], "--history")) {
            g.openHistoryOnStart = true;
            continue;
        }
        if (!strcmp(argv[i], "--list")) { wantList = true; continue; }
        if (!strcmp(argv[i], "--json")) { wantJson = true; continue; }
        if (!strcmp(argv[i], "--dump")) { wantDump = true; continue; }
        if (!strcmp(argv[i], "--quit")) { wantQuit = true; continue; }
        filteredArgv.push_back(argv[i]);
    }

    if (wantList) return ListToConsole(false);
    if (wantJson) return ListJson();
    if (wantDump) return ListToConsole(true);
    if (wantQuit) return QuitRunning();

    LoadSettings();
    i18n::Load();

    g_autoptr(GError) error = nullptr;
    if (!gtk_init_check()) { fprintf(stderr, "Cannot initialise GTK (no display?).\n"); return 1; }

    g.app = GTK_APPLICATION(gtk_application_new(kAppId, G_APPLICATION_DEFAULT_FLAGS));
    g_action_map_add_action_entries(G_ACTION_MAP(g.app), kActions, G_N_ELEMENTS(kActions), nullptr);

    if (!g_application_register(G_APPLICATION(g.app), nullptr, &error)) {
        fprintf(stderr, "Cannot register application (already running?): %s\n", error->message);
        return 1;
    }
    // GApplication already owns kAppId; reuse its connection for StatusNotifierItem.
    OnBusAcquired(g_application_get_dbus_connection(G_APPLICATION(g.app)), kAppId, nullptr);

    g_signal_connect(g.app, "activate", G_CALLBACK(OnActivate), nullptr);
    // Keep the tray application running even when all windows are closed.
    g_application_hold(G_APPLICATION(g.app));
    std::thread worker(Worker);
    int filteredArgc = static_cast<int>(filteredArgv.size());
    int status = g_application_run(G_APPLICATION(g.app), filteredArgc, filteredArgv.data());
    g.stop = true;
    g.cv.notify_all();
    worker.join();
    ClearMenuNodes();
    return status;
}
