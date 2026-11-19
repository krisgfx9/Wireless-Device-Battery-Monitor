#pragma once
// GTK4 + Cairo UI windows for BatteryHub on Linux (1:1 parity with Windows GUI):
// - Battery History & Runtime Insights viewer (src/battery_history.cpp parity)
// - Device Rename dialog (src/rename_dialog.cpp parity)
// - Request support for a device / Diagnostic report viewer (src/report.cpp parity)
// - Floating Taskbar/Desktop Widget strip (src/widget.cpp parity)

#include "../platform_compat.h"
#include "../devices.h"
#include "../device_aliases.h"

#include <gtk/gtk.h>

#include <functional>
#include <string>
#include <vector>

// Records battery samples for all connected, awake devices with a valid percentage (0..100)
// and atomically persists $XDG_DATA_HOME/wireless-battery/battery_history.tsv.
void RecordLinuxBatteryHistory(const std::vector<DeviceStatus>& devices);

// Opens (or brings to front) the dark-themed GTK4 Battery History window (1:1 with Windows).
void ShowLinuxBatteryHistoryWindow(GtkApplication* app,
                                   const std::vector<DeviceStatus>& currentDevices,
                                   const aliases::AliasMap& aliasesMap,
                                   const std::wstring& initialKey = L"",
                                   bool demo = false);

// Opens a GTK4 dialog to rename or reset a device's display alias.
// Passes an empty wstring to onSave when reset to default name.
void ShowLinuxRenameDialog(GtkApplication* app,
                           const std::wstring& deviceKey,
                           const std::wstring& originalName,
                           const std::wstring& currentAlias,
                           std::function<void(const std::wstring& newAlias)> onSave);

// Opens the dark-themed "Request support for a device" diagnostic report window.
void ShowLinuxReportWindow(GtkApplication* app);

// Shows, updates, or hides the floating Taskbar/Desktop Widget strip (1:1 with src/widget.cpp).
void UpdateLinuxWidgetWindow(GtkApplication* app,
                             bool visible,
                             const std::vector<DeviceStatus>& visibleDevices,
                             const aliases::AliasMap& aliasesMap,
                             bool useBrandAccents,
                             bool widgetBackground,
                             bool stacked,
                             bool demo = false);
