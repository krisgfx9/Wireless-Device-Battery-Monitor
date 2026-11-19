#include "ui_linux.h"

#include "../brands.h"
#include "../history_model.h"
#include "../i18n.h"
#include "../labels.h"
#include "../runtime_estimate.h"

#include <cairo/cairo.h>
#include <unistd.h>

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

// Exact 5-day discharge/recharge cycle from src/battery_history.cpp lines 109-121.
std::vector<battery_history::Sample> DemoSamples(const std::wstring& key, int64_t now) {
    std::vector<battery_history::Sample> points;
    const int64_t start = now - 30 * kSecondsPerDay;
    for (int i = 0; i <= 720; i += 3) {
        const int cycleHour = (i + 60) % 120;  // five-day discharge/recharge cycle
        const bool charging = cycleHour >= 108 && cycleHour <= 114;
        int pct = cycleHour < 108 ? 96 - cycleHour / 2 :
                  cycleHour == 108 ? 60 : cycleHour == 111 ? 78 : 96;
        points.push_back({ key, start + static_cast<int64_t>(i) * 3600, pct, charging });
    }
    return points;
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
        "window.batteryhub-widget {"
        "  background-color: #0c111c;"
        "  color: #e8f0fc;"
        "}"
        ".bh-card {"
        "  background-color: #161e2d;"
        "  border: 1px solid #2f3f53;"
        "  border-radius: 12px;"
        "  padding: 10px 14px;"
        "}"
        ".bh-headline {"
        "  color: #e8f0fc;"
        "  font-size: 22px;"
        "  font-weight: 600;"
        "}"
        ".bh-subtitle {"
        "  color: #a5b6ca;"
        "  font-size: 13px;"
        "}"
        ".bh-card-label {"
        "  color: #a5b6ca;"
        "  font-size: 13px;"
        "  font-weight: 500;"
        "}"
        ".bh-card-value {"
        "  color: #e8f0fc;"
        "  font-size: 21px;"
        "  font-weight: 600;"
        "}"
        ".bh-card-value-blue {"
        "  color: #5ba6ff;"
        "  font-size: 21px;"
        "  font-weight: 600;"
        "}"
        ".bh-card-value-green {"
        "  color: #3bd79e;"
        "  font-size: 21px;"
        "  font-weight: 600;"
        "}"
        ".bh-card-value-red {"
        "  color: #ff8493;"
        "  font-size: 21px;"
        "  font-weight: 600;"
        "}"
        ".bh-card-sub {"
        "  color: #a5b6ca;"
        "  font-size: 13px;"
        "}"
        "button.bh-btn {"
        "  background-image: none;"
        "  background-color: #161e2d;"
        "  color: #a5b6ca;"
        "  border: 1px solid #2f3f53;"
        "  border-radius: 12px;"
        "  padding: 7px 16px;"
        "  font-weight: 500;"
        "}"
        "button.bh-btn:hover {"
        "  background-color: #263b53;"
        "  color: #e8f0fc;"
        "}"
        "button.bh-btn-active {"
        "  background-image: none;"
        "  background-color: #1f4370;"
        "  color: #e8f0fc;"
        "  border: 1px solid #5ba6ff;"
        "  border-radius: 12px;"
        "  padding: 7px 16px;"
        "  font-weight: 600;"
        "}"
        "button.bh-btn-danger {"
        "  background-image: none;"
        "  background-color: #161e2d;"
        "  color: #ff8493;"
        "  border: 1px solid #2f3f53;"
        "  border-radius: 12px;"
        "  padding: 7px 16px;"
        "  font-weight: 500;"
        "}"
        "button.bh-btn-danger:hover {"
        "  background-color: #351a24;"
        "  border-color: #ff8493;"
        "}"
        "button.bh-btn-danger:disabled {"
        "  background-color: #0c111c;"
        "  color: #667588;"
        "  border-color: #2a374a;"
        "}"
        "entry.bh-entry {"
        "  background-color: #161e2d;"
        "  color: #e8f0fc;"
        "  border: 1px solid #2f3f53;"
        "  border-radius: 8px;"
        "  padding: 6px 10px;"
        "}"
        "textview.bh-textview, textview.bh-textview text {"
        "  background-color: #0f1725;"
        "  color: #e8f0fc;"
        "  font-family: monospace;"
        "  font-size: 12px;"
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

void DrawRoundedRect(cairo_t* cr, double x, double y, double w, double h, double r) {
    cairo_new_sub_path(cr);
    cairo_arc(cr, x + w - r, y + r, r, -M_PI / 2, 0);
    cairo_arc(cr, x + w - r, y + h - r, r, 0, M_PI / 2);
    cairo_arc(cr, x + r, y + h - r, r, M_PI / 2, M_PI);
    cairo_arc(cr, x + r, y + r, r, M_PI, 3 * M_PI / 2);
    cairo_close_path(cr);
}

void OpenUrlWithXdgOpen(const char* url) {
    if (!url || !*url) return;
    pid_t pid = fork();
    if (pid == 0) {
        execlp("xdg-open", "xdg-open", url, static_cast<char*>(nullptr));
        _exit(0);
    }
}

// ---- Battery History Window State (1:1 with src/battery_history.cpp) --------------------------

struct HistoryWindowState {
    GtkApplication* app = nullptr;
    GtkWidget* window = nullptr;
    GtkWidget* combo = nullptr;
    GtkWidget* btn24h = nullptr;
    GtkWidget* btn7d = nullptr;
    GtkWidget* btn30d = nullptr;
    GtkWidget* btnClear = nullptr;
    GtkWidget* headlineLabel = nullptr;
    GtkWidget* demoSubtitleLabel = nullptr;
    GtkWidget* statTitleLabels[5]{};
    GtkWidget* statValueLabels[5]{};
    GtkWidget* etaTitleLabel = nullptr;
    GtkWidget* etaValueLabel = nullptr;
    GtkWidget* etaDetailsLabel = nullptr;
    GtkWidget* drawingArea = nullptr;

    std::vector<DeviceStatus> currentDevices;
    aliases::AliasMap aliasesMap;
    std::vector<std::wstring> deviceKeys;
    std::wstring selectedKey;
    int days = 7;
    bool demo = false;
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
    if (key.empty()) return L"BatteryHub";
    DeviceStatus st = FindDeviceStatus(key);
    return aliases::DisplayName(g_histWin.aliasesMap, key, st.name.empty() ? key : st.name);
}

std::vector<battery_history::Sample> VisibleHistorySamples(int64_t now) {
    if (g_histWin.selectedKey.empty()) return {};
    const int64_t since = now - static_cast<int64_t>(g_histWin.days) * kSecondsPerDay;
    if (!g_histWin.demo) {
        return g_store.For(g_histWin.selectedKey, since, now);
    }
    auto points = DemoSamples(g_histWin.selectedKey, now);
    points.erase(std::remove_if(points.begin(), points.end(), [since](const battery_history::Sample& s) {
        return s.timestamp < since;
    }), points.end());
    return points;
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
    if (g_histWin.btnClear) {
        gtk_widget_set_sensitive(g_histWin.btnClear, g_histWin.demo ? FALSE : TRUE);
    }
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

    std::wstring dispName = ResolveDisplayName(g_histWin.selectedKey);
    std::wstring winTitle = std::wstring(T(L"Battery history")) + L" - " + dispName;
    gtk_window_set_title(GTK_WINDOW(g_histWin.window), WideToUtf8(winTitle).c_str());

    if (g_histWin.headlineLabel) {
        std::wstring headline = std::wstring(T(L"Battery history")) + L"  •  " + dispName;
        gtk_label_set_text(GTK_LABEL(g_histWin.headlineLabel), WideToUtf8(headline).c_str());
    }
    if (g_histWin.demoSubtitleLabel) {
        gtk_label_set_text(GTK_LABEL(g_histWin.demoSubtitleLabel),
                           WideToUtf8(T(L"Demo readings (not saved)")).c_str());
        gtk_widget_set_visible(g_histWin.demoSubtitleLabel, g_histWin.demo ? TRUE : FALSE);
    }

    const int64_t now = UtcNow();
    const auto points = VisibleHistorySamples(now);
    const battery_history::Stats stats = battery_history::Summarize(points);
    const auto forecastPoints = g_histWin.selectedKey.empty()
        ? std::vector<battery_history::Sample>{}
        : (g_histWin.demo
            ? DemoSamples(g_histWin.selectedKey, now)
            : g_store.For(g_histWin.selectedKey, now - battery_history::kRetentionSeconds, now));
    const battery_history::RuntimeEstimate forecast = battery_history::EstimateRuntime(forecastPoints, now);

    // Row 1 — 5 Equal Statistic Cards: Latest, Lowest, Highest, Change, Readings
    const wchar_t* headings[5] = { L"Latest", L"Lowest", L"Highest", L"Change", L"Readings" };
    std::wstring delta = L"—";
    const char* deltaClass = "bh-card-value";
    if (stats.count >= 2) {
        const int change = stats.last - stats.first;
        delta = (change > 0 ? L"+" : L"") + std::to_wstring(change) + L" " + T(L"pp");
        deltaClass = change < 0 ? "bh-card-value-red" : (change > 0 ? "bh-card-value-green" : "bh-card-value");
    }
    const std::wstring values[5] = {
        stats.count ? std::to_wstring(stats.last) + L"%" : L"—",
        stats.count ? std::to_wstring(stats.lowest) + L"%" : L"—",
        stats.count ? std::to_wstring(stats.highest) + L"%" : L"—",
        delta,
        std::to_wstring(stats.count)
    };
    for (int i = 0; i < 5; ++i) {
        if (g_histWin.statTitleLabels[i]) {
            gtk_label_set_text(GTK_LABEL(g_histWin.statTitleLabels[i]), WideToUtf8(T(headings[i])).c_str());
        }
        if (g_histWin.statValueLabels[i]) {
            const char* cls = (i == 0) ? "bh-card-value-blue" : (i == 3 ? deltaClass : "bh-card-value");
            SetValueLabelClass(g_histWin.statValueLabels[i], cls);
            gtk_label_set_text(GTK_LABEL(g_histWin.statValueLabels[i]), WideToUtf8(values[i]).c_str());
        }
    }

    // Row 2 — Full-Width "Estimated time to empty" Card
    if (g_histWin.etaTitleLabel) {
        gtk_label_set_text(GTK_LABEL(g_histWin.etaTitleLabel),
                           WideToUtf8(T(L"Estimated time to empty")).c_str());
    }
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
            break;
        case battery_history::RuntimeState::Flat:
            etaValue = T(L"Insufficient decline");
            etaDetails = T(L"A measurable discharge trend is required.");
            break;
        default:
            etaValue = T(L"Collecting data");
            etaDetails = T(L"Requires 4 readings, 2 hours and 3 percentage points of decline.");
            break;
    }
    SetValueLabelClass(g_histWin.etaValueLabel, etaClass);
    gtk_label_set_text(GTK_LABEL(g_histWin.etaValueLabel), WideToUtf8(etaValue).c_str());
    gtk_label_set_text(GTK_LABEL(g_histWin.etaDetailsLabel), WideToUtf8(etaDetails).c_str());

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
    if (!g_histWin.demo) {
        for (const auto& s : g_store.samples) {
            if (!s.key.empty() && seen.insert(s.key).second) {
                g_histWin.deviceKeys.push_back(s.key);
            }
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

void DrawHistoryChart(GtkDrawingArea*, cairo_t* cr, int width, int height, gpointer) {
    if (width <= 120 || height <= 120) return;

    // Outer panel matching Windows RoundedPanel(dc, panel, P().panel, P().border, 14)
    DrawRoundedRect(cr, 1.0, 1.0, width - 2.0, height - 2.0, 14.0);
    cairo_set_source_rgb(cr, 22.0 / 255.0, 30.0 / 255.0, 45.0 / 255.0);
    cairo_fill_preserve(cr);
    cairo_set_source_rgb(cr, 47.0 / 255.0, 63.0 / 255.0, 83.0 / 255.0);
    cairo_set_line_width(cr, 1.0);
    cairo_stroke(cr);

    // Legend caption at top of chart panel
    cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, 13.0);
    cairo_set_source_rgb(cr, 165.0 / 255.0, 182.0 / 255.0, 202.0 / 255.0);
    std::string legend = WideToUtf8(T(L"Blue: recorded battery; green: measured increase"));
    cairo_move_to(cr, 18.0, 28.0);
    cairo_show_text(cr, legend.c_str());

    const double plotLeft = 78.0;
    const double plotTop = 50.0;
    const double plotRight = width - 21.0;
    const double plotBottom = height - 61.0;
    const double plotW = plotRight - plotLeft;
    const double plotH = plotBottom - plotTop;
    if (plotW <= 120.0 || plotH <= 68.0) return;

    // Inner chart area matching Windows RoundedPanel(dc, plot, P().chart, P().chart, 6)
    DrawRoundedRect(cr, plotLeft, plotTop, plotW, plotH, 6.0);
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
    const auto points = VisibleHistorySamples(now);

    const double blueR = 91.0 / 255.0, blueG = 166.0 / 255.0, blueB = 255.0 / 255.0;
    const double greenR = 59.0 / 255.0, greenG = 215.0 / 255.0, greenB = 158.0 / 255.0;
    const double redR = 255.0 / 255.0, redG = 132.0 / 255.0, redB = 147.0 / 255.0;

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

        // Translucent gradient fill under contiguous curve segments
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

                cairo_pattern_t* grad = cairo_pattern_create_linear(0, plotTop, 0, plotBottom);
                cairo_pattern_add_color_stop_rgba(grad, 0.0, blueR, blueG, blueB, 0.22);
                cairo_pattern_add_color_stop_rgba(grad, 1.0, blueR, blueG, blueB, 0.01);
                cairo_set_source(cr, grad);
                cairo_fill(cr);
                cairo_pattern_destroy(grad);
                cairo_restore(cr);
            }
            segStart = segEnd + 1;
        }

        // Line segments and markers matching Windows Paint() lines 404-441
        cairo_set_line_width(cr, 2.0);
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
                rising = joined && curr.percent > prev.percent;
            }
            bool isLow = !curr.charging && !rising && curr.percent <= 15;
            double r = rising ? greenR : (isLow ? redR : blueR);
            double g = rising ? greenG : (isLow ? redG : blueG);
            double b = rising ? greenB : (isLow ? redB : blueB);

            if (joined) {
                const auto& prev = coords[i - 1];
                cairo_set_source_rgb(cr, rising ? greenR : blueR,
                                     rising ? greenG : blueG,
                                     rising ? greenB : blueB);
                cairo_move_to(cr, prev.x, prev.y);
                cairo_line_to(cr, curr.x, curr.y);
                cairo_stroke(cr);
            }

            if (i + 1 == coords.size() || coords.size() <= 70 || i % 10 == 0) {
                double radius = (i + 1 == coords.size()) ? 4.0 : 2.0;
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

    // X-axis time labels & disclaimer note matching Windows lines 447-455
    std::wstring startW = g_histWin.days == 1
        ? std::wstring(T(L"24h ago"))
        : TF(L"{days} days ago", { { L"days", std::to_wstring(g_histWin.days) } });
    std::string startLabel = WideToUtf8(startW);
    std::string nowLabel = WideToUtf8(T(L"Now"));
    std::string footerNote = WideToUtf8(T(L"Trend estimates are approximate; missing samples are not inferred."));

    cairo_set_source_rgb(cr, 165.0 / 255.0, 182.0 / 255.0, 202.0 / 255.0);
    cairo_move_to(cr, plotLeft, plotBottom + 20.0);
    cairo_show_text(cr, startLabel.c_str());

    cairo_text_extents_t nowExt{};
    cairo_text_extents(cr, nowLabel.c_str(), &nowExt);
    cairo_move_to(cr, plotRight - nowExt.width, plotBottom + 20.0);
    cairo_show_text(cr, nowLabel.c_str());

    cairo_text_extents_t noteExt{};
    cairo_text_extents(cr, footerNote.c_str(), &noteExt);
    cairo_move_to(cr, plotLeft + (plotW - noteExt.width) / 2.0, plotBottom + 44.0);
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
    if (g_histWin.demo || g_histWin.selectedKey.empty()) return;
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
    g_histWin.headlineLabel = nullptr;
    g_histWin.demoSubtitleLabel = nullptr;
    for (int i = 0; i < 5; ++i) {
        g_histWin.statTitleLabels[i] = nullptr;
        g_histWin.statValueLabels[i] = nullptr;
    }
    g_histWin.etaTitleLabel = nullptr;
    g_histWin.etaValueLabel = nullptr;
    g_histWin.etaDetailsLabel = nullptr;
    g_histWin.drawingArea = nullptr;
}

