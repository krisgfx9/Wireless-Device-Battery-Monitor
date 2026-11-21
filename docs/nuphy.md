# NuPhy WH80 (USB cable and Bluetooth) and VSPO! GEAR Gaming Keyboard Ver.2

Hardware tested with `19F5:A011`, firmware release `0116`, interface 1,
usage `0001:0000`, unnumbered 64-byte input/output payloads (65 bytes in Windows HID caps).

Protocol source: [NuPhyIO](https://drive.nuphy.io/), bundle `main.b3fb29e0.js`,
SDK `getBatteryState(0)`, `getDataPackage`, and `createCommand`.
Only `GetFunc` (`05`), offset `0020`, length `01` is requested. No initialization,
configuration, lighting or firmware commands are needed.

Request payload, zero-padded to 64 bytes:

```text
55 05 00 21 01 20 00 00
```

Actual reply payload:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

Byte 3 is the low byte of the sum of bytes 4..63. Battery is byte 8:
`value & 7F` is percentage, `value & 80` is the SDK charging flag.
The native C++ driver returned **100%, charging** on the attached keyboard.
Charging transitions and low/full boundaries have not been hardware tested;
the official firmware notes describe WH80 readings in 10% increments.
Receiver operation is outside this driver's scope.

## Bluetooth

On Bluetooth the same keyboard uses HID ID `19F5:324A` (release `0129`) and
advertises a user-visible name such as `NuPhy WH80 - 1`. It exposes two keyboard
collections and a mouse collection. The generic HID heuristic prioritizes mice,
so add this exact Bluetooth ID to the existing keyboard overrides.

Battery reporting continues to use the Windows Bluetooth battery property.
After unplugging USB, Windows reported **95%** on the attached keyboard. An
uncached read of standard GATT Battery Level (`180F` / `2A19`) also returned
**95%** directly from the keyboard. This
is a separate device/transport reading from the wired 100% observation; do not
replace it with an assumed full value or rescale it. The reason for the differing
firmware readings is not established.

## VSPO! GEAR Gaming Keyboard Ver.2

The VSPO! GEAR Gaming Keyboard Ver.2 (80% JIS, 91 keys; wired, 2.4 GHz and
Bluetooth) uses the same vendor id and the same GetFunc battery byte. Its web
driver, [vspogear-keyboard.app](https://vspogear-keyboard.app/), lists it as
`VSPO 80HE JIS`:

| Mode | HID ID | Status |
|---|---|---|
| 2.4 GHz receiver | `19F5:8F10` | hardware-tested |
| USB cable | `19F5:A022` | hardware-tested (level not usable, see below) |
| Bluetooth | `19F5:324A` | hardware-tested (Windows battery level) |

The web driver's `getBattery()` reads GetFunc byte 32 of the active profile:
`value & 7F` is the percentage, `value & 80` is the charging flag. The receiver
exposes the same interface 1, usage `0001:0000` collection with 65-byte reports,
so the unchanged WH80 request works:

```text
55 05 00 21 01 20 00 00  ->  AA 05 00 70 01 20 00 00 4F ...   (79%, not charging)
```

Reading the same byte for profiles 1..3 (offsets `0060`, `00A0`, `00E0`)
returned the same live level as profile 0 (`4E`, 78%), so the driver keeps
reading offset `0020` and does not need to query the active profile first.

On the USB cable the keyboard exposes the same collection and answers the same
request, but the level is fixed:

```text
55 05 00 21 01 20 00 00  ->  AA 05 00 85 01 20 00 00 64 ...   (100%, no charging bit)
```

The receiver read 78% just before plugging in and 77% right after switching
back, and the charging bit stayed clear while the cable was attached. The
vendor web driver also shows 100% as soon as the cable is plugged in, so this
is how the firmware reports, not a read error. The
driver therefore treats a valid cable reply only as "connected and on USB
power": it reports no level and sets charging, so the tray keeps the last known
level with a charging mark (the same handling as 8BitDo pads on a cable).
While the cable is used the receiver does not answer.

The cable and receiver entries share one device key. The cable is polled first,
so a keyboard that answers on both is reported once, as wired.

On Bluetooth the keyboard uses the same HID ID as the WH80, `19F5:324A`
(release `0136`), and advertises the name `BT5.0 KB-2`. The existing keyboard
override for that ID applies, and Windows reported **74%**, the same as the
receiver just before switching. No driver change was needed. Because Bluetooth
uses the Windows device container as its key, it is a separate tray entry from
the receiver/cable one; *Rename device...* can give it a clearer name.

With auto sleep set to 1 minute in the web driver, the receiver still answered
the same request 39 ms after 80 seconds without input, so sleep does not hide
the keyboard. A poll can still miss: while the web driver was writing a setting
the keyboard dropped out of the tray for one poll and came back on the next. The
receiver entry therefore keeps the last level, dimmed, for up to 30 minutes
(`graceSec` 1800, as other receiver drivers do).

The real charging state has not been hardware-tested.

## Driver checks

The driver checks the exact product/interface/report sizes, response header,
offset, length, checksum and percentage range. It uses a 400 ms response deadline
and ignores unrelated replies within that same deadline.

Regression test:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```
