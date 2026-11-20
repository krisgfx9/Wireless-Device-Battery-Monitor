<!--
  Single-file BatteryHub Documentation Translation Template
  How to translate into a new language (zero build scripts needed):
  1. Copy this file to docs/i18n/<code>.md (for example: docs/i18n/it.md).
  2. Translate all prose, headings, tables, and the Table of Contents into your language.
  3. Keep every <a id="sec-..."></a> and <a id="top"></a> anchor tag verbatim so links keep working.
  4. Keep CLI flags, code blocks, USB VID:PIDs, hex frames, file paths, and URLs verbatim.
  5. Bold your own language in the top lang-switcher bar, and add a link to your file in README.md, CONTRIBUTING.md, docs/*.md, and docs/i18n/README.md.
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Languages:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Add a language](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Complete Documentation (Translation Template)

> This single standalone Markdown file bundles every visible document in the repository so translators only need to maintain **one file per language**.

## Table of Contents

1. [BatteryHub Overview, Supported Devices, Install, CLI & Build (`README.md`)](#sec-readme)
2. [Contributing Guide (`CONTRIBUTING.md`)](#sec-contributing)
3. [Pull Request Template (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Release & Signing Guide (`docs/releasing.md`)](#sec-releasing)
5. [Keychron Keyboard 2.4 GHz Firmware Patch (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [GameSir Cyclone Pro BLE Support (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Multi-Language Usage & Localization Guide (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Areson 25A7 Receiver (`docs/areson.md`)](#sec-areson)
10. [DARKRIM SHADOW Receiver (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K Receiver (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Rapoo Mouse Battery Support (`docs/rapoo.md`)](#sec-rapoo)
16. [RAWM Protocol Notes (`docs/rawm.md`)](#sec-rawm)
17. [VAXEE 4K/8K Receivers (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Section:** BatteryHub Overview (`README.md`) · [English original](../../README.md) · [↑ Top](#top)

# BatteryHub

*Formerly **Wireless Battery**. Version 1.1.0 renamed the app; an update keeps your settings, startup choice and battery history.*

[![Support me on Ko-fi](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Donate with PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Join our Discord](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Star on GitHub](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Share on Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Report a device](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Help translate](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Battery levels of your wireless mouse, headset, keyboard and controller, right on the Windows taskbar.

![BatteryHub on the taskbar](../screenshot.png)

> **Just want it working?** Download **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** from the latest release, run it and click through. That's it.
>
> **Experienced users** can grab the portable zip, use the [command-line options](#command-line), or [build it from source](#build) with `make` or `build.bat`.
>
> **Like it?** BatteryHub is free and open source. If it saves you a trip into vendor software, you can support it on [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) or [GitHub Sponsors](https://github.com/sponsors/krisgfx9). It helps me keep my apps free alongside my studies. Not able to donate? A ⭐ star, sharing it, or reporting an unsupported device with a `--dump` helps just as much.

- **Tiny**: a ~350 KB app using about 2 MB of RAM. It's plain C++/Win32, with no runtime and no background service, and installs in seconds without admin rights.
- **No vendor software needed**: it talks to the devices directly. G HUB, Synapse, iCUE, GG and NGenuity can stay closed (or keep running; they don't conflict).
- **Many brands**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, PlayStation and Xbox controllers, Samsung Galaxy Buds, any Bluetooth device Windows knows a battery level for, and every headset the bundled [HeadsetControl](https://github.com/Sapd/HeadsetControl) supports.

## Display

**On the taskbar (default):** `🎧 30%  🖱 93%` next to the notification area, drawn with the Windows icon font.
- **Low battery:** a red number means 15% or less.
- **Charging:** a blue ⚡ appears next to the number. Once the device is fully charged and still on power, it turns into a green ✓.
- **Asleep:** dimmed text means the device is asleep and the last known value is shown.
- **Disconnected (optional):** turn on *Show disconnected devices* to display a dimmed `×` for devices whose driver explicitly reports an offline wireless link. This does not infer disconnection from a missed battery poll; the default remains to hide offline devices.
- **Two devices of one kind:** with two mice (or two controllers...) both would get the same icon, so each one gets a tiny caption of up to 3 letters in the corner of its icon, taken from its name (`MX`, `PRO`), or a number when the names do not tell them apart. A device that is alone in its kind shows no caption.
- **Theme:** it follows light/dark mode and DPI scaling.
- **Transparent taskbar themes** (e.g. Windhawk's Taskbar Styler): turn on *Background behind taskbar text* in the menu to keep the text readable over the wallpaper.
- **Several monitors:** the widget shows on every monitor's taskbar, next to its clock, so it stays visible while a game runs fullscreen. *Show the widget on* in the menu picks *All monitors*, *Main monitor only*, or one display (e.g. only *Display 3*).
- **More display options:** *Icons above percentages* stacks each icon over its level to save width; *Brand colors* shows known brands in their color (Razer green, HyperX red, ...) with a small level bar; two devices of the same kind get a tiny caption so they can be told apart; left and right taskbars get a column of devices.
- **Languages:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 and 繁體中文. Both the Windows and Linux apps follow the system display language; *Language* in the menu picks another one, and the Windows installer also supports all 19 languages. UI phrases live in editable static `lang/*.json` files, and complete translated documentation lives in [`docs/i18n/`](README.md). See [Translations](#translations) to edit or add a language.
- **Brand colors:** devices of 15 known brands get their maker's color, with a soft glow and a thin level bar under the
  percentage: Razer green, Logitech blue, SteelSeries orange, Corsair yellow, HyperX / ROG / ZOWIE red, PlayStation,
  Xbox, Samsung, Apple, Jabra, JBL, Cooler Master and Steam. Each color has a dark- and a light-taskbar shade. The brand
  comes from the driver that found the device, then the vendor ID, then the name; colors and rules are in
  `src/brands.cpp`. Turn it off with *Brand colors* in the menu.

**Tray icons:** one icon per device with the number drawn in it, plus a "Low battery" notification at 15%. The app switches to this automatically when the taskbar is vertical or can't be found.

**Custom device names:** open the device submenu and select *Rename device...* to set a name
(up to 64 characters). The name is shown in the taskbar widget's tooltip/caption,
tray tooltip and notifications, and the device menu. Use *Reset to original name*
to restore the driver's name. Names are stored locally in the current user's
Windows registry (`Software\WirelessBattery`, `DeviceAliases`), using the stable
device key. Renaming never changes driver matching, protocol queries, or `--list` /
`--dump` diagnostic output. No account or network access is needed.

Hover for details. Click for the menu: every device (click one to hide or show it), display mode, *Refresh now*, *Start with Windows*, and *Exit*. Levels refresh every 60 seconds (*Check battery every* in the menu changes this), and right away when a device is plugged in or the PC wakes up.

## Smart Battery Alerts (experimental)

You can set a **per-device low-battery notification threshold** from each device's
submenu: **Battery alerts** → *Use default (15%)*, *Disable notifications*,
or one of 5%, 10%, 15%, 20%, 25%, 30%, 35%, 40%. The existing 15% default stays
unchanged unless you choose an override. Settings are stored by device key in
the current user's Windows registry (`Software\WirelessBattery`, `AlertThresholds`).

An alert is triggered only from a real, fresh 0–100% battery reading when the
device is connected, awake and not charging. An alert is issued once, and will
re-arm after the level climbs more than 10 percentage points above the chosen
threshold (or when charging begins). Missing readings or sleeping devices do
not retrigger alerts. Hidden devices don't produce notifications. Disabling
notifications for one device does not hide it or change its percentage.

Both taskbar-widget and tray-icon modes support notifications. Since Windows
needs a notification-area icon to display a legacy balloon, widget mode may
show a temporary notification icon for up to one minute after an alert.
Widget colours and the low-battery highlight still use the project's
original global 15% threshold, independently of the notification setting.

## Battery history & insights

Right-click a device in the taskbar widget or tray menu and choose **Battery history...**.
The native, DPI-aware viewer (it follows the Windows light/dark theme) shows recorded battery levels with connected sample lines over the last **24 hours**, **7 days**, or **30 days**, along with the latest reading, lowest/highest level, change in percentage points, and sample count. You can clear the selected device's history from the viewer.

History is recorded **locally only** for connected, awake devices reporting a numeric percentage. Readings are sampled at most once every 30 minutes per device (except charging-state transitions, with a 60-second minimum). Data is kept for up to 30 days and the local file is kept under about 2 MB. The app never probes hardware beyond its existing polling, sends no history data over the network, and makes a conservative, approximate time-to-empty estimate from recent discharge observations only. At least four points, two hours, a three-percentage-point decline, a fresh reading and a stable discharge segment are required. Charging, old readings or insufficient data suppress the estimate; device-reported runtime is not available. The estimate is not a guarantee. Missing chart data is shown as gaps, not interpolated.

Turn off **Record battery history** in the menu to stop saving readings; what was already saved stays until you clear it in the viewer. The file is stored in `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Its device identities are encoded (not encrypted); the file is local to your Windows account. In `--demo`, the chart uses synthetic data that is never saved. **Note:** history starts collecting only after this feature is installed and the app has been running for a while.

## Supported devices

| Vendor | Devices | How |
|---|---|---|
| **NuPhy** | WH80 over USB cable (`19F5:A011`) or Bluetooth (`19F5:324A`), hardware-tested | USB: read-only NuPhyIO battery query; Bluetooth: Windows battery level with keyboard classification ([protocol notes](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) on its `3654:6901` USB receiver (hardware-tested) | Read-only CRC-checked battery query and charging flag; observed coarse readings in 10% steps, finer precision unverified ([protocol notes](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX on the KP 8K receiver (`1D57:FA65`; model `73` hardware-tested, model `74` untested) | Passive Xenta status reports; two matching frames confirm the level ([protocol notes](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, tested), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` tested, `002D`/`002A`), A50 Gen 3 (`9886:0015` tested, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), via USB base station | Battery percentage, charging and docked status |
| **Logitech** | Mice and keyboards on Unifying, Bolt, Lightspeed (including the PRO X3 SUPERSTRIKE dongle `046D:C54F`) and Nano receivers, over USB or Bluetooth; G headsets (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 on the newer `046D:0ADF` dongle | HID++ 1.0 / 2.0 with feature discovery: unified battery, battery level, voltage, ADC; G435: CRC-16 framed vendor reports, `GET_BATTERY` in mV |
| **Razer** | Wireless mice, keyboards and dongles; BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X headsets, V3 Pro for Xbox (`1532:0A55` receiver, `0A4E` cable); Barracuda X (2022) on its 2.4 GHz receiver (`1532:0550` or `1532:0552`); Barracuda Pro (`1532:053A`) | Razer feature-report protocol; BlackShark vendor protocols (V3 / V3 Pro / V3 X queried every 5 min); Barracuda X: Airoha battery and cable queries through the receiver |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (including `1038:225D`), Arctis Nova Elite (base station `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, untested), Aerox 3 Wireless CS2 Dragon Lore Edition (receiver `1038:1878`, cable `187A`), Aerox 3 Wireless Gen 2 (receiver `1038:1890`, cable `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Vendor HID reports; Aerox/Prime and Rival 650 share one entry across receiver and USB cable, preferring the cable reading when both answer |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 wireless; Bragi devices (Virtuoso, Void V2, HS80 MAX, Slipstream mice and keyboards, including the newer Slipstream receiver `1B1C:2B00`, e.g. Scimitar Elite SE Wireless, and Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, untested) | Vendor HID reports, Bragi `GET` (read-only), Compx 17-byte battery protocol (read-only) |
| **Cooler Master** | MM712, MM731 (2.4 GHz dongle or USB cable) | Vendor HID status report (read-only) |
| **Press Play** | ICARUS V2 Nearlink on its `7768:6434` 2.4 GHz receiver (driver hardware-tested at 90%; protocol captured at 100% and 90%) | Read-only output report `06 05` on `FFB2:0001`; battery percentage in reply byte 14 |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` for PS, untested), Cloud Flight S, Cloud Stinger Core Wireless (including DTS `03F0:0A8E`, tested), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (2.4 GHz dongle), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (2.4 GHz dongle) (2.4 GHz dongle `03F0:0F98`, tested; `0D97` untested) | Vendor HID reports (Haste 2: [protocol notes](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Vendor feature report |
| **Hitscan** | Hyperlight X, Hyperlight N | Vendor feature report (same protocol as Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, Pulsar and ATK VXE wireless mice (e.g. VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (receiver 3554:F512) | Shared vendor protocol with checksummed replies |
| **Pulsar X2 V3** | X2 V3 on the 1K dongle (`3710:5402`) or USB cable (`3710:3402`); X2 V3 eS on the 8K dongle (`3710:5403`) or USB cable (`3710:3406`) | 64-byte vendor feature report, battery register `08 81 01` (read-only) |
| **ATK / VXE NK** | VXE R1 NK and other NearLink mice on the NK mouse NANO dongle (`373B:1216`) | ATK BITMOUSE output report 08 on `FF05:0001` (battery and charging) |
| **ATK 8K Nano** | ATK / VXE mice on the ATK 8K Nano Dongle (`373B:1178`) | Holtek GetConfigData (`82`) feature report on `FF10:0001` (from ATK HUB; battery and charging) |
| **ATK headsets** | ATK N9 Pro, N9 Ultra (first generation) | Virtual COM port protocol (the ATK desktop app must be closed) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK and their 8K dongles | Glorious or Kysona protocol, depending on the model |
| **Keychron mice** | M4 and other Keychron mice on the 2.4 GHz receiver; 4K mice (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) on the Keychron 4K Link receiver (`3434:D038`); 8K mice (M5 8K, G6 HE 8K ...) on the TurboLink 8K receiver; 8K mice on the Ultra-Link 8K receiver (`3434:D028`); older mice (M1, M2, M3, M3 mini, M6, M7 ...) on the 1K receiver (`3434:D030` / `D031`); Nape Pro trackball on the Link-KM receiver or cable | Vendor report from Keychron Launcher (1K receiver: feature report 51 06, as used by the Keychron desktop app; Ultra-Link 8K: reports B5 03 / B3 06 on `FFC1`; Nape Pro: raw HID A7 31) |
| **Keychron keyboards** | K5 Max (`3434:0A50`, tested) on the Keychron Link receiver (`3434:D030`) or USB cable; other Keychron QMK wireless keyboards once built with the same patch | Raw HID on `FF60:0061`: `B2` asks the receiver which keyboard is linked, `A4` returns level, voltage and charging. **Needs patched keyboard firmware:** see [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). Stock firmware only reports over Bluetooth |
| **CHERRY** | MX 3.0S Wireless keyboard on its 2.4 GHz dongle (`046A:00EA`, tested) or USB cable (`046A:00E3`, tested) | Vendor HID query `1A` on `FF1C:0092` (read-only), with USB-powered state. Bluetooth is covered by the Bluetooth support |
| **CHERRY** | Cherry XTRFY wireless mouse on the 1K receiver (`046A:0330`, tested) | CompX 17-byte battery protocol (`08 03` link status, `08 04` GetPower), same framing as the Corsair Sabre V2 Pro (read-only) |
| **Arbiter Studio** | Akitsu (`373E:000A` 8K receiver, `373E:0009` cable), Akitsu 3950 (`373E:0039` 8K receiver, `373E:0038` cable), Akitsu Medium (`373E:0067` 8K receiver and `373E:0066` cable, both tested) | Read-only vendor feature report `0x83` on `FFFF:0000` from Arbiter Web HUB (battery and charging) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (cable, 1K and 4K/8K dongles) | Vendor feature report from LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) on the 4K dongle; XM2we on its original receiver (`3367:1961`) | Vendor feature report `A1`, battery command `B4` (read-only) |
| **ATK / VGN / Evision keyboards** | ATK V75X and VGN / VXE keyboards (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) on the shared 2.4 GHz receiver (`320F:5088`) or USB cable (`320F:5055`), recognized by product name; keyboards whose `320F:5088` receiver is named "Wireless Gaming Keyboard", e.g. Feker Alice80 (tested) | Evision output report `04`, battery command `1A` (from ATK HUB and VGN HUB); asked at most every 10 minutes over the receiver |
| **Redragon (Evision)** | K1NG M999 (tested) on the `320F:226F` 2.4 GHz receiver; the receiver id may be shared by other models | Same Evision protocol as the ATK keyboards (report `04`, command `1A` on `FF1C:0092`), asked on every poll; charging shown on the magnetic dock; with the USB cable plugged in the receiver keeps repeating the old level and no charging state |
| **Audeze** | Maxwell on the USB dongle (`3329:4B19`) or USB-C cable (`3329:4B1A`); Maxwell 2 on the USB dongle (`3329:4B29`, tested); Xbox ids untested | Vendor report `06` / input report `07`, battery attribute `0CD6` (single read-only query) |
| **ENDORFY** | Viro Wireless on its 2.4 GHz dongle (`3738:0072`, untested) | Airoha RACE "get battery" (`0CD6`) on vendor report `06` / input report `07`, the same read-only query as Audeze and Skullcandy dongles; no charging state |
| **Turtle Beach** | Stealth 700 Gen 3 on the USB transmitter (`10F5:2251`, tested in HaloBattery; PC version `10F5:2262`, untested) or the headset's own USB cable (`10F5:2253`) | RACE `0x9942` (enable the CoAP client) and a CoAP `GET /GSI` tunnelled in RACE `0x9902`, as Swarm II does; battery from key `240` (no charging flag) |
| **AKG** | N9 Hybrid on its USB dongle (`0ECB:20D9`, tested) | Airoha RACE on `FF13:0001`: output report `06`, input report `07`, battery attribute `0CD6` (single read-only query) |
| **NZXT** | Lift Elite Wireless on its dongle (`1E71:2101`) or USB cable (`1E71:2129`) | Vendor read `4E 02 81 .. B0` (from NZXT CAM captures) |
| **Poly / Plantronics** | Voyager 8200 UC and other headsets behind the BT600 adapter (`047F:02EE` / `02F7`) | Report `07` get/set protocol, battery item `0A 1A` (read only) |
| **WLMouse** | YING Magnesium (YING 8K receiver `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (receiver or cable; not the Beast X 4K); Beast X V2 (8K receiver `36A7:A856`); Beast G (8K receiver `36A7:A860` or cable `36A7:A861`; untested) | Vendor feature report, status command `0x83` (YING: same protocol as Glorious) |
| **Finalmouse** | UltralightX on its 2.4 GHz dongle (`361D:0100`, tested); Starlight X on its dongle (`361D:0300` / `0301`, tested). Not on the mouse's own cable | xpanel vendor reports on `FF00`: read-only GETs, then *wake/all* (`0xE0`); battery voltage on xpanel's curve, or the Starlight X's own percentage, plus charging state |
| **VAXEE** | Wireless mouse on the VAXEE 4K receiver (`3057:1002`) or 8K receiver (`3057:2002`, e.g. NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless over USB cable (`3057:1011`) | Read-only vendor feature report `0E` on `FF05:0001`; battery in 5% steps, charging state ([protocol notes](#sec-vaxee)) |
| **Scyrox** | V12M on its 2.4 GHz receiver (`395A:0006`) | S-Center 2.0 profile read (output report `08`, command `01`) on `FF00:0002`; battery only, no charging state |
| **HECATE** | G5M PRO and other HECATE mice on the same receiver, and USB cable `35BB:D3FA / D3FC / D3FD` | Kysona protocol |
| **Redragon** | Compx-based wireless mice: M916 Pro 1K (tested), M913 Impact Elite (tri-mode), G49 (receiver or cable) | Kysona protocol (the Areson `25A7` receivers are listed under Areson) |
| **Taidu (钛度)** | TSG808 on its Compx 2.4 GHz receiver `3554:F5D5` (tested) | Kysona protocol |
| **Areson (Redragon)** | M915RGB-WL (tested), original M913 Impact Elite and other mice on the `25A7:FA07` / `FA08` receiver | 17-byte `GetPower` feature report; level in 10% steps and a charging flag |
| **Ninjutso** | Sora V2 on the 1K receiver (`1915:AE1C`, tested) or USB cable (`1915:AE11`, tested); Ten Air (receiver `093A:EB01` and USB cable `093A:E020`, tested) / Ten (`093A:EB01` / `E020`, untested) | NinjaForce feature report `0x05` (`0x15` for Sora V2) and `0x06` (`0x13`/`0x12`/`0x11` for Ten / Ten Air) |
| **Sprime** | PM1 on the 2.4 GHz receiver (`1915:AC1C`, tested; `1915:AD8C`) or USB cable | Same feature report 0x05, status command 0x15, from Sprime's web driver (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 on the RAWM HS Receiver (`1915:2346`, tested); ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* and SADES Dagger mice on their RAWM receivers (`1915:232A`–`234B`) or USB cable | RAWM HUB 2.0 device-info query through the receiver (JSON with battery % and charging), read-only ([protocol notes](#sec-rawm)) |
| **AULA** | F75 / F87 Pro / F99 wireless keyboards on the 2.4 GHz receiver | Report 0x13 frame, command 0x4A, sum checksum (Bluetooth and wired modes untested) |
| **AULA mice** | X9 Ultra (tested) on AULA-8K Dongle `320F:22A0`; receiver ID shared with V9 models | Report `04`, read-only battery command `1A` between START `01` / END `02` on `FF1C:0092`; 2.4 GHz only |
| **SONiX keyboards (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (tested), EPOMAKER EA75 (tested), AULA F108 Pro on the `05AC:024F` 2.4G dongle; AJAZZ AK980 V2 on the `0C45:FEFE` dongle; AJAZZ AK820 Pro on the `0C45:FDFD` or `0C45:FEFE` dongle; EPOMAKER P75 on `342D:E479` (hardware untested) | Vendor report `20 01` on usage page FF60, sum checksum (2.4G mode only; no charging indication) |
| **Additional SONiX receivers (hardware untested)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | Same battery-only `20 01` query; exact VID:PID and FF60:0061 collection with 33-byte reports required; 2.4G only, no charging indication |
| **36B0 keyboards (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB on the `36B0:3002` 2.4G dongle or USB cable `36B0:3009` (protocol tested on both by the reporter of #343); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) on the same dongle or cable (untested); URX Core75 on the dongle (confirmed in HaloBattery); EVO80 (untested) | PMO Hub firmware: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` on usage page FF60, from pmohub.cn. URX / VIA firmware: VIA custom-get `08 00 07` (channel 0, value 7), from URX HUB via HaloBattery. No charging indication |
| **DAREU** | EM901X on the `260D:1074` 2.4 GHz receiver or `260D:1090` USB cable (battery reading tested on both; receiver dock/undock charging-flag transitions tested) | Battery-only feature report `08`, command `04`; reply `09` on a separate vendor collection. Requires one unambiguous input/feature pair per product ID. Prefers a valid USB reading when both are connected; the receiver can return cached telemetry even with the mouse switched off |
| **DAREU** | A84 keyboard (`260D:0022`, untested) | SONiX feature report on interface 0, command `04 F6` (the official A84 driver's battery read); level in percent, no charging flag |
| **DAREU** | A980 Pro on the `260D:1131` multi-mouse receiver and on its USB cable (`260D:1148`) (battery level tested on hardware; charging flag confirmed while plugged in) | Togran protocol: 65-byte feature report `0A` on the consumer-control collection; slot query (class 0 / `A0`) then battery query (class 7 / `80`), on slot 0 over the cable. Read-only |
| **Sharkoon** | Skiller SGM50W on `260D:1125` (untested) | Same Compx query as the DAREU EM901X (feature report `08`, command `04`; reply `09` on `FF01:0000`); Sharkoon's firmware updater for it is a Compx tool on VID `260D` |
| **Zenith** | Zenith Pro on the `260D:1114` 2.4 GHz receiver (battery reading tested; charging untested) or `260D:1143` USB cable (untested) | Same Compx command (`08`, `04`) as an output report on `FF02:0002`; reply `08 04` on the same collection with percent, charging flag and millivolts, checked by the `0x55` byte sum |
| **AJAZZ AK992** | Telink 2.4 GHz receiver `320F:50C3` (tested) | EVision battery query on HID collection `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, DW series (U2-DW, S2-DW ...) and U2 on its 2.4 GHz receiver | Community-documented read-only vendor commands |
| **Royal Kludge (RK)** | MG6 Pro on the 2.4 GHz dongle (`2E3C:00A6` / `00E6`) or USB cable (`2E3C:00A5` / `00E5`) | QiWang 64-byte frame from RK's web driver, `GET_BATTER_VOL` read (percent, voltage, charging) |
| **ASUS ROG** | Strix Scope II 96 (RX), Azoth, Falchion keyboards; Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact mice; Pelta headset (2.4 GHz dongle); Cetra Open Wireless earbuds (SpeedNova dongle `0B05:1CAC`, L / R / case); the Omni Receiver | ROG HID battery query |
| **Machenike** | L7 Arctic / L7 Mix on the `248A:FF4C` 2.4 GHz receiver or `248A:FF4E` USB cable (both tested) | Read-only feature report `51`, status command `06`; battery and charging. [Protocol notes](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS on its 2.4 GHz dongle (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (2.4 GHz receiver `0DB0:0D3C`, tested; USB cable `0DB0:0D3B`) and CLUTCH GM41 Lightweight Wireless (receiver `0DB0:0D4C` / cable `0DB0:0D4B`, from an owner's captures) | Read-only vendor query `0F 20` on `FF0D:00B0` and `FF00:0001`; battery and charging flag in one byte (protocol from MSI Center's Gaming Gear module); GM41: passive `A0 xx 07 …` reports on `FF10:0006` |
| **MCHOSE** | L7 / L7 Pro / L7 Ultra (L7 Ultra tested), M7 / M7 Ultra, A7 / A7 Ultra, K7 mice on the 2.4 GHz receiver or USB cable; A5 V2 Ultra (2.4 GHz receiver `3837:100C`, tested), K7 Ultra (2.4 GHz receiver `3837:1001`, tested; A7 V2 Ultra+ `3837:100B` expected to work, issue 227); G3 V2 (2.4 GHz receiver `3837:4245` and USB cable `3837:418C`); K7 V2 Ultra+ on the 2.4 GHz receiver `3837:1014` or on its USB cable `3837:4028` (both tested; the other new-family receiver ids `1018`, `1016`, `102C`, `102D` are untested) | Vendor feature report, inverted payload (protocol from alexfrih/mchose-linux); Realtek `3837` dongles answer the same query with the vid field set to `41E4` (A5 V2 Ultra) or `3837` (K7 Ultra); G3 V2: read-only vendor query on `FF01:0010`; K7 V2 Ultra+: 64-byte report `0x4D`, device-info command `0x0900` on `FF01:0001` (protocol from M HUB's web driver) |
| **MCHOSE A5 (first generation)** | A5 Pro / A5 Pro Max on the 1K or 4K 2.4 GHz receiver (`2023:F013`, `2023:F015`, `2023:F018`) or the USB cable (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); untested here | Read-only battery command `0x83` (page 0) in a 64-byte feature report on `FFFF`, reply marked `0xA1` (protocol from the z750sasr A5 Pro Max web driver and HaloBattery, ids from Klegus/mchose-macos) |
| **MCHOSE headsets** | V9 Pro 2 on the 2.4 GHz dongle (`3837:6011`, tested) | M HUB's read-only "MC" battery frame (report `0x55`, sub-command `0x0B`) on `FF07:0222`; battery and charging flag in one byte (protocol from M HUB's web driver) |
| **AULA / MCHOSE / Redragon keyboards** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 and the other M HUB keyboards; Redragon Horus Pro / Pro V2 (K618RGB-PRO) on the 2.4 GHz receiver (`3554:FA09`, `41E4:2001`); MCHOSE K87 on the `05AC:024F` receiver (BY layout on interface 1, not the SONiX one) | Report 0x13 frame, command 0x4A (MCHOSE and Redragon models identified by command 0x05, as in M HUB); Bluetooth and wired modes not covered |
| **MCHOSE keyboards** | G75 V2 on the 2.4 GHz receiver `3837:3033` (tested); the same receiver ships with the G87 V2 and K99 V3 (same protocol, untested); the K87S pairs the same receiver id with a different protocol and is not covered | M HUB's read-only "GLW" func-config query on the id-less 64-byte `0001:0000` collection: request flag `0x55`, command `0x05`, battery in payload byte 32 (bit 7 = charging), additive checksum |
| **AULA SC580** | SC580 / SC580X mouse over USB cable (`088D:062E`, tested) or its 2.4 GHz receiver (`089D:062F`, tested) | Read-only command `0x30` (device info) on the 33-byte vendor collection FF02:0000, sum checksum; while charging the mouse reports a fixed 100, so the last level is shown; Bluetooth mode not covered |
| **AULA HERO 68 Air** | HERO 68 Air on the 8K Wireless Receiver (`372E:106C`) | Acknowledged 20-byte frames on usage page FF60 (four data frames and a trailer per message), read-only battery command 0x87, charging flag 0x10 after the level; Bluetooth and wired modes not covered |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra and S9 Max / Pro / Ultra / Ultra+ on the "Gaming 2.4G" receiver (`372E:103D`); S9 Ultra on its USB cable (`372E:1027`) | Read-only feature report `03` on `FF00:0001`: link check `47`, device basics `4F 81` (battery percent and charging bit), from EWEADN's web driver |
| **Rapoo VT** | VT3 Max Gen 2 (tested); VT9 Gen 2 (tested); other Nordic 54L VT mice exposing the same status interface; legacy VT3 Pro (experimental); VT1 Pro Max (from the owner's USB captures) | Passive HID status report `07` on `FF00:0002` (16 or 19 bytes; 13 bytes on some VT3 Max Gen 2 receivers); legacy `BB` restricted to VT3 Pro `1215/4415` and VT1 Pro Max `1233/4433`. Receiver and USB cable, with charging state |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (Xenta models 30/50; legacy 3D), Delux M800 Pro, Ajazz AJ179 family; AJ159 and other AJ-series mice on the 3151 receiver; AJ139 V2 MC (`A8A5:2255` receiver, `A8A4:2255` cable) | Vendor reports (M900 Pro: passive status broadcasts or feature query, Xenta events 40/41; AJ-series: 0xF7 status poll, then feature report 0x05) |
| **Incott** | G23 V2 / G24 (`093A:522C` receiver, `093A:622C` cable) | Read-only status feature report 09 |
| **Attack Shark and other Chinese brands** | Rongyuan receivers (81 models: Attack Shark R3 and AJAZZ AJ179 Pro on `3151:402D`, K86, X82 PRO HE, Ajazz keyboards, some MSI and others; the K86 over Bluetooth is shown as a keyboard); Xenta receivers (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; the X6 also on `1D57:FA61`, untested); Semico 1A2C keyboards (Attack Shark X98 on `1A2C:8FFF` dongle, tested, and `1A2C:A034` cable; AJAZZ AK820 Max Plus on `1A2C:8FFF` / `1A2C:A036`) | Rongyuan status report; Xenta passive broadcasts; Semico read-only `0x0E` status query (`AA 55 CC 33` on `FF02:0002`; charging flag omitted because X98 reports `state=1` both on battery and while charging) |
| **Wraith** | W1 / W1 Freestyle (`093A:522C` receiver, `093A:622C` cable; same ids as Incott, told apart by the model code) | Read-only per-button reads `86` (feature report 09) over all buttons, then the pushed status input report 09 |
| **Fantech** | Helios Go XD5 (wired `25A7:FA7B`, dongle `25A7:FA7C`); Raigor III (tested), Raigor II WG10 and other generic 2.4G Mouse devices on the reused `1EA7:0066` / `1EA7:0064` dongle | Helios Go XD5: vendor feature report `08`, command `04`, sum-to-`0x55` checksum. Raigor/2.4G Mouse: read-only `B5` status-page query on `FFB5:0001`, chunk `94` = last reported percent (may be stale while asleep, off or charging; no charging state) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, wireless adapter); INZONE H9 II and H5 headsets; INZONE Buds (USB-C dongle) | Input report; INZONE vendor protocol |
| **Fractal Design** | Scape headset on its 2.4 GHz dongle or USB-C cable | Vendor `GET_DEVICE_STATE` query from Fractal's Adjust Pro web app (usage page FF00) |
| **Jabra** | Every Jabra headset that speaks the GN Protocol (Evolve2 / Evolve3 and others), on its own USB cable or behind a Jabra Link dongle; no product id list, DECT bases (Engage, PRO 9xx, GO 6400, Link 400) left out; name read from the headset | GNP status query (class 12 / op 02) on usage page FF00, usage 05 or 01, at GNP address 08 (USB) or 04 (dongle) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), 2.4 GHz receiver or USB; Apex 5 (`37D7:2501`), 2.4 GHz receiver or USB | Vendor HID info query on `FFA0:0001`; 0–5 battery level mapped to 0–100% in 20% steps, with charging state; no Space Station service required |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite on the 2.4 GHz receiver; Nova 2 Lite on USB; G7 Pro (tested: Zenless Zone Zero edition, receiver `3537:105E`) and other GameSir pads in Xbox (GIP) mode; Cyclone 2 (XInput mode, receiver or cable); Cyclone Pro on its 2.4 GHz dongle (`3537:1015`, pair the pad with Windows over Bluetooth once) | Vendor device-info query (usage page FF7A); Windows.Gaming.Input battery report (real %) in Xbox mode; Cyclone 2: vendor battery request (usage page FFF0); Cyclone Pro: GameSir app base-info request over Bluetooth LE (service `0x8650`), read every 2 min |
| **BEITONG** | KP20 / BTP-KP20 on its 2.4 GHz receiver (`20BC:5128`, XInput mode, tested) and KP40D / BTP-KP40D on its receiver (`20BC:515C`, XInput mode); BEITONG iControl not required | Vendor "get base info" query on usage page `00FF` (report `02`, nibble-scrambled payload), with charging state |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` tested on 2.4 GHz dongle, D-input `2DC8:6012` — hold B while turning it on, firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Vendor HID status query (`FF7A`/`FFA0`) and SDL gamepad input report `01`/`04`, with charging state |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Status frame the earbuds push on Samsung's RFCOMM (SPP) service, read-only. The tray shows the lower earbud; the tooltip lists left, right and case. The Galaxy Buds app must be closed |
| **Nothing / CMF** | Nothing Ear (3a) (tested), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Read-only `0xC007` battery query on Nothing's NT Link RFCOMM service (`aeac4a03-dff5-498f-843a-34487cf133eb`). The tray shows the lower earbud; the tooltip lists left, right and case |
| **Akko** | Akko Air 01 (`3151:5006`, 2.4 GHz receiver, tested) and Akko V9 Dash Pro (`38EE:000C`, 2.4 GHz receiver, tested) | Air 01: Rongyuan `0xF7` status report; V9 Dash Pro: read-only 64-byte `0x1A` status query on `FF1C:0092` with charging state |
| **MOONDROP** | GM01 Pro headset on its 2.4 GHz dongle (`35D8:0133`); on its USB cable it shows as charging with the last level | WalkPlay vendor read command on report `4B` (read-only) |
| **VGN** | OMNISOUND (ZHOUTING) headset on its 2.4 GHz dongle (`372E:10BB`, tested) | V HUB "ZHOU" query: output report `55` with payload `65 01` on the control collection `000C:0001` (32-byte input, 64-byte output reports); the percentage comes back in the reply (read-only) |
| **JBL** | Quantum 650 Wireless (tested, 2.4 GHz dongle); Quantum 520, 650X, 850, 950, 950X Wireless (dongle or USB cable, same protocol, untested) | JBL "HIDV3" device-info query for the battery feature (usage page FF12), with charging state |
| **JBL** | Quantum 350 Wireless (tested on Windows with the `0ECB:206B` 2.4 GHz receiver); Quantum 610 Wireless (`0ECB:205C` 2.4 GHz dongle, untested on Windows); Quantum 360 Wireless (`0ECB:2115` 2.4 GHz dongle, untested) | HIDV1 feature reports for wireless connection and battery percentage |
| **Xbox** | Controllers on the Xbox Wireless adapter, USB or Bluetooth; headsets plugged into a controller | Windows.Gaming.Input battery report (real %), XInput fallback |
| **Switch Pro-compatible** | Controllers presenting as `057E:2009` (tested: GameSir Tarantula Pro via the 2.4 GHz receiver in Switch mode) | Five battery levels from HID report `0x30` after Steam Input or another host enables full reports |
| **Apple AirPods / Beats** | AirPods Max (tested, `200A` Lightning and `201F` USB-C), AirPods Pro 3 (tested, `2027`), AirPods Pro 1 / 2, AirPods 1–5 and Beats headphones/earbuds | BLE "proximity pairing" (`0x07`) broadcasts (single battery for AirPods Max and Beats headphones; left, right and case for earbuds, in 10% steps with charging state), matched to the paired model |
| **Phones (Phone Link)** | Any Android phone linked with Microsoft Phone Link, over Wi-Fi or Bluetooth (tested: Nothing Phone (4a) Pro) | Battery and charging state from Phone Link's Windows 11 Start menu card (`StartMenuCompanion.json`); no Bluetooth needed |
| **Darmoshark** | M3 (`248A:FF30`) and M3S (`248A:FF31`) on their 2.4 GHz receivers on Windows | HID feature report for mouse identity and battery |
| **Darmoshark** | M3S Pro on the Nordic 1K receiver (`1915:0723`) | Vendor HID status query on the `FF0A` collection |
| **Alienware** | AW920H headset on its 2.4 GHz dongle (`413C:A515`, tested); over Bluetooth it is covered by the Bluetooth row | Vendor query `06 C0 0A` on `FF13:0001`, reply report `07` with an XOR checksum; level, charging and critical-level fields as decoded by Alienware Command Center's AW920H plugin |
| **Niceboy** | MW400 on its 2.4 GHz receiver (`248A:FA02`, tested) | Read-only report `05` query `24 FA 48`; battery voltage mapped to 10% steps with the vendor app's table, charging flag |
| **Bluetooth** | Anything that shows a battery in *Settings → Bluetooth & devices* (earbuds, headphones, BLE mice and keyboards). Google Fast Pair earbuds (Jabra Elite 8 Active tested; Pixel Buds and many Sony / JBL / Bose models) also get left, right and case levels | Windows device property; Fast Pair battery broadcasts (BLE service data `FE2C`), matched to the paired device by Bluetooth address |
| **Generic HID** | Devices reporting the standard HID *Battery Strength* usage | HID usage page 0x06 / 0x85 |
| **HeadsetControl** | [Every headset it supports](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, newer Logitech and more) | Bundled; runs `headsetcontrol -o json` |
| **MAONO PD200W** | 2.4 GHz receiver (352F:040E) | Battery percentage; hardware-tested |


**Tested on real hardware:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (PlayStation receiver `0951:1713`; charging untested), HyperX Cloud Core Wireless DTS (receiver `0951:173F`; full-charge level untested), HyperX Pulsefire Haste 2 Core Wireless (dongle `03F0:0AB5`; the Haste 2 Wireless dongles are untested), Cooler Master MM712 (dongle), Rapoo VT3 Max Gen 2 (receiver `24AE:1417` and USB cable `24AE:4617`; other Rapoo models are untested, see [Rapoo protocol notes](#sec-rapoo)), Redragon M916 Pro 1K (receiver `3554:F55D`), Taidu TSG808 (receiver `3554:F5D5`), Redragon M915RGB-WL (receiver `25A7:FA07`; other Areson models are untested, see [Areson protocol notes](#sec-areson)), SteelSeries Rival 650 Wireless (receiver `1038:1726` and USB cable `1038:172B`), SteelSeries Arctis Nova Pro Wireless (base station `1038:225D`; battery reading tested, charging and power transitions untested), HECATE G5M PRO (receiver `35BB:D3FB`), WLMouse YING Magnesium (8K receiver `36A7:A874`), ATK N9 Ultra (receiver `373B:1204`), Corsair Scimitar Elite SE Wireless (Slipstream receiver `1B1C:2B00`), Corsair Dark Core RGB Pro SE (Slipstream receiver `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (2.4 GHz receiver `1B1C:2B2A`; battery reading verified), DAREU EM901X (receiver `260D:1074`; charging and sleep/wake untested), Jabra Evolve3 75 on a Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (receiver `3837:4245` and USB cable `3837:418C`), MCHOSE K7 Ultra (receiver `3837:1001`), MCHOSE K7 V2 Ultra+ (receiver `3837:1014` and USB cable `3837:4028`; charging shown while plugged in), MSI VERSA 300 ELITE WIRELESS (dongle `0DB0:9E22`; charging and sleep handling untested), MSI Clutch GM31 Lightweight Wireless (receiver `0DB0:0D3C`; the GM41 uses the same driver from an owner's captures), AJAZZ AK820 MAX (dongle `05AC:024F`), AULA HERO 68 Air (8K Wireless Receiver `372E:106C`), AULA SC580 (USB cable `088D:062E` and receiver `089D:062F`, including charging and sleep), AirPods Pro 3 (Bluetooth, model `2027`), AirPods Max (Bluetooth, model `200A`), Sprime PM1 (receiver `1915:AC1C`), Ninjutso Ten Air (receiver `093A:EB01` and USB cable `093A:E020`), MOONDROP GM01 Pro (dongle `35D8:0133`), Delux M800 Pro (receiver `248A:5B2F`), Razer Barracuda X (2022) (receiver `1532:0550`; battery level read, charging transitions untested), Razer BlackShark V3 X (HyperSpeed dongle `1532:057D`), Fantech Helios Go XD5 (dongle `25A7:FA7C`), Fantech Raigor III (dongle `1EA7:0066`; charging not reported by the firmware), Finalmouse UltralightX (dongle `361D:0100`), Finalmouse Starlight X (on its dongle), and Chimera V2 (receiver `3554:F512`; battery level and charging read).
Also hardware-tested: Machenike L7 Arctic / L7 Mix (`248A:FF4C` receiver and `248A:FF4E` cable), including charging and cable/receiver duplicate suppression. Bluetooth and low-battery/full-charge boundaries were not hardware-tested.
Also hardware-tested: MCHOSE V9 Pro 2 (`3837:6011` dongle); battery level read, charging and sleep untested.
Also hardware-tested: EPOMAKER EA75 on its `05AC:024F` 2.4 GHz receiver, using the existing SONiX driver from [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). Battery percentage, receiver reconnection and power-on recovery were verified. Charging indication and wired battery reporting are not supported by this driver; Bluetooth battery reporting was not tested. The reported percentage can jump to 100% when USB power is attached, which is not a reliable charging indicator.
Also hardware-tested: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (receiver `1038:1878` and USB cable `1038:187A`), including charging, switching off (the last level stays, dimmed) and with SteelSeries GG running; GG only shows a three-step bar, which the level matched.
Also hardware-tested: RAWM Leviathan V4 (RAWM HS Receiver `1915:2346`; battery level read, charging untested).
**Implemented from protocol documentation and other projects, not yet tested:** everything else, including the Fantech Raigor II WG10 (same `1EA7:0066` dongle and collection as the tested Raigor III, so it should work). If you own one of these devices, please report whether it works by [opening an issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues).

## Install

[![Latest version](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Download **`BatteryHub-Setup-<version>.exe`** from the [latest release](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. Run it, choose any of the 19 supported setup languages, and click through. It needs **no administrator rights** and **nothing else installed**: no
   runtimes, no drivers, no vendor apps. HeadsetControl comes bundled, and the editable `lang\` folder is installed next to `BatteryHub.exe`.

The installer adds a Start menu entry and an uninstaller (*Settings → Apps*), and can start the app
when you sign in. Prefer no installer? Download `BatteryHub-<version>-portable.zip`, unzip it
anywhere (keep the `lang\` folder next to `BatteryHub.exe` for UI translations) and run `BatteryHub.exe`.

**Notes:**
- **SmartScreen warning:** the exe is not code-signed, so Windows may say "Windows protected your PC". Click *More info → Run anyway*, or build it yourself.
- **Tray-icon mode on Windows 11:** new tray icons go to the `^` overflow. Drag them onto the taskbar or enable them in *Settings → Personalization → Taskbar → Other system tray icons*.
- **Keeping the app away from a device:** if a device misbehaves while the app is running, list it in the registry string `IgnoreDevices` under `HKCU\Software\WirelessBattery` as `VID:PID` pairs (hex, separated by commas, e.g. `28BD:0947, 1234:ABCD`; `--dump` shows the ids). The app then never opens it. Drawing tablets are skipped automatically.

## Updates on Windows

Official stable Windows builds check the project's latest published stable release in the
background, 30 seconds after startup and then every 24 hours while the app is running. Open the
menu to see **Update available: vX.Y.Z...**, or choose **Check for updates...** yourself.
Update information appears only in this menu: battery icons, percentages and tooltips stay the
same, and automatic checks never show a notification or dialog. Turn off
**Automatically check for updates** in the menu to disable background checks.

For an installed copy, click the update entry and **Download and install**. Nothing is installed
without that click. The app downloads the release's `SHA256SUMS.txt` and its signature, checks the
signature against the maintainer's public key built into the app, downloads the Windows installer,
and runs it only if its SHA-256 is the one in the signed list (and the one GitHub lists for it). It
then updates the existing installation. Settings and startup preference are
preserved, and the app reopens after installation. An installation for all users can ask for
administrator permission. **Release notes** opens the official release page; **Later** keeps
your current version. Portable copies offer the release page for downloading the ZIP manually.

Checks contact GitHub's public API without an account or token. No device or battery information
is sent. Offline failures and GitHub rate limits leave battery monitoring running; a previously
found release stays in the menu until a successful check supersedes it or it is installed.
Cancelling a download waits for the current network operation to finish its finite timeout.
The installer never restarts Windows automatically.

**Why updates are safe to install:** the signing key never goes to GitHub. The maintainer signs
each release's checksum list on their own PC (see [docs/releasing.md](#sec-releasing)), so
even someone who took over the GitHub account or its build workflow could not publish an update
the app would install. A release without a valid signature is shown in the menu but can only be
downloaded by hand. The signature does not replace Windows' own SmartScreen or UAC prompts.

Install the first release containing this feature manually once. Development/test builds disable
official update checks so local changes cannot be replaced accidentally. Updates for Linux and
automatic replacement of portable copies are deferred.

## Command line

```
BatteryHub.exe --list     # print every device and its battery level, then exit
BatteryHub.exe --json     # print a JSON array of devices and battery levels, then exit
BatteryHub.exe --dump     # every HID collection, HID devices that could not be opened, all USB devices (also ones
                               # without a HID interface) and Bluetooth devices; also saved to %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # open the "Request support for a device" window
BatteryHub.exe --demo     # sample devices of every brand instead of real ones (screenshots, checking colors)
BatteryHub.exe --quit     # close the running instance
```

The Linux build uses the same flags with `wireless-battery` instead of `BatteryHub.exe`, and
also accepts `--help`. `--json` prints a stable array that scripts and bar widgets can parse:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` is how long the app keeps showing the last known level while the device is asleep.
Adding new fields is backwards compatible.

**Device not shown?** Right-click the widget or tray icon and choose **Request support for a device...**. Pick the device, check
what will be sent (it is shown word for word: the device name, its type, its USB/HID ids and interface layout, and your optional
name and notes) and click **Send**. It goes on the public list at [krisgfx.com/tools](https://krisgfx.com/tools/#requested) and
opens or updates a GitHub issue. **Copy full report** puts the complete `--dump` on the clipboard for the issue.
Report data is sent only when you click Send. Official Windows builds can also contact GitHub
to check for updates, as described in [Updates on Windows](#updates-on-windows); update checks
do not send device or battery information.

## Build

You need [MinGW-w64](https://www.mingw-w64.org/), e.g. from [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # development build, version 0.0.0
build.bat                                 # plain cmd with g++ and windres on PATH
make VERSION=1.2.3 CHANNEL=test            # versioned build, official updates disabled
build.bat 1.2.3 test                       # equivalent versioned cmd build
make test VERSION=1.2.3 CHANNEL=test       # device and updater regression tests
```

To build the installer and portable zip, install [Inno Setup](https://jrsoftware.org/isinfo.php),
first build with the intended version (for example `make VERSION=1.2.3 CHANNEL=test`), then run
`powershell -File installer\build-installer.ps1 -Version 1.2.3`. Packaging rejects a version that
differs from the executable. It downloads the pinned
HeadsetControl release and verifies its checksum. GitHub Actions does all of this automatically:
pushing a tag like `v1.0.0` publishes a release with the installer, the portable zip and the
HeadsetControl source (as its GPL license requires).

Windows builds also need PowerShell for generating the shared executable/resource version.
The official repository's version tags build with `CHANNEL=stable`; local builds default to
`dev`. Forks and pull requests do not enable official updates automatically.

`BatteryHub.exe` on its own also works. Without `headsetcontrol.exe` next to it (or on `PATH`) you
just lose the extra headsets.

## Linux (experimental)

A Linux build sits alongside the Windows app. It uses the same vendor drivers with a hidraw-based
HID backend and a GTK4 StatusNotifierItem tray icon; the Windows code path is unchanged.
All Linux-only files are in `linux/` and `src/linux/`, and `build-linux.sh` builds it (Windows keeps using `build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Compiler & make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

No extra HID library is needed (hidraw is used directly).

```sh
./build-linux.sh
./build-linux.sh test         # unit test for the HID report-descriptor parser
./wireless-battery --list     # print detected levels and exit
./wireless-battery --dump     # list HID collections
./wireless-battery --quit     # close the running tray instance
```

HID access needs a udev rule, otherwise the app starts but finds no devices:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# log out and back in
```

The tray icon works natively on KDE Plasma; GNOME needs an AppIndicator host such as
`gnome-shell-extension-appindicator`. Multi-language switching works via the *Language* submenu
(following `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` by default, and localizing `--help` too).
Running `make -f linux/Makefile.linux install` installs the binary, `lang/*.json` into
`$(PREFIX)/share/wireless-battery/lang/`, and the desktop launcher (`linux/wireless-battery.desktop`)
plus `linux/wireless-battery.svg` into `$(PREFIX)` (defaults to `~/.local`); user language
overrides live in `~/.config/wireless-battery/lang/`.

Phase 1 covers Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious,
Finalmouse and the shared Kysona/Pulsar/ATK/G-Wolves protocols. Bluetooth/UPower fallbacks, HeadsetControl and
the remaining vendors are planned follow-up phases.

## Limitations

- **Crowded taskbars:** with a very full centered Windows 11 taskbar, the app buttons can reach the widget. On Windows 10 the task-button area is narrowed automatically.
- **Phones:** read from a file Phone Link writes for the Start menu companion card, which is not a documented API and may change with Phone Link updates. The phone shows while Phone Link reports it as connected; a card older than 3 hours is shown dimmed. The card also says when the phone is charging, which shows as the charging bolt.
- **Sleeping devices:** a device that is asleep may not answer. Its last value stays visible, dimmed. Logitech receivers drop sleeping devices from the link, so their last value is kept for 30 minutes.
- **HECATE G2 Wireless 7.1 headset** (2.4 GHz dongle `35BB:A009` / `A209`): no battery query for its dongle is documented yet, so it is not read. A USB capture while the HECATE software shows the headset battery (see CONTRIBUTING.md) is the way to add it.
- **Keychron keyboards:** with stock firmware they only report their battery over Bluetooth (shown via the Bluetooth support). Over the 2.4 GHz receiver or the cable they need firmware with the battery patch ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); updating the keyboard from Keychron Launcher removes it. Keychron mice are supported.
- **Baseus AeQur GH02 headset:** the 2.4 GHz dongle (`10D6:4802`, Actions chip) only carries audio, media keys and the chip's firmware-update channel, not the battery. Connect the headset over Bluetooth to see its level (shown via the Bluetooth support when Windows reports one).
- **Weikav Lucky65 v1 keyboard:** the firmware does not report its battery over the 2.4 GHz dongle (`0603:0351`, Novatek chip). The keyboard has no battery-check shortcut, and the official configurator only connects over the USB cable, not through the dongle, so there is no battery reading to show.
- **Rapoo:** supported VT mice push their status, so a refresh can wait up to 4 seconds per matching interface. Sleeping mice may stay dimmed with their last reading for up to 30 minutes. Support is for Nordic 54L report `07` and legacy `BB` (VT3 Pro, VT1 Pro Max); CH584 report `08`, office MT/M-series mice and other firmware protocols are not covered by this driver.
- **GameSir Cyclone Pro:** the dongle carries no battery level, so it is read from the pad over Bluetooth LE. Pair the pad with Windows once (Settings > Bluetooth & devices > Add device > Bluetooth > `GameSir-Cyclone Pro`), and keep playing through the dongle. The PC needs Bluetooth. The level refreshes every 2 minutes, and there is no percentage while charging. Without pairing, the dongle shows as an Xbox controller at "Full". Details in [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM:** the mouse is asked through its receiver, so a sleeping mouse does not answer; it stays dimmed with its last reading for up to 30 minutes and adds about a second to a refresh while it sleeps. Only the Leviathan V4 on the RAWM HS Receiver (`1915:2346`) is tested; the other models are taken from RAWM HUB's device table. The Leviathan V4 GT and NYX60 (VID `373E`, RAWM HUB 3.0) and the RAWM HS keyboards use other protocols and are not covered.
- **Flydigi:** this driver targets Vader 5 Pro and Apex 5; Bluetooth and other Flydigi models (for example Apex 6) are not covered. Percentages represent coarse battery levels. Apex 5 was tested on real hardware over the 2.4 GHz receiver and a USB cable; Vader 5 Pro follows SDL and Windows hardware traces.
- **Not supported yet:** MSI wireless mice other than the VERSA 300 ELITE and the CLUTCH GM31 / GM41, MSI wireless keyboards, Razer Kraken headsets and the Barracuda models other than the Barracuda X (2022) on `1532:0550`, HyperX Pulsefire mice other than the Haste 2 Wireless / Haste 2 Core Wireless and the Xbox Wireless Headset on the Xbox adapter: their battery protocols are not documented. The Xbox Wireless Headset works over Bluetooth. A USB capture from an owner (see CONTRIBUTING.md) is the way to add them.
- **Other devices:** some 2.4 GHz devices use undocumented protocols and are not supported yet. See [CONTRIBUTING.md](#sec-contributing) for how to help add one.

## How it works

Each vendor driver in [`src/drivers/`](../../src/drivers) recognises its devices by USB vendor and product ID, and only ever sends read-only battery queries. Unknown devices are never written to. The generic fallbacks (HID battery usage, Bluetooth, XInput, HeadsetControl) only look at devices no vendor driver has claimed.

The taskbar widget is a layered child window of `Shell_TrayWnd`, placed left of `TrayNotifyWnd`. If Explorer restarts, it is re-created.

## Translations

Every UI language is a flat static UTF-8 JSON file in [`lang/`](../../lang): English source text on the left, the translation on the right. Language files are loaded from disk at runtime rather than compiled into the executable, so you can edit them directly without rebuilding.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **App UI (Windows & Linux):**
  - Edit or add `.json` files directly inside the `lang/` folder next to `BatteryHub.exe` (or `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/`, or `./lang/` on Linux).
  - Or choose *Language → Add your own language...* in the menu to prepare your user override folder (`%APPDATA%\WirelessBattery\lang` on Windows, `~/.config/wireless-battery/lang` on Linux) with `_template.json`. Copy `_template.json` to e.g. `it.json`, fill in `@code`, `@name` and the translations, and it appears in the menu (no restart needed). Files in the user folder override built-in phrases with the same `@code`.
  - Keep `{placeholders}` as they are, and set `"@rtl": true` for right-to-left scripts. Phrases left empty stay English, so a partial translation is fine.
  - The `--list` and `--dump` output stays English on purpose: it is pasted into GitHub issues.
- **Windows installer:** Inno Setup translations live in [`installer/lang/`](../../installer/lang) (saved as UTF-8 with BOM) and are registered under `[Languages]` in `installer/BatteryHub.iss`.
- **Documentation:** every visible project document is translated as a single standalone Markdown file per language in [`docs/i18n/`](README.md) (see [`docs/i18n/_template.md`](_template.md) to add a new language with no build scripts required).
- **Share it with everyone:** send a pull request adding your files in `lang/`, `installer/lang/`, `linux/wireless-battery.desktop`, and `docs/i18n/`. See [`docs/i18n/README.md`](README.md) for the step-by-step checklist.

## Credits

App icon by [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

The protocols come from these projects' research:

- [Google Fast Pair specification](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): left / right / case battery broadcasts of Fast Pair earbuds
- [HeadsetControl Astro drivers](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty), and [AstroBar](https://github.com/nichtlegacy/AstroBar): Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 battery protocols; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): A50 Gen 3 `0x72` status read

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): VAXEE battery and charging commands ([protocol documentation](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): SteelSeries, Corsair, HyperX, Logitech and Sony INZONE headsets
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) and [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) and the Logitech HID++ 2.0 documents: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) and [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (`0ADF` dongle)
- [rivalcfg](https://github.com/flozz/rivalcfg): SteelSeries mice (Rival Pro from its pull request #294)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) and [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Hitscan's web configurator ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- Linux `hid-kysona` (Lode Willems): Kysona, Pulsar and ATK
- ATK's web configurator ([hub.atk.pro](https://hub.atk.pro)): ATK mice and the N9 Pro / N9 Ultra headsets
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 and [mouse-battery](https://github.com/qwr79/mouse-battery): ATK / VXE NK NANO dongle
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X and Endgame Gear XM2we, ported from its providers (each driver names its source)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` and [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (findings only): the Turtle Beach Swarm II device family
- G-Wolves' web driver ([mouse.xyz](https://mouse.xyz)): G-Wolves models and their protocols
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): CHERRY keyboards on the 2.4 GHz dongle (frame format and battery query)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): Keychron mice
- [NinjaForce](https://www.ninjaforce.co/) and [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): Ninjutso Ten / Ten Air feature queries
- [nape_pro](https://github.com/nvalis/nape_pro) and [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro on the Link-KM receiver
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): LAMZU mice
- [vole](https://github.com/johanneszab/vole) and [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): Endgame Gear 4K mice
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) and [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) and [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (from Finalmouse's xpanel)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) and [g49-web-control](https://github.com/pingpingjinping/g49-web-control): Redragon ids
- [m913-ctl](https://github.com/Qehbr/m913-ctl) and [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): Areson `25A7` frame layout and `GetPower` command
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) and [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW and DW
- RK's web driver ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) and [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (docs): MCHOSE A5 Pro / A5 Pro Max (first generation, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): CompX receiver reports for Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) and [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) and [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- The Wraith web driver ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 and [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 and [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) and [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) on the `1532:0550` receiver; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): framing of the `1532:0552` receiver
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): Rongyuan and Xenta receivers (Attack Shark and others)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): SONiX keyboards on their 2.4G dongle (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) and [ak820-studio](https://github.com/usharik/ak820-studio): AJAZZ AK820 Pro receiver `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) and [Kraber](https://github.com/AkashPanja/Kraber): Semico `1A2C` (`AA 55 CC 33` / `0x0E`) status protocol for Attack Shark X98 and AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) and [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 and MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) and [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): GameSir Cyclone Pro Bluetooth LE "base info" battery request
- [jabridge](https://github.com/Watchdog0x/jabridge): Jabra GNP protocol (Link 380 / 390 dongles)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): `1EA7:0066` status-page protocol (Fantech Raigor III and other generic 2.4G Mouse devices)
- Linux `hid-playstation`: DualShock 4 / DualSense report layout
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): AULA SC580 / SC580X vendor protocol
- RAWM HUB web app ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) and its device table: RAWM mice and the SADES Dagger
- [SDL's Flydigi HID driver](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) and [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): Vader 5 Pro and Apex 5 query framing and battery layout
- [SDL's 8BitDo HID driver](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): 8BitDo Ultimate 2 battery byte
- BEITONG iControl (its KP20 and KP40D pages and the KP20 receiver's USB traffic): BEITONG KP20 / KP40D battery query and payload scrambling
- [SDL's 8BitDo HID driver](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) and [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): 8BitDo battery byte and vendor HID protocol
- JBL QuantumENGINE (its HIDV3 device-info messages): JBL Quantum headsets
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, Compx protocol on `FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) and [BrimDeck](https://github.com/MoFeng2223/BrimDeck): Scyrox V12M profile read
- JBL QuantumENGINE: HIDV1 connection and battery reports for the Quantum 350, and HIDV3 device-info messages for newer Quantum headsets
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): JBL Quantum 610 HIDV1 battery and link reports, and the Quantum lineup (360 as a HIDV1 dongle model)

## License

[GNU General Public License v3.0 or later](../../LICENSE). You may use, modify and redistribute this
software, but anything you distribute that is based on it must be released under the same license,
with its source code.


---

<a id="sec-contributing"></a>
> 📄 **Section:** Contributing (`CONTRIBUTING.md`) · [English original](../../CONTRIBUTING.md) · [↑ Top](#top)

# Contributing

## Reporting whether a device works

Most drivers were written from protocol documentation and could not be tested on every model.
Please open an issue with:

- the device name, and whether it is connected by receiver, cable or Bluetooth
- the output of `BatteryHub.exe --list`
- the output of `BatteryHub.exe --dump`
- what the vendor's own software shows as the battery level

## Adding a device

1. Run `BatteryHub.exe --dump` and find your device's vendor and product IDs, and the
   vendor-defined collections (usage page `FFxx`) with their report sizes.
2. Find the battery protocol. Good places to look: HeadsetControl, OpenRazer, Solaar, rivalcfg,
   OpenRGB, OpenLinkHub, or a USB capture of the vendor software (Wireshark + USBPcap).
3. If the vendor already has a driver in `src/drivers/`, add the product ID (and any differences) there.
   Otherwise create `src/drivers/<vendor>.cpp`:

   ```cpp
   #include "drivers.h"

   void PollAcme(PollContext& ctx) {
       for (auto [vid, pid] : ctx.Products(0x1234)) {           // unclaimed products of this vendor
           for (const HidColl* c : ctx.Find(vid, pid, [](const HidColl& c) { return c.page() == 0xFF00; })) {
               HidDev d;
               if (!d.Open(*c)) continue;
               std::vector<BYTE> r;
               if (!d.Write({ 0x01, 0x02 }) || d.Read(r, 500) < 3) continue;   // hidapi-style buffers
               DeviceStatus s;
               s.key = L"acme:" + Hex4(pid);
               s.name = HidProduct(*c);
               s.kind = DeviceKind::Mouse;
               s.via = L"2.4 GHz receiver";
               s.percent = Clamp100(r[2]);
               ctx.Add(s, vid, pid);
               break;
           }
       }
   }
   ```

4. Declare the function in `src/drivers/drivers.h`, call it from `PollAllDevices()` in
   `src/devices.cpp` (before the generic fallbacks). `build.bat` and the Makefile pick up new files automatically.
5. Update the device table in `README.md`.

### Rules for drivers

- **Read-only:** only send requests that read state. Never change settings, lighting or modes.
- **Exact matching:** only talk to devices you recognise by vendor and product ID, or by a
  vendor-specific collection that is unique to the protocol.
- **Always time out:** a missing device must not stall the poll for more than about a second.
  Passive protocols may need longer to cover a documented push interval (for example, Delux and
  Rapoo). Keep a single absolute deadline of at most 4 seconds per matching collection, do not
  restart it for unrelated reports, and document why the exception is needed.
- **Credit sources:** cite where the protocol comes from in a comment at the top of the file.

## Translations

UI languages are flat static UTF-8 JSON files in `lang/` loaded from disk at runtime on both Windows and Linux (copy `lang/_template.json` to `lang/<code>.json`, fill in `"@code"`, `"@name"` and the `"Original": "Translation"` entries — no rebuild required). New UI text in the code goes through `T(L"...")`, or `TF(L"... {name} ...", { { L"name", value } })` when it contains values; never build translated sentences from pieces. After adding phrases, add them to `lang/_template.json` too.

Windows installer translations live in `installer/lang/*.isl` (saved as UTF-8 with BOM and registered in `installer/BatteryHub.iss`), Linux launcher comments live in `linux/wireless-battery.desktop`, and full documentation translations live in `docs/i18n/<code>.md` (single standalone file copied from `docs/i18n/_template.md`). See [`docs/i18n/README.md`](README.md) for the complete contributor guide.

## Code style

C++17, Win32 only, no third-party dependencies. Keep the binary small. Format roughly as the
existing code does (4-space indent, 120-column lines).

## Windows updater development

The updater is Windows-only and uses WinHTTP, BCrypt and the existing Inno Setup installer.
Keep update status exclusively in the menu. Do not add update icons, badges, battery tooltip
changes, balloons, toasts or automatic dialogs. Device polling runs separately from network work.

Build version and channel are shared by C++ and the Windows resource through generated
`build/version.h`. Use `make VERSION=1.2.3 CHANNEL=test` or `build.bat 1.2.3 test` for local
testing; `dev` is the default and `stable` enables official release checks. Version components
must fit 0..65535. Only the official repository's release-tag workflow selects stable
automatically. Do not turn a fork build into an official update channel accidentally.

Run `make test VERSION=1.2.3 CHANNEL=test` for existing device tests plus strict release parsing,
version ordering, check scheduling, real SHA-256 file checks, argument quoting and helper guards.
Updater regressions also cover cancellation at download completion, dialog guards and failure
to configure HTTP timeouts/redirect restrictions. The Windows test includes the implementations,
following the existing Linux backend test pattern, and substitutes HTTP sending so these tests
cannot contact GitHub. No test-only controller entry points are added to production.
Individual targets are `make test-update-core` and `make test-update-win`. Native updater tests
link the application resource to activate Common Controls v6. Tests use local data and do not
download, elevate, install or change the user's startup settings. The application's production
endpoint cannot be overridden for tests.

Before packaging, run
`powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`.
`installer/build-installer.ps1 -Version 1.2.3` also runs this check before downloading dependencies.
The `/WBUPDATE=1` installer path preserves existing startup/settings and leaves relaunch to the
temporary helper. That helper remains under the original user, elevating only a global setup.
WinHTTP handles belong to the worker; cancellation is cooperative between finite-timeout calls.
Final app shutdown joins that worker and can therefore wait for an in-flight network timeout.

For a release review, use a disposable Windows account or VM to exercise two real installer
versions, per-user/global scope, UAC cancellation, startup on/off, custom paths, setup failure
and relaunch. Unit tests and compiling a package do not verify those installer effects. Visual
menu/theme review and real installer/UAC end-to-end checks remain manual release gates; do not
mark them passed unless actually observed. Never test by overwriting the daily user's install.

## Automatic safety check

Every pull request is scanned by the "PR safety check" for things this app should never do (network
access, launching programs, reading keyboard/clipboard/screen, startup entries, binaries, build or
release changes). A flag is not a rejection: just explain the flagged lines in the PR description.

Using AI tools is fine, but please remove `Co-authored-by` lines that credit them (for example
`Co-authored-by: Claude ...`) from your commit messages. The check fails while they are present.


---

<a id="sec-pr-template"></a>
> 📄 **Section:** Pull Request Template (`.github/pull_request_template.md`) · [English original](../../.github/pull_request_template.md) · [↑ Top](#top)

## What this adds

<!-- Device(s) and vendor/product IDs, e.g. "Acme M1 (1234:5678)". -->

## Where the protocol comes from

<!-- Link the source (another project, a vendor web driver, your own USB capture). -->

## Tested on real hardware?

<!-- Yes (which device, what --list printed) / No -->

## Checklist

- [ ] Only read-only battery queries are sent; no settings, lighting or firmware are changed
- [ ] Only devices recognised by vendor/product ID (or a protocol-specific collection) are touched
- [ ] No network access, no launching other programs, no new files outside `src/`, `docs/` or `README.md`
- [ ] No binaries or generated files are included
- [ ] No `Co-authored-by` lines crediting AI tools (Claude, Copilot, ChatGPT ...) in the commit messages
- [ ] Changes to `.github/`, `installer/`, `build.bat` or `Makefile` are explained above


---

<a id="sec-releasing"></a>
> 📄 **Section:** Releasing (`docs/releasing.md`) · [English original](../../docs/releasing.md) · [↑ Top](#top)

# Releasing

The app updates itself from GitHub releases, but it only installs a setup whose SHA-256 is listed in
a `SHA256SUMS.txt` signed with the release key. That key lives on the maintainer's PC, never on
GitHub: a hacked account, token or workflow can publish files, but not a signature the app accepts.

## Once: create the release key

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Asks for a password (12+ characters) and writes the encrypted private key to
  `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- Puts the public key into `src\update_public_key.h`. Commit that file. Official builds refuse
  to compile without a key in it.
- **Back up the key file and keep the password** (a password manager is a good place for both).
  If either is lost, the installed apps can no longer update themselves: you would create a new
  key and every user would have to install one release by hand.

## Every release

1. Push a version tag (`git tag v1.2.3 && git push origin v1.2.3`). CI builds the setup, the
   portable zip and `SHA256SUMS.txt`, and publishes the release.
2. Sign the checksum list:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   It downloads `SHA256SUMS.txt` from the release, shows it, asks you to confirm, asks for the key
   password and writes `SHA256SUMS.txt.sig`. If you have the same files in `dist\` (a local build of
   that version), it shows whether they match.
3. Upload `SHA256SUMS.txt.sig` to the release (the script opens the edit page). From then on the app
   offers **Download and install**. Before that it shows the update but only links to the release page.

Only sign a list for a release you published yourself. The signature says "these exact files are the
release", so signing is the step where a malicious upload would be caught.

## Changing the key

Run `new-release-key.ps1` with a new `-KeyFile`: it adds the new public key next to the old one in
`src\update_public_key.h`. Release a version signed with the old key that contains both, then sign
with the new key from the next release on and remove the old key later. A lost or leaked key
cannot be retired this way: remove it from the header, and users of older versions have to install
the next release by hand.

## What the app checks before running a setup

- The release is the repository's latest, not a draft or prerelease, and newer than the app.
- `SHA256SUMS.txt.sig` is a valid ECDSA P-256 signature of `SHA256SUMS.txt` by a key in
  `src\update_public_key.h` (Windows BCrypt, no third-party code).
- The signed list names `BatteryHub-Setup-<version>.exe` exactly once, with the same SHA-256
  that GitHub reports for the file.
- The downloaded setup has exactly that size and SHA-256. A copy of the app then checks it again
  right before starting it, and keeps the file locked so it cannot be swapped in between.
- Downloads only use HTTPS to `github.com`, `objects.githubusercontent.com` and
  `release-assets.githubusercontent.com`, with each redirect checked.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Section:** Keychron Keyboard Firmware (`docs/keychron_keyboard_firmware/README.md`) · [English original](../../docs/keychron_keyboard_firmware/README.md) · [↑ Top](#top)

# Keychron keyboard battery over the 2.4 GHz receiver

Keychron's stock firmware only reports the keyboard's battery over Bluetooth. With the small QMK change in
[`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch), the keyboard also answers a battery query (`A4`) through the
Keychron Link receiver and over the USB cable, and BatteryHub shows its level, voltage and charging state.

Tested on the **Keychron K5 Max ANSI RGB** (`3434:0A50`) with the Keychron Link receiver (`3434:D030`).

## What the patch changes

Based on [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) branch `2025q3` (commit `57e682c`):

- adds the `KC_GET_BATTERY` (`0xA4`) raw HID command from [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1):
  reply `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`;
- passes raw HID requests that arrive over the wireless link to the same handler;
- in `keyboards/keychron/k5_max/config.h`: `#define WILRESS_RAW_ENABLE` (spelled this way in Keychron's code) and
  `#define KC_BATTERY_MODEL_ID 0`.

Nothing else changes: keymaps, lighting and Keychron Launcher keep working.

## Option 1: flash the ready-made K5 Max firmware

A build for the **K5 Max ANSI RGB only** is attached to
[this release](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)
(`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`).
Do not flash it on another model or layout.

## Option 2: build it yourself

Needs Git and Docker (or a working [QMK setup](https://docs.qmk.fm/newbs_getting_started)).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

The result is `keychron_k5_max_ansi_rgb_keychron.bin` in the repository root. On Windows, a bind-mounted
checkout is very slow in Docker; cloning inside the container (or WSL) is much faster.

**Other Keychron wireless keyboards** (Q/V/K Max and other models on the `2025q3` tree with `LK_WIRELESS_ENABLE`):
the changes under `keyboards/keychron/common/` apply as they are. Add the two `#define` lines to your keyboard's
`config.h` instead of the K5 Max one, and build your own target, e.g. `make keychron/<model>/<layout>/<variant>:keychron`.
The app currently names a K5 Max (`0A50`–`0A58`) by model and any other one "Keychron keyboard".

## Flashing

1. Set the mode switch to **Cable** and unplug the USB cable.
2. Hold **Esc** while plugging the cable in. The keyboard enters the STM32 bootloader.
3. Flash the `.bin` with [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (or `dfu-util`).
4. Switch back to **2.4 GHz** and check with `BatteryHub.exe --list`:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Updating the keyboard from Keychron Launcher replaces this firmware and removes battery reporting. To undo it,
flash Keychron's official firmware the same way.

## License

QMK is GPL-2.0-or-later; the patch is under the same license. Anyone who receives a binary built from it must
also be able to get this source change.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Section:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [English original](../../docs/gamesir_cyclone_pro.md) · [↑ Top](#top)

# GameSir Cyclone Pro battery support

## Why the controller showed as a full Xbox controller

The Cyclone Pro (model T4cp) plays through a 2.4 GHz dongle, `3537:1015`. The dongle presents itself
to Windows as a wired Xbox 360 controller (XUSB, `Xbox 360 Controller for Windows`). XInput answers
its battery query with "Full", so the XInput fallback listed it as `Xbox controller 1` at 100%
whatever the real charge was.

The dongle carries no battery information:
- its only HID collection is the XInput game controller (`HID\VID_3537&PID_1015&IG_00`)
- it has no vendor-defined collection like the Nova (`FF7A`) or the Cyclone 2 (`FFF0`)

## Where the level is

While it plays through the dongle, the pad also advertises over Bluetooth LE as
`GameSir-Cyclone Pro`, which is the link GameSir's phone app uses. Its "get base info" request
returns the battery:

| Step | Detail |
|---|---|
| Service | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Characteristic | `0x865F` (notify, write without response) |
| Request | enable notifications, write `01 01` |
| Reply | 19-byte notification (some firmwares prefix it with `C9`, 20 bytes) |

Reply layout:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

Byte 18 is the battery in percent (0-100), or `FF` while charging. No level is reported while it
charges, so the last known percentage is kept and shown with the charging bolt.

The pad also has service `0xFF10`, which is GameSir's firmware-update channel. The driver never opens
it. The pad has no standard Battery Service (`0x180F`), which is why Windows' Bluetooth page and
the Bluetooth fallback show no level for it.

Source: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), where the protocol was
worked out from GameSir's Android app (`BluetoothLeService`, "get base info").

## How the driver works

`src/drivers/gamesir_ble.cpp`, called before the XInput fallback:

1. **Find the pad.** It looks up device interfaces of class `{00008650-0000-1000-8000-00805F9B34FB}`.
   Windows creates one for each GATT service of a paired BLE device. It only uses those whose parent
   `BTHLE\DEV_…` node is named `GameSir-Cyclone…`.
2. **Read the battery.** It opens that service with the Win32 GATT API (`bluetoothleapis.h`,
   `-lbluetoothapis`), subscribes to `0x865F` and writes `01 01`. It waits up to 3 seconds for the
   reply, then switches notifications back off.
3. **Keep the poll fast.** The BLE connection can take seconds, or time out while the pad is
   asleep, so the query runs on its own thread:
   - at most every 2 minutes after a good read, or every minute after a failed one
   - the poll reports the cached reading, and stops reporting it once it is 6 minutes old
   - `graceSec` then keeps it visible, dimmed, as asleep
   - only the first poll of a run waits for the thread, once, with an absolute 4-second deadline,
     so the level shows on start and in `--list`
4. **Hide the fake Xbox entry.** When the dongle is present, the driver claims `3537:1015`:
   - the Windows.Gaming.Input path now skips claimed vendor/product ids
   - the XInput path gets each slot's vendor/product id from `XInputGetCapabilitiesEx` (xinput1_4
     ordinal 108) and skips claimed ones
   - when that export is missing, XInput behaves as before

## Tested hardware

Windows 11, Cyclone Pro on its dongle (`3537:1015`), paired once over Bluetooth, on 2026-11-18:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

While the pad was asleep, the "Xbox controller 1 / Full" entry no longer appeared and nothing was
shown for the pad.

## Limitations

- **Pairing:** the pad must be paired with Windows once (Settings > Bluetooth & devices > Add device >
  Bluetooth > `GameSir-Cyclone Pro`). Unpaired pads have no GATT device interface. Pairing adds
  Bluetooth gamepad entries, but these send no input while the pad plays through the dongle.
- **Bluetooth required:** the PC needs Bluetooth LE.
- **One pad:** only one Cyclone Pro per PC is read.
- **Charging:** there is no percentage while charging.


---

<a id="sec-localization-guide"></a>
> 📄 **Section:** Multi-Language Usage & Localization Guide (`docs/i18n/README.md`) · [English original](../../docs/i18n/README.md) · [↑ Top](#top)

# BatteryHub Multi-Language Index & Localization Guide

Every visible document in this repository is collected into **one standalone Markdown file per language** inside `docs/i18n/`, while all runtime application strings live in **static editable JSON files** inside [`lang/`](../../lang) (shared by Windows and Linux) and Windows installer strings live in [`installer/lang/`](../../installer/lang).

## Supported Languages (19)

| Code | Language | Complete Documentation | App UI (Windows & Linux) | Windows Installer |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (source strings) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
| `ar` | العربية | [ar.md](ar.md) | [`lang/ar.json`](../../lang/ar.json) | [`installer/lang/ar.isl`](../../installer/lang/ar.isl) |
| `de` | Deutsch | [de.md](de.md) | [`lang/de.json`](../../lang/de.json) | [`installer/lang/de.isl`](../../installer/lang/de.isl) |
| `es` | Español | [es.md](es.md) | [`lang/es.json`](../../lang/es.json) | [`installer/lang/es.isl`](../../installer/lang/es.isl) |
| `fa` | فارسی | [fa.md](fa.md) | [`lang/fa.json`](../../lang/fa.json) | [`installer/lang/fa.isl`](../../installer/lang/fa.isl) |
| `fr` | Français | [fr.md](fr.md) | [`lang/fr.json`](../../lang/fr.json) | [`installer/lang/fr.isl`](../../installer/lang/fr.isl) |
| `he` | עברית | [he.md](he.md) | [`lang/he.json`](../../lang/he.json) | [`installer/lang/he.isl`](../../installer/lang/he.isl) |
| `hu` | Magyar | [hu.md](hu.md) | [`lang/hu.json`](../../lang/hu.json) | [`installer/lang/hu.isl`](../../installer/lang/hu.isl) |
| `ja` | 日本語 | [ja.md](ja.md) | [`lang/ja.json`](../../lang/ja.json) | [`installer/lang/ja.isl`](../../installer/lang/ja.isl) |
| `ko` | 한국어 | [ko.md](ko.md) | [`lang/ko.json`](../../lang/ko.json) | [`installer/lang/ko.isl`](../../installer/lang/ko.isl) |
| `pl` | Polski | [pl.md](pl.md) | [`lang/pl.json`](../../lang/pl.json) | [`installer/lang/pl.isl`](../../installer/lang/pl.isl) |
| `pt-BR` | Português (Brasil) | [pt-BR.md](pt-BR.md) | [`lang/pt-BR.json`](../../lang/pt-BR.json) | [`installer/lang/pt-BR.isl`](../../installer/lang/pt-BR.isl) |
| `ru` | Русский | [ru.md](ru.md) | [`lang/ru.json`](../../lang/ru.json) | [`installer/lang/ru.isl`](../../installer/lang/ru.isl) |
| `sv` | Svenska | [sv.md](sv.md) | [`lang/sv.json`](../../lang/sv.json) | [`installer/lang/sv.isl`](../../installer/lang/sv.isl) |
| `tr` | Türkçe | [tr.md](tr.md) | [`lang/tr.json`](../../lang/tr.json) | [`installer/lang/tr.isl`](../../installer/lang/tr.isl) |
| `uk` | Українська | [uk.md](uk.md) | [`lang/uk.json`](../../lang/uk.json) | [`installer/lang/uk.isl`](../../installer/lang/uk.isl) |
| `vi` | Tiếng Việt | [vi.md](vi.md) | [`lang/vi.json`](../../lang/vi.json) | [`installer/lang/vi.isl`](../../installer/lang/vi.isl) |
| `zh-CN` | 简体中文 | [zh-CN.md](zh-CN.md) | [`lang/zh-CN.json`](../../lang/zh-CN.json) | [`installer/lang/zh-CN.isl`](../../installer/lang/zh-CN.isl) |
| `zh-TW` | 繁體中文 | [zh-TW.md](zh-TW.md) | [`lang/zh-TW.json`](../../lang/zh-TW.json) | [`installer/lang/zh-TW.isl`](../../installer/lang/zh-TW.isl) |

---

## How Language Switching Works in Practice

### 1. Windows App (`BatteryHub.exe`)
- **Automatic detection:** When set to *Language → Automatic (Windows language)*, BatteryHub queries Windows `GetUserPreferredUILanguages` and matches the closest static `*.json` file.
- **Manual switching:** Click the taskbar widget or tray icon → **Language** → pick a language. The UI updates immediately and persists in `HKCU\Software\WirelessBattery\Language`.
- **Static external files (editable without rebuilding):** `BatteryHub.exe` loads `<exe>\lang\*.json` first, then `%APPDATA%\WirelessBattery\lang\*.json`. Any file in the user folder with the same `@code` overrides matching phrases, and reopening the menu reloads files from disk live.
- **CLI `--help`:** `BatteryHub.exe --help` shows the help dialog in your active UI language (`--list`, `--json`, and `--dump` intentionally stay English for GitHub issue reports).

### 2. Linux App (`wireless-battery`)
- **Automatic detection:** Follows POSIX locale variables in order: `LANGUAGE` (colon-separated list) → `LC_ALL` → `LC_MESSAGES` → `LANG` (unless overridden by `LC_ALL=C` / `POSIX`).
- **Manual switching:** Right-click the tray icon → **Language** → pick **Automatic (system language)** or any installed language. Saved under `[general] language=` in `$XDG_CONFIG_HOME/wireless-battery/config.ini` (default `~/.config/wireless-battery/config.ini`).
- **Static search paths (lowest to highest priority):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (default `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (default `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help` prints translated CLI help based on `config.ini` or system locale; `--list` and `--dump` stay English.

### 3. Windows Installer (`BatteryHub-Setup-<version>.exe`)
- Prompts with a language selector (`ShowLanguageDialog=yes`) pre-selected from your Windows UI language (`LanguageDetectionMethod=uilanguage`).
- Installs the full static `lang\*.json` directory into `{app}\lang\` alongside `BatteryHub.exe` (and the portable ZIP likewise ships `lang\*.json`).

---

## How to Add or Update a Language (Step-by-Step)

You do **not** need any build tools to translate the app UI or the documentation, and only Inno Setup 6 if you want to test-compile the Windows installer.

### Step 1 — App UI Strings (`lang/<code>.json`)
1. Open the user language folder from the tray menu (**Language → Add your own language...**) or copy [`lang/_template.json`](../../lang/_template.json) to `lang/<code>.json` (e.g. `lang/it.json`).
2. Fill in the metadata keys and `"Original English": "Translation"` pairs:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
   - Set `"@rtl": true` only for right-to-left scripts (Arabic, Hebrew, Persian, etc.).
   - Keep placeholders like `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}` verbatim.
   - Use `\n` inside JSON strings for explicit line breaks.
   - Save as valid **UTF-8 (no BOM)** JSON.
   - Re-open the BatteryHub tray menu to preview immediately — no rebuild required!

### Step 2 — Windows Installer (`installer/lang/<code>.isl`)
1. Copy [`installer/lang/_template.isl`](../../installer/lang/_template.isl) to `installer/lang/<code>.isl`.
2. **CRITICAL:** Save the file as **UTF-8 with BOM (`EF BB BF`)** so Inno Setup decodes Unicode characters reliably regardless of legacy Windows code pages.
3. Choose the matching pattern:
   - **Inno Setup already ships your language** (check `C:\Program Files (x86)\Inno Setup 6\Languages\`): keep only `[CustomMessages]` and translate the 6 lines (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, preserving `%1` and `%n`). Register in `installer/BatteryHub.iss` under `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup does not ship your language**: copy `installer/lang/zh-CN.isl` as a full reference, set `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, optional `RightToLeft=yes`), translate `[Messages]` and `[CustomMessages]`, and register after `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Note: `[Languages]` `Name:` identifiers must contain only ASCII letters, digits, and underscores (use `ptBR`, not `pt-BR`).

### Step 3 — Linux Desktop Launcher (`linux/wireless-battery.desktop`)
Add a localized `Comment[<code>]=...` line (use underscores for regional tags in `.desktop` files, e.g. `Comment[zh_CN]=...`).

### Step 4 — Complete Single-File Documentation (`docs/i18n/<code>.md`)
1. Copy [`docs/i18n/_template.md`](_template.md) to `docs/i18n/<code>.md` (zero generator scripts needed — only this one file!).
2. Translate the Table of Contents and all 17 sections in full while keeping:
   - All `<a id="sec-..."></a>` anchor tags and `<a id="top"></a>` intact
   - All code blocks, CLI flags (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), USB `VID:PID`s, HID usage pages, hex packets, registry keys, file paths, and URLs verbatim
   - Relative image/file paths intact (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE`, etc.)
3. Update the top `<!-- lang-switcher:start -->` bar in `docs/i18n/<code>.md` (bold your own language, link all others), add your language link to the switcher bars in `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md`, and sibling `docs/i18n/*.md` files.
4. For right-to-left languages (`ar`, `fa`, `he`), write standard Markdown without wrapping the whole file in `<div dir="rtl">` so tables and code blocks render cleanly.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Section:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [English original](../../docs/ardor_fury_v2.md) · [↑ Top](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

The 2.4 GHz receiver exposes HID usage page `000A`, usage `0000`, and a
5-byte input report. It broadcasts data; no HID commands are sent.

Observed reports from real hardware:

| Report | Battery |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

The high nibble of byte 3 encodes the tier (`1`, `3`, `7`, `F` for
25, 50, 75 and 100 percent). Reports for 25% and 100% are inferred
from the vendor application's decoding logic; the end user subsequently
confirmed that the remaining levels display correctly in the built app.
The fifth byte is not constant and is not used as a signature.

The listener needs two agreeing decoded battery tiers, rather than two
identical whole reports. The last confirmed value is kept for up to
45 seconds. The global auto-refresh interval changes to 15 seconds.

Validated by end user on Windows with ARDOR Fury V2 and Logitech G733:
50% and 75% captures, periodic automatic update, 25%/100% visual checks,
and portable startup. The reports for 25% and 100% were not captured.


---

<a id="sec-areson"></a>
> 📄 **Section:** Areson `25A7` (`docs/areson.md`) · [English original](../../docs/areson.md) · [↑ Top](#top)

# Areson 25A7 receiver battery support

## Why the original program missed the mouse

The Redragon M915RGB-WL connects through an Areson/CompX `25A7:FA07` "2.4G Wireless Receiver".
Its battery is not exposed as a standard HID *Battery Strength* usage and Windows has no
Bluetooth battery property for it, because the link is a proprietary 2.4 GHz one. The mouse
answers an active `GetPower` request instead, so neither the generic HID fallback nor the
Bluetooth fallback could see it. There was no driver for the vendor, so the receiver stayed
unclaimed and silent.

## Observed hardware and packets

Tested on Windows 11 with a Redragon M915RGB-WL on 2026-11-17:

| Direction | VID:PID | Interface | Usage page:usage | Report size |
|---|---|---|---|---|
| request (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 bytes |
| reply (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 bytes |

The reply arrives on a different top-level collection from the one the request is written to.
On Windows these are `MI_01&COL07` (feature) and `MI_01&COL05` (input), which is why the driver
opens both handles.

Captured request (`GetPower`, report id `08`, command `04`, checksum makes the frame sum to `0x55`):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Captured reply:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Offsets below count the report id as byte zero:

| Byte(s) | Meaning | Example |
|---|---|---|
| 0 | Reply report id | `09` |
| 1 | Command echo | `04` |
| 2 | Status, 0 = OK | `00` |
| 3–4 | Address, unused for `GetPower` | `00 00` |
| 5 | Data length (2) | `02` |
| 6 | Battery level, 0–10, in 10% steps | `08` = 80% |
| 7 | Charging flag, any non-zero value | `00` = not charging |
| 16 | Checksum; all 17 bytes sum to `0x55` (mod 256) | `3E` |

The vendor's own software showed 80% for the same frame, which is what establishes the ×10
scale. `GetConnectStatus` (`08 03 …`) answers with a 1-byte payload and reported the mouse as
linked at the same time.

## Other Areson mice

The older `FA7B` / `FA7C` receivers used by the Redragon M693 report the charge directly as a
whole percentage at the same reply offset. Applying this driver's ×10 scale there would show
800%, so those product ids are deliberately not claimed. Only `FA07` and `FA08` are handled;
`FA08` is the alternate identity of the same family and has not been verified on this machine.

## Polling and identity

- The driver only sends the read-only `GetPower` request. It never writes configuration,
  lighting or DPI data.
- Each refresh opens the feature collection with zero access and the input collection for
  reading, sends the request and waits up to 1.8 s for a reply, with two attempts and a queue
  flush between them so a stale report cannot be mistaken for the answer.
- A failed read claims nothing, so a sleeping mouse keeps the last value in the UI. The entry
  uses a 30-minute grace period, matching the other passive drivers.
- The device key is derived from vendor and product id (`areson:25A7:FA07`), so it survives the
  receive/sleep cycle and a receiver replug.

## Validation

The full application was built with MSVC C++17 and the Windows SDK and run against the actual
mouse. `BatteryHub.exe --list` returned:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

The reading matched the percentage displayed by the official Redragon software at the same
moment. The MinGW `build.bat` includes the new source file; the `Makefile` discovers it through
its wildcard.

## Protocol sources

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): 17-byte frames, feature/input split and the
  `0x55` checksum rule, recovered from USB captures of the Redragon software.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray):
  `GetPower` command and the 10% level scale on `25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md):
  reply layout and the different percentage scale on the `FA7B` / `FA7C` family.


---

<a id="sec-darkrim"></a>
> 📄 **Section:** DARKRIM SHADOW (`docs/darkrim.md`) · [English original](../../docs/darkrim.md) · [↑ Top](#top)

# DARKRIM SHADOW / 寸渊影弑 receiver

Hardware-tested on `3654:6901`, manufacturer `Jieli Technology`, release `0100`.
Use interface **3**, usage `FF02:0002`, unnumbered 64-byte input/output payloads
(65-byte Windows HID report sizes). Interface 4 also has `FF02:0002`, but uses
report ID 2 and did not answer this protocol; it is deliberately excluded.

Protocol source: the official [PC Hub download](https://app.darkrim.net/hub/zh.html),
`DARKRIM-0.1.26-x64-setup.rar`, downloaded and statically unpacked without
installing or launching the vendor software. The extracted `DARKRIM.exe` SHA-256:
`f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Useful addresses in that binary:

- `140124C80`: `sendGetBasicInfo(infoType)` sends command `0010`, Request `01`,
  payload `[infoType, 00]`. Battery selector is `01`.
- `140118D30`, `140119200`: frame header and CRC generation.
- `140126DB0`: device-info TLV parser; TLV `01` is battery.
- `1400F5660`, `1400FA700`: battery consumers; low seven bits give percentage,
  high bit is charging. The same battery value also arrives in `0011` Notify `03`.

Header: `FE seq cmdLE type index count lengthLE`, followed by payload and
CRC-16/CCITT-FALSE (polynomial `1021`, initial `FFFF`, stored big-endian).
The sequence is a nonzero four-bit counter; encryption is unused.

Actual request/reply payloads, before HID zero padding:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

The response TLV `01 01 28` gives **40%, not charging**. The production C++ driver
returned that value on three consecutive queries without vendor software.
The receiver emits startup notifications before the matching response, measured
at about 406 ms. Use one 800 ms response deadline (plus at most 200 ms for writing),
without restarting it for unrelated notifications. No heartbeat is required.

The driver sends only the battery GET. It accepts only an unencrypted response
with the matching sequence/command/type, index zero, count zero or one (the
hardware uses zero), valid length/CRC, and a single well-formed battery TLV.
Fragmented, unsolicited, malformed and out-of-range replies are ignored.

## Observed battery precision and charging state

Treat the percentage as a **coarse estimate, not a verified 1%-resolution gauge**.
The owner's unit displayed charging progress in 10-percentage-point steps from
40% to 90%. At 90%, five battery GET responses and one unsolicited notification
all carried `DA`: `DA & 7F = 90`, with bit 7 indicating charging. After the owner
unplugged the charging cable and continued using the 2.4 GHz receiver, another
five GET responses and one notification all carried `5A`: still 90%, now with
the charging bit cleared. All twelve frames passed CRC verification.

Representative query responses (sequence 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

The driver and official application both take the percentage directly from the
low seven bits. The driver does not round to tens, multiply a tier by ten, or
interpolate intermediate values; synthetic 47% and 95% reports remain 47% and
95% in the production parser. The observed coarse readings therefore originate
upstream of the parser, in the headset/receiver's reporting. Finer hardware
readings have not been observed. A full discharge curve has not been recorded,
so a fixed 10% step at every discharge level or on other firmware is unconfirmed.

Charging and subsequent non-charging states at 90% have been hardware-checked.
Low/full boundaries, headset power-off behavior, Bluetooth
and USB cable data mode have not been hardware-tested. No claim of support is made
for those modes. No firmware updates, configuration changes, EQ commands,
pairing changes, resets or vendor binaries are included in this implementation.

Test: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Section:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [English original](../../docs/hyperx_haste_2.md) · [↑ Top](#top)

# HyperX Pulsefire Haste 2 Wireless battery protocol

Read by `HasteWireless` in `src/drivers/hyperx.cpp`. The queries come from
[ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) and are the same NGENUITY uses.

Verified on hardware:

- Pulsefire Haste 2 Core Wireless, dongle `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, dongle `03F0:0F98`, by uzumakiprime (PR #312). The level matched HyperX NGENUITY.

The `03F0:0D97` dongle is expected to work the same way but is untested.

## HID collection

| Field | Value (`0F98`) |
|---|---|
| USB interface | `MI_02` (interface 2) |
| Usage page : usage | `FF00:0001` |
| Input / output / feature report length | 64 / 64 / 64 bytes |

The dongle also exposes the standard mouse and consumer-control collections. The driver only opens a vendor
collection (usage page `FF00` or higher) with input reports of at least 8 bytes.

## Queries

Both are output reports: the first two bytes below, zero-padded to the report length. Each reply is an input
report whose first byte is the command plus one. Each query waits at most one second for its reply and skips
unrelated reports (after a reconnect the dongle sends `44 xx`, `45 xx` and `FB xx` reports on its own).

| Request | Reply | Meaning |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0 when the mouse is off or out of range |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100; `charge` 1 = charging, 2 = full on the charger; voltage in mV, little endian (0 on the Core) |

- If the link reply is missing, the battery reply decides.
- If the link reports 0, no battery query is sent and the mouse is shown as switched off.
- For a few seconds after the mouse powers on it reports about 40%. A reading within 6 s of the link coming up is
  ignored, and the tray keeps the last value.

Both requests only read state. Nothing changes settings, lighting or modes.


---

<a id="sec-inphic"></a>
> 📄 **Section:** Inphic IN10 (`docs/inphic.md`) · [English original](../../docs/inphic.md) · [↑ Top](#top)

# Inphic IN10 family, KP 8K receiver

The attached device, identified by its owner as IN10 MAX, enumerates as
`Inphic KP 8K`, `1D57:FA65`, release `0116`. Its status collection is
interface 2, usage `000A:0000`, input length 5 (including report ID 03).

Observed every approximately four seconds, without sending any request:

```text
03 73 41 01 64
```

The existing Xenta parser recognizes this format: model, event, battery state,
percentage. Two equal reports are required before displaying 100%; the first
report after linking may be a misleading full reading on related receivers.
This change preserves that safeguard and the existing charging/sleep behavior.

The official [Inphic HUB](https://hub.inphic.cn/) bundle `assets/index-BcHQx9B6.js`
maps model decimal 115 (`73`) to `IN10RMax`, and 116 (`74`) to `IN10Max`.
It uses battery state 1 for percentage, 2 for full and 3 for charging.
Use the firmware's model name rather than assigning `73` to IN10 MAX and
potentially mislabeling other devices sharing this receiver.

Before this change the app listed the attached mouse as `Wireless mouse`.
The Xenta transport already handled its battery frames; the change supplies
the missing model names. A fresh `--list` may show asleep because its five-second
initial observation can receive only one four-second report. The resident app
retains the listener and confirms the value on a later poll.

Hardware verified: passive reports, repeated 100% level and native driver model
identification. Charging transitions, low-battery boundaries, Bluetooth and cable
mode have not been verified. Model `74` is sourced from the official table and
has not been tested on separate hardware.


---

<a id="sec-machenike"></a>
> 📄 **Section:** Machenike L7 (`docs/machenike.md`) · [English original](../../docs/machenike.md) · [↑ Top](#top)

# Machenike L7 Arctic / L7 Mix

Verified on an L7 Arctic which identifies as **L7 Mix**:

| Connection | VID:PID | Interface | Usage | Input / output / max feature |
| --- | --- | --- | --- | --- |
| 2.4 GHz receiver | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB cable | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

The driver also checks the HID product name `L7 Mix`. Other Machenike models,
different receiver IDs, and Bluetooth vendor queries are not enabled.

## Protocol source

Interoperability analysis of the official **Machenike L7 Mix 1.0.0.8** software,
available from the [manufacturer's driver page](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/),
and read-only queries on the actual mouse. `DeviceDriver.exe` SHA-256:
`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

In that 32-bit executable (image base `00400000`), function VA `00436750` builds
the status request; `004494F0` sends it through `HidD_SetFeature` and reads the
feature reply. Status parser `00410C20` extracts the fields below and passes the
battery and charge fields to the UI. These are virtual addresses, not file offsets.
No proprietary executable, application code, or resources are included here.

## Read-state query

Send **21 bytes**, report ID `51`, command `06`, all other bytes zero:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Read feature report `51`, also using 21 bytes. The collection's maximum feature
size is 1001 for other reports; it is not the length of the status report.
The driver waits 10 ms before reading and uses one 200 ms deadline per product,
including unrelated replies. It sends no setting, mode, macro, or firmware commands.

Indices include the report ID:

| Bytes | Meaning / observed values |
| --- | --- |
| 0–1 | `51 06`, required command echo |
| 4–7 | `8A 24 4E FF`, the verified L7 device signature |
| 10, bits 0–2 | Work mode: 1 on receiver, 0 on cable |
| 10, bit 3 | Wireless mouse connected; clear on the USB cable too |
| 11 | Battery percentage, 0–100 (zero is valid) |
| 12 | Charge flag: 0 discharging, 1 charging |

Other fields and checksum semantics are not established. The driver does not
invent a checksum. It validates the command, length, device signature, mode and
connected-state battery/charge ranges before publishing a reading.

Captured receiver reply, also 64% in the official app:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Captured USB cable reply while charging (74%):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

At that time the receiver still returned its cached 64%, but cleared its link bit:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

This disconnected reading must not expose cached battery/charging values. The
cable takes precedence when both transports are present, and the stable device
key is shared across transports. A known L7 is reserved even on query failure so
the later Ajazz driver cannot probe it with a different protocol on the shared VID.

## Validation boundaries

Fixtures and simulated transport tests cover captured readings, charging,
valid 0%/100%, disconnected receivers, malformed/stale replies, strict matching,
transport failure, duplicate suppression and bounded retry loops. Live 0%/100%
and all sleep/firmware variants are not implied by those tests.


---

<a id="sec-nuphy"></a>
> 📄 **Section:** NuPhy WH80 (`docs/nuphy.md`) · [English original](../../docs/nuphy.md) · [↑ Top](#top)

# NuPhy WH80 (USB cable and Bluetooth)

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

The driver checks the exact product/interface/report sizes, response header,
offset, length, checksum and percentage range. It uses a 400 ms response deadline
and ignores unrelated replies within that same deadline.

Regression test:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Section:** Rapoo (`docs/rapoo.md`) · [English original](../../docs/rapoo.md) · [↑ Top](#top)

# Rapoo mouse battery support

## Why the original program missed the mouse

`PollAllDevices()` enumerates Windows HID top-level collections once per refresh. Each vendor
driver recognises a protocol, adds a `DeviceStatus`, and claims its VID/PID so the generic drivers
do not add it again. The UI already handles percentage, charging, and the last reading while asleep.

There was no Rapoo driver. The VT3 Max Gen 2 sends its battery in a vendor-defined input report,
not the standard HID Battery Strength usage or a Windows Bluetooth battery property. The existing
generic HID/Bluetooth fallbacks therefore cannot decode its USB receiver.

## Observed hardware and packets

Tested on Windows with the owner's VT3 Max Gen 2 on 2026-11-16:

| Connection | VID:PID | Interface | Usage page:usage | Input / output size |
|---|---|---|---|---|
| 2.4 GHz receiver | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 bytes |
| USB cable | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 bytes |

Both identify themselves as `Rapoo Gaming Device`. The other collections include standard mouse,
keyboard and media inputs, vendor configuration collections, and a 513-byte firmware interface.
The battery driver only opens `FF00:0002` with a recognised input size. It never opens the firmware
interface and never sends an output report, feature report, handshake, or configuration command.

Captured wireless report, including report ID:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Captured cable/charging report:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Offsets below count the report ID as byte zero, matching this project's `HidDev::Read()`:

| Byte(s) | Meaning | Example |
|---|---|---|
| 0 | Report ID | `07` |
| 1 low nibble | Connection: 0 receiver, 1 Bluetooth, 2 cable | `20` / `22` |
| 1 high nibble | Sensor information; not part of the connection type | `2` |
| 2 | Current DPI gear | `03` |
| 3–4, 5–6 | X/Y DPI, little endian | `0320` = 800 |
| 7 | Battery state: 0 invalid, 1 discharging, 2 charging | `01` / `02` |
| 8 | Battery percentage, 0–100 | `19` = 25% |
| 13–14 | Mouse product ID, little endian, when present | `4617` |

The live receiver capture reported `25%`, and the complete application subsequently returned
`27%, charging` over the cable. The parser test includes the actual wireless capture. Charging and cable connectivity
were also verified against live hardware; these are not inferred just from a USB device being present.
After the owner disconnected the cable and reconnected the receiver, the final executable returned
`52%` over `2.4 GHz receiver`, without the charging flag, and retained the same `rapoo:4617` key.
This also verifies the cable-to-receiver transition against live hardware.

Also tested on Windows with a **VT9 Gen 2** on 2026-11-17:

| Connection | VID:PID | Interface | Usage page:usage | Input / output size |
|---|---|---|---|---|
| 2.4 GHz receiver | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 bytes |
| USB cable | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 bytes |

The VT9 Gen 2 receiver exposes a **16-byte** `FF00:0002` report rather than 19 bytes, using the exact
same Nordic 54L `07` layout (including the embedded `4614` PID at bytes 13–14). Captured frames:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

Over USB cable, status reports were observed on interaction (e.g., DPI change); with the bottom
power switch turned OFF while plugged in, the mouse reported `state=2, percent=1` instead of the
actual battery percentage.

### VT3 Max Gen 2 receiver with a 13-byte collection (issue #1396)

A device-request form report for the same receiver ID `24AE:1417` listed a different interface
layout: `FF00:0002` with **13 / 13** bytes (instead of 19), and `FF00:000E` with 33 / 33 bytes,
with no 513-byte firmware collection. This looks like another receiver firmware revision. The
Rapoo software still showed the battery, so the driver ignored a working status channel.

Rapoo Hub's `VT_nrf54L` decoder (`py`) is length-adaptive: it always reads the DPI, battery
state and percentage, and reads the later fields (mouse PID at `n[12..13]`, RF info, ...) only
when the report is long enough. The VT3 MAX manifest (`productId: [17943, 5143]`) has no special
input-report type, so report `07` goes through that decoder on this receiver too. A 13-byte report
(ID plus 12 bytes) still carries state at byte 7 and percentage at byte 8; only the embedded mouse
PID is missing, so the reading uses the receiver PID and keeps the `rapoo:4617` key.

The 13-byte length is accepted **only for `24AE:1417`**. Frames must still pass the same checks
(report `07`, connection nibble 0–2, state 1/2, percentage 0–100). No live 13-byte frame has
been captured yet; the tests use the tested 19-byte capture cut to 13 bytes.

## Other Rapoo mice

The official Rapoo Hub uses this `07` layout for its Nordic 54L mouse driver. Its manifests
list VT0, VT1, VT2, VT3, VT3S, VT7, VT9 and additional variants. Inspection of the current bundle
identified 69 VT variants using `VT_nrf54L`; this is evidence of a shared protocol, not 69 hardware
validations or a claim to cover most of the entire Rapoo catalog. Support is selected by Rapoo VID,
the dedicated collection, input length, and a valid status report, so an unlisted model on the same
protocol can still report its battery. A small name table covers common models; others retain their
HID product name or show `Rapoo wireless mouse`.

Product names and IDs vary across generations and regions. The tested `1417/4617` pair is called
`VT3 MAX` in the current official manifest; the owner identifies it as VT3 Max Gen 2. The current
manifest's separate `VT3 MAX V2` has IDs `1B06/4B06`. Community tables assigning `1417` to VT9 Pro
must not be used as the sole basis for naming or detecting this device.

Older VT firmware, documented for VT3 Pro (`1215/4415`), instead pushes a 7-byte report on the same
`FF00:0002` usage:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

For this legacy format, states 1/2 mean discharging/charging. A charging percentage of `7F` means
unknown and is preserved as unknown. Transition state 0, unrelated `BC` reports, malformed packets,
and percentages above 100 are ignored. Legacy support has automated coverage, but has not been
verified with a physical legacy mouse here. This interpretation is restricted to product IDs
`1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) and their 7-byte input collection.

The VT1 Pro Max (receiver `24AE:1233`, cable `24AE:4433`, mouse firmware 222, dongle firmware 213)
was added from USBPcap captures its owner attached to issue #136. The `--dump` output lists the
7-byte `FF00:0002` collection on interface 1, and the captures show it pushing, with no request
from the Rapoo app:

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

On the cable the report was seen only once in a 16-second capture, so a cable-only reading may
time out on some refreshes; the receiver pushes it regularly. The Nordic profile never interprets `BB` packets.

This does **not** establish support for every Rapoo device. CH584 models such as VT1 SE and VT7 SE
use report `08` in the official driver and are not supported by this decoder. Other Telink revisions use a different
interpretation of the `BB` flags, some office models use active battery queries, and Bluetooth models
may expose only the Windows battery property. These remain with the existing fallbacks or need a
separate verified implementation. Do not send guessed queries to them.

## Polling and identity

- Reading is passive. Matching `FF00:0002` handles stay open between polls (matching `PollXenta`)
  so Windows buffers status frames arriving during the 60-second refresh interval; each poll drains
  any queued frames (keeping the newest valid battery reading) before falling back to a 5-second
  wait on first open or an empty queue. Unplugged devices are removed and their handles closed.
  Unrelated packets do not restart the deadline.
- The embedded mouse PID, or a known cable/receiver pair for legacy devices, gives the same UI key
  across cable changes. Cable and receiver readings are merged into one entry, preferring the cable's
  state while preserving a valid receiver percentage if the cable reports an unknown level.
- A timeout does not invent a percentage or claim the device. After a successful reading, the
  existing UI can retain that reading, dimmed, for 30 minutes of silence.
- The program's existing VID/PID-based identity model cannot distinguish multiple identical mice
  with the same model ID. Physical simultaneous cable/receiver operation was not tested; merging
  both inputs is covered by the simulated transport test.

## Validation

`make test` runs a portable decoder test and a Windows driver test with simulated HID responses.
Coverage includes the actual capture, 0% and 100%, charging, missing levels, invalid/truncated frames,
unsupported collections/vendors, protocol-profile isolation, timeouts, stable keys, and cable/receiver
deduplication without discarding a known percentage.

The full application was built locally with MSVC C++17 and the Windows SDK, and `--list` / `--dump`
were run against the actual mouse. The maintained MinGW build includes `rapoo.cpp` in `build.bat`;
the Makefile discovers it automatically. MinGW itself was not installed in the test environment.

## Protocol sources

- [Official Rapoo Hub](https://hub.rapoo.cn/), inspected 2026-11-16: bundled
  [JavaScript driver and manifests](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js).
  Relevant decoders are `py`/`Hk` for `VT_nrf54L` and `qM`/`QM` for connection and battery-state
  meanings. The separate `VT_CH584` handler consumes report `08` and is outside this implementation.
  Minified names may change on future releases.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs),
  for legacy VT3 Pro reports, charging state and the unknown-level sentinel.
- Issue #136 USBPcap captures (VT1 Pro Max on receiver and on cable while charging).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js)
  independently corroborates passive `07` status broadcasts and the battery offset. Its parser
  clamps invalid percentages; this implementation rejects them instead.


---

<a id="sec-rawm"></a>
> 📄 **Section:** RAWM (`docs/rawm.md`) · [English original](../../docs/rawm.md) · [↑ Top](#top)

# RAWM protocol notes

RAWM mice (and the SADES Dagger, which shares the platform) talk to the RAWM HUB app over a
vendor HID collection, `FF00:0001`, with 64-byte unnumbered input and output reports (65 bytes
with the report ID). The receivers and mice use Nordic's vendor ID `1915`.

Source: the RAWM HUB web app, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), and its script
`https://hub.miracletek.net/hub/js/library.min.js` (obfuscated; the function and constant names below
are the script's own). The supported product IDs come from the device table the app downloads
(`https://www.miracletek.net/game/device.php`). Leviathan V4 GT and NYX60 use Hub Web 3.0 on VID
`373E`, which is a different protocol.

## Packets

Byte 0 of every report (after the report ID):

| Top bits | Meaning |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | the low 6 bits are a payload size; the payload continues the event stream |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | flow control (free buffer sizes); ignored here |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | the low 6 bits are an ESB channel; the rest of the report is a packet for that channel. The mouse behind a receiver is channel 0 |

The payloads form a byte stream of events:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## Reading the battery

The driver repeats what the app does when a receiver is connected (`send_event_query`, `send_event_ping`):

1. To the receiver: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), then
   pings `00 84 0E 04 00 00`. The device only sends while the host keeps writing, so the host pings.
   The receiver answers `CMD_QUERY_RESULT` (`02`) with JSON, e.g.
   `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. The same query and pings for channel 0, prefixed with `C0`. The mouse answers with a ~550-byte JSON object
   in 30-byte ESB chunks, e.g. `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`.
   `battery` is a percentage (RAWM HUB shows it as is), `chr` is 1 while charging.
3. Later changes arrive as `CMD_NOTIFY` (`0B`) type `17`: `[17, percent, charging]`.

The driver always asks the receiver first, as the app does (in one test, a query sent only to channel 0
got no reply). A sleeping mouse does not answer at all; the receiver still does.

The query carries the PC's clock because the app sends it that way; nothing else is written.
Mice report `"crc":1`, which tells the app to wrap later commands (configuration) in a CRC-16 frame;
the query and pings are accepted without one, as the app sends them before it knows.

Tested on a Leviathan V4 (firmware 1.2.0) with the RAWM HS Receiver `1915:2346` (firmware 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **Section:** VAXEE (`docs/vaxee.md`) · [English original](../../docs/vaxee.md) · [↑ Top](#top)

# VAXEE 4K/8K receivers and ZYGEN NP-01S V2

## Scope and hardware validation

This driver supports the VAXEE 4K receiver `3057:1002`, the VAXEE 8K receiver
`3057:2002` and the ZYGEN NP-01S V2 Wireless over USB cable (`3057:1011`), on
their vendor collection `FF05:0001` with a 64-byte feature report. Other VAXEE
receivers, other cable product IDs and ZOWIE devices are deliberately not
probed.

The 8K receiver (`VAXEE 8K Wireless`, paired with an NP-01 Ergo Wireless 8K)
was tested on Windows and reported through the same protocol:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

The receiver is shared by all VAXEE 8K mice and does not report which one is
paired, so it is shown by its own name. Charging status on the 8K receiver has not yet been observed on hardware.

A real 4K receiver was tested on Windows:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

The integrated application also reported:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

The same mouse was then connected directly over USB and Windows identified
it as `ZYGEN NP-01S V2 Wireless` (`3057:1011`). The updated production driver
reported:

```
VAXEE battery: 75%; charging: yes
```

The taskbar widget was created successfully in the initial receiver build.
Both on-battery receiver operation and wired charging have been observed;
full-charge transitions and sleep/off behavior have not been tested on
hardware. Charging decoding and invalid responses are covered by simulated
replies.

## Protocol

Source: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

A request is a zero-padded 64-byte HID feature report:

| Byte | Value |
|---|---|
| 0 | `0E`, report ID |
| 1 | `A5`, header |
| 2 | `0B` for battery level; `10` for charging status |
| 3 | `01`, read flag (never `02`, write) |
| 4 | `01`, data length |
| 5–63 | `00` |

After sending the request with `HidD_SetFeature`, wait 100 ms and read report
`0E` with `HidD_GetFeature`. Require at least six bytes and the expected report
ID, header, command echo and data length.

For battery, response byte 5 must be 0–20 and is multiplied by five, giving
0–100% in 5% steps. For charging, byte 5 is nonzero when charging. A failed
charging query does not discard an otherwise valid battery reading.

The driver retries the battery request once. There are at most three read
requests per matching collection (two battery attempts and one charging
query), with 300 ms total explicit delay. It sends no settings, pairing,
firmware or lighting commands.

If no valid battery reply is received, the driver reports nothing and leaves
the device unclaimed. While the USB collection remains present, the UI retains
a previously successful reading, dimmed, for up to 30 minutes using its existing
grace-period behavior. If the physical collection disappears, the driver emits
one disconnected status to end that grace period immediately. This prevents
a stale receiver icon lingering when the cable is moved to the mouse.

## Tests

`make test` includes `tests/vaxee_driver_test.cpp`, which links the production
driver against a simulated HID transport. It checks the exact outgoing
read-only requests, percentage conversion, charging decoding, invalid and
missing replies, already-claimed devices and exact collection filtering.
