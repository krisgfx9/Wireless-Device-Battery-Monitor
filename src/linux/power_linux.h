#pragma once
// 4-tier Linux fallback battery poller and diagnostic dump:
//   Tier 1: /sys/class/power_supply/* (kernel HID++ / peripheral power supplies)
//   Tier 2: UPower D-Bus (org.freedesktop.UPower)
//   Tier 3: BlueZ D-Bus (org.bluez.Device1 + org.bluez.Battery1)
//   Tier 4: Standard HID Battery Descriptor fallback (PollGenericHid)

#include <string>

#include "../drivers/drivers.h"

void PollLinuxPower(PollContext& ctx);
std::wstring DumpLinuxPower();
