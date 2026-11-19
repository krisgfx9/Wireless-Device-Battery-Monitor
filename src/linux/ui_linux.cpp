#include "ui_linux.h"

#include "../brands.h"
#include "../history_model.h"
#include "../i18n.h"
#include "../runtime_estimate.h"

#include <cairo/cairo.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <ctime>
#include <map>
#include <set>
#include <string>
#include <vector>

namespace battery_history {

// Functional helpers around battery_history::Store for file persistence and batch sample recording.
inline void ParseFile(Store& store, const std::string& content, int64_t now) {
    store.Load(content, now);
}

inline bool RecordSamples(Store& store, const std::vector<DeviceStatus>& devices, int64_t now) {
    bool changed = false;
    for (const auto& d : devices) {
        if (!d.connected || d.asleep || d.percent < 0 || d.percent > 100) continue;
        Sample s{ d.key, now, d.percent, d.charging };
        if (store.Record(s)) changed = true;
    }
    return changed;
}

inline std::string SerializeFile(const Store& store) {
    return store.Serialize();
}

}  // namespace battery_history

namespace {

constexpr int64_t kSecondsPerDay = 86400;
constexpr int64_t kMaxConnectedGap = 4 * 3600;
constexpr size_t kMaxFileBytes = 4 * 1024 * 1024;
constexpr size_t kBoundFileBytes = 2 * 1024 * 1024;

battery_history::Store g_store;
bool g_loaded = false;

int64_t UtcNow() {
    return static_cast<int64_t>(std::time(nullptr));
}

std::string HistoryFilePath() {
    const char* dataDir = g_get_user_data_dir();
    std::string base = (dataDir && *dataDir)
        ? std::string(dataDir)
        : (std::string(g_get_home_dir()) + "/.local/share");
    return base + "/wireless-battery/battery_history.tsv";
}

bool SaveHistoryFile() {
    std::string bytes = battery_history::SerializeFile(g_store);
    while (bytes.size() > kBoundFileBytes && !g_store.samples.empty()) {
        const size_t drop = std::max<size_t>(1, g_store.samples.size() / 8);
        g_store.samples.erase(g_store.samples.begin(), g_store.samples.begin() + drop);
        bytes = battery_history::SerializeFile(g_store);
    }
    std::string path = HistoryFilePath();
    g_autofree gchar* dir = g_path_get_dirname(path.c_str());
    if (dir) g_mkdir_with_parents(dir, 0700);
    return g_file_set_contents(path.c_str(), bytes.data(), static_cast<gssize>(bytes.size()), nullptr) == TRUE;
}

void EnsureLoaded() {
    if (g_loaded) return;
    g_loaded = true;
    std::string path = HistoryFilePath();
    gchar* contents = nullptr;
    gsize length = 0;
    if (!g_file_get_contents(path.c_str(), &contents, &length, nullptr) || !contents) return;
    if (length <= kMaxFileBytes) {
        std::string data(contents, length);
        battery_history::ParseFile(g_store, data, UtcNow());
        if (data != battery_history::SerializeFile(g_store)) {
            SaveHistoryFile();
        }
    }
    g_free(contents);
}

void InstallDarkCss() {
    static bool installed = false;
    if (installed) return;
    installed = true;

    const char* css =
        "window.batteryhub-window {"
        "  background-color: #0c111c;"
        "  color: #e8f0fc;"
        "}"
        ".bh-card {"
        "  background-color: #161e2d;"
        "  border: 1px solid #2f3f53;"
        "  border-radius: 12px;"
        "  padding: 12px 16px;"
        "}"
        ".bh-title {"
        "  color: #e8f0fc;"
        "  font-size: 18px;"
        "  font-weight: 700;"
        "}"
        ".bh-card-label {"
        "  color: #a5b6ca;"
        "  font-size: 12px;"
        "  font-weight: 600;"
        "}"
        ".bh-card-value {"
        "  color: #e8f0fc;"
        "  font-size: 20px;"
        "  font-weight: 700;"
        "}"
        ".bh-card-value-blue {"
        "  color: #5ba6ff;"
        "  font-size: 20px;"
        "  font-weight: 700;"
        "}"
        ".bh-card-value-green {"
        "  color: #3bd79e;"
        "  font-size: 20px;"
        "  font-weight: 700;"
        "}"
        ".bh-card-value-red {"
        "  color: #ff8493;"
        "  font-size: 20px;"
        "  font-weight: 700;"
        "}"
        ".bh-card-sub {"
        "  color: #a5b6ca;"
        "  font-size: 12px;"
        "}"
        "button.bh-btn {"
        "  background-image: none;"
        "  background-color: #161e2d;"
        "  color: #a5b6ca;"
        "  border: 1px solid #2f3f53;"
        "  border-radius: 10px;"
        "  padding: 6px 14px;"
        "  font-weight: 600;"
        "}"
        "button.bh-btn:hover {"
        "  background-color: #1f2b40;"
        "  color: #e8f0fc;"
        "}"
        "button.bh-btn-active {"
        "  background-image: none;"
        "  background-color: #1f4370;"
        "  color: #e8f0fc;"
        "  border: 1px solid #5ba6ff;"
        "  border-radius: 10px;"
        "  padding: 6px 14px;"
        "  font-weight: 700;"
        "}"
        "button.bh-btn-danger {"
        "  background-image: none;"
        "  background-color: #161e2d;"
        "  color: #ff8493;"
        "  border: 1px solid #2f3f53;"
        "  border-radius: 10px;"
        "  padding: 6px 14px;"
        "  font-weight: 600;"
        "}"
        "button.bh-btn-danger:hover {"
        "  background-color: #351a24;"
        "  border-color: #ff8493;"
        "}"
        "entry.bh-entry {"
        "  background-color: #161e2d;"
        "  color: #e8f0fc;"
        "  border: 1px solid #2f3f53;"
        "  border-radius: 8px;"
        "  padding: 6px 10px;"
        "}";

    GtkCssProvider* provider = gtk_css_provider_new();
    gtk_css_provider_load_from_data(provider, css, -1);
    GdkDisplay* display = gdk_display_get_default();
    if (display) {
        gtk_style_context_add_provider_for_display(
            display, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    }
    g_object_unref(provider);
}

std::wstring FormatRemainingTime(double hours) {
    const int total = static_cast<int>(std::round(hours));
    const int days = total / 24;
    const int hrs = total % 24;
    if (days > 0) {
        return TF(L"~{days} d {hours} h", {
            { L"days", std::to_wstring(days) },
            { L"hours", std::to_wstring(hrs) }
        });
    }
    return TF(L"~{hours} h", { { L"hours", std::to_wstring(total) } });
}

std::string FormatRatePerHour(double pctPerHour) {
    char buf[64]{};
    std::snprintf(buf, sizeof(buf), "%.2f %%/h", pctPerHour);
    return std::string(buf);
}

struct HistoryWindowState {
    GtkWidget* window = nullptr;
    GtkWidget* combo = nullptr;
    GtkWidget* btn24h = nullptr;
    GtkWidget* btn7d = nullptr;
    GtkWidget* btn30d = nullptr;
    GtkWidget* btnClear = nullptr;
    GtkWidget* levelValueLabel = nullptr;
    GtkWidget* levelSubLabel = nullptr;
    GtkWidget* rateValueLabel = nullptr;
    GtkWidget* rateSubLabel = nullptr;
    GtkWidget* etaValueLabel = nullptr;
    GtkWidget* etaSubLabel = nullptr;
    GtkWidget* drawingArea = nullptr;

    std::vector<DeviceStatus> currentDevices;
    aliases::AliasMap aliasesMap;
    std::vector<std::wstring> deviceKeys;
    std::wstring selectedKey;
    int days = 7;
    bool updatingCombo = false;
};

HistoryWindowState g_histWin;

DeviceStatus FindDeviceStatus(const std::wstring& key) {
    for (const auto& d : g_histWin.currentDevices) {
        if (d.key == key) return d;
    }
    DeviceStatus fallback;
    fallback.key = key;
    fallback.name = key;
    fallback.connected = false;
    for (auto it = g_store.samples.rbegin(); it != g_store.samples.rend(); ++it) {
        if (it->key == key) {
            fallback.percent = it->percent;
            fallback.charging = it->charging;
            break;
        }
    }
    return fallback;
}

std::wstring ResolveDisplayName(const std::wstring& key) {
    DeviceStatus st = FindDeviceStatus(key);
    return aliases::DisplayName(g_histWin.aliasesMap, key, st.name.empty() ? key : st.name);
}

void UpdateRangeButtonStyles() {
    auto setActive = [](GtkWidget* btn, bool active) {
        if (!btn) return;
        gtk_widget_remove_css_class(btn, "bh-btn");
        gtk_widget_remove_css_class(btn, "bh-btn-active");
        gtk_widget_add_css_class(btn, active ? "bh-btn-active" : "bh-btn");
    };
    setActive(g_histWin.btn24h, g_histWin.days == 1);
    setActive(g_histWin.btn7d, g_histWin.days == 7);
    setActive(g_histWin.btn30d, g_histWin.days == 30);
}

void SetValueLabelClass(GtkWidget* label, const char* cssClass) {
    if (!label) return;
    gtk_widget_remove_css_class(label, "bh-card-value");
    gtk_widget_remove_css_class(label, "bh-card-value-blue");
    gtk_widget_remove_css_class(label, "bh-card-value-green");
    gtk_widget_remove_css_class(label, "bh-card-value-red");
    gtk_widget_add_css_class(label, cssClass);
}

void RefreshHistorySummaryAndChart() {
    if (!g_histWin.window) return;
    UpdateRangeButtonStyles();

    const int64_t now = UtcNow();
    const int64_t since = now - static_cast<int64_t>(g_histWin.days) * kSecondsPerDay;
    const auto points = g_histWin.selectedKey.empty()
        ? std::vector<battery_history::Sample>{}
        : g_store.For(g_histWin.selectedKey, since, now);
    const battery_history::Stats stats = battery_history::Summarize(points);
    const auto allPoints = g_histWin.selectedKey.empty()
        ? std::vector<battery_history::Sample>{}
        : g_store.For(g_histWin.selectedKey, now - battery_history::kRetentionSeconds, now);
    const battery_history::RuntimeEstimate forecast = battery_history::EstimateRuntime(allPoints, now);

    DeviceStatus dev = FindDeviceStatus(g_histWin.selectedKey);

    // 1. Current Level Card
    int currentPct = dev.percent >= 0 ? dev.percent : (stats.count ? stats.last : -1);
    bool isCharging = dev.connected ? dev.charging : (!points.empty() && points.back().charging);
    std::string levelStr = currentPct >= 0 ? (std::to_string(currentPct) + "%") : "—";
    if (isCharging && currentPct >= 0) {
        levelStr += " (" + WideToUtf8(T(L"charging")) + ")";
    } else if (dev.asleep && currentPct >= 0) {
        levelStr += " (" + WideToUtf8(T(L"asleep")) + ")";
    }
    gtk_label_set_text(GTK_LABEL(g_histWin.levelValueLabel), levelStr.c_str());
    if (isCharging) SetValueLabelClass(g_histWin.levelValueLabel, "bh-card-value-green");
    else if (currentPct >= 0 && currentPct <= 15) SetValueLabelClass(g_histWin.levelValueLabel, "bh-card-value-red");
    else SetValueLabelClass(g_histWin.levelValueLabel, "bh-card-value-blue");

    std::string levelSub;
    if (stats.count > 0) {
        int change = stats.last - stats.first;
        std::string deltaStr = (change > 0 ? "+" : "") + std::to_string(change) + " " + WideToUtf8(T(L"pp"));
        levelSub = WideToUtf8(T(L"Lowest")) + ": " + std::to_string(stats.lowest) + "% · " +
                   WideToUtf8(T(L"Highest")) + ": " + std::to_string(stats.highest) + "% · " +
                   WideToUtf8(T(L"Change")) + ": " + deltaStr;
    } else {
        levelSub = WideToUtf8(T(L"No readings in this period"));
    }
    gtk_label_set_text(GTK_LABEL(g_histWin.levelSubLabel), levelSub.c_str());

    // 2. Discharge Rate Card
    std::string rateStr = "— %/h";
    std::string rateSub;
    if (forecast.state == battery_history::RuntimeState::Ready && forecast.percentPerHour > 0.0) {
        rateStr = FormatRatePerHour(forecast.percentPerHour);
        int tenthsPerDay = static_cast<int>(std::round(forecast.percentPerHour * 240.0));
        std::wstring ratePerDay = std::to_wstring(tenthsPerDay / 10) + L"." + std::to_wstring(tenthsPerDay % 10);
        rateSub = WideToUtf8(TF(L"Recent discharge: {rate} pp/day · {count} readings", {
            { L"rate", ratePerDay },
            { L"count", std::to_wstring(forecast.sampleCount) }
        }));
        SetValueLabelClass(g_histWin.rateValueLabel, "bh-card-value");
    } else if (forecast.state == battery_history::RuntimeState::Charging) {
        rateStr = WideToUtf8(T(L"Currently charging"));
        rateSub = WideToUtf8(T(L"Readings")) + ": " + std::to_string(stats.count);
        SetValueLabelClass(g_histWin.rateValueLabel, "bh-card-value-green");
    } else {
        rateSub = WideToUtf8(T(L"Readings")) + ": " + std::to_string(stats.count);
        SetValueLabelClass(g_histWin.rateValueLabel, "bh-card-value");
    }
    gtk_label_set_text(GTK_LABEL(g_histWin.rateValueLabel), rateStr.c_str());
    gtk_label_set_text(GTK_LABEL(g_histWin.rateSubLabel), rateSub.c_str());

    // 3. Estimated Remaining Time Card
    std::wstring etaValue, etaDetails;
    const char* etaClass = "bh-card-value-blue";
    switch (forecast.state) {
        case battery_history::RuntimeState::Ready:
            etaValue = FormatRemainingTime(forecast.hoursRemaining);
            etaDetails = TF(L"Recent discharge: {rate} pp/day · {count} readings", {
                { L"rate", std::to_wstring(static_cast<int>(std::round(forecast.percentPerHour * 240.0)) / 10) +
                           L"." + std::to_wstring(static_cast<int>(std::round(forecast.percentPerHour * 240.0)) % 10) },
                { L"count", std::to_wstring(forecast.sampleCount) }
            });
            break;
        case battery_history::RuntimeState::Charging:
            etaValue = T(L"Currently charging");
            etaDetails = T(L"No remaining-time estimate while charging.");
            etaClass = "bh-card-value-green";
            break;
        case battery_history::RuntimeState::Stale:
            etaValue = T(L"No recent readings");
            etaDetails = T(L"Connect the device to resume forecasting.");
            etaClass = "bh-card-value";
            break;
        case battery_history::RuntimeState::Flat:
            etaValue = T(L"Insufficient decline");
            etaDetails = T(L"A measurable discharge trend is required.");
            etaClass = "bh-card-value";
            break;
        default:
            etaValue = T(L"Collecting data");
            etaDetails = T(L"Requires 4 readings, 2 hours and 3 percentage points of decline.");
            etaClass = "bh-card-value";
            break;
    }
    SetValueLabelClass(g_histWin.etaValueLabel, etaClass);
    gtk_label_set_text(GTK_LABEL(g_histWin.etaValueLabel), WideToUtf8(etaValue).c_str());
    gtk_label_set_text(GTK_LABEL(g_histWin.etaSubLabel), WideToUtf8(etaDetails).c_str());

    if (g_histWin.drawingArea) {
        gtk_widget_queue_draw(g_histWin.drawingArea);
    }
}

void PopulateDeviceCombo() {
    if (!g_histWin.combo) return;
    g_histWin.updatingCombo = true;

    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(g_histWin.combo));
    g_histWin.deviceKeys.clear();

    std::set<std::wstring> seen;
    for (const auto& d : g_histWin.currentDevices) {
        if (!d.key.empty() && seen.insert(d.key).second) {
            g_histWin.deviceKeys.push_back(d.key);
        }
    }
    for (const auto& s : g_store.samples) {
        if (!s.key.empty() && seen.insert(s.key).second) {
            g_histWin.deviceKeys.push_back(s.key);
        }
    }

    int activeIdx = 0;
    for (size_t i = 0; i < g_histWin.deviceKeys.size(); ++i) {
        const auto& k = g_histWin.deviceKeys[i];
        std::string label = WideToUtf8(ResolveDisplayName(k));
        std::string id = WideToUtf8(k);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(g_histWin.combo), id.c_str(), label.c_str());
        if (k == g_histWin.selectedKey) {
            activeIdx = static_cast<int>(i);
        }
    }

