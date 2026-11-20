<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **语言：** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | **简体中文** | [繁體中文](zh-TW.md) | [添加语言](README.md)
<!-- lang-switcher:end -->

# BatteryHub — 完整文档

> 本独立 Markdown 文件汇总了仓库中的所有可见文档，译者只需为每种语言维护**这一个文件**即可。

## 目录

1. [BatteryHub 概览、支持设备、安装、命令行与构建（`README.md`）](#sec-readme)
2. [贡献指南（`CONTRIBUTING.md`）](#sec-contributing)
3. [Pull Request 模板（`.github/pull_request_template.md`）](#sec-pr-template)
4. [发布与签名指南（`docs/releasing.md`）](#sec-releasing)
5. [Keychron 键盘 2.4 GHz 固件补丁（`docs/keychron_keyboard_firmware/README.md`）](#sec-keychron-firmware)
6. [GameSir Cyclone Pro BLE 支持（`docs/gamesir_cyclone_pro.md`）](#sec-gamesir-cyclone-pro)
7. [多语言使用与本地化指南（`docs/i18n/README.md`）](#sec-localization-guide)
8. [ARDOR GAMING Fury V2（`docs/ardor_fury_v2.md`）](#sec-ardor-fury-v2)
9. [Areson 25A7 接收器（`docs/areson.md`）](#sec-areson)
10. [DARKRIM SHADOW 接收器（`docs/darkrim.md`）](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless（`docs/hyperx_haste_2.md`）](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K 接收器（`docs/inphic.md`）](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix（`docs/machenike.md`）](#sec-machenike)
14. [NuPhy WH80（`docs/nuphy.md`）](#sec-nuphy)
15. [Rapoo 鼠标电量支持（`docs/rapoo.md`）](#sec-rapoo)
16. [RAWM 协议说明（`docs/rawm.md`）](#sec-rawm)
17. [VAXEE 4K/8K 接收器（`docs/vaxee.md`）](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **章节：** BatteryHub 概览（`README.md`） · [英文原文](../../README.md) · [↑ 返回顶部](#top)

# BatteryHub

*原名 **Wireless Battery**。1.1.0 版本更名为 BatteryHub；更新后将保留你的设置、开机启动选项及电量历史记录。*

[![在 Ko-fi 上支持我](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![通过 PayPal 捐赠](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![加入我们的 Discord](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![在 GitHub 上点亮 Star](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![分享到 Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![报告设备](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![协助翻译](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

直接在 Windows 任务栏上显示你的无线鼠标、耳机、键盘和手柄的电量。

![任务栏上的 BatteryHub](../screenshot.png)

> **只想直接开箱即用？** 从最新发布版本下载 **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)**，运行并按向导点击完成即可。
>
> **进阶用户**可以获取便携版 ZIP、使用[命令行选项](#command-line)，或通过 `make` / `build.bat` [从源码构建](#build)。
>
> **喜欢这个工具吗？** BatteryHub 完全免费且开源。如果它帮你省去了打开各家厂商驱动软件的麻烦，欢迎在 [Ko-fi](https://ko-fi.com/krisgfx)、[PayPal](https://www.paypal.com/paypalme/krisgfx) 或 [GitHub Sponsors](https://github.com/sponsors/krisgfx9) 上支持本项目。这能帮助我在求学之余持续免费维护这些应用。暂时不方便捐赠？点一个 ⭐ Star、分享给朋友，或者通过 `--dump` 报告尚未支持的设备也同样非常有帮助。

- **极致轻量**：仅约 350 KB 的程序，内存占用约 2 MB。纯 C++/Win32 编写，无需额外运行时，无后台服务，无需管理员权限即可在数秒内完成安装。
- **无需厂商软件**：直接与设备通信。G HUB、Synapse、iCUE、GG 和 NGenuity 可以保持关闭（即使继续运行也不会冲突）。
- **支持众多品牌**：Logitech、Razer、SteelSeries、Corsair、HyperX、Glorious、Jabra、JBL、PlayStation 和 Xbox 手柄、Samsung Galaxy Buds、任何 Windows 能读取电量的蓝牙设备，以及内置 [HeadsetControl](https://github.com/Sapd/HeadsetControl) 所支持的全部耳机。

## 显示方式

**在任务栏上（默认）：** 位于通知区域旁边的 `🎧 30%  🖱 93%`，使用 Windows 图标字体绘制。
- **电量低：** 红色数字表示电量低于或等于 15%。
- **充电中：** 数字旁会显示蓝色 ⚡ 图标。设备充满且仍连接电源时，图标会变为绿色 ✓。
- **休眠中：** 暗淡显示的文字表示设备处于休眠状态，此时显示最后一次已知的电量值。
- **已断开（可选）：** 在菜单中开启 *显示已断开的设备* 后，当设备驱动程序明确报告无线链路离线时，会显示暗淡的 `×`。该功能不会仅因单次轮询超时而推断设备已断开；默认仍保持隐藏离线设备。
- **同类型多设备：** 当同时有两个鼠标（或两个手柄……）时，两台设备图标相同，因此图标角落会显示最多 3 个字母的简短角标（取自设备名称，如 `MX`、`PRO`；名称无法区分时则显示数字）。同类型中只有一台设备时不显示角标。
- **主题适配：** 自动跟随系统浅色/深色模式以及 DPI 缩放比例。
- **透明任务栏主题**（例如 Windhawk 的 Taskbar Styler）：可在菜单中开启 *任务栏文字背景*，以确保文字在壁纸背景上依然清晰可读。
- **多显示器：** 小部件会显示在每个显示器任务栏的时钟旁边，这样在全屏游戏时也能保持可见。菜单中的 *小部件显示位置* 可选择 *所有显示器*、*仅主显示器*，或仅指定某一显示器（例如仅 *显示器 3*）。
- **更多显示选项：** *图标位于百分比上方* 可将图标叠放在电量百分比上方以节省横向宽度；*品牌颜色* 会用对应厂商的代表色（如 Razer 绿、HyperX 红等）显示已知品牌并附带细电量条；同类型两个设备会自动附带小角标以便区分；停靠在屏幕左侧或右侧的垂直任务栏会纵向排列设备。
- **多语言：** 支持 English、العربية、Deutsch、Español、فارسی、Français、עברית、日本語、한국어、Magyar、Polski、Português (Brasil)、Русский、Svenska、Tiếng Việt、Türkçe、Українська、简体中文和繁體中文。Windows 版与 Linux 版均会默认跟随系统显示语言；在菜单的 *语言* 中可切换其他语言，Windows 安装程序同样支持全部 19 种语言。界面文本保存在可直接编辑的静态 `lang/*.json` 文件中，完整文档译文则存放在 [`docs/i18n/`](README.md)。编辑或新增语言请参阅[翻译](#translations)。
- **品牌颜色：** 来自 15 个已知品牌的设备会使用各自厂商的配色，带有柔和辉光并在百分比下方显示一条细电量条：Razer 绿、Logitech 蓝、SteelSeries 橙、Corsair 黄、HyperX / ROG / ZOWIE 红、PlayStation、Xbox、Samsung、Apple、Jabra、JBL、Cooler Master 和 Steam。每种颜色都分别针对深色与浅色任务栏进行了调校。品牌识别依次依据找到设备的驱动、厂商 ID（VID）和设备名称；具体颜色和规则定义在 `src/brands.cpp` 中。可在菜单中关闭 *品牌颜色* 停用此功能。

**托盘图标：** 每个设备占用一个托盘图标并直接在图标中绘制数字，电量降至 15% 时弹出“电量低”通知。当任务栏为垂直方向或无法定位任务栏时，应用会自动切换至此模式。

**自定义设备名称：** 打开设备子菜单并选择 *重命名设备...*，即可设置自定义名称（最多 64 个字符）。该名称会显示在任务栏小部件的提示/角标、托盘提示与通知以及设备菜单中。使用 *恢复原始名称* 可还原驱动程序提供的名称。名称以稳定的设备键本地保存在当前用户的 Windows 注册表（`Software\WirelessBattery`、`DeviceAliases`）中。重命名不会影响驱动匹配、协议查询或 `--list` / `--dump` 诊断输出，也无需账号或网络访问。

悬停可查看详细信息；点击可打开菜单：查看所有设备（点击任意设备可隐藏或显示它）、切换显示模式、*立即刷新*、*开机启动* 以及 *退出*。电量每 60 秒刷新一次（可通过菜单中的 *检查电量间隔* 调整），当插入设备或电脑唤醒时也会立即刷新。

## 智能电量提醒（实验性）

你可以在每个设备的子菜单中设置**单设备低电量通知阈值**：**电量提醒** → *使用默认值（15%）*、*禁用通知*，或从 5%、10%、15%、20%、25%、30%、35%、40% 中任选其一。除非你手动覆盖，否则默认的 15% 阈值保持不变。设置按设备键存储在当前用户的 Windows 注册表（`Software\WirelessBattery`、`AlertThresholds`）中。

仅当设备处于已连接、已唤醒且未充电状态并读取到真实的 0–100% 电量时，才会触发提醒。提醒仅发出一次，直到电量回升至所选阈值以上超过 10 个百分点（或开始充电）后才会重新布防。缺失读数或处于休眠状态的设备不会重复触发提醒。已隐藏的设备不会产生通知。禁用单个设备的通知不会隐藏该设备或改变其电量百分比显示。

任务栏小部件模式和托盘图标模式均支持通知。由于 Windows 需要通知区域图标才能显示传统气泡通知，小部件模式在触发提醒后可能会临时显示一个通知图标，持续最多一分钟。小部件颜色和低电量高亮仍沿用项目原有的全局 15% 阈值，不受单个设备通知设置的影响。

## 电量历史与分析

在任务栏小部件或托盘菜单中右键点击某个设备，并选择 **电量历史...**。
原生界面且支持 DPI 自适应的查看器（自动跟随 Windows 浅色/深色主题）会用折线图展示过去 **24 小时**、**7 天** 或 **30 天** 内记录的电量变化，同时显示最新读数、最低/最高电量、百分点变化以及记录数。你也可以在查看器中清除所选设备的历史记录。

历史数据**仅保存在本地**，并且仅针对已连接、已唤醒且报告了数字百分比的设备进行记录。每台设备最多每 30 分钟采样一次（充电状态切换时除外，但最短间隔仍为 60 秒）。数据最多保留 30 天，本地文件体积控制在约 2 MB 以内。应用绝不会在现有轮询之外额外探测硬件，也不会通过网络发送任何历史数据，仅根据近期的放电观测数据做保守的近似剩余续航预估。预估需要满足以下条件：至少 4 个数据点、跨越至少 2 小时、电量下降至少 3 个百分点、具备最新读数以及稳定的放电阶段。设备充电中、读数过旧或数据不足时均不会显示预估；设备自行报告的续航时间并不可用。预估仅供参考，不作保证。缺失的历史数据在图表中以空白断开显示，不会进行插值推算。

在菜单中关闭 **记录电量历史** 即可停止保存新读数；此前已保存的数据会保留，直到你在查看器中手动清除。数据文件保存在 `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv` 中。其中的设备标识经过编码（非加密），文件仅限当前 Windows 账户本地使用。在 `--demo` 模式下，图表使用的是永远不会被保存的演示数据。**注意：** 历史记录仅在安装包含此功能的版本且应用持续运行一段时间后才会开始累积。

## 支持的设备

| 厂商 | 设备 | 实现方式 |
|---|---|---|
| **NuPhy** | 通过 USB 线（`19F5:A011`）或蓝牙（`19F5:324A`）连接的 WH80，已实机测试 | USB：只读 NuPhyIO 电量查询；蓝牙：带键盘分类的 Windows 电池电量（[协议说明](#sec-nuphy)） |
| **DARKRIM** | 通过 `3654:6901` USB 接收器连接的 SHADOW（寸渊影弑）（已实机测试） | 带 CRC 校验的只读电量查询与充电标志；实测读数按 10% 步进，更高精度尚未验证（[协议说明](#sec-darkrim)） |
| **Inphic** | KP 8K 接收器（`1D57:FA65`）上的 IN10R MAX / IN10 MAX（型号 `73` 已实机测试，型号 `74` 未测试） | 被动 Xenta 状态报告；连续两帧一致后确认电量（[协议说明](#sec-inphic)） |
| **ASTRO** | 通过 USB 底座连接的 A50 X（`046D:0B0B`，已测试）、A50 Gen 5（`046D:0B1C`）、A50 Gen 4（`9886:002C` 已测试，`002D`/`002A`）、A50 Gen 3（`9886:0015` 已测试，`0014`/`0018`/`001D`/`0026`）、A20 Wireless（`9886:0037`–`0045`） | 电量百分比、充电及放回底座状态 |
| **Logitech** | Unifying、Bolt、Lightspeed（包括 PRO X3 SUPERSTRIKE 接收器 `046D:C54F`）和 Nano 接收器上的鼠标和键盘，以及 USB 或蓝牙连接；G 系列耳机（G533、G535、G633/G635/G733/G933/G935、G PRO/PRO X）；新版 `046D:0ADF` 接收器上的 G435 | 支持功能发现的 HID++ 1.0 / 2.0：统一电量、电量等级、电压、ADC；G435：CRC-16 帧格式厂商报告，以 mV 为单位的 `GET_BATTERY` |
| **Razer** | 无线鼠标、键盘和接收器；BlackShark V2 HyperSpeed、V2 Pro（2020/2023）、V3 / V3 Pro / V3 X 耳机、V3 Pro for Xbox（`1532:0A55` 接收器，`0A4E` 有线）；2.4 GHz 接收器上的 Barracuda X（2022）（`1532:0550` 或 `1532:0552`）；Barracuda Pro（`1532:053A`） | Razer 特征报告协议；BlackShark 厂商协议（V3 / V3 Pro / V3 X 每 5 分钟查询一次）；Barracuda X：通过接收器进行 Airoha 电量和有线连接查询 |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless、Arctis Nova 3P/5/7/7X/7P/Pro Wireless（含 `1038:225D`）、Arctis Nova Elite（底座 `1038:2244`）、GameBuds；Aerox 3/5/9 Wireless（Aerox 5 Diablo IV `1038:1860`，未测试）、Aerox 3 Wireless CS2 Dragon Lore Edition（接收器 `1038:1878`，有线 `187A`）、Aerox 3 Wireless Gen 2（接收器 `1038:1890`，有线 `1892`）、Prime Wireless、Rival 3 Wireless（Gen 2）、Rival 650、Rival Pro | 厂商 HID 报告；Aerox/Prime 和 Rival 650 在接收器与 USB 线之间共享同一个设备条目，两者均有响应时优先显示有线读数 |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 无线版；Bragi 设备（Virtuoso、Void V2、HS80 MAX、Slipstream 鼠标和键盘，含新版 Slipstream 接收器 `1B1C:2B00`，例如 Scimitar Elite SE Wireless，以及 Dark Core RGB Pro SE）；Sabre V2 Pro Ultralight Wireless（`1B1C:2B2A`）、Sabre v2 PRO WIRELESS MG（`1B1C:2B34`，未测试） | 厂商 HID 报告、Bragi `GET`（只读）、Compx 17 字节电量协议（只读） |
| **Cooler Master** | MM712、MM731（2.4 GHz 接收器或 USB 线） | 厂商 HID 状态报告（只读） |
| **Press Play** | `7768:6434` 2.4 GHz 接收器上的 ICARUS V2 Nearlink（驱动在 90% 电量下实机测试；协议在 100% 和 90% 下抓包验证） | `FFB2:0001` 上的只读输出报告 `06 05`；应答第 14 字节为电量百分比 |
| **HyperX** | Cloud III Wireless、Cloud III S Wireless、Cloud II Wireless（HP、Kingston、DTS）、Cloud II Core Wireless、Cloud Alpha Wireless、Cloud Alpha 2 Wireless、Cloud Flight（PS 版 `03F0:0C8C`，未测试）、Cloud Flight S、Cloud Stinger Core Wireless（含 DTS `03F0:0A8E`，已测试）、Cloud Core Wireless DTS、Pulsefire Haste 2 Core Wireless（2.4 GHz 接收器）、Pulsefire Haste 2 Wireless、Pulsefire Haste 2 Mini（2.4 GHz 接收器）（2.4 GHz 接收器 `03F0:0F98` 已测试；`0D97` 未测试） | 厂商 HID 报告（Haste 2：[协议说明](#sec-hyperx-haste-2)） |
| **Glorious** | Model O / O- / D / D- Wireless、Model O 2 / D 2 PRO | 厂商特征报告 |
| **Hitscan** | Hyperlight X、Hyperlight N | 厂商特征报告（与 Glorious 相同协议） |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury、Pulsar 和 ATK VXE 无线鼠标（例如 VXE X3 Pro、VXE Dragonfly R1 / R1 Pro Max / R1 SE+、ATK F1 Extreme）、Hitscan Hyperlight、Chimera V2（接收器 `3554:F512`） | 带校验和应答的共享厂商协议 |
| **Pulsar X2 V3** | 1K 接收器（`3710:5402`）或 USB 线（`3710:3402`）上的 X2 V3；8K 接收器（`3710:5403`）或 USB 线（`3710:3406`）上的 X2 V3 eS | 64 字节厂商特征报告，电量寄存器 `08 81 01`（只读） |
| **ATK / VXE NK** | NK 鼠标 NANO 接收器（`373B:1216`）上的 VXE R1 NK 及其他 NearLink 鼠标 | `FF05:0001` 上的 ATK BITMOUSE 输出报告 08（电量和充电状态） |
| **ATK 8K Nano** | ATK 8K Nano Dongle（`373B:1178`）上的 ATK / VXE 鼠标 | `FF10:0001` 上的 Holtek GetConfigData（`82`）特征报告（来自 ATK HUB；电量和充电状态） |
| **ATK 耳机** | ATK N9 Pro、N9 Ultra（第一代） | 虚拟串口协议（须关闭 ATK 桌面软件） |
| **G-Wolves** | Fenrir、Fenrir Pro / Max / Asym、HTX、HTS、HSK、HTR、HT-S2、Lycan、WARG、VUK 及其 8K 接收器 | 视型号采用 Glorious 或 Kysona 协议 |
| **Keychron 鼠标** | 2.4 GHz 接收器上的 M4 及其他 Keychron 鼠标；Keychron 4K Link 接收器（`3434:D038`）上的 4K 鼠标（M4 4K、M3 4K、M3 mini 4K、M6 4K 等）；TurboLink 8K 接收器上的 8K 鼠标（M5 8K、G6 HE 8K 等）；Ultra-Link 8K 接收器（`3434:D028`）上的 8K 鼠标；1K 接收器（`3434:D030` / `D031`）上的早期鼠标（M1、M2、M3、M3 mini、M6、M7 等）；Link-KM 接收器或有线上的 Nape Pro 轨迹球 | 来自 Keychron Launcher 的厂商报告（1K 接收器：特征报告 51 06，与 Keychron 桌面应用一致；Ultra-Link 8K：`FFC1` 上的报告 B5 03 / B3 06；Nape Pro：原始 HID A7 31） |
| **Keychron 键盘** | Keychron Link 接收器（`3434:D030`）或 USB 线上的 K5 Max（`3434:0A50`，已测试）；刷入相同补丁后的其他 Keychron QMK 无线键盘 | `FF60:0061` 上的原始 HID：`B2` 向接收器查询已配对键盘，`A4` 返回电量、电压和充电状态。**需要打补丁的键盘固件：**详见 [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)。原厂固件仅支持通过蓝牙上报 |
| **CHERRY** | 2.4 GHz 接收器（`046A:00EA`，已测试）或 USB 线（`046A:00E3`，已测试）上的 MX 3.0S 无线键盘 | `FF1C:0092` 上的厂商 HID 查询 `1A`（只读），含 USB 供电状态。蓝牙模式由通用蓝牙支持覆盖 |
| **CHERRY** | 1K 接收器（`046A:0330`，已测试）上的 Cherry XTRFY 无线鼠标 | CompX 17 字节电量协议（`08 03` 连接状态，`08 04` GetPower），与 Corsair Sabre V2 Pro 相同帧格式（只读） |
| **Arbiter Studio** | Akitsu（`373E:000A` 8K 接收器，`373E:0009` 有线）、Akitsu 3950（`373E:0039` 8K 接收器，`373E:0038` 有线）、Akitsu Medium（`373E:0067` 8K 接收器及 `373E:0066` 有线，均已测试） | 来自 Arbiter Web HUB 的 `FFFF:0000` 只读厂商特征报告 `0x83`（电量与充电状态） |
| **LAMZU** | Maya X、Maya、Maya M、Tachi、Inca、Paro、Thorn、Atlantis Mini / OG Champion、Orcus（有线、1K 及 4K/8K 接收器） | 来自 LAMZU Aurora 的厂商特征报告 |
| **Endgame Gear** | 4K 接收器上的 OP1w 4k（v1 / v2）、XM2w 4k（v1 / v2）；原装接收器（`3367:1961`）上的 XM2we | 厂商特征报告 `A1`，电量指令 `B4`（只读） |
| **ATK / VGN / Evision 键盘** | 共享 2.4 GHz 接收器（`320F:5088`）或 USB 线（`320F:5055`）上按产品名称识别的 ATK V75X 及 VGN / VXE 键盘（S99、V98 Pro / V98 Pro V2、N75 Pro、VXE75 / VXE75 V2、VXE V87）；名称为“Wireless Gaming Keyboard”的 `320F:5088` 接收器键盘，例如 Feker Alice80（已测试） | Evision 输出报告 `04`，电量指令 `1A`（来自 ATK HUB 和 VGN HUB）；通过接收器时最多每 10 分钟查询一次 |
| **Redragon (Evision)** | `320F:226F` 2.4 GHz 接收器上的 K1NG M999（已测试）；该接收器 ID 可能也被其他型号共用 | 与 ATK 键盘相同的 Evision 协议（`FF1C:0092` 上的报告 `04`、指令 `1A`），每次轮询均查询；置于磁吸底座时显示充电；插上 USB 线后接收器会持续返回旧电量且无充电状态 |
| **Audeze** | USB 接收器（`3329:4B19`）或 USB-C 线（`3329:4B1A`）上的 Maxwell；USB 接收器上的 Maxwell 2（`3329:4B29`，已测试）；Xbox 版本 ID 未测试 | 厂商报告 `06` / 输入报告 `07`，电量属性 `0CD6`（单次只读查询） |
| **ENDORFY** | 2.4 GHz 接收器（`3738:0072`，未测试）上的 Viro Wireless | 厂商报告 `06` / 输入报告 `07` 上的 Airoha RACE “get battery”（`0CD6`），与 Audeze 和 Skullcandy 接收器相同的只读查询；无充电状态 |
| **Turtle Beach** | USB 发射器（`10F5:2251`，已在 HaloBattery 中测试；PC 版 `10F5:2262`，未测试）或耳机自带 USB 线（`10F5:2253`）上的 Stealth 700 Gen 3 | RACE `0x9942`（启用 CoAP 客户端）及封装在 RACE `0x9902` 中的 CoAP `GET /GSI`（与 Swarm II 一致）；从键 `240` 读取电量（无充电标志） |
| **AKG** | USB 接收器（`0ECB:20D9`，已测试）上的 N9 Hybrid | `FF13:0001` 上的 Airoha RACE：输出报告 `06`，输入报告 `07`，电量属性 `0CD6`（单次只读查询） |
| **NZXT** | 接收器（`1E71:2101`）或 USB 线（`1E71:2129`）上的 Lift Elite Wireless | 厂商读取指令 `4E 02 81 .. B0`（来自 NZXT CAM 抓包） |
| **Poly / Plantronics** | BT600 适配器（`047F:02EE` / `02F7`）背后的 Voyager 8200 UC 及其他耳机 | 报告 `07` get/set 协议，电量项 `0A 1A`（只读） |
| **WLMouse** | YING Magnesium（YING 8K 接收器 `36A7:A874`）；Beast X 8K、Beast X Mini / Mini Pro、Beast X Pro、Beast MAX、Sword X 8K（接收器或有线；不含 Beast X 4K）；Beast X V2（8K 接收器 `36A7:A856`）；Beast G（8K 接收器 `36A7:A860` 或有线 `36A7:A861`；未测试） | 厂商特征报告，状态指令 `0x83`（YING 与 Glorious 协议相同） |
| **Finalmouse** | 2.4 GHz 接收器（`361D:0100`，已测试）上的 UltralightX；接收器（`361D:0300` / `0301`，已测试）上的 Starlight X。不支持鼠标自身有线连接 | `FF00` 上的 xpanel 厂商报告：先执行只读 GET，再执行 *wake/all*（`0xE0`）；依据 xpanel 曲线换算电池电压或直接读取 Starlight X 自报百分比，并含充电状态 |
| **VAXEE** | VAXEE 4K 接收器（`3057:1002`）或 8K 接收器（`3057:2002`，例如 NP-01 Ergo Wireless 8K）上的无线鼠标；通过 USB 线连接的 ZYGEN NP-01S V2 Wireless（`3057:1011`） | `FF05:0001` 上的只读厂商特征报告 `0E`；电量按 5% 步进，含充电状态（[协议说明](#sec-vaxee)） |
| **Scyrox** | 2.4 GHz 接收器（`395A:0006`）上的 V12M | `FF00:0002` 上的 S-Center 2.0 配置文件读取（输出报告 `08`，指令 `01`）；仅电量，无充电状态 |
| **HECATE** | 同一接收器上的 G5M PRO 及其他 HECATE 鼠标，以及 USB 线 `35BB:D3FA / D3FC / D3FD` | Kysona 协议 |
| **Redragon** | 基于 Compx 的无线鼠标：M916 Pro 1K（已测试）、M913 Impact Elite（三模）、G49（接收器或有线） | Kysona 协议（Areson `25A7` 接收器列在 Areson 一栏） |
| **Taidu (钛度)** | Compx 2.4 GHz 接收器 `3554:F5D5` 上的 TSG808（已测试） | Kysona 协议 |
| **Areson (Redragon)** | `25A7:FA07` / `FA08` 接收器上的 M915RGB-WL（已测试）、原版 M913 Impact Elite 及其他鼠标 | 17 字节 `GetPower` 特征报告；电量以 10% 为步进，含充电标志 |
| **Ninjutso** | 1K 接收器（`1915:AE1C`，已测试）或 USB 线（`1915:AE11`，已测试）上的 Sora V2；Ten Air（接收器 `093A:EB01` 和 USB 线 `093A:E020`，已测试）/ Ten（`093A:EB01` / `E020`，未测试） | NinjaForce 特征报告 `0x05`（Sora V2 为 `0x15`）和 `0x06`（Ten / Ten Air 为 `0x13`/`0x12`/`0x11`） |
| **Sprime** | 2.4 GHz 接收器（`1915:AC1C`，已测试；`1915:AD8C`）或 USB 线上的 PM1 | 来自 Sprime 网页驱动（sprime.pro）的相同特征报告 0x05，状态指令 0x15 |
| **RAWM / SADES** | RAWM HS Receiver（`1915:2346`，已测试）上的 Leviathan V4；使用 RAWM 接收器（`1915:232A`–`234B`）或 USB 线的 ES21 / ES21 Pro / ES21M、ER21 / ER21 Pro / ER21M、ES11、G11 / G11 Plus / G11 Pro、SA-* 以及 SADES Dagger 鼠标 | 通过接收器进行的 RAWM HUB 2.0 设备信息查询（包含电量 % 和充电状态的 JSON），只读（[协议说明](#sec-rawm)） |
| **AULA** | 2.4 GHz 接收器上的 F75 / F87 Pro / F99 无线键盘 | 报告 0x13 帧，指令 0x4A，累加和校验（蓝牙及有线模式未测试） |
| **AULA 鼠标** | AULA-8K Dongle `320F:22A0` 上的 X9 Ultra（已测试）；接收器 ID 与 V9 系列共用 | `FF1C:0092` 上位于 START `01` / END `02` 之间的报告 `04` 只读电量指令 `1A`；仅限 2.4 GHz |
| **SONiX 键盘 (AJAZZ / AULA / EPOMAKER)** | `05AC:024F` 2.4G 接收器上的 AJAZZ AK820 MAX（已测试）、EPOMAKER EA75（已测试）、AULA F108 Pro；`0C45:FEFE` 接收器上的 AJAZZ AK980 V2；`0C45:FDFD` 或 `0C45:FEFE` 接收器上的 AJAZZ AK820 Pro；`342D:E479` 上的 EPOMAKER P75（尚未实机测试） | 用途页 FF60 上的厂商报告 `20 01`，累加和校验（仅 2.4G 模式；无充电指示） |
| **其他 SONiX 接收器（尚未实机测试）** | RK Royal Kludge R75（`342D:E485`）；Redragon Arlokks K742B（`342D:E4BC`）；M1 V5 VIA（`342D:E4C2`）；Lucky65V2（`342D:E407`）；Lofree Flow2（`388D:0003`）；MSI FORGE TKL W FRIEREN EDITION（`0DB0:0CA0`）；Essential75（`36B0:30BD`）；NUT65（`342D:E51A`）；RK 2.4G Dongle（`342D:E487`）；WEIKAV MAX102（`342D:E537`）；Lofree Flow2（`388D:0002`）；NuPhy Air75V2（`19F5:3245`）；SKN 青龙（`362D:D028`）；Lemokey Link（`362D:D030`）；Wireless Link（`362D:D101`）；Spade65-QMK-2.4GHz（`342D:E49F`） | 相同的仅电量 `20 01` 查询；需精确匹配 VID:PID 以及带 33 字节报告的 FF60:0061 集合；仅限 2.4G，无充电指示 |
| **36B0 键盘 (PMO / WOBKEY / URX / EVO80)** | `36B0:3002` 2.4G 接收器或 `36B0:3009` USB 线上的 PMO (WOBKEY) Wave 75 RGB（#343 报告者已验证两种连接的协议）；同接收器或有线下的 Aurora 80（`3004`）、PMO P75（`302B`）、PMO 80（`3012`）（未测试）；接收器上的 URX Core75（在 HaloBattery 中已确认）；EVO80（未测试） | PMO Hub 固件：用途页 FF60 上的 `START_COMM` / `GET_BATTERY`（`AA 30`）/ `STOP_COMM`，来自 pmohub.cn。URX / VIA 固件：VIA custom-get `08 00 07`（通道 0，值 7），来自 HaloBattery 中的 URX HUB。无充电指示 |
| **DAREU** | `260D:1074` 2.4 GHz 接收器或 `260D:1090` USB 线上的 EM901X（两者均已实测电量读数；已实测接收器上底座充电/取下时的充电标志切换） | 仅电量特征报告 `08`，指令 `04`；应答 `09` 位于单独的厂商集合。每个产品 ID 需具备唯一的输入/特征集合对。两者同时连接时优先采用有效的 USB 读数；鼠标关闭后接收器仍可能返回缓存遥测数据 |
| **DAREU** | A84 键盘（`260D:0022`，未测试） | 接口 0 上的 SONiX 特征报告，指令 `04 F6`（官方 A84 驱动的电量读取）；返回百分比电量，无充电标志 |
| **DAREU** | `260D:1131` 多鼠标接收器及 USB 线（`260D:1148`）上的 A980 Pro（已实机测试电量；已确认插线时的充电标志） | Togran 协议：消费者控制集合上的 65 字节特征报告 `0A`；先槽位查询（class 0 / `A0`），再电量查询（class 7 / `80`），有线连接下固定查询槽位 0。只读 |
| **Sharkoon** | `260D:1125` 上的 Skiller SGM50W（未测试） | 与 DAREU EM901X 相同的 Compx 查询（特征报告 `08`，指令 `04`；`FF01:0000` 上的应答 `09`）；Sharkoon 为该鼠标提供的固件更新工具即基于 VID `260D` 的 Compx 工具 |
| **Zenith** | `260D:1114` 2.4 GHz 接收器（已实测电量；充电未测试）或 `260D:1143` USB 线（未测试）上的 Zenith Pro | 以 `FF02:0002` 输出报告形式发送相同 Compx 指令（`08`、`04`）；同一集合上的应答 `08 04` 包含百分比、充电标志与毫伏电压，按 `0x55` 字节和校验 |
| **AJAZZ AK992** | Telink 2.4 GHz 接收器 `320F:50C3`（已测试） | HID 集合 `FF1C:0092` 上的 EVision 电量查询 |
| **ZOWIE** | 2.4 GHz 接收器上的 EC1/EC2/EC3-CW、DW 系列（U2-DW、S2-DW 等）及 U2 | 社区整理记录的只读厂商指令 |
| **Royal Kludge (RK)** | 2.4 GHz 接收器（`2E3C:00A6` / `00E6`）或 USB 线（`2E3C:00A5` / `00E5`）上的 MG6 Pro | 来自 RK 网页驱动的 QiWang 64 字节帧，`GET_BATTER_VOL` 读取（百分比、电压、充电状态） |
| **ASUS ROG** | Strix Scope II 96 (RX)、Azoth、Falchion 键盘；Keris、Harpe、Gladius、Chakram、Spatha、Pugio、Strix Impact 鼠标；Pelta 耳机（2.4 GHz 接收器）；Cetra Open Wireless 真无线耳机（SpeedNova 接收器 `0B05:1CAC`，左耳 / 右耳 / 充电盒）；Omni Receiver | ROG HID 电量查询 |
| **Machenike** | `248A:FF4C` 2.4 GHz 接收器或 `248A:FF4E` USB 线上的 L7 Arctic / L7 Mix（均已测试） | 只读特征报告 `51`，状态指令 `06`；电量及充电状态。[协议说明](#sec-machenike) |
| **MSI** | 2.4 GHz 接收器（`0DB0:9E22`）上的 VERSA 300 ELITE WIRELESS；CLUTCH GM31 Lightweight Wireless（2.4 GHz 接收器 `0DB0:0D3C`，已测试；USB 线 `0DB0:0D3B`）及 CLUTCH GM41 Lightweight Wireless（接收器 `0DB0:0D4C` / 有线 `0DB0:0D4B`，来自机主抓包） | `FF0D:00B0` 和 `FF00:0001` 上的只读厂商查询 `0F 20`；单字节包含电量与充电标志（协议来自 MSI Center 的 Gaming Gear 模块）；GM41：`FF10:0006` 上的被动 `A0 xx 07 …` 报告 |
| **MCHOSE** | 2.4 GHz 接收器或 USB 线上的 L7 / L7 Pro / L7 Ultra（L7 Ultra 已测试）、M7 / M7 Ultra、A7 / A7 Ultra、K7 鼠标；A5 V2 Ultra（2.4 GHz 接收器 `3837:100C`，已测试）、K7 Ultra（2.4 GHz 接收器 `3837:1001`，已测试；A7 V2 Ultra+ `3837:100B` 预计可用，issue 227）；G3 V2（2.4 GHz 接收器 `3837:4245` 和 USB 线 `3837:418C`）；2.4 GHz 接收器 `3837:1014` 或 USB 线 `3837:4028` 上的 K7 V2 Ultra+（均已测试；同系列其余接收器 ID `1018`、`1016`、`102C`、`102D` 未测试） | 厂商特征报告，反码载荷（协议来自 alexfrih/mchose-linux）；Realtek `3837` 接收器以 `41E4`（A5 V2 Ultra）或 `3837`（K7 Ultra）作为应答 vid 字段；G3 V2：`FF01:0010` 上的只读厂商查询；K7 V2 Ultra+：`FF01:0001` 上的 64 字节报告 `0x4D`、设备信息指令 `0x0900`（协议来自 M HUB 网页驱动） |
| **MCHOSE A5 (第一代)** | 1K 或 4K 2.4 GHz 接收器（`2023:F013`、`2023:F015`、`2023:F018`）或 USB 线（`2023:F017` A5 Pro，`2023:F019` A5 Pro Max）上的 A5 Pro / A5 Pro Max；本地未实机测试 | `FFFF` 上 64 字节特征报告中的只读电量指令 `0x83`（第 0 页），应答标记为 `0xA1`（协议来自 z750sasr 的 A5 Pro Max 网页驱动和 HaloBattery，ID 来自 Klegus/mchose-macos） |
| **MCHOSE 耳机** | 2.4 GHz 接收器（`3837:6011`，已测试）上的 V9 Pro 2 | `FF07:0222` 上 M HUB 的只读“MC”电量帧（报告 `0x55`，子指令 `0x0B`）；单字节包含电量和充电标志（协议来自 M HUB 网页驱动） |
| **AULA / MCHOSE / Redragon 键盘** | AULA F75 / F87 Pro / F99；MCHOSE K99 V2、G75 Pro、X75 及其他 M HUB 键盘；2.4 GHz 接收器（`3554:FA09`、`41E4:2001`）上的 Redragon Horus Pro / Pro V2（K618RGB-PRO）；`05AC:024F` 接收器上的 MCHOSE K87（接口 1 上的 BY 布局，而非 SONiX 方案） | 报告 0x13 帧，指令 0x4A（MCHOSE 和 Redragon 型号通过指令 0x05 识别，与 M HUB 一致）；未涵盖蓝牙和有线模式 |
| **MCHOSE 键盘** | 2.4 GHz 接收器 `3837:3033` 上的 G75 V2（已测试）；G87 V2 和 K99 V3 使用同一接收器（协议相同，未测试）；K87S 虽然使用相同接收器 ID 但采用不同协议，不在支持范围内 | 无报告 ID 的 64 字节 `0001:0000` 集合上 M HUB 的只读“GLW”func-config 查询：请求标志 `0x55`，指令 `0x05`，载荷第 32 字节为电量（第 7 位为充电标志），累加校验和 |
| **AULA SC580** | USB 线（`088D:062E`，已测试）或 2.4 GHz 接收器（`089D:062F`，已测试）上的 SC580 / SC580X 鼠标 | 33 字节厂商集合 FF02:0000 上的只读指令 `0x30`（设备信息），累加和校验；充电时鼠标固定上报 100，因此界面保持显示上次电量；未涵盖蓝牙模式 |
| **AULA HERO 68 Air** | 8K Wireless Receiver（`372E:106C`）上的 HERO 68 Air | 用途页 FF60 上带确认的 20 字节帧（每条消息包含 4 个数据帧和 1 个尾帧），只读电量指令 0x87，电量后紧跟充电标志 0x10；未涵盖蓝牙和有线模式 |
| **EWEADN (前行者)** | “Gaming 2.4G”接收器（`372E:103D`）上的 S7 Max / Pro / Ultra 和 S9 Max / Pro / Ultra / Ultra+；USB 线（`372E:1027`）上的 S9 Ultra | `FF00:0001` 上的只读特征报告 `03`：连接检查 `47`，设备基础信息 `4F 81`（电量百分比及充电位），来自 EWEADN 网页驱动 |
| **Rapoo VT** | VT3 Max Gen 2（已测试）；VT9 Gen 2（已测试）；其他暴露相同状态接口的 Nordic 54L VT 鼠标；早期 VT3 Pro（实验性）；VT1 Pro Max（来自机主 USB 抓包） | `FF00:0002` 上的被动 HID 状态报告 `07`（16 或 19 字节；部分 VT3 Max Gen 2 接收器为 13 字节）；旧版 `BB` 仅限 VT3 Pro `1215/4415` 和 VT1 Pro Max `1233/4433`。支持接收器和 USB 线，含充电状态 |
| **Motospeed / Delux / Ajazz** | Motospeed X6、Delux M900 Pro（Xenta 型号 30/50；旧版 3D）、Delux M800 Pro、Ajazz AJ179 系列；3151 接收器上的 AJ159 及其他 AJ 系列鼠标；AJ139 V2 MC（`A8A5:2255` 接收器，`A8A4:2255` 有线） | 厂商报告（M900 Pro：被动状态广播或特征查询，Xenta 事件 40/41；AJ 系列：0xF7 状态轮询，然后特征报告 0x05） |
| **Incott** | G23 V2 / G24（`093A:522C` 接收器，`093A:622C` 有线） | 只读状态特征报告 09 |
| **Attack Shark 及其他国产品牌** | 荣圆（Rongyuan）接收器（81 个型号：`3151:402D` 上的 Attack Shark R3 和 AJAZZ AJ179 Pro、K86、X82 PRO HE、Ajazz 键盘、部分 MSI 及其他品牌；蓝牙连接的 K86 显示为键盘）；Xenta 接收器（Attack Shark X6 / R1、X11、X3 Max、V3 Pro、V6；X6 也见于 `1D57:FA61`，未测试）；Semico 1A2C 键盘（`1A2C:8FFF` 接收器上的 Attack Shark X98，已测试，以及 `1A2C:A034` 有线；`1A2C:8FFF` / `1A2C:A036` 上的 AJAZZ AK820 Max Plus） | 荣圆状态报告；Xenta 被动广播；Semico 只读 `0x0E` 状态查询（`FF02:0002` 上的 `AA 55 CC 33`；由于 X98 在使用电池和充电时均返回 `state=1`，故省略充电标志） |
| **Wraith** | W1 / W1 Freestyle（`093A:522C` 接收器，`093A:622C` 有线；与 Incott 共享 ID，通过型号码区分） | 遍历所有按键的只读逐键读取 `86`（特征报告 09），随后读取推送的状态输入报告 09 |
| **Fantech** | Helios Go XD5（有线 `25A7:FA7B`，接收器 `25A7:FA7C`）；复用 `1EA7:0066` / `1EA7:0064` 接收器的 Raigor III（已测试）、Raigor II WG10 及其他通用 2.4G Mouse 设备 | Helios Go XD5：厂商特征报告 `08`，指令 `04`，和为 `0x55` 的校验。Raigor/2.4G Mouse：`FFB5:0001` 上的只读 `B5` 状态页查询，chunk `94` = 最后上报百分比（休眠、关机或充电时可能滞后；无充电状态） |
| **Sony** | DualShock 4、DualSense、DualSense Edge（USB、蓝牙、无线适配器）；INZONE H9 II 和 H5 耳机；INZONE Buds（USB-C 接收器） | 输入报告；INZONE 厂商协议 |
| **Fractal Design** | 2.4 GHz 接收器或 USB-C 线上的 Scape 耳机 | 来自 Fractal Adjust Pro 网页应用的厂商 `GET_DEVICE_STATE` 查询（用途页 FF00） |
| **Jabra** | 所有使用 GN 协议的 Jabra 耳机（Evolve2 / Evolve3 等），支持自带 USB 线或经由 Jabra Link 接收器；不依赖固定产品 ID 列表，不包含 DECT 底座（Engage、PRO 9xx、GO 6400、Link 400）；直接从耳机读取名称 | 用途页 FF00、用途 05 或 01 上位于 GNP 地址 08（USB）或 04（接收器）的 GNP 状态查询（class 12 / op 02） |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro（`37D7:2401`），2.4 GHz 接收器或 USB；Apex 5（`37D7:2501`），2.4 GHz 接收器或 USB | `FFA0:0001` 上的厂商 HID 信息查询；0–5 电量挡位映射为步进 20% 的 0–100%，含充电状态；无需运行飞智空间站服务 |
| **GameSir** | 2.4 GHz 接收器上的 Nova Lite、Nova 2、Nova 2 Lite；USB 上的 Nova 2 Lite；处于 Xbox (GIP) 模式的 G7 Pro（已测试：绝区零联名版，接收器 `3537:105E`）及其他 GameSir 手柄；Cyclone 2（XInput 模式，接收器或有线）；2.4 GHz 接收器（`3537:1015`）上的 Cyclone Pro（需先在 Windows 中通过蓝牙配对一次手柄） | 厂商设备信息查询（用途页 FF7A）；Xbox 模式下使用 Windows.Gaming.Input 电量报告（真实百分比）；Cyclone 2：厂商电量请求（用途页 FFF0）；Cyclone Pro：通过低功耗蓝牙（服务 `0x8650`）发送 GameSir App 的基础信息请求，每 2 分钟读取一次 |
| **BEITONG** | 2.4 GHz 接收器（`20BC:5128`，XInput 模式，已测试）上的 KP20 / BTP-KP20 以及接收器（`20BC:515C`，XInput 模式）上的 KP40D / BTP-KP40D；无需安装北通游戏厅 | 用途页 `00FF` 上的厂商“get base info”查询（报告 `02`，半字节加扰载荷），含充电状态 |
| **8BitDo** | Ultimate 2 Wireless（已在 2.4 GHz 接收器上测试 X-input `2DC8:310B`；D-input `2DC8:6012` — 按住 B 键开机，需固件 1.03+）、Ultimate 2C Wireless、Ultimate 3-mode、Ultimate 2.4G、Ultimate Bluetooth、Pro 3、Pro 2、SN30 Pro、SF30 Pro | 厂商 HID 状态查询（`FF7A`/`FFA0`）及 SDL 手柄输入报告 `01`/`04`，含充电状态 |
| **Samsung** | Galaxy Buds、Buds+、Buds Live、Buds Pro、Buds2、Buds2 Pro、Buds FE、Buds Core、Buds3 / Buds3 Pro / Buds3 FE（蓝牙） | 只读监听耳机在 Samsung RFCOMM (SPP) 服务上推送的状态帧。托盘显示电量较低的一侧耳机；悬停提示分别列出左耳、右耳与充电盒。须关闭 Galaxy Buds 应用 |
| **Nothing / CMF** | Nothing Ear (3a)（已测试）、Ear (a)、Ear (2)、Ear、CMF Buds（蓝牙） | 在 Nothing 的 NT Link RFCOMM 服务（`aeac4a03-dff5-498f-843a-34487cf133eb`）上执行只读 `0xC007` 电量查询。托盘显示电量较低的一侧耳机；悬停提示列出左耳、右耳与充电盒 |
| **Akko** | Akko Air 01（`3151:5006`，2.4 GHz 接收器，已测试）及 Akko V9 Dash Pro（`38EE:000C`，2.4 GHz 接收器，已测试） | Air 01：荣圆 `0xF7` 状态报告；V9 Dash Pro：`FF1C:0092` 上的只读 64 字节 `0x1A` 状态查询，含充电状态 |
| **MOONDROP** | 2.4 GHz 接收器（`35D8:0133`）上的 GM01 Pro 耳机；接 USB 线时显示最后一次电量并带充电状态 | 报告 `4B` 上的 WalkPlay 厂商读取指令（只读） |
| **VGN** | 2.4 GHz 接收器（`372E:10BB`，已测试）上的 OMNISOUND（昼听）耳机 | V HUB “ZHOU” 查询：在控制集合 `000C:0001`（32 字节输入、64 字节输出报告）上发送载荷为 `65 01` 的输出报告 `55`；应答中返回电量百分比（只读） |
| **JBL** | Quantum 650 Wireless（已测试，2.4 GHz 接收器）；Quantum 520、650X、850、950、950X Wireless（接收器或 USB 线，同一协议，未测试） | 针对电量功能的 JBL “HIDV3” 设备信息查询（用途页 FF12），含充电状态 |
| **JBL** | Quantum 350 Wireless（已在 Windows 上配合 `0ECB:206B` 2.4 GHz 接收器测试）；Quantum 610 Wireless（`0ECB:205C` 2.4 GHz 接收器，Windows 下未测试）；Quantum 360 Wireless（`0ECB:2115` 2.4 GHz 接收器，未测试） | 用于无线连接状态和电量百分比的 HIDV1 特征报告 |
| **Xbox** | 通过 Xbox 无线适配器、USB 或蓝牙连接的手柄；接入控制器的耳机 | Windows.Gaming.Input 电量报告（真实百分比），回退至 XInput |
| **Switch Pro 兼容手柄** | 呈现为 `057E:2009` 的控制器（已测试：处于 Switch 模式下经由 2.4 GHz 接收器连接的 GameSir Tarantula Pro） | 在 Steam Input 或其他主机端开启完整报告后，从 HID 报告 `0x30` 读取 5 级电量 |
| **Apple AirPods / Beats** | AirPods Max（已测试，`200A` Lightning 版和 `201F` USB-C 版）、AirPods Pro 3（已测试，`2027`）、AirPods Pro 1 / 2、AirPods 1–5 以及 Beats 头戴式/入耳式耳机 | 低功耗蓝牙“靠近配对”（`0x07`）广播（AirPods Max 和 Beats 头戴耳机显示单电量；入耳式耳机分别显示左耳、右耳与充电盒，以 10% 为步进并含充电状态），匹配已配对型号 |
| **手机（手机连接 / Phone Link）** | 任何通过 Microsoft 手机连接（Phone Link）经 Wi-Fi 或蓝牙连接的 Android 手机（已测试：Nothing Phone (4a) Pro） | 从手机连接为 Windows 11 开始菜单卡片写入的文件（`StartMenuCompanion.json`）读取电量与充电状态；无需蓝牙 |
| **Darmoshark** | Windows 上 2.4 GHz 接收器连接的 M3（`248A:FF30`）和 M3S（`248A:FF31`） | 用于读取鼠标标识和电量的 HID 特征报告 |
| **Darmoshark** | Nordic 1K 接收器（`1915:0723`）上的 M3S Pro | `FF0A` 集合上的厂商 HID 状态查询 |
| **Alienware** | 2.4 GHz 接收器（`413C:A515`，已测试）上的 AW920H 耳机；蓝牙模式由通用蓝牙行覆盖 | `FF13:0001` 上的厂商查询 `06 C0 0A`，带 XOR 校验和的应答报告 `07`；电量、充电及低电量阈值字段按 Alienware Command Center 的 AW920H 插件解码 |
| **Niceboy** | 2.4 GHz 接收器（`248A:FA02`，已测试）上的 MW400 | 只读报告 `05` 查询 `24 FA 48`；使用厂商软件查表将电池电压映射为 10% 步进电量，含充电标志 |
| **蓝牙** | 任何在 *设置 → 蓝牙和其他设备* 中显示电量的设备（真无线耳机、头戴耳机、BLE 鼠标和键盘）。Google Fast Pair 耳机（已测试 Jabra Elite 8 Active；支持 Pixel Buds 及多款 Sony / JBL / Bose 型号）还可显示左耳、右耳和充电盒电量 | Windows 设备属性；Fast Pair 电量广播（BLE 服务数据 `FE2C`），按蓝牙地址匹配已配对设备 |
| **通用 HID** | 上报标准 HID *Battery Strength* 用途的设备 | HID 用途页 0x06 / 0x85 |
| **HeadsetControl** | [其支持的全部耳机](https://github.com/Sapd/HeadsetControl#supported-headsets)（Audeze、Jabra、Sony INZONE、新款 Logitech 等） | 内置提供；调用 `headsetcontrol -o json` |
| **MAONO PD200W** | 2.4 GHz 接收器（`352F:040E`） | 电量百分比；已实机测试 |


**已在真实硬件上测试：** Glorious Model O Wireless、HyperX Cloud III Wireless、HyperX Cloud Stinger Core Wireless（PlayStation 接收器 `0951:1713`；充电未测试）、HyperX Cloud Core Wireless DTS（接收器 `0951:173F`；满电显示未测试）、HyperX Pulsefire Haste 2 Core Wireless（接收器 `03F0:0AB5`；Haste 2 Wireless 的接收器未测试）、Cooler Master MM712（接收器）、Rapoo VT3 Max Gen 2（接收器 `24AE:1417` 及 USB 线 `24AE:4617`；其他 Rapoo 型号未测试，详见 [Rapoo 协议说明](#sec-rapoo)）、Redragon M916 Pro 1K（接收器 `3554:F55D`）、Taidu TSG808（接收器 `3554:F5D5`）、Redragon M915RGB-WL（接收器 `25A7:FA07`；其他 Areson 型号未测试，详见 [Areson 协议说明](#sec-areson)）、SteelSeries Rival 650 Wireless（接收器 `1038:1726` 及 USB 线 `1038:172B`）、SteelSeries Arctis Nova Pro Wireless（底座 `1038:225D`；电量读取已测试，充电与电源切换未测试）、HECATE G5M PRO（接收器 `35BB:D3FB`）、WLMouse YING Magnesium（8K 接收器 `36A7:A874`）、ATK N9 Ultra（接收器 `373B:1204`）、Corsair Scimitar Elite SE Wireless（Slipstream 接收器 `1B1C:2B00`）、Corsair Dark Core RGB Pro SE（Slipstream 接收器 `1B1C:1BDC`）、Corsair Sabre V2 Pro Ultralight（2.4 GHz 接收器 `1B1C:2B2A`；已验证电量读数）、DAREU EM901X（接收器 `260D:1074`；充电与休眠/唤醒未测试）、配合 Link 390（`0B0E:2E51`）的 Jabra Evolve3 75、MCHOSE G3 V2（接收器 `3837:4245` 及 USB 线 `3837:418C`）、MCHOSE K7 Ultra（接收器 `3837:1001`）、MCHOSE K7 V2 Ultra+（接收器 `3837:1014` 及 USB 线 `3837:4028`；插线时显示充电）、MSI VERSA 300 ELITE WIRELESS（接收器 `0DB0:9E22`；充电与休眠处理未测试）、MSI Clutch GM31 Lightweight Wireless（接收器 `0DB0:0D3C`；GM41 依据机主抓包复用同一驱动）、AJAZZ AK820 MAX（接收器 `05AC:024F`）、AULA HERO 68 Air（8K Wireless Receiver `372E:106C`）、AULA SC580（USB 线 `088D:062E` 及接收器 `089D:062F`，含充电与休眠）、AirPods Pro 3（蓝牙，型号 `2027`）、AirPods Max（蓝牙，型号 `200A`）、Sprime PM1（接收器 `1915:AC1C`）、Ninjutso Ten Air（接收器 `093A:EB01` 及 USB 线 `093A:E020`）、MOONDROP GM01 Pro（接收器 `35D8:0133`）、Delux M800 Pro（接收器 `248A:5B2F`）、Razer Barracuda X (2022)（接收器 `1532:0550`；已读取电量，充电切换未测试）、Razer BlackShark V3 X（HyperSpeed 接收器 `1532:057D`）、Fantech Helios Go XD5（接收器 `25A7:FA7C`）、Fantech Raigor III（接收器 `1EA7:0066`；固件不上报充电状态）、Finalmouse UltralightX（接收器 `361D:0100`）、Finalmouse Starlight X（接收器连接）以及 Chimera V2（接收器 `3554:F512`；已读取电量与充电状态）。
同样已实机测试：Machenike L7 Arctic / L7 Mix（`248A:FF4C` 接收器和 `248A:FF4E` 有线），包括充电以及有线/接收器去重逻辑；蓝牙模式及低电量/满电边界未实机测试。
同样已实机测试：MCHOSE V9 Pro 2（`3837:6011` 接收器）；已读取电量，充电与休眠未测试。
同样已实机测试：`05AC:024F` 2.4 GHz 接收器上的 EPOMAKER EA75，使用来自 [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60) 的现有 SONiX 驱动。已验证电量百分比、接收器重连以及重新开机恢复。该驱动不支持充电指示和有线电量上报；蓝牙电量上报未测试。接入 USB 供电时上报的百分比可能跳至 100%，这并非可靠的充电指示。
同样已实机测试：SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition（接收器 `1038:1878` 及 USB 线 `1038:187A`），包括充电、关机（保持暗淡显示最后电量）以及在 SteelSeries GG 运行时的表现；GG 仅显示三格电量条，且与所读电量一致。
同样已实机测试：RAWM Leviathan V4（RAWM HS Receiver `1915:2346`；已读取电量，充电未测试）。
**根据协议文档及其他项目实现，尚未实机测试：** 其余所有型号，包括 Fantech Raigor II WG10（与已测试的 Raigor III 使用相同的 `1EA7:0066` 接收器和集合，因此应当兼容）。如果你拥有其中某款设备，欢迎通过[提交 Issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues) 反馈实际使用情况。

## 安装

[![最新版本](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. 从[最新发布页面](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)下载 **`BatteryHub-Setup-<version>.exe`**。
2. 运行安装程序，从 19 种支持的安装语言中任选其一，按向导点击即可完成。**无需管理员权限**，也**无需安装任何其他组件**：无需运行时、无需驱动程序、无需厂商软件。HeadsetControl 已随附打包，可直接编辑的 `lang\` 文件夹会安装到 `BatteryHub.exe` 同级目录中。

安装程序会在“开始”菜单创建快捷方式并在（*设置 → 应用*）中注册卸载项，还可设置登录时自动启动。不想使用安装程序？可下载 `BatteryHub-<version>-portable.zip`，解压到任意目录（请保留 `BatteryHub.exe` 旁的 `lang\` 文件夹以使用界面翻译）并运行 `BatteryHub.exe`。

**注意事项：**
- **SmartScreen 警告：** 由于可执行文件未经过代码签名，Windows 可能会提示“Windows 已保护你的电脑”。点击 *更多信息 → 仍要运行*，或自行从源码构建。
- **Windows 11 上的托盘图标模式：** 新出现的托盘图标默认会收进 `^` 溢出区域。可将它们拖回任务栏，或在 *设置 → 个性化 → 任务栏 → 其他系统托盘图标* 中开启显示。
- **让应用忽略特定设备：** 若某个设备在应用运行时出现异常，可在注册表 `HKCU\Software\WirelessBattery` 下新建字符串值 `IgnoreDevices`，按十六进制 `VID:PID` 列出设备，以逗号分隔（例如 `28BD:0947, 1234:ABCD`；可通过 `--dump` 查看 ID）。应用之后便绝不会打开该设备。数位板会自动跳过。

<a id="updates-on-windows"></a>
## Windows 上的更新

官方稳定版 Windows 构建会在后台检查本项目的最新正式稳定版发布：启动 30 秒后检查一次，之后在运行期间每 24 小时检查一次。打开菜单即可看到 **有可用更新：vX.Y.Z...**，也可以自行点击 **检查更新...**。更新信息仅显示在该菜单内：电量图标、百分比和悬停提示均保持不变，自动检查也绝不会弹出通知或对话框。在菜单中取消勾选 **自动检查更新** 可关闭后台检查。

对于通过安装程序安装的版本，点击更新菜单项后再点击 **下载并安装**。若不点击该按钮，绝不会执行任何安装。应用会下载该发布版本的 `SHA256SUMS.txt` 及其签名，使用内置的维护者公钥校验签名，下载 Windows 安装程序，并仅当安装程序的 SHA-256 与签名列表（以及 GitHub 上为该文件列出的校验值）完全匹配时才运行它，随后原地更新现有安装。原有设置和开机启动偏好都会保留，并在安装完成后自动重新打开应用。全局（所有用户）安装可能会请求管理员权限。**发行说明** 会打开官方发布页面；**稍后** 则保留当前版本。便携版则会提供发布页面链接以便手动下载 ZIP 包。

更新检查仅访问 GitHub 的公共 API，无需账号或令牌，且不会发送任何设备或电量信息。断网或触发 GitHub 速率限制时，电量监控仍可正常运行；已发现的发布版本会保留在菜单中，直到被后续成功的检查替代或完成安装。取消下载时会等待当前网络操作在有限超时时间内结束。安装程序绝不会自动重启 Windows。

**为何可放心安装更新：** 签名私钥绝不会上传至 GitHub。维护者在自己的电脑上为每个版本的校验列表签名（见 [docs/releasing.md](#sec-releasing)），因此即使有人接管了 GitHub 账号或其构建工作流，也无法发布一个能被应用接受并安装的更新。没有有效签名的版本虽会在菜单中显示，但只能手动下载。该数字签名不能替代 Windows 自身的 SmartScreen 或 UAC 提示。

首次包含此功能的版本需手动安装一次。开发版/测试版构建会禁用官方更新检查，以防本地改动被意外替换。Linux 版更新与便携版自动替换功能暂未实现。

<a id="command-line"></a>
## 命令行

```
BatteryHub.exe --list     # print every device and its battery level, then exit
BatteryHub.exe --json     # print a JSON array of devices and battery levels, then exit
BatteryHub.exe --dump     # every HID collection, HID devices that could not be opened, all USB devices (also ones
                               # without a HID interface) and Bluetooth devices; also saved to %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # open the "Request support for a device" window
BatteryHub.exe --demo     # sample devices of every brand instead of real ones (screenshots, checking colors)
BatteryHub.exe --quit     # close the running instance
```

Linux 构建使用相同的参数，只需将 `BatteryHub.exe` 替换为 `wireless-battery`，同时还支持 `--help`。`--json` 会输出一个稳定的 JSON 数组，方便脚本和状态栏插件解析：

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` 表示设备休眠期间应用继续显示最后已知电量的保留时长。后续新增字段将保持向后兼容。

**没有显示你的设备？** 右键点击小部件或托盘图标并选择 **请求支持某个设备...**。选中目标设备，确认将要发送的数据（页面会逐字展示发送内容：设备名称、设备类型、USB/HID ID 与接口布局，以及你可选填写的姓名和备注），然后点击 **发送**。它会被提交到 [krisgfx.com/tools](https://krisgfx.com/tools/#requested) 的公开请求列表，并自动新建或更新对应的 GitHub Issue。**复制完整报告** 可将完整的 `--dump` 结果复制到剪贴板，方便粘贴到 Issue 中。报告数据仅在你点击“发送”后才会上传。如[Windows 上的更新](#updates-on-windows)所述，官方 Windows 构建还会访问 GitHub 以检查更新；更新检查不会发送任何设备或电量信息。

<a id="build"></a>
## 构建

需要安装 [MinGW-w64](https://www.mingw-w64.org/)，例如通过 [MSYS2](https://www.msys2.org/) 安装（`pacman -S mingw-w64-x86_64-gcc make`）。

```
make                                      # development build, version 0.0.0
build.bat                                 # plain cmd with g++ and windres on PATH
make VERSION=1.2.3 CHANNEL=test            # versioned build, official updates disabled
build.bat 1.2.3 test                       # equivalent versioned cmd build
make test VERSION=1.2.3 CHANNEL=test       # device and updater regression tests
```

要构建安装程序和便携版 ZIP，请先安装 [Inno Setup](https://jrsoftware.org/isinfo.php)，先按目标版本号完成构建（例如 `make VERSION=1.2.3 CHANNEL=test`），然后运行 `powershell -File installer\build-installer.ps1 -Version 1.2.3`。打包脚本会拒绝与可执行文件版本号不一致的版本参数。打包过程中会自动下载锁定版本的 HeadsetControl 发布包并校验其校验和。GitHub Actions 会自动完成上述全部流程：推送诸如 `v1.0.0` 的标签即可发布包含安装程序、便携版 ZIP 以及 HeadsetControl 源码（遵循其 GPL 许可证要求）的 Release。

Windows 构建还需要 PowerShell 来生成可执行文件与资源共用的版本号信息。官方仓库的版本标签构建会使用 `CHANNEL=stable`；本地构建默认为 `dev`。Fork 仓库和 Pull Request 不会自动开启官方更新通道。

`BatteryHub.exe` 也可单独运行。如果同级目录（或 `PATH`）下没有 `headsetcontrol.exe`，只是会缺少其额外支持的耳机而已。

## Linux（实验性）

项目同时提供与 Windows 应用并行的 Linux 构建。它复用相同的厂商驱动逻辑，底层改为基于 hidraw 的 HID 后端以及 GTK4 StatusNotifierItem 托盘图标；Windows 代码路径保持不变。所有仅限 Linux 的文件均位于 `linux/` 和 `src/linux/`，通过 `build-linux.sh` 构建（Windows 仍使用 `build.bat`）。

| | Fedora | Ubuntu / Debian |
|---|---|---|
| 编译器与 make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

不需要额外的 HID 库（直接使用内核 hidraw）。

```sh
./build-linux.sh
./build-linux.sh test         # unit test for the HID report-descriptor parser
./wireless-battery --list     # print detected levels and exit
./wireless-battery --dump     # list HID collections
./wireless-battery --quit     # close the running tray instance
```

访问 HID 设备需要配置 udev 规则，否则应用虽能启动但无法发现任何设备：

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# log out and back in
```

托盘图标在 KDE Plasma 上原生可用；GNOME 桌面需要安装 AppIndicator 扩展（如 `gnome-shell-extension-appindicator`）。通过 *语言* 子菜单支持多语言切换（默认遵循 `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG`，且同时本地化 `--help` 输出）。运行 `make -f linux/Makefile.linux install` 会将二进制文件、`lang/*.json` 安装至 `$(PREFIX)/share/wireless-battery/lang/`，并将桌面启动器（`linux/wireless-battery.desktop`）与图标（`linux/wireless-battery.svg`）安装至 `$(PREFIX)`（默认为 `~/.local`）；用户自定义语言覆盖文件位于 `~/.config/wireless-battery/lang/`。

第一阶段（Phase 1）涵盖 Logitech、Razer、SteelSeries、Corsair、HyperX、PlayStation、Cooler Master、Glorious、Finalmouse 以及共享的 Kysona/Pulsar/ATK/G-Wolves 协议。蓝牙/UPower 回退、HeadsetControl 以及其余厂商将在后续阶段计划跟进。

## 局限性

- **任务栏拥挤：** 在居中的 Windows 11 任务栏图标非常满时，应用按钮可能会延伸到小部件所在位置。在 Windows 10 上任务栏按钮区域会自动收窄留出空间。
- **手机：** 数据读取自微软手机连接（Phone Link）为开始菜单伴侣卡片写入的文件，这并非公开文档化 API，可能会随手机连接更新而发生变化。仅当手机连接报告手机处于已连接状态时才会显示；超过 3 小时未更新的卡片会以暗淡样式显示。卡片同时记录手机是否在充电，若在充电则会显示充电闪电图标。
- **休眠中的设备：** 处于休眠状态的设备可能无法应答查询。此时最后一次读数会保持显示但呈暗淡状态。Logitech 接收器会将休眠设备从连接中移除，因此其最后读数会保留 30 分钟。
- **HECATE G2 Wireless 7.1 耳机**（2.4 GHz 接收器 `35BB:A009` / `A209`）：目前尚未公开其接收器的电量查询协议，因此无法读取。在 HECATE 官方软件显示耳机电量时抓取 USB 通信数据包（见 CONTRIBUTING.md）是添加支持的方法。
- **Keychron 键盘：** 使用原厂固件时仅支持通过蓝牙上报电量（由蓝牙支持覆盖）。若要在 2.4 GHz 接收器或有线模式下显示电量，需要刷入带有电量补丁的固件（见 [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)）；通过 Keychron Launcher 更新键盘固件会覆盖掉该补丁。Keychron 鼠标已原生支持。
- **Baseus AeQur GH02 耳机：** 2.4 GHz 接收器（`10D6:4802`，Actions 炬芯芯片）仅传输音频、媒体键以及芯片固件升级通道，不包含电量信息。请通过蓝牙连接耳机以查看电量（当 Windows 报告电量时由通用蓝牙支持显示）。
- **Weikav Lucky65 v1 键盘：** 其固件不会通过 2.4 GHz 接收器（`0603:0351`，Novatek 芯片）上报电量。该键盘本身也没有查看电量的快捷键，且官方配置软件仅支持通过 USB 线连接而不支持通过接收器，因此没有可读取的电量数据。
- **Rapoo：** 支持的 VT 系列鼠标采用主动推送状态的方式，因此每次刷新在每个匹配的接口上最多可能等待 4 秒。休眠中的鼠标最多会保持暗淡显示最后一次读数 30 分钟。当前仅支持 Nordic 54L 报告 `07` 及旧版 `BB`（VT3 Pro、VT1 Pro Max）；CH584 报告 `08`、办公 MT/M 系列鼠标以及其他固件协议不在此驱动支持范围内。
- **GameSir Cyclone Pro：** 接收器本身不传输电量，因此电量通过低功耗蓝牙直接向手柄读取。请先在 Windows 中与手柄配对一次（设置 > 蓝牙和其他设备 > 添加设备 > 蓝牙 > `GameSir-Cyclone Pro`），之后仍可继续使用 2.4 GHz 接收器游玩。电脑需具备蓝牙功能。电量每 2 分钟刷新一次，且充电时无法获取电量百分比。未配对时，接收器会显示为电量为“满”的 Xbox 手柄。详情见 [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro)。
- **RAWM：** 鼠标通过接收器进行轮询，因此休眠中的鼠标不会响应；它将暗淡显示最后一次读数最多 30 分钟，且休眠期间每次刷新会多耗时约 1 秒。目前仅在 RAWM HS Receiver（`1915:2346`）上实测了 Leviathan V4；其余型号取自 RAWM HUB 的设备表。Leviathan V4 GT 和 NYX60（VID `373E`，RAWM HUB 3.0）以及 RAWM HS 键盘采用其他协议，暂不支持。
- **Flydigi：** 此驱动针对 Vader 5 Pro 与 Apex 5；蓝牙连接及其他飞智型号（例如 Apex 6）不在覆盖范围内。百分比为粗粒度电量挡位映射。Apex 5 已在真实硬件上验证了 2.4 GHz 接收器与 USB 有线连接；Vader 5 Pro 依据 SDL 及 Windows 硬件抓包实现。
- **尚未支持：** 除 VERSA 300 ELITE 和 CLUTCH GM31 / GM41 之外的 MSI 无线鼠标、MSI 无线键盘、Razer Kraken 耳机以及除 `1532:0550` 上 Barracuda X (2022) 之外的 Barracuda 型号、除 Haste 2 Wireless / Haste 2 Core Wireless 之外的 HyperX Pulsefire 鼠标，以及连接在 Xbox 无线适配器上的 Xbox 无线耳机：它们的电量协议尚未逆向或公开。Xbox 无线耳机在蓝牙模式下可正常使用。由机主抓包一份 USB 数据（见 CONTRIBUTING.md）是添加支持的方法。
- **其他设备：** 部分 2.4 GHz 设备使用了未公开的私有协议，暂时无法支持。如何协助添加支持请参阅 [CONTRIBUTING.md](#sec-contributing)。

## 工作原理

[`src/drivers/`](../../src/drivers) 中的每个厂商驱动通过 USB 厂商 ID 和产品 ID 识别对应设备，并且**仅**发送只读电量查询指令。绝不会向未知设备写入任何数据。通用回退方案（HID 电量用途、蓝牙、XInput、HeadsetControl）仅处理未被任何厂商驱动认领的设备。

任务栏小部件是挂载在 `Shell_TrayWnd` 下的分层子窗口，位于 `TrayNotifyWnd` 左侧。如果资源管理器（Explorer）重启，小部件会自动重新创建。

<a id="translations"></a>
## 翻译

每种应用界面语言都是 [`lang/`](../../lang) 目录下的纯静态 UTF-8 文本文件：等号左侧为英文原文，右侧为译文。语言文件在运行时直接从磁盘加载，而不是编译进可执行文件中，因此你可以直接编辑修改而无需重新编译。

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **应用界面（Windows 与 Linux）：**
  - 直接在 `BatteryHub.exe` 同级的 `lang/` 文件夹中编辑或新增 `.json` 文件（Linux 下为 `/usr/share/wireless-battery/lang/`、`/usr/local/share/wireless-battery/lang/`、`$XDG_DATA_HOME/wireless-battery/lang/` 或 `./lang/`）。
  - 或者在菜单中选择 *语言 → 添加你自己的语言...*，程序会在用户覆盖目录（Windows 下为 `%APPDATA%\WirelessBattery\lang`，Linux 下为 `~/.config/wireless-battery/lang`）中准备好 `_template.json`。将 `_template.json` 复制为例如 `it.json`，填写 `@code`、`@name` 和译文后即可直接出现在菜单中（无需重启）。用户目录中相同 `@code` 的文件会覆盖内置译文。
  - 请保持 `{placeholders}` 原样不变；如为从右向左书写的文字请添加 `"@rtl": true`。留空的条目会自动保持英文显示，因此部分翻译也是完全可用的。
  - `--list` 与 `--dump` 的输出特意保持英文，以便直接粘贴到 GitHub Issue 中。
- **Windows 安装程序：** Inno Setup 翻译存放在 [`installer/lang/`](../../installer/lang)（保存为带 BOM 的 UTF-8），并在 `installer/BatteryHub.iss` 的 `[Languages]` 段中注册。
- **文档：** 每种语言的全部可见项目文档均合并翻译为 [`docs/i18n/`](README.md) 中的单个独立 Markdown 文件（请参阅 [`docs/i18n/_template.md`](_template.md)，无需任何构建脚本即可新增语言）。
- **分享给所有人：** 提交 Pull Request，将你的文件添加到 `lang/`、`installer/lang/`、`linux/wireless-battery.desktop` 和 `docs/i18n/`。完整分步检查清单见 [`docs/i18n/README.md`](README.md)。

## 致谢

应用图标由 [nik-txt](https://github.com/nik-txt) 绘制（[`res/app.svg`](../../res/app.svg)）。

各设备协议源自以下开源项目的研究成果：

- [Google Fast Pair 规范](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification)：Fast Pair 耳机的左耳 / 右耳 / 充电盒电量广播
- [HeadsetControl Astro 驱动](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp)、[eh-fifty](https://github.com/tdryer/eh-fifty) 与 [AstroBar](https://github.com/nichtlegacy/AstroBar)：Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 电量协议；[OpenAstroCC](https://github.com/BenStein1/OpenAstroCC)：A50 Gen 3 `0x72` 状态读取
- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor)（stuffz）：VAXEE 电量及充电指令（[协议文档](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md)）
- [HeadsetControl](https://github.com/Sapd/HeadsetControl)：SteelSeries、Corsair、HyperX、Logitech 及 Sony INZONE 耳机
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray)（kinako19）与 [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray)（takamachi66）：Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer)：Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) 与 Logitech HID++ 2.0 文档：Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) 与 [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery)：Logitech G435（`0ADF` 接收器）
- [rivalcfg](https://github.com/flozz/rivalcfg)：SteelSeries 鼠标（其中 Rival Pro 来自其 PR #294）
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) 与 [glorious-ctl](https://github.com/louis4craft/glorious-ctl)：Glorious
- Hitscan 网页配置器（[control.hitscan.com](https://control.hitscan.com)）：Hitscan
- Linux `hid-kysona`（Lode Willems）：Kysona、Pulsar 与 ATK
- ATK 网页配置器（[hub.atk.pro](https://hub.atk.pro)）：ATK 鼠标以及 N9 Pro / N9 Ultra 耳机
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery)：Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 与 [mouse-battery](https://github.com/qwr79/mouse-battery)：ATK / VXE NK NANO 接收器
- [HaloBattery](https://github.com/HeyOkay/HaloBattery)（MIT）：Audeze Maxwell、NZXT Lift Elite、Poly BT600、Razer Barracuda Pro、SteelSeries Arctis Nova Elite、ATK V75X 与 Endgame Gear XM2we，移植自其各 provider（每个驱动内均标注了来源）
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` 与 [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700)（PaulRichez，MIT）：Turtle Beach Stealth 700 Gen 3；[Neap](https://github.com/lykosapps/Neap)（仅协议发现参考）：Turtle Beach Swarm II 设备家族
- G-Wolves 网页驱动（[mouse.xyz](https://mouse.xyz)）：G-Wolves 型号及其协议
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch)：2.4 GHz 接收器上的 CHERRY 键盘（帧格式与电量查询）
- Keychron Launcher（[launcher.keychron.com](https://launcher.keychron.com)）：Keychron 鼠标
- [NinjaForce](https://www.ninjaforce.co/) 与 [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray)：Ninjutso Ten / Ten Air 特征查询
- [nape_pro](https://github.com/nvalis/nape_pro) 与 [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget)：Link-KM 接收器上的 Keychron Nape Pro
- LAMZU Aurora（[lamzu.net](https://www.lamzu.net)）：LAMZU 鼠标
- [vole](https://github.com/johanneszab/vole) 与 [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator)：Endgame Gear 4K 鼠标
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) 与 [HaloBattery](https://github.com/Waturus/HaloBattery)：WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) 与 [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher)：Finalmouse UltralightX / Starlight X（源自 Finalmouse 的 xpanel）
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) 与 [g49-web-control](https://github.com/pingpingjinping/g49-web-control)：Redragon 设备 ID
- [m913-ctl](https://github.com/Qehbr/m913-ctl) 与 [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray)：Areson `25A7` 帧布局与 `GetPower` 指令
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper)：ASUS ROG；[pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch)：ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) 与 [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray)：ZOWIE EC-CW 与 DW
- RK 网页驱动（[drive.rkgaming.com](https://drive.rkgaming.com)）：Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor)：MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver)（MIT）、[HaloBattery](https://github.com/HeyOkay/HaloBattery)（MIT）、[mchose-macos](https://github.com/Klegus/mchose-macos)（MIT）与 [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol)（文档）：MCHOSE A5 Pro / A5 Pro Max（第一代，VID `2023`）
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6)、[omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900)、[aj179-linux](https://github.com/Rockeyxx/aj179-linux)：Motospeed、Delux、Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery)：Delux M900 Pro 的 CompX 接收器报告
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) 与 [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2)：Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager)、[incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) 与 [MouseBattery](https://github.com/FelixNg21/MouseBattery)：Incott
- Wraith 网页驱动（[w1.software](https://www.w1.software/)）：Wraith W1
- OpenRazer PR #2794 与 [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3)：BlackShark V3
- OpenRazer PR #2862 与 [HaloBattery](https://github.com/HeyOkay/HaloBattery)：BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) 与 [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery)：`1532:0550` 接收器上的 Razer Barracuda X (2022)；[razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray)：`1532:0552` 接收器的帧格式
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899)：BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM)：HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset)：HyperX Cloud III S、Cloud II Core、Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor)：HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray)：荣圆与 Xenta 接收器（Attack Shark 等）
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio)：2.4G 接收器上的 SONiX 键盘（AJAZZ AK820 MAX、AK980 V2、AULA F108 Pro）；[ak820-rs](https://github.com/deddroid/ak820-rs) 与 [ak820-studio](https://github.com/usharik/ak820-studio)：AJAZZ AK820 Pro 接收器 `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) 与 [Kraber](https://github.com/AkashPanja/Kraber)：Attack Shark X98 与 AJAZZ AK820 Max Plus 的 Semico `1A2C`（`AA 55 CC 33` / `0x0E`）状态协议
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) 与 [MM731-Controller](https://github.com/riVFerd/MM731-Controller)：Cooler Master MM712 与 MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) 与 [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection)：GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery)：GameSir Cyclone Pro 低功耗蓝牙“base info”电量请求
- [jabridge](https://github.com/Watchdog0x/jabridge)：Jabra GNP 协议（Link 380 / 390 接收器）
- [xd5-go-web](https://github.com/jarjut/xd5-go-web)：Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery)：`1EA7:0066` 状态页协议（Fantech Raigor III 及其他通用 2.4G Mouse 设备）
- Linux `hid-playstation`：DualShock 4 / DualSense 报告布局
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580)：AULA SC580 / SC580X 厂商协议
- RAWM HUB 网页应用（[rawmtech.com/hub.html](https://www.rawmtech.com/hub.html)，Hub Web 2.0）及其设备表：RAWM 鼠标与 SADES Dagger
- [SDL 的 Flydigi HID 驱动](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) 与 [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191)：Vader 5 Pro 与 Apex 5 查询帧格式和电量布局
- [SDL 的 8BitDo HID 驱动](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c)：8BitDo Ultimate 2 电量字节
- 北通游戏厅（BEITONG iControl，其 KP20 与 KP40D 页面及 KP20 接收器 USB 通信）：BEITONG KP20 / KP40D 电量查询与载荷加扰算法
- [SDL 的 8BitDo HID 驱动](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) 与 [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux)：8BitDo 电量字节与厂商 HID 协议
- JBL QuantumENGINE（其 HIDV3 设备信息消息）：JBL Quantum 耳机
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md)：Corsair Sabre V2 Pro Ultralight，`FF02:0002` 上的 Compx 协议
- [MouseDock](https://github.com/late-autumn-gif/mousedock)（MIT）与 [BrimDeck](https://github.com/MoFeng2223/BrimDeck)：Scyrox V12M 配置文件读取
- JBL QuantumENGINE：Quantum 350 的 HIDV1 连接与电量报告，以及新款 Quantum 耳机的 HIDV3 设备信息消息
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md)：JBL Quantum 610 HIDV1 电量与链路报告，以及 Quantum 产品线（360 为 HIDV1 接收器型号）

## 许可证

[GNU 通用公共许可证 v3.0 或更高版本（GPL-3.0-or-later）](../../LICENSE)。你可以自由使用、修改与再分发本软件，但任何基于本软件分发衍生作品时，必须以同一许可证附带源代码一并发布。


---

<a id="sec-contributing"></a>
> 📄 **章节：** 贡献指南（`CONTRIBUTING.md`） · [英文原文](../../CONTRIBUTING.md) · [↑ 返回顶部](#top)

# 贡献指南

## 报告设备是否正常工作

大多数驱动都是根据协议文档编写的，无法在每一个具体型号上实机测试。提交 Issue 时请附上以下信息：

- 设备名称，以及当前是通过接收器、USB 线还是蓝牙连接
- `BatteryHub.exe --list` 的输出
- `BatteryHub.exe --dump` 的输出
- 厂商官方软件所显示的电量

## 添加设备支持

1. 运行 `BatteryHub.exe --dump`，找出你的设备的厂商 ID（VID）和产品 ID（PID），以及厂商自定义 HID 集合（用途页 `FFxx`）及其报告长度。
2. 查找电量协议。可以参考这些项目：HeadsetControl、OpenRazer、Solaar、rivalcfg、OpenRGB、OpenLinkHub，或者使用 Wireshark + USBPcap 对官方软件进行 USB 抓包分析。
3. 如果 `src/drivers/` 中已有该厂商的驱动，则在其中添加新的产品 ID（及协议差异处理）。否则新建 `src/drivers/<vendor>.cpp`：

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

4. 在 `src/drivers/drivers.h` 中声明该函数，并在 `src/devices.cpp` 的 `PollAllDevices()` 中调用（需放在通用回退逻辑之前）。`build.bat` 和 Makefile 会自动包含新增的源文件。
5. 更新 `README.md` 中的设备支持表格。

### 驱动编写规则

- **只读操作：** 仅发送读取状态的请求。绝不修改设置、灯效或工作模式。
- **精确匹配：** 仅与通过厂商和产品 ID 明确识别的设备通信，或匹配该协议独有的厂商专用集合。
- **始终设置超时：** 离线设备绝对不能阻塞轮询超过约 1 秒。被动监听协议可能需要更长时间以覆盖已知的推送间隔（例如 Delux 和 Rapoo）。每个匹配集合只保留一个最多 4 秒的绝对截止时间，不要因为收到无关报告而重置超时，并在注释中说明需要例外的理由。
- **注明来源：** 在文件顶部注释中注明协议的出处。

## 翻译

应用界面语言是以纯静态 UTF-8 文本文件的形式存放在 `lang/` 目录中，在 Windows 和 Linux 上均于运行时从磁盘加载（将 `lang/_template.json` 复制为 `lang/<code>.json`，填写 `@code`、`@name` 和译文即可，无需重新编译）。代码中新增界面文本时必须使用 `T(L"...")`，若包含动态参数则使用 `TF(L"... {name} ...", { { L"name", value } })`；切勿将多段译文拼接成句子。新增短语后，也请同步添加到 `lang/_template.json`。

Windows 安装程序翻译位于 `installer/lang/*.isl`（以带 BOM 的 UTF-8 保存并在 `installer/BatteryHub.iss` 中注册），Linux 桌面启动器注释位于 `linux/wireless-battery.desktop`，完整文档翻译则位于 `docs/i18n/<code>.md`（从 `docs/i18n/_template.md` 复制得到的单文件文档）。完整贡献步骤请参见 [`docs/i18n/README.md`](README.md)。

## 代码风格

使用 C++17 和纯 Win32 API，不引入第三方依赖，保持二进制体积小巧。代码格式尽量与现有代码保持一致（4 空格缩进，行宽约 120 列）。

## Windows 更新器开发

更新器仅支持 Windows，使用 WinHTTP、BCrypt 以及现有的 Inno Setup 安装程序。更新状态只允许显示在菜单中。请勿添加更新角标、徽章、改动电量悬停提示、气泡通知、Toast 弹窗或自动弹出对话框。设备轮询与网络操作分开独立运行。

构建版本号和发布通道通过生成的 `build/version.h` 在 C++ 代码和 Windows 资源之间共享。本地测试请使用 `make VERSION=1.2.3 CHANNEL=test` 或 `build.bat 1.2.3 test`；默认为 `dev`，只有 `stable` 才会启用官方发布检查。版本号各段必须在 `0..65535` 范围内。仅官方仓库的发布标签工作流会自动选择 `stable`。切勿意外让 Fork 构建启用官方更新通道。

运行 `make test VERSION=1.2.3 CHANNEL=test` 可执行现有设备测试以及严格的版本解析、版本排序、检查调度、真实 SHA-256 文件校验、参数引用转义和辅助程序保护检查。更新器回归测试还涵盖下载完成时取消、对话框防重入以及配置 HTTP 超时/重定向限制失败的场景。Windows 测试遵循现有 Linux 后端测试模式直接包含实现源码，并替换 HTTP 发送逻辑以确保测试不会实际连接 GitHub。生产代码中不添加任何仅限测试的控制器入口。单项测试目标为 `make test-update-core` 和 `make test-update-win`。原生更新器测试会链接应用程序资源以启用 Common Controls v6。所有测试仅使用本地数据，不会执行下载、提权、安装或修改用户的开机启动设置。应用在生产环境使用的端点无法在测试中被覆盖。

打包前请运行：
`powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`。
`installer/build-installer.ps1 -Version 1.2.3` 在下载依赖项前也会自动运行此检查。
使用 `/WBUPDATE=1` 参数运行安装程序时会保留原有的开机启动项和设置，并将重新启动应用交由临时辅助进程完成。该辅助进程保持在原用户权限下运行，仅全局安装程序本身会触发提权。WinHTTP 句柄归工作线程所有；取消操作通过在有限超时的调用之间协作完成。应用程序最终退出时会等待该工作线程结束（join），因此可能需要等待正在进行中的网络调用超时。

发布评审时，请使用临时 Windows 账户或虚拟机，完整演练两个真实安装包版本、当前用户/所有用户安装范围、取消 UAC、开机启动开关、自定义安装路径、安装失败以及重启拉起流程。单元测试与编译打包本身无法验证这些安装程序实际效果。菜单/主题的视觉检查以及真实安装器/UAC 端到端验证仍属于手动发布卡点；除非亲眼实测通过，否则不要标记为已通过。绝不要在日常主力用户的安装环境中直接覆盖测试。

## 自动安全检查

每个 Pull Request 都会经过“PR safety check”扫描，检测本应用绝对不应包含的行为（如网络访问、启动外部程序、读取键盘/剪贴板/屏幕、自启项、二进制文件、构建或发布脚本改动）。被标记并不代表拒绝：只需在 PR 描述中解释标出的代码行即可。

使用 AI 工具辅助开发是可以的，但请从提交信息（commit message）中移除致谢 AI 工具的 `Co-authored-by` 行（例如 `Co-authored-by: Claude ...`）。如果存在此类行，自动检查将无法通过。


---

<a id="sec-pr-template"></a>
> 📄 **章节：** Pull Request 模板（`.github/pull_request_template.md`） · [英文原文](../../.github/pull_request_template.md) · [↑ 返回顶部](#top)

## 本次 PR 新增内容

<!-- 设备名称以及厂商/产品 ID，例如 "Acme M1 (1234:5678)"。 -->

## 协议来源

<!-- 贴出参考来源链接（其他开源项目、厂商网页驱动或你自己的 USB 抓包）。 -->

## 是否在真实硬件上测试？

<!-- 是（具体设备型号，--list 的输出结果）/ 否 -->

## 检查清单

- [ ] 仅发送只读电量查询指令；未修改任何设置、灯效或固件
- [ ] 仅访问通过厂商/产品 ID（或协议专属集合）识别的设备
- [ ] 无网络访问、未启动其他程序、未在 `src/`、`docs/` 或 `README.md` 之外新增文件
- [ ] 未包含任何二进制文件或生成产物
- [ ] 提交信息中不包含致谢 AI 工具（Claude、Copilot、ChatGPT 等）的 `Co-authored-by` 行
- [ ] 上方已说明对 `.github/`、`installer/`、`build.bat` 或 `Makefile` 的改动（如有）


---

<a id="sec-releasing"></a>
> 📄 **章节：** 发布与签名指南（`docs/releasing.md`） · [英文原文](../../docs/releasing.md) · [↑ 返回顶部](#top)

# 发布流程

本应用从 GitHub Releases 自动更新，但只会安装其 SHA-256 位于已用发布密钥签名的 `SHA256SUMS.txt` 中的安装程序。该签名私钥仅保存在维护者的本地电脑中，绝不上传至 GitHub：即使有人攻破了 GitHub 账号、令牌或工作流并发布了恶意文件，也无法伪造出一个能被应用接受的签名。

## 一次性操作：创建发布密钥

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- 脚本会要求输入密码（至少 12 个字符），并将加密后的私钥写入 `%USERPROFILE%\.wirelessbattery\release-key.wbk`。
- 自动将公钥写入 `src\update_public_key.h`。请提交该文件。若该文件中没有公钥，官方构建会拒绝编译。
- **请务必备份密钥文件并妥善保存密码**（密码管理器是保管两者的理想选择）。如果任意一项丢失，已安装的应用将无法再自动更新：你只能创建新密钥，并让所有用户手动下载安装一次新版本。

## 每次发布

1. 推送版本标签（`git tag v1.2.3 && git push origin v1.2.3`）。CI 会自动构建安装程序、便携版 ZIP 以及 `SHA256SUMS.txt`，并创建 Release。
2. 对校验和列表进行签名：

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   脚本会从 Release 下载 `SHA256SUMS.txt`、展示内容并请你确认、要求输入密钥密码，随后生成 `SHA256SUMS.txt.sig`。如果你在 `dist\` 目录中有同一版本的本地构建产物，它还会比对两者是否一致。
3. 将 `SHA256SUMS.txt.sig` 上传到 Release（脚本会自动打开编辑页面）。上传后应用便会提供 **下载并安装** 选项；在此之前，应用虽会提示有新版本，但仅提供跳转到发布页面的链接。

请仅为你亲自发布的 Release 列表签名。签名意味着“这些精确文件就是本次发布”，因此签名环节正是拦截恶意篡改上传的关键防线。

## 更换密钥

带一个新的 `-KeyFile` 参数运行 `new-release-key.ps1`：它会将新公钥添加到 `src\update_public_key.h` 中旧公钥的旁边。先用旧密钥签名发布一个同时包含新旧两个公钥的版本，再从下一个版本起改用新密钥签名，并在之后移除旧公钥。如果旧密钥已丢失或泄露，则不能用这种方式平滑过渡：必须直接从头文件中删除旧公钥，老版本用户需要手动安装一次下一版发布包。

## 应用在运行安装程序前执行的检查

- 该发布版本必须是仓库的最新正式版本，不能是草稿（draft）或预发布版本（prerelease），且版本号高于当前应用。
- `SHA256SUMS.txt.sig` 必须是 `SHA256SUMS.txt` 经由 `src\update_public_key.h` 中某个公钥验证通过的有效 ECDSA P-256 签名（基于 Windows BCrypt，无任何第三方加密库）。
- 已签名的列表中必须恰好包含一次 `BatteryHub-Setup-<version>.exe`，且其 SHA-256 与 GitHub 为该文件报告的校验值一致。
- 下载完成的安装程序文件大小与 SHA-256 必须完全匹配。随后应用副本会在启动安装程序前再次进行核验，并锁定文件防止在此期间被替换。
- 下载仅允许通过 HTTPS 访问 `github.com`、`objects.githubusercontent.com` 和 `release-assets.githubusercontent.com`，且每一次重定向都会经过校验。


---

<a id="sec-keychron-firmware"></a>
> 📄 **章节：** Keychron 键盘固件（`docs/keychron_keyboard_firmware/README.md`） · [英文原文](../../docs/keychron_keyboard_firmware/README.md) · [↑ 返回顶部](#top)

# 通过 2.4 GHz 接收器读取 Keychron 键盘电量

Keychron 原厂固件仅支持通过蓝牙上报键盘电量。应用 [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch) 中的少量 QMK 修改后，键盘也能通过 Keychron Link 接收器以及 USB 线响应电量查询（`A4`），BatteryHub 即可显示其电量百分比、电压和充电状态。

已在 **Keychron K5 Max ANSI RGB**（`3434:0A50`）搭配 Keychron Link 接收器（`3434:D030`）上实机测试。

## 补丁修改内容

基于 [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) 的 `2025q3` 分支（提交 `57e682c`）：

- 添加源自 [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1) 的 `KC_GET_BATTERY`（`0xA4`）原始 HID 指令：
  应答格式 `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`；
- 将通过无线链路收到的原始 HID 请求同样交给该处理函数；
- 在 `keyboards/keychron/k5_max/config.h` 中定义：`#define WILRESS_RAW_ENABLE`（Keychron 原厂代码中拼写即为如此）以及 `#define KC_BATTERY_MODEL_ID 0`。

其余功能均无变化：键位映射、背光灯效以及 Keychron Launcher 均可正常使用。

## 方式 1：刷写现成的 K5 Max 固件

仅适用于 **K5 Max ANSI RGB** 的预编译固件附在[此发布页面](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)中（`k5_max_ansi_rgb_battery.bin`，SHA256 为 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`）。切勿刷入其他型号或配列的键盘。

## 方式 2：自行编译

需要 Git 与 Docker（或者配置好的 [QMK 编译环境](https://docs.qmk.fm/newbs_getting_started)）。

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

编译产物为仓库根目录下的 `keychron_k5_max_ansi_rgb_keychron.bin`。在 Windows 上，Docker 挂载宿主机目录读写会非常慢；直接在容器内（或 WSL 中）克隆并编译会快得多。

**其他 Keychron 无线键盘**（`2025q3` 代码树中启用了 `LK_WIRELESS_ENABLE` 的 Q/V/K Max 等型号）：`keyboards/keychron/common/` 下的修改可直接通用。只需将那两行 `#define` 添加到对应键盘自己的 `config.h` 中（而不是 K5 Max 的），然后编译你自己的目标即可，例如 `make keychron/<model>/<layout>/<variant>:keychron`。目前应用会根据型号将 K5 Max（`0A50`–`0A58`）显示为具体型号，其余型号显示为“Keychron keyboard”。

## 刷写方法

1. 将键盘模式开关拨至 **Cable**（有线）并拔下 USB 线。
2. 按住 **Esc** 键的同时重新插入 USB 线，键盘即进入 STM32 Bootloader 模式。
3. 使用 [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)（或 `dfu-util`）刷入 `.bin` 文件。
4. 将开关拨回 **2.4 GHz**，运行 `BatteryHub.exe --list` 验证：
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`。

通过 Keychron Launcher 更新固件会覆盖此补丁并使 2.4 GHz 电量上报失效。如需还原，按相同步骤刷回 Keychron 官方固件即可。

## 许可证

QMK 采用 GPL-2.0-or-later 许可证，本补丁遵循同一许可证。任何收到基于本补丁构建的二进制文件的人，也必须能够获取对应的源码修改。


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **章节：** GameSir Cyclone Pro（`docs/gamesir_cyclone_pro.md`） · [英文原文](../../docs/gamesir_cyclone_pro.md) · [↑ 返回顶部](#top)

# GameSir Cyclone Pro 电量支持

## 为何手柄原本会显示为满电 Xbox 手柄

Cyclone Pro（型号 T4cp）通过 2.4 GHz 接收器 `3537:1015` 连接游玩。该接收器在 Windows 中伪装成一个有线 Xbox 360 手柄（XUSB，`Xbox 360 Controller for Windows`）。XInput 对其电量查询固定返回“Full”，因此不管实际剩余电量是多少，XInput 回退逻辑都会将其列为 100% 的 `Xbox controller 1`。

该接收器本身不携带任何电量信息：
- 它唯一的 HID 集合就是 XInput 游戏控制器（`HID\VID_3537&PID_1015&IG_00`）
- 它不像 Nova（`FF7A`）或 Cyclone 2（`FFF0`）那样拥有厂商自定义集合

## 电量数据位于何处

当手柄通过接收器游玩时，它同时会以 `GameSir-Cyclone Pro` 的名称进行低功耗蓝牙（BLE）广播，这正是小鸡手机 App 所使用的链路。其“get base info”请求会返回电量：

| 步骤 | 详情 |
|---|---|
| 服务 | `0x8650`（`00008650-0000-1000-8000-00805f9b34fb`） |
| 特征 | `0x865F`（notify，write without response） |
| 请求 | 启用通知，写入 `01 01` |
| 应答 | 19 字节通知（部分固件版本会在前面加 `C9` 前缀，共 20 字节） |

应答数据布局：

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

第 18 字节即为电量百分比（0–100），充电时则为 `FF`。充电期间不上报具体百分比，因此界面保留上次已知百分比并显示充电闪电图标。

手柄还包含服务 `0xFF10`，那是 GameSir 的固件升级通道，本驱动绝不会打开它。手柄没有标准 Battery Service（`0x180F`），这就是 Windows 蓝牙设置页和通用蓝牙回退均无法显示其电量的原因。

协议来源：[GameSirBattery](https://github.com/bpbp-boop/GameSirBattery)，该协议逆向自 GameSir Android 应用（`BluetoothLeService` 中的“get base info”）。

## 驱动工作原理

`src/drivers/gamesir_ble.cpp` 在 XInput 回退逻辑之前调用：

1. **查找手柄：** 枚举类 GUID 为 `{00008650-0000-1000-8000-00805F9B34FB}` 的设备接口。Windows 会为已配对 BLE 设备的每个 GATT 服务创建一个接口。驱动仅采用父节点 `BTHLE\DEV_…` 名称以 `GameSir-Cyclone…` 开头的接口。
2. **读取电量：** 使用 Win32 GATT API（`bluetoothleapis.h`，`-lbluetoothapis`）打开该服务，订阅 `0x865F` 并写入 `01 01`。最多等待 3 秒接收应答，随后关闭通知订阅。
3. **保持轮询流畅：** BLE 连接建立可能需要数秒，手柄休眠时还会超时，因此查询放在独立线程中运行：
   - 成功读取后最多每 2 分钟查询一次；失败后每 1 分钟重试一次
   - 轮询直接返回缓存的读数；一旦缓存超过 6 分钟未更新则停止返回
   - 之后由 `graceSec` 将其保留为暗淡的休眠状态显示
   - 仅程序启动后的第一次轮询会等待该后台线程完成（最多 4 秒绝对截止时间），从而确保刚启动时和 `--list` 时都能显示电量
4. **隐藏虚假的 Xbox 条目：** 检测到接收器存在时，驱动会认领 `3537:1015`：
   - Windows.Gaming.Input 路径现在会跳过已被认领的厂商/产品 ID
   - XInput 路径通过 `XInputGetCapabilitiesEx`（xinput1_4 序号 108）获取每个槽位的厂商/产品 ID，并跳过已被认领的设备
   - 若系统中缺少该导出函数，XInput 按原有方式运行

## 已测试硬件

2026-11-18 在 Windows 11 上测试 Cyclone Pro 搭配接收器（`3537:1015`），通过蓝牙配对一次后：

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

手柄进入休眠后，原本的“Xbox controller 1 / Full”条目不再出现，手柄条目也正常随休眠逻辑处理。

## 局限性

- **需要配对：** 必须先在 Windows 中与手柄配对一次（设置 > 蓝牙和其他设备 > 添加设备 > 蓝牙 > `GameSir-Cyclone Pro`）。未配对的手柄没有 GATT 设备接口。配对后系统会新增蓝牙手柄条目，但通过 2.4 GHz 接收器游玩时蓝牙通道不会发送按键输入。
- **需要蓝牙：** 电脑必须支持低功耗蓝牙（Bluetooth LE）。
- **单手柄限制：** 每台电脑仅读取一台 Cyclone Pro。
- **充电状态：** 充电时不提供具体电量百分比。


---

<a id="sec-localization-guide"></a>
> 📄 **章节：** 多语言使用与本地化指南（`docs/i18n/README.md`） · [英文原文](../../docs/i18n/README.md) · [↑ 返回顶部](#top)

# BatteryHub 多语言索引与本地化指南

仓库中所有可见文档均按**每种语言一个独立 Markdown 文件**的形式收集在 `docs/i18n/` 中；全部运行时应用程序界面字符串均存放在 [`lang/`](../../lang) 下的**静态可编辑文本文件**中（Windows 与 Linux 共用）；Windows 安装程序文本则存放在 [`installer/lang/`](../../installer/lang) 中。

## 支持的语言（19 种）

| 代码 | 语言 | 完整文档 | 应用界面（Windows 与 Linux） | Windows 安装程序 |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json)（源字符串） | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## 语言切换的实际工作机制

### 1. Windows 应用（`BatteryHub.exe`）
- **自动检测：** 当设置为 *语言 → 自动（Windows 语言）* 时，BatteryHub 会调用 Windows 的 `GetUserPreferredUILanguages` 并匹配最接近的静态 `*.json` 文件。
- **手动切换：** 点击任务栏小部件或托盘图标 → **语言** → 选择目标语言。界面立即刷新并将选择保存在 `HKCU\Software\WirelessBattery\Language`。
- **静态外部文件（修改无需重新编译）：** `BatteryHub.exe` 会先加载 `<exe>\lang\*.json`，再加载 `%APPDATA%\WirelessBattery\lang\*.json`。用户目录中具有相同 `@code` 的文件会覆盖对应短语，每次重新打开菜单都会从磁盘实时重载语言文件。
- **命令行 `--help`：** `BatteryHub.exe --help` 会以当前启用的界面语言显示帮助弹窗（`--list`、`--json` 和 `--dump` 刻意保持英文，以便直接提交至 GitHub Issue）。

### 2. Linux 应用（`wireless-battery`）
- **自动检测：** 按顺序遵循 POSIX 区域环境变量：`LANGUAGE`（冒号分隔列表）→ `LC_ALL` → `LC_MESSAGES` → `LANG`（除非被 `LC_ALL=C` / `POSIX` 覆盖）。
- **手动切换：** 右键托盘图标 → **语言** → 选择 **自动（系统语言）** 或任意已安装的语言。选择会保存在 `$XDG_CONFIG_HOME/wireless-battery/config.ini`（默认 `~/.config/wireless-battery/config.ini`）的 `[general] language=` 键下。
- **静态搜索路径（优先级从低到高）：**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/`（默认 `~/.local/share/wireless-battery/lang/`）
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/`（默认 `~/.config/wireless-battery/lang/`）
- **命令行 `--help`：** `wireless-battery --help` 根据 `config.ini` 或系统区域设置输出本地化后的帮助信息；`--list` 和 `--dump` 保持英文。

### 3. Windows 安装程序（`BatteryHub-Setup-<version>.exe`）
- 启动时弹出语言选择框（`ShowLanguageDialog=yes`），并根据用户的 Windows 界面语言预先选中默认项（`LanguageDetectionMethod=uilanguage`）。
- 将完整的静态 `lang\*.json` 目录安装到 `BatteryHub.exe` 旁的 `{app}\lang\` 中（便携版 ZIP 同样附带 `lang\*.json`）。

---

## 如何添加或更新一种语言（分步指南）

翻译应用界面或文档**不需要**任何编译工具；仅当你想自行试编 Windows 安装程序时才需要安装 Inno Setup 6。

### 第 1 步 — 应用界面文本（`lang/<code>.json`）
1. 通过托盘菜单打开用户语言文件夹（**语言 → 添加你自己的语言...**），或将 [`lang/_template.json`](../../lang/_template.json) 复制为 `lang/<code>.json`（例如 `lang/it.json`）。
2. 填写文件头部的元数据：
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. 在每行的 ` = ` 右侧填写译文。
   - 原样保留占位符，如 `{name}`、`{percent}`、`{version}`、`{days}`、`{hours}`、`{rate}`、`{count}`、`{monitor}`、`{number}`、`{seconds}`、`{minutes}`、`{page}`、`{reason}`、`{code}`。
   - 使用 `\n` 表示显式换行。
   - 保存为 **UTF-8（无 BOM）**。
   - 重新打开 BatteryHub 托盘菜单即可即时预览——无需重新编译！

### 第 2 步 — Windows 安装程序（`installer/lang/<code>.isl`）
1. 将 [`installer/lang/_template.isl`](../../installer/lang/_template.isl) 复制为 `installer/lang/<code>.isl`。
2. **关键要求：** 请务必将文件保存为 **带 BOM 的 UTF-8（`EF BB BF`）**，以便无论旧版 Windows 系统代码页为何，Inno Setup 都能正确解码 Unicode 字符。
3. 根据情况选择对应方式：
   - **Inno Setup 已内置你的语言**（检查 `C:\Program Files (x86)\Inno Setup 6\Languages\`）：只需保留 `[CustomMessages]` 并翻译这 6 行（`AutostartTask`、`LaunchApp`、`SupportProject`、`CloseFailed`、`DirNotWritableAdmin`、`DirNotWritableUser`，保留 `%1` 和 `%n`）。在 `installer/BatteryHub.iss` 的 `[Languages]` 段中注册：
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup 未内置你的语言**：以 `installer/lang/zh-CN.isl` 作为完整参考模板进行复制，设置 `[LangOptions]`（`LanguageName`、`LanguageID`、`LanguageCodePage=0`，如需要可加 `RightToLeft=yes`），翻译 `[Messages]` 与 `[CustomMessages]`，并紧跟在 `Default.isl` 之后注册：
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - 注意：`[Languages]` 中的 `Name:` 标识符只能包含 ASCII 字母、数字和下划线（应写 `ptBR`，而非 `pt-BR`）。

### 第 3 步 — Linux 桌面启动器（`linux/wireless-battery.desktop`）
添加本地化的 `Comment[<code>]=...` 行（`.desktop` 文件中的区域标签请使用下划线，例如 `Comment[zh_CN]=...`）。

### 第 4 步 — 完整单文件文档（`docs/i18n/<code>.md`）
1. 将 [`docs/i18n/_template.md`](_template.md) 复制为 `docs/i18n/<code>.md`（无需任何生成脚本——只需这一个文件！）。
2. 完整翻译目录及全部 17 个章节，并保持以下内容原样不变：
   - 所有 `<a id="sec-..."></a>` 与 `<a id="top"></a>` 锚点标签
   - 所有代码块、CLI 参数（`--list`、`--json`、`--dump`、`--report`、`--demo`、`--quit`、`--help`）、USB `VID:PID`、HID 用途页、十六进制数据包、注册表键名、文件路径与 URL
   - 相对路径的图片与文件链接（`../screenshot.png`、`../keychron_keyboard_firmware/k5_max_battery.patch`、`../../LICENSE` 等）
3. 更新 `docs/i18n/<code>.md` 顶部的 `<!-- lang-switcher:start -->` 导航栏（将当前语言加粗，其余语言保留链接），并将你的语言链接同步添加到 `README.md`、`CONTRIBUTING.md`、`docs/*.md`、`docs/keychron_keyboard_firmware/README.md`、`docs/i18n/README.md` 以及同级 `docs/i18n/*.md` 文件的语言切换栏中。
4. 对于从右向左书写的语言（`ar`、`fa`、`he`），请直接编写标准 Markdown，不要用 `<div dir="rtl">` 包裹整个文件，以便表格和代码块正常渲染。


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **章节：** ARDOR GAMING Fury V2（`docs/ardor_fury_v2.md`） · [英文原文](../../docs/ardor_fury_v2.md) · [↑ 返回顶部](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

该 2.4 GHz 接收器暴露了 HID 用途页 `000A`、用途 `0000` 以及一个 5 字节的输入报告。它采用被动广播机制，无需发送任何 HID 指令。

在真实硬件上观测到的报告如下：

| 报告 | 电量 |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

第 3 字节的高半字节编码了电量挡位（`1`、`3`、`7`、`F` 分别对应 25%、50%、75% 和 100%）。25% 和 100% 对应的报告值由厂商应用程序的解码逻辑推断得出；随后终端用户在实际构建的应用中确认其余电量挡位均能正确显示。第 5 字节并非固定常量，因此不作为特征签名校验。

监听逻辑要求连续收到两帧解码结果一致的电量挡位，而不要求整个报告字节完全相同。最后确认的电量值最多保留 45 秒。全局自动刷新间隔切换为 15 秒。

已由终端用户在 Windows 上通过 ARDOR Fury V2 与 Logitech G733 实机验证：包含 50% 与 75% 抓包、周期性自动更新、25%/100% 界面显示核验以及便携版启动运行。25% 与 100% 的原始数据包未单独抓包。


---

<a id="sec-areson"></a>
> 📄 **章节：** Areson `25A7`（`docs/areson.md`） · [英文原文](../../docs/areson.md) · [↑ 返回顶部](#top)

# Areson 25A7 接收器电量支持

## 为何原程序未能识别该鼠标

Redragon M915RGB-WL 通过 Areson/CompX `25A7:FA07` “2.4G Wireless Receiver”连接。由于它走的是私有 2.4 GHz 链路，其电量既未通过标准 HID *Battery Strength* 用途暴露，Windows 也没有对应的蓝牙电池属性。该鼠标改为响应主动发送的 `GetPower` 请求，因此通用 HID 回退和蓝牙回退都看不到它。此前又没有该厂商的驱动，导致接收器一直处于未被认领且静默的状态。

## 实测硬件与数据包

2026-11-17 在 Windows 11 上配合 Redragon M915RGB-WL 实测：

| 方向 | VID:PID | 接口 | 用途页:用途 | 报告长度 |
|---|---|---|---|---|
| 请求（特征） | `25A7:FA07` | 1 | `FF02:0002` | 17 字节 |
| 应答（输入） | `25A7:FA07` | 1 | `FF01:0000` | 17 字节 |

应答到达的顶级集合（top-level collection）与写入请求的集合不同。在 Windows 上它们分别是 `MI_01&COL07`（特征）和 `MI_01&COL05`（输入），因此驱动需要同时打开这两个句柄。

抓取到的请求（`GetPower`，报告 ID `08`，指令 `04`，校验和使整帧所有字节之和等于 `0x55`）：

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

抓取到的应答：

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

下方偏移量以报告 ID 作为第 0 字节计算：

| 字节 | 含义 | 示例 |
|---|---|---|
| 0 | 应答报告 ID | `09` |
| 1 | 指令回显 | `04` |
| 2 | 状态，0 = 成功 | `00` |
| 3–4 | 地址，对于 `GetPower` 未使用 | `00 00` |
| 5 | 数据长度（2） | `02` |
| 6 | 电量等级，0–10，步进 10% | `08` = 80% |
| 7 | 充电标志，任意非零值 | `00` = 未充电 |
| 16 | 校验和；全部 17 个字节之和（模 256）等于 `0x55` | `3E` |

同一帧数据下官方软件显示为 80%，由此确认了 ×10 的换算比例。同时 `GetConnectStatus`（`08 03 …`）以 1 字节载荷应答并报告鼠标已连接。

## 其他 Areson 鼠标

Redragon M693 所使用的较老 `FA7B` / `FA7C` 接收器在相同应答偏移量处直接上报完整百分比。若将本驱动的 ×10 换算套用到它们身上会显示 800%，因此刻意不认领这些产品 ID。本驱动仅处理 `FA07` 和 `FA08`；`FA08` 为同一系列的备用 ID，暂未在本机验证。

## 轮询与设备标识

- 驱动仅发送只读的 `GetPower` 请求，绝不写入配置、灯效或 DPI 数据。
- 每次刷新时以零访问权限打开特征集合、以读权限打开输入集合，发送请求并最多等待 1.8 秒接收应答，共尝试两次，并在两次尝试之间清空队列，以防把旧的滞留报告误认为当前应答。
- 读取失败时不会认领设备，因此鼠标休眠时界面会保留上一次电量值。条目采用与其他被动驱动一致的 30 分钟宽限期。
- 设备键由厂商与产品 ID 派生（`areson:25A7:FA07`），因此在接收/休眠周期及重新插拔接收器后仍能保持一致。

## 验证情况

使用 MSVC C++17 与 Windows SDK 完整编译应用并在真实鼠标上运行。`BatteryHub.exe --list` 返回：

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

读数与当时 Redragon 官方软件显示的百分比完全一致。MinGW 的 `build.bat` 已包含新源文件；`Makefile` 则通过通配符自动发现。

## 协议来源

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl)：从 Redragon 软件的 USB 抓包中还原的 17 字节帧、特征/输入分离集合及 `0x55` 校验规则。
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray)：`25A7:FA07` 上的 `GetPower` 指令及 10% 电量刻度。
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md)：应答布局以及 `FA7B` / `FA7C` 系列不同的百分比刻度。


---

<a id="sec-darkrim"></a>
> 📄 **章节：** DARKRIM SHADOW（`docs/darkrim.md`） · [英文原文](../../docs/darkrim.md) · [↑ 返回顶部](#top)

# DARKRIM SHADOW / 寸渊影弑接收器

已在 `3654:6901`（制造商 `Jieli Technology`，版本号 `0100`）上实机测试。使用接口 **3**、用途 `FF02:0002`、无编号 64 字节输入/输出载荷（Windows HID 报告长度为 65 字节）。接口 4 同样具有 `FF02:0002`，但它使用报告 ID 2 且不响应此协议，因此被刻意排除。

协议来源：官方 [PC Hub 下载页](https://app.darkrim.net/hub/zh.html) 提供的 `DARKRIM-0.1.26-x64-setup.rar`，下载后直接静态解包，未安装或启动厂商软件。提取出的 `DARKRIM.exe` SHA-256 为：
`f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`。

该可执行文件中的关键地址：

- `140124C80`：`sendGetBasicInfo(infoType)` 发送指令 `0010`、Request `01`、载荷 `[infoType, 00]`。电量选择器为 `01`。
- `140118D30`、`140119200`：帧头与 CRC 生成。
- `140126DB0`：设备信息 TLV 解析器；TLV `01` 即为电量。
- `1400F5660`、`1400FA700`：电量消费端；低 7 位给出百分比，最高位为充电标志。同一电量值也会随 `0011` Notify `03` 到达。

帧头格式：`FE seq cmdLE type index count lengthLE`，其后跟随载荷及 CRC-16/CCITT-FALSE（多项式 `1021`，初始值 `FFFF`，大端序存储）。序列号为非零的 4 位计数器；未使用加密。

实际请求/应答载荷（尚未做 HID 零填充）：

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

应答 TLV `01 01 28` 解析为 **40%，未充电**。在未运行厂商软件的情况下，生产版 C++ 驱动连续三次查询均稳定返回该值。接收器会在匹配应答之前发出启动通知，实测耗时约 406 ms。请使用单一 800 ms 应答截止时间（外加最多 200 ms 用于写入），且不要在收到无关通知时重置截止时间。无需发送心跳包。

驱动仅发送电量 GET 请求。它只接受满足以下条件的未加密应答：序列号/指令/类型匹配、索引为 0、计数为 0 或 1（硬件使用 0）、长度与 CRC 有效，且仅包含单个格式正确的电量 TLV。分片包、主动推送、畸形包以及越界应答均予忽略。

## 实测电量精度与充电状态

请将该百分比视为**粗略估计值，而非经验证的 1% 精度电量计**。机主的设备在充电过程中以 10 个百分点为步进从 40% 上升至 90%。在 90% 时，五次电量 GET 应答与一次主动通知均携带 `DA`：`DA & 7F = 90`，第 7 位表示正在充电。机主拔掉充电线继续通过 2.4 GHz 接收器使用后，接下来的五次 GET 应答与一次通知均携带 `5A`：依然为 90%，此时充电位已清零。全部十二帧均通过 CRC 校验。

典型查询应答（序列号 4）：

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

驱动与官方应用均直接从低 7 位提取百分比。驱动不会四舍五入到整十、不会将挡位乘以十，也不会插值推算中间值；构造 47% 和 95% 的测试报告在生产解析器中仍保持为 47% 和 95%。因此，观测到的粗粒度读数来源于解析器上游的耳机/接收器自身上报。目前尚未观测到更精细的硬件读数，也未记录完整的放电曲线，因此尚无法确认在所有放电阶段或其他固件上是否固定为 10% 步进。

90% 电量下的充电状态及随后的未充电状态已通过硬件核验。低电量/满电边界、耳机关机行为、蓝牙及 USB 有线数据模式尚未实机测试，不对这些模式作支持声明。本实现不包含任何固件升级、配置修改、EQ 指令、配对更改、重置操作或厂商二进制文件。

测试：`g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`。


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **章节：** HyperX Pulsefire Haste 2 Wireless（`docs/hyperx_haste_2.md`） · [英文原文](../../docs/hyperx_haste_2.md) · [↑ 返回顶部](#top)

# HyperX Pulsefire Haste 2 Wireless 电量协议

由 `src/drivers/hyperx.cpp` 中的 `HasteWireless` 读取。查询指令来自 [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli)，与 NGENUITY 所使用的协议一致。

已在真实硬件上验证：

- Pulsefire Haste 2 Core Wireless，接收器 `03F0:0AB5`。
- Pulsefire Haste 2 Wireless，接收器 `03F0:0F98`，由 uzumakiprime 验证（PR #312）。所读电量与 HyperX NGENUITY 一致。

`03F0:0D97` 接收器预计采用相同方式工作，但尚未实测。

## HID 集合

| 字段 | 数值（`0F98`） |
|---|---|
| USB 接口 | `MI_02`（接口 2） |
| 用途页 : 用途 | `FF00:0001` |
| 输入 / 输出 / 特征报告长度 | 64 / 64 / 64 字节 |

该接收器同时暴露标准鼠标与消费者控制集合。驱动仅打开输入报告长度至少为 8 字节的厂商集合（用途页 `FF00` 或更高）。

## 查询指令

两者均为输出报告：前两个字节如下，其余部分补零至报告长度。每条应答均为输入报告，首字节等于请求指令加 1。每次查询最多等待 1 秒接收应答，并跳过无关报告（重连后接收器会自行发送 `44 xx`、`45 xx` 和 `FB xx` 报告）。

| 请求 | 应答 | 含义 |
|---|---|---|
| `52 01` | `53 01 <linked>` | 当鼠标关闭或超出范围时 `linked` = 0 |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 为 0–100；`charge` 1 = 充电中，2 = 在充电器上已充满；电压单位为 mV，小端序（Core 版上为 0） |

- 如果缺少连接状态应答，则由电量应答决定结果。
- 如果连接状态报告为 0，则不再发送电量查询，鼠标显示为已关闭。
- 鼠标刚开机后的几秒内会上报约 40%。链路刚建立后 6 秒内的读数会被忽略，托盘保留上一次电量值。

两条请求均只读取状态，不会修改任何设置、灯效或模式。


---

<a id="sec-inphic"></a>
> 📄 **章节：** Inphic IN10（`docs/inphic.md`） · [英文原文](../../docs/inphic.md) · [↑ 返回顶部](#top)

# Inphic IN10 系列，KP 8K 接收器

接入的设备由机主确认为 IN10 MAX，系统枚举为 `Inphic KP 8K`、`1D57:FA65`、版本号 `0116`。其状态集合为接口 2、用途 `000A:0000`、输入长度 5（含报告 ID `03`）。

无需发送任何请求，约每 4 秒可观测到一次上报：

```text
03 73 41 01 64
```

现有的 Xenta 解析器可识别此格式：型号、事件、电池状态、百分比。需要连续收到两帧相等的报告才会显示 100%；在同类接收器上，刚连接后的第一帧报告可能是误报满电的假读数。此修改保留了该保护机制以及现有的充电/休眠处理逻辑。

官方 [Inphic HUB](https://hub.inphic.cn/) 前端包 `assets/index-BcHQx9B6.js` 将十进制型号 115（`73`）映射为 `IN10RMax`，将 116（`74`）映射为 `IN10Max`，并使用电池状态 1 表示百分比、2 表示充满、3 表示充电中。应优先采用固件上报的型号名称，而不是硬把 `73` 指定为 IN10 MAX 从而误标共用同一接收器的其他型号设备。

本次改动之前，应用将接入的鼠标显示为 `Wireless mouse`。Xenta 传输层其实已经能够解析其电量帧，本次改动补充了缺失的型号名称。冷启动执行 `--list` 时可能会显示为休眠状态，因为初始 5 秒的观测窗口内可能只赶上收到一帧约每 4 秒一次的报告。常驻后台的应用会保留监听句柄，并在后续轮询中确认读数。

已实机验证：被动报告、连续 100% 电量确认以及原生驱动型号识别。充电状态切换、低电量边界、蓝牙与有线模式尚未实机验证。型号 `74` 取自官方配置表，未在独立硬件上测试。


---

<a id="sec-machenike"></a>
> 📄 **章节：** Machenike L7（`docs/machenike.md`） · [英文原文](../../docs/machenike.md) · [↑ 返回顶部](#top)

# Machenike L7 Arctic / L7 Mix

已在标识为 **L7 Mix** 的 L7 Arctic 上实机验证：

| 连接方式 | VID:PID | 接口 | 用途 | 输入 / 输出 / 最大特征长度 |
| --- | --- | --- | --- | --- |
| 2.4 GHz 接收器 | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB 线 | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

驱动同时会校验 HID 产品名称 `L7 Mix`。其他机械师型号、不同接收器 ID 以及蓝牙厂商查询均未启用。

## 协议来源

对[厂商驱动页面](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/)提供的官方 **Machenike L7 Mix 1.0.0.8** 软件进行互操作分析，并在真实鼠标上执行只读查询验证。`DeviceDriver.exe` 的 SHA-256 为：
`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`。

在该 32 位可执行文件中（镜像基址 `00400000`），函数虚拟地址 `00436750` 构造状态请求；`004494F0` 通过 `HidD_SetFeature` 发送该请求并读取特征应答。状态解析器 `00410C20` 提取下方字段并将电量与充电字段传给 UI。这些均为虚拟地址（VA），而非文件偏移量。本仓库不包含任何专有可执行文件、应用代码或资源。

## 读取状态查询

发送 **21 字节**，报告 ID `51`，指令 `06`，其余字节全为零：

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

读取特征报告 `51`，同样使用 21 字节。该集合的最大特征报告长度 1001 是为其他报告准备的，并非状态报告的长度。驱动在发送后等待 10 ms 再读取，并对每个产品使用单一的 200 ms 截止时间（涵盖期间收到的无关应答）。驱动绝不发送任何设置、模式、宏或固件指令。

下表索引包含报告 ID：

| 字节 | 含义 / 实测值 |
| --- | --- |
| 0–1 | `51 06`，必需的指令回显 |
| 4–7 | `8A 24 4E FF`，已验证的 L7 设备签名 |
| 10，位 0–2 | 工作模式：接收器上为 1，有线为 0 |
| 10，位 3 | 无线鼠标已连接；在 USB 线连接时该位也为 0 |
| 11 | 电量百分比，0–100（0 为有效值） |
| 12 | 充电标志：0 放电中，1 充电中 |

其余字段与校验和语义尚未确定。驱动不会臆造校验逻辑，而是会在发布读数前严格校验指令、长度、设备签名、工作模式以及连接状态下的电量/充电取值范围。

抓取到的接收器应答（当时官方应用亦显示 64%）：

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

抓取到的 USB 线充电中应答（74%）：

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

此时接收器仍会返回其缓存的 64%，但会将连接位清零：

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

这种已断开读数绝不能暴露缓存的电量/充电状态。当两种传输路径同时存在时，有线连接优先，且跨连接方式共用同一个稳定的设备键。即使查询失败，已识别的 L7 也会被保留认领，以防止后续的 Ajazz 驱动在共用 VID 上用其他协议对其探测。

## 验证边界

单元测试夹具与模拟传输测试覆盖了抓包读数、充电、有效的 0%/100%、断开连接的接收器、畸形/陈旧应答、严格匹配、传输失败、去重以及有界重试循环。这些测试并不代表已覆盖真实设备上的 0%/100% 及所有休眠/固件变体。


---

<a id="sec-nuphy"></a>
> 📄 **章节：** NuPhy WH80（`docs/nuphy.md`） · [英文原文](../../docs/nuphy.md) · [↑ 返回顶部](#top)

# NuPhy WH80（USB 线与蓝牙）

已在硬件 `19F5:A011`（固件版本 `0116`，接口 1，用途 `0001:0000`，无编号 64 字节输入/输出载荷，Windows HID 能力报告中为 65 字节）上实测。

协议来源：[NuPhyIO](https://drive.nuphy.io/)，脚本包 `main.b3fb29e0.js`，SDK 方法 `getBatteryState(0)`、`getDataPackage` 与 `createCommand`。仅请求 `GetFunc`（`05`）、偏移量 `0020`、长度 `01`。不需要任何初始化、配置、灯效或固件指令。

请求载荷（补零至 64 字节）：

```text
55 05 00 21 01 20 00 00
```

实际应答载荷：

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

第 3 字节为第 4..63 字节之和的低字节。第 8 字节为电量：`value & 7F` 为百分比，`value & 80` 为 SDK 充电标志。原生 C++ 驱动在接入的键盘上返回了 **100%，充电中**。充电切换以及低电量/满电边界尚未实机测试；官方固件说明指出 WH80 读数以 10% 为增量变化。接收器模式不在本驱动覆盖范围内。

## 蓝牙

在蓝牙模式下，同一把键盘使用 HID ID `19F5:324A`（版本号 `0129`），并广播诸如 `NuPhy WH80 - 1` 的用户可见名称。它会暴露两个键盘集合和一个鼠标集合。由于通用 HID 启发式规则优先判定鼠标，因此将该蓝牙 ID 精确加入了现有的键盘覆写列表。

蓝牙电量报告继续使用 Windows 蓝牙电池属性。拔掉 USB 线后，Windows 在所连键盘上报告 **95%**。直接向键盘执行一次未缓存的标准 GATT Battery Level（`180F` / `2A19`）读取也同样返回 **95%**。这是独立于有线 100% 观测值的设备/传输读数；请勿将其替换为假定满电值或进行重新缩放。不同传输模式下固件读数存在差异的具体原因尚不明确。

驱动严格校验产品 ID、接口、报告长度、应答帧头、偏移量、长度、校验和及百分比范围。它使用 400 ms 应答截止时间，并在该时间内忽略无关应答。

回归测试：

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **章节：** Rapoo（`docs/rapoo.md`） · [英文原文](../../docs/rapoo.md) · [↑ 返回顶部](#top)

# Rapoo 鼠标电量支持

## 为何原程序未能识别该鼠标

`PollAllDevices()` 在每次刷新时枚举 Windows HID 顶级集合。每个厂商驱动识别对应协议、添加一条 `DeviceStatus`，并认领其 VID/PID，以免通用驱动重复添加。UI 本身已经处理了百分比、充电状态以及休眠期间保留最后读数的逻辑。

原本没有 Rapoo 驱动。VT3 Max Gen 2 通过厂商自定义的输入报告发送电量，而不是标准 HID Battery Strength 用途或 Windows 蓝牙电池属性，因此现有的通用 HID/蓝牙回退无法解码其 USB 接收器。

## 实测硬件与数据包

2026-11-16 在 Windows 上使用机主的 VT3 Max Gen 2 实测：

| 连接方式 | VID:PID | 接口 | 用途页:用途 | 输入 / 输出长度 |
|---|---|---|---|---|
| 2.4 GHz 接收器 | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 字节 |
| USB 线 | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 字节 |

两者均标识为 `Rapoo Gaming Device`。其余集合包括标准鼠标、键盘、媒体控制输入、厂商配置集合以及一个 513 字节的固件接口。电量驱动仅打开具有已识别输入长度的 `FF00:0002`，绝不会打开固件接口，也绝不发送任何输出报告、特征报告、握手或配置指令。

抓取到的无线报告（包含报告 ID）：

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

抓取到的有线/充电报告：

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

下方偏移量以报告 ID 作为第 0 字节计算，与本项目的 `HidDev::Read()` 一致：

| 字节 | 含义 | 示例 |
|---|---|---|
| 0 | 报告 ID | `07` |
| 1 低半字节 | 连接方式：0 接收器，1 蓝牙，2 有线 | `20` / `22` |
| 1 高半字节 | 传感器信息；不属于连接类型 | `2` |
| 2 | 当前 DPI 挡位 | `03` |
| 3–4、5–6 | X/Y DPI，小端序 | `0320` = 800 |
| 7 | 电池状态：0 无效，1 放电中，2 充电中 | `01` / `02` |
| 8 | 电量百分比，0–100 | `19` = 25% |
| 13–14 | 鼠标产品 ID（存在时），小端序 | `4617` |

实时接收器抓包报告为 `25%`，完整应用随后在有线连接下返回 `27%, charging`。解析器测试已收录该真实无线抓包。充电与有线连通性同样在真实硬件上得到验证，并非仅仅根据 USB 设备接入来推断。机主拔下 USB 线并重新接回接收器后，最终可执行文件在 `2.4 GHz receiver` 下返回了 `52%`，充电标志清除，并保持同一 `rapoo:4617` 设备键。这也从真实硬件上验证了从有线到接收器的切换过渡。

2026-11-17 还在 Windows 上使用 **VT9 Gen 2** 进行了实测：

| 连接方式 | VID:PID | 接口 | 用途页:用途 | 输入 / 输出长度 |
|---|---|---|---|---|
| 2.4 GHz 接收器 | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 字节 |
| USB 线 | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 字节 |

VT9 Gen 2 接收器暴露的是 **16 字节**的 `FF00:0002` 报告而非 19 字节，但仍采用完全相同的 Nordic 54L `07` 布局（包括位于第 13–14 字节的内嵌 `4614` PID）。抓取到的帧如下：

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

在 USB 线连接下，可观测到交互（例如切换 DPI）时上报状态报告；当插线状态下将底部电源开关拨至 OFF 时，鼠标上报 `state=2, percent=1`，而非实际电池百分比。

### 采用 13 字节集合的 VT3 Max Gen 2 接收器（issue #1396）

针对同一接收器 ID `24AE:1417` 的一篇设备请求表单报告显示了另一种接口布局：`FF00:0002` 为 **13 / 13** 字节（而非 19 字节），`FF00:000E` 为 33 / 33 字节，且没有 513 字节固件集合。这看起来属于另一版本接收器固件。当时 Rapoo 官方软件仍能正常显示电量，而本驱动忽略了一个本可正常工作的状态通道。

Rapoo Hub 的 `VT_nrf54L` 解码器（`py`）是长度自适应的：它始终读取 DPI、电池状态和百分比，仅当报告足够长时才读取后续字段（如位于 `n[12..13]` 的鼠标 PID、RF 信息等）。VT3 MAX 清单（`productId: [17943, 5143]`）并没有特殊输入报告类型，因此在该接收器上报告 `07` 同样经过此解码器。13 字节报告（ID 加 12 字节）在第 7 字节仍带有电池状态、在第 8 字节仍带有百分比，只是缺少了内嵌的鼠标 PID，因此读数回退使用接收器 PID 并保持 `rapoo:4617` 键。

13 字节长度**仅对 `24AE:1417` 接受**。帧数据仍须通过完全相同的校验（报告 `07`、连接半字节 0–2、状态 1/2、百分比 0–100）。目前尚未抓到实机的 13 字节帧；测试中使用的是将已测 19 字节抓包截断为 13 字节的数据。

## 其他 Rapoo 鼠标

官方 Rapoo Hub 将这套 `07` 布局用于其 Nordic 54L 鼠标驱动。其清单列出了 VT0、VT1、VT2、VT3、VT3S、VT7、VT9 及更多衍生型号。检查当前脚本包发现共有 69 个使用 `VT_nrf54L` 的 VT 变体；这仅证明它们共享同一协议，而不意味着已做过 69 次实机验证或覆盖了 Rapoo 几乎全部产品线。驱动按 Rapoo VID、专用集合、输入长度及有效状态报告进行匹配，因此采用同协议但未显式列出的型号依然可以上报电量。小型名称表覆盖了常见型号；其余型号保留其 HID 产品名称或显示 `Rapoo wireless mouse`。

产品名称与 ID 会随代数和地区而变化。已实测的 `1417/4617` 配对在当前官方清单中被称为 `VT3 MAX`，机主将其识别为 VT3 Max Gen 2。当前清单中另有一款 `VT3 MAX V2` 使用 ID `1B06/4B06`。不得仅以社区表中将 `1417` 归为 VT9 Pro 的记录作为命名或识别该设备的依据。

此前针对 VT3 Pro（`1215/4415`）记录的旧版 VT 固件则会在同一 `FF00:0002` 用途上推送 7 字节报告：

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

对于这种旧格式，状态 1/2 分别表示放电/充电。充电时百分比为 `7F` 表示未知，并保留为未知状态。过渡状态 0、无关的 `BC` 报告、畸形数据包以及超过 100 的百分比均予忽略。旧格式已有自动化测试覆盖，但尚未在本地用真实旧版鼠标验证。该解析逻辑严格限定于产品 ID `1215/4415`（VT3 Pro）、`1233/4433`（VT1 Pro Max）及其 7 字节输入集合。

VT1 Pro Max（接收器 `24AE:1233`，有线 `24AE:4433`，鼠标固件 222，接收器固件 213）是根据机主在 issue #136 附上的 USBPcap 抓包添加的。`--dump` 输出在接口 1 上列出了 7 字节 `FF00:0002` 集合，抓包显示其在 Rapoo 软件未发送请求的情况下主动推送：

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

在有线模式下，16 秒抓包中仅观测到一次该报告，因此纯有线读取在部分刷新周期内可能会超时；接收器则会定期持续推送。Nordic 配置文件绝不会去解析 `BB` 数据包。

这**并不**代表支持所有 Rapoo 设备。例如 VT1 SE、VT7 SE 等 CH584 型号在官方驱动中使用报告 `08`，不被本解码器支持。其他 Telink 硬件版本对 `BB` 标志位也有不同解释，部分办公型号使用主动电量查询，而蓝牙型号可能仅暴露 Windows 电池属性。这些设备仍交由现有回退处理，或需要单独经过验证的实现，切勿向它们发送猜测性的查询指令。

## 轮询与设备标识

- 读取为被动模式。匹配的 `FF00:0002` 句柄会在多次轮询之间保持打开（与 `PollXenta` 一致），以便 Windows 缓冲在 60 秒刷新间隔期间到达的状态帧；每次轮询先清空已排队的帧（保留最新有效电量读数），仅在首次打开或队列为空时才回退至最多 5 秒等待。拔出设备时将其移除并关闭句柄。无关数据包不会重置截止时间。
- 内嵌鼠标 PID（或旧版设备已知的有线/接收器配对）确保切换有线和无线连接时使用同一 UI 键。有线与接收器读数会合并为单一条目：优先采用有线状态，若此时有线端上报未知电量则保留有效的接收器百分比。
- 超时不会臆造百分比或认领设备。成功读取一次后，现有 UI 可在静默期间将其保持暗淡显示最长 30 分钟。
- 程序现有的基于 VID/PID 的身份模型无法区分多只同型号 ID 的相同鼠标。同时插入有线与接收器的物理场景未实机测试；两路输入的合并逻辑已由模拟传输测试覆盖。

## 验证

`make test` 会运行跨平台解码器测试以及使用模拟 HID 应答的 Windows 驱动测试。测试覆盖了真实抓包、0% 与 100%、充电、缺失电量、无效/截断帧、不支持的集合/厂商、协议配置文件隔离、超时、稳定设备键以及在不丢失已知百分比前提下的有线/接收器去重。

已本地使用 MSVC C++17 与 Windows SDK 完整编译应用，并在真实鼠标上运行了 `--list` / `--dump`。保持维护的 MinGW 构建已在 `build.bat` 中包含 `rapoo.cpp`；Makefile 会自动发现该文件。测试环境中未安装 MinGW 本身。

## 协议来源

- [官方 Rapoo Hub](https://hub.rapoo.cn/)，2026-11-16 检查：内置 [JavaScript 驱动与清单](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js)。相关解码函数为对应 `VT_nrf54L` 的 `py`/`Hk` 以及用于连接和电池状态语义的 `qM`/`QM`。独立的 `VT_CH584` 处理函数消费报告 `08`，不在本实现范围内。混淆压缩后的符号名在未来版本中可能会变化。
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs)：提供旧版 VT3 Pro 报告、充电状态及未知电量哨兵值参考。
- Issue #136 USBPcap 抓包（接收器及有线充电时的 VT1 Pro Max）。
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js)：独立印证了被动 `07` 状态广播与电量偏移量。其解析器会对越界百分比做限幅处理；本实现改为直接拒绝无效值。


---

<a id="sec-rawm"></a>
> 📄 **章节：** RAWM（`docs/rawm.md`） · [英文原文](../../docs/rawm.md) · [↑ 返回顶部](#top)

# RAWM 协议说明

RAWM 鼠标（以及共用同一平台的 SADES Dagger）通过厂商 HID 集合 `FF00:0001` 与 RAWM HUB 应用通信，使用 64 字节无编号输入和输出报告（含报告 ID 共 65 字节）。接收器与鼠标均采用 Nordic 的厂商 ID `1915`。

来源：RAWM HUB 网页应用 Hub Web 2.0（<https://www.rawmtech.com/hub.html>）及其脚本 `https://hub.miracletek.net/hub/js/library.min.js`（经过混淆；下方函数和常量名均出自该脚本自身）。所支持的产品 ID 源自该应用下载的设备列表（`https://www.miracletek.net/game/device.php`）。Leviathan V4 GT 和 NYX60 使用基于 VID `373E` 的 Hub Web 3.0，属于不同协议。

## 数据包格式

每条报告的第 0 字节（位于报告 ID 之后）：

| 高位比特 | 含义 |
|---|---|
| `0x80`（`PACKET_TYPE_EVENT_DATA`） | 低 6 位为载荷长度；载荷续接事件字节流 |
| `0x40`（`PACKET_TYPE_BUFFER_SIZE`） | 流控（空闲缓冲区大小）；此处忽略 |
| `0xC0`（`PACKET_TYPE_EXTENDED`） | 低 6 位为 ESB 通道号；报告其余部分为该通道的数据包。接收器背后的鼠标固定在通道 0 |

这些载荷构成事件字节流：

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## 读取电量

驱动复现应用在连接接收器时的查询流程（`send_event_query`、`send_event_ping`）：

1. 发往接收器：`00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>`（`CMD_QUERY`，OS = PC），随后轮询发送 ping `00 84 0E 04 00 00`。仅当主机持续写入时设备才会发送数据，因此主机必须发送 ping。接收器返回 `CMD_QUERY_RESULT`（`02`）及 JSON，例如：
   `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`。
2. 对通道 0 发送相同的查询与 ping，前缀加上 `C0`。鼠标通过 30 字节 ESB 分片返回一个约 550 字节的 JSON 对象，例如 `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`。`battery` 为百分比（RAWM HUB 原样显示），`chr` 为 1 表示充电中。
3. 后续状态变化以 `CMD_NOTIFY`（`0B`）类型 `17` 到达：`[17, percent, charging]`。

驱动按照官方应用的方式始终先询问接收器（在一次测试中，直接发往通道 0 的查询未收到应答）。处于休眠状态的鼠标完全不响应，但接收器仍会正常响应。

查询中携带电脑时钟是因为官方应用如此发送；除此之外不写入任何其他内容。鼠标报告 `"crc":1`，这指示应用对后续指令（如配置写入）包裹 CRC-16 帧；而在得知该字段前发送的查询和 ping 无需 CRC 即可被接收。

已在搭配 RAWM HS Receiver `1915:2346`（固件 2.0.2）的 Leviathan V4（固件 1.2.0）上实测。


---

<a id="sec-vaxee"></a>
> 📄 **章节：** VAXEE（`docs/vaxee.md`） · [英文原文](../../docs/vaxee.md) · [↑ 返回顶部](#top)

# VAXEE 4K/8K 接收器与 ZYGEN NP-01S V2

## 适用范围与硬件验证

本驱动支持 VAXEE 4K 接收器 `3057:1002`、VAXEE 8K 接收器 `3057:2002` 以及通过 USB 线连接的 ZYGEN NP-01S V2 Wireless（`3057:1011`），基于其厂商集合 `FF05:0001` 的 64 字节特征报告。其他 VAXEE 接收器、其他有线产品 ID 以及 ZOWIE 设备均刻意不予探测。

8K 接收器（`VAXEE 8K Wireless`，配对 NP-01 Ergo Wireless 8K）已在 Windows 上实测并通过相同协议正常上报：

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

所有 VAXEE 8K 鼠标共用这颗接收器，且接收器不上报当前配对了哪款鼠标，因此显示为接收器自身名称。8K 接收器上的充电状态尚未在硬件上观测。

真实 4K 接收器已在 Windows 上测试：

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

集成后的主程序同样报告：

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

随后同一只鼠标直接通过 USB 线连接，Windows 将其识别为 `ZYGEN NP-01S V2 Wireless`（`3057:1011`）。更新后的生产驱动报告：

```
VAXEE battery: 75%; charging: yes
```

任务栏小部件在首个接收器版本构建中即成功创建。电池供电下的接收器工作状态与有线充电状态均已实机观测；满电切换与休眠/关机行为尚未在硬件上测试。充电解码与无效响应由模拟应答测试覆盖。

## 协议

来源：[stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md)。

请求为一个补零的 64 字节 HID 特征报告：

| 字节 | 取值 |
|---|---|
| 0 | `0E`，报告 ID |
| 1 | `A5`，帧头 |
| 2 | `0B` 表示读取电量；`10` 表示读取充电状态 |
| 3 | `01`，读取标志（绝不使用 `02` 写入） |
| 4 | `01`，数据长度 |
| 5–63 | `00` |

使用 `HidD_SetFeature` 发送请求后，等待 100 ms 并通过 `HidD_GetFeature` 读取报告 `0E`。要求返回至少 6 字节，且报告 ID、帧头、指令回显和数据长度均符合预期。

对于电量查询，应答第 5 字节必须在 0–20 之间，乘以 5 即得到步进为 5% 的 0–100% 电量。对于充电查询，第 5 字节非零表示正在充电。充电查询失败不会丢弃本来有效的电量读数。

驱动会对电量请求重试一次。每个匹配集合最多执行三次读取请求（两次电量尝试和一次充电查询），累计显式延时 300 ms。绝不发送任何设置、配对、固件或灯效指令。

如果未收到有效电量应答，驱动不上报任何状态且不认领该设备。只要该 USB 集合仍然存在，UI 会沿用现有宽限期机制将此前成功的读数保留暗淡显示最多 30 分钟。一旦物理集合消失，驱动会发出一次已断开状态以立即结束该宽限期。这可避免拔下接收器改用有线插鼠标时，旧的接收器图标仍滞留在界面上。

## 测试

`make test` 包含 `tests/vaxee_driver_test.cpp`，将生产驱动链接至模拟 HID 传输层运行测试。测试检查了精确的只读请求帧、百分比换算、充电状态解码、无效与缺失应答、已被认领设备以及精确集合过滤。
