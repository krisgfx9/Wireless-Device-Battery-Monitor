#pragma once
// GTK4 + Cairo UI windows for BatteryHub on Linux:
// - Battery History & Runtime Insights viewer (backed by $XDG_DATA_HOME/wireless-battery/battery_history.tsv)
// - Device Rename dialog (validating via aliases::Trim and aliases::ValidName)

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

// Opens (or brings to front) the dark-themed GTK4 Battery History & Insights window.
void ShowLinuxBatteryHistoryWindow(GtkApplication* app,
                                   const std::vector<DeviceStatus>& currentDevices,
                                   const aliases::AliasMap& aliasesMap);

// Opens a GTK4 dialog to rename or reset a device's display alias.
// Passes an empty wstring to onSave when reset to default name.
void ShowLinuxRenameDialog(GtkApplication* app,
                           const std::wstring& deviceKey,
                           const std::wstring& originalName,
                           const std::wstring& currentAlias,
                           std::function<void(const std::wstring& newAlias)> onSave);