    if (!g_histWin.deviceKeys.empty()) {
        g_histWin.selectedKey = g_histWin.deviceKeys[activeIdx];
        gtk_combo_box_set_active(GTK_COMBO_BOX(g_histWin.combo), activeIdx);
    } else {
        g_histWin.selectedKey.clear();
    }

    g_histWin.updatingCombo = false;
}

void DrawRoundedRect(cairo_t* cr, double x, double y, double w, double h, double r) {
    cairo_new_sub_path(cr);
    cairo_arc(cr, x + w - r, y + r, r, -M_PI / 2, 0);
    cairo_arc(cr, x + w - r, y + h - r, r, 0, M_PI / 2);
    cairo_arc(cr, x + r, y + h - r, r, M_PI / 2, M_PI);
    cairo_arc(cr, x + r, y + r, r, M_PI, 3 * M_PI / 2);
    cairo_close_path(cr);
}

void DrawHistoryChart(GtkDrawingArea*, cairo_t* cr, int width, int height, gpointer) {
    if (width <= 40 || height <= 40) return;

    // Outer card background
    DrawRoundedRect(cr, 1.0, 1.0, width - 2.0, height - 2.0, 14.0);
    cairo_set_source_rgb(cr, 22.0 / 255.0, 30.0 / 255.0, 45.0 / 255.0);
    cairo_fill_preserve(cr);
    cairo_set_source_rgb(cr, 47.0 / 255.0, 63.0 / 255.0, 83.0 / 255.0);
    cairo_set_line_width(cr, 1.0);
    cairo_stroke(cr);

    // Legend caption at top of chart card
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 12.0);
    cairo_set_source_rgb(cr, 165.0 / 255.0, 182.0 / 255.0, 202.0 / 255.0);
    std::string legend = WideToUtf8(T(L"Blue: recorded battery; green: measured increase"));
    cairo_move_to(cr, 18.0, 24.0);
    cairo_show_text(cr, legend.c_str());

    const double plotLeft = 64.0;
    const double plotTop = 40.0;
    const double plotRight = width - 24.0;
    const double plotBottom = height - 48.0;
    const double plotW = plotRight - plotLeft;
    const double plotH = plotBottom - plotTop;
    if (plotW <= 60.0 || plotH <= 40.0) return;

    // Inner chart area
    DrawRoundedRect(cr, plotLeft, plotTop, plotW, plotH, 8.0);
    cairo_set_source_rgb(cr, 15.0 / 255.0, 23.0 / 255.0, 37.0 / 255.0);
    cairo_fill(cr);

    // Grid lines: 0%, 25%, 50%, 75%, 100% on Y-axis, and 4 time divisions on X-axis
    cairo_set_line_width(cr, 1.0);
    for (int i = 0; i <= 4; ++i) {
        const double y = plotTop + (plotH * i) / 4.0;
        cairo_set_source_rgb(cr, 42.0 / 255.0, 55.0 / 255.0, 74.0 / 255.0);
        cairo_move_to(cr, plotLeft, y);
        cairo_line_to(cr, plotRight, y);
        cairo_stroke(cr);

        std::string pctLabel = std::to_string(100 - i * 25) + "%";
        cairo_text_extents_t ext{};
        cairo_text_extents(cr, pctLabel.c_str(), &ext);
        cairo_set_source_rgb(cr, 165.0 / 255.0, 182.0 / 255.0, 202.0 / 255.0);
        cairo_move_to(cr, plotLeft - 10.0 - ext.width, y + ext.height / 2.0);
        cairo_show_text(cr, pctLabel.c_str());

        const double x = plotLeft + (plotW * i) / 4.0;
        cairo_set_source_rgb(cr, 42.0 / 255.0, 55.0 / 255.0, 74.0 / 255.0);
        cairo_move_to(cr, x, plotTop);
        cairo_line_to(cr, x, plotBottom);
        cairo_stroke(cr);
    }

    const int64_t now = UtcNow();
    const int64_t span = static_cast<int64_t>(g_histWin.days) * kSecondsPerDay;
    const int64_t since = now - span;
    const auto points = g_histWin.selectedKey.empty()
        ? std::vector<battery_history::Sample>{}
        : g_store.For(g_histWin.selectedKey, since, now);

    // Determine base line color from brand accent if available, fallback to blue (#5ba6ff)
    DeviceStatus dev = FindDeviceStatus(g_histWin.selectedKey);
    Accent accent = BrandOf(dev);
    double baseR = 91.0 / 255.0, baseG = 166.0 / 255.0, baseB = 255.0 / 255.0;
    if (accent != Accent::None) {
        BrandColor bc = AccentColor(accent, false);
        baseR = bc.r / 255.0;
        baseG = bc.g / 255.0;
        baseB = bc.b / 255.0;
    }
    const double chargeR = 59.0 / 255.0, chargeG = 215.0 / 255.0, chargeB = 158.0 / 255.0;
    const double lowR = 255.0 / 255.0, lowG = 82.0 / 255.0, lowB = 99.0 / 255.0;

    if (!points.empty()) {
        struct Pt {
            double x;
            double y;
            int percent;
            bool charging;
            int64_t timestamp;
        };
        std::vector<Pt> coords;
        coords.reserve(points.size());
        for (const auto& s : points) {
            double fracX = static_cast<double>(std::max<int64_t>(0, s.timestamp - since)) / static_cast<double>(span);
            fracX = std::max(0.0, std::min(1.0, fracX));
            double fracY = static_cast<double>(std::max(0, std::min(100, s.percent))) / 100.0;
            coords.push_back({
                plotLeft + plotW * fracX,
                plotBottom - plotH * fracY,
                s.percent,
                s.charging,
                s.timestamp
            });
        }

        // Draw translucent gradient fill under contiguous curve segments
        size_t segStart = 0;
        while (segStart < coords.size()) {
            size_t segEnd = segStart;
            while (segEnd + 1 < coords.size()) {
                const auto& prev = coords[segEnd];
                const auto& curr = coords[segEnd + 1];
                if (curr.timestamp > prev.timestamp &&
                    curr.timestamp - prev.timestamp <= kMaxConnectedGap &&
                    std::abs(curr.percent - prev.percent) <= 25) {
                    ++segEnd;
                } else {
                    break;
                }
            }
            if (segEnd > segStart) {
                cairo_save(cr);
                cairo_new_path(cr);
                cairo_move_to(cr, coords[segStart].x, plotBottom);
                for (size_t k = segStart; k <= segEnd; ++k) {
                    cairo_line_to(cr, coords[k].x, coords[k].y);
                }
                cairo_line_to(cr, coords[segEnd].x, plotBottom);
                cairo_close_path(cr);

                bool segCharging = coords[segEnd].charging;
                bool segLow = !segCharging && coords[segEnd].percent <= 15;
                double fillR = segCharging ? chargeR : (segLow ? lowR : baseR);
                double fillG = segCharging ? chargeG : (segLow ? lowG : baseG);
                double fillB = segCharging ? chargeB : (segLow ? lowB : baseB);

                cairo_pattern_t* grad = cairo_pattern_create_linear(0, plotTop, 0, plotBottom);
                cairo_pattern_add_color_stop_rgba(grad, 0.0, fillR, fillG, fillB, 0.30);
                cairo_pattern_add_color_stop_rgba(grad, 1.0, fillR, fillG, fillB, 0.02);
                cairo_set_source(cr, grad);
                cairo_fill(cr);
                cairo_pattern_destroy(grad);
                cairo_restore(cr);
            }
            segStart = segEnd + 1;
        }

        // Draw smooth line segments and data points
        cairo_set_line_width(cr, 2.4);
        cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND);
        cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);

        for (size_t i = 0; i < coords.size(); ++i) {
            const auto& curr = coords[i];
            bool joined = false;
            bool rising = false;
            if (i > 0) {
                const auto& prev = coords[i - 1];
                joined = curr.timestamp > prev.timestamp &&
                         curr.timestamp - prev.timestamp <= kMaxConnectedGap &&
                         std::abs(curr.percent - prev.percent) <= 25;
                rising = joined && (curr.percent > prev.percent || curr.charging);
            }
            bool isLow = !curr.charging && !rising && curr.percent <= 15;
            double r = (curr.charging || rising) ? chargeR : (isLow ? lowR : baseR);
            double g = (curr.charging || rising) ? chargeG : (isLow ? lowG : baseG);
            double b = (curr.charging || rising) ? chargeB : (isLow ? lowB : baseB);

            if (joined) {
                const auto& prev = coords[i - 1];
                cairo_set_source_rgb(cr, r, g, b);
                cairo_move_to(cr, prev.x, prev.y);
                cairo_line_to(cr, curr.x, curr.y);
                cairo_stroke(cr);
            }

            if (i + 1 == coords.size() || coords.size() <= 70 || i % 10 == 0) {
                double radius = (i + 1 == coords.size()) ? 4.5 : 2.5;
                if (i + 1 == coords.size()) {
                    cairo_set_source_rgba(cr, r, g, b, 0.28);
                    cairo_arc(cr, curr.x, curr.y, 8.0, 0, 2 * M_PI);
                    cairo_fill(cr);
                }
                cairo_set_source_rgb(cr, r, g, b);
                cairo_arc(cr, curr.x, curr.y, radius, 0, 2 * M_PI);
                cairo_fill(cr);
            }
        }
    } else {
        std::string emptyMsg = WideToUtf8(T(L"No readings in this period"));
        cairo_text_extents_t ext{};
        cairo_text_extents(cr, emptyMsg.c_str(), &ext);
        cairo_set_source_rgb(cr, 165.0 / 255.0, 182.0 / 255.0, 202.0 / 255.0);
        cairo_move_to(cr, plotLeft + (plotW - ext.width) / 2.0, plotTop + (plotH + ext.height) / 2.0);
        cairo_show_text(cr, emptyMsg.c_str());
    }

    // X-axis time labels
    std::wstring startW = g_histWin.days == 1
        ? std::wstring(T(L"24h ago"))
        : TF(L"{days} days ago", { { L"days", std::to_wstring(g_histWin.days) } });
    std::string startLabel = WideToUtf8(startW);
    std::string nowLabel = WideToUtf8(T(L"Now"));
    std::string footerNote = WideToUtf8(T(L"Trend estimates are approximate; missing samples are not inferred."));

    cairo_set_source_rgb(cr, 165.0 / 255.0, 182.0 / 255.0, 202.0 / 255.0);
    cairo_move_to(cr, plotLeft, plotBottom + 18.0);
    cairo_show_text(cr, startLabel.c_str());

    cairo_text_extents_t nowExt{};
    cairo_text_extents(cr, nowLabel.c_str(), &nowExt);
    cairo_move_to(cr, plotRight - nowExt.width, plotBottom + 18.0);
    cairo_show_text(cr, nowLabel.c_str());

    cairo_text_extents_t noteExt{};
    cairo_text_extents(cr, footerNote.c_str(), &noteExt);
    cairo_move_to(cr, plotLeft + (plotW - noteExt.width) / 2.0, plotBottom + 36.0);
    cairo_show_text(cr, footerNote.c_str());
}

