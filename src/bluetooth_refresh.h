#pragma once
#include "devices.h"

#include <algorithm>
#include <map>

constexpr unsigned kBluetoothLastRetryMs = 3000;

inline bool BluetoothBatteryPending(const DeviceStatus& device) {
    return device.kind == DeviceKind::Headset && (device.bluetoothAddress || device.via == L"Bluetooth") &&
           device.connected && !device.asleep && device.percent < 0;
}

// Used by the poll worker. Each connection gets one immediate scan and up to two retries.
class BluetoothRefresh {
    std::map<std::uint64_t, std::uint64_t> connectedAt_;

public:
    void ConnectionChanged(std::uint64_t address, bool connected, std::uint64_t now) {
        if (connected) connectedAt_.emplace(address, now);
        else connectedAt_.erase(address);
    }

    unsigned NextWait(const std::vector<DeviceStatus>& devices, std::uint64_t started,
                      std::uint64_t finished, unsigned fallback) {
        unsigned wait = fallback;
        for (auto it = connectedAt_.begin(); it != connectedAt_.end();) {
            const auto elapsed = started - it->second;
            const bool ready = std::any_of(devices.begin(), devices.end(), [&](const DeviceStatus& device) {
                return device.bluetoothAddress == it->first && device.connected && !device.asleep &&
                       device.percent >= 0 && device.percent <= 100;
            });
            if (ready || elapsed >= kBluetoothLastRetryMs) {
                it = connectedAt_.erase(it);
                continue;
            }
            const auto due = it->second + (elapsed < 1000 ? 1000 : kBluetoothLastRetryMs);
            wait = std::min(wait, due > finished ? static_cast<unsigned>(due - finished) : 0u);
            ++it;
        }
        return wait;
    }
};
