<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **言語:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | **日本語** | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [言語を追加](README.md)
<!-- lang-switcher:end -->

# BatteryHub — 完全ドキュメント（日本語）

> この単一のスタンドアロン Markdown ファイルには、リポジトリ内のすべての公開ドキュメントがまとめられているため、翻訳者は**言語ごとに 1 つのファイル**だけを管理すれば済みます。

## 目次

1. [BatteryHub の概要・対応デバイス・インストール・CLI・ビルド（`README.md`）](#sec-readme)
2. [コントリビュートガイド（`CONTRIBUTING.md`）](#sec-contributing)
3. [プルリクエストテンプレート（`.github/pull_request_template.md`）](#sec-pr-template)
4. [リリースおよび署名ガイド（`docs/releasing.md`）](#sec-releasing)
5. [Keychron キーボード 2.4 GHz ファームウェアパッチ（`docs/keychron_keyboard_firmware/README.md`）](#sec-keychron-firmware)
6. [GameSir Cyclone Pro BLE サポート（`docs/gamesir_cyclone_pro.md`）](#sec-gamesir-cyclone-pro)
7. [多言語利用・ローカライズガイド（`docs/i18n/README.md`）](#sec-localization-guide)
8. [ARDOR GAMING Fury V2（`docs/ardor_fury_v2.md`）](#sec-ardor-fury-v2)
9. [Areson 25A7 レシーバー（`docs/areson.md`）](#sec-areson)
10. [DARKRIM SHADOW レシーバー（`docs/darkrim.md`）](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless（`docs/hyperx_haste_2.md`）](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K レシーバー（`docs/inphic.md`）](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix（`docs/machenike.md`）](#sec-machenike)
14. [NuPhy WH80（`docs/nuphy.md`）](#sec-nuphy)
15. [Rapoo マウスのバッテリーサポート（`docs/rapoo.md`）](#sec-rapoo)
16. [RAWM プロトコルノート（`docs/rawm.md`）](#sec-rawm)
17. [VAXEE 4K/8K レシーバー（`docs/vaxee.md`）](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **セクション:** BatteryHub の概要（`README.md`） · [英語原文](../../README.md) · [↑ トップへ](#top)

# BatteryHub

*旧称 **Wireless Battery**。バージョン 1.1.0 でアプリ名が変更されました。アップデートしても、設定・起動オプション・バッテリー履歴はそのまま引き継がれます。*

[![Ko-fi で支援する](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![PayPal で寄付する](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Discord に参加](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![GitHub で Star を付ける](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Reddit で共有](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![デバイスを報告](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![翻訳を手伝う](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

ワイヤレスのマウス、ヘッドセット、キーボード、コントローラーのバッテリー残量を Windows タスクバーに直接表示します。

![タスクバー上の BatteryHub](../screenshot.png)

> **すぐ使いたい場合は？** 最新リリースから **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** をダウンロードし、実行して画面の案内に従うだけです。
>
> **上級ユーザー**は、ポータブル ZIP をダウンロードしたり、[コマンドラインオプション](#コマンドライン)を使ったり、`make` または `build.bat` で[ソースからビルド](#ビルド)したりできます。
>
> **気に入りましたか？** BatteryHub は無料のオープンソースソフトウェアです。メーカー純正ソフトを開く手間が省けたなら、[Ko-fi](https://ko-fi.com/krisgfx)、[PayPal](https://www.paypal.com/paypalme/krisgfx)、または [GitHub Sponsors](https://github.com/sponsors/krisgfx9) でご支援いただけます。学業と並行してアプリを無料で公開し続ける助けになります。寄付が難しい場合でも、⭐ Star を付けること、他の人に紹介すること、あるいは `--dump` を使って未対応デバイスを報告することも同じくらい大きな助けになります。

- **超軽量:** 約 350 KB のアプリで、メモリ使用量は約 2 MB。純粋な C++/Win32 製で、ランタイムもバックグラウンドサービスも不要です。管理者権限なしで数秒でインストールできます。
- **メーカー純正ソフト不要:** デバイスと直接通信します。G HUB、Synapse、iCUE、GG、NGenuity は閉じたままにできます（起動したままでも競合しません）。
- **多数のブランドに対応:** Logitech、Razer、SteelSeries、Corsair、HyperX、Glorious、Jabra、JBL、PlayStation / Xbox コントローラー、Samsung Galaxy Buds、Windows がバッテリー残量を認識できるあらゆる Bluetooth デバイス、および同梱の [HeadsetControl](https://github.com/Sapd/HeadsetControl) がサポートするすべてのヘッドセットに対応しています。

## 表示

**タスクバー上（既定）:** 通知領域の横に `🎧 30%  🖱 93%` のように Windows アイコンフォントで描画されます。
- **バッテリー残量低下:** 赤色の数字は 15% 以下を意味します。
- **充電中:** 数字の横に青い ⚡ が表示されます。電源につながったまま満充電になると、緑の ✓ に変わります。
- **スリープ中:** 薄い色の文字は、デバイスがスリープ中であり最後に確認した値を表示していることを示します。
- **切断済み（任意）:** メニューの *切断されたデバイスを表示* をオンにすると、ドライバーが無線リンクのオフラインを明示的に報告したデバイスに対して薄い `×` を表示します。バッテリー取得の失敗だけから切断と推測することはありません。既定ではオフラインデバイスは非表示のままです。
- **同種デバイスが 2 つある場合:** マウスが 2 台（またはコントローラーが 2 台など）あると同じアイコンになるため、それぞれのアイコンの隅に最大 3 文字の小さな識別文字が表示されます。識別文字はデバイス名（`MX`、`PRO` など）から自動抽出されるか、名前で区別できない場合は番号になります。その種類が 1 台だけのときは識別文字は表示されません。
- **テーマ:** Windows のライト / ダークモードおよび DPI スケーリングに追従します。
- **透明タスクバーテーマ**（例: Windhawk の Taskbar Styler）: 壁紙の上でも文字が読みやすくなるよう、メニューの *タスクバーの文字の背景* をオンにしてください。
- **マルチモニター:** 全画面ゲーム中にも見えるよう、すべてのモニターのタスクバーの時計の横にウィジェットが表示されます。メニューの *ウィジェットの表示先* から *すべてのモニター*、*メインモニターのみ*、または特定のディスプレイ（例: *ディスプレイ 3* のみ）を選択できます。
- **その他の表示オプション:** *パーセントの上にアイコン* を選ぶと、アイコンをパーセント表示の上に重ねて横幅を節約できます。*ブランドカラー* を選ぶと、対応ブランドをメーカーカラー（Razer の緑、HyperX の赤など）と細い残量バーで表示します。同種デバイスが複数あるときは小さなラベルで区別でき、左右配置のタスクバーでは縦 1 列に並びます。
- **対応言語:** English、العربية、Deutsch、Español、فارسی、Français、עברית、日本語、한국어、Magyar、Polski、Português (Brasil)、Русский、Svenska、Tiếng Việt、Türkçe、Українська、简体中文、繁體中文。Windows 版・Linux 版ともにシステムの表示言語に追従し、メニューの *言語* から別の言語を選択できます。Windows インストーラーも全 19 言語に対応しています。UI 文言は編集可能な静的ファイル `lang/*.json` に保存されており、完全なドキュメント翻訳は [`docs/i18n/`](README.md) にあります。言語の編集・追加方法は[翻訳](#翻訳)をご覧ください。
- **ブランドカラー:** 15 の有名ブランドのデバイスはメーカーごとのカラーで表示され、淡いグローとパーセント下の細い残量バーが付きます（Razer の緑、Logitech の青、SteelSeries のオレンジ、Corsair の黄、HyperX / ROG / ZOWIE の赤、PlayStation、Xbox、Samsung、Apple、Jabra、JBL、Cooler Master、Steam）。各カラーにはダーク／ライトタスクバー用の色調が用意されています。ブランド判定はデバイスを検出したドライバー、ベンダー ID、デバイス名の順で行われ、色とルールは `src/brands.cpp` に定義されています。メニューの *ブランドカラー* でオフにできます。

**トレイアイコン:** デバイスごとに数値入りのアイコンが 1 つずつ表示され、15% で「バッテリー残量低下」の通知が出ます。タスクバーが縦向きの場合やタスクバーが見つからない場合は、自動的にこのモードに切り替わります。

**カスタムデバイス名:** デバイスのサブメニューを開き *デバイスの名前を変更...* を選択すると、任意の名前（最大 64 文字）を設定できます。設定した名前はタスクバーウィジェットのツールチップ・識別文字、トレイのツールチップや通知、およびデバイスメニューに表示されます。元のドライバー名に戻すには *元の名前に戻す* を使います。名前は安定したデバイスキーを使って現在のユーザーの Windows レジストリ（`Software\WirelessBattery`、`DeviceAliases`）にローカル保存されます。名前を変更しても、ドライバーの一致判定、プロトコルクエリ、`--list` / `--dump` の診断出力には一切影響しません。アカウントやネットワーク接続は不要です。

マウスオーバーで詳細を表示し、クリックでメニューを開けます。メニューからは各デバイスの表示 / 非表示の切り替え、表示モードの変更、*今すぐ更新*、*Windows の起動時に開始*、*終了* が行えます。残量は 60 秒ごと（メニューの *バッテリー確認間隔* で変更可能）、およびデバイスの接続時や PC のスリープ復帰時に即座に更新されます。

## スマートバッテリー通知（実験的機能）

各デバイスのサブメニューから **デバイスごとの低バッテリー通知しきい値** を設定できます: **バッテリー通知** → *デフォルトを使用（15%）*、*通知を無効にする*、または 5%、10%、15%、20%、25%、30%、35%、40% から選択します。個別に上書き設定しない限り、従来の既定値 15% が維持されます。設定はデバイスキーごとに現在のユーザーの Windows レジストリ（`Software\WirelessBattery`、`AlertThresholds`）に保存されます。

通知は、デバイスが接続済み・起動中（スリープではない）・非充電状態であり、実際の新しい 0〜100% のバッテリー値が読み取れた場合にのみトリガーされます。通知は 1 回だけ表示され、残量が選択したしきい値より 10 ポイント以上回復したとき（または充電が開始されたとき）に再有効化されます。読み取り欠損やスリープ中のデバイスは再通知されません。非表示にしたデバイスは通知を出しません。あるデバイスの通知を無効にしても、そのデバイスが非表示になったりパーセント表示が変わったりすることはありません。

タスクバーウィジェットモードとトレイアイコンモードのどちらでも通知に対応しています。Windows では従来のバルーン通知を表示するために通知領域アイコンが必要なため、ウィジェットモードでは通知後最大 1 分間、一時的な通知アイコンが表示されることがあります。ウィジェットの色および低バッテリー強調表示は、通知設定とは独立してプロジェクト本来のグローバルな 15% しきい値を引き続き使用します。

## バッテリー履歴と分析

タスクバーウィジェットまたはトレイメニューでデバイスを右クリックし、**バッテリー履歴...** を選択します。
Windows のライト / ダークテーマに追従し DPI スケーリングに対応したネイティブビューアーでは、過去 **24 時間**・**7 日間**・**30 日間** の記録済みバッテリー残量が折れ線グラフで表示され、最新・最低・最高残量、変化量（ポイント）、記録数も確認できます。ビューアーから選択したデバイスの履歴を消去することもできます。

履歴は、数値のパーセントを報告する接続済み・稼働中のデバイスについて**ローカルのみに**記録されます。記録はデバイスあたり最大 30 分に 1 回サンプリングされます（充電状態の変化時は最短 60 秒間隔）。データは最大 30 日間保持され、ローカルファイルのサイズは約 2 MB 未満に保たれます。アプリが既存のポーリング以上にハードウェアへ追加アクセスしたり、履歴データをネットワーク経由で送信したりすることはありません。また、最近の放電観測のみから控えめで概算の「バッテリー切れまでの推定時間」を計算します。推定には少なくとも 4 件の記録、2 時間以上の経過、3 ポイント以上の低下、最新の読み取り値、および安定した放電区間が必要です。充電中、古い記録しかない場合、またはデータ不足の場合は推定を表示しません。デバイス側が報告する残り駆動時間自体は利用できません。推定値は保証されるものではなく、欠測データは補間せず空白区間として表示されます。

保存を停止するにはメニューの **バッテリー履歴を記録** をオフにします。すでに保存されたデータはビューアーで消去するまで保持されます。ファイルは `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv` に保存されます。デバイス識別子はエンコードされています（暗号化ではありません）が、ファイルはお使いの Windows アカウントのローカルに留まります。`--demo` モードではグラフにダミーデータが表示され、一切保存されません。**注:** 履歴の収集は、この機能がインストールされアプリがしばらく稼働した後にのみ開始されます。

## 対応デバイス

| ベンダー | デバイス | 取得方式 |
|---|---|---|
| **NuPhy** | USB ケーブル接続（`19F5:A011`）または Bluetooth 接続（`19F5:324A`）の WH80（実機検証済み） | USB: 読み取り専用の NuPhyIO バッテリークエリ、Bluetooth: キーボード分類を適用した Windows バッテリー残量（[プロトコルノート](#sec-nuphy)） |
| **DARKRIM** | `3654:6901` USB レシーバー接続の SHADOW（寸渊影弑）（実機検証済み） | 読み取り専用の CRC チェック付きバッテリークエリおよび充電フラグ。10% 刻みの粗い読み取りを確認、より細かい精度は未検証（[プロトコルノート](#sec-darkrim)） |
| **Inphic** | KP 8K レシーバー（`1D57:FA65`）接続の IN10R MAX / IN10 MAX（モデル `73` は実機検証済み、モデル `74` は未検証） | パッシブな Xenta ステータスレポート。一致する 2 フレームで残量を確定（[プロトコルノート](#sec-inphic)） |
| **ASTRO** | USB ベースステーション経由の A50 X（`046D:0B0B` 検証済み）、A50 Gen 5（`046D:0B1C`）、A50 Gen 4（`9886:002C` 検証済み、`002D`/`002A`）、A50 Gen 3（`9886:0015` 検証済み、`0014`/`0018`/`001D`/`0026`）、A20 Wireless（`9886:0037`–`0045`） | バッテリー残量（%）、充電中およびドック装着状態 |
| **Logitech** | Unifying、Bolt、Lightspeed（PRO X3 SUPERSTRIKE ドングル `046D:C54F` を含む）および Nano レシーバー、USB または Bluetooth 接続のマウス・キーボード。G ヘッドセット（G533、G535、G633/G635/G733/G933/G935、G PRO/PRO X）。新しい `046D:0ADF` ドングル接続の G435 | 機能検出機能付き HID++ 1.0 / 2.0（unified battery、battery level、voltage、ADC）。G435: CRC-16 フレーミングされたベンダーレポート、mV 単位の `GET_BATTERY` |
| **Razer** | ワイヤレスマウス・キーボード・ドングル。BlackShark V2 HyperSpeed、V2 Pro（2020/2023）、V3 / V3 Pro / V3 X ヘッドセット、V3 Pro for Xbox（`1532:0A55` レシーバー、`0A4E` ケーブル）。2.4 GHz レシーバー（`1532:0550` または `1532:0552`）接続の Barracuda X（2022）。Barracuda Pro（`1532:053A`） | Razer Feature Report プロトコル。BlackShark ベンダープロトコル（V3 / V3 Pro / V3 X は 5 分ごとにクエリ）。Barracuda X: レシーバー経由の Airoha バッテリーおよびケーブルクエリ |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless、Arctis Nova 3P/5/7/7X/7P/Pro Wireless（`1038:225D` を含む）、Arctis Nova Elite（ベースステーション `1038:2244`）、GameBuds。Aerox 3/5/9 Wireless（Aerox 5 Diablo IV `1038:1860` は未検証）、Aerox 3 Wireless CS2 Dragon Lore Edition（レシーバー `1038:1878`、ケーブル `187A`）、Aerox 3 Wireless Gen 2（レシーバー `1038:1890`、ケーブル `1892`）、Prime Wireless、Rival 3 Wireless（Gen 2）、Rival 650、Rival Pro | ベンダー HID レポート。Aerox/Prime および Rival 650 はレシーバーと USB ケーブルで 1 つのエントリーを共有し、両方が応答する場合はケーブル側の値を優先 |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 ワイヤレス。Bragi デバイス（Virtuoso、Void V2、HS80 MAX、新型 Slipstream レシーバー `1B1C:2B00` を含む Slipstream マウス・キーボード、例: Scimitar Elite SE Wireless および Dark Core RGB Pro SE）。Sabre V2 Pro Ultralight Wireless（`1B1C:2B2A`）、Sabre v2 PRO WIRELESS MG（`1B1C:2B34`、未検証） | ベンダー HID レポート、Bragi `GET`（読み取り専用）、Compx 17 バイトバッテリープロトコル（読み取り専用） |
| **Cooler Master** | MM712、MM731（2.4 GHz レシーバーまたは USB ケーブル） | ベンダー HID ステータスレポート（読み取り専用） |
| **Press Play** | `7768:6434` 2.4 GHz レシーバー接続の ICARUS V2 Nearlink（ドライバー実機検証は 90%、プロトコルキャプチャは 100% と 90% で取得） | `FFB2:0001` 上の読み取り専用 Output Report `06 05`。応答バイト 14 にバッテリー残量（%） |
| **HyperX** | Cloud III Wireless、Cloud III S Wireless、Cloud II Wireless（HP、Kingston、DTS）、Cloud II Core Wireless、Cloud Alpha Wireless、Cloud Alpha 2 Wireless、Cloud Flight（PS 用 `03F0:0C8C` は未検証）、Cloud Flight S、Cloud Stinger Core Wireless（DTS `03F0:0A8E` 検証済みを含む）、Cloud Core Wireless DTS、Pulsefire Haste 2 Core Wireless（2.4 GHz レシーバー）、Pulsefire Haste 2 Wireless、Pulsefire Haste 2 Mini（2.4 GHz レシーバー）（2.4 GHz レシーバー `03F0:0F98` は検証済み、`0D97` は未検証） | ベンダー HID レポート（Haste 2: [プロトコルノート](#sec-hyperx-haste-2)） |
| **Glorious** | Model O / O- / D / D- Wireless、Model O 2 / D 2 PRO | ベンダー Feature Report |
| **Hitscan** | Hyperlight X、Hyperlight N | ベンダー Feature Report（Glorious と同一プロトコル） |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury、Pulsar および ATK VXE ワイヤレスマウス（例: VXE X3 Pro、VXE Dragonfly R1 / R1 Pro Max / R1 SE+、ATK F1 Extreme）、Hitscan Hyperlight、Chimera V2（レシーバー 3554:F512） | チェックサム付き応答を伴う共通ベンダープロトコル |
| **Pulsar X2 V3** | 1K ドングル（`3710:5402`）または USB ケーブル（`3710:3402`）接続の X2 V3、8K ドングル（`3710:5403`）または USB ケーブル（`3710:3406`）接続の X2 V3 eS | 64 バイト ベンダー Feature Report、バッテリーレジスタ `08 81 01`（読み取り専用） |
| **ATK / VXE NK** | NK mouse NANO ドングル（`373B:1216`）接続の VXE R1 NK およびその他の NearLink マウス | `FF05:0001` 上の ATK BITMOUSE Output Report 08（残量と充電状態） |
| **ATK 8K Nano** | ATK 8K Nano Dongle（`373B:1178`）接続の ATK / VXE マウス | `FF10:0001` 上の Holtek GetConfigData（`82`）Feature Report（ATK HUB 由来、残量と充電状態） |
| **ATK ヘッドセット** | ATK N9 Pro、N9 Ultra（第 1 世代） | 仮想 COM ポートプロトコル（ATK デスクトップアプリを閉じておく必要あり） |
| **G-Wolves** | Fenrir、Fenrir Pro / Max / Asym、HTX、HTS、HSK、HTR、HT-S2、Lycan、WARG、VUK および各 8K ドングル | モデルに応じた Glorious または Kysona プロトコル |
| **Keychron マウス** | 2.4 GHz レシーバー接続の M4 などの Keychron マウス。Keychron 4K Link レシーバー（`3434:D038`）接続の 4K マウス（M4 4K、M3 4K、M3 mini 4K、M6 4K ...）。TurboLink 8K レシーバー接続の 8K マウス（M5 8K、G6 HE 8K ...）。Ultra-Link 8K レシーバー（`3434:D028`）接続の 8K マウス。1K レシーバー（`3434:D030` / `D031`）接続の旧マウス（M1、M2、M3、M3 mini、M6、M7 ...）。Link-KM レシーバーまたはケーブル接続の Nape Pro トラックボール | Keychron Launcher 準拠のベンダーレポート（1K レシーバー: Keychron デスクトップアプリが使用する Feature Report 51 06、Ultra-Link 8K: `FFC1` 上のレポート B5 03 / B3 06、Nape Pro: raw HID A7 31） |
| **Keychron キーボード** | Keychron Link レシーバー（`3434:D030`）または USB ケーブル接続の K5 Max（`3434:0A50`、検証済み）。同じパッチを適用してビルドされたその他の Keychron QMK ワイヤレスキーボード | `FF60:0061` 上の raw HID: `B2` でレシーバーに接続中のキーボードを確認し、`A4` で残量・電圧・充電状態を取得。**パッチ適用済みキーボードファームウェアが必要:** [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware) を参照。純正ファームウェアは Bluetooth でのみ残量を報告します |
| **CHERRY** | 2.4 GHz ドングル（`046A:00EA`、検証済み）または USB ケーブル（`046A:00E3`、検証済み）接続の MX 3.0S Wireless キーボード | `FF1C:0092` 上のベンダー HID クエリ `1A`（読み取り専用）、USB 給電状態に対応。Bluetooth 接続は Bluetooth サポートで対応 |
| **CHERRY** | 1K レシーバー（`046A:0330`、検証済み）接続の Cherry XTRFY ワイヤレスマウス | CompX 17 バイトバッテリープロトコル（`08 03` リンク状態、`08 04` GetPower）、Corsair Sabre V2 Pro と同等のフレーミング（読み取り専用） |
| **Arbiter Studio** | Akitsu（`373E:000A` 8K レシーバー、`373E:0009` ケーブル）、Akitsu 3950（`373E:0039` 8K レシーバー、`373E:0038` ケーブル）、Akitsu Medium（`373E:0067` 8K レシーバーおよび `373E:0066` ケーブル、ともに検証済み） | Arbiter Web HUB 由来の `FFFF:0000` 上の読み取り専用ベンダー Feature Report `0x83`（残量と充電状態） |
| **LAMZU** | Maya X、Maya、Maya M、Tachi、Inca、Paro、Thorn、Atlantis Mini / OG Champion、Orcus（ケーブル、1K および 4K/8K ドングル） | LAMZU Aurora 準拠のベンダー Feature Report |
| **Endgame Gear** | 4K ドングル接続の OP1w 4k（v1 / v2）、XM2w 4k（v1 / v2）。オリジナルレシーバー（`3367:1961`）接続の XM2we | ベンダー Feature Report `A1`、バッテリーコマンド `B4`（読み取り専用） |
| **ATK / VGN / Evision キーボード** | 共通 2.4 GHz レシーバー（`320F:5088`）または USB ケーブル（`320F:5055`）接続で製品名により識別される ATK V75X および VGN / VXE キーボード（S99、V98 Pro / V98 Pro V2、N75 Pro、VXE75 / VXE75 V2、VXE V87）。`320F:5088` レシーバー名が「Wireless Gaming Keyboard」となるキーボード（例: Feker Alice80、検証済み） | Evision Output Report `04`、バッテリーコマンド `1A`（ATK HUB および VGN HUB 由来）。レシーバー経由では最短 10 分間隔で問い合わせ |
| **Redragon (Evision)** | `320F:226F` 2.4 GHz レシーバー接続の K1NG M999（検証済み）。同じレシーバー ID を他モデルが共有している可能性あり | ATK キーボードと同一の Evision プロトコル（`FF1C:0092` 上のレポート `04`、コマンド `1A`）、毎回のポーリングで問い合わせ。マグネットドック上の充電表示に対応。USB ケーブル接続時はレシーバーが古い残量と充電なし状態を返し続けます |
| **Audeze** | USB ドングル（`3329:4B19`）または USB-C ケーブル（`3329:4B1A`）接続の Maxwell、USB ドングル（`3329:4B29`、検証済み）接続の Maxwell 2。Xbox 用 ID は未検証 | ベンダーレポート `06` / Input Report `07`、バッテリー属性 `0CD6`（読み取り専用の単発クエリ） |
| **ENDORFY** | 2.4 GHz ドングル（`3738:0072`、未検証）接続の Viro Wireless | ベンダーレポート `06` / Input Report `07` 上の Airoha RACE "get battery"（`0CD6`）。Audeze や Skullcandy のドングルと同じ読み取り専用クエリ。充電状態なし |
| **Turtle Beach** | USB トランスミッター（`10F5:2251`、HaloBattery で検証済み。PC 版 `10F5:2262` は未検証）またはヘッドセット付属 USB ケーブル（`10F5:2253`）接続の Stealth 700 Gen 3 | Swarm II と同様の RACE `0x9942`（CoAP クライアント有効化）および RACE `0x9902` 内にトンネリングした CoAP `GET /GSI`。キー `240` から残量を取得（充電フラグなし） |
| **AKG** | USB ドングル（`0ECB:20D9`、検証済み）接続の N9 Hybrid | `FF13:0001` 上の Airoha RACE: Output Report `06`、Input Report `07`、バッテリー属性 `0CD6`（読み取り専用の単発クエリ） |
| **NZXT** | ドングル（`1E71:2101`）または USB ケーブル（`1E71:2129`）接続の Lift Elite Wireless | ベンダー読み取り `4E 02 81 .. B0`（NZXT CAM の通信キャプチャより） |
| **Poly / Plantronics** | BT600 アダプター（`047F:02EE` / `02F7`）配下の Voyager 8200 UC およびその他のヘッドセット | レポート `07` get/set プロトコル、バッテリー項目 `0A 1A`（読み取り専用） |
| **WLMouse** | YING Magnesium（YING 8K レシーバー `36A7:A874`）。Beast X 8K、Beast X Mini / Mini Pro、Beast X Pro、Beast MAX、Sword X 8K（レシーバーまたはケーブル。Beast X 4K は対象外）。Beast X V2（8K レシーバー `36A7:A856`）。Beast G（8K レシーバー `36A7:A860` またはケーブル `36A7:A861`、未検証） | ベンダー Feature Report、ステータスコマンド `0x83`（YING: Glorious と同一プロトコル） |
| **Finalmouse** | 2.4 GHz ドングル（`361D:0100`、検証済み）接続の UltralightX、ドングル（`361D:0300` / `0301`、検証済み）接続の Starlight X。マウス本体のケーブル直結では非対応 | `FF00` 上の xpanel ベンダーレポート: 読み取り専用 GET 後、*wake/all*（`0xE0`）。xpanel カーブによるバッテリー電圧換算または Starlight X 独自のパーセント値＋充電状態 |
| **VAXEE** | VAXEE 4K レシーバー（`3057:1002`）または 8K レシーバー（`3057:2002`、例: NP-01 Ergo Wireless 8K）接続のワイヤレスマウス。USB ケーブル接続の ZYGEN NP-01S V2 Wireless（`3057:1011`） | `FF05:0001` 上の読み取り専用ベンダー Feature Report `0E`。5% 刻みの残量および充電状態（[プロトコルノート](#sec-vaxee)） |
| **Scyrox** | 2.4 GHz レシーバー（`395A:0006`）接続の V12M | `FF00:0002` 上の S-Center 2.0 プロファイル読み取り（Output Report `08`、コマンド `01`）。残量のみ、充電状態なし |
| **HECATE** | 同一レシーバーおよび USB ケーブル `35BB:D3FA / D3FC / D3FD` 接続の G5M PRO およびその他の HECATE マウス | Kysona プロトコル |
| **Redragon** | Compx ベースのワイヤレスマウス: M916 Pro 1K（検証済み）、M913 Impact Elite（トライモード）、G49（レシーバーまたはケーブル） | Kysona プロトコル（Areson `25A7` レシーバーは Areson の行を参照） |
| **Taidu (钛度)** | Compx 2.4 GHz レシーバー `3554:F5D5` 接続の TSG808（検証済み） | Kysona プロトコル |
| **Areson (Redragon)** | `25A7:FA07` / `FA08` レシーバー接続の M915RGB-WL（検証済み）、初代 M913 Impact Elite およびその他のマウス | 17 バイト `GetPower` Feature Report。10% 刻みの残量と充電フラグ |
| **Ninjutso** | 1K レシーバー（`1915:AE1C`、検証済み）または USB ケーブル（`1915:AE11`、検証済み）接続の Sora V2。Ten Air（レシーバー `093A:EB01` および USB ケーブル `093A:E020`、検証済み）/ Ten（`093A:EB01` / `E020`、未検証） | NinjaForce Feature Report `0x05`（Sora V2 は `0x15`）および `0x06`（Ten / Ten Air は `0x13`/`0x12`/`0x11`） |
| **Sprime** | 2.4 GHz レシーバー（`1915:AC1C` 検証済み、`1915:AD8C`）または USB ケーブル接続の PM1 | Sprime Web ドライバー（sprime.pro）準拠の Feature Report 0x05、ステータスコマンド 0x15 |
| **RAWM / SADES** | RAWM HS Receiver（`1915:2346`、検証済み）接続の Leviathan V4。RAWM レシーバー（`1915:232A`–`234B`）または USB ケーブル接続の ES21 / ES21 Pro / ES21M、ER21 / ER21 Pro / ER21M、ES11、G11 / G11 Plus / G11 Pro、SA-* および SADES Dagger マウス | レシーバー経由の RAWM HUB 2.0 デバイス情報クエリ（バッテリー % と充電状態を含む JSON）、読み取り専用（[プロトコルノート](#sec-rawm)） |
| **AULA** | 2.4 GHz レシーバー接続の F75 / F87 Pro / F99 ワイヤレスキーボード | レポート 0x13 フレーム、コマンド 0x4A、加算チェックサム（Bluetooth および有線モードは未検証） |
| **AULA マウス** | AULA-8K Dongle `320F:22A0` 接続の X9 Ultra（検証済み）。レシーバー ID は V9 モデルと共有 | `FF1C:0092` 上で START `01` / END `02` の間に送るレポート `04`、読み取り専用バッテリーコマンド `1A`。2.4 GHz のみ |
| **SONiX キーボード（AJAZZ / AULA / EPOMAKER）** | `05AC:024F` 2.4G ドングル接続の AJAZZ AK820 MAX（検証済み）、EPOMAKER EA75（検証済み）、AULA F108 Pro。`0C45:FEFE` ドングル接続の AJAZZ AK980 V2。`0C45:FDFD` または `0C45:FEFE` ドングル接続の AJAZZ AK820 Pro。`342D:E479` 接続の EPOMAKER P75（実機未検証） | Usage Page FF60 上のベンダーレポート `20 01`、加算チェックサム（2.4G モードのみ、充電表示なし） |
| **その他の SONiX レシーバー（実機未検証）** | RK Royal Kludge R75（`342D:E485`）、Redragon Arlokks K742B（`342D:E4BC`）、M1 V5 VIA（`342D:E4C2`）、Lucky65V2（`342D:E407`）、Lofree Flow2（`388D:0003`）、MSI FORGE TKL W FRIEREN EDITION（`0DB0:0CA0`）、Essential75（`36B0:30BD`）、NUT65（`342D:E51A`）、RK 2.4G Dongle（`342D:E487`）、WEIKAV MAX102（`342D:E537`）、Lofree Flow2（`388D:0002`）、NuPhy Air75V2（`19F5:3245`）、SKN Qinglong（`362D:D028`）、Lemokey Link（`362D:D030`）、Wireless Link（`362D:D101`）、Spade65-QMK-2.4GHz（`342D:E49F`） | 同じくバッテリーのみの `20 01` クエリ。正確な VID:PID と 33 バイトのレポートを持つ FF60:0061 コレクションが必要。2.4G のみ、充電表示なし |
| **36B0 キーボード（PMO / WOBKEY / URX / EVO80）** | `36B0:3002` 2.4G ドングルまたは `36B0:3009` USB ケーブル接続の PMO (WOBKEY) Wave 75 RGB（Issue #343 の報告者が両接続でプロトコル検証済み）。同一ドングルまたはケーブル接続の Aurora 80（`3004`）、PMO P75（`302B`）、PMO 80（`3012`）（未検証）。ドングル接続の URX Core75（HaloBattery で確認済み）。EVO80（未検証） | PMO Hub ファームウェア: pmohub.cn 準拠の Usage Page FF60 上での `START_COMM` / `GET_BATTERY`（`AA 30`）/ `STOP_COMM`。URX / VIA ファームウェア: HaloBattery 経由 URX HUB 準拠の VIA custom-get `08 00 07`（チャネル 0、値 7）。充電表示なし |
| **DAREU** | `260D:1074` 2.4 GHz レシーバーまたは `260D:1090` USB ケーブル接続の EM901X（バッテリー読み取りは両接続で検証済み、レシーバーのドック着脱による充電フラグ遷移も検証済み） | バッテリーのみの Feature Report `08`、コマンド `04`、別のベンダーコレクション上で応答 `09`。製品 ID ごとに明確な単一の Input/Feature ペアが必要。両方接続時は有効な USB 読み取りを優先（マウス電源オフでもレシーバーがキャッシュ済みテレメトリを返すことがあるため） |
| **DAREU** | A84 キーボード（`260D:0022`、未検証） | インターフェース 0 上の SONiX Feature Report、コマンド `04 F6`（公式 A84 ドライバーのバッテリー読み取り）。パーセント単位の残量、充電フラグなし |
| **DAREU** | `260D:1131` マルチマウスレシーバーおよび USB ケーブル（`260D:1148`）接続の A980 Pro（バッテリー残量は実機検証済み、有線接続時の充電フラグも確認済み） | Togran プロトコル: Consumer Control コレクション上の 65 バイト Feature Report `0A`。スロットクエリ（class 0 / `A0`）の後にバッテリークエリ（class 7 / `80`、ケーブル経由時はスロット 0）。読み取り専用 |
| **Sharkoon** | `260D:1125` 接続の Skiller SGM50W（未検証） | DAREU EM901X と同じ Compx クエリ（Feature Report `08`、コマンド `04`、`FF01:0000` 上で応答 `09`）。Sharkoon のファームウェアアップデーターも VID `260D` の Compx 製ツール |
| **Zenith** | `260D:1114` 2.4 GHz レシーバー（バッテリー読み取り検証済み、充電状態は未検証）または `260D:1143` USB ケーブル（未検証）接続の Zenith Pro | `FF02:0002` 上の Output Report として送信する同一 Compx コマンド（`08`、`04`）。同じコレクション上でパーセント・充電フラグ・ミリボルトを含む応答 `08 04`（全バイト合計 `0x55` で検証） |
| **AJAZZ AK992** | Telink 2.4 GHz レシーバー `320F:50C3`（検証済み） | HID コレクション `FF1C:0092` 上の EVision バッテリークエリ |
| **ZOWIE** | 2.4 GHz レシーバー接続の EC1/EC2/EC3-CW、DW シリーズ（U2-DW、S2-DW ...）および U2 | コミュニティで文書化された読み取り専用ベンダーコマンド |
| **Royal Kludge (RK)** | 2.4 GHz ドングル（`2E3C:00A6` / `00E6`）または USB ケーブル（`2E3C:00A5` / `00E5`）接続の MG6 Pro | RK Web ドライバー由来の QiWang 64 バイトフレーム、`GET_BATTER_VOL` 読み取り（パーセント・電圧・充電状態） |
| **ASUS ROG** | Strix Scope II 96 (RX)、Azoth、Falchion キーボード。Keris、Harpe、Gladius、Chakram、Spatha、Pugio、Strix Impact マウス。Pelta ヘッドセット（2.4 GHz ドングル）。Cetra Open Wireless イヤホン（SpeedNova ドングル `0B05:1CAC`、左 / 右 / ケース）。Omni Receiver | ROG HID バッテリークエリ |
| **Machenike** | `248A:FF4C` 2.4 GHz レシーバーまたは `248A:FF4E` USB ケーブル接続の L7 Arctic / L7 Mix（両接続で検証済み） | 読み取り専用 Feature Report `51`、ステータスコマンド `06`、残量と充電状態。[プロトコルノート](#sec-machenike) |
| **MSI** | 2.4 GHz ドングル（`0DB0:9E22`）接続の VERSA 300 ELITE WIRELESS。CLUTCH GM31 Lightweight Wireless（2.4 GHz レシーバー `0DB0:0D3C` 検証済み、USB ケーブル `0DB0:0D3B`）および CLUTCH GM41 Lightweight Wireless（レシーバー `0DB0:0D4C` / ケーブル `0DB0:0D4B`、所有者のキャプチャに基づく） | `FF0D:00B0` および `FF00:0001` 上の読み取り専用ベンダークエリ `0F 20`。1 バイトにバッテリー残量と充電フラグを格納（MSI Center の Gaming Gear モジュール準拠のプロトコル）。GM41: `FF10:0006` 上のパッシブ `A0 xx 07 …` レポート |
| **MCHOSE** | 2.4 GHz レシーバーまたは USB ケーブル接続の L7 / L7 Pro / L7 Ultra（L7 Ultra 検証済み）、M7 / M7 Ultra、A7 / A7 Ultra、K7 マウス。A5 V2 Ultra（2.4 GHz レシーバー `3837:100C`、検証済み）、K7 Ultra（2.4 GHz レシーバー `3837:1001` 検証済み、A7 V2 Ultra+ `3837:100B` も動作見込み、Issue 227）、G3 V2（2.4 GHz レシーバー `3837:4245` および USB ケーブル `3837:418C`）。2.4 GHz レシーバー `3837:1014` または USB ケーブル `3837:4028` 接続の K7 V2 Ultra+（両接続で検証済み。同新ファミリの他レシーバー ID `1018`、`1016`、`102C`、`102D` は未検証） | 反転ペイロード付きベンダー Feature Report（alexfrih/mchose-linux 由来のプロトコル）。Realtek `3837` ドングルは vid フィールドを `41E4`（A5 V2 Ultra）または `3837`（K7 Ultra）として同一クエリに応答。G3 V2: `FF01:0010` 上の読み取り専用ベンダークエリ。K7 V2 Ultra+: `FF01:0001` 上の 64 バイトレポート `0x4D`、デバイス情報コマンド `0x0900`（M HUB Web ドライバー由来のプロトコル） |
| **MCHOSE A5（第 1 世代）** | 1K または 4K 2.4 GHz レシーバー（`2023:F013`、`2023:F015`、`2023:F018`）または USB ケーブル（`2023:F017` A5 Pro、`2023:F019` A5 Pro Max）接続の A5 Pro / A5 Pro Max（こちらでは未検証） | `FFFF` 上の 64 バイト Feature Report 内の読み取り専用バッテリーコマンド `0x83`（ページ 0）、応答マーカー `0xA1`（プロトコルは z750sasr A5 Pro Max Web ドライバーと HaloBattery、ID は Klegus/mchose-macos 由来） |
| **MCHOSE ヘッドセット** | 2.4 GHz ドングル（`3837:6011`、検証済み）接続の V9 Pro 2 | `FF07:0222` 上の M HUB 読み取り専用 "MC" バッテリーフレーム（レポート `0x55`、サブコマンド `0x0B`）。1 バイトに残量と充電フラグ（M HUB Web ドライバー由来のプロトコル） |
| **AULA / MCHOSE / Redragon キーボード** | 2.4 GHz レシーバー（`3554:FA09`、`41E4:2001`）接続の AULA F75 / F87 Pro / F99、MCHOSE K99 V2、G75 Pro、X75 およびその他の M HUB キーボード、Redragon Horus Pro / Pro V2（K618RGB-PRO）。`05AC:024F` レシーバー接続の MCHOSE K87（SONiX ではなくインターフェース 1 上の BY レイアウト） | レポート 0x13 フレーム、コマンド 0x4A（MCHOSE および Redragon モデルは M HUB 同様にコマンド 0x05 で識別）。Bluetooth および有線モードは対象外 |
| **MCHOSE キーボード** | 2.4 GHz レシーバー `3837:3033` 接続の G75 V2（検証済み）。G87 V2 および K99 V3 も同じレシーバーを採用（同一プロトコル、未検証）。K87S は同一レシーバー ID で別プロトコルを使用するため対象外 | ID なし 64 バイト `0001:0000` コレクション上の M HUB 読み取り専用 "GLW" func-config クエリ: リクエストフラグ `0x55`、コマンド `0x05`、ペイロードバイト 32 に残量（bit 7 = 充電中）、加算チェックサム |
| **AULA SC580** | USB ケーブル（`088D:062E`、検証済み）または 2.4 GHz レシーバー（`089D:062F`、検証済み）接続の SC580 / SC580X マウス | 33 バイトベンダーコレクション FF02:0000 上の読み取り専用コマンド `0x30`（デバイス情報）、加算チェックサム。充電中はマウスが固定値 100 を返すため最後の残量を表示。Bluetooth モードは対象外 |
| **AULA HERO 68 Air** | 8K Wireless Receiver（`372E:106C`）接続の HERO 68 Air | Usage Page FF60 上の ACK 付き 20 バイトフレーム（1 メッセージあたりデータフレーム 4 つ＋トレーラー）、読み取り専用バッテリーコマンド 0x87、残量後の充電フラグ 0x10。Bluetooth および有線モードは対象外 |
| **EWEADN (前行者)** | "Gaming 2.4G" レシーバー（`372E:103D`）接続の S7 Max / Pro / Ultra および S9 Max / Pro / Ultra / Ultra+。USB ケーブル（`372E:1027`）接続の S9 Ultra | `FF00:0001` 上の読み取り専用 Feature Report `03`: リンク確認 `47`、デバイス基本情報 `4F 81`（バッテリー % と充電ビット）、EWEADN Web ドライバー準拠 |
| **Rapoo VT** | VT3 Max Gen 2（検証済み）、VT9 Gen 2（検証済み）、同一ステータスインターフェースを公開するその他の Nordic 54L VT マウス、旧 VT3 Pro（実験的対応）、VT1 Pro Max（所有者の USB キャプチャに基づく） | `FF00:0002` 上のパッシブ HID ステータスレポート `07`（16 または 19 バイト。一部の VT3 Max Gen 2 レシーバーでは 13 バイト）。旧 `BB` は VT3 Pro `1215/4415` と VT1 Pro Max `1233/4433` に限定。レシーバーと USB ケーブル対応、充電状態付き |
| **Motospeed / Delux / Ajazz** | Motospeed X6、Delux M900 Pro（Xenta モデル 30/50、旧 3D）、Delux M800 Pro、Ajazz AJ179 ファミリ。3151 レシーバー接続の AJ159 およびその他の AJ シリーズマウス。AJ139 V2 MC（レシーバー `A8A5:2255`、ケーブル `A8A4:2255`） | ベンダーレポート（M900 Pro: パッシブステータスブロードキャストまたは Feature クエリ、Xenta イベント 40/41。AJ シリーズ: 0xF7 ステータスポーリング後、Feature Report 0x05） |
| **Incott** | G23 V2 / G24（`093A:522C` レシーバー、`093A:622C` ケーブル） | 読み取り専用ステータス Feature Report 09 |
| **Attack Shark およびその他の中国系ブランド** | Rongyuan レシーバー（81 モデル: `3151:402D` の Attack Shark R3 および AJAZZ AJ179 Pro、K86、X82 PRO HE、Ajazz キーボード、一部の MSI など。Bluetooth 接続の K86 はキーボードとして表示）。Xenta レシーバー（Attack Shark X6 / R1、X11、X3 Max、V3 Pro、V6。X6 は `1D57:FA61` でも対応、未検証）。Semico 1A2C キーボード（`1A2C:8FFF` ドングル検証済みの Attack Shark X98 および `1A2C:A034` ケーブル、`1A2C:8FFF` / `1A2C:A036` の AJAZZ AK820 Max Plus） | Rongyuan ステータスレポート。Xenta パッシブブロードキャスト。Semico 読み取り専用 `0x0E` ステータスクエリ（`FF02:0002` 上の `AA 55 CC 33`。X98 はバッテリー動作中も充電中も `state=1` を返すため充電フラグは省略） |
| **Wraith** | W1 / W1 Freestyle（`093A:522C` レシーバー、`093A:622C` ケーブル。Incott と同一 ID でモデルコードにより判別） | 全ボタンに対する読み取り専用のボタン別読み取り `86`（Feature Report 09）の後、プッシュされたステータス Input Report 09 を受信 |
| **Fantech** | Helios Go XD5（有線 `25A7:FA7B`、ドングル `25A7:FA7C`）。再利用された `1EA7:0066` / `1EA7:0064` ドングル接続の Raigor III（検証済み）、Raigor II WG10 およびその他の汎用 2.4G Mouse デバイス | Helios Go XD5: ベンダー Feature Report `08`、コマンド `04`、合計 `0x55` チェックサム。Raigor/2.4G Mouse: `FFB5:0001` 上の読み取り専用 `B5` ステータスページクエリ、チャンク `94` = 最後に報告されたパーセント（スリープ中・電源オフ・充電中は古い値のままの場合あり、充電状態なし） |
| **Sony** | DualShock 4、DualSense、DualSense Edge（USB、Bluetooth、ワイヤレスアダプター）。INZONE H9 II および H5 ヘッドセット。INZONE Buds（USB-C ドングル） | Input Report、INZONE ベンダープロトコル |
| **Fractal Design** | 2.4 GHz ドングルまたは USB-C ケーブル接続の Scape ヘッドセット | Fractal の Adjust Pro Web アプリ準拠のベンダー `GET_DEVICE_STATE` クエリ（Usage Page FF00） |
| **Jabra** | GN Protocol を話す全 Jabra ヘッドセット（Evolve2 / Evolve3 など）、専用 USB ケーブル直結または Jabra Link ドングル配下。製品 ID リスト不要、DECT ベース（Engage、PRO 9xx、GO 6400、Link 400）は除外。デバイス名はヘッドセットから取得 | Usage Page FF00、Usage 05 または 01 上の GNP ステータスクエリ（class 12 / op 02）、GNP アドレス 08（USB）または 04（ドングル） |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro（`37D7:2401`）、2.4 GHz レシーバーまたは USB。Apex 5（`37D7:2501`）、2.4 GHz レシーバーまたは USB | `FFA0:0001` 上のベンダー HID 情報クエリ。0〜5 のバッテリー段階を 20% 刻みで 0〜100% へ変換、充電状態付き。Space Station サービス不要 |
| **GameSir** | 2.4 GHz レシーバー接続の Nova Lite、Nova 2、Nova 2 Lite。USB 接続の Nova 2 Lite。Xbox (GIP) モードの G7 Pro（検証済み: ゼンレスゾーンゼロ エディション、レシーバー `3537:105E`）およびその他の GameSir パッド。Cyclone 2（XInput モード、レシーバーまたはケーブル）。2.4 GHz ドングル（`3537:1015`）接続の Cyclone Pro（事前に 1 度 Windows と Bluetooth ペアリングが必要） | ベンダーデバイス情報クエリ（Usage Page FF7A）。Xbox モードでは Windows.Gaming.Input バッテリーレポート（実 %）。Cyclone 2: ベンダーバッテリーリクエスト（Usage Page FFF0）。Cyclone Pro: Bluetooth LE（サービス `0x8650`）経由の GameSir アプリ base-info リクエストを 2 分ごとに読み取り |
| **BEITONG** | 2.4 GHz レシーバー（`20BC:5128`、XInput モード、検証済み）接続の KP20 / BTP-KP20、およびレシーバー（`20BC:515C`、XInput モード）接続の KP40D / BTP-KP40D。BEITONG iControl 不要 | Usage Page `00FF` 上のベンダー "get base info" クエリ（レポート `02`、ニブルスクランブルされたペイロード）、充電状態付き |
| **8BitDo** | Ultimate 2 Wireless（2.4 GHz ドングルで X-input `2DC8:310B` 検証済み、D-input `2DC8:6012` — B ボタンを押しながら電源オン、ファームウェア 1.03+）、Ultimate 2C Wireless、Ultimate 3-mode、Ultimate 2.4G、Ultimate Bluetooth、Pro 3、Pro 2、SN30 Pro、SF30 Pro | ベンダー HID ステータスクエリ（`FF7A`/`FFA0`）および SDL ゲームパッド Input Report `01`/`04`、充電状態付き |
| **Samsung** | Galaxy Buds、Buds+、Buds Live、Buds Pro、Buds2、Buds2 Pro、Buds FE、Buds Core、Buds3 / Buds3 Pro / Buds3 FE（Bluetooth） | Samsung の RFCOMM (SPP) サービス上でイヤホンがプッシュするステータスフレーム（読み取り専用）。トレイには低い方のイヤホン残量を表示し、ツールチップに左・右・ケースを表示。Galaxy Buds アプリは閉じておく必要あり |
| **Nothing / CMF** | Nothing Ear (3a)（検証済み）、Ear (a)、Ear (2)、Ear、CMF Buds（Bluetooth） | Nothing の NT Link RFCOMM サービス（`aeac4a03-dff5-498f-843a-34487cf133eb`）上の読み取り専用 `0xC007` バッテリークエリ。トレイには低い方のイヤホン残量を表示し、ツールチップに左・右・ケースを表示 |
| **Akko** | Akko Air 01（`3151:5006`、2.4 GHz レシーバー、検証済み）および Akko V9 Dash Pro（`38EE:000C`、2.4 GHz レシーバー、検証済み） | Air 01: Rongyuan `0xF7` ステータスレポート。V9 Dash Pro: `FF1C:0092` 上の読み取り専用 64 バイト `0x1A` ステータスクエリ、充電状態付き |
| **MOONDROP** | 2.4 GHz ドングル（`35D8:0133`）接続の GM01 Pro ヘッドセット。USB ケーブル接続時は前回の残量で充電中として表示 | レポート `4B` 上の WalkPlay ベンダー読み取りコマンド（読み取り専用） |
| **VGN** | 2.4 GHz ドングル（`372E:10BB`、検証済み）接続の OMNISOUND (ZHOUTING) ヘッドセット | V HUB "ZHOU" クエリ: コントロールコレクション `000C:0001`（32 バイト入力、64 バイト出力レポート）上の Output Report `55`（ペイロード `65 01`）。応答からパーセント値を取得（読み取り専用） |
| **JBL** | Quantum 650 Wireless（検証済み、2.4 GHz ドングル）。Quantum 520、650X、850、950、950X Wireless（ドングルまたは USB ケーブル、同一プロトコル、未検証） | バッテリー機能向けの JBL "HIDV3" デバイス情報クエリ（Usage Page FF12）、充電状態付き |
| **JBL** | Quantum 350 Wireless（Windows で `0ECB:206B` 2.4 GHz レシーバー検証済み）。Quantum 610 Wireless（`0ECB:205C` 2.4 GHz ドングル、Windows 未検証）。Quantum 360 Wireless（`0ECB:2115` 2.4 GHz ドングル、未検証） | ワイヤレス接続およびバッテリー残量（%）用の HIDV1 Feature Report |
| **Xbox** | Xbox Wireless アダプター、USB または Bluetooth 接続のコントローラー。コントローラーに接続されたヘッドセット | Windows.Gaming.Input バッテリーレポート（実 %）、XInput フォールバック |
| **Switch Pro 互換** | `057E:2009` として認識されるコントローラー（検証済み: Switch モードで 2.4 GHz レシーバー経由の GameSir Tarantula Pro） | Steam Input または他のホストがフルレポートを有効化した後の HID レポート `0x30` による 5 段階バッテリー残量 |
| **Apple AirPods / Beats** | AirPods Max（検証済み、Lightning `200A` および USB-C `201F`）、AirPods Pro 3（検証済み、`2027`）、AirPods Pro 1 / 2、AirPods 1–5 および Beats ヘッドホン / イヤホン | BLE "近接ペアリング"（`0x07`）ブロードキャスト（AirPods Max と Beats ヘッドホンは単一残量、イヤホンは左・右・ケースを 10% 刻み＋充電状態で表示）、ペアリング済みモデルと照合 |
| **スマートフォン（スマートフォン連携）** | Wi-Fi または Bluetooth 経由で Microsoft スマートフォン連携に接続された任意の Android スマートフォン（検証済み: Nothing Phone (4a) Pro） | スマートフォン連携の Windows 11 スタートメニューカード（`StartMenuCompanion.json`）から残量と充電状態を取得。Bluetooth 不要 |
| **Darmoshark** | Windows 上で 2.4 GHz レシーバー接続の M3（`248A:FF30`）および M3S（`248A:FF31`） | マウス識別およびバッテリー用 HID Feature Report |
| **Darmoshark** | Nordic 1K レシーバー（`1915:0723`）接続の M3S Pro | `FF0A` コレクション上のベンダー HID ステータスクエリ |
| **Alienware** | 2.4 GHz ドングル（`413C:A515`、検証済み）接続の AW920H ヘッドセット。Bluetooth 接続時は Bluetooth の行で対応 | `FF13:0001` 上のベンダークエリ `06 C0 0A`、XOR チェックサム付き応答レポート `07`。Alienware Command Center の AW920H プラグインによるデコードに準拠した残量・充電状態・危険残量フィールド |
| **Niceboy** | 2.4 GHz レシーバー（`248A:FA02`、検証済み）接続の MW400 | 読み取り専用レポート `05` クエリ `24 FA 48`。メーカーアプリのテーブルを用いてバッテリー電圧を 10% 刻みへ変換、充電フラグ付き |
| **Bluetooth** | *設定 → Bluetooth とデバイス* でバッテリーが表示されるあらゆるデバイス（イヤホン、ヘッドホン、BLE マウス・キーボード）。Google Fast Pair イヤホン（Jabra Elite 8 Active 検証済み、Pixel Buds や多数の Sony / JBL / Bose モデル）では左・右・ケースの残量も取得 | Windows デバイスプロパティ。Fast Pair バッテリーブロードキャスト（BLE サービスデータ `FE2C`）を Bluetooth アドレスでペアリング済みデバイスと照合 |
| **汎用 HID** | 標準 HID *Battery Strength* Usage を報告するデバイス | HID Usage Page 0x06 / 0x85 |
| **HeadsetControl** | [HeadsetControl がサポートするすべてのヘッドセット](https://github.com/Sapd/HeadsetControl#supported-headsets)（Audeze、Jabra、Sony INZONE、新型 Logitech など） | 同梱。`headsetcontrol -o json` を実行 |
| **MAONO PD200W** | 2.4 GHz レシーバー（352F:040E） | バッテリー残量（%）、実機検証済み |


**実機検証済み:** Glorious Model O Wireless、HyperX Cloud III Wireless、HyperX Cloud Stinger Core Wireless（PlayStation レシーバー `0951:1713`、充電状態は未検証）、HyperX Cloud Core Wireless DTS（レシーバー `0951:173F`、満充電時の値は未検証）、HyperX Pulsefire Haste 2 Core Wireless（ドングル `03F0:0AB5`、Haste 2 Wireless の他ドングルは未検証）、Cooler Master MM712（ドングル）、Rapoo VT3 Max Gen 2（レシーバー `24AE:1417` および USB ケーブル `24AE:4617`、他の Rapoo モデルは未検証、[Rapoo プロトコルノート](#sec-rapoo)参照）、Redragon M916 Pro 1K（レシーバー `3554:F55D`）、Taidu TSG808（レシーバー `3554:F5D5`）、Redragon M915RGB-WL（レシーバー `25A7:FA07`、他の Areson モデルは未検証、[Areson プロトコルノート](#sec-areson)参照）、SteelSeries Rival 650 Wireless（レシーバー `1038:1726` および USB ケーブル `1038:172B`）、SteelSeries Arctis Nova Pro Wireless（ベースステーション `1038:225D`、残量読み取り検証済み、充電および電源遷移は未検証）、HECATE G5M PRO（レシーバー `35BB:D3FB`）、WLMouse YING Magnesium（8K レシーバー `36A7:A874`）、ATK N9 Ultra（レシーバー `373B:1204`）、Corsair Scimitar Elite SE Wireless（Slipstream レシーバー `1B1C:2B00`）、Corsair Dark Core RGB Pro SE（Slipstream レシーバー `1B1C:1BDC`）、Corsair Sabre V2 Pro Ultralight（2.4 GHz レシーバー `1B1C:2B2A`、残量読み取り確認済み）、DAREU EM901X（レシーバー `260D:1074`、充電およびスリープ/復帰は未検証）、Link 390（`0B0E:2E51`）上の Jabra Evolve3 75、MCHOSE G3 V2（レシーバー `3837:4245` および USB ケーブル `3837:418C`）、MCHOSE K7 Ultra（レシーバー `3837:1001`）、MCHOSE K7 V2 Ultra+（レシーバー `3837:1014` および USB ケーブル `3837:4028`、有線接続時の充電表示あり）、MSI VERSA 300 ELITE WIRELESS（ドングル `0DB0:9E22`、充電およびスリープ処理は未検証）、MSI Clutch GM31 Lightweight Wireless（レシーバー `0DB0:0D3C`、GM41 は所有者のキャプチャから同一ドライバーを使用）、AJAZZ AK820 MAX（ドングル `05AC:024F`）、AULA HERO 68 Air（8K Wireless Receiver `372E:106C`）、AULA SC580（USB ケーブル `088D:062E` およびレシーバー `089D:062F`、充電・スリープ含む）、AirPods Pro 3（Bluetooth、モデル `2027`）、AirPods Max（Bluetooth、モデル `200A`）、Sprime PM1（レシーバー `1915:AC1C`）、Ninjutso Ten Air（レシーバー `093A:EB01` および USB ケーブル `093A:E020`）、MOONDROP GM01 Pro（ドングル `35D8:0133`）、Delux M800 Pro（レシーバー `248A:5B2F`）、Razer Barracuda X (2022)（レシーバー `1532:0550`、残量読み取り確認済み、充電遷移は未検証）、Razer BlackShark V3 X（HyperSpeed ドングル `1532:057D`）、Fantech Helios Go XD5（ドングル `25A7:FA7C`）、Fantech Raigor III（ドングル `1EA7:0066`、ファームウェアから充電状態は報告されず）、Finalmouse UltralightX（ドングル `361D:0100`）、Finalmouse Starlight X（ドングル接続）、Chimera V2（レシーバー `3554:F512`、残量と充電状態を読み取り）。
同じく実機検証済み: Machenike L7 Arctic / L7 Mix（`248A:FF4C` レシーバーおよび `248A:FF4E` ケーブル）、充電状態とケーブル・レシーバー間の重複抑止を含む。Bluetooth および低バッテリー／満充電境界は実機未検証。
同じく実機検証済み: MCHOSE V9 Pro 2（`3837:6011` ドングル）、残量読み取り済み、充電およびスリープは未検証。
同じく実機検証済み: `05AC:024F` 2.4 GHz レシーバー接続の EPOMAKER EA75（[PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60) の既存 SONiX ドライバーを使用）。バッテリー残量（%）、レシーバー再接続、電源オン復帰を確認済み。このドライバーでは充電表示および有線時のバッテリー報告はサポートされず、Bluetooth での報告は未検証。USB 給電接続時に報告値が 100% へ跳ね上がることがありますが、信頼できる充電インジケーターではありません。
同じく実機検証済み: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition（レシーバー `1038:1878` および USB ケーブル `1038:187A`）、充電中・電源オフ（最後の残量を薄く保持）・SteelSeries GG 起動中の動作を含む。GG は 3 段階バーのみを表示しますが、残量は一致していました。
同じく実機検証済み: RAWM Leviathan V4（RAWM HS Receiver `1915:2346`、残量読み取り済み、充電状態は未検証）。
**プロトコル文書および他プロジェクトをもとに実装済み・実機未検証:** 上記以外のすべての対応デバイス（Fantech Raigor II WG10 を含む。検証済みの Raigor III と同じ `1EA7:0066` ドングルとコレクションを使用するため動作する見込み）。これらのデバイスをお持ちの場合は、[Issue を作成して](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues)動作可否をご報告ください。

## インストール

[![最新バージョン](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. [最新リリース](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)から **`BatteryHub-Setup-<version>.exe`** をダウンロードします。
2. 実行して 19 種類の対応言語から好みのセットアップ言語を選び、画面の案内に従って進めます。**管理者権限は不要**で、**他にインストールすべきものも一切ありません**（ランタイム、ドライバー、メーカー純正アプリ不要）。HeadsetControl は同梱されており、編集可能な `lang\` フォルダーも `BatteryHub.exe` の隣にインストールされます。

インストーラーはスタートメニュー項目とアンインストーラー（*設定 → アプリ*）を登録し、サインイン時の自動起動も設定できます。インストール不要で使いたい場合は、`BatteryHub-<version>-portable.zip` をダウンロードし、任意の場所に展開して（UI 翻訳を使うには `lang\` フォルダーを `BatteryHub.exe` と同じ場所に残してください）`BatteryHub.exe` を実行してください。

**注意:**
- **SmartScreen の警告:** 実行ファイルにはコード署名がないため、Windows が「Windows によって PC が保護されました」と表示する場合があります。*詳細情報 → 実行* をクリックするか、ご自身でビルドしてください。
- **Windows 11 のトレイアイコンモード:** 新しいトレイアイコンは `^` のオーバーフロー領域に入ります。タスクバーにドラッグするか、*設定 → 個人用設定 → タスクバー → その他のシステム トレイ アイコン* で有効にしてください。
- **特定のデバイスにアクセスさせない:** アプリの実行中に動作が不安定になるデバイスがある場合は、`HKCU\Software\WirelessBattery` 配下のレジストリ文字列値 `IgnoreDevices` に `VID:PID` のペアを記載してください（16 進数、カンマ区切り、例: `28BD:0947, 1234:ABCD`。ID は `--dump` で確認できます）。これにより、そのデバイスを一切開かなくなります。ペンタブレットは自動的にスキップされます。

## Windows でのアップデート

公式の安定版 Windows ビルドは、起動の 30 秒後、およびアプリ実行中の 24 時間ごとに、バックグラウンドでプロジェクトの最新安定リリースを確認します。メニューを開くと **アップデートが利用可能: vX.Y.Z...** と表示されるほか、手動で **アップデートを確認...** を選ぶこともできます。アップデート情報はこのメニュー内にのみ表示され、バッテリーアイコン・パーセント表示・ツールチップは一切変わらず、自動確認で通知やダイアログが出ることもありません。バックグラウンド確認を無効にするには、メニューの **アップデートを自動的に確認** をオフにしてください。

インストール版の場合は、アップデートの項目をクリックして **ダウンロードしてインストール** を選びます。このクリックなしにインストールされることはありません。アプリはリリースの `SHA256SUMS.txt` とその署名をダウンロードし、アプリに組み込まれたメンテナーの公開鍵で署名を検証したうえで、Windows インストーラーをダウンロードし、その SHA-256 が署名済みリスト（および GitHub が報告するハッシュ）と一致する場合にのみ実行します。その後、既存のインストールが更新されます。設定と自動起動の設定は保持され、インストール完了後にアプリが再起動します。すべてのユーザー向けインストールでは管理者権限の昇格を求められる場合があります。**リリースノート**は公式リリースページを開き、**後で**は現在のバージョンを維持します。ポータブル版では ZIP を手動ダウンロードできるようリリースページが開きます。

更新確認はアカウントやトークンなしで GitHub の公開 API に接続します。デバイス情報やバッテリー情報は一切送信されません。オフライン時の失敗や GitHub のレート制限が発生してもバッテリー監視は継続され、すでに検出されたリリースは後続の成功した確認で置き換わるかインストールされるまでメニューに表示され続けます。ダウンロードのキャンセルは、実行中のネットワーク操作が所定のタイムアウトで終了するのを待機します。インストーラーが Windows を自動的に再起動することはありません。

**アップデートが安全にインストールできる理由:** 署名鍵は GitHub に置かれることがありません。メンテナー自身の PC 上で各リリースのチェックサム一覧に署名しているため（[docs/releasing.md](#sec-releasing) を参照）、仮に GitHub アカウントやビルドワークフローが乗っ取られたとしても、アプリがインストールを受け入れるアップデートを公開することはできません。有効な署名のないリリースもメニューには表示されますが、手動ダウンロードのみ可能です。この署名は Windows 独自の SmartScreen や UAC プロンプトに代わるものではありません。

この機能を含む最初のリリースは、一度手動でインストールしてください。開発ビルド／テストビルドではローカルの変更が意図せず上書きされないよう公式アップデート確認が無効化されています。Linux 版のアップデートおよびポータブル版の自動置換は今後の対応予定です。

## コマンドライン

```
BatteryHub.exe --list     # すべてのデバイスとバッテリー残量を表示して終了
BatteryHub.exe --json     # デバイスとバッテリー残量の JSON 配列を表示して終了
BatteryHub.exe --dump     # すべての HID コレクション、開けなかった HID デバイス、すべての USB デバイス（HID インターフェースなしを含む）、Bluetooth デバイスを表示（%TEMP%\BatteryHub-dump.txt にも保存）
BatteryHub.exe --report   # 「デバイスのサポートをリクエスト」ウィンドウを開く
BatteryHub.exe --demo     # 実機の代わりに全ブランドのサンプルデバイスを表示（スクリーンショットや配色の確認用）
BatteryHub.exe --quit     # 実行中のインスタンスを終了
```

Linux ビルドでも `BatteryHub.exe` の代わりに `wireless-battery` を使って同じフラグが利用でき、さらに `--help` も使用できます。`--json` はスクリプトやステータスバー用ウィジェットで解析できる安定した配列を出力します:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` は、デバイスがスリープ状態のときに最後に確認した残量をアプリが表示し続ける秒数です。新しいフィールドが追加されても後方互換性が保たれます。

**デバイスが表示されない場合:** ウィジェットまたはトレイアイコンを右クリックして **デバイスのサポートをリクエスト...** を選択します。該当デバイスを選び、送信される内容（デバイス名、種類、USB/HID ID とインターフェース構成、および任意の氏名・メモがそのまま表示されます）を確認して **送信** をクリックしてください。[krisgfx.com/tools](https://krisgfx.com/tools/#requested) の公開リストに追加され、GitHub Issue の作成または更新が行われます。**完全なレポートをコピー** を押すと、`--dump` の完全な出力がクリップボードにコピーされ、Issue に貼り付けられます。レポートデータが送信されるのは「送信」をクリックしたときだけです。公式の Windows ビルドは[Windows でのアップデート](#windows-でのアップデート)で説明したとおりアップデート確認のため GitHub に接続することもありますが、アップデート確認でデバイス情報やバッテリー情報が送信されることはありません。

## ビルド

[MinGW-w64](https://www.mingw-w64.org/)（例: [MSYS2](https://www.msys2.org/) の `pacman -S mingw-w64-x86_64-gcc make`）が必要です。

```
make                                      # 開発ビルド、バージョン 0.0.0
build.bat                                 # PATH に g++ と windres がある標準 cmd でのビルド
make VERSION=1.2.3 CHANNEL=test            # バージョン指定ビルド、公式アップデート無効
build.bat 1.2.3 test                       # 同等のバージョン指定 cmd ビルド
make test VERSION=1.2.3 CHANNEL=test       # デバイスおよびアップデーターの回帰テスト
```

インストーラーおよびポータブル ZIP をビルドするには、[Inno Setup](https://jrsoftware.org/isinfo.php) をインストールし、まず目的のバージョンでビルドしてから（例: `make VERSION=1.2.3 CHANNEL=test`）、`powershell -File installer\build-installer.ps1 -Version 1.2.3` を実行します。パッケージ化スクリプトは実行ファイルのバージョンと異なる場合エラーになります。このスクリプトはピン留めされた HeadsetControl リリースをダウンロードしてチェックサムを検証します。GitHub Actions はこれらすべてを自動実行するため、`v1.0.0` のようなタグをプッシュするとインストーラー、ポータブル ZIP、および（GPL ライセンスの要件に従い）HeadsetControl のソースコードを含むリリースが公開されます。

Windows ビルドでは実行ファイルとリソースで共有するバージョン情報を生成するため PowerShell も必要です。公式リポジトリのバージョンタグは `CHANNEL=stable` でビルドされ、ローカルビルドの既定値は `dev` です。フォークやプルリクエストでは公式アップデートが自動的に有効になることはありません。

`BatteryHub.exe` 単体でも動作します。同じ場所（または `PATH` 上）に `headsetcontrol.exe` がない場合は、追加のヘッドセット対応のみ利用できなくなります。

## Linux（実験的機能）

Windows アプリと並行して Linux ビルドも用意されています。hidraw ベースの HID バックエンドと GTK4 StatusNotifierItem トレイアイコンを使い、Windows 版と同じベンダードライバーを使用します（Windows 側のコードパスには影響しません）。Linux 専用ファイルはすべて `linux/` と `src/linux/` にあり、`build-linux.sh` でビルドします（Windows 版は引き続き `build.bat` を使用します）。

| | Fedora | Ubuntu / Debian |
|---|---|---|
| コンパイラと make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

追加の HID ライブラリは不要です（hidraw を直接使用します）。

```sh
./build-linux.sh
./build-linux.sh test         # HID レポートディスクリプターパーサーの単体テスト
./wireless-battery --list     # 検出した残量を表示して終了
./wireless-battery --dump     # HID コレクション一覧を表示
./wireless-battery --quit     # 実行中のトレイインスタンスを終了
```

HID へアクセスするには udev ルールが必要です。設定しない場合、アプリは起動してもデバイスが見つかりません:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# ログアウトして再ログインしてください
```

トレイアイコンは KDE Plasma でネイティブに動作し、GNOME では `gnome-shell-extension-appindicator` などの AppIndicator ホストが必要です。*言語* サブメニューから多言語切り替えが行えます（既定では `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` に追従し、`--help` もローカライズされます）。`make -f linux/Makefile.linux install` を実行すると、バイナリ、`$(PREFIX)/share/wireless-battery/lang/` への `lang/*.json`、および `$(PREFIX)`（既定は `~/.local`）へのデスクトップランチャー（`linux/wireless-battery.desktop`）と `linux/wireless-battery.svg` がインストールされます。ユーザーによる言語の上書きファイルは `~/.config/wireless-battery/lang/` に配置します。

フェーズ 1 では Logitech、Razer、SteelSeries、Corsair、HyperX、PlayStation、Cooler Master、Glorious、Finalmouse、および共通の Kysona/Pulsar/ATK/G-Wolves プロトコルに対応しています。Bluetooth/UPower フォールバック、HeadsetControl、および残りのベンダーは今後のフェーズで対応予定です。

## 制限事項

- **混雑したタスクバー:** Windows 11 の中央揃えタスクバーが非常に混み合っている場合、アプリボタンがウィジェットの位置まで伸びて重なることがあります。Windows 10 ではタスクボタン領域が自動的に狭められます。
- **スマートフォン:** 「スマートフォン連携」がスタートメニューのコンパニオンカード用に書き出すファイルから読み取っています。これは公開 API ではないため、スマートフォン連携のアップデートで動作が変わる可能性があります。スマートフォン連携が接続中と報告している間表示され、3 時間以上古いカードは薄く表示されます。カードが充電中を示している場合は充電ボルトが表示されます。
- **スリープ中のデバイス:** スリープ中のデバイスは応答しないことがあります。その場合、最後の値が薄く表示されたままになります。Logitech レシーバーはスリープ中のデバイスをリンクから切断するため、最後の値は 30 分間保持されます。
- **HECATE G2 Wireless 7.1 ヘッドセット**（2.4 GHz ドングル `35BB:A009` / `A209`）: このドングルのバッテリークエリがまだ文書化されていないため読み取れません。対応を追加するには、HECATE ソフトがヘッドセットのバッテリーを表示している間の USB キャプチャ（CONTRIBUTING.md を参照）が必要です。
- **Keychron キーボード:** 純正ファームウェアでは Bluetooth 経由でのみバッテリーを報告します（Bluetooth サポート経由で表示されます）。2.4 GHz レシーバーまたはケーブル経由で表示するにはバッテリーパッチ適用済みのファームウェアが必要です（[docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware) を参照）。Keychron Launcher からキーボードを更新するとパッチは上書きされて消えます。Keychron マウスには対応しています。
- **Baseus AeQur GH02 ヘッドセット:** 2.4 GHz ドングル（`10D6:4802`、Actions チップ）はオーディオ、メディアキー、および同チップのファームウェア更新チャネルのみを扱い、バッテリー情報は伝送しません。残量を見るには Bluetooth で接続してください（Windows が残量を報告する場合は Bluetooth サポート経由で表示されます）。
- **Weikav Lucky65 v1 キーボード:** ファームウェアが 2.4 GHz ドングル（`0603:0351`、Novatek チップ）経由でバッテリーを報告しません。キーボード側にバッテリー確認ショートカットもなく、公式コンフィギュレーターもドングル経由ではなく USB ケーブル接続時のみ通信するため、表示できるバッテリー情報がありません。
- **Rapoo:** 対応している VT マウスは自発的にステータスを送信するため、1 回の更新で一致するインターフェースごとに最大 4 秒待機する場合があります。スリープ中のマウスは最後の値を薄く表示したまま最大 30 分間保持されることがあります。対応対象は Nordic 54L のレポート `07` および旧 `BB`（VT3 Pro、VT1 Pro Max）であり、CH584 レポート `08`、オフィス向け MT/M シリーズマウス、およびその他のファームウェアプロトコルはこのドライバーの対象外です。
- **GameSir Cyclone Pro:** ドングルがバッテリー残量を伝送しないため、コントローラーから Bluetooth LE 経由で読み取ります。Windows と 1 度ペアリングし（設定 > Bluetooth とデバイス > デバイスの追加 > Bluetooth > `GameSir-Cyclone Pro`）、そのままドングル経由でプレイしてください。PC に Bluetooth が必要です。残量は 2 分ごとに更新され、充電中のパーセント表示はありません。ペアリングしない場合、ドングルは "Full" の Xbox コントローラーとして表示されます。詳細は [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro) にあります。
- **RAWM:** レシーバー越しにマウスへ問い合わせるため、スリープ中のマウスは応答しません。最後の値を薄く表示したまま最大 30 分間保持され、スリープ中は更新ごとに約 1 秒余分に時間がかかります。実機検証済みは RAWM HS Receiver（`1915:2346`）上の Leviathan V4 のみで、他モデルは RAWM HUB のデバイステーブルから取得しています。Leviathan V4 GT および NYX60（VID `373E`、RAWM HUB 3.0）や RAWM HS キーボードは別プロトコルを使用するため対象外です。
- **Flydigi:** このドライバーは Vader 5 Pro および Apex 5 を対象としています。Bluetooth 接続およびその他の Flydigi モデル（例: Apex 6）は対象外です。パーセント表示は粗いバッテリー段階を表します。Apex 5 は 2.4 GHz レシーバーと USB ケーブルで実機検証済みで、Vader 5 Pro は SDL および Windows ハードウェアトレースに基づいています。
- **未対応デバイス:** VERSA 300 ELITE と CLUTCH GM31 / GM41 以外の MSI ワイヤレスマウス、MSI ワイヤレスキーボード、Razer Kraken ヘッドセットおよび `1532:0550` 上の Barracuda X (2022) 以外の Barracuda モデル、Haste 2 Wireless / Haste 2 Core Wireless 以外の HyperX Pulsefire マウス、ならびに Xbox アダプター経由の Xbox Wireless Headset は、バッテリープロトコルが文書化されていないためまだ対応していません。Xbox Wireless Headset は Bluetooth 接続であれば動作します。これらを追加するには所有者からの USB キャプチャ（CONTRIBUTING.md を参照）が必要です。
- **その他のデバイス:** 一部の 2.4 GHz デバイスは非公開プロトコルを使用しているためまだ対応していません。追加に協力する方法は [CONTRIBUTING.md](#sec-contributing) をご覧ください。

## 仕組み

[`src/drivers/`](../../src/drivers) 内の各ベンダードライバーは USB のベンダー ID とプロダクト ID によってデバイスを認識し、読み取り専用のバッテリークエリのみを送信します。未知のデバイスに対して書き込みを行うことは決してありません。汎用フォールバック（HID バッテリー Usage、Bluetooth、XInput、HeadsetControl）は、どのベンダードライバーも処理しなかったデバイスのみを対象とします。

タスクバーウィジェットは `Shell_TrayWnd` のレイヤード子ウィンドウとして `TrayNotifyWnd` の左側に配置されます。Explorer が再起動された場合は自動的に再作成されます。

## 翻訳

UI の各言語は [`lang/`](../../lang) 内のプレーンな静的 UTF-8 テキストファイルです（左側が英語、右側が翻訳文）。言語ファイルは実行ファイルへコンパイルされず実行時にディスクから読み込まれるため、再ビルドせずに直接編集できます。

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **アプリ UI（Windows および Linux）:**
  - `lang/` フォルダー（`BatteryHub.exe` の隣、または Linux では `/usr/share/wireless-battery/lang/`、`/usr/local/share/wireless-battery/lang/`、`$XDG_DATA_HOME/wireless-battery/lang/`、もしくは `./lang/`）内の `.json` ファイルを直接編集・追加できます。
  - あるいはメニューから *言語 → 自分の言語を追加...* を選ぶと、`_template.json` 入りのユーザー上書き用フォルダー（Windows は `%APPDATA%\WirelessBattery\lang`、Linux は `~/.config/wireless-battery/lang`）が準備されます。`_template.json` を `it.json` などにコピーし、`@code`、`@name`、翻訳文を記入すればメニューに表示されます（再起動不要）。ユーザーフォルダー内のファイルは同じ `@code` の組み込み文言を上書きします。
  - `{placeholders}` はそのまま残し、右から左に書く文字体系では `"@rtl": true` を追加してください。空欄の文言は英語のまま残るため、部分的な翻訳でも問題なく動作します。
  - `--list` および `--dump` の出力は GitHub Issue に貼り付ける用途のため、意図的に英語のままになっています。
- **Windows インストーラー:** Inno Setup 用の翻訳は [`installer/lang/`](../../installer/lang)（UTF-8 BOM 付きで保存）にあり、`installer/BatteryHub.iss` の `[Languages]` セクションに登録されています。
- **ドキュメント:** すべての公開ドキュメントは [`docs/i18n/`](README.md) 内に言語ごと 1 つのスタンドアロン Markdown ファイルとして翻訳されています（ビルドスクリプト不要で新言語を追加するには [`docs/i18n/_template.md`](_template.md) を参照してください）。
- **みんなと共有:** `lang/`、`installer/lang/`、`linux/wireless-battery.desktop`、および `docs/i18n/` にファイルを追加したプルリクエストを送ってください。手順チェックリストは [`docs/i18n/README.md`](README.md) にあります。

## クレジット

アプリアイコン制作: [nik-txt](https://github.com/nik-txt)（[`res/app.svg`](../../res/app.svg)）。

各プロトコルは以下のプロジェクトによる調査に基づいています:

- [Google Fast Pair 仕様](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): Fast Pair イヤホンの左 / 右 / ケース残量ブロードキャスト
- [HeadsetControl Astro ドライバー](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp)、[eh-fifty](https://github.com/tdryer/eh-fifty)、[AstroBar](https://github.com/nichtlegacy/AstroBar): Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 バッテリープロトコル。[OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): A50 Gen 3 `0x72` ステータス読み取り

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor)（stuffz）: VAXEE のバッテリーおよび充電コマンド（[プロトコルドキュメント](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md)）

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): SteelSeries、Corsair、HyperX、Logitech、Sony INZONE ヘッドセット
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray)（kinako19）および [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray)（takamachi66）: Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) および Logitech HID++ 2.0 文書: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) および [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435（`0ADF` ドングル）
- [rivalcfg](https://github.com/flozz/rivalcfg): SteelSeries マウス（Rival Pro は同リポジトリ PR #294 より）
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) および [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Hitscan Web コンフィギュレーター（[control.hitscan.com](https://control.hitscan.com)）: Hitscan
- Linux `hid-kysona`（Lode Willems）: Kysona、Pulsar、ATK
- ATK Web コンフィギュレーター（[hub.atk.pro](https://hub.atk.pro)）: ATK マウスおよび N9 Pro / N9 Ultra ヘッドセット
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 および [mouse-battery](https://github.com/qwr79/mouse-battery): ATK / VXE NK NANO ドングル
- [HaloBattery](https://github.com/HeyOkay/HaloBattery)（MIT）: Audeze Maxwell、NZXT Lift Elite、Poly BT600、Razer Barracuda Pro、SteelSeries Arctis Nova Elite、ATK V75X、Endgame Gear XM2we（各プロバイダーから移植、各ドライバーに出典記載）
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` および [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700)（PaulRichez、MIT）: Turtle Beach Stealth 700 Gen 3。[Neap](https://github.com/lykosapps/Neap)（調査知見のみ）: Turtle Beach Swarm II デバイスファミリ
- G-Wolves Web ドライバー（[mouse.xyz](https://mouse.xyz)）: G-Wolves モデルとそのプロトコル
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): 2.4 GHz ドングル接続の CHERRY キーボード（フレーム形式とバッテリークエリ）
- Keychron Launcher（[launcher.keychron.com](https://launcher.keychron.com)）: Keychron マウス
- [NinjaForce](https://www.ninjaforce.co/) および [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): Ninjutso Ten / Ten Air Feature クエリ
- [nape_pro](https://github.com/nvalis/nape_pro) および [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Link-KM レシーバー接続の Keychron Nape Pro
- LAMZU Aurora（[lamzu.net](https://www.lamzu.net)）: LAMZU マウス
- [vole](https://github.com/johanneszab/vole) および [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): Endgame Gear 4K マウス
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) および [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) および [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X（Finalmouse xpanel より）
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) および [g49-web-control](https://github.com/pingpingjinping/g49-web-control): Redragon ID
- [m913-ctl](https://github.com/Qehbr/m913-ctl) および [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): Areson `25A7` フレーム構成および `GetPower` コマンド
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG。[pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) および [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW および DW
- RK Web ドライバー（[drive.rkgaming.com](https://drive.rkgaming.com)）: Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver)（MIT）、[HaloBattery](https://github.com/HeyOkay/HaloBattery)（MIT）、[mchose-macos](https://github.com/Klegus/mchose-macos)（MIT）および [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol)（文書）: MCHOSE A5 Pro / A5 Pro Max（第 1 世代、VID `2023`）
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6)、[omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900)、[aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed、Delux、Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): Delux M900 Pro 向け CompX レシーバーレポート
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) および [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager)、[incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) および [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- Wraith Web ドライバー（[w1.software](https://www.w1.software/)）: Wraith W1
- OpenRazer PR #2794 および [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 および [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) および [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): `1532:0550` レシーバー上の Razer Barracuda X (2022)。[razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): `1532:0552` レシーバーのフレーミング
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S、Cloud II Core、Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): Rongyuan および Xenta レシーバー（Attack Shark など）
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): 2.4G ドングル接続の SONiX キーボード（AJAZZ AK820 MAX、AK980 V2、AULA F108 Pro）。[ak820-rs](https://github.com/deddroid/ak820-rs) および [ak820-studio](https://github.com/usharik/ak820-studio): AJAZZ AK820 Pro レシーバー `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) および [Kraber](https://github.com/AkashPanja/Kraber): Attack Shark X98 および AJAZZ AK820 Max Plus 用 Semico `1A2C`（`AA 55 CC 33` / `0x0E`）ステータスプロトコル
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) および [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 および MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) および [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): GameSir Cyclone Pro Bluetooth LE "base info" バッテリーリクエスト
- [jabridge](https://github.com/Watchdog0x/jabridge): Jabra GNP プロトコル（Link 380 / 390 ドングル）
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): `1EA7:0066` ステータスページプロトコル（Fantech Raigor III およびその他の汎用 2.4G Mouse デバイス）
- Linux `hid-playstation`: DualShock 4 / DualSense レポートレイアウト
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): AULA SC580 / SC580X ベンダープロトコル
- RAWM HUB Web アプリ（[rawmtech.com/hub.html](https://www.rawmtech.com/hub.html)、Hub Web 2.0）とそのデバイステーブル: RAWM マウスおよび SADES Dagger
- [SDL の Flydigi HID ドライバー](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) および [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): Vader 5 Pro および Apex 5 のクエリフレーミングとバッテリーレイアウト
- [SDL の 8BitDo HID ドライバー](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): 8BitDo Ultimate 2 バッテリーバイト
- BEITONG iControl（KP20 / KP40D ページおよび KP20 レシーバーの USB トラフィック）: BEITONG KP20 / KP40D のバッテリークエリおよびペイロードスクランブル
- [SDL の 8BitDo HID ドライバー](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) および [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): 8BitDo バッテリーバイトおよびベンダー HID プロトコル
- JBL QuantumENGINE（HIDV3 デバイス情報メッセージ）: JBL Quantum ヘッドセット
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight、`FF02:0002` 上の Compx プロトコル
- [MouseDock](https://github.com/late-autumn-gif/mousedock)（MIT）および [BrimDeck](https://github.com/MoFeng2223/BrimDeck): Scyrox V12M プロファイル読み取り
- JBL QuantumENGINE: Quantum 350 向け HIDV1 接続・バッテリーレポート、および新型 Quantum ヘッドセット向け HIDV3 デバイス情報メッセージ
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): JBL Quantum 610 HIDV1 バッテリー・リンクレポート、および Quantum ラインナップ（HIDV1 ドングルモデルとしての 360）

## ライセンス

[GNU General Public License v3.0 or later](../../LICENSE)。このソフトウェアを使用、改変、再配布できますが、本ソフトウェアに基づいて配布する派生物はすべてソースコードとともに同じライセンスで公開する必要があります。


---

<a id="sec-contributing"></a>
> 📄 **セクション:** コントリビュートガイド（`CONTRIBUTING.md`） · [英語原文](../../CONTRIBUTING.md) · [↑ トップへ](#top)

# コントリビュートガイド

## デバイスが動作するか報告する

ほとんどのドライバーはプロトコル文書に基づいて作成されており、すべてのモデルで実機テストできたわけではありません。
以下の情報を添えて Issue を作成してください:

- デバイス名、およびレシーバー・ケーブル・Bluetooth のいずれで接続しているか
- `BatteryHub.exe --list` の出力
- `BatteryHub.exe --dump` の出力
- メーカー純正ソフトに表示されているバッテリー残量

## デバイスを追加する

1. `BatteryHub.exe --dump` を実行し、デバイスのベンダー ID・プロダクト ID、およびベンダー定義コレクション（Usage Page `FFxx`）とそのレポートサイズを確認します。
2. バッテリープロトコルを調査します。参考になる調査先: HeadsetControl、OpenRazer、Solaar、rivalcfg、OpenRGB、OpenLinkHub、またはメーカー純正ソフトの USB キャプチャ（Wireshark + USBPcap）。
3. `src/drivers/` にそのベンダーのドライバーがすでにある場合は、プロダクト ID（および差異）をそこへ追加します。
   新規の場合は `src/drivers/<vendor>.cpp` を作成します:

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

4. `src/drivers/drivers.h` に関数を宣言し、`src/devices.cpp` の `PollAllDevices()` から呼び出します（汎用フォールバックより前に配置）。`build.bat` と Makefile は新しいファイルを自動的に認識します。
5. `README.md` の対応デバイステーブルを更新します。

### ドライバー実装のルール

- **読み取り専用:** 状態を読み取るリクエストのみを送信してください。設定・ライティング・モードを一切変更してはなりません。
- **厳密な一致判定:** ベンダー ID とプロダクト ID で認識できるデバイス、またはそのプロトコル固有のベンダーコレクションを持つデバイスのみにアクセスしてください。
- **必ずタイムアウトを設定:** 応答しないデバイスによってポーリングが約 1 秒以上止まらないようにしてください。パッシブプロトコルでは仕様上の送信間隔をカバーするため長めの待機が必要な場合があります（例: Delux や Rapoo）。その場合でも、一致するコレクションあたり最大 4 秒の単一の絶対期限を守り、無関係なレポートで期限を延長しないでください。例外が必要な理由はドキュメントに明記してください。
- **出典の明記:** プロトコルの出典をファイル先頭のコメントに記載してください。

## 翻訳

UI 言語は `lang/` にあるプレーンな静的 UTF-8 テキストファイルで、Windows 版・Linux 版ともに実行時にディスクから読み込まれます（`lang/_template.json` を `lang/<code>.json` にコピーし、`@code`、`@name`、文言を記入するだけで、再ビルドは不要です）。コード内の新しい UI テキストは `T(L"...")`、または値を含む場合は `TF(L"... {name} ...", { { L"name", value } })` を通してください。パーツを連結して翻訳文を組み立ててはいけません。文言を追加したら、`lang/_template.json` にも追加してください。

Windows インストーラーの翻訳は `installer/lang/*.isl`（UTF-8 BOM 付きで保存し `installer/BatteryHub.iss` に登録）、Linux ランチャーのコメントは `linux/wireless-battery.desktop`、完全なドキュメント翻訳は `docs/i18n/<code>.md`（`docs/i18n/_template.md` からコピーした単一スタンドアロンファイル）にあります。コントリビューター向けの完全ガイドは [`docs/i18n/README.md`](README.md) をご覧ください。

## コードスタイル

C++17、Win32 のみ、サードパーティ依存なし。バイナリは小さく保ってください。既存のコードとおおよそ同じ書式（インデント 4 スペース、1 行 120 桁）で記述してください。

## Windows アップデーターの開発

アップデーターは Windows 専用で、WinHTTP、BCrypt、および既存の Inno Setup インストーラーを使用します。
アップデートの状態表示はメニュー内のみに留めてください。アップデートアイコン、バッジ、バッテリーツールチップの変更、バルーン通知、トースト通知、自動ダイアログを追加してはいけません。デバイスのポーリングはネットワーク処理とは別スレッドで実行されます。

ビルドバージョンとチャネルは生成される `build/version.h` を通じて C++ と Windows リソースで共有されます。ローカルテストには `make VERSION=1.2.3 CHANNEL=test` または `build.bat 1.2.3 test` を使用してください。既定値は `dev` で、`stable` が公式リリース確認を有効にします。バージョンの各要素は 0..65535 の範囲内である必要があります。公式リポジトリのリリースタグワークフローのみが自動的に `stable` を選択します。フォークビルドを誤って公式アップデートチャネルにしないでください。

`make test VERSION=1.2.3 CHANNEL=test` を実行すると、既存のデバイステストに加えて、厳密なリリース解析、バージョン比較、チェックのスケジュール、実際の SHA-256 ファイル検証、引数クォート、ヘルパーガードのテストが走ります。アップデーターの回帰テストでは、ダウンロード完了時のキャンセル、ダイアログガード、HTTP タイムアウト/リダイレクト制限の構成失敗も検証します。Windows テストは既存の Linux バックエンドテストのパターンに従って実装を取り込み、HTTP 送信を差し替えているためテストが GitHub に接続することはありません。本番コードにテスト専用の制御エントリーポイントは追加されません。個別のターゲットとして `make test-update-core` と `make test-update-win` があります。ネイティブアップデーターテストは Common Controls v6 を有効にするためアプリケーションリソースをリンクします。テストはローカルデータを使用し、ダウンロード・権限昇格・インストール・ユーザーの自動起動設定の変更を行いません。テスト用にアプリの本番エンドポイントを上書きすることはできません。

パッケージ化の前に、`powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3` を実行してください。`installer/build-installer.ps1 -Version 1.2.3` も依存ファイルをダウンロードする前にこのチェックを実行します。`/WBUPDATE=1` インストーラーパスは既存の自動起動および設定を保持し、再起動を一時ヘルパーに委ねます。そのヘルパーは元のユーザー権限のまま動作し、グローバルインストールの場合のみ昇格を行います。WinHTTP ハンドルはワーカーに属し、キャンセルは有限タイムアウト呼び出しの間で協調的に処理されます。アプリ終了処理ではそのワーカーを join するため、進行中のネットワークタイムアウト完了まで待機することがあります。

リリースレビューの際は、使い捨ての Windows アカウントまたは仮想マシンを使い、実際のインストーラー 2 バージョン、ユーザー単位/全体スコープ、UAC キャンセル、自動起動のオン/オフ、カスタムパス、セットアップ失敗、再起動を実機で確認してください。単体テストやパッケージのコンパイルだけではこれらのインストーラー動作は検証されません。メニュー/テーマの目視確認および実際のインストーラー/UAC エンドツーエンド確認は引き続き手動リリースゲートであり、実際に確認するまで合格扱いにしてはいけません。普段使いのユーザーのインストール環境を上書きしてテストしないでください。

## 自動安全性チェック

すべてのプルリクエストは「PR safety check」によってスキャンされ、このアプリが決して行うべきでない動作（ネットワークアクセス、他プログラムの起動、キーボード/クリップボード/画面の読み取り、スタートアップ登録、バイナリ、ビルドまたはリリース関連の変更）がないか確認されます。フラグが付いても即座に却下されるわけではなく、PR の説明欄でその該当行の理由を説明すれば問題ありません。

AI ツールを使うこと自体は問題ありませんが、AI をクレジットする `Co-authored-by` 行（例: `Co-authored-by: Claude ...`）はコミットメッセージから削除してください。含まれている間はチェックが失敗します。


---

<a id="sec-pr-template"></a>
> 📄 **セクション:** プルリクエストテンプレート（`.github/pull_request_template.md`） · [英語原文](../../.github/pull_request_template.md) · [↑ トップへ](#top)

## 追加内容

<!-- デバイス名とベンダー/プロダクト ID（例: "Acme M1 (1234:5678)"）。 -->

## プロトコルの出典

<!-- 参照元のリンク（他プロジェクト、メーカー Web ドライバー、自身の USB キャプチャなど）。 -->

## 実機テスト済みか？

<!-- はい（どのデバイスか、--list の出力内容） / いいえ -->

## チェックリスト

- [ ] 読み取り専用のバッテリークエリのみを送信しており、設定・ライティング・ファームウェアは一切変更しない
- [ ] ベンダー/プロダクト ID（またはプロトコル固有コレクション）で識別したデバイスのみにアクセスしている
- [ ] ネットワークアクセス、他プログラムの起動、`src/`、`docs/`、`README.md` 以外への新規ファイル追加を行っていない
- [ ] バイナリファイルや生成ファイルが含まれていない
- [ ] コミットメッセージに AI ツール（Claude、Copilot、ChatGPT など）を示す `Co-authored-by` 行が含まれていない
- [ ] `.github/`、`installer/`、`build.bat`、`Makefile` への変更がある場合は上記で説明している


---

<a id="sec-releasing"></a>
> 📄 **セクション:** リリースおよび署名（`docs/releasing.md`） · [英語原文](../../docs/releasing.md) · [↑ トップへ](#top)

# リリース手順

アプリは GitHub リリースから自動アップデートを行いますが、リリース鍵で署名された `SHA256SUMS.txt` に SHA-256 が記載されているインストーラーのみをインストールします。その鍵は GitHub 上ではなくメンテナーの PC 上にのみ保管されるため、アカウント・トークン・ワークフローが侵害されてファイルを公開できたとしても、アプリが受け入れる署名は生成できません。

## 初回のみ: リリース鍵の作成

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- パスワード（12 文字以上）の入力を求められ、暗号化された秘密鍵を `%USERPROFILE%\.wirelessbattery\release-key.wbk` に書き込みます。
- 公開鍵を `src\update_public_key.h` に書き出します。このファイルをコミットしてください。公開鍵が入っていない場合、公式ビルドはコンパイルを拒否します。
- **鍵ファイルとパスワードを必ずバックアップしてください**（両方ともパスワードマネージャーへの保管が適しています）。どちらかを失うとインストール済みアプリが自動アップデートできなくなり、新しい鍵を作り直して全ユーザーが 1 度手動でリリースをインストールし直す必要が生じます。

## リリースごとの手順

1. バージョンタグをプッシュします（`git tag v1.2.3 && git push origin v1.2.3`）。CI がインストーラー、ポータブル ZIP、および `SHA256SUMS.txt` をビルドしてリリースを公開します。
2. チェックサム一覧に署名します:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   リリースから `SHA256SUMS.txt` をダウンロードして表示し、確認と鍵パスワードの入力を求めたあと `SHA256SUMS.txt.sig` を書き出します。`dist\` に同じファイル（同バージョンのローカルビルド）がある場合は一致するかどうかを表示します。
3. `SHA256SUMS.txt.sig` をリリースにアップロードします（スクリプトが編集ページを開きます）。この時点からアプリは **ダウンロードしてインストール** を提示するようになります。それまではアップデートがあることを表示しつつリリースページへのリンクのみを提供します。

必ず自分で公開したリリースのチェックサム一覧にのみ署名してください。署名は「まさにこれらのファイルが公式リリースである」ことを保証するものであり、悪意あるアップロードを阻止する最後の砦となります。

## 鍵の変更

新しい `-KeyFile` を指定して `new-release-key.ps1` を実行すると、`src\update_public_key.h` 内の古い鍵の隣に新しい公開鍵が追加されます。両方の鍵を含んだバージョンを古い鍵で署名してリリースし、次のリリースから新しい鍵で署名したうえで、後日古い鍵を削除してください。紛失または漏洩した鍵はこの方法では失効できません。ヘッダーからその鍵を削除すると、旧バージョンのユーザーは次のリリースを手動でインストールする必要があります。

## セットアップ実行前にアプリが検証する項目

- そのリリースがリポジトリの最新リリースであり、ドラフトやプレリリースではなく、現在のアプリより新しいこと。
- `SHA256SUMS.txt.sig` が、`src\update_public_key.h` に含まれるいずれかの鍵による `SHA256SUMS.txt` の有効な ECDSA P-256 署名であること（Windows BCrypt 使用、サードパーティコードなし）。
- 署名済み一覧に `BatteryHub-Setup-<version>.exe` がちょうど 1 回だけ記載されており、GitHub がそのファイルに対して報告する SHA-256 と一致すること。
- ダウンロードしたセットアップがそのサイズと SHA-256 に完全に一致すること。起動直前にアプリの別コピーが再度検証し、その間に差し替えられないようファイルをロックしたまま実行します。
- ダウンロードは `github.com`、`objects.githubusercontent.com`、および `release-assets.githubusercontent.com` への HTTPS のみを使用し、すべてのリダイレクト先も検証されます。


---

<a id="sec-keychron-firmware"></a>
> 📄 **セクション:** Keychron キーボードファームウェア（`docs/keychron_keyboard_firmware/README.md`） · [英語原文](../../docs/keychron_keyboard_firmware/README.md) · [↑ トップへ](#top)

# Keychron キーボードの 2.4 GHz レシーバー経由バッテリー取得

Keychron の純正ファームウェアは Bluetooth 経由でのみキーボードのバッテリー残量を報告します。[`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch) にある小さな QMK の変更を適用すると、Keychron Link レシーバーおよび USB ケーブル経由でもバッテリークエリ（`A4`）に応答するようになり、BatteryHub で残量・電圧・充電状態を表示できるようになります。

**Keychron K5 Max ANSI RGB**（`3434:0A50`）と Keychron Link レシーバー（`3434:D030`）の組み合わせで実機検証済みです。

## パッチの変更内容

[Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) の `2025q3` ブランチ（コミット `57e682c`）をベースにしています:

- [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1) の `KC_GET_BATTERY`（`0xA4`）raw HID コマンドを追加:
  応答フォーマット `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`
- ワイヤレスリンク経由で届いた raw HID リクエストも同じハンドラーへ渡すように変更
- `keyboards/keychron/k5_max/config.h` に `#define WILRESS_RAW_ENABLE`（Keychron のコード上のスペルのまま）および `#define KC_BATTERY_MODEL_ID 0` を追加

それ以外の動作（キーマップ、ライティング、Keychron Launcher など）は一切変わらずそのまま動作します。

## 方法 1: ビルド済み K5 Max ファームウェアを書き込む

**K5 Max ANSI RGB 専用**のビルド済みバイナリが[このリリース](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)に添付されています（`k5_max_ansi_rgb_battery.bin`、SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`）。他のモデルや配列には絶対に書き込まないでください。

## 方法 2: 自分でビルドする

Git と Docker（または動作する [QMK 環境](https://docs.qmk.fm/newbs_getting_started)）が必要です。

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

リポジトリルートに `keychron_k5_max_ansi_rgb_keychron.bin` が生成されます。Windows 環境ではバインドマウントしたチェックアウトに対する Docker 処理が非常に遅いため、コンテナ内（または WSL 内）でクローンする方がはるかに高速です。

**その他の Keychron ワイヤレスキーボード**（`2025q3` ツリー上で `LK_WIRELESS_ENABLE` を持つ Q/V/K Max などのモデル）:
`keyboards/keychron/common/` 配下の変更はそのまま適用できます。K5 Max の代わりに自分のキーボードの `config.h` に 2 行の `#define` を追加し、自身のターゲットをビルドしてください（例: `make keychron/<model>/<layout>/<variant>:keychron`）。アプリは現在 K5 Max（`0A50`–`0A58`）をモデル名で表示し、それ以外は「Keychron keyboard」として表示します。

## 書き込み手順

1. モードスイッチを **Cable** に合わせ、USB ケーブルを抜きます。
2. **Esc** キーを押したまま USB ケーブルを差し込みます。キーボードが STM32 ブートローダーモードに入ります。
3. [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)（または `dfu-util`）を使って `.bin` ファイルを書き込みます。
4. **2.4 GHz** モードに戻し、`BatteryHub.exe --list` で確認します:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`。

Keychron Launcher からキーボードのファームウェアを更新するとこのファームウェアが上書きされ、バッテリー報告機能は失われます。元に戻したい場合も、同じ手順で Keychron 公式ファームウェアを書き込んでください。

## ライセンス

QMK は GPL-2.0-or-later であり、このパッチも同じライセンスの下にあります。本パッチを用いてビルドしたバイナリを受け取るすべての人が、このソース変更も入手できるようにする必要があります。


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **セクション:** GameSir Cyclone Pro（`docs/gamesir_cyclone_pro.md`） · [英語原文](../../docs/gamesir_cyclone_pro.md) · [↑ トップへ](#top)

# GameSir Cyclone Pro バッテリーサポート

## なぜ満充電の Xbox コントローラーとして表示されていたのか

Cyclone Pro（モデル T4cp）は 2.4 GHz ドングル `3537:1015` 経由で動作します。このドングルは Windows に対して有線の Xbox 360 コントローラー（XUSB、`Xbox 360 Controller for Windows`）として認識されます。XInput はバッテリー問い合わせに対して常に "Full" と応答するため、XInput フォールバックでは実際の残量にかかわらず `Xbox controller 1` が 100% として表示されていました。

ドングル自体にはバッテリー情報が一切含まれていません:
- 公開されている唯一の HID コレクションが XInput ゲームコントローラー（`HID\VID_3537&PID_1015&IG_00`）である
- Nova（`FF7A`）や Cyclone 2（`FFF0`）のようなベンダー定義コレクションを持たない

## 残量データの取得元

ドングル経由でプレイしている間も、コントローラー本体は Bluetooth LE で `GameSir-Cyclone Pro` としてアドバタイズを行っています（これは GameSir のスマートフォンアプリが使う接続です）。その「get base info」リクエストでバッテリー残量が返ってきます:

| 項目 | 詳細 |
|---|---|
| Service | `0x8650`（`00008650-0000-1000-8000-00805f9b34fb`） |
| Characteristic | `0x865F`（notify、write without response） |
| Request | 通知を有効化し、`01 01` を書き込む |
| Reply | 19 バイトの通知（一部ファームウェアでは先頭に `C9` が付く 20 バイト） |

応答レイアウト:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

バイト 18 がパーセント単位のバッテリー残量（0〜100）、充電中は `FF` となります。充電中は残量数値が報告されないため、最後に確認したパーセントを保持して充電ボルト付きで表示します。

コントローラーには GameSir のファームウェア更新チャネルであるサービス `0xFF10` もありますが、ドライバーがこれを開くことはありません。標準の Battery Service（`0x180F`）を持たないため、Windows の Bluetooth 設定画面や Bluetooth フォールバックでは残量が表示されません。

出典: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery)（GameSir の Android アプリ `BluetoothLeService` の「get base info」からプロトコルを解析）。

## ドライバーの仕組み

XInput フォールバックより前に `src/drivers/gamesir_ble.cpp` が呼び出されます:

1. **コントローラーの検索:** クラス `{00008650-0000-1000-8000-00805F9B34FB}` のデバイスインターフェースを検索します。Windows はペアリング済み BLE デバイスの GATT サービスごとにインターフェースを作成します。そのうち親の `BTHLE\DEV_…` ノード名が `GameSir-Cyclone…` のものだけを対象とします。
2. **バッテリーの読み取り:** Win32 GATT API（`bluetoothleapis.h`、`-lbluetoothapis`）で該当サービスを開き、`0x865F` を購読して `01 01` を書き込みます。応答を最大 3 秒待ったあと、通知を再びオフに戻します。
3. **ポーリングを高速に保つ:** BLE 接続は数秒かかったり、コントローラーがスリープ中はタイムアウトしたりするため、クエリは専用スレッド上で実行されます:
   - 正常読み取り後は最短 2 分間隔、失敗後は 1 分間隔で実行
   - ポーリングはキャッシュされた値を返し、6 分以上経過すると返却を停止
   - その後 `graceSec` によりスリープ中として薄く表示され続ける
   - 起動直後や `--list` で残量が表示されるよう、実行中の最初のポーリングのみ 1 度だけ絶対期限 4 秒でスレッドを待機
4. **偽の Xbox エントリーを非表示にする:** ドングルが存在するとき、ドライバーは `3537:1015` を専有（claim）します:
   - Windows.Gaming.Input 経路は専有済みのベンダー/プロダクト ID をスキップするようになりました
   - XInput 経路は `XInputGetCapabilitiesEx`（xinput1_4 ordinal 108）から各スロットのベンダー/プロダクト ID を取得し、専有済みのものをスキップします
   - そのエクスポート関数がない場合は従来どおりの XInput 動作になります

## 実機検証環境

Windows 11、ドングル接続の Cyclone Pro（`3537:1015`）、Bluetooth で 1 度ペアリング済み、2026-11-18 に確認:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

コントローラーがスリープ状態のときは「Xbox controller 1 / Full」の項目が出なくなり、コントローラーに関して何も表示されなくなりました。

## 制限事項

- **ペアリング:** コントローラーを 1 度 Windows とペアリングする必要があります（設定 > Bluetooth とデバイス > デバイスの追加 > Bluetooth > `GameSir-Cyclone Pro`）。未ペアリングでは GATT デバイスインターフェースが存在しません。ペアリングすると Bluetooth ゲームパッドのエントリーが追加されますが、ドングル経由でプレイしている間そちらから入力が送られることはありません。
- **Bluetooth 必須:** PC に Bluetooth LE が必要です。
- **1 台のみ:** PC 1 台につき 1 台の Cyclone Pro のみ読み取ります。
- **充電中:** 充電中はパーセント値が取得できません。


---

<a id="sec-localization-guide"></a>
> 📄 **セクション:** 多言語利用・ローカライズガイド（`docs/i18n/README.md`） · [英語原文](../../docs/i18n/README.md) · [↑ トップへ](#top)

# BatteryHub 多言語インデックスおよびローカライズガイド

このリポジトリのすべての公開ドキュメントは `docs/i18n/` 内の**言語ごとに 1 つのスタンドアロン Markdown ファイル**にまとめられており、アプリケーション実行時の全文字列は [`lang/`](../../lang) 内の**編集可能な静的テキストファイル**（Windows と Linux で共有）、Windows インストーラーの文字列は [`installer/lang/`](../../installer/lang) に配置されています。

## 対応言語（19 言語）

| コード | 言語 | 完全ドキュメント | アプリ UI（Windows & Linux） | Windows インストーラー |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json)（原文テンプレート） | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## 実際の言語切り替えの仕組み

### 1. Windows アプリ（`BatteryHub.exe`）
- **自動検出:** *言語 → 自動（Windows の言語）* に設定されている場合、BatteryHub は Windows の `GetUserPreferredUILanguages` を問い合わせて最も近い静的 `*.json` ファイルを選択します。
- **手動切り替え:** タスクバーウィジェットまたはトレイアイコンをクリック → **言語** → 言語を選択します。UI は即座に更新され、`HKCU\Software\WirelessBattery\Language` に保存されます。
- **静的外部ファイル（再ビルド不要で編集可能）:** `BatteryHub.exe` は最初に `<exe>\lang\*.json`、次に `%APPDATA%\WirelessBattery\lang\*.json` を読み込みます。ユーザーフォルダー側に同じ `@code` のファイルがあると該当文言が上書きされ、メニューを開き直すたびにディスクからリアルタイムに再読み込みされます。
- **CLI `--help`:** `BatteryHub.exe --help` は現在有効な UI 言語でヘルプダイアログを表示します（`--list`、`--json`、`--dump` は GitHub Issue 報告用のため意図的に英語のままです）。

### 2. Linux アプリ（`wireless-battery`）
- **自動検出:** `LANGUAGE`（コロン区切りリスト）→ `LC_ALL` → `LC_MESSAGES` → `LANG` の順で POSIX ロケール変数を参照します（`LC_ALL=C` / `POSIX` で上書きされている場合を除く）。
- **手動切り替え:** トレイアイコンを右クリック → **言語** → **自動（システムの言語）** またはインストール済みの言語を選びます。`$XDG_CONFIG_HOME/wireless-battery/config.ini`（既定 `~/.config/wireless-battery/config.ini`）の `[general] language=` に保存されます。
- **静的検索パス（優先度の低い順）:**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/`（既定 `~/.local/share/wireless-battery/lang/`）
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/`（既定 `~/.config/wireless-battery/lang/`）
- **CLI `--help`:** `wireless-battery --help` は `config.ini` またはシステムロケールに基づいて翻訳された CLI ヘルプを出力します。`--list` と `--dump` は英語のままです。

### 3. Windows インストーラー（`BatteryHub-Setup-<version>.exe`）
- Windows UI 言語から事前選択された言語セレクター（`ShowLanguageDialog=yes`、`LanguageDetectionMethod=uilanguage`）を表示します。
- 静的な `lang\*.json` ディレクトリ全体を `BatteryHub.exe` と同じ `{app}\lang\` にインストールします（ポータブル ZIP も同様に `lang\*.json` を同梱しています）。

---

## 言語の追加・更新方法（ステップバイステップ）

アプリ UI やドキュメントの翻訳にビルドツールは**一切不要**です。Windows インストーラーをテストコンパイルしたい場合にのみ Inno Setup 6 が必要になります。

### ステップ 1 — アプリ UI 文字列（`lang/<code>.json`）
1. トレイメニュー（**言語 → 自分の言語を追加...**）からユーザー言語フォルダーを開くか、[`lang/_template.json`](../../lang/_template.json) を `lang/<code>.json`（例: `lang/it.json`）にコピーします。
2. メタデータヘッダーを記入します:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. 各行の ` = ` より右側を翻訳します。
   - `{name}`、`{percent}`、`{version}`、`{days}`、`{hours}`、`{rate}`、`{count}`、`{monitor}`、`{number}`、`{seconds}`、`{minutes}`、`{page}`、`{reason}`、`{code}` などのプレースホルダーはそのまま維持してください。
   - 明示的な改行には `\n` を使います。
   - **UTF-8（BOM なし）** で保存してください。
   - BatteryHub のトレイメニューを開き直すだけで即座にプレビューできます（再ビルド不要）。

### ステップ 2 — Windows インストーラー（`installer/lang/<code>.isl`）
1. [`installer/lang/_template.isl`](../../installer/lang/_template.isl) を `installer/lang/<code>.isl` にコピーします。
2. **重要:** 従来の Windows コードページに左右されず Inno Setup が Unicode 文字を正しくデコードできるよう、必ず **UTF-8 BOM 付き（`EF BB BF`）** で保存してください。
3. 該当するパターンを選択します:
   - **Inno Setup にその言語がすでに同梱されている場合**（`C:\Program Files (x86)\Inno Setup 6\Languages\` を確認）: `[CustomMessages]` のみを残し、6 行（`AutostartTask`、`LaunchApp`、`SupportProject`、`CloseFailed`、`DirNotWritableAdmin`、`DirNotWritableUser`。`%1` と `%n` は保持）を翻訳します。`installer/BatteryHub.iss` の `[Languages]` に登録します:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup にその言語が同梱されていない場合**: `installer/lang/zh-CN.isl` を完全な見本としてコピーし、`[LangOptions]`（`LanguageName`、`LanguageID`、`LanguageCodePage=0`、必要に応じて `RightToLeft=yes`）を設定して `[Messages]` と `[CustomMessages]` を翻訳し、`Default.isl` の後ろに登録します:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - 注意: `[Languages]` の `Name:` 識別子には ASCII 英字・数字・アンダースコアのみ使用できます（`pt-BR` ではなく `ptBR` にしてください）。

### ステップ 3 — Linux デスクトップランチャー（`linux/wireless-battery.desktop`）
ローカライズされた `Comment[<code>]=...` 行を追加します（`.desktop` ファイル内の地域タグにはアンダースコアを使用してください。例: `Comment[zh_CN]=...`）。

### ステップ 4 — 完全な単一ファイルドキュメント（`docs/i18n/<code>.md`）
1. [`docs/i18n/_template.md`](_template.md) を `docs/i18n/<code>.md` にコピーします（ジェネレータースクリプトは不要で、この 1 ファイルだけです）。
2. 目次と全 17 セクションを省略せずに翻訳しつつ、以下をそのまま維持してください:
   - すべての `<a id="sec-..."></a>` アンカータグおよび `<a id="top"></a>`
   - すべてのコードブロック、CLI フラグ（`--list`、`--json`、`--dump`、`--report`、`--demo`、`--quit`、`--help`）、USB `VID:PID`、HID Usage Page、16 進フレーム、レジストリキー、ファイルパス、URL
   - 相対画像・ファイルパス（`../screenshot.png`、`../keychron_keyboard_firmware/k5_max_battery.patch`、`../../LICENSE` など）
3. `docs/i18n/<code>.md` の先頭にある `<!-- lang-switcher:start -->` バーを更新し（自分の言語を太字にし、他のすべてにリンクを貼る）、`README.md`、`CONTRIBUTING.md`、`docs/*.md`、`docs/keychron_keyboard_firmware/README.md`、`docs/i18n/README.md`、および他の `docs/i18n/*.md` ファイルの言語スイッチャーバーにも自言語のリンクを追加します。
4. 右から左へ記述する言語（`ar`、`fa`、`he`）では、テーブルやコードブロックが崩れないようファイル全体を `<div dir="rtl">` で囲まず、標準的な Markdown のまま記述してください。


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **セクション:** ARDOR GAMING Fury V2（`docs/ardor_fury_v2.md`） · [英語原文](../../docs/ardor_fury_v2.md) · [↑ トップへ](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

この 2.4 GHz レシーバーは HID Usage Page `000A`、Usage `0000`、および 5 バイトの Input Report を公開しています。データをブロードキャストする方式であり、HID コマンドは送信しません。

実機から観測されたレポート:

| レポート | バッテリー残量 |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

バイト 3 の上位ニブルが段階（25%、50%、75%、100% に対して `1`、`3`、`7`、`F`）をエンコードしています。25% と 100% のレポートはメーカーアプリのデコードロジックから推測したもので、その後のエンドユーザーによるビルド済みアプリの確認で残りの段階も正しく表示されることが確認されました。5 バイト目は固定値ではないため識別子としては使用しません。

リスナーは、全体が一致する 2 つのレポートではなく、デコードされたバッテリー段階が一致する 2 回の通知を必要とします。最後に確定した値は最大 45 秒間保持されます。グローバルの自動更新間隔は 15 秒に変更されます。

ARDOR Fury V2 と Logitech G733 を使用した Windows 上のエンドユーザー検証内容: 50% および 75% のキャプチャ、定期自動更新、25%/100% の目視確認、およびポータブル版起動。25% と 100% 自体のパケットレポートは未キャプチャです。


---

<a id="sec-areson"></a>
> 📄 **セクション:** Areson `25A7`（`docs/areson.md`） · [英語原文](../../docs/areson.md) · [↑ トップへ](#top)

# Areson 25A7 レシーバー バッテリーサポート

## 従来のプログラムでマウスが検出されなかった理由

Redragon M915RGB-WL は Areson/CompX `25A7:FA07`「2.4G Wireless Receiver」経由で接続します。
独自の 2.4 GHz リンクを使用しているため、バッテリーは標準の HID *Battery Strength* Usage として公開されておらず、Windows 側の Bluetooth バッテリープロパティも持ちません。代わりにこのマウスは能動的な `GetPower` リクエストに応答するため、汎用 HID フォールバックでも Bluetooth フォールバックでも検出できませんでした。当該ベンダー用ドライバーが存在しなかったため、レシーバーは未処理のまま無視されていました。

## 実機確認したハードウェアとパケット

2026-11-17 に Windows 11 上で Redragon M915RGB-WL を用いてテスト:

| 方向 | VID:PID | インターフェース | Usage Page:Usage | レポートサイズ |
|---|---|---|---|---|
| リクエスト（Feature） | `25A7:FA07` | 1 | `FF02:0002` | 17 バイト |
| 応答（Input） | `25A7:FA07` | 1 | `FF01:0000` | 17 バイト |

応答は、リクエストを書き込むトップレベルコレクションとは別のコレクションへ届きます。
Windows 上ではそれぞれ `MI_01&COL07`（Feature）と `MI_01&COL05`（Input）になるため、ドライバーは両方のハンドルを開きます。

キャプチャしたリクエスト（`GetPower`、レポート ID `08`、コマンド `04`、フレーム合計が `0x55` になるチェックサム付き）:

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

キャプチャした応答:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

以下のオフセットはレポート ID をバイト 0 として数えています:

| バイト位置 | 意味 | 例 |
|---|---|---|
| 0 | 応答レポート ID | `09` |
| 1 | コマンドエコー | `04` |
| 2 | ステータス（0 = OK） | `00` |
| 3–4 | アドレス（`GetPower` では未使用） | `00 00` |
| 5 | データ長（2） | `02` |
| 6 | バッテリー残量（0〜10、10% 刻み） | `08` = 80% |
| 7 | 充電フラグ（0 以外の任意の値） | `00` = 非充電中 |
| 16 | チェックサム（全 17 バイトの合計が mod 256 で `0x55`） | `3E` |

同じフレームの時点でメーカー純正ソフトが 80% を表示していたことから、×10 スケールであることが確定しました。同時に `GetConnectStatus`（`08 03 …`）も 1 バイトペイロードで応答し、マウスがリンク済みであることを報告しました。

## その他の Areson マウス

Redragon M693 などで使われる旧型の `FA7B` / `FA7C` レシーバーは、同じ応答オフセットに残量をそのままパーセント整数で返します。このドライバーの ×10 スケールを適用すると 800% と表示されてしまうため、それらのプロダクト ID は意図的に対象外としています。`FA07` と `FA08` のみを処理しており、`FA08` は同ファミリの別 ID ですが本環境では実機検証されていません。

## ポーリングと識別子

- ドライバーは読み取り専用の `GetPower` リクエストのみを送信します。設定、ライティング、DPI データは一切書き込みません。
- 更新のたびに Feature コレクションをアクセス権ゼロで、Input コレクションを読み取り用に開き、リクエストを送信して最大 1.8 秒待機します。古いレポートを応答と誤認しないよう、間にキューのフラッシュを挟んで 2 回試行します。
- 読み取り失敗時は何も登録しないため、スリープ中のマウスは UI 上に最後の値を保持します。他のパッシブドライバーに合わせ、猶予期間は 30 分です。
- デバイスキーはベンダー ID とプロダクト ID から生成されるため（`areson:25A7:FA07`）、受信/スリープサイクルやレシーバーの挿し直しを跨いでも維持されます。

## 検証結果

MSVC C++17 と Windows SDK でアプリケーション全体をビルドし、実際のマウスに対して実行しました。`BatteryHub.exe --list` の結果は以下のとおりです:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

表示された値は同じ時刻の Redragon 公式ソフトのパーセント表示と一致しました。MinGW 用の `build.bat` には新しいソースファイルが含まれており、`Makefile` はワイルドカードで自動検出します。

## プロトコル出典

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): Redragon ソフトの USB キャプチャから解析された 17 バイトフレーム、Feature/Input 分離、および `0x55` チェックサム規則。
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): `25A7:FA07` での `GetPower` コマンドと 10% 刻みスケール。
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md): 応答レイアウトおよび `FA7B` / `FA7C` ファミリでの異なるパーセントスケール。


---

<a id="sec-darkrim"></a>
> 📄 **セクション:** DARKRIM SHADOW（`docs/darkrim.md`） · [英語原文](../../docs/darkrim.md) · [↑ トップへ](#top)

# DARKRIM SHADOW / 寸渊影弑 レシーバー

実機テスト済み: `3654:6901`、製造元 `Jieli Technology`、リリース `0100`。
インターフェース **3**、Usage `FF02:0002`、レポート ID なしの 64 バイト入出力ペイロード（Windows HID レポートサイズは 65 バイト）を使用します。インターフェース 4 にも `FF02:0002` がありますが、レポート ID 2 を使用しこのプロトコルには応答しないため、意図的に除外しています。

プロトコル出典: 公式の [PC Hub ダウンロード](https://app.darkrim.net/hub/zh.html) から入手した `DARKRIM-0.1.26-x64-setup.rar`（メーカーソフトをインストール・起動せずに静的展開）。展開された `DARKRIM.exe` の SHA-256:
`f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`。

同バイナリ内の有用なアドレス:

- `140124C80`: `sendGetBasicInfo(infoType)` がコマンド `0010`、Request `01`、ペイロード `[infoType, 00]` を送信。バッテリーセレクタは `01`。
- `140118D30`、`140119200`: フレームヘッダーおよび CRC 生成。
- `140126DB0`: デバイス情報 TLV パーサー。TLV `01` がバッテリー。
- `1400F5660`、`1400FA700`: バッテリー値参照箇所。下位 7 ビットがパーセント値、最上位ビットが充電中フラグ。同じバッテリー値は `0011` Notify `03` でも届く。

ヘッダー: `FE seq cmdLE type index count lengthLE` の後ろにペイロードおよび CRC-16/CCITT-FALSE（多項式 `1021`、初期値 `FFFF`、ビッグエンディアン格納）が続きます。シーケンスは非ゼロの 4 ビットカウンタで、暗号化は使用されません。

HID ゼロパディング前の実際のリクエスト / 応答ペイロード:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

応答 TLV `01 01 28` は **40%、非充電中** を意味します。製品版 C++ ドライバーはメーカーソフトなしで 3 回連続のクエリで同じ値を返しました。
レシーバーは一致する応答の前に起動時通知を送出します（実測約 406 ms）。応答期限は単一の 800 ms（加えて書き込みに最大 200 ms）を使用し、無関係な通知を受け取っても期限を延長しません。ハートビートは不要です。

ドライバーはバッテリー GET のみを送信します。受け入れるのは、一致するシーケンス/コマンド/タイプ、インデックス 0、カウント 0 または 1（実機では 0 を使用）、有効な長さ・CRC、および整形式の単一バッテリー TLV を持つ非暗号化応答のみです。断片化応答、自発的通知、不正形式、および範囲外の応答は無視されます。

## 観測されたバッテリー精度と充電状態

このパーセント値は**1% 解像度が検証された精密なゲージではなく、概算値**として扱ってください。
所有者の個体では充電の進行が 40% から 90% まで 10 ポイント刻みで変化しました。90% の時点で 5 回のバッテリー GET 応答と 1 回の自発的通知がすべて `DA`（`DA & 7F = 90`、bit 7 が充電中を示す）を返しました。所有者が充電ケーブルを抜いて 2.4 GHz レシーバーでの使用を続けたところ、別の 5 回の GET 応答と 1 回の通知がすべて `5A`（同じく 90% だが充電ビットがクリア）になりました。12 フレームすべてが CRC 検証を通過しました。

代表的なクエリ応答（シーケンス 4）:

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

ドライバーも公式アプリも下位 7 ビットからパーセント値をそのまま取り出しています。ドライバー側で 10 の位に丸めたり、段階値に 10 を掛けたり、中間値を補間したりすることはなく、合成した 47% と 95% のレポートは製品版パーサーでも 47% と 95% としてそのまま解釈されます。したがって、観測された粗い読み取り値はパーサーの上流、つまりヘッドセット／レシーバー側の報告仕様に起因しています。より細かい実機値は観測されておらず、完全な放電カーブも記録されていないため、すべての放電領域や他ファームウェアで常に 10% 刻みになるかどうかは未確定です。

90% における充電状態およびその後の非充電状態は実機で確認済みです。低残量/満充電の境界、ヘッドセット電源オフ時の挙動、Bluetooth、および USB ケーブルデータモードは実機テストされておらず、それらのモードに対するサポートは主張していません。この実装にはファームウェア更新、設定変更、EQ コマンド、ペアリング変更、リセット、およびベンダー製バイナリは一切含まれていません。

テスト: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`。


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **セクション:** HyperX Pulsefire Haste 2 Wireless（`docs/hyperx_haste_2.md`） · [英語原文](../../docs/hyperx_haste_2.md) · [↑ トップへ](#top)

# HyperX Pulsefire Haste 2 Wireless バッテリープロトコル

`src/drivers/hyperx.cpp` 内の `HasteWireless` によって読み取られます。クエリは [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) に由来し、NGENUITY が使用しているものと同一です。

実機確認済み:

- Pulsefire Haste 2 Core Wireless、ドングル `03F0:0AB5`。
- Pulsefire Haste 2 Wireless、ドングル `03F0:0F98`（uzumakiprime 氏による確認、PR #312）。残量は HyperX NGENUITY と一致。

`03F0:0D97` ドングルも同じ仕組みで動作する見込みですが、未テストです。

## HID コレクション

| 項目 | 値（`0F98`） |
|---|---|
| USB インターフェース | `MI_02`（インターフェース 2） |
| Usage Page : Usage | `FF00:0001` |
| Input / Output / Feature レポート長 | 64 / 64 / 64 バイト |

このドングルは標準のマウスおよび Consumer Control コレクションも公開しています。ドライバーは、Input レポート長が 8 バイト以上あるベンダーコレクション（Usage Page `FF00` 以上）のみを開きます。

## クエリ

どちらも Output Report であり、先頭 2 バイトが以下の値で、残りはレポート長までゼロ埋めします。各応答は先頭バイトが「コマンド + 1」の Input Report です。各クエリは応答を最大 1 秒待機し、無関係なレポートはスキップします（再接続直後、ドングルは自発的に `44 xx`、`45 xx`、`FB xx` レポートを送信します）。

| リクエスト | 応答 | 意味 |
|---|---|---|
| `52 01` | `53 01 <linked>` | マウスが電源オフまたは圏外のとき `linked` = 0 |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0〜100、`charge` 1 = 充電中 / 2 = 充電器上で満充電、mV 単位の電圧（リトルエンディアン、Core では 0） |

- リンク応答が得られない場合は、バッテリー応答で判断します。
- リンクが 0 を返した場合、バッテリークエリは送信せずマウスは電源オフとして表示されます。
- マウス電源オン直後の数秒間は約 40% を報告するため、リンク確立から 6 秒以内の読み取り値は無視し、トレイには前回の値を保持します。

どちらのリクエストも状態の読み取り専用です。設定・ライティング・モードを変更することはありません。


---

<a id="sec-inphic"></a>
> 📄 **セクション:** Inphic IN10（`docs/inphic.md`） · [英語原文](../../docs/inphic.md) · [↑ トップへ](#top)

# Inphic IN10 ファミリ、KP 8K レシーバー

所有者が IN10 MAX と特定した接続デバイスは、`Inphic KP 8K`、`1D57:FA65`、リリース `0116` として列挙されます。そのステータスコレクションはインターフェース 2、Usage `000A:0000`、Input 長 5（レポート ID 03 を含む）です。

リクエストを一切送信しなくても、約 4 秒ごとに以下が観測されます:

```text
03 73 41 01 64
```

既存の Xenta パーサーはこのフォーマット（モデル、イベント、バッテリー状態、パーセント）を認識します。関連レシーバーではリンク直後の初回レポートが誤って満充電を返すことがあるため、100% を表示する前には一致する 2 つのレポートを必須としています。この変更でもその保護機構と既存のスリープ/充電挙動は維持されます。

公式の [Inphic HUB](https://hub.inphic.cn/) バンドル `assets/index-BcHQx9B6.js` では、モデル番号 10 進 115（`73`）を `IN10RMax`、116（`74`）を `IN10Max` にマッピングしています。またバッテリー状態 1 をパーセント表示、2 を満充電、3 を充電中としています。`73` を IN10 MAX へ固定割り当てして同一レシーバーを共有する別デバイスを誤表示してしまうのを防ぐため、ファームウェア側のモデル名を使用しています。

この変更以前は、アプリは接続されたマウスを `Wireless mouse` と表示していました。Xenta トランスポート自体はすでにバッテリーフレームを処理できており、今回の変更は不足していたモデル名を補うものです。初回起動直後の `--list` は 5 秒の初期観測時間内に 4 秒間隔のレポートを 1 回しか受信できないことがあるためスリープ中と表示される場合がありますが、常駐アプリはリスナーを保持し、後続のポーリングで値を確定します。

実機検証済み: パッシブレポート、連続した 100% 残量、ネイティブドライバーでのモデル識別。充電遷移、低バッテリー境界、Bluetooth および有線モードは未検証です。モデル `74` は公式テーブルから取得したものであり、実機での個別検証は行われていません。


---

<a id="sec-machenike"></a>
> 📄 **セクション:** Machenike L7（`docs/machenike.md`） · [英語原文](../../docs/machenike.md) · [↑ トップへ](#top)

# Machenike L7 Arctic / L7 Mix

**L7 Mix** として認識される L7 Arctic 実機で検証済み:

| 接続方式 | VID:PID | インターフェース | Usage | Input / Output / 最大 Feature サイズ |
| --- | --- | --- | --- | --- |
| 2.4 GHz レシーバー | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB ケーブル | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

ドライバーは HID 製品名 `L7 Mix` も確認します。他の Machenike モデル、異なるレシーバー ID、および Bluetooth ベンダークエリは有効にしていません。

## プロトコル出典

[メーカーのドライバーページ](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/)から入手可能な公式ソフト **Machenike L7 Mix 1.0.0.8** の相互運用性解析、および実機マウスに対する読み取り専用クエリによる検証。`DeviceDriver.exe` SHA-256:
`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`。

この 32 ビット実行ファイル（イメージベース `00400000`）において、関数 VA `00436750` がステータスリクエストを構築し、`004494F0` が `HidD_SetFeature` 経由で送信して Feature 応答を読み取ります。ステータスパーサー `00410C20` が以下のフィールドを抽出し、バッテリーおよび充電フィールドを UI に渡します。これらはファイルオフセットではなく仮想アドレス（VA）です。プロプライエタリな実行ファイル、アプリコード、リソースはここには一切含まれていません。

## 状態読み取りクエリ

**21 バイト**（レポート ID `51`、コマンド `06`、残りの全バイト 0）を送信します:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

同じく 21 バイトで Feature Report `51` を読み取ります。コレクションの最大 Feature サイズ 1001 は他レポート用の値であり、ステータスレポートの長さではありません。ドライバーは読み取り前に 10 ms 待機し、無関係な応答を含め製品あたり単一の 200 ms 期限を使用します。設定・モード・マクロ・ファームウェアコマンドは一切送信しません。

インデックスはレポート ID を含みます:

| バイト位置 | 意味 / 観測値 |
| --- | --- |
| 0–1 | `51 06`、必須のコマンドエコー |
| 4–7 | `8A 24 4E FF`、検証済みの L7 デバイス署名 |
| 10, bit 0–2 | 動作モード: レシーバー時は 1、ケーブル時は 0 |
| 10, bit 3 | ワイヤレスマウス接続済みフラグ（USB ケーブル接続時もクリア） |
| 11 | バッテリー残量（%）、0〜100（0 も有効値） |
| 12 | 充電フラグ: 0 放電中、1 充電中 |

その他のフィールドおよびチェックサム仕様は未確定です。ドライバーが独自のチェックサムを仮定して検証することはありません。値を公開する前に、コマンド、長さ、デバイス署名、モード、および接続状態のバッテリー/充電範囲を検証します。

キャプチャしたレシーバー応答（公式アプリ上でも 64%）:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

充電中の USB ケーブル応答キャプチャ（74%）:

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

このときレシーバー側も引き続きキャッシュ済みの 64% を返していましたが、リンクビットはクリアされていました:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

この切断状態の読み取り値からキャッシュ済みのバッテリー/充電値を表示してはなりません。両方のトランスポートが存在する場合はケーブルが優先され、安定したデバイスキーはトランスポート間で共有されます。既知の L7 はクエリ失敗時にも専有（reserve）され、後続の Ajazz ドライバーが共有 VID 上で別プロトコルを用いてプローブしないように保護されます。

## 検証範囲の境界

フィクスチャおよび模擬トランスポートテストでは、キャプチャ済み読み取り値、充電中、有効な 0%/100%、切断されたレシーバー、不正/古い応答、厳密一致、トランスポート失敗、重複抑止、および有界リトライループをカバーしています。実機での 0%/100% やあらゆるスリープ/ファームウェア変種まではそれらのテストで保証されません。


---

<a id="sec-nuphy"></a>
> 📄 **セクション:** NuPhy WH80（`docs/nuphy.md`） · [英語原文](../../docs/nuphy.md) · [↑ トップへ](#top)

# NuPhy WH80（USB ケーブルおよび Bluetooth）

実機テスト済み: `19F5:A011`、ファームウェアリリース `0116`、インターフェース 1、Usage `0001:0000`、レポート ID なしの 64 バイト入出力ペイロード（Windows HID キャップでは 65 バイト）。

プロトコル出典: [NuPhyIO](https://drive.nuphy.io/)、バンドル `main.b3fb29e0.js`、SDK `getBatteryState(0)`、`getDataPackage`、`createCommand`。
リクエストするのは `GetFunc`（`05`）、オフセット `0020`、長さ `01` のみです。初期化、設定、ライティング、ファームウェアコマンドは一切不要です。

64 バイトにゼロパディングされるリクエストペイロード:

```text
55 05 00 21 01 20 00 00
```

実際の応答ペイロード:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

バイト 3 はバイト 4..63 の合計の下位バイトです。バッテリーはバイト 8 にあり、`value & 7F` がパーセント、`value & 80` が SDK の充電フラグです。
ネイティブ C++ ドライバーは接続されたキーボードで **100%、充電中** を返しました。
充電状態の遷移や低残量/満充電の境界は実機テストされていません。公式ファームウェアノートでは WH80 の読み取り値は 10% 刻みと説明されています。
レシーバー動作はこのドライバーの対象範囲外です。

## Bluetooth

Bluetooth 接続では同じキーボードが HID ID `19F5:324A`（リリース `0129`）を使用し、`NuPhy WH80 - 1` のようなユーザー向け表示名でアドバタイズします。キーボードコレクション 2 つとマウスコレクション 1 つを公開しており、汎用 HID のヒューリスティックがマウスを優先してしまうため、この正確な Bluetooth ID を既存のキーボード上書きリストへ追加しています。

バッテリー報告には引き続き Windows の Bluetooth バッテリープロパティを使用します。USB を抜いた後、接続中のキーボードについて Windows は **95%** を報告しました。標準 GATT Battery Level（`180F` / `2A19`）をキャッシュなしで直接読み取った場合もキーボードから **95%** が返されました。これは有線時の 100% 観測値とは別トランスポート/別デバイスの測定値であり、勝手な満充電値への置き換えや再スケーリングを行ってはなりません。ファームウェアの報告値が異なる理由は確定していません。

ドライバーは正確なプロダクト/インターフェース/レポートサイズ、応答ヘッダー、オフセット、長さ、チェックサム、およびパーセント範囲を検証します。400 ms の応答期限を使用し、同じ期限内の無関係な応答は無視します。

回帰テスト:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **セクション:** Rapoo（`docs/rapoo.md`） · [英語原文](../../docs/rapoo.md) · [↑ トップへ](#top)

# Rapoo マウス バッテリーサポート

## 従来のプログラムでマウスが検出されなかった理由

`PollAllDevices()` は更新ごとに Windows の HID トップレベルコレクションを 1 度列挙します。各ベンダードライバーはプロトコルを認識して `DeviceStatus` を追加し、汎用ドライバーが重複追加しないようその VID/PID を専有（claim）します。UI 側にはパーセント表示、充電中表示、およびスリープ中の最後の値を保持する機能がすでに備わっています。

従来は Rapoo 用ドライバーがありませんでした。VT3 Max Gen 2 は標準の HID Battery Strength Usage や Windows Bluetooth バッテリープロパティではなく、ベンダー定義の Input Report 内でバッテリー残量を送信します。そのため既存の汎用 HID / Bluetooth フォールバックでは USB レシーバーをデコードできませんでした。

## 実機確認したハードウェアとパケット

2026-11-16 に所有者の VT3 Max Gen 2 を用いて Windows 上でテスト:

| 接続方式 | VID:PID | インターフェース | Usage Page:Usage | Input / Output サイズ |
|---|---|---|---|---|
| 2.4 GHz レシーバー | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 バイト |
| USB ケーブル | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 バイト |

どちらもデバイス名は `Rapoo Gaming Device` として識別されます。他のコレクションには標準マウス・キーボード・メディア入力、ベンダー設定コレクション、および 513 バイトのファームウェアインターフェースが含まれます。バッテリードライバーは認識された Input サイズを持つ `FF00:0002` のみを開きます。ファームウェアインターフェースを開くことはなく、Output Report、Feature Report、ハンドシェイク、設定コマンドも一切送信しません。

キャプチャしたワイヤレスレポート（レポート ID を含む）:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

キャプチャしたケーブル／充電中レポート:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

以下のオフセットは本プロジェクトの `HidDev::Read()` に合わせ、レポート ID をバイト 0 として数えています:

| バイト位置 | 意味 | 例 |
|---|---|---|
| 0 | レポート ID | `07` |
| 1 下位ニブル | 接続種別: 0 レシーバー、1 Bluetooth、2 ケーブル | `20` / `22` |
| 1 上位ニブル | センサー情報（接続種別の一部ではない） | `2` |
| 2 | 現在の DPI 段階 | `03` |
| 3–4, 5–6 | X/Y DPI（リトルエンディアン） | `0320` = 800 |
| 7 | バッテリー状態: 0 無効、1 放電中、2 充電中 | `01` / `02` |
| 8 | バッテリー残量（%）、0〜100 | `19` = 25% |
| 13–14 | マウスのプロダクト ID（リトルエンディアン、存在する場合） | `4617` |

ライブのレシーバーキャプチャでは `25%` が報告され、その後のアプリ全体での動作ではケーブル接続時に `27%, charging` が返されました。パーサーテストにはこの実際のワイヤレスキャプチャが含まれています。充電状態およびケーブル接続状態も実機で確認済みであり、単に USB デバイスが存在することから推測しているわけではありません。所有者がケーブルを抜いてレシーバーを再接続したところ、最終ビルドの実行ファイルは充電フラグなしの `2.4 GHz receiver` 経由で `52%` を返し、同一の `rapoo:4617` キーを維持しました。これにより、ケーブルからレシーバーへの遷移も実機で確認されています。

2026-11-17 に Windows 上で **VT9 Gen 2** でもテスト済み:

| 接続方式 | VID:PID | インターフェース | Usage Page:Usage | Input / Output サイズ |
|---|---|---|---|---|
| 2.4 GHz レシーバー | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 バイト |
| USB ケーブル | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 バイト |

VT9 Gen 2 レシーバーは 19 バイトではなく **16 バイト** の `FF00:0002` レポートを公開していますが、Nordic 54L `07` レイアウト自体は完全に同一です（バイト 13–14 に埋め込まれた `4614` PID を含む）。キャプチャしたフレーム:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

USB ケーブル接続時は操作時（DPI 変更など）にステータスレポートが観測されました。また、接続した状態で底面電源スイッチを OFF にすると、マウスは実際のバッテリー残量ではなく `state=2, percent=1` を報告しました。

### 13 バイトコレクションを持つ VT3 Max Gen 2 レシーバー（Issue #1396）

同一レシーバー ID `24AE:1417` に対するデバイスリクエストフォームの報告で、19 バイトではなく **13 / 13** バイトの `FF00:0002`、33 / 33 バイトの `FF00:000E`、および 513 バイトのファームウェアコレクションなしという異なるインターフェース構成が報告されました。これはレシーバーの別ファームウェアリビジョンと見られます。Rapoo 純正ソフトではバッテリーが表示されていたため、従来のドライバーは有効なステータスチャネルを見落としていたことになります。

Rapoo Hub の `VT_nrf54L` デコーダー（`py`）は可変長対応であり、DPI・バッテリー状態・残量（%）を常に読み取り、後続フィールド（`n[12..13]` のマウス PID、RF 情報など）はレポート長が十分な場合にのみ読み取ります。VT3 MAX マニフェスト（`productId: [17943, 5143]`）には特別な Input Report 種別が存在しないため、このレシーバーでもレポート `07` はそのデコーダーを通ります。13 バイトのレポート（ID＋12 バイト）でも引き続きバイト 7 に状態、バイト 8 に残量が含まれており、埋め込みマウス PID だけが欠落しているため、読み取り値にはレシーバー PID を使いつつ `rapoo:4617` キーを維持します。

この 13 バイト長は **`24AE:1417` に対してのみ**許可されています。フレームは引き続き同じチェック（レポート `07`、接続ニブル 0〜2、状態 1/2、残量 0〜100）に合格する必要があります。実機の 13 バイトフレーム自体は未キャプチャであり、テストでは検証済みの 19 バイトキャプチャを 13 バイトに切り詰めたものを使用しています。

## その他の Rapoo マウス

公式の Rapoo Hub は Nordic 54L マウスドライバーにこの `07` レイアウトを使用しています。マニフェストには VT0、VT1、VT2、VT3、VT3S、VT7、VT9 および追加バリアントが記載されています。現行バンドルの調査では `VT_nrf54L` を使用する 69 種類の VT バリアントが確認されましたが、これは共通プロトコルであることの根拠であり、69 機種すべてで実機検証したことや Rapoo 全製品群を網羅していることを主張するものではありません。サポート判定は Rapoo VID、専用コレクション、Input 長、および有効なステータスレポートによって行われるため、一覧にないモデルでも同じプロトコルを使っていればバッテリーを報告できます。主要なモデルは小規模な名称テーブルで対応しており、それ以外は HID 製品名をそのまま使うか `Rapoo wireless mouse` と表示します。

製品名や ID は世代や地域によって異なります。検証済みの `1417/4617` ペアは現在の公式マニフェストでは `VT3 MAX` と呼ばれていますが、所有者は VT3 Max Gen 2 として識別しています。現行マニフェスト上の別モデル `VT3 MAX V2` の ID は `1B06/4B06` です。`1417` を VT9 Pro としているコミュニティの対応表を、このデバイスの命名や検出の唯一の根拠として使ってはなりません。

VT3 Pro（`1215/4415`）で文書化されている旧 VT ファームウェアは、代わりに同じ `FF00:0002` Usage 上で 7 バイトレポートをプッシュします:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

このレガシー形式では、状態 1/2 が放電中/充電中を意味します。充電中の残量 `7F` は不明を意味し、不明としてそのまま保持されます。遷移状態 0、無関係な `BC` レポート、不正パケット、および 100 を超える値は無視されます。レガシーサポートは自動テストで検証されていますが、ここではレガシー実機マウスでの検証は行っていません。この解釈はプロダクト ID `1215/4415`（VT3 Pro）、`1233/4433`（VT1 Pro Max）およびそれらの 7 バイト Input コレクションに限定しています。

VT1 Pro Max（レシーバー `24AE:1233`、ケーブル `24AE:4433`、マウスファームウェア 222、ドングルファームウェア 213）は、所有者が Issue #136 に添付した USBPcap キャプチャから追加されました。`--dump` 出力にはインターフェース 1 上の 7 バイト `FF00:0002` コレクションが示され、キャプチャでは Rapoo アプリからのリクエストなしに以下がプッシュ送信されていました:

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

ケーブル接続時は 16 秒間のキャプチャで 1 回しかレポートが見られなかったため、ケーブル単独の読み取りでは更新によってタイムアウトすることがありますが、レシーバーは定期的にプッシュします。Nordic プロファイルが `BB` パケットを解釈することは決してありません。

これらによってすべての Rapoo デバイスがサポートされるわけでは**ありません**。VT1 SE や VT7 SE などの CH584 モデルは公式ドライバーでレポート `08` を使用するためこのデコーダーでは非対応です。他の Telink リビジョンでは `BB` フラグの解釈が異なり、オフィス向けモデルの一部は能動的なバッテリークエリを使い、Bluetooth モデルは Windows バッテリープロパティのみを公開する場合があります。それらは既存のフォールバックに任せるか、別途検証済みの実装が必要であり、推測でクエリを送信してはなりません。

## ポーリングと識別子

- 読み取りはパッシブです。一致する `FF00:0002` ハンドルはポーリング間も開いたまま維持され（`PollXenta` と同様）、60 秒の更新間隔中に届くステータスフレームを Windows にバッファリングさせます。各ポーリングではキュー内のフレームをすべて読み出して最新の有効な値を採用し、初回オープン時やキューが空の場合のみ 5 秒の待機にフォールバックします。取り外されたデバイスは削除されハンドルも閉じられます。無関係なパケットで期限が延長されることはありません。
- 埋め込みマウス PID、または旧機種向けの既知のケーブル/レシーバーペアにより、ケーブル着脱を跨いでも同一の UI キーになります。ケーブルとレシーバーの読み取り値は 1 つのエントリーに統合され、ケーブル側の状態を優先しつつ、ケーブル側が残量不明を返した場合でも有効なレシーバー側のパーセント値を保持します。
- タイムアウト時に勝手なパーセント値を捏造したりデバイスを専有したりしません。1 度読み取りに成功した後は、既存 UI が最大 30 分間の無応答の間その値を薄く表示して保持できます。
- プログラム既存の VID/PID ベース識別モデルでは、同じモデル ID を持つ同一マウス複数台を区別できません。ケーブルとレシーバーの物理的な同時動作は実機テストしていませんが、両入力のマージ処理は模擬トランスポートテストで網羅しています。

## 検証

`make test` はポータブルデコーダーテストおよび模擬 HID 応答を用いた Windows ドライバーテストを実行します。テスト範囲には実キャプチャ、0% と 100%、充電中、残量欠損、不正/切り詰めフレーム、未対応コレクション/ベンダー、プロトコルプロファイル分離、タイムアウト、安定キー、および既知の残量を捨てずにケーブル/レシーバー重複排除を行う処理が含まれます。

MSVC C++17 と Windows SDK でアプリケーション全体をローカルビルドし、実機マウスに対して `--list` / `--dump` を実行しました。保守されている MinGW ビルドでは `build.bat` に `rapoo.cpp` が含まれており、Makefile は自動検出します。テスト環境自体に MinGW はインストールされていませんでした。

## プロトコル出典

- [公式 Rapoo Hub](https://hub.rapoo.cn/)（2026-11-16 調査）: バンドルされた [JavaScript ドライバーおよびマニフェスト](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js)。関連するデコーダーは `VT_nrf54L` 用の `py`/`Hk`、および接続・バッテリー状態の意味を表す `qM`/`QM`。別個の `VT_CH584` ハンドラーはレポート `08` を扱うためこの実装の対象外。縮小（minify）後の識別子名は今後のリリースで変わる可能性があります。
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs): 旧 VT3 Pro レポート、充電状態、不明残量のセンチネル値。
- Issue #136 USBPcap キャプチャ（レシーバー接続時および充電中のケーブル接続時の VT1 Pro Max）。
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js): パッシブ `07` ステータスブロードキャストおよびバッテリーオフセットを独立して裏付け。先方のパーサーは無効なパーセント値をクランプしますが、本実装では代わりに破棄します。


---

<a id="sec-rawm"></a>
> 📄 **セクション:** RAWM（`docs/rawm.md`） · [英語原文](../../docs/rawm.md) · [↑ トップへ](#top)

# RAWM プロトコルノート

RAWM マウス（およびプラットフォームを共有する SADES Dagger）は、64 バイトのレポート ID なし入出力レポート（レポート ID 込みで 65 バイト）を持つベンダー HID コレクション `FF00:0001` を介して RAWM HUB アプリと通信します。レシーバーとマウスは Nordic のベンダー ID `1915` を使用します。

出典: RAWM HUB Web アプリ Hub Web 2.0（<https://www.rawmtech.com/hub.html>）およびそのスクリプト `https://hub.miracletek.net/hub/js/library.min.js`（難読化されており、以下の関数名・定数名は同スクリプト独自のものです）。対応プロダクト ID は同アプリがダウンロードするデバイステーブル（`https://www.miracletek.net/game/device.php`）に由来します。Leviathan V4 GT および NYX60 は VID `373E` の Hub Web 3.0 を使用しており、別プロトコルです。

## パケット

すべてのレポートのバイト 0（レポート ID の後ろ）:

| 上位ビット | 意味 |
|---|---|
| `0x80`（`PACKET_TYPE_EVENT_DATA`） | 下位 6 ビットがペイロード長であり、ペイロードがイベントストリームを継続する |
| `0x40`（`PACKET_TYPE_BUFFER_SIZE`） | フロー制御（空きバッファサイズ）。ここでは無視 |
| `0xC0`（`PACKET_TYPE_EXTENDED`） | 下位 6 ビットが ESB チャネルであり、レポートの残りはそのチャネル宛てのパケット。レシーバー配下のマウスはチャネル 0 |

ペイロードはイベントのバイトストリームを形成します:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## バッテリーの読み取り

ドライバーはレシーバー接続時にアプリが行う手順（`send_event_query`、`send_event_ping`）を再現します:

1. レシーバー宛てに `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>`（`CMD_QUERY`、OS = PC）を送り、続いて ping `00 84 0E 04 00 00` を送ります。デバイスはホストが書き込み続けている間のみ応答を返すため、ホストは ping を送り続けます。レシーバーは `CMD_QUERY_RESULT`（`02`）として JSON（例: `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`）を返します。
2. 先頭に `C0` を付けたチャネル 0 宛ての同一クエリおよび ping を送信します。マウスは 30 バイトの ESB チャンクに分割された約 550 バイトの JSON オブジェクト（例: `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`）で応答します。`battery` がパーセント値（RAWM HUB はそのまま表示）、`chr` が充電中 1 です。
3. その後の変化は `CMD_NOTIFY`（`0B`）タイプ `17`: `[17, percent, charging]` として届きます。

アプリと同様、ドライバーは必ず先にレシーバーへ問い合わせます（あるテストではチャネル 0 のみにクエリを送ったところ応答がありませんでした）。スリープ中のマウスは一切応答しませんが、レシーバーは応答します。

アプリがそのように送信しているためクエリには PC の時刻を含めますが、それ以外の書き込みは行いません。マウスは `"crc":1` を報告して後続コマンド（設定変更）を CRC-16 フレームで包むようアプリに指示しますが、クエリと ping はアプリがそれを知る前に送る仕様のため CRC なしでも受け付けられます。

Leviathan V4（ファームウェア 1.2.0）と RAWM HS Receiver `1915:2346`（ファームウェア 2.0.2）の組み合わせで実機テスト済みです。


---

<a id="sec-vaxee"></a>
> 📄 **セクション:** VAXEE（`docs/vaxee.md`） · [英語原文](../../docs/vaxee.md) · [↑ トップへ](#top)

# VAXEE 4K/8K レシーバーおよび ZYGEN NP-01S V2

## 対象範囲と実機検証

このドライバーは VAXEE 4K レシーバー `3057:1002`、VAXEE 8K レシーバー `3057:2002`、および USB ケーブル接続の ZYGEN NP-01S V2 Wireless（`3057:1011`）を、64 バイト Feature Report を持つベンダーコレクション `FF05:0001` 上でサポートします。他の VAXEE レシーバー、他のケーブルプロダクト ID、および ZOWIE デバイスには意図的にアクセスしません。

8K レシーバー（`VAXEE 8K Wireless`、NP-01 Ergo Wireless 8K とペアリング）は Windows 上でテストされ、同じプロトコルで以下のように報告されました:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

このレシーバーはすべての VAXEE 8K マウスで共通であり、どの機種がペアリングされているかを報告しないため、レシーバー自身の名前で表示されます。8K レシーバーでの充電状態はまだ実機で確認されていません。

実際の 4K レシーバーも Windows 上でテスト済みです:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

統合アプリケーションでも以下のように報告されました:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

続いて同じマウスを USB で直接接続したところ、Windows は `ZYGEN NP-01S V2 Wireless`（`3057:1011`）として認識し、更新後の製品版ドライバーは以下のように報告しました:

```
VAXEE battery: 75%; charging: yes
```

初期のレシーバービルドでタスクバーウィジェットも正常に作成されました。バッテリー駆動でのレシーバー動作および有線充電はいずれも観測済みですが、満充電への遷移およびスリープ/電源オフ時の挙動は実機テストされていません。充電状態のデコードおよび不正応答は模擬応答テストで網羅しています。

## プロトコル

出典: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md)。

リクエストはゼロパディングされた 64 バイトの HID Feature Report です:

| バイト位置 | 値 |
|---|---|
| 0 | `0E`（レポート ID） |
| 1 | `A5`（ヘッダー） |
| 2 | バッテリー残量は `0B`、充電状態は `10` |
| 3 | `01`（読み取りフラグ。書き込みの `02` は決して使用しない） |
| 4 | `01`（データ長） |
| 5–63 | `00` |

`HidD_SetFeature` でリクエストを送信したあと 100 ms 待機し、`HidD_GetFeature` でレポート `0E` を読み取ります。少なくとも 6 バイトあり、期待されるレポート ID、ヘッダー、コマンドエコー、およびデータ長が一致することを要求します。

バッテリーの場合、応答バイト 5 は 0〜20 でなければならず、これに 5 を掛けて 5% 刻みの 0〜100% とします。充電状態の場合、バイト 5 が非ゼロであれば充電中です。充電状態クエリが失敗しても、有効なバッテリー残量の読み取り値は破棄しません。

ドライバーはバッテリーリクエストを 1 回だけリトライします。一致するコレクションあたり送信される読み取りリクエストは最大 3 回（バッテリー取得最大 2 回＋充電状態クエリ 1 回）で、明示的な待機時間は合計 300 ms です。設定・ペアリング・ファームウェア・ライティングコマンドは一切送信しません。

有効なバッテリー応答が得られない場合、ドライバーは何も報告せずデバイスを未専有のままにします。USB コレクションが存在し続ける間、UI は既存の猶予期間動作により、以前取得できた値を薄くして最大 30 分間保持します。物理コレクションが消滅した場合、ドライバーは切断ステータスを 1 回送出してその猶予期間を即座に終了します。これにより、ケーブルをマウスへ差し替えた際に古いレシーバーアイコンが残り続けるのを防ぎます。

## テスト

`make test` には `tests/vaxee_driver_test.cpp` が含まれており、製品版ドライバーを模擬 HID トランスポートとリンクして実行します。送出される正確な読み取り専用リクエスト、パーセント換算、充電状態デコード、不正応答・欠損応答、すでに専有済みのデバイス、および厳密なコレクションフィルタリングを検証します。