void OnDeviceComboChanged(GtkComboBox* combo, gpointer) {
    if (g_histWin.updatingCombo) return;
    int idx = gtk_combo_box_get_active(combo);
    if (idx >= 0 && static_cast<size_t>(idx) < g_histWin.deviceKeys.size()) {
        g_histWin.selectedKey = g_histWin.deviceKeys[static_cast<size_t>(idx)];
        RefreshHistorySummaryAndChart();
    }
}

void OnRange24h(GtkButton*, gpointer) {
    g_histWin.days = 1;
    RefreshHistorySummaryAndChart();
}

void OnRange7d(GtkButton*, gpointer) {
    g_histWin.days = 7;
    RefreshHistorySummaryAndChart();
}

void OnRange30d(GtkButton*, gpointer) {
    g_histWin.days = 30;
    RefreshHistorySummaryAndChart();
}

void OnClearHistory(GtkButton*, gpointer) {
    if (g_histWin.selectedKey.empty()) return;
    g_store.Clear(g_histWin.selectedKey);
    SaveHistoryFile();
    RefreshHistorySummaryAndChart();
}

void OnHistoryWindowDestroy(GtkWidget*, gpointer) {
    g_histWin.window = nullptr;
    g_histWin.combo = nullptr;
    g_histWin.btn24h = nullptr;
    g_histWin.btn7d = nullptr;
    g_histWin.btn30d = nullptr;
    g_histWin.btnClear = nullptr;
    g_histWin.levelValueLabel = nullptr;
    g_histWin.levelSubLabel = nullptr;
    g_histWin.rateValueLabel = nullptr;
    g_histWin.rateSubLabel = nullptr;
    g_histWin.etaValueLabel = nullptr;
    g_histWin.etaSubLabel = nullptr;
    g_histWin.drawingArea = nullptr;
}