GtkWidget* CreateStatCard(const std::string& headingText,
                          GtkWidget** outTitleLabel,
                          GtkWidget** outValueLabel) {
    GtkWidget* card = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_widget_add_css_class(card, "bh-card");
    gtk_widget_set_hexpand(card, TRUE);

    GtkWidget* title = gtk_label_new(headingText.c_str());
    gtk_widget_add_css_class(title, "bh-card-label");
    gtk_widget_set_halign(title, GTK_ALIGN_START);
    gtk_box_append(GTK_BOX(card), title);

    GtkWidget* value = gtk_label_new("—");
    gtk_widget_add_css_class(value, "bh-card-value");
    gtk_widget_set_halign(value, GTK_ALIGN_START);
    gtk_label_set_ellipsize(GTK_LABEL(value), PANGO_ELLIPSIZE_END);
    gtk_box_append(GTK_BOX(card), value);

    if (outTitleLabel) *outTitleLabel = title;
    if (outValueLabel) *outValueLabel = value;
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

// ---- Request Support / Report Window State (src/report.cpp parity) ----------------------------

struct ReportWindowData {
    GtkWidget* window = nullptr;
    GtkWidget* statusLabel = nullptr;
    std::string reportText;
};

ReportWindowData* g_reportWin = nullptr;

void OnReportCopy(GtkButton*, gpointer userData) {
    auto* data = static_cast<ReportWindowData*>(userData);
    if (!data) return;
    GdkDisplay* display = gdk_display_get_default();
    if (display) {
        GdkClipboard* clipboard = gdk_display_get_clipboard(display);
        if (clipboard) {
            gdk_clipboard_set_text(clipboard, data->reportText.c_str());
        }
    }
    if (data->statusLabel) {
        gtk_label_set_text(
            GTK_LABEL(data->statusLabel),
            WideToUtf8(T(L"The full report is copied. Paste it into a GitHub issue if we ask for more details.")).c_str());
        gtk_widget_set_visible(data->statusLabel, TRUE);
    }
}

void OnReportOpenGitHub(GtkButton*, gpointer) {
    OpenUrlWithXdgOpen("https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues");
}

void OnReportClose(GtkButton*, gpointer userData) {
    auto* data = static_cast<ReportWindowData*>(userData);
    if (data && data->window) {
        gtk_window_destroy(GTK_WINDOW(data->window));
    }
}

void OnReportDestroy(GtkWidget*, gpointer userData) {
    auto* data = static_cast<ReportWindowData*>(userData);
    if (g_reportWin == data) g_reportWin = nullptr;
    delete data;
}

// ---- Floating Taskbar/Desktop Widget Window (src/widget.cpp parity) ---------------------------

struct WidgetWindowState {
    GtkApplication* app = nullptr;
    GtkWidget* window = nullptr;
    GtkWidget* drawingArea = nullptr;
    std::vector<DeviceStatus> devices;
    aliases::AliasMap aliasesMap;
    std::vector<std::wstring> shortLabels;
    bool useBrandAccents = false;
    bool widgetBackground = false;
    bool stacked = false;
    bool demo = false;
};

WidgetWindowState g_widgetWin;

void DrawDeviceKindIcon(cairo_t* cr, DeviceKind kind, double cx, double cy, double size,
                        double r, double g, double b, double alpha) {
    cairo_save(cr);
    cairo_set_source_rgba(cr, r, g, b, alpha);
    cairo_set_line_width(cr, 1.8);
    cairo_set_line_cap(cr, CAIRO_LINE_CAP_ROUND);
    cairo_set_line_join(cr, CAIRO_LINE_JOIN_ROUND);

    const double half = size * 0.5;
    switch (kind) {
        case DeviceKind::Mouse: {
            double w = size * 0.62, h = size * 0.90;
            DrawRoundedRect(cr, cx - w * 0.5, cy - h * 0.5, w, h, w * 0.45);
            cairo_stroke(cr);
            cairo_move_to(cr, cx, cy - h * 0.30);
            cairo_line_to(cr, cx, cy - h * 0.08);
            cairo_stroke(cr);
            break;
        }
        case DeviceKind::Keyboard: {
            double w = size * 0.96, h = size * 0.62;
            DrawRoundedRect(cr, cx - w * 0.5, cy - h * 0.5, w, h, 3.0);
            cairo_stroke(cr);
            for (int row = 0; row < 2; ++row) {
                for (int col = -1; col <= 1; ++col) {
                    cairo_arc(cr, cx + col * (w * 0.24), cy - h * 0.14 + row * (h * 0.24), 1.1, 0, 2 * M_PI);
                    cairo_fill(cr);
                }
            }
            break;
        }
        case DeviceKind::Headset: {
            double rad = size * 0.38;
            cairo_arc(cr, cx, cy - 1.0, rad, M_PI, 2 * M_PI);
            cairo_stroke(cr);
            DrawRoundedRect(cr, cx - rad - 2.0, cy - 2.0, 4.0, size * 0.36, 1.5);
            cairo_fill(cr);
            DrawRoundedRect(cr, cx + rad - 2.0, cy - 2.0, 4.0, size * 0.36, 1.5);
            cairo_fill(cr);
            break;
        }
        case DeviceKind::Gamepad: {
            double w = size * 0.94, h = size * 0.62;
            DrawRoundedRect(cr, cx - w * 0.5, cy - h * 0.5, w, h, h * 0.4);
            cairo_stroke(cr);
            cairo_move_to(cr, cx - w * 0.22 - 2.5, cy);
            cairo_line_to(cr, cx - w * 0.22 + 2.5, cy);
            cairo_move_to(cr, cx - w * 0.22, cy - 2.5);
            cairo_line_to(cr, cx - w * 0.22, cy + 2.5);
            cairo_stroke(cr);
            cairo_arc(cr, cx + w * 0.22, cy - 1.5, 1.4, 0, 2 * M_PI);
            cairo_fill(cr);
            cairo_arc(cr, cx + w * 0.14, cy + 1.5, 1.4, 0, 2 * M_PI);
            cairo_fill(cr);
            break;
        }
        case DeviceKind::Phone: {
            double w = size * 0.56, h = size * 0.92;
            DrawRoundedRect(cr, cx - w * 0.5, cy - h * 0.5, w, h, 3.0);
            cairo_stroke(cr);
            cairo_arc(cr, cx, cy + h * 0.32, 1.2, 0, 2 * M_PI);
            cairo_fill(cr);
            break;
        }
        default: {
            double w = size * 0.78, h = size * 0.48;
            DrawRoundedRect(cr, cx - w * 0.5, cy - h * 0.5, w, h, 2.5);
            cairo_stroke(cr);
            cairo_rectangle(cr, cx + w * 0.5, cy - h * 0.22, 2.2, h * 0.44);
            cairo_fill(cr);
            (void)half;
            break;
        }
    }
    cairo_restore(cr);
}

void DrawWidgetStrip(GtkDrawingArea*, cairo_t* cr, int width, int height, gpointer) {
    if (width <= 10 || height <= 10) return;

    // Outer pill background
    double bgAlpha = g_widgetWin.widgetBackground ? 0.96 : 0.80;
    DrawRoundedRect(cr, 1.0, 1.0, width - 2.0, height - 2.0, 10.0);
    cairo_set_source_rgba(cr, 18.0 / 255.0, 25.0 / 255.0, 38.0 / 255.0, bgAlpha);
    cairo_fill_preserve(cr);
    cairo_set_source_rgba(cr, 47.0 / 255.0, 63.0 / 255.0, 83.0 / 255.0, 0.9);
    cairo_set_line_width(cr, 1.0);
    cairo_stroke(cr);

    if (g_widgetWin.devices.empty()) {
        cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
        cairo_set_font_size(cr, 12.0);
        cairo_set_source_rgb(cr, 165.0 / 255.0, 182.0 / 255.0, 202.0 / 255.0);
        std::string msg = "BatteryHub";
        cairo_text_extents_t ext{};
        cairo_text_extents(cr, msg.c_str(), &ext);
        cairo_move_to(cr, (width - ext.width) * 0.5, (height + ext.height) * 0.5);
        cairo_show_text(cr, msg.c_str());
        return;
    }

    const size_t n = g_widgetWin.devices.size();
    const double cellW = static_cast<double>(width - 12) / static_cast<double>(n);

    for (size_t i = 0; i < n; ++i) {
        const auto& s = g_widgetWin.devices[i];
        const double cellX = 6.0 + i * cellW;
        const bool offline = !s.connected;
        const bool dim = offline || s.percent < 0 || s.asleep;
        const double alpha = dim ? 0.55 : 1.0;
        const bool isLow = !offline && !s.charging && s.percent >= 0 && s.percent <= 15;
        const bool isFull = !offline && (s.full || (s.charging && s.percent >= 100));
        const bool isCharging = !offline && !s.asleep && s.charging && !isFull;

        Accent accent = g_widgetWin.useBrandAccents ? BrandOf(s) : Accent::None;
        BrandColor bc = AccentColor(accent, false);
        double iconR = 232.0 / 255.0, iconG = 240.0 / 255.0, iconB = 252.0 / 255.0;
        if (accent != Accent::None) {
            iconR = bc.r / 255.0;
            iconG = bc.g / 255.0;
            iconB = bc.b / 255.0;
        }

        double barR = isCharging ? 0.0 : (isLow ? 0.92 : (accent != Accent::None ? iconR : 0.12));
        double barG = isCharging ? 0.67 : (isLow ? 0.20 : (accent != Accent::None ? iconG : 0.75));
        double barB = isCharging ? 1.0 : (isLow ? 0.24 : (accent != Accent::None ? iconB : 0.35));

        std::string pctText;
        if (offline) pctText = "×";
        else if (!s.levelText.empty() && s.percent >= 0) pctText = WideToUtf8(T(s.levelText));
        else if (s.percent >= 0) pctText = std::to_string(s.percent) + "%";
        else pctText = "?";
        if (isFull) pctText += " ✓";
        else if (isCharging) pctText += " ⚡";

        double iconCx = g_widgetWin.stacked ? (cellX + cellW * 0.5) : (cellX + 16.0);
        double iconCy = g_widgetWin.stacked ? 15.0 : (height * 0.45);

        if (accent != Accent::None) {
            cairo_pattern_t* glow = cairo_pattern_create_radial(iconCx, iconCy, 1.0, iconCx, iconCy, 13.0);
            cairo_pattern_add_color_stop_rgba(glow, 0.0, iconR, iconG, iconB, 0.32 * alpha);
            cairo_pattern_add_color_stop_rgba(glow, 1.0, iconR, iconG, iconB, 0.0);
            cairo_set_source(cr, glow);
            cairo_arc(cr, iconCx, iconCy, 13.0, 0, 2 * M_PI);
            cairo_fill(cr);
            cairo_pattern_destroy(glow);
        }

        DrawDeviceKindIcon(cr, s.kind, iconCx, iconCy, 16.0, iconR, iconG, iconB, alpha);

        // Short disambiguation label when multiple devices of the same kind are shown
        if (i < g_widgetWin.shortLabels.size() && !g_widgetWin.shortLabels[i].empty()) {
            std::string shortLbl = WideToUtf8(g_widgetWin.shortLabels[i]);
            cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
            cairo_set_font_size(cr, 8.5);
            cairo_set_source_rgba(cr, 165.0 / 255.0, 182.0 / 255.0, 202.0 / 255.0, alpha);
            cairo_move_to(cr, iconCx + 8.0, iconCy - 4.0);
            cairo_show_text(cr, shortLbl.c_str());
        }

        // Percentage text
        cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
        cairo_set_font_size(cr, g_widgetWin.stacked ? 11.5 : 13.0);
        if (isLow) cairo_set_source_rgba(cr, 0.95, 0.25, 0.28, alpha);
        else cairo_set_source_rgba(cr, 232.0 / 255.0, 240.0 / 255.0, 252.0 / 255.0, alpha);

        cairo_text_extents_t ext{};
        cairo_text_extents(cr, pctText.c_str(), &ext);
        if (g_widgetWin.stacked) {
            cairo_move_to(cr, cellX + (cellW - ext.width) * 0.5, height - 10.0);
        } else {
            cairo_move_to(cr, cellX + 30.0, height * 0.45 + ext.height * 0.45);
        }
        cairo_show_text(cr, pctText.c_str());

        // Level bar underneath
        double barX = cellX + 6.0;
        double barW = std::max(16.0, cellW - 12.0);
        double barY = height - 5.0;
        cairo_set_source_rgba(cr, 1.0, 1.0, 1.0, 0.18);
        cairo_rectangle(cr, barX, barY, barW, 3.0);
        cairo_fill(cr);

        if (!offline && s.percent >= 0) {
            double fillW = std::max(2.0, (barW * std::min(100, s.percent)) / 100.0);
            cairo_set_source_rgba(cr, barR, barG, barB, alpha);
            cairo_rectangle(cr, barX, barY, fillW, 3.0);
            cairo_fill(cr);
        }
    }
}

void OnWidgetClicked(GtkGestureClick*, gint, gdouble, gdouble, gpointer) {
    std::wstring key = g_widgetWin.devices.empty() ? std::wstring() : g_widgetWin.devices.front().key;
    ShowLinuxBatteryHistoryWindow(
        g_widgetWin.app, g_widgetWin.devices, g_widgetWin.aliasesMap, key, g_widgetWin.demo);
}

void OnWidgetDestroy(GtkWidget*, gpointer) {
    g_widgetWin.window = nullptr;
    g_widgetWin.drawingArea = nullptr;
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
                                   const aliases::AliasMap& aliasesMap,
                                   const std::wstring& initialKey,
                                   bool demo) {
    EnsureLoaded();
    InstallDarkCss();

    g_histWin.app = app;
    g_histWin.currentDevices = currentDevices;
    g_histWin.aliasesMap = aliasesMap;
    g_histWin.demo = demo;
    if (!initialKey.empty()) {
        g_histWin.selectedKey = initialKey;
    }

    if (g_histWin.window) {
        PopulateDeviceCombo();
        RefreshHistorySummaryAndChart();
        gtk_window_present(GTK_WINDOW(g_histWin.window));
        return;
    }

    GtkWidget* win = app ? gtk_application_window_new(app) : gtk_window_new();
    g_histWin.window = win;
    gtk_widget_add_css_class(win, "batteryhub-window");
    gtk_window_set_default_size(GTK_WINDOW(win), 1020, 710);
    gtk_widget_set_size_request(win, 880, 620);

    GtkWidget* root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 14);
    gtk_widget_set_margin_top(root, 18);
    gtk_widget_set_margin_bottom(root, 22);
    gtk_widget_set_margin_start(root, 24);
    gtk_widget_set_margin_end(root, 24);
    gtk_window_set_child(GTK_WINDOW(win), root);

    // Top button bar: Left (Last 24 hours, Last 7 days, Last 30 days), Right (Device selector + Clear device history)
    GtkWidget* topBar = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_append(GTK_BOX(root), topBar);

    g_histWin.btn24h = gtk_button_new_with_label(WideToUtf8(T(L"Last 24 hours")).c_str());
    g_histWin.btn7d = gtk_button_new_with_label(WideToUtf8(T(L"Last 7 days")).c_str());
    g_histWin.btn30d = gtk_button_new_with_label(WideToUtf8(T(L"Last 30 days")).c_str());

    g_signal_connect(g_histWin.btn24h, "clicked", G_CALLBACK(OnRange24h), nullptr);
    g_signal_connect(g_histWin.btn7d, "clicked", G_CALLBACK(OnRange7d), nullptr);
    g_signal_connect(g_histWin.btn30d, "clicked", G_CALLBACK(OnRange30d), nullptr);

    gtk_box_append(GTK_BOX(topBar), g_histWin.btn24h);
    gtk_box_append(GTK_BOX(topBar), g_histWin.btn7d);
    gtk_box_append(GTK_BOX(topBar), g_histWin.btn30d);

    GtkWidget* spacer = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_widget_set_hexpand(spacer, TRUE);
    gtk_box_append(GTK_BOX(topBar), spacer);

    g_histWin.combo = gtk_combo_box_text_new();
    g_signal_connect(g_histWin.combo, "changed", G_CALLBACK(OnDeviceComboChanged), nullptr);
    gtk_box_append(GTK_BOX(topBar), g_histWin.combo);

    g_histWin.btnClear = gtk_button_new_with_label(WideToUtf8(T(L"Clear device history")).c_str());
    gtk_widget_add_css_class(g_histWin.btnClear, "bh-btn-danger");
    g_signal_connect(g_histWin.btnClear, "clicked", G_CALLBACK(OnClearHistory), nullptr);
    gtk_box_append(GTK_BOX(topBar), g_histWin.btnClear);

    // Headline row + optional Demo subtitle row (matching src/battery_history.cpp lines 302-309)
    GtkWidget* headerBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    gtk_box_append(GTK_BOX(root), headerBox);

    g_histWin.headlineLabel = gtk_label_new("");
    gtk_widget_add_css_class(g_histWin.headlineLabel, "bh-headline");
    gtk_widget_set_halign(g_histWin.headlineLabel, GTK_ALIGN_START);
    gtk_label_set_ellipsize(GTK_LABEL(g_histWin.headlineLabel), PANGO_ELLIPSIZE_END);
    gtk_box_append(GTK_BOX(headerBox), g_histWin.headlineLabel);

    g_histWin.demoSubtitleLabel = gtk_label_new(WideToUtf8(T(L"Demo readings (not saved)")).c_str());
    gtk_widget_add_css_class(g_histWin.demoSubtitleLabel, "bh-subtitle");
    gtk_widget_set_halign(g_histWin.demoSubtitleLabel, GTK_ALIGN_START);
    gtk_widget_set_visible(g_histWin.demoSubtitleLabel, demo ? TRUE : FALSE);
    gtk_box_append(GTK_BOX(headerBox), g_histWin.demoSubtitleLabel);

    // Row 1 — 5 Equal Statistic Cards: Latest, Lowest, Highest, Change, Readings
    GtkWidget* statsRow = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_box_set_homogeneous(GTK_BOX(statsRow), TRUE);
    gtk_box_append(GTK_BOX(root), statsRow);

    const wchar_t* headings[5] = { L"Latest", L"Lowest", L"Highest", L"Change", L"Readings" };
    for (int i = 0; i < 5; ++i) {
        GtkWidget* card = CreateStatCard(
            WideToUtf8(T(headings[i])), &g_histWin.statTitleLabels[i], &g_histWin.statValueLabels[i]);
        gtk_box_append(GTK_BOX(statsRow), card);
    }

    // Row 2 — Full-Width "Estimated time to empty" Card (matching src/battery_history.cpp lines 335-375)
    GtkWidget* etaCard = gtk_box_new(GTK_ORIENTATION_VERTICAL, 6);
    gtk_widget_add_css_class(etaCard, "bh-card");
    gtk_box_append(GTK_BOX(root), etaCard);

    g_histWin.etaTitleLabel = gtk_label_new(WideToUtf8(T(L"Estimated time to empty")).c_str());
    gtk_widget_add_css_class(g_histWin.etaTitleLabel, "bh-card-label");
    gtk_widget_set_halign(g_histWin.etaTitleLabel, GTK_ALIGN_START);
    gtk_box_append(GTK_BOX(etaCard), g_histWin.etaTitleLabel);

    GtkWidget* etaBottomRow = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 16);
    gtk_box_append(GTK_BOX(etaCard), etaBottomRow);

    g_histWin.etaValueLabel = gtk_label_new("—");
    gtk_widget_add_css_class(g_histWin.etaValueLabel, "bh-card-value-blue");
    gtk_widget_set_halign(g_histWin.etaValueLabel, GTK_ALIGN_START);
    gtk_widget_set_hexpand(g_histWin.etaValueLabel, TRUE);
    gtk_label_set_ellipsize(GTK_LABEL(g_histWin.etaValueLabel), PANGO_ELLIPSIZE_END);
    gtk_box_append(GTK_BOX(etaBottomRow), g_histWin.etaValueLabel);

    g_histWin.etaDetailsLabel = gtk_label_new("");
    gtk_widget_add_css_class(g_histWin.etaDetailsLabel, "bh-card-sub");
    gtk_widget_set_halign(g_histWin.etaDetailsLabel, GTK_ALIGN_START);
    gtk_widget_set_valign(g_histWin.etaDetailsLabel, GTK_ALIGN_CENTER);
    gtk_widget_set_hexpand(g_histWin.etaDetailsLabel, TRUE);
    gtk_label_set_ellipsize(GTK_LABEL(g_histWin.etaDetailsLabel), PANGO_ELLIPSIZE_END);
    gtk_box_append(GTK_BOX(etaBottomRow), g_histWin.etaDetailsLabel);

    // Row 3 — Cairo Chart Panel
    g_histWin.drawingArea = gtk_drawing_area_new();
    gtk_widget_set_vexpand(g_histWin.drawingArea, TRUE);
    gtk_widget_set_hexpand(g_histWin.drawingArea, TRUE);
    gtk_drawing_area_set_content_width(GTK_DRAWING_AREA(g_histWin.drawingArea), 830);
    gtk_drawing_area_set_content_height(GTK_DRAWING_AREA(g_histWin.drawingArea), 340);
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

