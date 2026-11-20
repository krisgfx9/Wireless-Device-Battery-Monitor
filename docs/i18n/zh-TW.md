<!--
  BatteryHub 繁體中文完整文件（翻譯自 docs/i18n/_template.md）
  本獨立 Markdown 檔案彙整了儲存庫中的所有可見文件。
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **語言：** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | **繁體中文** | [新增語言](README.md)
<!-- lang-switcher:end -->

# BatteryHub — 完整文件

> 這份獨立的 Markdown 檔案彙整了儲存庫中的所有可見文件，因此譯者只需維護**每種語言一份檔案**。

## 目錄

1. [BatteryHub 概覽、支援裝置、安裝、命令列與建置（`README.md`）](#sec-readme)
2. [貢獻指南（`CONTRIBUTING.md`）](#sec-contributing)
3. [Pull Request 範本（`.github/pull_request_template.md`）](#sec-pr-template)
4. [發佈與簽署指南（`docs/releasing.md`）](#sec-releasing)
5. [Keychron 鍵盤 2.4 GHz 韌體修補程式（`docs/keychron_keyboard_firmware/README.md`）](#sec-keychron-firmware)
6. [GameSir Cyclone Pro 藍牙低功耗支援（`docs/gamesir_cyclone_pro.md`）](#sec-gamesir-cyclone-pro)
7. [多語言使用與在地化指南（`docs/i18n/README.md`）](#sec-localization-guide)
8. [ARDOR GAMING Fury V2（`docs/ardor_fury_v2.md`）](#sec-ardor-fury-v2)
9. [Areson 25A7 接收器（`docs/areson.md`）](#sec-areson)
10. [DARKRIM SHADOW 接收器（`docs/darkrim.md`）](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless（`docs/hyperx_haste_2.md`）](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K 接收器（`docs/inphic.md`）](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix（`docs/machenike.md`）](#sec-machenike)
14. [NuPhy WH80（`docs/nuphy.md`）](#sec-nuphy)
15. [Rapoo 滑鼠電量支援（`docs/rapoo.md`）](#sec-rapoo)
16. [RAWM 通訊協定說明（`docs/rawm.md`）](#sec-rawm)
17. [VAXEE 4K/8K 接收器（`docs/vaxee.md`）](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **章節：** BatteryHub 概覽（`README.md`） · [英文原文](../../README.md) · [↑ 返回頂端](#top)

# BatteryHub

*原名為 **Wireless Battery**。1.1.0 版已重新命名此應用程式；更新時會保留您的設定、開機啟動選擇與電量歷史。*

[![在 Ko-fi 上支持我](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![透過 PayPal 贊助](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![加入我們的 Discord](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![在 GitHub 上給我們一顆星](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![分享到 Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![回報裝置](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![協助翻譯](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

直接在 Windows 工作列上顯示您的無線滑鼠、耳機、鍵盤與遊戲手把的電量。

![工作列上的 BatteryHub](../screenshot.png)

> **只想直接安裝使用？** 從最新版本下載 **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)**，執行並依步驟點擊安裝即可。
>
> **進階使用者** 可以下載可攜版 ZIP、使用[命令列選項](#命令列)，或透過 `make` 或 `build.bat` [從原始碼建置](#建置)。
>
> **喜歡這個工具嗎？** BatteryHub 是免費且開源的軟體。如果它幫您省下了開啟原廠軟體的麻煩，歡迎在 [Ko-fi](https://ko-fi.com/krisgfx)、[PayPal](https://www.paypal.com/paypalme/krisgfx) 或 [GitHub Sponsors](https://github.com/sponsors/krisgfx9) 支持我們，這能幫助我在求學期間繼續維持應用程式免費。無法贊助嗎？給一顆 ⭐ 星、分享給朋友，或使用 `--dump` 回報尚未支援的裝置，也同樣非常有幫助。

- **極致輕巧**：檔案約 350 KB，僅佔用約 2 MB 記憶體。採用純 C++/Win32 開發，無需執行環境、無背景服務，且無需系統管理員權限即可在數秒內完成安裝。
- **無需原廠軟體**：程式直接與裝置通訊。G HUB、Synapse、iCUE、GG 和 NGenuity 都可以保持關閉（或是同時執行，彼此不會衝突）。
- **支援眾多品牌**：Logitech、Razer、SteelSeries、Corsair、HyperX、Glorious、Jabra、JBL、PlayStation 與 Xbox 控制器、Samsung Galaxy Buds、任何 Windows 能偵測到電量的藍牙裝置，以及內建的 [HeadsetControl](https://github.com/Sapd/HeadsetControl) 所支援的所有耳機。

## 顯示方式

**顯示在工作列上（預設）：** 在通知區域旁顯示 `🎧 30%  🖱 93%`，使用 Windows 圖示字型繪製。
- **電量低：** 紅色數字代表電量為 15% 或更低。
- **充電中：** 數字旁會出現藍色 ⚡ 圖示。當裝置已充滿電且仍插著電源時，會變為綠色 ✓。
- **休眠中：** 暗淡文字代表裝置正在休眠，並顯示上次已知的電量數值。
- **已中斷連線（選用）：** 在選單中開啟 *顯示已中斷連線的裝置* 後，當驅動程式明確回報無線連線中斷時，會顯示暗淡的 `×`。此功能不會因單次電量輪詢逾時就推斷為斷線；預設仍為隱藏離線裝置。
- **兩個同類型裝置：** 當有兩支滑鼠（或兩支手把……）時，兩者會使用相同的圖示，因此每個圖示角落都會顯示最多 3 個字元的小標籤，擷取自裝置名稱（例如 `MX`、`PRO`），若名稱無法區分則顯示數字。若該類型只有單一裝置，則不顯示標籤。
- **佈景主題：** 自動跟隨淺色 / 深色模式與 DPI 縮放比例。
- **透明工作列佈景主題**（例如 Windhawk 的 Taskbar Styler）：請在選單中開啟 *工作列文字背景*，讓文字在桌布上保持清晰可讀。
- **多螢幕：** 小工具會顯示在每個螢幕工作列的時鐘旁邊，因此在全螢幕玩遊戲時依然可見。選單中的 *小工具顯示位置* 可選擇 *所有螢幕*、*僅主螢幕* 或指定單一顯示器（例如僅 *螢幕 3*）。
- **更多顯示選項：** *圖示位於百分比上方* 會將圖示疊放在百分比上方以節省寬度；*品牌顏色* 會以已知品牌的代表色（Razer 綠、HyperX 紅等）搭配小型電量條顯示；同類型有兩個裝置時會顯示小標籤以便區分；左側與右側垂直工作列會改以直欄排列裝置。
- **多國語言：** 支援 English、العربية、Deutsch、Español、فارسی、Français、עברית、日本語、한국어、Magyar、Polski、Português (Brasil)、Русский、Svenska、Tiếng Việt、Türkçe、Українська、简体中文與繁體中文。Windows 與 Linux 版本皆會自動跟隨系統顯示語言；選單中的 *語言* 可手動切換其他語言，Windows 安裝程式也支援全部 19 種語言。介面字串存放在可編輯的靜態 `lang/*.json` 檔案中，完整翻譯文件位於 [`docs/i18n/`](README.md)。若要編輯或新增語言，請參閱[翻譯](#翻譯)。
- **品牌顏色：** 15 個知名品牌的裝置會套用原廠代表色，並於百分比下方顯示柔和光暈與細電量條：Razer 綠、Logitech 藍、SteelSeries 橘、Corsair 黃、HyperX / ROG / ZOWIE 紅、PlayStation、Xbox、Samsung、Apple、Jabra、JBL、Cooler Master 與 Steam。每種顏色皆提供深色工作列與淺色工作列兩種色調。品牌判定順序為偵測到該裝置的驅動程式、廠商 ID（VID），最後為裝置名稱；顏色與規則定義於 `src/brands.cpp`。可在選單中透過 *品牌顏色* 關閉此功能。

**系統匣圖示：** 每個裝置各自擁有一個繪有電量數字的系統匣圖示，並在電量降至 15% 時顯示「電量低」通知。當工作列為垂直配置或無法偵測到工作列時，程式會自動切換至此模式。

**自訂裝置名稱：** 開啟裝置子選單並選擇 *重新命名裝置...* 即可設定名稱（最多 64 個字元）。該名稱會顯示在工作列小工具的工具提示 / 標籤、系統匣工具提示與通知，以及裝置選單中。使用 *還原原始名稱* 即可恢復驅動程式提供的原名。名稱是透過穩定的裝置識別鍵儲存在目前使用者的本機 Windows 登錄檔（`Software\WirelessBattery`、`DeviceAliases`）中。重新命名絕不會影響驅動程式比對、通訊協定查詢，或是 `--list` / `--dump` 診斷輸出，也不需要任何帳號或網路連線。

將滑鼠游標懸停可查看詳細資訊。點擊可開啟選單：列出所有裝置（點擊裝置可隱藏或顯示）、顯示模式、*立即重新整理*、*開機時啟動* 與 *結束*。電量每 60 秒更新一次（可在選單中的 *檢查電量間隔* 調整），並在裝置插入或電腦喚醒時立即更新。

## 智慧電量通知（實驗性功能）

您可以從每個裝置的子選單中設定**個別裝置的低電量通知門檻**：**電量通知** → *使用預設值（15%）*、*停用通知*，或選擇 5%、10%、15%、20%、25%、30%、35%、40% 其中之一。除非您另行覆寫，否則仍維持既有的 15% 預設值。設定會依據裝置識別鍵儲存在目前使用者的 Windows 登錄檔（`Software\WirelessBattery`、`AlertThresholds`）中。

只有當裝置處於已連線、已喚醒且未充電狀態，並測得真實有效的 0–100% 讀數時，才會觸發通知。通知僅會發出一次，並在電量回升至高於所選門檻超過 10 個百分點（或開始充電）後才會重新啟用觸發。遺漏讀數或休眠中的裝置不會重複觸發通知。已隱藏的裝置不會產生通知。停用單一裝置的通知並不會隱藏該裝置或改變其百分比顯示。

工作列小工具模式與系統匣圖示模式皆支援通知。由於 Windows 需要通知區域圖示才能顯示傳統氣球通知，小工具模式在觸發通知後可能會在系統匣短暫顯示一個臨時通知圖示最多一分鐘。小工具的顏色與低電量醒目提示仍獨立於通知設定之外，繼續使用專案原本的全域 15% 門檻。

## 電量歷史與洞察

在工作列小工具或系統匣選單中的裝置上按右鍵，然後選擇 **電量歷史...**。原生且支援 DPI 縮放的檢視器（會自動跟隨 Windows 淺色 / 深色佈景主題）會以連接樣本點的折線圖顯示過去 **24 小時**、**7 天**或 **30 天**內記錄的電量變化，同時列出最新讀數、最低 / 最高電量、百分點變化以及記錄數。您也可以在檢視器中清除所選裝置的歷史記錄。

電量歷史**僅儲存在本機**，且只針對已連線、已喚醒並回報數值百分比的裝置進行記錄。每個裝置最多每 30 分鐘取樣一次（充電狀態轉換除外，最短間隔 60 秒）。資料最多保留 30 天，且本機檔案大小會控制在約 2 MB 以內。應用程式絕不會在既有輪詢之外額外探測硬體、絕不透過網路傳送任何歷史資料，並僅依據近期的放電觀測值進行保守的近似剩餘續航預估。必須具備至少 4 筆記錄、2 小時時間跨度、3 個百分點的下降幅度、最新讀數與穩定的放電區段才會進行計算。充電中、讀數過舊或資料不足時皆會隱藏預估；此功能不會讀取裝置自行回報的剩餘時間。預估結果僅供參考，不構成任何保證。圖表中缺失的資料時段會保留為斷點，不會進行內插補齊。

在選單中關閉 **記錄電量歷史** 即可停止儲存讀數；已儲存的資料會保留，直到您在檢視器中清除為止。檔案儲存在 `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`。其中的裝置識別碼經過編碼處理（並非加密）；該檔案僅限您的 Windows 帳戶於本機使用。在 `--demo` 模式下，圖表使用合成的示範資料且不會儲存。**注意：** 唯有在安裝具備此功能的版本並讓應用程式執行一段時間後，才會開始收集歷史資料。

## 支援的裝置

| 廠商 | 裝置 | 讀取方式 |
|---|---|---|
| **NuPhy** | WH80 透過 USB 線（`19F5:A011`）或藍牙（`19F5:324A`），已實機測試 | USB：唯讀 NuPhyIO 電量查詢；藍牙：Windows 電量讀數並分類為鍵盤（[通訊協定說明](#sec-nuphy)） |
| **DARKRIM** | SHADOW（寸渊影弑）透過其 `3654:6901` USB 接收器（已實機測試） | 唯讀 CRC 校驗電量查詢與充電旗標；實測為 10% 階梯粗略讀數，更細精度尚未驗證（[通訊協定說明](#sec-darkrim)） |
| **Inphic** | IN10R MAX / IN10 MAX 透過 KP 8K 接收器（`1D57:FA65`；型號 `73` 已實機測試，型號 `74` 未實測） | 被動接收 Xenta 狀態報告；須連續兩筆相符幀才確認電量（[通訊協定說明](#sec-inphic)） |
| **ASTRO** | A50 X（`046D:0B0B`，已實測）、A50 Gen 5（`046D:0B1C`）、A50 Gen 4（`9886:002C` 已實測、`002D`/`002A`）、A50 Gen 3（`9886:0015` 已實測、`0014`/`0018`/`001D`/`0026`）、A20 Wireless（`9886:0037`–`0045`），透過 USB 底座 | 電量百分比、充電中與底座停靠狀態 |
| **Logitech** | 搭配 Unifying、Bolt、Lightspeed（含 PRO X3 SUPERSTRIKE 接收器 `046D:C54F`）與 Nano 接收器，或透過 USB / 藍牙連線的滑鼠與鍵盤；G 系列耳機（G533、G535、G633/G635/G733/G933/G935、G PRO/PRO X）；新版 `046D:0ADF` 接收器上的 G435 | 支援功能探索的 HID++ 1.0 / 2.0：統一電量、電量等級、電壓、ADC；G435：CRC-16 封包廠商報告、`GET_BATTERY`（單位 mV） |
| **Razer** | 無線滑鼠、鍵盤與接收器；BlackShark V2 HyperSpeed、V2 Pro（2020/2023）、V3 / V3 Pro / V3 X 耳機、V3 Pro for Xbox（`1532:0A55` 接收器、`0A4E` 連接線）；Barracuda X（2022）透過 2.4 GHz 接收器（`1532:0550` 或 `1532:0552`）；Barracuda Pro（`1532:053A`） | Razer 功能報告通訊協定；BlackShark 廠商通訊協定（V3 / V3 Pro / V3 X 每 5 分鐘查詢一次）；Barracuda X：透過接收器進行 Airoha 電量與線材查詢 |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless、Arctis Nova 3P/5/7/7X/7P/Pro Wireless（含 `1038:225D`）、Arctis Nova Elite（底座 `1038:2244`）、GameBuds；Aerox 3/5/9 Wireless（Aerox 5 Diablo IV `1038:1860`，未實測）、Aerox 3 Wireless CS2 Dragon Lore Edition（接收器 `1038:1878`、連接線 `187A`）、Aerox 3 Wireless Gen 2（接收器 `1038:1890`、連接線 `1892`）、Prime Wireless、Rival 3 Wireless（Gen 2）、Rival 650、Rival Pro | 廠商 HID 報告；Aerox/Prime 與 Rival 650 在接收器與 USB 線之間共用同一項目，當兩者皆有回應時優先採用連接線讀數 |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 無線耳機；Bragi 裝置（Virtuoso、Void V2、HS80 MAX、Slipstream 滑鼠與鍵盤，含新款 Slipstream 接收器 `1B1C:2B00`，例如 Scimitar Elite SE Wireless 與 Dark Core RGB Pro SE）；Sabre V2 Pro Ultralight Wireless（`1B1C:2B2A`）、Sabre v2 PRO WIRELESS MG（`1B1C:2B34`，未實測） | 廠商 HID 報告、Bragi `GET`（唯讀）、Compx 17 位元組電量通訊協定（唯讀） |
| **Cooler Master** | MM712、MM731（2.4 GHz 接收器或 USB 線） | 廠商 HID 狀態報告（唯讀） |
| **Press Play** | ICARUS V2 Nearlink 透過其 `7768:6434` 2.4 GHz 接收器（驅動程式已在 90% 電量下實機測試；通訊協定已於 100% 與 90% 擷取） | 在 `FFB2:0001` 上發送唯讀輸出報告 `06 05`；電量百分比位於回應第 14 位元組 |
| **HyperX** | Cloud III Wireless、Cloud III S Wireless、Cloud II Wireless（HP、Kingston、DTS）、Cloud II Core Wireless、Cloud Alpha Wireless、Cloud Alpha 2 Wireless、Cloud Flight（PS 版 `03F0:0C8C`，未實測）、Cloud Flight S、Cloud Stinger Core Wireless（含 DTS `03F0:0A8E`，已實測）、Cloud Core Wireless DTS、Pulsefire Haste 2 Core Wireless（2.4 GHz 接收器）、Pulsefire Haste 2 Wireless、Pulsefire Haste 2 Mini（2.4 GHz 接收器）（2.4 GHz 接收器 `03F0:0F98` 已實測；`0D97` 未實測） | 廠商 HID 報告（Haste 2：[通訊協定說明](#sec-hyperx-haste-2)） |
| **Glorious** | Model O / O- / D / D- Wireless、Model O 2 / D 2 PRO | 廠商功能報告 |
| **Hitscan** | Hyperlight X、Hyperlight N | 廠商功能報告（與 Glorious 相同通訊協定） |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury、Pulsar 與 ATK VXE 無線滑鼠（例如 VXE X3 Pro、VXE Dragonfly R1 / R1 Pro Max / R1 SE+、ATK F1 Extreme）、Hitscan Hyperlight、Chimera V2（接收器 `3554:F512`） | 共用廠商通訊協定，附帶校驗碼回應 |
| **Pulsar X2 V3** | X2 V3 透過 1K 接收器（`3710:5402`）或 USB 線（`3710:3402`）；X2 V3 eS 透過 8K 接收器（`3710:5403`）或 USB 線（`3710:3406`） | 64 位元組廠商功能報告，電量暫存器 `08 81 01`（唯讀） |
| **ATK / VXE NK** | VXE R1 NK 與其他在 NK mouse NANO 接收器（`373B:1216`）上的 NearLink 滑鼠 | 在 `FF05:0001` 上的 ATK BITMOUSE 輸出報告 08（電量與充電狀態） |
| **ATK 8K Nano** | 透過 ATK 8K Nano Dongle（`373B:1178`）連線的 ATK / VXE 滑鼠 | 在 `FF10:0001` 上的 Holtek GetConfigData（`82`）功能報告（出自 ATK HUB；電量與充電狀態） |
| **ATK 耳機** | ATK N9 Pro、N9 Ultra（第一代） | 虛擬 COM 連接埠通訊協定（必須關閉 ATK 桌面應用程式） |
| **G-Wolves** | Fenrir、Fenrir Pro / Max / Asym、HTX、HTS、HSK、HTR、HT-S2、Lycan、WARG、VUK 及其 8K 接收器 | Glorious 或 Kysona 通訊協定，依型號而定 |
| **Keychron 滑鼠** | 2.4 GHz 接收器上的 M4 與其他 Keychron 滑鼠；Keychron 4K Link 接收器（`3434:D038`）上的 4K 滑鼠（M4 4K、M3 4K、M3 mini 4K、M6 4K ...）；TurboLink 8K 接收器上的 8K 滑鼠（M5 8K、G6 HE 8K ...）；Ultra-Link 8K 接收器（`3434:D028`）上的 8K 滑鼠；1K 接收器（`3434:D030` / `D031`）上的舊款滑鼠（M1、M2、M3、M3 mini、M6、M7 ...）；Link-KM 接收器或連接線上的 Nape Pro 軌跡球 | 出自 Keychron Launcher 的廠商報告（1K 接收器：功能報告 51 06，與 Keychron 桌面程式相同；Ultra-Link 8K：`FFC1` 上的報告 B5 03 / B3 06；Nape Pro：原始 HID A7 31） |
| **Keychron 鍵盤** | K5 Max（`3434:0A50`，已實測）透過 Keychron Link 接收器（`3434:D030`）或 USB 線；其他套用相同修補程式建置的 Keychron QMK 無線鍵盤 | 在 `FF60:0061` 上的原始 HID：`B2` 詢問接收器目前連線的鍵盤，`A4` 回傳電量、電壓與充電狀態。**需要已修補的鍵盤韌體：** 請參閱 [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)。原廠韌體僅支援透過藍牙回報 |
| **CHERRY** | MX 3.0S 無線鍵盤透過 2.4 GHz 接收器（`046A:00EA`，已實測）或 USB 線（`046A:00E3`，已實測） | 在 `FF1C:0092` 上的廠商 HID 查詢 `1A`（唯讀），含 USB 供電狀態。藍牙模式由藍牙支援涵蓋 |
| **CHERRY** | Cherry XTRFY 無線滑鼠透過 1K 接收器（`046A:0330`，已實測） | CompX 17 位元組電量通訊協定（`08 03` 連線狀態、`08 04` GetPower），與 Corsair Sabre V2 Pro 相同封包格式（唯讀） |
| **Arbiter Studio** | Akitsu（`373E:000A` 8K 接收器、`373E:0009` 連接線）、Akitsu 3950（`373E:0039` 8K 接收器、`373E:0038` 連接線）、Akitsu Medium（`373E:0067` 8K 接收器與 `373E:0066` 連接線，兩者皆已實測） | 在 `FFFF:0000` 上的唯讀廠商功能報告 `0x83`，出自 Arbiter Web HUB（電量與充電狀態） |
| **LAMZU** | Maya X、Maya、Maya M、Tachi、Inca、Paro、Thorn、Atlantis Mini / OG Champion、Orcus（連接線、1K 與 4K/8K 接收器） | 出自 LAMZU Aurora 的廠商功能報告 |
| **Endgame Gear** | 4K 接收器上的 OP1w 4k（v1 / v2）、XM2w 4k（v1 / v2）；原裝接收器（`3367:1961`）上的 XM2we | 廠商功能報告 `A1`，電量指令 `B4`（唯讀） |
| **ATK / VGN / Evision 鍵盤** | 共用 2.4 GHz 接收器（`320F:5088`）或 USB 線（`320F:5055`）上的 ATK V75X 與 VGN / VXE 鍵盤（S99、V98 Pro / V98 Pro V2、N75 Pro、VXE75 / VXE75 V2、VXE V87），依產品名稱辨識；`320F:5088` 接收器名稱為 "Wireless Gaming Keyboard" 的鍵盤，例如 Feker Alice80（已實測） | Evision 輸出報告 `04`，電量指令 `1A`（出自 ATK HUB 與 VGN HUB）；透過接收器時最多每 10 分鐘查詢一次 |
| **Redragon (Evision)** | K1NG M999（已實測）透過 `320F:226F` 2.4 GHz 接收器；該接收器 ID 可能與其他型號共用 | 與 ATK 鍵盤相同的 Evision 通訊協定（在 `FF1C:0092` 上的報告 `04`、指令 `1A`），每次輪詢皆查詢；磁吸充電座上會顯示充電中；插上 USB 線時接收器會持續重複回報舊電量且無充電狀態 |
| **Audeze** | Maxwell 透過 USB 接收器（`3329:4B19`）或 USB-C 連接線（`3329:4B1A`）；Maxwell 2 透過 USB 接收器（`3329:4B29`，已實測）；Xbox 版本 ID 未實測 | 廠商報告 `06` / 輸入報告 `07`，電量屬性 `0CD6`（單次唯讀查詢） |
| **ENDORFY** | Viro Wireless 透過其 2.4 GHz 接收器（`3738:0072`，未實測） | 在廠商報告 `06` / 輸入報告 `07` 上的 Airoha RACE "get battery"（`0CD6`），與 Audeze 及 Skullcandy 接收器相同的唯讀查詢；無充電狀態 |
| **Turtle Beach** | Stealth 700 Gen 3 透過 USB 發射器（`10F5:2251`，已在 HaloBattery 中實測；PC 版 `10F5:2262` 未實測）或耳機隨附 USB 線（`10F5:2253`） | RACE `0x9942`（啟用 CoAP 用戶端）並透過 RACE `0x9902` 通道傳送 CoAP `GET /GSI`，與 Swarm II 相同；從鍵值 `240` 讀取電量（無充電旗標） |
| **AKG** | N9 Hybrid 透過其 USB 接收器（`0ECB:20D9`，已實測） | 在 `FF13:0001` 上的 Airoha RACE：輸出報告 `06`、輸入報告 `07`、電量屬性 `0CD6`（單次唯讀查詢） |
| **NZXT** | Lift Elite Wireless 透過其接收器（`1E71:2101`）或 USB 線（`1E71:2129`） | 廠商讀取 `4E 02 81 .. B0`（擷取自 NZXT CAM） |
| **Poly / Plantronics** | Voyager 8200 UC 與其他搭配 BT600 轉接器（`047F:02EE` / `02F7`）的耳機 | 報告 `07` get/set 通訊協定，電量項目 `0A 1A`（唯讀） |
| **WLMouse** | YING Magnesium（YING 8K 接收器 `36A7:A874`）；Beast X 8K、Beast X Mini / Mini Pro、Beast X Pro、Beast MAX、Sword X 8K（接收器或連接線；不含 Beast X 4K）；Beast X V2（8K 接收器 `36A7:A856`）；Beast G（8K 接收器 `36A7:A860` 或連接線 `36A7:A861`；未實測） | 廠商功能報告，狀態指令 `0x83`（YING：與 Glorious 相同通訊協定） |
| **Finalmouse** | UltralightX 透過其 2.4 GHz 接收器（`361D:0100`，已實測）；Starlight X 透過其接收器（`361D:0300` / `0301`，已實測）。不支援滑鼠本身的有線連接 | `FF00` 上的 xpanel 廠商報告：唯讀 GET 查詢，接著執行 *wake/all*（`0xE0`）；依據 xpanel 電壓曲線換算電量，或讀取 Starlight X 自身的百分比，加上充電狀態 |
| **VAXEE** | VAXEE 4K 接收器（`3057:1002`）或 8K 接收器（`3057:2002`，例如 NP-01 Ergo Wireless 8K）上的無線滑鼠；透過 USB 線（`3057:1011`）連線的 ZYGEN NP-01S V2 Wireless | 在 `FF05:0001` 上的唯讀廠商功能報告 `0E`；以 5% 為單位的電量與充電狀態（[通訊協定說明](#sec-vaxee)） |
| **Scyrox** | V12M 透過其 2.4 GHz 接收器（`395A:0006`） | 在 `FF00:0002` 上讀取 S-Center 2.0 設定檔（輸出報告 `08`，指令 `01`）；僅有電量，無充電狀態 |
| **HECATE** | G5M PRO 與其他使用同一接收器的 HECATE 滑鼠，以及 USB 線 `35BB:D3FA / D3FC / D3FD` | Kysona 通訊協定 |
| **Redragon** | 採用 Compx 方案的無線滑鼠：M916 Pro 1K（已實測）、M913 Impact Elite（三模）、G49（接收器或連接線） | Kysona 通訊協定（Areson `25A7` 接收器列於下方 Areson 項目） |
| **Taidu（鈦度）** | TSG808 透過其 Compx 2.4 GHz 接收器 `3554:F5D5`（已實測） | Kysona 通訊協定 |
| **Areson (Redragon)** | M915RGB-WL（已實測）、原版 M913 Impact Elite 與其他透過 `25A7:FA07` / `FA08` 接收器連線的滑鼠 | 17 位元組 `GetPower` 功能報告；10% 階梯電量與充電旗標 |
| **Ninjutso** | Sora V2 透過 1K 接收器（`1915:AE1C`，已實測）或 USB 線（`1915:AE11`，已實測）；Ten Air（接收器 `093A:EB01` 與 USB 線 `093A:E020`，已實測）/ Ten（`093A:EB01` / `E020`，未實測） | NinjaForce 功能報告 `0x05`（Sora V2 為 `0x15`）與 `0x06`（Ten / Ten Air 為 `0x13`/`0x12`/`0x11`） |
| **Sprime** | PM1 透過 2.4 GHz 接收器（`1915:AC1C`，已實測；`1915:AD8C`）或 USB 線 | 與 Sprime 網頁驅動（sprime.pro）相同的 0x05 功能報告、狀態指令 0x15 |
| **RAWM / SADES** | Leviathan V4 透過 RAWM HS Receiver（`1915:2346`，已實測）；ES21 / ES21 Pro / ES21M、ER21 / ER21 Pro / ER21M、ES11、G11 / G11 Plus / G11 Pro、SA-* 與 SADES Dagger 滑鼠透過其 RAWM 接收器（`1915:232A`–`234B`）或 USB 線 | 透過接收器查詢 RAWM HUB 2.0 裝置資訊（回傳含電量百分比與充電狀態的 JSON），唯讀（[通訊協定說明](#sec-rawm)） |
| **AULA** | F75 / F87 Pro / F99 無線鍵盤透過 2.4 GHz 接收器 | 報告 0x13 幀、指令 0x4A、加總校驗碼（藍牙與有線模式未實測） |
| **AULA 滑鼠** | X9 Ultra（已實測）透過 AULA-8K Dongle `320F:22A0`；接收器 ID 與 V9 型號共用 | 在 `FF1C:0092` 上於 START `01` / END `02` 之間發送報告 `04` 唯讀電量指令 `1A`；僅支援 2.4 GHz |
| **SONiX 鍵盤（AJAZZ / AULA / EPOMAKER）** | AJAZZ AK820 MAX（已實測）、EPOMAKER EA75（已實測）、AULA F108 Pro 透過 `05AC:024F` 2.4G 接收器；AJAZZ AK980 V2 透過 `0C45:FEFE` 接收器；AJAZZ AK820 Pro 透過 `0C45:FDFD` 或 `0C45:FEFE` 接收器；EPOMAKER P75 透過 `342D:E479`（未經實機測試） | 在用途頁面 FF60 上發送廠商報告 `20 01`，加總校驗碼（僅限 2.4G 模式；無充電指示） |
| **其他 SONiX 接收器（未經實機測試）** | RK Royal Kludge R75（`342D:E485`）；Redragon Arlokks K742B（`342D:E4BC`）；M1 V5 VIA（`342D:E4C2`）；Lucky65V2（`342D:E407`）；Lofree Flow2（`388D:0003`）；MSI FORGE TKL W FRIEREN EDITION（`0DB0:0CA0`）；Essential75（`36B0:30BD`）；NUT65（`342D:E51A`）；RK 2.4G Dongle（`342D:E487`）；WEIKAV MAX102（`342D:E537`）；Lofree Flow2（`388D:0002`）；NuPhy Air75V2（`19F5:3245`）；SKN Qinglong（`362D:D028`）；Lemokey Link（`362D:D030`）；Wireless Link（`362D:D101`）；Spade65-QMK-2.4GHz（`342D:E49F`） | 相同的僅電量 `20 01` 查詢；必須具備確切的 VID:PID 與 33 位元組報告長度的 FF60:0061 集合；僅支援 2.4G，無充電指示 |
| **36B0 鍵盤（PMO / WOBKEY / URX / EVO80）** | PMO (WOBKEY) Wave 75 RGB 透過 `36B0:3002` 2.4G 接收器或 `36B0:3009` USB 線（通訊協定已由 #343 回報者在兩者上測試）；Aurora 80（`3004`）、PMO P75（`302B`）、PMO 80（`3012`）透過相同接收器或連接線（未實測）；URX Core75 透過接收器（已在 HaloBattery 確認）；EVO80（未實測） | PMO Hub 韌體：在用途頁面 FF60 上發送 `START_COMM` / `GET_BATTERY`（`AA 30`）/ `STOP_COMM`，出自 pmohub.cn。URX / VIA 韌體：VIA 自訂讀取 `08 00 07`（通道 0、數值 7），透過 HaloBattery 取自 URX HUB。無充電指示 |
| **DAREU** | EM901X 透過 `260D:1074` 2.4 GHz 接收器或 `260D:1090` USB 線（兩者皆已實測電量讀數；已測試接收器在底座放上 / 取下時的充電旗標切換） | 僅讀取電量的功能報告 `08`、指令 `04`；於另一廠商集合收到回應 `09`。每個產品 ID 需具備唯一明確的輸入 / 功能集合配對。兩者同時連線時優先採用有效的 USB 讀數；即使滑鼠電源關閉，接收器仍可能回傳快取的遙測資料 |
| **DAREU** | A84 鍵盤（`260D:0022`，未實測） | 在介面 0 上的 SONiX 功能報告，指令 `04 F6`（官方 A84 驅動程式的電量讀取方式）；回報百分比，無充電旗標 |
| **DAREU** | A980 Pro 透過 `260D:1131` 多滑鼠共用接收器及其 USB 線（`260D:1148`）（已於實機測試電量；插線時已確認充電旗標） | Togran 通訊協定：在消費者控制（consumer-control）集合上的 65 位元組功能報告 `0A`；先進行插槽查詢（class 0 / `A0`），再進行電量查詢（class 7 / `80`），接線時固定使用插槽 0。唯讀 |
| **Sharkoon** | Skiller SGM50W 透過 `260D:1125`（未實測） | 與 DAREU EM901X 相同的 Compx 查詢（功能報告 `08`、指令 `04`；在 `FF01:0000` 回應 `09`）；Sharkoon 為其提供的韌體更新工具即為 VID `260D` 的 Compx 工具 |
| **Zenith** | Zenith Pro 透過 `260D:1114` 2.4 GHz 接收器（已實測電量讀數；充電未測）或 `260D:1143` USB 線（未實測） | 在 `FF02:0002` 上作為輸出報告發送相同的 Compx 指令（`08`、`04`）；同一集合回傳 `08 04` 包含百分比、充電旗標與毫伏特數，並以位元組總和 `0x55` 校驗 |
| **AJAZZ AK992** | Telink 2.4 GHz 接收器 `320F:50C3`（已實測） | 在 HID 集合 `FF1C:0092` 上的 EVision 電量查詢 |
| **ZOWIE** | EC1/EC2/EC3-CW、DW 系列（U2-DW、S2-DW ...）與 U2 透過其 2.4 GHz 接收器 | 社群記錄的唯讀廠商指令 |
| **Royal Kludge (RK)** | MG6 Pro 透過 2.4 GHz 接收器（`2E3C:00A6` / `00E6`）或 USB 線（`2E3C:00A5` / `00E5`） | 出自 RK 網頁驅動程式的 QiWang 64 位元組封包，`GET_BATTER_VOL` 讀取（百分比、電壓、充電狀態） |
| **ASUS ROG** | Strix Scope II 96 (RX)、Azoth、Falchion 鍵盤；Keris、Harpe、Gladius、Chakram、Spatha、Pugio、Strix Impact 滑鼠；Pelta 耳機（2.4 GHz 接收器）；Cetra Open Wireless 真無線耳機（SpeedNova 接收器 `0B05:1CAC`，左耳 / 右耳 / 充電盒）；Omni Receiver | ROG HID 電量查詢 |
| **Machenike** | L7 Arctic / L7 Mix 透過 `248A:FF4C` 2.4 GHz 接收器或 `248A:FF4E` USB 線（兩者皆已實測） | 唯讀功能報告 `51`、狀態指令 `06`；電量與充電狀態。[通訊協定說明](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS 透過其 2.4 GHz 接收器（`0DB0:9E22`）；CLUTCH GM31 Lightweight Wireless（2.4 GHz 接收器 `0DB0:0D3C` 已實測；USB 線 `0DB0:0D3B`）與 CLUTCH GM41 Lightweight Wireless（接收器 `0DB0:0D4C` / 連接線 `0DB0:0D4B`，根據持有者的封包擷取） | 在 `FF0D:00B0` 與 `FF00:0001` 上的唯讀廠商查詢 `0F 20`；單一位元組內包含電量與充電旗標（通訊協定源自 MSI Center 的 Gaming Gear 模組）；GM41：`FF10:0006` 上的被動 `A0 xx 07 …` 報告 |
| **MCHOSE** | 透過 2.4 GHz 接收器或 USB 線的 L7 / L7 Pro / L7 Ultra（L7 Ultra 已實測）、M7 / M7 Ultra、A7 / A7 Ultra、K7 滑鼠；A5 V2 Ultra（2.4 GHz 接收器 `3837:100C`，已實測）、K7 Ultra（2.4 GHz 接收器 `3837:1001`，已實測；A7 V2 Ultra+ `3837:100B` 預期相容，issue 227）；G3 V2（2.4 GHz 接收器 `3837:4245` 與 USB 線 `3837:418C`）；K7 V2 Ultra+ 透過 2.4 GHz 接收器 `3837:1014` 或 USB 線 `3837:4028`（兩者皆已實測；其餘新系列接收器 ID `1018`、`1016`、`102C`、`102D` 未實測） | 廠商功能報告與反轉酬載（通訊協定出自 alexfrih/mchose-linux）；Realtek `3837` 接收器以設為 `41E4`（A5 V2 Ultra）或 `3837`（K7 Ultra）的 vid 欄位回應相同查詢；G3 V2：`FF01:0010` 上的唯讀廠商查詢；K7 V2 Ultra+：`FF01:0001` 上的 64 位元組報告 `0x4D`、裝置資訊指令 `0x0900`（通訊協定出自 M HUB 網頁驅動程式） |
| **MCHOSE A5（第一代）** | A5 Pro / A5 Pro Max 透過 1K 或 4K 2.4 GHz 接收器（`2023:F013`、`2023:F015`、`2023:F018`）或 USB 線（A5 Pro `2023:F017`、A5 Pro Max `2023:F019`）；此處未實測 | 在 `FFFF` 上發送 64 位元組功能報告中的唯讀電量指令 `0x83`（page 0），回應標記為 `0xA1`（通訊協定出自 z750sasr A5 Pro Max 網頁驅動程式與 HaloBattery，ID 出自 Klegus/mchose-macos） |
| **MCHOSE 耳機** | V9 Pro 2 透過 2.4 GHz 接收器（`3837:6011`，已實測） | 在 `FF07:0222` 上使用 M HUB 的唯讀 "MC" 電量幀（報告 `0x55`，子指令 `0x0B`）；單一位元組內包含電量與充電旗標（通訊協定出自 M HUB 網頁驅動程式） |
| **AULA / MCHOSE / Redragon 鍵盤** | AULA F75 / F87 Pro / F99；MCHOSE K99 V2、G75 Pro、X75 與其他 M HUB 鍵盤；Redragon Horus Pro / Pro V2 (K618RGB-PRO) 透過 2.4 GHz 接收器（`3554:FA09`、`41E4:2001`）；MCHOSE K87 透過 `05AC:024F` 接收器（介面 1 上的 BY 配置，而非 SONiX 配置） | 報告 0x13 幀、指令 0x4A（MCHOSE 與 Redragon 型號透過指令 0x05 辨識，與 M HUB 相同）；未涵蓋藍牙與有線模式 |
| **MCHOSE 鍵盤** | G75 V2 透過 2.4 GHz 接收器 `3837:3033`（已實測）；同一接收器亦搭配 G87 V2 與 K99 V3 出貨（相同通訊協定，未實測）；K87S 雖使用相同接收器 ID 但採用不同通訊協定，故未涵蓋 | 在無 ID 的 64 位元組 `0001:0000` 集合上執行 M HUB 的唯讀 "GLW" func-config 查詢：請求旗標 `0x55`、指令 `0x05`、電量位於酬載位元組 32（位元 7 = 充電中），加法校驗碼 |
| **AULA SC580** | SC580 / SC580X 滑鼠透過 USB 線（`088D:062E`，已實測）或其 2.4 GHz 接收器（`089D:062F`，已實測） | 在 33 位元組廠商集合 FF02:0000 上發送唯讀指令 `0x30`（裝置資訊），加總校驗碼；充電時滑鼠固定回報 100，因此顯示上次電量；未涵蓋藍牙模式 |
| **AULA HERO 68 Air** | HERO 68 Air 透過 8K 無線接收器（`372E:106C`） | 在用途頁面 FF60 上使用帶確認機制的 20 位元組幀（每則訊息包含 4 個資料幀與 1 個結尾幀），唯讀電量指令 0x87，電量之後附帶充電旗標 0x10；未涵蓋藍牙與有線模式 |
| **EWEADN（前行者）** | S7 Max / Pro / Ultra 與 S9 Max / Pro / Ultra / Ultra+ 透過 "Gaming 2.4G" 接收器（`372E:103D`）；S9 Ultra 透過其 USB 線（`372E:1027`） | 在 `FF00:0001` 上的唯讀功能報告 `03`：連線檢查 `47`、裝置基本資訊 `4F 81`（電量百分比與充電位元），出自 EWEADN 網頁驅動程式 |
| **Rapoo VT** | VT3 Max Gen 2（已實測）；VT9 Gen 2（已實測）；其他暴露相同狀態介面的 Nordic 54L VT 滑鼠；舊款 VT3 Pro（實驗性）；VT1 Pro Max（來自持有者的 USB 封包擷取） | `FF00:0002` 上的被動 HID 狀態報告 `07`（16 或 19 位元組；部分 VT3 Max Gen 2 接收器為 13 位元組）；舊版 `BB` 僅限於 VT3 Pro `1215/4415` 與 VT1 Pro Max `1233/4433`。支援接收器與 USB 線，含充電狀態 |
| **Motospeed / Delux / Ajazz** | Motospeed X6、Delux M900 Pro（Xenta 型號 30/50；舊款 3D）、Delux M800 Pro、Ajazz AJ179 系列；AJ159 與其他在 3151 接收器上的 AJ 系列滑鼠；AJ139 V2 MC（`A8A5:2255` 接收器、`A8A4:2255` 連接線） | 廠商報告（M900 Pro：被動狀態廣播或功能查詢，Xenta 事件 40/41；AJ 系列：0xF7 狀態輪詢，接著功能報告 0x05） |
| **Incott** | G23 V2 / G24（`093A:522C` 接收器、`093A:622C` 連接線） | 唯讀狀態功能報告 09 |
| **Attack Shark 與其他中國品牌** | Rongyuan 接收器（81 種型號：`3151:402D` 上的 Attack Shark R3 與 AJAZZ AJ179 Pro、K86、X82 PRO HE、Ajazz 鍵盤、部分 MSI 等；藍牙連線下的 K86 顯示為鍵盤）；Xenta 接收器（Attack Shark X6 / R1、X11、X3 Max、V3 Pro、V6；X6 亦見於 `1D57:FA61`，未實測）；Semico 1A2C 鍵盤（`1A2C:8FFF` 接收器上的 Attack Shark X98 已實測，以及 `1A2C:A034` 連接線；`1A2C:8FFF` / `1A2C:A036` 上的 AJAZZ AK820 Max Plus） | Rongyuan 狀態報告；Xenta 被動廣播；Semico 唯讀 `0x0E` 狀態查詢（`FF02:0002` 上的 `AA 55 CC 33`；因 X98 無論使用電池或充電時皆回報 `state=1`，故省略充電旗標） |
| **Wraith** | W1 / W1 Freestyle（`093A:522C` 接收器、`093A:622C` 連接線；與 Incott 相同 ID，透過型號代碼區分） | 對所有按鍵進行唯讀逐鍵讀取 `86`（功能報告 09），接著讀取推送的狀態輸入報告 09 |
| **Fantech** | Helios Go XD5（有線 `25A7:FA7B`、接收器 `25A7:FA7C`）；Raigor III（已實測）、Raigor II WG10 與其他共用 `1EA7:0066` / `1EA7:0064` 接收器的通用 2.4G 滑鼠裝置 | Helios Go XD5：廠商功能報告 `08`、指令 `04`、加總至 `0x55` 校驗碼。Raigor/2.4G 滑鼠：`FFB5:0001` 上的唯讀 `B5` 狀態頁查詢，區段 `94` = 上次回報的百分比（休眠、關機或充電時可能為舊值；無充電狀態） |
| **Sony** | DualShock 4、DualSense、DualSense Edge（USB、藍牙、無線轉接器）；INZONE H9 II 與 H5 耳機；INZONE Buds（USB-C 接收器） | 輸入報告；INZONE 廠商通訊協定 |
| **Fractal Design** | Scape 耳機透過其 2.4 GHz 接收器或 USB-C 連接線 | 出自 Fractal Adjust Pro 網頁應用的廠商 `GET_DEVICE_STATE` 查詢（用途頁面 FF00） |
| **Jabra** | 所有支援 GN 通訊協定的 Jabra 耳機（Evolve2 / Evolve3 等），透過自帶 USB 線或 Jabra Link 接收器連線；無須產品 ID 清單，排除 DECT 底座（Engage、PRO 9xx、GO 6400、Link 400）；直接從耳機讀取名稱 | 在用途頁面 FF00、用途 05 或 01 上發送 GNP 狀態查詢（class 12 / op 02），GNP 位址為 08（USB）或 04（接收器） |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro（`37D7:2401`），2.4 GHz 接收器或 USB；Apex 5（`37D7:2501`），2.4 GHz 接收器或 USB | 在 `FFA0:0001` 上的廠商 HID 資訊查詢；0–5 電量等級對應至 0–100%（以 20% 為一階），含充電狀態；無需 Space Station 服務 |
| **GameSir** | Nova Lite、Nova 2、Nova 2 Lite 透過 2.4 GHz 接收器；Nova 2 Lite 透過 USB；G7 Pro（已實測：絕區零聯名版，接收器 `3537:105E`）與其他處於 Xbox (GIP) 模式的 GameSir 手把；Cyclone 2（XInput 模式，接收器或連接線）；Cyclone Pro 透過 2.4 GHz 接收器（`3537:1015`，須先透過藍牙與 Windows 配對一次） | 廠商裝置資訊查詢（用途頁面 FF7A）；Xbox 模式下使用 Windows.Gaming.Input 電量報告（真實百分比）；Cyclone 2：廠商電量請求（用途頁面 FFF0）；Cyclone Pro：透過藍牙低功耗（服務 `0x8650`）發送 GameSir App 基本資訊請求，每 2 分鐘讀取一次 |
| **BEITONG** | KP20 / BTP-KP20 透過其 2.4 GHz 接收器（`20BC:5128`，XInput 模式，已實測）與 KP40D / BTP-KP40D 透過其接收器（`20BC:515C`，XInput 模式）；無需 BEITONG iControl | 在用途頁面 `00FF` 上發送廠商「取得基本資訊」查詢（報告 `02`，半位元組打亂編碼酬載），含充電狀態 |
| **8BitDo** | Ultimate 2 Wireless（2.4 GHz 接收器上已實測 X-input `2DC8:310B`，D-input `2DC8:6012` — 開機時按住 B 鍵，韌體 1.03+）、Ultimate 2C Wireless、Ultimate 三模、Ultimate 2.4G、Ultimate Bluetooth、Pro 3、Pro 2、SN30 Pro、SF30 Pro | 廠商 HID 狀態查詢（`FF7A`/`FFA0`）與 SDL 遊戲手把輸入報告 `01`/`04`，含充電狀態 |
| **Samsung** | Galaxy Buds、Buds+、Buds Live、Buds Pro、Buds2、Buds2 Pro、Buds FE、Buds Core、Buds3 / Buds3 Pro / Buds3 FE（藍牙） | 耳機透過 Samsung RFCOMM (SPP) 服務主動推送的狀態幀，唯讀。系統匣顯示電量較低的一耳；工具提示會列出左耳、右耳與充電盒。必須關閉 Galaxy Buds 應用程式 |
| **Nothing / CMF** | Nothing Ear (3a)（已實測）、Ear (a)、Ear (2)、Ear、CMF Buds（藍牙） | 在 Nothing 的 NT Link RFCOMM 服務（`aeac4a03-dff5-498f-843a-34487cf133eb`）上執行唯讀 `0xC007` 電量查詢。系統匣顯示電量較低的一耳；工具提示列出左耳、右耳與充電盒 |
| **Akko** | Akko Air 01（`3151:5006`，2.4 GHz 接收器，已實測）與 Akko V9 Dash Pro（`38EE:000C`，2.4 GHz 接收器，已實測） | Air 01：Rongyuan `0xF7` 狀態報告；V9 Dash Pro：在 `FF1C:0092` 上發送唯讀 64 位元組 `0x1A` 狀態查詢，含充電狀態 |
| **MOONDROP** | GM01 Pro 耳機透過其 2.4 GHz 接收器（`35D8:0133`）；使用 USB 線連接時顯示充電中與最後已知電量 | 在報告 `4B` 上發送 WalkPlay 廠商讀取指令（唯讀） |
| **VGN** | OMNISOUND（宙聽 / ZHOUTING）耳機透過其 2.4 GHz 接收器（`372E:10BB`，已實測） | V HUB「ZHOU」查詢：在控制集合 `000C:0001`（32 位元組輸入、64 位元組輸出報告）發送輸出報告 `55` 與酬載 `65 01`；百分比會於回應中傳回（唯讀） |
| **JBL** | Quantum 650 Wireless（已實測，2.4 GHz 接收器）；Quantum 520、650X、850、950、950X Wireless（接收器或 USB 線，相同通訊協定，未實測） | 查詢電量功能的 JBL "HIDV3" 裝置資訊請求（用途頁面 FF12），含充電狀態 |
| **JBL** | Quantum 350 Wireless（已於 Windows 搭配 `0ECB:206B` 2.4 GHz 接收器實測）；Quantum 610 Wireless（`0ECB:205C` 2.4 GHz 接收器，Windows 未實測）；Quantum 360 Wireless（`0ECB:2115` 2.4 GHz 接收器，未實測） | 取得無線連線狀態與電量百分比的 HIDV1 功能報告 |
| **Xbox** | 透過 Xbox 無線轉接器、USB 或藍牙連線的控制器；插在控制器上的耳機 | Windows.Gaming.Input 電量報告（真實百分比），無法取得時退回 XInput |
| **Switch Pro 相容手把** | 識別為 `057E:2009` 的控制器（已實測：GameSir Tarantula Pro 在 Switch 模式下透過 2.4 GHz 接收器連線） | 在 Steam 輸入或其他主機程式啟用完整報告後，從 HID 報告 `0x30` 讀取五段電量等級 |
| **Apple AirPods / Beats** | AirPods Max（已實測，Lightning `200A` 與 USB-C `201F`）、AirPods Pro 3（已實測，`2027`）、AirPods Pro 1 / 2、AirPods 1–5 與 Beats 耳罩式 / 入耳式耳機 | 藍牙低功耗「鄰近配對」（`0x07`）廣播（AirPods Max 與 Beats 耳罩式耳機顯示單一電量；入耳式耳機以 10% 為單位顯示左耳、右耳與充電盒電量及充電狀態），依已配對型號進行比對 |
| **手機（手機連結 / Phone Link）** | 任何透過 Wi-Fi 或藍牙與 Microsoft 手機連結（Phone Link）連線的 Android 手機（已實測：Nothing Phone (4a) Pro） | 從手機連結的 Windows 11 開始功能表卡片檔案（`StartMenuCompanion.json`）讀取電量與充電狀態；無需藍牙連線 |
| **Darmoshark** | 在 Windows 上透過 2.4 GHz 接收器連線的 M3（`248A:FF30`）與 M3S（`248A:FF31`） | 讀取滑鼠身分識別與電量的 HID 功能報告 |
| **Darmoshark** | M3S Pro 透過 Nordic 1K 接收器（`1915:0723`） | `FF0A` 集合上的廠商 HID 狀態查詢 |
| **Alienware** | AW920H 耳機透過其 2.4 GHz 接收器（`413C:A515`，已實測）；透過藍牙連線時由藍牙項目涵蓋 | 在 `FF13:0001` 上發送廠商查詢 `06 C0 0A`，回應報告 `07` 附帶 XOR 校驗碼；依據 Alienware Command Center 的 AW920H 外掛程式解析電量、充電狀態與極低電量欄位 |
| **Niceboy** | MW400 透過其 2.4 GHz 接收器（`248A:FA02`，已實測） | 唯讀報告 `05` 查詢 `24 FA 48`；依據原廠應用程式查表將電池電壓對應為 10% 階梯電量，含充電旗標 |
| **藍牙** | 任何會在 *設定 → 藍牙與裝置* 中顯示電量的裝置（真無線耳機、頭戴式耳機、BLE 滑鼠與鍵盤）。支援 Google Fast Pair 的耳機（Jabra Elite 8 Active 已實測；Pixel Buds 及多款 Sony / JBL / Bose 型號）也可取得左耳、右耳與充電盒電量 | Windows 裝置屬性；Fast Pair 電量廣播（BLE 服務資料 `FE2C`），依藍牙位址與已配對裝置比對 |
| **通用 HID** | 回報標準 HID *Battery Strength* 用途的裝置 | HID 用途頁面 0x06 / 0x85 |
| **HeadsetControl** | [其支援的每一款耳機](https://github.com/Sapd/HeadsetControl#supported-headsets)（Audeze、Jabra、Sony INZONE、新款 Logitech 等） | 內建於安裝檔中；執行 `headsetcontrol -o json` |
| **MAONO PD200W** | 2.4 GHz 接收器（`352F:040E`） | 電量百分比；已實機測試 |


**已於實體硬體實測：** Glorious Model O Wireless、HyperX Cloud III Wireless、HyperX Cloud Stinger Core Wireless（PlayStation 接收器 `0951:1713`；充電尚未測試）、HyperX Cloud Core Wireless DTS（接收器 `0951:173F`；滿電數值尚未測試）、HyperX Pulsefire Haste 2 Core Wireless（接收器 `03F0:0AB5`；Haste 2 Wireless 接收器尚未測試）、Cooler Master MM712（接收器）、Rapoo VT3 Max Gen 2（接收器 `24AE:1417` 與 USB 線 `24AE:4617`；其他 Rapoo 型號尚未測試，請參閱 [Rapoo 通訊協定說明](#sec-rapoo)）、Redragon M916 Pro 1K（接收器 `3554:F55D`）、Taidu（鈦度）TSG808（接收器 `3554:F5D5`）、Redragon M915RGB-WL（接收器 `25A7:FA07`；其他 Areson 型號尚未測試，請參閱 [Areson 通訊協定說明](#sec-areson)）、SteelSeries Rival 650 Wireless（接收器 `1038:1726` 與 USB 線 `1038:172B`）、SteelSeries Arctis Nova Pro Wireless（底座 `1038:225D`；已測試電量讀取，充電與開關機切換尚未測試）、HECATE G5M PRO（接收器 `35BB:D3FB`）、WLMouse YING Magnesium（8K 接收器 `36A7:A874`）、ATK N9 Ultra（接收器 `373B:1204`）、Corsair Scimitar Elite SE Wireless（Slipstream 接收器 `1B1C:2B00`）、Corsair Dark Core RGB Pro SE（Slipstream 接收器 `1B1C:1BDC`）、Corsair Sabre V2 Pro Ultralight（2.4 GHz 接收器 `1B1C:2B2A`；已驗證電量讀取）、DAREU EM901X（接收器 `260D:1074`；充電與休眠/喚醒尚未測試）、Jabra Evolve3 75 搭配 Link 390（`0B0E:2E51`）、MCHOSE G3 V2（接收器 `3837:4245` 與 USB 線 `3837:418C`）、MCHOSE K7 Ultra（接收器 `3837:1001`）、MCHOSE K7 V2 Ultra+（接收器 `3837:1014` 與 USB 線 `3837:4028`；插線時會顯示充電中）、MSI VERSA 300 ELITE WIRELESS（接收器 `0DB0:9E22`；充電與休眠處理尚未測試）、MSI Clutch GM31 Lightweight Wireless（接收器 `0DB0:0D3C`；GM41 依據持有者擷取的封包共用同一驅動程式）、AJAZZ AK820 MAX（接收器 `05AC:024F`）、AULA HERO 68 Air（8K 無線接收器 `372E:106C`）、AULA SC580（USB 線 `088D:062E` 與接收器 `089D:062F`，含充電與休眠）、AirPods Pro 3（藍牙，型號 `2027`）、AirPods Max（藍牙，型號 `200A`）、Sprime PM1（接收器 `1915:AC1C`）、Ninjutso Ten Air（接收器 `093A:EB01` 與 USB 線 `093A:E020`）、MOONDROP GM01 Pro（接收器 `35D8:0133`）、Delux M800 Pro（接收器 `248A:5B2F`）、Razer Barracuda X (2022)（接收器 `1532:0550`；已讀取電量，充電切換尚未測試）、Razer BlackShark V3 X（HyperSpeed 接收器 `1532:057D`）、Fantech Helios Go XD5（接收器 `25A7:FA7C`）、Fantech Raigor III（接收器 `1EA7:0066`；韌體未回報充電狀態）、Finalmouse UltralightX（接收器 `361D:0100`）、Finalmouse Starlight X（透過其接收器），以及 Chimera V2（接收器 `3554:F512`；已讀取電量與充電狀態）。
同樣已實機測試：Machenike L7 Arctic / L7 Mix（`248A:FF4C` 接收器與 `248A:FF4E` 連接線），含充電與連接線 / 接收器重複項目合併抑制。藍牙與低電量 / 滿電邊界未經實機測試。
同樣已實機測試：MCHOSE V9 Pro 2（`3837:6011` 接收器）；已讀取電量，充電與休眠未測試。
同樣已實機測試：EPOMAKER EA75 透過其 `05AC:024F` 2.4 GHz 接收器，使用來自 [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60) 的既有 SONiX 驅動程式。已驗證電量百分比、接收器重新連線與開機恢復。此驅動程式不支援充電指示與有線電量回報；藍牙電量回報未測試。插上 USB 電源時回報的百分比可能會跳至 100%，因此不可視為可靠的充電指示。
同樣已實機測試：SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition（接收器 `1038:1878` 與 USB 線 `1038:187A`），包含充電、關機（保留上次電量並變暗）以及在 SteelSeries GG 執行時同時運作；GG 僅顯示三段式電量條，與本程式讀數相符。
同樣已實機測試：RAWM Leviathan V4（RAWM HS Receiver `1915:2346`；已讀取電量，充電未測試）。
**依據通訊協定文件與其他專案實作、尚未實機測試：** 其餘所有裝置，包含 Fantech Raigor II WG10（與已實測的 Raigor III 使用相同的 `1EA7:0066` 接收器與集合，因此應可正常運作）。如果您擁有其中任何一款裝置，歡迎[建立 Issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues) 回報是否正常運作。

## 安裝

[![最新版本](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. 從[最新版本頁面](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)下載 **`BatteryHub-Setup-<version>.exe`**。
2. 執行安裝程式，從支援的 19 種安裝語言中任選一種，依步驟點擊安裝即可。**無需系統管理員權限**，也**不需要額外安裝任何元件**：無需執行環境、無需額外驅動程式，也無需安裝原廠軟體。HeadsetControl 已隨附於內，且可編輯的 `lang\` 資料夾會安裝在 `BatteryHub.exe` 同層目錄中。

安裝程式會建立開始功能表捷徑與解除安裝項目（*設定 → 應用程式*），並可設定於登入時自動啟動。不想使用安裝程式嗎？您可以下載 `BatteryHub-<version>-portable.zip`，解壓縮到任意位置（請將 `lang\` 資料夾保留在 `BatteryHub.exe` 同層以使用介面翻譯），然後直接執行 `BatteryHub.exe`。

**注意事項：**
- **SmartScreen 警告：** 由於執行檔未經程式碼簽署，Windows 可能會顯示「Windows 已保護您的電腦」。點擊 *其他資訊 → 仍要執行*，或自行從原始碼建置。
- **Windows 11 上的系統匣圖示模式：** 新增的系統匣圖示預設會收進 `^` 溢位區。您可以直接將它們拖曳到工作列上，或在 *設定 → 個人化 → 工作列 → 其他系統匣圖示* 中啟用顯示。
- **讓應用程式略過特定裝置：** 若某個裝置在程式執行期間出現異常行為，請在登錄檔 `HKCU\Software\WirelessBattery` 下的字串值 `IgnoreDevices` 中列出其 `VID:PID`（十六進位，以逗號分隔，例如 `28BD:0947, 1234:ABCD`；`--dump` 可查看各裝置 ID），程式便永遠不會開啟該裝置。繪圖板會自動略過。

## Windows 更新

官方穩定版 Windows 建置會在啟動後 30 秒及執行期間每 24 小時，於背景檢查專案最新發佈的穩定版本。開啟選單即可看到 **有可用更新：vX.Y.Z...**，或自行點擊 **檢查更新...**。更新資訊只會顯示在這個選單內：電量圖示、百分比與工具提示都維持不變，自動檢查絕不會彈出通知或對話方塊。關閉選單中的 **自動檢查更新** 即可停用背景檢查。

對於安裝版程式，點擊更新項目並選擇 **下載並安裝**。除非您點擊該按鈕，否則不會安裝任何內容。程式會下載該發佈版本的 `SHA256SUMS.txt` 與其簽章，使用內建於應用程式中的維護者公開金鑰驗證簽章，接著下載 Windows 安裝程式，並僅在檔案大小與 SHA-256 符合已簽署清單（以及 GitHub 所列資訊）時才會執行安裝。隨後會就地更新現有安裝，保留您的設定與開機啟動偏好，並在安裝完成後重新開啟應用程式。若為所有使用者安裝，可能會要求系統管理員權限。點擊 **發行說明** 會開啟官方發佈頁面；點擊 **稍後** 則保留目前版本。可攜版會引導開啟發佈頁面以供手動下載 ZIP 檔案。

檢查更新時會連線至 GitHub 公開 API，無需帳號或權杖，也不會傳送任何裝置或電池資訊。離線失敗與 GitHub 速率限制都不會中斷電量監控；先前偵測到的新版本會持續保留在選單中，直到有更新版本取代或完成安裝為止。取消下載時，會等待目前的網路作業在有限逾時時間內結束。安裝程式絕不會自動重新啟動 Windows。

**為什麼此更新機制可以安心安裝：** 簽署金鑰永遠不會上傳到 GitHub。維護者會在自己的電腦上為每個版本的雜湊清單進行簽署（參閱 [docs/releasing.md](#sec-releasing)），因此即使有人入侵了 GitHub 帳號或其建置工作流程，也無法發佈可通過應用程式驗證的更新。缺少有效簽章的發佈版本雖會顯示在選單中，但僅能手動下載。此簽章機制不會取代 Windows 本身的 SmartScreen 或 UAC 提示。

首次使用此功能前請先手動安裝包含該功能的版本一次。開發 / 測試建置會停用官方更新檢查，以免意外覆寫本機修改。Linux 版的自動更新與可攜版自動替換功能目前暫緩支援。

## 命令列

```
BatteryHub.exe --list     # 輸出所有裝置與電量，然後結束
BatteryHub.exe --json     # 以 JSON 陣列輸出裝置與電量，然後結束
BatteryHub.exe --dump     # 輸出所有 HID 集合、無法開啟的 HID 裝置、所有 USB 裝置（包含
                               # 無 HID 介面的裝置）與藍牙裝置；同時儲存至 %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # 開啟「請求支援某個裝置」視窗
BatteryHub.exe --demo     # 顯示各品牌的範例裝置以取代真實裝置（用於截圖、檢查顏色）
BatteryHub.exe --quit     # 關閉正在執行的執行個體
```

Linux 版本使用相同的旗標（將 `BatteryHub.exe` 換成 `wireless-battery`），且額外支援 `--help`。`--json` 會輸出結構穩定的陣列，方便腳本與狀態列小工具解析：

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` 表示裝置進入休眠時，程式繼續保留顯示最後已知電量的秒數。日後新增欄位皆會維持向下相容。

**找不到您的裝置嗎？** 在小工具或系統匣圖示上按右鍵並選擇 **請求支援某個裝置...**。選取該裝置、檢查即將送出的內容（畫面上會逐字顯示：裝置名稱、類型、USB/HID ID 與介面配置，以及您選填的姓名與備註），然後點擊 **送出**。它會加入位於 [krisgfx.com/tools](https://krisgfx.com/tools/#requested) 的公開請求清單，並建立或更新一個 GitHub Issue。**複製完整報告** 會將完整的 `--dump` 輸出複製到剪貼簿，方便您貼進 Issue。只有在您點擊「送出」時才會傳送回報資料。官方 Windows 版本亦會依 [Windows 更新](#windows-更新) 所述連線至 GitHub 檢查更新；更新檢查不會傳送任何裝置或電池資訊。

## 建置

您需要 [MinGW-w64](https://www.mingw-w64.org/)，例如透過 [MSYS2](https://www.msys2.org/) 安裝（`pacman -S mingw-w64-x86_64-gcc make`）。

```
make                                      # 開發建置，版本 0.0.0
build.bat                                 # 在 PATH 含 g++ 與 windres 的一般 cmd 下建置
make VERSION=1.2.3 CHANNEL=test            # 帶版本號建置，停用官方更新
build.bat 1.2.3 test                       # 同等的 cmd 帶版本號建置
make test VERSION=1.2.3 CHANNEL=test       # 裝置與更新器迴歸測試
```

若要建置安裝程式與可攜版 ZIP，請安裝 [Inno Setup](https://jrsoftware.org/isinfo.php)，先使用目標版本進行建置（例如 `make VERSION=1.2.3 CHANNEL=test`），然後執行 `powershell -File installer\build-installer.ps1 -Version 1.2.3`。打包腳本若發現版本與執行檔不一致將會拒絕打包。腳本會下載指定版本的 HeadsetControl 並驗證其雜湊值。GitHub Actions 會自動完成上述全部流程：推送如 `v1.0.0` 的標籤後，即會發佈包含安裝程式、可攜版 ZIP 與 HeadsetControl 原始碼（依其 GPL 授權條款要求）的 Release。

Windows 建置也需要 PowerShell 來產生共用的執行檔 / 資源版本標頭。官方儲存庫的版本標籤會以 `CHANNEL=stable` 建置；本機建置預設為 `dev`。Fork 與 Pull Request 不會自動啟用官方更新通道。

`BatteryHub.exe` 也能單獨運作。若同目錄（或 `PATH`）中沒有 `headsetcontrol.exe`，僅會少掉額外支援的耳機裝置。

## Linux（實驗性功能）

除了 Windows 應用程式之外，本專案也提供 Linux 版本。它共用相同的廠商驅動程式邏輯，並採用基於 hidraw 的 HID 後端與 GTK4 StatusNotifierItem 系統匣圖示；Windows 程式碼路徑完全不受影響。所有 Linux 專用檔案都位於 `linux/` 與 `src/linux/`，並透過 `build-linux.sh` 建置（Windows 仍維持使用 `build.bat`）。

| | Fedora | Ubuntu / Debian |
|---|---|---|
| 編譯器與 make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

不需要額外的 HID 函式庫（直接使用 hidraw）。

```sh
./build-linux.sh
./build-linux.sh test         # HID 報告描述元解析器單元測試
./wireless-battery --list     # 輸出偵測到的電量並結束
./wireless-battery --dump     # 列出所有 HID 集合
./wireless-battery --quit     # 關閉正在執行的系統匣執行個體
```

存取 HID 需要設定 udev 規則，否則程式雖可啟動但無法偵測到任何裝置：

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# 登出並重新登入
```

系統匣圖示在 KDE Plasma 上可原生運作；GNOME 則需要安裝如 `gnome-shell-extension-appindicator` 等 AppIndicator 宿主擴充套件。可透過 *語言* 子選單切換多國語言（預設依序跟隨 `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG`，且 `--help` 亦會套用在地化文字）。執行 `make -f linux/Makefile.linux install` 會將執行檔安裝至預期路徑、將 `lang/*.json` 安裝至 `$(PREFIX)/share/wireless-battery/lang/`，並將桌面啟動器（`linux/wireless-battery.desktop`）與 `linux/wireless-battery.svg` 安裝至 `$(PREFIX)`（預設為 `~/.local`）；使用者自訂語言覆寫檔則存放於 `~/.config/wireless-battery/lang/`。

第一階段支援 Logitech、Razer、SteelSeries、Corsair、HyperX、PlayStation、Cooler Master、Glorious、Finalmouse 以及共用的 Kysona/Pulsar/ATK/G-Wolves 通訊協定。藍牙/UPower 後備方案、HeadsetControl 以及其餘廠商則規劃於後續階段加入。

## 使用限制

- **工作列擁擠：** 當置中的 Windows 11 工作列圖示非常滿時，應用程式按鈕可能會延伸覆蓋到小工具位置。在 Windows 10 上，工作按鈕區域則會自動縮窄。
- **手機：** 電量讀取自「手機連結」（Phone Link）為開始功能表隨附卡片寫入的檔案，這並非公開文件化的 API，未來可能會隨手機連結更新而變動。當手機連結回報手機已連線時即會顯示；超過 3 小時未更新的卡片會顯示為暗淡狀態。卡片亦會標示手機是否正在充電，畫面會以充電閃電圖示表示。
- **休眠中的裝置：** 處於休眠狀態的裝置可能不會回應查詢，系統會將上次已知的數值以暗淡方式繼續顯示。Logitech 接收器會將休眠裝置從連線中移除，因此其最後讀數會保留顯示 30 分鐘。
- **HECATE G2 Wireless 7.1 耳機**（2.4 GHz 接收器 `35BB:A009` / `A209`）：其接收器的電量查詢方式尚未見諸公開文件，因此目前無法讀取。請在 HECATE 官方軟體顯示耳機電量時擷取 USB 封包（參閱 [CONTRIBUTING.md](#sec-contributing)），這是新增支援的方式。
- **Keychron 鍵盤：** 搭配原廠韌體時僅會透過藍牙回報電量（由藍牙支援顯示）。若要透過 2.4 GHz 接收器或連接線顯示電量，則需要刷入包含電量修補程式的韌體（[docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)）；透過 Keychron Launcher 更新鍵盤韌體將會覆寫並移除此功能。Keychron 滑鼠則直接支援。
- **Baseus AeQur GH02 耳機：** 其 2.4 GHz 接收器（`10D6:4802`，Actions 晶片）僅傳輸音訊、媒體鍵與晶片韌體更新通道，並不傳輸電量資訊。請透過藍牙連線耳機以查看電量（當 Windows 有回報電量時，會透過藍牙支援顯示）。
- **Weikav Lucky65 v1 鍵盤：** 其韌體不會透過 2.4 GHz 接收器（`0603:0351`，Novatek 晶片）回報電量。該鍵盤沒有查詢電量的快捷鍵，且官方設定軟體僅支援透過 USB 線連線、不支援透過接收器連線，因此沒有任何電量讀數可供顯示。
- **Rapoo：** 支援的 VT 系列滑鼠為主動推送狀態，因此每次重新整理在每個相符介面上最多可能等待 4 秒。休眠中的滑鼠會以暗淡方式保留最後讀數最多 30 分鐘。支援範圍僅限 Nordic 54L 報告 `07` 與舊款 `BB`（VT3 Pro、VT1 Pro Max）；CH584 報告 `08`、辦公系列 MT/M 滑鼠與其他韌體通訊協定皆未包含在此驅動程式內。
- **GameSir Cyclone Pro：** 其接收器不傳送電量資訊，因此程式是透過藍牙低功耗從手把讀取電量。請先將手把與 Windows 配對一次（設定 > 藍牙與裝置 > 新增裝置 > 藍牙 > `GameSir-Cyclone Pro`），之後仍可繼續透過接收器遊玩。電腦需要支援藍牙。電量每 2 分鐘更新一次，且充電中無法取得百分比。若未進行藍牙配對，接收器只會顯示為滿電（Full）的 Xbox 控制器。詳細資訊請參閱 [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro)。
- **RAWM：** 程式透過接收器向滑鼠查詢電量，因此休眠中的滑鼠不會回應；它會以暗淡方式保留最後讀數最多 30 分鐘，且在休眠期間每次重新整理會多花約 1 秒等待。僅在 RAWM HS Receiver（`1915:2346`）上的 Leviathan V4 經過實機測試；其餘型號取自 RAWM HUB 的裝置清單。Leviathan V4 GT 與 NYX60（VID `373E`，RAWM HUB 3.0）以及 RAWM HS 鍵盤採用其他通訊協定，故不在支援範圍內。
- **Flydigi：** 此驅動程式針對 Vader 5 Pro 與 Apex 5 設計；藍牙連線及其他 Flydigi 型號（例如 Apex 6）不在支援範圍內。顯示的百分比代表粗略電量等級。Apex 5 已於 2.4 GHz 接收器與 USB 連接線上實機測試；Vader 5 Pro 則依據 SDL 與 Windows 硬體追蹤紀錄實作。
- **尚未支援：** 除了 VERSA 300 ELITE 與 CLUTCH GM31 / GM41 以外的 MSI 無線滑鼠、MSI 無線鍵盤、Razer Kraken 耳機與除了 `1532:0550` 上 Barracuda X (2022) 以外的 Barracuda 型號、除了 Haste 2 Wireless / Haste 2 Core Wireless 以外的 HyperX Pulsefire 滑鼠，以及接在 Xbox 轉接器上的 Xbox 無線耳機：這些裝置的電量通訊協定皆尚未有公開文件。Xbox 無線耳機透過藍牙連線時可以正常顯示。由裝置持有者提供 USB 封包擷取（參閱 [CONTRIBUTING.md](#sec-contributing)）是新增支援的方法。
- **其他裝置：** 部分 2.4 GHz 裝置採用未公開的專有通訊協定，因此尚未獲得支援。請參閱 [CONTRIBUTING.md](#sec-contributing) 了解如何協助新增裝置支援。

## 運作原理

[`src/drivers/`](../../src/drivers) 中的每個廠商驅動程式都會依據 USB 廠商與產品 ID 辨識所屬裝置，且僅發送唯讀的電量查詢請求。絕不會對未知裝置進行寫入操作。通用的後備機制（HID 電量用途、藍牙、XInput、HeadsetControl）只會檢查尚未被任何廠商驅動程式認領的裝置。

工作列小工具是一個附屬於 `Shell_TrayWnd` 的分層子視窗，配置於 `TrayNotifyWnd` 左側。若檔案總管（Explorer）重新啟動，小工具會自動重新建立。

## 翻譯

每一種介面語言都是存放在 [`lang/`](../../lang) 中的純靜態 UTF-8 文字檔：等號左側為英文原文，右側為對應翻譯。語言檔案是在執行期直接從磁碟載入，而非編譯進執行檔中，因此您可以直接編輯而無需重新建置。

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **應用程式介面（Windows 與 Linux）：**
  - 直接編輯或新增 `.json` 檔案於 `BatteryHub.exe` 同層的 `lang/` 資料夾內（在 Linux 上則為 `/usr/share/wireless-battery/lang/`、`/usr/local/share/wireless-battery/lang/`、`$XDG_DATA_HOME/wireless-battery/lang/` 或 `./lang/`）。
  - 或者在選單中選擇 *語言 → 新增你自己的語言...*，程式會以 `_template.json` 為您建立使用者覆寫資料夾（Windows 為 `%APPDATA%\WirelessBattery\lang`，Linux 為 `~/.config/wireless-battery/lang`）。將 `_template.json` 複製為例如 `it.json`，填寫 `@code`、`@name` 與各項翻譯後，就會立即出現在選單中（無需重新啟動）。使用者資料夾中的檔案會覆寫相同 `@code` 的內建字串。
  - 請保持 `{placeholders}` 原封不動，若是從右到左書寫的語言請加上 `"@rtl": true`。留空的句子會維持英文原文，因此部分翻譯也可以正常使用。
  - `--list` 與 `--dump` 的輸出刻意維持英文，以便直接貼入 GitHub Issue 中進行除錯。
- **Windows 安裝程式：** Inno Setup 翻譯位於 [`installer/lang/`](../../installer/lang)（以含 BOM 的 UTF-8 儲存），並在 `installer/BatteryHub.iss` 的 `[Languages]` 區段中註冊。
- **文件：** 所有可見專案文件都以每種語言一份獨立 Markdown 檔案的形式翻譯於 [`docs/i18n/`](README.md)（請參閱 [`docs/i18n/_template.md`](_template.md)，無需任何建置腳本即可新增語言）。
- **分享給大家：** 發送 Pull Request 新增您於 `lang/`、`installer/lang/`、`linux/wireless-battery.desktop` 與 `docs/i18n/` 中的翻譯檔案。逐步檢查清單請參閱 [`docs/i18n/README.md`](README.md)。

## 致謝

應用程式圖示由 [nik-txt](https://github.com/nik-txt) 設計（[`res/app.svg`](../../res/app.svg)）。

各項通訊協定來自以下專案的研究成果：

- [Google Fast Pair 規格書](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification)：Fast Pair 耳機的左耳 / 右耳 / 充電盒電量廣播
- [HeadsetControl Astro 驅動程式](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp)、[eh-fifty](https://github.com/tdryer/eh-fifty) 與 [AstroBar](https://github.com/nichtlegacy/AstroBar)：Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 電量通訊協定；[OpenAstroCC](https://github.com/BenStein1/OpenAstroCC)：A50 Gen 3 `0x72` 狀態讀取

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor)（stuffz）：VAXEE 電量與充電指令（[通訊協定文件](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md)）

- [HeadsetControl](https://github.com/Sapd/HeadsetControl)：SteelSeries、Corsair、HyperX、Logitech 與 Sony INZONE 耳機
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray)（kinako19）與 [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray)（takamachi66）：Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer)：Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) 與 Logitech HID++ 2.0 文件：Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) 與 [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery)：Logitech G435（`0ADF` 接收器）
- [rivalcfg](https://github.com/flozz/rivalcfg)：SteelSeries 滑鼠（Rival Pro 出自其 pull request #294）
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) 與 [glorious-ctl](https://github.com/louis4craft/glorious-ctl)：Glorious
- Hitscan 網頁設定工具（[control.hitscan.com](https://control.hitscan.com)）：Hitscan
- Linux `hid-kysona`（Lode Willems）：Kysona、Pulsar 與 ATK
- ATK 網頁設定工具（[hub.atk.pro](https://hub.atk.pro)）：ATK 滑鼠與 N9 Pro / N9 Ultra 耳機
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery)：Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 與 [mouse-battery](https://github.com/qwr79/mouse-battery)：ATK / VXE NK NANO 接收器
- [HaloBattery](https://github.com/HeyOkay/HaloBattery)（MIT）：Audeze Maxwell、NZXT Lift Elite、Poly BT600、Razer Barracuda Pro、SteelSeries Arctis Nova Elite、ATK V75X 與 Endgame Gear XM2we，移植自其各別驅動程式（每個驅動檔案皆已註明來源）
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` 與 [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700)（PaulRichez，MIT）：Turtle Beach Stealth 700 Gen 3；[Neap](https://github.com/lykosapps/Neap)（僅參考研究成果）：Turtle Beach Swarm II 裝置系列
- G-Wolves 網頁驅動程式（[mouse.xyz](https://mouse.xyz)）：G-Wolves 型號與其通訊協定
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch)：2.4 GHz 接收器上的 CHERRY 鍵盤（幀格式與電量查詢）
- Keychron Launcher（[launcher.keychron.com](https://launcher.keychron.com)）：Keychron 滑鼠
- [NinjaForce](https://www.ninjaforce.co/) 與 [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray)：Ninjutso Ten / Ten Air 功能報告查詢
- [nape_pro](https://github.com/nvalis/nape_pro) 與 [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget)：Link-KM 接收器上的 Keychron Nape Pro
- LAMZU Aurora（[lamzu.net](https://www.lamzu.net)）：LAMZU 滑鼠
- [vole](https://github.com/johanneszab/vole) 與 [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator)：Endgame Gear 4K 滑鼠
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) 與 [HaloBattery](https://github.com/Waturus/HaloBattery)：WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) 與 [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher)：Finalmouse UltralightX / Starlight X（出自 Finalmouse 的 xpanel）
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) 與 [g49-web-control](https://github.com/pingpingjinping/g49-web-control)：Redragon 裝置 ID
- [m913-ctl](https://github.com/Qehbr/m913-ctl) 與 [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray)：Areson `25A7` 幀結構與 `GetPower` 指令
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper)：ASUS ROG；[pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch)：ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) 與 [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray)：ZOWIE EC-CW 與 DW
- RK 網頁驅動程式（[drive.rkgaming.com](https://drive.rkgaming.com)）：Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor)：MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver)（MIT）、[HaloBattery](https://github.com/HeyOkay/HaloBattery)（MIT）、[mchose-macos](https://github.com/Klegus/mchose-macos)（MIT）與 [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol)（文件）：MCHOSE A5 Pro / A5 Pro Max（第一代，VID `2023`）
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6)、[omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900)、[aj179-linux](https://github.com/Rockeyxx/aj179-linux)：Motospeed、Delux、Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery)：Delux M900 Pro 的 CompX 接收器報告
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) 與 [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2)：Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager)、[incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) 與 [MouseBattery](https://github.com/FelixNg21/MouseBattery)：Incott
- Wraith 網頁驅動程式（[w1.software](https://www.w1.software/)）：Wraith W1
- OpenRazer PR #2794 與 [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3)：BlackShark V3
- OpenRazer PR #2862 與 [HaloBattery](https://github.com/HeyOkay/HaloBattery)：BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) 與 [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery)：`1532:0550` 接收器上的 Razer Barracuda X (2022)；[razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray)：`1532:0552` 接收器的封包格式
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899)：BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM)：HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset)：HyperX Cloud III S、Cloud II Core、Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor)：HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray)：Rongyuan 與 Xenta 接收器（Attack Shark 與其他品牌）
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio)：2.4G 接收器上的 SONiX 鍵盤（AJAZZ AK820 MAX、AK980 V2、AULA F108 Pro）；[ak820-rs](https://github.com/deddroid/ak820-rs) 與 [ak820-studio](https://github.com/usharik/ak820-studio)：AJAZZ AK820 Pro 接收器 `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) 與 [Kraber](https://github.com/AkashPanja/Kraber)：Attack Shark X98 與 AJAZZ AK820 Max Plus 的 Semico `1A2C`（`AA 55 CC 33` / `0x0E`）狀態通訊協定
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) 與 [MM731-Controller](https://github.com/riVFerd/MM731-Controller)：Cooler Master MM712 與 MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) 與 [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection)：GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery)：GameSir Cyclone Pro 藍牙低功耗「base info」電量請求
- [jabridge](https://github.com/Watchdog0x/jabridge)：Jabra GNP 通訊協定（Link 380 / 390 接收器）
- [xd5-go-web](https://github.com/jarjut/xd5-go-web)：Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery)：`1EA7:0066` 狀態頁通訊協定（Fantech Raigor III 與其他通用 2.4G 滑鼠裝置）
- Linux `hid-playstation`：DualShock 4 / DualSense 報告格式
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580)：AULA SC580 / SC580X 廠商通訊協定
- RAWM HUB 網頁應用程式（[rawmtech.com/hub.html](https://www.rawmtech.com/hub.html)，Hub Web 2.0）與其裝置清單：RAWM 滑鼠與 SADES Dagger
- [SDL 的 Flydigi HID 驅動程式](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c)與 [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191)：Vader 5 Pro 與 Apex 5 查詢幀與電量資料結構
- [SDL 的 8BitDo HID 驅動程式](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c)：8BitDo Ultimate 2 電量位元組
- BEITONG iControl（其 KP20 與 KP40D 頁面及 KP20 接收器的 USB 封包流量）：BEITONG KP20 / KP40D 電量查詢與酬載混淆方式
- [SDL 的 8BitDo HID 驅動程式](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c)與 [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux)：8BitDo 電量位元組與廠商 HID 通訊協定
- JBL QuantumENGINE（其 HIDV3 裝置資訊訊息）：JBL Quantum 耳機
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md)：Corsair Sabre V2 Pro Ultralight，`FF02:0002` 上的 Compx 通訊協定
- [MouseDock](https://github.com/late-autumn-gif/mousedock)（MIT）與 [BrimDeck](https://github.com/MoFeng2223/BrimDeck)：Scyrox V12M 設定檔讀取
- JBL QuantumENGINE：Quantum 350 的 HIDV1 連線與電量報告，以及新款 Quantum 耳機的 HIDV3 裝置資訊訊息
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md)：JBL Quantum 610 HIDV1 電量與連線報告，以及 Quantum 系列陣容（360 屬於 HIDV1 接收器型號）

## 授權條款

[GNU General Public License v3.0 或更新版本](../../LICENSE)。您可以自由使用、修改並散布本軟體，但任何基於本軟體進行散布的衍生作品都必須採用相同的授權條款，並公開其原始碼。


---

<a id="sec-contributing"></a>
> 📄 **章節：** 貢獻指南（`CONTRIBUTING.md`） · [英文原文](../../CONTRIBUTING.md) · [↑ 返回頂端](#top)

# 貢獻指南

## 回報裝置是否正常運作

大多數驅動程式皆是依據通訊協定文件編寫而成，無法在每一個型號上親自實機測試。請開啟一個 Issue 並提供以下資訊：

- 裝置名稱，以及它是透過接收器、連接線還是藍牙連線
- `BatteryHub.exe --list` 的輸出結果
- `BatteryHub.exe --dump` 的輸出結果
- 原廠軟體目前顯示的電量百分比

## 新增裝置支援

1. 執行 `BatteryHub.exe --dump`，找出您裝置的廠商 ID 與產品 ID，以及廠商自訂集合（用途頁面 `FFxx`）和其報告長度。
2. 尋找電量讀取通訊協定。值得參考的來源包括：HeadsetControl、OpenRazer、Solaar、rivalcfg、OpenRGB、OpenLinkHub，或是透過 Wireshark + USBPcap 擷取原廠軟體的 USB 封包。
3. 若 `src/drivers/` 中已有該廠商的驅動程式，請在該檔案中加入產品 ID（及任何差異處）。否則請新建 `src/drivers/<vendor>.cpp`：

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

4. 在 `src/drivers/drivers.h` 中宣告函式，並在 `src/devices.cpp` 的 `PollAllDevices()` 中呼叫它（須位於通用後備機制之前）。`build.bat` 與 Makefile 會自動納編新增的檔案。
5. 更新 `README.md` 中的裝置支援表格。

### 驅動程式開發規範

- **唯讀操作：** 只發送讀取狀態的請求。絕不修改裝置設定、燈效或模式。
- **精確比對：** 只對透過廠商與產品 ID（或該通訊協定獨有的廠商專用集合）明確辨識的裝置進行通訊。
- **務必設定逾時：** 遺失或未連線的裝置絕不可讓單次輪詢停滯超過約 1 秒。被動式通訊協定可能需要較長時間以涵蓋其文件規定的推送週期（例如 Delux 與 Rapoo）。請對每個相符的集合保留單一絕對截止時間（最多 4 秒），不要因收到無關的報告而重設該計時器，並在程式註解中說明為何需要此例外處理。
- **註明來源：** 在檔案頂端的註解中引用通訊協定來源。

## 翻譯

介面語言皆為存放在 `lang/` 中的純靜態 UTF-8 文字檔，Windows 與 Linux 版本都會在執行期直接從磁碟載入（將 `lang/_template.json` 複製為 `lang/<code>.json`，填寫 `@code`、`@name` 與對應翻譯——無需重新建置）。程式碼中新增介面文字時應透過 `T(L"...")`，若包含動態變數則使用 `TF(L"... {name} ...", { { L"name", value } })`；切勿以片段拼接的方式組裝翻譯句子。新增字串後，請同步加入 `lang/_template.json`。

Windows 安裝程式翻譯位於 `installer/lang/*.isl`（須以含 BOM 的 UTF-8 儲存，並在 `installer/BatteryHub.iss` 中註冊），Linux 桌面啟動器註解位於 `linux/wireless-battery.desktop`，完整文件翻譯則位於 `docs/i18n/<code>.md`（由 `docs/i18n/_template.md` 複製的單一獨立檔案）。完整貢獻指南請參閱 [`docs/i18n/README.md`](README.md)。

## 程式碼風格

使用 C++17 與純 Win32 API，不引入第三方相依套件。保持執行檔體積小巧。排版格式大致比照現有程式碼（4 個空白縮排、每行 120 字元寬度）。

## Windows 更新程式開發

更新程式僅適用於 Windows，採用 WinHTTP、BCrypt 與既有的 Inno Setup 安裝程式。更新狀態必須僅顯示於選單中；請勿新增更新圖示、徽章、變更電量工具提示內容、氣球通知、Toast 通知或自動跳出的對話方塊。裝置輪詢作業須與網路工作分開執行。

建置版本號與通道透過產生的 `build/version.h` 在 C++ 與 Windows 資源檔之間共用。本機測試請使用 `make VERSION=1.2.3 CHANNEL=test` 或 `build.bat 1.2.3 test`；預設通道為 `dev`，而 `stable` 會啟用官方發佈版本檢查。版本號各欄位數值必須介於 0..65535。只有官方儲存庫的發佈標籤工作流程會自動選用 stable。請勿意外讓 Fork 建置指向官方更新通道。

執行 `make test VERSION=1.2.3 CHANNEL=test` 可跑完既有裝置測試加上嚴格發佈資訊解析、版本排序、檢查排程、真實 SHA-256 檔案校驗、引數跳脫與輔助程式防護等測試。更新程式迴歸測試亦涵蓋下載完成瞬間取消、對話方塊防護，以及設定 HTTP 逾時 / 重新導向限制失敗等情境。Windows 測試遵循既有 Linux 後端測試模式直接納入實作碼，並替換 HTTP 傳送端點以確保測試絕不會連線到 GitHub。正式版程式碼中不加入僅供測試使用的控制器進入點。單獨測試目標為 `make test-update-core` 與 `make test-update-win`。原生更新程式測試會連結應用程式資源檔以啟用 Common Controls v6。所有測試皆使用本機資料，不會進行下載、提權、安裝或變更使用者的開機啟動設定。應用程式的正式更新端點無法於測試中覆寫。

打包之前請先執行 `powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`。`installer/build-installer.ps1 -Version 1.2.3` 在下載相依檔案前也會先執行這項檢查。`/WBUPDATE=1` 安裝程式路徑會保留既有的開機啟動與設定，並交由暫時輔助程式負責重新啟動應用程式。該輔助程式維持在原使用者身分下執行，僅在全域安裝時才請求提升權限。WinHTTP 控制代碼歸背景工作執行緒管理；取消作業是在各個有限逾時的呼叫之間以協作方式完成。最終應用程式關閉時會 join 該背景執行緒，因此可能會等待執行中的網路逾時結束。

發佈審查時，請使用可拋棄式 Windows 帳戶或虛擬機器實際演練兩個真實安裝程式版本、單一使用者 / 全體使用者範圍、UAC 取消、開機啟動開啟 / 關閉、自訂路徑、安裝失敗以及重新啟動流程。單元測試與打包安裝檔無法驗證上述安裝程式實際效果。視覺選單 / 佈景主題檢查與真實安裝程式 / UAC 端對端檢查仍屬於人工發佈把關項目；未實際觀測驗證前不得標記為通過。切勿透過覆寫日常使用者的安裝來進行測試。

## 自動安全檢查

每個 Pull Request 都會由「PR safety check」掃描本應用程式不應出現的行為（網路存取、啟動外部程式、讀取鍵盤 / 剪貼簿 / 螢幕畫面、開機啟動項目、二進位檔案、建置或發佈流程修改）。被標記並不代表遭到拒絕：只需在 PR 說明中解釋被標記的程式碼即可。

歡迎使用 AI 工具協助開發，但請從您的 commit 訊息中移除標示 AI 工具的 `Co-authored-by` 行（例如 `Co-authored-by: Claude ...`）。只要存在這些行，自動安全檢查就會失敗。


---

<a id="sec-pr-template"></a>
> 📄 **章節：** Pull Request 範本（`.github/pull_request_template.md`） · [英文原文](../../.github/pull_request_template.md) · [↑ 返回頂端](#top)

## 本次新增內容

<!-- 裝置名稱與廠商/產品 ID，例如 "Acme M1 (1234:5678)"。 -->

## 通訊協定來源

<!-- 附上來源連結（其他開源專案、廠商網頁驅動程式，或您自己的 USB 封包擷取）。 -->

## 是否已於實體硬體測試？

<!-- 是（測試哪款裝置，--list 輸出內容為何）/ 否 -->

## 檢查清單

- [ ] 僅發送唯讀電量查詢；未修改任何設定、燈效或韌體
- [ ] 僅存取依據廠商 / 產品 ID（或通訊協定專用集合）辨識的裝置
- [ ] 無網路存取、未啟動其他程式，且未在 `src/`、`docs/` 或 `README.md` 之外新增檔案
- [ ] 未包含任何二進位檔案或自動產生的檔案
- [ ] commit 訊息中未包含歸功於 AI 工具（Claude、Copilot、ChatGPT 等）的 `Co-authored-by` 行
- [ ] 若有修改 `.github/`、`installer/`、`build.bat` 或 `Makefile`，已於上方說明原因


---

<a id="sec-releasing"></a>
> 📄 **章節：** 發佈與簽署指南（`docs/releasing.md`） · [英文原文](../../docs/releasing.md) · [↑ 返回頂端](#top)

# 發佈與簽署

應用程式會從 GitHub Releases 自我更新，但它只會安裝 SHA-256 列於以發佈金鑰簽署之 `SHA256SUMS.txt` 內的安裝檔。該金鑰僅保存在維護者的個人電腦上，永遠不會上傳到 GitHub：即使帳號、權杖或工作流程遭到入侵，攻擊者雖能上傳檔案，卻無法產生應用程式認可的簽章。

## 初次設定：建立發佈金鑰

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- 腳本會要求輸入密碼（12 個字元以上），並將加密後的私鑰寫入 `%USERPROFILE%\.wirelessbattery\release-key.wbk`。
- 將公開金鑰寫入 `src\update_public_key.h`。請提交該檔案；若缺少金鑰，官方建置將拒絕編譯。
- **請務必備份金鑰檔案並妥善保存密碼**（建議將兩者都存入密碼管理器）。若遺失其中任何一項，已安裝的應用程式將無法再自動更新：您必須建立新的金鑰，且所有使用者都必須手動安裝一次新版本。

## 每次發佈流程

1. 推送版本標籤（`git tag v1.2.3 && git push origin v1.2.3`）。CI 會自動建置安裝程式、可攜版 ZIP 與 `SHA256SUMS.txt`，並發佈 Release。
2. 簽署雜湊校驗清單：

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   腳本會從 Release 下載 `SHA256SUMS.txt`，顯示內容並要求您確認，接著要求輸入金鑰密碼並寫出 `SHA256SUMS.txt.sig`。如果 `dist\` 中已有相同檔案（該版本的本機建置結果），腳本也會比對並顯示兩者是否相符。
3. 將 `SHA256SUMS.txt.sig` 上傳至該 Release（腳本會自動開啟編輯頁面）。上傳完成後，應用程式就會提供 **下載並安裝** 選項；在此之前僅會顯示有新版本並附上 Release 頁面連結。

請只為您親自發佈的 Release 簽署清單。簽章代表「這些確切的檔案即為正式發佈版本」，因此簽署步驟正是攔截惡意上傳的關鍵防線。

## 更換金鑰

搭配新的 `-KeyFile` 參數執行 `new-release-key.ps1`：腳本會在 `src\update_public_key.h` 中把新公鑰附加於舊公鑰旁。先發佈一個同時包含新舊公鑰、並以舊金鑰簽署的版本；從下一個版本開始改用新金鑰簽署，之後再移除舊公鑰。若金鑰遺失或外洩則無法透過這種平滑方式汰換：此時必須直接從標頭檔移除該公鑰，舊版使用者則需手動安裝下一個發佈版本。

## 執行安裝程式前的應用程式檢查項目

- 該 Release 必須是儲存庫的最新正式版，非草稿（draft）或搶先體驗版（prerelease），且版本號高於目前應用程式。
- `SHA256SUMS.txt.sig` 必須是以 `src\update_public_key.h` 中任一公鑰驗證通過的 `SHA256SUMS.txt` 有效 ECDSA P-256 簽章（採用 Windows BCrypt，無第三方程式碼）。
- 已簽署清單中必須恰僅列出 `BatteryHub-Setup-<version>.exe` 一次，且其 SHA-256 須與 GitHub 回報的檔案雜湊一致。
- 下載的安裝程式必須具備完全相符的檔案大小與 SHA-256。應用程式的副本會在啟動安裝程式前再次驗證，並在驗證與啟動期間保持檔案鎖定以防中途遭到掉包。
- 下載僅透過 HTTPS 連線至 `github.com`、`objects.githubusercontent.com` 與 `release-assets.githubusercontent.com`，且每一次重新導向皆會經過檢查。


---

<a id="sec-keychron-firmware"></a>
> 📄 **章節：** Keychron 鍵盤韌體（`docs/keychron_keyboard_firmware/README.md`） · [英文原文](../../docs/keychron_keyboard_firmware/README.md) · [↑ 返回頂端](#top)

# 透過 2.4 GHz 接收器讀取 Keychron 鍵盤電量

Keychron 原廠韌體僅支援透過藍牙回報鍵盤電量。套用 [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch) 中的小型 QMK 修改後，鍵盤也能透過 Keychron Link 接收器與 USB 線回應電量查詢（`A4`），讓 BatteryHub 顯示其電量百分比、電壓與充電狀態。

已在 **Keychron K5 Max ANSI RGB**（`3434:0A50`）搭配 Keychron Link 接收器（`3434:D030`）上實機測試。

## 修補程式變更內容

基於 [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) 的 `2025q3` 分支（commit `57e682c`）：

- 新增來自 [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1) 的 `KC_GET_BATTERY`（`0xA4`）原始 HID 指令：回應 `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`；
- 將透過無線連線送達的原始 HID 請求導向相同的處理常式；
- 在 `keyboards/keychron/k5_max/config.h` 中加入 `#define WILRESS_RAW_ENABLE`（Keychron 原廠程式碼中即為此拼寫）與 `#define KC_BATTERY_MODEL_ID 0`。

其餘功能皆維持不變：按鍵配置、燈效與 Keychron Launcher 仍可正常運作。

## 方案 1：刷入預先編譯好的 K5 Max 韌體

**僅供 K5 Max ANSI RGB 使用**的建置檔案附加於[此 Release](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)（`k5_max_ansi_rgb_battery.bin`，SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`）。切勿刷入其他型號或鍵盤配列。

## 方案 2：自行建置

需要 Git 與 Docker（或已設定完成的 [QMK 開發環境](https://docs.qmk.fm/newbs_getting_started)）。

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

編譯結果為儲存庫根目錄下的 `keychron_k5_max_ansi_rgb_keychron.bin`。在 Windows 上於 Docker 中掛載本機目錄會非常緩慢；直接在容器內部（或 WSL 中）clone 儲存庫會快上許多。

**其他 Keychron 無線鍵盤**（Q/V/K Max 及其他基於 `2025q3` 原始碼樹且啟用 `LK_WIRELESS_ENABLE` 的型號）：`keyboards/keychron/common/` 底下的修改可直接套用。請改將上述兩行 `#define` 加到您目標鍵盤的 `config.h`，再建置對應目標，例如 `make keychron/<model>/<layout>/<variant>:keychron`。目前應用程式會將 K5 Max（`0A50`–`0A58`）顯示為對應型號名稱，其餘型號則顯示為 "Keychron keyboard"。

## 刷入韌體

1. 將模式開關切至 **Cable（有線）** 並拔除 USB 線。
2. 按住 **Esc** 鍵同時插回 USB 線，鍵盤將進入 STM32 bootloader。
3. 使用 [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)（或 `dfu-util`）刷入 `.bin` 檔案。
4. 切換回 **2.4 GHz** 並執行 `BatteryHub.exe --list` 檢查輸出：`Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`。

透過 Keychron Launcher 更新鍵盤韌體將會覆寫此韌體並移除電量回報功能。若要還原，請以相同步驟重新刷回 Keychron 官方韌體即可。

## 授權條款

QMK 採用 GPL-2.0-or-later 授權；本修補程式亦採用相同授權。任何取得依此修補程式建置之二進位檔案的人，也必須能夠取得這份原始碼修改內容。


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **章節：** GameSir Cyclone Pro（`docs/gamesir_cyclone_pro.md`） · [英文原文](../../docs/gamesir_cyclone_pro.md) · [↑ 返回頂端](#top)

# GameSir Cyclone Pro 電量支援

## 為什麼該控制器原本顯示為滿電的 Xbox 控制器

Cyclone Pro（型號 T4cp）透過 `3537:1015` 2.4 GHz 接收器遊玩。該接收器在 Windows 中將自己呈現為有線 Xbox 360 控制器（XUSB，`Xbox 360 Controller for Windows`）。XInput 在回應電量查詢時永遠回傳「Full」，因此無論實際電量為何，XInput 後備機制都會將它列為 100% 電量的 `Xbox controller 1`。

該接收器本身完全不傳送電量資訊：
- 它唯一的 HID 集合就是 XInput 遊戲控制器（`HID\VID_3537&PID_1015&IG_00`）
- 它沒有像 Nova（`FF7A`）或 Cyclone 2（`FFF0`）那樣的廠商自訂集合

## 電量資訊的位置

當透過接收器遊玩時，手把同時也會以 `GameSir-Cyclone Pro` 的名稱透過藍牙低功耗（BLE）廣播，這正是 GameSir 手機 App 使用的連線。其「get base info」請求會回傳電量：

| 步驟 | 詳細資訊 |
|---|---|
| 服務 | `0x8650`（`00008650-0000-1000-8000-00805f9b34fb`） |
| 特徵（Characteristic） | `0x865F`（notify、write without response） |
| 請求 | 啟用通知，寫入 `01 01` |
| 回應 | 19 位元組通知（部分韌體會在前方加上 `C9`，共 20 位元組） |

回應格式配置：

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

第 18 位元組即為電量百分比（0–100），充電中則為 `FF`。充電期間手把不會回報電量數字，因此程式會保留上次已知的百分比並一併顯示充電閃電圖示。

手把另外還提供 `0xFF10` 服務，這是 GameSir 的韌體更新通道，驅動程式絕不會開啟它。該手把並未實作標準電池服務（`0x180F`），這正是 Windows 藍牙設定頁面與藍牙後備機制無法顯示其電量的原因。

來源：[GameSirBattery](https://github.com/bpbp-boop/GameSirBattery)，該專案從 GameSir Android App（`BluetoothLeService`，「get base info」）反推出這套通訊協定。

## 驅動程式運作方式

`src/drivers/gamesir_ble.cpp` 會在 XInput 後備機制之前執行：

1. **尋找手把。** 搜尋類別為 `{00008650-0000-1000-8000-00805F9B34FB}` 的裝置介面。Windows 會為已配對 BLE 裝置的每個 GATT 服務建立一個介面。程式僅使用父節點 `BTHLE\DEV_…` 名稱為 `GameSir-Cyclone…` 的介面。
2. **讀取電量。** 透過 Win32 GATT API（`bluetoothleapis.h`、`-lbluetoothapis`）開啟該服務，訂閱 `0x865F` 並寫入 `01 01`。最多等待 3 秒接收回應，隨後關閉通知訂閱。
3. **保持輪詢迅速。** BLE 連線可能需要數秒，或是在手把休眠時逾時，因此查詢會在獨立執行緒中執行：
   - 讀取成功後最多每 2 分鐘查詢一次，失敗後則每分鐘查詢一次
   - 輪詢會回報快取的讀數，並在讀數超過 6 分鐘未更新時停止回報
   - 接著 `graceSec` 會將其保留為暗淡的休眠狀態顯示
   - 僅在程式執行期間的第一次輪詢會等待該執行緒一次（設定 4 秒絕對截止時間），好讓電量能在啟動時與 `--list` 中立即顯示
4. **隱藏假的 Xbox 項目。** 偵測到接收器存在時，驅動程式會認領 `3537:1015`：
   - Windows.Gaming.Input 路徑現在會跳過已被認領的廠商 / 產品 ID
   - XInput 路徑會透過 `XInputGetCapabilitiesEx`（xinput1_4 序號 108）取得每個插槽的廠商 / 產品 ID，並跳過已被認領的裝置
   - 若系統缺少該匯出函式，XInput 則維持原有行為

## 已測試硬體

Windows 11，Cyclone Pro 透過接收器（`3537:1015`）連線，已透過藍牙配對一次，測試日期 2026-11-18：

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

當手把進入休眠時，「Xbox controller 1 / Full」項目不再出現，且手把也不再顯示任何虛假電量。

## 使用限制

- **必須配對：** 手把必須先與 Windows 配對一次（設定 > 藍牙與裝置 > 新增裝置 > 藍牙 > `GameSir-Cyclone Pro`）。未配對的手把不會建立 GATT 裝置介面。配對後雖然會新增藍牙遊戲手把裝置項目，但手把透過接收器遊玩時不會透過藍牙送出輸入訊號。
- **需要藍牙：** 電腦必須具備藍牙低功耗（BLE）功能。
- **限單一支手把：** 每台電腦僅讀取一支 Cyclone Pro。
- **充電狀態：** 充電期間無法取得百分比。


---

<a id="sec-localization-guide"></a>
> 📄 **章節：** 多語言使用與在地化指南（`docs/i18n/README.md`） · [英文原文](../../docs/i18n/README.md) · [↑ 返回頂端](#top)

# BatteryHub 多語言索引與在地化指南

本儲存庫中的每一份可見文件皆彙整為 `docs/i18n/` 內的**每種語言一份獨立 Markdown 檔案**，而所有執行期應用程式介面字串則存放在 [`lang/`](../../lang) 中的**靜態可編輯文字檔**（Windows 與 Linux 共用），Windows 安裝程式字串則位於 [`installer/lang/`](../../installer/lang)。

## 支援的語言（19 種）

| 代碼 | 語言 | 完整文件 | 應用程式介面（Windows 與 Linux） | Windows 安裝程式 |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json)（來源字串） | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## 語言切換的實際運作機制

### 1. Windows 應用程式（`BatteryHub.exe`）
- **自動偵測：** 當設為 *語言 → 自動（Windows 語言）* 時，BatteryHub 會查詢 Windows 的 `GetUserPreferredUILanguages`，並比對最接近的靜態 `*.json` 檔案。
- **手動切換：** 點擊工作列小工具或系統匣圖示 → **語言** → 選擇一種語言。介面會立即更新並儲存在 `HKCU\Software\WirelessBattery\Language`。
- **靜態外部檔案（無需重新建置即可編輯）：** `BatteryHub.exe` 會先載入 `<exe>\lang\*.json`，接著載入 `%APPDATA%\WirelessBattery\lang\*.json`。使用者資料夾中具有相同 `@code` 的檔案會覆寫相符字串，且重新開啟選單時會即時從磁碟重新載入檔案。
- **CLI `--help`：** `BatteryHub.exe --help` 會以您目前啟用的介面語言顯示說明對話方塊（`--list`、`--json` 與 `--dump` 刻意維持英文，以方便貼入 GitHub Issue 回報）。

### 2. Linux 應用程式（`wireless-battery`）
- **自動偵測：** 依序遵循 POSIX 地區設定環境變數：`LANGUAGE`（以冒號分隔的清單）→ `LC_ALL` → `LC_MESSAGES` → `LANG`（除非被 `LC_ALL=C` / `POSIX` 覆寫）。
- **手動切換：** 在系統匣圖示上按右鍵 → **語言** → 選擇 **自動（系統語言）** 或任何已安裝的語言。設定會儲存在 `$XDG_CONFIG_HOME/wireless-battery/config.ini`（預設為 `~/.config/wireless-battery/config.ini`）的 `[general] language=` 底下。
- **靜態搜尋路徑（由最低到最高優先順序）：**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/`（預設為 `~/.local/share/wireless-battery/lang/`）
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/`（預設為 `~/.config/wireless-battery/lang/`）
- **CLI `--help`：** `wireless-battery --help` 會根據 `config.ini` 或系統地區設定輸出翻譯後的命令列說明；`--list` 與 `--dump` 維持英文。

### 3. Windows 安裝程式（`BatteryHub-Setup-<version>.exe`）
- 會跳出語言選擇器（`ShowLanguageDialog=yes`），並依據您的 Windows 介面語言預先選取對應語言（`LanguageDetectionMethod=uilanguage`）。
- 會將完整的靜態 `lang\*.json` 目錄安裝到 `{app}\lang\`，置於 `BatteryHub.exe` 旁邊（可攜版 ZIP 亦同樣附帶 `lang\*.json`）。

---

## 如何新增或更新一種語言（逐步教學）

您**不需要**任何建置工具即可翻譯應用程式介面或文件；僅當您想測試編譯 Windows 安裝程式時，才需要安裝 Inno Setup 6。

### 步驟 1 — 應用程式介面字串（`lang/<code>.json`）
1. 從系統匣選單開啟使用者語言資料夾（**語言 → 新增你自己的語言...**），或將 [`lang/_template.json`](../../lang/_template.json) 複製為 `lang/<code>.json`（例如 `lang/it.json`）。
2. 填寫中繼資料標頭：
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. 在每一行的 ` = ` 右側寫上翻譯。
   - 請原封不動保留 `{name}`、`{percent}`、`{version}`、`{days}`、`{hours}`、`{rate}`、`{count}`、`{monitor}`、`{number}`、`{seconds}`、`{minutes}`、`{page}`、`{reason}`、`{code}` 等預留位置。
   - 使用 `\n` 表示明確的換行。
   - 以 **UTF-8（無 BOM）** 儲存檔案。
   - 重新開啟 BatteryHub 系統匣選單即可立即預覽——無需重新建置！

### 步驟 2 — Windows 安裝程式（`installer/lang/<code>.isl`）
1. 將 [`installer/lang/_template.isl`](../../installer/lang/_template.isl) 複製為 `installer/lang/<code>.isl`。
2. **重要事項：** 請將檔案儲存為 **UTF-8 含 BOM（`EF BB BF`）**，如此 Inno Setup 才能不受舊版 Windows 字碼頁影響而正確解碼 Unicode 字元。
3. 選擇相符的設定方式：
   - **Inno Setup 已內建您的語言**（可查看 `C:\Program Files (x86)\Inno Setup 6\Languages\`）：只需保留 `[CustomMessages]` 並翻譯其中的 6 行（`AutostartTask`、`LaunchApp`、`SupportProject`、`CloseFailed`、`DirNotWritableAdmin`、`DirNotWritableUser`，保留 `%1` 與 `%n`）。在 `installer/BatteryHub.iss` 的 `[Languages]` 區段中註冊：
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup 尚未內建您的語言**：複製 `installer/lang/zh-CN.isl` 作為完整範本，設定 `[LangOptions]`（`LanguageName`、`LanguageID`、`LanguageCodePage=0`，視需要加上 `RightToLeft=yes`），翻譯 `[Messages]` 與 `[CustomMessages]`，並於 `Default.isl` 之後註冊：
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - 注意：`[Languages]` 的 `Name:` 識別名稱只能包含 ASCII 英文字母、數字與底線（請使用 `ptBR`，不可用 `pt-BR`）。

### 步驟 3 — Linux 桌面啟動器（`linux/wireless-battery.desktop`）
新增一行在地化的 `Comment[<code>]=...`（在 `.desktop` 檔案中，區域代碼請使用底線，例如 `Comment[zh_CN]=...`）。

### 步驟 4 — 完整獨立文件（`docs/i18n/<code>.md`）
1. 將 [`docs/i18n/_template.md`](_template.md) 複製為 `docs/i18n/<code>.md`（無需任何產生器腳本——只需這一個檔案！）。
2. 完整翻譯目錄與所有 17 個章節，同時保持下列內容原封不動：
   - 所有的 `<a id="sec-..."></a>` 錨點標籤與 `<a id="top"></a>`
   - 所有的程式碼區塊、命令列旗標（`--list`、`--json`、`--dump`、`--report`、`--demo`、`--quit`、`--help`）、USB `VID:PID`、HID 用途頁面、十六進位封包、登錄機碼、檔案路徑與網址
   - 相對圖片 / 檔案路徑（`../screenshot.png`、`../keychron_keyboard_firmware/k5_max_battery.patch`、`../../LICENSE` 等）
3. 更新 `docs/i18n/<code>.md` 頂端的 `<!-- lang-switcher:start -->` 切換列（將您自己的語言設為粗體，其餘皆設為連結），並將您的語言連結加入 `README.md`、`CONTRIBUTING.md`、`docs/*.md`、`docs/keychron_keyboard_firmware/README.md`、`docs/i18n/README.md` 與其他 `docs/i18n/*.md` 檔案中的切換列。
4. 對於從右到左書寫的語言（`ar`、`fa`、`he`），請直接撰寫標準 Markdown，不要用 `<div dir="rtl">` 包裹整份檔案，以確保表格與程式碼區塊能正確排版。


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **章節：** ARDOR GAMING Fury V2（`docs/ardor_fury_v2.md`） · [英文原文](../../docs/ardor_fury_v2.md) · [↑ 返回頂端](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

該 2.4 GHz 接收器暴露了 HID 用途頁面 `000A`、用途 `0000` 以及 5 位元組輸入報告。它會主動廣播資料；不需發送任何 HID 指令。

在實體硬體上觀測到的報告：

| 報告 | 電量 |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

第 3 位元組的高半位元組編碼了電量階級（`1`、`3`、`7`、`F` 分別對應 25%、50%、75% 與 100%）。25% 與 100% 的報告格式是由原廠應用程式的解碼邏輯推導而來；終端使用者隨後已確認剩餘電量階級在建置後的應用程式中皆能正確顯示。第 5 位元組並非固定常數，因此不用作特徵識別碼。

監聽程式要求連續兩筆解碼後的電量階級一致，而非要求整份報告完全相同。最後確認的數值最多保留 45 秒。全域自動重新整理間隔則調整為 15 秒。

已由終端使用者在 Windows 上搭配 ARDOR Fury V2 與 Logitech G733 進行驗證：包含 50% 與 75% 封包擷取、週期性自動更新、25%/100% 視覺檢查以及可攜版啟動。25% 與 100% 的原始封包尚未進行擷取。


---

<a id="sec-areson"></a>
> 📄 **章節：** Areson `25A7`（`docs/areson.md`） · [英文原文](../../docs/areson.md) · [↑ 返回頂端](#top)

# Areson 25A7 接收器電量支援

## 為什麼原程式會漏掉這支滑鼠

Redragon M915RGB-WL 透過一顆 Areson/CompX `25A7:FA07`「2.4G Wireless Receiver」連線。它的電量並未透過標準 HID *Battery Strength* 用途暴露，且由於採用專有 2.4 GHz 連線，Windows 也沒有對應的藍牙電量屬性。滑鼠改為回應主動式 `GetPower` 請求，因此通用 HID 後備機制與藍牙後備機制都偵測不到它。當時程式內尚未實作該廠商的驅動程式，導致接收器一直未被認領且毫無回應。

## 實測硬體與封包

於 2026-11-17 在 Windows 11 上以 Redragon M915RGB-WL 實機測試：

| 方向 | VID:PID | 介面 | 用途頁面:用途 | 報告大小 |
|---|---|---|---|---|
| 請求（feature） | `25A7:FA07` | 1 | `FF02:0002` | 17 位元組 |
| 回應（input） | `25A7:FA07` | 1 | `FF01:0000` | 17 位元組 |

回應會出現在與寫入請求不同的頂層集合上。在 Windows 上這兩者分別對應 `MI_01&COL07`（feature）與 `MI_01&COL05`（input），這也是為什麼驅動程式會同時開啟這兩個控制代碼。

擷取到的請求（`GetPower`，報告 ID `08`，指令 `04`，校驗碼使整幀總和為 `0x55`）：

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

擷取到的回應：

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

下方偏移量將報告 ID 計為第 0 位元組：

| 位元組 | 含義 | 範例 |
|---|---|---|
| 0 | 回應報告 ID | `09` |
| 1 | 指令回顯 | `04` |
| 2 | 狀態，0 = 正常 | `00` |
| 3–4 | 位址，`GetPower` 未使用 | `00 00` |
| 5 | 資料長度（2） | `02` |
| 6 | 電量等級，0–10，以 10% 為一階 | `08` = 80% |
| 7 | 充電旗標，任何非零值代表充電中 | `00` = 未充電 |
| 16 | 校驗碼；全部 17 個位元組總和為 `0x55`（mod 256） | `3E` |

原廠軟體在同一組封包出現時恰好顯示 80%，藉此確認了 ×10 的換算倍率。同時 `GetConnectStatus`（`08 03 …`）會回傳 1 位元組酬載，並回報滑鼠處於已連線狀態。

## 其他 Areson 滑鼠

Redragon M693 所使用的舊款 `FA7B` / `FA7C` 接收器會在相同的回應偏移位置直接回報完整百分比。若對它們套用本驅動程式的 ×10 倍率會顯示成 800%，因此我們刻意不認領那些產品 ID。本驅動程式僅處理 `FA07` 與 `FA08`；`FA08` 是同一家族的替代識別碼，但尚未在本機驗證。

## 輪詢與識別

- 驅動程式僅發送唯讀的 `GetPower` 請求，絕不寫入任何設定、燈效或 DPI 資料。
- 每次重新整理會以零權限存取方式開啟 feature 集合，並以讀取方式開啟 input 集合，發送請求後最多等待 1.8 秒接收回應，中間會執行兩次嘗試並清空佇列，避免將過時的舊報告誤判為本次回答。
- 讀取失敗時不會認領任何裝置，讓休眠中的滑鼠能在介面上保留上次的數值。該項目使用 30 分鐘寬限期，與其他被動式驅動程式一致。
- 裝置識別鍵由廠商與產品 ID 衍生（`areson:25A7:FA07`），因此能跨越接收 / 休眠週期以及重新插拔接收器而維持一致。

## 驗證

完整應用程式已使用 MSVC C++17 與 Windows SDK 編譯，並搭配實體滑鼠執行測試。`BatteryHub.exe --list` 回傳：

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

該讀數與同一時間點 Redragon 官方軟體顯示的百分比完全一致。MinGW 的 `build.bat` 已包含新的原始碼檔案；`Makefile` 則透過萬用字元自動納編。

## 通訊協定來源

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl)：17 位元組封包、feature/input 分離與 `0x55` 校驗規則，由 Redragon 軟體的 USB 封包擷取反推而得。
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray)：`GetPower` 指令與 `25A7:FA07` 上的 10% 電量刻度。
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md)：回應格式以及 `FA7B` / `FA7C` 家族不同的百分比刻度。


---

<a id="sec-darkrim"></a>
> 📄 **章節：** DARKRIM SHADOW（`docs/darkrim.md`） · [英文原文](../../docs/darkrim.md) · [↑ 返回頂端](#top)

# DARKRIM SHADOW / 寸渊影弑接收器

已於 `3654:6901` 實機測試，製造商 `Jieli Technology`，版本號 `0100`。使用介面 **3**、用途 `FF02:0002`、無編號的 64 位元組輸入 / 輸出酬載（Windows HID 報告大小為 65 位元組）。介面 4 同樣具有 `FF02:0002`，但使用報告 ID 2 且不回應此通訊協定，因此已刻意排除。

通訊協定來源：官方 [PC Hub 下載頁面](https://app.darkrim.net/hub/zh.html) 提供的 `DARKRIM-0.1.26-x64-setup.rar`，經下載並靜態解包分析，未安裝或啟動原廠軟體。解壓出的 `DARKRIM.exe` SHA-256 為：`f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`。

該執行檔中的關鍵位址：

- `140124C80`：`sendGetBasicInfo(infoType)` 發送指令 `0010`、Request `01`，酬載 `[infoType, 00]`。電量選擇器為 `01`。
- `140118D30`、`140119200`：幀標頭與 CRC 產生函式。
- `140126DB0`：裝置資訊 TLV 解析器；TLV `01` 即為電量。
- `1400F5660`、`1400FA700`：電量讀取端；低 7 位元代表百分比，最高位元代表充電狀態。相同的電量值也會透過 `0011` Notify `03` 送達。

標頭格式：`FE seq cmdLE type index count lengthLE`，後接酬載與 CRC-16/CCITT-FALSE（多項式 `1021`，初始值 `FFFF`，以大端序儲存）。序號（sequence）為非零的 4 位元計數器；未使用加密。

HID 補零填充前的實際請求 / 回應酬載：

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

回應中的 TLV `01 01 28` 解析為 **40%，未充電**。正式版 C++ 驅動程式在未執行原廠軟體的情況下連續三次查詢皆回傳該數值。接收器在回傳相符回應前會先送出啟動通知，實測耗時約 406 ms。請使用單一 800 ms 的回應截止時間（外加最多 200 ms 寫入時間），且不要因為收到無關的通知而重設該計時器。不需要發送心跳封包（heartbeat）。

驅動程式只發送電量 GET 查詢。它僅接受未加密且具備相符序號 / 指令 / 類型、索引為 0、計數為 0 或 1（硬體實際使用 0）、有效長度 / CRC 以及單一格式正確之電量 TLV 的回應。片段化、未經請求、格式錯誤與超出範圍的回應都會被忽略。

## 實測電量精度與充電狀態

請將此百分比視為**粗略估計，而非經 1% 解析度驗證的精確電量計**。持有者的裝置在充電過程中以每 10 個百分點一階顯示從 40% 到 90% 的進度。在 90% 時，五次電量 GET 回應與一次主動通知全都帶有 `DA`：`DA & 7F = 90`，其中位元 7 表示充電中。當持有者拔除充電線並繼續使用 2.4 GHz 接收器後，另外五次 GET 回應與一次通知全都帶有 `5A`：仍為 90%，此時充電位元已清除。全部十二個封包皆通過 CRC 驗證。

代表性的查詢回應（序號 4）：

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

本驅動程式與官方應用程式皆直接從低 7 位元讀取百分比。驅動程式不會四捨五入到十位數、不會將階級乘以十，也不會內插中間數值；在正式版解析器中輸入合成的 47% 與 95% 報告依然會維持 47% 與 95%。因此觀測到的粗略讀數源自解析器上游（耳機 / 接收器本身的回報機制）。目前尚未觀測到更細粒度的硬體讀數，也尚未記錄完整放電曲線，故各放電階段或其他韌體版本是否固定以 10% 為步進尚未獲得證實。

90% 狀態下的充電中與後續未充電狀態皆已於硬體上驗證。低電量 / 滿電邊界、耳機關機行為、藍牙以及 USB 線資料模式尚未經硬體測試，因此不對這些模式做任何支援保證。此實作不包含任何韌體更新、組態變更、EQ 指令、配對變更、重設指令或原廠二進位檔。

測試指令：`g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`。


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **章節：** HyperX Pulsefire Haste 2 Wireless（`docs/hyperx_haste_2.md`） · [英文原文](../../docs/hyperx_haste_2.md) · [↑ 返回頂端](#top)

# HyperX Pulsefire Haste 2 Wireless 電量通訊協定

由 `src/drivers/hyperx.cpp` 中的 `HasteWireless` 讀取。查詢指令源自 [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli)，與 NGENUITY 使用的指令相同。

已於硬體上驗證：

- Pulsefire Haste 2 Core Wireless，接收器 `03F0:0AB5`。
- Pulsefire Haste 2 Wireless，接收器 `03F0:0F98`，由 uzumakiprime 測試（PR #312）。電量讀數與 HyperX NGENUITY 一致。

`03F0:0D97` 接收器預期運作方式相同，但尚未實機測試。

## HID 集合

| 欄位 | 數值（`0F98`） |
|---|---|
| USB 介面 | `MI_02`（介面 2） |
| 用途頁面 : 用途 | `FF00:0001` |
| 輸入 / 輸出 / 功能報告長度 | 64 / 64 / 64 位元組 |

該接收器亦暴露了標準滑鼠與消費者控制集合。驅動程式僅會開啟輸入報告至少為 8 位元組的廠商集合（用途頁面 `FF00` 或更高）。

## 查詢指令

兩者皆為輸出報告：以下列出前兩個位元組，其餘補零至報告長度。每筆回應皆為輸入報告，其第一個位元組為指令碼加一。每次查詢最多等待一秒接收回應，並會略過無關的報告（重新連線後，接收器會自行送出 `44 xx`、`45 xx` 與 `FB xx` 報告）。

| 請求 | 回應 | 含義 |
|---|---|---|
| `52 01` | `53 01 <linked>` | 當滑鼠關閉或超出範圍時 `linked` = 0 |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100；`charge` 1 = 充電中、2 = 底座/插線上已充滿；電壓單位為 mV，小端序（Core 版為 0） |

- 若缺少連線狀態回應，則直接由電量回應決定狀態。
- 若連線狀態回報為 0，則不發送電量查詢，並將滑鼠顯示為已關閉。
- 滑鼠剛開機後的最初幾秒內會回報約 40% 的電量。因此連線建立後 6 秒內的讀數會被忽略，系統匣會維持上一次的數值。

這兩個請求僅用於讀取狀態，絕不會修改任何設定、燈效或模式。


---

<a id="sec-inphic"></a>
> 📄 **章節：** Inphic IN10（`docs/inphic.md`） · [英文原文](../../docs/inphic.md) · [↑ 返回頂端](#top)

# Inphic IN10 系列、KP 8K 接收器

外接裝置經持有者確認為 IN10 MAX，在系統中列舉為 `Inphic KP 8K`、`1D57:FA65`，版本號 `0116`。其狀態集合位於介面 2，用途為 `000A:0000`，輸入長度為 5（包含報告 ID 03）。

無需發送任何請求，大約每四秒可觀測到一次以下報告：

```text
03 73 41 01 64
```

既有的 Xenta 解析器已能辨識此格式：型號、事件、電池狀態、百分比。系統要求須連續兩筆相等的報告才會顯示 100%；在相關接收器上，剛連線後的第一筆報告有時會是不準確的滿電讀數。本次變更保留了該保護機制以及既有的充電 / 休眠行為。

官方 [Inphic HUB](https://hub.inphic.cn/) 的腳本 `assets/index-BcHQx9B6.js` 將十進位型號 115（`73`）對應至 `IN10RMax`，將 116（`74`）對應至 `IN10Max`。其使用電池狀態 1 代表百分比、2 代表已充滿、3 代表充電中。我們沿用韌體的型號名稱，而非將 `73` 硬指派為 IN10 MAX，以免誤標示共用此接收器的其他裝置。

在此變更之前，應用程式會將該滑鼠列為 `Wireless mouse`。Xenta 傳輸層本來就已處理其電量幀；這次變更補上了缺少的型號名稱。剛執行 `--list` 時有時可能顯示為休眠中，因為其五秒的初始觀測視窗內可能只來得及收到一筆四秒週期的報告。常駐執行的應用程式會保留監聽器，並在隨後的輪詢中確認數值。

硬體已驗證項目：被動報告、重複的 100% 電量確認以及原生驅動程式型號辨識。充電切換、低電量邊界、藍牙與有線模式尚未驗證。型號 `74` 取自官方對照表，尚未在另一台實體裝置上測試。


---

<a id="sec-machenike"></a>
> 📄 **章節：** Machenike L7（`docs/machenike.md`） · [英文原文](../../docs/machenike.md) · [↑ 返回頂端](#top)

# Machenike L7 Arctic / L7 Mix

已在系統中識別為 **L7 Mix** 的 L7 Arctic 上完成驗證：

| 連線方式 | VID:PID | 介面 | 用途 | 輸入 / 輸出 / 最大功能報告長度 |
| --- | --- | --- | --- | --- |
| 2.4 GHz 接收器 | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB 線 | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

驅動程式同時會檢查 HID 產品名稱 `L7 Mix`。其他 Machenike 型號、不同的接收器 ID 以及藍牙廠商查詢均未啟用。

## 通訊協定來源

源自對官方 **Machenike L7 Mix 1.0.0.8** 軟體（可於[製造商驅動程式頁面](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/)取得）的互通性分析，以及在實體滑鼠上的唯讀查詢實測。`DeviceDriver.exe` SHA-256 為：`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`。

在該 32 位元執行檔（映像基底位址 `00400000`）中，函式 VA `00436750` 建構狀態請求；`004494F0` 透過 `HidD_SetFeature` 發送並讀取功能報告回應。狀態解析器 `00410C20` 擷取下方欄位並將電量與充電欄位傳給 UI。上述皆為虛擬位址，而非檔案偏移量。本專案未包含任何專有執行檔、應用程式碼或資源。

## 讀取狀態查詢

發送 **21 個位元組**，報告 ID `51`，指令 `06`，其餘位元組全為零：

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

讀取同樣為 21 個位元組的功能報告 `51`。該集合的最大功能報告大小為 1001，那是給其他報告使用的，並非狀態報告的長度。驅動程式在讀取前會等待 10 ms，並對每個產品使用單一 200 ms 的截止時間（包含處理無關的回應）。它不會發送任何設定、模式、巨集或韌體指令。

以下索引包含報告 ID：

| 位元組 | 含義 / 實測數值 |
| --- | --- |
| 0–1 | `51 06`，必要的指令回顯 |
| 4–7 | `8A 24 4E FF`，已驗證的 L7 裝置特徵碼 |
| 10，位元 0–2 | 工作模式：接收器上為 1，連接線上為 0 |
| 10，位元 3 | 無線滑鼠已連線；接在 USB 線上時此位元亦為清除（0） |
| 11 | 電量百分比，0–100（0 為有效值） |
| 12 | 充電旗標：0 放電中，1 充電中 |

其他欄位與校驗碼語意尚未確立。驅動程式不會自行臆測校驗碼，而是在發佈讀數前驗證指令、長度、裝置特徵碼、模式以及已連線狀態下的電量 / 充電範圍。

擷取到的接收器回應，官方程式當時同樣顯示 64%：

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

充電期間擷取到的 USB 線回應（74%）：

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

此時接收器仍持續回傳其快取的 64%，但已清除其連線位元：

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

這筆已斷線的讀數絕不可暴露出快取的電量 / 充電值。當兩種傳輸方式同時存在時，優先採用連接線讀數，且兩種傳輸之間共用穩定的裝置識別鍵。即使查詢失敗，已知的 L7 裝置仍會被保留認領，以免後續的 Ajazz 驅動程式在共用 VID 上以不同通訊協定探測它。

## 驗證邊界

測試夾具與模擬傳輸測試涵蓋了實測擷取讀數、充電狀態、有效的 0%/100%、已中斷連線的接收器、格式錯誤 / 過期回應、嚴格比對、傳輸失敗、重複項目抑制以及有限次數重試迴圈。這些測試不代表涵蓋實際硬體上的 0%/100% 以及所有休眠 / 韌體變體。


---

<a id="sec-nuphy"></a>
> 📄 **章節：** NuPhy WH80（`docs/nuphy.md`） · [英文原文](../../docs/nuphy.md) · [↑ 返回頂端](#top)

# NuPhy WH80（USB 線與藍牙）

已於 `19F5:A011` 硬體測試，韌體版本 `0116`，介面 1，用途 `0001:0000`，無編號的 64 位元組輸入 / 輸出酬載（在 Windows HID 屬性中為 65 位元組）。

通訊協定來源：[NuPhyIO](https://drive.nuphy.io/)，腳本 `main.b3fb29e0.js`，SDK `getBatteryState(0)`、`getDataPackage` 與 `createCommand`。僅請求 `GetFunc`（`05`）、偏移 `0020`、長度 `01`。不需要任何初始化、組態、燈效或韌體指令。

請求酬載，補零至 64 位元組：

```text
55 05 00 21 01 20 00 00
```

實際回應酬載：

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

第 3 位元組為第 4..63 位元組總和的低位元組。電量位於第 8 位元組：`value & 7F` 為百分比，`value & 80` 為 SDK 充電旗標。原生 C++ 驅動程式在連接的鍵盤上回傳了 **100%，充電中**。充電狀態切換與低電量 / 滿電邊界尚未經硬體測試；官方韌體說明記載 WH80 的讀數是以 10% 為遞增單位。接收器運作方式超出本驅動程式範圍。

## 藍牙

在藍牙模式下，同一把鍵盤使用 HID ID `19F5:324A`（版本號 `0129`），並廣播使用者可見名稱如 `NuPhy WH80 - 1`。它暴露了兩個鍵盤集合與一個滑鼠集合。由於通用 HID 啟發式判斷優先將裝置視為滑鼠，因此需將此確切的藍牙 ID 加入既有的鍵盤覆寫清單中。

電量回報繼續使用 Windows 藍牙電量屬性。拔除 USB 線後，Windows 在該鍵盤上回報 **95%**。對標準 GATT Battery Level（`180F` / `2A19`）進行未快取的直接讀取時，鍵盤也同樣直接回傳 **95%**。這是相較於有線模式下測得 100% 的另一組獨立裝置 / 傳輸讀數；切勿將其替換為假設的滿電值或重新縮放比例。目前尚未確認不同韌體讀數產生差異的原因。

驅動程式會檢查確切的產品 / 介面 / 報告大小、回應標頭、偏移量、長度、校驗碼以及百分比範圍。它採用 400 ms 的回應截止時間，並在同一截止時間內略過無關的回應。

迴歸測試指令：

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **章節：** Rapoo（`docs/rapoo.md`） · [英文原文](../../docs/rapoo.md) · [↑ 返回頂端](#top)

# Rapoo 滑鼠電量支援

## 為什麼原程式會漏掉這支滑鼠

`PollAllDevices()` 會在每次重新整理時列舉 Windows HID 頂層集合一次。每個廠商驅動程式會辨識特定通訊協定、新增一個 `DeviceStatus`，並認領其 VID/PID 以避免通用驅動程式重複加入。UI 本身已支援顯示百分比、充電中以及休眠時的最後讀數。

先前尚未實作 Rapoo 驅動程式。VT3 Max Gen 2 是透過廠商自訂的輸入報告傳送電量，而非標準 HID Battery Strength 用途或 Windows 藍牙電量屬性。因此既有的通用 HID / 藍牙後備機制無法解碼其 USB 接收器。

## 實測硬體與封包

於 2026-11-16 在 Windows 上以持有者的 VT3 Max Gen 2 實機測試：

| 連線方式 | VID:PID | 介面 | 用途頁面:用途 | 輸入 / 輸出大小 |
|---|---|---|---|---|
| 2.4 GHz 接收器 | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 位元組 |
| USB 線 | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 位元組 |

兩者皆自我識別為 `Rapoo Gaming Device`。其餘集合包含標準滑鼠、鍵盤與媒體輸入、廠商設定集合，以及一個 513 位元組的韌體介面。電量驅動程式僅會開啟輸入長度相符的 `FF00:0002`，絕不開啟韌體介面，也絕不發送輸出報告、功能報告、交握封包或設定指令。

擷取到的無線報告（含報告 ID）：

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

擷取到的連接線 / 充電報告：

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

下方偏移量將報告 ID 計為第 0 位元組，與本專案的 `HidDev::Read()` 一致：

| 位元組 | 含義 | 範例 |
|---|---|---|
| 0 | 報告 ID | `07` |
| 1 低半位元組 | 連線方式：0 接收器、1 藍牙、2 連接線 | `20` / `22` |
| 1 高半位元組 | 感測器資訊；非連線類型的一部分 | `2` |
| 2 | 目前 DPI 檔位 | `03` |
| 3–4、5–6 | X/Y DPI，小端序 | `0320` = 800 |
| 7 | 電池狀態：0 無效、1 放電中、2 充電中 | `01` / `02` |
| 8 | 電量百分比，0–100 | `19` = 25% |
| 13–14 | 滑鼠產品 ID，小端序（若有提供） | `4617` |

即時接收器封包擷取回報了 `25%`，隨後完整應用程式在連接線上回傳了 `27%, charging`。解析器測試納入了實際無線封包擷取資料。充電狀態與有線連線偵測同樣經過實體硬體檢驗，並非僅憑偵測到 USB 裝置存在就自行推論。在持有者拔除連接線並重新接回接收器後，最終執行檔透過 `2.4 GHz receiver` 回傳了 `52%`（不含充電旗標），且維持相同的 `rapoo:4617` 識別鍵。這也對有線切換至無線接收器的轉換過程完成了實體硬體檢驗。

同樣於 2026-11-17 在 Windows 上搭配 **VT9 Gen 2** 完成測試：

| 連線方式 | VID:PID | 介面 | 用途頁面:用途 | 輸入 / 輸出大小 |
|---|---|---|---|---|
| 2.4 GHz 接收器 | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 位元組 |
| USB 線 | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 位元組 |

VT9 Gen 2 接收器暴露的是 **16 位元組** 的 `FF00:0002` 報告而非 19 位元組，並採用完全相同的 Nordic 54L `07` 格式（包含位元組 13–14 中內嵌的 `4614` PID）。擷取到的封包：

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # 接收器：100%，放電中
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB 線（電源開關開啟）：100%，充電中
```

透過 USB 線連接時，狀態報告會在互動時（例如切換 DPI）出現；若在插線狀態下將底部電源開關切為 OFF，滑鼠會回報 `state=2, percent=1`，而非實際的電量百分比。

### 具備 13 位元組集合的 VT3 Max Gen 2 接收器（issue #1396）

一筆針對相同接收器 ID `24AE:1417` 的裝置支援請求回報列出了不同的介面配置：`FF00:0002` 為 **13 / 13** 位元組（而非 19 位元組），且 `FF00:000E` 為 33 / 33 位元組，並缺少 513 位元組的韌體集合。這看起來是另一種接收器韌體版本。Rapoo 官方軟體仍能正常顯示電量，但原驅動程式卻忽略了這個正常運作的狀態通道。

Rapoo Hub 的 `VT_nrf54L` 解碼器（`py`）具備長度適應性：它總是讀取 DPI、電池狀態與百分比，僅當報告夠長時才讀取後續欄位（位於 `n[12..13]` 的滑鼠 PID、RF 資訊等）。VT3 MAX 清單項目（`productId: [17943, 5143]`）沒有特殊的輸入報告類型，因此在此接收器上報告 `07` 也會經過同一解碼器處理。13 位元組的報告（ID 加上 12 位元組）仍在第 7 位元組帶有狀態、第 8 位元組帶有百分比；僅缺少內嵌的滑鼠 PID，因此讀數會改用接收器 PID 並保留 `rapoo:4617` 識別鍵。

13 位元組的長度**僅針對 `24AE:1417` 開放接受**。封包幀仍須通過相同的檢查條件（報告 `07`、連線半位元組 0–2、狀態 1/2、百分比 0–100）。目前尚未擷取到實機的 13 位元組封包幀；測試中使用經實測的 19 位元組擷取資料截斷至 13 位元組進行驗證。

## 其他 Rapoo 滑鼠

官方 Rapoo Hub 將此 `07` 格式用於其 Nordic 54L 滑鼠驅動程式。其清單列出了 VT0、VT1、VT2、VT3、VT3S、VT7、VT9 與其他衍生型號。檢視目前的套件檔案可辨識出 69 種採用 `VT_nrf54L` 的 VT 衍生型號；這證明了它們共用同一通訊協定，但不代表已完成 69 款硬體實測或宣稱涵蓋整個 Rapoo 產品線的大多數型號。支援判斷是依據 Rapoo VID、專用集合、輸入長度與有效狀態報告來篩選，因此使用同一通訊協定的未列名型號仍有機會回報電量。程式內建了一張小型名稱對照表涵蓋常見型號；其餘型號則保留其 HID 產品名稱或顯示為 `Rapoo wireless mouse`。

產品名稱與 ID 會隨世代與地區而有所不同。實測的 `1417/4617` 配對在現有官方清單中稱為 `VT3 MAX`，持有者則辨識其為 VT3 Max Gen 2。目前清單中另有獨立的 `VT3 MAX V2`，其 ID 為 `1B06/4B06`。部分社群對照表將 `1417` 標記為 VT9 Pro，不可單獨作為命名或偵測此裝置的依據。

見於 VT3 Pro（`1215/4415`）紀錄的較舊版 VT 韌體，改為在相同的 `FF00:0002` 用途上推送 7 位元組報告：

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

在此舊版格式中，狀態 1/2 分別代表放電中 / 充電中。充電百分比為 `7F` 代表未知，並會保留顯示為未知。過渡狀態 0、無關的 `BC` 報告、格式錯誤封包與大於 100 的百分比都會被忽略。舊版支援具備自動化測試覆蓋，但尚未在此處使用實體舊款滑鼠驗證。此解析邏輯嚴格限制僅適用於產品 ID `1215/4415`（VT3 Pro）、`1233/4433`（VT1 Pro Max）及其 7 位元組輸入集合。

VT1 Pro Max（接收器 `24AE:1233`、連接線 `24AE:4433`，滑鼠韌體 222、接收器韌體 213）是依據持有者在 issue #136 附上的 USBPcap 封包擷取而新增支援的。`--dump` 輸出列出了介面 1 上的 7 位元組 `FF00:0002` 集合，而封包擷取顯示它在沒有 Rapoo 應用程式發送任何請求的情況下會自行推送：

```text
BB B0 71 84 03 01 64   接收器，約每 3.2 秒一次；Rapoo 應用程式顯示 100%
BB B0 71 84 03 02 5F   連接線，充電中，95%；Rapoo 應用程式顯示 "Charging"
```

在連接線上，該報告於一段 16 秒的擷取中僅出現過一次，因此單純插線時部分輪詢可能會逾時；接收器則會規律推送。Nordic 設定檔絕不會解析 `BB` 封包。

這並**不**代表支援所有 Rapoo 裝置。如 VT1 SE 與 VT7 SE 等 CH584 型號在官方驅動程式中使用報告 `08`，不受此解碼器支援。其他 Telink 版本對 `BB` 旗標有不同的解釋，部分辦公型號採用主動電量查詢，而藍牙型號可能僅暴露 Windows 電量屬性。這些裝置仍交由既有的後備機制處理，或需要另外建立經過驗證的實作，切勿向它們發送猜測的查詢指令。

## 輪詢與識別

- 讀取方式為被動接收。相符的 `FF00:0002` 控制代碼會在各次輪詢之間保持開啟（比照 `PollXenta`），讓 Windows 緩衝在 60 秒重新整理間隔期間抵達的狀態幀；每次輪詢會清空所有排隊的幀（保留最新的有效電量讀數），僅在首次開啟或佇列為空時才退回最多 5 秒的等待。已拔除的裝置會被移除並關閉其控制代碼。無關的封包不會重設截止時間。
- 內嵌的滑鼠 PID 或舊版裝置已知的連接線 / 接收器配對，能確保在切換有線與無線連線時維持相同的 UI 識別鍵。連接線與接收器的讀數會合併成單一項目，優先採用連接線的狀態，並在連接線回報未知電量時保留有效的接收器百分比。
- 逾時不會憑空捏造百分比或認領裝置。一旦成功讀取過電量，既有 UI 可在裝置靜默無回應時將該讀數以暗淡方式保留最多 30 分鐘。
- 程式現有以 VID/PID 為基礎的識別模型無法區分多支相同型號 ID 的同款滑鼠。實體環境下同時插著連接線與接收器的情境尚未實測；合併兩路輸入的邏輯由模擬傳輸測試涵蓋驗證。

## 驗證

`make test` 會執行可攜式解碼器測試與搭配模擬 HID 回應的 Windows 驅動程式測試。測試覆蓋範圍包含實際擷取資料、0% 與 100%、充電中、缺失電量、無效 / 截斷幀、不支援的集合 / 廠商、通訊協定設定檔隔離、逾時、穩定識別鍵，以及在不丟棄已知百分比的前提下合併有線 / 接收器重複項目。

完整應用程式已在本機使用 MSVC C++17 與 Windows SDK 編譯，並搭配實體滑鼠執行過 `--list` / `--dump`。既有維護的 MinGW 建置在 `build.bat` 中已納入 `rapoo.cpp`；Makefile 則會自動探索納編。測試環境本身並未安裝 MinGW。

## 通訊協定來源

- [官方 Rapoo Hub](https://hub.rapoo.cn/)，檢視於 2026-11-16：內建的 [JavaScript 驅動程式與清單](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js)。相關解碼器為用於 `VT_nrf54L` 的 `py`/`Hk`，以及代表連線與電池狀態含義的 `qM`/`QM`。獨立的 `VT_CH584` 處理常式消費報告 `08`，不在本實作範圍內。壓縮混淆後的識別名稱可能會在未來版本中變動。
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs)，參考其舊版 VT3 Pro 報告、充電狀態與未知電量標記值。
- Issue #136 USBPcap 封包擷取（VT1 Pro Max 於接收器上與連接線充電中狀態）。
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js) 獨立印證了被動 `07` 狀態廣播與電量偏移位置。其解析器會將無效百分比鉗位限制在範圍內；本實作則選擇直接拒絕無效封包。


---

<a id="sec-rawm"></a>
> 📄 **章節：** RAWM（`docs/rawm.md`） · [英文原文](../../docs/rawm.md) · [↑ 返回頂端](#top)

# RAWM 通訊協定說明

RAWM 滑鼠（以及共用同一平台的 SADES Dagger）透過廠商 HID 集合 `FF00:0001` 與 RAWM HUB 應用程式通訊，使用無編號的 64 位元組輸入與輸出報告（含報告 ID 時為 65 位元組）。接收器與滑鼠均採用 Nordic 的廠商 ID `1915`。

來源：RAWM HUB 網頁應用程式 Hub Web 2.0（<https://www.rawmtech.com/hub.html>），及其腳本 `https://hub.miracletek.net/hub/js/library.min.js`（經過混淆處理；下方函式與常數名稱皆取自該腳本本身）。支援的產品 ID 來自該應用程式下載的裝置對照表（`https://www.miracletek.net/game/device.php`）。Leviathan V4 GT 與 NYX60 使用位於 VID `373E` 上的 Hub Web 3.0，屬於不同的通訊協定。

## 封包結構

每份報告（於報告 ID 之後）的第 0 位元組：

| 高位元 | 含義 |
|---|---|
| `0x80`（`PACKET_TYPE_EVENT_DATA`） | 低 6 位元為酬載大小；酬載接續事件資料流 |
| `0x40`（`PACKET_TYPE_BUFFER_SIZE`） | 流量控制（可用緩衝區大小）；此處忽略 |
| `0xC0`（`PACKET_TYPE_EXTENDED`） | 低 6 位元為 ESB 通道；報告其餘部分為傳送給該通道的封包。接收器後方的滑鼠位於通道 0 |

酬載構成一串事件的位元組流：

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## 讀取電量

驅動程式重複執行應用程式在接收器連線時的操作（`send_event_query`、`send_event_ping`）：

1. 傳送給接收器：`00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>`（`CMD_QUERY`，OS = PC），接著發送 ping `00 84 0E 04 00 00`。裝置僅在主機持續寫入期間才會回傳資料，因此主機需要發送 ping。接收器會以 `CMD_QUERY_RESULT`（`02`）回傳 JSON，例如 `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`。
2. 對通道 0 發送相同的查詢與 ping，前方加上 `C0` 前綴。滑鼠會以 30 位元組 ESB 區塊傳回約 550 位元組的 JSON 物件，例如 `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`。`battery` 為百分比（RAWM HUB 直接照原樣顯示），`chr` 在充電時為 1。
3. 後續電量變化會透過類型為 `17` 的 `CMD_NOTIFY`（`0B`）送達：`[17, percent, charging]`。

如同官方應用程式，驅動程式總是先詢問接收器（在某次測試中，僅直接向通道 0 發送查詢並未獲得任何回應）。休眠中的滑鼠完全不會回應；接收器則仍會回應。

查詢封包會夾帶電腦的系統時鐘，因為官方應用程式就是這樣發送的；除此以外不會寫入其他資料。滑鼠回報 `"crc":1` 時，是告知應用程式將後續指令（如組態設定）包裹在 CRC-16 幀中；至於上述查詢與 ping 則因為是應用程式在得知該旗標前發送的，因此不帶 CRC 即可被接受。

已於 Leviathan V4（韌體 1.2.0）搭配 RAWM HS Receiver `1915:2346`（韌體 2.0.2）上實機測試。


---

<a id="sec-vaxee"></a>
> 📄 **章節：** VAXEE 4K/8K 接收器（`docs/vaxee.md`） · [英文原文](../../docs/vaxee.md) · [↑ 返回頂端](#top)

# VAXEE 4K/8K 接收器與 ZYGEN NP-01S V2

## 支援範圍與硬體驗證

本驅動程式支援 VAXEE 4K 接收器 `3057:1002`、VAXEE 8K 接收器 `3057:2002` 以及透過 USB 線連線的 ZYGEN NP-01S V2 Wireless（`3057:1011`），通訊介面為其廠商集合 `FF05:0001` 上的 64 位元組功能報告。我們刻意不探測其他 VAXEE 接收器、其他連接線產品 ID 以及 ZOWIE 裝置。

8K 接收器（`VAXEE 8K Wireless`，搭配 NP-01 Ergo Wireless 8K 配對）已於 Windows 上完成測試，並透過相同的通訊協定回報：

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

由於該接收器為所有 VAXEE 8K 滑鼠共用且不會回報目前配對的是哪一款滑鼠，因此會直接以接收器本身的名稱顯示。8K 接收器上的充電狀態尚未在實體硬體上觀測到。

實體 4K 接收器已於 Windows 上完成測試：

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

整合後的完整應用程式亦回報：

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

接著將同一支滑鼠直接透過 USB 線連接，Windows 將其辨識為 `ZYGEN NP-01S V2 Wireless`（`3057:1011`）。更新後的正式版驅動程式回報：

```
VAXEE battery: 75%; charging: yes
```

在最初的接收器建置版本中已成功建立工作列小工具。接收器電池供電運作與有線充電皆已於實機上觀測驗證；滿電切換與休眠 / 關機行為尚未經硬體實測。充電解碼與無效回應處理則由模擬回應測試涵蓋。

## 通訊協定

來源：[stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md)。

每筆請求為補零至 64 位元組的 HID 功能報告：

| 位元組 | 數值 |
|---|---|
| 0 | `0E`，報告 ID |
| 1 | `A5`，標頭 |
| 2 | `0B` 代表電量；`10` 代表充電狀態 |
| 3 | `01`，讀取旗標（絕不使用寫入旗標 `02`） |
| 4 | `01`，資料長度 |
| 5–63 | `00` |

透過 `HidD_SetFeature` 發送請求後，等待 100 ms 再透過 `HidD_GetFeature` 讀取報告 `0E`。回應必須至少包含六個位元組，且具備預期的報告 ID、標頭、指令回顯與資料長度。

讀取電量時，回應第 5 位元組必須介於 0–20，乘以 5 後即得到以 5% 為單位的 0–100% 電量。讀取充電狀態時，充電中第 5 位元組為非零值。即使充電查詢失敗，也不會捨棄已取得的有效電量讀數。

驅動程式會對電量請求重試一次。每個相符的集合每次最多發送三次讀取請求（兩次電量嘗試與一次充電查詢），明確延遲總計 300 ms。絕不發送任何設定、配對、韌體或燈效指令。

若未收到任何有效的電量回應，驅動程式不會回報任何內容並讓裝置維持未認領狀態。只要 USB 集合仍然存在，UI 會沿用既有的寬限期機制將先前成功的讀數以暗淡方式保留最多 30 分鐘。若實體集合消失，驅動程式會發出一筆已中斷連線狀態以立即結束該寬限期，藉此避免在把連接線改接到滑鼠上之後，系統匣仍殘留過時的接收器圖示。

## 測試

`make test` 包含 `tests/vaxee_driver_test.cpp`，將正式版驅動程式連結至模擬 HID 傳輸層進行測試。測試檢查項目包含確切的送出唯讀請求、百分比換算、充電狀態解碼、無效與遺漏回應、已被認領的裝置，以及精確的集合過濾條件。