GtkWidget* CreateSummaryCard(const std::string& titleText,
                             GtkWidget** outValueLabel,
                             GtkWidget** outSubLabel) {
    GtkWidget* card = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_widget_add_css_class(card, "bh-card");
    gtk_widget_set_hexpand(card, TRUE);

    GtkWidget* title = gtk_label_new(titleText.c_str());
    gtk_widget_add_css_class(title, "bh-card-label");
    gtk_widget_set_halign(title, GTK_ALIGN_START);
    gtk_box_append(GTK_BOX(card), title);

    GtkWidget* value = gtk_label_new("—");
    gtk_widget_add_css_class(value, "bh-card-value");
    gtk_widget_set_halign(value, GTK_ALIGN_START);
    gtk_label_set_ellipsize(GTK_LABEL(value), PANGO_ELLIPSIZE_END);
    gtk_box_append(GTK_BOX(card), value);

    GtkWidget* sub = gtk_label_new("");
    gtk_widget_add_css_class(sub, "bh-card-sub");
    gtk_widget_set_halign(sub, GTK_ALIGN_START);
    gtk_label_set_ellipsize(GTK_LABEL(sub), PANGO_ELLIPSIZE_END);
    gtk_box_append(GTK_BOX(card), sub);

    if (outValueLabel) *outValueLabel = value;
    if (outSubLabel) *outSubLabel = sub;
    return card;
}

