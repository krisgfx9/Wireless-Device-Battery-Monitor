<!--
  Pełne tłumaczenie dokumentacji BatteryHub (Polski)
  Źródło: docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Języki:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | **Polski** | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Dodaj język](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Pełna dokumentacja (Polski)

> Ten pojedynczy, samodzielny plik Markdown gromadzi wszystkie widoczne dokumenty z repozytorium, dzięki czemu tłumacze muszą utrzymywać tylko **jeden plik na język**.

## Spis treści

1. [Przegląd BatteryHub, obsługiwane urządzenia, instalacja, wiersz poleceń i kompilacja (`README.md`)](#sec-readme)
2. [Przewodnik dla współtwórców (`CONTRIBUTING.md`)](#sec-contributing)
3. [Szablon Pull Requesta (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Przewodnik wydawania i podpisywania wersji (`docs/releasing.md`)](#sec-releasing)
5. [Łatka oprogramowania układowego klawiatur Keychron dla odbiornika 2,4 GHz (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [Obsługa GameSir Cyclone Pro przez BLE (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Przewodnik wielojęzyczności i lokalizacji (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Odbiornik Areson 25A7 (`docs/areson.md`)](#sec-areson)
10. [Odbiornik DARKRIM SHADOW (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Odbiornik Inphic IN10 / KP 8K (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Obsługa baterii myszy Rapoo (`docs/rapoo.md`)](#sec-rapoo)
16. [Uwagi o protokole RAWM (`docs/rawm.md`)](#sec-rawm)
17. [Odbiorniki VAXEE 4K/8K (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Sekcja:** Przegląd BatteryHub (`README.md`) · [Oryginał angielski](../../README.md) · [↑ Na górę](#top)

# BatteryHub

*Wcześniej znane jako **Wireless Battery**. Wersja 1.1.0 zmieniła nazwę aplikacji; aktualizacja zachowuje Twoje ustawienia, wybór autostartu oraz historię baterii.*

[![Wesprzyj mnie na Ko-fi](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Wesprzyj przez PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Dołącz do naszego Discorda](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Gwiazdka na GitHubie](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Udostępnij na Reddicie](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Zgłoś urządzenie](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Pomóż w tłumaczeniu](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Poziomy baterii Twojej bezprzewodowej myszy, słuchawek, klawiatury i kontrolera — bezpośrednio na pasku zadań systemu Windows.

![BatteryHub na pasku zadań](../screenshot.png)

> **Chcesz po prostu zacząć?** Pobierz **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** z najnowszego wydania, uruchom instalator i przeklikaj go dalej. To wszystko.
>
> **Zaawansowani użytkownicy** mogą pobrać przenośne archiwum ZIP, skorzystać z [opcji wiersza poleceń](#wiersz-poleceń) lub [skompilować aplikację ze źródeł](#kompilacja) za pomocą `make` albo `build.bat`.
>
> **Podoba Ci się?** BatteryHub jest darmowe i otwartoźródłowe. Jeśli oszczędza Ci otwierania oprogramowania producentów, możesz wesprzeć projekt na [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) lub [GitHub Sponsors](https://github.com/sponsors/krisgfx9). Pomaga mi to utrzymywać moje aplikacje za darmo równolegle ze studiami. Nie możesz wesprzeć finansowo? Gwiazdka ⭐, udostępnienie projektu albo zgłoszenie nieobsługiwanego urządzenia z wynikiem `--dump` pomaga równie bardzo.

- **Niewielki rozmiar**: aplikacja ma ok. ~350 KB i zużywa około 2 MB pamięci RAM. Napisana w czystym C++/Win32, bez dodatkowych środowisk uruchomieniowych i bez usługi działającej w tle; instaluje się w kilka sekund bez uprawnień administratora.
- **Bez oprogramowania producentów**: komunikuje się bezpośrednio z urządzeniami. G HUB, Synapse, iCUE, GG oraz NGenuity mogą pozostać zamknięte (lub działać w tle — nie kolidują ze sobą).
- **Wiele marek**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, kontrolery PlayStation i Xbox, Samsung Galaxy Buds, każde urządzenie Bluetooth, dla którego system Windows zna poziom baterii, oraz wszystkie słuchawki obsługiwane przez dołączony projekt [HeadsetControl](https://github.com/Sapd/HeadsetControl).

## Wyświetlanie

**Na pasku zadań (domyślnie):** `🎧 30%  🖱 93%` obok obszaru powiadomień, rysowane za pomocą czcionki ikon systemu Windows.
- **Słaba bateria:** czerwona liczba oznacza 15% lub mniej.
- **Ładowanie:** obok liczby pojawia się niebieska ikona ⚡. Gdy urządzenie jest w pełni naładowane i nadal podłączone do zasilania, zmienia się w zielony symbol ✓.
- **Uśpienie:** przyciemniony tekst oznacza, że urządzenie jest uśpione i wyświetlana jest ostatnia znana wartość.
- **Rozłączone (opcjonalnie):** włącz *Pokazuj rozłączone urządzenia*, aby wyświetlać przyciemniony symbol `×` dla urządzeń, których sterownik jawnie zgłasza brak połączenia bezprzewodowego. Nie wnioskuje to rozłączenia na podstawie pominiętego odczytu baterii; domyślnie urządzenia offline pozostają ukryte.
- **Dwa urządzenia tego samego rodzaju:** przy dwóch myszach (lub dwóch kontrolerach...) oba otrzymałyby tę samą ikonę, więc każde dostaje w rogu ikony drobny podpis o długości do 3 liter pochodzący z jego nazwy (`MX`, `PRO`), lub numer, jeśli nazwy ich nie rozróżniają. Pojedyncze urządzenie danego rodzaju nie wyświetla podpisu.
- **Motyw:** dopasowuje się do jasnego/ciemnego trybu systemu oraz skalowania DPI.
- **Przezroczyste motywy paska zadań** (np. Windhawk Taskbar Styler): włącz *Tło za tekstem na pasku zadań* w menu, aby napisy pozostały czytelne na tle tapety.
- **Wiele monitorów:** widżet wyświetla się na pasku zadań każdego monitora obok zegara, dzięki czemu pozostaje widoczny podczas gry na pełnym ekranie. Opcja *Pokaż widżet na* w menu pozwala wybrać *Wszystkie monitory*, *Tylko monitor główny* lub jeden konkretny ekran (np. tylko *Ekran 3*).
- **Więcej opcji wyświetlania:** *Ikony nad procentami* układa każdą ikonę nad wartością procentową, aby zmniejszyć szerokość; *Kolory marek* pokazuje znane marki w ich kolorze (zieleń Razer, czerwień HyperX, ...) z małym paskiem poziomu; dwa urządzenia tego samego rodzaju dostają drobny podpis ułatwiający rozróżnienie; paski zadań po lewej i prawej stronie wyświetlają urządzenia w kolumnie.
- **Języki:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 oraz 繁體中文. Zarówno aplikacja dla systemu Windows, jak i dla systemu Linux dopasowuje się do języka wyświetlania systemu; pozycja *Język* w menu pozwala wybrać inny, a instalator systemu Windows również obsługuje wszystkie 19 języków. Komunikaty interfejsu znajdują się w edytowalnych statycznych plikach `lang/*.json`, a kompletna przetłumaczona dokumentacja znajduje się w [`docs/i18n/`](README.md). Zobacz [Tłumaczenia](#tłumaczenia), aby edytować lub dodać język.
- **Kolory marek:** urządzenia 15 znanych marek otrzymują kolor swojego producenta z delikatną poświatą oraz cienkim paskiem poziomu pod
  wartością procentową: zieleń Razer, błękit Logitech, pomarańcz SteelSeries, żółć Corsair, czerwień HyperX / ROG / ZOWIE, PlayStation,
  Xbox, Samsung, Apple, Jabra, JBL, Cooler Master oraz Steam. Każdy kolor ma odcień dla ciemnego i jasnego paska zadań. Marka
  jest określana na podstawie sterownika, który wykrył urządzenie, następnie identyfikatora producenta (VID), a potem nazwy; kolory i reguły znajdują się w
  `src/brands.cpp`. Funkcję można wyłączyć opcją *Kolory marek* w menu.

**Ikony w zasobniku:** jedna ikona na urządzenie z wpisaną wartością liczbową oraz powiadomienie „Słaba bateria” przy 15%. Aplikacja przełącza się w ten tryb automatycznie, gdy pasek zadań jest pionowy lub nie można go odnaleźć.

**Własne nazwy urządzeń:** otwórz podmenu urządzenia i wybierz *Zmień nazwę urządzenia...*, aby ustawić własną nazwę
(do 64 znaków). Nazwa jest widoczna w podpowiedzi/etykiecie widżetu paska zadań,
podpowiedzi i powiadomieniach w zasobniku oraz w menu urządzenia. Użyj *Przywróć oryginalną nazwę*,
aby przywrócić nazwę ze sterownika. Nazwy są przechowywane lokalnie w rejestrze systemu Windows
bieżącego użytkownika (`Software\WirelessBattery`, `DeviceAliases`) pod stałym
kluczem urządzenia. Zmiana nazwy nigdy nie wpływa na dopasowanie sterowników, zapytania protokołów ani wynik diagnostyczny `--list` /
`--dump`. Nie wymaga konta ani dostępu do sieci.

Najedź kursorem, aby zobaczyć szczegóły. Kliknij, aby otworzyć menu: każde urządzenie (kliknięcie ukrywa lub pokazuje je), tryb wyświetlania, *Odśwież teraz*, *Uruchamiaj z systemem Windows* oraz *Zakończ*. Poziomy są odświeżane co 60 sekund (zmienisz to w menu opcją *Sprawdzaj baterię co*) oraz natychmiast po podłączeniu urządzenia lub wybudzeniu komputera.

## Inteligentne powiadomienia o baterii (eksperymentalne)

W podmenu każdego urządzenia możesz ustawić **indywidualny próg powiadomienia o niskim poziomie baterii**:
**Powiadomienia o baterii** → *Domyślnie (15%)*, *Wyłącz powiadomienia*
lub jedną z wartości: 5%, 10%, 15%, 20%, 25%, 30%, 35%, 40%. Dotychczasowa domyślna wartość 15% pozostaje
bez zmian, chyba że wybierzesz inne ustawienie. Ustawienia są zapisywane według klucza urządzenia w
rejestrze systemu Windows bieżącego użytkownika (`Software\WirelessBattery`, `AlertThresholds`).

Powiadomienie jest wyzwalane wyłącznie na podstawie rzeczywistego, świeżego odczytu baterii z zakresu 0–100%, gdy
urządzenie jest połączone, wybudzone i nie ładuje się. Powiadomienie pojawia się raz i uzbraja się
ponownie dopiero wtedy, gdy poziom baterii wzrośnie o ponad 10 punktów procentowych powyżej wybranego
progu (lub gdy rozpocznie się ładowanie). Brakujące odczyty ani uśpione urządzenia nie wywołują
ponownych alertów. Ukryte urządzenia nie generują powiadomień. Wyłączenie
powiadomień dla jednego urządzenia nie ukrywa go ani nie zmienia jego wartości procentowej.

Zarówno tryb widżetu paska zadań, jak i tryb ikon w zasobniku obsługują powiadomienia. Ponieważ system Windows
wymaga ikony w obszarze powiadomień do wyświetlenia klasycznego dymku, tryb widżetu może
tymczasowo pokazać ikonę powiadomień na maksymalnie jedną minutę po wyświetleniu alertu.
Kolory widżetu oraz wyróżnienie słabej baterii nadal korzystają z pierwotnego,
globalnego progu 15% projektu, niezależnie od ustawień powiadomień.

## Historia baterii i statystyki

Kliknij prawym przyciskiem myszy urządzenie w widżecie paska zadań lub menu zasobnika i wybierz **Historia baterii...**.
Natywne okno podglądu obsługujące skalowanie DPI (dopasowujące się do jasnego/ciemnego motywu Windows) wyświetla zapisane poziomy baterii połączone liniami próbek z ostatnich **24 godzin**, **7 dni** lub **30 dni**, wraz z ostatnim odczytem, wartością najniższą/najwyższą, zmianą w punktach procentowych oraz liczbą odczytów. Historię wybranego urządzenia można wyczyścić z poziomu okna podglądu.

Historia jest zapisywana **wyłącznie lokalnie** dla połączonych, wybudzonych urządzeń zgłaszających liczbowy procent naładowania. Odczyty są próbkowane najwyżej raz na 30 minut na urządzenie (z wyjątkiem zmian stanu ładowania, przy minimum 60 sekund). Dane są przechowywane do 30 dni, a lokalny plik nie przekracza około 2 MB. Aplikacja nigdy nie odpytuje sprzętu ponad istniejący harmonogram odświeżania, nie wysyła danych historii przez sieć i wylicza ostrożny, przybliżony czas do rozładowania wyłącznie na podstawie ostatnich obserwacji rozładowywania. Wymagane są co najmniej cztery punkty pomiarowe, dwie godziny, spadek o trzy punkty procentowe, świeży odczyt oraz stabilny odcinek rozładowywania. Ładowanie, stare odczyty lub niewystarczająca ilość danych ukrywają szacowanie; czas pracy zgłaszany przez samo urządzenie nie jest dostępny. Szacunek nie stanowi gwarancji. Brakujące dane wykresu są wyświetlane jako luki, bez interpolacji.

Wyłącz **Zapisuj historię baterii** w menu, aby zatrzymać zapisywanie odczytów; wcześniej zapisane dane pozostaną do momentu ich wyczyszczenia w oknie podglądu. Plik znajduje się w `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Identyfikatory urządzeń w pliku są zakodowane (niezaszyfrowane); plik jest lokalny dla Twojego konta Windows. W trybie `--demo` wykres korzysta z danych syntetycznych, które nigdy nie są zapisywane. **Uwaga:** zbieranie historii rozpoczyna się dopiero po zainstalowaniu tej funkcji i dłuższym działaniu aplikacji.

## Obsługiwane urządzenia

| Producent | Urządzenia | Sposób odczytu |
|---|---|---|
| **NuPhy** | WH80 przez kabel USB (`19F5:A011`) lub Bluetooth (`19F5:324A`), przetestowane sprzętowo | USB: zapytanie NuPhyIO o baterię tylko do odczytu; Bluetooth: poziom baterii systemu Windows z klasyfikacją jako klawiatura ([uwagi o protokole](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) na swoim odbiorniku USB `3654:6901` (przetestowane sprzętowo) | Zapytanie o baterię i flagę ładowania tylko do odczytu z sumą CRC; zaobserwowano zgrubne odczyty co 10%, dokładniejsza precyzja niezweryfikowana ([uwagi o protokole](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX na odbiorniku KP 8K (`1D57:FA65`; model `73` przetestowany sprzętowo, model `74` nieprzetestowany) | Pasywne raporty statusu Xenta; dwie zgodne ramki potwierdzają poziom ([uwagi o protokole](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, przetestowane), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` przetestowane, `002D`/`002A`), A50 Gen 3 (`9886:0015` przetestowane, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), przez stację bazową USB | Procent baterii, status ładowania i zadokowania |
| **Logitech** | Myszy i klawiatury na odbiornikach Unifying, Bolt, Lightspeed (w tym odbiornik PRO X3 SUPERSTRIKE `046D:C54F`) i Nano, przez USB lub Bluetooth; słuchawki G (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 na nowszym odbiorniku `046D:0ADF` | HID++ 1.0 / 2.0 z wykrywaniem funkcji: zunifikowana bateria, poziom baterii, napięcie, ADC; G435: raporty producenta w ramkach CRC-16, `GET_BATTERY` w mV |
| **Razer** | Bezprzewodowe myszy, klawiatury i odbiorniki; słuchawki BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X, V3 Pro for Xbox (odbiornik `1532:0A55`, kabel `0A4E`); Barracuda X (2022) na odbiorniku 2,4 GHz (`1532:0550` lub `1532:0552`); Barracuda Pro (`1532:053A`) | Protokół raportów funkcji (feature report) Razer; protokoły producenta BlackShark (V3 / V3 Pro / V3 X odpytywane co 5 min); Barracuda X: zapytania Airoha o baterię i kabel przez odbiornik |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (w tym `1038:225D`), Arctis Nova Elite (stacja bazowa `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, nieprzetestowana), Aerox 3 Wireless CS2 Dragon Lore Edition (odbiornik `1038:1878`, kabel `187A`), Aerox 3 Wireless Gen 2 (odbiornik `1038:1890`, kabel `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Raporty HID producenta; Aerox/Prime i Rival 650 współdzielą jeden wpis między odbiornikiem i kablem USB, preferując odczyt po kablu, gdy odpowiadają oba |
| **Corsair** | Bezprzewodowe Void / Void Pro / Void Elite / HS70 / HS80; urządzenia Bragi (Virtuoso, Void V2, HS80 MAX, myszy i klawiatury Slipstream, w tym nowszy odbiornik Slipstream `1B1C:2B00`, np. Scimitar Elite SE Wireless i Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, nieprzetestowana) | Raporty HID producenta, Bragi `GET` (tylko do odczytu), 17-bajtowy protokół baterii Compx (tylko do odczytu) |
| **Cooler Master** | MM712, MM731 (odbiornik 2,4 GHz lub kabel USB) | Raport statusu HID producenta (tylko do odczytu) |
| **Press Play** | ICARUS V2 Nearlink na swoim odbiorniku 2,4 GHz `7768:6434` (sterownik przetestowany sprzętowo przy 90%; protokół przechwycony przy 100% i 90%) | Raport wyjściowy tylko do odczytu `06 05` na `FFB2:0001`; procent baterii w bajcie 14 odpowiedzi |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` dla PS, nieprzetestowane), Cloud Flight S, Cloud Stinger Core Wireless (w tym DTS `03F0:0A8E`, przetestowane), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (odbiornik 2,4 GHz), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (odbiornik 2,4 GHz) (odbiornik 2,4 GHz `03F0:0F98`, przetestowany; `0D97` nieprzetestowany) | Raporty HID producenta (Haste 2: [uwagi o protokole](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Raport funkcji (feature report) producenta |
| **Hitscan** | Hyperlight X, Hyperlight N | Raport funkcji producenta (ten sam protokół co Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, bezprzewodowe myszy Pulsar i ATK VXE (np. VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (odbiornik 3554:F512) | Wspólny protokół producenta z odpowiedziami z sumą kontrolną |
| **Pulsar X2 V3** | X2 V3 na odbiorniku 1K (`3710:5402`) lub kablu USB (`3710:3402`); X2 V3 eS na odbiorniku 8K (`3710:5403`) lub kablu USB (`3710:3406`) | 64-bajtowy raport funkcji producenta, rejestr baterii `08 81 01` (tylko do odczytu) |
| **ATK / VXE NK** | VXE R1 NK i inne myszy NearLink na odbiorniku NK mouse NANO (`373B:1216`) | Raport wyjściowy ATK BITMOUSE 08 na `FF05:0001` (bateria i ładowanie) |
| **ATK 8K Nano** | Myszy ATK / VXE na odbiorniku ATK 8K Nano Dongle (`373B:1178`) | Raport funkcji Holtek GetConfigData (`82`) na `FF10:0001` (z ATK HUB; bateria i ładowanie) |
| **Słuchawki ATK** | ATK N9 Pro, N9 Ultra (pierwsza generacja) | Protokół wirtualnego portu COM (aplikacja desktopowa ATK musi być zamknięta) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK oraz ich odbiorniki 8K | Protokół Glorious lub Kysona, zależnie od modelu |
| **Myszy Keychron** | M4 i inne myszy Keychron na odbiorniku 2,4 GHz; myszy 4K (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) na odbiorniku Keychron 4K Link (`3434:D038`); myszy 8K (M5 8K, G6 HE 8K ...) na odbiorniku TurboLink 8K; myszy 8K na odbiorniku Ultra-Link 8K (`3434:D028`); starsze myszy (M1, M2, M3, M3 mini, M6, M7 ...) na odbiorniku 1K (`3434:D030` / `D031`); trackball Nape Pro na odbiorniku Link-KM lub kablu | Raport producenta z Keychron Launcher (odbiornik 1K: raport funkcji 51 06, jak w aplikacji desktopowej Keychron; Ultra-Link 8K: raporty B5 03 / B3 06 na `FFC1`; Nape Pro: surowy HID A7 31) |
| **Klawiatury Keychron** | K5 Max (`3434:0A50`, przetestowana) na odbiorniku Keychron Link (`3434:D030`) lub kablu USB; inne bezprzewodowe klawiatury Keychron QMK po skompilowaniu z tą samą łatką | Surowy HID na `FF60:0061`: `B2` pyta odbiornik, która klawiatura jest sparowana, `A4` zwraca poziom, napięcie i ładowanie. **Wymaga zmodyfikowanego firmware klawiatury:** zobacz [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). Fabryczne firmware raportuje tylko przez Bluetooth |
| **CHERRY** | Klawiatura MX 3.0S Wireless na odbiorniku 2,4 GHz (`046A:00EA`, przetestowana) lub kablu USB (`046A:00E3`, przetestowana) | Zapytanie HID producenta `1A` na `FF1C:0092` (tylko do odczytu), ze stanem zasilania USB. Tryb Bluetooth jest obsługiwany przez wsparcie Bluetooth |
| **CHERRY** | Bezprzewodowa mysz Cherry XTRFY na odbiorniku 1K (`046A:0330`, przetestowana) | 17-bajtowy protokół baterii CompX (`08 03` status połączenia, `08 04` GetPower), takie samo ramkowanie jak Corsair Sabre V2 Pro (tylko do odczytu) |
| **Arbiter Studio** | Akitsu (odbiornik 8K `373E:000A`, kabel `373E:0009`), Akitsu 3950 (odbiornik 8K `373E:0039`, kabel `373E:0038`), Akitsu Medium (odbiornik 8K `373E:0067` i kabel `373E:0066`, oba przetestowane) | Raport funkcji producenta tylko do odczytu `0x83` na `FFFF:0000` z Arbiter Web HUB (bateria i ładowanie) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (kabel, odbiorniki 1K oraz 4K/8K) | Raport funkcji producenta z LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) na odbiorniku 4K; XM2we na oryginalnym odbiorniku (`3367:1961`) | Raport funkcji producenta `A1`, polecenie baterii `B4` (tylko do odczytu) |
| **Klawiatury ATK / VGN / Evision** | ATK V75X oraz klawiatury VGN / VXE (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) na wspólnym odbiorniku 2,4 GHz (`320F:5088`) lub kablu USB (`320F:5055`), rozpoznawane po nazwie produktu; klawiatury, których odbiornik `320F:5088` nazywa się „Wireless Gaming Keyboard”, np. Feker Alice80 (przetestowana) | Raport wyjściowy Evision `04`, polecenie baterii `1A` (z ATK HUB i VGN HUB); odpytywane przez odbiornik najwyżej raz na 10 minut |
| **Redragon (Evision)** | K1NG M999 (przetestowana) na odbiorniku 2,4 GHz `320F:226F`; identyfikator odbiornika może być współdzielony z innymi modelami | Ten sam protokół Evision co w klawiaturach ATK (raport `04`, polecenie `1A` na `FF1C:0092`), odpytywany przy każdym odświeżeniu; ładowanie widoczne na stacji magnetycznej; z podłączonym kablem USB odbiornik powtarza stary poziom bez stanu ładowania |
| **Audeze** | Maxwell na odbiorniku USB (`3329:4B19`) lub kablu USB-C (`3329:4B1A`); Maxwell 2 na odbiorniku USB (`3329:4B29`, przetestowane); identyfikatory Xbox nieprzetestowane | Raport producenta `06` / raport wejściowy `07`, atrybut baterii `0CD6` (pojedyncze zapytanie tylko do odczytu) |
| **ENDORFY** | Viro Wireless na odbiorniku 2,4 GHz (`3738:0072`, nieprzetestowane) | Zapytanie Airoha RACE „get battery” (`0CD6`) przez raport producenta `06` / raport wejściowy `07`, to samo zapytanie tylko do odczytu co w odbiornikach Audeze i Skullcandy; brak stanu ładowania |
| **Turtle Beach** | Stealth 700 Gen 3 na nadajniku USB (`10F5:2251`, przetestowane w HaloBattery; wersja PC `10F5:2262`, nieprzetestowana) lub własnym kablu USB słuchawek (`10F5:2253`) | RACE `0x9942` (włączenie klienta CoAP) oraz CoAP `GET /GSI` tunelowane w RACE `0x9902`, tak jak w Swarm II; bateria z klucza `240` (bez flagi ładowania) |
| **AKG** | N9 Hybrid na odbiorniku USB (`0ECB:20D9`, przetestowane) | Airoha RACE na `FF13:0001`: raport wyjściowy `06`, raport wejściowy `07`, atrybut baterii `0CD6` (pojedyncze zapytanie tylko do odczytu) |
| **NZXT** | Lift Elite Wireless na odbiorniku (`1E71:2101`) lub kablu USB (`1E71:2129`) | Odczyt producenta `4E 02 81 .. B0` (z przechwytów NZXT CAM) |
| **Poly / Plantronics** | Voyager 8200 UC i inne słuchawki przez adapter BT600 (`047F:02EE` / `02F7`) | Protokół get/set raportu `07`, pozycja baterii `0A 1A` (tylko do odczytu) |
| **WLMouse** | YING Magnesium (odbiornik YING 8K `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (odbiornik lub kabel; nie dotyczy Beast X 4K); Beast X V2 (odbiornik 8K `36A7:A856`); Beast G (odbiornik 8K `36A7:A860` lub kabel `36A7:A861`; nieprzetestowana) | Raport funkcji producenta, polecenie statusu `0x83` (YING: ten sam protokół co Glorious) |
| **Finalmouse** | UltralightX na odbiorniku 2,4 GHz (`361D:0100`, przetestowana); Starlight X na swoim odbiorniku (`361D:0300` / `0301`, przetestowana). Nie przez własny kabel myszy | Raporty producenta xpanel na `FF00`: żądania GET tylko do odczytu, następnie *wake/all* (`0xE0`); napięcie baterii na krzywej xpanel lub własny procent w Starlight X oraz stan ładowania |
| **VAXEE** | Mysz bezprzewodowa na odbiorniku VAXEE 4K (`3057:1002`) lub 8K (`3057:2002`, np. NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless przez kabel USB (`3057:1011`) | Raport funkcji producenta tylko do odczytu `0E` na `FF05:0001`; bateria w krokach co 5%, stan ładowania ([uwagi o protokole](#sec-vaxee)) |
| **Scyrox** | V12M na odbiorniku 2,4 GHz (`395A:0006`) | Odczyt profilu S-Center 2.0 (raport wyjściowy `08`, polecenie `01`) na `FF00:0002`; tylko bateria, bez stanu ładowania |
| **HECATE** | G5M PRO i inne myszy HECATE na tym samym odbiorniku oraz kabel USB `35BB:D3FA / D3FC / D3FD` | Protokół Kysona |
| **Redragon** | Myszy bezprzewodowe oparte na Compx: M916 Pro 1K (przetestowana), M913 Impact Elite (tri-mode), G49 (odbiornik lub kabel) | Protokół Kysona (odbiorniki Areson `25A7` są wymienione pod pozycją Areson) |
| **Taidu (钛度)** | TSG808 na odbiorniku 2,4 GHz Compx `3554:F5D5` (przetestowana) | Protokół Kysona |
| **Areson (Redragon)** | M915RGB-WL (przetestowana), oryginalna M913 Impact Elite i inne myszy na odbiorniku `25A7:FA07` / `FA08` | 17-bajtowy raport funkcji `GetPower`; poziom w krokach co 10% i flaga ładowania |
| **Ninjutso** | Sora V2 na odbiorniku 1K (`1915:AE1C`, przetestowana) lub kablu USB (`1915:AE11`, przetestowana); Ten Air (odbiornik `093A:EB01` i kabel USB `093A:E020`, przetestowana) / Ten (`093A:EB01` / `E020`, nieprzetestowana) | Raport funkcji NinjaForce `0x05` (`0x15` dla Sora V2) i `0x06` (`0x13`/`0x12`/`0x11` dla Ten / Ten Air) |
| **Sprime** | PM1 na odbiorniku 2,4 GHz (`1915:AC1C`, przetestowana; `1915:AD8C`) lub kablu USB | Ten sam raport funkcji 0x05, polecenie statusu 0x15, ze sterownika WWW Sprime (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 na odbiorniku RAWM HS Receiver (`1915:2346`, przetestowana); ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* oraz myszy SADES Dagger na swoich odbiornikach RAWM (`1915:232A`–`234B`) lub kablu USB | Zapytanie o informacje o urządzeniu RAWM HUB 2.0 przez odbiornik (JSON z % baterii i ładowaniem), tylko do odczytu ([uwagi o protokole](#sec-rawm)) |
| **AULA** | Bezprzewodowe klawiatury F75 / F87 Pro / F99 na odbiorniku 2,4 GHz | Ramka raportu 0x13, polecenie 0x4A, suma kontrolna (tryb Bluetooth i przewodowy nieprzetestowane) |
| **Myszy AULA** | X9 Ultra (przetestowana) na odbiorniku AULA-8K Dongle `320F:22A0`; ID odbiornika współdzielone z modelami V9 | Raport `04`, polecenie baterii tylko do odczytu `1A` między START `01` / END `02` na `FF1C:0092`; tylko 2,4 GHz |
| **Klawiatury SONiX (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (przetestowana), EPOMAKER EA75 (przetestowana), AULA F108 Pro na odbiorniku 2,4G `05AC:024F`; AJAZZ AK980 V2 na odbiorniku `0C45:FEFE`; AJAZZ AK820 Pro na odbiorniku `0C45:FDFD` lub `0C45:FEFE`; EPOMAKER P75 na `342D:E479` (nieprzetestowana sprzętowo) | Raport producenta `20 01` na stronie użycia FF60, suma kontrolna (tylko tryb 2,4G; brak wskazania ładowania) |
| **Dodatkowe odbiorniki SONiX (nieprzetestowane sprzętowo)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | To samo zapytanie o samą baterię `20 01`; wymagany dokładny VID:PID oraz kolekcja FF60:0061 z 33-bajtowymi raportami; tylko 2,4G, brak wskazania ładowania |
| **Klawiatury 36B0 (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB na odbiorniku 2,4G `36B0:3002` lub kablu USB `36B0:3009` (protokół przetestowany na obu przez zgłaszającego #343); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) na tym samym odbiorniku lub kablu (nieprzetestowane); URX Core75 na odbiorniku (potwierdzona w HaloBattery); EVO80 (nieprzetestowana) | Firmware PMO Hub: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` na stronie użycia FF60, z pmohub.cn. Firmware URX / VIA: VIA custom-get `08 00 07` (kanał 0, wartość 7), z URX HUB przez HaloBattery. Brak wskazania ładowania |
| **DAREU** | EM901X na odbiorniku 2,4 GHz `260D:1074` lub kablu USB `260D:1090` (odczyt baterii przetestowany na obu; przejścia flagi ładowania przy dokowaniu/wyjmowaniu z doku na odbiorniku przetestowane) | Raport funkcji tylko dla baterii `08`, polecenie `04`; odpowiedź `09` na osobnej kolekcji producenta. Wymaga jednej jednoznacznej pary wejście/funkcja na identyfikator produktu. Preferuje prawidłowy odczyt USB, gdy oba są podłączone; odbiornik może zwracać buforowaną telemetrię nawet przy wyłączonej myszy |
| **DAREU** | Klawiatura A84 (`260D:0022`, nieprzetestowana) | Raport funkcji SONiX na interfejsie 0, polecenie `04 F6` (odczyt baterii oficjalnego sterownika A84); poziom w procentach, bez flagi ładowania |
| **DAREU** | A980 Pro na wielomyszowym odbiorniku `260D:1131` i na swoim kablu USB (`260D:1148`) (poziom baterii przetestowany sprzętowo; flaga ładowania potwierdzona po podłączeniu kabla) | Protokół Togran: 65-bajtowy raport funkcji `0A` w kolekcji consumer-control; zapytanie o slot (klasa 0 / `A0`), potem zapytanie o baterię (klasa 7 / `80`), na slocie 0 po kablu. Tylko do odczytu |
| **Sharkoon** | Skiller SGM50W na `260D:1125` (nieprzetestowana) | To samo zapytanie Compx co w DAREU EM901X (raport funkcji `08`, polecenie `04`; odpowiedź `09` na `FF01:0000`); program aktualizujący firmware Sharkoon dla niej to narzędzie Compx na VID `260D` |
| **Zenith** | Zenith Pro na odbiorniku 2,4 GHz `260D:1114` (odczyt baterii przetestowany; ładowanie nieprzetestowane) lub kablu USB `260D:1143` (nieprzetestowana) | To samo polecenie Compx (`08`, `04`) jako raport wyjściowy na `FF02:0002`; odpowiedź `08 04` na tej samej kolekcji z procentem, flagą ładowania i miliwoltami, sprawdzana sumą bajtów `0x55` |
| **AJAZZ AK992** | Odbiornik 2,4 GHz Telink `320F:50C3` (przetestowana) | Zapytanie o baterię EVision w kolekcji HID `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, seria DW (U2-DW, S2-DW ...) i U2 na odbiorniku 2,4 GHz | Udokumentowane przez społeczność polecenia producenta tylko do odczytu |
| **Royal Kludge (RK)** | MG6 Pro na odbiorniku 2,4 GHz (`2E3C:00A6` / `00E6`) lub kablu USB (`2E3C:00A5` / `00E5`) | 64-bajtowa ramka QiWang ze sterownika WWW RK, odczyt `GET_BATTER_VOL` (procent, napięcie, ładowanie) |
| **ASUS ROG** | Klawiatury Strix Scope II 96 (RX), Azoth, Falchion; myszy Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact; słuchawki Pelta (odbiornik 2,4 GHz); słuchawki douszne Cetra Open Wireless (odbiornik SpeedNova `0B05:1CAC`, L / P / etui); odbiornik Omni Receiver | Zapytanie o baterię ROG HID |
| **Machenike** | L7 Arctic / L7 Mix na odbiorniku 2,4 GHz `248A:FF4C` lub kablu USB `248A:FF4E` (oba przetestowane) | Raport funkcji tylko do odczytu `51`, polecenie statusu `06`; bateria i ładowanie. [Uwagi o protokole](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS na odbiorniku 2,4 GHz (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (odbiornik 2,4 GHz `0DB0:0D3C`, przetestowana; kabel USB `0DB0:0D3B`) oraz CLUTCH GM41 Lightweight Wireless (odbiornik `0DB0:0D4C` / kabel `0DB0:0D4B`, na podstawie przechwytów właściciela) | Zapytanie producenta tylko do odczytu `0F 20` na `FF0D:00B0` i `FF00:0001`; bateria i flaga ładowania w jednym bajcie (protokół z modułu Gaming Gear w MSI Center); GM41: pasywne raporty `A0 xx 07 …` na `FF10:0006` |
| **MCHOSE** | Myszy L7 / L7 Pro / L7 Ultra (L7 Ultra przetestowana), M7 / M7 Ultra, A7 / A7 Ultra, K7 na odbiorniku 2,4 GHz lub kablu USB; A5 V2 Ultra (odbiornik 2,4 GHz `3837:100C`, przetestowana), K7 Ultra (odbiornik 2,4 GHz `3837:1001`, przetestowana; A7 V2 Ultra+ `3837:100B` powinna działać, zgłoszenie 227); G3 V2 (odbiornik 2,4 GHz `3837:4245` i kabel USB `3837:418C`); K7 V2 Ultra+ na odbiorniku 2,4 GHz `3837:1014` lub kablu USB `3837:4028` (oba przetestowane; pozostałe identyfikatory odbiorników nowej rodziny `1018`, `1016`, `102C`, `102D` są nieprzetestowane) | Raport funkcji producenta, odwrócony ładunek (protokół z alexfrih/mchose-linux); odbiorniki Realtek `3837` odpowiadają na to samo zapytanie z polem vid ustawionym na `41E4` (A5 V2 Ultra) lub `3837` (K7 Ultra); G3 V2: zapytanie producenta tylko do odczytu na `FF01:0010`; K7 V2 Ultra+: 64-bajtowy raport `0x4D`, polecenie info o urządzeniu `0x0900` na `FF01:0001` (protokół ze sterownika WWW M HUB) |
| **MCHOSE A5 (pierwsza generacja)** | A5 Pro / A5 Pro Max na odbiorniku 2,4 GHz 1K lub 4K (`2023:F013`, `2023:F015`, `2023:F018`) lub kablu USB (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); nieprzetestowana u nas | Polecenie baterii tylko do odczytu `0x83` (strona 0) w 64-bajtowym raporcie funkcji na `FFFF`, odpowiedź oznaczona `0xA1` (protokół ze sterownika WWW z750sasr A5 Pro Max i HaloBattery, identyfikatory z Klegus/mchose-macos) |
| **Słuchawki MCHOSE** | V9 Pro 2 na odbiorniku 2,4 GHz (`3837:6011`, przetestowane) | Ramka baterii „MC” tylko do odczytu z M HUB (raport `0x55`, podpolecenie `0x0B`) na `FF07:0222`; bateria i flaga ładowania w jednym bajcie (protokół ze sterownika WWW M HUB) |
| **Klawiatury AULA / MCHOSE / Redragon** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 i inne klawiatury M HUB; Redragon Horus Pro / Pro V2 (K618RGB-PRO) na odbiorniku 2,4 GHz (`3554:FA09`, `41E4:2001`); MCHOSE K87 na odbiorniku `05AC:024F` (układ BY na interfejsie 1, nie SONiX) | Ramka raportu 0x13, polecenie 0x4A (modele MCHOSE i Redragon identyfikowane poleceniem 0x05, jak w M HUB); tryb Bluetooth i przewodowy nie są objęte |
| **Klawiatury MCHOSE** | G75 V2 na odbiorniku 2,4 GHz `3837:3033` (przetestowana); ten sam odbiornik jest dostarczany z G87 V2 i K99 V3 (ten sam protokół, nieprzetestowane); K87S łączy ten sam identyfikator odbiornika z innym protokołem i nie jest obsługiwana | Zapytanie func-config „GLW” tylko do odczytu z M HUB na bezidentyfikatorowej 64-bajtowej kolekcji `0001:0000`: flaga żądania `0x55`, polecenie `0x05`, bateria w bajcie 32 ładunku (bit 7 = ładowanie), suma kontrolna addytywna |
| **AULA SC580** | Mysz SC580 / SC580X przez kabel USB (`088D:062E`, przetestowana) lub odbiornik 2,4 GHz (`089D:062F`, przetestowana) | Polecenie tylko do odczytu `0x30` (informacje o urządzeniu) w 33-bajtowej kolekcji producenta FF02:0000, suma kontrolna; podczas ładowania mysz zgłasza stałe 100, więc wyświetlany jest ostatni poziom; tryb Bluetooth nie jest objęty |
| **AULA HERO 68 Air** | HERO 68 Air na odbiorniku 8K Wireless Receiver (`372E:106C`) | Potwierdzane 20-bajtowe ramki na stronie użycia FF60 (cztery ramki danych i stopka na komunikat), polecenie baterii tylko do odczytu 0x87, flaga ładowania 0x10 po poziomie; tryb Bluetooth i przewodowy nie są objęte |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra oraz S9 Max / Pro / Ultra / Ultra+ na odbiorniku „Gaming 2.4G” (`372E:103D`); S9 Ultra na kablu USB (`372E:1027`) | Raport funkcji tylko do odczytu `03` na `FF00:0001`: sprawdzenie łącza `47`, podstawowe dane urządzenia `4F 81` (procent baterii i bit ładowania), ze sterownika WWW EWEADN |
| **Rapoo VT** | VT3 Max Gen 2 (przetestowana); VT9 Gen 2 (przetestowana); inne myszy Nordic 54L VT udostępniające ten sam interfejs statusu; starsza VT3 Pro (eksperymentalnie); VT1 Pro Max (z przechwytów USB właściciela) | Pasywny raport statusu HID `07` na `FF00:0002` (16 lub 19 bajtów; 13 bajtów w niektórych odbiornikach VT3 Max Gen 2); starsze `BB` ograniczone do VT3 Pro `1215/4415` oraz VT1 Pro Max `1233/4433`. Odbiornik i kabel USB, ze stanem ładowania |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (modele Xenta 30/50; starsze 3D), Delux M800 Pro, rodzina Ajazz AJ179; AJ159 i inne myszy serii AJ na odbiorniku 3151; AJ139 V2 MC (odbiornik `A8A5:2255`, kabel `A8A4:2255`) | Raporty producenta (M900 Pro: pasywne rozgłoszenia statusu lub zapytanie funkcji, zdarzenia Xenta 40/41; seria AJ: odpytanie statusu 0xF7, potem raport funkcji 0x05) |
| **Incott** | G23 V2 / G24 (odbiornik `093A:522C`, kabel `093A:622C`) | Raport funkcji statusu tylko do odczytu 09 |
| **Attack Shark i inne chińskie marki** | Odbiorniki Rongyuan (81 modeli: Attack Shark R3 i AJAZZ AJ179 Pro na `3151:402D`, K86, X82 PRO HE, klawiatury Ajazz, niektóre MSI i inne; K86 przez Bluetooth wyświetla się jako klawiatura); odbiorniki Xenta (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; X6 także na `1D57:FA61`, nieprzetestowana); klawiatury Semico 1A2C (Attack Shark X98 na odbiorniku `1A2C:8FFF`, przetestowana, i kablu `1A2C:A034`; AJAZZ AK820 Max Plus na `1A2C:8FFF` / `1A2C:A036`) | Raport statusu Rongyuan; pasywne rozgłoszenia Xenta; zapytanie o status Semico tylko do odczytu `0x0E` (`AA 55 CC 33` na `FF02:0002`; flaga ładowania pominięta, ponieważ X98 zgłasza `state=1` zarówno na baterii, jak i podczas ładowania) |
| **Wraith** | W1 / W1 Freestyle (odbiornik `093A:522C`, kabel `093A:622C`; te same identyfikatory co Incott, rozróżniane kodem modelu) | Odczyty przypisań przycisków tylko do odczytu `86` (raport funkcji 09) dla wszystkich przycisków, następnie wypychany raport wejściowy statusu 09 |
| **Fantech** | Helios Go XD5 (przewodowa `25A7:FA7B`, odbiornik `25A7:FA7C`); Raigor III (przetestowana), Raigor II WG10 i inne ogólne urządzenia 2.4G Mouse na współdzielonym odbiorniku `1EA7:0066` / `1EA7:0064` | Helios Go XD5: raport funkcji producenta `08`, polecenie `04`, suma kontrolna sumująca się do `0x55`. Raigor/2.4G Mouse: zapytanie tylko do odczytu o stronę statusu `B5` na `FFB5:0001`, fragment `94` = ostatni zgłoszony procent (może być nieaktualny w uśpieniu, po wyłączeniu lub podczas ładowania; brak stanu ładowania) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, adapter bezprzewodowy); słuchawki INZONE H9 II i H5; INZONE Buds (odbiornik USB-C) | Raport wejściowy; protokół producenta INZONE |
| **Fractal Design** | Słuchawki Scape na odbiorniku 2,4 GHz lub kablu USB-C | Zapytanie producenta `GET_DEVICE_STATE` z aplikacji WWW Fractal Adjust Pro (strona użycia FF00) |
| **Jabra** | Wszystkie słuchawki Jabra używające protokołu GN (Evolve2 / Evolve3 i inne), na własnym kablu USB lub za odbiornikiem Jabra Link; brak listy identyfikatorów produktów, pominięte bazy DECT (Engage, PRO 9xx, GO 6400, Link 400); nazwa odczytywana ze słuchawek | Zapytanie o status GNP (klasa 12 / op 02) na stronie użycia FF00, użycie 05 lub 01, pod adresem GNP 08 (USB) lub 04 (odbiornik) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), odbiornik 2,4 GHz lub USB; Apex 5 (`37D7:2501`), odbiornik 2,4 GHz lub USB | Zapytanie HID producenta o informacje na `FFA0:0001`; poziom baterii 0–5 mapowany na 0–100% w krokach co 20%, ze stanem ładowania; nie wymaga usługi Space Station |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite na odbiorniku 2,4 GHz; Nova 2 Lite przez USB; G7 Pro (przetestowany: edycja Zenless Zone Zero, odbiornik `3537:105E`) i inne pady GameSir w trybie Xbox (GIP); Cyclone 2 (tryb XInput, odbiornik lub kabel); Cyclone Pro na odbiorniku 2,4 GHz (`3537:1015`, sparuj pada z systemem Windows przez Bluetooth jednorazowo) | Zapytanie producenta o informacje o urządzeniu (strona użycia FF7A); raport baterii Windows.Gaming.Input (rzeczywisty %) w trybie Xbox; Cyclone 2: żądanie baterii producenta (strona użycia FFF0); Cyclone Pro: żądanie base-info aplikacji GameSir przez Bluetooth LE (usługa `0x8650`), odczytywane co 2 min |
| **BEITONG** | KP20 / BTP-KP20 na odbiorniku 2,4 GHz (`20BC:5128`, tryb XInput, przetestowany) oraz KP40D / BTP-KP40D na odbiorniku (`20BC:515C`, tryb XInput); BEITONG iControl nie jest wymagany | Zapytanie producenta „get base info” na stronie użycia `00FF` (raport `02`, ładunek z zamianą półbajtów), ze stanem ładowania |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` przetestowany na odbiorniku 2,4 GHz, D-input `2DC8:6012` — przytrzymaj B podczas włączania, firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Zapytanie o status HID producenta (`FF7A`/`FFA0`) i raport wejściowy gamepada SDL `01`/`04`, ze stanem ładowania |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Ramka statusu wysyłana przez słuchawki w usłudze RFCOMM (SPP) firmy Samsung, tylko do odczytu. Zasobnik pokazuje słuchawkę o niższym poziomie; podpowiedź wymienia lewą, prawą i etui. Aplikacja Galaxy Buds musi być zamknięta |
| **Nothing / CMF** | Nothing Ear (3a) (przetestowane), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Zapytanie o baterię tylko do odczytu `0xC007` w usłudze NT Link RFCOMM firmy Nothing (`aeac4a03-dff5-498f-843a-34487cf133eb`). Zasobnik pokazuje słuchawkę o niższym poziomie; podpowiedź wymienia lewą, prawą i etui |
| **Akko** | Akko Air 01 (`3151:5006`, odbiornik 2,4 GHz, przetestowana) oraz Akko V9 Dash Pro (`38EE:000C`, odbiornik 2,4 GHz, przetestowana) | Air 01: raport statusu Rongyuan `0xF7`; V9 Dash Pro: 64-bajtowe zapytanie o status tylko do odczytu `0x1A` na `FF1C:0092` ze stanem ładowania |
| **MOONDROP** | Słuchawki GM01 Pro na odbiorniku 2,4 GHz (`35D8:0133`); na kablu USB pokazują ładowanie z ostatnim poziomem | Polecenie odczytu producenta WalkPlay w raporcie `4B` (tylko do odczytu) |
| **VGN** | Słuchawki OMNISOUND (ZHOUTING) na odbiorniku 2,4 GHz (`372E:10BB`, przetestowane) | Zapytanie V HUB „ZHOU”: raport wyjściowy `55` z ładunkiem `65 01` w kolekcji sterującej `000C:0001` (32-bajtowe raporty wejściowe, 64-bajtowe wyjściowe); procent wraca w odpowiedzi (tylko do odczytu) |
| **JBL** | Quantum 650 Wireless (przetestowane, odbiornik 2,4 GHz); Quantum 520, 650X, 850, 950, 950X Wireless (odbiornik lub kabel USB, ten sam protokół, nieprzetestowane) | Zapytanie o informacje o urządzeniu JBL „HIDV3” dla funkcji baterii (strona użycia FF12), ze stanem ładowania |
| **JBL** | Quantum 350 Wireless (przetestowane w Windows z odbiornikiem 2,4 GHz `0ECB:206B`); Quantum 610 Wireless (odbiornik 2,4 GHz `0ECB:205C`, nieprzetestowane w Windows); Quantum 360 Wireless (odbiornik 2,4 GHz `0ECB:2115`, nieprzetestowane) | Raporty funkcji HIDV1 dla połączenia bezprzewodowego i procentu baterii |
| **Xbox** | Kontrolery na adapterze Xbox Wireless, USB lub Bluetooth; słuchawki podłączone do kontrolera | Raport baterii Windows.Gaming.Input (rzeczywisty %), tryb awaryjny XInput |
| **Zgodne z Switch Pro** | Kontrolery przedstawiające się jako `057E:2009` (przetestowany: GameSir Tarantula Pro przez odbiornik 2,4 GHz w trybie Switch) | Pięć poziomów baterii z raportu HID `0x30` po włączeniu pełnych raportów przez Steam Input lub innego hosta |
| **Apple AirPods / Beats** | AirPods Max (przetestowane, `200A` Lightning i `201F` USB-C), AirPods Pro 3 (przetestowane, `2027`), AirPods Pro 1 / 2, AirPods 1–5 oraz słuchawki nauszne/douszne Beats | Rozgłoszenia BLE „proximity pairing” (`0x07`) (pojedyncza bateria dla AirPods Max i nausznych Beats; lewa, prawa i etui dla słuchawek dousznych, w krokach co 10% ze stanem ładowania), dopasowane do sparowanego modelu |
| **Telefony (Łącze z telefonem)** | Dowolny telefon z Androidem połączony z Łączem z telefonem firmy Microsoft, przez Wi-Fi lub Bluetooth (przetestowany: Nothing Phone (4a) Pro) | Stan baterii i ładowania z karty menu Start systemu Windows 11 dla Łącza z telefonem (`StartMenuCompanion.json`); nie wymaga Bluetooth |
| **Darmoshark** | M3 (`248A:FF30`) i M3S (`248A:FF31`) na ich odbiornikach 2,4 GHz w systemie Windows | Raport funkcji HID dla identyfikacji myszy i baterii |
| **Darmoshark** | M3S Pro na odbiorniku Nordic 1K (`1915:0723`) | Zapytanie o status HID producenta w kolekcji `FF0A` |
| **Alienware** | Słuchawki AW920H na odbiorniku 2,4 GHz (`413C:A515`, przetestowane); przez Bluetooth są obsługiwane w wierszu Bluetooth | Zapytanie producenta `06 C0 0A` na `FF13:0001`, raport odpowiedzi `07` z sumą kontrolną XOR; pola poziomu, ładowania i poziomu krytycznego zgodnie z dekodowaniem wtyczki AW920H w Alienware Command Center |
| **Niceboy** | MW400 na odbiorniku 2,4 GHz (`248A:FA02`, przetestowane) | Zapytanie raportu `05` tylko do odczytu `24 FA 48`; napięcie baterii mapowane na kroki co 10% z tabeli aplikacji producenta, flaga ładowania |
| **Bluetooth** | Wszystko, co wyświetla baterię w *Ustawienia → Bluetooth i urządzenia* (słuchawki douszne, nauszne, myszy i klawiatury BLE). Słuchawki douszne Google Fast Pair (przetestowane Jabra Elite 8 Active; Pixel Buds oraz wiele modeli Sony / JBL / Bose) pokazują też poziomy lewej, prawej i etui | Właściwość urządzenia w systemie Windows; rozgłoszenia baterii Fast Pair (dane usługi BLE `FE2C`), dopasowywane do sparowanego urządzenia po adresie Bluetooth |
| **Standardowy HID** | Urządzenia zgłaszające standardowe użycie HID *Battery Strength* | Strona użycia HID 0x06 / 0x85 |
| **HeadsetControl** | [Wszystkie obsługiwane słuchawki](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, nowsze Logitech i inne) | Dołączony w pakiecie; uruchamia `headsetcontrol -o json` |
| **MAONO PD200W** | Odbiornik 2,4 GHz (352F:040E) | Procent baterii; przetestowany sprzętowo |


**Przetestowane na rzeczywistym sprzęcie:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (odbiornik PlayStation `0951:1713`; ładowanie nieprzetestowane), HyperX Cloud Core Wireless DTS (odbiornik `0951:173F`; poziom pełnego naładowania nieprzetestowany), HyperX Pulsefire Haste 2 Core Wireless (odbiornik `03F0:0AB5`; odbiorniki Haste 2 Wireless są nieprzetestowane), Cooler Master MM712 (odbiornik), Rapoo VT3 Max Gen 2 (odbiornik `24AE:1417` i kabel USB `24AE:4617`; inne modele Rapoo nieprzetestowane, zobacz [uwagi o protokole Rapoo](#sec-rapoo)), Redragon M916 Pro 1K (odbiornik `3554:F55D`), Taidu TSG808 (odbiornik `3554:F5D5`), Redragon M915RGB-WL (odbiornik `25A7:FA07`; inne modele Areson nieprzetestowane, zobacz [uwagi o protokole Areson](#sec-areson)), SteelSeries Rival 650 Wireless (odbiornik `1038:1726` i kabel USB `1038:172B`), SteelSeries Arctis Nova Pro Wireless (stacja bazowa `1038:225D`; odczyt baterii przetestowany, ładowanie i przejścia zasilania nieprzetestowane), HECATE G5M PRO (odbiornik `35BB:D3FB`), WLMouse YING Magnesium (odbiornik 8K `36A7:A874`), ATK N9 Ultra (odbiornik `373B:1204`), Corsair Scimitar Elite SE Wireless (odbiornik Slipstream `1B1C:2B00`), Corsair Dark Core RGB Pro SE (odbiornik Slipstream `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (odbiornik 2,4 GHz `1B1C:2B2A`; odczyt baterii zweryfikowany), DAREU EM901X (odbiornik `260D:1074`; ładowanie i uśpienie/wybudzenie nieprzetestowane), Jabra Evolve3 75 na Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (odbiornik `3837:4245` i kabel USB `3837:418C`), MCHOSE K7 Ultra (odbiornik `3837:1001`), MCHOSE K7 V2 Ultra+ (odbiornik `3837:1014` i kabel USB `3837:4028`; ładowanie widoczne przy podłączeniu kabla), MSI VERSA 300 ELITE WIRELESS (odbiornik `0DB0:9E22`; obsługa ładowania i uśpienia nieprzetestowana), MSI Clutch GM31 Lightweight Wireless (odbiornik `0DB0:0D3C`; GM41 używa tego samego sterownika z przechwytów właściciela), AJAZZ AK820 MAX (odbiornik `05AC:024F`), AULA HERO 68 Air (odbiornik 8K Wireless Receiver `372E:106C`), AULA SC580 (kabel USB `088D:062E` i odbiornik `089D:062F`, w tym ładowanie i uśpienie), AirPods Pro 3 (Bluetooth, model `2027`), AirPods Max (Bluetooth, model `200A`), Sprime PM1 (odbiornik `1915:AC1C`), Ninjutso Ten Air (odbiornik `093A:EB01` i kabel USB `093A:E020`), MOONDROP GM01 Pro (odbiornik `35D8:0133`), Delux M800 Pro (odbiornik `248A:5B2F`), Razer Barracuda X (2022) (odbiornik `1532:0550`; odczyt poziomu baterii, przejścia ładowania nieprzetestowane), Razer BlackShark V3 X (odbiornik HyperSpeed `1532:057D`), Fantech Helios Go XD5 (odbiornik `25A7:FA7C`), Fantech Raigor III (odbiornik `1EA7:0066`; ładowanie nie jest zgłaszane przez firmware), Finalmouse UltralightX (odbiornik `361D:0100`), Finalmouse Starlight X (na odbiorniku) oraz Chimera V2 (odbiornik `3554:F512`; odczyt poziomu baterii i ładowania).
Przetestowane sprzętowo również: Machenike L7 Arctic / L7 Mix (odbiornik `248A:FF4C` i kabel `248A:FF4E`), w tym ładowanie i tłumienie duplikatów kabla/odbiornika. Bluetooth oraz progi niskiej/pełnej baterii nie były testowane sprzętowo.
Przetestowane sprzętowo również: MCHOSE V9 Pro 2 (odbiornik `3837:6011`); odczyt poziomu baterii, ładowanie i uśpienie nieprzetestowane.
Przetestowane sprzętowo również: EPOMAKER EA75 na odbiorniku 2,4 GHz `05AC:024F` przy użyciu istniejącego sterownika SONiX z [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). Zweryfikowano procent baterii, ponowne połączenie z odbiornikiem i odzyskanie po włączeniu zasilania. Wskazanie ładowania i raportowanie baterii po kablu nie są obsługiwane przez ten sterownik; raportowanie baterii przez Bluetooth nie było testowane. Zgłaszany procent może skoczyć do 100% po podłączeniu zasilania USB, co nie jest wiarygodnym wskaźnikiem ładowania.
Przetestowane sprzętowo również: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (odbiornik `1038:1878` i kabel USB `1038:187A`), w tym ładowanie, wyłączanie (ostatni poziom pozostaje przyciemniony) oraz działanie przy uruchomionym SteelSeries GG; GG pokazuje tylko trzystopniowy pasek, z którym poziom był zgodny.
Przetestowane sprzętowo również: RAWM Leviathan V4 (odbiornik RAWM HS Receiver `1915:2346`; odczyt poziomu baterii, ładowanie nieprzetestowane).
**Zaimplementowane na podstawie dokumentacji protokołów i innych projektów, jeszcze nieprzetestowane:** cała reszta, w tym Fantech Raigor II WG10 (ten sam odbiornik `1EA7:0066` i kolekcja co w przetestowanym Raigor III, więc powinien działać). Jeśli posiadasz któreś z tych urządzeń, zgłoś, czy działa, [otwierając zgłoszenie (issue)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues).

## Instalacja

[![Najnowsza wersja](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Pobierz **`BatteryHub-Setup-<version>.exe`** z [najnowszego wydania](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. Uruchom instalator, wybierz dowolny z 19 obsługiwanych języków instalacji i przeklikaj go dalej. Nie wymaga **uprawnień administratora** ani **żadnego innego oprogramowania**: żadnych
   środowisk uruchomieniowych, sterowników ani aplikacji producentów. HeadsetControl jest dołączony w pakiecie, a edytowalny folder `lang\` jest instalowany obok `BatteryHub.exe`.

Instalator dodaje wpis w menu Start oraz deinstalator (*Ustawienia → Aplikacje*), i może uruchamiać aplikację
po zalogowaniu. Wolisz wersję bez instalatora? Pobierz `BatteryHub-<version>-portable.zip`, rozpakuj go
w dowolnym miejscu (zachowaj folder `lang\` obok `BatteryHub.exe`, aby działały tłumaczenia interfejsu) i uruchom `BatteryHub.exe`.

**Uwagi:**
- **Ostrzeżenie SmartScreen:** plik exe nie jest podpisany cyfrowo, więc system Windows może wyświetlić komunikat „System Windows ochronił ten komputer”. Kliknij *Więcej informacji → Uruchom mimo to* albo skompiluj program samodzielnie.
- **Tryb ikon w zasobniku w systemie Windows 11:** nowe ikony zasobnika trafiają do przepełnienia `^`. Przeciągnij je na pasek zadań lub włącz w *Ustawienia → Personalizacja → Pasek zadań → Inne ikony paska zadań*.
- **Wykluczenie urządzenia z odpytywania:** jeśli jakieś urządzenie zachowuje się nieprawidłowo podczas działania aplikacji, wpisz je w ciągu rejestru `IgnoreDevices` w gałęzi `HKCU\Software\WirelessBattery` jako pary `VID:PID` (szesnastkowo, rozdzielone przecinkami, np. `28BD:0947, 1234:ABCD`; polecenie `--dump` pokazuje identyfikatory). Aplikacja nigdy go wtedy nie otworzy. Tablety graficzne są pomijane automatycznie.

## Aktualizacje w systemie Windows

Oficjalne, stabilne kompilacje dla systemu Windows sprawdzają najnowsze opublikowane stabilne wydanie projektu w
tle: 30 sekund po uruchomieniu, a następnie co 24 godziny podczas działania aplikacji. Otwórz
menu, aby zobaczyć **Dostępna aktualizacja: vX.Y.Z...**, lub wybierz **Sprawdź aktualizacje...** ręcznie.
Informacje o aktualizacjach pojawiają się wyłącznie w tym menu: ikony baterii, wartości procentowe i podpowiedzi pozostają
bez zmian, a automatyczne sprawdzanie nigdy nie wyświetla powiadomień ani okien dialogowych. Wyłącz
**Automatycznie sprawdzaj aktualizacje** w menu, aby wyłączyć sprawdzanie w tle.

W przypadku zainstalowanej kopii kliknij wpis aktualizacji i wybierz **Pobierz i zainstaluj**. Bez tego kliknięcia
nic nie jest instalowane. Aplikacja pobiera plik `SHA256SUMS.txt` danego wydania oraz jego podpis, weryfikuje
podpis za pomocą klucza publicznego opiekuna projektu wbudowanego w aplikację, pobiera instalator systemu Windows
i uruchamia go tylko wtedy, gdy jego suma SHA-256 zgadza się z podpisaną listą (oraz z sumą podaną przez GitHub). Następnie
aktualizuje istniejącą instalację. Ustawienia i preferencja autostartu są
zachowywane, a aplikacja uruchamia się ponownie po zakończeniu instalacji. Instalacja dla wszystkich użytkowników może wymagać
uprawnień administratora. **Informacje o wydaniu** otwierają oficjalną stronę wydania; **Później** zachowuje
obecną wersję. Wersje przenośne kierują na stronę wydania w celu ręcznego pobrania archiwum ZIP.

Sprawdzanie łączy się z publicznym API serwisu GitHub bez konta ani tokena. Żadne informacje o urządzeniach ani baterii
nie są wysyłane. Błędy połączenia offline oraz limity zapytań GitHub nie przerywają monitorowania baterii; wcześniej
znalezione wydanie pozostaje w menu, dopóki pomyślne sprawdzenie go nie zastąpi lub nie zostanie zainstalowane.
Anulowanie pobierania czeka na zakończenie bieżącej operacji sieciowej w ramach jej ograniczonego limitu czasu.
Instalator nigdy nie uruchamia ponownie systemu Windows automatycznie.

**Dlaczego aktualizacje są bezpieczne:** klucz podpisujący nigdy nie trafia na GitHub. Opiekun projektu podpisuje
listę sum kontrolnych każdego wydania na własnym komputerze (zobacz [docs/releasing.md](#sec-releasing)), więc
nawet osoba, która przejęłaby konto GitHub lub jego proces budowania, nie mogłaby opublikować aktualizacji,
którą aplikacja by zainstalowała. Wydanie bez ważnego podpisu jest widoczne w menu, ale można je pobrać wyłącznie
ręcznie. Podpis nie zastępuje wbudowanych w system Windows monitów SmartScreen ani UAC.

Pierwsze wydanie zawierające tę funkcję należy zainstalować ręcznie jeden raz. Kompilacje deweloperskie/testowe wyłączają
oficjalne sprawdzanie aktualizacji, aby lokalne zmiany nie zostały przypadkowo nadpisane. Aktualizacje dla systemu Linux oraz
automatyczne zastępowanie kopii przenośnych są odłożone na później.

## Wiersz poleceń

```
BatteryHub.exe --list     # wypisz każde urządzenie i poziom baterii, a następnie zakończ
BatteryHub.exe --json     # wypisz tablicę JSON urządzeń i poziomów baterii, a następnie zakończ
BatteryHub.exe --dump     # każda kolekcja HID, urządzenia HID, których nie udało się otworzyć, wszystkie urządzenia USB (także te
                               # bez interfejsu HID) oraz urządzenia Bluetooth; zapisywane także do %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # otwórz okno „Poproś o obsługę urządzenia”
BatteryHub.exe --demo     # przykładowe urządzenia każdej marki zamiast rzeczywistych (zrzuty ekranu, sprawdzanie kolorów)
BatteryHub.exe --quit     # zamknij działającą instancję
```

Wersja dla systemu Linux obsługuje te same flagi z plikiem `wireless-battery` zamiast `BatteryHub.exe` oraz
przyjmuje również `--help`. Flaga `--json` wypisuje stabilną tablicę, którą mogą przetwarzać skrypty i widżety pasków:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` określa, jak długo aplikacja wyświetla ostatni znany poziom, gdy urządzenie jest uśpione.
Dodawanie nowych pól zachowuje kompatybilność wsteczną.

**Urządzenie się nie wyświetla?** Kliknij widżet lub ikonę w zasobniku prawym przyciskiem myszy i wybierz **Poproś o obsługę urządzenia...**. Wybierz urządzenie, sprawdź,
co zostanie wysłane (jest to pokazane słowo w słowo: nazwa urządzenia, jego typ, identyfikatory USB/HID i układ interfejsów oraz opcjonalnie Twoje
imię i uwagi) i kliknij **Wyślij**. Zgłoszenie trafia na publiczną listę na [krisgfx.com/tools](https://krisgfx.com/tools/#requested) oraz
otwiera lub aktualizuje zgłoszenie (issue) na GitHubie. **Kopiuj pełny raport** umieszcza pełny wynik `--dump` w schowku na potrzeby zgłoszenia.
Dane raportu są wysyłane wyłącznie po kliknięciu przycisku Wyślij. Oficjalne kompilacje dla systemu Windows mogą także łączyć się z serwisem GitHub
w celu sprawdzania aktualizacji, zgodnie z opisem w sekcji [Aktualizacje w systemie Windows](#aktualizacje-w-systemie-windows); sprawdzanie aktualizacji
nie wysyła żadnych informacji o urządzeniach ani baterii.

## Kompilacja

Potrzebujesz [MinGW-w64](https://www.mingw-w64.org/), np. z [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # kompilacja deweloperska, wersja 0.0.0
build.bat                                 # zwykłe cmd z g++ i windres w zmiennej PATH
make VERSION=1.2.3 CHANNEL=test            # kompilacja z wersją, oficjalne aktualizacje wyłączone
build.bat 1.2.3 test                       # równoważna kompilacja z wersją w cmd
make test VERSION=1.2.3 CHANNEL=test       # testy regresyjne urządzeń i aktualizatora
```

Aby zbudować instalator oraz przenośne archiwum zip, zainstaluj [Inno Setup](https://jrsoftware.org/isinfo.php),
najpierw skompiluj z zamierzoną wersją (na przykład `make VERSION=1.2.3 CHANNEL=test`), a następnie uruchom
`powershell -File installer\build-installer.ps1 -Version 1.2.3`. Pakowanie odrzuca wersję, która
różni się od pliku wykonywalnego. Skrypt pobiera przypięte
wydanie HeadsetControl i weryfikuje jego sumę kontrolną. GitHub Actions wykonuje to wszystko automatycznie:
wypchnięcie tagu takiego jak `v1.0.0` publikuje wydanie z instalatorem, przenośnym archiwum zip oraz
kodem źródłowym HeadsetControl (zgodnie z wymogiem jego licencji GPL).

Kompilacje dla systemu Windows wymagają również programu PowerShell do wygenerowania wspólnej wersji pliku wykonywalnego i zasobów.
Tagi wersji oficjalnego repozytorium budują się z `CHANNEL=stable`; lokalne kompilacje domyślnie używają
`dev`. Forki oraz pull requesty nie włączają automatycznie oficjalnych aktualizacji.

Sam plik `BatteryHub.exe` również działa samodzielnie. Bez pliku `headsetcontrol.exe` obok niego (lub w `PATH`)
tracisz jedynie obsługę dodatkowych słuchawek.

## Linux (eksperymentalne)

Kompilacja dla systemu Linux rozwija się równolegle z aplikacją dla systemu Windows. Korzysta z tych samych sterowników producentów poprzez backend HID oparty na
hidraw oraz ikonę w zasobniku GTK4 StatusNotifierItem; ścieżka kodu dla Windows pozostaje bez zmian.
Wszystkie pliki specyficzne dla systemu Linux znajdują się w `linux/` oraz `src/linux/`, a do kompilacji służy `build-linux.sh` (Windows nadal korzysta z `build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Kompilator i make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

Żadna dodatkowa biblioteka HID nie jest potrzebna (hidraw używane jest bezpośrednio).

```sh
./build-linux.sh
./build-linux.sh test         # test jednostkowy parsera deskryptora raportów HID
./wireless-battery --list     # wypisz wykryte poziomy i zakończ
./wireless-battery --dump     # wypisz kolekcje HID
./wireless-battery --quit     # zamknij działającą instancję zasobnika
```

Dostęp do HID wymaga reguły udev — w przeciwnym razie aplikacja uruchamia się, ale nie znajduje żadnych urządzeń:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# wyloguj się i zaloguj ponownie
```

Ikona w zasobniku działa natywnie w KDE Plasma; GNOME wymaga hosta AppIndicator takiego jak
`gnome-shell-extension-appindicator`. Przełączanie wielu języków działa poprzez podmenu *Język*
(domyślnie zgodnie z `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG`, lokalizując także `--help`).
Uruchomienie `make -f linux/Makefile.linux install` instaluje plik binarny, `lang/*.json` w
`$(PREFIX)/share/wireless-battery/lang/` oraz aktywator pulpitu (`linux/wireless-battery.desktop`)
i `linux/wireless-battery.svg` w `$(PREFIX)` (domyślnie `~/.local`); nadpisania językowe użytkownika
znajdują się w `~/.config/wireless-battery/lang/`.

Faza 1 obejmuje Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious,
Finalmouse oraz wspólne protokoły Kysona/Pulsar/ATK/G-Wolves. Obsługa zapasowa Bluetooth/UPower, HeadsetControl oraz
pozostali producenci są planowani w kolejnych fazach.

## Ograniczenia

- **Przepełnione paski zadań:** przy bardzo zapełnionym wyśrodkowanym pasku zadań w Windows 11 przyciski aplikacji mogą nachodzić na widżet. W Windows 10 obszar przycisków zadań jest automatycznie zwężany.
- **Telefony:** odczytywane z pliku zapisywanego przez aplikację Łącze z telefonem dla karty towarzyszącej menu Start, co nie jest udokumentowanym API i może ulec zmianie wraz z aktualizacjami Łącza z telefonem. Telefon jest wyświetlany, dopóki Łącze z telefonem zgłasza go jako połączony; karta starsza niż 3 godziny jest wyświetlana jako przyciemniona. Karta informuje też o ładowaniu telefonu, co jest pokazywane jako ikona błyskawicy ładowania.
- **Uśpione urządzenia:** urządzenie w stanie uśpienia może nie odpowiadać. Jego ostatnia wartość pozostaje widoczna, przyciemniona. Odbiorniki Logitech odłączają uśpione urządzenia z łącza, więc ich ostatnia wartość jest zachowywana przez 30 minut.
- **Słuchawki HECATE G2 Wireless 7.1** (odbiornik 2,4 GHz `35BB:A009` / `A209`): brak jeszcze udokumentowanego zapytania o baterię dla tego odbiornika, więc nie są odczytywane. Przechwycenie ruchu USB w momencie, gdy oprogramowanie HECATE pokazuje baterię słuchawek (zobacz CONTRIBUTING.md), to sposób na ich dodanie.
- **Klawiatury Keychron:** z fabrycznym oprogramowaniem układowym raportują baterię tylko przez Bluetooth (wyświetlaną przez obsługę Bluetooth). Przez odbiornik 2,4 GHz lub kabel wymagają firmware z łatką baterii ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); aktualizacja klawiatury przez Keychron Launcher usuwa tę łatkę. Myszy Keychron są obsługiwane.
- **Słuchawki Baseus AeQur GH02:** odbiornik 2,4 GHz (`10D6:4802`, układ Actions) przenosi wyłącznie dźwięk, klawisze multimedialne i kanał aktualizacji firmware układu, bez informacji o baterii. Podłącz słuchawki przez Bluetooth, aby zobaczyć poziom baterii (wyświetlany przez obsługę Bluetooth, gdy Windows go zgłasza).
- **Klawiatura Weikav Lucky65 v1:** oprogramowanie układowe nie raportuje poziomu baterii przez odbiornik 2,4 GHz (`0603:0351`, układ Novatek). Klawiatura nie ma skrótu sprawdzania baterii, a oficjalny konfigurator łączy się wyłącznie po kablu USB, nie przez odbiornik, więc nie ma żadnego odczytu baterii do wyświetlenia.
- **Rapoo:** obsługiwane myszy VT same wypychają swój status, więc odświeżenie może czekać do 4 sekund na każdy pasujący interfejs. Uśpione myszy mogą pozostać przyciemnione z ostatnim odczytem do 30 minut. Obsługa dotyczy raportu `07` układów Nordic 54L oraz starszego `BB` (VT3 Pro, VT1 Pro Max); raport `08` układów CH584, biurowe myszy z serii MT/M oraz inne protokoły firmware nie są objęte tym sterownikiem.
- **GameSir Cyclone Pro:** odbiornik nie przenosi poziomu baterii, więc jest on odczytywany z pada przez Bluetooth LE. Sparuj pada jednorazowo z systemem Windows (Ustawienia > Bluetooth i urządzenia > Dodaj urządzenie > Bluetooth > `GameSir-Cyclone Pro`) i dalej graj przez odbiornik. Komputer wymaga Bluetooth. Poziom odświeża się co 2 minuty i brak odczytu procentowego podczas ładowania. Bez sparowania odbiornik widoczny jest jako kontroler Xbox o poziomie „Pełna”. Szczegóły w [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM:** mysz jest odpytywana przez swój odbiornik, więc uśpiona mysz nie odpowiada; pozostaje przyciemniona z ostatnim odczytem do 30 minut i wydłuża odświeżanie o około sekundę podczas uśpienia. Przetestowano wyłącznie Leviathan V4 na odbiorniku RAWM HS Receiver (`1915:2346`); pozostałe modele pochodzą z tabeli urządzeń RAWM HUB. Leviathan V4 GT i NYX60 (VID `373E`, RAWM HUB 3.0) oraz klawiatury RAWM HS używają innych protokołów i nie są objęte.
- **Flydigi:** ten sterownik obsługuje Vader 5 Pro i Apex 5; Bluetooth oraz inne modele Flydigi (na przykład Apex 6) nie są objęte. Procenty reprezentują zgrubne poziomy baterii. Apex 5 był testowany na rzeczywistym sprzęcie przez odbiornik 2,4 GHz i kabel USB; Vader 5 Pro opiera się na SDL oraz śladach sprzętowych systemu Windows.
- **Jeszcze nieobsługiwane:** bezprzewodowe myszy MSI inne niż VERSA 300 ELITE i CLUTCH GM31 / GM41, bezprzewodowe klawiatury MSI, słuchawki Razer Kraken oraz modele Barracuda inne niż Barracuda X (2022) na `1532:0550`, myszy HyperX Pulsefire inne niż Haste 2 Wireless / Haste 2 Core Wireless oraz Xbox Wireless Headset na adapterze Xbox: ich protokoły baterii nie są udokumentowane. Słuchawki Xbox Wireless Headset działają przez Bluetooth. Przechwycenie ruchu USB od właściciela (zobacz CONTRIBUTING.md) to sposób na ich dodanie.
- **Inne urządzenia:** niektóre urządzenia 2,4 GHz korzystają z nieudokumentowanych protokołów i nie są jeszcze obsługiwane. Zobacz [CONTRIBUTING.md](#sec-contributing), jak pomóc w dodaniu obsługi.

## Jak to działa

Każdy sterownik producenta w [`src/drivers/`](../../src/drivers) rozpoznaje swoje urządzenia po identyfikatorach producenta (VID) i produktu (PID) USB oraz wysyła wyłącznie zapytania o baterię tylko do odczytu. Nieznane urządzenia nigdy nie otrzymują żadnych zapisów. Ogólne mechanizmy zapasowe (użycie baterii HID, Bluetooth, XInput, HeadsetControl) sprawdzają wyłącznie urządzenia, których nie przejął żaden sterownik producenta.

Widżet paska zadań jest warstwowym oknem podrzędnym `Shell_TrayWnd`, umieszczonym po lewej stronie `TrayNotifyWnd`. Jeśli Eksplorator zostanie uruchomiony ponownie, okno jest odtwarzane.

## Tłumaczenia

Każdy język interfejsu to zwykły, statyczny plik tekstowy UTF-8 w [`lang/`](../../lang): po lewej angielski, po prawej tłumaczenie. Pliki językowe są wczytywane z dysku w czasie działania zamiast wkompilowywania w plik wykonywalny, więc możesz je bezpośrednio edytować bez ponownej kompilacji.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **Interfejs aplikacji (Windows i Linux):**
  - Edytuj lub dodaj pliki `.json` bezpośrednio w folderze `lang/` obok `BatteryHub.exe` (lub `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/` albo `./lang/` w systemie Linux).
  - Możesz też wybrać *Język → Dodaj własny język...* w menu, aby przygotować swój folder nadpisań użytkownika (`%APPDATA%\WirelessBattery\lang` w Windows, `~/.config/wireless-battery/lang` w Linux) z plikiem `_template.json`. Skopiuj `_template.json` np. do `it.json`, uzupełnij `@code`, `@name` i tłumaczenia, a język pojawi się w menu (bez potrzeby restartu). Pliki w folderze użytkownika nadpisują wbudowane frazy o tym samym `@code`.
  - Pozostaw symbole zastępcze `{placeholders}` bez zmian i dodaj `"@rtl": true` dla pism od prawej do lewej. Puste frazy pozostają po angielsku, więc częściowe tłumaczenie również działa.
  - Wynik `--list` oraz `--dump` celowo pozostaje po angielsku: służy do wklejania w zgłoszeniach na GitHubie.
- **Instalator Windows:** tłumaczenia Inno Setup znajdują się w [`installer/lang/`](../../installer/lang) (zapisywane jako UTF-8 z BOM) i są rejestrowane w sekcji `[Languages]` w `installer/BatteryHub.iss`.
- **Dokumentacja:** każdy widoczny dokument projektu jest przetłumaczony jako jeden samodzielny plik Markdown na język w [`docs/i18n/`](README.md) (zobacz [`docs/i18n/_template.md`](_template.md), aby dodać nowy język bez żadnych skryptów budujących).
- **Podziel się ze wszystkimi:** wyślij pull request dodający Twoje pliki w `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` oraz `docs/i18n/`. Zobacz [`docs/i18n/README.md`](README.md), aby sprawdzić listę kroków.

## Podziękowania

Ikona aplikacji autorstwa [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

Protokoły pochodzą z badań następujących projektów:

- [Specyfikacja Google Fast Pair](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): rozgłoszenia baterii lewej / prawej słuchawki i etui słuchawek Fast Pair
- [Sterowniki Astro w HeadsetControl](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) oraz [AstroBar](https://github.com/nichtlegacy/AstroBar): protokoły baterii Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): odczyt statusu `0x72` dla A50 Gen 3

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): polecenia baterii i ładowania VAXEE ([dokumentacja protokołu](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): słuchawki SteelSeries, Corsair, HyperX, Logitech oraz Sony INZONE
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) oraz [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) oraz dokumentacja Logitech HID++ 2.0: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) oraz [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (odbiornik `0ADF`)
- [rivalcfg](https://github.com/flozz/rivalcfg): myszy SteelSeries (Rival Pro z pull requesta #294)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) oraz [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Konfigurator WWW Hitscan ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- Linux `hid-kysona` (Lode Willems): Kysona, Pulsar i ATK
- Konfigurator WWW ATK ([hub.atk.pro](https://hub.atk.pro)): myszy ATK oraz słuchawki N9 Pro / N9 Ultra
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 oraz [mouse-battery](https://github.com/qwr79/mouse-battery): odbiornik ATK / VXE NK NANO
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X oraz Endgame Gear XM2we, przeniesione z jego dostawców (każdy sterownik podaje swoje źródło)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` oraz [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (wyłącznie ustalenia): rodzina urządzeń Turtle Beach Swarm II
- Sterownik WWW G-Wolves ([mouse.xyz](https://mouse.xyz)): modele G-Wolves i ich protokoły
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): klawiatury CHERRY na odbiorniku 2,4 GHz (format ramki i zapytanie o baterię)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): myszy Keychron
- [NinjaForce](https://www.ninjaforce.co/) oraz [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): zapytania funkcji Ninjutso Ten / Ten Air
- [nape_pro](https://github.com/nvalis/nape_pro) oraz [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro na odbiorniku Link-KM
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): myszy LAMZU
- [vole](https://github.com/johanneszab/vole) oraz [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): myszy Endgame Gear 4K
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) oraz [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) oraz [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (z xpanel firmy Finalmouse)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) oraz [g49-web-control](https://github.com/pingpingjinping/g49-web-control): identyfikatory Redragon
- [m913-ctl](https://github.com/Qehbr/m913-ctl) oraz [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): układ ramki Areson `25A7` i polecenie `GetPower`
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) oraz [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW i DW
- Sterownik WWW RK ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) oraz [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (dokumentacja): MCHOSE A5 Pro / A5 Pro Max (pierwsza generacja, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): raporty odbiornika CompX dla Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) oraz [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) oraz [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- Sterownik WWW Wraith ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 oraz [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 oraz [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) oraz [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) na odbiorniku `1532:0550`; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): ramkowanie odbiornika `1532:0552`
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): odbiorniki Rongyuan i Xenta (Attack Shark i inne)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): klawiatury SONiX na odbiorniku 2,4G (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) oraz [ak820-studio](https://github.com/usharik/ak820-studio): odbiornik AJAZZ AK820 Pro `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) oraz [Kraber](https://github.com/AkashPanja/Kraber): protokół statusu Semico `1A2C` (`AA 55 CC 33` / `0x0E`) dla Attack Shark X98 i AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) oraz [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 i MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) oraz [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): żądanie baterii „base info” przez Bluetooth LE dla GameSir Cyclone Pro
- [jabridge](https://github.com/Watchdog0x/jabridge): protokół Jabra GNP (odbiorniki Link 380 / 390)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): protokół strony statusu `1EA7:0066` (Fantech Raigor III i inne ogólne urządzenia 2.4G Mouse)
- Linux `hid-playstation`: układ raportu DualShock 4 / DualSense
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): protokół producenta AULA SC580 / SC580X
- Aplikacja WWW RAWM HUB ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) oraz jej tabela urządzeń: myszy RAWM i SADES Dagger
- [Sterownik HID Flydigi w SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) oraz [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): ramkowanie zapytań i układ baterii dla Vader 5 Pro i Apex 5
- [Sterownik HID 8BitDo w SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): bajt baterii 8BitDo Ultimate 2
- BEITONG iControl (strony dla KP20 i KP40D oraz ruch USB odbiornika KP20): zapytanie o baterię i mieszanie ładunku BEITONG KP20 / KP40D
- [Sterownik HID 8BitDo w SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) oraz [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): bajt baterii 8BitDo i protokół HID producenta
- JBL QuantumENGINE (komunikaty device-info HIDV3): słuchawki JBL Quantum
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, protokół Compx na `FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) oraz [BrimDeck](https://github.com/MoFeng2223/BrimDeck): odczyt profilu Scyrox V12M
- JBL QuantumENGINE: raporty połączenia i baterii HIDV1 dla Quantum 350 oraz komunikaty device-info HIDV3 dla nowszych słuchawek Quantum
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): raporty baterii i łącza HIDV1 dla JBL Quantum 610 oraz rodzina Quantum (360 jako model z odbiornikiem HIDV1)

## Licencja

[GNU General Public License v3.0 lub nowsza](../../LICENSE). Możesz używać, modyfikować i rozpowszechniać to
oprogramowanie, ale wszystko, co rozpowszechniasz na jego podstawie, musi zostać wydane na tej samej licencji
wraz z kodem źródłowym.


---

<a id="sec-contributing"></a>
> 📄 **Sekcja:** Współtworzenie (`CONTRIBUTING.md`) · [Oryginał angielski](../../CONTRIBUTING.md) · [↑ Na górę](#top)

# Współtworzenie

## Zgłaszanie, czy urządzenie działa

Większość sterowników została napisana na podstawie dokumentacji protokołów i nie mogła zostać przetestowana na każdym modelu.
Otwórz zgłoszenie (issue), podając:

- nazwę urządzenia oraz informację, czy jest połączone przez odbiornik, kabel czy Bluetooth
- wynik polecenia `BatteryHub.exe --list`
- wynik polecenia `BatteryHub.exe --dump`
- poziom baterii pokazywany przez własne oprogramowanie producenta

## Dodawanie urządzenia

1. Uruchom `BatteryHub.exe --dump` i znajdź identyfikatory producenta (VID) i produktu (PID) urządzenia oraz
   kolekcje zdefiniowane przez producenta (strona użycia `FFxx`) wraz z rozmiarami raportów.
2. Znajdź protokół baterii. Dobre miejsca do poszukiwań to: HeadsetControl, OpenRazer, Solaar, rivalcfg,
   OpenRGB, OpenLinkHub albo przechwycenie ruchu USB oprogramowania producenta (Wireshark + USBPcap).
3. Jeśli producent ma już sterownik w `src/drivers/`, dodaj tam identyfikator produktu (oraz ewentualne różnice).
   W przeciwnym razie utwórz plik `src/drivers/<vendor>.cpp`:

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

4. Zadeklaruj funkcję w `src/drivers/drivers.h` i wywołaj ją z `PollAllDevices()` w
   `src/devices.cpp` (przed ogólnymi mechanizmami zapasowymi). `build.bat` i Makefile wykrywają nowe pliki automatycznie.
5. Zaktualizuj tabelę urządzeń w `README.md`.

### Zasady dla sterowników

- **Tylko do odczytu:** wysyłaj wyłącznie żądania odczytujące stan. Nigdy nie zmieniaj ustawień, podświetlenia ani trybów.
- **Dokładne dopasowanie:** komunikuj się wyłącznie z urządzeniami rozpoznanymi po identyfikatorze producenta i produktu lub po
  kolekcji specyficznej dla producenta, która jest unikalna dla danego protokołu.
- **Zawsze stosuj limit czasu:** brakujące urządzenie nie może wstrzymywać odświeżania na dłużej niż około sekundę.
  Protokoły pasywne mogą potrzebować więcej czasu, aby objąć udokumentowany interwał rozgłaszania (na przykład Delux i
  Rapoo). Zachowaj pojedynczy bezwzględny termin maksymalnie 4 sekund na pasującą kolekcję, nie
  resetuj go dla niepowiązanych raportów i udokumentuj, dlaczego wyjątek jest potrzebny.
- **Podawaj źródła:** wskaż w komentarzu na początku pliku, skąd pochodzi protokół.

## Tłumaczenia

Języki interfejsu to zwykłe, statyczne pliki tekstowe UTF-8 w `lang/` wczytywane z dysku w czasie działania zarówno w Windows, jak i w Linuxie (skopiuj `lang/_template.json` do `lang/<code>.json`, uzupełnij `@code`, `@name` i frazy — bez ponownej kompilacji). Nowe teksty interfejsu w kodzie przechodzą przez `T(L"...")` lub `TF(L"... {name} ...", { { L"name", value } })`, gdy zawierają wartości; nigdy nie buduj tłumaczonych zdań z kawałków. Po dodaniu fraz dopisz je także do `lang/_template.json`.

Tłumaczenia instalatora Windows znajdują się w `installer/lang/*.isl` (zapisane jako UTF-8 z BOM i zarejestrowane w `installer/BatteryHub.iss`), komentarze aktywatora dla systemu Linux znajdują się w `linux/wireless-battery.desktop`, a pełne tłumaczenia dokumentacji znajdują się w `docs/i18n/<code>.md` (jeden samodzielny plik skopiowany z `docs/i18n/_template.md`). Zobacz [`docs/i18n/README.md`](README.md), aby zapoznać się z kompletnym przewodnikiem dla współtwórców.

## Styl kodu

C++17, wyłącznie Win32, bez zewnętrznych zależności. Utrzymuj mały rozmiar pliku binarnego. Formatuj kod podobnie jak
istniejący kod w repozytorium (wcięcie 4 spacje, linie do 120 znaków).

## Rozwój aktualizatora Windows

Aktualizator działa wyłącznie w systemie Windows i wykorzystuje WinHTTP, BCrypt oraz istniejący instalator Inno Setup.
Status aktualizacji utrzymuj wyłącznie w menu. Nie dodawaj ikon aktualizacji, plakietek, zmian w podpowiedzi baterii,
dymków, powiadomień toast ani automatycznych okien dialogowych. Odpytywanie urządzeń działa oddzielnie od zadań sieciowych.

Wersja kompilacji i kanał są współdzielone przez C++ oraz zasoby Windows poprzez generowany plik
`build/version.h`. Do lokalnych testów użyj `make VERSION=1.2.3 CHANNEL=test` lub `build.bat 1.2.3 test`;
`dev` to wartość domyślna, a `stable` włącza sprawdzanie oficjalnych wydań. Składniki wersji
muszą mieścić się w zakresie 0..65535. Tylko przepływ pracy dla tagów wydań oficjalnego repozytorium automatycznie wybiera kanał stable.
Nie przełączaj przypadkowo kompilacji forka na oficjalny kanał aktualizacji.

Uruchom `make test VERSION=1.2.3 CHANNEL=test` dla istniejących testów urządzeń oraz ścisłego parsowania wydań,
kolejności wersji, planowania sprawdzeń, rzeczywistych testów plików SHA-256, cytowania argumentów i zabezpieczeń pomocnika.
Testy regresyjne aktualizatora obejmują także anulowanie po zakończeniu pobierania, zabezpieczenia okien dialogowych oraz obsługę błędów
konfiguracji limitów czasu i przekierowań HTTP. Test Windows dołącza implementacje,
zgodnie z istniejącym wzorcem testów backendu Linux, i podmienia wysyłanie HTTP, aby testy nie
łączyły się z GitHubem. Żadne punkty wejścia kontrolera przeznaczone tylko do testów nie są dodawane do wersji produkcyjnej.
Poszczególne cele to `make test-update-core` oraz `make test-update-win`. Natywne testy aktualizatora
linkują zasób aplikacji w celu aktywacji Common Controls v6. Testy używają danych lokalnych i nie
pobierają plików, nie podnoszą uprawnień, nie instalują ani nie zmieniają ustawień autostartu użytkownika. Produkcyjnego
punktu końcowego aplikacji nie można nadpisać na potrzeby testów.

Przed spakowaniem uruchom
`powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`.
Skrypt `installer/build-installer.ps1 -Version 1.2.3` również wykonuje to sprawdzenie przed pobraniem zależności.
Ścieżka instalatora `/WBUPDATE=1` zachowuje istniejące ustawienia oraz autostart i pozostawia ponowne uruchomienie
tymczasowemu narzędziu pomocniczemu. Narzędzie to pozostaje w kontekście pierwotnego użytkownika, podnosząc uprawnienia tylko dla instalacji globalnej.
Uchwyty WinHTTP należą do wątku roboczego; anulowanie odbywa się kooperacyjnie pomiędzy wywołaniami ze skończonym limitem czasu.
Końcowe zamknięcie aplikacji dołącza do tego wątku roboczego i dlatego może poczekać na trwający limit czasu sieciowego.

Do przeglądu wydania użyj jednorazowego konta Windows lub maszyny wirtualnej, aby przetestować dwie rzeczywiste wersje
instalatora, zakres dla użytkownika i globalny, anulowanie UAC, włączony/wyłączony autostart, niestandardowe ścieżki, błędy instalacji
oraz ponowne uruchomienie. Testy jednostkowe i kompilacja pakietu nie weryfikują tych efektów instalatora. Wizualny
przegląd menu/motywów oraz rzeczywiste testy end-to-end instalatora/UAC pozostają ręcznymi bramkami wydania; nie
oznaczaj ich jako zaliczone bez rzeczywistej obserwacji. Nigdy nie testuj, nadpisując codzienną instalację użytkownika.

## Automatyczne sprawdzanie bezpieczeństwa

Każdy pull request jest skanowany przez „PR safety check” pod kątem operacji, których ta aplikacja nigdy nie powinna wykonywać (dostęp
do sieci, uruchamianie programów, odczyt klawiatury/schowka/ekranu, wpisy autostartu, pliki binarne, zmiany budowania lub
wydawania). Oznaczenie przez skaner nie oznacza odrzucenia: po prostu wyjaśnij oznaczone linie w opisie PR.

Korzystanie z narzędzi AI jest w porządku, ale usuń linie `Co-authored-by`, które je wymieniają (na przykład
`Co-authored-by: Claude ...`) z komunikatów commitów. Sprawdzanie kończy się błędem, dopóki są one obecne.


---

<a id="sec-pr-template"></a>
> 📄 **Sekcja:** Szablon Pull Requesta (`.github/pull_request_template.md`) · [Oryginał angielski](../../.github/pull_request_template.md) · [↑ Na górę](#top)

## Co dodaje ta zmiana

<!-- Urządzenie(a) oraz identyfikatory producenta/produktu, np. „Acme M1 (1234:5678)”. -->

## Skąd pochodzi protokół

<!-- Podaj link do źródła (inny projekt, sterownik WWW producenta, własne przechwycenie USB). -->

## Przetestowane na rzeczywistym sprzęcie?

<!-- Tak (jakie urządzenie, co wypisało --list) / Nie -->

## Lista kontrolna

- [ ] Wysyłane są wyłącznie zapytania o baterię tylko do odczytu; żadne ustawienia, podświetlenie ani firmware nie są zmieniane
- [ ] Dotykane są wyłącznie urządzenia rozpoznane po identyfikatorze producenta/produktu (lub kolekcji specyficznej dla protokołu)
- [ ] Brak dostępu do sieci, brak uruchamiania innych programów, brak nowych plików poza `src/`, `docs/` lub `README.md`
- [ ] Nie dołączono żadnych plików binarnych ani wygenerowanych
- [ ] Brak linii `Co-authored-by` przypisujących autorstwo narzędziom AI (Claude, Copilot, ChatGPT ...) w komunikatach commitów
- [ ] Zmiany w `.github/`, `installer/`, `build.bat` lub `Makefile` zostały wyjaśnione powyżej


---

<a id="sec-releasing"></a>
> 📄 **Sekcja:** Wydawanie wersji (`docs/releasing.md`) · [Oryginał angielski](../../docs/releasing.md) · [↑ Na górę](#top)

# Wydawanie wersji

Aplikacja aktualizuje się z wydań na GitHubie, ale instaluje wyłącznie instalator, którego suma SHA-256 znajduje się w
pliku `SHA256SUMS.txt` podpisanym kluczem wydania. Ten klucz znajduje się na komputerze opiekuna projektu, nigdy na
GitHubie: przejęte konto, token lub przepływ pracy może opublikować pliki, ale nie podpis, który aplikacja zaakceptuje.

## Jednorazowo: utworzenie klucza wydania

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Prosi o hasło (12+ znaków) i zapisuje zaszyfrowany klucz prywatny do
  `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- Umieszcza klucz publiczny w `src\update_public_key.h`. Zatwierdź (commit) ten plik. Oficjalne kompilacje odmawiają
  kompilacji bez obecnego w nim klucza.
- **Zrób kopię zapasową pliku klucza i zachowaj hasło** (menedżer haseł to dobre miejsce na oba).
  Jeśli którekolwiek z nich zostanie utracone, zainstalowane aplikacje nie będą już mogły same się aktualizować: trzeba będzie utworzyć nowy
  klucz, a każdy użytkownik będzie musiał ręcznie zainstalować jedno wydanie.

## Przy każdym wydaniu

1. Wypchnij tag wersji (`git tag v1.2.3 && git push origin v1.2.3`). CI buduje instalator,
   przenośne archiwum zip oraz `SHA256SUMS.txt` i publikuje wydanie.
2. Podpisz listę sum kontrolnych:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Skrypt pobiera `SHA256SUMS.txt` z wydania, wyświetla go, prosi o potwierdzenie, pyta o hasło
   klucza i zapisuje `SHA256SUMS.txt.sig`. Jeśli masz te same pliki w `dist\` (lokalna kompilacja
   tej wersji), sprawdza i pokazuje, czy są zgodne.
3. Prześlij `SHA256SUMS.txt.sig` do wydania (skrypt otwiera stronę edycji). Od tego momentu aplikacja
   oferuje opcję **Pobierz i zainstaluj**. Wcześniej pokazuje aktualizację, ale tylko linkuje do strony wydania.

Podpisuj listę wyłącznie dla wydania, które sam opublikowałeś. Podpis oznacza „te dokładnie pliki stanowią
wydanie”, więc podpisywanie jest etapem, na którym złośliwie przesłany plik zostałby wykryty.

## Zmiana klucza

Uruchom `new-release-key.ps1` z nowym `-KeyFile`: dodaje nowy klucz publiczny obok starego w
`src\update_public_key.h`. Wydaj wersję podpisaną starym kluczem, która zawiera oba klucze, następnie podpisuj
nowym kluczem od kolejnego wydania i później usuń stary klucz. Utraconego lub ujawnionego klucza
nie można wycofać w ten sposób: usuń go z pliku nagłówkowego, a użytkownicy starszych wersji muszą zainstalować
kolejne wydanie ręcznie.

## Co sprawdza aplikacja przed uruchomieniem instalatora

- Wydanie jest najnowszym wydaniem repozytorium, nie jest wersją roboczą ani przedpremierową i jest nowsze niż aplikacja.
- `SHA256SUMS.txt.sig` jest ważnym podpisem ECDSA P-256 pliku `SHA256SUMS.txt` złożonym przez klucz z
  `src\update_public_key.h` (Windows BCrypt, bez kodu stron trzecich).
- Podpisana lista wymienia `BatteryHub-Setup-<version>.exe` dokładnie raz, z tą samą sumą SHA-256,
  jaką GitHub podaje dla tego pliku.
- Pobrany instalator ma dokładnie ten sam rozmiar i sumę SHA-256. Kopia aplikacji sprawdza go ponownie
  tuż przed uruchomieniem i utrzymuje blokadę pliku, aby nie można go było podmienić w międzyczasie.
- Pobieranie używa wyłącznie HTTPS do `github.com`, `objects.githubusercontent.com` oraz
  `release-assets.githubusercontent.com`, przy sprawdzaniu każdego przekierowania.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Sekcja:** Oprogramowanie układowe klawiatur Keychron (`docs/keychron_keyboard_firmware/README.md`) · [Oryginał angielski](../../docs/keychron_keyboard_firmware/README.md) · [↑ Na górę](#top)

# Bateria klawiatur Keychron przez odbiornik 2,4 GHz

Fabryczne oprogramowanie układowe firmy Keychron raportuje baterię klawiatury wyłącznie przez Bluetooth. Dzięki niewielkiej zmianie QMK w pliku
[`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch) klawiatura odpowiada również na zapytanie o baterię (`A4`) przez
odbiornik Keychron Link oraz po kablu USB, a BatteryHub wyświetla jej poziom, napięcie i stan ładowania.

Przetestowano na **Keychron K5 Max ANSI RGB** (`3434:0A50`) z odbiornikiem Keychron Link (`3434:D030`).

## Co zmienia łatka

Na podstawie repozytorium [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware), gałąź `2025q3` (commit `57e682c`):

- dodaje surowe polecenie HID `KC_GET_BATTERY` (`0xA4`) z [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1):
  odpowiedź `[A4][procent][mV młodszy][mV starszy][ładowanie: 0 bateria / 1 ładowanie / 2 pełna][transport][id modelu]`;
- przekazuje surowe żądania HID przychodzące przez łącze bezprzewodowe do tego samego procederu obsługi;
- w `keyboards/keychron/k5_max/config.h`: `#define WILRESS_RAW_ENABLE` (zapisane dokładnie w ten sposób w kodzie Keychrona) oraz
  `#define KC_BATTERY_MODEL_ID 0`.

Nic innego się nie zmienia: mapy klawiszy, podświetlenie i Keychron Launcher działają bez zmian.

## Opcja 1: wgraj gotowe firmware dla K5 Max

Kompilacja przeznaczona **wyłącznie dla K5 Max ANSI RGB** jest dołączona do
[tego wydania](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)
(`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`).
Nie wgrywaj jej na inny model ani inny układ klawiszy.

## Opcja 2: skompiluj samodzielnie

Wymaga programów Git i Docker (lub działającego [środowiska QMK](https://docs.qmk.fm/newbs_getting_started)).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

Wynikiem jest plik `keychron_k5_max_ansi_rgb_keychron.bin` w katalogu głównym repozytorium. W systemie Windows zamontowany katalog roboczy (bind mount)
działa w Dockerze bardzo wolno; klonowanie wewnątrz kontenera (lub w WSL) jest znacznie szybsze.

**Inne bezprzewodowe klawiatury Keychron** (Q/V/K Max oraz inne modele z drzewa `2025q3` z `LK_WIRELESS_ENABLE`):
zmiany w `keyboards/keychron/common/` aplikują się bez modyfikacji. Dodaj obie linie `#define` do pliku
`config.h` swojej klawiatury zamiast pliku K5 Max i zbuduj własny cel, np. `make keychron/<model>/<layout>/<variant>:keychron`.
Aplikacja obecnie nazywa K5 Max (`0A50`–`0A58`) według modelu, a każdą inną jako „Keychron keyboard”.

## Wgrywanie (flashing)

1. Ustaw przełącznik trybu na **Cable** i odłącz kabel USB.
2. Przytrzymaj **Esc** podczas podłączania kabla. Klawiatura przejdzie w tryb bootloadera STM32.
3. Wgraj plik `.bin` za pomocą [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (lub `dfu-util`).
4. Przełącz z powrotem na **2.4 GHz** i sprawdź za pomocą `BatteryHub.exe --list`:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Aktualizacja klawiatury z poziomu Keychron Launcher zastępuje to oprogramowanie układowe i usuwa raportowanie baterii. Aby to cofnąć,
wgraj oficjalne firmware Keychrona w ten sam sposób.

## Licencja

QMK jest udostępniany na licencji GPL-2.0-or-later; łatka podlega tej samej licencji. Każdy, kto otrzyma plik binarny z niej zbudowany, musi
również móc otrzymać tę zmianę źródłową.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Sekcja:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [Oryginał angielski](../../docs/gamesir_cyclone_pro.md) · [↑ Na górę](#top)

# Obsługa baterii GameSir Cyclone Pro

## Dlaczego kontroler wyświetlał się jako w pełni naładowany kontroler Xbox

Cyclone Pro (model T4cp) działa przez odbiornik 2,4 GHz `3537:1015`. Odbiornik przedstawia się
systemowi Windows jako przewodowy kontroler Xbox 360 (XUSB, `Xbox 360 Controller for Windows`). XInput odpowiada
na zapytanie o baterię wartością „Full”, więc mechanizm zapasowy XInput wyświetlał go jako `Xbox controller 1` na poziomie 100%,
niezależnie od rzeczywistego stanu naładowania.

Odbiornik nie przenosi żadnych informacji o baterii:
- jego jedyną kolekcją HID jest kontroler gier XInput (`HID\VID_3537&PID_1015&IG_00`)
- nie posiada kolekcji zdefiniowanej przez producenta, takiej jak w Nova (`FF7A`) czy Cyclone 2 (`FFF0`)

## Gdzie znajduje się poziom baterii

Podczas gry przez odbiornik pad rozgłasza się także przez Bluetooth LE jako
`GameSir-Cyclone Pro`, z czego korzysta mobilna aplikacja GameSir. Jej żądanie „get base info”
zwraca stan baterii:

| Krok | Szczegóły |
|---|---|
| Usługa | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Charakterystyka | `0x865F` (powiadomienie, zapis bez odpowiedzi) |
| Żądanie | włącz powiadomienia, zapisz `01 01` |
| Odpowiedź | 19-bajtowe powiadomienie (niektóre wersje firmware poprzedzają je bajtem `C9`, 20 bajtów) |

Układ odpowiedzi:

```text
[0..5] MAC  [6..7] wersja sprzętu  [8..9] wersja BT  [10..11] wersja firmware  [12..17] data kompilacji  [18] bateria
```

Bajt 18 to poziom baterii w procentach (0–100) lub `FF` podczas ładowania. Podczas ładowania nie jest raportowany
poziom, więc zachowywana jest ostatnia znana wartość procentowa wraz z ikoną błyskawicy ładowania.

Pad ma także usługę `0xFF10`, która jest kanałem aktualizacji firmware GameSir. Sterownik nigdy jej nie
otwiera. Pad nie posiada standardowej usługi Battery Service (`0x180F`), dlatego strona Bluetooth w systemie Windows
oraz mechanizm zapasowy Bluetooth nie pokazują jego poziomu.

Źródło: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), gdzie protokół został
rozpracowany z aplikacji GameSir dla systemu Android (`BluetoothLeService`, „get base info”).

## Jak działa sterownik

`src/drivers/gamesir_ble.cpp`, wywoływany przed mechanizmem zapasowym XInput:

1. **Znajdź pada.** Wyszukuje interfejsy urządzeń klasy `{00008650-0000-1000-8000-00805F9B34FB}`.
   Windows tworzy jeden taki interfejs dla każdej usługi GATT sparowanego urządzenia BLE. Wykorzystuje tylko te, których nadrzędny
   węzeł `BTHLE\DEV_…` nosi nazwę `GameSir-Cyclone…`.
2. **Odczytaj baterię.** Otwiera tę usługę przez Win32 GATT API (`bluetoothleapis.h`,
   `-lbluetoothapis`), subskrybuje `0x865F` i zapisuje `01 01`. Czeka maksymalnie 3 sekundy na
   odpowiedź, a następnie ponownie wyłącza powiadomienia.
3. **Utrzymaj szybkie odpytywanie.** Połączenie BLE może zająć kilka sekund lub przekroczyć limit czasu, gdy pad jest
   uśpiony, dlatego zapytanie działa we własnym wątku:
   - najwyżej co 2 minuty po udanym odczycie lub co minutę po nieudanym
   - odpytywanie zwraca buforowany odczyt i przestaje go raportować po upływie 6 minut
   - `graceSec` utrzymuje go następnie jako widoczny, przyciemniony, w stanie uśpienia
   - tylko pierwsze odpytanie po uruchomieniu czeka na ten wątek, jednorazowo, z bezwzględnym limitem 4 sekund,
     aby poziom pojawił się przy starcie i w `--list`
4. **Ukryj fałszywy wpis Xbox.** Gdy obecny jest odbiornik, sterownik przejmuje `3537:1015`:
   - ścieżka Windows.Gaming.Input pomija teraz przejęte identyfikatory producenta/produktu
   - ścieżka XInput pobiera identyfikator producenta/produktu każdego gniazda z `XInputGetCapabilitiesEx` (xinput1_4
     ordinal 108) i pomija te przejęte
   - gdy ten eksport jest nieobecny, XInput zachowuje się tak jak wcześniej

## Przetestowany sprzęt

Windows 11, Cyclone Pro na swoim odbiorniku (`3537:1015`), jednorazowo sparowany przez Bluetooth, 2026-11-18:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Gdy pad był uśpiony, wpis „Xbox controller 1 / Full” przestał się pojawiać i nic nie było
wyświetlane dla pada.

## Ograniczenia

- **Parowanie:** pad musi zostać jednorazowo sparowany z systemem Windows (Ustawienia > Bluetooth i urządzenia > Dodaj urządzenie >
  Bluetooth > `GameSir-Cyclone Pro`). Niesparowane pady nie mają interfejsu urządzenia GATT. Parowanie dodaje
  wpisy gamepada Bluetooth, ale nie wysyłają one żadnych danych wejściowych, gdy pad działa przez odbiornik.
- **Wymagany Bluetooth:** komputer musi posiadać obsługę Bluetooth LE.
- **Jeden pad:** odczytywany jest tylko jeden Cyclone Pro na komputer.
- **Ładowanie:** brak wartości procentowej podczas ładowania.


---

<a id="sec-localization-guide"></a>
> 📄 **Sekcja:** Przewodnik wielojęzyczności i lokalizacji (`docs/i18n/README.md`) · [Oryginał angielski](../../docs/i18n/README.md) · [↑ Na górę](#top)

# Indeks wielojęzyczności i przewodnik lokalizacji BatteryHub

Każdy widoczny dokument w tym repozytorium jest zebrany w **jednym samodzielnym pliku Markdown na język** w katalogu `docs/i18n/`, podczas gdy wszystkie komunikaty aplikacji w czasie działania znajdują się w **statycznych edytowalnych plikach tekstowych** w [`lang/`](../../lang) (wspólnych dla Windows i Linuxa), a teksty instalatora Windows w [`installer/lang/`](../../installer/lang).

## Obsługiwane języki (19)

| Kod | Język | Pełna dokumentacja | Interfejs aplikacji (Windows i Linux) | Instalator Windows |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (teksty źródłowe) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Jak przełączanie języków działa w praktyce

### 1. Aplikacja Windows (`BatteryHub.exe`)
- **Automatyczne wykrywanie:** gdy wybrano *Język → Automatycznie (język Windows)*, BatteryHub odpytuje funkcję `GetUserPreferredUILanguages` w Windows i dopasowuje najbliższy statyczny plik `*.json`.
- **Ręczne przełączanie:** kliknij widżet paska zadań lub ikonę w zasobniku → **Język** → wybierz język. Interfejs aktualizuje się natychmiast, a wybór jest zapisywany w `HKCU\Software\WirelessBattery\Language`.
- **Statyczne pliki zewnętrzne (edytowalne bez ponownej kompilacji):** `BatteryHub.exe` najpierw ładuje `<exe>\lang\*.json`, a następnie `%APPDATA%\WirelessBattery\lang\*.json`. Każdy plik w folderze użytkownika o tym samym `@code` nadpisuje pasujące frazy, a ponowne otwarcie menu wczytuje pliki z dysku na żywo.
- **CLI `--help`:** `BatteryHub.exe --help` wyświetla okno pomocy w aktywnym języku interfejsu (`--list`, `--json` i `--dump` celowo pozostają po angielsku na potrzeby zgłoszeń na GitHubie).

### 2. Aplikacja Linux (`wireless-battery`)
- **Automatyczne wykrywanie:** podąża za zmiennymi lokalizacji POSIX w kolejności: `LANGUAGE` (lista rozdzielana dwukropkami) → `LC_ALL` → `LC_MESSAGES` → `LANG` (chyba że zostanie nadpisane przez `LC_ALL=C` / `POSIX`).
- **Ręczne przełączanie:** kliknij prawym przyciskiem ikonę w zasobniku → **Język** → wybierz **Automatycznie (język systemu)** lub dowolny zainstalowany język. Zapisywane pod `[general] language=` w `$XDG_CONFIG_HOME/wireless-battery/config.ini` (domyślnie `~/.config/wireless-battery/config.ini`).
- **Statyczne ścieżki wyszukiwania (od najniższego do najwyższego priorytetu):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (domyślnie `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (domyślnie `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help` wypisuje przetłumaczoną pomoc wiersza poleceń na podstawie `config.ini` lub ustawień regionalnych systemu; `--list` i `--dump` pozostają po angielsku.

### 3. Instalator Windows (`BatteryHub-Setup-<version>.exe`)
- Wyświetla okno wyboru języka (`ShowLanguageDialog=yes`) wstępnie ustawione na język interfejsu Windows (`LanguageDetectionMethod=uilanguage`).
- Instaluje pełny statyczny katalog `lang\*.json` do `{app}\lang\` obok `BatteryHub.exe` (przenośne archiwum ZIP również zawiera `lang\*.json`).

---

## Jak dodać lub zaktualizować język (krok po kroku)

Nie potrzebujesz **żadnych** narzędzi do budowania, aby przetłumaczyć interfejs aplikacji lub dokumentację — jedynie Inno Setup 6, jeśli chcesz testowo skompilować instalator systemu Windows.

### Krok 1 — Komunikaty interfejsu aplikacji (`lang/<code>.json`)
1. Otwórz folder języków użytkownika z menu zasobnika (**Język → Dodaj własny język...**) lub skopiuj [`lang/_template.json`](../../lang/_template.json) do `lang/<code>.json` (np. `lang/it.json`).
2. Wypełnij nagłówek metadanych:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Przetłumacz prawą stronę po znaku ` = ` w każdym wierszu.
   - Zachowaj dokładnie symbole zastępcze takie jak `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}`.
   - Użyj `\n` dla jawnych podziałów wiersza.
   - Zapisz jako **UTF-8 (bez BOM)**.
   - Otwórz ponownie menu w zasobniku BatteryHub, aby zobaczyć podgląd od razu — bez ponownej kompilacji!

### Krok 2 — Instalator Windows (`installer/lang/<code>.isl`)
1. Skopiuj [`installer/lang/_template.isl`](../../installer/lang/_template.isl) do `installer/lang/<code>.isl`.
2. **KRYTYCZNE:** zapisz plik jako **UTF-8 z BOM (`EF BB BF`)**, aby Inno Setup poprawnie dekodował znaki Unicode niezależnie od starszych stron kodowych Windows.
3. Wybierz pasujący wariant:
   - **Inno Setup ma już wbudowany Twój język** (sprawdź `C:\Program Files (x86)\Inno Setup 6\Languages\`): zachowaj wyłącznie sekcję `[CustomMessages]` i przetłumacz 6 wierszy (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, zachowując `%1` oraz `%n`). Zarejestruj go w `installer/BatteryHub.iss` w sekcji `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup nie zawiera Twojego języka**: skopiuj `installer/lang/zh-CN.isl` jako pełny wzorzec, ustaw `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, opcjonalnie `RightToLeft=yes`), przetłumacz `[Messages]` oraz `[CustomMessages]` i zarejestruj go po `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Uwaga: identyfikatory `Name:` w sekcji `[Languages]` mogą zawierać wyłącznie litery ASCII, cyfry i podkreślenia (użyj `ptBR`, nie `pt-BR`).

### Krok 3 — Aktywator pulpitu Linux (`linux/wireless-battery.desktop`)
Dodaj zlokalizowany wiersz `Comment[<code>]=...` (w plikach `.desktop` używaj podkreśleń dla tagów regionalnych, np. `Comment[zh_CN]=...`).

### Krok 4 — Kompletna dokumentacja w jednym pliku (`docs/i18n/<code>.md`)
1. Skopiuj [`docs/i18n/_template.md`](_template.md) do `docs/i18n/<code>.md` (zero skryptów generujących — tylko ten jeden plik!).
2. Przetłumacz w całości Spis treści oraz wszystkie 17 sekcji, zachowując:
   - Wszystkie znaczniki kotwic `<a id="sec-..."></a>` oraz `<a id="top"></a>` w niezmienionej postaci
   - Wszystkie bloki kodu, flagi CLI (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), identyfikatory USB `VID:PID`, strony użycia HID, pakiety szesnastkowe, klucze rejestru, ścieżki plików oraz adresy URL dokładnie tak jak w oryginale
   - Względne ścieżki obrazków/plików w niezmienionej postaci (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE` itd.)
3. Zaktualizuj górny pasek `<!-- lang-switcher:start -->` w `docs/i18n/<code>.md` (pogrub swój język, podlinkuj pozostałe), dodaj odnośnik do swojego języka na paskach przełączania w `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` oraz sąsiednich plikach `docs/i18n/*.md`.
4. W przypadku języków pisanych od prawej do lewej (`ar`, `fa`, `he`) używaj standardowego Markdown bez obejmowania całego pliku tagiem `<div dir="rtl">`, aby tabele i bloki kodu renderowały się czysto.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Sekcja:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [Oryginał angielski](../../docs/ardor_fury_v2.md) · [↑ Na górę](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

Odbiornik 2,4 GHz udostępnia stronę użycia HID `000A`, użycie `0000` oraz
5-bajtowy raport wejściowy. Rozgłasza dane samodzielnie; żadne polecenia HID nie są wysyłane.

Zaobserwowane raporty z rzeczywistego sprzętu:

| Raport | Bateria |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

Starszy półbajt bajtu 3 koduje próg (`1`, `3`, `7`, `F` dla
25, 50, 75 i 100 procent). Raporty dla 25% oraz 100% wywnioskowano
z logiki dekodowania aplikacji producenta; użytkownik końcowy następnie
potwierdził, że pozostałe poziomy wyświetlają się poprawnie w skompilowanej aplikacji.
Piąty bajt nie jest stały i nie służy jako sygnatura.

Nasłuch wymaga dwóch zgodnych zdekodowanych progów baterii, a nie dwóch
identycznych całych raportów. Ostatnia potwierdzona wartość jest utrzymywana przez maksymalnie
45 sekund. Globalny interwał automatycznego odświeżania zmienia się na 15 sekund.

Zweryfikowane przez użytkownika końcowego w systemie Windows z ARDOR Fury V2 i Logitech G733:
przechwyty 50% i 75%, okresowa automatyczna aktualizacja, wizualne sprawdzenie 25%/100%
oraz uruchomienie w trybie przenośnym. Raporty dla 25% i 100% nie zostały przechwycone.


---

<a id="sec-areson"></a>
> 📄 **Sekcja:** Areson `25A7` (`docs/areson.md`) · [Oryginał angielski](../../docs/areson.md) · [↑ Na górę](#top)

# Obsługa baterii odbiornika Areson 25A7

## Dlaczego pierwotny program pominął mysz

Redragon M915RGB-WL łączy się przez odbiornik „2.4G Wireless Receiver” firmy Areson/CompX `25A7:FA07`.
Jego bateria nie jest udostępniana jako standardowe użycie HID *Battery Strength*, a system Windows nie ma
dla niej właściwości baterii Bluetooth, ponieważ łącze jest własnościowe 2,4 GHz. Mysz
odpowiada natomiast na aktywne żądanie `GetPower`, więc ani ogólny mechanizm zapasowy HID, ani
Bluetooth nie mogły jej zobaczyć. Nie było sterownika dla tego producenta, więc odbiornik pozostawał
nieprzejęty i cichy.

## Zaobserwowany sprzęt i pakiety

Przetestowano w systemie Windows 11 z myszą Redragon M915RGB-WL dnia 2026-11-17:

| Kierunek | VID:PID | Interfejs | Strona użycia:użycie | Rozmiar raportu |
|---|---|---|---|---|
| żądanie (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 bajtów |
| odpowiedź (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 bajtów |

Odpowiedź przychodzi na innej kolekcji najwyższego poziomu niż ta, do której zapisywane jest żądanie.
W systemie Windows są to `MI_01&COL07` (feature) oraz `MI_01&COL05` (input), dlatego sterownik
otwiera oba uchwyty.

Przechwycone żądanie (`GetPower`, id raportu `08`, polecenie `04`, suma kontrolna dopełnia sumę ramki do `0x55`):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Przechwycona odpowiedź:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Przesunięcia poniżej liczą id raportu jako bajt zerowy:

| Bajt(y) | Znaczenie | Przykład |
|---|---|---|
| 0 | Id raportu odpowiedzi | `09` |
| 1 | Echo polecenia | `04` |
| 2 | Status, 0 = OK | `00` |
| 3–4 | Adres, nieużywany dla `GetPower` | `00 00` |
| 5 | Długość danych (2) | `02` |
| 6 | Poziom baterii, 0–10, w krokach co 10% | `08` = 80% |
| 7 | Flaga ładowania, dowolna wartość niezerowa | `00` = brak ładowania |
| 16 | Suma kontrolna; suma wszystkich 17 bajtów daje `0x55` (mod 256) | `3E` |

Własne oprogramowanie producenta wskazywało 80% dla tej samej ramki, co potwierdza mnożnik ×10.
`GetConnectStatus` (`08 03 …`) odpowiada 1-bajtowym ładunkiem i zgłaszało mysz jako
połączoną w tym samym czasie.

## Inne myszy Areson

Starsze odbiorniki `FA7B` / `FA7C` używane w Redragon M693 raportują poziom naładowania bezpośrednio jako
pełną wartość procentową pod tym samym przesunięciem w odpowiedzi. Zastosowanie mnożnika ×10 tego sterownika pokazałoby tam
800%, więc te identyfikatory produktu celowo nie są przejmowane. Obsługiwane są wyłącznie `FA07` i `FA08`;
`FA08` to alternatywny identyfikator tej samej rodziny i nie został zweryfikowany na tej maszynie.

## Odpytywanie i tożsamość

- Sterownik wysyła wyłącznie żądanie `GetPower` tylko do odczytu. Nigdy nie zapisuje konfiguracji,
  podświetlenia ani danych DPI.
- Każde odświeżenie otwiera kolekcję feature z dostępem zerowym oraz kolekcję input do
  odczytu, wysyła żądanie i czeka do 1,8 s na odpowiedź, z dwiema próbami i opróżnieniem
  kolejki pomiędzy nimi, aby stary raport nie został omyłkowo uznany za odpowiedź.
- Nieudany odczyt niczego nie przejmuje, więc uśpiona mysz zachowuje ostatnią wartość w interfejsie. Wpis
  korzysta z 30-minutowego okresu karencji, zgodnie z innymi sterownikami pasywnymi.
- Klucz urządzenia wyliczany jest z identyfikatora producenta i produktu (`areson:25A7:FA07`), więc przetrwa
  cykl odbioru/uśpienia oraz ponowne podłączenie odbiornika.

## Weryfikacja

Pełna aplikacja została skompilowana przy użyciu MSVC C++17 i Windows SDK oraz uruchomiona z rzeczywistą
myszą. Polecenie `BatteryHub.exe --list` zwróciło:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

Odczyt zgadzał się z wartością procentową wyświetlaną w tym samym momencie przez oficjalne oprogramowanie Redragon.
Plik `build.bat` dla MinGW uwzględnia nowy plik źródłowy; `Makefile` wykrywa go automatycznie poprzez
maskę plików.

## Źródła protokołu

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): 17-bajtowe ramki, podział na feature/input oraz
  reguła sumy kontrolnej `0x55`, odtworzone z przechwytów USB oprogramowania Redragon.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray):
  polecenie `GetPower` oraz skala co 10% na `25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md):
  układ odpowiedzi i inna skala procentowa w rodzinie `FA7B` / `FA7C`.


---

<a id="sec-darkrim"></a>
> 📄 **Sekcja:** DARKRIM SHADOW (`docs/darkrim.md`) · [Oryginał angielski](../../docs/darkrim.md) · [↑ Na górę](#top)

# Odbiornik DARKRIM SHADOW / 寸渊影弑

Przetestowano sprzętowo na `3654:6901`, producent `Jieli Technology`, wersja `0100`.
Użyj interfejsu **3**, użycie `FF02:0002`, nienumerowane 64-bajtowe ładunki wejścia/wyjścia
(65-bajtowe rozmiary raportów HID w Windows). Interfejs 4 również posiada `FF02:0002`, ale używa
ID raportu 2 i nie odpowiadał na ten protokół; jest celowo wykluczony.

Źródło protokołu: oficjalny plik z [pobierania PC Hub](https://app.darkrim.net/hub/zh.html),
`DARKRIM-0.1.26-x64-setup.rar`, pobrany i rozpakowany statycznie bez
instalowania ani uruchamiania oprogramowania producenta. Suma SHA-256 rozpakowanego `DARKRIM.exe`:
`f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Przydatne adresy w tym pliku binarnym:

- `140124C80`: `sendGetBasicInfo(infoType)` wysyła polecenie `0010`, Request `01`,
  ładunek `[infoType, 00]`. Selektor baterii to `01`.
- `140118D30`, `140119200`: nagłówek ramki oraz generowanie CRC.
- `140126DB0`: parser TLV informacji o urządzeniu; TLV `01` to bateria.
- `1400F5660`, `1400FA700`: odbiorcy danych baterii; młodsze siedem bitów daje procent,
  najstarszy bit oznacza ładowanie. Ta sama wartość baterii przychodzi też w `0011` Notify `03`.

Nagłówek: `FE seq cmdLE type index count lengthLE`, po którym następuje ładunek oraz
CRC-16/CCITT-FALSE (wielomian `1021`, wartość początkowa `FFFF`, zapisywane big-endian).
Sekwencja to niezerowy 4-bitowy licznik; szyfrowanie nie jest używane.

Rzeczywiste ładunki żądania/odpowiedzi, przed dopełnieniem zerami HID:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

W odpowiedzi TLV `01 01 28` daje **40%, nie ładuje się**. Produkcyjny sterownik C++
zwrócił tę wartość w trzech kolejnych zapytaniach bez oprogramowania producenta.
Odbiornik wysyła powiadomienia startowe przed pasującą odpowiedzią, zmierzone
na około 406 ms. Należy użyć jednego terminu odpowiedzi 800 ms (plus najwyżej 200 ms na zapis),
bez resetowania go przy niepowiązanych powiadomieniach. Żaden sygnał heartbeat nie jest wymagany.

Sterownik wysyła wyłącznie bateryjne GET. Akceptuje tylko niezaszyfrowaną odpowiedź
o pasującym numerze sekwencji/poleceniu/typie, indeksie zero, liczniku zero lub jeden (sprzęt
używa zera), poprawnej długości/CRC oraz pojedynczym poprawnie sformowanym TLV baterii.
Odpowiedzi pofragmentowane, niezamówione, uszkodzone i spoza zakresu są ignorowane.

## Zaobserwowana precyzja baterii i stan ładowania

Traktuj procent jako **zgrubne oszacowanie, a nie zweryfikowany wskaźnik o rozdzielczości 1%**.
Egzemplarz właściciela wyświetlał postęp ładowania w krokach co 10 punktów procentowych od
40% do 90%. Przy 90% pięć odpowiedzi GET baterii oraz jedno niezamówione powiadomienie
zawierały `DA`: `DA & 7F = 90`, z bitem 7 wskazującym ładowanie. Po odłączeniu przez właściciela
kabla ładowania i dalszym używaniu odbiornika 2,4 GHz, kolejnych
pięć odpowiedzi GET i jedno powiadomienie zawierały `5A`: nadal 90%, teraz z
wyzerowanym bitem ładowania. Wszystkie dwanaście ramek przeszło weryfikację CRC.

Reprezentatywne odpowiedzi na zapytania (sekwencja 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Zarówno sterownik, jak i oficjalna aplikacja pobierają procent bezpośrednio z
młodszych siedmiu bitów. Sterownik nie zaokrągla do dziesiątek, nie mnoży progu przez dziesięć ani nie
interpoluje wartości pośrednich; syntetyczne raporty 47% i 95% pozostają jako 47% i
95% w produkcyjnym parserze. Zaobserwowane zgrubne odczyty pochodzą zatem
ze źródła przed parserem — z raportowania słuchawek/odbiornika. Dokładniejsze odczyty sprzętowe
nie zostały zaobserwowane. Pełna krzywa rozładowywania nie została zarejestrowana,
więc stały krok 10% na każdym poziomie rozładowania lub w innym firmware jest niepotwierdzony.

Ładowanie i następujący po nim stan bez ładowania przy 90% zostały sprawdzone sprzętowo.
Progi niskiego/pełnego naładowania, zachowanie po wyłączeniu słuchawek, tryb Bluetooth
oraz tryb transmisji danych po kablu USB nie były testowane sprzętowo. Dla tych trybów nie deklaruje się wsparcia.
W tej implementacji nie zawarto żadnych aktualizacji firmware, zmian konfiguracji, poleceń EQ,
zmian parowania, resetów ani plików binarnych producenta.

Test: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Sekcja:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [Oryginał angielski](../../docs/hyperx_haste_2.md) · [↑ Na górę](#top)

# Protokół baterii HyperX Pulsefire Haste 2 Wireless

Odczytywany przez `HasteWireless` w `src/drivers/hyperx.cpp`. Zapytania pochodzą z
[ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) i są takie same, jakich używa NGENUITY.

Zweryfikowano na sprzęcie:

- Pulsefire Haste 2 Core Wireless, odbiornik `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, odbiornik `03F0:0F98`, przez użytkownika uzumakiprime (PR #312). Poziom pokrywał się z HyperX NGENUITY.

Odbiornik `03F0:0D97` powinien działać tak samo, ale nie jest przetestowany.

## Kolekcja HID

| Pole | Wartość (`0F98`) |
|---|---|
| Interfejs USB | `MI_02` (interfejs 2) |
| Strona użycia : użycie | `FF00:0001` |
| Długość raportu wejściowego / wyjściowego / funkcji | 64 / 64 / 64 bajty |

Odbiornik udostępnia również standardowe kolekcje myszy i sterowania multimediami (consumer-control). Sterownik otwiera wyłącznie
kolekcję producenta (strona użycia `FF00` lub wyższa) z raportami wejściowymi o długości co najmniej 8 bajtów.

## Zapytania

Oba są raportami wyjściowymi: poniższe pierwsze dwa bajty dopełnione zerami do długości raportu. Każda odpowiedź to raport
wejściowy, którego pierwszy bajt jest równy poleceniu powiększonemu o jeden. Każde zapytanie czeka maksymalnie sekundę na swoją odpowiedź i pomija
niepowiązane raporty (po ponownym połączeniu odbiornik sam wysyła raporty `44 xx`, `45 xx` oraz `FB xx`).

| Żądanie | Odpowiedź | Znaczenie |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0, gdy mysz jest wyłączona lub poza zasięgiem |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0–100; `charge` 1 = ładowanie, 2 = pełna na ładowarce; napięcie w mV, little-endian (0 w wersji Core) |

- Jeśli brak odpowiedzi o połączeniu, decyduje odpowiedź o baterii.
- Jeśli połączenie zgłasza 0, nie jest wysyłane zapytanie o baterię, a mysz jest pokazywana jako wyłączona.
- Przez kilka sekund po włączeniu mysz zgłasza około 40%. Odczyt w ciągu 6 s od nawiązania połączenia jest
  ignorowany, a zasobnik zachowuje ostatnią wartość.

Oba żądania odczytują wyłącznie stan. Nic nie zmienia ustawień, podświetlenia ani trybów.


---

<a id="sec-inphic"></a>
> 📄 **Sekcja:** Inphic IN10 (`docs/inphic.md`) · [Oryginał angielski](../../docs/inphic.md) · [↑ Na górę](#top)

# Rodzina Inphic IN10, odbiornik KP 8K

Podłączone urządzenie, zidentyfikowane przez właściciela jako IN10 MAX, zgłasza się jako
`Inphic KP 8K`, `1D57:FA65`, wersja `0116`. Jego kolekcja statusu to
interfejs 2, użycie `000A:0000`, długość wejścia 5 (wraz z ID raportu 03).

Zaobserwowano co około cztery sekundy, bez wysyłania żadnego żądania:

```text
03 73 41 01 64
```

Istniejący parser Xenta rozpoznaje ten format: model, zdarzenie, stan baterii,
procent. Wymagane są dwa identyczne raporty przed wyświetleniem 100%; pierwszy
raport po połączeniu może być mylącym odczytem pełnego naładowania w pokrewnych odbiornikach.
Ta zmiana zachowuje to zabezpieczenie oraz dotychczasowe zachowanie ładowania/uśpienia.

Oficjalny pakiet [Inphic HUB](https://hub.inphic.cn/) `assets/index-BcHQx9B6.js`
mapuje dziesiętny numer modelu 115 (`73`) na `IN10RMax`, a 116 (`74`) na `IN10Max`.
Używa stanu baterii 1 dla procentu, 2 dla pełnego naładowania i 3 dla ładowania.
Należy używać nazwy modelu z firmware zamiast przypisywania `73` do IN10 MAX i
potencjalnego błędnego oznaczania innych urządzeń dzielących ten odbiornik.

Przed tą zmianą aplikacja wyświetlała podłączoną mysz jako `Wireless mouse`.
Transport Xenta obsługiwał już jej ramki baterii; zmiana dostarcza
brakujących nazw modeli. Świeże wywołanie `--list` może pokazać uśpienie, ponieważ jego pięciosekundowa
początkowa obserwacja może odebrać tylko jeden raport nadawany co cztery sekundy. Aplikacja działająca w tle
utrzymuje nasłuch i potwierdza wartość przy kolejnym odświeżeniu.

Zweryfikowano sprzętowo: raporty pasywne, powtórzony poziom 100% oraz identyfikację modelu
przez natywny sterownik. Przejścia ładowania, progi niskiej baterii, tryb Bluetooth oraz tryb
przewodowy nie zostały zweryfikowane. Model `74` pochodzi z oficjalnej tabeli i
nie był testowany na osobnym sprzęcie.


---

<a id="sec-machenike"></a>
> 📄 **Sekcja:** Machenike L7 (`docs/machenike.md`) · [Oryginał angielski](../../docs/machenike.md) · [↑ Na górę](#top)

# Machenike L7 Arctic / L7 Mix

Zweryfikowano na L7 Arctic, która identyfikuje się jako **L7 Mix**:

| Połączenie | VID:PID | Interfejs | Użycie | Wejście / wyjście / maks. feature |
| --- | --- | --- | --- | --- |
| Odbiornik 2,4 GHz | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| Kabel USB | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

Sterownik sprawdza również nazwę produktu HID `L7 Mix`. Inne modele Machenike,
inne identyfikatory odbiorników oraz zapytania producenta przez Bluetooth nie są włączone.

## Źródło protokołu

Analiza interoperacyjności oficjalnego oprogramowania **Machenike L7 Mix 1.0.0.8**,
dostępnego na [stronie sterowników producenta](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/),
oraz zapytania tylko do odczytu na rzeczywistej myszy. Suma SHA-256 pliku `DeviceDriver.exe`:
`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

W tym 32-bitowym pliku wykonywalnym (baza obrazu `00400000`) funkcja pod VA `00436750` buduje
żądanie statusu; `004494F0` wysyła je przez `HidD_SetFeature` i odczytuje
odpowiedź feature. Parser statusu `00410C20` wyodrębnia poniższe pola i przekazuje
pola baterii oraz ładowania do interfejsu. Są to adresy wirtualne, a nie przesunięcia w pliku.
Nie dołączono tu żadnego własnościowego pliku wykonywalnego, kodu aplikacji ani zasobów.

## Zapytanie odczytu stanu

Wyślij **21 bajtów**, ID raportu `51`, polecenie `06`, wszystkie pozostałe bajty zerowe:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Odczytaj raport funkcji `51`, również używając 21 bajtów. Maksymalny rozmiar raportu feature kolekcji
wynosi 1001 dla innych raportów; nie jest to długość raportu statusu.
Sterownik czeka 10 ms przed odczytem i stosuje jeden limit czasu 200 ms na produkt,
wliczając niepowiązane odpowiedzi. Nie wysyła żadnych poleceń ustawień, trybu, makr ani firmware.

Indeksy zawierają ID raportu:

| Bajty | Znaczenie / zaobserwowane wartości |
| --- | --- |
| 0–1 | `51 06`, wymagane echo polecenia |
| 4–7 | `8A 24 4E FF`, zweryfikowana sygnatura urządzenia L7 |
| 10, bity 0–2 | Tryb pracy: 1 na odbiorniku, 0 na kablu |
| 10, bit 3 | Mysz bezprzewodowa połączona; wyzerowany także na kablu USB |
| 11 | Procent baterii, 0–100 (zero jest prawidłowe) |
| 12 | Flaga ładowania: 0 rozładowywanie, 1 ładowanie |

Znaczenie pozostałych pól i sumy kontrolnej nie jest ustalone. Sterownik nie
wymyśla sumy kontrolnej. Waliduje polecenie, długość, sygnaturę urządzenia, tryb oraz
zakresy baterii/ładowania dla stanu połączonego przed opublikowaniem odczytu.

Przechwycona odpowiedź odbiornika, również 64% w oficjalnej aplikacji:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Przechwycona odpowiedź z kabla USB podczas ładowania (74%):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

W tym momencie odbiornik nadal zwracał zbuforowane 64%, ale wyzerował bit połączenia:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Ten rozłączony odczyt nie może ujawniać zbuforowanych wartości baterii/ładowania.
Kabel ma pierwszeństwo, gdy obecne są oba połączenia, a stabilny klucz urządzenia
jest współdzielony między transportami. Znana L7 jest rezerwowana nawet przy błędzie zapytania, aby
późniejszy sterownik Ajazz nie mógł odpytywać jej innym protokołem na współdzielonym VID.

## Granice weryfikacji

Dane testowe (fixtures) i testy symulowanego transportu obejmują przechwycone odczyty, ładowanie,
prawidłowe 0%/100%, odłączone odbiorniki, uszkodzone/przeterminowane odpowiedzi, ścisłe dopasowanie,
błędy transportu, tłumienie duplikatów oraz ograniczone pętle ponowień. Rzeczywiste 0%/100%
oraz wszystkie warianty uśpienia/firmware nie wynikają z tych testów.


---

<a id="sec-nuphy"></a>
> 📄 **Sekcja:** NuPhy WH80 (`docs/nuphy.md`) · [Oryginał angielski](../../docs/nuphy.md) · [↑ Na górę](#top)

# NuPhy WH80 (kabel USB i Bluetooth)

Przetestowano sprzętowo z `19F5:A011`, wydanie firmware `0116`, interfejs 1,
użycie `0001:0000`, nienumerowane 64-bajtowe ładunki wejścia/wyjścia (65 bajtów w możliwościach HID Windows).

Źródło protokołu: [NuPhyIO](https://drive.nuphy.io/), pakiet `main.b3fb29e0.js`,
funkcje SDK `getBatteryState(0)`, `getDataPackage` oraz `createCommand`.
Wysyłane jest wyłącznie żądanie `GetFunc` (`05`), przesunięcie `0020`, długość `01`. Żadne polecenia inicjalizacji,
konfiguracji, podświetlenia ani firmware nie są potrzebne.

Ładunek żądania, dopełniony zerami do 64 bajtów:

```text
55 05 00 21 01 20 00 00
```

Rzeczywisty ładunek odpowiedzi:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

Bajt 3 to młodszy bajt sumy bajtów 4..63. Bateria to bajt 8:
`value & 7F` to procent, a `value & 80` to flaga ładowania SDK.
Natywny sterownik C++ zwrócił **100%, ładowanie** na podłączonej klawiaturze.
Przejścia ładowania oraz progi niskiego/pełnego naładowania nie były testowane sprzętowo;
oficjalne informacje o firmware opisują odczyty WH80 w przyrostach co 10%.
Działanie przez odbiornik wykracza poza zakres tego sterownika.

## Bluetooth

Przez Bluetooth ta sama klawiatura używa identyfikatora HID `19F5:324A` (wydanie `0129`) i
rozgłasza widoczną dla użytkownika nazwę, taką jak `NuPhy WH80 - 1`. Udostępnia dwie kolekcje klawiatury
oraz kolekcję myszy. Ogólna heurystyka HID nadaje priorytet myszom,
więc należy dodać ten konkretny identyfikator Bluetooth do istniejących nadpisań klawiatur.

Raportowanie baterii nadal korzysta z właściwości baterii Bluetooth systemu Windows.
Po odłączeniu USB system Windows zgłosił **95%** na podłączonej klawiaturze. Niebuforowany
odczyt standardowego GATT Battery Level (`180F` / `2A19`) również zwrócił
**95%** bezpośrednio z klawiatury. Jest to
oddzielny odczyt urządzenia/transportu względem przewodowej obserwacji 100%; nie należy
zastępować go zakładaną wartością pełną ani przeskalowywać. Przyczyna rozbieżnych
odczytów firmware nie została ustalona.

Sterownik sprawdza dokładny produkt/interfejs/rozmiary raportów, nagłówek odpowiedzi,
przesunięcie, długość, sumę kontrolną oraz zakres procentowy. Używa limitu czasu odpowiedzi 400 ms
i ignoruje niepowiązane odpowiedzi w ramach tego samego limitu.

Test regresyjny:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Sekcja:** Rapoo (`docs/rapoo.md`) · [Oryginał angielski](../../docs/rapoo.md) · [↑ Na górę](#top)

# Obsługa baterii myszy Rapoo

## Dlaczego pierwotny program pominął mysz

`PollAllDevices()` wylicza kolekcje najwyższego poziomu Windows HID raz na odświeżenie. Każdy sterownik
producenta rozpoznaje protokół, dodaje `DeviceStatus` i przejmuje jego VID/PID, aby sterowniki ogólne
nie dodały go ponownie. Interfejs użytkownika obsługuje już procent, ładowanie oraz ostatni odczyt w stanie uśpienia.

Nie istniał sterownik Rapoo. VT3 Max Gen 2 wysyła swoją baterię w raporcie wejściowym zdefiniowanym przez producenta,
a nie w standardowym użyciu HID Battery Strength ani właściwości baterii Bluetooth systemu Windows. Istniejące
ogólne mechanizmy zapasowe HID/Bluetooth nie mogły więc zdekodować jej odbiornika USB.

## Zaobserwowany sprzęt i pakiety

Przetestowano w systemie Windows z myszą VT3 Max Gen 2 właściciela dnia 2026-11-16:

| Połączenie | VID:PID | Interfejs | Strona użycia:użycie | Rozmiar wejścia / wyjścia |
|---|---|---|---|---|
| Odbiornik 2,4 GHz | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 bajtów |
| Kabel USB | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 bajtów |

Oba przedstawiają się jako `Rapoo Gaming Device`. Pozostałe kolekcje obejmują standardowe wejścia myszy,
klawiatury i multimediów, kolekcje konfiguracyjne producenta oraz 513-bajtowy interfejs firmware.
Sterownik baterii otwiera wyłącznie `FF00:0002` o rozpoznanym rozmiarze wejścia. Nigdy nie otwiera interfejsu
firmware i nigdy nie wysyła raportu wyjściowego, raportu funkcji, powitania (handshake) ani polecenia konfiguracji.

Przechwycony raport bezprzewodowy wraz z ID raportu:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Przechwycony raport kabla/ładowania:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Przesunięcia poniżej liczą ID raportu jako bajt zerowy, zgodnie z funkcją `HidDev::Read()` w tym projekcie:

| Bajt(y) | Znaczenie | Przykład |
|---|---|---|
| 0 | ID raportu | `07` |
| 1 młodszy półbajt | Połączenie: 0 odbiornik, 1 Bluetooth, 2 kabel | `20` / `22` |
| 1 starszy półbajt | Informacja o sensorze; nie jest częścią typu połączenia | `2` |
| 2 | Aktualny bieg DPI | `03` |
| 3–4, 5–6 | X/Y DPI, little endian | `0320` = 800 |
| 7 | Stan baterii: 0 nieprawidłowy, 1 rozładowywanie, 2 ładowanie | `01` / `02` |
| 8 | Procent baterii, 0–100 | `19` = 25% |
| 13–14 | Identyfikator produktu myszy, little endian, gdy obecny | `4617` |

Przechwycenie na żywo z odbiornika zgłosiło `25%`, a kompletna aplikacja następnie zwróciła
`27%, charging` po kablu. Test parsera obejmuje rzeczywisty przechwyt bezprzewodowy. Ładowanie oraz łączność po kablu
również zostały zweryfikowane na rzeczywistym sprzęcie; nie są wnioskowane wyłącznie na podstawie obecności urządzenia USB.
Po odłączeniu kabla przez właściciela i ponownym podłączeniu odbiornika końcowy plik wykonywalny zwrócił
`52%` przez `2.4 GHz receiver`, bez flagi ładowania, i zachował ten sam klucz `rapoo:4617`.
Potwierdza to także przejście z kabla na odbiornik na rzeczywistym sprzęcie.

Przetestowano także w systemie Windows z **VT9 Gen 2** dnia 2026-11-17:

| Połączenie | VID:PID | Interfejs | Strona użycia:użycie | Rozmiar wejścia / wyjścia |
|---|---|---|---|---|
| Odbiornik 2,4 GHz | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 bajtów |
| Kabel USB | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 bajtów |

Odbiornik VT9 Gen 2 udostępnia **16-bajtowy** raport `FF00:0002` zamiast 19 bajtów, korzystając z dokładnie
tego samego układu Nordic 54L `07` (w tym osadzonego PID `4614` na bajtach 13–14). Przechwycone ramki:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # odbiornik: 100%, rozładowywanie
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # kabel USB (przełącznik ON): 100%, ładowanie
```

Przez kabel USB raporty statusu obserwowano przy interakcji (np. zmianie DPI); przy dolnym
wyłączniku zasilania ustawionym na OFF podczas podłączenia, mysz zgłaszała `state=2, percent=1` zamiast
rzeczywistego procentu baterii.

### Odbiornik VT3 Max Gen 2 z 13-bajtową kolekcją (zgłoszenie #1396)

Raport formularza prośby o urządzenie dla tego samego identyfikatora odbiornika `24AE:1417` wymieniał inny układ
interfejsów: `FF00:0002` o długości **13 / 13** bajtów (zamiast 19) oraz `FF00:000E` o długości 33 / 33 bajtów,
bez 513-bajtowej kolekcji firmware. Wygląda to na inną wersję oprogramowania układowego odbiornika. Oprogramowanie
Rapoo nadal pokazywało baterię, więc sterownik ignorował działający kanał statusu.

Dekoder `VT_nrf54L` (`py`) z Rapoo Hub jest adaptacyjny względem długości: zawsze odczytuje DPI, stan baterii
oraz procent, a późniejsze pola (PID myszy w `n[12..13]`, informacje RF itd.) odczytuje tylko
wtedy, gdy raport jest wystarczająco długi. Manifest VT3 MAX (`productId: [17943, 5143]`) nie ma specjalnego
typu raportu wejściowego, więc raport `07` trafia do tego dekodera również na tym odbiorniku. 13-bajtowy raport
(ID plus 12 bajtów) nadal przenosi stan na bajcie 7 i procent na bajcie 8; brakuje jedynie osadzonego PID myszy,
więc odczyt używa PID odbiornika i zachowuje klucz `rapoo:4617`.

Długość 13 bajtów jest akceptowana **wyłącznie dla `24AE:1417`**. Ramki nadal muszą przejść te same kontrole
(raport `07`, półbajt połączenia 0–2, stan 1/2, procent 0–100). Nie przechwycono jeszcze żadnej rzeczywistej 13-bajtowej
ramki; testy wykorzystują przetestowane 19-bajtowe przechwycenie przycięte do 13 bajtów.

## Inne myszy Rapoo

Oficjalny Rapoo Hub używa tego układu `07` dla swojego sterownika myszy Nordic 54L. Jego manifesty
wymieniają VT0, VT1, VT2, VT3, VT3S, VT7, VT9 i dodatkowe warianty. Inspekcja bieżącego pakietu
wskazała 69 wariantów VT używających `VT_nrf54L`; jest to dowód współdzielonego protokołu, a nie 69 sprzętowych
walidacji czy deklaracji pokrycia większości całego katalogu Rapoo. Obsługa wybierana jest po VID Rapoo,
dedykowanej kolekcji, długości wejścia i prawidłowym raporcie statusu, więc niewymieniony model na tym samym
protokole również może zgłaszać baterię. Mała tabela nazw pokrywa popularne modele; pozostałe zachowują swoją
nazwę produktu HID lub pokazują `Rapoo wireless mouse`.

Nazwy produktów i identyfikatory różnią się między generacjami i regionami. Przetestowana para `1417/4617` nazywa się
`VT3 MAX` w obecnym oficjalnym manifeście; właściciel identyfikuje ją jako VT3 Max Gen 2. Osobny wpis
`VT3 MAX V2` w obecnym manifeście ma identyfikatory `1B06/4B06`. Tabele społeczności przypisujące `1417` do VT9 Pro
nie mogą być używane jako jedyna podstawa do nazywania ani wykrywania tego urządzenia.

Starsze oprogramowanie układowe VT, udokumentowane dla VT3 Pro (`1215/4415`), zamiast tego wypycha 7-bajtowy raport na tym samym
użyciu `FF00:0002`:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

W tym starszym formacie stany 1/2 oznaczają rozładowywanie/ładowanie. Procent ładowania `7F` oznacza
nieznany i jest zachowywany jako nieznany. Stan przejściowy 0, niepowiązane raporty `BC`, uszkodzone pakiety
oraz wartości procentowe powyżej 100 są ignorowane. Starsza obsługa ma pokrycie w testach automatycznych, ale nie została
tu zweryfikowana na fizycznej starszej myszy. Ta interpretacja jest ograniczona do identyfikatorów produktów
`1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) oraz ich 7-bajtowej kolekcji wejściowej.

VT1 Pro Max (odbiornik `24AE:1233`, kabel `24AE:4433`, firmware myszy 222, firmware odbiornika 213)
została dodana na podstawie przechwytów USBPcap dołączonych przez właściciela do zgłoszenia #136. Wynik `--dump` wymienia
7-bajtową kolekcję `FF00:0002` na interfejsie 1, a przechwyty pokazują jej rozgłaszanie, bez żadnego żądania
ze strony aplikacji Rapoo:

```text
BB B0 71 84 03 01 64   odbiornik, co ~3,2 s; aplikacja Rapoo pokazywała 100%
BB B0 71 84 03 02 5F   kabel, ładowanie, 95%; aplikacja Rapoo pokazywała „Charging”
```

Po kablu raport zaobserwowano tylko raz w ciągu 16-sekundowego przechwycenia, więc odczyt wyłącznie po kablu może
przekroczyć limit czasu przy niektórych odświeżeniach; odbiornik wysyła go regularnie. Profil Nordic nigdy nie interpretuje pakietów `BB`.

**Nie** oznacza to wsparcia dla każdego urządzenia Rapoo. Modele CH584, takie jak VT1 SE i VT7 SE,
używają raportu `08` w oficjalnym sterowniku i nie są obsługiwane przez ten dekoder. Inne rewizje Telink używają innej
interpretacji flag `BB`, niektóre modele biurowe korzystają z aktywnych zapytań o baterię, a modele Bluetooth
mogą udostępniać jedynie właściwość baterii systemu Windows. Pozostają one przy istniejących mechanizmach zapasowych lub wymagają
osobnej zweryfikowanej implementacji. Nie należy wysyłać do nich odgadywanych zapytań.

## Odpytywanie i tożsamość

- Odczyt jest pasywny. Pasujące uchwyty `FF00:0002` pozostają otwarte pomiędzy odświeżeniami (analogicznie do `PollXenta`),
  dzięki czemu system Windows buforuje ramki statusu napływające w 60-sekundowym interwale odświeżania; każde odświeżenie opróżnia
  wszystkie zakolejkowane ramki (zachowując najnowszy prawidłowy odczyt baterii), zanim przejdzie do 5-sekundowego
  oczekiwania przy pierwszym otwarciu lub pustej kolejce. Odłączone urządzenia są usuwane, a ich uchwyty zamykane.
  Niepowiązane pakiety nie resetują limitu czasu.
- Osadzony PID myszy lub znana para kabla/odbiornika dla starszych urządzeń daje ten sam klucz interfejsu
  przy zmianach kabla. Odczyty z kabla i odbiornika są scalane w jeden wpis, preferując stan kabla,
  przy jednoczesnym zachowaniu prawidłowego procentu z odbiornika, jeśli kabel zgłasza nieznany poziom.
- Przekroczenie limitu czasu nie wymyśla wartości procentowej ani nie przejmuje urządzenia. Po udanym odczycie
  istniejący interfejs może zachować ten odczyt jako przyciemniony przez 30 minut ciszy.
- Dotychczasowy model tożsamości programu oparty na VID/PID nie rozróżnia wielu identycznych myszy
  o tym samym ID modelu. Fizyczna jednoczesna praca kabla i odbiornika nie była testowana; scalanie
  obu wejść jest pokryte testem symulowanego transportu.

## Weryfikacja

`make test` uruchamia przenośny test dekodera oraz test sterownika Windows z symulowanymi odpowiedziami HID.
Zakres obejmuje rzeczywiste przechwycenie, 0% i 100%, ładowanie, brakujące poziomy, nieprawidłowe/obcięte ramki,
nieobsługiwane kolekcje/producentów, izolację profili protokołów, limity czasu, stabilne klucze oraz deduplikację kabla/odbiornika
bez odrzucania znanego procentu.

Pełna aplikacja została skompilowana lokalnie przy użyciu MSVC C++17 oraz Windows SDK, a `--list` / `--dump`
zostały uruchomione na rzeczywistej myszy. Utrzymywana kompilacja MinGW zawiera `rapoo.cpp` w `build.bat`;
Makefile wykrywa go automatycznie. Sam kompilator MinGW nie był zainstalowany w środowisku testowym.

## Źródła protokołu

- [Oficjalny Rapoo Hub](https://hub.rapoo.cn/), zbadany 2026-11-16: wbudowany
  [sterownik JavaScript i manifesty](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js).
  Istotne dekodery to `py`/`Hk` dla `VT_nrf54L` oraz `qM`/`QM` dla znaczeń połączenia i stanu
  baterii. Osobna obsługa `VT_CH584` konsumuje raport `08` i znajduje się poza tą implementacją.
  Zminifikowane nazwy mogą zmienić się w przyszłych wydaniach.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs),
  dla starszych raportów VT3 Pro, stanu ładowania i znacznika nieznanego poziomu.
- Przechwyty USBPcap ze zgłoszenia #136 (VT1 Pro Max na odbiorniku i na kablu podczas ładowania).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js)
  niezależnie potwierdza pasywne rozgłoszenia statusu `07` i przesunięcie baterii. Jego parser
  przycina nieprawidłowe procenty; ta implementacja zamiast tego je odrzuca.


---

<a id="sec-rawm"></a>
> 📄 **Sekcja:** RAWM (`docs/rawm.md`) · [Oryginał angielski](../../docs/rawm.md) · [↑ Na górę](#top)

# Uwagi o protokole RAWM

Myszy RAWM (oraz SADES Dagger, która współdzieli platformę) rozmawiają z aplikacją RAWM HUB przez
kolekcję HID producenta `FF00:0001` z 64-bajtowymi nienumerowanymi raportami wejściowymi i wyjściowymi (65 bajtów
z ID raportu). Odbiorniki i myszy używają identyfikatora producenta Nordic `1915`.

Źródło: aplikacja webowa RAWM HUB, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>) oraz jej skrypt
`https://hub.miracletek.net/hub/js/library.min.js` (zaciemniony; nazwy funkcji i stałych poniżej
pochodzą z samego skryptu). Obsługiwane identyfikatory produktów pochodzą z tabeli urządzeń pobieranej przez aplikację
(`https://www.miracletek.net/game/device.php`). Leviathan V4 GT i NYX60 używają Hub Web 3.0 na VID
`373E`, co jest innym protokołem.

## Pakiety

Bajt 0 każdego raportu (po ID raportu):

| Najstarsze bity | Znaczenie |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | młodsze 6 bitów to rozmiar ładunku; ładunek kontynuuje strumień zdarzeń |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | kontrola przepływu (rozmiary wolnych buforów); ignorowane tutaj |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | młodsze 6 bitów to kanał ESB; reszta raportu to pakiet dla tego kanału. Mysz za odbiornikiem to kanał 0 |

Ładunki tworzą strumień bajtów zdarzeń:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## Odczyt baterii

Sterownik powtarza to, co robi aplikacja po podłączeniu odbiornika (`send_event_query`, `send_event_ping`):

1. Do odbiornika: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), następnie
   pingi `00 84 0E 04 00 00`. Urządzenie wysyła dane tylko wtedy, gdy host ciągle pisze, więc host wysyła pingi.
   Odbiornik odpowiada `CMD_QUERY_RESULT` (`02`) obiektem JSON, np.
   `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. To samo zapytanie i pingi dla kanału 0, poprzedzone bajtem `C0`. Mysz odpowiada ~550-bajtowym obiektem JSON
   w 30-bajtowych fragmentach ESB, np. `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`.
   `battery` to wartość procentowa (RAWM HUB pokazuje ją bezpośrednio), `chr` wynosi 1 podczas ładowania.
3. Późniejsze zmiany przychodzą jako `CMD_NOTIFY` (`0B`) typu `17`: `[17, percent, charging]`.

Sterownik zawsze pyta najpierw odbiornik, tak jak aplikacja (w jednym teście zapytanie wysłane tylko do kanału 0
nie otrzymało odpowiedzi). Uśpiona mysz nie odpowiada w ogóle; odbiornik nadal odpowiada.

Zapytanie przenosi zegar komputera, ponieważ aplikacja wysyła je w ten sposób; nic więcej nie jest zapisywane.
Myszy zgłaszają `"crc":1`, co nakazuje aplikacji opakowywać późniejsze polecenia (konfiguracji) w ramkę CRC-16;
zapytanie oraz pingi są akceptowane bez niej, ponieważ aplikacja wysyła je, zanim się o tym dowie.

Przetestowano na Leviathan V4 (firmware 1.2.0) z odbiornikiem RAWM HS Receiver `1915:2346` (firmware 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **Sekcja:** VAXEE (`docs/vaxee.md`) · [Oryginał angielski](../../docs/vaxee.md) · [↑ Na górę](#top)

# Odbiorniki VAXEE 4K/8K i ZYGEN NP-01S V2

## Zakres i weryfikacja sprzętowa

Ten sterownik obsługuje odbiornik VAXEE 4K `3057:1002`, odbiornik VAXEE 8K
`3057:2002` oraz ZYGEN NP-01S V2 Wireless przez kabel USB (`3057:1011`), na
ich kolekcji producenta `FF05:0001` z 64-bajtowym raportem funkcji. Inne odbiorniki
VAXEE, inne identyfikatory produktów po kablu oraz urządzenia ZOWIE celowo nie są
odpytywane.

Odbiornik 8K (`VAXEE 8K Wireless`, sparowany z NP-01 Ergo Wireless 8K)
został przetestowany w systemie Windows i zaraportowany tym samym protokołem:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

Odbiornik jest współdzielony przez wszystkie myszy VAXEE 8K i nie zgłasza, która z nich jest
sparowana, więc jest pokazywany pod własną nazwą. Status ładowania na odbiorniku 8K nie został jeszcze zaobserwowany sprzętowo.

Rzeczywisty odbiornik 4K został przetestowany w systemie Windows:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

Zintegrowana aplikacja zgłosiła również:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

Następnie tę samą mysz podłączono bezpośrednio przez USB, a system Windows zidentyfikował
ją jako `ZYGEN NP-01S V2 Wireless` (`3057:1011`). Zaktualizowany sterownik produkcyjny
zgłosił:

```
VAXEE battery: 75%; charging: yes
```

Widżet paska zadań został utworzony pomyślnie w początkowej kompilacji odbiornika.
Zaobserwowano zarówno pracę na baterii przez odbiornik, jak i ładowanie przewodowe;
przejścia pełnego naładowania oraz zachowanie w stanie uśpienia/wyłączenia nie były testowane na
sprzęcie. Dekodowanie ładowania i nieprawidłowe odpowiedzi są pokryte symulowanymi
odpowiedziami.

## Protokół

Źródło: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

Żądanie to 64-bajtowy raport funkcji HID dopełniony zerami:

| Bajt | Wartość |
|---|---|
| 0 | `0E`, ID raportu |
| 1 | `A5`, nagłówek |
| 2 | `0B` dla poziomu baterii; `10` dla statusu ładowania |
| 3 | `01`, flaga odczytu (nigdy `02`, zapis) |
| 4 | `01`, długość danych |
| 5–63 | `00` |

Po wysłaniu żądania przez `HidD_SetFeature` odczekaj 100 ms i odczytaj raport
`0E` za pomocą `HidD_GetFeature`. Wymagane jest co najmniej sześć bajtów oraz oczekiwane ID
raportu, nagłówek, echo polecenia i długość danych.

Dla baterii bajt odpowiedzi 5 musi wynosić 0–20 i jest mnożony przez pięć, dając
0–100% w krokach co 5%. Dla ładowania bajt 5 jest niezerowy podczas ładowania. Nieudane
zapytanie o ładowanie nie odrzuca poprawnego w pozostałym zakresie odczytu baterii.

Sterownik ponawia żądanie baterii jeden raz. Na pasującą kolekcję przypadają maksymalnie trzy
żądania odczytu (dwie próby baterii i jedno zapytanie o ładowanie), z łącznym jawnym opóźnieniem 300 ms.
Nie wysyła żadnych poleceń ustawień, parowania, firmware ani podświetlenia.

Jeśli nie otrzymano prawidłowej odpowiedzi o baterii, sterownik nic nie zgłasza i pozostawia
urządzenie nieprzejęte. Dopóki kolekcja USB jest obecna, interfejs zachowuje
wcześniejszy udany odczyt jako przyciemniony przez maksymalnie 30 minut, wykorzystując dotychczasowy
mechanizm okresu karencji. Jeśli fizyczna kolekcja zniknie, sterownik emituje
jeden status rozłączenia, aby natychmiast zakończyć ten okres karencji. Zapobiega to
pozostawaniu nieaktualnej ikony odbiornika po przełożeniu kabla do myszy.

## Testy

`make test` obejmuje `tests/vaxee_driver_test.cpp`, który linkuje sterownik
produkcyjny z symulowanym transportem HID. Sprawdza dokładne wychodzące
żądania tylko do odczytu, konwersję procentów, dekodowanie ładowania, nieprawidłowe i
brakujące odpowiedzi, już przejęte urządzenia oraz dokładne filtrowanie kolekcji.
