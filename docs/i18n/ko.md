<!--
  BatteryHub 전체 문서 한국어 번역본
  단일 독립형 Markdown 파일로 저장소 내 모든 문서를 포함합니다.
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **언어:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | **한국어** | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [언어 추가](README.md)
<!-- lang-switcher:end -->

# BatteryHub — 전체 문서 (한국어)

> 이 단일 독립형 Markdown 파일은 저장소의 모든 공개 문서를 하나로 모아 번역자가 **언어당 하나의 파일만** 유지·관리할 수 있도록 구성되어 있습니다.

## 목차

1. [BatteryHub 개요, 지원 기기, 설치, CLI 및 빌드 (`README.md`)](#sec-readme)
2. [기여 가이드 (`CONTRIBUTING.md`)](#sec-contributing)
3. [Pull Request 템플릿 (`.github/pull_request_template.md`)](#sec-pr-template)
4. [릴리스 및 서명 가이드 (`docs/releasing.md`)](#sec-releasing)
5. [Keychron 키보드 2.4 GHz 펌웨어 패치 (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [GameSir Cyclone Pro BLE 지원 (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [다국어 사용 및 현지화 가이드 (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Areson 25A7 수신기 (`docs/areson.md`)](#sec-areson)
10. [DARKRIM SHADOW 수신기 (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K 수신기 (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Rapoo 마우스 배터리 지원 (`docs/rapoo.md`)](#sec-rapoo)
16. [RAWM 프로토콜 노트 (`docs/rawm.md`)](#sec-rawm)
17. [VAXEE 4K/8K 수신기 (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **섹션:** BatteryHub 개요 (`README.md`) · [English 원문](../../README.md) · [↑ 맨 위로](#top)

# BatteryHub

*이전 이름: **Wireless Battery**. 버전 1.1.0에서 앱 이름이 변경되었으며, 업데이트 후에도 기존 설정, 시작 프로그램 설정 및 배터리 기록이 그대로 유지됩니다.*

[![Ko-fi로 후원하기](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![PayPal로 기부하기](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Discord 참여하기](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![GitHub 스타 누르기](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Reddit에 공유하기](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![기기 제보하기](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![번역 돕기](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

무선 마우스, 헤드셋, 키보드, 컨트롤러의 배터리 잔량을 Windows 작업 표시줄에서 바로 확인하세요.

![작업 표시줄의 BatteryHub](../screenshot.png)

> **바로 쓰고 싶다면?** 최신 릴리스에서 **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)**을 내려받아 실행하고 다음 단계를 따라 설치하면 끝입니다.
>
> **고급 사용자**는 포터블 ZIP을 내려받거나, [명령줄 옵션](#명령줄)을 사용하거나, `make` 또는 `build.bat`으로 [소스에서 직접 빌드](#빌드)할 수 있습니다.
>
> **마음에 드셨나요?** BatteryHub는 무료 오픈 소스 소프트웨어입니다. 제조사 전용 소프트웨어를 켜지 않아도 되어 도움이 되었다면 [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) 또는 [GitHub Sponsors](https://github.com/sponsors/krisgfx9)로 후원해 주세요. 학업과 병행하며 앱을 계속 무료로 유지하는 데 큰 힘이 됩니다. 금전적 후원이 어렵더라도 GitHub ⭐ 스타, 주변 공유, 또는 `--dump`로 미지원 기기를 제보해 주시면 똑같이 큰 도움이 됩니다.

- **초경량:** RAM 약 2 MB만 사용하는 ~350 KB 크기의 앱입니다. 별도 런타임이나 백그라운드 서비스가 없는 순수 C++/Win32 앱이며, 관리자 권한 없이 몇 초 만에 설치됩니다.
- **제조사 소프트웨어 불필요:** 기기와 직접 통신합니다. G HUB, Synapse, iCUE, GG, NGenuity를 꺼 두어도 되며, 함께 실행해도 충돌하지 않습니다.
- **다양한 브랜드 지원:** Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, PlayStation 및 Xbox 컨트롤러, Samsung Galaxy Buds, Windows가 배터리 잔량을 인식하는 모든 블루투스 기기, 그리고 기본 포함된 [HeadsetControl](https://github.com/Sapd/HeadsetControl)이 지원하는 모든 헤드셋을 지원합니다.

## 표시 방식

**작업 표시줄 표시 (기본값):** 알림 영역 옆에 Windows 아이콘 글꼴로 `🎧 30%  🖱 93%`처럼 표시됩니다.
- **배터리 부족:** 숫자가 빨간색이면 잔량이 15% 이하라는 뜻입니다.
- **충전 중:** 숫자 옆에 파란색 ⚡ 아이콘이 표시됩니다. 전원이 연결된 상태에서 완전히 충전되면 초록색 ✓로 바뀝니다.
- **절전 중:** 흐리게 표시된 텍스트는 기기가 절전 상태이며 마지막으로 확인된 잔량이 표시되고 있음을 의미합니다.
- **연결 끊김 (선택 사항):** *연결되지 않은 기기 표시*를 켜면 드라이버가 무선 링크 오프라인을 명시적으로 보고하는 기기에 흐린 `×`를 표시합니다. 이는 배터리 폴링 누락으로 연결 끊김을 추정하는 것이 아니며, 기본값은 오프라인 기기를 숨기는 것입니다.
- **같은 종류의 기기가 두 대 이상일 때:** 마우스 두 대(또는 컨트롤러 두 대 등)를 함께 쓰면 아이콘이 같아지므로, 각 아이콘 모서리에 기기 이름에서 따온 최대 3글자의 작은 라벨(`MX`, `PRO`)이나 이름으로 구분되지 않을 경우 숫자가 표시됩니다. 해당 종류의 기기가 하나뿐이면 라벨이 표시되지 않습니다.
- **테마:** Windows 밝게/어둡게 모드 및 DPI 배율을 자동으로 따릅니다.
- **투명 작업 표시줄 테마** (예: Windhawk의 Taskbar Styler): 배경화면 위에서도 글자가 잘 보이도록 메뉴에서 *작업 표시줄의 글자 뒤에 배경 표시*를 켜세요.
- **다중 모니터:** 전체 화면 게임을 실행 중일 때도 볼 수 있도록 모든 모니터의 작업 표시줄 시계 옆에 위젯이 표시됩니다. 메뉴의 *위젯을 표시할 모니터*에서 *모든 모니터*, *주 모니터에만* 또는 특정 디스플레이 하나(예: *디스플레이 3에만*)를 선택할 수 있습니다.
- **추가 표시 옵션:** *백분율 위에 아이콘 표시*는 아이콘을 잔량 위에 세로로 배치해 가로 너비를 줄여 줍니다. *브랜드 색상*은 알려진 브랜드(Razer 초록색, HyperX 빨간색 등)를 고유 색상과 얇은 잔량 막대로 표시합니다. 같은 종류의 기기가 두 대 이상이면 구분할 수 있도록 작은 라벨이 붙으며, 왼쪽/오른쪽 세로 작업 표시줄에서는 기기가 세로 열로 배치됩니다.
- **언어:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文, 繁體中文을 지원합니다. Windows 앱과 Linux 앱 모두 시스템 표시 언어를 따르며, 메뉴의 *언어*에서 다른 언어를 고를 수 있고 Windows 설치 프로그램도 19개 언어를 모두 지원합니다. UI 문구는 편집 가능한 정적 `lang/*.json` 파일에 저장되어 있으며, 전체 번역 문서는 [`docs/i18n/`](README.md)에 있습니다. 언어를 수정하거나 추가하려면 [번역](#번역)을 참고하세요.
- **브랜드 색상:** 알려진 15개 브랜드의 기기는 은은한 빛 효과와 백분율 아래의 얇은 잔량 막대가 포함된 제조사 색상으로 표시됩니다: Razer 초록색, Logitech 파란색, SteelSeries 주황색, Corsair 노란색, HyperX / ROG / ZOWIE 빨간색, PlayStation, Xbox, Samsung, Apple, Jabra, JBL, Cooler Master, Steam. 각 색상에는 어두운 작업 표시줄용과 밝은 작업 표시줄용 색조가 따로 마련되어 있습니다. 브랜드는 기기를 찾은 드라이버, 제조사 ID(VID), 기기 이름 순으로 판별하며, 색상과 규칙은 `src/brands.cpp`에 정의되어 있습니다. 메뉴의 *브랜드 색상*에서 끌 수 있습니다.

**시스템 트레이 아이콘:** 기기마다 숫자가 그려진 트레이 아이콘을 표시하며, 15%에서 "배터리 부족" 알림을 띄웁니다. 작업 표시줄이 세로 방향이거나 작업 표시줄을 찾을 수 없으면 앱이 자동으로 이 모드로 전환됩니다.

**사용자 지정 기기 이름:** 기기 하위 메뉴를 열고 *기기 이름 변경...*을 선택해 최대 64자까지 이름을 지정할 수 있습니다. 이 이름은 작업 표시줄 위젯의 도구 설명/라벨, 트레이 도구 설명 및 알림, 기기 메뉴에 표시됩니다. *원래 이름으로 복원*을 선택하면 드라이버의 원래 이름으로 되돌아갑니다. 이름은 안정적인 기기 키를 사용해 현재 사용자의 Windows 레지스트리(`Software\WirelessBattery`, `DeviceAliases`)에 로컬로 저장됩니다. 이름을 변경해도 드라이버 매칭, 프로토콜 쿼리, `--list` / `--dump` 진단 출력은 달라지지 않으며 계정이나 네트워크 연결도 필요하지 않습니다.

아이콘에 마우스를 올리면 자세한 정보를 볼 수 있고, 클릭하면 모든 기기(클릭하여 숨기거나 표시), 표시 모드, *지금 새로 고침*, *Windows 시작 시 실행*, *종료* 메뉴가 열립니다. 배터리 잔량은 60초마다(메뉴의 *배터리 확인 주기*로 변경 가능) 새로 고침되며, 기기를 연결하거나 PC가 절전 모드에서 깨어날 때는 즉시 새로 고침됩니다.

## 스마트 배터리 알림 (실험적 기능)

각 기기의 하위 메뉴(**배터리 알림** → *기본값 사용 (15%)*, *알림 끄기* 또는 5%, 10%, 15%, 20%, 25%, 30%, 35%, 40% 중 선택)에서 **기기별 배터리 부족 알림 임계값**을 설정할 수 있습니다. 별도로 재정의하지 않으면 기존 기본값인 15%가 그대로 유지됩니다. 설정은 현재 사용자의 Windows 레지스트리(`Software\WirelessBattery`, `AlertThresholds`)에 기기 키별로 저장됩니다.

알림은 기기가 연결되어 있고 절전 상태가 아니며 충전 중이 아닐 때 실제로 새로 측정된 0~100% 배터리 수치를 기준으로만 발생합니다. 알림은 한 번만 표시되며, 배터리 잔량이 선택한 임계값보다 10퍼센트포인트 초과로 올라가거나 충전이 시작되면 다시 활성화됩니다. 측정값이 누락되거나 기기가 절전 중일 때는 알림이 반복 발생하지 않습니다. 숨겨진 기기는 알림을 생성하지 않으며, 한 기기의 알림을 꺼도 해당 기기가 숨겨지거나 백분율 표시가 바뀌지는 않습니다.

작업 표시줄 위젯 모드와 트레이 아이콘 모드 모두 알림을 지원합니다. Windows에서 레거시 풍선 알림을 표시하려면 알림 영역 아이콘이 필요하므로, 위젯 모드에서는 알림 후 최대 1분 동안 임시 알림 아이콘이 표시될 수 있습니다. 위젯 색상과 배터리 부족 강조 표시는 알림 설정과 무관하게 프로젝트의 기존 전역 15% 임계값을 그대로 사용합니다.

## 배터리 기록 및 인사이트

작업 표시줄 위젯이나 트레이 메뉴에서 기기를 마우스 오른쪽 버튼으로 클릭하고 **배터리 기록...**을 선택하세요. Windows 밝게/어둡게 테마를 따르는 DPI 대응 네이티브 뷰어에서 최근 **24시간**, **7일** 또는 **30일** 동안 기록된 배터리 잔량 그래프와 최근 값, 최저/최고 값, 변화량(퍼센트포인트), 측정 횟수를 확인할 수 있습니다. 뷰어에서 선택한 기기의 기록을 삭제할 수도 있습니다.

기록은 숫자 백분율을 보고하는 연결된 활성 상태의 기기에 대해서만 **로컬에만** 저장됩니다. 측정값은 기기당 최소 30분 간격으로 샘플링됩니다(충전 상태 전환 시에는 최소 60초 간격). 데이터는 최대 30일간 보관되며 로컬 파일 크기는 약 2 MB 이하로 유지됩니다. 앱은 기존 폴링 외에 하드웨어를 추가로 탐색하지 않고 네트워크로 기록 데이터를 전혀 전송하지 않으며, 최근 방전 관측치만을 바탕으로 보수적이고 대략적인 예상 배터리 사용 가능 시간을 계산합니다. 예측에는 최소 4개의 측정값, 2시간 이상의 경과, 3퍼센트포인트 이상의 감소, 최신 측정값, 안정적인 방전 구간이 필요합니다. 충전 중이거나 측정값이 오래되었거나 데이터가 부족하면 예측을 표시하지 않으며, 기기가 직접 보고하는 남은 시간은 제공되지 않습니다. 이 추정치는 보장된 수치가 아닙니다. 차트에서 누락된 데이터는 보간하지 않고 빈 구간으로 표시합니다.

메뉴에서 **배터리 기록 저장**을 끄면 새 측정값 저장을 중지할 수 있으며, 이미 저장된 데이터는 뷰어에서 삭제할 때까지 유지됩니다. 파일은 `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`에 저장되며, 기기 식별자는 인코딩되어 있습니다(암호화는 아님). 또한 이 파일은 현재 Windows 계정의 로컬에만 저장됩니다. `--demo` 모드에서는 차트에 저장되지 않는 가상 예시 데이터를 사용합니다. **참고:** 기록 수집은 이 기능이 포함된 버전을 설치하고 앱이 일정 시간 실행된 이후부터 시작됩니다.

## 지원 기기

| 제조사 | 지원 기기 | 동작 방식 |
|---|---|---|
| **NuPhy** | USB 케이블(`19F5:A011`) 또는 블루투스(`19F5:324A`)로 연결된 WH80, 실기 테스트 완료 | USB: 읽기 전용 NuPhyIO 배터리 쿼리; 블루투스: 키보드 분류가 적용된 Windows 배터리 잔량 ([프로토콜 노트](#sec-nuphy)) |
| **DARKRIM** | `3654:6901` USB 수신기의 SHADOW(寸渊影弑) (실기 테스트 완료) | CRC 검증을 거친 읽기 전용 배터리 쿼리 및 충전 플래그; 10% 단위 단계 측정값만 관측되었으며 더 세밀한 정밀도는 미검증 ([프로토콜 노트](#sec-darkrim)) |
| **Inphic** | KP 8K 수신기(`1D57:FA65`)의 IN10R MAX / IN10 MAX (모델 `73` 실기 테스트 완료, 모델 `74` 미테스트) | 수동 Xenta 상태 보고; 일치하는 두 프레임으로 잔량 확정 ([프로토콜 노트](#sec-inphic)) |
| **ASTRO** | USB 베이스 스테이션을 통한 A50 X(`046D:0B0B`, 테스트 완료), A50 Gen 5(`046D:0B1C`), A50 Gen 4(`9886:002C` 테스트 완료, `002D`/`002A`), A50 Gen 3(`9886:0015` 테스트 완료, `0014`/`0018`/`001D`/`0026`), A20 Wireless(`9886:0037`–`0045`) | 배터리 백분율, 충전 및 거치 상태 |
| **Logitech** | Unifying, Bolt, Lightspeed(PRO X3 SUPERSTRIKE 동글 `046D:C54F` 포함) 및 Nano 수신기, USB 또는 블루투스 연결 마우스 및 키보드; G 헤드셋(G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); 신형 `046D:0ADF` 동글의 G435 | 기능 탐색을 지원하는 HID++ 1.0 / 2.0: 통합 배터리, 배터리 잔량, 전압, ADC; G435: CRC-16 프레이밍 제조사 보고서, mV 단위 `GET_BATTERY` |
| **Razer** | 무선 마우스, 키보드 및 동글; BlackShark V2 HyperSpeed, V2 Pro(2020/2023), V3 / V3 Pro / V3 X 헤드셋, Xbox용 V3 Pro(`1532:0A55` 수신기, `0A4E` 케이블); 2.4 GHz 수신기(`1532:0550` 또는 `1532:0552`)를 사용하는 Barracuda X(2022); Barracuda Pro(`1532:053A`) | Razer 기능 보고서 프로토콜; BlackShark 제조사 프로토콜(V3 / V3 Pro / V3 X는 5분마다 조회); Barracuda X: 수신기를 통한 Airoha 배터리 및 케이블 쿼리 |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless(`1038:225D` 포함), Arctis Nova Elite(베이스 스테이션 `1038:2244`), GameBuds; Aerox 3/5/9 Wireless(Aerox 5 Diablo IV `1038:1860`, 미테스트), Aerox 3 Wireless CS2 Dragon Lore Edition(수신기 `1038:1878`, 케이블 `187A`), Aerox 3 Wireless Gen 2(수신기 `1038:1890`, 케이블 `1892`), Prime Wireless, Rival 3 Wireless(Gen 2), Rival 650, Rival Pro | 제조사 HID 보고서; Aerox/Prime과 Rival 650은 수신기와 USB 케이블 간에 하나의 항목을 공유하며, 둘 다 응답할 때는 케이블 측정값을 우선 사용 |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 무선; Bragi 기기(Virtuoso, Void V2, HS80 MAX, 신형 Slipstream 수신기 `1B1C:2B00`을 포함한 Slipstream 마우스 및 키보드 — 예: Scimitar Elite SE Wireless, Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless(`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG(`1B1C:2B34`, 미테스트) | 제조사 HID 보고서, Bragi `GET`(읽기 전용), Compx 17바이트 배터리 프로토콜(읽기 전용) |
| **Cooler Master** | MM712, MM731 (2.4 GHz 동글 또는 USB 케이블) | 제조사 HID 상태 보고서 (읽기 전용) |
| **Press Play** | `7768:6434` 2.4 GHz 수신기의 ICARUS V2 Nearlink (90%에서 드라이버 실기 테스트 완료; 100% 및 90%에서 프로토콜 캡처) | `FFB2:0001`의 읽기 전용 출력 보고서 `06 05`; 응답 바이트 14에 배터리 백분율 포함 |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless(HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight(PS용 `03F0:0C8C`, 미테스트), Cloud Flight S, Cloud Stinger Core Wireless(DTS `03F0:0A8E` 포함, 테스트 완료), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless(2.4 GHz 동글), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini(2.4 GHz 동글)(2.4 GHz 동글 `03F0:0F98` 테스트 완료; `0D97` 미테스트) | 제조사 HID 보고서 (Haste 2: [프로토콜 노트](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | 제조사 기능 보고서 |
| **Hitscan** | Hyperlight X, Hyperlight N | 제조사 기능 보고서 (Glorious와 동일한 프로토콜) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, Pulsar 및 ATK VXE 무선 마우스(예: VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2(수신기 `3554:F512`) | 체크섬이 포함된 응답을 사용하는 공용 제조사 프로토콜 |
| **Pulsar X2 V3** | 1K 동글(`3710:5402`) 또는 USB 케이블(`3710:3402`)의 X2 V3; 8K 동글(`3710:5403`) 또는 USB 케이블(`3710:3406`)의 X2 V3 eS | 64바이트 제조사 기능 보고서, 배터리 레지스터 `08 81 01` (읽기 전용) |
| **ATK / VXE NK** | NK mouse NANO 동글(`373B:1216`)의 VXE R1 NK 및 기타 NearLink 마우스 | `FF05:0001`의 ATK BITMOUSE 출력 보고서 08 (배터리 및 충전 상태) |
| **ATK 8K Nano** | ATK 8K Nano Dongle(`373B:1178`)의 ATK / VXE 마우스 | `FF10:0001`의 Holtek GetConfigData(`82`) 기능 보고서 (ATK HUB 기반; 배터리 및 충전 상태) |
| **ATK 헤드셋** | ATK N9 Pro, N9 Ultra (1세대) | 가상 COM 포트 프로토콜 (ATK 데스크톱 앱을 닫아야 함) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK 및 해당 8K 동글 | 모델에 따라 Glorious 또는 Kysona 프로토콜 사용 |
| **Keychron 마우스** | 2.4 GHz 수신기의 M4 및 기타 Keychron 마우스; Keychron 4K Link 수신기(`3434:D038`)의 4K 마우스(M4 4K, M3 4K, M3 mini 4K, M6 4K ...); TurboLink 8K 수신기의 8K 마우스(M5 8K, G6 HE 8K ...); Ultra-Link 8K 수신기(`3434:D028`)의 8K 마우스; 1K 수신기(`3434:D030` / `D031`)의 구형 마우스(M1, M2, M3, M3 mini, M6, M7 ...); Link-KM 수신기 또는 케이블의 Nape Pro 트랙볼 | Keychron Launcher 기반 제조사 보고서 (1K 수신기: Keychron 데스크톱 앱이 사용하는 기능 보고서 51 06; Ultra-Link 8K: `FFC1`의 보고서 B5 03 / B3 06; Nape Pro: Raw HID A7 31) |
| **Keychron 키보드** | Keychron Link 수신기(`3434:D030`) 또는 USB 케이블의 K5 Max(`3434:0A50`, 테스트 완료); 동일한 패치로 빌드된 기타 Keychron QMK 무선 키보드 | `FF60:0061`의 Raw HID: `B2`로 수신기에 연결된 키보드를 조회하고, `A4`로 잔량·전압·충전 상태를 수신. **패치된 키보드 펌웨어 필요:** [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware) 참고. 순정 펌웨어는 블루투스로만 보고 |
| **CHERRY** | 2.4 GHz 동글(`046A:00EA`, 테스트 완료) 또는 USB 케이블(`046A:00E3`, 테스트 완료)의 MX 3.0S Wireless 키보드 | `FF1C:0092`의 제조사 HID 쿼리 `1A`(읽기 전용) 및 USB 전원 공급 상태. 블루투스는 기본 블루투스 지원으로 처리 |
| **CHERRY** | 1K 수신기(`046A:0330`, 테스트 완료)의 Cherry XTRFY 무선 마우스 | CompX 17바이트 배터리 프로토콜(`08 03` 연결 상태, `08 04` GetPower), Corsair Sabre V2 Pro와 동일한 프레이밍(읽기 전용) |
| **Arbiter Studio** | Akitsu(`373E:000A` 8K 수신기, `373E:0009` 케이블), Akitsu 3950(`373E:0039` 8K 수신기, `373E:0038` 케이블), Akitsu Medium(`373E:0067` 8K 수신기 및 `373E:0066` 케이블, 둘 다 테스트 완료) | Arbiter Web HUB 기반 `FFFF:0000`의 읽기 전용 제조사 기능 보고서 `0x83` (배터리 및 충전 상태) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (케이블, 1K 및 4K/8K 동글) | LAMZU Aurora 기반 제조사 기능 보고서 |
| **Endgame Gear** | 4K 동글의 OP1w 4k(v1 / v2), XM2w 4k(v1 / v2); 기본 수신기(`3367:1961`)의 XM2we | 제조사 기능 보고서 `A1`, 배터리 명령 `B4` (읽기 전용) |
| **ATK / VGN / Evision 키보드** | 공용 2.4 GHz 수신기(`320F:5088`) 또는 USB 케이블(`320F:5055`)에 연결되며 제품명으로 식별되는 ATK V75X 및 VGN / VXE 키보드(S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87); `320F:5088` 수신기 이름이 "Wireless Gaming Keyboard"인 키보드 — 예: Feker Alice80(테스트 완료) | Evision 출력 보고서 `04`, 배터리 명령 `1A`(ATK HUB 및 VGN HUB 기반); 수신기를 통해 최대 10분마다 한 번씩 질의 |
| **Redragon (Evision)** | `320F:226F` 2.4 GHz 수신기의 K1NG M999(테스트 완료); 이 수신기 ID는 다른 모델에서도 공유될 수 있음 | ATK 키보드와 동일한 Evision 프로토콜(`FF1C:0092`의 보고서 `04`, 명령 `1A`)로 매 폴링마다 질의; 자석 충전 독에서 충전 표시; USB 케이블 연결 시 수신기가 이전 잔량을 계속 반복하며 충전 상태는 보고되지 않음 |
| **Audeze** | USB 동글(`3329:4B19`) 또는 USB-C 케이블(`3329:4B1A`)의 Maxwell; USB 동글(`3329:4B29`, 테스트 완료)의 Maxwell 2; Xbox용 ID는 미테스트 | 제조사 보고서 `06` / 입력 보고서 `07`, 배터리 속성 `0CD6` (단일 읽기 전용 쿼리) |
| **ENDORFY** | 2.4 GHz 동글(`3738:0072`, 미테스트)의 Viro Wireless | 제조사 보고서 `06` / 입력 보고서 `07`의 Airoha RACE "get battery"(`0CD6`), Audeze 및 Skullcandy 동글과 동일한 읽기 전용 쿼리; 충전 상태 없음 |
| **Turtle Beach** | USB 송신기(`10F5:2251`, HaloBattery에서 테스트 완료; PC 버전 `10F5:2262`, 미테스트) 또는 헤드셋 전용 USB 케이블(`10F5:2253`)의 Stealth 700 Gen 3 | Swarm II와 동일하게 RACE `0x9942`(CoAP 클라이언트 활성화) 및 RACE `0x9902` 내부에 터널링된 CoAP `GET /GSI` 사용; 키 `240`에서 배터리 읽기(충전 플래그 없음) |
| **AKG** | USB 동글(`0ECB:20D9`, 테스트 완료)의 N9 Hybrid | `FF13:0001`의 Airoha RACE: 출력 보고서 `06`, 입력 보고서 `07`, 배터리 속성 `0CD6` (단일 읽기 전용 쿼리) |
| **NZXT** | 동글(`1E71:2101`) 또는 USB 케이블(`1E71:2129`)의 Lift Elite Wireless | 제조사 읽기 명령 `4E 02 81 .. B0` (NZXT CAM 패킷 캡처 기반) |
| **Poly / Plantronics** | BT600 어댑터(`047F:02EE` / `02F7`)에 연결된 Voyager 8200 UC 및 기타 헤드셋 | 보고서 `07` get/set 프로토콜, 배터리 항목 `0A 1A` (읽기 전용) |
| **WLMouse** | YING Magnesium(YING 8K 수신기 `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K(수신기 또는 케이블; Beast X 4K 제외); Beast X V2(8K 수신기 `36A7:A856`); Beast G(8K 수신기 `36A7:A860` 또는 케이블 `36A7:A861`; 미테스트) | 제조사 기능 보고서, 상태 명령 `0x83` (YING: Glorious와 동일한 프로토콜) |
| **Finalmouse** | 2.4 GHz 동글(`361D:0100`, 테스트 완료)의 UltralightX; 동글(`361D:0300` / `0301`, 테스트 완료)의 Starlight X. 마우스 자체 케이블 연결 시에는 미지원 | `FF00`의 xpanel 제조사 보고서: 읽기 전용 GET 요청 후 *wake/all*(`0xE0`); xpanel 곡선 기반 배터리 전압 또는 Starlight X 자체 백분율과 충전 상태 |
| **VAXEE** | VAXEE 4K 수신기(`3057:1002`) 또는 8K 수신기(`3057:2002`, 예: NP-01 Ergo Wireless 8K)의 무선 마우스; USB 케이블(`3057:1011`)의 ZYGEN NP-01S V2 Wireless | `FF05:0001`의 읽기 전용 제조사 기능 보고서 `0E`; 5% 단위 배터리 잔량, 충전 상태 ([프로토콜 노트](#sec-vaxee)) |
| **Scyrox** | 2.4 GHz 수신기(`395A:0006`)의 V12M | `FF00:0002`의 S-Center 2.0 프로필 읽기(출력 보고서 `08`, 명령 `01`); 배터리 잔량만 지원, 충전 상태 없음 |
| **HECATE** | G5M PRO 및 동일 수신기의 기타 HECATE 마우스, USB 케이블 `35BB:D3FA / D3FC / D3FD` | Kysona 프로토콜 |
| **Redragon** | Compx 기반 무선 마우스: M916 Pro 1K(테스트 완료), M913 Impact Elite(트라이 모드), G49(수신기 또는 케이블) | Kysona 프로토콜 (Areson `25A7` 수신기는 아래 Areson 항목에 표시) |
| **Taidu (钛度)** | Compx 2.4 GHz 수신기 `3554:F5D5`의 TSG808 (테스트 완료) | Kysona 프로토콜 |
| **Areson (Redragon)** | `25A7:FA07` / `FA08` 수신기의 M915RGB-WL(테스트 완료), 오리지널 M913 Impact Elite 및 기타 마우스 | 17바이트 `GetPower` 기능 보고서; 10% 단위 잔량과 충전 플래그 |
| **Ninjutso** | 1K 수신기(`1915:AE1C`, 테스트 완료) 또는 USB 케이블(`1915:AE11`, 테스트 완료)의 Sora V2; Ten Air(수신기 `093A:EB01` 및 USB 케이블 `093A:E020`, 테스트 완료) / Ten(`093A:EB01` / `E020`, 미테스트) | NinjaForce 기능 보고서 `0x05`(Sora V2용 `0x15`) 및 `0x06`(Ten / Ten Air용 `0x13`/`0x12`/`0x11`) |
| **Sprime** | 2.4 GHz 수신기(`1915:AC1C`, 테스트 완료; `1915:AD8C`) 또는 USB 케이블의 PM1 | Sprime 웹 드라이버(sprime.pro) 기반의 동일한 기능 보고서 0x05, 상태 명령 0x15 |
| **RAWM / SADES** | RAWM HS Receiver(`1915:2346`, 테스트 완료)의 Leviathan V4; RAWM 수신기(`1915:232A`–`234B`) 또는 USB 케이블의 ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* 및 SADES Dagger 마우스 | 수신기를 통한 RAWM HUB 2.0 기기 정보 쿼리(배터리 % 및 충전 상태가 포함된 JSON), 읽기 전용 ([프로토콜 노트](#sec-rawm)) |
| **AULA** | 2.4 GHz 수신기의 F75 / F87 Pro / F99 무선 키보드 | 보고서 0x13 프레임, 명령 0x4A, 합계 체크섬 (블루투스 및 유선 모드는 미테스트) |
| **AULA 마우스** | AULA-8K Dongle `320F:22A0`의 X9 Ultra(테스트 완료); 수신기 ID는 V9 모델과 공유 | `FF1C:0092`에서 START `01` / END `02` 사이의 보고서 `04`, 읽기 전용 배터리 명령 `1A`; 2.4 GHz 전용 |
| **SONiX 키보드 (AJAZZ / AULA / EPOMAKER)** | `05AC:024F` 2.4G 동글의 AJAZZ AK820 MAX(테스트 완료), EPOMAKER EA75(테스트 완료), AULA F108 Pro; `0C45:FEFE` 동글의 AJAZZ AK980 V2; `0C45:FDFD` 또는 `0C45:FEFE` 동글의 AJAZZ AK820 Pro; `342D:E479`의 EPOMAKER P75(실기 미테스트) | 사용 페이지 FF60의 제조사 보고서 `20 01`, 합계 체크섬 (2.4G 모드 전용; 충전 표시 없음) |
| **추가 SONiX 수신기 (실기 미테스트)** | RK Royal Kludge R75(`342D:E485`); Redragon Arlokks K742B(`342D:E4BC`); M1 V5 VIA(`342D:E4C2`); Lucky65V2(`342D:E407`); Lofree Flow2(`388D:0003`); MSI FORGE TKL W FRIEREN EDITION(`0DB0:0CA0`); Essential75(`36B0:30BD`); NUT65(`342D:E51A`); RK 2.4G Dongle(`342D:E487`); WEIKAV MAX102(`342D:E537`); Lofree Flow2(`388D:0002`); NuPhy Air75V2(`19F5:3245`); SKN Qinglong(`362D:D028`); Lemokey Link(`362D:D030`); Wireless Link(`362D:D101`); Spade65-QMK-2.4GHz(`342D:E49F`) | 동일한 배터리 전용 `20 01` 쿼리; 정확한 VID:PID와 33바이트 보고서를 갖춘 FF60:0061 컬렉션 필요; 2.4G 전용, 충전 표시 없음 |
| **36B0 키보드 (PMO / WOBKEY / URX / EVO80)** | `36B0:3002` 2.4G 동글 또는 USB 케이블 `36B0:3009`의 PMO (WOBKEY) Wave 75 RGB(#343 제보자가 둘 다 프로토콜 테스트 완료); 동일 동글 또는 케이블의 Aurora 80(`3004`), PMO P75(`302B`), PMO 80(`3012`)(미테스트); 동글의 URX Core75(HaloBattery에서 확인됨); EVO80(미테스트) | PMO Hub 펌웨어: pmohub.cn 기반 사용 페이지 FF60의 `START_COMM` / `GET_BATTERY`(`AA 30`) / `STOP_COMM`. URX / VIA 펌웨어: HaloBattery를 통한 URX HUB 기반 VIA custom-get `08 00 07`(채널 0, 값 7). 충전 표시 없음 |
| **DAREU** | `260D:1074` 2.4 GHz 수신기 또는 `260D:1090` USB 케이블의 EM901X (둘 다 배터리 측정 테스트 완료; 수신기 독 거치/해제 충전 플래그 전환 테스트 완료) | 배터리 전용 기능 보고서 `08`, 명령 `04`; 별도 제조사 컬렉션의 응답 `09`. 제품 ID별로 명확히 단일한 입력/기능 쌍이 필요. 둘 다 연결된 경우 유효한 USB 측정값을 우선하며, 수신기는 마우스가 꺼져 있어도 캐시된 텔레메트리를 반환할 수 있음 |
| **DAREU** | A84 키보드(`260D:0022`, 미테스트) | 인터페이스 0의 SONiX 기능 보고서, 명령 `04 F6`(공식 A84 드라이버의 배터리 읽기 명령); 백분율 잔량, 충전 플래그 없음 |
| **DAREU** | `260D:1131` 멀티 마우스 수신기 및 USB 케이블(`260D:1148`)의 A980 Pro (실기에서 배터리 잔량 테스트 완료; 케이블 연결 중 충전 플래그 확인 완료) | Togran 프로토콜: 소비자 제어 컬렉션의 65바이트 기능 보고서 `0A`; 슬롯 쿼리(클래스 0 / `A0`) 후 배터리 쿼리(클래스 7 / `80`), 케이블 연결 시 슬롯 0 사용. 읽기 전용 |
| **Sharkoon** | `260D:1125`의 Skiller SGM50W (미테스트) | DAREU EM901X와 동일한 Compx 쿼리(`FF01:0000`의 기능 보고서 `08`, 명령 `04`, 응답 `09`); Sharkoon의 펌웨어 업데이터 역시 VID `260D` 기반 Compx 도구임 |
| **Zenith** | `260D:1114` 2.4 GHz 수신기(배터리 측정 테스트 완료; 충전 미테스트) 또는 `260D:1143` USB 케이블(미테스트)의 Zenith Pro | `FF02:0002`의 출력 보고서로 동일한 Compx 명령(`08`, `04`) 전송; 같은 컬렉션에서 백분율·충전 플래그·밀리볼트(mV)가 포함된 응답 `08 04` 수신, `0x55` 바이트 합계로 검증 |
| **AJAZZ AK992** | Telink 2.4 GHz 수신기 `320F:50C3` (테스트 완료) | HID 컬렉션 `FF1C:0092`의 EVision 배터리 쿼리 |
| **ZOWIE** | 2.4 GHz 수신기의 EC1/EC2/EC3-CW, DW 시리즈(U2-DW, S2-DW ...) 및 U2 | 커뮤니티에서 문서화된 읽기 전용 제조사 명령 |
| **Royal Kludge (RK)** | 2.4 GHz 동글(`2E3C:00A6` / `00E6`) 또는 USB 케이블(`2E3C:00A5` / `00E5`)의 MG6 Pro | RK 웹 드라이버 기반 QiWang 64바이트 프레임, `GET_BATTER_VOL` 읽기 (백분율, 전압, 충전 상태) |
| **ASUS ROG** | Strix Scope II 96 (RX), Azoth, Falchion 키보드; Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact 마우스; Pelta 헤드셋(2.4 GHz 동글); Cetra Open Wireless 이어버드(SpeedNova 동글 `0B05:1CAC`, L / R / 케이스); Omni Receiver | ROG HID 배터리 쿼리 |
| **Machenike** | `248A:FF4C` 2.4 GHz 수신기 또는 `248A:FF4E` USB 케이블의 L7 Arctic / L7 Mix (둘 다 테스트 완료) | 읽기 전용 기능 보고서 `51`, 상태 명령 `06`; 배터리 및 충전 상태. [프로토콜 노트](#sec-machenike) |
| **MSI** | 2.4 GHz 동글(`0DB0:9E22`)의 VERSA 300 ELITE WIRELESS; CLUTCH GM31 Lightweight Wireless(2.4 GHz 수신기 `0DB0:0D3C` 테스트 완료; USB 케이블 `0DB0:0D3B`) 및 CLUTCH GM41 Lightweight Wireless(수신기 `0DB0:0D4C` / 케이블 `0DB0:0D4B`, 소유자 캡처 기반) | `FF0D:00B0` 및 `FF00:0001`의 읽기 전용 제조사 쿼리 `0F 20`; 한 바이트에 배터리 및 충전 플래그 포함(MSI Center의 Gaming Gear 모듈 기반 프로토콜); GM41: `FF10:0006`의 수동 `A0 xx 07 …` 보고서 |
| **MCHOSE** | 2.4 GHz 수신기 또는 USB 케이블의 L7 / L7 Pro / L7 Ultra(L7 Ultra 테스트 완료), M7 / M7 Ultra, A7 / A7 Ultra, K7 마우스; A5 V2 Ultra(2.4 GHz 수신기 `3837:100C`, 테스트 완료), K7 Ultra(2.4 GHz 수신기 `3837:1001`, 테스트 완료; A7 V2 Ultra+ `3837:100B` 동작 예상, 이슈 227); G3 V2(2.4 GHz 수신기 `3837:4245` 및 USB 케이블 `3837:418C`); 2.4 GHz 수신기 `3837:1014` 또는 USB 케이블 `3837:4028`의 K7 V2 Ultra+(둘 다 테스트 완료; 기타 신형 패밀리 수신기 ID `1018`, `1016`, `102C`, `102D`는 미테스트) | 반전 페이로드가 적용된 제조사 기능 보고서(alexfrih/mchose-linux 기반 프로토콜); Realtek `3837` 동글은 vid 필드를 `41E4`(A5 V2 Ultra) 또는 `3837`(K7 Ultra)로 설정해 동일한 쿼리에 응답; G3 V2: `FF01:0010`의 읽기 전용 제조사 쿼리; K7 V2 Ultra+: `FF01:0001`의 64바이트 보고서 `0x4D`, 기기 정보 명령 `0x0900`(M HUB 웹 드라이버 기반 프로토콜) |
| **MCHOSE A5 (1세대)** | 1K 또는 4K 2.4 GHz 수신기(`2023:F013`, `2023:F015`, `2023:F018`) 또는 USB 케이블(`2023:F017` A5 Pro, `2023:F019` A5 Pro Max)의 A5 Pro / A5 Pro Max; 여기서는 미테스트 | `FFFF`의 64바이트 기능 보고서에 담긴 읽기 전용 배터리 명령 `0x83`(페이지 0), `0xA1`로 표시된 응답 (z750sasr A5 Pro Max 웹 드라이버 및 HaloBattery 기반 프로토콜, ID는 Klegus/mchose-macos 출처) |
| **MCHOSE 헤드셋** | 2.4 GHz 동글(`3837:6011`, 테스트 완료)의 V9 Pro 2 | `FF07:0222`의 M HUB 읽기 전용 "MC" 배터리 프레임(보고서 `0x55`, 하위 명령 `0x0B`); 한 바이트에 배터리 및 충전 플래그 포함 (M HUB 웹 드라이버 기반 프로토콜) |
| **AULA / MCHOSE / Redragon 키보드** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 및 기타 M HUB 키보드; 2.4 GHz 수신기(`3554:FA09`, `41E4:2001`)의 Redragon Horus Pro / Pro V2(K618RGB-PRO); `05AC:024F` 수신기의 MCHOSE K87(SONiX가 아닌 인터페이스 1의 BY 레이아웃) | 보고서 0x13 프레임, 명령 0x4A (MCHOSE 및 Redragon 모델은 M HUB와 같이 명령 0x05로 식별); 블루투스 및 유선 모드는 미지원 |
| **MCHOSE 키보드** | 2.4 GHz 수신기 `3837:3033`의 G75 V2 (테스트 완료); G87 V2 및 K99 V3도 동일 수신기 사용(동일 프로토콜, 미테스트); K87S는 같은 수신기 ID에 다른 프로토콜을 사용하므로 미지원 | ID 없는 64바이트 `0001:0000` 컬렉션의 M HUB 읽기 전용 "GLW" func-config 쿼리: 요청 플래그 `0x55`, 명령 `0x05`, 페이로드 바이트 32에 배터리(비트 7 = 충전 중), 가산 체크섬 |
| **AULA SC580** | USB 케이블(`088D:062E`, 테스트 완료) 또는 2.4 GHz 수신기(`089D:062F`, 테스트 완료)의 SC580 / SC580X 마우스 | 33바이트 제조사 컬렉션 FF02:0000의 읽기 전용 명령 `0x30`(기기 정보), 합계 체크섬; 충전 중에는 마우스가 고정값 100을 보고하므로 마지막 측정 잔량을 표시; 블루투스 모드는 미지원 |
| **AULA HERO 68 Air** | 8K Wireless Receiver(`372E:106C`)의 HERO 68 Air | 사용 페이지 FF60의 확인 응답형 20바이트 프레임(메시지당 데이터 프레임 4개와 트레일러 1개), 읽기 전용 배터리 명령 0x87, 잔량 뒤의 충전 플래그 0x10; 블루투스 및 유선 모드는 미지원 |
| **EWEADN (前行者)** | "Gaming 2.4G" 수신기(`372E:103D`)의 S7 Max / Pro / Ultra 및 S9 Max / Pro / Ultra / Ultra+; USB 케이블(`372E:1027`)의 S9 Ultra | EWEADN 웹 드라이버 기반 `FF00:0001`의 읽기 전용 기능 보고서 `03`: 연결 확인 `47`, 기기 기본 정보 `4F 81` (배터리 백분율 및 충전 비트) |
| **Rapoo VT** | VT3 Max Gen 2(테스트 완료); VT9 Gen 2(테스트 완료); 동일한 상태 인터페이스를 노출하는 기타 Nordic 54L VT 마우스; 구형 VT3 Pro(실험적); VT1 Pro Max(소유자의 USB 캡처 기반) | `FF00:0002`의 수동 HID 상태 보고서 `07`(16 또는 19바이트; 일부 VT3 Max Gen 2 수신기에서는 13바이트); 구형 `BB`는 VT3 Pro `1215/4415` 및 VT1 Pro Max `1233/4433`으로 제한. 수신기 및 USB 케이블, 충전 상태 포함 |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro(Xenta 모델 30/50; 구형 3D), Delux M800 Pro, Ajazz AJ179 계열; 3151 수신기의 AJ159 및 기타 AJ 시리즈 마우스; AJ139 V2 MC(`A8A5:2255` 수신기, `A8A4:2255` 케이블) | 제조사 보고서 (M900 Pro: 수동 상태 브로드캐스트 또는 기능 쿼리, Xenta 이벤트 40/41; AJ 시리즈: 0xF7 상태 폴링 후 기능 보고서 0x05) |
| **Incott** | G23 V2 / G24 (`093A:522C` 수신기, `093A:622C` 케이블) | 읽기 전용 상태 기능 보고서 09 |
| **Attack Shark 및 기타 중국 브랜드** | Rongyuan 수신기(81개 모델: `3151:402D`의 Attack Shark R3 및 AJAZZ AJ179 Pro, K86, X82 PRO HE, Ajazz 키보드, 일부 MSI 등; 블루투스로 연결된 K86은 키보드로 표시됨); Xenta 수신기(Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; `1D57:FA61`의 X6도 포함, 미테스트); Semico 1A2C 키보드(`1A2C:8FFF` 동글(테스트 완료) 및 `1A2C:A034` 케이블의 Attack Shark X98; `1A2C:8FFF` / `1A2C:A036`의 AJAZZ AK820 Max Plus) | Rongyuan 상태 보고서; Xenta 수동 브로드캐스트; Semico 읽기 전용 `0x0E` 상태 쿼리(`FF02:0002`의 `AA 55 CC 33`; X98이 배터리 사용 중과 충전 중 모두 `state=1`을 보고하므로 충전 플래그는 생략) |
| **Wraith** | W1 / W1 Freestyle (`093A:522C` 수신기, `093A:622C` 케이블; Incott와 동일한 ID이며 모델 코드로 구분) | 모든 버튼에 대한 읽기 전용 버튼별 읽기 `86`(기능 보고서 09) 후 푸시된 상태 입력 보고서 09 |
| **Fantech** | Helios Go XD5(유선 `25A7:FA7B`, 동글 `25A7:FA7C`); 공용 `1EA7:0066` / `1EA7:0064` 동글의 Raigor III(테스트 완료), Raigor II WG10 및 기타 일반 2.4G Mouse 기기 | Helios Go XD5: 제조사 기능 보고서 `08`, 명령 `04`, 합계 `0x55` 체크섬. Raigor/2.4G Mouse: `FFB5:0001`의 읽기 전용 `B5` 상태 페이지 쿼리, 청크 `94` = 마지막 보고 백분율(절전, 전원 꺼짐 또는 충전 중에는 오래된 값일 수 있음; 충전 상태 없음) |
| **Sony** | DualShock 4, DualSense, DualSense Edge(USB, 블루투스, 무선 어댑터); INZONE H9 II 및 H5 헤드셋; INZONE Buds(USB-C 동글) | 입력 보고서; INZONE 제조사 프로토콜 |
| **Fractal Design** | 2.4 GHz 동글 또는 USB-C 케이블의 Scape 헤드셋 | Fractal의 Adjust Pro 웹 앱 기반 제조사 `GET_DEVICE_STATE` 쿼리 (사용 페이지 FF00) |
| **Jabra** | 전용 USB 케이블 또는 Jabra Link 동글 뒤에서 GN 프로토콜을 지원하는 모든 Jabra 헤드셋(Evolve2 / Evolve3 등); 제품 ID 목록 없이 동적 인식, DECT 베이스(Engage, PRO 9xx, GO 6400, Link 400)는 제외; 이름은 헤드셋에서 읽어옴 | 사용 페이지 FF00, 사용량 05 또는 01, GNP 주소 08(USB) 또는 04(동글)의 GNP 상태 쿼리(클래스 12 / op 02) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro(`37D7:2401`), 2.4 GHz 수신기 또는 USB; Apex 5(`37D7:2501`), 2.4 GHz 수신기 또는 USB | `FFA0:0001`의 제조사 HID 정보 쿼리; 0–5 배터리 단계를 20% 단위의 0–100%로 매핑하며 충전 상태 지원; Space Station 서비스 불필요 |
| **GameSir** | 2.4 GHz 수신기의 Nova Lite, Nova 2, Nova 2 Lite; USB의 Nova 2 Lite; Xbox(GIP) 모드의 G7 Pro(테스트 완료: Zenless Zone Zero 에디션, 수신기 `3537:105E`) 및 기타 GameSir 패드; Cyclone 2(XInput 모드, 수신기 또는 케이블); 2.4 GHz 동글(`3537:1015`)의 Cyclone Pro(Windows와 블루투스로 1회 페어링 필요) | 제조사 기기 정보 쿼리(사용 페이지 FF7A); Xbox 모드의 Windows.Gaming.Input 배터리 보고서(실제 %); Cyclone 2: 제조사 배터리 요청(사용 페이지 FFF0); Cyclone Pro: 블루투스 LE(서비스 `0x8650`)를 통한 GameSir 앱 기본 정보 요청, 2분마다 읽기 |
| **BEITONG** | 2.4 GHz 수신기(`20BC:5128`, XInput 모드, 테스트 완료)의 KP20 / BTP-KP20 및 수신기(`20BC:515C`, XInput 모드)의 KP40D / BTP-KP40D; BEITONG iControl 불필요 | 사용 페이지 `00FF`의 제조사 "get base info" 쿼리(보고서 `02`, 니블 단위 스크램블 페이로드), 충전 상태 포함 |
| **8BitDo** | Ultimate 2 Wireless(2.4 GHz 동글에서 X-input `2DC8:310B` 테스트 완료, D-input `2DC8:6012` — B 버튼을 누른 채 전원 켜기, 펌웨어 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | 제조사 HID 상태 쿼리(`FF7A`/`FFA0`) 및 SDL 게임패드 입력 보고서 `01`/`04`, 충전 상태 포함 |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (블루투스) | 이어버드가 Samsung의 RFCOMM(SPP) 서비스로 푸시하는 상태 프레임, 읽기 전용. 트레이에는 더 낮은 쪽 이어버드가 표시되며 도구 설명에는 왼쪽, 오른쪽, 케이스가 표시됨. Galaxy Buds 앱을 닫아 두어야 함 |
| **Nothing / CMF** | Nothing Ear (3a)(테스트 완료), Ear (a), Ear (2), Ear, CMF Buds (블루투스) | Nothing의 NT Link RFCOMM 서비스(`aeac4a03-dff5-498f-843a-34487cf133eb`)의 읽기 전용 `0xC007` 배터리 쿼리. 트레이에는 더 낮은 쪽 이어버드가 표시되며 도구 설명에는 왼쪽, 오른쪽, 케이스가 표시됨 |
| **Akko** | Akko Air 01(`3151:5006`, 2.4 GHz 수신기, 테스트 완료) 및 Akko V9 Dash Pro(`38EE:000C`, 2.4 GHz 수신기, 테스트 완료) | Air 01: Rongyuan `0xF7` 상태 보고서; V9 Dash Pro: `FF1C:0092`의 읽기 전용 64바이트 `0x1A` 상태 쿼리, 충전 상태 포함 |
| **MOONDROP** | 2.4 GHz 동글(`35D8:0133`)의 GM01 Pro 헤드셋; USB 케이블 연결 시 마지막 잔량과 함께 충전 중으로 표시 | 보고서 `4B`의 WalkPlay 제조사 읽기 명령 (읽기 전용) |
| **VGN** | 2.4 GHz 동글(`372E:10BB`, 테스트 완료)의 OMNISOUND(ZHOUTING) 헤드셋 | V HUB "ZHOU" 쿼리: 제어 컬렉션 `000C:0001`(32바이트 입력, 64바이트 출력 보고서)의 페이로드 `65 01`을 담은 출력 보고서 `55`; 응답에 백분율 포함 (읽기 전용) |
| **JBL** | Quantum 650 Wireless(테스트 완료, 2.4 GHz 동글); Quantum 520, 650X, 850, 950, 950X Wireless(동글 또는 USB 케이블, 동일 프로토콜, 미테스트) | 배터리 기능용 JBL "HIDV3" 기기 정보 쿼리(사용 페이지 FF12), 충전 상태 포함 |
| **JBL** | Quantum 350 Wireless(`0ECB:206B` 2.4 GHz 수신기로 Windows에서 테스트 완료); Quantum 610 Wireless(`0ECB:205C` 2.4 GHz 동글, Windows에서 미테스트); Quantum 360 Wireless(`0ECB:2115` 2.4 GHz 동글, 미테스트) | 무선 연결 및 배터리 백분율용 HIDV1 기능 보고서 |
| **Xbox** | Xbox 무선 어댑터, USB 또는 블루투스 연결 컨트롤러; 컨트롤러에 연결된 헤드셋 | Windows.Gaming.Input 배터리 보고서(실제 %), XInput 폴백 |
| **Switch Pro 호환** | `057E:2009`로 인식되는 컨트롤러 (테스트 완료: Switch 모드에서 2.4 GHz 수신기로 연결한 GameSir Tarantula Pro) | Steam Input 또는 다른 호스트가 전체 보고서를 활성화한 후 HID 보고서 `0x30`의 5단계 배터리 잔량 |
| **Apple AirPods / Beats** | AirPods Max(테스트 완료, `200A` Lightning 및 `201F` USB-C), AirPods Pro 3(테스트 완료, `2027`), AirPods Pro 1 / 2, AirPods 1–5 및 Beats 헤드폰/이어버드 | 페어링된 모델과 매칭되는 BLE "근접 페어링"(`0x07`) 브로드캐스트(AirPods Max 및 Beats 헤드폰은 단일 배터리; 이어버드는 왼쪽·오른쪽·케이스를 10% 단위 및 충전 상태와 함께 표시) |
| **휴대전화 (휴대폰과 연결)** | Wi-Fi 또는 블루투스로 Microsoft 휴대폰과 연결(Phone Link)에 연결된 모든 Android 휴대전화 (테스트 완료: Nothing Phone (4a) Pro) | 휴대폰과 연결의 Windows 11 시작 메뉴 카드(`StartMenuCompanion.json`)에서 배터리 및 충전 상태 읽기; 블루투스 불필요 |
| **Darmoshark** | Windows에서 2.4 GHz 수신기로 연결된 M3(`248A:FF30`) 및 M3S(`248A:FF31`) | 마우스 식별 및 배터리용 HID 기능 보고서 |
| **Darmoshark** | Nordic 1K 수신기(`1915:0723`)의 M3S Pro | `FF0A` 컬렉션의 제조사 HID 상태 쿼리 |
| **Alienware** | 2.4 GHz 동글(`413C:A515`, 테스트 완료)의 AW920H 헤드셋; 블루투스 연결 시에는 아래 블루투스 항목으로 처리 | `FF13:0001`의 제조사 쿼리 `06 C0 0A`, XOR 체크섬이 포함된 응답 보고서 `07`; Alienware Command Center의 AW920H 플러그인 방식으로 잔량, 충전 및 위험 수준 필드 디코딩 |
| **Niceboy** | 2.4 GHz 수신기(`248A:FA02`, 테스트 완료)의 MW400 | 읽기 전용 보고서 `05` 쿼리 `24 FA 48`; 제조사 앱 테이블을 사용해 배터리 전압을 10% 단위로 매핑, 충전 플래그 지원 |
| **블루투스** | *설정 → Bluetooth 및 장치*에 배터리가 표시되는 모든 기기(이어버드, 헤드폰, BLE 마우스 및 키보드). Google Fast Pair 이어버드(Jabra Elite 8 Active 테스트 완료; Pixel Buds 및 다수의 Sony / JBL / Bose 모델)는 왼쪽, 오른쪽, 케이스 잔량도 지원 | Windows 장치 속성; Fast Pair 배터리 브로드캐스트(BLE 서비스 데이터 `FE2C`)를 블루투스 주소로 페어링된 기기와 매칭 |
| **일반 HID** | 표준 HID *Battery Strength* 사용량을 보고하는 기기 | HID 사용 페이지 0x06 / 0x85 |
| **HeadsetControl** | [HeadsetControl이 지원하는 모든 헤드셋](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, 신형 Logitech 등) | 기본 내장; `headsetcontrol -o json` 실행 |
| **MAONO PD200W** | 2.4 GHz 수신기 (`352F:040E`) | 배터리 백분율; 실기 테스트 완료 |


**실기 하드웨어에서 테스트 완료:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless(PlayStation 수신기 `0951:1713`; 충전 미테스트), HyperX Cloud Core Wireless DTS(수신기 `0951:173F`; 완충 수치 미테스트), HyperX Pulsefire Haste 2 Core Wireless(동글 `03F0:0AB5`; Haste 2 Wireless 동글은 미테스트), Cooler Master MM712(동글), Rapoo VT3 Max Gen 2(수신기 `24AE:1417` 및 USB 케이블 `24AE:4617`; 기타 Rapoo 모델은 미테스트, [Rapoo 프로토콜 노트](#sec-rapoo) 참고), Redragon M916 Pro 1K(수신기 `3554:F55D`), Taidu TSG808(수신기 `3554:F5D5`), Redragon M915RGB-WL(수신기 `25A7:FA07`; 기타 Areson 모델은 미테스트, [Areson 프로토콜 노트](#sec-areson) 참고), SteelSeries Rival 650 Wireless(수신기 `1038:1726` 및 USB 케이블 `1038:172B`), SteelSeries Arctis Nova Pro Wireless(베이스 스테이션 `1038:225D`; 배터리 읽기 테스트 완료, 충전 및 전원 전환 미테스트), HECATE G5M PRO(수신기 `35BB:D3FB`), WLMouse YING Magnesium(8K 수신기 `36A7:A874`), ATK N9 Ultra(수신기 `373B:1204`), Corsair Scimitar Elite SE Wireless(Slipstream 수신기 `1B1C:2B00`), Corsair Dark Core RGB Pro SE(Slipstream 수신기 `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight(2.4 GHz 수신기 `1B1C:2B2A`; 배터리 읽기 검증 완료), DAREU EM901X(수신기 `260D:1074`; 충전 및 절전/해제 미테스트), Link 390(`0B0E:2E51`)의 Jabra Evolve3 75, MCHOSE G3 V2(수신기 `3837:4245` 및 USB 케이블 `3837:418C`), MCHOSE K7 Ultra(수신기 `3837:1001`), MCHOSE K7 V2 Ultra+(수신기 `3837:1014` 및 USB 케이블 `3837:4028`; 케이블 연결 중 충전 표시 확인), MSI VERSA 300 ELITE WIRELESS(동글 `0DB0:9E22`; 충전 및 절전 처리 미테스트), MSI Clutch GM31 Lightweight Wireless(수신기 `0DB0:0D3C`; GM41은 소유자의 캡처 기반 동일 드라이버 사용), AJAZZ AK820 MAX(동글 `05AC:024F`), AULA HERO 68 Air(8K Wireless Receiver `372E:106C`), AULA SC580(USB 케이블 `088D:062E` 및 수신기 `089D:062F`, 충전 및 절전 포함), AirPods Pro 3(블루투스, 모델 `2027`), AirPods Max(블루투스, 모델 `200A`), Sprime PM1(수신기 `1915:AC1C`), Ninjutso Ten Air(수신기 `093A:EB01` 및 USB 케이블 `093A:E020`), MOONDROP GM01 Pro(동글 `35D8:0133`), Delux M800 Pro(수신기 `248A:5B2F`), Razer Barracuda X (2022)(수신기 `1532:0550`; 배터리 잔량 읽기 완료, 충전 전환 미테스트), Razer BlackShark V3 X(HyperSpeed 동글 `1532:057D`), Fantech Helios Go XD5(동글 `25A7:FA7C`), Fantech Raigor III(동글 `1EA7:0066`; 펌웨어에서 충전 상태 미보고), Finalmouse UltralightX(동글 `361D:0100`), Finalmouse Starlight X(동글 연결), Chimera V2(수신기 `3554:F512`; 배터리 잔량 및 충전 읽기 완료).
추가 실기 테스트 완료: Machenike L7 Arctic / L7 Mix(`248A:FF4C` 수신기 및 `248A:FF4E` 케이블), 충전 및 케이블/수신기 중복 제거 포함. 블루투스와 저전력/완충 경계값은 실기 미테스트.
추가 실기 테스트 완료: MCHOSE V9 Pro 2(`3837:6011` 동글); 배터리 잔량 읽기 완료, 충전 및 절전 미테스트.
추가 실기 테스트 완료: `05AC:024F` 2.4 GHz 수신기의 EPOMAKER EA75([PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60)의 기존 SONiX 드라이버 사용). 배터리 백분율, 수신기 재연결, 전원 켜짐 복구 검증 완료. 이 드라이버는 충전 표시 및 유선 배터리 보고를 지원하지 않으며 블루투스 배터리 보고는 테스트되지 않았습니다. USB 전원이 연결되면 보고되는 백분율이 100%로 뛸 수 있어 신뢰할 수 있는 충전 지표로 사용할 수 없습니다.
추가 실기 테스트 완료: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition(수신기 `1038:1878` 및 USB 케이블 `1038:187A`), 충전, 전원 끄기(마지막 잔량이 흐리게 유지됨), SteelSeries GG 실행 중 동작 포함; GG는 3단계 막대만 표시하며 측정된 잔량과 일치했습니다.
추가 실기 테스트 완료: RAWM Leviathan V4(RAWM HS Receiver `1915:2346`; 배터리 잔량 읽기 완료, 충전 미테스트).
**프로토콜 문서 및 타 프로젝트 기반으로 구현되었으나 아직 미테스트:** Fantech Raigor II WG10(테스트된 Raigor III와 동일한 `1EA7:0066` 동글 및 컬렉션을 사용하므로 동작할 것으로 예상)을 포함한 나머지 모든 기기. 이 중 하나를 보유하고 계시다면 [이슈를 열어](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues) 동작 여부를 알려 주세요.

## 설치

[![최신 버전](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. [최신 릴리스](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)에서 **`BatteryHub-Setup-<version>.exe`**를 다운로드합니다.
2. 실행한 뒤 지원하는 19개 설치 언어 중 원하는 언어를 선택하고 다음 단계를 따라 진행합니다. **관리자 권한이 필요하지 않으며** 런타임, 드라이버, 제조사 앱 등 **별도 설치도 필요 없습니다**. HeadsetControl이 기본으로 포함되어 있고, 편집 가능한 `lang\` 폴더가 `BatteryHub.exe` 옆에 설치됩니다.

설치 프로그램은 시작 메뉴 항목과 제거 프로그램(*설정 → 앱*)을 추가하며, Windows 로그인 시 앱을 자동 실행하도록 설정할 수 있습니다. 설치 없이 사용하고 싶다면 `BatteryHub-<version>-portable.zip`을 내려받아 원하는 위치에 압축을 풀고(`lang\` 폴더를 `BatteryHub.exe` 옆에 그대로 두어야 UI 번역이 적용됩니다) `BatteryHub.exe`를 실행하세요.

**참고:**
- **SmartScreen 경고:** 실행 파일에 코드 서명이 되어 있지 않아 Windows에서 "Windows의 PC 보호" 경고가 뜰 수 있습니다. *추가 정보 → 실행*을 클릭하거나 소스에서 직접 빌드하세요.
- **Windows 11 트레이 아이콘 모드:** 새로 추가된 트레이 아이콘은 `^` 오버플로 영역으로 들어갑니다. 아이콘을 작업 표시줄로 끌어다 놓거나 *설정 → 개인 설정 → 작업 표시줄 → 기타 시스템 트레이 아이콘*에서 켜세요.
- **특정 기기를 앱에서 제외하기:** 앱 실행 중 오동작하는 기기가 있다면 `HKCU\Software\WirelessBattery` 아래의 문자열 값 `IgnoreDevices`에 `VID:PID` 쌍을 16진수, 쉼표 구분 형식으로 등록하세요(예: `28BD:0947, 1234:ABCD`; `--dump`에서 ID를 확인할 수 있습니다). 그러면 앱이 해당 기기를 열지 않습니다. 그래픽 태블릿은 자동으로 건너뜁니다.

## Windows 업데이트

공식 안정화(stable) Windows 빌드는 앱 시작 30초 후, 이후 실행 중인 동안 24시간마다 백그라운드에서 프로젝트의 최신 안정화 릴리스를 확인합니다. 메뉴를 열면 **업데이트 가능: vX.Y.Z...**가 표시되거나, 직접 **업데이트 확인...**을 선택할 수 있습니다. 업데이트 정보는 이 메뉴에만 표시되며 배터리 아이콘, 백분율, 도구 설명은 그대로 유지되고 자동 확인 시 알림이나 대화 상자를 띄우지 않습니다. 백그라운드 확인을 끄려면 메뉴에서 **자동으로 업데이트 확인**을 해제하세요.

설치형 버전의 경우 업데이트 항목을 클릭하고 **다운로드 및 설치**를 누릅니다. 클릭하기 전에는 아무것도 설치되지 않습니다. 앱은 해당 릴리스의 `SHA256SUMS.txt`와 서명을 내려받아 앱에 내장된 메인테이너 공개 키로 서명을 검증한 뒤, Windows 설치 프로그램을 다운로드하고 서명된 목록(및 GitHub에 표시된 값)과 SHA-256이 일치할 때만 설치 프로그램을 실행합니다. 그런 다음 기존 설치를 업데이트하며, 설정과 시작 프로그램 선택 상태가 유지되고 설치 후 앱이 다시 실행됩니다. 전체 사용자용 설치인 경우 관리자 권한을 요청할 수 있습니다. **릴리스 노트**는 공식 릴리스 페이지를 열고, **나중에**는 현재 버전을 유지합니다. 포터블 버전은 ZIP을 수동으로 내려받을 수 있도록 릴리스 페이지를 안내합니다.

업데이트 확인은 계정이나 토큰 없이 GitHub 공개 API에 접속하며, 기기 정보나 배터리 정보는 전혀 전송하지 않습니다. 오프라인 오류나 GitHub 요청 제한이 발생해도 배터리 모니터링은 중단되지 않으며, 이미 찾은 릴리스 정보는 새 확인이 이를 대체하거나 설치가 완료될 때까지 메뉴에 남아 있습니다. 다운로드를 취소하면 현재 진행 중인 네트워크 작업이 유한 시간 초과를 마칠 때까지 대기합니다. 설치 프로그램은 Windows를 자동으로 다시 시작하지 않습니다.

**업데이트를 안전하게 설치할 수 있는 이유:** 서명 키는 절대 GitHub에 올라가지 않습니다. 메인테이너가 자신의 PC에서 각 릴리스의 체크섬 목록에 직접 서명하므로([docs/releasing.md](#sec-releasing) 참고), 누군가 GitHub 계정이나 빌드 워크플로를 탈취하더라도 앱이 설치를 허용하는 업데이트를 게시할 수 없습니다. 유효한 서명이 없는 릴리스는 메뉴에 표시되더라도 수동으로만 다운로드할 수 있습니다. 다만 이 서명이 Windows 자체의 SmartScreen이나 UAC 프롬프트를 대체하지는 않습니다.

이 기능이 포함된 첫 릴리스는 한 번 수동으로 설치해 주세요. 개발/테스트 빌드에서는 로컬 변경 사항이 실수로 덮어쓰이지 않도록 공식 업데이트 확인이 비활성화되어 있습니다. Linux용 업데이트 및 포터블 버전의 자동 교체 기능은 추후 지원 예정입니다.

## 명령줄

```
BatteryHub.exe --list     # print every device and its battery level, then exit
BatteryHub.exe --json     # print a JSON array of devices and battery levels, then exit
BatteryHub.exe --dump     # every HID collection, HID devices that could not be opened, all USB devices (also ones
                               # without a HID interface) and Bluetooth devices; also saved to %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # open the "Request support for a device" window
BatteryHub.exe --demo     # sample devices of every brand instead of real ones (screenshots, checking colors)
BatteryHub.exe --quit     # close the running instance
```

Linux 빌드는 `BatteryHub.exe` 대신 `wireless-battery`로 동일한 플래그를 사용하며 `--help`도 지원합니다. `--json`은 스크립트와 상태 표시줄 위젯이 파싱할 수 있는 안정적인 JSON 배열을 출력합니다:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec`는 기기가 절전 상태인 동안 앱이 마지막으로 알려진 잔량을 계속 표시하는 시간(초)입니다. 새 필드가 추가되더라도 하위 호환성이 유지됩니다.

**기기가 표시되지 않나요?** 위젯이나 트레이 아이콘을 마우스 오른쪽 버튼으로 클릭하고 **기기 지원 요청...**을 선택하세요. 기기를 고른 뒤 전송될 내용(기기 이름, 유형, USB/HID ID 및 인터페이스 구조, 선택 사항인 이름과 추가 정보가 글자 그대로 표시됩니다)을 확인하고 **보내기**를 클릭하면 [krisgfx.com/tools](https://krisgfx.com/tools/#requested)의 공개 목록에 등록되고 GitHub 이슈가 생성되거나 업데이트됩니다. **전체 보고서 복사**를 누르면 이슈에 붙여넣을 수 있도록 전체 `--dump` 결과가 클립보드에 복사됩니다. 보고서 데이터는 **보내기**를 클릭할 때만 전송됩니다. 공식 Windows 빌드는 [Windows 업데이트](#windows-업데이트)에 설명된 대로 업데이트 확인을 위해 GitHub에 접속할 수도 있으며, 업데이트 확인 시에는 기기나 배터리 정보를 전송하지 않습니다.

## 빌드

[MSYS2](https://www.msys2.org/) 등을 통해 [MinGW-w64](https://www.mingw-w64.org/)가 필요합니다 (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # development build, version 0.0.0
build.bat                                 # plain cmd with g++ and windres on PATH
make VERSION=1.2.3 CHANNEL=test            # versioned build, official updates disabled
build.bat 1.2.3 test                       # equivalent versioned cmd build
make test VERSION=1.2.3 CHANNEL=test       # device and updater regression tests
```

설치 프로그램과 포터블 ZIP을 빌드하려면 [Inno Setup](https://jrsoftware.org/isinfo.php)을 설치하고 먼저 원하는 버전으로 빌드한 뒤(예: `make VERSION=1.2.3 CHANNEL=test`), `powershell -File installer\build-installer.ps1 -Version 1.2.3`을 실행하세요. 패키징 스크립트는 실행 파일과 버전이 다르면 빌드를 거부합니다. 이 스크립트는 고정된 HeadsetControl 릴리스를 내려받아 체크섬을 검증합니다. GitHub Actions는 이 모든 과정을 자동으로 수행하며, `v1.0.0`과 같은 태그를 푸시하면 설치 프로그램, 포터블 ZIP, HeadsetControl 소스 코드(GPL 라이선스 요구 사항 준수)가 포함된 릴리스가 게시됩니다.

Windows 빌드에서는 공유 실행 파일/리소스 버전을 생성하기 위해 PowerShell도 필요합니다. 공식 저장소의 버전 태그는 `CHANNEL=stable`로 빌드되며, 로컬 빌드는 기본값이 `dev`입니다. 포크와 Pull Request에서는 공식 업데이트가 자동으로 활성화되지 않습니다.

`BatteryHub.exe` 단독으로도 실행됩니다. 옆에(또는 `PATH`에) `headsetcontrol.exe`가 없으면 추가 헤드셋 지원만 제외됩니다.

## Linux (실험적 기능)

Windows 앱과 함께 Linux 빌드도 제공됩니다. hidraw 기반 HID 백엔드와 GTK4 StatusNotifierItem 트레이 아이콘으로 동일한 제조사 드라이버들을 사용하며, Windows 코드 경로는 변경되지 않습니다. Linux 전용 파일은 모두 `linux/` 및 `src/linux/`에 있고 `build-linux.sh`로 빌드합니다(Windows는 계속 `build.bat` 사용).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| 컴파일러 및 make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

별도의 HID 라이브러리는 필요하지 않습니다(hidraw 직접 사용).

```sh
./build-linux.sh
./build-linux.sh test         # unit test for the HID report-descriptor parser
./wireless-battery --list     # print detected levels and exit
./wireless-battery --dump     # list HID collections
./wireless-battery --quit     # close the running tray instance
```

HID 접근에는 udev 규칙이 필요하며, 규칙이 없으면 앱이 시작되더라도 기기를 찾지 못합니다:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# log out and back in
```

트레이 아이콘은 KDE Plasma에서 기본 동작하며, GNOME에서는 `gnome-shell-extension-appindicator` 같은 AppIndicator 호스트가 필요합니다. 다국어 전환은 *언어* 하위 메뉴에서 동작합니다(기본적으로 `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG`를 따르며 `--help`도 현지화됨). `make -f linux/Makefile.linux install`을 실행하면 바이너리, `$(PREFIX)/share/wireless-battery/lang/` 아래 `lang/*.json`, 그리고 `$(PREFIX)`(기본값 `~/.local`) 아래 데스크톱 실행기(`linux/wireless-battery.desktop`)와 `linux/wireless-battery.svg`가 설치됩니다. 사용자 언어 재정의 파일은 `~/.config/wireless-battery/lang/`에 저장됩니다.

1단계는 Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious, Finalmouse 및 공용 Kysona/Pulsar/ATK/G-Wolves 프로토콜을 지원합니다. 블루투스/UPower 폴백, HeadsetControl 및 나머지 제조사는 후속 단계로 예정되어 있습니다.

## 제한 사항

- **혼잡한 작업 표시줄:** 가운데 정렬된 Windows 11 작업 표시줄에 앱 버튼이 아주 많이 차면 작업 표시줄 버튼이 위젯 위치까지 닿을 수 있습니다. Windows 10에서는 작업 버튼 영역이 자동으로 줄어듭니다.
- **휴대전화:** 시작 메뉴 동반자 카드용으로 휴대폰과 연결(Phone Link)이 작성하는 파일에서 읽어 오므로 공식 문서화된 API가 아니며 휴대폰과 연결 업데이트에 따라 바뀔 수 있습니다. 휴대폰과 연결이 연결됨으로 보고하는 동안 표시되며, 3시간이 지난 카드는 흐리게 표시됩니다. 카드에 충전 중 정보가 있으면 충전 번개 아이콘으로 표시됩니다.
- **절전 중인 기기:** 절전 상태의 기기는 응답하지 않을 수 있으며 마지막 값이 흐리게 유지됩니다. Logitech 수신기는 절전 중인 기기를 링크에서 제거하므로 마지막 값을 30분 동안 유지합니다.
- **HECATE G2 Wireless 7.1 헤드셋** (2.4 GHz 동글 `35BB:A009` / `A209`): 동글용 배터리 쿼리가 아직 문서화되지 않아 읽을 수 없습니다. HECATE 소프트웨어가 헤드셋 배터리를 표시하는 동안 USB 패킷을 캡처해 공유해 주시면([CONTRIBUTING.md](#sec-contributing) 참고) 지원을 추가할 수 있습니다.
- **Keychron 키보드:** 순정 펌웨어에서는 블루투스로만 배터리를 보고합니다(블루투스 지원으로 표시됨). 2.4 GHz 수신기나 USB 케이블로 확인하려면 배터리 패치가 적용된 펌웨어가 필요하며([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)), Keychron Launcher로 키보드 펌웨어를 업데이트하면 패치가 제거됩니다. Keychron 마우스는 바로 지원됩니다.
- **Baseus AeQur GH02 헤드셋:** 2.4 GHz 동글(`10D6:4802`, Actions 칩)은 오디오, 미디어 키 및 칩 펌웨어 업데이트 채널만 전달하며 배터리는 전달하지 않습니다. 잔량을 확인하려면 헤드셋을 블루투스로 연결하세요(Windows가 보고하는 경우 블루투스 지원으로 표시됨).
- **Weikav Lucky65 v1 키보드:** 펌웨어가 2.4 GHz 동글(`0603:0351`, Novatek 칩)을 통해 배터리를 보고하지 않습니다. 키보드 자체 배터리 확인 단축키도 없고 공식 설정 도구도 동글이 아닌 USB 케이블로만 연결되므로 표시할 수 있는 배터리 측정값이 없습니다.
- **Rapoo:** 지원되는 VT 마우스는 상태를 푸시 방식으로 전송하므로 새로 고침 시 일치하는 인터페이스당 최대 4초까지 대기할 수 있습니다. 절전 중인 마우스는 마지막 측정값으로 최대 30분 동안 흐리게 유지될 수 있습니다. 지원 범위는 Nordic 54L 보고서 `07` 및 구형 `BB`(VT3 Pro, VT1 Pro Max)이며, CH584 보고서 `08`, 사무용 MT/M 시리즈 마우스 및 기타 펌웨어 프로토콜은 이 드라이버에서 지원하지 않습니다.
- **GameSir Cyclone Pro:** 동글이 배터리 잔량을 전달하지 않으므로 패드에서 블루투스 LE로 직접 읽어옵니다. Windows와 패드를 한 번 페어링한 뒤(설정 > Bluetooth 및 장치 > 장치 추가 > Bluetooth > `GameSir-Cyclone Pro`) 계속 동글로 플레이하면 됩니다. PC에 블루투스가 필요합니다. 잔량은 2분마다 새로 고침되며 충전 중에는 백분율이 표시되지 않습니다. 페어링하지 않으면 동글이 "가득 참" 상태의 Xbox 컨트롤러로 표시됩니다. 자세한 내용은 [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro)를 참고하세요.
- **RAWM:** 마우스가 수신기를 통해 질의되므로 절전 중인 마우스는 응답하지 않으며, 최대 30분 동안 마지막 측정값이 흐리게 유지되고 절전 중에는 새로 고침에 약 1초가 더 걸립니다. RAWM HS Receiver(`1915:2346`)의 Leviathan V4만 실기 테스트되었으며 다른 모델은 RAWM HUB 기기 테이블을 기반으로 합니다. Leviathan V4 GT 및 NYX60(VID `373E`, RAWM HUB 3.0)과 RAWM HS 키보드는 다른 프로토콜을 사용하므로 지원되지 않습니다.
- **Flydigi:** 이 드라이버는 Vader 5 Pro 및 Apex 5를 대상으로 하며 블루투스 연결 및 기타 Flydigi 모델(예: Apex 6)은 지원하지 않습니다. 백분율은 대략적인 배터리 단계를 나타냅니다. Apex 5는 2.4 GHz 수신기와 USB 케이블을 통해 실기 테스트되었고, Vader 5 Pro는 SDL 및 Windows 하드웨어 트레이스를 따릅니다.
- **아직 미지원:** VERSA 300 ELITE 및 CLUTCH GM31 / GM41 이외의 MSI 무선 마우스, MSI 무선 키보드, Razer Kraken 헤드셋 및 `1532:0550`의 Barracuda X (2022) 이외 Barracuda 모델, Haste 2 Wireless / Haste 2 Core Wireless 이외의 HyperX Pulsefire 마우스, Xbox 어댑터 연결 시의 Xbox Wireless Headset은 배터리 프로토콜이 문서화되지 않았습니다. Xbox Wireless Headset은 블루투스 연결 시 동작합니다. 실제 소유자가 USB 캡처를 제공해 주시면([CONTRIBUTING.md](#sec-contributing) 참고) 지원을 추가할 수 있습니다.
- **기타 기기:** 일부 2.4 GHz 기기는 미공개 프로토콜을 사용하므로 아직 지원되지 않습니다. 지원 추가에 도움을 주는 방법은 [CONTRIBUTING.md](#sec-contributing)를 참고하세요.

## 동작 원리

[`src/drivers/`](../../src/drivers)의 각 제조사 드라이버는 USB 제조사/제품 ID(VID/PID)로 기기를 식별하며 읽기 전용 배터리 쿼리만 전송합니다. 알 수 없는 기기에는 절대 쓰기 작업을 하지 않습니다. 일반 폴백 드라이버(HID 배터리 사용량, 블루투스, XInput, HeadsetControl)는 어떤 제조사 드라이버도 점유하지 않은 기기만 확인합니다.

작업 표시줄 위젯은 `Shell_TrayWnd`의 계층형 자식 창(layered child window)으로 `TrayNotifyWnd` 왼쪽에 배치됩니다. 탐색기(Explorer)가 다시 시작되면 자동으로 다시 생성됩니다.

## 번역

모든 UI 언어는 [`lang/`](../../lang) 폴더에 있는 일반 정적 UTF-8 텍스트 파일이며 왼쪽에 영어 원문, 오른쪽에 번역문이 들어갑니다. 언어 파일은 실행 파일에 컴파일되지 않고 런타임에 디스크에서 불러오므로 다시 빌드하지 않고도 직접 편집할 수 있습니다.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **앱 UI (Windows 및 Linux):**
  - `BatteryHub.exe` 옆의 `lang/` 폴더(Linux의 경우 `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/` 또는 `./lang/`) 안에 있는 `.json` 파일을 직접 수정하거나 추가할 수 있습니다.
  - 또는 메뉴에서 *언어 → 새 언어 추가...*를 선택하면 사용자 재정의 폴더(Windows: `%APPDATA%\WirelessBattery\lang`, Linux: `~/.config/wireless-battery/lang`)에 `_template.json`가 준비됩니다. `_template.json`를 예: `it.json`로 복사해 `@code`, `@name` 및 번역문을 채우면 메뉴에 바로 나타납니다(재시작 불필요). 사용자 폴더의 파일은 동일한 `@code`의 기본 내장 문구를 덮어씁니다.
  - `{placeholder}`는 그대로 유지하고 오른쪽에서 왼쪽으로 쓰는 문자는 `"@rtl": true`을 추가하세요. 비워 둔 문구는 영어로 표시되므로 일부만 번역해도 문제없이 동작합니다.
  - `--list`와 `--dump` 출력은 GitHub 이슈에 붙여넣기 위해 의도적으로 영어를 유지합니다.
- **Windows 설치 프로그램:** Inno Setup 번역 파일은 [`installer/lang/`](../../installer/lang)에 있으며(UTF-8 with BOM으로 저장) `installer/BatteryHub.iss`의 `[Languages]`에 등록됩니다.
- **문서:** 저장소의 모든 공개 문서는 [`docs/i18n/`](README.md) 안에 언어별 단일 독립형 Markdown 파일로 번역됩니다(빌드 스크립트 없이 새 언어를 추가하려면 [`docs/i18n/_template.md`](_template.md) 참고).
- **모두와 공유하기:** `lang/`, `installer/lang/`, `linux/wireless-battery.desktop`, `docs/i18n/`에 파일을 추가해 Pull Request를 보내 주세요. 단계별 체크리스트는 [`docs/i18n/README.md`](README.md)를 참고하세요.

## 크레딧

앱 아이콘 제작: [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

프로토콜 구현은 다음 프로젝트들의 연구를 바탕으로 합니다:

- [Google Fast Pair 사양](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): Fast Pair 이어버드의 왼쪽 / 오른쪽 / 케이스 배터리 브로드캐스트
- [HeadsetControl Astro 드라이버](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty), [AstroBar](https://github.com/nichtlegacy/AstroBar): Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 배터리 프로토콜; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): A50 Gen 3 `0x72` 상태 읽기

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): VAXEE 배터리 및 충전 명령 ([프로토콜 문서](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): SteelSeries, Corsair, HyperX, Logitech 및 Sony INZONE 헤드셋
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) 및 [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) 및 Logitech HID++ 2.0 문서: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) 및 [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (`0ADF` 동글)
- [rivalcfg](https://github.com/flozz/rivalcfg): SteelSeries 마우스 (Rival Pro는 pull request #294 기반)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) 및 [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Hitscan 웹 설정 도구 ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- Linux `hid-kysona` (Lode Willems): Kysona, Pulsar 및 ATK
- ATK 웹 설정 도구 ([hub.atk.pro](https://hub.atk.pro)): ATK 마우스 및 N9 Pro / N9 Ultra 헤드셋
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 및 [mouse-battery](https://github.com/qwr79/mouse-battery): ATK / VXE NK NANO 동글
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X 및 Endgame Gear XM2we (각 드라이버 파일에 출처 명시)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` 및 [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (조사 내용 참고): Turtle Beach Swarm II 기기 제품군
- G-Wolves 웹 드라이버 ([mouse.xyz](https://mouse.xyz)): G-Wolves 모델 및 프로토콜
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): 2.4 GHz 동글의 CHERRY 키보드 (프레임 형식 및 배터리 쿼리)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): Keychron 마우스
- [NinjaForce](https://www.ninjaforce.co/) 및 [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): Ninjutso Ten / Ten Air 기능 쿼리
- [nape_pro](https://github.com/nvalis/nape_pro) 및 [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Link-KM 수신기의 Keychron Nape Pro
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): LAMZU 마우스
- [vole](https://github.com/johanneszab/vole) 및 [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): Endgame Gear 4K 마우스
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) 및 [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) 및 [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (Finalmouse의 xpanel 기반)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) 및 [g49-web-control](https://github.com/pingpingjinping/g49-web-control): Redragon ID
- [m913-ctl](https://github.com/Qehbr/m913-ctl) 및 [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): Areson `25A7` 프레임 구조 및 `GetPower` 명령
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) 및 [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW 및 DW
- RK 웹 드라이버 ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) 및 [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (문서): MCHOSE A5 Pro / A5 Pro Max (1세대, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): Delux M900 Pro용 CompX 수신기 보고서
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) 및 [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) 및 [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- Wraith 웹 드라이버 ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 및 [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 및 [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) 및 [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): `1532:0550` 수신기의 Razer Barracuda X (2022); [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): `1532:0552` 수신기의 프레이밍
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): Rongyuan 및 Xenta 수신기 (Attack Shark 등)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): 2.4G 동글의 SONiX 키보드 (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) 및 [ak820-studio](https://github.com/usharik/ak820-studio): AJAZZ AK820 Pro 수신기 `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) 및 [Kraber](https://github.com/AkashPanja/Kraber): Attack Shark X98 및 AJAZZ AK820 Max Plus용 Semico `1A2C` (`AA 55 CC 33` / `0x0E`) 상태 프로토콜
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) 및 [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 및 MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) 및 [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): GameSir Cyclone Pro 블루투스 LE "base info" 배터리 요청
- [jabridge](https://github.com/Watchdog0x/jabridge): Jabra GNP 프로토콜 (Link 380 / 390 동글)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): `1EA7:0066` 상태 페이지 프로토콜 (Fantech Raigor III 및 기타 일반 2.4G Mouse 기기)
- Linux `hid-playstation`: DualShock 4 / DualSense 보고서 레이아웃
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): AULA SC580 / SC580X 제조사 프로토콜
- RAWM HUB 웹 앱 ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) 및 기기 테이블: RAWM 마우스 및 SADES Dagger
- [SDL의 Flydigi HID 드라이버](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) 및 [HaloBattery 이슈 #191](https://github.com/HeyOkay/HaloBattery/issues/191): Vader 5 Pro 및 Apex 5 쿼리 프레이밍과 배터리 레이아웃
- [SDL의 8BitDo HID 드라이버](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): 8BitDo Ultimate 2 배터리 바이트
- BEITONG iControl (KP20 및 KP40D 페이지와 KP20 수신기의 USB 트래픽): BEITONG KP20 / KP40D 배터리 쿼리 및 페이로드 스크램블링
- [SDL의 8BitDo HID 드라이버](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) 및 [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): 8BitDo 배터리 바이트 및 제조사 HID 프로토콜
- JBL QuantumENGINE (HIDV3 기기 정보 메시지): JBL Quantum 헤드셋
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, `FF02:0002`의 Compx 프로토콜
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) 및 [BrimDeck](https://github.com/MoFeng2223/BrimDeck): Scyrox V12M 프로필 읽기
- JBL QuantumENGINE: Quantum 350용 HIDV1 연결 및 배터리 보고서와 신형 Quantum 헤드셋용 HIDV3 기기 정보 메시지
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): JBL Quantum 610 HIDV1 배터리 및 링크 보고서와 Quantum 제품군 (HIDV1 동글 모델로서의 360 포함)

## 라이선스

[GNU General Public License v3.0 이상](../../LICENSE). 이 소프트웨어를 자유롭게 사용, 수정 및 재배포할 수 있지만, 이를 기반으로 파생된 결과물을 배포할 때는 동일한 라이선스로 소스 코드와 함께 공개해야 합니다.


---

<a id="sec-contributing"></a>
> 📄 **섹션:** 기여 가이드 (`CONTRIBUTING.md`) · [English 원문](../../CONTRIBUTING.md) · [↑ 맨 위로](#top)

# 기여하기

## 기기 동작 여부 제보하기

대부분의 드라이버는 프로토콜 문서를 바탕으로 작성되었기 때문에 모든 모델에서 직접 테스트할 수는 없었습니다. 다음 내용을 포함해 이슈를 등록해 주세요:

- 기기 이름 및 연결 방식 (수신기, 케이블 또는 블루투스)
- `BatteryHub.exe --list` 출력 결과
- `BatteryHub.exe --dump` 출력 결과
- 제조사 자체 소프트웨어에 표시되는 배터리 잔량

## 새 기기 추가하기

1. `BatteryHub.exe --dump`를 실행해 기기의 제조사/제품 ID(VID/PID)와 제조사 정의 컬렉션(사용 페이지 `FFxx`) 및 보고서 크기를 찾습니다.
2. 배터리 프로토콜을 확인합니다. 참고하기 좋은 곳: HeadsetControl, OpenRazer, Solaar, rivalcfg, OpenRGB, OpenLinkHub 또는 제조사 소프트웨어의 USB 패킷 캡처(Wireshark + USBPcap).
3. 해당 제조사 드라이버가 `src/drivers/`에 이미 있다면 제품 ID(및 차이점)를 추가합니다. 없다면 `src/drivers/<vendor>.cpp`를 새로 만듭니다:

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

4. `src/drivers/drivers.h`에 함수를 선언하고 `src/devices.cpp`의 `PollAllDevices()`(일반 폴백 이전)에서 호출합니다. `build.bat`과 Makefile은 새 파일을 자동으로 인식합니다.
5. `README.md`의 기기 목록 표를 업데이트합니다.

### 드라이버 작성 규칙

- **읽기 전용:** 상태를 읽는 요청만 전송합니다. 설정, 조명, 모드를 절대 변경하지 마세요.
- **정확한 매칭:** 제조사/제품 ID 또는 해당 프로토콜에 고유한 제조사 전용 컬렉션으로 식별되는 기기와만 통신합니다.
- **항상 시간 초과 설정:** 연결되지 않은 기기가 폴링을 약 1초 이상 지연시켜서는 안 됩니다. 수동(passive) 프로토콜은 문서화된 푸시 주기를 포괄하기 위해 더 길게 기다려야 할 수 있습니다(예: Delux, Rapoo). 일치하는 컬렉션당 최대 4초의 단일 절대 마감 시간을 유지하고, 무관한 보고서 때문에 타이머를 재시작하지 않으며, 예외가 필요한 이유를 주석으로 문서화하세요.
- **출처 명시:** 파일 상단 주석에 프로토콜 출처를 인용하세요.

## 번역

UI 언어는 Windows와 Linux 모두에서 런타임에 디스크로부터 불러오는 일반 정적 UTF-8 텍스트 파일(`lang/`)입니다(`lang/_template.json`를 `lang/<code>.json`로 복사한 뒤 `@code`, `@name`, 문구를 채워 넣으면 되며 재빌드가 필요 없습니다). 코드에 새 UI 문구를 추가할 때는 `T(L"...")` 또는 값이 포함된 경우 `TF(L"... {name} ...", { { L"name", value } })`를 사용하세요. 조각난 문자열을 이어 붙여 번역 문장을 조립하지 마세요. 문구를 추가한 뒤에는 `lang/_template.json`에도 추가하세요.

Windows 설치 프로그램 번역은 `installer/lang/*.isl`(UTF-8 with BOM으로 저장 후 `installer/BatteryHub.iss`에 등록)에 있으며, Linux 실행기 설명은 `linux/wireless-battery.desktop`에, 전체 문서 번역은 `docs/i18n/<code>.md`(`docs/i18n/_template.md`에서 복사한 단일 독립형 파일)에 있습니다. 전체 기여자 가이드는 [`docs/i18n/README.md`](README.md)를 참고하세요.

## 코드 스타일

C++17, Win32 전용, 서드파티 의존성 없음. 바이너리 크기를 작게 유지하세요. 기존 코드 스타일(들여쓰기 공백 4칸, 한 줄 120자)을 따릅니다.

## Windows 업데이터 개발

업데이터는 Windows 전용이며 WinHTTP, BCrypt 및 기존 Inno Setup 설치 프로그램을 사용합니다. 업데이트 상태는 메뉴에만 표시하며, 업데이트 아이콘, 배지, 배터리 도구 설명 변경, 풍선 알림, 토스트, 자동 대화 상자를 추가하지 마세요. 기기 폴링은 네트워크 작업과 분리되어 실행됩니다.

빌드 버전과 채널은 생성되는 `build/version.h`를 통해 C++와 Windows 리소스가 공유합니다. 로컬 테스트에는 `make VERSION=1.2.3 CHANNEL=test` 또는 `build.bat 1.2.3 test`를 사용하세요. 기본값은 `dev`이며 `stable`은 공식 릴리스 확인을 활성화합니다. 버전 구성 요소는 0..65535 범위여야 합니다. 공식 저장소의 릴리스 태그 워크플로만 `stable`을 자동으로 선택합니다. 포크 빌드가 실수로 공식 업데이트 채널로 동작하지 않도록 주의하세요.

기존 기기 테스트와 엄격한 릴리스 파싱, 버전 정렬, 확인 예약, 실제 SHA-256 파일 검증, 인수 인용 및 도우미 가드를 실행하려면 `make test VERSION=1.2.3 CHANNEL=test`를 실행하세요. 업데이터 회귀 테스트는 다운로드 완료 시점의 취소, 대화 상자 가드, HTTP 시간 초과/리디렉션 제한 구성 실패도 검증합니다. Windows 테스트는 기존 Linux 백엔드 테스트 패턴을 따라 구현 파일을 포함하며, 테스트가 GitHub에 접속하지 않도록 HTTP 전송을 대체합니다. 프로덕션 코드에는 테스트 전용 컨트롤러 진입점을 추가하지 않습니다. 개별 타깃은 `make test-update-core`와 `make test-update-win`입니다. 네이티브 업데이터 테스트는 Common Controls v6를 활성화하기 위해 애플리케이션 리소스를 링크합니다. 테스트는 로컬 데이터를 사용하며 다운로드, 권한 상승, 설치 또는 사용자 시작 프로그램 설정을 변경하지 않습니다. 애플리케이션의 프로덕션 엔드포인트는 테스트를 위해 재정의할 수 없습니다.

패키징 전에 `powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`를 실행하세요. `installer/build-installer.ps1 -Version 1.2.3` 역시 의존성을 다운로드하기 전에 이 검사를 실행합니다. `/WBUPDATE=1` 설치 경로는 기존 시작 프로그램/설정을 보존하고 재실행을 임시 도우미에 맡깁니다. 해당 도우미는 원래 사용자 권한으로 유지되며 전체 사용자용 설치일 때만 권한 상승을 수행합니다. WinHTTP 핸들은 워커 스레드에 속하며 취소는 유한 시간 초과 호출 사이에서 협조적으로 처리됩니다. 최종 앱 종료 시 해당 워커를 조인하므로 진행 중인 네트워크 시간 초과를 기다릴 수 있습니다.

릴리스 검토 시에는 일회용 Windows 계정이나 VM에서 실제 설치 프로그램 두 개 버전, 사용자별/전체 사용자 범위, UAC 취소, 시작 프로그램 켜짐/꺼짐, 사용자 지정 경로, 설치 실패 및 재실행을 테스트하세요. 단위 테스트나 패키지 컴파일만으로는 이러한 설치 프로그램 동작을 검증할 수 없습니다. 시각적 메뉴/테마 검토와 실제 설치 프로그램/UAC 종단 간 점검은 수동 릴리스 게이트로 남아 있으므로, 실제로 관찰하지 않았다면 통과로 표시하지 마세요. 일상 사용 중인 설치본을 덮어쓰며 테스트하지 마세요.

## 자동 안전 검사

모든 Pull Request는 이 앱이 절대 해서는 안 되는 동작(네트워크 접근, 타 프로그램 실행, 키보드/클립보드/화면 읽기, 시작 프로그램 항목, 바이너리, 빌드 또는 릴리스 변경)을 검사하는 "PR safety check"를 거칩니다. 경고가 떴다고 해서 무조건 거절되는 것은 아니며, PR 설명에 표시된 줄의 이유만 설명해 주시면 됩니다.

AI 도구를 사용하는 것은 괜찮지만 커밋 메시지에서 AI 도구를 크레딧하는 `Co-authored-by` 줄(예: `Co-authored-by: Claude ...`)은 반드시 제거해 주세요. 이 줄이 남아 있으면 검사가 실패합니다.


---

<a id="sec-pr-template"></a>
> 📄 **섹션:** Pull Request 템플릿 (`.github/pull_request_template.md`) · [English 원문](../../.github/pull_request_template.md) · [↑ 맨 위로](#top)

## 추가되는 내용

<!-- 기기 및 제조사/제품 ID (예: "Acme M1 (1234:5678)"). -->

## 프로토콜 출처

<!-- 출처 링크 (다른 프로젝트, 제조사 웹 드라이버, 직접 캡처한 USB 패킷 등). -->

## 실기 하드웨어에서 테스트했나요?

<!-- 예 (어떤 기기인지, --list 출력 결과) / 아니요 -->

## 체크리스트

- [ ] 읽기 전용 배터리 쿼리만 전송하며 설정, 조명 또는 펌웨어를 변경하지 않음
- [ ] 제조사/제품 ID(또는 프로토콜 전용 컬렉션)로 식별되는 기기만 다룸
- [ ] 네트워크 접근 없음, 다른 프로그램 실행 없음, `src/`, `docs/` 또는 `README.md` 외 새 파일 없음
- [ ] 바이너리나 생성된 파일이 포함되지 않음
- [ ] 커밋 메시지에 AI 도구(Claude, Copilot, ChatGPT 등)를 크레딧하는 `Co-authored-by` 줄이 없음
- [ ] `.github/`, `installer/`, `build.bat` 또는 `Makefile` 변경 사항이 위에 설명되어 있음


---

<a id="sec-releasing"></a>
> 📄 **섹션:** 릴리스 (`docs/releasing.md`) · [English 원문](../../docs/releasing.md) · [↑ 맨 위로](#top)

# 릴리스

앱은 GitHub 릴리스에서 자체 업데이트를 수행하지만, 릴리스 키로 서명된 `SHA256SUMS.txt`에 SHA-256이 등재된 설치 프로그램만 설치합니다. 이 키는 GitHub가 아니라 메인테이너의 PC에만 보관되므로, 계정·토큰·워크플로가 침해되어 파일을 게시하더라도 앱이 허용하는 서명은 만들 수 없습니다.

## 최초 1회: 릴리스 키 생성

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- 암호(12자 이상)를 입력받아 암호화된 개인 키를 `%USERPROFILE%\.wirelessbattery\release-key.wbk`에 저장합니다.
- 공개 키를 `src\update_public_key.h`에 기록합니다. 이 파일을 커밋하세요. 공식 빌드는 이 파일에 키가 없으면 컴파일을 거부합니다.
- **키 파일을 백업하고 암호를 안전하게 보관하세요** (암호 관리자를 사용하는 것이 좋습니다). 둘 중 하나라도 분실하면 이미 설치된 앱들이 더 이상 자동 업데이트를 할 수 없으므로 새 키를 만들고 모든 사용자가 다음 릴리스를 수동으로 한 번 설치해야 합니다.

## 매 릴리스마다

1. 버전 태그를 푸시합니다 (`git tag v1.2.3 && git push origin v1.2.3`). CI가 설치 프로그램, 포터블 ZIP, `SHA256SUMS.txt`를 빌드해 릴리스를 게시합니다.
2. 체크섬 목록에 서명합니다:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   스크립트가 릴리스에서 `SHA256SUMS.txt`를 내려받아 내용을 표시하고 확인을 요청한 뒤 키 암호를 물어 `SHA256SUMS.txt.sig`를 생성합니다. `dist\`에 동일한 파일(해당 버전의 로컬 빌드)이 있다면 일치 여부도 보여 줍니다.
3. 릴리스에 `SHA256SUMS.txt.sig`를 업로드합니다(스크립트가 편집 페이지를 엽니다). 이때부터 앱에 **다운로드 및 설치**가 제공됩니다. 그전까지는 업데이트가 표시되더라도 릴리스 페이지 링크만 제공합니다.

반드시 본인이 직접 게시한 릴리스의 목록에만 서명하세요. 서명은 "이 파일들이 정확한 공식 릴리스임"을 보증하는 단계이므로 악의적인 업로드를 걸러내는 핵심 관문입니다.

## 키 교체

새 `-KeyFile` 인수를 지정해 `new-release-key.ps1`을 실행하면 `src\update_public_key.h`에 기존 키 옆에 새 공개 키가 추가됩니다. 두 키가 모두 포함된 버전을 기존 키로 서명해 릴리스한 다음, 그 이후 릴리스부터 새 키로 서명하고 나중에 이전 키를 제거하세요. 키를 분실했거나 유출된 경우에는 이 방식으로 폐기할 수 없으며, 헤더에서 해당 키를 제거하고 구버전 사용자들이 다음 릴리스를 수동으로 설치해야 합니다.

## 앱이 설치 프로그램 실행 전 확인하는 항목

- 해당 릴리스가 저장소의 최신 정식 릴리스이며(초안이나 시험판 아님) 현재 앱보다 새 버전인지 여부
- `SHA256SUMS.txt.sig`가 `src\update_public_key.h`에 있는 키로 서명된 `SHA256SUMS.txt`의 유효한 ECDSA P-256 서명인지 여부 (서드파티 코드 없이 Windows BCrypt 사용)
- 서명된 목록에 `BatteryHub-Setup-<version>.exe`가 정확히 한 번 명시되어 있고 GitHub가 보고한 SHA-256과 일치하는지 여부
- 내려받은 설치 프로그램의 크기와 SHA-256이 정확히 일치하는지 여부. 앱의 복사본이 실행 직전에 이를 다시 검증하며, 중간에 파일이 바뀌지 않도록 파일을 잠근 상태로 유지합니다.
- 다운로드는 `github.com`, `objects.githubusercontent.com`, `release-assets.githubusercontent.com`에 대한 HTTPS만 사용하며 모든 리디렉션을 검증합니다.


---

<a id="sec-keychron-firmware"></a>
> 📄 **섹션:** Keychron 키보드 펌웨어 (`docs/keychron_keyboard_firmware/README.md`) · [English 원문](../../docs/keychron_keyboard_firmware/README.md) · [↑ 맨 위로](#top)

# 2.4 GHz 수신기를 통한 Keychron 키보드 배터리 확인

Keychron 순정 펌웨어는 블루투스로만 키보드 배터리를 보고합니다. [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch)에 포함된 간단한 QMK 변경 사항을 적용하면 키보드가 Keychron Link 수신기와 USB 케이블을 통해서도 배터리 쿼리(`A4`)에 응답하며, BatteryHub에서 잔량, 전압, 충전 상태를 표시할 수 있습니다.

**Keychron K5 Max ANSI RGB**(`3434:0A50`)와 Keychron Link 수신기(`3434:D030`) 조합에서 테스트되었습니다.

## 패치 변경 사항

[Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) `2025q3` 브랜치(커밋 `57e682c`) 기준:

- [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1)의 `KC_GET_BATTERY`(`0xA4`) Raw HID 명령을 추가합니다:
  응답 `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`;
- 무선 링크를 통해 도착하는 Raw HID 요청도 동일한 핸들러로 전달합니다;
- `keyboards/keychron/k5_max/config.h`에 `#define WILRESS_RAW_ENABLE`(Keychron 코드의 철자 그대로) 및 `#define KC_BATTERY_MODEL_ID 0`을 추가합니다.

키맵, 조명, Keychron Launcher 등 다른 기능은 모두 그대로 동작합니다.

## 방법 1: 미리 빌드된 K5 Max 펌웨어 플래싱

**K5 Max ANSI RGB 전용** 빌드가 [이 릴리스](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)에 첨부되어 있습니다(`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`). 다른 모델이나 배열에 플래싱하지 마세요.

## 방법 2: 직접 빌드하기

Git과 Docker(또는 동작하는 [QMK 환경](https://docs.qmk.fm/newbs_getting_started))가 필요합니다.

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

결과 파일은 저장소 루트의 `keychron_k5_max_ansi_rgb_keychron.bin`입니다. Windows에서는 바인드 마운트된 체크아웃이 Docker에서 매우 느리므로 컨테이너 내부(또는 WSL)에서 클론하면 훨씬 빠릅니다.

**기타 Keychron 무선 키보드** (`LK_WIRELESS_ENABLE`이 있는 `2025q3` 트리의 Q/V/K Max 및 기타 모델): `keyboards/keychron/common/` 아래 변경 사항은 그대로 적용됩니다. K5 Max 대신 본인 키보드의 `config.h`에 두 `#define` 줄을 추가하고 자신의 타깃을 빌드하세요(예: `make keychron/<model>/<layout>/<variant>:keychron`). 현재 앱은 K5 Max(`0A50`–`0A58`)는 모델명으로, 그 외 모델은 "Keychron keyboard"로 표시합니다.

## 플래싱

1. 모드 스위치를 **Cable**로 전환하고 USB 케이블을 분리합니다.
2. **Esc** 키를 누른 상태에서 케이블을 연결하면 키보드가 STM32 부트로더로 진입합니다.
3. [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases)(또는 `dfu-util`)로 `.bin` 파일을 플래싱합니다.
4. 스위치를 **2.4 GHz**로 되돌리고 `BatteryHub.exe --list`로 확인합니다:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Keychron Launcher에서 키보드를 업데이트하면 이 펌웨어가 덮어쓰여 배터리 보고 기능이 제거됩니다. 원래대로 되돌리려면 같은 방법으로 Keychron 공식 펌웨어를 플래싱하세요.

## 라이선스

QMK는 GPL-2.0-or-later이며 이 패치도 동일한 라이선스를 따릅니다. 이 패치로 빌드된 바이너리를 받는 사람은 누구든 이 소스 변경 내용도 함께 받을 수 있어야 합니다.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **섹션:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [English 원문](../../docs/gamesir_cyclone_pro.md) · [↑ 맨 위로](#top)

# GameSir Cyclone Pro 배터리 지원

## 컨트롤러가 가득 찬 Xbox 컨트롤러로 표시되던 이유

Cyclone Pro(모델 T4cp)는 `3537:1015` 2.4 GHz 동글을 통해 작동합니다. 이 동글은 Windows에 유선 Xbox 360 컨트롤러(XUSB, `Xbox 360 Controller for Windows`)로 인식됩니다. XInput이 배터리 쿼리에 항상 "Full"로 응답하기 때문에 XInput 폴백은 실제 잔량과 무관하게 `Xbox controller 1`을 100%로 표시했습니다.

동글 자체에는 배터리 정보가 없습니다:
- 유일한 HID 컬렉션이 XInput 게임 컨트롤러(`HID\VID_3537&PID_1015&IG_00`)입니다
- Nova(`FF7A`)나 Cyclone 2(`FFF0`) 같은 제조사 정의 컬렉션이 없습니다

## 배터리 잔량이 있는 위치

동글로 플레이하는 동안에도 패드는 블루투스 LE로 `GameSir-Cyclone Pro`를 광고하며, 이는 GameSir 모바일 앱이 사용하는 연결입니다. 이 연결의 "get base info" 요청이 배터리를 반환합니다:

| 항목 | 세부 내용 |
|---|---|
| 서비스 | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| 특성(Characteristic) | `0x865F` (notify, write without response) |
| 요청 | 알림(notifications) 활성화 후 `01 01` 쓰기 |
| 응답 | 19바이트 알림 (일부 펌웨어는 앞에 `C9`가 붙어 20바이트) |

응답 구조:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

바이트 18은 백분율(0-100) 배터리 잔량이며, 충전 중일 때는 `FF`입니다. 충전 중에는 잔량이 보고되지 않으므로 마지막으로 알려진 백분율을 유지하고 충전 번개 아이콘을 함께 표시합니다.

패드에는 GameSir의 펌웨어 업데이트 채널인 `0xFF10` 서비스도 있지만 드라이버는 이를 절대 열지 않습니다. 패드에 표준 Battery Service(`0x180F`)가 없기 때문에 Windows 블루투스 페이지와 기본 블루투스 폴백에서도 잔량이 표시되지 않습니다.

출처: GameSir의 Android 앱(`BluetoothLeService`, "get base info")에서 프로토콜을 분석한 [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery).

## 드라이버 동작 방식

XInput 폴백보다 먼저 호출되는 `src/drivers/gamesir_ble.cpp`:

1. **패드 찾기.** `{00008650-0000-1000-8000-00805F9B34FB}` 클래스의 장치 인터페이스를 조회합니다. Windows는 페어링된 BLE 기기의 각 GATT 서비스마다 인터페이스를 생성합니다. 드라이버는 상위 `BTHLE\DEV_…` 노드 이름이 `GameSir-Cyclone…`인 것만 사용합니다.
2. **배터리 읽기.** Win32 GATT API(`bluetoothleapis.h`, `-lbluetoothapis`)로 해당 서비스를 열고 `0x865F`를 구독한 뒤 `01 01`을 씁니다. 최대 3초 동안 응답을 기다린 후 알림 구독을 다시 끕니다.
3. **폴링 속도 유지.** BLE 연결은 수 초가 걸리거나 패드 절전 중 시간 초과가 날 수 있으므로 별도 스레드에서 쿼리를 실행합니다:
   - 정상 읽기 후에는 최소 2분 간격, 실패 후에는 최소 1분 간격
   - 폴링은 캐시된 측정값을 보고하며, 측정 후 6분이 지나면 보고를 중단합니다
   - 이후 `graceSec` 동안 절전 상태로 흐리게 계속 표시됩니다
   - 실행 후 첫 번째 폴링에서만 최대 4초의 절대 마감 시간으로 스레드를 한 번 대기하므로 시작 시와 `--list`에서도 잔량이 표시됩니다
4. **가짜 Xbox 항목 숨기기.** 동글이 연결되어 있으면 드라이버가 `3537:1015`를 점유합니다:
   - Windows.Gaming.Input 경로는 이제 점유된 제조사/제품 ID를 건너뜁니다
   - XInput 경로는 `XInputGetCapabilitiesEx`(xinput1_4 서수 108)로 각 슬롯의 제조사/제품 ID를 얻어 점유된 항목을 건너뜁니다
   - 해당 내보내기 함수가 없는 경우 XInput은 기존과 동일하게 동작합니다

## 테스트된 하드웨어

2026-11-18, Windows 11, 블루투스로 1회 페어링된 동글(`3537:1015`) 연결 Cyclone Pro:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

패드가 절전 중일 때는 "Xbox controller 1 / Full" 항목이 더 이상 나타나지 않았으며 패드에 대한 항목도 표시되지 않았습니다.

## 제한 사항

- **페어링:** 패드를 Windows에 한 번 페어링해야 합니다 (설정 > Bluetooth 및 장치 > 장치 추가 > Bluetooth > `GameSir-Cyclone Pro`). 페어링되지 않은 패드는 GATT 장치 인터페이스가 없습니다. 페어링하면 블루투스 게임패드 항목이 추가되지만 동글로 플레이하는 동안에는 입력을 보내지 않습니다.
- **블루투스 필수:** PC에 블루투스 LE가 있어야 합니다.
- **패드 1대 제한:** PC당 Cyclone Pro 한 대만 읽습니다.
- **충전:** 충전 중에는 백분율이 표시되지 않습니다.


---

<a id="sec-localization-guide"></a>
> 📄 **섹션:** 다국어 사용 및 현지화 가이드 (`docs/i18n/README.md`) · [English 원문](../../docs/i18n/README.md) · [↑ 맨 위로](#top)

# BatteryHub 다국어 색인 및 현지화 가이드

이 저장소의 모든 공개 문서는 `docs/i18n/` 안에 **언어별 단일 독립형 Markdown 파일**로 모여 있으며, 모든 런타임 애플리케이션 문자열은 [`lang/`](../../lang) 안의 **정적 편집 가능 텍스트 파일**(Windows와 Linux 공유)에, Windows 설치 프로그램 문자열은 [`installer/lang/`](../../installer/lang)에 있습니다.

## 지원 언어 (19개)

| 코드 | 언어 | 전체 문서 | 앱 UI (Windows & Linux) | Windows 설치 프로그램 |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (원본 문자열) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## 실제 환경에서의 언어 전환 동작

### 1. Windows 앱 (`BatteryHub.exe`)
- **자동 감지:** *언어 → 자동 (Windows 표시 언어)*로 설정하면 BatteryHub가 Windows `GetUserPreferredUILanguages`를 조회해 가장 잘 일치하는 정적 `*.json` 파일을 선택합니다.
- **수동 전환:** 작업 표시줄 위젯 또는 트레이 아이콘 클릭 → **언어** → 원하는 언어 선택. UI가 즉시 업데이트되며 `HKCU\Software\WirelessBattery\Language`에 저장됩니다.
- **정적 외부 파일 (재빌드 없이 편집 가능):** `BatteryHub.exe`는 먼저 `<exe>\lang\*.json`를 불러온 다음 `%APPDATA%\WirelessBattery\lang\*.json`를 불러옵니다. 사용자 폴더에 동일한 `@code`를 가진 파일이 있으면 일치하는 문구를 덮어쓰며, 메뉴를 다시 열면 디스크에서 파일을 실시간으로 다시 읽습니다.
- **CLI `--help`:** `BatteryHub.exe --help`는 현재 활성화된 UI 언어로 도움말 대화 상자를 표시합니다 (`--list`, `--json`, `--dump`는 GitHub 이슈 제보용으로 의도적으로 영어를 유지합니다).

### 2. Linux 앱 (`wireless-battery`)
- **자동 감지:** `LANGUAGE`(콜론 구분 목록) → `LC_ALL` → `LC_MESSAGES` → `LANG` 순서로 POSIX 로캘 변수를 따릅니다(`LC_ALL=C` / `POSIX`로 재정의된 경우는 제외).
- **수동 전환:** 트레이 아이콘 마우스 오른쪽 버튼 클릭 → **언어** → **자동 (시스템 언어)** 또는 설치된 언어 선택. `$XDG_CONFIG_HOME/wireless-battery/config.ini`(기본값 `~/.config/wireless-battery/config.ini`)의 `[general] language=` 아래에 저장됩니다.
- **정적 검색 경로 (우선순위 낮은 순 → 높은 순):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (기본값 `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (기본값 `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help`는 `config.ini` 또는 시스템 로캘에 따라 번역된 CLI 도움말을 출력하며, `--list`와 `--dump`는 영어를 유지합니다.

### 3. Windows 설치 프로그램 (`BatteryHub-Setup-<version>.exe`)
- Windows UI 언어로 미리 선택된 언어 선택창(`ShowLanguageDialog=yes`, `LanguageDetectionMethod=uilanguage`)을 표시합니다.
- 전체 정적 `lang\*.json` 디렉터리를 `BatteryHub.exe` 옆의 `{app}\lang\`에 설치합니다(포터블 ZIP에도 마찬가지로 `lang\*.json`가 포함됩니다).

---

## 새 언어 추가 또는 업데이트 방법 (단계별)

앱 UI나 문서를 번역하는 데는 빌드 도구가 **전혀 필요하지 않으며**, Windows 설치 프로그램을 테스트 컴파일하려는 경우에만 Inno Setup 6이 필요합니다.

### 1단계 — 앱 UI 문자열 (`lang/<code>.json`)
1. 트레이 메뉴(**언어 → 새 언어 추가...**)에서 사용자 언어 폴더를 열거나 [`lang/_template.json`](../../lang/_template.json)를 `lang/<code>.json`(예: `lang/it.json`)로 복사합니다.
2. 메타데이터 헤더를 채웁니다:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. 각 줄의 ` = ` 오른쪽에 번역문을 작성합니다.
   - `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}` 같은 자리 표시자는 글자 그대로 유지하세요.
   - 명시적 줄 바꿈에는 `\n`을 사용합니다.
   - **UTF-8 (BOM 없음)** 으로 저장합니다.
   - BatteryHub 트레이 메뉴를 다시 열면 재빌드 없이 바로 미리 볼 수 있습니다!

### 2단계 — Windows 설치 프로그램 (`installer/lang/<code>.isl`)
1. [`installer/lang/_template.isl`](../../installer/lang/_template.isl)을 `installer/lang/<code>.isl`로 복사합니다.
2. **중요:** 레거시 Windows 코드 페이지와 관계없이 Inno Setup이 유니코드 문자를 안정적으로 디코딩할 수 있도록 **UTF-8 with BOM (`EF BB BF`)** 으로 저장하세요.
3. 해당하는 방식을 선택합니다:
   - **Inno Setup에 이미 해당 언어가 기본 포함된 경우** (`C:\Program Files (x86)\Inno Setup 6\Languages\` 확인): `[CustomMessages]`만 남기고 6줄(`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser` — `%1` 및 `%n` 유지)을 번역합니다. `installer/BatteryHub.iss`의 `[Languages]` 아래에 등록합니다:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup에 해당 언어가 기본 포함되지 않은 경우**: `installer/lang/zh-CN.isl`을 전체 참고용으로 복사하고 `[LangOptions]`(`LanguageName`, `LanguageID`, `LanguageCodePage=0`, 선택 사항 `RightToLeft=yes`)를 설정한 뒤 `[Messages]`와 `[CustomMessages]`를 번역하고 `Default.isl` 뒤에 등록합니다:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - 참고: `[Languages]`의 `Name:` 식별자에는 ASCII 영문자, 숫자, 밑줄만 사용할 수 있습니다(`pt-BR` 대신 `ptBR` 사용).

### 3단계 — Linux 데스크톱 실행기 (`linux/wireless-battery.desktop`)
현지화된 `Comment[<code>]=...` 줄을 추가합니다(`.desktop` 파일의 지역 태그는 밑줄을 사용하세요. 예: `Comment[zh_CN]=...`).

### 4단계 — 단일 파일 전체 문서 (`docs/i18n/<code>.md`)
1. [`docs/i18n/_template.md`](_template.md)를 `docs/i18n/<code>.md`로 복사합니다(생성 스크립트가 전혀 필요 없으며 이 파일 하나만 있으면 됩니다!).
2. 목차와 17개 섹션 전체를 번역하되 다음 항목은 그대로 유지하세요:
   - 모든 `<a id="sec-..."></a>` 앵커 태그와 `<a id="top"></a>`
   - 모든 코드 블록, CLI 플래그(`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), USB `VID:PID`, HID 사용 페이지, 16진수 패킷, 레지스트리 키, 파일 경로, URL
   - 상대 이미지/파일 경로(`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE` 등)
3. `docs/i18n/<code>.md` 상단의 `<!-- lang-switcher:start -->` 바를 업데이트하고(자신의 언어는 굵게 표시하고 나머지는 링크), `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` 및 형제 `docs/i18n/*.md` 파일의 언어 전환 바에 새 언어 링크를 추가합니다.
4. 오른쪽에서 왼쪽으로 쓰는 언어(`ar`, `fa`, `he`)는 표와 코드 블록이 깔끔하게 렌더링되도록 파일 전체를 `<div dir="rtl">`로 감싸지 말고 표준 Markdown으로 작성하세요.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **섹션:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [English 원문](../../docs/ardor_fury_v2.md) · [↑ 맨 위로](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

2.4 GHz 수신기는 HID 사용 페이지 `000A`, 사용량 `0000`, 5바이트 입력 보고서를 노출합니다. 데이터를 브로드캐스트할 뿐이며 HID 명령은 전송하지 않습니다.

실기 하드웨어에서 관측된 보고서:

| 보고서 | 배터리 |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

바이트 3의 상위 니블이 단계(`1`, `3`, `7`, `F` = 각각 25, 50, 75, 100%)를 인코딩합니다. 25%와 100% 보고서는 제조사 애플리케이션의 디코딩 로직에서 추론했으며, 이후 최종 사용자가 빌드된 앱에서 나머지 잔량 단계도 올바르게 표시됨을 확인했습니다. 다섯 번째 바이트는 상수가 아니므로 서명으로 사용하지 않습니다.

리스너는 전체 보고서가 완전히 동일할 필요가 아니라 디코딩된 배터리 단계가 일치하는 두 보고서를 요구합니다. 마지막으로 확인된 값은 최대 45초 동안 유지됩니다. 전역 자동 새로 고침 간격은 15초로 변경됩니다.

Windows에서 ARDOR Fury V2 및 Logitech G733과 함께 최종 사용자가 검증: 50% 및 75% 캡처, 주기적 자동 업데이트, 25%/100% 시각 확인 및 포터블 실행. 25% 및 100% 보고서 패킷 자체는 캡처되지 않았습니다.


---

<a id="sec-areson"></a>
> 📄 **섹션:** Areson `25A7` (`docs/areson.md`) · [English 원문](../../docs/areson.md) · [↑ 맨 위로](#top)

# Areson 25A7 수신기 배터리 지원

## 기존 프로그램이 마우스를 놓친 이유

Redragon M915RGB-WL은 Areson/CompX `25A7:FA07` "2.4G Wireless Receiver"를 통해 연결됩니다. 배터리가 표준 HID *Battery Strength* 사용량으로 노출되지 않고 독자적인 2.4 GHz 링크를 쓰기 때문에 Windows에도 블루투스 배터리 속성이 없습니다. 대신 마우스는 능동적인 `GetPower` 요청에 응답하므로 일반 HID 폴백과 블루투스 폴백 모두 이 마우스를 볼 수 없었습니다. 해당 제조사 드라이버가 없어 수신기가 점유되지 않고 비활성 상태로 남아 있었습니다.

## 관측된 하드웨어 및 패킷

2026-11-17, Windows 11에서 Redragon M915RGB-WL로 테스트됨:

| 방향 | VID:PID | 인터페이스 | 사용 페이지:사용량 | 보고서 크기 |
|---|---|---|---|---|
| 요청 (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17바이트 |
| 응답 (input) | `25A7:FA07` | 1 | `FF01:0000` | 17바이트 |

응답은 요청을 쓰는 최상위 컬렉션과 다른 최상위 컬렉션으로 도착합니다. Windows에서는 각각 `MI_01&COL07`(feature)와 `MI_01&COL05`(input)이며, 드라이버가 두 핸들을 모두 여는 이유가 바로 이 때문입니다.

캡처된 요청 (`GetPower`, 보고서 ID `08`, 명령 `04`, 체크섬을 더해 프레임 전체 합이 `0x55`가 됨):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

캡처된 응답:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

아래 오프셋은 보고서 ID를 0번 바이트로 계산합니다:

| 바이트 | 의미 | 예시 |
|---|---|---|
| 0 | 응답 보고서 ID | `09` |
| 1 | 명령 에코 | `04` |
| 2 | 상태, 0 = OK | `00` |
| 3–4 | 주소, `GetPower`에서는 미사용 | `00 00` |
| 5 | 데이터 길이 (2) | `02` |
| 6 | 배터리 잔량, 0–10, 10% 단위 | `08` = 80% |
| 7 | 충전 플래그, 0이 아닌 모든 값 | `00` = 충전 안 함 |
| 16 | 체크섬; 17바이트 전체 합이 `0x55` (mod 256) | `3E` |

같은 프레임에 대해 제조사 자체 소프트웨어가 80%를 표시했으며, 이를 통해 ×10 스케일이 확인되었습니다. `GetConnectStatus`(`08 03 …`)는 1바이트 페이로드로 응답하며 당시 마우스가 연결된 상태임을 보고했습니다.

## 기타 Areson 마우스

Redragon M693이 사용하는 구형 `FA7B` / `FA7C` 수신기는 같은 응답 오프셋에 충전량을 정수 백분율 그대로 보고합니다. 여기에 이 드라이버의 ×10 스케일을 적용하면 800%로 표시되므로 해당 제품 ID들은 의도적으로 점유하지 않습니다. `FA07`과 `FA08`만 처리하며, `FA08`은 동일 제품군의 대체 ID이지만 이 시스템에서 직접 검증되지는 않았습니다.

## 폴링 및 식별자

- 드라이버는 읽기 전용 `GetPower` 요청만 보냅니다. 설정, 조명, DPI 데이터는 절대 쓰지 않습니다.
- 새로 고침마다 액세스 권한 0으로 feature 컬렉션을 열고 읽기 전용으로 input 컬렉션을 연 뒤 요청을 보내 최대 1.8초 동안 응답을 기다립니다. 오래된 보고서를 응답으로 오인하지 않도록 중간에 큐를 비우며 두 번 시도합니다.
- 읽기에 실패하면 아무것도 점유하지 않으므로 절전 중인 마우스는 UI에 마지막 값을 유지합니다. 이 항목은 다른 수동 드라이버와 동일하게 30분의 유예 기간을 사용합니다.
- 기기 키는 제조사 및 제품 ID에서 파생되므로(`areson:25A7:FA07`) 수신/절전 주기와 수신기 재연결 이후에도 유지됩니다.

## 검증

MSVC C++17 및 Windows SDK로 전체 애플리케이션을 빌드하고 실제 마우스에 대해 실행했습니다. `BatteryHub.exe --list` 출력 결과:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

측정값은 같은 시각 공식 Redragon 소프트웨어에 표시된 백분율과 일치했습니다. MinGW용 `build.bat`에는 새 소스 파일이 포함되어 있으며 `Makefile`은 와일드카드로 자동 인식합니다.

## 프로토콜 출처

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): Redragon 소프트웨어의 USB 캡처에서 복원한 17바이트 프레임, feature/input 분리 및 `0x55` 체크섬 규칙.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): `25A7:FA07`의 `GetPower` 명령과 10% 단위 잔량 스케일.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md): 응답 레이아웃 및 `FA7B` / `FA7C` 계열의 다른 백분율 스케일.


---

<a id="sec-darkrim"></a>
> 📄 **섹션:** DARKRIM SHADOW (`docs/darkrim.md`) · [English 원문](../../docs/darkrim.md) · [↑ 맨 위로](#top)

# DARKRIM SHADOW / 寸渊影弑 수신기

`3654:6901`, 제조사 `Jieli Technology`, 릴리스 `0100`에서 실기 테스트되었습니다. 인터페이스 **3**, 사용량 `FF02:0002`, 보고서 ID 없는 64바이트 입출력 페이로드(Windows HID 보고서 크기 65바이트)를 사용합니다. 인터페이스 4에도 `FF02:0002`가 있지만 보고서 ID 2를 사용하며 이 프로토콜에 응답하지 않으므로 의도적으로 제외됩니다.

프로토콜 출처: 공식 [PC Hub 다운로드](https://app.darkrim.net/hub/zh.html)의 `DARKRIM-0.1.26-x64-setup.rar`를 제조사 소프트웨어를 설치하거나 실행하지 않고 내려받아 정적으로 압축 해제함. 추출된 `DARKRIM.exe` SHA-256: `f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

해당 바이너리의 주요 주소:

- `140124C80`: `sendGetBasicInfo(infoType)`는 명령 `0010`, Request `01`, 페이로드 `[infoType, 00]`을 전송합니다. 배터리 선택자는 `01`입니다.
- `140118D30`, `140119200`: 프레임 헤더 및 CRC 생성.
- `140126DB0`: 기기 정보 TLV 파서; TLV `01`이 배터리입니다.
- `1400F5660`, `1400FA700`: 배터리 사용 함수; 하위 7비트가 백분율이고 최상위 비트가 충전 여부입니다. 동일한 배터리 값은 `0011` Notify `03`으로도 도착합니다.

헤더: `FE seq cmdLE type index count lengthLE`, 이어서 페이로드와 CRC-16/CCITT-FALSE(다항식 `1021`, 초기값 `FFFF`, 빅 엔디안 저장)가 뒤따릅니다. 시퀀스는 0이 아닌 4비트 카운터이며 암호화는 사용되지 않습니다.

HID 제로 패딩 이전의 실제 요청/응답 페이로드:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

응답 TLV `01 01 28`은 **40%, 충전 중 아님**을 나타냅니다. 프로덕션 C++ 드라이버는 제조사 소프트웨어 없이 연속 세 번의 쿼리에서 해당 값을 반환했습니다. 수신기는 일치하는 응답 전에 약 406 ms로 측정된 시작 알림을 내보냅니다. 무관한 알림 때문에 타이머를 재시작하지 말고 800 ms 응답 마감 시간(쓰기 최대 200 ms 추가)을 사용하세요. 하트비트는 필요하지 않습니다.

드라이버는 배터리 GET만 전송하며, 암호화되지 않고 시퀀스/명령/유형이 일치하며 인덱스 0, 카운트 0 또는 1(하드웨어는 0 사용), 유효한 길이/CRC 및 단일 정상 배터리 TLV를 갖춘 응답만 수락합니다. 분할되거나 요청하지 않은 응답, 잘못된 형식 및 범위 밖 응답은 무시됩니다.

## 관측된 배터리 정밀도 및 충전 상태

백분율은 **검증된 1% 해상도 게이지가 아닌 대략적인 추정치**로 취급하세요. 소유자의 기기는 40%에서 90%까지 10퍼센트포인트 단위로 충전 진행을 표시했습니다. 90%에서 다섯 번의 배터리 GET 응답과 한 번의 비요청 알림이 모두 `DA`를 담고 있었습니다(`DA & 7F = 90`, 비트 7은 충전 중). 소유자가 충전 케이블을 분리하고 2.4 GHz 수신기를 계속 사용한 뒤에는 또 다른 다섯 번의 GET 응답과 한 번의 알림이 모두 `5A`를 전달했습니다(여전히 90%이며 충전 비트가 해제됨). 12개 프레임 모두 CRC 검증을 통과했습니다.

대표 쿼리 응답 (시퀀스 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

드라이버와 공식 애플리케이션 모두 하위 7비트에서 백분율을 직접 가져옵니다. 드라이버는 10 단위로 반올림하거나, 단계 값에 10을 곱하거나, 중간 값을 보간하지 않습니다. 가상의 47% 및 95% 보고서도 프로덕션 파서에서는 47% 및 95% 그대로 유지됩니다. 따라서 관측된 거친 단위의 측정값은 파서 이전 단계인 헤드셋/수신기의 보고 자체에서 비롯된 것입니다. 더 세밀한 하드웨어 측정값은 관측되지 않았습니다. 전체 방전 곡선도 기록되지 않았으므로 모든 방전 구간이나 다른 펌웨어에서도 10% 단위 고정이 적용되는지는 확인되지 않았습니다.

90%에서의 충전 상태 및 이후 비충전 상태 전환은 실기에서 확인되었습니다. 저전력/완충 경계, 헤드셋 전원 꺼짐 동작, 블루투스 및 USB 케이블 데이터 모드는 실기에서 테스트되지 않았으므로 해당 모드에 대한 지원은 보장하지 않습니다. 이 구현에는 펌웨어 업데이트, 설정 변경, EQ 명령, 페어링 변경, 초기화 또는 제조사 바이너리가 포함되지 않습니다.

테스트: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **섹션:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [English 원문](../../docs/hyperx_haste_2.md) · [↑ 맨 위로](#top)

# HyperX Pulsefire Haste 2 Wireless 배터리 프로토콜

`src/drivers/hyperx.cpp`의 `HasteWireless`에서 읽습니다. 쿼리는 [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) 출처이며 NGENUITY가 사용하는 것과 동일합니다.

실기 하드웨어에서 검증됨:

- Pulsefire Haste 2 Core Wireless, 동글 `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, 동글 `03F0:0F98`, uzumakiprime (PR #312). 잔량이 HyperX NGENUITY와 일치했습니다.

`03F0:0D97` 동글도 같은 방식으로 동작할 것으로 예상되지만 테스트되지는 않았습니다.

## HID 컬렉션

| 항목 | 값 (`0F98`) |
|---|---|
| USB 인터페이스 | `MI_02` (인터페이스 2) |
| 사용 페이지 : 사용량 | `FF00:0001` |
| 입력 / 출력 / 기능 보고서 길이 | 64 / 64 / 64바이트 |

이 동글은 표준 마우스 및 소비자 제어 컬렉션도 함께 노출합니다. 드라이버는 입력 보고서 길이가 최소 8바이트 이상인 제조사 컬렉션(사용 페이지 `FF00` 이상)만 엽니다.

## 쿼리

두 요청 모두 출력 보고서이며, 아래 처음 두 바이트 뒤에 보고서 길이만큼 0으로 채웁니다. 각 응답은 첫 바이트가 `명령 + 1`인 입력 보고서입니다. 각 쿼리는 최대 1초 동안 응답을 기다리며 무관한 보고서는 건너뜁니다(재연결 후 동글이 자체적으로 `44 xx`, `45 xx`, `FB xx` 보고서를 보냅니다).

| 요청 | 응답 | 의미 |
|---|---|---|
| `52 01` | `53 01 <linked>` | 마우스가 꺼져 있거나 범위를 벗어나면 `linked` = 0 |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100; `charge` 1 = 충전 중, 2 = 충전기에서 완충; mV 단위 전압, 리틀 엔디안 (Core에서는 0) |

- 링크 응답이 없으면 배터리 응답으로 판단합니다.
- 링크가 0을 보고하면 배터리 쿼리를 보내지 않고 마우스가 꺼진 것으로 표시합니다.
- 마우스를 켠 직후 몇 초 동안은 약 40%를 보고합니다. 링크가 연결된 후 6초 이내의 측정값은 무시하고 트레이에 마지막 값을 유지합니다.

두 요청 모두 상태만 읽습니다. 설정, 조명 또는 모드는 전혀 변경하지 않습니다.


---

<a id="sec-inphic"></a>
> 📄 **섹션:** Inphic IN10 (`docs/inphic.md`) · [English 원문](../../docs/inphic.md) · [↑ 맨 위로](#top)

# Inphic IN10 제품군, KP 8K 수신기

소유자가 IN10 MAX로 식별한 연결 기기는 `Inphic KP 8K`, `1D57:FA65`, 릴리스 `0116`으로 열거됩니다. 상태 컬렉션은 인터페이스 2, 사용량 `000A:0000`, 입력 길이 5(보고서 ID 03 포함)입니다.

어떤 요청도 보내지 않고 약 4초마다 관측된 보고서:

```text
03 73 41 01 64
```

기존 Xenta 파서는 이 형식(모델, 이벤트, 배터리 상태, 백분율)을 인식합니다. 100%를 표시하기 전에는 두 개의 동일한 보고서가 필요하며, 관련 수신기에서는 연결 직후 첫 번째 보고서가 잘못된 완충 값일 수 있습니다. 이 변경 사항은 해당 안전장치와 기존 충전/절전 동작을 그대로 유지합니다.

공식 [Inphic HUB](https://hub.inphic.cn/) 번들 `assets/index-BcHQx9B6.js`는 십진수 모델 115(`73`)를 `IN10RMax`에, 116(`74`)을 `IN10Max`에 매핑합니다. 배터리 상태 값으로는 1을 백분율, 2를 완충, 3을 충전 중으로 사용합니다. `73`을 IN10 MAX로 임의 할당해 이 수신기를 공유하는 다른 기기를 잘못 라벨링하는 대신 펌웨어의 모델명을 사용합니다.

이 변경 이전에는 앱이 연결된 마우스를 `Wireless mouse`로 표시했습니다. Xenta 전송 계층이 이미 배터리 프레임을 처리하고 있었으며 이번 변경은 누락된 모델명만 보충합니다. 새로 실행한 `--list`는 5초 초기 관측 시간 동안 4초 간격의 보고서를 한 번만 받을 수 있으므로 절전(asleep)으로 표시될 수 있습니다. 상주 앱은 리스너를 유지하고 다음 폴링에서 값을 확정합니다.

하드웨어 검증 완료: 수동 보고서, 반복되는 100% 잔량 및 네이티브 드라이버 모델 식별. 충전 전환, 저전력 경계, 블루투스 및 케이블 모드는 검증되지 않았습니다. 모델 `74`는 공식 테이블 출처이며 별도 실기 하드웨어에서 테스트되지 않았습니다.


---

<a id="sec-machenike"></a>
> 📄 **섹션:** Machenike L7 (`docs/machenike.md`) · [English 원문](../../docs/machenike.md) · [↑ 맨 위로](#top)

# Machenike L7 Arctic / L7 Mix

**L7 Mix**로 식별되는 L7 Arctic에서 검증됨:

| 연결 방식 | VID:PID | 인터페이스 | 사용량 | 입력 / 출력 / 최대 기능 크기 |
| --- | --- | --- | --- | --- |
| 2.4 GHz 수신기 | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB 케이블 | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

드라이버는 HID 제품명 `L7 Mix`도 함께 확인합니다. 다른 Machenike 모델, 다른 수신기 ID 및 블루투스 제조사 쿼리는 활성화되어 있지 않습니다.

## 프로토콜 출처

[제조사 드라이버 페이지](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/)에서 제공되는 공식 **Machenike L7 Mix 1.0.0.8** 소프트웨어에 대한 상호 운용성 분석 및 실제 마우스에 대한 읽기 전용 쿼리 결과입니다. `DeviceDriver.exe` SHA-256: `A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

해당 32비트 실행 파일(이미지 베이스 `00400000`)에서 함수 VA `00436750`이 상태 요청을 구성하고, `004494F0`이 `HidD_SetFeature`로 전송한 뒤 기능 응답을 읽습니다. 상태 파서 `00410C20`은 아래 필드를 추출해 배터리 및 충전 필드를 UI로 전달합니다. 이 주소들은 파일 오프셋이 아닌 가상 주소입니다. 독점 실행 파일, 애플리케이션 코드 또는 리소스는 여기에 포함되지 않습니다.

## 상태 읽기 쿼리

보고서 ID `51`, 명령 `06`, 나머지 모든 바이트 0으로 **21바이트**를 전송합니다:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

마찬가지로 21바이트를 사용해 기능 보고서 `51`을 읽습니다. 컬렉션의 최대 기능 크기 1001은 다른 보고서용이며 상태 보고서의 길이가 아닙니다. 드라이버는 읽기 전 10 ms를 대기하고 무관한 응답을 포함해 제품당 하나의 200 ms 마감 시간을 사용합니다. 설정, 모드, 매크로 또는 펌웨어 명령은 전송하지 않습니다.

인덱스에는 보고서 ID가 포함됩니다:

| 바이트 | 의미 / 관측된 값 |
| --- | --- |
| 0–1 | `51 06`, 필수 명령 에코 |
| 4–7 | `8A 24 4E FF`, 검증된 L7 기기 서명 |
| 10, 비트 0–2 | 작동 모드: 수신기 1, 케이블 0 |
| 10, 비트 3 | 무선 마우스 연결됨; USB 케이블에서도 0으로 해제됨 |
| 11 | 배터리 백분율, 0–100 (0도 유효) |
| 12 | 충전 플래그: 0 방전 중, 1 충전 중 |

다른 필드와 체크섬 의미는 규명되지 않았습니다. 드라이버는 임의의 체크섬을 만들어 쓰지 않으며, 측정값을 게시하기 전에 명령, 길이, 기기 서명, 모드 및 연결 상태의 배터리/충전 범위를 검증합니다.

공식 앱에서도 64%로 표시되었던 캡처된 수신기 응답:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

충전 중 캡처된 USB 케이블 응답 (74%):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

이때 수신기는 여전히 캐시된 64%를 반환했지만 링크 비트는 해제했습니다:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

이 연결 끊김 측정값은 캐시된 배터리/충전 값을 노출해서는 안 됩니다. 두 전송 경로가 모두 존재할 때는 케이블이 우선권을 가지며, 전송 경로 간에 안정적인 기기 키를 공유합니다. 쿼리가 실패하더라도 알려진 L7은 점유 상태로 예약되므로 이후 Ajazz 드라이버가 공유 VID에서 다른 프로토콜로 이를 탐색하지 못합니다.

## 검증 범위

픽스처 및 시뮬레이션된 전송 테스트는 캡처된 측정값, 충전 중, 유효한 0%/100%, 연결 끊긴 수신기, 잘못되거나 오래된 응답, 엄격한 매칭, 전송 실패, 중복 억제 및 제한된 재시도 루프를 다룹니다. 실제 기기에서의 0%/100% 및 모든 절전/펌웨어 변형까지 이 테스트로 보장되는 것은 아닙니다.


---

<a id="sec-nuphy"></a>
> 📄 **섹션:** NuPhy WH80 (`docs/nuphy.md`) · [English 원문](../../docs/nuphy.md) · [↑ 맨 위로](#top)

# NuPhy WH80 (USB 케이블 및 블루투스)

`19F5:A011`, 펌웨어 릴리스 `0116`, 인터페이스 1, 사용량 `0001:0000`, 보고서 ID 없는 64바이트 입출력 페이로드(Windows HID 기능 정보에서는 65바이트)로 실기 테스트되었습니다.

프로토콜 출처: [NuPhyIO](https://drive.nuphy.io/), 번들 `main.b3fb29e0.js`, SDK `getBatteryState(0)`, `getDataPackage` 및 `createCommand`. 오직 `GetFunc`(`05`), 오프셋 `0020`, 길이 `01`만 요청합니다. 초기화, 설정, 조명 또는 펌웨어 명령은 필요하지 않습니다.

64바이트로 0 패딩된 요청 페이로드:

```text
55 05 00 21 01 20 00 00
```

실제 응답 페이로드:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

바이트 3은 바이트 4..63 합계의 하위 바이트입니다. 배터리는 바이트 8에 있습니다: `value & 7F`가 백분율, `value & 80`이 SDK 충전 플래그입니다. 네이티브 C++ 드라이버는 연결된 키보드에서 **100%, 충전 중**을 반환했습니다. 충전 전환 및 저전력/완충 경계는 실기 테스트되지 않았으며, 공식 펌웨어 노트는 WH80 측정값을 10% 단위로 설명하고 있습니다. 수신기 동작은 이 드라이버의 범위 밖입니다.

## 블루투스

블루투스 연결 시 동일한 키보드가 HID ID `19F5:324A`(릴리스 `0129`)를 사용하며 `NuPhy WH80 - 1`과 같은 사용자 표시 이름을 광고합니다. 이 기기는 키보드 컬렉션 두 개와 마우스 컬렉션 하나를 노출합니다. 일반 HID 휴리스틱이 마우스를 우선시하므로 이 정확한 블루투스 ID를 기존 키보드 재정의 목록에 추가해야 합니다.

배터리 보고는 계속 Windows 블루투스 배터리 속성을 사용합니다. USB를 분리한 후 Windows는 연결된 키보드에서 **95%**를 보고했습니다. 표준 GATT Battery Level(`180F` / `2A19`)을 캐시 없이 직접 읽어도 키보드에서 **95%**가 반환되었습니다. 이는 유선의 100% 관측치와는 별개의 장치/전송 측정값이므로, 임의의 완충 값으로 바꾸거나 크기를 재조정하지 마세요. 펌웨어 측정값이 서로 다른 이유는 규명되지 않았습니다.

드라이버는 정확한 제품/인터페이스/보고서 크기, 응답 헤더, 오프셋, 길이, 체크섬 및 백분율 범위를 검증합니다. 400 ms 응답 마감 시간을 사용하며 같은 마감 시간 내의 무관한 응답은 무시합니다.

회귀 테스트:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **섹션:** Rapoo (`docs/rapoo.md`) · [English 원문](../../docs/rapoo.md) · [↑ 맨 위로](#top)

# Rapoo 마우스 배터리 지원

## 기존 프로그램이 마우스를 놓친 이유

`PollAllDevices()`는 새로 고침마다 Windows HID 최상위 컬렉션을 한 번 열거합니다. 각 제조사 드라이버는 프로토콜을 인식해 `DeviceStatus`를 추가하고 일반 드라이버가 중복 추가하지 않도록 해당 VID/PID를 점유합니다. UI는 이미 백분율, 충전 상태, 절전 중 마지막 측정값 유지를 처리하고 있습니다.

기존에는 Rapoo 드라이버가 없었습니다. VT3 Max Gen 2는 표준 HID Battery Strength 사용량이나 Windows 블루투스 배터리 속성이 아니라 제조사 정의 입력 보고서로 배터리를 전송합니다. 따라서 기존 일반 HID/블루투스 폴백은 USB 수신기를 디코딩할 수 없었습니다.

## 관측된 하드웨어 및 패킷

2026-11-16, Windows에서 소유자의 VT3 Max Gen 2로 테스트됨:

| 연결 방식 | VID:PID | 인터페이스 | 사용 페이지:사용량 | 입력 / 출력 크기 |
|---|---|---|---|---|
| 2.4 GHz 수신기 | `24AE:1417` | 1 | `FF00:0002` | 19 / 19바이트 |
| USB 케이블 | `24AE:4617` | 1 | `FF00:0002` | 19 / 19바이트 |

둘 다 `Rapoo Gaming Device`로 식별됩니다. 나머지 컬렉션에는 표준 마우스, 키보드 및 미디어 입력, 제조사 설정 컬렉션, 그리고 513바이트 펌웨어 인터페이스가 포함됩니다. 배터리 드라이버는 인식된 입력 크기를 가진 `FF00:0002`만 엽니다. 펌웨어 인터페이스는 절대 열지 않으며 출력 보고서, 기능 보고서, 핸드셰이크 또는 설정 명령을 전혀 전송하지 않습니다.

보고서 ID를 포함해 캡처된 무선 보고서:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

캡처된 케이블/충전 보고서:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

아래 오프셋은 이 프로젝트의 `HidDev::Read()`와 동일하게 보고서 ID를 0번 바이트로 계산합니다:

| 바이트 | 의미 | 예시 |
|---|---|---|
| 0 | 보고서 ID | `07` |
| 1 하위 니블 | 연결 방식: 0 수신기, 1 블루투스, 2 케이블 | `20` / `22` |
| 1 상위 니블 | 센서 정보; 연결 유형의 일부가 아님 | `2` |
| 2 | 현재 DPI 단계 | `03` |
| 3–4, 5–6 | X/Y DPI, 리틀 엔디안 | `0320` = 800 |
| 7 | 배터리 상태: 0 무효, 1 방전 중, 2 충전 중 | `01` / `02` |
| 8 | 배터리 백분율, 0–100 | `19` = 25% |
| 13–14 | 마우스 제품 ID, 리틀 엔디안 (포함된 경우) | `4617` |

실시간 수신기 캡처는 `25%`를 보고했고 이후 전체 애플리케이션은 케이블 연결 시 `27%, charging`을 반환했습니다. 파서 테스트에는 실제 무선 캡처가 포함되어 있습니다. 충전 상태와 케이블 연결 여부도 실제 하드웨어에서 검증되었으며, 단순히 USB 장치가 존재한다는 사실만으로 추론한 것이 아닙니다. 소유자가 케이블을 분리하고 수신기를 다시 연결한 뒤에는 최종 실행 파일이 충전 플래그 없이 `2.4 GHz receiver`로 `52%`를 반환했고 동일한 `rapoo:4617` 키를 유지했습니다. 이로써 케이블에서 수신기로의 전환도 실제 하드웨어에서 검증되었습니다.

2026-11-17, Windows에서 **VT9 Gen 2**로도 테스트됨:

| 연결 방식 | VID:PID | 인터페이스 | 사용 페이지:사용량 | 입력 / 출력 크기 |
|---|---|---|---|---|
| 2.4 GHz 수신기 | `24AE:1414` | 1 | `FF00:0002` | 16 / 16바이트 |
| USB 케이블 | `24AE:4614` | 1 | `FF00:0002` | 19 / 19바이트 |

VT9 Gen 2 수신기는 19바이트 대신 **16바이트** `FF00:0002` 보고서를 노출하며, 정확히 동일한 Nordic 54L `07` 레이아웃(바이트 13–14의 내장 `4614` PID 포함)을 사용합니다. 캡처된 프레임:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

USB 케이블 연결 시에는 조작(예: DPI 변경) 시점에 상태 보고서가 관측되었으며, 케이블에 꽂힌 상태에서 바닥 전원 스위치를 OFF로 두면 마우스가 실제 배터리 백분율 대신 `state=2, percent=1`을 보고했습니다.

### 13바이트 컬렉션을 가진 VT3 Max Gen 2 수신기 (이슈 #1396)

동일한 수신기 ID `24AE:1417`에 대한 기기 요청 양식 보고서에서 다른 인터페이스 레이아웃이 보고되었습니다: 513바이트 펌웨어 컬렉션 없이 `FF00:0002`가 (19바이트 대신) **13 / 13**바이트이고 `FF00:000E`가 33 / 33바이트였습니다. 이는 다른 수신기 펌웨어 리비전으로 보입니다. Rapoo 소프트웨어에서는 여전히 배터리가 표시되었으므로 기존 드라이버가 정상 작동하는 상태 채널을 놓치고 있던 것입니다.

Rapoo Hub의 `VT_nrf54L` 디코더(`py`)는 길이에 적응적으로 동작합니다: 항상 DPI, 배터리 상태, 백분율을 읽고, 보고서가 충분히 길 때만 뒤쪽 필드(`n[12..13]`의 마우스 PID, RF 정보 등)를 읽습니다. VT3 MAX 매니페스트(`productId: [17943, 5143]`)에는 특수 입력 보고서 유형이 없으므로 이 수신기에서도 보고서 `07`이 해당 디코더를 통과합니다. 13바이트 보고서(ID + 12바이트)도 여전히 바이트 7에 상태, 바이트 8에 백분율을 담고 있으며 내장 마우스 PID만 빠져 있으므로 측정값은 수신기 PID를 사용하고 `rapoo:4617` 키를 유지합니다.

13바이트 길이는 **`24AE:1417`에 대해서만** 허용됩니다. 프레임은 여전히 동일한 검사(보고서 `07`, 연결 니블 0–2, 상태 1/2, 백분율 0–100)를 통과해야 합니다. 실제 13바이트 프레임은 아직 캡처되지 않았으며, 테스트에서는 검증된 19바이트 캡처를 13바이트로 잘라 사용합니다.

## 기타 Rapoo 마우스

공식 Rapoo Hub는 Nordic 54L 마우스 드라이버에 이 `07` 레이아웃을 사용합니다. 매니페스트에는 VT0, VT1, VT2, VT3, VT3S, VT7, VT9 및 추가 변형 모델들이 나열되어 있습니다. 현재 번들을 검사한 결과 `VT_nrf54L`을 사용하는 VT 변형 모델 69종이 확인되었으나, 이는 공용 프로토콜의 근거일 뿐 69종 모두에 대한 실기 검증이나 Rapoo 전체 제품군 대부분의 지원을 주장하는 것은 아닙니다. 지원 여부는 Rapoo VID, 전용 컬렉션, 입력 길이, 유효한 상태 보고서로 판별되므로, 목록에 없더라도 같은 프로토콜을 사용하는 모델이면 여전히 배터리를 보고할 수 있습니다. 소규모 이름 테이블이 주요 모델을 다루며 나머지는 HID 제품명을 유지하거나 `Rapoo wireless mouse`로 표시됩니다.

제품명과 ID는 세대와 지역에 따라 다릅니다. 테스트된 `1417/4617` 쌍은 현재 공식 매니페스트에서 `VT3 MAX`로 불리며 소유자는 이를 VT3 Max Gen 2로 식별합니다. 현재 매니페스트의 별도 항목인 `VT3 MAX V2`는 ID `1B06/4B06`을 가집니다. `1417`을 VT9 Pro에 할당하는 커뮤니티 표를 이 기기의 이름 지정이나 감지의 유일한 근거로 사용해서는 안 됩니다.

VT3 Pro(`1215/4415`)용으로 문서화된 구형 VT 펌웨어는 대신 동일한 `FF00:0002` 사용량으로 7바이트 보고서를 푸시합니다:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

이 구형 형식에서 상태 1/2는 방전/충전을 의미합니다. 충전 중 백분율이 `7F`이면 알 수 없음을 의미하며 알 수 없음 상태로 보존됩니다. 전환 상태 0, 무관한 `BC` 보고서, 잘못된 패킷, 100을 초과하는 백분율은 무시됩니다. 구형 지원은 자동화된 테스트 커버리지를 갖추고 있지만 여기서는 실제 구형 마우스로 검증되지 않았습니다. 이 해석은 제품 ID `1215/4415`(VT3 Pro), `1233/4433`(VT1 Pro Max) 및 해당 7바이트 입력 컬렉션으로만 제한됩니다.

VT1 Pro Max(수신기 `24AE:1233`, 케이블 `24AE:4433`, 마우스 펌웨어 222, 동글 펌웨어 213)는 소유자가 이슈 #136에 첨부한 USBPcap 캡처를 바탕으로 추가되었습니다. `--dump` 출력은 인터페이스 1의 7바이트 `FF00:0002` 컬렉션을 보여 주며, 캡처에서는 Rapoo 앱의 요청 없이도 보고서가 푸시되는 것이 확인되었습니다:

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

케이블에서는 16초 캡처 동안 보고서가 단 한 번만 관측되었으므로 케이블 단독 측정 시 일부 새로 고침에서 시간 초과가 발생할 수 있으며, 수신기는 주기적으로 푸시합니다. Nordic 프로필은 `BB` 패킷을 절대 해석하지 않습니다.

이 지원이 모든 Rapoo 기기의 지원을 의미하는 것은 **아닙니다**. VT1 SE 및 VT7 SE 같은 CH584 모델은 공식 드라이버에서 보고서 `08`을 사용하므로 이 디코더에서 지원되지 않습니다. 다른 Telink 리비전은 `BB` 플래그를 다르게 해석하고, 일부 사무용 모델은 능동 배터리 쿼리를 사용하며, 블루투스 모델은 Windows 배터리 속성만 노출할 수 있습니다. 이러한 기기들은 기존 폴백으로 처리하거나 별도의 검증된 구현이 필요합니다. 추측에 기반한 쿼리를 절대 전송하지 마세요.

## 폴링 및 식별자

- 읽기는 수동(passive) 방식입니다. 일치하는 `FF00:0002` 핸들은 폴링 사이에도 열린 상태를 유지하므로(`PollXenta`와 동일) Windows가 60초 새로 고침 간격 동안 도착하는 상태 프레임을 버퍼링합니다. 각 폴링은 처음 열 때나 큐가 비어 있을 때 5초 대기로 넘어가기 전에 큐에 쌓인 프레임을 모두 비우면서 가장 최신의 유효한 배터리 측정값을 취합니다. 분리된 기기는 제거되고 핸들이 닫힙니다. 무관한 패킷은 마감 시간을 재시작하지 않습니다.
- 내장된 마우스 PID 또는 구형 기기의 알려진 케이블/수신기 쌍을 사용해 케이블을 꽂고 뺄 때도 동일한 UI 키를 유지합니다. 케이블과 수신기의 측정값은 하나의 항목으로 병합되며, 케이블이 알 수 없는 잔량을 보고할 경우 유효한 수신기 백분율을 보존하면서 케이블의 상태를 우선합니다.
- 시간 초과가 발생하더라도 백분율을 임의로 만들어 내거나 기기를 점유하지 않습니다. 성공적인 읽기 이후 기존 UI는 응답이 없는 동안 최대 30분까지 해당 측정값을 흐리게 유지할 수 있습니다.
- 프로그램의 기존 VID/PID 기반 식별 모델은 동일한 모델 ID를 가진 여러 대의 똑같은 마우스를 구분할 수 없습니다. 실제 물리적인 케이블/수신기 동시 연결 작동은 테스트되지 않았으며, 두 입력의 병합은 시뮬레이션된 전송 테스트로 검증되었습니다.

## 검증

`make test`는 이식 가능한 디코더 테스트와 시뮬레이션된 HID 응답을 사용하는 Windows 드라이버 테스트를 실행합니다. 테스트 범위에는 실제 캡처, 0% 및 100%, 충전 중, 누락된 잔량, 잘못되거나 잘린 프레임, 미지원 컬렉션/제조사, 프로토콜 프로필 격리, 시간 초과, 안정적인 키, 알려진 백분율을 버리지 않는 케이블/수신기 중복 제거가 포함됩니다.

MSVC C++17 및 Windows SDK로 전체 애플리케이션을 로컬 빌드해 실제 마우스에서 `--list` / `--dump`를 실행했습니다. 유지 관리 중인 MinGW 빌드는 `build.bat`에 `rapoo.cpp`를 포함하며 Makefile은 이를 자동으로 찾습니다. 테스트 환경에는 MinGW 자체가 설치되어 있지 않았습니다.

## 프로토콜 출처

- [공식 Rapoo Hub](https://hub.rapoo.cn/), 2026-11-16 확인: 번들 [JavaScript 드라이버 및 매니페스트](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js). 관련 디코더는 `VT_nrf54L`용 `py`/`Hk`와 연결 및 배터리 상태 의미 해석용 `qM`/`QM`입니다. 별도의 `VT_CH584` 핸들러는 보고서 `08`을 처리하며 이 구현의 범위 밖입니다. 난독화된 이름은 향후 릴리스에서 변경될 수 있습니다.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs): 구형 VT3 Pro 보고서, 충전 상태 및 알 수 없는 잔량 센티널 값.
- 이슈 #136 USBPcap 캡처 (수신기 연결 및 충전 중 케이블 연결 상태의 VT1 Pro Max).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js): 수동 `07` 상태 브로드캐스트와 배터리 오프셋을 독립적으로 뒷받침합니다. 해당 파서는 잘못된 백분율을 범위 내로 고정(clamp)하지만 이 구현에서는 대신 거부합니다.


---

<a id="sec-rawm"></a>
> 📄 **섹션:** RAWM (`docs/rawm.md`) · [English 원문](../../docs/rawm.md) · [↑ 맨 위로](#top)

# RAWM 프로토콜 노트

RAWM 마우스(및 동일 플랫폼을 공유하는 SADES Dagger)는 64바이트 비번호(unnumbered) 입출력 보고서(보고서 ID 포함 65바이트)를 사용하는 제조사 HID 컬렉션 `FF00:0001`을 통해 RAWM HUB 앱과 통신합니다. 수신기와 마우스는 Nordic의 제조사 ID `1915`를 사용합니다.

출처: RAWM HUB 웹 앱인 Hub Web 2.0(<https://www.rawmtech.com/hub.html>) 및 해당 스크립트 `https://hub.miracletek.net/hub/js/library.min.js`(난독화됨; 아래 함수와 상수 이름은 해당 스크립트 자체의 이름입니다). 지원되는 제품 ID는 앱이 내려받는 기기 테이블(`https://www.miracletek.net/game/device.php`)에서 가져왔습니다. Leviathan V4 GT와 NYX60은 VID `373E`에서 Hub Web 3.0을 사용하며 이는 다른 프로토콜입니다.

## 패킷

모든 보고서의 바이트 0 (보고서 ID 다음 바이트):

| 상위 비트 | 의미 |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | 하위 6비트는 페이로드 크기; 페이로드가 이벤트 스트림을 이어갑니다 |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | 흐름 제어 (여유 버퍼 크기); 여기서는 무시합니다 |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | 하위 6비트는 ESB 채널; 보고서의 나머지는 해당 채널용 패킷입니다. 수신기 뒤의 마우스는 채널 0입니다 |

페이로드는 다음과 같은 이벤트 바이트 스트림을 구성합니다:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## 배터리 읽기

드라이버는 수신기가 연결되었을 때 앱이 수행하는 동작(`send_event_query`, `send_event_ping`)을 그대로 수행합니다:

1. 수신기 대상: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>`(`CMD_QUERY`, OS = PC)를 보낸 뒤 핑 `00 84 0E 04 00 00`을 보냅니다. 기기는 호스트가 계속 쓸 때만 데이터를 보내므로 호스트가 핑을 보냅니다. 수신기는 `CMD_QUERY_RESULT`(`02`)로 JSON(예: `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`)을 응답합니다.
2. 앞에 `C0`을 붙인 채 채널 0에 동일한 쿼리와 핑을 보냅니다. 마우스는 30바이트 ESB 청크로 나뉜 약 550바이트 JSON 객체(예: `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`)로 응답합니다. `battery`는 백분율(RAWM HUB가 그대로 표시)이며 `chr`은 충전 중일 때 1입니다.
3. 이후 변경 사항은 `CMD_NOTIFY`(`0B`) 유형 `17`인 `[17, percent, charging]`으로 도착합니다.

드라이버는 앱과 마찬가지로 항상 수신기에 먼저 질의합니다(한 테스트에서 채널 0에만 쿼리를 보냈을 때는 응답이 없었습니다). 절전 중인 마우스는 전혀 응답하지 않지만 수신기는 응답합니다.

쿼리는 앱이 그렇게 전송하기 때문에 PC의 시각을 실어 보낼 뿐 다른 쓰기 작업은 하지 않습니다. 마우스는 `"crc":1`을 보고해 이후 명령(설정)을 CRC-16 프레임으로 감싸도록 앱에 알리지만, 쿼리와 핑은 앱이 이 정보를 알기 전에 보내는 것이므로 CRC 없이도 수락됩니다.

RAWM HS Receiver `1915:2346`(펌웨어 2.0.2)과 함께 Leviathan V4(펌웨어 1.2.0)에서 테스트되었습니다.


---

<a id="sec-vaxee"></a>
> 📄 **섹션:** VAXEE (`docs/vaxee.md`) · [English 원문](../../docs/vaxee.md) · [↑ 맨 위로](#top)

# VAXEE 4K/8K 수신기 및 ZYGEN NP-01S V2

## 범위 및 하드웨어 검증

이 드라이버는 64바이트 기능 보고서를 갖춘 제조사 컬렉션 `FF05:0001`에서 VAXEE 4K 수신기 `3057:1002`, VAXEE 8K 수신기 `3057:2002`, 그리고 USB 케이블 연결 시의 ZYGEN NP-01S V2 Wireless(`3057:1011`)를 지원합니다. 다른 VAXEE 수신기, 다른 케이블 제품 ID 및 ZOWIE 기기는 의도적으로 탐색하지 않습니다.

8K 수신기(`VAXEE 8K Wireless`, NP-01 Ergo Wireless 8K와 페어링됨)는 Windows에서 테스트되었으며 동일한 프로토콜을 통해 보고되었습니다:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

이 수신기는 모든 VAXEE 8K 마우스가 공용으로 사용하며 어떤 마우스가 페어링되어 있는지 보고하지 않으므로 수신기 자체 이름으로 표시됩니다. 8K 수신기의 충전 상태는 아직 실기에서 관측되지 않았습니다.

실제 4K 수신기는 Windows에서 다음과 같이 테스트되었습니다:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

통합 애플리케이션에서도 동일하게 보고되었습니다:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

그런 다음 동일한 마우스를 USB로 직접 연결하자 Windows가 이를 `ZYGEN NP-01S V2 Wireless`(`3057:1011`)로 식별했습니다. 업데이트된 프로덕션 드라이버는 다음과 같이 보고했습니다:

```
VAXEE battery: 75%; charging: yes
```

초기 수신기 빌드에서 작업 표시줄 위젯이 정상적으로 생성되었습니다. 수신기 배터리 작동과 유선 충전 모두 관측되었으며, 완충 전환 및 절전/전원 꺼짐 동작은 실기에서 테스트되지 않았습니다. 충전 디코딩과 잘못된 응답은 시뮬레이션된 응답 테스트로 검증됩니다.

## 프로토콜

출처: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

요청은 0으로 패딩된 64바이트 HID 기능 보고서입니다:

| 바이트 | 값 |
|---|---|
| 0 | `0E`, 보고서 ID |
| 1 | `A5`, 헤더 |
| 2 | 배터리 잔량은 `0B`; 충전 상태는 `10` |
| 3 | `01`, 읽기 플래그 (`02` 쓰기 플래그는 절대 사용 안 함) |
| 4 | `01`, 데이터 길이 |
| 5–63 | `00` |

`HidD_SetFeature`로 요청을 보낸 후 100 ms를 기다리고 `HidD_GetFeature`로 보고서 `0E`를 읽습니다. 최소 6바이트 이상이어야 하며 예상되는 보고서 ID, 헤더, 명령 에코 및 데이터 길이가 일치해야 합니다.

배터리 응답에서는 바이트 5가 0–20 범위여야 하며 여기에 5를 곱해 5% 단위의 0–100% 값을 얻습니다. 충전 응답에서는 충전 중일 때 바이트 5가 0이 아닌 값입니다. 충전 쿼리가 실패하더라도 유효한 배터리 측정값을 버리지 않습니다.

드라이버는 배터리 요청을 한 번 재시도합니다. 일치하는 컬렉션당 읽기 요청은 최대 3회(배터리 시도 2회 + 충전 쿼리 1회)이며 총 명시적 지연은 300 ms입니다. 설정, 페어링, 펌웨어 또는 조명 명령은 전혀 전송하지 않습니다.

유효한 배터리 응답을 받지 못하면 드라이버는 아무것도 보고하지 않고 기기를 점유하지 않은 채로 둡니다. USB 컬렉션이 유지되는 동안 UI는 기존 유예 기간 동작을 사용해 이전에 성공한 측정값을 최대 30분 동안 흐리게 유지합니다. 물리적 컬렉션이 사라지면 드라이버는 해당 유예 기간을 즉시 끝내기 위해 연결 끊김 상태를 한 번 내보냅니다. 이렇게 하면 케이블을 마우스로 옮겨 꽂았을 때 오래된 수신기 아이콘이 계속 남아 있는 현상을 방지합니다.

## 테스트

`make test`에는 시뮬레이션된 HID 전송 계층에 대해 프로덕션 드라이버를 링크하는 `tests/vaxee_driver_test.cpp`가 포함되어 있습니다. 이 테스트는 정확한 송신 읽기 전용 요청, 백분율 변환, 충전 디코딩, 잘못되거나 누락된 응답, 이미 점유된 기기 및 정확한 컬렉션 필터링을 검증합니다.