// ---- Rename Dialog State ----------------------------------------------------------------------

struct RenameDialogData {
    GtkWidget* window = nullptr;
    GtkWidget* entry = nullptr;
    GtkWidget* errorLabel = nullptr;
    std::wstring deviceKey;
    std::wstring originalName;
    std::function<void(const std::wstring&)> onSave;
};

void OnRenameSave(GtkWidget*, gpointer userData) {
    auto* data = static_cast<RenameDialogData*>(userData);
    if (!data || !data->entry) return;
    const char* text = gtk_editable_get_text(GTK_EDITABLE(data->entry));
    std::wstring trimmed = aliases::Trim(Utf8ToWide(text ? text : ""));
    if (!aliases::ValidName(trimmed)) {
        if (data->errorLabel) {
            gtk_label_set_text(GTK_LABEL(data->errorLabel),
                               WideToUtf8(T(L"Enter a name (1-64 characters).")).c_str());
            gtk_widget_set_visible(data->errorLabel, TRUE);
        }
        gtk_widget_grab_focus(data->entry);
        return;
    }
    std::wstring newAlias = (trimmed == data->originalName) ? std::wstring() : trimmed;
    if (data->onSave) data->onSave(newAlias);
    if (data->window) gtk_window_destroy(GTK_WINDOW(data->window));
}

