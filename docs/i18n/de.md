<!--
  Vollständige Übersetzung der BatteryHub-Dokumentation (Deutsch)
  Quelle: docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Sprachen:** [English](../../README.md) | [العربية](ar.md) | **Deutsch** | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Sprache hinzufügen](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Vollständige Dokumentation (Deutsch)

> Diese einzelne eigenständige Markdown-Datei bündelt alle sichtbaren Dokumente des Repositorys, sodass Übersetzer nur **eine Datei pro Sprache** pflegen müssen.

## Inhaltsverzeichnis

1. [BatteryHub Übersicht, Unterstützte Geräte, Installation, CLI & Kompilieren (`README.md`)](#sec-readme)
2. [Leitfaden für Mitwirkende (`CONTRIBUTING.md`)](#sec-contributing)
3. [Pull-Request-Vorlage (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Release- & Signaturleitfaden (`docs/releasing.md`)](#sec-releasing)
5. [Keychron-Tastatur 2,4-GHz-Firmware-Patch (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [GameSir Cyclone Pro BLE-Unterstützung (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Leitfaden zur Mehrsprachigkeit & Lokalisierung (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Areson 25A7 Empfänger (`docs/areson.md`)](#sec-areson)
10. [DARKRIM SHADOW Empfänger (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K Empfänger (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Rapoo-Maus-Akkuunterstützung (`docs/rapoo.md`)](#sec-rapoo)
16. [RAWM-Protokollhinweise (`docs/rawm.md`)](#sec-rawm)
17. [VAXEE 4K/8K Empfänger (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Abschnitt:** BatteryHub Übersicht (`README.md`) · [Englisches Original](../../README.md) · [↑ Nach oben](#top)

# BatteryHub

*Ehemals **Wireless Battery**. Mit Version 1.1.0 wurde die App umbenannt; ein Update behält deine Einstellungen, die Autostart-Auswahl und den Akkuverlauf bei.*

[![Auf Ko-fi unterstützen](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Über PayPal spenden](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Unserem Discord beitreten](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Stern auf GitHub vergeben](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Auf Reddit teilen](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Gerät melden](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Beim Übersetzen helfen](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Akkustände deiner kabellosen Maus, deines Headsets, deiner Tastatur und deines Controllers direkt in der Windows-Taskleiste.

![BatteryHub in der Taskleiste](../screenshot.png)

> **Einfach loslegen?** Lade **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** aus dem neuesten Release herunter, starte das Setup und klicke dich durch. Fertig.
>
> **Erfahrene Nutzer** können das portable ZIP herunterladen, die [Befehlszeilenoptionen](#befehlszeile) verwenden oder das Programm mit `make` oder `build.bat` [aus dem Quellcode kompilieren](#kompilieren).
>
> **Gefällt es dir?** BatteryHub ist kostenlos und Open Source. Wenn es dir den Umweg über Hersteller-Software erspart, kannst du das Projekt auf [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) oder [GitHub Sponsors](https://github.com/sponsors/krisgfx9) unterstützen. Das hilft mir, meine Apps neben dem Studium kostenlos zu halten. Keine Spende möglich? Ein ⭐ Stern auf GitHub, das Teilen des Projekts oder das Melden eines nicht unterstützten Geräts mit `--dump` hilft genauso sehr.

- **Winzig**: eine ca. 350 KB große App mit rund 2 MB RAM-Verbrauch. Reines C++/Win32, ohne Laufzeitumgebung und ohne Hintergrunddienst, in Sekunden und ohne Administratorrechte installiert.
- **Keine Hersteller-Software nötig**: spricht direkt mit den Geräten. G HUB, Synapse, iCUE, GG und NGenuity können geschlossen bleiben (oder weiterlaufen; sie kommen sich nicht in die Quere).
- **Viele Marken**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, PlayStation- und Xbox-Controller, Samsung Galaxy Buds, jedes Bluetooth-Gerät, für das Windows einen Akkustand kennt, sowie jedes Headset, das vom mitgelieferten [HeadsetControl](https://github.com/Sapd/HeadsetControl) unterstützt wird.

## Anzeige

**In der Taskleiste (Standard):** `🎧 30%  🖱 93%` neben dem Infobereich, gezeichnet mit der Windows-Symbolschriftart.
- **Akku schwach:** Eine rote Zahl steht für 15 % oder weniger.
- **Lädt:** Ein blauer ⚡ erscheint neben der Zahl. Sobald das Gerät vollständig geladen ist und noch am Strom hängt, wird daraus ein grünes ✓.
- **Im Ruhezustand:** Abgeblendeter Text bedeutet, dass sich das Gerät im Ruhezustand befindet und der zuletzt bekannte Wert angezeigt wird.
- **Getrennt (optional):** Aktiviere *Getrennte Geräte anzeigen*, um ein abgeblendetes `×` für Geräte anzuzeigen, deren Treiber ausdrücklich eine getrennte Funkverbindung meldet. Dies leitet keine Trennung aus einer fehlenden Akkuabfrage ab; standardmäßig bleiben Offline-Geräte ausgeblendet.
- **Zwei Geräte derselben Art:** Bei zwei Mäusen (oder zwei Controllern …) bekämen beide dasselbe Symbol; daher erhält jedes Gerät eine winzige Beschriftung mit bis zu 3 Buchstaben in der Ecke seines Symbols, abgeleitet aus seinem Namen (`MX`, `PRO`), oder eine Zahl, falls sich die Namen nicht unterscheiden lassen. Ein allein vorhandenes Gerät seiner Art zeigt keine Beschriftung.
- **Design:** Passt sich automatisch an Hell-/Dunkelmodus und DPI-Skalierung an.
- **Transparente Taskleisten-Designs** (z. B. Windhawk Taskbar Styler): Aktiviere *Hintergrund hinter dem Taskleistentext* im Menü, damit der Text über dem Hintergrundbild lesbar bleibt.
- **Mehrere Bildschirme:** Das Widget erscheint in der Taskleiste jedes Bildschirms neben der Uhr, sodass es auch während eines Vollbildspiels sichtbar bleibt. *Widget anzeigen auf* im Menü wählt *Alle Bildschirme*, *Nur Hauptbildschirm* oder einen einzelnen Bildschirm (z. B. nur *Bildschirm 3*).
- **Weitere Anzeigeoptionen:** *Symbole über den Prozentwerten* stapelt jedes Symbol über seinem Wert, um Breite zu sparen; *Markenfarben* zeigt bekannte Marken in ihrer jeweiligen Farbe (Razer-Grün, HyperX-Rot …) mit einem schmalen Füllstandsbalken; zwei Geräte desselben Typs erhalten eine winzige Beschriftung zur Unterscheidung; seitliche Taskleisten erhalten eine Gerätespalte.
- **Sprachen:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 und 繁體中文. Sowohl die Windows- als auch die Linux-App folgen der Systemanzeigesprache; über *Sprache* im Menü lässt sich eine andere wählen, und das Windows-Installationsprogramm unterstützt ebenfalls alle 19 Sprachen. Oberflächentexte liegen in bearbeitbaren statischen `lang/*.json`-Dateien und die vollständige übersetzte Dokumentation in [`docs/i18n/`](README.md). Siehe [Übersetzungen](#übersetzungen), um eine Sprache zu bearbeiten oder hinzuzufügen.
- **Markenfarben:** Geräte von 15 bekannten Marken erhalten die Farbe ihres Herstellers mit einem sanften Leuchten und einem dünnen Füllstandsbalken unter dem Prozentwert: Razer-Grün, Logitech-Blau, SteelSeries-Orange, Corsair-Gelb, HyperX / ROG / ZOWIE-Rot, PlayStation, Xbox, Samsung, Apple, Jabra, JBL, Cooler Master und Steam. Jede Farbe besitzt einen Farbton für dunkle und helle Taskleisten. Die Marke wird aus dem Treiber, der das Gerät gefunden hat, dann der Hersteller-ID und schließlich dem Namen ermittelt; Farben und Regeln befinden sich in `src/brands.cpp`. Im Menü über *Markenfarben* abschaltbar.

**Symbole im Infobereich:** Ein Symbol pro Gerät mit der eingezeichneten Prozentzahl sowie eine Benachrichtigung „Akku schwach“ bei 15 %. Die App wechselt automatisch dorthin, wenn die Taskleiste vertikal steht oder nicht gefunden wird.

**Eigene Gerätenamen:** Öffne das Geräte-Untermenü und wähle *Gerät umbenennen...*, um einen Namen festzulegen (bis zu 64 Zeichen). Der Name erscheint im Tooltip und in der Beschriftung des Taskleisten-Widgets, im Tooltip und in Benachrichtigungen des Infobereichs sowie im Gerätemenü. Mit *Auf ursprünglichen Namen zurücksetzen* stellst du den Treibernamen wieder her. Namen werden lokal in der Windows-Registrierung des aktuellen Benutzers (`Software\WirelessBattery`, `DeviceAliases`) unter dem stabilen Geräteschlüssel gespeichert. Das Umbenennen ändert niemals die Treiberzuordnung, Protokollabfragen oder die Diagnoseausgabe von `--list` / `--dump`. Es sind weder Konto noch Netzwerkzugriff nötig.

Fahre mit der Maus darüber für Details. Klicke für das Menü: jedes Gerät (anklicken zum Ein- oder Ausblenden), Anzeigemodus, *Jetzt aktualisieren*, *Mit Windows starten* und *Beenden*. Akkustände werden alle 60 Sekunden aktualisiert (*Akku prüfen alle* im Menü ändert dieses Intervall) sowie sofort beim Anschließen eines Geräts oder nach dem Aufwachen des PCs.

## Intelligente Akkuwarnungen (experimentell)

Du kannst für jedes Gerät über dessen Untermenü einen **individuellen Schwellenwert für die Akkuwarnung** festlegen: **Akkuwarnungen** → *Standard verwenden (15 %)*, *Benachrichtigungen deaktivieren* oder 5 %, 10 %, 15 %, 20 %, 25 %, 30 %, 35 %, 40 %. Der bestehende Standardwert von 15 % bleibt unverändert, sofern du keine Abweichung auswählst. Einstellungen werden nach Geräteschlüssel in der Windows-Registrierung des aktuellen Benutzers gespeichert (`Software\WirelessBattery`, `AlertThresholds`).

Eine Warnung wird nur durch einen echten, aktuellen Akkumesswert zwischen 0 und 100 % ausgelöst, wenn das Gerät verbunden, wach und nicht am Laden ist. Sie wird einmalig ausgegeben und erst wieder scharfgeschaltet, nachdem der Ladestand um mehr als 10 Prozentpunkte über den gewählten Schwellenwert gestiegen ist (oder wenn das Laden beginnt). Fehlende Messwerte oder schlafende Geräte lösen keine erneute Warnung aus. Ausgeblendete Geräte erzeugen keine Benachrichtigungen. Das Deaktivieren von Benachrichtigungen für ein Gerät blendet dieses weder aus noch verändert es dessen Prozentanzeige.

Sowohl der Taskleisten-Widget-Modus als auch der Infobereich-Modus unterstützen Benachrichtigungen. Da Windows für eine klassische Sprechblasen-Benachrichtigung ein Symbol im Infobereich benötigt, kann der Widget-Modus nach einer Warnung bis zu eine Minute lang ein vorübergehendes Infobereich-Symbol anzeigen. Die Widget-Farben und die Hervorhebung für schwachen Akku nutzen unabhängig von der Benachrichtigungseinstellung weiterhin den ursprünglichen globalen 15-%-Schwellenwert des Projekts.

## Akkuverlauf & Einblicke

Klicke im Taskleisten-Widget oder Infobereich-Menü mit der rechten Maustaste auf ein Gerät und wähle **Akkuverlauf...**. Der native, DPI-skalierte Betrachter (er folgt dem hellen/dunklen Windows-Design) zeigt aufgezeichnete Akkustände mit verbundenen Messwertlinien für die letzten **24 Stunden**, **7 Tage** oder **30 Tage** zusammen mit dem aktuellen Wert, dem niedrigsten/höchsten Stand, der Änderung in Prozentpunkten und der Anzahl der Messwerte. Du kannst den Verlauf des ausgewählten Geräts direkt im Betrachter löschen.

Der Verlauf wird **ausschließlich lokal** für verbundene, wache Geräte aufgezeichnet, die einen numerischen Prozentwert melden. Messwerte werden höchstens alle 30 Minuten pro Gerät gespeichert (außer bei Wechseln des Ladezustands, mit mindestens 60 Sekunden Abstand). Daten werden bis zu 30 Tage aufbewahrt und die lokale Datei bleibt unter etwa 2 MB. Die App fragt Hardware niemals über die bestehende Abfrage hinaus ab, sendet keine Verlaufsdaten über das Netzwerk und berechnet eine konservative, ungefähre Schätzung der Restlaufzeit ausschließlich aus jüngsten Entladungsbeobachtungen. Erforderlich sind mindestens vier Messpunkte, zwei Stunden, drei Prozentpunkte Rückgang, ein aktueller Messwert und ein stabiler Entladungsabschnitt. Laden, veraltete Messwerte oder unzureichende Daten unterdrücken die Schätzung; eine vom Gerät gemeldete Laufzeit ist nicht verfügbar. Die Schätzung ist keine Garantie. Fehlende Diagrammdaten werden als Lücken dargestellt und nicht interpoliert.

Deaktiviere **Akkuverlauf aufzeichnen** im Menü, um das Speichern neuer Messwerte zu stoppen; bereits gespeicherte Daten bleiben erhalten, bis du sie im Betrachter löschst. Die Datei liegt unter `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Die Gerätekennungen darin sind kodiert (nicht verschlüsselt); die Datei ist lokal auf dein Windows-Konto beschränkt. Mit `--demo` nutzt das Diagramm synthetische Daten, die niemals gespeichert werden. **Hinweis:** Die Aufzeichnung beginnt erst, nachdem diese Funktion installiert wurde und die App eine Weile gelaufen ist.

## Unterstützte Geräte

| Hersteller | Geräte | Verfahren |
|---|---|---|
| **NuPhy** | WH80 über USB-Kabel (`19F5:A011`) oder Bluetooth (`19F5:324A`), hardwaregetestet | USB: schreibgeschützte NuPhyIO-Akkuabfrage; Bluetooth: Windows-Akkustand mit Tastatur-Klassifizierung ([Protokollhinweise](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) über den `3654:6901`-USB-Empfänger (hardwaregetestet) | Schreibgeschützte CRC-geprüfte Akkuabfrage mit Ladeflag; grobe Messwerte in 10-%-Schritten beobachtet, feinere Auflösung nicht verifiziert ([Protokollhinweise](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX über den KP-8K-Empfänger (`1D57:FA65`; Modell `73` hardwaregetestet, Modell `74` ungetestet) | Passive Xenta-Statusberichte; zwei übereinstimmende Frames bestätigen den Stand ([Protokollhinweise](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, getestet), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` getestet, `002D`/`002A`), A50 Gen 3 (`9886:0015` getestet, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), über USB-Basisstation | Akkuprozentwert, Lade- und Dock-Status |
| **Logitech** | Mäuse und Tastaturen an Unifying-, Bolt-, Lightspeed- (einschließlich PRO X3 SUPERSTRIKE Dongle `046D:C54F`) und Nano-Empfängern, per USB oder Bluetooth; G-Headsets (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 am neueren `046D:0ADF`-Dongle | HID++ 1.0 / 2.0 mit Feature-Erkennung: Unified Battery, Battery Level, Voltage, ADC; G435: CRC-16-gerahmte Herstellerberichte, `GET_BATTERY` in mV |
| **Razer** | Kabellose Mäuse, Tastaturen und Dongles; Headsets BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X, V3 Pro for Xbox (`1532:0A55`-Empfänger, `0A4E`-Kabel); Barracuda X (2022) über 2,4-GHz-Empfänger (`1532:0550` oder `1532:0552`); Barracuda Pro (`1532:053A`) | Razer-Feature-Report-Protokoll; BlackShark-Herstellerprotokolle (V3 / V3 Pro / V3 X werden alle 5 Min. abgefragt); Barracuda X: Airoha-Akku- und Kabelabfragen über den Empfänger |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (einschließlich `1038:225D`), Arctis Nova Elite (Basisstation `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, ungetestet), Aerox 3 Wireless CS2 Dragon Lore Edition (Empfänger `1038:1878`, Kabel `187A`), Aerox 3 Wireless Gen 2 (Empfänger `1038:1890`, Kabel `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Hersteller-HID-Berichte; Aerox/Prime und Rival 650 teilen sich einen Eintrag für Empfänger und USB-Kabel und bevorzugen bei gleichzeitiger Antwort den Kabelmesswert |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 Wireless; Bragi-Geräte (Virtuoso, Void V2, HS80 MAX, Slipstream-Mäuse und -Tastaturen, einschließlich neuerem Slipstream-Empfänger `1B1C:2B00`, z. B. Scimitar Elite SE Wireless und Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, ungetestet) | Hersteller-HID-Berichte, Bragi `GET` (schreibgeschützt), 17-Byte-Compx-Akkuprotokoll (schreibgeschützt) |
| **Cooler Master** | MM712, MM731 (2,4-GHz-Empfänger oder USB-Kabel) | Hersteller-HID-Statusbericht (schreibgeschützt) |
| **Press Play** | ICARUS V2 Nearlink am 2,4-GHz-Empfänger `7768:6434` (Treiber auf Hardware bei 90 % getestet; Protokoll bei 100 % und 90 % mitgeschnitten) | Schreibgeschützter Output-Report `06 05` auf `FFB2:0001`; Akkuprozentwert in Antwortbyte 14 |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` für PS, ungetestet), Cloud Flight S, Cloud Stinger Core Wireless (einschließlich DTS `03F0:0A8E`, getestet), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (2,4-GHz-Empfänger), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (2,4-GHz-Empfänger) (2,4-GHz-Empfänger `03F0:0F98`, getestet; `0D97` ungetestet) | Hersteller-HID-Berichte (Haste 2: [Protokollhinweise](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Hersteller-Feature-Report |
| **Hitscan** | Hyperlight X, Hyperlight N | Hersteller-Feature-Report (gleiches Protokoll wie Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, kabellose Pulsar- und ATK-VXE-Mäuse (z. B. VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (Empfänger `3554:F512`) | Gemeinsames Herstellerprotokoll mit Prüfsummen-Antworten |
| **Pulsar X2 V3** | X2 V3 am 1K-Dongle (`3710:5402`) oder USB-Kabel (`3710:3402`); X2 V3 eS am 8K-Dongle (`3710:5403`) oder USB-Kabel (`3710:3406`) | 64-Byte-Hersteller-Feature-Report, Akkuregister `08 81 01` (schreibgeschützt) |
| **ATK / VXE NK** | VXE R1 NK und andere NearLink-Mäuse am NK-Maus-NANO-Dongle (`373B:1216`) | ATK-BITMOUSE-Output-Report 08 auf `FF05:0001` (Akku und Ladestatus) |
| **ATK 8K Nano** | ATK- / VXE-Mäuse am ATK 8K Nano Dongle (`373B:1178`) | Holtek-Feature-Report `GetConfigData` (`82`) auf `FF10:0001` (aus ATK HUB; Akku und Ladestatus) |
| **ATK-Headsets** | ATK N9 Pro, N9 Ultra (erste Generation) | Virtuelles-COM-Port-Protokoll (die ATK-Desktop-App muss geschlossen sein) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK und deren 8K-Dongles | Glorious- oder Kysona-Protokoll, je nach Modell |
| **Keychron-Mäuse** | M4 und andere Keychron-Mäuse am 2,4-GHz-Empfänger; 4K-Mäuse (M4 4K, M3 4K, M3 mini 4K, M6 4K …) am Keychron-4K-Link-Empfänger (`3434:D038`); 8K-Mäuse (M5 8K, G6 HE 8K …) am TurboLink-8K-Empfänger; 8K-Mäuse am Ultra-Link-8K-Empfänger (`3434:D028`); ältere Mäuse (M1, M2, M3, M3 mini, M6, M7 …) am 1K-Empfänger (`3434:D030` / `D031`); Nape Pro Trackball am Link-KM-Empfänger oder Kabel | Herstellerbericht aus Keychron Launcher (1K-Empfänger: Feature-Report 51 06 wie in der Keychron-Desktop-App; Ultra-Link 8K: Berichte B5 03 / B3 06 auf `FFC1`; Nape Pro: Raw-HID A7 31) |
| **Keychron-Tastaturen** | K5 Max (`3434:0A50`, getestet) am Keychron-Link-Empfänger (`3434:D030`) oder USB-Kabel; andere kabellose Keychron-QMK-Tastaturen nach Kompilierung mit demselben Patch | Raw-HID auf `FF60:0061`: `B2` fragt den Empfänger nach der verbundenen Tastatur, `A4` liefert Stand, Spannung und Ladestatus. **Erfordert gepatchte Tastatur-Firmware:** siehe [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). Die Original-Firmware meldet nur über Bluetooth |
| **CHERRY** | Kabellose Tastatur MX 3.0S am 2,4-GHz-Dongle (`046A:00EA`, getestet) oder USB-Kabel (`046A:00E3`, getestet) | Hersteller-HID-Abfrage `1A` auf `FF1C:0092` (schreibgeschützt), mit USB-Netzbetriebsstatus. Bluetooth wird über die Bluetooth-Unterstützung abgedeckt |
| **CHERRY** | Kabellose Cherry-XTRFY-Maus am 1K-Empfänger (`046A:0330`, getestet) | 17-Byte-CompX-Akkuprotokoll (`08 03` Verbindungsstatus, `08 04` GetPower), gleiches Framing wie bei Corsair Sabre V2 Pro (schreibgeschützt) |
| **Arbiter Studio** | Akitsu (`373E:000A` 8K-Empfänger, `373E:0009` Kabel), Akitsu 3950 (`373E:0039` 8K-Empfänger, `373E:0038` Kabel), Akitsu Medium (`373E:0067` 8K-Empfänger und `373E:0066` Kabel, beide getestet) | Schreibgeschützter Hersteller-Feature-Report `0x83` auf `FFFF:0000` aus Arbiter Web HUB (Akku und Ladestatus) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (Kabel, 1K- und 4K/8K-Dongles) | Hersteller-Feature-Report aus LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) am 4K-Dongle; XM2we am Original-Empfänger (`3367:1961`) | Hersteller-Feature-Report `A1`, Akkubefehl `B4` (schreibgeschützt) |
| **ATK / VGN / Evision-Tastaturen** | ATK V75X sowie VGN- / VXE-Tastaturen (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) am gemeinsamen 2,4-GHz-Empfänger (`320F:5088`) oder USB-Kabel (`320F:5055`), erkannt anhand des Produktnamens; Tastaturen, deren `320F:5088`-Empfänger „Wireless Gaming Keyboard“ heißt, z. B. Feker Alice80 (getestet) | Evision-Output-Report `04`, Akkubefehl `1A` (aus ATK HUB und VGN HUB); wird über den Empfänger höchstens alle 10 Minuten abgefragt |
| **Redragon (Evision)** | K1NG M999 (getestet) am 2,4-GHz-Empfänger `320F:226F`; die Empfänger-ID kann von weiteren Modellen geteilt werden | Gleiches Evision-Protokoll wie bei den ATK-Tastaturen (Report `04`, Befehl `1A` auf `FF1C:0092`), bei jeder Aktualisierung abgefragt; Laden wird auf dem Magnet-Dock angezeigt; bei angeschlossenem USB-Kabel wiederholt der Empfänger den alten Wert ohne Ladestatus |
| **Audeze** | Maxwell am USB-Dongle (`3329:4B19`) oder USB-C-Kabel (`3329:4B1A`); Maxwell 2 am USB-Dongle (`3329:4B29`, getestet); Xbox-IDs ungetestet | Herstellerreport `06` / Input-Report `07`, Akku-Attribut `0CD6` (einzelne schreibgeschützte Abfrage) |
| **ENDORFY** | Viro Wireless am 2,4-GHz-Dongle (`3738:0072`, ungetestet) | Airoha RACE „get battery“ (`0CD6`) über Herstellerreport `06` / Input-Report `07`, gleiche schreibgeschützte Abfrage wie bei Audeze- und Skullcandy-Dongles; kein Ladestatus |
| **Turtle Beach** | Stealth 700 Gen 3 am USB-Sender (`10F5:2251`, in HaloBattery getestet; PC-Version `10F5:2262`, ungetestet) oder am eigenen USB-Kabel des Headsets (`10F5:2253`) | RACE `0x9942` (aktiviert den CoAP-Client) und ein in RACE `0x9902` getunneltes CoAP `GET /GSI`, wie in Swarm II; Akku aus Schlüssel `240` (kein Ladeflag) |
| **AKG** | N9 Hybrid am USB-Dongle (`0ECB:20D9`, getestet) | Airoha RACE auf `FF13:0001`: Output-Report `06`, Input-Report `07`, Akku-Attribut `0CD6` (einzelne schreibgeschützte Abfrage) |
| **NZXT** | Lift Elite Wireless am Dongle (`1E71:2101`) oder USB-Kabel (`1E71:2129`) | Hersteller-Leseabfrage `4E 02 81 .. B0` (aus NZXT-CAM-Mitschnitten) |
| **Poly / Plantronics** | Voyager 8200 UC und andere Headsets hinter dem BT600-Adapter (`047F:02EE` / `02F7`) | Report-`07`-Get/Set-Protokoll, Akkuelement `0A 1A` (schreibgeschützt) |
| **WLMouse** | YING Magnesium (YING 8K-Empfänger `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (Empfänger oder Kabel; nicht Beast X 4K); Beast X V2 (8K-Empfänger `36A7:A856`); Beast G (8K-Empfänger `36A7:A860` oder Kabel `36A7:A861`; ungetestet) | Hersteller-Feature-Report, Statusbefehl `0x83` (YING: gleiches Protokoll wie Glorious) |
| **Finalmouse** | UltralightX am 2,4-GHz-Dongle (`361D:0100`, getestet); Starlight X am Dongle (`361D:0300` / `0301`, getestet). Nicht über das eigene Kabel der Maus | xpanel-Herstellerberichte auf `FF00`: schreibgeschützte GETs, dann *wake/all* (`0xE0`); Akkuspannung anhand der xpanel-Kurve bzw. eigener Prozentwert der Starlight X plus Ladestatus |
| **VAXEE** | Kabellose Maus am VAXEE-4K-Empfänger (`3057:1002`) oder 8K-Empfänger (`3057:2002`, z. B. NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless über USB-Kabel (`3057:1011`) | Schreibgeschützter Hersteller-Feature-Report `0E` auf `FF05:0001`; Akku in 5-%-Schritten, Ladestatus ([Protokollhinweise](#sec-vaxee)) |
| **Scyrox** | V12M am 2,4-GHz-Empfänger (`395A:0006`) | S-Center-2.0-Profilabfrage (Output-Report `08`, Befehl `01`) auf `FF00:0002`; nur Akkustand, kein Ladestatus |
| **HECATE** | G5M PRO und weitere HECATE-Mäuse am selben Empfänger sowie USB-Kabel `35BB:D3FA / D3FC / D3FD` | Kysona-Protokoll |
| **Redragon** | Compx-basierte Funkmäuse: M916 Pro 1K (getestet), M913 Impact Elite (Tri-Mode), G49 (Empfänger oder Kabel) | Kysona-Protokoll (die Areson-`25A7`-Empfänger sind unter Areson aufgeführt) |
| **Taidu (钛度)** | TSG808 am Compx-2,4-GHz-Empfänger `3554:F5D5` (getestet) | Kysona-Protokoll |
| **Areson (Redragon)** | M915RGB-WL (getestet), ursprüngliche M913 Impact Elite und andere Mäuse am `25A7:FA07` / `FA08`-Empfänger | 17-Byte-`GetPower`-Feature-Report; Stand in 10-%-Schritten und Ladeflag |
| **Ninjutso** | Sora V2 am 1K-Empfänger (`1915:AE1C`, getestet) oder USB-Kabel (`1915:AE11`, getestet); Ten Air (Empfänger `093A:EB01` und USB-Kabel `093A:E020`, getestet) / Ten (`093A:EB01` / `E020`, ungetestet) | NinjaForce-Feature-Report `0x05` (`0x15` für Sora V2) und `0x06` (`0x13`/`0x12`/`0x11` für Ten / Ten Air) |
| **Sprime** | PM1 am 2,4-GHz-Empfänger (`1915:AC1C`, getestet; `1915:AD8C`) oder USB-Kabel | Gleicher Feature-Report `0x05`, Statusbefehl `0x15`, aus Sprimes Web-Treiber (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 am RAWM HS Receiver (`1915:2346`, getestet); ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* und SADES Dagger Mäuse an ihren RAWM-Empfängern (`1915:232A`–`234B`) oder USB-Kabel | RAWM-HUB-2.0-Geräteinfoabfrage über den Empfänger (JSON mit Akku-% und Ladestatus), schreibgeschützt ([Protokollhinweise](#sec-rawm)) |
| **AULA** | Kabellose Tastaturen F75 / F87 Pro / F99 am 2,4-GHz-Empfänger | Report-0x13-Frame, Befehl 0x4A, Summenprüfsumme (Bluetooth- und Kabelmodus ungetestet) |
| **AULA-Mäuse** | X9 Ultra (getestet) am AULA-8K-Dongle `320F:22A0`; Empfänger-ID wird mit V9-Modellen geteilt | Report `04`, schreibgeschützter Akkubefehl `1A` zwischen START `01` / END `02` auf `FF1C:0092`; nur 2,4 GHz |
| **SONiX-Tastaturen (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (getestet), EPOMAKER EA75 (getestet), AULA F108 Pro am 2,4G-Dongle `05AC:024F`; AJAZZ AK980 V2 am Dongle `0C45:FEFE`; AJAZZ AK820 Pro am Dongle `0C45:FDFD` oder `0C45:FEFE`; EPOMAKER P75 an `342D:E479` (Hardware ungetestet) | Herstellerreport `20 01` auf Usage Page `FF60`, Summenprüfsumme (nur 2,4G-Modus; keine Ladeanzeige) |
| **Weitere SONiX-Empfänger (Hardware ungetestet)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | Gleiche reine Akkuabfrage `20 01`; exakte VID:PID und `FF60:0061`-Sammlung mit 33-Byte-Berichten erforderlich; nur 2,4G, keine Ladeanzeige |
| **36B0-Tastaturen (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB am 2,4G-Dongle `36B0:3002` oder USB-Kabel `36B0:3009` (Protokoll vom Melder in #343 auf beiden getestet); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) am selben Dongle oder Kabel (ungetestet); URX Core75 am Dongle (in HaloBattery bestätigt); EVO80 (ungetestet) | PMO-Hub-Firmware: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` auf Usage Page `FF60`, aus pmohub.cn. URX- / VIA-Firmware: VIA custom-get `08 00 07` (Kanal 0, Wert 7), aus URX HUB über HaloBattery. Keine Ladeanzeige |
| **DAREU** | EM901X am 2,4-GHz-Empfänger `260D:1074` oder USB-Kabel `260D:1090` (Akkumessung auf beiden getestet; Wechsel des Ladeflags beim Aufsetzen/Abnehmen vom Dock am Empfänger getestet) | Reiner Akku-Feature-Report `08`, Befehl `04`; Antwort `09` auf einer separaten Herstellersammlung. Erfordert genau ein eindeutiges Input-/Feature-Paar pro Produkt-ID. Bevorzugt einen gültigen USB-Messwert, wenn beide verbunden sind; der Empfänger kann zwischengespeicherte Telemetrie auch bei ausgeschalteter Maus zurückgeben |
| **DAREU** | A84-Tastatur (`260D:0022`, ungetestet) | SONiX-Feature-Report auf Schnittstelle 0, Befehl `04 F6` (Akkuabfrage des offiziellen A84-Treibers); Stand in Prozent, kein Ladeflag |
| **DAREU** | A980 Pro am Multi-Maus-Empfänger `260D:1131` und am USB-Kabel `260D:1148` (Akkustand auf Hardware getestet; Ladeflag im eingesteckten Zustand bestätigt) | Togran-Protokoll: 65-Byte-Feature-Report `0A` auf der Consumer-Control-Sammlung; Slot-Abfrage (Klasse 0 / `A0`), dann Akkuabfrage (Klasse 7 / `80`), über Kabel auf Slot 0. Schreibgeschützt |
| **Sharkoon** | Skiller SGM50W an `260D:1125` (ungetestet) | Gleiche Compx-Abfrage wie DAREU EM901X (Feature-Report `08`, Befehl `04`; Antwort `09` auf `FF01:0000`); Sharkoons Firmware-Updater dafür ist ein Compx-Tool auf VID `260D` |
| **Zenith** | Zenith Pro am 2,4-GHz-Empfänger `260D:1114` (Akkumessung getestet; Laden ungetestet) oder USB-Kabel `260D:1143` (ungetestet) | Gleicher Compx-Befehl (`08`, `04`) als Output-Report auf `FF02:0002`; Antwort `08 04` auf derselben Sammlung mit Prozentwert, Ladeflag und Millivolt, geprüft durch die `0x55`-Bytesumme |
| **AJAZZ AK992** | Telink-2,4-GHz-Empfänger `320F:50C3` (getestet) | EVision-Akkuabfrage auf HID-Sammlung `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, DW-Serie (U2-DW, S2-DW …) und U2 am 2,4-GHz-Empfänger | Von der Community dokumentierte schreibgeschützte Herstellerbefehle |
| **Royal Kludge (RK)** | MG6 Pro am 2,4-GHz-Dongle (`2E3C:00A6` / `00E6`) oder USB-Kabel (`2E3C:00A5` / `00E5`) | QiWang-64-Byte-Frame aus RKs Web-Treiber, `GET_BATTER_VOL`-Leseabfrage (Prozent, Spannung, Ladestatus) |
| **ASUS ROG** | Tastaturen Strix Scope II 96 (RX), Azoth, Falchion; Mäuse Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact; Pelta-Headset (2,4-GHz-Dongle); Cetra Open Wireless Ohrhörer (SpeedNova-Dongle `0B05:1CAC`, L / R / Ladecase); der Omni Receiver | ROG-HID-Akkuabfrage |
| **Machenike** | L7 Arctic / L7 Mix am 2,4-GHz-Empfänger `248A:FF4C` oder USB-Kabel `248A:FF4E` (beide getestet) | Schreibgeschützter Feature-Report `51`, Statusbefehl `06`; Akku und Ladestatus. [Protokollhinweise](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS am 2,4-GHz-Dongle (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (2,4-GHz-Empfänger `0DB0:0D3C`, getestet; USB-Kabel `0DB0:0D3B`) und CLUTCH GM41 Lightweight Wireless (Empfänger `0DB0:0D4C` / Kabel `0DB0:0D4B`, aus Mitschnitten eines Besitzers) | Schreibgeschützte Herstellerabfrage `0F 20` auf `FF0D:00B0` und `FF00:0001`; Akku und Ladeflag in einem Byte (Protokoll aus dem Gaming-Gear-Modul von MSI Center); GM41: passive `A0 xx 07 …`-Berichte auf `FF10:0006` |
| **MCHOSE** | Mäuse L7 / L7 Pro / L7 Ultra (L7 Ultra getestet), M7 / M7 Ultra, A7 / A7 Ultra, K7 am 2,4-GHz-Empfänger oder USB-Kabel; A5 V2 Ultra (2,4-GHz-Empfänger `3837:100C`, getestet), K7 Ultra (2,4-GHz-Empfänger `3837:1001`, getestet; A7 V2 Ultra+ `3837:100B` sollte funktionieren, Issue 227); G3 V2 (2,4-GHz-Empfänger `3837:4245` und USB-Kabel `3837:418C`); K7 V2 Ultra+ am 2,4-GHz-Empfänger `3837:1014` oder am USB-Kabel `3837:4028` (beide getestet; die anderen Empfänger-IDs der neuen Familie `1018`, `1016`, `102C`, `102D` sind ungetestet) | Hersteller-Feature-Report, invertierte Nutzlast (Protokoll von alexfrih/mchose-linux); Realtek-`3837`-Dongles beantworten dieselbe Abfrage mit VID-Feld `41E4` (A5 V2 Ultra) oder `3837` (K7 Ultra); G3 V2: schreibgeschützte Herstellerabfrage auf `FF01:0010`; K7 V2 Ultra+: 64-Byte-Report `0x4D`, Geräteinfobefehl `0x0900` auf `FF01:0001` (Protokoll aus dem Web-Treiber von M HUB) |
| **MCHOSE A5 (erste Generation)** | A5 Pro / A5 Pro Max am 1K- oder 4K-2,4-GHz-Empfänger (`2023:F013`, `2023:F015`, `2023:F018`) oder am USB-Kabel (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); hier ungetestet | Schreibgeschützter Akkubefehl `0x83` (Seite 0) in einem 64-Byte-Feature-Report auf `FFFF`, Antwort markiert mit `0xA1` (Protokoll aus dem z750sasr A5 Pro Max Web-Treiber und HaloBattery, IDs aus Klegus/mchose-macos) |
| **MCHOSE-Headsets** | V9 Pro 2 am 2,4-GHz-Dongle (`3837:6011`, getestet) | Schreibgeschützter „MC“-Akkuframe aus M HUB (Report `0x55`, Unterbefehl `0x0B`) auf `FF07:0222`; Akku und Ladeflag in einem Byte (Protokoll aus dem Web-Treiber von M HUB) |
| **AULA / MCHOSE / Redragon-Tastaturen** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 und die weiteren M-HUB-Tastaturen; Redragon Horus Pro / Pro V2 (K618RGB-PRO) am 2,4-GHz-Empfänger (`3554:FA09`, `41E4:2001`); MCHOSE K87 am Empfänger `05AC:024F` (BY-Layout auf Schnittstelle 1, nicht das SONiX-Protokoll) | Report-0x13-Frame, Befehl 0x4A (MCHOSE- und Redragon-Modelle durch Befehl 0x05 identifiziert, wie in M HUB); Bluetooth- und Kabelmodus nicht abgedeckt |
| **MCHOSE-Tastaturen** | G75 V2 am 2,4-GHz-Empfänger `3837:3033` (getestet); derselbe Empfänger wird auch mit G87 V2 und K99 V3 ausgeliefert (gleiches Protokoll, ungetestet); die K87S nutzt bei derselben Empfänger-ID ein anderes Protokoll und wird nicht abgedeckt | Schreibgeschützte „GLW“-Func-Config-Abfrage aus M HUB auf der ID-losen 64-Byte-Sammlung `0001:0000`: Anfrageflag `0x55`, Befehl `0x05`, Akku in Nutzlast-Byte 32 (Bit 7 = lädt), additive Prüfsumme |
| **AULA SC580** | SC580- / SC580X-Maus über USB-Kabel (`088D:062E`, getestet) oder 2,4-GHz-Empfänger (`089D:062F`, getestet) | Schreibgeschützter Befehl `0x30` (Geräteinfo) auf der 33-Byte-Herstellersammlung `FF02:0000`, Summenprüfsumme; während des Ladens meldet die Maus feste 100, daher wird der letzte Stand angezeigt; Bluetooth-Modus nicht abgedeckt |
| **AULA HERO 68 Air** | HERO 68 Air am 8K Wireless Receiver (`372E:106C`) | Bestätigte 20-Byte-Frames auf Usage Page `FF60` (vier Datenframes und ein Trailer pro Nachricht), schreibgeschützter Akkubefehl `0x87`, Ladeflag `0x10` nach dem Stand; Bluetooth- und Kabelmodus nicht abgedeckt |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra und S9 Max / Pro / Ultra / Ultra+ am Empfänger „Gaming 2.4G“ (`372E:103D`); S9 Ultra am USB-Kabel (`372E:1027`) | Schreibgeschützter Feature-Report `03` auf `FF00:0001`: Verbindungsprüfung `47`, Gerätebasisdaten `4F 81` (Akkuprozent und Ladebit), aus dem Web-Treiber von EWEADN |
| **Rapoo VT** | VT3 Max Gen 2 (getestet); VT9 Gen 2 (getestet); andere Nordic-54L-VT-Mäuse mit derselben Statusschnittstelle; ältere VT3 Pro (experimentell); VT1 Pro Max (aus USB-Mitschnitten des Besitzers) | Passiver HID-Statusbericht `07` auf `FF00:0002` (16 oder 19 Bytes; 13 Bytes bei manchen VT3-Max-Gen-2-Empfängern); älteres `BB` auf VT3 Pro `1215/4415` und VT1 Pro Max `1233/4433` beschränkt. Empfänger und USB-Kabel, mit Ladestatus |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (Xenta-Modelle 30/50; Legacy 3D), Delux M800 Pro, Ajazz AJ179-Familie; AJ159 und andere AJ-Mäuse am 3151-Empfänger; AJ139 V2 MC (`A8A5:2255` Empfänger, `A8A4:2255` Kabel) | Herstellerberichte (M900 Pro: passive Status-Broadcasts oder Feature-Abfrage, Xenta-Ereignisse 40/41; AJ-Serie: Statusabfrage `0xF7`, dann Feature-Report `0x05`) |
| **Incott** | G23 V2 / G24 (`093A:522C` Empfänger, `093A:622C` Kabel) | Schreibgeschützter Status-Feature-Report 09 |
| **Attack Shark und weitere chinesische Marken** | Rongyuan-Empfänger (81 Modelle: Attack Shark R3 und AJAZZ AJ179 Pro an `3151:402D`, K86, X82 PRO HE, Ajazz-Tastaturen, einige MSI u. a.; die K86 über Bluetooth wird als Tastatur angezeigt); Xenta-Empfänger (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; X6 auch an `1D57:FA61`, ungetestet); Semico-1A2C-Tastaturen (Attack Shark X98 am Dongle `1A2C:8FFF`, getestet, und Kabel `1A2C:A034`; AJAZZ AK820 Max Plus an `1A2C:8FFF` / `1A2C:A036`) | Rongyuan-Statusbericht; passive Xenta-Broadcasts; schreibgeschützte Semico-`0x0E`-Statusabfrage (`AA 55 CC 33` auf `FF02:0002`; Ladeflag weggelassen, da die X98 sowohl im Akkubetrieb als auch beim Laden `state=1` meldet) |
| **Wraith** | W1 / W1 Freestyle (`093A:522C` Empfänger, `093A:622C` Kabel; gleiche IDs wie Incott, unterschieden durch den Modellcode) | Schreibgeschützte Tasten-Einzelabfragen `86` (Feature-Report 09) über alle Tasten, anschließend der gesendete Status-Input-Report 09 |
| **Fantech** | Helios Go XD5 (Kabel `25A7:FA7B`, Dongle `25A7:FA7C`); Raigor III (getestet), Raigor II WG10 und andere generische „2.4G Mouse“-Geräte am wiederverwendeten Dongle `1EA7:0066` / `1EA7:0064` | Helios Go XD5: Hersteller-Feature-Report `08`, Befehl `04`, Prüfsumme auf `0x55`. Raigor / 2.4G Mouse: schreibgeschützte `B5`-Statusseiten-Abfrage auf `FFB5:0001`, Block `94` = zuletzt gemeldeter Prozentwert (kann im Ruhezustand, ausgeschaltet oder beim Laden veraltet sein; kein Ladestatus) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, Wireless-Adapter); Headsets INZONE H9 II und H5; INZONE Buds (USB-C-Dongle) | Input-Report; INZONE-Herstellerprotokoll |
| **Fractal Design** | Scape-Headset am 2,4-GHz-Dongle oder USB-C-Kabel | Herstellerabfrage `GET_DEVICE_STATE` aus Fractals Adjust-Pro-Web-App (Usage Page `FF00`) |
| **Jabra** | Jedes Jabra-Headset mit GN-Protokoll (Evolve2 / Evolve3 u. a.), am eigenen USB-Kabel oder hinter einem Jabra-Link-Dongle; keine Produkt-ID-Liste, DECT-Basen (Engage, PRO 9xx, GO 6400, Link 400) ausgenommen; Name wird direkt vom Headset gelesen | GNP-Statusabfrage (Klasse 12 / Op 02) auf Usage Page `FF00`, Usage `05` oder `01`, an GNP-Adresse `08` (USB) oder `04` (Dongle) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), 2,4-GHz-Empfänger oder USB; Apex 5 (`37D7:2501`), 2,4-GHz-Empfänger oder USB | Hersteller-HID-Infoabfrage auf `FFA0:0001`; Akkustufe 0–5 umgerechnet auf 0–100 % in 20-%-Schritten, mit Ladestatus; kein Space-Station-Dienst erforderlich |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite am 2,4-GHz-Empfänger; Nova 2 Lite über USB; G7 Pro (getestet: Zenless-Zone-Zero-Edition, Empfänger `3537:105E`) und andere GameSir-Controller im Xbox-(GIP-)Modus; Cyclone 2 (XInput-Modus, Empfänger oder Kabel); Cyclone Pro am 2,4-GHz-Dongle (`3537:1015`, Controller einmalig per Bluetooth mit Windows koppeln) | Hersteller-Geräteinfoabfrage (Usage Page `FF7A`); Windows.Gaming.Input-Akkubericht (echte %) im Xbox-Modus; Cyclone 2: Hersteller-Akkuanfrage (Usage Page `FFF0`); Cyclone Pro: GameSir-App-Basisinfoabfrage über Bluetooth LE (Dienst `0x8650`), alle 2 Min. gelesen |
| **BEITONG** | KP20 / BTP-KP20 am 2,4-GHz-Empfänger (`20BC:5128`, XInput-Modus, getestet) und KP40D / BTP-KP40D am Empfänger (`20BC:515C`, XInput-Modus); BEITONG iControl nicht erforderlich | Herstellerabfrage „get base info“ auf Usage Page `00FF` (Report `02`, Nibble-verwürfelte Nutzlast), mit Ladestatus |
| **8BitDo** | Ultimate 2 Wireless (X-Input `2DC8:310B` am 2,4-GHz-Dongle getestet, D-Input `2DC8:6012` — B beim Einschalten gedrückt halten, Firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Hersteller-HID-Statusabfrage (`FF7A`/`FFA0`) und SDL-Gamepad-Input-Report `01`/`04`, mit Ladestatus |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Statusframe, den die Ohrhörer über Samsungs RFCOMM-(SPP-)Dienst senden, schreibgeschützt. Der Infobereich zeigt den niedrigeren Ohrhörer; der Tooltip listet links, rechts und Ladecase auf. Die Galaxy-Buds-App muss geschlossen sein |
| **Nothing / CMF** | Nothing Ear (3a) (getestet), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Schreibgeschützte `0xC007`-Akkuabfrage über Nothings NT-Link-RFCOMM-Dienst (`aeac4a03-dff5-498f-843a-34487cf133eb`). Der Infobereich zeigt den niedrigeren Ohrhörer; der Tooltip listet links, rechts und Ladecase auf |
| **Akko** | Akko Air 01 (`3151:5006`, 2,4-GHz-Empfänger, getestet) und Akko V9 Dash Pro (`38EE:000C`, 2,4-GHz-Empfänger, getestet) | Air 01: Rongyuan-`0xF7`-Statusbericht; V9 Dash Pro: schreibgeschützte 64-Byte-`0x1A`-Statusabfrage auf `FF1C:0092` mit Ladestatus |
| **MOONDROP** | GM01 Pro Headset am 2,4-GHz-Dongle (`35D8:0133`); am USB-Kabel wird es als ladend mit dem letzten Stand angezeigt | WalkPlay-Hersteller-Lesebefehl auf Report `4B` (schreibgeschützt) |
| **VGN** | OMNISOUND-(ZHOUTING-)Headset am 2,4-GHz-Dongle (`372E:10BB`, getestet) | V-HUB-„ZHOU“-Abfrage: Output-Report `55` mit Nutzlast `65 01` auf der Steuerungssammlung `000C:0001` (32-Byte-Input-, 64-Byte-Output-Berichte); der Prozentwert kommt in der Antwort zurück (schreibgeschützt) |
| **JBL** | Quantum 650 Wireless (getestet, 2,4-GHz-Dongle); Quantum 520, 650X, 850, 950, 950X Wireless (Dongle oder USB-Kabel, gleiches Protokoll, ungetestet) | JBL-„HIDV3“-Geräteinfoabfrage für die Akkufunktion (Usage Page `FF12`), mit Ladestatus |
| **JBL** | Quantum 350 Wireless (unter Windows mit 2,4-GHz-Empfänger `0ECB:206B` getestet); Quantum 610 Wireless (2,4-GHz-Dongle `0ECB:205C`, unter Windows ungetestet); Quantum 360 Wireless (2,4-GHz-Dongle `0ECB:2115`, ungetestet) | HIDV1-Feature-Reports für Funkverbindung und Akkuprozentwert |
| **Xbox** | Controller am Xbox Wireless Adapter, per USB oder Bluetooth; an einen Controller angeschlossene Headsets | Windows.Gaming.Input-Akkubericht (echte %), XInput-Fallback |
| **Switch-Pro-kompatibel** | Controller, die sich als `057E:2009` melden (getestet: GameSir Tarantula Pro über den 2,4-GHz-Empfänger im Switch-Modus) | Fünf Akkustufen aus HID-Report `0x30`, nachdem Steam Input oder ein anderer Host vollständige Berichte aktiviert hat |
| **Apple AirPods / Beats** | AirPods Max (getestet, `200A` Lightning und `201F` USB-C), AirPods Pro 3 (getestet, `2027`), AirPods Pro 1 / 2, AirPods 1–5 und Beats Kopfhörer/Ohrhörer | BLE-„Proximity-Pairing“-Broadcasts (`0x07`) (einzelner Akkustand für AirPods Max und Beats-Kopfhörer; links, rechts und Ladecase für Ohrhörer, in 10-%-Schritten mit Ladestatus), zugeordnet zum gekoppelten Modell |
| **Smartphones (Smartphone-Link)** | Jedes Android-Smartphone, das per WLAN oder Bluetooth mit Microsoft Smartphone-Link gekoppelt ist (getestet: Nothing Phone (4a) Pro) | Akkustand und Ladestatus aus der Windows-11-Startmenü-Karte von Smartphone-Link (`StartMenuCompanion.json`); kein Bluetooth erforderlich |
| **Darmoshark** | M3 (`248A:FF30`) und M3S (`248A:FF31`) an ihren 2,4-GHz-Empfängern unter Windows | HID-Feature-Report für Maus-Identität und Akku |
| **Darmoshark** | M3S Pro am Nordic-1K-Empfänger (`1915:0723`) | Hersteller-HID-Statusabfrage auf der `FF0A`-Sammlung |
| **Alienware** | AW920H-Headset am 2,4-GHz-Dongle (`413C:A515`, getestet); über Bluetooth übernimmt die Bluetooth-Zeile | Herstellerabfrage `06 C0 0A` auf `FF13:0001`, Antwort-Report `07` mit XOR-Prüfsumme; Stand, Ladestatus und Kritisch-Feld wie vom AW920H-Plugin des Alienware Command Center dekodiert |
| **Niceboy** | MW400 am 2,4-GHz-Empfänger (`248A:FA02`, getestet) | Schreibgeschützter Report `05` mit Abfrage `24 FA 48`; Akkuspannung anhand der Tabelle der Hersteller-App auf 10-%-Schritte abgebildet, Ladeflag |
| **Bluetooth** | Alles, was unter *Einstellungen → Bluetooth und Geräte* einen Akku anzeigt (Ohrhörer, Kopfhörer, BLE-Mäuse und -Tastaturen). Google-Fast-Pair-Ohrhörer (Jabra Elite 8 Active getestet; Pixel Buds und viele Sony-/JBL-/Bose-Modelle) liefern zudem Stände für links, rechts und das Ladecase | Windows-Geräteeigenschaft; Fast-Pair-Akku-Broadcasts (BLE-Dienstdaten `FE2C`), über die Bluetooth-Adresse dem gekoppelten Gerät zugeordnet |
| **Generisches HID** | Geräte, die die standardmäßige HID-Usage *Battery Strength* melden | HID Usage Page `0x06` / `0x85` |
| **HeadsetControl** | [Jedes unterstützte Headset](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, neuere Logitech u. v. m.) | Mitgeliefert; führt `headsetcontrol -o json` aus |
| **MAONO PD200W** | 2,4-GHz-Empfänger (`352F:040E`) | Akkuprozentwert; hardwaregetestet |


**Auf echter Hardware getestet:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (PlayStation-Empfänger `0951:1713`; Laden ungetestet), HyperX Cloud Core Wireless DTS (Empfänger `0951:173F`; Voll-Ladestand ungetestet), HyperX Pulsefire Haste 2 Core Wireless (Dongle `03F0:0AB5`; die Haste-2-Wireless-Dongles sind ungetestet), Cooler Master MM712 (Dongle), Rapoo VT3 Max Gen 2 (Empfänger `24AE:1417` und USB-Kabel `24AE:4617`; andere Rapoo-Modelle sind ungetestet, siehe [Rapoo-Protokollhinweise](#sec-rapoo)), Redragon M916 Pro 1K (Empfänger `3554:F55D`), Taidu TSG808 (Empfänger `3554:F5D5`), Redragon M915RGB-WL (Empfänger `25A7:FA07`; andere Areson-Modelle sind ungetestet, siehe [Areson-Protokollhinweise](#sec-areson)), SteelSeries Rival 650 Wireless (Empfänger `1038:1726` und USB-Kabel `1038:172B`), SteelSeries Arctis Nova Pro Wireless (Basisstation `1038:225D`; Akkumessung getestet, Laden und Ein-/Ausschaltübergänge ungetestet), HECATE G5M PRO (Empfänger `35BB:D3FB`), WLMouse YING Magnesium (8K-Empfänger `36A7:A874`), ATK N9 Ultra (Empfänger `373B:1204`), Corsair Scimitar Elite SE Wireless (Slipstream-Empfänger `1B1C:2B00`), Corsair Dark Core RGB Pro SE (Slipstream-Empfänger `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (2,4-GHz-Empfänger `1B1C:2B2A`; Akkumessung verifiziert), DAREU EM901X (Empfänger `260D:1074`; Laden und Ruhemodus/Aufwachen ungetestet), Jabra Evolve3 75 an einem Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (Empfänger `3837:4245` und USB-Kabel `3837:418C`), MCHOSE K7 Ultra (Empfänger `3837:1001`), MCHOSE K7 V2 Ultra+ (Empfänger `3837:1014` und USB-Kabel `3837:4028`; Laden beim Einstecken angezeigt), MSI VERSA 300 ELITE WIRELESS (Dongle `0DB0:9E22`; Laden und Ruhemodus-Verhalten ungetestet), MSI Clutch GM31 Lightweight Wireless (Empfänger `0DB0:0D3C`; die GM41 nutzt denselben Treiber auf Basis von Mitschnitten eines Besitzers), AJAZZ AK820 MAX (Dongle `05AC:024F`), AULA HERO 68 Air (8K Wireless Receiver `372E:106C`), AULA SC580 (USB-Kabel `088D:062E` und Empfänger `089D:062F`, einschließlich Laden und Ruhemodus), AirPods Pro 3 (Bluetooth, Modell `2027`), AirPods Max (Bluetooth, Modell `200A`), Sprime PM1 (Empfänger `1915:AC1C`), Ninjutso Ten Air (Empfänger `093A:EB01` und USB-Kabel `093A:E020`), MOONDROP GM01 Pro (Dongle `35D8:0133`), Delux M800 Pro (Empfänger `248A:5B2F`), Razer Barracuda X (2022) (Empfänger `1532:0550`; Akkustand ausgelesen, Ladeübergänge ungetestet), Razer BlackShark V3 X (HyperSpeed-Dongle `1532:057D`), Fantech Helios Go XD5 (Dongle `25A7:FA7C`), Fantech Raigor III (Dongle `1EA7:0066`; Laden wird von der Firmware nicht gemeldet), Finalmouse UltralightX (Dongle `361D:0100`), Finalmouse Starlight X (am Dongle) und Chimera V2 (Empfänger `3554:F512`; Akkustand und Laden ausgelesen).
Ebenfalls hardwaregetestet: Machenike L7 Arctic / L7 Mix (Empfänger `248A:FF4C` und Kabel `248A:FF4E`), einschließlich Laden und Unterdrückung doppelter Kabel-/Empfänger-Einträge. Bluetooth sowie Unter-/Obergrenzen (niedriger/voller Akku) wurden nicht auf Hardware getestet.
Ebenfalls hardwaregetestet: MCHOSE V9 Pro 2 (Dongle `3837:6011`); Akkustand ausgelesen, Laden und Ruhemodus ungetestet.
Ebenfalls hardwaregetestet: EPOMAKER EA75 am 2,4-GHz-Empfänger `05AC:024F` mithilfe des bestehenden SONiX-Treibers aus [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). Akkuprozentwert, Wiederverbindung des Empfängers und Wiederherstellung nach dem Einschalten wurden verifiziert. Ladeanzeige und Akkumeldung per Kabel werden von diesem Treiber nicht unterstützt; Akkumeldung über Bluetooth wurde nicht getestet. Der gemeldete Prozentwert kann bei anliegendem USB-Strom auf 100 % springen, was kein zuverlässiger Ladeindikator ist.
Ebenfalls hardwaregetestet: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (Empfänger `1038:1878` und USB-Kabel `1038:187A`), einschließlich Laden, Ausschalten (der letzte Stand bleibt abgeblendet sichtbar) und bei laufendem SteelSeries GG; GG zeigt nur einen dreistufigen Balken, mit dem der Stand übereinstimmte.
Ebenfalls hardwaregetestet: RAWM Leviathan V4 (RAWM HS Receiver `1915:2346`; Akkustand ausgelesen, Laden ungetestet).
**Auf Basis von Protokolldokumentation und anderen Projekten implementiert, noch nicht getestet:** alles Weitere, einschließlich der Fantech Raigor II WG10 (gleicher `1EA7:0066`-Dongle und gleiche Sammlung wie die getestete Raigor III, sollte also funktionieren). Wenn du eines dieser Geräte besitzt, berichte bitte über ein [neues Issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues), ob es funktioniert.

## Installation

[![Neueste Version](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Lade **`BatteryHub-Setup-<version>.exe`** aus dem [neuesten Release](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest) herunter.
2. Starte das Setup, wähle eine der 19 unterstützten Installationssprachen und klicke dich durch. Es werden **keine Administratorrechte** und **keine weiteren Installationen** benötigt: keine Laufzeitumgebungen, keine Treiber, keine Hersteller-Apps. HeadsetControl ist bereits enthalten, und der bearbeitbare Ordner `lang\` wird direkt neben `BatteryHub.exe` installiert.

Das Installationsprogramm legt einen Startmenü-Eintrag sowie ein Deinstallationsprogramm (*Einstellungen → Apps*) an und kann die App beim Anmelden automatisch starten. Lieber ohne Installation? Lade `BatteryHub-<version>-portable.zip` herunter, entpacke es an einen beliebigen Ort (lasse den Ordner `lang\` für UI-Übersetzungen neben `BatteryHub.exe`) und starte `BatteryHub.exe`.

**Hinweise:**
- **SmartScreen-Warnung:** Die EXE-Datei ist nicht digital signiert, daher meldet Windows möglicherweise „Der Computer wurde durch Windows geschützt“. Klicke auf *Weitere Informationen → Trotzdem ausführen*, oder kompiliere die App selbst.
- **Infobereich-Symbolmodus unter Windows 11:** Neue Symbole landen im Überlaufbereich `^`. Ziehe sie auf die Taskleiste oder aktiviere sie unter *Einstellungen → Personalisierung → Taskleiste → Andere Taskleistensymbole*.
- **Ein Gerät von der App fernhalten:** Wenn sich ein Gerät beim Laufen der App unerwünscht verhält, trage es in der Registrierungszeichenfolge `IgnoreDevices` unter `HKCU\Software\WirelessBattery` als `VID:PID`-Paare ein (hexadezimal, durch Kommas getrennt, z. B. `28BD:0947, 1234:ABCD`; `--dump` zeigt die IDs an). Die App öffnet es dann niemals. Grafiktabletts werden automatisch übersprungen.

## Updates unter Windows

Offizielle stabile Windows-Builds prüfen im Hintergrund auf das neueste veröffentlichte stabile Release des Projekts – erstmals 30 Sekunden nach dem Start und danach alle 24 Stunden, solange die App läuft. Öffne das Menü, um **Update verfügbar: vX.Y.Z...** zu sehen, oder wähle selbst **Nach Updates suchen...**. Update-Informationen erscheinen ausschließlich in diesem Menü: Akkusymbole, Prozentwerte und Tooltips bleiben unverändert, und automatische Prüfungen zeigen niemals eine Benachrichtigung oder einen Dialog an. Deaktiviere **Automatisch nach Updates suchen** im Menü, um Hintergrundprüfungen abzuschalten.

Bei einer installierten Version klicke auf den Update-Eintrag und auf **Herunterladen und installieren**. Ohne diesen Klick wird nichts installiert. Die App lädt die `SHA256SUMS.txt` des Releases und ihre Signatur herunter, prüft die Signatur gegen den fest in die App eingebauten öffentlichen Schlüssel des Maintainers, lädt das Windows-Installationsprogramm herunter und führt es nur aus, wenn dessen SHA-256-Prüfsumme mit der in der signierten Liste (und der von GitHub angegebenen) übereinstimmt. Anschließend wird die bestehende Installation aktualisiert. Einstellungen und Autostart-Präferenz bleiben erhalten, und die App startet nach der Installation neu. Bei einer Installation für alle Benutzer können Administratorrechte abgefragt werden. **Versionshinweise** öffnet die offizielle Release-Seite; **Später** behält deine aktuelle Version bei. Portable Kopien verlinken auf die Release-Seite zum manuellen Herunterladen des ZIP-Archivs.

Die Prüfungen fragen die öffentliche GitHub-API ohne Konto oder Token ab. Es werden keinerlei Geräte- oder Akkuinformationen gesendet. Offline-Fehler und GitHub-Ratenbegrenzungen beeinträchtigen die Akkuüberwachung nicht; ein zuvor gefundenes Release bleibt im Menü, bis eine erfolgreiche Prüfung es ablöst oder es installiert wird. Beim Abbrechen eines Downloads wird gewartet, bis der laufende Netzwerkvorgang sein begrenztes Zeitlimit erreicht. Das Installationsprogramm startet Windows niemals automatisch neu.

**Warum Updates sicher zu installieren sind:** Der Signierschlüssel verlässt niemals den PC des Maintainers und gelangt nie zu GitHub. Der Maintainer signiert die Prüfsummenliste jedes Releases auf seinem eigenen Rechner (siehe [docs/releasing.md](#sec-releasing)), sodass selbst jemand, der das GitHub-Konto oder dessen Build-Workflow übernimmt, kein Update veröffentlichen könnte, das die App installieren würde. Ein Release ohne gültige Signatur wird im Menü angezeigt, kann aber nur manuell heruntergeladen werden. Die Signatur ersetzt nicht die eigenen SmartScreen- oder UAC-Hinweise von Windows.

Installiere das erste Release mit dieser Funktion einmalig manuell. Entwicklungs-/Test-Builds deaktivieren offizielle Update-Prüfungen, damit lokale Änderungen nicht versehentlich überschrieben werden. Updates für Linux und das automatische Ersetzen portabler Kopien sind auf später verschoben.

## Befehlszeile

```
BatteryHub.exe --list     # alle Geräte und ihre Akkustände ausgeben, dann beenden
BatteryHub.exe --json     # JSON-Array mit Geräten und Akkuständen ausgeben, dann beenden
BatteryHub.exe --dump     # jede HID-Sammlung, nicht öffenbare HID-Geräte, alle USB-Geräte (auch ohne
                               # HID-Schnittstelle) und Bluetooth-Geräte; wird auch in %TEMP%\BatteryHub-dump.txt gespeichert
BatteryHub.exe --report   # Fenster „Unterstützung für ein Gerät anfragen“ öffnen
BatteryHub.exe --demo     # Beispielgeräte jeder Marke statt echter Geräte anzeigen (Screenshots, Farben prüfen)
BatteryHub.exe --quit     # laufende Instanz schließen
```

Der Linux-Build verwendet dieselben Flags mit `wireless-battery` anstelle von `BatteryHub.exe` und akzeptiert zusätzlich `--help`. `--json` gibt ein stabiles Array aus, das Skripte und Statusleisten-Widgets auswerten können:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` gibt an, wie lange die App den zuletzt bekannten Stand anzeigt, während das Gerät schläft. Das Hinzufügen neuer Felder ist abwärtskompatibel.

**Gerät wird nicht angezeigt?** Klicke mit der rechten Maustaste auf das Widget oder Infobereich-Symbol und wähle **Unterstützung für ein Gerät anfragen...**. Wähle das Gerät aus, prüfe was gesendet wird (es wird wortwörtlich angezeigt: Gerätename, Gerätetyp, USB-/HID-IDs und Schnittstellenlayout sowie dein optionaler Name und Hinweise) und klicke auf **Senden**. Die Anfrage erscheint auf der öffentlichen Liste unter [krisgfx.com/tools](https://krisgfx.com/tools/#requested) und öffnet oder aktualisiert ein GitHub-Issue. **Vollständigen Bericht kopieren** legt das vollständige `--dump` für das Issue in die Zwischenablage. Berichtsdaten werden ausschließlich gesendet, wenn du auf „Senden“ klickst. Offizielle Windows-Builds können außerdem GitHub kontaktieren, um nach Updates zu suchen, wie unter [Updates unter Windows](#updates-unter-windows) beschrieben; Update-Prüfungen senden keinerlei Geräte- oder Akkuinformationen.

## Kompilieren

Du benötigst [MinGW-w64](https://www.mingw-w64.org/), z. B. über [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # Entwicklungs-Build, Version 0.0.0
build.bat                                 # einfache cmd mit g++ und windres im PATH
make VERSION=1.2.3 CHANNEL=test            # versionierter Build, offizielle Updates deaktiviert
build.bat 1.2.3 test                       # entsprechender versionierter cmd-Build
make test VERSION=1.2.3 CHANNEL=test       # Geräte- und Updater-Regressionstests
```

Um das Installationsprogramm und das portable ZIP zu erstellen, installiere [Inno Setup](https://jrsoftware.org/isinfo.php), kompiliere zuerst mit der gewünschten Version (z. B. `make VERSION=1.2.3 CHANNEL=test`) und führe dann `powershell -File installer\build-installer.ps1 -Version 1.2.3` aus. Die Paketierung lehnt eine Version ab, die von der ausführbaren Datei abweicht. Das Skript lädt das festgepinnte HeadsetControl-Release herunter und prüft dessen Prüfsumme. GitHub Actions erledigt all dies automatisch: Das Pushen eines Tags wie `v1.0.0` veröffentlicht ein Release mit dem Installationsprogramm, dem portablen ZIP und dem HeadsetControl-Quellcode (wie von dessen GPL-Lizenz verlangt).

Windows-Builds benötigen außerdem PowerShell, um die gemeinsame Versionsnummer für Programm und Ressource zu erzeugen. Die Versions-Tags des offiziellen Repositorys kompilieren mit `CHANNEL=stable`; lokale Builds nutzen standardmäßig `dev`. Forks und Pull Requests aktivieren offizielle Updates nicht automatisch.

`BatteryHub.exe` funktioniert auch allein. Ohne `headsetcontrol.exe` daneben (oder im `PATH`) fehlen lediglich die zusätzlichen Headsets.

## Linux (experimentell)

Ein Linux-Build steht neben der Windows-App bereit. Er nutzt dieselben Herstellertreiber mit einem hidraw-basierten HID-Backend und einem GTK4-StatusNotifierItem-Infobereichsymbol; der Windows-Codepfad bleibt unverändert. Alle reinen Linux-Dateien liegen in `linux/` und `src/linux/`, und `build-linux.sh` kompiliert ihn (Windows nutzt weiterhin `build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Compiler & make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

Es wird keine zusätzliche HID-Bibliothek benötigt (hidraw wird direkt verwendet).

```sh
./build-linux.sh
./build-linux.sh test         # Unit-Test für den HID-Report-Descriptor-Parser
./wireless-battery --list     # erkannte Akkustände ausgeben und beenden
./wireless-battery --dump     # HID-Sammlungen auflisten
./wireless-battery --quit     # laufende Infobereich-Instanz beenden
```

Der HID-Zugriff erfordert eine udev-Regel, sonst startet die App, findet aber keine Geräte:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# abmelden und wieder anmelden
```

Das Infobereichsymbol funktioniert unter KDE Plasma nativ; GNOME benötigt einen AppIndicator-Host wie `gnome-shell-extension-appindicator`. Mehrsprachiges Umschalten funktioniert über das Untermenü *Sprache* (folgt standardmäßig `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` und übersetzt auch `--help`). `make -f linux/Makefile.linux install` installiert die Binärdatei, `lang/*.json` nach `$(PREFIX)/share/wireless-battery/lang/` sowie den Desktop-Starter (`linux/wireless-battery.desktop`) samt `linux/wireless-battery.svg` nach `$(PREFIX)` (Standard: `~/.local`); benutzerspezifische Sprachüberschreibungen liegen unter `~/.config/wireless-battery/lang/`.

Phase 1 deckt Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious, Finalmouse und die gemeinsamen Kysona-/Pulsar-/ATK-/G-Wolves-Protokolle ab. Bluetooth-/UPower-Fallbacks, HeadsetControl und die übrigen Hersteller sind für Folgephasen geplant.

## Einschränkungen

- **Überfüllte Taskleisten:** Bei einer sehr vollen zentrierten Windows-11-Taskleiste können die App-Schaltflächen bis an das Widget heranreichen. Unter Windows 10 wird der Bereich der Task-Schaltflächen automatisch verschmälert.
- **Smartphones:** Wird aus einer Datei ausgelesen, die Smartphone-Link für die Startmenü-Begleitkarte schreibt; dies ist keine dokumentierte API und kann sich mit Updates von Smartphone-Link ändern. Das Smartphone wird angezeigt, solange Smartphone-Link es als verbunden meldet; eine Karte, die älter als 3 Stunden ist, wird abgeblendet dargestellt. Die Karte gibt außerdem an, ob das Smartphone lädt, was als Ladeblitz erscheint.
- **Schlafende Geräte:** Ein Gerät im Ruhezustand antwortet möglicherweise nicht. Sein letzter Wert bleibt abgeblendet sichtbar. Logitech-Empfänger entfernen schlafende Geräte aus der Funkverbindung, daher wird ihr letzter Wert 30 Minuten lang beibehalten.
- **HECATE G2 Wireless 7.1 Headset** (2,4-GHz-Dongle `35BB:A009` / `A209`): Für dessen Dongle ist noch keine Akkuabfrage dokumentiert, daher wird er nicht ausgelesen. Ein USB-Mitschnitt, während die HECATE-Software den Headset-Akku anzeigt (siehe `CONTRIBUTING.md`), ist der Weg, es hinzuzufügen.
- **Keychron-Tastaturen:** Mit der Original-Firmware melden sie ihren Akkustand nur über Bluetooth (angezeigt über die Bluetooth-Unterstützung). Über den 2,4-GHz-Empfänger oder das Kabel benötigen sie eine Firmware mit dem Akku-Patch ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); ein Update der Tastatur über den Keychron Launcher entfernt ihn wieder. Keychron-Mäuse werden unterstützt.
- **Baseus AeQur GH02 Headset:** Der 2,4-GHz-Dongle (`10D6:4802`, Actions-Chip) überträgt nur Audio, Medientasten und den Firmware-Update-Kanal des Chips, jedoch keinen Akkustand. Verbinde das Headset über Bluetooth, um den Stand zu sehen (über die Bluetooth-Unterstützung, sofern Windows einen meldet).
- **Weikav Lucky65 v1 Tastatur:** Die Firmware meldet den Akku nicht über den 2,4-GHz-Dongle (`0603:0351`, Novatek-Chip). Die Tastatur hat keine Tastenkombination zur Akkuabfrage, und der offizielle Konfigurator verbindet sich nur über das USB-Kabel, nicht über den Dongle – daher gibt es keinen Akkustand zum Anzeigen.
- **Rapoo:** Unterstützte VT-Mäuse senden ihren Status selbstständig (Push), daher kann eine Abfrage bis zu 4 Sekunden pro passender Schnittstelle warten. Schlafende Mäuse können mit ihrem letzten Messwert bis zu 30 Minuten lang abgeblendet angezeigt werden. Die Unterstützung gilt für Nordic-54L-Bericht `07` und Legacy `BB` (VT3 Pro, VT1 Pro Max); CH584-Bericht `08`, Büro-Mäuse der MT-/M-Serie und andere Firmware-Protokolle werden von diesem Treiber nicht abgedeckt.
- **GameSir Cyclone Pro:** Der Dongle überträgt keinen Akkustand, daher wird er über Bluetooth LE direkt vom Controller gelesen. Kopple den Controller einmalig mit Windows (Einstellungen > Bluetooth und Geräte > Gerät hinzufügen > Bluetooth > `GameSir-Cyclone Pro`) und spiele weiter über den Dongle. Der PC benötigt Bluetooth. Der Stand wird alle 2 Minuten aktualisiert, und beim Laden gibt es keinen Prozentwert. Ohne Kopplung erscheint der Dongle als Xbox-Controller mit „Voll“. Details in [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM:** Die Maus wird über ihren Empfänger abgefragt, daher antwortet eine schlafende Maus nicht; sie bleibt mit ihrem letzten Wert bis zu 30 Minuten abgeblendet stehen und verlängert eine Aktualisierung im Schlafzustand um etwa eine Sekunde. Nur die Leviathan V4 am RAWM HS Receiver (`1915:2346`) ist getestet; die anderen Modelle stammen aus der Gerätetabelle von RAWM HUB. Die Leviathan V4 GT und NYX60 (VID `373E`, RAWM HUB 3.0) sowie die RAWM-HS-Tastaturen nutzen andere Protokolle und sind nicht abgedeckt.
- **Flydigi:** Dieser Treiber richtet sich an Vader 5 Pro und Apex 5; Bluetooth und andere Flydigi-Modelle (z. B. Apex 6) sind nicht abgedeckt. Die Prozentwerte stellen grobe Akkustufen dar. Apex 5 wurde auf echter Hardware über den 2,4-GHz-Empfänger und ein USB-Kabel getestet; Vader 5 Pro orientiert sich an SDL und Windows-Hardware-Traces.
- **Noch nicht unterstützt:** Kabellose MSI-Mäuse außer VERSA 300 ELITE und CLUTCH GM31 / GM41, kabellose MSI-Tastaturen, Razer-Kraken-Headsets sowie Barracuda-Modelle außer der Barracuda X (2022) auf `1532:0550`, HyperX-Pulsefire-Mäuse außer der Haste 2 Wireless / Haste 2 Core Wireless und das Xbox Wireless Headset am Xbox-Adapter: deren Akkuprotokolle sind nicht dokumentiert. Das Xbox Wireless Headset funktioniert über Bluetooth. Ein USB-Mitschnitt eines Besitzers (siehe `CONTRIBUTING.md`) ist der Weg, sie hinzuzufügen.
- **Weitere Geräte:** Einige 2,4-GHz-Geräte verwenden undokumentierte Protokolle und werden noch nicht unterstützt. Siehe [CONTRIBUTING.md](#sec-contributing), wie du helfen kannst, eines hinzuzufügen.

## Funktionsweise

Jeder Herstellertreiber in [`src/drivers/`](../../src/drivers) erkennt seine Geräte anhand der USB-Hersteller- und Produkt-ID und sendet ausschließlich schreibgeschützte Akkuabfragen. Unbekannte Geräte werden niemals beschrieben. Die generischen Fallbacks (HID Battery Usage, Bluetooth, XInput, HeadsetControl) betrachten nur Geräte, die noch kein Herstellertreiber beansprucht hat.

Das Taskleisten-Widget ist ein geschichtetes Kindfenster (`layered child window`) von `Shell_TrayWnd`, platziert links neben `TrayNotifyWnd`. Bei einem Neustart des Explorers wird es neu erstellt.

## Übersetzungen

Jede UI-Sprache ist eine einfache statische UTF-8-Textdatei in [`lang/`](../../lang): Englisch links, die Übersetzung rechts. Sprachdateien werden zur Laufzeit von der Festplatte geladen statt in die ausführbare Datei einkompiliert, sodass du sie direkt ohne Neukompilierung bearbeiten kannst.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **App-Oberfläche (Windows & Linux):**
  - Bearbeite oder füge `.json`-Dateien direkt im Ordner `lang/` neben `BatteryHub.exe` hinzu (oder unter `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/` bzw. `./lang/` unter Linux).
  - Oder wähle im Menü *Sprache → Eigene Sprache hinzufügen...*, um deinen Benutzer-Überschreibungsordner (`%APPDATA%\WirelessBattery\lang` unter Windows, `~/.config/wireless-battery/lang` unter Linux) mit `_template.json` vorzubereiten. Kopiere `_template.json` z. B. nach `it.json`, trage `@code`, `@name` sowie die Übersetzungen ein, und die Sprache erscheint im Menü (kein Neustart nötig). Dateien im Benutzerordner überschreiben eingebaute Texte mit demselben `@code`.
  - Lasse `{platzhalter}` unverändert stehen und ergänze `"@rtl": true` für von rechts nach links geschriebene Schriften. Leer gelassene Phrasen bleiben Englisch, eine Teilübersetzung ist also problemlos möglich.
  - Die Ausgaben von `--list` und `--dump` bleiben absichtlich auf Englisch: sie werden in GitHub-Issues eingefügt.
- **Windows-Installationsprogramm:** Inno-Setup-Übersetzungen liegen in [`installer/lang/`](../../installer/lang) (gespeichert als UTF-8 mit BOM) und sind unter `[Languages]` in `installer/BatteryHub.iss` registriert.
- **Dokumentation:** Jedes sichtbare Projektdokument wird als eine einzige eigenständige Markdown-Datei pro Sprache in [`docs/i18n/`](README.md) übersetzt (siehe [`docs/i18n/_template.md`](_template.md), um eine neue Sprache ganz ohne Build-Skripte hinzuzufügen).
- **Mit allen teilen:** Sende einen Pull Request mit deinen Dateien in `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` und `docs/i18n/`. Siehe [`docs/i18n/README.md`](README.md) für die Schritt-für-Schritt-Checkliste.

## Danksagungen

App-Symbol von [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

Die Protokolle stammen aus der Forschungsarbeit dieser Projekte:

- [Google Fast Pair Spezifikation](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): Akku-Broadcasts (links / rechts / Ladecase) von Fast-Pair-Ohrhörern
- [HeadsetControl Astro-Treiber](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) und [AstroBar](https://github.com/nichtlegacy/AstroBar): Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 Akkuprotokolle; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): A50 Gen 3 `0x72` Statusabfrage

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): VAXEE-Akku- und Ladebefehle ([Protokolldokumentation](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): SteelSeries-, Corsair-, HyperX-, Logitech- und Sony-INZONE-Headsets
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) und [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) und die Logitech-HID++-2.0-Dokumente: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) und [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (`0ADF`-Dongle)
- [rivalcfg](https://github.com/flozz/rivalcfg): SteelSeries-Mäuse (Rival Pro aus Pull Request #294)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) und [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Hitscans Web-Konfigurator ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- Linux `hid-kysona` (Lode Willems): Kysona, Pulsar und ATK
- ATKs Web-Konfigurator ([hub.atk.pro](https://hub.atk.pro)): ATK-Mäuse und die Headsets N9 Pro / N9 Ultra
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 und [mouse-battery](https://github.com/qwr79/mouse-battery): ATK / VXE NK NANO Dongle
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X und Endgame Gear XM2we, portiert aus dessen Providern (jeder Treiber nennt seine Quelle)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` und [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (nur Erkenntnisse): die Turtle-Beach-Swarm-II-Gerätefamilie
- G-Wolves' Web-Treiber ([mouse.xyz](https://mouse.xyz)): G-Wolves-Modelle und ihre Protokolle
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): CHERRY-Tastaturen am 2,4-GHz-Dongle (Frame-Format und Akkuabfrage)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): Keychron-Mäuse
- [NinjaForce](https://www.ninjaforce.co/) und [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): Ninjutso Ten / Ten Air Feature-Abfragen
- [nape_pro](https://github.com/nvalis/nape_pro) und [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro am Link-KM-Empfänger
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): LAMZU-Mäuse
- [vole](https://github.com/johanneszab/vole) und [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): Endgame Gear 4K-Mäuse
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) und [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) und [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (aus Finalmouses xpanel)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) und [g49-web-control](https://github.com/pingpingjinping/g49-web-control): Redragon-IDs
- [m913-ctl](https://github.com/Qehbr/m913-ctl) und [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): Areson-`25A7`-Frame-Layout und `GetPower`-Befehl
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) und [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW und DW
- RKs Web-Treiber ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) und [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (Dokumentation): MCHOSE A5 Pro / A5 Pro Max (erste Generation, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): CompX-Empfängerberichte für Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) und [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) und [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- Der Wraith-Web-Treiber ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 und [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 und [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) und [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) am Empfänger `1532:0550`; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): Framing des Empfängers `1532:0552`
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): Rongyuan- und Xenta-Empfänger (Attack Shark u. a.)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): SONiX-Tastaturen an ihrem 2,4G-Dongle (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) und [ak820-studio](https://github.com/usharik/ak820-studio): AJAZZ AK820 Pro Empfänger `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) und [Kraber](https://github.com/AkashPanja/Kraber): Semico-`1A2C`-Statusprotokoll (`AA 55 CC 33` / `0x0E`) für Attack Shark X98 und AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) und [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 und MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) und [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): GameSir Cyclone Pro Bluetooth-LE-„base info“-Akkuanfrage
- [jabridge](https://github.com/Watchdog0x/jabridge): Jabra-GNP-Protokoll (Link 380 / 390 Dongles)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): `1EA7:0066`-Statusseiten-Protokoll (Fantech Raigor III und andere generische „2.4G Mouse“-Geräte)
- Linux `hid-playstation`: DualShock 4 / DualSense Berichtsaufbau
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): AULA SC580 / SC580X Herstellerprotokoll
- RAWM HUB Web-App ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) und ihre Gerätetabelle: RAWM-Mäuse und SADES Dagger
- [SDLs Flydigi-HID-Treiber](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) und [HaloBattery Issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): Abfrage-Framing und Akkuaufbau von Vader 5 Pro und Apex 5
- [SDLs 8BitDo-HID-Treiber](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): 8BitDo Ultimate 2 Akkubyte
- BEITONG iControl (dessen KP20- und KP40D-Seiten sowie der USB-Datenverkehr des KP20-Empfängers): BEITONG KP20 / KP40D Akkuabfrage und Nutzlast-Verwürfelung
- [SDLs 8BitDo-HID-Treiber](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) und [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): 8BitDo Akkubyte und Hersteller-HID-Protokoll
- JBL QuantumENGINE (dessen HIDV3-Geräteinfo-Nachrichten): JBL Quantum Headsets
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, Compx-Protokoll auf `FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) und [BrimDeck](https://github.com/MoFeng2223/BrimDeck): Scyrox V12M Profilabfrage
- JBL QuantumENGINE: HIDV1-Verbindungs- und Akkuberichte für das Quantum 350 sowie HIDV3-Geräteinfo-Nachrichten für neuere Quantum-Headsets
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): JBL Quantum 610 HIDV1-Akku- und Verbindungsberichte sowie die Quantum-Reihe (360 als HIDV1-Dongle-Modell)

## Lizenz

[GNU General Public License v3.0 oder neuer](../../LICENSE). Du darfst diese Software verwenden, verändern und weiterverbreiten; alles, was du auf ihrer Grundlage weitergibst, muss jedoch unter derselben Lizenz samt Quellcode veröffentlicht werden.


---

<a id="sec-contributing"></a>
> 📄 **Abschnitt:** Mitwirken (`CONTRIBUTING.md`) · [Englisches Original](../../CONTRIBUTING.md) · [↑ Nach oben](#top)

# Mitwirken

## Melden, ob ein Gerät funktioniert

Die meisten Treiber wurden anhand von Protokolldokumentation geschrieben und konnten nicht an jedem Modell getestet werden. Bitte öffne ein Issue mit:

- dem Gerätenamen und ob es über Empfänger, Kabel oder Bluetooth verbunden ist
- der Ausgabe von `BatteryHub.exe --list`
- der Ausgabe von `BatteryHub.exe --dump`
- dem Akkustand, den die eigene Software des Herstellers anzeigt

## Ein Gerät hinzufügen

1. Führe `BatteryHub.exe --dump` aus und finde die Hersteller- und Produkt-IDs deines Geräts sowie die herstellerspezifischen Sammlungen (Usage Page `FFxx`) samt ihren Berichtsgrößen.
2. Finde das Akkuprotokoll. Gute Anlaufstellen: HeadsetControl, OpenRazer, Solaar, rivalcfg, OpenRGB, OpenLinkHub oder ein USB-Mitschnitt der Hersteller-Software (Wireshark + USBPcap).
3. Wenn der Hersteller bereits einen Treiber in `src/drivers/` hat, ergänze dort die Produkt-ID (und eventuelle Unterschiede). Erstelle andernfalls `src/drivers/<vendor>.cpp`:

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

4. Deklariere die Funktion in `src/drivers/drivers.h` und rufe sie aus `PollAllDevices()` in `src/devices.cpp` auf (vor den generischen Fallbacks). `build.bat` und das Makefile erfassen neue Dateien automatisch.
5. Aktualisiere die Gerätetabelle in `README.md`.

### Regeln für Treiber

- **Schreibgeschützt:** Sende ausschließlich Anfragen, die den Zustand auslesen. Ändere niemals Einstellungen, Beleuchtung oder Modi.
- **Exakte Erkennung:** Sprich nur Geräte an, die du anhand von Hersteller- und Produkt-ID oder anhand einer für das Protokoll eindeutigen herstellerspezifischen Sammlung erkennst.
- **Immer mit Zeitlimit:** Ein fehlendes Gerät darf die Abfrage nicht länger als etwa eine Sekunde blockieren. Passive Protokolle benötigen möglicherweise mehr Zeit, um ein dokumentiertes Sendeintervall abzudecken (z. B. Delux und Rapoo). Halte ein einziges absolutes Zeitlimit von höchstens 4 Sekunden pro passender Sammlung ein, starte es bei unzusammenhängenden Berichten nicht neu und dokumentiere, warum die Ausnahme nötig ist.
- **Quellen angeben:** Nenne die Herkunft des Protokolls in einem Kommentar am Anfang der Datei.

## Übersetzungen

UI-Sprachen sind einfache statische UTF-8-Textdateien in `lang/`, die unter Windows und Linux zur Laufzeit von der Festplatte geladen werden (kopiere `lang/_template.json` nach `lang/<code>.json`, trage `@code`, `@name` und die Phrasen ein — keine Neukompilierung erforderlich). Neue UI-Texte im Code laufen über `T(L"...")` oder über `TF(L"... {name} ...", { { L"name", value } })`, wenn sie Werte enthalten; setze übersetzte Sätze niemals aus Bruchstücken zusammen. Füge neu hinzugefügte Phrasen ebenfalls zu `lang/_template.json` hinzu.

Übersetzungen des Windows-Installationsprogramms liegen in `installer/lang/*.isl` (gespeichert als UTF-8 mit BOM und registriert in `installer/BatteryHub.iss`), Kommentare des Linux-Launchers liegen in `linux/wireless-battery.desktop`, und vollständige Dokumentationsübersetzungen liegen in `docs/i18n/<code>.md` (einzelne eigenständige Datei, kopiert aus `docs/i18n/_template.md`). Siehe [`docs/i18n/README.md`](README.md) für den vollständigen Leitfaden für Mitwirkende.

## Code-Stil

C++17, reines Win32, keine Abhängigkeiten von Drittanbietern. Halte die Binärdatei klein. Formatiere ungefähr wie der bestehende Code (4 Leerzeichen Einrückung, 120 Zeichen Zeilenlänge).

## Entwicklung des Windows-Updaters

Der Updater ist nur für Windows verfügbar und nutzt WinHTTP, BCrypt sowie das vorhandene Inno-Setup-Installationsprogramm. Halte den Update-Status ausschließlich im Menü. Füge keine Update-Symbole, Badges, Änderungen an Akku-Tooltips, Sprechblasen, Toasts oder automatische Dialoge hinzu. Die Geräteabfrage läuft getrennt von Netzwerkarbeit.

Build-Version und -Kanal werden über die generierte Datei `build/version.h` von C++ und den Windows-Ressourcen geteilt. Nutze `make VERSION=1.2.3 CHANNEL=test` oder `build.bat 1.2.3 test` für lokale Tests; `dev` ist der Standardwert und `stable` aktiviert offizielle Release-Prüfungen. Versionskomponenten müssen in `0..65535` passen. Nur der Release-Tag-Workflow des offiziellen Repositorys wählt automatisch `stable`. Aktiviere in einem Fork-Build niemals versehentlich einen offiziellen Update-Kanal.

Führe `make test VERSION=1.2.3 CHANNEL=test` für die bestehenden Gerätetests sowie striktes Release-Parsing, Versionssortierung, Prüfungsplanung, echte SHA-256-Dateiprüfungen, Argument-Quoting und Hilfsprogramm-Schutzprüfungen aus. Updater-Regressionstests decken außerdem Abbruch bei Download-Abschluss, Dialog-Schutzmaßnahmen sowie Fehler beim Konfigurieren von HTTP-Timeouts und Weiterleitungsbeschränkungen ab. Der Windows-Test bindet die Implementierungen ein – nach dem Muster der bestehenden Linux-Backend-Tests – und ersetzt das Senden über HTTP, sodass diese Tests GitHub nicht kontaktieren können. In der Produktion werden keine reinen Test-Controller-Einstiegspunkte hinzugefügt. Einzelne Targets sind `make test-update-core` und `make test-update-win`. Native Updater-Tests binden die Anwendungsressource ein, um Common Controls v6 zu aktivieren. Tests verwenden lokale Daten und laden nichts herunter, fordern keine Rechteerhöhung an, installieren nichts und ändern nicht die Autostart-Einstellungen des Benutzers. Der Produktions-Endpunkt der Anwendung kann für Tests nicht überschrieben werden.

Führe vor dem Paketieren `powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3` aus. `installer/build-installer.ps1 -Version 1.2.3` führt diese Prüfung vor dem Herunterladen von Abhängigkeiten ebenfalls aus. Der Installer-Pfad `/WBUPDATE=1` behält vorhandene Autostart- und App-Einstellungen bei und überlässt den Neustart dem temporären Hilfsprogramm. Dieses Hilfsprogramm verbleibt unter dem ursprünglichen Benutzer und erhöht Rechte nur bei einer globalen Installation. WinHTTP-Handles gehören dem Worker; ein Abbruch erfolgt kooperativ zwischen Aufrufen mit endlichem Zeitlimit. Beim endgültigen Beenden der App wird auf diesen Worker gewartet (`join`), wodurch ein laufendes Netzwerk-Timeout abgewartet werden kann.

Nutze für eine Release-Überprüfung ein separates Windows-Testkonto oder eine VM, um zwei echte Installer-Versionen, benutzerbezogene und globale Installation, UAC-Abbruch, Autostart ein/aus, benutzerdefinierte Pfade, Setup-Fehler und Neustart durchzutesten. Unit-Tests und das Bauen eines Pakets verifizieren diese Installer-Effekte nicht. Visuelle Menü-/Theme-Prüfungen und echte End-to-End-Installer-/UAC-Tests bleiben manuelle Release-Gates; markiere sie erst als bestanden, wenn sie tatsächlich beobachtet wurden. Teste niemals, indem du die Produktivinstallation des Alltagsbenutzers überschreibst.

## Automatische Sicherheitsprüfung

Jeder Pull Request wird vom „PR safety check“ auf Dinge gescannt, die diese App niemals tun sollte (Netzwerkzugriff, Starten von Programmen, Auslesen von Tastatur/Zwischenablage/Bildschirm, Autostart-Einträge, Binärdateien, Build- oder Release-Änderungen). Eine Markierung bedeutet keine Ablehnung: Erläutere die markierten Zeilen einfach in der PR-Beschreibung.

Die Nutzung von KI-Werkzeugen ist in Ordnung, entferne jedoch bitte `Co-authored-by`-Zeilen, die ihnen Credits geben (z. B. `Co-authored-by: Claude ...`), aus deinen Commit-Nachrichten. Die Prüfung schlägt fehl, solange sie vorhanden sind.


---

<a id="sec-pr-template"></a>
> 📄 **Abschnitt:** Pull-Request-Vorlage (`.github/pull_request_template.md`) · [Englisches Original](../../.github/pull_request_template.md) · [↑ Nach oben](#top)

## Was hinzugefügt wird

<!-- Gerät(e) und Hersteller-/Produkt-IDs, z. B. "Acme M1 (1234:5678)". -->

## Woher das Protokoll stammt

<!-- Verlinke die Quelle (ein anderes Projekt, ein Web-Treiber des Herstellers, dein eigener USB-Mitschnitt). -->

## Auf echter Hardware getestet?

<!-- Ja (welches Gerät, was --list ausgegeben hat) / Nein -->

## Checkliste

- [ ] Es werden ausschließlich schreibgeschützte Akkuabfragen gesendet; keine Einstellungen, Beleuchtung oder Firmware werden verändert
- [ ] Es werden nur Geräte angesprochen, die anhand von Hersteller-/Produkt-ID (oder einer protokollspezifischen Sammlung) erkannt werden
- [ ] Kein Netzwerkzugriff, kein Starten anderer Programme, keine neuen Dateien außerhalb von `src/`, `docs/` oder `README.md`
- [ ] Keine Binärdateien oder generierten Dateien enthalten
- [ ] Keine `Co-authored-by`-Zeilen mit Nennung von KI-Tools (Claude, Copilot, ChatGPT …) in den Commit-Nachrichten
- [ ] Änderungen an `.github/`, `installer/`, `build.bat` oder `Makefile` sind oben erläutert


---

<a id="sec-releasing"></a>
> 📄 **Abschnitt:** Releases erstellen (`docs/releasing.md`) · [Englisches Original](../../docs/releasing.md) · [↑ Nach oben](#top)

# Releases erstellen

Die App aktualisiert sich selbst über GitHub-Releases, installiert jedoch ausschließlich ein Setup, dessen SHA-256 in einer mit dem Release-Schlüssel signierten `SHA256SUMS.txt` aufgeführt ist. Dieser Schlüssel liegt auf dem PC des Maintainers, niemals auf GitHub: Ein kompromittiertes Konto, Token oder ein kompromittierter Workflow kann zwar Dateien veröffentlichen, aber keine Signatur, die die App akzeptiert.

## Einmalig: Release-Schlüssel erstellen

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Fragt nach einem Passwort (12+ Zeichen) und schreibt den verschlüsselten privaten Schlüssel nach `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- Schreibt den öffentlichen Schlüssel in `src\update_public_key.h`. Committe diese Datei. Offizielle Builds verweigern ohne darin enthaltenen Schlüssel die Kompilierung.
- **Sichere die Schlüsseldatei und bewahre das Passwort auf** (ein Passwortmanager eignet sich gut für beides). Geht eines von beiden verloren, können sich installierte Apps nicht mehr selbst aktualisieren: Du müsstest einen neuen Schlüssel anlegen und jeder Benutzer müsste ein Release manuell installieren.

## Bei jedem Release

1. Pushe ein Versions-Tag (`git tag v1.2.3 && git push origin v1.2.3`). CI erstellt das Setup, das portable ZIP sowie `SHA256SUMS.txt` und veröffentlicht das Release.
2. Signiere die Prüfsummenliste:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Das Skript lädt `SHA256SUMS.txt` vom Release herunter, zeigt sie an, bittet um Bestätigung, fragt nach dem Schlüssel-Passwort und schreibt `SHA256SUMS.txt.sig`. Wenn sich dieselben Dateien in `dist\` befinden (ein lokaler Build dieser Version), zeigt es an, ob sie übereinstimmen.
3. Lade `SHA256SUMS.txt.sig` zum Release hoch (das Skript öffnet die Bearbeitungsseite). Ab diesem Moment bietet die App **Herunterladen und installieren** an. Vorher zeigt sie das Update an, verlinkt aber nur auf die Release-Seite.

Signiere eine Liste ausschließlich für ein Release, das du selbst veröffentlicht hast. Die Signatur besagt „genau diese Dateien sind das Release“; das Signieren ist also der Schritt, bei dem ein manipulierter Upload auffliegen würde.

## Schlüssel wechseln

Führe `new-release-key.ps1` mit einem neuen `-KeyFile` aus: Es fügt den neuen öffentlichen Schlüssel neben dem alten in `src\update_public_key.h` hinzu. Veröffentliche eine mit dem alten Schlüssel signierte Version, die beide Schlüssel enthält, signiere ab dem darauffolgenden Release mit dem neuen Schlüssel und entferne den alten Schlüssel später. Ein verlorener oder geleakter Schlüssel lässt sich nicht auf diesem Weg ablösen: Entferne ihn aus der Header-Datei; Benutzer älterer Versionen müssen das nächste Release manuell installieren.

## Was die App prüft, bevor sie ein Setup ausführt

- Das Release ist das neueste des Repositorys, kein Entwurf (Draft) oder Vorab-Release (Prerelease) und neuer als die App.
- `SHA256SUMS.txt.sig` ist eine gültige ECDSA-P-256-Signatur von `SHA256SUMS.txt` mit einem Schlüssel aus `src\update_public_key.h` (Windows BCrypt, kein Drittanbietercode).
- Die signierte Liste nennt `BatteryHub-Setup-<version>.exe` genau einmal mit derselben SHA-256-Prüfsumme, die GitHub für die Datei angibt.
- Das heruntergeladene Setup hat exakt diese Größe und SHA-256-Prüfsumme. Eine Kopie der App prüft sie unmittelbar vor dem Start erneut und hält die Datei gesperrt, damit sie dazwischen nicht ausgetauscht werden kann.
- Downloads verwenden ausschließlich HTTPS zu `github.com`, `objects.githubusercontent.com` und `release-assets.githubusercontent.com`, wobei jede Weiterleitung geprüft wird.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Abschnitt:** Keychron-Tastatur-Firmware (`docs/keychron_keyboard_firmware/README.md`) · [Englisches Original](../../docs/keychron_keyboard_firmware/README.md) · [↑ Nach oben](#top)

# Keychron-Tastatur-Akku über den 2,4-GHz-Empfänger

Keychrons Original-Firmware meldet den Akkustand der Tastatur nur über Bluetooth. Mit der kleinen QMK-Änderung in [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch) beantwortet die Tastatur auch eine Akkuabfrage (`A4`) über den Keychron-Link-Empfänger und das USB-Kabel, und BatteryHub zeigt Akkustand, Spannung und Ladestatus an.

Getestet auf der **Keychron K5 Max ANSI RGB** (`3434:0A50`) mit dem Keychron-Link-Empfänger (`3434:D030`).

## Was der Patch ändert

Basierend auf [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) Branch `2025q3` (Commit `57e682c`):

- fügt den Raw-HID-Befehl `KC_GET_BATTERY` (`0xA4`) aus [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1) hinzu: Antwort `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`;
- leitet Raw-HID-Anfragen, die über die Funkverbindung eintreffen, an denselben Handler weiter;
- in `keyboards/keychron/k5_max/config.h`: `#define WILRESS_RAW_ENABLE` (im Keychron-Code genau so geschrieben) und `#define KC_BATTERY_MODEL_ID 0`.

Sonst ändert sich nichts: Keymaps, Beleuchtung und Keychron Launcher funktionieren weiter.

## Option 1: fertige K5-Max-Firmware flashen

Ein Build **ausschließlich für die K5 Max ANSI RGB** hängt an [diesem Release](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1) (`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`). Flashe sie auf kein anderes Modell oder Layout.

## Option 2: selbst kompilieren

Benötigt Git und Docker (oder eine funktionierende [QMK-Umgebung](https://docs.qmk.fm/newbs_getting_started)).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

Das Ergebnis ist `keychron_k5_max_ansi_rgb_keychron.bin` im Stammverzeichnis des Repositorys. Unter Windows ist ein über Bind-Mount eingebundener Checkout in Docker sehr langsam; direkt im Container (oder in WSL) zu klonen ist deutlich schneller.

**Weitere kabellose Keychron-Tastaturen** (Q/V/K Max und andere Modelle im `2025q3`-Baum mit `LK_WIRELESS_ENABLE`): Die Änderungen unter `keyboards/keychron/common/` lassen sich unverändert anwenden. Füge die beiden `#define`-Zeilen in die `config.h` deiner eigenen Tastatur statt der der K5 Max ein und baue dein eigenes Target, z. B. `make keychron/<model>/<layout>/<variant>:keychron`. Die App benennt derzeit eine K5 Max (`0A50`–`0A58`) nach Modell und jede andere als „Keychron keyboard“.

## Flashen

1. Stelle den Modusschalter auf **Cable** und ziehe das USB-Kabel ab.
2. Halte **Esc** gedrückt, während du das Kabel einsteckst. Die Tastatur wechselt in den STM32-Bootloader.
3. Flashe die `.bin`-Datei mit [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (oder `dfu-util`).
4. Schalte zurück auf **2.4 GHz** und prüfe mit `BatteryHub.exe --list`:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Ein Update der Tastatur über Keychron Launcher ersetzt diese Firmware und entfernt die Akkumeldung. Um die Änderung rückgängig zu machen, flashe auf demselben Weg Keychrons offizielle Firmware.

## Lizenz

QMK steht unter GPL-2.0-or-later; der Patch steht unter derselben Lizenz. Jeder, der eine daraus gebaute Binärdatei erhält, muss auch diese Quellcodeänderung erhalten können.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Abschnitt:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [Englisches Original](../../docs/gamesir_cyclone_pro.md) · [↑ Nach oben](#top)

# GameSir Cyclone Pro Akkuunterstützung

## Warum der Controller als voller Xbox-Controller angezeigt wurde

Der Cyclone Pro (Modell T4cp) spielt über einen 2,4-GHz-Dongle, `3537:1015`. Der Dongle meldet sich gegenüber Windows als kabelgebundener Xbox-360-Controller (XUSB, `Xbox 360 Controller for Windows`). XInput beantwortet dessen Akkuabfrage mit „Full“, sodass der XInput-Fallback ihn unabhängig vom tatsächlichen Ladestand als `Xbox controller 1` mit 100 % aufführte.

Der Dongle überträgt keinerlei Akkuinformationen:
- seine einzige HID-Sammlung ist der XInput-Gamecontroller (`HID\VID_3537&PID_1015&IG_00`)
- er besitzt keine herstellerspezifische Sammlung wie der Nova (`FF7A`) oder der Cyclone 2 (`FFF0`)

## Wo sich der Akkustand befindet

Während er über den Dongle spielt, sendet das Gamepad zusätzlich über Bluetooth LE als `GameSir-Cyclone Pro` – das ist die Verbindung, die GameSirs Smartphone-App nutzt. Deren Anfrage „get base info“ liefert den Akkustand zurück:

| Schritt | Detail |
|---|---|
| Dienst | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Charakteristik | `0x865F` (Notify, Write without Response) |
| Anfrage | Benachrichtigungen aktivieren, `01 01` schreiben |
| Antwort | 19-Byte-Benachrichtigung (manche Firmwares stellen `C9` voran, 20 Bytes) |

Aufbau der Antwort:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

Byte 18 ist der Akkustand in Prozent (0–100) oder `FF` während des Ladens. Beim Laden wird kein Stand gemeldet, sodass der zuletzt bekannte Prozentwert beibehalten und mit dem Ladeblitz angezeigt wird.

Das Gamepad bietet außerdem den Dienst `0xFF10`, den Firmware-Update-Kanal von GameSir. Der Treiber öffnet ihn niemals. Das Gamepad besitzt keinen Standard-Battery-Service (`0x180F`), weshalb die Bluetooth-Seite von Windows und der Bluetooth-Fallback keinen Stand dafür anzeigen.

Quelle: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), wo das Protokoll aus GameSirs Android-App (`BluetoothLeService`, „get base info“) ermittelt wurde.

## Wie der Treiber funktioniert

`src/drivers/gamesir_ble.cpp`, aufgerufen vor dem XInput-Fallback:

1. **Gamepad finden.** Er sucht Geräteschnittstellen der Klasse `{00008650-0000-1000-8000-00805F9B34FB}`. Windows legt für jeden GATT-Dienst eines gekoppelten BLE-Geräts eine solche Schnittstelle an. Es werden nur jene verwendet, deren übergeordneter `BTHLE\DEV_…`-Knoten `GameSir-Cyclone…` heißt.
2. **Akku auslesen.** Er öffnet diesen Dienst über die Win32-GATT-API (`bluetoothleapis.h`, `-lbluetoothapis`), abonniert `0x865F` und schreibt `01 01`. Er wartet bis zu 3 Sekunden auf die Antwort und schaltet Benachrichtigungen danach wieder ab.
3. **Abfrage schnell halten.** Die BLE-Verbindung kann mehrere Sekunden dauern oder im Schlafzustand des Gamepads in ein Timeout laufen, daher läuft die Abfrage in einem eigenen Thread:
   - höchstens alle 2 Minuten nach einem erfolgreichen Auslesen bzw. jede Minute nach einem fehlgeschlagenen
   - die Abfrage meldet den zwischengespeicherten Messwert und beendet die Ausgabe, sobald er 6 Minuten alt ist
   - `graceSec` hält ihn danach abgeblendet als im Ruhezustand sichtbar
   - nur die allererste Abfrage eines Programmlaufs wartet einmalig auf den Thread mit einem absoluten 4-Sekunden-Limit, sodass der Stand beim Start und in `--list` erscheint
4. **Gefälschten Xbox-Eintrag ausblenden.** Sobald der Dongle vorhanden ist, beansprucht der Treiber `3537:1015`:
   - der Pfad über `Windows.Gaming.Input` überspringt nun beanspruchte Hersteller-/Produkt-IDs
   - der XInput-Pfad ermittelt die Hersteller-/Produkt-ID jedes Slots über `XInputGetCapabilitiesEx` (xinput1_4 Ordinal 108) und überspringt beanspruchte Geräte
   - fehlt dieser Export, verhält sich XInput wie bisher

## Getestete Hardware

Windows 11, Cyclone Pro am Dongle (`3537:1015`), einmalig über Bluetooth gekoppelt, am 2026-11-18:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Während das Gamepad schlief, erschien der Eintrag „Xbox controller 1 / Full“ nicht mehr und es wurde nichts für das Gamepad angezeigt.

## Einschränkungen

- **Kopplung:** Das Gamepad muss einmalig mit Windows gekoppelt werden (Einstellungen > Bluetooth und Geräte > Gerät hinzufügen > Bluetooth > `GameSir-Cyclone Pro`). Nicht gekoppelte Gamepads besitzen keine GATT-Geräteschnittstelle. Das Koppeln fügt Bluetooth-Gamepad-Einträge hinzu, die jedoch keine Eingaben senden, solange das Gamepad über den Dongle spielt.
- **Bluetooth erforderlich:** Der PC benötigt Bluetooth LE.
- **Ein Gamepad:** Es wird nur ein Cyclone Pro pro PC ausgelesen.
- **Laden:** Während des Ladens wird kein Prozentwert ausgegeben.


---

<a id="sec-localization-guide"></a>
> 📄 **Abschnitt:** Leitfaden zur Mehrsprachigkeit & Lokalisierung (`docs/i18n/README.md`) · [Englisches Original](../../docs/i18n/README.md) · [↑ Nach oben](#top)

# BatteryHub Index & Leitfaden für Mehrsprachigkeit und Lokalisierung

Jedes sichtbare Dokument in diesem Repository ist als **eine eigenständige Markdown-Datei pro Sprache** in `docs/i18n/` zusammengefasst, während alle Anwendungstexte zur Laufzeit in **statischen bearbeitbaren Textdateien** unter [`lang/`](../../lang) (gemeinsam genutzt von Windows und Linux) und die Texte des Windows-Installationsprogramms in [`installer/lang/`](../../installer/lang) liegen.

## Unterstützte Sprachen (19)

| Code | Sprache | Vollständige Dokumentation | App-Oberfläche (Windows & Linux) | Windows-Installationsprogramm |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (Quelltexte) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Wie die Sprachumschaltung in der Praxis funktioniert

### 1. Windows-App (`BatteryHub.exe`)
- **Automatische Erkennung:** Bei Auswahl von *Sprache → Automatisch (Windows-Sprache)* fragt BatteryHub unter Windows `GetUserPreferredUILanguages` ab und wählt die am besten passende statische `*.json`-Datei.
- **Manuelles Umschalten:** Klicke auf das Taskleisten-Widget oder Infobereich-Symbol → **Sprache** → wähle eine Sprache aus. Die Oberfläche aktualisiert sich sofort und speichert die Wahl in `HKCU\Software\WirelessBattery\Language`.
- **Statische externe Dateien (ohne Neukompilierung bearbeitbar):** `BatteryHub.exe` lädt zuerst `<exe>\lang\*.json` und danach `%APPDATA%\WirelessBattery\lang\*.json`. Jede Datei im Benutzerordner mit demselben `@code` überschreibt passende Phrasen, und beim erneuten Öffnen des Menüs werden die Dateien live von der Festplatte neu geladen.
- **CLI `--help`:** `BatteryHub.exe --help` zeigt den Hilfedialog in deiner aktiven UI-Sprache an (`--list`, `--json` und `--dump` bleiben für GitHub-Fehlerberichte absichtlich auf Englisch).

### 2. Linux-App (`wireless-battery`)
- **Automatische Erkennung:** Folgt den POSIX-Locale-Variablen in der Reihenfolge: `LANGUAGE` (durch Doppelpunkt getrennte Liste) → `LC_ALL` → `LC_MESSAGES` → `LANG` (sofern nicht durch `LC_ALL=C` / `POSIX` überschrieben).
- **Manuelles Umschalten:** Rechtsklick auf das Infobereich-Symbol → **Sprache** → wähle **Automatisch (Systemsprache)** oder eine beliebige installierte Sprache. Gespeichert unter `[general] language=` in `$XDG_CONFIG_HOME/wireless-battery/config.ini` (Standard: `~/.config/wireless-battery/config.ini`).
- **Statische Suchpfade (niedrigste bis höchste Priorität):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (Standard: `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (Standard: `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help` gibt eine anhand von `config.ini` oder System-Locale übersetzte CLI-Hilfe aus; `--list` und `--dump` bleiben Englisch.

### 3. Windows-Installationsprogramm (`BatteryHub-Setup-<version>.exe`)
- Zeigt eine Sprachauswahl (`ShowLanguageDialog=yes`), die anhand deiner Windows-UI-Sprache vorausgewählt ist (`LanguageDetectionMethod=uilanguage`).
- Installiert den vollständigen statischen Ordner `lang\*.json` neben `BatteryHub.exe` nach `{app}\lang\` (und auch das portable ZIP enthält `lang\*.json`).

---

## Eine Sprache hinzufügen oder aktualisieren (Schritt für Schritt)

Du benötigst **keine** Build-Werkzeuge, um die App-Oberfläche oder die Dokumentation zu übersetzen, und nur Inno Setup 6, falls du das Windows-Installationsprogramm testweise kompilieren möchtest.

### Schritt 1 — App-UI-Texte (`lang/<code>.json`)
1. Öffne den Benutzer-Sprachordner über das Infobereich-Menü (**Sprache → Eigene Sprache hinzufügen...**) oder kopiere [`lang/_template.json`](../../lang/_template.json) nach `lang/<code>.json` (z. B. `lang/it.json`).
2. Fülle den Metadaten-Kopf aus:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Übersetze die rechte Seite nach ` = ` in jeder Zeile.
   - Behalte Platzhalter wie `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}` wortgetreu bei.
   - Verwende `\n` für explizite Zeilenumbrüche.
   - Speichere als **UTF-8 (ohne BOM)**.
   - Öffne das BatteryHub-Infobereich-Menü erneut für eine sofortige Vorschau — kein Neubau erforderlich!

### Schritt 2 — Windows-Installationsprogramm (`installer/lang/<code>.isl`)
1. Kopiere [`installer/lang/_template.isl`](../../installer/lang/_template.isl) nach `installer/lang/<code>.isl`.
2. **WICHTIG:** Speichere die Datei als **UTF-8 mit BOM (`EF BB BF`)**, damit Inno Setup Unicode-Zeichen unabhängig von veralteten Windows-Codepages zuverlässig einliest.
3. Wähle das passende Muster:
   - **Inno Setup liefert deine Sprache bereits mit** (prüfe `C:\Program Files (x86)\Inno Setup 6\Languages\`): Behalte nur `[CustomMessages]` und übersetze die 6 Zeilen (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, wobei `%1` und `%n` erhalten bleiben). Registriere sie in `installer/BatteryHub.iss` unter `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup liefert deine Sprache nicht mit**: Kopiere `installer/lang/zh-CN.isl` als vollständige Vorlage, setze `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, optional `RightToLeft=yes`), übersetze `[Messages]` und `[CustomMessages]` und registriere sie nach `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Hinweis: Bezeichner für `Name:` unter `[Languages]` dürfen nur ASCII-Buchstaben, Ziffern und Unterstriche enthalten (verwende `ptBR`, nicht `pt-BR`).

### Schritt 3 — Linux-Desktop-Starter (`linux/wireless-battery.desktop`)
Füge eine lokalisierte Zeile `Comment[<code>]=...` hinzu (verwende in `.desktop`-Dateien Unterstriche für Regionskürzel, z. B. `Comment[zh_CN]=...`).

### Schritt 4 — Vollständige Dokumentation in einer Datei (`docs/i18n/<code>.md`)
1. Kopiere [`docs/i18n/_template.md`](_template.md) nach `docs/i18n/<code>.md` (keine Generator-Skripte nötig — nur diese eine Datei!).
2. Übersetze das Inhaltsverzeichnis und alle 17 Abschnitte vollständig und behalte dabei Folgendes bei:
   - Alle `<a id="sec-..."></a>`-Anker-Tags und `<a id="top"></a>` unverändert
   - Alle Codeblöcke, CLI-Flags (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), USB-`VID:PID`s, HID Usage Pages, Hex-Pakete, Registry-Schlüssel, Dateipfade und URLs wortgetreu
   - Relative Bild-/Dateipfade unverändert (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE` usw.)
3. Aktualisiere die obere `<!-- lang-switcher:start -->`-Leiste in `docs/i18n/<code>.md` (hebe deine eigene Sprache fett hervor, verlinke alle anderen) und füge den Link zu deiner Sprache in die Sprachumschalter-Leisten in `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` und den benachbarten `docs/i18n/*.md`-Dateien ein.
4. Verwende für von rechts nach links geschriebene Sprachen (`ar`, `fa`, `he`) standardmäßiges Markdown, ohne die gesamte Datei in `<div dir="rtl">` einzuschließen, damit Tabellen und Codeblöcke sauber gerendert werden.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Abschnitt:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [Englisches Original](../../docs/ardor_fury_v2.md) · [↑ Nach oben](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

Der 2,4-GHz-Empfänger stellt HID Usage Page `000A`, Usage `0000` und einen 5-Byte-Input-Report bereit. Er sendet Daten per Broadcast; es werden keine HID-Befehle gesendet.

Auf echter Hardware beobachtete Berichte:

| Bericht | Akku |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

Das obere Nibble von Byte 3 kodiert die Stufe (`1`, `3`, `7`, `F` für 25, 50, 75 und 100 Prozent). Die Berichte für 25 % und 100 % wurden aus der Dekodierlogik der Herstelleranwendung abgeleitet; der Endbenutzer bestätigte anschließend, dass die übrigen Stände in der gebauten App korrekt angezeigt werden. Das fünfte Byte ist nicht konstant und wird nicht als Signatur verwendet.

Der Listener benötigt zwei übereinstimmende dekodierte Akkustufen statt zweier identischer Gesamtberichte. Der zuletzt bestätigte Wert wird bis zu 45 Sekunden lang beibehalten. Das globale Intervall für die automatische Aktualisierung wechselt auf 15 Sekunden.

Vom Endbenutzer unter Windows mit ARDOR Fury V2 und Logitech G733 validiert: Mitschnitte bei 50 % und 75 %, periodische automatische Aktualisierung, Sichtprüfung bei 25 % / 100 % sowie portabler Start. Die Berichte für 25 % und 100 % wurden nicht direkt mitgeschnitten.


---

<a id="sec-areson"></a>
> 📄 **Abschnitt:** Areson `25A7` (`docs/areson.md`) · [Englisches Original](../../docs/areson.md) · [↑ Nach oben](#top)

# Areson 25A7 Empfänger Akkuunterstützung

## Warum das ursprüngliche Programm die Maus übersah

Die Redragon M915RGB-WL verbindet sich über einen Areson/CompX-`25A7:FA07` „2.4G Wireless Receiver“. Ihr Akkustand wird nicht als standardmäßige HID-Usage *Battery Strength* bereitgestellt, und Windows führt dafür keine Bluetooth-Akkueigenschaft, da es sich um eine proprietäre 2,4-GHz-Funkverbindung handelt. Stattdessen beantwortet die Maus eine aktive `GetPower`-Anfrage, sodass weder der generische HID-Fallback noch der Bluetooth-Fallback sie erkennen konnte. Da kein Treiber für den Hersteller vorhanden war, blieb der Empfänger unbeansprucht und stumm.

## Beobachtete Hardware und Pakete

Getestet unter Windows 11 mit einer Redragon M915RGB-WL am 2026-11-17:

| Richtung | VID:PID | Schnittstelle | Usage Page:Usage | Berichtsgröße |
|---|---|---|---|---|
| Anfrage (Feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 Bytes |
| Antwort (Input) | `25A7:FA07` | 1 | `FF01:0000` | 17 Bytes |

Die Antwort trifft auf einer anderen Top-Level-Sammlung ein als die, an die die Anfrage geschrieben wird. Unter Windows sind dies `MI_01&COL07` (Feature) und `MI_01&COL05` (Input), weshalb der Treiber beide Handles öffnet.

Mitgeschnittene Anfrage (`GetPower`, Report-ID `08`, Befehl `04`, Prüfsumme ergänzt den Frame auf Summe `0x55`):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Mitgeschnittene Antwort:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Die folgenden Offsets zählen die Report-ID als Byte null:

| Byte(s) | Bedeutung | Beispiel |
|---|---|---|
| 0 | Antwort-Report-ID | `09` |
| 1 | Befehlsecho | `04` |
| 2 | Status, 0 = OK | `00` |
| 3–4 | Adresse, bei `GetPower` ungenutzt | `00 00` |
| 5 | Datenlänge (2) | `02` |
| 6 | Akkustand, 0–10, in 10-%-Schritten | `08` = 80% |
| 7 | Ladeflag, jeder Wert ungleich null | `00` = lädt nicht |
| 16 | Prüfsumme; alle 17 Bytes ergeben zusammen `0x55` (mod 256) | `3E` |

Die eigene Software des Herstellers zeigte für denselben Frame 80 % an, was die Skalierung mit ×10 belegt. `GetConnectStatus` (`08 03 …`) antwortet mit 1 Byte Nutzlast und meldete die Maus gleichzeitig als verbunden.

## Andere Areson-Mäuse

Die älteren Empfänger `FA7B` / `FA7C`, die von der Redragon M693 verwendet werden, melden die Ladung direkt als ganzen Prozentwert an demselben Antwort-Offset. Die ×10-Skalierung dieses Treibers würde dort 800 % anzeigen, daher werden diese Produkt-IDs bewusst nicht beansprucht. Es werden nur `FA07` und `FA08` verarbeitet; `FA08` ist die alternative Kennung derselben Familie und wurde auf dieser Maschine nicht verifiziert.

## Abfrage und Identität

- Der Treiber sendet ausschließlich die schreibgeschützte `GetPower`-Anfrage. Er schreibt niemals Konfigurations-, Beleuchtungs- oder DPI-Daten.
- Jede Aktualisierung öffnet die Feature-Sammlung ohne Schreibzugriff (Zero-Access) und die Input-Sammlung zum Lesen, sendet die Anfrage und wartet bis zu 1,8 s auf eine Antwort – mit zwei Versuchen und einer Warteschlangen-Leerung dazwischen, damit kein veralteter Bericht mit der Antwort verwechselt wird.
- Ein fehlgeschlagener Lesevorgang beansprucht nichts, sodass eine schlafende Maus den letzten Wert in der Oberfläche behält. Der Eintrag verwendet wie die anderen passiven Treiber eine Nachlaufzeit von 30 Minuten.
- Der Geräteschlüssel wird aus Hersteller- und Produkt-ID abgeleitet (`areson:25A7:FA07`), sodass er Empfangs-/Ruhezyklen und ein erneutes Einstecken des Empfängers übersteht.

## Validierung

Die vollständige Anwendung wurde mit MSVC C++17 und dem Windows SDK gebaut und gegen die echte Maus ausgeführt. `BatteryHub.exe --list` lieferte:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

Der Messwert stimmte im selben Moment mit dem Prozentwert der offiziellen Redragon-Software überein. Die MinGW-Datei `build.bat` bindet die neue Quelldatei ein; das `Makefile` erkennt sie über seinen Platzhalter automatisch.

## Protokollquellen

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): 17-Byte-Frames, Feature-/Input-Aufteilung und die `0x55`-Prüfsummenregel, rekonstruiert aus USB-Mitschnitten der Redragon-Software.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): `GetPower`-Befehl und die 10-%-Skalierung bei `25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md): Antwortlayout und die abweichende Prozentskalierung bei der `FA7B`- / `FA7C`-Familie.


---

<a id="sec-darkrim"></a>
> 📄 **Abschnitt:** DARKRIM SHADOW (`docs/darkrim.md`) · [Englisches Original](../../docs/darkrim.md) · [↑ Nach oben](#top)

# DARKRIM SHADOW / 寸渊影弑 Empfänger

Hardwaregetestet an `3654:6901`, Hersteller `Jieli Technology`, Release `0100`. Verwendet Schnittstelle **3**, Usage `FF02:0002`, unnummerierte 64-Byte-Input-/Output-Nutzlasten (65-Byte-Windows-HID-Berichtsgrößen). Schnittstelle 4 besitzt ebenfalls `FF02:0002`, verwendet jedoch Report-ID 2 und antwortete nicht auf dieses Protokoll; sie wird bewusst ausgeschlossen.

Protokollquelle: der offizielle [PC-Hub-Download](https://app.darkrim.net/hub/zh.html), `DARKRIM-0.1.26-x64-setup.rar`, heruntergeladen und statisch entpackt, ohne die Hersteller-Software zu installieren oder zu starten. SHA-256 der extrahierten `DARKRIM.exe`: `f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Nützliche Adressen in dieser Binärdatei:

- `140124C80`: `sendGetBasicInfo(infoType)` sendet Befehl `0010`, Request `01`, Nutzlast `[infoType, 00]`. Der Akku-Selektor ist `01`.
- `140118D30`, `140119200`: Frame-Header- und CRC-Erzeugung.
- `140126DB0`: Geräteinfo-TLV-Parser; TLV `01` ist der Akku.
- `1400F5660`, `1400FA700`: Akku-Verbraucher; die unteren sieben Bits geben den Prozentwert an, das höchste Bit steht für das Laden. Derselbe Akkuwert trifft auch in `0011` Notify `03` ein.

Header: `FE seq cmdLE type index count lengthLE`, gefolgt von Nutzlast und CRC-16/CCITT-FALSE (Polynom `1021`, Startwert `FFFF`, Big-Endian gespeichert). Die Sequenz ist ein vierbittiger Zähler ungleich null; Verschlüsselung wird nicht verwendet.

Tatsächliche Anfrage-/Antwortnutzlasten vor dem Auffüllen mit HID-Nullen:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

Das Antwort-TLV `01 01 28` ergibt **40 %, lädt nicht**. Der produktive C++-Treiber gab diesen Wert bei drei aufeinanderfolgenden Abfragen ohne Hersteller-Software zurück. Der Empfänger sendet vor der passenden Antwort Startbenachrichtigungen, gemessen nach rund 406 ms. Es wird ein einziges Antwortzeitlimit von 800 ms verwendet (plus höchstens 200 ms zum Schreiben), ohne es bei unzusammenhängenden Benachrichtigungen neu zu starten. Ein Heartbeat ist nicht erforderlich.

Der Treiber sendet ausschließlich das Akku-GET. Er akzeptiert nur eine unverschlüsselte Antwort mit passender Sequenz/Befehl/Typ, Index null, Count null oder eins (die Hardware nutzt null), gültiger Länge/CRC und einem einzigen wohlgeformten Akku-TLV. Fragmentierte, unaufgeforderte, fehlerhafte und außerhalb des Bereichs liegende Antworten werden verworfen.

## Beobachtete Akkugenauigkeit und Ladestatus

Behandle den Prozentwert als **grobe Schätzung, nicht als verifizierte Anzeige mit 1-%-Auflösung**. Das Gerät des Besitzers zeigte den Ladefortschritt in 10-Prozentpunkt-Schritten von 40 % bis 90 %. Bei 90 % enthielten fünf Akku-GET-Antworten und eine unaufgeforderte Benachrichtigung allesamt `DA`: `DA & 7F = 90`, wobei Bit 7 das Laden anzeigt. Nachdem der Besitzer das Ladekabel abgezogen hatte und den 2,4-GHz-Empfänger weiter verwendete, enthielten weitere fünf GET-Antworten und eine Benachrichtigung allesamt `5A`: weiterhin 90 %, nun mit gelöschtem Ladebit. Alle zwölf Frames bestanden die CRC-Prüfung.

Repräsentative Abfrageantworten (Sequenz 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Sowohl der Treiber als auch die offizielle Anwendung entnehmen den Prozentwert direkt den unteren sieben Bits. Der Treiber rundet nicht auf Zehner, multipliziert keine Stufe mit zehn und interpoliert keine Zwischenwerte; synthetische Berichte mit 47 % und 95 % bleiben im Produktiv-Parser 47 % und 95 %. Die beobachteten groben Werte entstehen daher bereits vor dem Parser in der Meldung des Headsets/Empfängers. Feinere Hardware-Messwerte wurden nicht beobachtet. Eine vollständige Entladekurve wurde nicht aufgezeichnet, sodass ein fester 10-%-Schritt auf jedem Entladelevel oder auf anderer Firmware unbestätigt ist.

Laden und nachfolgender Nicht-Ladezustand bei 90 % wurden auf Hardware geprüft. Unter-/Obergrenzen (niedrig/voll), das Verhalten beim Ausschalten des Headsets, Bluetooth und der USB-Kabel-Datenmodus wurden nicht auf Hardware getestet. Für diese Betriebsarten wird kein Unterstützungsanspruch erhoben. In dieser Implementierung sind keine Firmware-Updates, Konfigurationsänderungen, EQ-Befehle, Kopplungsänderungen, Resets oder Hersteller-Binärdateien enthalten.

Test: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Abschnitt:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [Englisches Original](../../docs/hyperx_haste_2.md) · [↑ Nach oben](#top)

# HyperX Pulsefire Haste 2 Wireless Akkuprotokoll

Ausgelesen durch `HasteWireless` in `src/drivers/hyperx.cpp`. Die Abfragen stammen aus [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) und entsprechen denen von NGENUITY.

Auf Hardware verifiziert:

- Pulsefire Haste 2 Core Wireless, Dongle `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, Dongle `03F0:0F98`, von uzumakiprime (PR #312). Der Stand stimmte mit HyperX NGENUITY überein.

Der Dongle `03F0:0D97` dürfte identisch funktionieren, ist jedoch ungetestet.

## HID-Sammlung

| Feld | Wert (`0F98`) |
|---|---|
| USB-Schnittstelle | `MI_02` (Schnittstelle 2) |
| Usage Page : Usage | `FF00:0001` |
| Input- / Output- / Feature-Berichtslänge | 64 / 64 / 64 Bytes |

Der Dongle stellt außerdem die Standard-Sammlungen für Maus und Consumer-Control bereit. Der Treiber öffnet ausschließlich eine Herstellersammlung (Usage Page `FF00` oder höher) mit Input-Berichten von mindestens 8 Bytes.

## Abfragen

Beide sind Output-Berichte: die ersten beiden Bytes wie unten, bis zur Berichtslänge mit Nullen aufgefüllt. Jede Antwort ist ein Input-Report, dessen erstes Byte gleich dem Befehl plus eins ist. Jede Abfrage wartet höchstens eine Sekunde auf ihre Antwort und überspringt unzusammenhängende Berichte (nach einer Wiederverbindung sendet der Dongle von sich aus `44 xx`, `45 xx` und `FB xx` Berichte).

| Anfrage | Antwort | Bedeutung |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0, wenn die Maus ausgeschaltet oder außer Reichweite ist |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0–100; `charge` 1 = lädt, 2 = voll am Ladegerät; Spannung in mV, Little-Endian (0 bei der Core) |

- Fehlt die Verbindungsantwort, entscheidet die Akkuantwort.
- Meldet die Verbindung 0, wird keine Akkuabfrage gesendet und die Maus als ausgeschaltet angezeigt.
- Für einige Sekunden nach dem Einschalten der Maus meldet sie etwa 40 %. Ein Messwert innerhalb von 6 s nach Verbindungsaufbau wird verworfen, und das Infobereich-Menü behält den letzten Wert.

Beide Anfragen lesen ausschließlich den Status. Nichts verändert Einstellungen, Beleuchtung oder Modi.


---

<a id="sec-inphic"></a>
> 📄 **Abschnitt:** Inphic IN10 (`docs/inphic.md`) · [Englisches Original](../../docs/inphic.md) · [↑ Nach oben](#top)

# Inphic IN10-Familie, KP 8K Empfänger

Das angeschlossene Gerät, von seinem Besitzer als IN10 MAX identifiziert, meldet sich als `Inphic KP 8K`, `1D57:FA65`, Release `0116`. Seine Statussammlung ist Schnittstelle 2, Usage `000A:0000`, Input-Länge 5 (einschließlich Report-ID 03).

Etwa alle vier Sekunden ohne Senden einer Anfrage beobachtet:

```text
03 73 41 01 64
```

Der bestehende Xenta-Parser erkennt dieses Format: Modell, Ereignis, Akkuzustand, Prozentwert. Vor der Anzeige von 100 % sind zwei gleiche Berichte erforderlich; der erste Bericht nach dem Verbinden kann auf verwandten Empfängern ein irreführender Voll-Wert sein. Diese Änderung behält jene Schutzmaßnahme sowie das bestehende Lade- und Ruhemodus-Verhalten bei.

Das offizielle [Inphic-HUB](https://hub.inphic.cn/)-Bundle `assets/index-BcHQx9B6.js` ordnet Modell dezimal 115 (`73`) der `IN10RMax` und 116 (`74`) der `IN10Max` zu. Es nutzt Akkuzustand 1 für Prozentwert, 2 für voll und 3 für ladend. Verwende den Modellnamen aus der Firmware, statt `73` pauschal der IN10 MAX zuzuordnen und möglicherweise andere Geräte an demselben Empfänger falsch zu beschriften.

Vor dieser Änderung führte die App die angeschlossene Maus als `Wireless mouse`. Der Xenta-Transport verarbeitete ihre Akkuframes bereits; die Änderung ergänzt die fehlenden Modellnamen. Ein direktes `--list` kann den Ruhezustand melden, da das fünfsekündige anfängliche Beobachten unter Umständen nur einen einzigen Vier-Sekunden-Bericht empfängt. Die dauerhaft laufende App behält den Listener bei und bestätigt den Wert bei einer späteren Abfrage.

Auf Hardware verifiziert: passive Berichte, wiederholter 100-%-Stand und native Treiber-Modellkennung. Ladeübergänge, Schwellenwerte bei niedrigem Akku, Bluetooth- und Kabelmodus wurden nicht verifiziert. Modell `74` stammt aus der offiziellen Tabelle und wurde nicht an separater Hardware getestet.


---

<a id="sec-machenike"></a>
> 📄 **Abschnitt:** Machenike L7 (`docs/machenike.md`) · [Englisches Original](../../docs/machenike.md) · [↑ Nach oben](#top)

# Machenike L7 Arctic / L7 Mix

Verifiziert an einer L7 Arctic, die sich als **L7 Mix** identifiziert:

| Verbindung | VID:PID | Schnittstelle | Usage | Input / Output / max. Feature |
| --- | --- | --- | --- | --- |
| 2,4-GHz-Empfänger | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB-Kabel | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

Der Treiber prüft außerdem den HID-Produktnamen `L7 Mix`. Andere Machenike-Modelle, abweichende Empfänger-IDs und Bluetooth-Herstellerabfragen sind nicht aktiviert.

## Protokollquelle

Interoperabilitätsanalyse der offiziellen Software **Machenike L7 Mix 1.0.0.8**, verfügbar auf der [Treiber-Seite des Herstellers](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/), sowie schreibgeschützte Abfragen an der echten Maus. SHA-256 von `DeviceDriver.exe`: `A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

In dieser 32-Bit-Ausführungsdatei (Image Base `00400000`) erstellt die Funktion bei VA `00436750` die Statusanfrage; `004494F0` sendet sie über `HidD_SetFeature` und liest die Feature-Antwort ein. Der Status-Parser `00410C20` extrahiert die unten stehenden Felder und reicht Akku- und Ladefeld an die Oberfläche weiter. Dies sind virtuelle Adressen, keine Datei-Offsets. Hier sind keinerlei proprietäre ausführbare Dateien, Anwendungscode oder Ressourcen enthalten.

## Abfrage zum Auslesen des Status

Sende **21 Bytes**, Report-ID `51`, Befehl `06`, alle übrigen Bytes null:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Lies Feature-Report `51`, ebenfalls mit 21 Bytes. Die maximale Feature-Größe der Sammlung beträgt 1001 für andere Berichte; sie ist nicht die Länge des Statusberichts. Der Treiber wartet vor dem Lesen 10 ms und verwendet ein einziges Zeitlimit von 200 ms pro Produkt, einschließlich unzusammenhängender Antworten. Er sendet keine Einstellungs-, Modus-, Makro- oder Firmware-Befehle.

Indizes schließen die Report-ID mit ein:

| Bytes | Bedeutung / beobachtete Werte |
| --- | --- |
| 0–1 | `51 06`, erforderliches Befehlsecho |
| 4–7 | `8A 24 4E FF`, die verifizierte L7-Gerätesignatur |
| 10, Bits 0–2 | Betriebsmodus: 1 am Empfänger, 0 am Kabel |
| 10, Bit 3 | Funkmaus verbunden; auch am USB-Kabel gelöscht |
| 11 | Akkuprozentwert, 0–100 (null ist gültig) |
| 12 | Ladeflag: 0 entlädt, 1 lädt |

Weitere Felder und die Prüfsummensemantik sind nicht geklärt. Der Treiber erfindet keine Prüfsumme. Er validiert Befehl, Länge, Gerätesignatur, Modus und die Akku-/Ladebereiche im verbundenen Zustand, bevor er einen Messwert veröffentlicht.

Mitgeschnittene Empfängerantwort, in der offiziellen App ebenfalls 64 %:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Mitgeschnittene USB-Kabelantwort beim Laden (74 %):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

Zu diesem Zeitpunkt gab der Empfänger weiterhin seine zwischengespeicherten 64 % zurück, löschte jedoch sein Verbindungsbit:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Dieser getrennte Messwert darf keine zwischengespeicherten Akku-/Ladewerte preisgeben. Das Kabel hat Vorrang, wenn beide Übertragungswege vorhanden sind, und der stabile Geräteschlüssel wird transportübergreifend geteilt. Eine bekannte L7 wird selbst bei fehlgeschlagener Abfrage reserviert, damit der spätere Ajazz-Treiber sie auf der gemeinsam genutzten VID nicht mit einem anderen Protokoll abfragen kann.

## Validierungsgrenzen

Fixtures und simulierte Transporttests decken mitgeschnittene Messwerte, Laden, gültige 0 % / 100 %, getrennte Empfänger, fehlerhafte/veraltete Antworten, strikten Abgleich, Transportfehler, Duplikatunterdrückung und begrenzte Wiederholungsschleifen ab. Echtes 0 % / 100 % am Gerät sowie sämtliche Ruhemodus-/Firmware-Varianten sind durch diese Tests nicht abgedeckt.


---

<a id="sec-nuphy"></a>
> 📄 **Abschnitt:** NuPhy WH80 (`docs/nuphy.md`) · [Englisches Original](../../docs/nuphy.md) · [↑ Nach oben](#top)

# NuPhy WH80 (USB-Kabel und Bluetooth)

Hardwaregetestet mit `19F5:A011`, Firmware-Version `0116`, Schnittstelle 1, Usage `0001:0000`, unnummerierte 64-Byte-Input-/Output-Nutzlasten (65 Bytes in den Windows-HID-Capabilities).

Protokollquelle: [NuPhyIO](https://drive.nuphy.io/), Bundle `main.b3fb29e0.js`, SDK `getBatteryState(0)`, `getDataPackage` und `createCommand`. Es wird ausschließlich `GetFunc` (`05`), Offset `0020`, Länge `01` angefordert. Es sind keine Initialisierungs-, Konfigurations-, Beleuchtungs- oder Firmware-Befehle erforderlich.

Anfrage-Nutzlast, mit Nullen auf 64 Bytes aufgefüllt:

```text
55 05 00 21 01 20 00 00
```

Tatsächliche Antwort-Nutzlast:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

Byte 3 ist das untere Byte der Summe der Bytes 4..63. Der Akku steht in Byte 8: `value & 7F` ist der Prozentwert, `value & 80` ist das SDK-Ladeflag. Der native C++-Treiber gab an der angeschlossenen Tastatur **100 %, lädt** zurück. Ladeübergänge sowie Unter-/Obergrenzen (niedrig/voll) wurden nicht auf Hardware getestet; die offiziellen Firmware-Hinweise beschreiben WH80-Messwerte in 10-%-Schritten. Der Betrieb über den Empfänger liegt außerhalb des Umfangs dieses Treibers.

## Bluetooth

Über Bluetooth verwendet dieselbe Tastatur die HID-ID `19F5:324A` (Release `0129`) und kündigt einen für den Benutzer sichtbaren Namen wie `NuPhy WH80 - 1` an. Sie stellt zwei Tastatursammlungen und eine Maussammlung bereit. Die generische HID-Heuristik priorisiert Mäuse, daher wird diese exakte Bluetooth-ID den bestehenden Tastatur-Überschreibungen hinzugefügt.

Die Akkumeldung nutzt weiterhin die Windows-Bluetooth-Akkueigenschaft. Nach dem Abziehen des USB-Kabels meldete Windows an der angeschlossenen Tastatur **95 %**. Ein ungepuffertes Auslesen des standardmäßigen GATT Battery Level (`180F` / `2A19`) direkt von der Tastatur ergab ebenfalls **95 %**. Dies ist ein eigenständiger Geräte-/Transport-Messwert gegenüber der kabelgebundenen 100-%-Beobachtung; er darf nicht durch einen angenommenen Vollwert ersetzt oder neu skaliert werden. Der Grund für die unterschiedlichen Firmware-Messwerte ist nicht geklärt.

Der Treiber prüft exakt Produkt-/Schnittstellen-/Berichtsgrößen, Antwort-Header, Offset, Länge, Prüfsumme und Prozentbereich. Er verwendet ein Antwortzeitlimit von 400 ms und ignoriert unzusammenhängende Antworten innerhalb desselben Zeitlimits.

Regressionstest:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Abschnitt:** Rapoo (`docs/rapoo.md`) · [Englisches Original](../../docs/rapoo.md) · [↑ Nach oben](#top)

# Rapoo-Maus-Akkuunterstützung

## Warum das ursprüngliche Programm die Maus übersah

`PollAllDevices()` zählt pro Aktualisierung einmal die Windows-HID-Top-Level-Sammlungen auf. Jeder Herstellertreiber erkennt ein Protokoll, fügt ein `DeviceStatus` hinzu und beansprucht seine VID/PID, sodass die generischen Treiber das Gerät nicht ein zweites Mal hinzufügen. Die Oberfläche verarbeitet bereits Prozentwerte, Ladestatus und den letzten Messwert im Ruhezustand.

Es gab keinen Rapoo-Treiber. Die VT3 Max Gen 2 sendet ihren Akkustand in einem herstellerspezifischen Input-Report und nicht über die standardmäßige HID-Usage *Battery Strength* oder eine Windows-Bluetooth-Akkueigenschaft. Die bestehenden generischen HID-/Bluetooth-Fallbacks können ihren USB-Empfänger daher nicht dekodieren.

## Beobachtete Hardware und Pakete

Getestet unter Windows mit der VT3 Max Gen 2 des Besitzers am 2026-11-16:

| Verbindung | VID:PID | Schnittstelle | Usage Page:Usage | Input- / Output-Größe |
|---|---|---|---|---|
| 2,4-GHz-Empfänger | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 Bytes |
| USB-Kabel | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 Bytes |

Beide melden sich als `Rapoo Gaming Device`. Zu den weiteren Sammlungen gehören Standard-Maus-, Tastatur- und Medieneingaben, Hersteller-Konfigurationssammlungen sowie eine 513-Byte-Firmware-Schnittstelle. Der Akkutreiber öffnet ausschließlich `FF00:0002` mit einer erkannten Input-Größe. Er öffnet niemals die Firmware-Schnittstelle und sendet niemals einen Output-Report, Feature-Report, Handshake oder Konfigurationsbefehl.

Mitgeschnittener Funkbericht, einschließlich Report-ID:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Mitgeschnittener Kabel-/Ladebericht:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Die folgenden Offsets zählen die Report-ID als Byte null, passend zu `HidDev::Read()` dieses Projekts:

| Byte(s) | Bedeutung | Beispiel |
|---|---|---|
| 0 | Report-ID | `07` |
| 1 unteres Nibble | Verbindung: 0 Empfänger, 1 Bluetooth, 2 Kabel | `20` / `22` |
| 1 oberes Nibble | Sensorinformation; kein Teil des Verbindungstyps | `2` |
| 2 | Aktuelle DPI-Stufe | `03` |
| 3–4, 5–6 | X/Y-DPI, Little-Endian | `0320` = 800 |
| 7 | Akkustatus: 0 ungültig, 1 entlädt, 2 lädt | `01` / `02` |
| 8 | Akkuprozentwert, 0–100 | `19` = 25% |
| 13–14 | Maus-Produkt-ID, Little-Endian, falls vorhanden | `4617` |

Der Live-Mitschnitt am Empfänger meldete `25%`, und die vollständige Anwendung lieferte anschließend `27%, charging` über das Kabel. Der Parser-Test enthält den tatsächlichen Funkmitschnitt. Lade- und Kabelverbindung wurden ebenfalls gegen echte Hardware verifiziert; sie werden nicht bloß aus dem Vorhandensein eines USB-Geräts abgeleitet. Nachdem der Besitzer das Kabel getrennt und den Empfänger wieder angeschlossen hatte, lieferte die fertige Programmdatei `52%` über `2.4 GHz receiver` ohne Ladeflag und behielt denselben Schlüssel `rapoo:4617`. Dies verifiziert auch den Übergang von Kabel zu Empfänger an echter Hardware.

Ebenfalls unter Windows getestet mit einer **VT9 Gen 2** am 2026-11-17:

| Verbindung | VID:PID | Schnittstelle | Usage Page:Usage | Input- / Output-Größe |
|---|---|---|---|---|
| 2,4-GHz-Empfänger | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 Bytes |
| USB-Kabel | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 Bytes |

Der VT9-Gen-2-Empfänger stellt einen **16-Byte**-`FF00:0002`-Bericht statt 19 Bytes bereit, nutzt dabei aber exakt dasselbe Nordic-54L-`07`-Layout (einschließlich der eingebetteten `4614`-PID an den Bytes 13–14). Mitgeschnittene Frames:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

Über das USB-Kabel wurden Statusberichte bei Interaktion (z. B. DPI-Wechsel) beobachtet; bei ausgeschaltetem unterem Netzschalter im eingesteckten Zustand meldete die Maus `state=2, percent=1` statt des tatsächlichen Akkuprozentwerts.

### VT3 Max Gen 2 Empfänger mit einer 13-Byte-Sammlung (Issue #1396)

Ein Geräteanfrage-Bericht für dieselbe Empfänger-ID `24AE:1417` führte ein anderes Schnittstellenlayout auf: `FF00:0002` mit **13 / 13** Bytes (statt 19) sowie `FF00:000E` mit 33 / 33 Bytes, ohne 513-Byte-Firmware-Sammlung. Dies deutet auf eine andere Empfänger-Firmware-Revision hin. Die Rapoo-Software zeigte den Akku weiterhin an, daher ignorierte der Treiber bis dahin einen funktionierenden Statuskanal.

Der `VT_nrf54L`-Decoder (`py`) von Rapoo Hub ist längenadaptiv: Er liest stets DPI, Akkustatus und Prozentwert und wertet die späteren Felder (Maus-PID bei `n[12..13]`, RF-Infos …) nur dann aus, wenn der Bericht lang genug ist. Das Manifest der VT3 MAX (`productId: [17943, 5143]`) besitzt keinen speziellen Input-Report-Typ, sodass Report `07` auch auf diesem Empfänger durch jenen Decoder läuft. Ein 13-Byte-Bericht (ID plus 12 Bytes) trägt Status in Byte 7 und Prozentwert in Byte 8 weiterhin mit sich; lediglich die eingebettete Maus-PID fehlt, daher verwendet der Messwert die Empfänger-PID und behält den Schlüssel `rapoo:4617`.

Die 13-Byte-Länge wird **ausschließlich für `24AE:1417`** akzeptiert. Frames müssen weiterhin dieselben Prüfungen bestehen (Report `07`, Verbindungsnibble 0–2, Status 1/2, Prozentwert 0–100). Bisher wurde noch kein Live-13-Byte-Frame mitgeschnitten; die Tests verwenden den getesteten, auf 13 Bytes gekürzten 19-Byte-Mitschnitt.

## Andere Rapoo-Mäuse

Der offizielle Rapoo Hub verwendet dieses `07`-Layout für seinen Nordic-54L-Maustreiber. Seine Manifeste listen VT0, VT1, VT2, VT3, VT3S, VT7, VT9 und weitere Varianten auf. Eine Prüfung des aktuellen Bundles ergab 69 VT-Varianten mit `VT_nrf54L`; dies belegt ein gemeinsames Protokoll, nicht jedoch 69 Hardware-Validierungen oder den Anspruch, den Großteil des gesamten Rapoo-Katalogs abzudecken. Die Unterstützung wird über die Rapoo-VID, die zugehörige Sammlung, die Input-Länge und einen gültigen Statusbericht gewählt, sodass auch ein nicht gelistetes Modell mit demselben Protokoll seinen Akku melden kann. Eine kleine Namenstabelle deckt gängige Modelle ab; andere behalten ihren HID-Produktnamen oder zeigen `Rapoo wireless mouse`.

Produktnamen und -IDs variieren über Generationen und Regionen hinweg. Das getestete Paar `1417/4617` heißt im aktuellen offiziellen Manifest `VT3 MAX`; der Besitzer identifiziert es als VT3 Max Gen 2. Die separate `VT3 MAX V2` im aktuellen Manifest trägt die IDs `1B06/4B06`. Community-Tabellen, die `1417` der VT9 Pro zuweisen, dürfen nicht als alleinige Grundlage zur Benennung oder Erkennung dieses Geräts herangezogen werden.

Ältere VT-Firmware, dokumentiert für die VT3 Pro (`1215/4415`), sendet stattdessen einen 7-Byte-Bericht auf derselben Usage `FF00:0002`:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

Bei diesem Legacy-Format bedeuten die Zustände 1/2 entladen/laden. Ein Ladeprozentwert von `7F` bedeutet unbekannt und bleibt als unbekannt erhalten. Übergangszustand 0, unzusammenhängende `BC`-Berichte, fehlerhafte Pakete und Prozentwerte über 100 werden verworfen. Die Legacy-Unterstützung verfügt über automatisierte Testabdeckung, wurde hier jedoch nicht mit einer physischen Legacy-Maus verifiziert. Diese Auslegung ist auf die Produkt-IDs `1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) und deren 7-Byte-Input-Sammlung beschränkt.

Die VT1 Pro Max (Empfänger `24AE:1233`, Kabel `24AE:4433`, Maus-Firmware 222, Dongle-Firmware 213) wurde anhand von USBPcap-Mitschnitten hinzugefügt, die ihr Besitzer an Issue #136 angehängt hatte. Die `--dump`-Ausgabe listet die 7-Byte-Sammlung `FF00:0002` auf Schnittstelle 1 auf, und die Mitschnitte zeigen, wie sie ohne Anfrage der Rapoo-App sendet:

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

Am Kabel wurde der Bericht in einem 16-Sekunden-Mitschnitt nur einmal beobachtet, sodass eine reine Kabelmessung bei manchen Aktualisierungen in ein Timeout laufen kann; der Empfänger sendet ihn regelmäßig. Das Nordic-Profil interpretiert niemals `BB`-Pakete.

Dies begründet **keine** Unterstützung für jedes Rapoo-Gerät. CH584-Modelle wie VT1 SE und VT7 SE verwenden im offiziellen Treiber Report `08` und werden von diesem Decoder nicht unterstützt. Andere Telink-Revisionen nutzen eine abweichende Bedeutung der `BB`-Flags, manche Büro-Modelle verwenden aktive Akkuabfragen, und Bluetooth-Modelle stellen womöglich nur die Windows-Akkueigenschaft bereit. Diese verbleiben bei den bestehenden Fallbacks oder erfordern eine eigene verifizierte Implementierung. Sende niemals geratene Abfragen an sie.

## Abfrage und Identität

- Das Auslesen erfolgt passiv. Passende `FF00:0002`-Handles bleiben zwischen Abfragen geöffnet (entsprechend `PollXenta`), sodass Windows während des 60-Sekunden-Aktualisierungsintervalls eintreffende Statusframes puffert; jede Abfrage leert alle eingereihten Frames (und behält den neuesten gültigen Akkumesswert), bevor beim ersten Öffnen oder leerer Warteschlange ein 5-Sekunden-Warten greift. Abgesteckte Geräte werden entfernt und ihre Handles geschlossen. Unzusammenhängende Pakete starten das Zeitlimit nicht neu.
- Die eingebettete Maus-PID oder ein bekanntes Kabel-/Empfänger-Paar bei Legacy-Geräten liefert über Kabelwechsel hinweg denselben UI-Schlüssel. Kabel- und Empfänger-Messwerte werden zu einem Eintrag zusammengeführt, wobei der Kabelzustand bevorzugt und ein gültiger Empfänger-Prozentwert beibehalten wird, falls das Kabel einen unbekannten Stand meldet.
- Ein Timeout erfindet keinen Prozentwert und beansprucht das Gerät nicht. Nach einem erfolgreichen Auslesen kann die bestehende Oberfläche diesen Messwert bis zu 30 Minuten Stille abgeblendet beibehalten.
- Das bestehende VID/PID-basierte Identitätsmodell des Programms kann mehrere identische Mäuse mit derselben Modell-ID nicht unterscheiden. Physisch gleichzeitiger Kabel-/Empfänger-Betrieb wurde nicht getestet; das Zusammenführen beider Eingaben ist durch den simulierten Transporttest abgedeckt.

## Validierung

`make test` führt einen portablen Decoder-Test sowie einen Windows-Treibertest mit simulierten HID-Antworten aus. Abgedeckt sind der echte Mitschnitt, 0 % und 100 %, Laden, fehlende Stände, ungültige/abgeschnittene Frames, nicht unterstützte Sammlungen/Hersteller, Trennung der Protokollprofile, Timeouts, stabile Schlüssel sowie Kabel-/Empfänger-Deduplizierung ohne Verwerfen eines bekannten Prozentwerts.

Die vollständige Anwendung wurde lokal mit MSVC C++17 und dem Windows SDK gebaut, und `--list` / `--dump` wurden gegen die echte Maus ausgeführt. Der gepflegte MinGW-Build bindet `rapoo.cpp` in `build.bat` ein; das Makefile erkennt sie automatisch. MinGW selbst war in der Testumgebung nicht installiert.

## Protokollquellen

- [Offizieller Rapoo Hub](https://hub.rapoo.cn/), untersucht am 2026-11-16: gebündelter [JavaScript-Treiber und Manifeste](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js). Relevante Decoder sind `py`/`Hk` für `VT_nrf54L` sowie `qM`/`QM` für die Bedeutung von Verbindung und Akkuzustand. Der separate `VT_CH584`-Handler verarbeitet Report `08` und liegt außerhalb dieser Implementierung. Minifizierte Namen können sich in künftigen Versionen ändern.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs), für Legacy-VT3-Pro-Berichte, Ladestatus und den Sentinel für unbekannten Stand.
- Issue #136 USBPcap-Mitschnitte (VT1 Pro Max am Empfänger und am Kabel beim Laden).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js) bestätigt unabhängig die passiven `07`-Status-Broadcasts und den Akku-Offset. Dessen Parser begrenzt ungültige Prozentwerte per Clamping; diese Implementierung lehnt sie stattdessen ab.


---

<a id="sec-rawm"></a>
> 📄 **Abschnitt:** RAWM (`docs/rawm.md`) · [Englisches Original](../../docs/rawm.md) · [↑ Nach oben](#top)

# RAWM-Protokollhinweise

RAWM-Mäuse (und die SADES Dagger, die dieselbe Plattform teilt) kommunizieren mit der RAWM-HUB-App über eine Hersteller-HID-Sammlung, `FF00:0001`, mit unnummerierten 64-Byte-Input- und -Output-Berichten (65 Bytes mit Report-ID). Die Empfänger und Mäuse verwenden Nordics Hersteller-ID `1915`.

Quelle: die RAWM-HUB-Web-App, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), und ihr Skript `https://hub.miracletek.net/hub/js/library.min.js` (obfuskiert; die Funktions- und Konstantennamen unten stammen direkt aus dem Skript). Die unterstützten Produkt-IDs stammen aus der Gerätetabelle, die die App herunterlädt (`https://www.miracletek.net/game/device.php`). Leviathan V4 GT und NYX60 verwenden Hub Web 3.0 auf VID `373E`, was ein anderes Protokoll ist.

## Pakete

Byte 0 jedes Berichts (nach der Report-ID):

| Obere Bits | Bedeutung |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | die unteren 6 Bits sind eine Nutzlastgröße; die Nutzlast setzt den Ereignisstrom fort |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | Flusssteuerung (freie Puffergrößen); hier ignoriert |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | die unteren 6 Bits sind ein ESB-Kanal; der Rest des Berichts ist ein Paket für diesen Kanal. Die Maus hinter einem Empfänger ist Kanal 0 |

Die Nutzlasten bilden einen Bytestrom von Ereignissen:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## Akku auslesen

Der Treiber wiederholt das Verhalten der App, wenn ein Empfänger verbunden ist (`send_event_query`, `send_event_ping`):

1. An den Empfänger: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), dann Pings `00 84 0E 04 00 00`. Das Gerät sendet nur, solange der Host weiterschreibt, daher pingt der Host. Der Empfänger antwortet mit `CMD_QUERY_RESULT` (`02`) und JSON, z. B. `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. Dieselbe Abfrage und Pings für Kanal 0, vorangestellt mit `C0`. Die Maus antwortet mit einem rund 550 Byte großen JSON-Objekt in 30-Byte-ESB-Blöcken, z. B. `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`. `battery` ist ein Prozentwert (RAWM HUB zeigt ihn unverändert an), `chr` ist 1 während des Ladens.
3. Spätere Änderungen treffen als `CMD_NOTIFY` (`0B`) Typ `17` ein: `[17, percent, charging]`.

Der Treiber fragt genau wie die App stets zuerst den Empfänger ab (in einem Test erhielt eine nur an Kanal 0 gesendete Abfrage keine Antwort). Eine schlafende Maus antwortet überhaupt nicht; der Empfänger antwortet weiterhin.

Die Abfrage übermittelt die PC-Uhrzeit, weil die App sie so sendet; sonst wird nichts geschrieben. Mäuse melden `"crc":1`, was die App anweist, spätere Befehle (Konfiguration) in einen CRC-16-Frame zu verpacken; die Abfrage und Pings werden ohne solchen akzeptiert, da die App sie sendet, bevor sie das weiß.

Getestet an einer Leviathan V4 (Firmware 1.2.0) mit dem RAWM HS Receiver `1915:2346` (Firmware 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **Abschnitt:** VAXEE (`docs/vaxee.md`) · [Englisches Original](../../docs/vaxee.md) · [↑ Nach oben](#top)

# VAXEE 4K/8K Empfänger und ZYGEN NP-01S V2

## Geltungsbereich und Hardware-Validierung

Dieser Treiber unterstützt den VAXEE-4K-Empfänger `3057:1002`, den VAXEE-8K-Empfänger `3057:2002` und die ZYGEN NP-01S V2 Wireless über USB-Kabel (`3057:1011`) auf ihrer Herstellersammlung `FF05:0001` mit einem 64-Byte-Feature-Report. Andere VAXEE-Empfänger, andere Kabel-Produkt-IDs und ZOWIE-Geräte werden bewusst nicht abgefragt.

Der 8K-Empfänger (`VAXEE 8K Wireless`, gekoppelt mit einer NP-01 Ergo Wireless 8K) wurde unter Windows getestet und meldete über dasselbe Protokoll:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

Der Empfänger wird von allen VAXEE-8K-Mäusen gemeinsam genutzt und meldet nicht, welche gekoppelt ist, sodass er unter seinem eigenen Namen angezeigt wird. Der Ladestatus am 8K-Empfänger wurde auf Hardware noch nicht beobachtet.

Ein echter 4K-Empfänger wurde unter Windows getestet:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

Die integrierte Anwendung meldete ebenfalls:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

Dieselbe Maus wurde anschließend direkt per USB verbunden, und Windows erkannte sie als `ZYGEN NP-01S V2 Wireless` (`3057:1011`). Der aktualisierte Produktivtreiber meldete:

```
VAXEE battery: 75%; charging: yes
```

Das Taskleisten-Widget wurde im ersten Empfänger-Build erfolgreich erstellt. Sowohl der Akkubetrieb am Empfänger als auch das Laden am Kabel wurden beobachtet; Übergänge zur Vollladung und Ruhemodus-/Ausschaltverhalten wurden nicht auf Hardware getestet. Die Dekodierung des Ladestatus und ungültige Antworten werden durch simulierte Antworten abgedeckt.

## Protokoll

Quelle: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

Eine Anfrage ist ein mit Nullen aufgefüllter 64-Byte-HID-Feature-Report:

| Byte | Wert |
|---|---|
| 0 | `0E`, Report-ID |
| 1 | `A5`, Header |
| 2 | `0B` für Akkustand; `10` für Ladestatus |
| 3 | `01`, Leseflag (niemals `02`, Schreiben) |
| 4 | `01`, Datenlänge |
| 5–63 | `00` |

Nach dem Senden der Anfrage mit `HidD_SetFeature` 100 ms warten und Report `0E` mit `HidD_GetFeature` lesen. Erforderlich sind mindestens sechs Bytes sowie die erwartete Report-ID, Header, Befehlsecho und Datenlänge.

Beim Akku muss Antwortbyte 5 zwischen 0 und 20 liegen und wird mit fünf multipliziert, was 0–100 % in 5-%-Schritten ergibt. Beim Laden ist Byte 5 ungleich null, sobald geladen wird. Eine fehlgeschlagene Ladeabfrage verwirft keinen ansonsten gültigen Akkumesswert.

Der Treiber wiederholt die Akkuanfrage einmal. Pro passender Sammlung gibt es höchstens drei Leseanfragen (zwei Akkuversuche und eine Ladeabfrage) mit insgesamt 300 ms expliziter Wartezeit. Er sendet keine Einstellungs-, Kopplungs-, Firmware- oder Beleuchtungsbefehle.

Wird keine gültige Akkuantwort empfangen, meldet der Treiber nichts und lässt das Gerät unbeansprucht. Solange die USB-Sammlung vorhanden bleibt, behält die Oberfläche einen zuvor erfolgreichen Messwert bis zu 30 Minuten lang abgeblendet mit ihrem bestehenden Nachlaufzeit-Verhalten. Verschwindet die physische Sammlung, gibt der Treiber einen Status „getrennt“ aus, um diese Nachlaufzeit sofort zu beenden. Dies verhindert, dass ein veraltetes Empfängersymbol bestehen bleibt, wenn das Kabel an die Maus umgesteckt wird.

## Tests

`make test` umfasst `tests/vaxee_driver_test.cpp`, das den Produktivtreiber gegen einen simulierten HID-Transport linkt. Es prüft die exakten ausgehenden schreibgeschützten Anfragen, Prozentumrechnung, Ladedekodierung, ungültige und fehlende Antworten, bereits beanspruchte Geräte und die exakte Sammlungsfilterung.
