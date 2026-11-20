<!--
  Fullständig svensk översättning av dokumentationen för BatteryHub
  Källa: docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Språk:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | **Svenska** | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Lägg till ett språk](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Fullständig dokumentation (Svenska)

> Den här fristående Markdown-filen samlar alla synliga dokument i arkivet så att översättare bara behöver underhålla **en fil per språk**.

## Innehållsförteckning

1. [Översikt över BatteryHub, enheter som stöds, installation, CLI och kompilering (`README.md`)](#sec-readme)
2. [Guide för bidragsgivare (`CONTRIBUTING.md`)](#sec-contributing)
3. [Mall för pull requests (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Guide för utgivning och signering (`docs/releasing.md`)](#sec-releasing)
5. [Patch för Keychron-tangentbordets 2,4 GHz-firmware (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [BLE-stöd för GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Guide för flerspråkighet och lokalisering (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Areson 25A7-mottagare (`docs/areson.md`)](#sec-areson)
10. [DARKRIM SHADOW-mottagare (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K-mottagare (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Batteristöd för Rapoo-möss (`docs/rapoo.md`)](#sec-rapoo)
16. [Protokollanteckningar för RAWM (`docs/rawm.md`)](#sec-rawm)
17. [VAXEE 4K/8K-mottagare (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Avsnitt:** Översikt över BatteryHub (`README.md`) · [Engelskt original](../../README.md) · [↑ Till toppen](#top)

# BatteryHub

*Tidigare **Wireless Battery**. Version 1.1.0 bytte namn på appen; en uppdatering behåller dina inställningar, ditt autostartval och din batterihistorik.*

[![Stöd mig på Ko-fi](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Donera med PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Gå med i vår Discord](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Ge en stjärna på GitHub](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Dela på Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Rapportera en enhet](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Hjälp till att översätta](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Batterinivåer för din trådlösa mus, ditt headset, ditt tangentbord och din spelkontroll direkt i Windows aktivitetsfält.

![BatteryHub i aktivitetsfältet](../screenshot.png)

> **Vill du bara att det ska fungera?** Ladda ned **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** från den senaste versionen, kör programmet och klicka dig vidare. Det är allt.
>
> **Erfarna användare** kan hämta den portabla zip-filen, använda [kommandoradsalternativen](#kommandorad) eller [kompilera det från källkod](#kompilering) med `make` eller `build.bat`.
>
> **Gillar du det?** BatteryHub är gratis och har öppen källkod. Om det sparar dig ett besök i tillverkarens programvara kan du stödja projektet på [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) eller [GitHub Sponsors](https://github.com/sponsors/krisgfx9). Det hjälper mig att hålla mina appar gratis vid sidan av studierna. Kan du inte donera? En ⭐-stjärna, att dela projektet eller att rapportera en enhet som saknar stöd med `--dump` hjälper lika mycket.

- **Litet:** en app på ~350 KB som använder ungefär 2 MB RAM. Det är ren C++/Win32 utan körtidsmiljö eller bakgrundstjänst och installeras på några sekunder utan administratörsrättigheter.
- **Ingen tillverkarprogramvara krävs:** den kommunicerar direkt med enheterna. G HUB, Synapse, iCUE, GG och NGenuity kan hållas stängda (eller vara igång; de krockar inte).
- **Många varumärken:** Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, PlayStation- och Xbox-kontroller, Samsung Galaxy Buds, alla Bluetooth-enheter som Windows känner till batterinivån för och alla headset som medföljande [HeadsetControl](https://github.com/Sapd/HeadsetControl) stöder.

## Visning

**I aktivitetsfältet (standard):** `🎧 30%  🖱 93%` intill meddelandefältet, ritat med Windows ikonteckensnitt.
- **Lågt batteri:** en röd siffra betyder 15 % eller mindre.
- **Laddning:** en blå ⚡ visas bredvid siffran. När enheten är fulladdad och fortfarande ansluten till ström ändras den till en grön ✓.
- **Sover:** nedtonad text betyder att enheten sover och att det senast kända värdet visas.
- **Frånkopplad (valfritt):** aktivera *Visa frånkopplade enheter* för att visa ett nedtonat `×` för enheter vars drivrutin uttryckligen rapporterar att den trådlösa länken är offline. Detta drar inte slutsatsen att en enhet är frånkopplad utifrån en missad batterikontroll; standardläget är fortfarande att dölja frånkopplade enheter.
- **Två enheter av samma typ:** med två möss (eller två kontroller...) skulle båda få samma ikon, så varje enhet får en liten etikett på upp till 3 tecken i hörnet av sin ikon, hämtad från namnet (`MX`, `PRO`), eller en siffra när namnen inte skiljer dem åt. En enhet som är ensam i sin kategori visar ingen etikett.
- **Tema:** följer ljust/mörkt läge och DPI-skalning.
- **Genomskinliga teman för aktivitetsfältet** (t.ex. Windhawks Taskbar Styler): aktivera *Bakgrund bakom texten i aktivitetsfältet* i menyn så att texten förblir läsbar mot skrivbordsbakgrunden.
- **Flera bildskärmar:** widgeten visas på varje bildskärms aktivitetsfält bredvid klockan, så att den förblir synlig när ett spel körs i helskärm. Med *Visa widgeten på* i menyn väljer du *Alla bildskärmar*, *Endast huvudbildskärmen* eller en specifik skärm (t.ex. endast *Bildskärm 3*).
- **Fler visningsalternativ:** *Ikoner ovanför procenttal* placerar varje ikon ovanför dess nivå för att spara bredd; *Tillverkarfärger* visar kända märken i sin färg (Razer-grön, HyperX-röd, ...) med en tunn stapel; två enheter av samma typ får en liten etikett så att de går att skilja åt; vänster- och högerställda aktivitetsfält får en vertikal kolumn av enheter.
- **Språk:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 och 繁體中文. Både Windows- och Linux-appen följer systemets visningsspråk; med *Språk* i menyn kan du välja ett annat, och Windows-installationsprogrammet stöder också alla 19 språken. Gränssnittsfraser ligger i redigerbara statiska `lang/*.json`-filer, och komplett översatt dokumentation finns i [`docs/i18n/`](README.md). Se [Översättningar](#översättningar) för att redigera eller lägga till ett språk.
- **Tillverkarfärger:** enheter från 15 kända märken får tillverkarens färg, med ett mjukt sken och en tunn nivåstapel under
  procenttalet: Razer grön, Logitech blå, SteelSeries orange, Corsair gul, HyperX / ROG / ZOWIE röd, PlayStation,
  Xbox, Samsung, Apple, Jabra, JBL, Cooler Master och Steam. Varje färg har en nyans för mörkt och en för ljust aktivitetsfält. Märket
  hämtas från drivrutinen som hittade enheten, sedan från tillverkar-ID:t och därefter från namnet; färger och regler finns i
  `src/brands.cpp`. Stäng av detta med *Tillverkarfärger* i menyn.

**Ikoner i systemfältet:** en ikon per enhet med siffran ritad inuti, plus aviseringen "Lågt batteri" vid 15 %. Appen växlar till detta automatiskt när aktivitetsfältet är vertikalt eller inte hittas.

**Anpassade enhetsnamn:** öppna enhetens undermeny och välj *Byt namn på enhet...* för att ange ett namn
(upp till 64 tecken). Namnet visas i aktivitetsfältswidgetens verktygstips/etikett,
systemfältets verktygstips och aviseringar samt i enhetsmenyn. Använd *Återställ ursprungligt namn*
för att återställa drivrutinens namn. Namnen lagras lokalt i den aktuella användarens
Windows-register (`Software\WirelessBattery`, `DeviceAliases`) med hjälp av den stabila
enhetsnyckeln. Namnbytet ändrar aldrig drivrutinsmatchning, protokollfrågor eller diagnostikutdata från `--list` /
`--dump`. Inget konto eller nätverksåtkomst behövs.

Håll muspekaren över för detaljer. Klicka för att öppna menyn: alla enheter (klicka på en för att dölja eller visa den), visningsläge, *Uppdatera nu*, *Starta med Windows* och *Avsluta*. Nivåerna uppdateras var 60:e sekund (*Intervall för batterikontroll* i menyn ändrar detta), samt direkt när en enhet ansluts eller datorn vaknar ur strömsparläge.

## Smarta batterilarm (experimentellt)

Du kan ställa in en **enskild aviseringsgräns för lågt batteri per enhet** via varje enhets
undermeny: **Batterilarm** → *Använd standard (15%)*, *Inaktivera aviseringar*
eller någon av nivåerna 5 %, 10 %, 15 %, 20 %, 25 %, 30 %, 35 %, 40 %. Den befintliga standardgränsen på 15 %
gäller om du inte väljer ett annat värde. Inställningarna sparas per enhetsnyckel i
den aktuella användarens Windows-register (`Software\WirelessBattery`, `AlertThresholds`).

Ett larm utlöses bara utifrån en verklig, färsk batteriavläsning på 0–100 % när
enheten är ansluten, vaken och inte laddas. Aviseringen visas en gång och återaktiveras
först när nivån har stigit mer än 10 procentenheter över den valda
gränsen (eller när laddning påbörjas). Saknade avläsningar eller sovande enheter
utlöser inga nya larm. Dolda enheter ger inga aviseringar. Att inaktivera
aviseringar för en enhet döljer den inte och ändrar inte dess procenttal.

Både aktivitetsfältswidgeten och systemfältsläget stöder aviseringar. Eftersom Windows
kräver en ikon i meddelandefältet för att visa en äldre pratbubbla kan widgetläget
visa en tillfällig aviseringsikon i upp till en minut efter ett larm.
Widgetens färger och markeringen för lågt batteri använder fortfarande projektets
ursprungliga globala 15 %-gräns, oberoende av aviseringsinställningen.

## Batterihistorik och insikter

Högerklicka på en enhet i aktivitetsfältswidgeten eller systemfältsmenyn och välj **Batterihistorik...**.
Den inbyggda, DPI-anpassade visaren (den följer Windows ljusa/mörka tema) visar insamlade batterinivåer med sammanbundna mätpunkter för de senaste **24 timmarna**, **7 dagarna** eller **30 dagarna**, tillsammans med senaste mätvärde, lägsta/högsta nivå, förändring i procentenheter och antal mätvärden. Du kan rensa den valda enhetens historik direkt i visaren.

Historiken sparas **endast lokalt** för anslutna, vakna enheter som rapporterar en numerisk procentsiffra. Mätvärden sparas högst en gång var 30:e minut per enhet (förutom vid ändrad laddningsstatus, med minst 60 sekunders intervall). Data sparas i upp till 30 dagar och den lokala filen hålls under ungefär 2 MB. Appen ställer aldrig extra frågor till hårdvaran utöver sin befintliga polling, skickar ingen historikdata över nätverket och gör en försiktig, ungefärlig uppskattning av tiden tills batteriet är tomt enbart utifrån nyliga urladdningsobservationer. Det krävs minst fyra mätvärden, två timmar, en minskning på tre procentenheter, ett färskt mätvärde och ett stabilt urladdningsintervall. Laddning, gamla mätvärden eller otillräckligt dataunderlag döljer uppskattningen; drifttid rapporterad direkt från enheten är inte tillgänglig. Uppskattningen är ingen garanti. Saknade datapunkter visas som luckor i diagrammet och interpoleras inte.

Stäng av **Samla in batterihistorik** i menyn för att sluta spara mätvärden; det som redan har sparats finns kvar tills du rensar det i visaren. Filen lagras i `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Enhetsidentiteterna i filen är kodade (inte krypterade); filen är lokal för ditt Windows-konto. I `--demo` använder diagrammet syntetiska data som aldrig sparas. **Obs:** historik börjar samlas in först efter att den här funktionen har installerats och appen har varit igång ett tag.

## Enheter som stöds

| Tillverkare | Enheter | Hur |
|---|---|---|
| **NuPhy** | WH80 via USB-kabel (`19F5:A011`) eller Bluetooth (`19F5:324A`), hårdvarutestad | USB: skrivskyddad NuPhyIO-batterifråga; Bluetooth: Windows batterinivå med tangentbordsklassificering ([protokollanteckningar](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) på sin `3654:6901` USB-mottagare (hårdvarutestad) | Skrivskyddad CRC-kontrollerad batterifråga och laddningsflagga; observerade grova avläsningar i steg om 10 %, finare upplösning ej verifierad ([protokollanteckningar](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX på KP 8K-mottagaren (`1D57:FA65`; modell `73` hårdvarutestad, modell `74` otestad) | Passiva Xenta-statusrapporter; två matchande ramar bekräftar nivån ([protokollanteckningar](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, testad), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` testad, `002D`/`002A`), A50 Gen 3 (`9886:0015` testad, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), via USB-basstation | Batteriprocent, laddning och dockningsstatus |
| **Logitech** | Möss och tangentbord på Unifying-, Bolt-, Lightspeed- (inklusive dongeln för PRO X3 SUPERSTRIKE `046D:C54F`) och Nano-mottagare, via USB eller Bluetooth; G-headset (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 på den nyare dongeln `046D:0ADF` | HID++ 1.0 / 2.0 med funktionsupptäckt: enhetligt batteri, batterinivå, spänning, ADC; G435: CRC-16-ramade tillverkarrapporter, `GET_BATTERY` i mV |
| **Razer** | Trådlösa möss, tangentbord och donglar; headseten BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X, V3 Pro for Xbox (`1532:0A55`-mottagare, `0A4E`-kabel); Barracuda X (2022) på sin 2,4 GHz-mottagare (`1532:0550` eller `1532:0552`); Barracuda Pro (`1532:053A`) | Razers feature-report-protokoll; BlackShark-tillverkarprotokoll (V3 / V3 Pro / V3 X tillfrågas var 5:e minut); Barracuda X: Airoha-frågor för batteri och kabel via mottagaren |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (inklusive `1038:225D`), Arctis Nova Elite (basstation `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, otestad), Aerox 3 Wireless CS2 Dragon Lore Edition (mottagare `1038:1878`, kabel `187A`), Aerox 3 Wireless Gen 2 (mottagare `1038:1890`, kabel `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Tillverkarens HID-rapporter; Aerox/Prime och Rival 650 delar en post mellan mottagare och USB-kabel och föredrar kabelns avläsning när båda svarar |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 wireless; Bragi-enheter (Virtuoso, Void V2, HS80 MAX, Slipstream-möss och -tangentbord, inklusive den nyare Slipstream-mottagaren `1B1C:2B00`, t.ex. Scimitar Elite SE Wireless och Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, otestad) | Tillverkarens HID-rapporter, Bragi `GET` (skrivskyddad), Compx 17-bytes batteriprotokoll (skrivskyddat) |
| **Cooler Master** | MM712, MM731 (2,4 GHz-dongel eller USB-kabel) | Tillverkarens HID-statusrapport (skrivskyddad) |
| **Press Play** | ICARUS V2 Nearlink på sin `7768:6434` 2,4 GHz-mottagare (drivrutinen hårdvarutestad vid 90 %; protokollet fångat vid 100 % och 90 %) | Skrivskyddad utrapport `06 05` på `FFB2:0001`; batteriprocent i svarsbyte 14 |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` för PS, otestad), Cloud Flight S, Cloud Stinger Core Wireless (inklusive DTS `03F0:0A8E`, testad), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (2,4 GHz-dongel), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (2,4 GHz-dongel) (2,4 GHz-dongel `03F0:0F98`, testad; `0D97` otestad) | Tillverkarens HID-rapporter (Haste 2: [protokollanteckningar](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Tillverkarens feature-rapport |
| **Hitscan** | Hyperlight X, Hyperlight N | Tillverkarens feature-rapport (samma protokoll som Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, trådlösa Pulsar- och ATK VXE-möss (t.ex. VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (mottagare `3554:F512`) | Delat tillverkarprotokoll med kontrollsumma i svaren |
| **Pulsar X2 V3** | X2 V3 på 1K-dongeln (`3710:5402`) eller USB-kabel (`3710:3402`); X2 V3 eS på 8K-dongeln (`3710:5403`) eller USB-kabel (`3710:3406`) | 64-bytes feature-rapport från tillverkaren, batteriregister `08 81 01` (skrivskyddad) |
| **ATK / VXE NK** | VXE R1 NK och andra NearLink-möss på NK mouse NANO-dongeln (`373B:1216`) | ATK BITMOUSE utrapport 08 på `FF05:0001` (batteri och laddning) |
| **ATK 8K Nano** | ATK / VXE-möss på ATK 8K Nano Dongle (`373B:1178`) | Holtek GetConfigData (`82`) feature-rapport på `FF10:0001` (från ATK HUB; batteri och laddning) |
| **ATK-headset** | ATK N9 Pro, N9 Ultra (första generationen) | Protokoll via virtuell COM-port (ATK-datorappen måste vara stängd) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK och deras 8K-donglar | Glorious- eller Kysona-protokoll beroende på modell |
| **Keychron-möss** | M4 och andra Keychron-möss på 2,4 GHz-mottagaren; 4K-möss (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) på Keychron 4K Link-mottagaren (`3434:D038`); 8K-möss (M5 8K, G6 HE 8K ...) på TurboLink 8K-mottagaren; 8K-möss på Ultra-Link 8K-mottagaren (`3434:D028`); äldre möss (M1, M2, M3, M3 mini, M6, M7 ...) på 1K-mottagaren (`3434:D030` / `D031`); styrkulan Nape Pro på Link-KM-mottagaren eller kabel | Tillverkarrapport från Keychron Launcher (1K-mottagare: feature-rapport 51 06, som används av Keychrons datorapp; Ultra-Link 8K: rapporterna B5 03 / B3 06 på `FFC1`; Nape Pro: rå HID A7 31) |
| **Keychron-tangentbord** | K5 Max (`3434:0A50`, testad) på Keychron Link-mottagaren (`3434:D030`) eller USB-kabel; andra trådlösa Keychron QMK-tangentbord som kompilerats med samma patch | Rå HID på `FF60:0061`: `B2` frågar mottagaren vilket tangentbord som är länkat, `A4` returnerar nivå, spänning och laddning. **Kräver patchad tangentbordsfirmware:** se [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). Originalfirmware rapporterar endast via Bluetooth |
| **CHERRY** | Trådlöst tangentbord MX 3.0S Wireless på sin 2,4 GHz-dongel (`046A:00EA`, testad) eller USB-kabel (`046A:00E3`, testad) | Tillverkarens HID-fråga `1A` på `FF1C:0092` (skrivskyddad), med USB-strömtillstånd. Bluetooth täcks av Bluetooth-stödet |
| **CHERRY** | Trådlös mus Cherry XTRFY på 1K-mottagaren (`046A:0330`, testad) | CompX 17-bytes batteriprotokoll (`08 03` länkstatus, `08 04` GetPower), samma inramning som Corsair Sabre V2 Pro (skrivskyddat) |
| **Arbiter Studio** | Akitsu (`373E:000A` 8K-mottagare, `373E:0009` kabel), Akitsu 3950 (`373E:0039` 8K-mottagare, `373E:0038` kabel), Akitsu Medium (`373E:0067` 8K-mottagare och `373E:0066` kabel, båda testade) | Skrivskyddad feature-rapport `0x83` på `FFFF:0000` från Arbiter Web HUB (batteri och laddning) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (kabel, 1K- och 4K/8K-donglar) | Tillverkarens feature-rapport från LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) på 4K-dongeln; XM2we på sin ursprungliga mottagare (`3367:1961`) | Tillverkarens feature-rapport `A1`, batterikommando `B4` (skrivskyddad) |
| **ATK / VGN / Evision-tangentbord** | ATK V75X samt VGN-/VXE-tangentbord (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) på den delade 2,4 GHz-mottagaren (`320F:5088`) eller USB-kabeln (`320F:5055`), identifierade via produktnamn; tangentbord vars `320F:5088`-mottagare heter "Wireless Gaming Keyboard", t.ex. Feker Alice80 (testad) | Evision-utrapport `04`, batterikommando `1A` (från ATK HUB och VGN HUB); tillfrågas högst var 10:e minut via mottagaren |
| **Redragon (Evision)** | K1NG M999 (testad) på `320F:226F` 2,4 GHz-mottagaren; mottagar-ID:t kan delas av andra modeller | Samma Evision-protokoll som ATK-tangentborden (rapport `04`, kommando `1A` på `FF1C:0092`), tillfrågas vid varje polling; laddning visas på den magnetiska dockan; när USB-kabeln är inkopplad fortsätter mottagaren att upprepa den gamla nivån utan laddningstillstånd |
| **Audeze** | Maxwell på USB-dongeln (`3329:4B19`) eller USB-C-kabeln (`3329:4B1A`); Maxwell 2 på USB-dongeln (`3329:4B29`, testad); Xbox-ID:n otestade | Tillverkarrapport `06` / inrapport `07`, batteriattribut `0CD6` (enskild skrivskyddad fråga) |
| **ENDORFY** | Viro Wireless på sin 2,4 GHz-dongel (`3738:0072`, otestad) | Airoha RACE "get battery" (`0CD6`) på tillverkarrapport `06` / inrapport `07`, samma skrivskyddade fråga som Audeze- och Skullcandy-donglar; inget laddningstillstånd |
| **Turtle Beach** | Stealth 700 Gen 3 på USB-sändaren (`10F5:2251`, testad i HaloBattery; PC-versionen `10F5:2262`, otestad) eller headsetets egen USB-kabel (`10F5:2253`) | RACE `0x9942` (aktivera CoAP-klienten) och en CoAP `GET /GSI` tunnlad i RACE `0x9902`, precis som Swarm II gör; batteri från nyckel `240` (ingen laddningsflagga) |
| **AKG** | N9 Hybrid på sin USB-dongel (`0ECB:20D9`, testad) | Airoha RACE på `FF13:0001`: utrapport `06`, inrapport `07`, batteriattribut `0CD6` (enskild skrivskyddad fråga) |
| **NZXT** | Lift Elite Wireless på sin dongel (`1E71:2101`) eller USB-kabel (`1E71:2129`) | Tillverkarläsning `4E 02 81 .. B0` (från NZXT CAM-infångningar) |
| **Poly / Plantronics** | Voyager 8200 UC och andra headset bakom BT600-adaptern (`047F:02EE` / `02F7`) | Rapport `07` get/set-protokoll, batteripost `0A 1A` (skrivskyddad) |
| **WLMouse** | YING Magnesium (YING 8K-mottagare `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (mottagare eller kabel; ej Beast X 4K); Beast X V2 (8K-mottagare `36A7:A856`); Beast G (8K-mottagare `36A7:A860` eller kabel `36A7:A861`; otestad) | Tillverkarens feature-rapport, statuskommando `0x83` (YING: samma protokoll som Glorious) |
| **Finalmouse** | UltralightX på sin 2,4 GHz-dongel (`361D:0100`, testad); Starlight X på sin dongel (`361D:0300` / `0301`, testad). Ej på musens egen kabel | xpanel-tillverkarrapporter på `FF00`: skrivskyddade GET-anrop, därefter *wake/all* (`0xE0`); batterispänning enligt xpanels kurva, eller Starlight X:s egen procentsiffra, plus laddningstillstånd |
| **VAXEE** | Trådlös mus på VAXEE 4K-mottagaren (`3057:1002`) eller 8K-mottagaren (`3057:2002`, t.ex. NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless via USB-kabel (`3057:1011`) | Skrivskyddad feature-rapport `0E` på `FF05:0001`; batteri i steg om 5 %, laddningstillstånd ([protokollanteckningar](#sec-vaxee)) |
| **Scyrox** | V12M på sin 2,4 GHz-mottagare (`395A:0006`) | S-Center 2.0-profilläsning (utrapport `08`, kommando `01`) på `FF00:0002`; endast batteri, inget laddningstillstånd |
| **HECATE** | G5M PRO och andra HECATE-möss på samma mottagare samt USB-kabel `35BB:D3FA / D3FC / D3FD` | Kysona-protokoll |
| **Redragon** | Compx-baserade trådlösa möss: M916 Pro 1K (testad), M913 Impact Elite (tri-mode), G49 (mottagare eller kabel) | Kysona-protokoll (Areson-mottagarna `25A7` listas under Areson) |
| **Taidu (钛度)** | TSG808 på sin Compx 2,4 GHz-mottagare `3554:F5D5` (testad) | Kysona-protokoll |
| **Areson (Redragon)** | M915RGB-WL (testad), ursprungliga M913 Impact Elite och andra möss på mottagaren `25A7:FA07` / `FA08` | 17-bytes `GetPower` feature-rapport; nivå i steg om 10 % och en laddningsflagga |
| **Ninjutso** | Sora V2 på 1K-mottagaren (`1915:AE1C`, testad) eller USB-kabel (`1915:AE11`, testad); Ten Air (mottagare `093A:EB01` och USB-kabel `093A:E020`, testad) / Ten (`093A:EB01` / `E020`, otestad) | NinjaForce feature-rapport `0x05` (`0x15` för Sora V2) och `0x06` (`0x13`/`0x12`/`0x11` för Ten / Ten Air) |
| **Sprime** | PM1 på 2,4 GHz-mottagaren (`1915:AC1C`, testad; `1915:AD8C`) eller USB-kabel | Samma feature-rapport `0x05`, statuskommando `0x15`, från Sprimes webbdrivrutin (`sprime.pro`) |
| **RAWM / SADES** | Leviathan V4 på RAWM HS Receiver (`1915:2346`, testad); ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* och SADES Dagger-möss på sina RAWM-mottagare (`1915:232A`–`234B`) eller USB-kabel | RAWM HUB 2.0-enhetsinformationsfråga via mottagaren (JSON med batteri-% och laddning), skrivskyddad ([protokollanteckningar](#sec-rawm)) |
| **AULA** | Trådlösa tangentborden F75 / F87 Pro / F99 på 2,4 GHz-mottagaren | Rapport `0x13`-ram, kommando `0x4A`, summakontrollsumma (Bluetooth och trådbundet läge otestade) |
| **AULA-möss** | X9 Ultra (testad) på AULA-8K Dongle `320F:22A0`; mottagar-ID delas med V9-modeller | Rapport `04`, skrivskyddat batterikommando `1A` mellan START `01` / END `02` på `FF1C:0092`; endast 2,4 GHz |
| **SONiX-tangentbord (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (testad), EPOMAKER EA75 (testad), AULA F108 Pro på `05AC:024F` 2,4G-dongeln; AJAZZ AK980 V2 på `0C45:FEFE`-dongeln; AJAZZ AK820 Pro på `0C45:FDFD`- eller `0C45:FEFE`-dongeln; EPOMAKER P75 på `342D:E479` (hårdvarumässigt otestad) | Tillverkarrapport `20 01` på usage page `FF60`, summakontrollsumma (endast 2,4G-läge; ingen laddningsindikering) |
| **Ytterligare SONiX-mottagare (ej hårdvarutestade)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | Samma batterienliga `20 01`-fråga; exakt VID:PID och `FF60:0061`-samling med 33-bytes rapporter krävs; endast 2,4G, ingen laddningsindikering |
| **36B0-tangentbord (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB på `36B0:3002` 2,4G-dongeln eller USB-kabeln `36B0:3009` (protokollet testat på båda av rapportören i #343); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) på samma dongel eller kabel (otestade); URX Core75 på dongeln (bekräftad i HaloBattery); EVO80 (otestad) | PMO Hub-firmware: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` på usage page `FF60`, från pmohub.cn. URX / VIA-firmware: VIA custom-get `08 00 07` (kanal 0, värde 7), från URX HUB via HaloBattery. Ingen laddningsindikering |
| **DAREU** | EM901X på `260D:1074` 2,4 GHz-mottagaren eller `260D:1090` USB-kabeln (batteriavläsning testad på båda; växling av laddningsflagga vid dockning/urkoppling på mottagaren testad) | Batterienlig feature-rapport `08`, kommando `04`; svar `09` på en separat tillverkarsamling. Kräver ett entydigt in-/feature-par per produkt-ID. Föredrar en giltig USB-avläsning när båda är anslutna; mottagaren kan returnera cachad telemetri även när musen är avstängd |
| **DAREU** | A84-tangentbord (`260D:0022`, otestad) | SONiX feature-rapport på gränssnitt 0, kommando `04 F6` (den officiella A84-drivrutinens batteriläsning); nivå i procent, ingen laddningsflagga |
| **DAREU** | A980 Pro på multi-mus-mottagaren `260D:1131` och på sin USB-kabel (`260D:1148`) (batterinivå testad på hårdvara; laddningsflagga bekräftad när den är inkopplad) | Togran-protokoll: 65-bytes feature-rapport `0A` på consumer-control-samlingen; kortplatsfråga (klass 0 / `A0`) följd av batterifråga (klass 7 / `80`), på kortplats 0 via kabeln. Skrivskyddat |
| **Sharkoon** | Skiller SGM50W på `260D:1125` (otestad) | Samma Compx-fråga som DAREU EM901X (feature-rapport `08`, kommando `04`; svar `09` på `FF01:0000`); Sharkoons firmwareuppdaterare för den är ett Compx-verktyg på VID `260D` |
| **Zenith** | Zenith Pro på `260D:1114` 2,4 GHz-mottagaren (batteriavläsning testad; laddning otestad) eller `260D:1143` USB-kabeln (otestad) | Samma Compx-kommando (`08`, `04`) som utrapport på `FF02:0002`; svar `08 04` på samma samling med procent, laddningsflagga och millivolt, kontrollerat med `0x55`-bytesumma |
| **AJAZZ AK992** | Telink 2,4 GHz-mottagare `320F:50C3` (testad) | EVision-batterifråga på HID-samling `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, DW-serien (U2-DW, S2-DW ...) och U2 på sin 2,4 GHz-mottagare | Skrivskyddade tillverkarkommandon dokumenterade av gemenskapen |
| **Royal Kludge (RK)** | MG6 Pro på 2,4 GHz-dongeln (`2E3C:00A6` / `00E6`) eller USB-kabeln (`2E3C:00A5` / `00E5`) | QiWang 64-bytes ram från RK:s webbdrivrutin, `GET_BATTER_VOL`-läsning (procent, spänning, laddning) |
| **ASUS ROG** | Tangentborden Strix Scope II 96 (RX), Azoth, Falchion; mössen Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact; headsetet Pelta (2,4 GHz-dongel); öronsnäckorna Cetra Open Wireless (SpeedNova-dongel `0B05:1CAC`, V / H / etui); Omni Receiver | ROG HID-batterifråga |
| **Machenike** | L7 Arctic / L7 Mix på `248A:FF4C` 2,4 GHz-mottagaren eller `248A:FF4E` USB-kabeln (båda testade) | Skrivskyddad feature-rapport `51`, statuskommando `06`; batteri och laddning. [Protokollanteckningar](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS på sin 2,4 GHz-dongel (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (2,4 GHz-mottagare `0DB0:0D3C`, testad; USB-kabel `0DB0:0D3B`) och CLUTCH GM41 Lightweight Wireless (mottagare `0DB0:0D4C` / kabel `0DB0:0D4B`, från en ägares infångningar) | Skrivskyddad tillverkarfråga `0F 20` på `FF0D:00B0` och `FF00:0001`; batteri och laddningsflagga i en byte (protokoll från MSI Centers Gaming Gear-modul); GM41: passiva `A0 xx 07 …`-rapporter på `FF10:0006` |
| **MCHOSE** | Mössen L7 / L7 Pro / L7 Ultra (L7 Ultra testad), M7 / M7 Ultra, A7 / A7 Ultra, K7 på 2,4 GHz-mottagaren eller USB-kabeln; A5 V2 Ultra (2,4 GHz-mottagare `3837:100C`, testad), K7 Ultra (2,4 GHz-mottagare `3837:1001`, testad; A7 V2 Ultra+ `3837:100B` förväntas fungera, ärende 227); G3 V2 (2,4 GHz-mottagare `3837:4245` och USB-kabel `3837:418C`); K7 V2 Ultra+ på 2,4 GHz-mottagaren `3837:1014` eller på sin USB-kabel `3837:4028` (båda testade; de andra mottagar-ID:na i nya familjen `1018`, `1016`, `102C`, `102D` är otestade) | Tillverkarens feature-rapport, inverterad nyttolast (protokoll från `alexfrih/mchose-linux`); Realtek `3837`-donglar svarar på samma fråga med vid-fältet satt till `41E4` (A5 V2 Ultra) eller `3837` (K7 Ultra); G3 V2: skrivskyddad tillverkarfråga på `FF01:0010`; K7 V2 Ultra+: 64-bytes rapport `0x4D`, enhetsinformationskommando `0x0900` på `FF01:0001` (protokoll från M HUB:s webbdrivrutin) |
| **MCHOSE A5 (första generationen)** | A5 Pro / A5 Pro Max på 1K- eller 4K-mottagaren för 2,4 GHz (`2023:F013`, `2023:F015`, `2023:F018`) eller USB-kabeln (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); otestad här | Skrivskyddat batterikommando `0x83` (sida 0) i en 64-bytes feature-rapport på `FFFF`, svar markerat `0xA1` (protokoll från `z750sasr` A5 Pro Max webbdrivrutin och HaloBattery, ID:n från `Klegus/mchose-macos`) |
| **MCHOSE-headset** | V9 Pro 2 på 2,4 GHz-dongeln (`3837:6011`, testad) | M HUB:s skrivskyddade "MC"-batteriram (rapport `0x55`, underkommando `0x0B`) på `FF07:0222`; batteri och laddningsflagga i en byte (protokoll från M HUB:s webbdrivrutin) |
| **AULA / MCHOSE / Redragon-tangentbord** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 och övriga M HUB-tangentbord; Redragon Horus Pro / Pro V2 (K618RGB-PRO) på 2,4 GHz-mottagaren (`3554:FA09`, `41E4:2001`); MCHOSE K87 på `05AC:024F`-mottagaren (BY-layout på gränssnitt 1, inte SONiX-varianten) | Rapport `0x13`-ram, kommando `0x4A` (MCHOSE- och Redragon-modeller identifieras med kommando `0x05`, som i M HUB); Bluetooth och trådbundet läge täcks inte |
| **MCHOSE-tangentbord** | G75 V2 på 2,4 GHz-mottagaren `3837:3033` (testad); samma mottagare levereras med G87 V2 och K99 V3 (samma protokoll, otestade); K87S kombinerar samma mottagar-ID med ett annat protokoll och täcks inte | M HUB:s skrivskyddade "GLW" func-config-fråga på den ID-lösa 64-bytes samlingen `0001:0000`: begäransflagga `0x55`, kommando `0x05`, batteri i nyttolastbyte 32 (bit 7 = laddning), additiv kontrollsumma |
| **AULA SC580** | Musen SC580 / SC580X via USB-kabel (`088D:062E`, testad) eller sin 2,4 GHz-mottagare (`089D:062F`, testad) | Skrivskyddat kommando `0x30` (enhetsinfo) på den 33-bytes tillverkarsamlingen `FF02:0000`, summakontrollsumma; under laddning rapporterar musen ett fast värde på 100, så den senaste nivån visas; Bluetooth-läge täcks inte |
| **AULA HERO 68 Air** | HERO 68 Air på 8K Wireless Receiver (`372E:106C`) | Bekräftade 20-bytes ramar på usage page `FF60` (fyra datarammar och en avslutning per meddelande), skrivskyddat batterikommando `0x87`, laddningsflagga `0x10` efter nivån; Bluetooth och trådbundet läge täcks inte |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra och S9 Max / Pro / Ultra / Ultra+ på mottagaren "Gaming 2.4G" (`372E:103D`); S9 Ultra på sin USB-kabel (`372E:1027`) | Skrivskyddad feature-rapport `03` på `FF00:0001`: länkkontroll `47`, grundläggande enhetsdata `4F 81` (batteriprocent och laddningsbit), från EWEADN:s webbdrivrutin |
| **Rapoo VT** | VT3 Max Gen 2 (testad); VT9 Gen 2 (testad); andra Nordic 54L VT-möss som exponerar samma statusgränssnitt; äldre VT3 Pro (experimentellt); VT1 Pro Max (från ägarens USB-infångningar) | Passiv HID-statusrapport `07` på `FF00:0002` (16 eller 19 byte; 13 byte på vissa VT3 Max Gen 2-mottagare); äldre `BB` begränsad till VT3 Pro `1215/4415` och VT1 Pro Max `1233/4433`. Mottagare och USB-kabel, med laddningstillstånd |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (Xenta-modellerna 30/50; äldre 3D), Delux M800 Pro, Ajazz AJ179-familjen; AJ159 och andra möss i AJ-serien på 3151-mottagaren; AJ139 V2 MC (`A8A5:2255`-mottagare, `A8A4:2255`-kabel) | Tillverkarrapporter (M900 Pro: passiva statusutsändningar eller feature-fråga, Xenta-händelser 40/41; AJ-serien: `0xF7`-statusfråga, därefter feature-rapport `0x05`) |
| **Incott** | G23 V2 / G24 (`093A:522C`-mottagare, `093A:622C`-kabel) | Skrivskyddad status-feature-rapport `09` |
| **Attack Shark och andra kinesiska märken** | Rongyuan-mottagare (81 modeller: Attack Shark R3 och AJAZZ AJ179 Pro på `3151:402D`, K86, X82 PRO HE, Ajazz-tangentbord, vissa MSI m.fl.; K86 över Bluetooth visas som ett tangentbord); Xenta-mottagare (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; X6 även på `1D57:FA61`, otestad); Semico `1A2C`-tangentbord (Attack Shark X98 på `1A2C:8FFF`-dongeln, testad, och `1A2C:A034`-kabeln; AJAZZ AK820 Max Plus på `1A2C:8FFF` / `1A2C:A036`) | Rongyuan-statusrapport; passiva Xenta-utsändningar; Semico skrivskyddad `0x0E`-statusfråga (`AA 55 CC 33` på `FF02:0002`; laddningsflagga utelämnad eftersom X98 rapporterar `state=1` både på batteri och under laddning) |
| **Wraith** | W1 / W1 Freestyle (`093A:522C`-mottagare, `093A:622C`-kabel; samma ID:n som Incott, särskiljs via modellkoden) | Skrivskyddade läsningar per knapp `86` (feature-rapport `09`) för alla knappar, därefter den skickade statusinrapporten `09` |
| **Fantech** | Helios Go XD5 (trådbunden `25A7:FA7B`, dongel `25A7:FA7C`); Raigor III (testad), Raigor II WG10 och andra generiska 2.4G Mouse-enheter på den återanvända dongeln `1EA7:0066` / `1EA7:0064` | Helios Go XD5: tillverkarens feature-rapport `08`, kommando `04`, kontrollsumma med summa till `0x55`. Raigor/2.4G Mouse: skrivskyddad `B5`-statussidefråga på `FFB5:0001`, stycke `94` = senast rapporterade procent (kan vara inaktuell när den sover, är avstängd eller laddas; inget laddningstillstånd) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, trådlös adapter); headseten INZONE H9 II och H5; INZONE Buds (USB-C-dongel) | Inrapport; INZONE-tillverkarprotokoll |
| **Fractal Design** | Headsetet Scape på sin 2,4 GHz-dongel eller USB-C-kabel | Tillverkarfrågan `GET_DEVICE_STATE` från Fractals webbapp Adjust Pro (usage page `FF00`) |
| **Jabra** | Alla Jabra-headset som talar GN-protokollet (Evolve2 / Evolve3 och andra), på sin egen USB-kabel eller bakom en Jabra Link-dongel; ingen lista över produkt-ID:n, DECT-basstationer (Engage, PRO 9xx, GO 6400, Link 400) utelämnas; namnet läses från headsetet | GNP-statusfråga (klass 12 / op 02) på usage page `FF00`, usage `05` eller `01`, på GNP-adress `08` (USB) eller `04` (dongel) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), 2,4 GHz-mottagare eller USB; Apex 5 (`37D7:2501`), 2,4 GHz-mottagare eller USB | Tillverkarens HID-infofråga på `FFA0:0001`; batterinivå 0–5 mappad till 0–100 % i steg om 20 %, med laddningstillstånd; ingen Space Station-tjänst krävs |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite på 2,4 GHz-mottagaren; Nova 2 Lite via USB; G7 Pro (testad: Zenless Zone Zero Edition, mottagare `3537:105E`) och andra GameSir-kontroller i Xbox-läge (GIP); Cyclone 2 (XInput-läge, mottagare eller kabel); Cyclone Pro på sin 2,4 GHz-dongel (`3537:1015`, parkoppla kontrollen med Windows via Bluetooth en gång) | Tillverkarens enhetsinfofråga (usage page `FF7A`); Windows.Gaming.Input-batterirapport (verklig %) i Xbox-läge; Cyclone 2: tillverkarens batteribegäran (usage page `FFF0`); Cyclone Pro: GameSir-appens base-info-begäran via Bluetooth LE (tjänst `0x8650`), läses varannan minut |
| **BEITONG** | KP20 / BTP-KP20 på sin 2,4 GHz-mottagare (`20BC:5128`, XInput-läge, testad) och KP40D / BTP-KP40D på sin mottagare (`20BC:515C`, XInput-läge); BEITONG iControl krävs inte | Tillverkarfrågan "get base info" på usage page `00FF` (rapport `02`, nibble-blandad nyttolast), med laddningstillstånd |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` testad på 2,4 GHz-dongel, D-input `2DC8:6012` — håll in B medan du slår på den, firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Tillverkarens HID-statusfråga (`FF7A`/`FFA0`) och SDL-gamepad-inrapport `01`/`04`, med laddningstillstånd |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Statusram som snäckorna skickar via Samsungs RFCOMM-tjänst (SPP), skrivskyddad. Systemfältet visar den lägre snäckan; verktygstipset listar vänster, höger och etui. Galaxy Buds-appen måste vara stängd |
| **Nothing / CMF** | Nothing Ear (3a) (testad), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Skrivskyddad `0xC007`-batterifråga på Nothings NT Link RFCOMM-tjänst (`aeac4a03-dff5-498f-843a-34487cf133eb`). Systemfältet visar den lägre snäckan; verktygstipset listar vänster, höger och etui |
| **Akko** | Akko Air 01 (`3151:5006`, 2,4 GHz-mottagare, testad) och Akko V9 Dash Pro (`38EE:000C`, 2,4 GHz-mottagare, testad) | Air 01: Rongyuan `0xF7`-statusrapport; V9 Dash Pro: skrivskyddad 64-bytes `0x1A`-statusfråga på `FF1C:0092` med laddningstillstånd |
| **MOONDROP** | Headsetet GM01 Pro på sin 2,4 GHz-dongel (`35D8:0133`); på sin USB-kabel visas det som laddande med den senaste nivån | WalkPlays skrivskyddade tillverkarläskommando på rapport `4B` |
| **VGN** | Headsetet OMNISOUND (ZHOUTING) på sin 2,4 GHz-dongel (`372E:10BB`, testad) | V HUB "ZHOU"-fråga: utrapport `55` med nyttolast `65 01` på kontrollsamlingen `000C:0001` (32-bytes inrapporter, 64-bytes utrapporter); procentsiffran kommer tillbaka i svaret (skrivskyddad) |
| **JBL** | Quantum 650 Wireless (testad, 2,4 GHz-dongel); Quantum 520, 650X, 850, 950, 950X Wireless (dongel eller USB-kabel, samma protokoll, otestade) | JBL "HIDV3"-enhetsinfofråga för batterifunktionen (usage page `FF12`), med laddningstillstånd |
| **JBL** | Quantum 350 Wireless (testad på Windows med `0ECB:206B` 2,4 GHz-mottagaren); Quantum 610 Wireless (`0ECB:205C` 2,4 GHz-dongel, otestad på Windows); Quantum 360 Wireless (`0ECB:2115` 2,4 GHz-dongel, otestad) | HIDV1 feature-rapporter för trådlös anslutning och batteriprocent |
| **Xbox** | Handkontroller på Xbox Wireless-adaptern, USB eller Bluetooth; headset anslutna till en handkontroll | Windows.Gaming.Input-batterirapport (verklig %), XInput-reservlösning |
| **Switch Pro-kompatibla** | Kontroller som presenterar sig som `057E:2009` (testad: GameSir Tarantula Pro via 2,4 GHz-mottagaren i Switch-läge) | Fem batterinivåer från HID-rapport `0x30` efter att Steam Input eller en annan värd aktiverat fullständiga rapporter |
| **Apple AirPods / Beats** | AirPods Max (testad, `200A` Lightning och `201F` USB-C), AirPods Pro 3 (testad, `2027`), AirPods Pro 1 / 2, AirPods 1–5 samt Beats-hörlurar och -öronsnäckor | BLE-utsändningar för "proximity pairing" (`0x07`) (enkel batterinivå för AirPods Max och Beats-hörlurar; vänster, höger och etui för öronsnäckor, i steg om 10 % med laddningstillstånd), matchade mot den parkopplade modellen |
| **Telefoner (Telefonlänk)** | Alla Android-telefoner länkade med Microsoft Telefonlänk, via Wi-Fi eller Bluetooth (testad: Nothing Phone (4a) Pro) | Batteri och laddningstillstånd från Telefonlänks kort i Windows 11 Start-meny (`StartMenuCompanion.json`); ingen Bluetooth behövs |
| **Darmoshark** | M3 (`248A:FF30`) och M3S (`248A:FF31`) på sina 2,4 GHz-mottagare i Windows | HID feature-rapport för musidentitet och batteri |
| **Darmoshark** | M3S Pro på Nordic 1K-mottagaren (`1915:0723`) | Tillverkarens HID-statusfråga på samlingen `FF0A` |
| **Alienware** | Headsetet AW920H på sin 2,4 GHz-dongel (`413C:A515`, testad); via Bluetooth täcks det av Bluetooth-raden | Tillverkarfråga `06 C0 0A` på `FF13:0001`, svarsrapport `07` med en XOR-kontrollsumma; fält för nivå, laddning och kritisk nivå avkodade enligt Alienware Command Centers AW920H-insticksprogram |
| **Niceboy** | MW400 på sin 2,4 GHz-mottagare (`248A:FA02`, testad) | Skrivskyddad rapport `05`-fråga `24 FA 48`; batterispänning mappad till 10 %-steg med tillverkarappens tabell, laddningsflagga |
| **Bluetooth** | Allt som visar ett batteri i *Inställningar → Bluetooth och enheter* (öronsnäckor, hörlurar, BLE-möss och -tangentbord). Google Fast Pair-öronsnäckor (Jabra Elite 8 Active testad; Pixel Buds och många Sony-/JBL-/Bose-modeller) får också nivåer för vänster, höger och etui | Windows enhetsegenskap; Fast Pair-batteriutsändningar (BLE-tjänstdata `FE2C`), matchade mot den parkopplade enheten via Bluetooth-adress |
| **Generisk HID** | Enheter som rapporterar standardanvändningen HID *Battery Strength* | HID usage page `0x06` / `0x85` |
| **HeadsetControl** | [Alla headset som programmet stöder](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, nyare Logitech m.fl.) | Medföljer; kör `headsetcontrol -o json` |
| **MAONO PD200W** | 2,4 GHz-mottagare (`352F:040E`) | Batteriprocent; hårdvarutestad |


**Testat på riktig hårdvara:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (PlayStation-mottagare `0951:1713`; laddning otestad), HyperX Cloud Core Wireless DTS (mottagare `0951:173F`; fulladdad nivå otestad), HyperX Pulsefire Haste 2 Core Wireless (dongel `03F0:0AB5`; donglarna för Haste 2 Wireless är otestade), Cooler Master MM712 (dongel), Rapoo VT3 Max Gen 2 (mottagare `24AE:1417` och USB-kabel `24AE:4617`; andra Rapoo-modeller är otestade, se [protokollanteckningar för Rapoo](#sec-rapoo)), Redragon M916 Pro 1K (mottagare `3554:F55D`), Taidu TSG808 (mottagare `3554:F5D5`), Redragon M915RGB-WL (mottagare `25A7:FA07`; andra Areson-modeller är otestade, se [protokollanteckningar för Areson](#sec-areson)), SteelSeries Rival 650 Wireless (mottagare `1038:1726` och USB-kabel `1038:172B`), SteelSeries Arctis Nova Pro Wireless (basstation `1038:225D`; batteriavläsning testad, laddning och strömövergångar otestade), HECATE G5M PRO (mottagare `35BB:D3FB`), WLMouse YING Magnesium (8K-mottagare `36A7:A874`), ATK N9 Ultra (mottagare `373B:1204`), Corsair Scimitar Elite SE Wireless (Slipstream-mottagare `1B1C:2B00`), Corsair Dark Core RGB Pro SE (Slipstream-mottagare `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (2,4 GHz-mottagare `1B1C:2B2A`; batteriavläsning verifierad), DAREU EM901X (mottagare `260D:1074`; laddning och viloläge/väckning otestat), Jabra Evolve3 75 på en Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (mottagare `3837:4245` och USB-kabel `3837:418C`), MCHOSE K7 Ultra (mottagare `3837:1001`), MCHOSE K7 V2 Ultra+ (mottagare `3837:1014` och USB-kabel `3837:4028`; laddning visas när den är inkopplad), MSI VERSA 300 ELITE WIRELESS (dongel `0DB0:9E22`; laddning och hantering av viloläge otestat), MSI Clutch GM31 Lightweight Wireless (mottagare `0DB0:0D3C`; GM41 använder samma drivrutin från en ägares infångningar), AJAZZ AK820 MAX (dongel `05AC:024F`), AULA HERO 68 Air (8K Wireless Receiver `372E:106C`), AULA SC580 (USB-kabel `088D:062E` och mottagare `089D:062F`, inklusive laddning och viloläge), AirPods Pro 3 (Bluetooth, modell `2027`), AirPods Max (Bluetooth, modell `200A`), Sprime PM1 (mottagare `1915:AC1C`), Ninjutso Ten Air (mottagare `093A:EB01` och USB-kabel `093A:E020`), MOONDROP GM01 Pro (dongel `35D8:0133`), Delux M800 Pro (mottagare `248A:5B2F`), Razer Barracuda X (2022) (mottagare `1532:0550`; batterinivå avläst, laddningsövergångar otestade), Razer BlackShark V3 X (HyperSpeed-dongel `1532:057D`), Fantech Helios Go XD5 (dongel `25A7:FA7C`), Fantech Raigor III (dongel `1EA7:0066`; laddning rapporteras inte av firmwaren), Finalmouse UltralightX (dongel `361D:0100`), Finalmouse Starlight X (på sin dongel) och Chimera V2 (mottagare `3554:F512`; batterinivå och laddning avlästa).
Även hårdvarutestad: Machenike L7 Arctic / L7 Mix (`248A:FF4C`-mottagare och `248A:FF4E`-kabel), inklusive laddning och dubblettundertryckning mellan kabel och mottagare. Bluetooth och gränsvärden för lågt/fullt batteri har inte hårdvarutestats.
Även hårdvarutestad: MCHOSE V9 Pro 2 (`3837:6011`-dongel); batterinivå avläst, laddning och viloläge otestat.
Även hårdvarutestad: EPOMAKER EA75 på sin `05AC:024F` 2,4 GHz-mottagare, med den befintliga SONiX-drivrutinen från [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). Batteriprocent, återanslutning till mottagaren och återhämtning vid påslagning har verifierats. Laddningsindikering och trådbunden batterirapportering stöds inte av den här drivrutinen; batterirapportering via Bluetooth har inte testats. Den rapporterade procentsiffran kan hoppa till 100 % när USB-ström ansluts, vilket inte är en tillförlitlig laddningsindikator.
Även hårdvarutestad: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (mottagare `1038:1878` och USB-kabel `1038:187A`), inklusive laddning, avstängning (den senaste nivån stannar kvar nedtonad) och med SteelSeries GG igång; GG visar bara en trestegsstapel, vilket nivån stämde överens med.
Även hårdvarutestad: RAWM Leviathan V4 (RAWM HS Receiver `1915:2346`; batterinivå avläst, laddning otestad).
**Implementerat från protokolldokumentation och andra projekt, ännu ej testat:** allt annat, inklusive Fantech Raigor II WG10 (samma `1EA7:0066`-dongel och samling som den testade Raigor III, så den bör fungera). Om du äger någon av dessa enheter, rapportera gärna om den fungerar genom att [öppna ett ärende](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues).

## Installation

[![Senaste version](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Ladda ned **`BatteryHub-Setup-<version>.exe`** från den [senaste utgåvan](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. Kör programmet, välj något av de 19 installationsspråken som stöds och klicka dig igenom guiden. Det kräver **inga administratörsrättigheter** och **inget annat behöver installeras**: inga
   körtidsmiljöer, inga drivrutiner, inga tillverkarappar. HeadsetControl medföljer och den redigerbara mappen `lang\` installeras bredvid `BatteryHub.exe`.

Installationsprogrammet lägger till en genväg i Start-menyn och en avinstallerare (*Inställningar → Appar*), och kan starta appen
när du loggar in. Föredrar du inget installationsprogram? Ladda ned `BatteryHub-<version>-portable.zip`, packa upp filen
var du vill (behåll mappen `lang\` bredvid `BatteryHub.exe` för gränssnittsöversättningar) och kör `BatteryHub.exe`.

**Observera:**
- **SmartScreen-varning:** exe-filen är inte kodsignerad, så Windows kan visa "Windows skyddade din dator". Klicka på *Mer information → Kör ändå*, eller kompilera programmet själv.
- **Systemfältsläge i Windows 11:** nya systemfältsikoner hamnar i överflödsmenyn `^`. Dra ut dem till aktivitetsfältet eller aktivera dem under *Inställningar → Anpassning → Aktivitetsfältet → Övriga systemfältsikoner*.
- **Hålla appen borta från en enhet:** om en enhet beter sig illa medan appen körs kan du ange den i registersträngen `IgnoreDevices` under `HKCU\Software\WirelessBattery` som `VID:PID`-par (hexadecimalt, åtskilda med kommatecken, t.ex. `28BD:0947, 1234:ABCD`; `--dump` visar ID:na). Appen öppnar den då aldrig. Ritplattor hoppas över automatiskt.

## Uppdateringar i Windows

Officiella stabila Windows-byggen söker efter projektets senaste publicerade stabila utgåva i
bakgrunden, 30 sekunder efter start och därefter var 24:e timme medan appen körs. Öppna
menyn för att se **Uppdatering tillgänglig: vX.Y.Z...**, eller välj **Sök efter uppdateringar...** manuellt.
Uppdateringsinformation visas endast i denna meny: batteriikoner, procenttal och verktygstips förblir
desamma, och automatiska kontroller visar aldrig någon avisering eller dialogruta. Stäng av
**Sök efter uppdateringar automatiskt** i menyn för att inaktivera bakgrundskontroller.

För en installerad kopia klickar du på uppdateringsposten och **Ladda ned och installera**. Inget installeras
utan det klicket. Appen laddar ned utgåvans `SHA256SUMS.txt` och dess signatur, kontrollerar
signaturen mot underhållarens publika nyckel som är inbyggd i appen, laddar ned Windows-installationsprogrammet
och kör det bara om dess SHA-256 stämmer med den signerade listan (och den som GitHub anger för filen). Det
uppdaterar sedan den befintliga installationen. Inställningar och val för autostart
bevaras, och appen startar om efter installationen. En installation för alla användare kan be om
administratörsbehörighet. **Uppdateringsanteckningar** öppnar den officiella releasesidan; **Senare** behåller
din nuvarande version. Portabla kopior hänvisar till releasesidan för att ladda ned ZIP-filen manuellt.

Kontroller kontaktar GitHubs publika API utan konto eller token. Ingen enhets- eller batteriinformation
skickas. Offlinefel och GitHubs hastighetsgränser låter batteriövervakningen fortsätta att köras; en tidigare
hittad utgåva stannar kvar i menyn tills en lyckad kontroll ersätter den eller den installeras.
Att avbryta en nedladdning väntar på att den pågående nätverksåtgärden når sin tidsgräns.
Installationsprogrammet startar aldrig om Windows automatiskt.

**Varför uppdateringar är säkra att installera:** signeringsnyckeln hamnar aldrig på GitHub. Underhållaren signerar
varje utgåvas kontrollsummelista på sin egen dator (se [docs/releasing.md](#sec-releasing)), så
även om någon tog över GitHub-kontot eller dess byggarbetsflöde skulle de inte kunna publicera en uppdatering
som appen accepterar att installera. En utgåva utan giltig signatur visas i menyn men kan endast laddas
ned manuellt. Signaturen ersätter inte Windows egna SmartScreen- eller UAC-dialoger.

Installera den första utgåvan som innehåller den här funktionen manuellt en gång. Utvecklings- och testbyggen inaktiverar
officiella uppdateringskontroller så att lokala ändringar inte kan ersättas av misstag. Uppdateringar för Linux och
automatiskt utbyte av portabla kopior är uppskjutna till senare.

## Kommandorad

```
BatteryHub.exe --list     # skriv ut varje enhet och dess batterinivå, avsluta sedan
BatteryHub.exe --json     # skriv ut en JSON-array med enheter och batterinivåer, avsluta sedan
BatteryHub.exe --dump     # varje HID-samling, HID-enheter som inte kunde öppnas, alla USB-enheter (även de
                               # utan HID-gränssnitt) och Bluetooth-enheter; sparas även i %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # öppna fönstret "Begär stöd för en enhet"
BatteryHub.exe --demo     # visa exempelenheter för alla märken istället för verkliga enheter (skärmdumpar, färgkontroll)
BatteryHub.exe --quit     # avsluta den körande instansen
```

Linux-bygget använder samma flaggor med `wireless-battery` istället för `BatteryHub.exe`, och
accepterar även `--help`. `--json` skriver ut en stabil array som skript och panelwidgetar kan tolka:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` anger hur länge appen fortsätter att visa den senast kända nivån medan enheten sover.
Att lägga till nya fält är bakåtkompatibelt.

**Visas inte enheten?** Högerklicka på widgeten eller systemfältsikonen och välj **Begär stöd för en enhet...**. Välj enheten, granska
vad som kommer att skickas (det visas ord för ord: enhetens namn, typ, USB-/HID-ID:n och gränssnittslayout samt ditt valfria
namn och anteckningar) och klicka på **Skicka**. Den läggs till på den offentliga listan på [krisgfx.com/tools](https://krisgfx.com/tools/#requested) och
öppnar eller uppdaterar ett GitHub-ärende. **Kopiera fullständig rapport** lägger hela `--dump`-utdatan i urklipp för ärendet.
Rapportdata skickas endast när du klickar på Skicka. Officiella Windows-byggen kan även kontakta GitHub
för att söka efter uppdateringar enligt beskrivningen i [Uppdateringar i Windows](#uppdateringar-i-windows); uppdateringskontroller
skickar ingen enhets- eller batteriinformation.

## Kompilering

Du behöver [MinGW-w64](https://www.mingw-w64.org/), t.ex. från [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # utvecklingsbygge, version 0.0.0
build.bat                                 # ren cmd med g++ och windres i PATH
make VERSION=1.2.3 CHANNEL=test            # versionssatt bygge, officiella uppdateringar inaktiverade
build.bat 1.2.3 test                       # motsvarande versionssatta cmd-bygge
make test VERSION=1.2.3 CHANNEL=test       # regressionstester för enheter och uppdaterare
```

För att bygga installationsprogrammet och den portabla zip-filen, installera [Inno Setup](https://jrsoftware.org/isinfo.php),
kompilera först med avsedd version (till exempel `make VERSION=1.2.3 CHANNEL=test`) och kör sedan
`powershell -File installer\build-installer.ps1 -Version 1.2.3`. Paketeringen avvisar en version som
skiljer sig från den körbara filen. Den laddar ned den fastställda
HeadsetControl-utgåvan och verifierar dess kontrollsumma. GitHub Actions gör allt detta automatiskt:
att pusha en tagg som `v1.0.0` publicerar en utgåva med installationsprogrammet, den portabla zip-filen och
källkoden till HeadsetControl (enligt kraven i dess GPL-licens).

Windows-byggen behöver även PowerShell för att generera den delade versionsfilen för program och resurser.
Det officiella arkivets versionstaggar byggs med `CHANNEL=stable`; lokala byggen använder `dev` som standard.
Forkar och pull requests aktiverar inte officiella uppdateringar automatiskt.

`BatteryHub.exe` fungerar även på egen hand. Utan `headsetcontrol.exe` bredvid (eller i `PATH`)
går du bara miste om de extra headseten.

## Linux (experimentellt)

Ett Linux-bygge finns vid sidan av Windows-appen. Det använder samma tillverkardrivrutiner med en hidraw-baserad
HID-backend och en GTK4 StatusNotifierItem-systemfältsikon; Windows-kodvägen är oförändrad.
Alla Linux-specifika filer ligger i `linux/` och `src/linux/`, och `build-linux.sh` bygger det (Windows fortsätter att använda `build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Kompilator och make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

Inget extra HID-bibliotek behövs (`hidraw` används direkt).

```sh
./build-linux.sh
./build-linux.sh test         # enhetstest för tolken av HID-rapportdeskriptorer
./wireless-battery --list     # skriv ut upptäckta nivåer och avsluta
./wireless-battery --dump     # lista HID-samlingar
./wireless-battery --quit     # avsluta den körande systemfältsinstansen
```

HID-åtkomst kräver en udev-regel, annars startar appen men hittar inga enheter:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# logga ut och in igen
```

Systemfältsikonen fungerar direkt i KDE Plasma; GNOME behöver en AppIndicator-värd såsom
`gnome-shell-extension-appindicator`. Växling mellan flera språk fungerar via undermenyn *Språk*
(följer `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` som standard och lokaliserar även `--help`).
Kommandot `make -f linux/Makefile.linux install` installerar binärfilen, `lang/*.json` till
`$(PREFIX)/share/wireless-battery/lang/`, samt skrivbordsstartaren (`linux/wireless-battery.desktop`)
och `linux/wireless-battery.svg` till `$(PREFIX)` (standard är `~/.local`); användarens språkåsidosättningar
ligger i `~/.config/wireless-battery/lang/`.

Fas 1 täcker Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious,
Finalmouse och de delade protokollen för Kysona/Pulsar/ATK/G-Wolves. Bluetooth-/UPower-reservlösningar, HeadsetControl och
övriga tillverkare planeras för kommande faser.

## Begränsningar

- **Fulla aktivitetsfält:** med ett mycket fullt centrerat aktivitetsfält i Windows 11 kan appknapparna nå fram till widgeten. I Windows 10 smalnas området för aktivitetsfältsknapparna av automatiskt.
- **Telefoner:** läses från en fil som Telefonlänk skriver för Start-menyns följeslagarkort, vilket inte är ett dokumenterat API och kan ändras med uppdateringar av Telefonlänk. Telefonen visas medan Telefonlänk rapporterar den som ansluten; ett kort som är äldre än 3 timmar visas nedtonat. Kortet anger också när telefonen laddas, vilket visas med laddningsblixten.
- **Sovande enheter:** en enhet som sover svarar eventuellt inte. Dess senaste värde förblir synligt, nedtonat. Logitech-mottagare släpper sovande enheter från länken, så deras senaste värde behålls i 30 minuter.
- **Headsetet HECATE G2 Wireless 7.1** (2,4 GHz-dongel `35BB:A009` / `A209`): ingen batterifråga för dess dongel är dokumenterad ännu, så den läses inte av. En USB-infångning medan HECATE-programvaran visar headsetets batteri (se `CONTRIBUTING.md`) är sättet att lägga till stöd.
- **Keychron-tangentbord:** med originalfirmware rapporterar de endast batteriet via Bluetooth (visas via Bluetooth-stödet). Via 2,4 GHz-mottagaren eller kabeln kräver de firmware med batteripatchen ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); om tangentbordet uppdateras från Keychron Launcher tas patchen bort. Keychron-möss stöds.
- **Headsetet Baseus AeQur GH02:** 2,4 GHz-dongeln (`10D6:4802`, Actions-krets) överför endast ljud, medietangenter och kretsens kanal för firmwareuppdateringar, inte batteriet. Anslut headsetet via Bluetooth för att se nivån (visas via Bluetooth-stödet när Windows rapporterar en nivå).
- **Tangentbordet Weikav Lucky65 v1:** firmwaren rapporterar inte batteriet via 2,4 GHz-dongeln (`0603:0351`, Novatek-krets). Tangentbordet har inget kortkommando för batterikontroll, och den officiella konfiguratorn ansluter bara via USB-kabel, inte genom dongeln, så det finns ingen batteriavläsning att visa.
- **Rapoo:** VT-möss som stöds skickar sin status själva (push), så en uppdatering kan vänta upp till 4 sekunder per matchande gränssnitt. Sovande möss kan stanna kvar nedtonade med sin senaste avläsning i upp till 30 minuter. Stödet gäller Nordic 54L-rapport `07` och äldre `BB` (VT3 Pro, VT1 Pro Max); CH584-rapport `08`, kontorsmöss i MT/M-serien och andra firmwareprotokoll täcks inte av den här drivrutinen.
- **GameSir Cyclone Pro:** dongeln överför ingen batterinivå, så den läses från handkontrollen via Bluetooth LE. Parkoppla handkontrollen med Windows en gång (Inställningar > Bluetooth och enheter > Lägg till enhet > Bluetooth > `GameSir-Cyclone Pro`) och fortsätt spela via dongeln. Datorn måste ha Bluetooth. Nivån uppdateras varannan minut, och ingen procentsiffra visas under laddning. Utan parkoppling visas dongeln som en Xbox-kontroll med "Full". Mer information finns i [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM:** musen tillfrågas via sin mottagare, så en sovande mus svarar inte; den stannar kvar nedtonad med sin senaste avläsning i upp till 30 minuter och förlänger varje uppdatering med ungefär en sekund medan den sover. Endast Leviathan V4 på RAWM HS Receiver (`1915:2346`) är testad; övriga modeller kommer från RAWM HUB:s enhetstabell. Leviathan V4 GT och NYX60 (VID `373E`, RAWM HUB 3.0) samt RAWM HS-tangentborden använder andra protokoll och täcks inte.
- **Flydigi:** den här drivrutinen riktar sig till Vader 5 Pro och Apex 5; Bluetooth och andra Flydigi-modeller (till exempel Apex 6) täcks inte. Procentsiffrorna representerar grova batterinivåer. Apex 5 testades på riktig hårdvara via 2,4 GHz-mottagaren och en USB-kabel; Vader 5 Pro följer SDL och Windows-hårdvaruspårningar.
- **Stöds inte ännu:** trådlösa MSI-möss förutom VERSA 300 ELITE och CLUTCH GM31 / GM41, trådlösa MSI-tangentbord, Razer Kraken-headset och andra Barracuda-modeller än Barracuda X (2022) på `1532:0550`, HyperX Pulsefire-möss förutom Haste 2 Wireless / Haste 2 Core Wireless samt Xbox Wireless Headset på Xbox-adaptern: deras batteriprotokoll är inte dokumenterade. Xbox Wireless Headset fungerar via Bluetooth. En USB-infångning från en ägare (se `CONTRIBUTING.md`) är sättet att lägga till dem.
- **Andra enheter:** vissa 2,4 GHz-enheter använder odokumenterade protokoll och stöds inte ännu. Se [CONTRIBUTING.md](#sec-contributing) för hur du kan hjälpa till att lägga till en enhet.

## Så fungerar det

Varje tillverkardrivrutin i [`src/drivers/`](../../src/drivers) känner igen sina enheter via USB-tillverkar- och produkt-ID och skickar endast skrivskyddade batterifrågor. Okända enheter skrivs det aldrig till. De generiska reservlösningarna (HID-batterianvändning, Bluetooth, XInput, HeadsetControl) tittar endast på enheter som ingen tillverkardrivrutin har tagit anspråk på.

Aktivitetsfältswidgeten är ett skiktat underfönster till `Shell_TrayWnd`, placerat till vänster om `TrayNotifyWnd`. Om Utforskaren startar om skapas widgeten på nytt.

## Översättningar

Varje språk för gränssnittet är en vanlig statisk UTF-8-textfil i [`lang/`](../../lang): engelska till vänster och översättningen till höger. Språkfiler läses från disk vid körning snarare än att kompileras in i den körbara filen, så du kan redigera dem direkt utan att bygga om.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **Appgränssnitt (Windows och Linux):**
  - Redigera eller lägg till `.json`-filer direkt i mappen `lang/` bredvid `BatteryHub.exe` (eller `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/`, eller `./lang/` på Linux).
  - Eller välj *Språk → Lägg till ditt eget språk...* i menyn för att förbereda din användarmapp för åsidosättningar (`%APPDATA%\WirelessBattery\lang` på Windows, `~/.config/wireless-battery/lang` på Linux) med `_template.json`. Kopiera `_template.json` till t.ex. `it.json`, fyll i `@code`, `@name` och översättningarna så dyker det upp i menyn (ingen omstart behövs). Filer i användarmappen åsidosätter inbyggda fraser med samma `@code`.
  - Behåll `{placeholders}` som de är och lägg till `"@rtl": true` för skriftsystem från höger till vänster. Fraser som lämnas tomma förblir engelska, så en partiell översättning fungerar fint.
  - Utdatan från `--list` och `--dump` förblir engelsk med flit: den klistras in i GitHub-ärenden.
- **Windows-installationsprogrammet:** Inno Setup-översättningar finns i [`installer/lang/`](../../installer/lang) (sparade som UTF-8 med BOM) och registreras under `[Languages]` i `installer/BatteryHub.iss`.
- **Dokumentation:** varje synligt projektdokument översätts som en enda fristående Markdown-fil per språk i [`docs/i18n/`](README.md) (se [`docs/i18n/_template.md`](_template.md) för att lägga till ett nytt språk utan byggskript).
- **Dela med alla:** skicka en pull request med dina filer i `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` och `docs/i18n/`. Se [`docs/i18n/README.md`](README.md) för den stegvisa checklistan.

## Erkännanden

Appikon av [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

Protokollen kommer från följande projekts efterforskningar:

- [Google Fast Pair-specifikation](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): batteriutsändningar för vänster / höger / etui på Fast Pair-öronsnäckor
- [HeadsetControl Astro-drivrutiner](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) och [AstroBar](https://github.com/nichtlegacy/AstroBar): batteriprotokoll för Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): A50 Gen 3 `0x72`-statusläsning

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): VAXEE-kommandon för batteri och laddning ([protokolldokumentation](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): headset från SteelSeries, Corsair, HyperX, Logitech och Sony INZONE
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) och [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) och Logitech HID++ 2.0-dokumenten: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) och [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (`0ADF`-dongel)
- [rivalcfg](https://github.com/flozz/rivalcfg): SteelSeries-möss (Rival Pro från dess pull request #294)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) och [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Hitscans webbkonfigurator ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- Linux `hid-kysona` (Lode Willems): Kysona, Pulsar och ATK
- ATK:s webbkonfigurator ([hub.atk.pro](https://hub.atk.pro)): ATK-möss samt headseten N9 Pro / N9 Ultra
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 och [mouse-battery](https://github.com/qwr79/mouse-battery): ATK / VXE NK NANO-dongel
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X och Endgame Gear XM2we, porterade från dess providers (varje drivrutin anger sin källa)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` och [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (endast rön): enhetsfamiljen Turtle Beach Swarm II
- G-Wolves webbdrivrutin ([mouse.xyz](https://mouse.xyz)): G-Wolves-modeller och deras protokoll
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): CHERRY-tangentbord på 2,4 GHz-dongeln (ramformat och batterifråga)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): Keychron-möss
- [NinjaForce](https://www.ninjaforce.co/) och [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): feature-frågor för Ninjutso Ten / Ten Air
- [nape_pro](https://github.com/nvalis/nape_pro) och [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro på Link-KM-mottagaren
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): LAMZU-möss
- [vole](https://github.com/johanneszab/vole) och [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): Endgame Gear 4K-möss
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) och [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) och [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (från Finalmouses xpanel)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) och [g49-web-control](https://github.com/pingpingjinping/g49-web-control): Redragon-ID:n
- [m913-ctl](https://github.com/Qehbr/m913-ctl) och [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): Areson `25A7`-ramlayout och `GetPower`-kommando
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) och [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW och DW
- RK:s webbdrivrutin ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) och [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (dokumentation): MCHOSE A5 Pro / A5 Pro Max (första generationen, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): CompX-mottagarrapporter för Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) och [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) och [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- Wraiths webbdrivrutin ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 och [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 och [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) och [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) på mottagaren `1532:0550`; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): inramning för mottagaren `1532:0552`
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): Rongyuan- och Xenta-mottagare (Attack Shark med flera)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): SONiX-tangentbord på sin 2,4G-dongel (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) och [ak820-studio](https://github.com/usharik/ak820-studio): AJAZZ AK820 Pro-mottagare `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) och [Kraber](https://github.com/AkashPanja/Kraber): Semico `1A2C` (`AA 55 CC 33` / `0x0E`) statusprotokoll för Attack Shark X98 och AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) och [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 och MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) och [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): GameSir Cyclone Pro Bluetooth LE "base info"-batteribegäran
- [jabridge](https://github.com/Watchdog0x/jabridge): Jabra GNP-protokoll (Link 380 / 390-donglar)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): `1EA7:0066` statussideprotokoll (Fantech Raigor III och andra generiska 2.4G Mouse-enheter)
- Linux `hid-playstation`: rapportlayout för DualShock 4 / DualSense
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): AULA SC580 / SC580X tillverkarprotokoll
- RAWM HUB-webbapp ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) och dess enhetstabell: RAWM-möss och SADES Dagger
- [SDL:s Flydigi HID-drivrutin](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) och [HaloBattery-ärende #191](https://github.com/HeyOkay/HaloBattery/issues/191): frågeinramning och batterilayout för Vader 5 Pro och Apex 5
- [SDL:s 8BitDo HID-drivrutin](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): 8BitDo Ultimate 2-batteribyte
- BEITONG iControl (dess sidor för KP20 och KP40D samt USB-trafiken från KP20-mottagaren): batterifråga och nyttolastblandning för BEITONG KP20 / KP40D
- [SDL:s 8BitDo HID-drivrutin](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) och [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): 8BitDo-batteribyte och tillverkar-HID-protokoll
- JBL QuantumENGINE (dess HIDV3-enhetsinfomeddelanden): JBL Quantum-headset
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, Compx-protokoll på `FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) och [BrimDeck](https://github.com/MoFeng2223/BrimDeck): profilläsning för Scyrox V12M
- JBL QuantumENGINE: HIDV1-anslutnings- och batterirapporter för Quantum 350 samt HIDV3-enhetsinfomeddelanden för nyare Quantum-headset
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): JBL Quantum 610 HIDV1-batteri- och länkrapporter samt Quantum-serien (360 som en HIDV1-dongelmodell)

## Licens

[GNU General Public License v3.0 eller senare](../../LICENSE). Du får använda, modifiera och vidaredistribuera den här
programvaran, men allt du distribuerar som bygger på den måste släppas under samma licens,
med sin källkod.


---

<a id="sec-contributing"></a>
> 📄 **Avsnitt:** Bidra (`CONTRIBUTING.md`) · [Engelskt original](../../CONTRIBUTING.md) · [↑ Till toppen](#top)

# Bidra

## Rapportera om en enhet fungerar

De flesta drivrutiner skrevs utifrån protokolldokumentation och kunde inte testas på varje modell.
Öppna gärna ett ärende (issue) med:

- enhetens namn och om den är ansluten via mottagare, kabel eller Bluetooth
- utdatan från `BatteryHub.exe --list`
- utdatan från `BatteryHub.exe --dump`
- vad tillverkarens egen programvara visar som batterinivå

## Lägga till en enhet

1. Kör `BatteryHub.exe --dump` och leta upp enhetens tillverkar- och produkt-ID samt de
   tillverkarspecifika samlingarna (usage page `FFxx`) med deras rapportstorlekar.
2. Hitta batteriprotokollet. Bra ställen att leta på: HeadsetControl, OpenRazer, Solaar, rivalcfg,
   OpenRGB, OpenLinkHub eller en USB-infångning av tillverkarens programvara (Wireshark + USBPcap).
3. Om tillverkaren redan har en drivrutin i `src/drivers/`, lägg till produkt-ID:t (och eventuella skillnader) där.
   Skapa annars `src/drivers/<vendor>.cpp`:

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

4. Deklarera funktionen i `src/drivers/drivers.h` och anropa den från `PollAllDevices()` i
   `src/devices.cpp` (före de generiska reservlösningarna). `build.bat` och Makefilen plockar upp nya filer automatiskt.
5. Uppdatera enhetstabellen i `README.md`.

### Regler för drivrutiner

- **Endast läsning (read-only):** skicka bara förfrågningar som läser tillstånd. Ändra aldrig inställningar, belysning eller lägen.
- **Exakt matchning:** kommunicera bara med enheter du känner igen via tillverkar- och produkt-ID, eller via en
  tillverkarspecifik samling som är unik för protokollet.
- **Ha alltid en tidsgräns:** en frånvarande enhet får inte fördröja pollen i mer än ungefär en sekund.
  Passiva protokoll kan behöva längre tid för att täcka ett dokumenterat push-intervall (till exempel Delux och
  Rapoo). Håll en enda absolut tidsgräns på högst 4 sekunder per matchande samling, starta inte om
  den för orelaterade rapporter och dokumentera varför undantaget behövs.
- **Ange källor:** citera var protokollet kommer ifrån i en kommentar överst i filen.

## Översättningar

UI-språk är vanliga statiska UTF-8-textfiler i `lang/` som läses från disk vid körning på både Windows och Linux (kopiera `lang/_template.json` till `lang/<code>.json`, fyll i `@code`, `@name` och fraserna — ingen omkompilering krävs). Ny gränssnittstext i koden går genom `T(L"...")`, eller `TF(L"... {name} ...", { { L"name", value } })` när den innehåller värden; bygg aldrig upp översatta meningar av delar. Efter att ha lagt till fraser, lägg även till dem i `lang/_template.json`.

Översättningar av Windows-installationsprogrammet finns i `installer/lang/*.isl` (sparade som UTF-8 med BOM och registrerade i `installer/BatteryHub.iss`), Linux-startarens kommentarer finns i `linux/wireless-battery.desktop` och fullständiga dokumentationsöversättningar finns i `docs/i18n/<code>.md` (en enda fristående fil kopierad från `docs/i18n/_template.md`). Se [`docs/i18n/README.md`](README.md) för den fullständiga bidragsgivarguiden.

## Kodstil

Endast C++17 och Win32, inga beroenden från tredje part. Håll binären liten. Formatera ungefär som
den befintliga koden gör (4 blankstegs indrag, 120-teckenrader).

## Utveckling av Windows-uppdateraren

Uppdateraren gäller endast Windows och använder WinHTTP, BCrypt och det befintliga Inno Setup-installationsprogrammet.
Behåll uppdateringsstatus uteslutande i menyn. Lägg inte till uppdateringsikoner, brickor, ändringar i
batteriverktygstipset, pratbubblor, toast-aviseringar eller automatiska dialogrutor. Enhetspolling körs separat från nätverksarbete.

Byggversion och kanal delas av C++ och Windows-resursen via den genererade filen
`build/version.h`. Använd `make VERSION=1.2.3 CHANNEL=test` eller `build.bat 1.2.3 test` för lokal
testning; `dev` är standard och `stable` aktiverar officiella utgivningskontroller. Versionskomponenter
måste rymmas inom 0..65535. Endast det officiella arkivets arbetsflöde för versionstaggar väljer `stable`
automatiskt. Gör inte ett fork-bygge till en officiell uppdateringskanal av misstag.

Kör `make test VERSION=1.2.3 CHANNEL=test` för befintliga enhetstester plus strikt release-tolkning,
versionsordning, schemaläggning av kontroller, riktiga SHA-256-filkontroller, citattecken för argument och skydd i hjälpfunktioner.
Uppdateringsregressioner täcker även avbrytning när nedladdningen slutförs, dialogskydd och misslyckanden
med att konfigurera HTTP-tidsgränser/omdirigeringsbegränsningar. Windows-testet inkluderar implementationerna,
enligt det befintliga mönstret för Linux-backendtester, och ersätter HTTP-sändning så att dessa tester
inte kan kontakta GitHub. Inga testspecifika styringångar läggs till i produktionskoden.
Enskilda mål är `make test-update-core` och `make test-update-win`. Inbyggda uppdateringstester
länkar applikationsresursen för att aktivera Common Controls v6. Tester använder lokala data och
laddar inte ned, höjer inte behörighet, installerar inte och ändrar inte användarens autostartinställningar. Applikationens
produktionsslutpunkt kan inte åsidosättas för tester.

Före paketering, kör
`powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`.
`installer/build-installer.ps1 -Version 1.2.3` kör också denna kontroll innan beroenden laddas ned.
Installationssökvägen `/WBUPDATE=1` bevarar befintlig autostart/inställningar och överlåter omstart till det
tillfälliga hjälpprogrammet. Hjälpprogrammet förblir under den ursprungliga användaren och begär höjd behörighet endast för en global installation.
WinHTTP-handtag tillhör arbetaren; avbrytning sker kooperativt mellan anrop med ändlig tidsgräns.
Den slutliga nedstängningen av appen inväntar den arbetaren och kan därför vänta på en pågående nätverkstidsgräns.

För en release-granskning, använd ett tillfälligt Windows-konto eller en virtuell maskin för att prova två verkliga
installationsversioner, omfattning per användare/globalt, UAC-avbrytning, autostart på/av, anpassade sökvägar, installationsfel
och omstart. Enhetstester och kompilering av ett paket verifierar inte de installationseffekterna. Visuell
granskning av menyer/teman och riktiga slut-till-slut-tester av installationsprogram/UAC förblir manuella utgivningskontroller; markera dem inte
som godkända om de inte faktiskt har observerats. Testa aldrig genom att skriva över den dagliga användarens installation.

## Automatisk säkerhetskontroll

Varje pull request skannas av "PR safety check" efter saker som den här appen aldrig ska göra (nätverksåtkomst,
starta program, läsa tangentbord/urklipp/skärm, autostartsposter, binärfiler, bygg- eller
utgivningsändringar). En flaggning är inget avslag: förklara bara de flaggade raderna i PR-beskrivningen.

Att använda AI-verktyg går bra, men ta bort `Co-authored-by`-rader som krediterar dem (till exempel
`Co-authored-by: Claude ...`) från dina commit-meddelanden. Kontrollen misslyckas så länge de finns kvar.


---

<a id="sec-pr-template"></a>
> 📄 **Avsnitt:** Mall för pull requests (`.github/pull_request_template.md`) · [Engelskt original](../../.github/pull_request_template.md) · [↑ Till toppen](#top)

## Vad detta lägger till

<!-- Enhet(er) och tillverkar-/produkt-ID:n, t.ex. "Acme M1 (1234:5678)". -->

## Var protokollet kommer ifrån

<!-- Länka källan (ett annat projekt, en tillverkares webbdrivrutin, din egen USB-infångning). -->

## Testad på riktig hårdvara?

<!-- Ja (vilken enhet, vad --list skrev ut) / Nej -->

## Checklista

- [ ] Endast skrivskyddade batterifrågor skickas; inga inställningar, belysning eller firmware ändras
- [ ] Endast enheter som känns igen via tillverkar-/produkt-ID (eller en protokollspecifik samling) berörs
- [ ] Ingen nätverksåtkomst, inga startade externa program, inga nya filer utanför `src/`, `docs/` eller `README.md`
- [ ] Inga binärfiler eller genererade filer ingår
- [ ] Inga `Co-authored-by`-rader som krediterar AI-verktyg (Claude, Copilot, ChatGPT ...) i commit-meddelandena
- [ ] Ändringar i `.github/`, `installer/`, `build.bat` eller `Makefile` förklaras ovan


---

<a id="sec-releasing"></a>
> 📄 **Avsnitt:** Utgivning (`docs/releasing.md`) · [Engelskt original](../../docs/releasing.md) · [↑ Till toppen](#top)

# Utgivning

Appen uppdaterar sig själv från GitHub-utgåvor, men den installerar bara ett installationsprogram vars SHA-256 finns med i
en `SHA256SUMS.txt` signerad med utgivningsnyckeln. Den nyckeln finns på underhållarens dator, aldrig på
GitHub: ett kapat konto, en token eller ett arbetsflöde kan publicera filer, men inte en signatur som appen accepterar.

## En gång: skapa utgivningsnyckeln

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Frågar efter ett lösenord (12+ tecken) och skriver den krypterade privata nyckeln till
  `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- Lägger in den publika nyckeln i `src\update_public_key.h`. Committa den filen. Officiella byggen vägrar
  kompilera utan en nyckel i den.
- **Säkerhetskopiera nyckelfilen och spara lösenordet** (en lösenordshanterare är en bra plats för båda).
  Om någon av dem går förlorad kan installerade appar inte längre uppdatera sig själva: du måste då skapa en ny
  nyckel och varje användare måste installera en utgåva för hand.

## Varje utgåva

1. Pusha en versionstagg (`git tag v1.2.3 && git push origin v1.2.3`). CI bygger installationsprogrammet, den
   portabla zip-filen och `SHA256SUMS.txt`, och publicerar utgåvan.
2. Signera kontrollsummelistan:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Det laddar ned `SHA256SUMS.txt` från utgåvan, visar den, ber dig bekräfta, frågar efter nyckelns
   lösenord och skriver `SHA256SUMS.txt.sig`. Om du har samma filer i `dist\` (ett lokalt bygge av
   den versionen) visar det om de stämmer överens.
3. Ladda upp `SHA256SUMS.txt.sig` till utgåvan (skriptet öppnar redigeringssidan). Från och med då erbjuder appen
   **Ladda ned och installera**. Före det visar den uppdateringen men länkar bara till utgåvans sida.

Signera bara en lista för en utgåva som du själv har publicerat. Signaturen säger "exakt dessa filer är
utgåvan", så signeringen är steget där en skadlig uppladdning skulle upptäckas.

## Byta nyckel

Kör `new-release-key.ps1` med en ny `-KeyFile`: den lägger till den nya publika nyckeln bredvid den gamla i
`src\update_public_key.h`. Släpp en version signerad med den gamla nyckeln som innehåller båda, signera sedan
med den nya nyckeln från och med nästa utgåva och ta bort den gamla nyckeln senare. En förlorad eller läckt nyckel
kan inte pensioneras på det här sättet: ta bort den från header-filen, så måste användare av äldre versioner installera
nästa utgåva manuellt.

## Vad appen kontrollerar innan ett installationsprogram körs

- Utgåvan är arkivets senaste, inte ett utkast eller en förhandsvisning (prerelease), och är nyare än appen.
- `SHA256SUMS.txt.sig` är en giltig ECDSA P-256-signatur av `SHA256SUMS.txt` gjord med en nyckel i
  `src\update_public_key.h` (Windows BCrypt, ingen tredjepartskod).
- Den signerade listan namnger `BatteryHub-Setup-<version>.exe` exakt en gång, med samma SHA-256
  som GitHub rapporterar för filen.
- Det nedladdade installationsprogrammet har exakt den storleken och SHA-256. En kopia av appen kontrollerar den sedan igen
  precis innan den startas och håller filen låst så att den inte kan bytas ut däremellan.
- Nedladdningar använder endast HTTPS till `github.com`, `objects.githubusercontent.com` och
  `release-assets.githubusercontent.com`, med kontroll av varje omdirigering.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Avsnitt:** Keychron-tangentbordets firmware (`docs/keychron_keyboard_firmware/README.md`) · [Engelskt original](../../docs/keychron_keyboard_firmware/README.md) · [↑ Till toppen](#top)

# Keychron-tangentbordets batteri via 2,4 GHz-mottagaren

Keychrons originalfirmware rapporterar bara tangentbordets batteri via Bluetooth. Med den lilla QMK-ändringen i
[`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch) svarar tangentbordet också på en batterifråga (`A4`) genom
Keychron Link-mottagaren och via USB-kabeln, och BatteryHub visar dess nivå, spänning och laddningstillstånd.

Testat på **Keychron K5 Max ANSI RGB** (`3434:0A50`) med Keychron Link-mottagaren (`3434:D030`).

## Vad patchen ändrar

Baserad på [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) grenen `2025q3` (commit `57e682c`):

- lägger till råa HID-kommandot `KC_GET_BATTERY` (`0xA4`) från [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1):
  svar `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`;
- skickar vidare råa HID-begäranden som anländer över den trådlösa länken till samma hanterare;
- i `keyboards/keychron/k5_max/config.h`: `#define WILRESS_RAW_ENABLE` (stavat så i Keychrons kod) och
  `#define KC_BATTERY_MODEL_ID 0`.

Inget annat ändras: tangentuppsättningar, belysning och Keychron Launcher fortsätter att fungera.

## Alternativ 1: flasha den färdigbyggda K5 Max-firmwaren

Ett bygge för **endast K5 Max ANSI RGB** är bifogat till
[denna utgåva](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)
(`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`).
Flasha den inte på någon annan modell eller layout.

## Alternativ 2: bygg den själv

Kräver Git och Docker (eller en fungerande [QMK-miljö](https://docs.qmk.fm/newbs_getting_started)).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

Resultatet blir `keychron_k5_max_ansi_rgb_keychron.bin` i arkivets rot. På Windows är en bind-monterad
utcheckning mycket långsam i Docker; att klona inne i containern (eller i WSL) går mycket snabbare.

**Andra trådlösa Keychron-tangentbord** (Q/V/K Max och andra modeller på `2025q3`-trädet med `LK_WIRELESS_ENABLE`):
ändringarna under `keyboards/keychron/common/` gäller direkt som de är. Lägg till de två `#define`-raderna i ditt tangentbords
`config.h` istället för K5 Max-filen, och bygg ditt eget mål, t.ex. `make keychron/<model>/<layout>/<variant>:keychron`.
Appen namnger för närvarande en K5 Max (`0A50`–`0A58`) efter modell och alla andra som "Keychron keyboard".

## Flashning

1. Ställ lägesomkopplaren på **Cable** och koppla ur USB-kabeln.
2. Håll in **Esc** medan du kopplar in kabeln. Tangentbordet går in i STM32-bootloadern.
3. Flasha `.bin`-filen med [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (eller `dfu-util`).
4. Växla tillbaka till **2.4 GHz** och kontrollera med `BatteryHub.exe --list`:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Att uppdatera tangentbordet från Keychron Launcher ersätter den här firmwaren och tar bort batterirapporteringen. För att återställa,
flasha Keychrons officiella firmware på samma sätt.

## Licens

QMK är under GPL-2.0-or-later; patchen ligger under samma licens. Alla som tar emot en binärfil byggd från den måste
även kunna få tillgång till denna källkodsändring.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Avsnitt:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [Engelskt original](../../docs/gamesir_cyclone_pro.md) · [↑ Till toppen](#top)

# Batteristöd för GameSir Cyclone Pro

## Varför handkontrollen visades som en full Xbox-kontroll

Cyclone Pro (modell T4cp) spelar via en 2,4 GHz-dongel, `3537:1015`. Dongeln presenterar sig
för Windows som en trådbunden Xbox 360-kontroll (XUSB, `Xbox 360 Controller for Windows`). XInput besvarar
sin batterifråga med "Full", så XInput-reservlösningen listade den som `Xbox controller 1` på 100 %
oavsett vad den verkliga laddningen var.

Dongeln bär ingen batteriinformation:
- dess enda HID-samling är XInput-spelkontrollen (`HID\VID_3537&PID_1015&IG_00`)
- den har ingen tillverkardefinierad samling som Nova (`FF7A`) eller Cyclone 2 (`FFF0`)

## Var nivån finns

Medan den spelar via dongeln annonserar handkontrollen även över Bluetooth LE som
`GameSir-Cyclone Pro`, vilket är den länk GameSirs mobilapp använder. Dess begäran "get base info"
returnerar batteriet:

| Steg | Detalj |
|---|---|
| Tjänst (Service) | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Egenskap (Characteristic) | `0x865F` (notify, write without response) |
| Begäran | aktivera aviseringar, skriv `01 01` |
| Svar | 19-bytes avisering (vissa firmwares lägger till prefixet `C9`, 20 byte) |

Svarslayout:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

Byte 18 är batteriet i procent (0–100), eller `FF` under laddning. Ingen nivå rapporteras medan den
laddas, så den senast kända procentsiffran behålls och visas med laddningsblixten.

Handkontrollen har också tjänst `0xFF10`, vilket är GameSirs kanal för firmwareuppdateringar. Drivrutinen öppnar
den aldrig. Handkontrollen har ingen standardiserad Battery Service (`0x180F`), vilket är anledningen till att Windows Bluetooth-sida och
Bluetooth-reservlösningen inte visar någon nivå för den.

Källa: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), där protokollet
utreddes från GameSirs Android-app (`BluetoothLeService`, "get base info").

## Så fungerar drivrutinen

`src/drivers/gamesir_ble.cpp`, som anropas före XInput-reservlösningen:

1. **Hitta handkontrollen.** Den söker efter enhetsgränssnitt av klassen `{00008650-0000-1000-8000-00805F9B34FB}`.
   Windows skapar ett för varje GATT-tjänst på en parkopplad BLE-enhet. Den använder bara de vars överordnade
   `BTHLE\DEV_…`-nod heter `GameSir-Cyclone…`.
2. **Läs av batteriet.** Den öppnar den tjänsten med Win32 GATT API (`bluetoothleapis.h`,
   `-lbluetoothapis`), prenumererar på `0x865F` och skriver `01 01`. Den väntar upp till 3 sekunder på
   svaret och stänger sedan av aviseringar igen.
3. **Håll pollen snabb.** BLE-anslutningen kan ta sekunder eller överskrida tidsgränsen medan handkontrollen
   sover, så frågan körs i en egen tråd:
   - högst varannan minut efter en lyckad läsning, eller varje minut efter en misslyckad
   - pollen rapporterar den cachade avläsningen och slutar rapportera den när den är 6 minuter gammal
   - `graceSec` håller den sedan synlig, nedtonad, som sovande
   - endast den första pollen i en körning väntar på tråden, en gång, med en absolut tidsgräns på 4 sekunder,
     så att nivån visas vid start och i `--list`
4. **Dölj den falska Xbox-posten.** När dongeln är ansluten tar drivrutinen anspråk på `3537:1015`:
   - `Windows.Gaming.Input`-sökvägen hoppar nu över tillverkar-/produkt-ID:n som tagits i anspråk
   - `XInput`-sökvägen hämtar varje kortplats tillverkar-/produkt-ID från `XInputGetCapabilitiesEx` (`xinput1_4`
     ordinal 108) och hoppar över dem som tagits i anspråk
   - när den exporten saknas beter sig XInput som tidigare

## Testad hårdvara

Windows 11, Cyclone Pro på sin dongel (`3537:1015`), parkopplad en gång via Bluetooth, den 2026-11-18:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Medan handkontrollen sov dök posten "Xbox controller 1 / Full" inte längre upp och ingenting
visades för handkontrollen.

## Begränsningar

- **Parkoppling:** handkontrollen måste parkopplas med Windows en gång (Inställningar > Bluetooth och enheter > Lägg till enhet >
  Bluetooth > `GameSir-Cyclone Pro`). Oparkopplade handkontroller har inget GATT-enhetsgränssnitt. Parkoppling lägger till
  Bluetooth-gamepad-poster, men dessa skickar ingen indata medan handkontrollen spelar via dongeln.
- **Bluetooth krävs:** datorn behöver Bluetooth LE.
- **En handkontroll:** endast en Cyclone Pro per dator läses av.
- **Laddning:** det finns ingen procentsiffra under laddning.


---

<a id="sec-localization-guide"></a>
> 📄 **Avsnitt:** Guide för flerspråkighet och lokalisering (`docs/i18n/README.md`) · [Engelskt original](../../docs/i18n/README.md) · [↑ Till toppen](#top)

# BatteryHub flerspråkighetsindex och lokaliseringsguide

Varje synligt dokument i det här arkivet är samlat i **en fristående Markdown-fil per språk** inuti `docs/i18n/`, medan alla textsträngar för programmet vid körning ligger i **statiska redigerbara textfiler** inuti [`lang/`](../../lang) (delade av Windows och Linux) och strängar för Windows-installationsprogrammet ligger i [`installer/lang/`](../../installer/lang).

## Språk som stöds (19)

| Kod | Språk | Komplett dokumentation | Appgränssnitt (Windows och Linux) | Windows-installationsprogram |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (källsträngar) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Så fungerar språkväxling i praktiken

### 1. Windows-appen (`BatteryHub.exe`)
- **Automatisk identifiering:** När inställningen är *Språk → Automatiskt (Windows-språk)* ställer BatteryHub en fråga till Windows `GetUserPreferredUILanguages` och matchar närmaste statiska `*.json`-fil.
- **Manuell växling:** Klicka på aktivitetsfältswidgeten eller systemfältsikonen → **Språk** → välj ett språk. Gränssnittet uppdateras direkt och sparas i `HKCU\Software\WirelessBattery\Language`.
- **Statiska externa filer (redigerbara utan omkompilering):** `BatteryHub.exe` läser först in `<exe>\lang\*.json` och sedan `%APPDATA%\WirelessBattery\lang\*.json`. Alla filer i användarmappen med samma `@code` åsidosätter matchande fraser, och när menyn öppnas på nytt läses filerna om från disk direkt.
- **CLI `--help`:** `BatteryHub.exe --help` visar hjälpdialogen på ditt aktiva gränssnittsspråk (`--list`, `--json` och `--dump` förblir avsiktligt på engelska för felrapporter på GitHub).

### 2. Linux-appen (`wireless-battery`)
- **Automatisk identifiering:** Följer POSIX-lokalvariabler i ordning: `LANGUAGE` (kolonseparerad lista) → `LC_ALL` → `LC_MESSAGES` → `LANG` (om det inte åsidosätts av `LC_ALL=C` / `POSIX`).
- **Manuell växling:** Högerklicka på systemfältsikonen → **Språk** → välj **Automatiskt (systemspråk)** eller något installerat språk. Sparas under `[general] language=` i `$XDG_CONFIG_HOME/wireless-battery/config.ini` (standard `~/.config/wireless-battery/config.ini`).
- **Statiska söksökvägar (från lägst till högst prioritet):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (standard `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (standard `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help` skriver ut översatt CLI-hjälp baserad på `config.ini` eller systemets språkinställning; `--list` och `--dump` förblir på engelska.

### 3. Windows-installationsprogrammet (`BatteryHub-Setup-<version>.exe`)
- Visar en språkväljare (`ShowLanguageDialog=yes`) som förväljer ditt gränssnittsspråk i Windows (`LanguageDetectionMethod=uilanguage`).
- Installerar hela den statiska mappen `lang\*.json` i `{app}\lang\` bredvid `BatteryHub.exe` (och den portabla ZIP-filen levereras på samma sätt med `lang\*.json`).

---

## Så lägger du till eller uppdaterar ett språk (steg för steg)

Du behöver **inga** byggverktyg för att översätta appens gränssnitt eller dokumentationen, och endast Inno Setup 6 om du vill testkompilera Windows-installationsprogrammet.

### Steg 1 — Strängar för appgränssnittet (`lang/<code>.json`)
1. Öppna användarens språkmapp från systemfältsmenyn (**Språk → Lägg till ditt eget språk...**) eller kopiera [`lang/_template.json`](../../lang/_template.json) till `lang/<code>.json` (t.ex. `lang/it.json`).
2. Fyll i metadatahuvudet:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Översätt högersidan efter ` = ` på varje rad.
   - Behåll platshållare som `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}` ordagrant.
   - Använd `\n` för uttryckliga radbrytningar.
   - Spara som **UTF-8 (utan BOM)**.
   - Öppna BatteryHubs systemfältsmeny igen för att förhandsgranska direkt — ingen omkompilering krävs!

### Steg 2 — Windows-installationsprogrammet (`installer/lang/<code>.isl`)
1. Kopiera [`installer/lang/_template.isl`](../../installer/lang/_template.isl) till `installer/lang/<code>.isl`.
2. **KRITISKT:** Spara filen som **UTF-8 med BOM (`EF BB BF`)** så att Inno Setup avkodar Unicode-tecken tillförlitligt oavsett äldre Windows-kodtabeller.
3. Välj matchande mönster:
   - **Inno Setup levererar redan ditt språk** (kontrollera `C:\Program Files (x86)\Inno Setup 6\Languages\`): behåll bara `[CustomMessages]` och översätt de 6 raderna (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, med bevarade `%1` och `%n`). Registrera i `installer/BatteryHub.iss` under `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup levererar inte ditt språk**: kopiera `installer/lang/zh-CN.isl` som fullständig referens, ställ in `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, valfritt `RightToLeft=yes`), översätt `[Messages]` och `[CustomMessages]` och registrera efter `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Obs: `[Languages]` `Name:`-identifierare får endast innehålla ASCII-bokstäver, siffror och understreck (använd `ptBR`, inte `pt-BR`).

### Steg 3 — Skrivbordsstartare för Linux (`linux/wireless-battery.desktop`)
Lägg till en lokaliserad rad `Comment[<code>]=...` (använd understreck för regionala taggar i `.desktop`-filer, t.ex. `Comment[zh_CN]=...`).

### Steg 4 — Komplett dokumentation i en enda fil (`docs/i18n/<code>.md`)
1. Kopiera [`docs/i18n/_template.md`](_template.md) till `docs/i18n/<code>.md` (inga generatorskript behövs — bara denna enda fil!).
2. Översätt innehållsförteckningen och alla 17 avsnitten i sin helhet samtidigt som du behåller:
   - Alla ankartaggar `<a id="sec-..."></a>` och `<a id="top"></a>` oförändrade
   - Alla kodblock, CLI-flaggor (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), USB-`VID:PID`, HID usage pages, hex-paket, registernycklar, filsökvägar och URL:er ordagrant
   - Relativa bild-/filsökvägar intakta (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE` osv.)
3. Uppdatera det översta `<!-- lang-switcher:start -->`-fältet i `docs/i18n/<code>.md` (fetstil på ditt eget språk, länka alla andra), lägg till din språklänk i växlingsfälten i `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` samt syskonfiler i `docs/i18n/*.md`.
4. För höger-till-vänster-språk (`ar`, `fa`, `he`), skriv vanlig Markdown utan att omsluta hela filen i `<div dir="rtl">` så att tabeller och kodblock renderas rent.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Avsnitt:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [Engelskt original](../../docs/ardor_fury_v2.md) · [↑ Till toppen](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

2,4 GHz-mottagaren exponerar HID usage page `000A`, usage `0000` och en
5-bytes inrapport. Den sänder ut data automatiskt; inga HID-kommandon skickas.

Observerade rapporter från riktig hårdvara:

| Rapport | Batteri |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

Den höga nibbeln i byte 3 kodar nivån (`1`, `3`, `7`, `F` för
25, 50, 75 och 100 procent). Rapporterna för 25 % och 100 % har härletts
från tillverkarapplikationens avkodningslogik; slutanvändaren bekräftade därefter
att de återstående nivåerna visas korrekt i den kompilerade appen.
Den femte byten är inte konstant och används inte som signatur.

Lyssnaren kräver två överensstämmande avkodade batterinivåer, snarare än två
identiska helrapporter. Det senast bekräftade värdet behålls i upp till
45 sekunder. Det globala automatiska uppdateringsintervallet ändras till 15 sekunder.

Validerat av slutanvändare i Windows med ARDOR Fury V2 och Logitech G733:
infångningar vid 50 % och 75 %, periodisk automatisk uppdatering, visuell kontroll av 25 %/100 %
och portabel start. Rapporterna för 25 % och 100 % fångades inte in.


---

<a id="sec-areson"></a>
> 📄 **Avsnitt:** Areson `25A7` (`docs/areson.md`) · [Engelskt original](../../docs/areson.md) · [↑ Till toppen](#top)

# Batteristöd för Areson 25A7-mottagare

## Varför det ursprungliga programmet missade musen

Redragon M915RGB-WL ansluter via en Areson/CompX `25A7:FA07` "2.4G Wireless Receiver".
Dess batteri exponeras inte som en standardiserad HID *Battery Strength*-användning och Windows har ingen
Bluetooth-batteriegenskap för den, eftersom länken är en proprietär 2,4 GHz-länk. Musen
svarar istället på en aktiv `GetPower`-begäran, så varken den generiska HID-reservlösningen eller
Bluetooth-reservlösningen kunde se den. Det fanns ingen drivrutin för tillverkaren, så mottagaren förblev
otagen i anspråk och tyst.

## Observerad hårdvara och paket

Testat i Windows 11 med en Redragon M915RGB-WL den 2026-11-17:

| Riktning | VID:PID | Gränssnitt | Usage page:usage | Rapportstorlek |
|---|---|---|---|---|
| begäran (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 byte |
| svar (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 byte |

Svaret anländer på en annan toppnivåsamling än den som begäran skrivs till.
I Windows är dessa `MI_01&COL07` (feature) och `MI_01&COL05` (input), vilket är anledningen till att drivrutinen
öppnar båda handtagen.

Infångad begäran (`GetPower`, rapport-ID `08`, kommando `04`, kontrollsumman gör att ramens summa blir `0x55`):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Infångat svar:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Förskjutningarna nedan räknar rapport-ID som byte noll:

| Byte | Betydelse | Exempel |
|---|---|---|
| 0 | Svarsrapport-ID | `09` |
| 1 | Kommandoeko | `04` |
| 2 | Status, 0 = OK | `00` |
| 3–4 | Adress, oanvänd för `GetPower` | `00 00` |
| 5 | Datalängd (2) | `02` |
| 6 | Batterinivå, 0–10, i steg om 10 % | `08` = 80% |
| 7 | Laddningsflagga, valfritt värde skilt från noll | `00` = laddas inte |
| 16 | Kontrollsumma; alla 17 byte summerar till `0x55` (mod 256) | `3E` |

Tillverkarens egen programvara visade 80 % för samma ram, vilket är det som fastställer ×10-skalan.
`GetConnectStatus` (`08 03 …`) svarar med en 1-bytes nyttolast och rapporterade musen som
länkad samtidigt.

## Andra Areson-möss

De äldre `FA7B` / `FA7C`-mottagarna som används av Redragon M693 rapporterar laddningen direkt som en
hel procentsiffra på samma svarsförskjutning. Att använda den här drivrutinens ×10-skala där skulle visa
800 %, så dessa produkt-ID:n tas avsiktligt inte i anspråk. Endast `FA07` och `FA08` hanteras;
`FA08` är den alternativa identiteten i samma familj och har inte verifierats på den här datorn.

## Polling och identitet

- Drivrutinen skickar endast den skrivskyddade `GetPower`-begäran. Den skriver aldrig konfigurations-,
  belysnings- eller DPI-data.
- Varje uppdatering öppnar feature-samlingen utan åtkomstbegäran och in-samlingen för
  läsning, skickar begäran och väntar upp till 1,8 s på ett svar, med två försök och en tömning
  av kön däremellan så att en gammal rapport inte kan förväxlas med svaret.
- En misslyckad läsning tar ingenting i anspråk, så en sovande mus behåller det senaste värdet i gränssnittet. Posten
  använder en respittid på 30 minuter, vilket motsvarar de andra passiva drivrutinerna.
- Enhetsnyckeln härleds från tillverkar- och produkt-ID (`areson:25A7:FA07`), så den överlever
  mottagnings-/vilocykeln och att mottagaren kopplas ur och in igen.

## Validering

Hela applikationen byggdes med MSVC C++17 och Windows SDK och kördes mot den riktiga
musen. `BatteryHub.exe --list` returnerade:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

Avläsningen stämde överens med den procentsiffra som visades av den officiella Redragon-programvaran i samma
ögonblick. MinGW:s `build.bat` inkluderar den nya källfilen; `Makefile` upptäcker den genom
sitt jokertecken.

## Protokollkällor

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): 17-bytes ramar, uppdelning mellan feature/input och
  `0x55`-kontrollsummeregeln, hämtade från USB-infångningar av Redragon-programvaran.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray):
  `GetPower`-kommandot och 10 %-nivåskalan på `25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md):
  svarslayout och den annorlunda procentskalan i `FA7B` / `FA7C`-familjen.


---

<a id="sec-darkrim"></a>
> 📄 **Avsnitt:** DARKRIM SHADOW (`docs/darkrim.md`) · [Engelskt original](../../docs/darkrim.md) · [↑ Till toppen](#top)

# DARKRIM SHADOW / 寸渊影弑-mottagare

Hårdvarutestad på `3654:6901`, tillverkare `Jieli Technology`, utgåva `0100`.
Använd gränssnitt **3**, usage `FF02:0002`, onumrerade 64-bytes in-/utnyttolaster
(65-bytes Windows HID-rapportstorlekar). Gränssnitt 4 har också `FF02:0002`, men använder
rapport-ID 2 och svarade inte på detta protokoll; det utesluts avsiktligt.

Protokollkälla: den officiella [PC Hub-nedladdningen](https://app.darkrim.net/hub/zh.html),
`DARKRIM-0.1.26-x64-setup.rar`, nedladdad och statiskt uppackad utan att
installera eller starta tillverkarens programvara. Den extraherade `DARKRIM.exe` SHA-256:
`f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Användbara adresser i den binärfilen:

- `140124C80`: `sendGetBasicInfo(infoType)` skickar kommando `0010`, Request `01`,
  nyttolast `[infoType, 00]`. Batteriväljaren är `01`.
- `140118D30`, `140119200`: generering av ramhuvud och CRC.
- `140126DB0`: TLV-tolk för enhetsinfo; TLV `01` är batteri.
- `1400F5660`, `1400FA700`: batterikonsumenter; de sju låga bitarna ger procent,
  den höga biten är laddning. Samma batterivärde anländer även i `0011` Notify `03`.

Huvud: `FE seq cmdLE type index count lengthLE`, följt av nyttolast och
CRC-16/CCITT-FALSE (polynom `1021`, startvärde `FFFF`, lagrat i big-endian).
Sekvensen är en fyrabitars räknare skild från noll; kryptering används inte.

Faktiska begärans-/svarsnyttolaster, före HID-nollutfyllnad:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

Svars-TLV `01 01 28` ger **40 %, laddas inte**. Den skarpa C++-drivrutinen
returnerade det värdet vid tre på varandra följande frågor utan tillverkarprogramvaran.
Mottagaren sänder ut uppstartsaviseringar före det matchande svaret, uppmätt
till cirka 406 ms. Använd en enda svarstidsgräns på 800 ms (plus högst 200 ms för skrivning),
utan att starta om den för orelaterade aviseringar. Inget pulsslag (heartbeat) krävs.

Drivrutinen skickar bara batteri-GET. Den accepterar bara ett okrypterat svar
med matchande sekvens/kommando/typ, index noll, antal noll eller ett (hårdvaran
använder noll), giltig längd/CRC och en enda välformad batteri-TLV.
Fragmenterade, oombedda, felformade och otillåtna svar ignoreras.

## Observerad batteriprecision och laddningstillstånd

Betrakta procentsiffran som en **grov uppskattning, inte en verifierad mätare med 1 %-upplösning**.
Ägarens enhet visade laddningsförloppet i steg om 10 procentenheter från
40 % till 90 %. Vid 90 % bar fem batteri-GET-svar och en oombedd avisering
alla värdet `DA`: `DA & 7F = 90`, där bit 7 anger laddning. Efter att ägaren
kopplade ur laddkabeln och fortsatte använda 2,4 GHz-mottagaren bar ytterligare
fem GET-svar och en avisering alla `5A`: fortfarande 90 %, nu med
laddningsbiten nollställd. Alla tolv ramarna passerade CRC-verifiering.

Representativa frågesvar (sekvens 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Både drivrutinen och den officiella applikationen tar procentsiffran direkt från de
sju låga bitarna. Drivrutinen avrundar inte till tiotal, multiplicerar inte en nivå med tio och
interpolerar inte mellanvärden; syntetiska rapporter på 47 % och 95 % förblir 47 % och
95 % i produktionstolken. De observerade grova avläsningarna härrör därför
uppströms från tolken, i headsetets/mottagarens rapportering. Finare hårdvaruavläsningar
har inte observerats. En hel urladdningskurva har inte spelats in,
så ett fast 10 %-steg vid varje urladdningsnivå eller på annan firmware är obekräftat.

Laddning och efterföljande icke-laddande tillstånd vid 90 % har kontrollerats på hårdvara.
Gränsvärden för lågt/fullt batteri, beteende när headsetet stängs av, Bluetooth
och dataläge via USB-kabel har inte hårdvarutestats. Inget stöd utlovas
för de lägena. Inga firmwareuppdateringar, konfigurationsändringar, EQ-kommandon,
parkopplingsändringar, återställningar eller tillverkarbinärer ingår i den här implementationen.

Test: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Avsnitt:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [Engelskt original](../../docs/hyperx_haste_2.md) · [↑ Till toppen](#top)

# Batteriprotokoll för HyperX Pulsefire Haste 2 Wireless

Läses av `HasteWireless` i `src/drivers/hyperx.cpp`. Frågorna kommer från
[ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) och är desamma som NGENUITY använder.

Verifierat på hårdvara:

- Pulsefire Haste 2 Core Wireless, dongel `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, dongel `03F0:0F98`, av uzumakiprime (PR #312). Nivån stämde överens med HyperX NGENUITY.

Dongeln `03F0:0D97` förväntas fungera på samma sätt men är otestad.

## HID-samling

| Fält | Värde (`0F98`) |
|---|---|
| USB-gränssnitt | `MI_02` (gränssnitt 2) |
| Usage page : usage | `FF00:0001` |
| Rapportlängd in / ut / feature | 64 / 64 / 64 byte |

Dongeln exponerar även standardiserade samlingar för mus och consumer-control. Drivrutinen öppnar bara en
tillverkarsamling (usage page `FF00` eller högre) med inrapporter på minst 8 byte.

## Frågor

Båda är utrapporter: de två första byten nedan, nollutfyllda till rapportlängden. Varje svar är en inrapport
vars första byte är kommandot plus ett. Varje fråga väntar högst en sekund på sitt svar och hoppar över
orelaterade rapporter (efter en återanslutning skickar dongeln rapporterna `44 xx`, `45 xx` och `FB xx` på egen hand).

| Begäran | Svar | Betydelse |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0 när musen är avstängd eller utom räckhåll |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0–100; `charge` 1 = laddas, 2 = full på laddaren; spänning i mV, little endian (0 på Core) |

- Om länksvar saknas avgör batterisvaret.
- Om länken rapporterar 0 skickas ingen batterifråga och musen visas som avstängd.
- Under några sekunder efter att musen slagits på rapporterar den ungefär 40 %. En avläsning inom 6 s efter att länken kommit upp
  ignoreras, och systemfältet behåller det senaste värdet.

Båda förfrågningarna läser bara tillstånd. Ingenting ändrar inställningar, belysning eller lägen.


---

<a id="sec-inphic"></a>
> 📄 **Avsnitt:** Inphic IN10 (`docs/inphic.md`) · [Engelskt original](../../docs/inphic.md) · [↑ Till toppen](#top)

# Inphic IN10-familjen, KP 8K-mottagare

Den anslutna enheten, av ägaren identifierad som IN10 MAX, räknas upp som
`Inphic KP 8K`, `1D57:FA65`, utgåva `0116`. Dess statussamling är
gränssnitt 2, usage `000A:0000`, inlängd 5 (inklusive rapport-ID 03).

Observerad ungefär var fjärde sekund, utan att skicka någon begäran:

```text
03 73 41 01 64
```

Den befintliga Xenta-tolken känner igen detta format: modell, händelse, batteritillstånd,
procentsiffra. Två likadana rapporter krävs innan 100 % visas; den första
rapporten efter länkning kan vara en vilseledande full-avläsning på besläktade mottagare.
Denna ändring bevarar den spärren och det befintliga laddnings-/vilobeteendet.

Den officiella [Inphic HUB](https://hub.inphic.cn/)-samlingen `assets/index-BcHQx9B6.js`
mappar modell decimal 115 (`73`) till `IN10RMax`, och 116 (`74`) till `IN10Max`.
Den använder batteritillstånd 1 för procent, 2 för full och 3 för laddning.
Använd firmwarens modellnamn snarare än att tilldela `73` till IN10 MAX och
eventuellt märka andra enheter som delar denna mottagare fel.

Före den här ändringen listade appen den anslutna musen som `Wireless mouse`.
Xenta-transporten hanterade redan dess batteriramar; ändringen tillför
de saknade modellnamnen. En färsk `--list` kan visa sovande (asleep) eftersom dess fem sekunder långa
inledande observation ibland bara hinner ta emot en rapport per fyra sekunder. Den bakgrundskörande appen
behåller lyssnaren och bekräftar värdet vid en senare polling.

Hårdvaruverifierat: passiva rapporter, upprepad 100 %-nivå och drivrutinens inbyggda
modellidentifiering. Laddningsövergångar, gränser för lågt batteri, Bluetooth och kabelläge
har inte verifierats. Modell `74` är hämtad från den officiella tabellen och
har inte testats på separat hårdvara.


---

<a id="sec-machenike"></a>
> 📄 **Avsnitt:** Machenike L7 (`docs/machenike.md`) · [Engelskt original](../../docs/machenike.md) · [↑ Till toppen](#top)

# Machenike L7 Arctic / L7 Mix

Verifierad på en L7 Arctic som identifierar sig som **L7 Mix**:

| Anslutning | VID:PID | Gränssnitt | Usage | In / ut / max feature |
| --- | --- | --- | --- | --- |
| 2,4 GHz-mottagare | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB-kabel | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

Drivrutinen kontrollerar även HID-produktnamnet `L7 Mix`. Andra Machenike-modeller,
andra mottagar-ID:n och tillverkarfrågor via Bluetooth är inte aktiverade.

## Protokollkälla

Interoperabilitetsanalys av den officiella programvaran **Machenike L7 Mix 1.0.0.8**,
tillgänglig från [tillverkarens drivrutinssida](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/),
samt skrivskyddade frågor på den riktiga musen. `DeviceDriver.exe` SHA-256:
`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

I den 32-bitars körbara filen (image base `00400000`) bygger funktionen på VA `00436750`
statusbegäran; `004494F0` skickar den via `HidD_SetFeature` och läser
feature-svaret. Statustolken `00410C20` extraherar fälten nedan och skickar
batteri- och laddningsfälten till gränssnittet. Dessa är virtuella adresser, inte filförskjutningar.
Ingen proprietär körbar fil, applikationskod eller resurser ingår här.

## Läsningstillståndsfråga

Skicka **21 byte**, rapport-ID `51`, kommando `06`, alla övriga byte noll:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Läs feature-rapport `51`, också med 21 byte. Samlingens maximala feature-storlek
är 1001 för andra rapporter; det är inte längden på statusrapporten.
Drivrutinen väntar 10 ms före läsning och använder en enda tidsgräns på 200 ms per produkt,
inklusive orelaterade svar. Den skickar inga kommandon för inställningar, lägen, makron eller firmware.

Index inkluderar rapport-ID:t:

| Byte | Betydelse / observerade värden |
| --- | --- |
| 0–1 | `51 06`, obligatoriskt kommandoeko |
| 4–7 | `8A 24 4E FF`, den verifierade L7-enhetssignaturen |
| 10, bitarna 0–2 | Arbetsläge: 1 på mottagare, 0 på kabel |
| 10, bit 3 | Trådlös mus ansluten; nollställd även på USB-kabeln |
| 11 | Batteriprocent, 0–100 (noll är giltigt) |
| 12 | Laddningsflagga: 0 laddas ur, 1 laddas |

Andra fält och eventuell kontrollsummesemantik är inte fastställda. Drivrutinen hittar inte på
någon kontrollsumma. Den validerar kommandot, längden, enhetssignaturen, läget och
intervallen för batteri/laddning i anslutet tillstånd innan den publicerar en avläsning.

Infångat mottagarsvar, också 64 % i den officiella appen:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Infångat USB-kabelssvar under laddning (74 %):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

Vid det tillfället returnerade mottagaren fortfarande sitt cachade värde 64 %, men nollställde sin länkbit:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Denna frånkopplade avläsning får inte exponera cachade batteri-/laddningsvärden.
Kabeln har företräde när båda transporterna är anslutna, och den stabila enhetsnyckeln
delas mellan transporterna. En känd L7 reserveras även om frågan misslyckas så att
den senare Ajazz-drivrutinen inte kan prova den med ett annat protokoll på det delade VID:t.

## Valideringsgränser

Fixturer och simulerade transporttester täcker infångade avläsningar, laddning,
giltiga 0 %/100 %, frånkopplade mottagare, felformade/inaktuella svar, strikt matchning,
transportfel, dubblettundertryckning och begränsade omförsöksslingor. Verkliga 0 %/100 %-nivåer
samt alla vilo-/firmwarevarianter garanteras inte av dessa tester.


---

<a id="sec-nuphy"></a>
> 📄 **Avsnitt:** NuPhy WH80 (`docs/nuphy.md`) · [Engelskt original](../../docs/nuphy.md) · [↑ Till toppen](#top)

# NuPhy WH80 (USB-kabel och Bluetooth)

Hårdvarutestad med `19F5:A011`, firmwareutgåva `0116`, gränssnitt 1,
usage `0001:0000`, onumrerade 64-bytes in-/utnyttolaster (65 byte i Windows HID-egenskaper).

Protokollkälla: [NuPhyIO](https://drive.nuphy.io/), samling `main.b3fb29e0.js`,
SDK `getBatteryState(0)`, `getDataPackage` och `createCommand`.
Endast `GetFunc` (`05`), förskjutning `0020`, längd `01` begärs. Ingen initiering,
konfiguration, belysning eller firmwarekommandon behövs.

Begärans nyttolast, nollutfylld till 64 byte:

```text
55 05 00 21 01 20 00 00
```

Faktisk svarsnyttolast:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

Byte 3 är den låga byten av summan av byte 4..63. Batteriet är byte 8:
`value & 7F` är procent, `value & 80` är SDK:s laddningsflagga.
Den skarpa C++-drivrutinen returnerade **100 %, laddas** på det anslutna tangentbordet.
Laddningsövergångar och gränsvärden för lågt/fullt batteri har inte hårdvarutestats;
de officiella firmwareanteckningarna beskriver WH80-avläsningar i steg om 10 %.
Drift via mottagare ligger utanför den här drivrutinens omfattning.

## Bluetooth

Via Bluetooth använder samma tangentbord HID-ID `19F5:324A` (utgåva `0129`) och
annonserar ett användarsynligt namn som `NuPhy WH80 - 1`. Det exponerar två tangentbordssamlingar
och en mussamling. Den generiska HID-heuristiken prioriterar möss,
så detta exakta Bluetooth-ID läggs till i de befintliga tangentbordsåsidosättningarna.

Batterirapporteringen fortsätter att använda Windows Bluetooth-batteriegenskapen.
Efter att USB kopplats ur rapporterade Windows **95 %** på det anslutna tangentbordet. En
ocachad läsning av standardiserad GATT Battery Level (`180F` / `2A19`) returnerade också
**95 %** direkt från tangentbordet. Detta
är en separat enhets-/transportavläsning från den trådbundna observationen på 100 %; ersätt den inte
med ett antaget fullvärde och skala inte om den. Orsaken till de avvikande
firmwareavläsningarna är inte fastställd.

Drivrutinen kontrollerar exakta produkt-/gränssnitts-/rapportstorlekar, svarshuvud,
förskjutning, längd, kontrollsumma och procentintervall. Den använder en svarstidsgräns på 400 ms
och ignorerar orelaterade svar inom samma tidsgräns.

Regressionstest:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Avsnitt:** Rapoo (`docs/rapoo.md`) · [Engelskt original](../../docs/rapoo.md) · [↑ Till toppen](#top)

# Batteristöd för Rapoo-möss

## Varför det ursprungliga programmet missade musen

`PollAllDevices()` räknar upp Windows HID-toppnivåsamlingar en gång per uppdatering. Varje tillverkardrivrutin
känner igen ett protokoll, lägger till en `DeviceStatus` och tar anspråk på sitt VID/PID så att de generiska drivrutinerna
inte lägger till den igen. Gränssnittet hanterar redan procent, laddning och den senaste avläsningen medan enheten sover.

Det fanns ingen Rapoo-drivrutin. VT3 Max Gen 2 skickar sitt batteri i en tillverkardefinierad inrapport,
inte i standardanvändningen HID Battery Strength eller som en Windows Bluetooth-batteriegenskap. De befintliga
generiska HID-/Bluetooth-reservlösningarna kan därför inte avkoda dess USB-mottagare.

## Observerad hårdvara och paket

Testat i Windows med ägarens VT3 Max Gen 2 den 2026-11-16:

| Anslutning | VID:PID | Gränssnitt | Usage page:usage | In-/utstorlek |
|---|---|---|---|---|
| 2,4 GHz-mottagare | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 byte |
| USB-kabel | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 byte |

Båda identifierar sig som `Rapoo Gaming Device`. De övriga samlingarna inkluderar standardinmatningar för mus,
tangentbord och media, tillverkarens konfigurationssamlingar samt ett 513-bytes firmwaregränssnitt.
Batteridrivrutinen öppnar endast `FF00:0002` med en igenkänd instorlek. Den öppnar aldrig firmwaregränssnittet
och skickar aldrig någon utrapport, feature-rapport, handskakning eller konfigurationskommando.

Infångad trådlös rapport, inklusive rapport-ID:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Infångad kabel-/laddningsrapport:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Förskjutningarna nedan räknar rapport-ID som byte noll, vilket motsvarar projektets `HidDev::Read()`:

| Byte | Betydelse | Exempel |
|---|---|---|
| 0 | Rapport-ID | `07` |
| 1 låg nibble | Anslutning: 0 mottagare, 1 Bluetooth, 2 kabel | `20` / `22` |
| 1 hög nibble | Sensorinformation; inte en del av anslutningstypen | `2` |
| 2 | Aktuellt DPI-steg | `03` |
| 3–4, 5–6 | X/Y DPI, little endian | `0320` = 800 |
| 7 | Batteritillstånd: 0 ogiltigt, 1 laddas ur, 2 laddas | `01` / `02` |
| 8 | Batteriprocent, 0–100 | `19` = 25% |
| 13–14 | Musens produkt-ID, little endian, när det finns med | `4617` |

Den skarpa mottagarinfångningen rapporterade `25%`, och den färdiga applikationen returnerade därefter
`27%, charging` via kabeln. Tolkningsprovet inkluderar den verkliga trådlösa infångningen. Laddning och kabelanslutning
verifierades också mot riktig hårdvara; dessa antas inte enbart utifrån att en USB-enhet är närvarande.
Efter att ägaren kopplade ur kabeln och anslöt mottagaren igen returnerade den slutliga körbara filen
`52%` via `2.4 GHz receiver`, utan laddningsflaggan, och behöll samma `rapoo:4617`-nyckel.
Detta verifierar även övergången från kabel till mottagare mot riktig hårdvara.

Även testat i Windows med en **VT9 Gen 2** den 2026-11-17:

| Anslutning | VID:PID | Gränssnitt | Usage page:usage | In-/utstorlek |
|---|---|---|---|---|
| 2,4 GHz-mottagare | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 byte |
| USB-kabel | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 byte |

VT9 Gen 2-mottagaren exponerar en **16-bytes** `FF00:0002`-rapport snarare än 19 byte, med exakt
samma Nordic 54L `07`-layout (inklusive det inbäddade `4614`-PID:t på byte 13–14). Infångade ramar:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

Via USB-kabel observerades statusrapporter vid interaktion (t.ex. DPI-byte); med den nedre
strömbrytaren ställd på OFF medan kabeln var inkopplad rapporterade musen `state=2, percent=1` istället för den
faktiska batteriprocenten.

### VT3 Max Gen 2-mottagare med en 13-bytes samling (ärende #1396)

En rapport från enhetsbegäransformuläret för samma mottagar-ID `24AE:1417` listade en annan gränssnittslayout:
`FF00:0002` med **13 / 13** byte (istället för 19), och `FF00:000E` med 33 / 33 byte,
utan någon 513-bytes firmwaresamling. Detta ser ut som en annan firmwarerevision för mottagaren.
Rapoo-programvaran visade fortfarande batteriet, så drivrutinen ignorerade en fungerande statuskanal.

Rapoo Hubs `VT_nrf54L`-avkodare (`py`) är längdanpassad: den läser alltid DPI, batteritillstånd
och procent, och läser de senare fälten (musens PID på `n[12..13]`, RF-info, ...) endast
när rapporten är tillräckligt lång. Manifestet för VT3 MAX (`productId: [17943, 5143]`) har ingen speciell
inrapporttyp, så rapport `07` går igenom den avkodaren på denna mottagare också. En 13-bytes rapport
(ID plus 12 byte) bär fortfarande tillstånd på byte 7 och procent på byte 8; endast musens inbäddade
PID saknas, så avläsningen använder mottagarens PID och behåller nyckeln `rapoo:4617`.

13-byteslängden accepteras **endast för `24AE:1417`**. Ramar måste fortfarande klara samma kontroller
(rapport `07`, anslutningsnibble 0–2, tillstånd 1/2, procent 0–100). Ingen skarp 13-bytes ram har
fångats in ännu; testerna använder den testade 19-bytesinfångningen avkortad till 13 byte.

## Andra Rapoo-möss

Officiella Rapoo Hub använder denna `07`-layout för sin Nordic 54L-musdrivrutin. Dess manifest
listar VT0, VT1, VT2, VT3, VT3S, VT7, VT9 och ytterligare varianter. Granskning av den nuvarande samlingen
identifierade 69 VT-varianter som använder `VT_nrf54L`; detta är bevis på ett delat protokoll, inte 69 hårdvaruvalideringar
eller ett påstående om att täcka merparten av hela Rapoos katalog. Stöd väljs utifrån Rapoos VID,
den dedikerade samlingen, inlängden och en giltig statusrapport, så en olistad modell på samma
protokoll kan ändå rapportera sitt batteri. En liten namntabell täcker vanliga modeller; andra behåller sitt
HID-produktnamn eller visar `Rapoo wireless mouse`.

Produktnamn och ID:n varierar mellan generationer och regioner. Det testade `1417/4617`-paret kallas
`VT3 MAX` i det nuvarande officiella manifestet; ägaren identifierar det som VT3 Max Gen 2. Det nuvarande
manifestets separata `VT3 MAX V2` har ID:na `1B06/4B06`. Gemenskapstabeller som tilldelar `1417` till VT9 Pro
får inte användas som enda grund för att namnge eller upptäcka denna enhet.

Äldre VT-firmware, dokumenterad för VT3 Pro (`1215/4415`), skickar istället en 7-bytes rapport på samma
`FF00:0002`-usage:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

För detta äldre format betyder tillstånd 1/2 urladdning/laddning. En laddningsprocent på `7F` betyder
okänd och bevaras som okänd. Övergångstillstånd 0, orelaterade `BC`-rapporter, felformade paket
och procentsiffror över 100 ignoreras. Det äldre stödet har automatiserad testtäckning, men har inte
verifierats med en fysisk äldre mus här. Denna tolkning är begränsad till produkt-ID:na
`1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) och deras 7-bytes insamling.

VT1 Pro Max (mottagare `24AE:1233`, kabel `24AE:4433`, musfirmware 222, dongelfirmware 213)
lades till utifrån USBPcap-infångningar som dess ägare bifogade i ärende #136. Utdatan från `--dump` listar
7-bytes `FF00:0002`-samlingen på gränssnitt 1, och infångningarna visar att den skickar rapporter utan någon begäran
från Rapoo-appen:

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

På kabeln sågs rapporten bara en gång under en 16-sekundersinfångning, så en kabelbaserad avläsning kan
överskrida tidsgränsen vid vissa uppdateringar; mottagaren skickar den regelbundet. Nordic-profilen tolkar aldrig `BB`-paket.

Detta fastställer **inte** stöd för alla Rapoo-enheter. CH584-modeller såsom VT1 SE och VT7 SE
använder rapport `08` i den officiella drivrutinen och stöds inte av denna avkodare. Andra Telink-revisioner använder en annan
tolkning av `BB`-flaggorna, vissa kontorsmodeller använder aktiva batterifrågor och Bluetooth-modeller
exponerar eventuellt bara Windows batteriegenskap. Dessa blir kvar hos befintliga reservlösningar eller kräver en
separat verifierad implementation. Skicka inte gissade frågor till dem.

## Polling och identitet

- Läsningen är passiv. Matchande `FF00:0002`-handtag hålls öppna mellan polls (precis som `PollXenta`)
  så att Windows buffrar statusramar som anländer under det 60 sekunder långa uppdateringsintervallet; varje poll tömmer
  eventuella köade ramar (och behåller den nyaste giltiga batteriavläsningen) innan den faller tillbaka på en 5 sekunders
  väntan vid första öppning eller tom kö. Urkopplade enheter tas bort och deras handtag stängs.
  Orelaterade paket startar inte om tidsgränsen.
- Musens inbäddade PID, eller ett känt kabel-/mottagarpar för äldre enheter, ger samma UI-nyckel
  oavsett kabelbyten. Kabel- och mottagaravläsningar slås samman till en post, där kabelns tillstånd föredras
  samtidigt som en giltig mottagarprocent behålls om kabeln rapporterar en okänd nivå.
- En tidsgräns hittar inte på en procentsiffra och tar inte anspråk på enheten. Efter en lyckad avläsning kan det
  befintliga gränssnittet behålla den avläsningen, nedtonad, i 30 minuter av tystnad.
- Programmets befintliga VID/PID-baserade identitetsmodell kan inte skilja på flera identiska möss
  med samma modell-ID. Fysisk samtidig kabel-/mottagardrift har inte testats; sammanslagning av
  båda indatakällorna täcks av det simulerade transporttestet.

## Validering

`make test` kör ett portabelt avkodartest och ett Windows-drivrutinstest med simulerade HID-svar.
Täckningen omfattar den verkliga infångningen, 0 % och 100 %, laddning, saknade nivåer, ogiltiga/trunkerade ramar,
samlingar/tillverkare som inte stöds, isolering av protokollprofiler, tidsgränser, stabila nycklar samt dubblettborttagning mellan kabel/mottagare
utan att kassera en känd procentsiffra.

Hela applikationen kompilerades lokalt med MSVC C++17 och Windows SDK, och `--list` / `--dump`
kördes mot den riktiga musen. Det underhållna MinGW-bygget inkluderar `rapoo.cpp` i `build.bat`;
Makefilen upptäcker den automatiskt. MinGW självt var inte installerat i testmiljön.

## Protokollkällor

- [Officiella Rapoo Hub](https://hub.rapoo.cn/), granskad 2026-11-16: medföljande
  [JavaScript-drivrutin och manifest](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js).
  Relevanta avkodare är `py`/`Hk` för `VT_nrf54L` och `qM`/`QM` för betydelsen av anslutnings- och
  batteritillstånd. Den separata `VT_CH584`-hanteraren tar emot rapport `08` och ligger utanför den här implementationen.
  Minifierade namn kan ändras i framtida utgåvor.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs),
  för äldre VT3 Pro-rapporter, laddningstillstånd och markören för okänd nivå.
- USBPcap-infångningar i ärende #136 (VT1 Pro Max på mottagare och på kabel under laddning).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js)
  bekräftar oberoende passiva `07`-statusutsändningar och batteriförskjutningen. Dess tolk
  begränsar ogiltiga procentsiffror; denna implementation avvisar dem istället.


---

<a id="sec-rawm"></a>
> 📄 **Avsnitt:** RAWM (`docs/rawm.md`) · [Engelskt original](../../docs/rawm.md) · [↑ Till toppen](#top)

# Protokollanteckningar för RAWM

RAWM-möss (och SADES Dagger, som delar plattform) pratar med appen RAWM HUB via en
tillverkar-HID-samling, `FF00:0001`, med 64-bytes onumrerade in- och utrapporter (65 byte
med rapport-ID). Mottagarna och mössen använder Nordics tillverkar-ID `1915`.

Källa: webbappen RAWM HUB, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), och dess skript
`https://hub.miracletek.net/hub/js/library.min.js` (obfuskerat; funktions- och konstantnamnen nedan
är skriptets egna). Produkt-ID:na som stöds kommer från enhetstabellen som appen laddar ned
(`https://www.miracletek.net/game/device.php`). Leviathan V4 GT och NYX60 använder Hub Web 3.0 på VID
`373E`, vilket är ett annat protokoll.

## Paket

Byte 0 i varje rapport (efter rapport-ID):

| Övre bitar | Betydelse |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | de 6 låga bitarna är en nyttolaststorlek; nyttolasten fortsätter händelseströmmen |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | flödeskontroll (lediga buffertstorlekar); ignoreras här |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | de 6 låga bitarna är en ESB-kanal; resten av rapporten är ett paket för den kanalen. Musen bakom en mottagare är kanal 0 |

Nyttolasterna bildar en byteström av händelser:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## Läsa av batteriet

Drivrutinen upprepar vad appen gör när en mottagare är ansluten (`send_event_query`, `send_event_ping`):

1. Till mottagaren: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), därefter
   pingar `00 84 0E 04 00 00`. Enheten skickar bara medan värden fortsätter skriva, så värden pingar.
   Mottagaren svarar `CMD_QUERY_RESULT` (`02`) med JSON, t.ex.
   `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. Samma fråga och pingar för kanal 0, med prefixet `C0`. Musen svarar med ett ~550-bytes JSON-objekt
   i 30-bytes ESB-stycken, t.ex. `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`.
   `battery` är en procentsiffra (RAWM HUB visar den som den är), `chr` är 1 under laddning.
3. Senare ändringar anländer som `CMD_NOTIFY` (`0B`) typ `17`: `[17, percent, charging]`.

Drivrutinen frågar alltid mottagaren först, precis som appen gör (i ett test fick en fråga som bara skickades till kanal 0
inget svar). En sovande mus svarar inte alls; mottagaren gör det fortfarande.

Frågan bär datorns klocka eftersom appen skickar den så; inget annat skrivs.
Möss rapporterar `"crc":1`, vilket säger åt appen att omsluta senare kommandon (konfiguration) i en CRC-16-ram;
frågan och pingarna accepteras utan en sådan, eftersom appen skickar dem innan den känner till detta.

Testad på en Leviathan V4 (firmware 1.2.0) med RAWM HS Receiver `1915:2346` (firmware 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **Avsnitt:** VAXEE (`docs/vaxee.md`) · [Engelskt original](../../docs/vaxee.md) · [↑ Till toppen](#top)

# VAXEE 4K/8K-mottagare och ZYGEN NP-01S V2

## Omfattning och hårdvaruvalidering

Den här drivrutinen stöder VAXEE 4K-mottagaren `3057:1002`, VAXEE 8K-mottagaren
`3057:2002` och ZYGEN NP-01S V2 Wireless via USB-kabel (`3057:1011`), på
deras tillverkarsamling `FF05:0001` med en 64-bytes feature-rapport. Andra VAXEE-mottagare,
andra kabelprodukt-ID:n och ZOWIE-enheter provas avsiktligt inte.

8K-mottagaren (`VAXEE 8K Wireless`, parkopplad med en NP-01 Ergo Wireless 8K)
testades i Windows och rapporterade via samma protokoll:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

Mottagaren delas av alla VAXEE 8K-möss och rapporterar inte vilken som är
parkopplad, så den visas under sitt eget namn. Laddningsstatus på 8K-mottagaren har ännu inte observerats på hårdvara.

En riktig 4K-mottagare testades i Windows:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

Den integrerade applikationen rapporterade också:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

Samma mus anslöts sedan direkt via USB och Windows identifierade
den som `ZYGEN NP-01S V2 Wireless` (`3057:1011`). Den uppdaterade produktionsdrivrutinen
rapporterade:

```
VAXEE battery: 75%; charging: yes
```

Aktivitetsfältswidgeten skapades utan problem i det första mottagarbygget.
Både batteridrift via mottagare och trådbunden laddning har observerats;
övergångar till full laddning och vilo-/avstängningsbeteende har inte testats på
hårdvara. Laddningsavkodning och ogiltiga svar täcks av simulerade
svar.

## Protokoll

Källa: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

En begäran är en nollutfylld 64-bytes HID feature-rapport:

| Byte | Värde |
|---|---|
| 0 | `0E`, rapport-ID |
| 1 | `A5`, huvud (header) |
| 2 | `0B` för batterinivå; `10` för laddningsstatus |
| 3 | `01`, läsflagga (aldrig `02`, skriv) |
| 4 | `01`, datalängd |
| 5–63 | `00` |

Efter att ha skickat begäran med `HidD_SetFeature`, vänta 100 ms och läs rapport
`0E` med `HidD_GetFeature`. Kräv minst sex byte samt förväntat rapport-ID,
huvud, kommandoeko och datalängd.

För batteri måste svarsbyte 5 vara 0–20 och multipliceras med fem, vilket ger
0–100 % i steg om 5 %. För laddning är byte 5 skild från noll vid laddning. En misslyckad
laddningsfråga kasserar inte en i övrigt giltig batteriavläsning.

Drivrutinen försöker skicka batteribegäran en gång till vid fel. Det görs högst tre läsbegäranden
per matchande samling (två batteriförsök och en laddningsfråga),
med totalt 300 ms uttrycklig fördröjning. Den skickar inga kommandon för inställningar, parkoppling,
firmware eller belysning.

Om inget giltigt batterisvar tas emot rapporterar drivrutinen ingenting och lämnar
enheten otagen i anspråk. Så länge USB-samlingen finns kvar behåller gränssnittet
en tidigare lyckad avläsning, nedtonad, i upp till 30 minuter med sitt befintliga
respittidsbeteende. Om den fysiska samlingen försvinner skickar drivrutinen ut
en frånkopplad status för att avsluta den respittiden direkt. Detta förhindrar
att en inaktuell mottagarikon dröjer kvar när kabeln flyttas till musen.

## Tester

`make test` inkluderar `tests/vaxee_driver_test.cpp`, som länkar produktionsdrivrutinen
mot en simulerad HID-transport. Den kontrollerar exakt utgående
skrivskyddade förfrågningar, procentomvandling, laddningsavkodning, ogiltiga och
saknade svar, redan ianspråktagna enheter samt exakt samlingsfiltrering.