void OnRenameReset(GtkWidget*, gpointer userData) {
    auto* data = static_cast<RenameDialogData*>(userData);
    if (!data) return;
    if (data->onSave) data->onSave(std::wstring());
    if (data->window) gtk_window_destroy(GTK_WINDOW(data->window));
}

void OnRenameCancel(GtkWidget*, gpointer userData) {
    auto* data = static_cast<RenameDialogData*>(userData);
    if (!data) return;
    if (data->window) gtk_window_destroy(GTK_WINDOW(data->window));
}

void OnRenameDestroy(GtkWidget*, gpointer userData) {
    delete static_cast<RenameDialogData*>(userData);
}

}  // namespace

void RecordLinuxBatteryHistory(const std::vector<DeviceStatus>& devices) {
    EnsureLoaded();
    if (battery_history::RecordSamples(g_store, devices, UtcNow())) {
        SaveHistoryFile();
    }
    if (g_histWin.window) {
        g_histWin.currentDevices = devices;
        PopulateDeviceCombo();
        RefreshHistorySummaryAndChart();
    }
}

void ShowLinuxBatteryHistoryWindow(GtkApplication* app,
                                   const std::vector<DeviceStatus>& currentDevices,
                                   const aliases::AliasMap& aliasesMap) {
    EnsureLoaded();
    InstallDarkCss();

    g_histWin.currentDevices = currentDevices;
    g_histWin.aliasesMap = aliasesMap;

    if (g_histWin.window) {
        PopulateDeviceCombo();
        RefreshHistorySummaryAndChart();
        gtk_window_present(GTK_WINDOW(g_histWin.window));
        return;
    }

    GtkWidget* win = app ? gtk_application_window_new(app) : gtk_window_new();
    g_histWin.window = win;
    gtk_widget_add_css_class(win, "batteryhub-window");
    gtk_window_set_title(GTK_WINDOW(win), "BatteryHub — Battery History & Insights");
    gtk_window_set_default_size(GTK_WINDOW(win), 960, 640);

    GtkWidget* root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 16);
    gtk_widget_set_margin_top(root, 20);
    gtk_widget_set_margin_bottom(root, 20);
    gtk_widget_set_margin_start(root, 22);
    gtk_widget_set_margin_end(root, 22);
    gtk_window_set_child(GTK_WINDOW(win), root);

    // Top bar: title + device selector + range buttons + clear button
    GtkWidget* topBar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_append(GTK_BOX(root), topBar);

    GtkWidget* titleLabel = gtk_label_new(WideToUtf8(T(L"Battery history")).c_str());
    gtk_widget_add_css_class(titleLabel, "bh-title");
    gtk_widget_set_margin_end(titleLabel, 12);
    gtk_box_append(GTK_BOX(topBar), titleLabel);

    g_histWin.combo = gtk_combo_box_text_new();
    gtk_widget_set_hexpand(g_histWin.combo, TRUE);
    g_signal_connect(g_histWin.combo, "changed", G_CALLBACK(OnDeviceComboChanged), nullptr);
    gtk_box_append(GTK_BOX(topBar), g_histWin.combo);

    g_histWin.btn24h = gtk_button_new_with_label("24h");
    g_histWin.btn7d = gtk_button_new_with_label("7d");
    g_histWin.btn30d = gtk_button_new_with_label("30d");
    g_histWin.btnClear = gtk_button_new_with_label(WideToUtf8(T(L"Clear device history")).c_str());
    gtk_widget_add_css_class(g_histWin.btnClear, "bh-btn-danger");

    g_signal_connect(g_histWin.btn24h, "clicked", G_CALLBACK(OnRange24h), nullptr);
    g_signal_connect(g_histWin.btn7d, "clicked", G_CALLBACK(OnRange7d), nullptr);
    g_signal_connect(g_histWin.btn30d, "clicked", G_CALLBACK(OnRange30d), nullptr);
    g_signal_connect(g_histWin.btnClear, "clicked", G_CALLBACK(OnClearHistory), nullptr);

    gtk_box_append(GTK_BOX(topBar), g_histWin.btn24h);
    gtk_box_append(GTK_BOX(topBar), g_histWin.btn7d);
    gtk_box_append(GTK_BOX(topBar), g_histWin.btn30d);
    gtk_box_append(GTK_BOX(topBar), g_histWin.btnClear);

    // Summary cards row: Current Level, Discharge Rate, Estimated Remaining Time
    GtkWidget* cardsRow = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 12);
    gtk_box_set_homogeneous(GTK_BOX(cardsRow), TRUE);
    gtk_box_append(GTK_BOX(root), cardsRow);

    GtkWidget* levelCard = CreateSummaryCard(
        WideToUtf8(T(L"Latest")), &g_histWin.levelValueLabel, &g_histWin.levelSubLabel);
    GtkWidget* rateCard = CreateSummaryCard(
        "Discharge Rate (%/h)", &g_histWin.rateValueLabel, &g_histWin.rateSubLabel);
    GtkWidget* etaCard = CreateSummaryCard(
        WideToUtf8(T(L"Estimated time to empty")), &g_histWin.etaValueLabel, &g_histWin.etaSubLabel);

    gtk_box_append(GTK_BOX(cardsRow), levelCard);
    gtk_box_append(GTK_BOX(cardsRow), rateCard);
    gtk_box_append(GTK_BOX(cardsRow), etaCard);

    // Cairo chart drawing area
    g_histWin.drawingArea = gtk_drawing_area_new();
    gtk_widget_set_vexpand(g_histWin.drawingArea, TRUE);
    gtk_widget_set_hexpand(g_histWin.drawingArea, TRUE);
    gtk_drawing_area_set_content_width(GTK_DRAWING_AREA(g_histWin.drawingArea), 880);
    gtk_drawing_area_set_content_height(GTK_DRAWING_AREA(g_histWin.drawingArea), 380);
    gtk_drawing_area_set_draw_func(
        GTK_DRAWING_AREA(g_histWin.drawingArea), DrawHistoryChart, nullptr, nullptr);
    gtk_box_append(GTK_BOX(root), g_histWin.drawingArea);

    g_signal_connect(win, "destroy", G_CALLBACK(OnHistoryWindowDestroy), nullptr);

    PopulateDeviceCombo();
    RefreshHistorySummaryAndChart();
    gtk_window_present(GTK_WINDOW(win));
}