void ShowLinuxReportWindow(GtkApplication* app) {
    InstallDarkCss();

    if (g_reportWin && g_reportWin->window) {
        gtk_window_present(GTK_WINDOW(g_reportWin->window));
        return;
    }

    auto* data = new ReportWindowData();
    g_reportWin = data;
    data->reportText = WideToUtf8(DumpHidCollections());

    GtkWidget* win = app ? gtk_application_window_new(app) : gtk_window_new();
    data->window = win;
    gtk_widget_add_css_class(win, "batteryhub-window");
    gtk_window_set_title(GTK_WINDOW(win), WideToUtf8(T(L"Request support for a device...")).c_str());
    gtk_window_set_default_size(GTK_WINDOW(win), 720, 520);

    GtkWidget* root = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
    gtk_widget_set_margin_top(root, 18);
    gtk_widget_set_margin_bottom(root, 18);
    gtk_widget_set_margin_start(root, 20);
    gtk_widget_set_margin_end(root, 20);
    gtk_window_set_child(GTK_WINDOW(win), root);

    GtkWidget* intro = gtk_label_new(
        WideToUtf8(T(L"This is exactly what will be sent:")).c_str());
    gtk_widget_add_css_class(intro, "bh-card-label");
    gtk_widget_set_halign(intro, GTK_ALIGN_START);
    gtk_box_append(GTK_BOX(root), intro);

    GtkWidget* scrolled = gtk_scrolled_window_new();
    gtk_widget_set_vexpand(scrolled, TRUE);
    gtk_widget_set_hexpand(scrolled, TRUE);
    gtk_box_append(GTK_BOX(root), scrolled);

    GtkWidget* tv = gtk_text_view_new();
    gtk_widget_add_css_class(tv, "bh-textview");
    gtk_text_view_set_editable(GTK_TEXT_VIEW(tv), FALSE);
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(tv), TRUE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(tv), GTK_WRAP_NONE);
    GtkTextBuffer* buf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(tv));
    if (buf) {
        gtk_text_buffer_set_text(buf, data->reportText.c_str(), static_cast<int>(data->reportText.size()));
    }
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled), tv);

    data->statusLabel = gtk_label_new("");
    gtk_widget_add_css_class(data->statusLabel, "bh-card-sub");
    gtk_widget_set_halign(data->statusLabel, GTK_ALIGN_START);
    gtk_widget_set_visible(data->statusLabel, FALSE);
    gtk_box_append(GTK_BOX(root), data->statusLabel);

    GtkWidget* btnRow = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);
    gtk_widget_set_halign(btnRow, GTK_ALIGN_END);
    gtk_box_append(GTK_BOX(root), btnRow);

    GtkWidget* btnCopy = gtk_button_new_with_label(WideToUtf8(T(L"Copy full report")).c_str());
    gtk_widget_add_css_class(btnCopy, "bh-btn-active");
    g_signal_connect(btnCopy, "clicked", G_CALLBACK(OnReportCopy), data);
    gtk_box_append(GTK_BOX(btnRow), btnCopy);

    GtkWidget* btnGitHub = gtk_button_new_with_label("Open GitHub issues");
    gtk_widget_add_css_class(btnGitHub, "bh-btn");
    g_signal_connect(btnGitHub, "clicked", G_CALLBACK(OnReportOpenGitHub), data);
    gtk_box_append(GTK_BOX(btnRow), btnGitHub);

    GtkWidget* btnClose = gtk_button_new_with_label(WideToUtf8(T(L"Close")).c_str());
    gtk_widget_add_css_class(btnClose, "bh-btn");
    g_signal_connect(btnClose, "clicked", G_CALLBACK(OnReportClose), data);
    gtk_box_append(GTK_BOX(btnRow), btnClose);

    g_signal_connect(win, "destroy", G_CALLBACK(OnReportDestroy), data);
    gtk_window_present(GTK_WINDOW(win));
}