void ShowLinuxRenameDialog(GtkApplication* app,
                           const std::wstring& deviceKey,
                           const std::wstring& originalName,
                           const std::wstring& currentAlias,
                           std::function<void(const std::wstring& newAlias)> onSave) {
    InstallDarkCss();

    auto* data = new RenameDialogData();
    data->deviceKey = deviceKey;
    data->originalName = originalName;
    data->onSave = std::move(onSave);

    GtkWidget* win = app ? gtk_application_window_new(app) : gtk_window_new();
    data->window = win;
    gtk_widget_add_css_class(win, "batteryhub-window");
    gtk_window_set_title(GTK_WINDOW(win), WideToUtf8(T(L"Rename device")).c_str());
    gtk_window_set_default_size(GTK_WINDOW(win), 420, 180);
    gtk_window_set_resizable(GTK_WINDOW(win), FALSE);
    gtk_window_set_modal(GTK_WINDOW(win), TRUE);

    GtkWidget* box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
    gtk_widget_set_margin_top(box, 18);
    gtk_widget_set_margin_bottom(box, 18);
    gtk_widget_set_margin_start(box, 20);
    gtk_widget_set_margin_end(box, 20);
    gtk_window_set_child(GTK_WINDOW(win), box);

    GtkWidget* promptLabel = gtk_label_new(WideToUtf8(T(L"Device display name:")).c_str());
    gtk_widget_add_css_class(promptLabel, "bh-card-label");
    gtk_widget_set_halign(promptLabel, GTK_ALIGN_START);
    gtk_box_append(GTK_BOX(box), promptLabel);

    GtkWidget* entry = gtk_entry_new();
    data->entry = entry;
    gtk_widget_add_css_class(entry, "bh-entry");
    gtk_entry_set_max_length(GTK_ENTRY(entry), static_cast<int>(aliases::kMaxNameLength));
    std::wstring initialText = currentAlias.empty() ? originalName : currentAlias;
    gtk_editable_set_text(GTK_EDITABLE(entry), WideToUtf8(initialText).c_str());
    g_signal_connect(entry, "activate", G_CALLBACK(OnRenameSave), data);
    gtk_box_append(GTK_BOX(box), entry);

    GtkWidget* errorLabel = gtk_label_new("");
    data->errorLabel = errorLabel;
    gtk_widget_add_css_class(errorLabel, "bh-card-value-red");
    gtk_widget_set_halign(errorLabel, GTK_ALIGN_START);
    gtk_widget_set_visible(errorLabel, FALSE);
    gtk_box_append(GTK_BOX(box), errorLabel);

    GtkWidget* btnRow = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_widget_set_halign(btnRow, GTK_ALIGN_END);
    gtk_box_append(GTK_BOX(box), btnRow);

    GtkWidget* btnReset = gtk_button_new_with_label(WideToUtf8(T(L"Reset to default")).c_str());
    gtk_widget_add_css_class(btnReset, "bh-btn");
    g_signal_connect(btnReset, "clicked", G_CALLBACK(OnRenameReset), data);
    gtk_box_append(GTK_BOX(btnRow), btnReset);

    GtkWidget* btnCancel = gtk_button_new_with_label(WideToUtf8(T(L"Cancel")).c_str());
    gtk_widget_add_css_class(btnCancel, "bh-btn");
    g_signal_connect(btnCancel, "clicked", G_CALLBACK(OnRenameCancel), data);
    gtk_box_append(GTK_BOX(btnRow), btnCancel);

    GtkWidget* btnSave = gtk_button_new_with_label(WideToUtf8(T(L"Save")).c_str());
    gtk_widget_add_css_class(btnSave, "bh-btn-active");
    g_signal_connect(btnSave, "clicked", G_CALLBACK(OnRenameSave), data);
    gtk_box_append(GTK_BOX(btnRow), btnSave);

    g_signal_connect(win, "destroy", G_CALLBACK(OnRenameDestroy), data);
    gtk_window_present(GTK_WINDOW(win));
    gtk_widget_grab_focus(entry);
}