void UpdateLinuxWidgetWindow(GtkApplication* app,
                             bool visible,
                             const std::vector<DeviceStatus>& visibleDevices,
                             const aliases::AliasMap& aliasesMap,
                             bool useBrandAccents,
                             bool widgetBackground,
                             bool stacked,
                             bool demo) {
    g_widgetWin.app = app;
    g_widgetWin.devices = visibleDevices;
    g_widgetWin.aliasesMap = aliasesMap;
    g_widgetWin.useBrandAccents = useBrandAccents;
    g_widgetWin.widgetBackground = widgetBackground;
    g_widgetWin.stacked = stacked;
    g_widgetWin.demo = demo;

    if (!visible) {
        if (g_widgetWin.window) {
            gtk_window_destroy(GTK_WINDOW(g_widgetWin.window));
            g_widgetWin.window = nullptr;
            g_widgetWin.drawingArea = nullptr;
        }
        return;
    }

    InstallDarkCss();

    std::vector<LabelInput> labelIn;
    labelIn.reserve(visibleDevices.size());
    std::string tip;
    for (const auto& d : visibleDevices) {
        std::wstring disp = aliases::DisplayName(aliasesMap, d.key, d.name);
        labelIn.push_back({ d.kind, disp });
        if (!tip.empty()) tip += "\n";
        tip += WideToUtf8(disp) + ": " + (d.percent >= 0 ? (std::to_string(d.percent) + "%") : "?");
    }
    g_widgetWin.shortLabels = ShortLabels(labelIn, 3);
    if (tip.empty()) {
        tip = "BatteryHub: " + WideToUtf8(T(L"No devices with battery info found"));
    }

    const int count = std::max<int>(1, static_cast<int>(visibleDevices.size()));
    const int itemW = stacked ? 58 : 88;
    const int winW = 12 + count * itemW;
    const int winH = stacked ? 46 : 36;

    if (!g_widgetWin.window) {
        GtkWidget* win = app ? gtk_application_window_new(app) : gtk_window_new();
        g_widgetWin.window = win;
        gtk_widget_add_css_class(win, "batteryhub-widget");
        gtk_window_set_title(GTK_WINDOW(win), "BatteryHub");
        gtk_window_set_decorated(GTK_WINDOW(win), FALSE);
        gtk_window_set_resizable(GTK_WINDOW(win), FALSE);

        GtkWidget* area = gtk_drawing_area_new();
        g_widgetWin.drawingArea = area;
        gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(area), DrawWidgetStrip, nullptr, nullptr);

        GtkGesture* click = gtk_gesture_click_new();
        g_signal_connect(click, "pressed", G_CALLBACK(OnWidgetClicked), nullptr);
        gtk_widget_add_controller(area, GTK_EVENT_CONTROLLER(click));

        gtk_window_set_child(GTK_WINDOW(win), area);
        g_signal_connect(win, "destroy", G_CALLBACK(OnWidgetDestroy), nullptr);
        gtk_window_present(GTK_WINDOW(win));
    }

    gtk_drawing_area_set_content_width(GTK_DRAWING_AREA(g_widgetWin.drawingArea), winW);
    gtk_drawing_area_set_content_height(GTK_DRAWING_AREA(g_widgetWin.drawingArea), winH);
    gtk_window_set_default_size(GTK_WINDOW(g_widgetWin.window), winW, winH);
    gtk_widget_set_tooltip_text(g_widgetWin.drawingArea, tip.c_str());
    gtk_widget_queue_draw(g_widgetWin.drawingArea);
}
