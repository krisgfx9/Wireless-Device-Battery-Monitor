<!--
  A BatteryHub dokumentációjának teljes magyar fordítása
  Forrás: docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Nyelvek:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | **Magyar** | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Nyelv hozzáadása](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Teljes dokumentáció (Magyar)

> Ez az egyetlen önálló Markdown-fájl összefoglalja a tároló összes látható dokumentumát, így a fordítóknak nyelvenként csak **egy fájlt** kell karbantartaniuk.

## Tartalomjegyzék

1. [BatteryHub áttekintés, támogatott eszközök, telepítés, parancssor és összeállítás (`README.md`)](#sec-readme)
2. [Közreműködői útmutató (`CONTRIBUTING.md`)](#sec-contributing)
3. [Pull Request sablon (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Kiadási és aláírási útmutató (`docs/releasing.md`)](#sec-releasing)
5. [Keychron billentyűzet 2,4 GHz-es firmware-javítás (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [GameSir Cyclone Pro BLE-támogatás (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Többnyelvű használati és honosítási útmutató (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Areson 25A7 vevő (`docs/areson.md`)](#sec-areson)
10. [DARKRIM SHADOW vevő (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K vevő (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Rapoo egér akkumulátor-támogatás (`docs/rapoo.md`)](#sec-rapoo)
16. [RAWM protokoll-megjegyzések (`docs/rawm.md`)](#sec-rawm)
17. [VAXEE 4K/8K vevők (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Szakasz:** BatteryHub áttekintés (`README.md`) · [Angol eredeti](../../README.md) · [↑ Elejére](#top)

# BatteryHub

*Korábban **Wireless Battery**. Az 1.1.0-s verzió átnevezte az alkalmazást; a frissítés megőrzi a beállításaidat, az automatikus indítási beállítást és az akkumulátor-előzményeket.*

[![Támogass a Ko-fi-n](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Adományozás PayPallal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Csatlakozz a Discordunkhoz](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Csillagozás GitHubon](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Megosztás Redditen](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Eszköz jelentése](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Segíts a fordításban](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

A vezeték nélküli egered, fejhallgatód, billentyűzeted és kontrollered akkumulátorszintjei közvetlenül a Windows tálcáján.

![BatteryHub a tálcán](../screenshot.png)

> **Csak használni szeretnéd?** Töltsd le a **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** telepítőt a legújabb kiadásból, futtasd, és kattints végig a varázslón. Ennyi az egész.
>
> **Tapasztaltabb felhasználók** letölthetik a hordozható ZIP-et, használhatják a [parancssori opciókat](#parancssor), vagy `make` illetve `build.bat` segítségével [forráskódból is lefordíthatják](#összeállítás).
>
> **Tetszik?** A BatteryHub ingyenes és nyílt forráskódú. Ha megspórol neked egy kört a gyártói szoftverekben, támogathatod a projektet a [Ko-fi](https://ko-fi.com/krisgfx), a [PayPal](https://www.paypal.com/paypalme/krisgfx) vagy a [GitHub Sponsors](https://github.com/sponsors/krisgfx9) oldalon. Ez segít abban, hogy a tanulmányaim mellett is ingyenesen tarthassam az alkalmazásaimat. Nem tudsz adományozni? Egy ⭐ csillag, a megosztás vagy egy nem támogatott eszköz jelentése `--dump` kimenettel ugyanannyit segít.

- **Apró**: egy ~350 KB-os alkalmazás, amely körülbelül 2 MB RAM-ot használ. Tiszta C++/Win32, futásidejű környezet és háttérszolgáltatás nélkül, és másodpercek alatt települ rendszergazdai jogosultság nélkül.
- **Nincs szükség gyártói szoftverre**: közvetlenül kommunikál az eszközökkel. A G HUB, Synapse, iCUE, GG és NGenuity zárva maradhat (vagy tovább futhat; nem akadnak össze).
- **Sok márka**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, PlayStation és Xbox kontrollerek, Samsung Galaxy Buds, bármely Bluetooth-eszköz, amelynek a Windows ismeri az akkumulátorszintjét, valamint minden fejhallgató, amelyet a mellékelt [HeadsetControl](https://github.com/Sapd/HeadsetControl) támogat.

## Megjelenítés

**A tálcán (alapértelmezett):** `🎧 30%  🖱 93%` az értesítési terület mellett, a Windows ikonbetűtípusával rajzolva.
- **Alacsony töltöttség:** a piros szám 15%-ot vagy annál kevesebbet jelent.
- **Töltés:** egy kék ⚡ jelenik meg a szám mellett. Amint az eszköz teljesen feltöltődött és még áram alatt van, zöld ✓ jellé változik.
- **Alvó módban:** a halványított szöveg azt jelenti, hogy az eszköz alvó módban van, és az utolsó ismert érték látható.
- **Leválasztva (opcionális):** kapcsold be a *Leválasztott eszközök megjelenítése* opciót, hogy halványított `×` jelenjen meg azoknál az eszközöknél, amelyek illesztőprogramja kifejezetten offline vezeték nélküli kapcsolatot jelent. Ez nem következtet leválasztásra egy elmaradt akkumulátor-lekérdezésből; alapértelmezés szerint az offline eszközök rejtve maradnak.
- **Két azonos típusú eszköz:** két egér (vagy két kontroller...) esetén mindkettő ugyanazt az ikont kapná, ezért mindegyik egy apró, legfeljebb 3 betűs feliratot kap az ikonja sarkában a nevéből (`MX`, `PRO`), vagy egy számot, ha a nevek nem különböztetik meg őket. Az egyedül lévő eszköztípus nem kap feliratot.
- **Téma:** követi a világos/sötét módot és a DPI-méretezést.
- **Átlátszó tálcatémák** (pl. Windhawk Taskbar Styler): kapcsold be a *Háttér a tálca szövege mögött* beállítást a menüben, hogy a szöveg a háttérkép felett is olvasható maradjon.
- **Több monitor:** a widget minden monitor tálcáján megjelenik az óra mellett, így teljes képernyős játék közben is látható marad. A menüben a *Widget megjelenítése itt* opcióval választható az *Összes monitor*, a *Csak a fő monitor* vagy egyetlen kijelző (pl. csak a *3. kijelző*).
- **További megjelenítési beállítások:** az *Ikonok a százalékok felett* egymás fölé rendezi az ikont és az értéket a szélesség csökkentéséhez; a *Márkaszínek* az ismert márkákat saját színükben jeleníti meg (Razer zöld, HyperX piros, ...) egy vékony töltöttségi sávval; két azonos típusú eszköz apró megkülönböztető feliratot kap; a bal és jobb oldali tálcákon az eszközök oszlopba rendeződnek.
- **Nyelvek:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 és 繁體中文. Mind a Windows, mind a Linux alkalmazás követi a rendszer megjelenítési nyelvét; a menü *Nyelv* almenüjében választható másik nyelv, és a Windows telepítő is támogatja mind a 19 nyelvet. A felületi kifejezések szerkeszthető statikus `lang/*.json` fájlokban találhatók, a teljes lefordított dokumentáció pedig a [`docs/i18n/`](README.md) mappában. Nyelv szerkesztéséhez vagy hozzáadásához lásd a [Fordítások](#fordítások) szakaszt.
- **Márkaszínek:** 15 ismert márka eszközei megkapják a gyártójuk színét, lágy ragyogással és egy vékony töltöttségi sávval a százalék alatt: Razer zöld, Logitech kék, SteelSeries narancssárga, Corsair sárga, HyperX / ROG / ZOWIE piros, PlayStation, Xbox, Samsung, Apple, Jabra, JBL, Cooler Master és Steam. Minden színhez tartozik sötét és világos tálca-árnyalat is. A márka az eszközt megtaláló illesztőprogramból, majd a gyártóazonosítóból (VID), végül a névből származik; a színek és szabályok a `src/brands.cpp` fájlban találhatók. A menüben a *Márkaszínek* opcióval kikapcsolható.

**Tálcaikonok:** eszközönként egy ikon a bele rajzolt számmal, valamint „Alacsony töltöttség” értesítés 15%-nál. Az alkalmazás automatikusan erre vált, ha a tálca függőleges vagy nem található.

**Egyéni eszköznevek:** nyisd meg az eszköz almenüjét, és válaszd az *Eszköz átnevezése...* opciót egy név (legfeljebb 64 karakter) beállításához. A név megjelenik a tálca-widget eszköztippjében/feliratában, a tálcaikon eszköztippjében és értesítéseiben, valamint az eszköz menüjében. Használd az *Eredeti név visszaállítása* lehetőséget az illesztőprogram nevének visszaállításához. A nevek helyben, az aktuális felhasználó Windows rendszerleíró adatbázisában (`Software\WirelessBattery`, `DeviceAliases`) tárolódnak, a stabil eszközkulcs segítségével. Az átnevezés sosem módosítja az illesztőprogram-illesztést, a protokoll-lekérdezéseket vagy a `--list` / `--dump` diagnosztikai kimenetet. Nincs szükség fiókra vagy hálózati hozzáférésre.

Vidd fölé az egeret a részletekért. Kattints a menühöz: minden eszköz (kattints egyre az elrejtéshez vagy megjelenítéshez), megjelenítési mód, *Frissítés most*, *Indítás a Windowszal* és *Kilépés*. A szintek 60 másodpercenként frissülnek (az *Akkumulátor ellenőrzése* menüponttal módosítható), illetve azonnal, amikor egy eszközt csatlakoztatnak vagy a PC felébred.

## Intelligens akkumulátor-értesítések (kísérleti)

Minden eszköz almenüjében beállíthatsz **eszközönkénti alacsony töltöttségi értesítési küszöböt**: **Akkumulátor-értesítések** → *Alapértelmezett használata (15%)*, *Értesítések kikapcsolása*, vagy 5%, 10%, 15%, 20%, 25%, 30%, 35%, 40% valamelyike. A meglévő 15%-os alapérték változatlan marad, hacsak nem választasz felülbírálást. A beállítások eszközkulcsonként tárolódnak az aktuális felhasználó Windows rendszerleíró adatbázisában (`Software\WirelessBattery`, `AlertThresholds`).

Értesítés csak valódi, friss 0–100%-os akkumulátormérés alapján váltódik ki, ha az eszköz csatlakoztatva van, ébren van és nem töltődik. Az értesítés egyszer jelenik meg, és csak akkor aktiválódik újra, miután a töltöttség több mint 10 százalékponttal a választott küszöb fölé emelkedik (vagy elkezdődik a töltés). A hiányzó mérések vagy az alvó eszközök nem indítanak újabb értesítést. A rejtett eszközök nem küldenek értesítést. Egy eszköz értesítéseinek letiltása nem rejti el az eszközt és nem változtatja meg a százalékát.

Mind a tálca-widget, mind a tálcaikon mód támogatja az értesítéseket. Mivel a Windowsnak értesítési területi ikonra van szüksége a hagyományos buborékértesítés megjelenítéséhez, a widget mód az értesítés után legfeljebb egy percig egy ideiglenes értesítési ikont jeleníthet meg. A widget színei és az alacsony töltöttség kiemelése továbbra is a projekt eredeti globális 15%-os küszöbét használja, az értesítési beállítástól függetlenül.

## Akkumulátor-előzmények és elemzések

Kattints jobb gombbal egy eszközre a tálca-widgetben vagy a tálcamenüben, és válaszd az **Akkumulátor-előzmények...** menüpontot.
A natív, DPI-érzékeny megjelenítő (követi a Windows világos/sötét témáját) összekötött mintapontokkal ábrázolja a rögzített töltöttségi szinteket az elmúlt **24 óra**, **7 nap** vagy **30 nap** időszakában, a legutóbbi méréssel, a legalacsonyabb/legmagasabb szinttel, a százalékpontos változással és a minták számával együtt. A kiválasztott eszköz előzményeit közvetlenül a megjelenítőből törölheted.

Az előzmények **kizárólag helyben** rögzítődnek a csatlakoztatott, ébren lévő, numerikus százalékot jelentő eszközökről. A mintavételezés eszközönként legfeljebb 30 percenként történik (kivéve a töltési állapotváltásokat, legalább 60 másodperces közzel). Az adatok legfeljebb 30 napig maradnak meg, a helyi fájl mérete pedig kb. 2 MB alatt marad. Az alkalmazás sosem vizsgálja a hardvert a meglévő lekérdezésen túl, nem küld előzményadatokat a hálózaton, és kizárólag a legutóbbi merülési megfigyelésekből készít konzervatív, hozzávetőleges becslést a lemerülésig hátralévő időről. Legalább négy mérési pont, két óra, három százalékpontos csökkenés, egy friss mérés és egy stabil merülési szakasz szükséges. Töltés, régi mérések vagy elégtelen adat esetén a becslés rejtve marad; az eszköz által jelentett üzemidő nem érhető el. A becslés nem garantált. A hiányzó grafikonadatok hézagként jelennek meg, nem kerülnek interpolálásra.

Kapcsold ki az **Akkumulátor-előzmények rögzítése** opciót a menüben a mérések mentésének leállításához; a korábban mentett adatok megmaradnak, amíg nem törlöd őket a megjelenítőben. A fájl helye: `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Az eszközazonosítók kódoltak (nem titkosítottak); a fájl a Windows-fiókodhoz kötött helyi fájl. `--demo` módban a grafikon szintetikus adatokat használ, amelyek sosem kerülnek mentésre. **Megjegyzés:** az előzmények gyűjtése csak a funkció telepítése és az alkalmazás egy ideig történő futtatása után kezdődik el.

## Támogatott eszközök

| Gyártó | Eszközök | Működés |
|---|---|---|
| **NuPhy** | WH80 USB-kábelen (`19F5:A011`) vagy Bluetoothon (`19F5:324A`), hardveren tesztelve | USB: csak olvasható NuPhyIO akkumulátor-lekérdezés; Bluetooth: Windows akkumulátorszint billentyűzet-besorolással ([protokoll-megjegyzések](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) a `3654:6901` USB-vevőn (hardveren tesztelve) | Csak olvasható, CRC-ellenőrzött akkumulátor-lekérdezés és töltésjelző; megfigyelt durva mérések 10%-os lépésekben, finomabb felbontás nem igazolt ([protokoll-megjegyzések](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX a KP 8K vevőn (`1D57:FA65`; a `73`-as modell hardveren tesztelve, a `74`-es modell nem tesztelt) | Passzív Xenta állapotjelentések; két egyező keret erősíti meg a szintet ([protokoll-megjegyzések](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, tesztelve), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` tesztelve, `002D`/`002A`), A50 Gen 3 (`9886:0015` tesztelve, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), USB bázisállomáson keresztül | Akkumulátor-százalék, töltési és dokkolási állapot |
| **Logitech** | Egerek és billentyűzetek Unifying, Bolt, Lightspeed (beleértve a PRO X3 SUPERSTRIKE `046D:C54F` adaptert) és Nano vevőkön, USB-n vagy Bluetoothon; G fejhallgatók (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 az újabb `046D:0ADF` adapteren | HID++ 1.0 / 2.0 funkciófelderítéssel: egységesített akkumulátor, töltöttségi szint, feszültség, ADC; G435: CRC-16 keretezett gyártói jelentések, `GET_BATTERY` mV-ban |
| **Razer** | Vezeték nélküli egerek, billentyűzetek és adapterek; BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X fejhallgatók, V3 Pro for Xbox (`1532:0A55` vevő, `0A4E` kábel); Barracuda X (2022) a 2,4 GHz-es vevőjén (`1532:0550` vagy `1532:0552`); Barracuda Pro (`1532:053A`) | Razer feature-report protokoll; BlackShark gyártói protokollok (V3 / V3 Pro / V3 X 5 percenként lekérdezve); Barracuda X: Airoha akkumulátor- és kábel-lekérdezés a vevőn keresztül |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (beleértve a `1038:225D`-t), Arctis Nova Elite (`1038:2244` bázisállomás), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, nem tesztelt), Aerox 3 Wireless CS2 Dragon Lore Edition (`1038:1878` vevő, `187A` kábel), Aerox 3 Wireless Gen 2 (`1038:1890` vevő, `1892` kábel), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Gyártói HID-jelentések; az Aerox/Prime és a Rival 650 egyetlen bejegyzésen osztozik a vevő és az USB-kábel között, előnyben részesítve a kábeles mérést, ha mindkettő válaszol |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 vezeték nélküli; Bragi eszközök (Virtuoso, Void V2, HS80 MAX, Slipstream egerek és billentyűzetek, beleértve az újabb `1B1C:2B00` Slipstream vevőt, pl. Scimitar Elite SE Wireless, valamint Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, nem tesztelt) | Gyártói HID-jelentések, Bragi `GET` (csak olvasható), Compx 17 bájtos akkumulátor-protokoll (csak olvasható) |
| **Cooler Master** | MM712, MM731 (2,4 GHz-es adapter vagy USB-kábel) | Gyártói HID állapotjelentés (csak olvasható) |
| **Press Play** | ICARUS V2 Nearlink a `7768:6434` 2,4 GHz-es vevőjén (illesztőprogram hardveren tesztelve 90%-on; protokoll rögzítve 100%-on és 90%-on) | Csak olvasható `06 05` kimeneti jelentés az `FFB2:0001` gyűjteményen; akkumulátor-százalék a válasz 14. bájtjában |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` PS-hez, nem tesztelt), Cloud Flight S, Cloud Stinger Core Wireless (beleértve a DTS `03F0:0A8E`-t, tesztelve), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (2,4 GHz-es adapter), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (2,4 GHz-es adapter) (`03F0:0F98` 2,4 GHz-es adapter tesztelve; `0D97` nem tesztelt) | Gyártói HID-jelentések (Haste 2: [protokoll-megjegyzések](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Gyártói feature-jelentés |
| **Hitscan** | Hyperlight X, Hyperlight N | Gyártói feature-jelentés (ugyanaz a protokoll, mint a Gloriousnál) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, Pulsar és ATK VXE vezeték nélküli egerek (pl. VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (`3554:F512` vevő) | Megosztott gyártói protokoll ellenőrzőösszeggel ellátott válaszokkal |
| **Pulsar X2 V3** | X2 V3 az 1K adapteren (`3710:5402`) vagy USB-kábelen (`3710:3402`); X2 V3 eS a 8K adapteren (`3710:5403`) vagy USB-kábelen (`3710:3406`) | 64 bájtos gyártói feature-jelentés, `08 81 01` akkumulátor-regiszter (csak olvasható) |
| **ATK / VXE NK** | VXE R1 NK és más NearLink egerek az NK mouse NANO adapteren (`373B:1216`) | ATK BITMOUSE 08-as kimeneti jelentés az `FF05:0001` gyűjteményen (akkumulátor és töltés) |
| **ATK 8K Nano** | ATK / VXE egerek az ATK 8K Nano Dongle (`373B:1178`) vevőn | Holtek GetConfigData (`82`) feature-jelentés az `FF10:0001` gyűjteményen (az ATK HUB-ból; akkumulátor és töltés) |
| **ATK fejhallgatók** | ATK N9 Pro, N9 Ultra (első generáció) | Virtuális COM-port protokoll (az ATK asztali alkalmazást be kell zárni) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK és azok 8K adapterei | Glorious vagy Kysona protokoll, modelltől függően |
| **Keychron egerek** | M4 és más Keychron egerek a 2,4 GHz-es vevőn; 4K egerek (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) a Keychron 4K Link vevőn (`3434:D038`); 8K egerek (M5 8K, G6 HE 8K ...) a TurboLink 8K vevőn; 8K egerek az Ultra-Link 8K vevőn (`3434:D028`); régebbi egerek (M1, M2, M3, M3 mini, M6, M7 ...) az 1K vevőn (`3434:D030` / `D031`); Nape Pro trackball a Link-KM vevőn vagy kábelen | Gyártói jelentés a Keychron Launcherből (1K vevő: 51 06 feature-jelentés, ahogy a Keychron asztali alkalmazás használja; Ultra-Link 8K: B5 03 / B3 06 jelentések az `FFC1`-en; Nape Pro: nyers HID A7 31) |
| **Keychron billentyűzetek** | K5 Max (`3434:0A50`, tesztelve) a Keychron Link vevőn (`3434:D030`) vagy USB-kábelen; más Keychron QMK vezeték nélküli billentyűzetek ugyanazzal a javítással fordítva | Nyers HID az `FF60:0061`-en: a `B2` megkérdezi a vevőtől, melyik billentyűzet van csatolva, az `A4` visszaadja a szintet, feszültséget és töltést. **Javított billentyűzet-firmware szükséges:** lásd [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). A gyári firmware csak Bluetoothon jelent |
| **CHERRY** | MX 3.0S Wireless billentyűzet a 2,4 GHz-es adapteren (`046A:00EA`, tesztelve) vagy USB-kábelen (`046A:00E3`, tesztelve) | Gyártói HID `1A` lekérdezés az `FF1C:0092`-n (csak olvasható), USB-tápellátás állapottal. A Bluetootht a Bluetooth-támogatás fedi le |
| **CHERRY** | Cherry XTRFY vezeték nélküli egér az 1K vevőn (`046A:0330`, tesztelve) | CompX 17 bájtos akkumulátor-protokoll (`08 03` kapcsolatállapot, `08 04` GetPower), ugyanaz a keretezés, mint a Corsair Sabre V2 Prónál (csak olvasható) |
| **Arbiter Studio** | Akitsu (`373E:000A` 8K vevő, `373E:0009` kábel), Akitsu 3950 (`373E:0039` 8K vevő, `373E:0038` kábel), Akitsu Medium (`373E:0067` 8K vevő és `373E:0066` kábel, mindkettő tesztelve) | Csak olvasható gyártói `0x83` feature-jelentés az `FFFF:0000`-n az Arbiter Web HUB-ból (akkumulátor és töltés) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (kábel, 1K és 4K/8K adapterek) | Gyártói feature-jelentés a LAMZU Aurorából |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) a 4K adapteren; XM2we az eredeti vevőjén (`3367:1961`) | Gyártói `A1` feature-jelentés, `B4` akkumulátor-parancs (csak olvasható) |
| **ATK / VGN / Evision billentyűzetek** | ATK V75X és VGN / VXE billentyűzetek (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) a megosztott 2,4 GHz-es vevőn (`320F:5088`) vagy USB-kábelen (`320F:5055`), terméknév alapján felismerve; olyan billentyűzetek, amelyek `320F:5088` vevőjének neve „Wireless Gaming Keyboard”, pl. Feker Alice80 (tesztelve) | Evision `04` kimeneti jelentés, `1A` akkumulátor-parancs (az ATK HUB-ból és a VGN HUB-ból); a vevőn keresztül legfeljebb 10 percenként lekérdezve |
| **Redragon (Evision)** | K1NG M999 (tesztelve) a `320F:226F` 2,4 GHz-es vevőn; a vevőazonosítót más modellek is használhatják | Ugyanaz az Evision protokoll, mint az ATK billentyűzeteknél (`04` jelentés, `1A` parancs az `FF1C:0092`-n), minden lekérdezéskor; töltés jelzése a mágneses dokkolón; csatlakoztatott USB-kábellel a vevő a régi szintet ismétli töltésállapot nélkül |
| **Audeze** | Maxwell az USB-adapteren (`3329:4B19`) vagy USB-C kábelen (`3329:4B1A`); Maxwell 2 az USB-adapteren (`3329:4B29`, tesztelve); Xbox azonosítók nem teszteltek | Gyártói `06` jelentés / `07` bemeneti jelentés, `0CD6` akkumulátor-attribútum (egyetlen csak olvasható lekérdezés) |
| **ENDORFY** | Viro Wireless a 2,4 GHz-es adapterén (`3738:0072`, nem tesztelt) | Airoha RACE „get battery” (`0CD6`) a gyártói `06` jelentésen / `07` bemeneti jelentésen, ugyanaz a csak olvasható lekérdezés, mint az Audeze és Skullcandy adaptereknél; töltésállapot nélkül |
| **Turtle Beach** | Stealth 700 Gen 3 az USB-adón (`10F5:2251`, tesztelve a HaloBatteryben; PC verzió `10F5:2262`, nem tesztelt) vagy a fejhallgató saját USB-kábelén (`10F5:2253`) | RACE `0x9942` (CoAP kliens engedélyezése) és a RACE `0x9902`-be alagutazott CoAP `GET /GSI`, ahogy a Swarm II teszi; akkumulátor a `240`-es kulcsból (töltésjelző nélkül) |
| **AKG** | N9 Hybrid az USB-adapterén (`0ECB:20D9`, tesztelve) | Airoha RACE az `FF13:0001`-en: `06` kimeneti jelentés, `07` bemeneti jelentés, `0CD6` akkumulátor-attribútum (egyetlen csak olvasható lekérdezés) |
| **NZXT** | Lift Elite Wireless az adapterén (`1E71:2101`) vagy USB-kábelén (`1E71:2129`) | Gyártói olvasás `4E 02 81 .. B0` (NZXT CAM rögzítésekből) |
| **Poly / Plantronics** | Voyager 8200 UC és más fejhallgatók a BT600 adapter mögött (`047F:02EE` / `02F7`) | `07` jelentés get/set protokoll, `0A 1A` akkumulátor-elem (csak olvasható) |
| **WLMouse** | YING Magnesium (`36A7:A874` YING 8K vevő); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (vevő vagy kábel; nem a Beast X 4K); Beast X V2 (`36A7:A856` 8K vevő); Beast G (`36A7:A860` 8K vevő vagy `36A7:A861` kábel; nem tesztelt) | Gyártói feature-jelentés, `0x83` állapotparancs (YING: ugyanaz a protokoll, mint a Gloriousnál) |
| **Finalmouse** | UltralightX a 2,4 GHz-es adapterén (`361D:0100`, tesztelve); Starlight X az adapterén (`361D:0300` / `0301`, tesztelve). Nem az egér saját kábelén | xpanel gyártói jelentések az `FF00`-n: csak olvasható GET-ek, majd *wake/all* (`0xE0`); akkumulátor-feszültség az xpanel görbéjén vagy a Starlight X saját százaléka, valamint töltésállapot |
| **VAXEE** | Vezeték nélküli egér a VAXEE 4K vevőn (`3057:1002`) vagy 8K vevőn (`3057:2002`, pl. NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless USB-kábelen (`3057:1011`) | Csak olvasható gyártói `0E` feature-jelentés az `FF05:0001`-en; akkumulátor 5%-os lépésekben, töltésállapot ([protokoll-megjegyzések](#sec-vaxee)) |
| **Scyrox** | V12M a 2,4 GHz-es vevőjén (`395A:0006`) | S-Center 2.0 profilolvasás (`08` kimeneti jelentés, `01` parancs) az `FF00:0002`-n; csak akkumulátor, töltésállapot nélkül |
| **HECATE** | G5M PRO és más HECATE egerek ugyanazon a vevőn, valamint USB-kábel `35BB:D3FA / D3FC / D3FD` | Kysona protokoll |
| **Redragon** | Compx-alapú vezeték nélküli egerek: M916 Pro 1K (tesztelve), M913 Impact Elite (tri-mode), G49 (vevő vagy kábel) | Kysona protokoll (az Areson `25A7` vevők az Areson alatt szerepelnek) |
| **Taidu (钛度)** | TSG808 a Compx `3554:F5D5` 2,4 GHz-es vevőjén (tesztelve) | Kysona protokoll |
| **Areson (Redragon)** | M915RGB-WL (tesztelve), eredeti M913 Impact Elite és más egerek a `25A7:FA07` / `FA08` vevőn | 17 bájtos `GetPower` feature-jelentés; szint 10%-os lépésekben és töltésjelző |
| **Ninjutso** | Sora V2 az 1K vevőn (`1915:AE1C`, tesztelve) vagy USB-kábelen (`1915:AE11`, tesztelve); Ten Air (`093A:EB01` vevő és `093A:E020` USB-kábel, tesztelve) / Ten (`093A:EB01` / `E020`, nem tesztelt) | NinjaForce `0x05` (`0x15` a Sora V2-höz) és `0x06` (`0x13`/`0x12`/`0x11` a Ten / Ten Air-hez) feature-jelentés |
| **Sprime** | PM1 a 2,4 GHz-es vevőn (`1915:AC1C`, tesztelve; `1915:AD8C`) vagy USB-kábelen | Ugyanaz a 0x05 feature-jelentés, 0x15 állapotparancs, a Sprime webes illesztőprogramjából (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 a RAWM HS Receiveren (`1915:2346`, tesztelve); ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* és SADES Dagger egerek a RAWM vevőiken (`1915:232A`–`234B`) vagy USB-kábelen | RAWM HUB 2.0 eszközadat-lekérdezés a vevőn keresztül (JSON akkumulátor-%-kal és töltéssel), csak olvasható ([protokoll-megjegyzések](#sec-rawm)) |
| **AULA** | F75 / F87 Pro / F99 vezeték nélküli billentyűzetek a 2,4 GHz-es vevőn | 0x13 jelentéskeret, 0x4A parancs, összeg-ellenőrzőszám (a Bluetooth és vezetékes módok nem teszteltek) |
| **AULA egerek** | X9 Ultra (tesztelve) az AULA-8K Dongle `320F:22A0` vevőn; a vevőazonosító megosztott a V9 modellekkel | `04` jelentés, csak olvasható `1A` akkumulátor-parancs START `01` / END `02` között az `FF1C:0092`-n; csak 2,4 GHz |
| **SONiX billentyűzetek (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (tesztelve), EPOMAKER EA75 (tesztelve), AULA F108 Pro a `05AC:024F` 2.4G adapteren; AJAZZ AK980 V2 a `0C45:FEFE` adapteren; AJAZZ AK820 Pro a `0C45:FDFD` vagy `0C45:FEFE` adapteren; EPOMAKER P75 a `342D:E479`-en (hardveren nem tesztelt) | Gyártói `20 01` jelentés az FF60 használati oldalon, összeg-ellenőrzőszám (csak 2.4G mód; töltésjelzés nincs) |
| **További SONiX vevők (hardveren nem tesztelve)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | Ugyanaz a csak akkumulátoros `20 01` lekérdezés; pontos VID:PID és 33 bájtos jelentésekkel rendelkező FF60:0061 gyűjtemény szükséges; csak 2.4G, töltésjelzés nincs |
| **36B0 billentyűzetek (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB a `36B0:3002` 2.4G adapteren vagy a `36B0:3009` USB-kábelen (a protokollt mindkettőn tesztelte a #343 bejelentője); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) ugyanazon az adapteren vagy kábelen (nem tesztelt); URX Core75 az adapteren (megerősítve a HaloBatteryben); EVO80 (nem tesztelt) | PMO Hub firmware: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` az FF60 használati oldalon, a pmohub.cn-ből. URX / VIA firmware: VIA custom-get `08 00 07` (0. csatorna, 7. érték), az URX HUB-ból a HaloBatteryn keresztül. Töltésjelzés nincs |
| **DAREU** | EM901X a `260D:1074` 2,4 GHz-es vevőn vagy `260D:1090` USB-kábelen (akkumulátor-olvasás mindkettőn tesztelve; a vevő dokkolási/levételi töltésjelző-átmenetei tesztelve) | Csak akkumulátoros `08` feature-jelentés, `04` parancs; `09` válasz egy külön gyártói gyűjteményen. Termékazonosítónként egy egyértelmű bemeneti/feature párt igényel. Az érvényes USB-mérést részesíti előnyben, ha mindkettő csatlakoztatva van; a vevő kikapcsolt egér esetén is visszaadhat gyorsítótárazott telemetriát |
| **DAREU** | A84 billentyűzet (`260D:0022`, nem tesztelt) | SONiX feature-jelentés a 0. interfészen, `04 F6` parancs (a hivatalos A84 illesztőprogram akkumulátor-olvasása); szint százalékban, töltésjelző nélkül |
| **DAREU** | A980 Pro a `260D:1131` több-egeres vevőn és az USB-kábelén (`260D:1148`) (akkumulátorszint hardveren tesztelve; töltésjelző bedugva megerősítve) | Togran protokoll: 65 bájtos `0A` feature-jelentés a fogyasztói vezérlő (consumer-control) gyűjteményen; hely-lekérdezés (0. osztály / `A0`), majd akkumulátor-lekérdezés (7. osztály / `80`), kábelen a 0. helyen. Csak olvasható |
| **Sharkoon** | Skiller SGM50W a `260D:1125`-ön (nem tesztelt) | Ugyanaz a Compx lekérdezés, mint a DAREU EM901X-nél (`08` feature-jelentés, `04` parancs; `09` válasz az `FF01:0000`-n); a Sharkoon firmware-frissítője ehhez egy Compx eszköz a `260D` VID-on |
| **Zenith** | Zenith Pro a `260D:1114` 2,4 GHz-es vevőn (akkumulátor-olvasás tesztelve; töltés nem tesztelt) vagy `260D:1143` USB-kábelen (nem tesztelt) | Ugyanaz a Compx parancs (`08`, `04`) kimeneti jelentésként az `FF02:0002`-n; `08 04` válasz ugyanazon a gyűjteményen százalékkal, töltésjelzővel és millivolttal, a `0x55` bájtösszeggel ellenőrizve |
| **AJAZZ AK992** | Telink `320F:50C3` 2,4 GHz-es vevő (tesztelve) | EVision akkumulátor-lekérdezés az `FF1C:0092` HID-gyűjteményen |
| **ZOWIE** | EC1/EC2/EC3-CW, DW sorozat (U2-DW, S2-DW ...) és U2 a 2,4 GHz-es vevőjén | Közösség által dokumentált, csak olvasható gyártói parancsok |
| **Royal Kludge (RK)** | MG6 Pro a 2,4 GHz-es adapteren (`2E3C:00A6` / `00E6`) vagy USB-kábelen (`2E3C:00A5` / `00E5`) | QiWang 64 bájtos keret az RK webes illesztőprogramjából, `GET_BATTER_VOL` olvasás (százalék, feszültség, töltés) |
| **ASUS ROG** | Strix Scope II 96 (RX), Azoth, Falchion billentyűzetek; Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact egerek; Pelta fejhallgató (2,4 GHz-es adapter); Cetra Open Wireless fülhallgató (`0B05:1CAC` SpeedNova adapter, bal / jobb / tok); az Omni Receiver | ROG HID akkumulátor-lekérdezés |
| **Machenike** | L7 Arctic / L7 Mix a `248A:FF4C` 2,4 GHz-es vevőn vagy `248A:FF4E` USB-kábelen (mindkettő tesztelve) | Csak olvasható `51` feature-jelentés, `06` állapotparancs; akkumulátor és töltés. [Protokoll-megjegyzések](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS a 2,4 GHz-es adapterén (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (`0DB0:0D3C` 2,4 GHz-es vevő, tesztelve; `0DB0:0D3B` USB-kábel) és CLUTCH GM41 Lightweight Wireless (`0DB0:0D4C` vevő / `0DB0:0D4B` kábel, tulajdonosi rögzítésekből) | Csak olvasható gyártói `0F 20` lekérdezés az `FF0D:00B0`-n és `FF00:0001`-en; akkumulátor és töltésjelző egy bájtban (protokoll az MSI Center Gaming Gear moduljából); GM41: passzív `A0 xx 07 …` jelentések az `FF10:0006`-on |
| **MCHOSE** | L7 / L7 Pro / L7 Ultra (L7 Ultra tesztelve), M7 / M7 Ultra, A7 / A7 Ultra, K7 egerek a 2,4 GHz-es vevőn vagy USB-kábelen; A5 V2 Ultra (`3837:100C` 2,4 GHz-es vevő, tesztelve), K7 Ultra (`3837:1001` 2,4 GHz-es vevő, tesztelve; az A7 V2 Ultra+ `3837:100B` várhatóan működik, 227-es hibajegy); G3 V2 (`3837:4245` 2,4 GHz-es vevő és `3837:418C` USB-kábel); K7 V2 Ultra+ a `3837:1014` 2,4 GHz-es vevőn vagy `3837:4028` USB-kábelen (mindkettő tesztelve; a többi új családba tartozó `1018`, `1016`, `102C`, `102D` vevőazonosító nem tesztelt) | Gyártói feature-jelentés, invertált hasznos teher (protokoll az alexfrih/mchose-linux projektből); a Realtek `3837` adapterek ugyanarra a lekérdezésre válaszolnak `41E4` (A5 V2 Ultra) vagy `3837` (K7 Ultra) értékre állított vid mezővel; G3 V2: csak olvasható gyártói lekérdezés az `FF01:0010`-n; K7 V2 Ultra+: 64 bájtos `0x4D` jelentés, `0x0900` eszközadat-parancs az `FF01:0001`-en (protokoll az M HUB webes illesztőprogramjából) |
| **MCHOSE A5 (első generáció)** | A5 Pro / A5 Pro Max az 1K vagy 4K 2,4 GHz-es vevőn (`2023:F013`, `2023:F015`, `2023:F018`) vagy USB-kábelen (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); itt nem tesztelt | Csak olvasható `0x83` akkumulátor-parancs (0. oldal) egy 64 bájtos feature-jelentésben az `FFFF`-en, `0xA1` jelölésű válasz (protokoll a z750sasr A5 Pro Max webes illesztőprogramból és a HaloBatteryből, azonosítók a Klegus/mchose-macos projektből) |
| **MCHOSE fejhallgatók** | V9 Pro 2 a 2,4 GHz-es adapteren (`3837:6011`, tesztelve) | Az M HUB csak olvasható „MC” akkumulátorkerete (`0x55` jelentés, `0x0B` alparancs) az `FF07:0222`-n; akkumulátor és töltésjelző egy bájtban (protokoll az M HUB webes illesztőprogramjából) |
| **AULA / MCHOSE / Redragon billentyűzetek** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 és a többi M HUB billentyűzet; Redragon Horus Pro / Pro V2 (K618RGB-PRO) a 2,4 GHz-es vevőn (`3554:FA09`, `41E4:2001`); MCHOSE K87 a `05AC:024F` vevőn (BY elrendezés az 1. interfészen, nem a SONiX-féle) | 0x13 jelentéskeret, 0x4A parancs (az MCHOSE és Redragon modelleket a 0x05 parancs azonosítja, mint az M HUB-ban); a Bluetooth és vezetékes módok nincsenek lefedve |
| **MCHOSE billentyűzetek** | G75 V2 a `3837:3033` 2,4 GHz-es vevőn (tesztelve); ugyanazzal a vevővel érkezik a G87 V2 és a K99 V3 is (ugyanaz a protokoll, nem tesztelt); a K87S ugyanezt a vevőazonosítót más protokollal párosítja és nincs lefedve | Az M HUB csak olvasható „GLW” func-config lekérdezése az azonosító nélküli 64 bájtos `0001:0000` gyűjteményen: `0x55` kérésjelző, `0x05` parancs, akkumulátor a hasznos teher 32. bájtjában (7. bit = töltés), additív ellenőrzőösszeg |
| **AULA SC580** | SC580 / SC580X egér USB-kábelen (`088D:062E`, tesztelve) vagy a 2,4 GHz-es vevőjén (`089D:062F`, tesztelve) | Csak olvasható `0x30` parancs (eszközadatok) a 33 bájtos FF02:0000 gyártói gyűjteményen, összeg-ellenőrzőszám; töltés közben az egér fix 100-at jelent, így az utolsó szint jelenik meg; a Bluetooth mód nincs lefedve |
| **AULA HERO 68 Air** | HERO 68 Air a 8K vezeték nélküli vevőn (`372E:106C`) | Nyugtázott 20 bájtos keretek az FF60 használati oldalon (üzenetenként négy adatkeret és egy zárókeret), csak olvasható 0x87 akkumulátor-parancs, 0x10 töltésjelző a szint után; a Bluetooth és vezetékes módok nincsenek lefedve |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra és S9 Max / Pro / Ultra / Ultra+ a „Gaming 2.4G” vevőn (`372E:103D`); S9 Ultra az USB-kábelén (`372E:1027`) | Csak olvasható `03` feature-jelentés az `FF00:0001`-en: `47` kapcsolatellenőrzés, `4F 81` alapvető eszközadatok (akkumulátor-százalék és töltésbit), az EWEADN webes illesztőprogramjából |
| **Rapoo VT** | VT3 Max Gen 2 (tesztelve); VT9 Gen 2 (tesztelve); más Nordic 54L VT egerek ugyanazzal az állapotinterfész-szel; régi VT3 Pro (kísérleti); VT1 Pro Max (a tulajdonos USB-rögzítéseiből) | Passzív `07` HID állapotjelentés az `FF00:0002`-n (16 vagy 19 bájt; egyes VT3 Max Gen 2 vevőkön 13 bájt); a régi `BB` a VT3 Pro `1215/4415` és VT1 Pro Max `1233/4433` modellekre korlátozva. Vevő és USB-kábel, töltésállapottal |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (Xenta 30/50 modellek; régi 3D), Delux M800 Pro, Ajazz AJ179 család; AJ159 és más AJ-sorozatú egerek a 3151-es vevőn; AJ139 V2 MC (`A8A5:2255` vevő, `A8A4:2255` kábel) | Gyártói jelentések (M900 Pro: passzív állapotadások vagy feature-lekérdezés, Xenta 40/41 események; AJ-sorozat: 0xF7 állapotlekérdezés, majd 0x05 feature-jelentés) |
| **Incott** | G23 V2 / G24 (`093A:522C` vevő, `093A:622C` kábel) | Csak olvasható `09` állapot feature-jelentés |
| **Attack Shark és más kínai márkák** | Rongyuan vevők (81 modell: Attack Shark R3 és AJAZZ AJ179 Pro a `3151:402D`-n, K86, X82 PRO HE, Ajazz billentyűzetek, néhány MSI és mások; a K86 Bluetoothon billentyűzetként jelenik meg); Xenta vevők (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; az X6 a `1D57:FA61`-en is, nem tesztelt); Semico 1A2C billentyűzetek (Attack Shark X98 az `1A2C:8FFF` adapteren, tesztelve, és `1A2C:A034` kábelen; AJAZZ AK820 Max Plus az `1A2C:8FFF` / `1A2C:A036`-on) | Rongyuan állapotjelentés; Xenta passzív adások; Semico csak olvasható `0x0E` állapotlekérdezés (`AA 55 CC 33` az `FF02:0002`-n; a töltésjelző elhagyva, mert az X98 akkumulátorról és töltés közben is `state=1`-et jelent) |
| **Wraith** | W1 / W1 Freestyle (`093A:522C` vevő, `093A:622C` kábel; ugyanazok az azonosítók, mint az Incottnál, a modellkód különbözteti meg) | Csak olvasható gombonkénti `86` olvasás (09 feature-jelentés) az összes gombon, majd a küldött `09` állapot bemeneti jelentés |
| **Fantech** | Helios Go XD5 (vezetékes `25A7:FA7B`, adapter `25A7:FA7C`); Raigor III (tesztelve), Raigor II WG10 és más általános 2.4G Mouse eszközök az újrahasznosított `1EA7:0066` / `1EA7:0064` adapteren | Helios Go XD5: gyártói `08` feature-jelentés, `04` parancs, `0x55`-re összegződő ellenőrzőösszeg. Raigor/2.4G Mouse: csak olvasható `B5` állapotoldal-lekérdezés az `FFB5:0001`-en, `94`-es blokk = utolsó jelentett százalék (alvás, kikapcsolás vagy töltés közben elavult lehet; nincs töltésállapot) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, vezeték nélküli adapter); INZONE H9 II és H5 fejhallgatók; INZONE Buds (USB-C adapter) | Bemeneti jelentés; INZONE gyártói protokoll |
| **Fractal Design** | Scape fejhallgató a 2,4 GHz-es adapterén vagy USB-C kábelén | Gyártói `GET_DEVICE_STATE` lekérdezés a Fractal Adjust Pro webes alkalmazásából (FF00 használati oldal) |
| **Jabra** | Minden olyan Jabra fejhallgató, amely a GN Protocolt használja (Evolve2 / Evolve3 és mások), saját USB-kábelen vagy Jabra Link adapter mögött; nincs termékazonosító-lista, a DECT bázisok (Engage, PRO 9xx, GO 6400, Link 400) kihagyva; a név a fejhallgatóból olvasva | GNP állapotlekérdezés (12. osztály / op 02) az FF00 használati oldalon, 05 vagy 01 használaton, a 08-as (USB) vagy 04-es (adapter) GNP címen |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), 2,4 GHz-es vevő vagy USB; Apex 5 (`37D7:2501`), 2,4 GHz-es vevő vagy USB | Gyártói HID információs lekérdezés az `FFA0:0001`-en; 0–5 akkumulátorszint leképezve 0–100%-ra 20%-os lépésekben, töltésállapottal; nincs szükség Space Station szolgáltatásra |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite a 2,4 GHz-es vevőn; Nova 2 Lite USB-n; G7 Pro (tesztelve: Zenless Zone Zero kiadás, `3537:105E` vevő) és más GameSir kontrollerek Xbox (GIP) módban; Cyclone 2 (XInput mód, vevő vagy kábel); Cyclone Pro a 2,4 GHz-es adapterén (`3537:1015`, párosítsd egyszer a kontrollert a Windowszal Bluetoothon) | Gyártói eszközadat-lekérdezés (FF7A használati oldal); Windows.Gaming.Input akkumulátorjelentés (valódi %) Xbox módban; Cyclone 2: gyártói akkumulátorkérés (FFF0 használati oldal); Cyclone Pro: GameSir alkalmazás alapinformáció-kérés Bluetooth LE-n (`0x8650` szolgáltatás), 2 percenként olvasva |
| **BEITONG** | KP20 / BTP-KP20 a 2,4 GHz-es vevőjén (`20BC:5128`, XInput mód, tesztelve) és KP40D / BTP-KP40D a vevőjén (`20BC:515C`, XInput mód); a BEITONG iControl nem szükséges | Gyártói „get base info” lekérdezés a `00FF` használati oldalon (`02` jelentés, félbájtonként kevert hasznos teher), töltésállapottal |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` tesztelve 2,4 GHz-es adapteren, D-input `2DC8:6012` — tartsd nyomva a B-t bekapcsoláskor, firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Gyártói HID állapotlekérdezés (`FF7A`/`FFA0`) és SDL kontroller `01`/`04` bemeneti jelentés, töltésállapottal |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Állapotkeret, amelyet a fülhallgatók küldenek a Samsung RFCOMM (SPP) szolgáltatásán, csak olvasható. A tálca az alacsonyabb töltöttségű fülhallgatót mutatja; az eszköztipp felsorolja a bal, a jobb és a tok szintjét. A Galaxy Buds alkalmazást be kell zárni |
| **Nothing / CMF** | Nothing Ear (3a) (tesztelve), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Csak olvasható `0xC007` akkumulátor-lekérdezés a Nothing NT Link RFCOMM szolgáltatásán (`aeac4a03-dff5-498f-843a-34487cf133eb`). A tálca az alacsonyabb töltöttségű fülhallgatót mutatja; az eszköztipp felsorolja a bal, a jobb és a tok szintjét |
| **Akko** | Akko Air 01 (`3151:5006`, 2,4 GHz-es vevő, tesztelve) és Akko V9 Dash Pro (`38EE:000C`, 2,4 GHz-es vevő, tesztelve) | Air 01: Rongyuan `0xF7` állapotjelentés; V9 Dash Pro: csak olvasható 64 bájtos `0x1A` állapotlekérdezés az `FF1C:0092`-n töltésállapottal |
| **MOONDROP** | GM01 Pro fejhallgató a 2,4 GHz-es adapterén (`35D8:0133`); az USB-kábelén töltőként jelenik meg az utolsó szinttel | WalkPlay gyártói olvasási parancs a `4B` jelentésen (csak olvasható) |
| **VGN** | OMNISOUND (ZHOUTING) fejhallgató a 2,4 GHz-es adapterén (`372E:10BB`, tesztelve) | V HUB „ZHOU” lekérdezés: `55` kimeneti jelentés `65 01` hasznos teherrel a `000C:0001` vezérlőgyűjteményen (32 bájtos bemeneti, 64 bájtos kimeneti jelentések); a százalék a válaszban érkezik (csak olvasható) |
| **JBL** | Quantum 650 Wireless (tesztelve, 2,4 GHz-es adapter); Quantum 520, 650X, 850, 950, 950X Wireless (adapter vagy USB-kábel, ugyanaz a protokoll, nem tesztelt) | JBL „HIDV3” eszközadat-lekérdezés az akkumulátor funkcióhoz (FF12 használati oldal), töltésállapottal |
| **JBL** | Quantum 350 Wireless (tesztelve Windowson a `0ECB:206B` 2,4 GHz-es vevővel); Quantum 610 Wireless (`0ECB:205C` 2,4 GHz-es adapter, Windowson nem tesztelt); Quantum 360 Wireless (`0ECB:2115` 2,4 GHz-es adapter, nem tesztelt) | HIDV1 feature-jelentések a vezeték nélküli kapcsolathoz és az akkumulátor-százalékhoz |
| **Xbox** | Kontrollerek az Xbox Wireless adapteren, USB-n vagy Bluetoothon; kontrollerbe dugott fejhallgatók | Windows.Gaming.Input akkumulátorjelentés (valódi %), XInput tartalék |
| **Switch Pro-kompatibilis** | `057E:2009`-ként megjelenő kontrollerek (tesztelve: GameSir Tarantula Pro a 2,4 GHz-es vevőn Switch módban) | Öt akkumulátorszint a `0x30` HID-jelentésből, miután a Steam Input vagy más gazdagép engedélyezte a teljes jelentéseket |
| **Apple AirPods / Beats** | AirPods Max (tesztelve, `200A` Lightning és `201F` USB-C), AirPods Pro 3 (tesztelve, `2027`), AirPods Pro 1 / 2, AirPods 1–5 és Beats fejhallgatók/fülhallgatók | BLE „proximity pairing” (`0x07`) hirdetések (egyetlen akkumulátor az AirPods Maxhoz és Beats fejhallgatókhoz; bal, jobb és tok a fülhallgatókhoz, 10%-os lépésekben, töltésállapottal), a párosított modellhez illesztve |
| **Telefonok (Telefon-kapcsolat)** | Bármely, a Microsoft Telefon-kapcsolattal (Phone Link) összekapcsolt Android telefon, Wi-Fi-n vagy Bluetoothon (tesztelve: Nothing Phone (4a) Pro) | Akkumulátor és töltésállapot a Telefon-kapcsolat Windows 11 Start menü kártyájáról (`StartMenuCompanion.json`); nincs szükség Bluetoothra |
| **Darmoshark** | M3 (`248A:FF30`) és M3S (`248A:FF31`) a 2,4 GHz-es vevőiken Windowson | HID feature-jelentés az egér azonosítójához és akkumulátorához |
| **Darmoshark** | M3S Pro a Nordic 1K vevőn (`1915:0723`) | Gyártói HID állapotlekérdezés az `FF0A` gyűjteményen |
| **Alienware** | AW920H fejhallgató a 2,4 GHz-es adapterén (`413C:A515`, tesztelve); Bluetoothon a Bluetooth sor fedi le | Gyártói `06 C0 0A` lekérdezés az `FF13:0001`-en, `07` válaszjelentés XOR ellenőrzőösszeggel; szint, töltés és kritikus szint mezők az Alienware Command Center AW920H bővítményének dekódolása szerint |
| **Niceboy** | MW400 a 2,4 GHz-es vevőjén (`248A:FA02`, tesztelve) | Csak olvasható `05` jelentés `24 FA 48` lekérdezés; akkumulátor-feszültség 10%-os lépésekre leképezve a gyártói alkalmazás táblázatával, töltésjelző |
| **Bluetooth** | Minden, ami akkumulátorszintet mutat a *Gépház → Bluetooth és eszközök* alatt (fülhallgatók, fejhallgatók, BLE egerek és billentyűzetek). A Google Fast Pair fülhallgatók (Jabra Elite 8 Active tesztelve; Pixel Buds és sok Sony / JBL / Bose modell) bal, jobb és tok szintet is kapnak | Windows eszköztulajdonság; Fast Pair akkumulátor-hirdetések (BLE szolgáltatásadat `FE2C`), Bluetooth-cím alapján párosítva a párosított eszközzel |
| **Általános HID** | A szabványos HID *Battery Strength* használatot jelentő eszközök | HID használati oldal 0x06 / 0x85 |
| **HeadsetControl** | [Minden általa támogatott fejhallgató](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, újabb Logitech és egyebek) | Mellékelve; a `headsetcontrol -o json` parancsot futtatja |
| **MAONO PD200W** | 2,4 GHz-es vevő (352F:040E) | Akkumulátor-százalék; hardveren tesztelve |


**Valódi hardveren tesztelve:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (PlayStation vevő `0951:1713`; a töltés nem tesztelt), HyperX Cloud Core Wireless DTS (`0951:173F` vevő; a teljes töltöttségi szint nem tesztelt), HyperX Pulsefire Haste 2 Core Wireless (`03F0:0AB5` adapter; a Haste 2 Wireless adapterek nem teszteltek), Cooler Master MM712 (adapter), Rapoo VT3 Max Gen 2 (`24AE:1417` vevő és `24AE:4617` USB-kábel; más Rapoo modellek nem teszteltek, lásd [Rapoo protokoll-megjegyzések](#sec-rapoo)), Redragon M916 Pro 1K (`3554:F55D` vevő), Taidu TSG808 (`3554:F5D5` vevő), Redragon M915RGB-WL (`25A7:FA07` vevő; más Areson modellek nem teszteltek, lásd [Areson protokoll-megjegyzések](#sec-areson)), SteelSeries Rival 650 Wireless (`1038:1726` vevő és `1038:172B` USB-kábel), SteelSeries Arctis Nova Pro Wireless (`1038:225D` bázisállomás; az akkumulátor-olvasás tesztelve, a töltés és tápellátási átmenetek nem teszteltek), HECATE G5M PRO (`35BB:D3FB` vevő), WLMouse YING Magnesium (`36A7:A874` 8K vevő), ATK N9 Ultra (`373B:1204` vevő), Corsair Scimitar Elite SE Wireless (`1B1C:2B00` Slipstream vevő), Corsair Dark Core RGB Pro SE (`1B1C:1BDC` Slipstream vevő), Corsair Sabre V2 Pro Ultralight (`1B1C:2B2A` 2,4 GHz-es vevő; akkumulátor-olvasás ellenőrizve), DAREU EM901X (`260D:1074` vevő; a töltés és alvás/ébredés nem tesztelt), Jabra Evolve3 75 Link 390-en (`0B0E:2E51`), MCHOSE G3 V2 (`3837:4245` vevő és `3837:418C` USB-kábel), MCHOSE K7 Ultra (`3837:1001` vevő), MCHOSE K7 V2 Ultra+ (`3837:1014` vevő és `3837:4028` USB-kábel; töltés kijelezve bedugott kábellel), MSI VERSA 300 ELITE WIRELESS (`0DB0:9E22` adapter; a töltés és alváskezelés nem tesztelt), MSI Clutch GM31 Lightweight Wireless (`0DB0:0D3C` vevő; a GM41 ugyanazt az illesztőprogramot használja egy tulajdonos rögzítéseiből), AJAZZ AK820 MAX (`05AC:024F` adapter), AULA HERO 68 Air (`372E:106C` 8K vezeték nélküli vevő), AULA SC580 (`088D:062E` USB-kábel és `089D:062F` vevő, beleértve a töltést és alvást), AirPods Pro 3 (Bluetooth, `2027` modell), AirPods Max (Bluetooth, `200A` modell), Sprime PM1 (`1915:AC1C` vevő), Ninjutso Ten Air (`093A:EB01` vevő és `093A:E020` USB-kábel), MOONDROP GM01 Pro (`35D8:0133` adapter), Delux M800 Pro (`248A:5B2F` vevő), Razer Barracuda X (2022) (`1532:0550` vevő; akkumulátorszint kiolvasva, töltési átmenetek nem teszteltek), Razer BlackShark V3 X (`1532:057D` HyperSpeed adapter), Fantech Helios Go XD5 (`25A7:FA7C` adapter), Fantech Raigor III (`1EA7:0066` adapter; a firmware nem jelenti a töltést), Finalmouse UltralightX (`361D:0100` adapter), Finalmouse Starlight X (az adapterén), és Chimera V2 (`3554:F512` vevő; akkumulátorszint és töltés kiolvasva).
Szintén hardveren tesztelve: Machenike L7 Arctic / L7 Mix (`248A:FF4C` vevő és `248A:FF4E` kábel), beleértve a töltést és a kábel/vevő duplikáció-elnyomást. A Bluetooth és az alacsony töltöttségi / teljes feltöltési határok nem voltak hardveren tesztelve.
Szintén hardveren tesztelve: MCHOSE V9 Pro 2 (`3837:6011` adapter); az akkumulátorszint kiolvasva, a töltés és az alvás nem tesztelt.
Szintén hardveren tesztelve: EPOMAKER EA75 a `05AC:024F` 2,4 GHz-es vevőjén, a meglévő SONiX illesztőprogrammal a [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60)-ból. Az akkumulátor-százalék, a vevő újracsatlakozása és a bekapcsolás utáni helyreállás ellenőrizve lett. A töltésjelzést és a vezetékes akkumulátor-jelentést ez az illesztőprogram nem támogatja; a Bluetooth akkumulátor-jelentés nem lett tesztelve. A jelentett százalék USB-tápellátás csatlakoztatásakor 100%-ra ugorhat, ami nem megbízható töltésjelző.
Szintén hardveren tesztelve: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (`1038:1878` vevő és `1038:187A` USB-kábel), beleértve a töltést, a kikapcsolást (az utolsó szint halványítva megmarad) és a futó SteelSeries GG melletti működést; a GG csak háromlépcsős sávot mutat, amellyel a szint megegyezett.
Szintén hardveren tesztelve: RAWM Leviathan V4 (`1915:2346` RAWM HS Receiver; akkumulátorszint kiolvasva, a töltés nem tesztelt).
**Protokoll-dokumentációból és más projektekből megvalósítva, még nem tesztelve:** minden más, beleértve a Fantech Raigor II WG10-et (ugyanaz az `1EA7:0066` adapter és gyűjtemény, mint a tesztelt Raigor III esetében, így működnie kell). Ha rendelkezel ezen eszközök valamelyikével, kérjük, jelezd egy [hibajegy megnyitásával](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues), hogy működik-e.

## Telepítés

[![Legújabb verzió](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Töltsd le a **`BatteryHub-Setup-<version>.exe`** fájlt a [legújabb kiadásból](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. Futtasd, válaszd ki a 19 támogatott telepítési nyelv bármelyikét, és kattints végig rajta. Nincs szükség **rendszergazdai jogosultságra** és **semmilyen más telepített összetevőre**: nincs futásidejű környezet, nincsenek illesztőprogramok, nincsenek gyártói alkalmazások. A HeadsetControl mellékelve van, a szerkeszthető `lang\` mappa pedig a `BatteryHub.exe` mellé települ.

A telepítő hozzáad egy Start menü bejegyzést és egy eltávolítót (*Gépház → Alkalmazások*), valamint el tudja indítani az alkalmazást bejelentkezéskor. Inkább nem telepítenéd? Töltsd le a `BatteryHub-<version>-portable.zip` fájlt, csomagold ki bárhová (tartsd meg a `lang\` mappát a `BatteryHub.exe` mellett a felületi fordításokhoz), és indítsd el a `BatteryHub.exe`-t.

**Megjegyzések:**
- **SmartScreen figyelmeztetés:** az exe nincs digitálisan aláírva, így a Windows azt mondhatja: „A Windows megvédte a számítógépet”. Kattints a *További információ → Futtatás mindenképpen* gombra, vagy fordítsd le magadnak.
- **Tálcaikon mód Windows 11-en:** az új tálcaikonok a `^` túlcsordulási menübe kerülnek. Húzd ki őket a tálcára, vagy engedélyezd őket a *Gépház → Személyre szabás → Tálca → Egyéb tálcaikonok* menüben.
- **Az alkalmazás távol tartása egy eszköztől:** ha egy eszköz rendellenesen viselkedik az alkalmazás futása közben, sorold fel a `HKCU\Software\WirelessBattery` alatt található `IgnoreDevices` rendszerleíró karakterláncban `VID:PID` párokként (hexadecimálisan, vesszővel elválasztva, pl. `28BD:0947, 1234:ABCD`; a `--dump` megmutatja az azonosítókat). Az alkalmazás ekkor sosem nyitja meg. A rajztáblák automatikusan kimaradnak.

## Frissítések Windows alatt

A hivatalos stabil Windows buildek a háttérben ellenőrzik a projekt legutóbbi közzétett stabil kiadását, indítás után 30 másodperccel, majd az alkalmazás futása közben 24 óránként. Nyisd meg a menüt a **Frissítés érhető el: vX.Y.Z...** megjelenítéséhez, vagy válaszd magad a **Frissítések keresése...** lehetőséget. A frissítési információk kizárólag ebben a menüben jelennek meg: az akkumulátor-ikonok, százalékok és eszköztippek változatlanok maradnak, és az automatikus ellenőrzések sosem jelenítenek meg értesítést vagy párbeszédablakot. A háttérellenőrzések kikapcsolásához kapcsold ki a **Frissítések automatikus keresése** opciót a menüben.

Telepített példány esetén kattints a frissítés bejegyzésre és a **Letöltés és telepítés** gombra. Enélkül a kattintás nélkül semmi nem települ. Az alkalmazás letölti a kiadás `SHA256SUMS.txt` fájlját és annak aláírását, ellenőrzi az aláírást az alkalmazásba beépített karbantartói nyilvános kulccsal, letölti a Windows telepítőt, és csak akkor futtatja, ha annak SHA-256-ja megegyezik az aláírt listában szereplővel (és azzal, amelyet a GitHub felsorol hozzá). Ezután frissíti a meglévő telepítést. A beállítások és az automatikus indítási preferencia megmaradnak, és az alkalmazás a telepítés után újraindul. Minden felhasználóra kiterjedő telepítés esetén rendszergazdai engedélyt kérhet. A **Kiadási megjegyzések** megnyitja a hivatalos kiadási oldalt; a **Később** megtartja a jelenlegi verziót. A hordozható példányok a kiadási oldalt kínálják fel a ZIP kézi letöltéséhez.

Az ellenőrzések fiók vagy token nélkül lépnek kapcsolatba a GitHub nyilvános API-jával. Semmilyen eszköz- vagy akkumulátor-információ nem kerül elküldésre. Az offline hibák és a GitHub sebességkorlátozásai mellett az akkumulátorfigyelés zavartalanul fut tovább; egy korábban talált kiadás mindaddig a menüben marad, amíg egy sikeres ellenőrzés felül nem írja, vagy telepítésre nem kerül. A letöltés megszakítása megvárja, amíg az aktuális hálózati művelet véges időkorlátja lejár. A telepítő sosem indítja újra automatikusan a Windowst.

**Miért biztonságos a frissítések telepítése:** az aláíró kulcs sosem kerül fel a GitHubra. A karbantartó a saját PC-jén írja alá minden kiadás ellenőrzőösszeg-listáját (lásd [docs/releasing.md](#sec-releasing)), így még az sem tudna olyan frissítést közzétenni, amelyet az alkalmazás telepítene, aki átvenné a GitHub-fiókot vagy annak build-munkafolyamatát. Az érvényes aláírás nélküli kiadás megjelenik a menüben, de csak kézzel tölthető le. Az aláírás nem váltja ki a Windows saját SmartScreen vagy UAC kéréseit.

Az első olyan kiadást, amely ezt a funkciót tartalmazza, egyszer telepítsd kézzel. A fejlesztői/teszt buildek letiltják a hivatalos frissítés-ellenőrzéseket, hogy a helyi módosítások ne íródhassanak felül véletlenül. A Linuxos frissítések és a hordozható példányok automatikus cseréje későbbre van halasztva.

## Parancssor

```
BatteryHub.exe --list     # minden eszköz és akkumulátorszint kiírása, majd kilépés
BatteryHub.exe --json     # eszközök és töltöttségi szintek kiírása JSON tömbként, majd kilépés
BatteryHub.exe --dump     # minden HID-gyűjtemény, nem megnyitható HID-eszközök, minden USB-eszköz (HID-interfész
                               # nélküliek is) és Bluetooth-eszközök; a %TEMP%\BatteryHub-dump.txt fájlba is mentve
BatteryHub.exe --report   # az „Eszköztámogatás kérése” ablak megnyitása
BatteryHub.exe --demo     # minden márka példaeszközeinek megjelenítése a valódiak helyett (képernyőképek, színek ellenőrzése)
BatteryHub.exe --quit     # a futó példány bezárása
```

A Linuxos build ugyanezeket a kapcsolókat használja `wireless-battery` névvel a `BatteryHub.exe` helyett, és elfogadja a `--help` kapcsolót is. A `--json` egy stabil tömböt ír ki, amelyet szkriptek és állapotsor-widgetek is fel tudnak dolgozni:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

A `graceSec` azt jelzi, mennyi ideig jeleníti meg az alkalmazás az utolsó ismert szintet, amíg az eszköz alszik. Az új mezők hozzáadása visszafelé kompatibilis.

**Nem látszik egy eszköz?** Kattints jobb gombbal a widgetre vagy a tálcaikonra, és válaszd az **Eszköztámogatás kérése...** lehetőséget. Válaszd ki az eszközt, ellenőrizd, mi kerül elküldésre (szóról szóra megjelenik: az eszköz neve, típusa, USB/HID azonosítói és interfész-elrendezése, valamint az opcionális neved és megjegyzéseid), majd kattints a **Küldés** gombra. Felkerül a nyilvános listára a [krisgfx.com/tools](https://krisgfx.com/tools/#requested) oldalon, és nyit vagy frissít egy GitHub-hibajegyet. A **Teljes jelentés másolása** a teljes `--dump` kimenetet a vágólapra helyezi a hibajegyhez. A jelentés adatai csak akkor kerülnek elküldésre, ha a Küldés gombra kattintasz. A hivatalos Windows buildek a GitHubot is felkereshetik frissítések kereséséhez a [Frissítések Windows alatt](#frissítések-windows-alatt) szakaszban leírtak szerint; a frissítés-ellenőrzések nem küldenek eszköz- vagy akkumulátor-információkat.

## Összeállítás

Szükséged lesz a [MinGW-w64](https://www.mingw-w64.org/) eszközláncra, például az [MSYS2](https://www.msys2.org/)-ből (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # fejlesztői build, 0.0.0 verzió
build.bat                                 # egyszerű cmd, ahol a g++ és windres a PATH-on van
make VERSION=1.2.3 CHANNEL=test            # verziózott build, hivatalos frissítések letiltva
build.bat 1.2.3 test                       # egyenértékű verziózott cmd build
make test VERSION=1.2.3 CHANNEL=test       # eszköz- és frissítő-regressziós tesztek
```

A telepítő és a hordozható ZIP elkészítéséhez telepítsd az [Inno Setup](https://jrsoftware.org/isinfo.php) programot, először fordíts a kívánt verzióval (például `make VERSION=1.2.3 CHANNEL=test`), majd futtasd a `powershell -File installer\build-installer.ps1 -Version 1.2.3` parancsot. A csomagolás elutasítja a futtatható fájltól eltérő verziót. Letölti a rögzített HeadsetControl kiadást, és ellenőrzi az ellenőrzőösszegét. A GitHub Actions mindezt automatikusan elvégzi: egy olyan címke feltöltése, mint a `v1.0.0`, közzétesz egy kiadást a telepítővel, a hordozható ZIP-pel és a HeadsetControl forráskódjával (ahogy a GPL licenc megköveteli).

A Windowsos fordításhoz PowerShell is szükséges a megosztott futtatható/erőforrás-verzió előállításához. A hivatalos tároló verziócímkéi `CHANNEL=stable` értékkel fordulnak; a helyi buildek alapértelmezése a `dev`. A forkok és pull requestek nem engedélyezik automatikusan a hivatalos frissítéseket.

A `BatteryHub.exe` önmagában is működik. A mellette (vagy a `PATH`-on) lévő `headsetcontrol.exe` nélkül csupán a kiegészítő fejhallgatók esnek ki.

## Linux (kísérleti)

A Windows alkalmazás mellett egy Linuxos build is létezik. Ugyanazokat a gyártói illesztőprogramokat használja egy hidraw-alapú HID háttérrendszerrel és egy GTK4 StatusNotifierItem tálcaikonnal; a Windowsos kódút változatlan. Minden kizárólag Linuxos fájl a `linux/` és `src/linux/` mappákban található, és a `build-linux.sh` fordítja le (Windows továbbra is a `build.bat`-ot használja).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Fordító & make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

Nincs szükség külön HID könyvtárra (közvetlenül a hidraw-t használja).

```sh
./build-linux.sh
./build-linux.sh test         # egységteszt a HID report-descriptor értelmezőhöz
./wireless-battery --list     # észlelt szintek kiírása és kilépés
./wireless-battery --dump     # HID-gyűjtemények listázása
./wireless-battery --quit     # a futó tálcapéldány bezárása
```

A HID-hozzáféréshez udev szabály szükséges, különben az alkalmazás elindul, de nem talál eszközöket:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# jelentkezz ki, majd lépj be újra
```

A tálcaikon natívan működik KDE Plasma alatt; a GNOME-nak egy AppIndicator gazdára van szüksége, például a `gnome-shell-extension-appindicator` kiegészítőre. A többnyelvű váltás a *Nyelv* almenün keresztül működik (alapértelmezetten követve a `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` változókat, és a `--help` kimenetet is honosítva). A `make -f linux/Makefile.linux install` parancs telepíti a binárist, a `lang/*.json` fájlokat a `$(PREFIX)/share/wireless-battery/lang/` mappába, valamint az asztali indítófájlt (`linux/wireless-battery.desktop`) és a `linux/wireless-battery.svg` ikont a `$(PREFIX)` alá (alapértelmezés: `~/.local`); a felhasználói nyelvi felülbírálások a `~/.config/wireless-battery/lang/` mappában élnek.

Az 1. fázis lefedi a Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious, Finalmouse és a megosztott Kysona/Pulsar/ATK/G-Wolves protokollokat. A Bluetooth/UPower tartalékok, a HeadsetControl és a fennmaradó gyártók a következő fázisokra vannak betervezve.

## Korlátozások

- **Zsúfolt tálcák:** nagyon tele, középre igazított Windows 11-es tálca esetén az alkalmazásgombok elérhetik a widgetet. Windows 10-en a feladatgomb-terület automatikusan keskenyedik.
- **Telefonok:** egy olyan fájlból olvasva, amelyet a Telefon-kapcsolat (Phone Link) ír a Start menü kísérőkártyájához; ez nem dokumentált API, és a Telefon-kapcsolat frissítéseivel változhat. A telefon addig látszik, amíg a Telefon-kapcsolat csatlakoztatottként jelenti; a 3 óránál régebbi kártya halványítva jelenik meg. A kártya azt is jelzi, ha a telefon töltődik, ami töltési villámként jelenik meg.
- **Alvó eszközök:** az alvó eszköz nem biztos, hogy válaszol. Az utolsó értéke halványítva látható marad. A Logitech vevők eltávolítják az alvó eszközöket a kapcsolatról, így az utolsó értékük 30 percig marad meg.
- **HECATE G2 Wireless 7.1 fejhallgató** (`35BB:A009` / `A209` 2,4 GHz-es adapter): az adapterhez még nincs dokumentálva akkumulátor-lekérdezés, így nincs kiolvasva. A hozzáadás módja egy USB-forgalomrögzítés, miközben a HECATE szoftver mutatja a fejhallgató akkumulátorát (lásd `CONTRIBUTING.md`).
- **Keychron billentyűzetek:** gyári firmware-rel csak Bluetoothon jelentik az akkumulátorukat (a Bluetooth-támogatáson keresztül jelennek meg). A 2,4 GHz-es vevőn vagy a kábelen az akkumulátor-javítást tartalmazó firmware-re van szükségük ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); a billentyűzet frissítése a Keychron Launcherből eltávolítja azt. A Keychron egerek támogatottak.
- **Baseus AeQur GH02 fejhallgató:** a 2,4 GHz-es adapter (`10D6:4802`, Actions chip) csak hangot, médiagombokat és a chip firmware-frissítési csatornáját hordozza, az akkumulátort nem. Csatlakoztasd a fejhallgatót Bluetoothon a szint megtekintéséhez (a Bluetooth-támogatáson keresztül jelenik meg, ha a Windows jelent egyet).
- **Weikav Lucky65 v1 billentyűzet:** a firmware nem jelenti az akkumulátort a 2,4 GHz-es adapteren (`0603:0351`, Novatek chip). A billentyűzetnek nincs akkumulátor-ellenőrző gyorsbillentyűje, a hivatalos konfigurátor pedig csak USB-kábelen keresztül csatlakozik, az adapteren át nem, így nincs megjeleníthető akkumulátorérték.
- **Rapoo:** a támogatott VT egerek maguktól küldik az állapotukat (push), így egy frissítés illesztőfelületenként legfeljebb 4 másodpercet várhat. Az alvó egerek az utolsó mérésükkel legfeljebb 30 percig halványítva maradhatnak. A támogatás a Nordic 54L `07`-es jelentésre és a régi `BB`-re (VT3 Pro, VT1 Pro Max) vonatkozik; a CH584 `08`-as jelentést, az irodai MT/M-sorozatú egereket és más firmware-protokollokat ez az illesztőprogram nem fed le.
- **GameSir Cyclone Pro:** az adapter nem továbbít akkumulátorszintet, ezért azt Bluetooth LE-n keresztül közvetlenül a kontrollertől olvassa be. Párosítsd egyszer a kontrollert a Windowszal (Gépház > Bluetooth és eszközök > Eszköz hozzáadása > Bluetooth > `GameSir-Cyclone Pro`), és játssz tovább az adapteren keresztül. A PC-nek szüksége van Bluetoothra. A szint 2 percenként frissül, és töltés közben nincs százalékérték. Párosítás nélkül az adapter Xbox kontrollerként jelenik meg „Tele” értékkel. Részletek a [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro) dokumentumban.
- **RAWM:** az egér lekérdezése a vevőjén keresztül történik, így az alvó egér nem válaszol; az utolsó mérésével legfeljebb 30 percig halványítva marad, és alvás közben körülbelül egy másodperccel meghosszabbítja a frissítést. Csak a Leviathan V4 van tesztelve a RAWM HS Receiveren (`1915:2346`); a többi modell a RAWM HUB eszköztáblázatából származik. A Leviathan V4 GT és NYX60 (`373E` VID, RAWM HUB 3.0), valamint a RAWM HS billentyűzetek más protokollokat használnak és nincsenek lefedve.
- **Flydigi:** ez az illesztőprogram a Vader 5 Pro és az Apex 5 modelleket célozza; a Bluetooth és más Flydigi modellek (például Apex 6) nincsenek lefedve. A százalékok durva akkumulátorszinteket jelölnek. Az Apex 5 valódi hardveren lett tesztelve 2,4 GHz-es vevőn és USB-kábelen; a Vader 5 Pro az SDL-t és Windowsos hardver-nyomkövetéseket követ.
- **Még nem támogatott:** az MSI vezeték nélküli egerek a VERSA 300 ELITE és a CLUTCH GM31 / GM41 kivételével, az MSI vezeték nélküli billentyűzetek, a Razer Kraken fejhallgatók és a Barracuda modellek a `1532:0550`-en lévő Barracuda X (2022) kivételével, a HyperX Pulsefire egerek a Haste 2 Wireless / Haste 2 Core Wireless kivételével, valamint az Xbox Wireless Headset az Xbox adapteren: ezek akkumulátor-protokolljai nincsenek dokumentálva. Az Xbox Wireless Headset Bluetoothon működik. A hozzáadásuk módja egy tulajdonos USB-forgalomrögzítése (lásd `CONTRIBUTING.md`).
- **Egyéb eszközök:** néhány 2,4 GHz-es eszköz dokumentálatlan protokollt használ, és még nem támogatott. Lásd a [CONTRIBUTING.md](#sec-contributing) útmutatót ahhoz, hogyan segíthetsz egy újabb támogatásában.

## Működési elv

A [`src/drivers/`](../../src/drivers) mappában található minden egyes gyártói illesztőprogram USB gyártó- és termékazonosító alapján ismeri fel az eszközeit, és kizárólag csak olvasható akkumulátor-lekérdezéseket küld. Ismeretlen eszközökre sosem ír. Az általános tartalék-megoldások (HID akkumulátor-használat, Bluetooth, XInput, HeadsetControl) csak azokat az eszközöket vizsgálják, amelyeket egyetlen gyártói illesztőprogram sem foglalt le.

A tálca-widget a `Shell_TrayWnd` rétegezett gyermekablaka (`layered child window`), a `TrayNotifyWnd` bal oldalán elhelyezve. Ha az Explorer újraindul, újra létrejön.

## Fordítások

Minden felületi nyelv egy egyszerű, statikus UTF-8 szövegfájl a [`lang/`](../../lang) mappában: bal oldalon az angol, jobb oldalon a fordítás. A nyelvi fájlok futásidőben töltődnek be a lemezről ahelyett, hogy belefordulnának a futtatható fájlba, így közvetlenül szerkesztheted őket újrafordítás nélkül.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **Alkalmazás felülete (Windows és Linux):**
  - Szerkessz vagy adj hozzá `.json` fájlokat közvetlenül a `BatteryHub.exe` melletti `lang/` mappában (vagy Linuxon a `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/`, illetve `./lang/` mappában).
  - Vagy válaszd a *Nyelv → Saját nyelv hozzáadása...* lehetőséget a menüben, hogy előkészítsd a felhasználói felülbírálási mappádat (`%APPDATA%\WirelessBattery\lang` Windowson, `~/.config/wireless-battery/lang` Linuxon) a `_template.json` fájllal. Másold a `_template.json` fájlt például `it.json` névre, töltsd ki a `@code`, `@name` értékeket és a fordításokat, és máris megjelenik a menüben (újraindítás nem szükséges). A felhasználói mappában lévő fájlok felülírják a beépített kifejezéseket azonos `@code` mellett.
  - Hagyd meg a `{helyőrzőket}` változatlanul, és add hozzá a `"@rtl": true` sort a jobbról balra írt írásrendszerekhez. Az üresen hagyott kifejezések angolul maradnak, így a részleges fordítás is megfelelő.
  - A `--list` és `--dump` kimenet szándékosan angol marad: ezeket GitHub-hibajegyekbe szokás beilleszteni.
- **Windows telepítő:** az Inno Setup fordítások az [`installer/lang/`](../../installer/lang) mappában élnek (BOM-mal ellátott UTF-8 formátumban mentve), és az `installer/BatteryHub.iss` fájl `[Languages]` szakasza alatt vannak regisztrálva.
- **Dokumentáció:** minden látható projektdokumentum nyelvenként egyetlen önálló Markdown-fájlként van lefordítva a [`docs/i18n/`](README.md) mappában (új nyelv építőszkriptek nélküli hozzáadásához lásd [`docs/i18n/_template.md`](_template.md)).
- **Oszd meg mindenkivel:** küldj egy pull requestet a `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` és `docs/i18n/` mappákba kerülő fájlokkal. A lépésről lépésre szóló ellenőrzőlistához lásd [`docs/i18n/README.md`](README.md).

## Köszönetnyilvánítás

Alkalmazásikon: [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

A protokollok az alábbi projektek kutatómunkájából származnak:

- [Google Fast Pair specifikáció](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): Fast Pair fülhallgatók bal / jobb / tok akkumulátor-hirdetései
- [HeadsetControl Astro illesztőprogramok](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) és [AstroBar](https://github.com/nichtlegacy/AstroBar): Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 akkumulátor-protokollok; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): A50 Gen 3 `0x72` állapotolvasás

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): VAXEE akkumulátor- és töltésparancsok ([protokoll-dokumentáció](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): SteelSeries, Corsair, HyperX, Logitech és Sony INZONE fejhallgatók
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) és [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) és a Logitech HID++ 2.0 dokumentumok: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) és [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (`0ADF` adapter)
- [rivalcfg](https://github.com/flozz/rivalcfg): SteelSeries egerek (Rival Pro a #294-es pull requestből)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) és [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- A Hitscan webes konfigurátora ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- Linux `hid-kysona` (Lode Willems): Kysona, Pulsar és ATK
- Az ATK webes konfigurátora ([hub.atk.pro](https://hub.atk.pro)): ATK egerek és az N9 Pro / N9 Ultra fejhallgatók
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 és [mouse-battery](https://github.com/qwr79/mouse-battery): ATK / VXE NK NANO adapter
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X és Endgame Gear XM2we, átültetve annak szolgáltatóiból (minden illesztőprogram megnevezi a forrását)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` és [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (csak megállapítások): a Turtle Beach Swarm II eszközcsalád
- A G-Wolves webes illesztőprogramja ([mouse.xyz](https://mouse.xyz)): G-Wolves modellek és protokolljaik
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): CHERRY billentyűzetek a 2,4 GHz-es adapteren (keretformátum és akkumulátor-lekérdezés)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): Keychron egerek
- [NinjaForce](https://www.ninjaforce.co/) és [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): Ninjutso Ten / Ten Air feature lekérdezések
- [nape_pro](https://github.com/nvalis/nape_pro) és [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro a Link-KM vevőn
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): LAMZU egerek
- [vole](https://github.com/johanneszab/vole) és [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): Endgame Gear 4K egerek
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) és [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) és [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (a Finalmouse xpanelből)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) és [g49-web-control](https://github.com/pingpingjinping/g49-web-control): Redragon azonosítók
- [m913-ctl](https://github.com/Qehbr/m913-ctl) és [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): Areson `25A7` keretfelépítés és `GetPower` parancs
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) és [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW és DW
- Az RK webes illesztőprogramja ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) és [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (dokumentáció): MCHOSE A5 Pro / A5 Pro Max (első generáció, `2023` VID)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): CompX vevőjelentések a Delux M900 Próhoz
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) és [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) és [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- A Wraith webes illesztőprogramja ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 és [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 és [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) és [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) a `1532:0550` vevőn; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): a `1532:0552` vevő keretezése
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): Rongyuan és Xenta vevők (Attack Shark és mások)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): SONiX billentyűzetek a 2.4G adapterükön (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) és [ak820-studio](https://github.com/usharik/ak820-studio): AJAZZ AK820 Pro `0C45:FDFD` vevő
- [openajazz](https://github.com/shrey715/openajazz) és [Kraber](https://github.com/AkashPanja/Kraber): Semico `1A2C` (`AA 55 CC 33` / `0x0E`) állapotprotokoll az Attack Shark X98 és AJAZZ AK820 Max Plus eszközökhöz
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) és [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 és MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) és [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): GameSir Cyclone Pro Bluetooth LE „base info” akkumulátorkérés
- [jabridge](https://github.com/Watchdog0x/jabridge): Jabra GNP protokoll (Link 380 / 390 adapterek)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): `1EA7:0066` állapotoldal-protokoll (Fantech Raigor III és más általános 2.4G Mouse eszközök)
- Linux `hid-playstation`: DualShock 4 / DualSense jelentés-elrendezés
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): AULA SC580 / SC580X gyártói protokoll
- RAWM HUB webes alkalmazás ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) és annak eszköztáblázata: RAWM egerek és a SADES Dagger
- [SDL Flydigi HID illesztőprogramja](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) és [HaloBattery #191-es hibajegy](https://github.com/HeyOkay/HaloBattery/issues/191): Vader 5 Pro és Apex 5 lekérdezési keretezés és akkumulátor-elrendezés
- [SDL 8BitDo HID illesztőprogramja](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): 8BitDo Ultimate 2 akkumulátor-bájt
- BEITONG iControl (annak KP20 és KP40D oldalai, valamint a KP20 vevő USB-forgalma): BEITONG KP20 / KP40D akkumulátor-lekérdezés és hasznos teher keverése
- [SDL 8BitDo HID illesztőprogramja](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) és [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): 8BitDo akkumulátor-bájt és gyártói HID protokoll
- JBL QuantumENGINE (annak HIDV3 eszközadat-üzenetei): JBL Quantum fejhallgatók
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, Compx protokoll az `FF02:0002`-n
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) és [BrimDeck](https://github.com/MoFeng2223/BrimDeck): Scyrox V12M profilolvasás
- JBL QuantumENGINE: HIDV1 kapcsolat- és akkumulátor-jelentések a Quantum 350-hez, valamint HIDV3 eszközadat-üzenetek az újabb Quantum fejhallgatókhoz
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): JBL Quantum 610 HIDV1 akkumulátor- és kapcsolatjelentések, valamint a Quantum termékcsalád (360 mint HIDV1 adapteres modell)

## Licenc

[GNU General Public License v3.0 vagy újabb](../../LICENSE). Ezt a szoftvert használhatod, módosíthatod és továbbterjesztheted, de minden általa alapul vett terjesztett munkát ugyanazon licenc alatt, a forráskódjával együtt kell kiadnod.


---

<a id="sec-contributing"></a>
> 📄 **Szakasz:** Közreműködés (`CONTRIBUTING.md`) · [Angol eredeti](../../CONTRIBUTING.md) · [↑ Elejére](#top)

# Közreműködés

## Eszköz működésének jelentése

A legtöbb illesztőprogram protokoll-dokumentáció alapján készült, és nem volt tesztelhető minden modellen.
Kérjük, nyiss egy hibajegyet (issue) az alábbiakkal:

- az eszköz neve, valamint hogy vevővel, kábellel vagy Bluetoothon csatlakozik-e
- a `BatteryHub.exe --list` kimenete
- a `BatteryHub.exe --dump` kimenete
- mit mutat a gyártó saját szoftvere akkumulátorszintként

## Eszköz hozzáadása

1. Futtasd a `BatteryHub.exe --dump` parancsot, és keresd meg az eszközöd gyártó- és termékazonosítóit (VID/PID), valamint a gyártó-specifikus gyűjteményeket (`FFxx` használati oldal) a jelentésméreteikkel együtt.
2. Keresd meg az akkumulátor-protokollt. Jó kiindulási helyek: HeadsetControl, OpenRazer, Solaar, rivalcfg, OpenRGB, OpenLinkHub, vagy a gyártói szoftver USB-forgalmának rögzítése (Wireshark + USBPcap).
3. Ha a gyártónak már van illesztőprogramja a `src/drivers/` mappában, add hozzá a termékazonosítót (és az esetleges eltéréseket) ott. Egyébként hozd létre a `src/drivers/<vendor>.cpp` fájlt:

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

4. Deklaráld a függvényt a `src/drivers/drivers.h` fájlban, hívd meg a `src/devices.cpp` fájl `PollAllDevices()` függvényéből (az általános tartalék-illesztők előtt). A `build.bat` és a Makefile automatikusan felveszi az új fájlokat.
5. Frissítsd az eszköztáblázatot a `README.md` fájlban.

### Szabályok az illesztőprogramokhoz

- **Csak olvasható:** csak állapotot lekérdező kéréseket küldj. Soha ne módosíts beállításokat, világítást vagy üzemmódokat.
- **Pontos illesztés:** csak olyan eszközökkel kommunikálj, amelyeket gyártó- és termékazonosító alapján, vagy a protokollra egyedi gyártó-specifikus gyűjtemény alapján ismersz fel.
- **Mindig legyen időkorlát:** egy hiányzó eszköz nem akaszthatja meg a lekérdezést nagyjából egy másodpercnél tovább. A passzív protokolloknak hosszabb időre lehet szükségük a dokumentált küldési időköz lefedéséhez (például Delux és Rapoo). Tarts fenn egyetlen abszolút, legfeljebb 4 másodperces határidőt egyező gyűjteményenként, ne indítsd újra nem kapcsolódó jelentések miatt, és dokumentáld, miért van szükség a kivételre.
- **Források feltüntetése:** a fájl tetején egy megjegyzésben idézd, honnan származik a protokoll.

## Fordítások

A felületi nyelvek egyszerű, statikus UTF-8 szövegfájlok a `lang/` mappában, amelyeket a program futásidőben tölt be a lemezről mind Windowson, mind Linuxon (másold a `lang/_template.json` fájlt `lang/<code>.json` névre, töltsd ki a `@code`, `@name` értékeket és a kifejezéseket — újrafordítás nem szükséges). A kódban lévő új felületi szövegek a `T(L"...")` vagy — ha értékeket tartalmaznak — a `TF(L"... {name} ...", { { L"name", value } })` híváson mennek keresztül; sose építs lefordított mondatokat darabokból. Kifejezések hozzáadása után add hozzá azokat a `lang/_template.json` fájlhoz is.

A Windows telepítő fordításai az `installer/lang/*.isl` fájlokban élnek (BOM-mal ellátott UTF-8-ként mentve és az `installer/BatteryHub.iss` fájlban regisztrálva), a Linuxos asztali indító megjegyzései a `linux/wireless-battery.desktop` fájlban találhatók, a teljes dokumentáció fordításai pedig a `docs/i18n/<code>.md` fájlokban (egyetlen önálló fájl, amely a `docs/i18n/_template.md` fájlból készült másolással). A teljes közreműködői útmutatót lásd a [`docs/i18n/README.md`](README.md) fájlban.

## Kódstílus

C++17, kizárólag Win32, külső függőségek nélkül. Tartsd kicsin a binárist. Formázd nagyjából úgy, ahogy a meglévő kód teszi (4 szóközös behúzás, 120 oszlopos sorok).

## Windows frissítő fejlesztése

A frissítő kizárólag Windowsra szól, és a WinHTTP, a BCrypt, valamint a meglévő Inno Setup telepítő használatára épül.
Tartsd a frissítési állapotot kizárólag a menüben. Ne adj hozzá frissítési ikonokat, jelvényeket, akkumulátor-eszköztipp módosításokat, buborékokat, toast értesítéseket vagy automatikus párbeszédablakokat. Az eszközök lekérdezése elkülönítve fut a hálózati munkától.

A build verziót és csatornát a C++ és a Windows erőforrás a generált `build/version.h` fájlon keresztül osztja meg. Használd a `make VERSION=1.2.3 CHANNEL=test` vagy `build.bat 1.2.3 test` parancsot helyi teszteléshez; a `dev` az alapértelmezett, a `stable` pedig engedélyezi a hivatalos kiadási ellenőrzéseket. A verziókomponenseknek 0..65535 közé kell esniük. Csak a hivatalos tároló kiadás-címke munkafolyamata választja ki automatikusan a `stable` csatornát. Ne állíts át véletlenül egy fork buildet hivatalos frissítési csatornára.

Futtasd a `make test VERSION=1.2.3 CHANNEL=test` parancsot a meglévő eszköztesztekhez, valamint a szigorú kiadás-feldolgozási, verzió-sorrendezési, ellenőrzés-ütemezési, valódi SHA-256 fájl-ellenőrzési, argumentum-idézési és segédprogram-védelmi tesztekhez. A frissítő regressziós tesztjei lefedik a letöltés befejezésekor történő megszakítást, a párbeszédablak-védelmeket és a HTTP időkorlátok/átirányítási korlátozások sikertelen beállítását is. A Windows teszt belefoglalja az implementációkat a meglévő Linux háttérrendszer-teszt mintáját követve, és helyettesíti a HTTP küldést, így ezek a tesztek nem léphetnek kapcsolatba a GitHubbal. Nem kerülnek csak tesztelésre szolgáló vezérlő belépési pontok az éles kódba. Az egyedi célok a `make test-update-core` és a `make test-update-win`. A natív frissítőtesztek hozzászerkesztik az alkalmazás erőforrását a Common Controls v6 aktiválásához. A tesztek helyi adatokat használnak, és nem töltenek le, nem kérnek emelt jogosultságot, nem telepítenek és nem módosítják a felhasználó automatikus indítási beállításait. Az alkalmazás éles végpontja tesztekhez nem bírálható felül.

Csomagolás előtt futtasd a
`powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3` parancsot.
Az `installer/build-installer.ps1 -Version 1.2.3` szintén lefuttatja ezt az ellenőrzést a függőségek letöltése előtt. A `/WBUPDATE=1` telepítői útvonal megőrzi a meglévő automatikus indítást/beállításokat, és az újraindítást az ideiglenes segédprogramra bízza. Ez a segédprogram az eredeti felhasználó alatt marad, csak globális telepítésnél kér emelt jogosultságot. A WinHTTP leírók a háttérszálhoz tartoznak; a megszakítás együttműködő a véges időkorlátú hívások között. Az alkalmazás végső leállása bevárja ezt a háttérszálat, ezért megvárhat egy folyamatban lévő hálózati időkorlátot.

Kiadás-ellenőrzéshez használj egy eldobható Windows-fiókot vagy virtuális gépet két valódi telepítőverzió, a felhasználónkénti/globális hatókör, az UAC megszakítás, az automatikus indítás be/ki, az egyéni útvonalak, a telepítési hiba és az újraindítás kipróbálásához. Az egységtesztek és a csomag lefordítása nem ellenőrzi ezeket a telepítői hatásokat. A vizuális menü/téma áttekintés és a valódi telepítő/UAC végponttól végpontig tartó ellenőrzések továbbra is manuális kiadási kapuk; ne jelöld őket sikeresnek tényleges megfigyelés nélkül. Soha ne tesztelj a napi használatú felhasználó telepítésének felülírásával.

## Automatikus biztonsági ellenőrzés

Minden pull requestet átvizsgál a „PR safety check” olyan dolgok után kutatva, amelyeket ennek az alkalmazásnak sosem szabad tennie (hálózati hozzáférés, programok indítása, billentyűzet/vágólap/képernyő olvasása, indítási bejegyzések, binárisok, build vagy kiadási módosítások). Egy megjelölés nem elutasítás: egyszerűen magyarázd el a megjelölt sorokat a PR leírásában.

AI eszközök használata rendben van, de kérjük, távolítsd el azokat a `Co-authored-by` sorokat a commit üzeneteidből, amelyek ezeket említik (például `Co-authored-by: Claude ...`). Az ellenőrzés elbukik, amíg ezek jelen vannak.


---

<a id="sec-pr-template"></a>
> 📄 **Szakasz:** Pull Request sablon (`.github/pull_request_template.md`) · [Angol eredeti](../../.github/pull_request_template.md) · [↑ Elejére](#top)

## Mit ad hozzá ez a módosítás

<!-- Eszköz(ök) és gyártó/termékazonosítók, pl. „Acme M1 (1234:5678)”. -->

## Honnan származik a protokoll

<!-- Linkeld be a forrást (másik projekt, gyártói webes illesztőprogram, saját USB-forgalomrögzítés). -->

## Tesztelve valódi hardveren?

<!-- Igen (melyik eszköz, mit írt ki a --list) / Nem -->

## Ellenőrzőlista

- [ ] Csak csak olvasható akkumulátor-lekérdezések kerülnek elküldésre; semmilyen beállítás, világítás vagy firmware nem módosul
- [ ] Csak gyártó-/termékazonosító (vagy protokoll-specifikus gyűjtemény) alapján felismert eszközök érintettek
- [ ] Nincs hálózati hozzáférés, nincs más program indítása, nincsenek új fájlok a `src/`, `docs/` vagy `README.md` helyeken kívül
- [ ] Nincsenek benne binárisok vagy generált fájlok
- [ ] Nincsenek AI eszközöket említő `Co-authored-by` sorok (Claude, Copilot, ChatGPT ...) a commit üzenetekben
- [ ] A `.github/`, `installer/`, `build.bat` vagy `Makefile` módosításai fentebb el vannak magyarázva


---

<a id="sec-releasing"></a>
> 📄 **Szakasz:** Kiadás (`docs/releasing.md`) · [Angol eredeti](../../docs/releasing.md) · [↑ Elejére](#top)

# Kiadás

Az alkalmazás GitHub-kiadásokból frissíti önmagát, de csak olyan telepítőt telepít, amelynek SHA-256 értéke szerepel egy a kiadási kulccsal aláírt `SHA256SUMS.txt` fájlban. Ez a kulcs a karbantartó PC-jén él, soha nem a GitHubon: egy feltört fiók, token vagy munkafolyamat közzétehet fájlokat, de az alkalmazás által elfogadott aláírást nem.

## Egyszeri teendő: a kiadási kulcs létrehozása

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Jelszót kér (legalább 12 karakter), és kiírja a titkosított privát kulcsot a
  `%USERPROFILE%\.wirelessbattery\release-key.wbk` fájlba.
- Beleteszi a nyilvános kulcsot a `src\update_public_key.h` fájlba. Commitold ezt a fájlt. A hivatalos buildek megtagadják a fordulást benne lévő kulcs nélkül.
- **Készíts biztonsági mentést a kulcsfájlról és őrizd meg a jelszót** (egy jelszókezelő mindkettőhöz jó hely). Ha bármelyik elvész, a telepített alkalmazások többé nem tudják frissíteni magukat: új kulcsot kellene létrehozni, és minden felhasználónak kézzel kellene telepítenie egy kiadást.

## Minden kiadásnál

1. Tolj fel egy verziócímkét (`git tag v1.2.3 && git push origin v1.2.3`). A CI lefordítja a telepítőt, a hordozható ZIP-et és a `SHA256SUMS.txt` fájlt, majd közzéteszi a kiadást.
2. Írd alá az ellenőrzőösszeg-listát:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Letölti a `SHA256SUMS.txt` fájlt a kiadásból, megjeleníti, megerősítést kér, bekéri a kulcs jelszavát és kiírja a `SHA256SUMS.txt.sig` fájlt. Ha ugyanazok a fájlok megvannak a `dist\` mappában (egy helyi build ebből a verzióból), megmutatja, egyeznek-e.
3. Töltsd fel a `SHA256SUMS.txt.sig` fájlt a kiadáshoz (a szkript megnyitja a szerkesztőoldalt). Ettől kezdve az alkalmazás felajánlja a **Letöltés és telepítés** lehetőséget. Előtte megmutatja a frissítést, de csak a kiadási oldalra hivatkozik.

Csak olyan kiadás listáját írd alá, amelyet magad tettél közzé. Az aláírás azt jelenti, hogy „pontosan ezek a fájlok alkotják a kiadást”, így az aláírás az a lépés, ahol egy rosszindulatú feltöltés fennakadna.

## A kulcs cseréje

Futtasd a `new-release-key.ps1` szkriptet egy új `-KeyFile` paraméterrel: hozzáadja az új nyilvános kulcsot a régi mellé a `src\update_public_key.h` fájlban. Adj ki egy olyan verziót a régi kulccsal aláírva, amely mindkettőt tartalmazza, majd a következő kiadástól írj alá az új kulccsal, és később távolítsd el a régit. Elveszett vagy kiszivárgott kulcsot nem lehet így nyugdíjazni: távolítsd el a fejlécfájlból, és a régebbi verziók felhasználóinak kézzel kell telepíteniük a következő kiadást.

## Mit ellenőriz az alkalmazás a telepítő futtatása előtt

- A kiadás a tároló legújabb kiadása, nem piszkozat vagy előzetes kiadás, és újabb az alkalmazásnál.
- A `SHA256SUMS.txt.sig` a `SHA256SUMS.txt` érvényes ECDSA P-256 aláírása a `src\update_public_key.h` egyik kulcsával (Windows BCrypt, külső kód nélkül).
- Az aláírt lista pontosan egyszer nevezi meg a `BatteryHub-Setup-<version>.exe` fájlt, ugyanazzal a SHA-256 értékkel, amelyet a GitHub jelent a fájlhoz.
- A letöltött telepítő pontosan ezzel a mérettel és SHA-256 értékkel rendelkezik. Az alkalmazás egy másolata közvetlenül az indítás előtt újra ellenőrzi, és zárolva tartja a fájlt, hogy közben ne lehessen kicserélni.
- A letöltések kizárólag HTTPS-t használnak a `github.com`, `objects.githubusercontent.com` és `release-assets.githubusercontent.com` címek felé, minden átirányítást ellenőrizve.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Szakasz:** Keychron billentyűzet-firmware (`docs/keychron_keyboard_firmware/README.md`) · [Angol eredeti](../../docs/keychron_keyboard_firmware/README.md) · [↑ Elejére](#top)

# Keychron billentyűzet akkumulátora a 2,4 GHz-es vevőn keresztül

A Keychron gyári firmware-e csak Bluetoothon jelenti a billentyűzet akkumulátorát. A [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch) fájlban található kis QMK-módosítással a billentyűzet a Keychron Link vevőn és az USB-kábelen keresztül is válaszol az akkumulátor-lekérdezésre (`A4`), a BatteryHub pedig megjeleníti a töltöttségi szintjét, feszültségét és töltési állapotát.

Tesztelve a **Keychron K5 Max ANSI RGB** (`3434:0A50`) billentyűzeten a Keychron Link vevővel (`3434:D030`).

## Mit változtat meg a javítás

A [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) tároló `2025q3` ága (`57e682c` commit) alapján:

- hozzáadja a `KC_GET_BATTERY` (`0xA4`) nyers HID parancsot a [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1) PR-ból:
  válasz `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`;
- a vezeték nélküli kapcsolaton érkező nyers HID kéréseket ugyanahhoz a kezelőhöz továbbítja;
- a `keyboards/keychron/k5_max/config.h` fájlban: `#define WILRESS_RAW_ENABLE` (a Keychron kódjában így van írva) és
  `#define KC_BATTERY_MODEL_ID 0`.

Semmi más nem változik: a billentyűkiosztások, a világítás és a Keychron Launcher továbbra is működnek.

## 1. lehetőség: az előre elkészített K5 Max firmware felírása

A **kizárólag K5 Max ANSI RGB-hez** készült build csatolva van
[ehhez a kiadáshoz](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)
(`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`).
Ne írd fel más modellre vagy kiosztásra.

## 2. lehetőség: fordítsd le magad

Szükséges hozzá Git és Docker (vagy egy működő [QMK környezet](https://docs.qmk.fm/newbs_getting_started)).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

Az eredmény a `keychron_k5_max_ansi_rgb_keychron.bin` fájl a tároló gyökerében. Windowson a bind-mountolt munkakönyvtár nagyon lassú a Dockerben; a konténeren belüli klónozás (vagy a WSL használata) sokkal gyorsabb.

**Egyéb Keychron vezeték nélküli billentyűzetek** (`LK_WIRELESS_ENABLE` beállítással rendelkező Q/V/K Max és más modellek a `2025q3` fán):
a `keyboards/keychron/common/` alatti módosítások változatlanul alkalmazhatók. Add hozzá a két `#define` sort a billentyűzeted `config.h` fájljához a K5 Maxé helyett, és fordítsd le a saját célodat, pl. `make keychron/<model>/<layout>/<variant>:keychron`.
Az alkalmazás jelenleg a K5 Max (`0A50`–`0A58`) modelleket név szerint, minden másikat pedig „Keychron keyboard” néven jelenít meg.

## Flashelés

1. Állítsd a módváltó kapcsolót **Cable** állásba, és húzd ki az USB-kábelt.
2. Tartsd nyomva az **Esc** billentyűt, miközben bedugod a kábelt. A billentyűzet belép az STM32 bootloaderbe.
3. Írd fel a `.bin` fájlt a [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (vagy a `dfu-util`) segítségével.
4. Kapcsolj vissza **2.4 GHz** állásba, és ellenőrizd a `BatteryHub.exe --list` paranccsal:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

A billentyűzet frissítése a Keychron Launcherben felülírja ezt a firmware-t és eltávolítja az akkumulátor-jelentést. A visszaállításhoz flasheld ugyanígy a Keychron hivatalos firmware-ét.

## Licenc

A QMK GPL-2.0-or-later licencű; a javítás ugyanazon licenc alatt áll. Bárki, aki ebből fordított binárist kap, jogosult kell legyen e forráskód-módosítás megszerzésére is.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Szakasz:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [Angol eredeti](../../docs/gamesir_cyclone_pro.md) · [↑ Elejére](#top)

# GameSir Cyclone Pro akkumulátor-támogatás

## Miért látszott a kontroller teljes Xbox kontrollerként

A Cyclone Pro (T4cp modell) egy 2,4 GHz-es adapteren, a `3537:1015`-ön keresztül kommunikál. Az adapter vezetékes Xbox 360 kontrollerként (XUSB, `Xbox 360 Controller for Windows`) jelenik meg a Windows számára. Az XInput „Tele” válasszal felel az akkumulátor-lekérdezésére, így az XInput tartalék `Xbox controller 1`-ként listázta 100%-kal, bármi is volt a valódi töltöttség.

Az adapter nem hordoz semmilyen akkumulátor-információt:
- egyetlen HID-gyűjteménye az XInput játékkontroller (`HID\VID_3537&PID_1015&IG_00`)
- nincs gyártó által definiált gyűjteménye, mint a Novának (`FF7A`) vagy a Cyclone 2-nek (`FFF0`)

## Hol található a töltöttségi szint

Miközben az adapteren keresztül játszik, a kontroller Bluetooth LE-n is hirdeti magát `GameSir-Cyclone Pro` néven, amelyet a GameSir telefonos alkalmazása használ. Ennek a „get base info” kérése adja vissza az akkumulátort:

| Lépés | Részlet |
|---|---|
| Szolgáltatás | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Jellemző (Characteristic) | `0x865F` (értesítés, válasz nélküli írás) |
| Kérés | értesítések engedélyezése, `01 01` írása |
| Válasz | 19 bájtos értesítés (egyes firmware-ek `C9`-cel előtagolják, 20 bájt) |

A válasz felépítése:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

A 18. bájt az akkumulátor százalékban (0–100), vagy `FF` töltés közben. Töltés közben nem jelent szintet, így az utolsó ismert százalék megmarad és a töltési villámmal jelenik meg.

A kontrollernek van egy `0xFF10` szolgáltatása is, amely a GameSir firmware-frissítési csatornája. Az illesztőprogram sosem nyitja meg. A kontrollernek nincs szabványos Battery Service (`0x180F`) szolgáltatása, ezért nem mutat hozzá szintet a Windows Bluetooth oldala és a Bluetooth tartalék sem.

Forrás: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), ahol a protokollt a GameSir Androidos alkalmazásából (`BluetoothLeService`, „get base info”) fejtették vissza.

## Hogyan működik az illesztőprogram

A `src/drivers/gamesir_ble.cpp` az XInput tartalék előtt hívódik meg:

1. **A kontroller megtalálása.** Megkeresi a `{00008650-0000-1000-8000-00805F9B34FB}` osztályú eszközinterfészeket. A Windows minden párosított BLE-eszköz minden GATT szolgáltatásához létrehoz egyet. Csak azokat használja, amelyek szülő `BTHLE\DEV_…` csomópontjának neve `GameSir-Cyclone…`.
2. **Az akkumulátor kiolvasása.** Megnyitja ezt a szolgáltatást a Win32 GATT API-val (`bluetoothleapis.h`, `-lbluetoothapis`), feliratkozik a `0x865F`-re és beírja a `01 01` értéket. Legfeljebb 3 másodpercet vár a válaszra, majd kikapcsolja az értesítéseket.
3. **A lekérdezés gyorsan tartása.** A BLE-kapcsolat másodpercekig tarthat vagy időtúllépéssel leállhat, amíg a kontroller alszik, ezért a lekérdezés saját szálon fut:
   - legfeljebb 2 percenként sikeres olvasás után, vagy percenként sikertelen után
   - a lekérdezés a gyorsítótárazott mérést jelenti, és leállítja annak jelentését, amint az 6 perces lesz
   - a `graceSec` ezután halványítva, alvóként tartja láthatóan
   - csak egy futtatás első lekérdezése várja meg a szálat, egyszer, abszolút 4 másodperces határidővel, így a szint megjelenik induláskor és a `--list` kimenetben
4. **A hamis Xbox bejegyzés elrejtése.** Amikor az adapter jelen van, az illesztőprogram lefoglalja a `3537:1015` azonosítót:
   - a `Windows.Gaming.Input` útvonal most kihagyja a lefoglalt gyártó/termékazonosítókat
   - az XInput útvonal lekéri az egyes helyek gyártó/termékazonosítóját az `XInputGetCapabilitiesEx` (`xinput1_4` 108-as sorszám) függvényből, és kihagyja a lefoglaltakat
   - amikor ez az export hiányzik, az XInput a korábbiak szerint viselkedik

## Tesztelt hardver

Windows 11, Cyclone Pro az adapterén (`3537:1015`), egyszer párosítva Bluetoothon, 2026-11-18-án:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Amíg a kontroller aludt, az „Xbox controller 1 / Full” bejegyzés többé nem jelent meg, és semmi sem látszott a kontrollerhez.

## Korlátozások

- **Párosítás:** a kontrollert egyszer párosítani kell a Windowszal (Gépház > Bluetooth és eszközök > Eszköz hozzáadása > Bluetooth > `GameSir-Cyclone Pro`). A nem párosított kontrollereknek nincs GATT eszközinterfészük. A párosítás hozzáad Bluetooth kontroller-bejegyzéseket, de ezek nem küldenek bemenetet, amíg a kontroller az adapteren keresztül játszik.
- **Bluetooth szükséges:** a PC-nek Bluetooth LE-vel kell rendelkeznie.
- **Egy kontroller:** PC-nként csak egy Cyclone Pro kerül kiolvasásra.
- **Töltés:** töltés közben nincs százalékérték.


---

<a id="sec-localization-guide"></a>
> 📄 **Szakasz:** Többnyelvű használati és honosítási útmutató (`docs/i18n/README.md`) · [Angol eredeti](../../docs/i18n/README.md) · [↑ Elejére](#top)

# BatteryHub többnyelvű névjegyzék és honosítási útmutató

A tároló minden látható dokumentuma nyelvenként **egyetlen önálló Markdown-fájlban** gyűlik össze a `docs/i18n/` mappában, míg az alkalmazás összes futásidejű szövege **statikus, szerkeszthető szövegfájlokban** él a [`lang/`](../../lang) mappában (Windows és Linux által megosztva), a Windows telepítő szövegei pedig az [`installer/lang/`](../../installer/lang) mappában találhatók.

## Támogatott nyelvek (19)

| Kód | Nyelv | Teljes dokumentáció | Alkalmazás felülete (Windows & Linux) | Windows telepítő |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (forrásszövegek) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Hogyan működik a nyelvváltás a gyakorlatban

### 1. Windows alkalmazás (`BatteryHub.exe`)
- **Automatikus felismerés:** Ha a *Nyelv → Automatikus (Windows nyelve)* beállítás aktív, a BatteryHub lekérdezi a Windows `GetUserPreferredUILanguages` API-ját, és kiválasztja a legközelebbi statikus `*.json` fájlt.
- **Kézi váltás:** Kattints a tálca-widgetre vagy a tálcaikonra → **Nyelv** → válassz nyelvet. A felület azonnal frissül és a `HKCU\Software\WirelessBattery\Language` kulcsban tárolódik.
- **Statikus külső fájlok (újrafordítás nélkül szerkeszthetők):** A `BatteryHub.exe` először az `<exe>\lang\*.json` fájlokat tölti be, majd a `%APPDATA%\WirelessBattery\lang\*.json` mappát. A felhasználói mappában található, azonos `@code` kóddal rendelkező fájlok felülírják az egyező kifejezéseket, és a menü újranyitása élőben újratölti a fájlokat a lemezről.
- **Parancssori `--help`:** A `BatteryHub.exe --help` az aktív felületi nyelven jeleníti meg a súgóablakot (a `--list`, `--json` és `--dump` szándékosan angol marad a GitHub-hibajegyekhez).

### 2. Linux alkalmazás (`wireless-battery`)
- **Automatikus felismerés:** Sorrendben követi a POSIX területi változókat: `LANGUAGE` (kettősponttal elválasztott lista) → `LC_ALL` → `LC_MESSAGES` → `LANG` (kivéve, ha az `LC_ALL=C` / `POSIX` felülírja).
- **Kézi váltás:** Kattints jobb gombbal a tálcaikonra → **Nyelv** → válaszd az **Automatikus (rendszernyelv)** vagy bármely telepített nyelvet. A `$XDG_CONFIG_HOME/wireless-battery/config.ini` (alapértelmezés szerint `~/.config/wireless-battery/config.ini`) fájlban, a `[general] language=` alatt mentődik.
- **Statikus keresési útvonalak (legalacsonyabb prioritástól a legmagasabbig):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (alapértelmezés: `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (alapértelmezés: `~/.config/wireless-battery/lang/`)
- **Parancssori `--help`:** A `wireless-battery --help` a `config.ini` vagy a rendszer területi beállítása alapján lefordított parancssori súgót ír ki; a `--list` és `--dump` angol marad.

### 3. Windows telepítő (`BatteryHub-Setup-<version>.exe`)
- Nyelvválasztóval indul (`ShowLanguageDialog=yes`), előre kiválasztva a Windows felületi nyelve alapján (`LanguageDetectionMethod=uilanguage`).
- A teljes statikus `lang\*.json` könyvtárat telepíti az `{app}\lang\` mappába a `BatteryHub.exe` mellé (és a hordozható ZIP is ugyanígy tartalmazza a `lang\*.json` fájlokat).

---

## Új nyelv hozzáadása vagy frissítése (lépésről lépésre)

**Nincs** szükséged semmilyen fordítóeszközre az alkalmazás felületének vagy a dokumentációnak a lefordításához, és az Inno Setup 6 is csak akkor kell, ha tesztfordítani szeretnéd a Windows telepítőt.

### 1. lépés — Alkalmazás felületi szövegei (`lang/<code>.json`)
1. Nyisd meg a felhasználói nyelvmappát a tálcamenüből (**Nyelv → Saját nyelv hozzáadása...**), vagy másold a [`lang/_template.json`](../../lang/_template.json) fájlt `lang/<code>.json` névre (pl. `lang/it.json`).
2. Töltsd ki a metaadat-fejlécet:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Fordítsd le a jobb oldalt a ` = ` jel után minden sorban.
   - Tartsd meg pontosan a helyőrzőket, mint például `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}`.
   - Használd a `\n` karakterláncot az explicit sortörésekhez.
   - Mentsd el **UTF-8 (BOM nélkül)** kódolással.
   - Nyisd meg újra a BatteryHub tálcamenüjét az azonnali előnézethez — nincs szükség újrafordításra!

### 2. lépés — Windows telepítő (`installer/lang/<code>.isl`)
1. Másold az [`installer/lang/_template.isl`](../../installer/lang/_template.isl) fájlt `installer/lang/<code>.isl` névre.
2. **KRITIKUS:** Mentsd el a fájlt **BOM-mal ellátott UTF-8 (`EF BB BF`)** formátumban, hogy az Inno Setup megbízhatóan dekódolja a Unicode karaktereket a régi Windows kódlapoktól függetlenül.
3. Válaszd ki a megfelelő mintát:
   - **Az Inno Setup már tartalmazza a nyelvedet** (ellenőrizd a `C:\Program Files (x86)\Inno Setup 6\Languages\` mappában): csak a `[CustomMessages]` szakaszt tartsd meg, és fordítsd le a 6 sort (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, megőrizve a `%1` és `%n` helyőrzőket). Regisztráld az `installer/BatteryHub.iss` fájlban a `[Languages]` alatt:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Az Inno Setup nem tartalmazza a nyelvedet**: másold az `installer/lang/zh-CN.isl` fájlt teljes referenciaként, állítsd be a `[LangOptions]` értékeket (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, opcionálisan `RightToLeft=yes`), fordítsd le a `[Messages]` és `[CustomMessages]` szakaszokat, majd regisztráld a `Default.isl` után:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Megjegyzés: a `[Languages]` alatti `Name:` azonosítók csak ASCII betűket, számjegyeket és aláhúzásjeleket tartalmazhatnak (használj `ptBR`-t a `pt-BR` helyett).

### 3. lépés — Linux asztali indító (`linux/wireless-battery.desktop`)
Adj hozzá egy honosított `Comment[<code>]=...` sort (a `.desktop` fájlokban használj aláhúzásjelet a regionális címkékhez, pl. `Comment[zh_CN]=...`).

### 4. lépés — Teljes egyfájlos dokumentáció (`docs/i18n/<code>.md`)
1. Másold a [`docs/i18n/_template.md`](_template.md) fájlt `docs/i18n/<code>.md` névre (nincs szükség generáló szkriptekre — csak erre az egyetlen fájlra!).
2. Fordítsd le teljes egészében a Tartalomjegyzéket és mind a 17 szakaszt, miközben pontosan megőrzöd:
   - Az összes `<a id="sec-..."></a>` és `<a id="top"></a>` horgonycímkét
   - Az összes kódblokkot, parancssori kapcsolót (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), USB `VID:PID` azonosítót, HID használati oldalt, hexadecimális csomagot, rendszerleíró kulcsot, fájlútvonalat és URL-t
   - A relatív kép-/fájlútvonalakat (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE` stb.)
3. Frissítsd a felső `<!-- lang-switcher:start -->` sávot a `docs/i18n/<code>.md` fájlban (tedd félkövérré a saját nyelvedet, linkeld az összes többit), add hozzá a nyelved linkjét a nyelvválasztó sávokhoz a `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` és a testvér `docs/i18n/*.md` fájlokban.
4. Jobbról balra írt nyelveknél (`ar`, `fa`, `he`) írj szabványos Markdownt anélkül, hogy az egész fájlt `<div dir="rtl">` elembe csomagolnád, így a táblázatok és kódblokkok tisztán jelennek meg.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Szakasz:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [Angol eredeti](../../docs/ardor_fury_v2.md) · [↑ Elejére](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

A 2,4 GHz-es vevő a `000A` HID használati oldalt, a `0000` használatot és egy 5 bájtos bemeneti jelentést tesz közzé. Adatokat sugároz; nem kerülnek elküldésre HID parancsok.

Valódi hardverről megfigyelt jelentések:

| Jelentés | Akkumulátor |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

A 3. bájt felső félbájtja (nibble) kódolja a szintet (`1`, `3`, `7`, `F` a 25, 50, 75 és 100 százalékhoz). A 25%-os és 100%-os jelentések a gyártói alkalmazás dekódolási logikájából lettek kikövetkeztetve; a végfelhasználó ezt követően megerősítette, hogy a többi szint is helyesen jelenik meg a lefordított alkalmazásban. Az ötödik bájt nem állandó, és nincs aláírásként használva.

A figyelőnek két egyező dekódolt akkumulátorszintre van szüksége, nem pedig két azonos teljes jelentésre. Az utolsó megerősített érték legfeljebb 45 másodpercig marad meg. A globális automatikus frissítési időköz 15 másodpercre változik.

Végfelhasználó által ellenőrizve Windowson ARDOR Fury V2-vel és Logitech G733-mal: 50%-os és 75%-os rögzítések, időszakos automatikus frissítés, 25%/100%-os vizuális ellenőrzések és hordozható indítás. A 25%-os és 100%-os jelentések nem lettek rögzítve.


---

<a id="sec-areson"></a>
> 📄 **Szakasz:** Areson `25A7` (`docs/areson.md`) · [Angol eredeti](../../docs/areson.md) · [↑ Elejére](#top)

# Areson 25A7 vevő akkumulátor-támogatás

## Miért hagyta ki az eredeti program az egeret

A Redragon M915RGB-WL egy Areson/CompX `25A7:FA07` „2.4G Wireless Receiver” vevőn keresztül csatlakozik. Az akkumulátora nincs szabványos HID *Battery Strength* használatként közzétéve, és a Windowsnak sincs hozzá Bluetooth akkumulátor-tulajdonsága, mivel a kapcsolat egy saját 2,4 GHz-es protokoll. Az egér ehelyett egy aktív `GetPower` kérésre válaszol, így sem az általános HID tartalék, sem a Bluetooth tartalék nem tudta látni. A gyártóhoz nem volt illesztőprogram, így a vevő lefoglalatlan és néma maradt.

## Megfigyelt hardver és csomagok

Tesztelve Windows 11-en egy Redragon M915RGB-WL egérrel 2026-11-17-én:

| Irány | VID:PID | Interfész | Használati oldal:használat | Jelentésméret |
|---|---|---|---|---|
| kérés (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 bájt |
| válasz (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 bájt |

A válasz egy másik legfelső szintű gyűjteményen érkezik, mint amelyikre a kérés íródik. Windowson ezek a `MI_01&COL07` (feature) és a `MI_01&COL05` (input), ezért nyitja meg az illesztőprogram mindkét leírót.

Rögzített kérés (`GetPower`, jelentésazonosító `08`, parancs `04`, az ellenőrzőösszeg `0x55`-re egészíti ki a keret összegét):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Rögzített válasz:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Az alábbi eltolások a jelentésazonosítót számolják nulladik bájtnak:

| Bájt(ok) | Jelentés | Példa |
|---|---|---|
| 0 | Válasz jelentésazonosító | `09` |
| 1 | Parancs visszhang | `04` |
| 2 | Állapot, 0 = OK | `00` |
| 3–4 | Cím, a `GetPower`-nél nincs használva | `00 00` |
| 5 | Adathossz (2) | `02` |
| 6 | Akkumulátorszint, 0–10, 10%-os lépésekben | `08` = 80% |
| 7 | Töltésjelző, bármely nem nulla érték | `00` = nem töltődik |
| 16 | Ellenőrzőösszeg; mind a 17 bájt összege `0x55` (mod 256) | `3E` |

A gyártó saját szoftvere ugyanahhoz a kerethez 80%-ot mutatott, ami igazolja a ×10-es skálát. A `GetConnectStatus` (`08 03 …`) egy 1 bájtos hasznos teherrel válaszol, és ugyanebben az időben csatlakoztatottként jelentette az egeret.

## Egyéb Areson egerek

A Redragon M693 által használt régebbi `FA7B` / `FA7C` vevők ugyanezen a válaszeloláson közvetlenül egész százalékként jelentik a töltöttséget. Ennek az illesztőprogramnak a ×10-es skáláját alkalmazva ott 800% jelenne meg, ezért ezek a termékazonosítók szándékosan nincsenek lefoglalva. Csak az `FA07` és `FA08` kezeltek; az `FA08` ugyanannak a családnak az alternatív azonosítója, és ezen a gépen nem volt ellenőrizve.

## Lekérdezés és azonosság

- Az illesztőprogram csak a csak olvasható `GetPower` kérést küldi. Soha nem ír konfigurációs, világítási vagy DPI adatokat.
- Minden frissítés megnyitja a feature gyűjteményt nulla hozzáféréssel és a bemeneti gyűjteményt olvasásra, elküldi a kérést és legfeljebb 1,8 másodpercig vár válaszra, két próbálkozással és köztük sor-kiürítéssel, hogy egy elavult jelentést ne lehessen válasznak nézni.
- A sikertelen olvasás nem foglal le semmit, így az alvó egér megtartja az utolsó értéket a felületen. A bejegyzés 30 perces türelmi időt használ, összhangban a többi passzív illesztőprogrammal.
- Az eszközkulcs a gyártó- és termékazonosítóból származik (`areson:25A7:FA07`), így túléli a vételi/alvási ciklust és a vevő kihúzását-visszadugását.

## Ellenőrzés

A teljes alkalmazás MSVC C++17 és Windows SDK segítségével lett lefordítva, és a valódi egéren futtatva. A `BatteryHub.exe --list` ezt adta vissza:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

A mérés megegyezett a hivatalos Redragon szoftver által ugyanabban a pillanatban kijelzett százalékkal. A MinGW `build.bat` tartalmazza az új forrásfájlt; a `Makefile` pedig helyettesítő karakterrel fedezi fel.

## Protokollforrások

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): 17 bájtos keretek, feature/input szétválasztás és a `0x55` ellenőrzőösszeg-szabály, a Redragon szoftver USB-rögzítéseiből visszafejtve.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): `GetPower` parancs és a 10%-os szintskála a `25A7:FA07` eszközön.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md): válasz-elrendezés és az eltérő százalékskála az `FA7B` / `FA7C` családon.


---

<a id="sec-darkrim"></a>
> 📄 **Szakasz:** DARKRIM SHADOW (`docs/darkrim.md`) · [Angol eredeti](../../docs/darkrim.md) · [↑ Elejére](#top)

# DARKRIM SHADOW / 寸渊影弑 vevő

Hardveren tesztelve a `3654:6901` eszközön, gyártó: `Jieli Technology`, kiadás: `0100`. Használd a **3-as** interfészt, `FF02:0002` használattal, számozatlan 64 bájtos bemeneti/kimeneti hasznos teherrel (65 bájtos Windows HID jelentésméretek). A 4-es interfésznek is van `FF02:0002`, de 2-es jelentésazonosítót használ és nem válaszolt erre a protokollra; szándékosan ki van zárva.

Protokollforrás: a hivatalos [PC Hub letöltés](https://app.darkrim.net/hub/zh.html), `DARKRIM-0.1.26-x64-setup.rar`, letöltve és statikusan kicsomagolva a gyártói szoftver telepítése vagy elindítása nélkül. A kicsomagolt `DARKRIM.exe` SHA-256 értéke: `f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Hasznos címek ebben a binárisban:

- `140124C80`: a `sendGetBasicInfo(infoType)` elküldi a `0010` parancsot, Request `01`, hasznos teher `[infoType, 00]`. Az akkumulátor választója `01`.
- `140118D30`, `140119200`: keretfejléc és CRC előállítása.
- `140126DB0`: eszközadat TLV értelmező; a `01`-es TLV az akkumulátor.
- `1400F5660`, `1400FA700`: akkumulátor-fogyasztók; az alsó hét bit adja a százalékot, a felső bit a töltést. Ugyanez az akkumulátorérték megérkezik a `0011` Notify `03`-ban is.

Fejléc: `FE seq cmdLE type index count lengthLE`, majd a hasznos teher és a CRC-16/CCITT-FALSE (`1021` polinom, kezdeti `FFFF`, big-endian tárolással). A szekvencia egy nem nulla négybites számláló; a titkosítás nincs használatban.

Valódi kérés/válasz hasznos terhek, HID nullával való kitöltés előtt:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

A `01 01 28` válasz TLV **40%-ot, nem töltődik** értéket ad. Az éles C++ illesztőprogram ezt az értéket adta vissza három egymást követő lekérdezésnél a gyártói szoftver nélkül. A vevő az egyező válasz előtt indítási értesítéseket bocsát ki, körülbelül 406 ms-ra mérve. Használj egyetlen 800 ms-os válaszhatáridőt (plusz legfeljebb 200 ms-ot az íráshoz), anélkül hogy újraindítanád nem kapcsolódó értesítések miatt. Szívverés (heartbeat) nem szükséges.

Az illesztőprogram csak az akkumulátor GET kérést küldi el. Csak titkosítatlan választ fogad el egyező szekvenciával/paranccsal/típussal, nulla indexszel, nulla vagy egy darabszámmal (a hardver nullát használ), érvényes hosszal/CRC-vel és egyetlen szabályosan formázott akkumulátor TLV-vel. A töredezett, kéretlen, hibás és tartományon kívüli válaszok figyelmen kívül maradnak.

## Megfigyelt akkumulátor-pontosság és töltési állapot

Kezeld a százalékot **durva becslésként, ne igazolt 1%-os felbontású mérőként**. A tulajdonos egysége a töltési folyamatot 10 százalékpontos lépésekben jelezte 40%-tól 90%-ig. 90%-nál öt akkumulátor GET válasz és egy kéretlen értesítés mind `DA`-t hordozott: `DA & 7F = 90`, a 7. bit pedig a töltést jelezte. Miután a tulajdonos kihúzta a töltőkábelt és tovább használta a 2,4 GHz-es vevőt, további öt GET válasz és egy értesítés mind `5A`-t hordozott: továbbra is 90%, immár törölt töltésbittel. Mind a tizenkét keret átment a CRC ellenőrzésen.

Tipikus lekérdezési válaszok (4-es szekvencia):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Az illesztőprogram és a hivatalos alkalmazás egyaránt közvetlenül az alsó hét bitből veszi a százalékot. Az illesztőprogram nem kerekít tízesekre, nem szoroz meg egy fokozatot tízzel, és nem interpolál közbenső értékeket; a szintetikus 47%-os és 95%-os jelentések 47% és 95% maradnak az éles értelmezőben. A megfigyelt durva értékek tehát az értelmező előtt, a fejhallgató/vevő jelentésében keletkeznek. Finomabb hardvermérések nem voltak megfigyelhetők. Teljes merülési görbe nem lett rögzítve, így a fix 10%-os lépésköz minden merülési szinten vagy más firmware-en nem megerősített.

A töltés és az azt követő nem töltő állapot 90%-on hardveren ellenőrizve lett. Az alacsony/teljes határok, a fejhallgató kikapcsolási viselkedése, a Bluetooth és az USB-kábeles adatátviteli mód nem lettek hardveren tesztelve. Ezekre a módokra nem teszünk támogatási ígéretet. Ez az implementáció nem tartalmaz firmware-frissítéseket, konfigurációmódosításokat, EQ parancsokat, párosítás-módosításokat, visszaállításokat vagy gyártói binárisokat.

Teszt: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Szakasz:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [Angol eredeti](../../docs/hyperx_haste_2.md) · [↑ Elejére](#top)

# HyperX Pulsefire Haste 2 Wireless akkumulátor-protokoll

A `src/drivers/hyperx.cpp` fájlban a `HasteWireless` olvassa ki. A lekérdezések a [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) projektből származnak, és ugyanazok, amelyeket az NGENUITY használ.

Hardveren igazolva:

- Pulsefire Haste 2 Core Wireless, `03F0:0AB5` adapter.
- Pulsefire Haste 2 Wireless, `03F0:0F98` adapter, uzumakiprime által (PR #312). A szint megegyezett a HyperX NGENUITY-val.

A `03F0:0D97` adapter várhatóan ugyanúgy működik, de nincs tesztelve.

## HID-gyűjtemény

| Mező | Érték (`0F98`) |
|---|---|
| USB-interfész | `MI_02` (2. interfész) |
| Használati oldal : használat | `FF00:0001` |
| Bemeneti / kimeneti / feature jelentéshossz | 64 / 64 / 64 bájt |

Az adapter a szabványos egér és fogyasztói vezérlő (consumer-control) gyűjteményeket is közzéteszi. Az illesztőprogram csak olyan gyártói gyűjteményt nyit meg (`FF00` vagy magasabb használati oldal), amelynek bemeneti jelentései legalább 8 bájtosak.

## Lekérdezések

Mindkettő kimeneti jelentés: az alábbi első két bájt, nullával kitöltve a jelentés hosszáig. Minden válasz egy bemeneti jelentés, amelynek első bájtja a parancs plusz egy. Minden lekérdezés legfeljebb egy másodpercet vár a válaszra, és átugorja a nem kapcsolódó jelentéseket (újracsatlakozás után az adapter magától küld `44 xx`, `45 xx` és `FB xx` jelentéseket).

| Kérés | Válasz | Jelentés |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0, ha az egér ki van kapcsolva vagy hatótávon kívül van |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0–100; `charge` 1 = töltődik, 2 = tele a töltőn; feszültség mV-ban, little endian (0 a Core modellen) |

- Ha a kapcsolatválasz hiányzik, az akkumulátorválasz dönt.
- Ha a kapcsolat 0-t jelent, nem küld akkumulátor-lekérdezést, és az egér kikapcsoltként jelenik meg.
- Az egér bekapcsolása után néhány másodpercig körülbelül 40%-ot jelent. A kapcsolat felépülésétől számított 6 másodpercen belüli mérés figyelmen kívül marad, és a tálca megtartja az utolsó értéket.

Mindkét kérés csak állapotot olvas. Semmi sem módosít beállításokat, világítást vagy üzemmódokat.


---

<a id="sec-inphic"></a>
> 📄 **Szakasz:** Inphic IN10 (`docs/inphic.md`) · [Angol eredeti](../../docs/inphic.md) · [↑ Elejére](#top)

# Inphic IN10 család, KP 8K vevő

A csatlakoztatott eszköz, amelyet tulajdonosa IN10 MAX-ként azonosított, `Inphic KP 8K`, `1D57:FA65`, `0116` kiadásként sorolódik fel. Állapotgyűjteménye a 2. interfész, `000A:0000` használat, 5 bájtos bemeneti hossz (beleértve a 03 jelentésazonosítót).

Körülbelül négy másodpercenként megfigyelve, kérés küldése nélkül:

```text
03 73 41 01 64
```

A meglévő Xenta értelmező felismeri ezt a formátumot: modell, esemény, akkumulátor-állapot, százalék. Két azonos jelentés szükséges a 100% megjelenítése előtt; a kapcsolódás utáni első jelentés megtévesztő teljes érték lehet a rokon vevőkön. Ez a módosítás megőrzi ezt a védőkorlátot és a meglévő töltési/alvási viselkedést.

A hivatalos [Inphic HUB](https://hub.inphic.cn/) `assets/index-BcHQx9B6.js` csomagja a decimális 115-ös (`73`) modellt az `IN10RMax`-hoz, a 116-ost (`74`) pedig az `IN10Max`-hoz rendeli. Az 1-es akkumulátor-állapotot használja a százalékhoz, a 2-est a teljességhez és a 3-ast a töltéshez. Használd a firmware modellnevét ahelyett, hogy a `73`-at az IN10 MAX-hoz rendelnéd és esetleg félrecímkéznél más, ezen a vevőn osztozó eszközöket.

Ezt a módosítást megelőzően az alkalmazás `Wireless mouse` néven listázta a csatlakoztatott egeret. A Xenta átviteli réteg már kezelte az akkumulátorkereteit; a módosítás a hiányzó modellneveket pótolja. Egy friss `--list` futtatás alvónak mutathatja, mert az ötmásodperces kezdeti megfigyelés csak egy négymásodperces jelentést kaphat el. A háttérben futó alkalmazás megtartja a figyelőt, és egy későbbi lekérdezésnél megerősíti az értéket.

Hardveren igazolva: passzív jelentések, ismételt 100%-os szint és natív illesztőprogramos modellazonosítás. A töltési átmenetek, az alacsony akkumulátorszint-határok, a Bluetooth és a kábeles mód nem lettek ellenőrizve. A `74`-es modell a hivatalos táblázatból származik, és külön hardveren nem volt tesztelve.


---

<a id="sec-machenike"></a>
> 📄 **Szakasz:** Machenike L7 (`docs/machenike.md`) · [Angol eredeti](../../docs/machenike.md) · [↑ Elejére](#top)

# Machenike L7 Arctic / L7 Mix

Ellenőrizve egy L7 Arctic egéren, amely **L7 Mix** néven azonosítja magát:

| Kapcsolat | VID:PID | Interfész | Használat | Bemeneti / kimeneti / max feature |
| --- | --- | --- | --- | --- |
| 2,4 GHz-es vevő | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB-kábel | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

Az illesztőprogram ellenőrzi az `L7 Mix` HID terméknevet is. Más Machenike modellek, eltérő vevőazonosítók és Bluetooth gyártói lekérdezések nincsenek engedélyezve.

## Protokollforrás

A hivatalos **Machenike L7 Mix 1.0.0.8** szoftver interoperabilitási elemzése, amely elérhető a [gyártó illesztőprogram-oldalán](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/), valamint csak olvasható lekérdezések a valódi egéren. A `DeviceDriver.exe` SHA-256 értéke: `A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

Ebben a 32 bites futtatható fájlban (képalap: `00400000`) a `00436750` virtuális című függvény állítja össze az állapotkérést; a `004494F0` küldi el a `HidD_SetFeature` segítségével és olvassa be a feature választ. A `00410C20` állapotértelmező kivonja az alábbi mezőket, és átadja az akkumulátor- és töltésmezőket a felületnek. Ezek virtuális címek, nem fájlbeli eltolások. Itt semmilyen jogvédett futtatható fájl, alkalmazáskód vagy erőforrás nincs mellékelve.

## Állapotolvasási lekérdezés

Küldj **21 bájtot**, `51` jelentésazonosítóval, `06` paranccsal, minden más bájt nulla:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Olvasd be az `51`-es feature jelentést, szintén 21 bájttal. A gyűjtemény maximális feature mérete más jelentésekhez 1001; ez nem az állapotjelentés hossza. Az illesztőprogram 10 ms-ot vár olvasás előtt, és termékenként egyetlen 200 ms-os határidőt használ, beleértve a nem kapcsolódó válaszokat is. Semmilyen beállítást, üzemmódot, makrót vagy firmware-parancsot nem küld.

Az indexek tartalmazzák a jelentésazonosítót:

| Bájtok | Jelentés / megfigyelt értékek |
| --- | --- |
| 0–1 | `51 06`, kötelező parancsvisszhang |
| 4–7 | `8A 24 4E FF`, az igazolt L7 eszközaláírás |
| 10, 0–2. bitek | Működési mód: 1 vevőn, 0 kábelen |
| 10, 3. bit | Vezeték nélküli egér csatlakoztatva; az USB-kábelen is törölt |
| 11 | Akkumulátor-százalék, 0–100 (a nulla érvényes) |
| 12 | Töltésjelző: 0 merül, 1 töltődik |

Egyéb mezők és ellenőrzőösszeg-szemantika nincsenek megállapítva. Az illesztőprogram nem talál ki ellenőrzőösszeget. Mérés közzététele előtt ellenőrzi a parancsot, a hosszt, az eszközaláírást, az üzemmódot és a csatlakoztatott állapotú akkumulátor/töltés tartományokat.

Rögzített vevőválasz, a hivatalos alkalmazásban szintén 64%:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Rögzített USB-kábeles válasz töltés közben (74%):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

Ekkor a vevő még mindig visszaadta a gyorsítótárazott 64%-ot, de törölte a kapcsolatbitjét:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Ez a leválasztott mérés nem fedheti fel a gyorsítótárazott akkumulátor/töltés értékeket. Ha mindkét átviteli út jelen van, a kábel élvez elsőbbséget, és a stabil eszközkulcs közös az átviteli utak között. Egy ismert L7 lekérdezési hiba esetén is lefoglalásra kerül, így a későbbi Ajazz illesztőprogram nem szondázhatja egy másik protokollal a megosztott VID-on.

## Ellenőrzési határok

A tesztadatok és szimulált átviteli tesztek lefedik a rögzített méréseket, a töltést, az érvényes 0%/100%-ot, a leválasztott vevőket, a hibás/elavult válaszokat, a szigorú illesztést, az átviteli hibát, a duplikáció-elnyomást és a korlátos újrapróbálkozási ciklusokat. Az élő 0%/100% és az összes alvási/firmware-változat nem következik ezekből a tesztekből.


---

<a id="sec-nuphy"></a>
> 📄 **Szakasz:** NuPhy WH80 (`docs/nuphy.md`) · [Angol eredeti](../../docs/nuphy.md) · [↑ Elejére](#top)

# NuPhy WH80 (USB-kábel és Bluetooth)

Hardveren tesztelve `19F5:A011` eszközzel, `0116` firmware-kiadással, 1. interfésszel, `0001:0000` használattal, számozatlan 64 bájtos bemeneti/kimeneti hasznos teherrel (65 bájt a Windows HID képességekben).

Protokollforrás: [NuPhyIO](https://drive.nuphy.io/), `main.b3fb29e0.js` csomag, SDK `getBatteryState(0)`, `getDataPackage` és `createCommand`.
Csak a `GetFunc` (`05`), `0020` eltolás, `01` hossz kerül lekérésre. Nincs szükség inicializálásra, konfigurációra, világításra vagy firmware-parancsokra.

Kérés hasznos teher, 64 bájtig nullával kitöltve:

```text
55 05 00 21 01 20 00 00
```

Valódi válasz hasznos teher:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

A 3. bájt a 4..63. bájtok összegének alsó bájtja. Az akkumulátor a 8. bájt: a `value & 7F` a százalék, a `value & 80` az SDK töltésjelzője. A natív C++ illesztőprogram **100%, töltődik** értéket adott vissza a csatlakoztatott billentyűzeten. A töltési átmenetek és az alacsony/teljes határok nem lettek hardveren tesztelve; a hivatalos firmware-megjegyzések a WH80 méréseit 10%-os lépésekben írják le. A vevővel való működés kívül esik ennek az illesztőprogramnak a hatókörén.

## Bluetooth

Bluetoothon ugyanaz a billentyűzet az `19F5:324A` HID-azonosítót használja (`0129` kiadás), és olyan felhasználó által látható nevet hirdet, mint a `NuPhy WH80 - 1`. Két billentyűzet-gyűjteményt és egy egér-gyűjteményt tesz közzé. Az általános HID heurisztika előnyben részesíti az egereket, ezért add hozzá ezt a pontos Bluetooth azonosítót a meglévő billentyűzet-felülbírálásokhoz.

Az akkumulátor-jelentés továbbra is a Windows Bluetooth akkumulátor-tulajdonságát használja. Az USB kihúzása után a Windows **95%**-ot jelentett a csatlakoztatott billentyűzeten. A szabványos GATT Battery Level (`180F` / `2A19`) gyorsítótárazatlan olvasása szintén **95%**-ot adott vissza közvetlenül a billentyűzettől. Ez a vezetékes 100%-os megfigyeléstől független eszköz-/átviteli mérés; ne helyettesítsd feltételezett teljes értékkel és ne skálázd át. Az eltérő firmware-mérések oka nincs megállapítva.

Az illesztőprogram ellenőrzi a pontos termék/interfész/jelentés méreteket, a válaszfejlécet, az eltolást, a hosszt, az ellenőrzőösszeget és a százaléktartományt. 400 ms-os válaszhatáridőt használ, és ugyanazon a határidőn belül figyelmen kívül hagyja a nem kapcsolódó válaszokat.

Regressziós teszt:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Szakasz:** Rapoo (`docs/rapoo.md`) · [Angol eredeti](../../docs/rapoo.md) · [↑ Elejére](#top)

# Rapoo egér akkumulátor-támogatás

## Miért hagyta ki az eredeti program az egeret

A `PollAllDevices()` frissítésenként egyszer felsorolja a Windows HID legfelső szintű gyűjteményeit. Minden gyártói illesztőprogram felismer egy protokollt, hozzáad egy `DeviceStatus` bejegyzést, és lefoglalja a VID/PID-ját, hogy az általános illesztőprogramok ne adják hozzá újra. A felület már kezeli a százalékot, a töltést és az utolsó mérést alvás közben.

Nem volt Rapoo illesztőprogram. A VT3 Max Gen 2 egy gyártó által definiált bemeneti jelentésben küldi az akkumulátorát, nem a szabványos HID Battery Strength használatként vagy Windows Bluetooth akkumulátor-tulajdonságként. A meglévő általános HID/Bluetooth tartalékok ezért nem tudják dekódolni az USB-vevőjét.

## Megfigyelt hardver és csomagok

Tesztelve Windowson a tulajdonos VT3 Max Gen 2 egerével 2026-11-16-án:

| Kapcsolat | VID:PID | Interfész | Használati oldal:használat | Bemeneti / kimeneti méret |
|---|---|---|---|---|
| 2,4 GHz-es vevő | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 bájt |
| USB-kábel | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 bájt |

Mindkettő `Rapoo Gaming Device`-ként azonosítja magát. A többi gyűjtemény szabványos egér-, billentyűzet- és médiabemeneteket, gyártói konfigurációs gyűjteményeket és egy 513 bájtos firmware-interfészt tartalmaz. Az akkumulátor-illesztőprogram csak a felismert bemeneti méretű `FF00:0002` gyűjteményt nyitja meg. Soha nem nyitja meg a firmware-interfészt, és sosem küld kimeneti jelentést, feature jelentést, kézfogást vagy konfigurációs parancsot.

Rögzített vezeték nélküli jelentés, beleértve a jelentésazonosítót:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Rögzített kábeles/töltési jelentés:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Az alábbi eltolások a jelentésazonosítót számolják nulladik bájtnak, összhangban a projekt `HidDev::Read()` függvényével:

| Bájt(ok) | Jelentés | Példa |
|---|---|---|
| 0 | Jelentésazonosító | `07` |
| 1 alsó félbájt | Kapcsolat: 0 vevő, 1 Bluetooth, 2 kábel | `20` / `22` |
| 1 felső félbájt | Szenzoradatok; nem része a kapcsolattípusnak | `2` |
| 2 | Aktuális DPI fokozat | `03` |
| 3–4, 5–6 | X/Y DPI, little endian | `0320` = 800 |
| 7 | Akkumulátor-állapot: 0 érvénytelen, 1 merül, 2 töltődik | `01` / `02` |
| 8 | Akkumulátor-százalék, 0–100 | `19` = 25% |
| 13–14 | Egér termékazonosító, little endian, amikor jelen van | `4617` |

Az élő vevőrögzítés `25%`-ot jelentett, majd a teljes alkalmazás ezt követően `27%, charging` értéket adott vissza a kábelen. Az értelmező tesztje tartalmazza a valódi vezeték nélküli rögzítést. A töltés és a kábeles csatlakoztatás szintén ellenőrizve lett élő hardveren; ezek nincsenek csupán egy USB-eszköz jelenlétéből kikövetkeztetve. Miután a tulajdonos kihúzta a kábelt és visszacsatlakoztatta a vevőt, a végső futtatható fájl `52%`-ot adott vissza `2.4 GHz receiver` kapcsolaton, töltésjelző nélkül, és megtartotta ugyanazt a `rapoo:4617` kulcsot. Ez igazolja a kábelről vevőre való átmenetet is élő hardveren.

Szintén tesztelve Windowson egy **VT9 Gen 2** egérrel 2026-11-17-én:

| Kapcsolat | VID:PID | Interfész | Használati oldal:használat | Bemeneti / kimeneti méret |
|---|---|---|---|---|
| 2,4 GHz-es vevő | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 bájt |
| USB-kábel | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 bájt |

A VT9 Gen 2 vevő 19 bájt helyett **16 bájtos** `FF00:0002` jelentést tesz közzé, pontosan ugyanazzal a Nordic 54L `07` elrendezéssel (beleértve a beágyazott `4614` PID-et a 13–14. bájtokon). Rögzített keretek:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # vevő: 100%, merül
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB-kábel (kapcsoló BE): 100%, töltődik
```

USB-kábelen keresztül az állapotjelentések interakciókor (pl. DPI-váltás) voltak megfigyelhetők; ha az alsó tápkapcsoló KI állásban volt bedugott állapotban, az egér `state=2, percent=1`-et jelentett a valódi akkumulátor-százalék helyett.

### VT3 Max Gen 2 vevő 13 bájtos gyűjteménnyel (#1396-os hibajegy)

Egy ugyanahhoz a `24AE:1417` vevőazonosítóhoz tartozó eszközkérési űrlapjelentés eltérő interfész-elrendezést sorolt fel: `FF00:0002` **13 / 13** bájttal (19 helyett), és `FF00:000E` 33 / 33 bájttal, 513 bájtos firmware-gyűjtemény nélkül. Ez egy másik vevő-firmware verziónak tűnik. A Rapoo szoftver továbbra is mutatta az akkumulátort, így az illesztőprogram figyelmen kívül hagyott egy működő állapotcsatornát.

A Rapoo Hub `VT_nrf54L` dekódere (`py`) hosszhoz alkalmazkodó: mindig kiolvassa a DPI-t, az akkumulátor-állapotot és a százalékot, és a későbbi mezőket (egér PID az `n[12..13]` helyen, RF információk stb.) csak akkor olvassa, ha a jelentés elég hosszú. A VT3 MAX jegyzékfájl (`productId: [17943, 5143]`) nem rendelkezik különleges bemeneti jelentéstípussal, így a `07`-es jelentés ezen a vevőn is átmegy ezen a dekóderen. Egy 13 bájtos jelentés (ID plusz 12 bájt) továbbra is hordozza az állapotot a 7. bájton és a százalékot a 8. bájton; csak a beágyazott egér-PID hiányzik, így a mérés a vevő PID-jét használja és megtartja a `rapoo:4617` kulcsot.

A 13 bájtos hossz **kizárólag a `24AE:1417` esetében** elfogadott. A kereteknek továbbra is át kell menniük ugyanazokon az ellenőrzéseken (`07`-es jelentés, 0–2 kapcsolat-félbájt, 1/2 állapot, 0–100 százalék). Élő 13 bájtos keret még nem lett rögzítve; a tesztek a tesztelt, 13 bájtra vágott 19 bájtos rögzítést használják.

## Egyéb Rapoo egerek

A hivatalos Rapoo Hub ezt a `07`-es elrendezést használja a Nordic 54L egér-illesztőprogramjához. Jegyzékei felsorolják a VT0, VT1, VT2, VT3, VT3S, VT7, VT9 és további változatokat. A jelenlegi csomag vizsgálata 69 VT változatot azonosított, amelyek a `VT_nrf54L`-t használják; ez egy megosztott protokoll bizonyítéka, nem 69 hardveres ellenőrzés vagy ígéret a teljes Rapoo katalógus nagy részének lefedésére. A támogatás a Rapoo VID, a dedikált gyűjtemény, a bemeneti hossz és egy érvényes állapotjelentés alapján választódik ki, így egy ugyanazon a protokollon lévő, fel nem sorolt modell is jelentheti az akkumulátorát. Egy kis névtáblázat lefedi a gyakori modelleket; a többiek megtartják HID terméknevüket vagy a `Rapoo wireless mouse` nevet jelenítik meg.

A terméknevek és azonosítók generációnként és régiónként eltérnek. A tesztelt `1417/4617` pár neve `VT3 MAX` a jelenlegi hivatalos jegyzékben; a tulajdonos VT3 Max Gen 2-ként azonosítja. A jelenlegi jegyzék különálló `VT3 MAX V2` modelljének azonosítói `1B06/4B06`. Azok a közösségi táblázatok, amelyek az `1417`-et a VT9 Próhoz rendelik, nem használhatók kizárólagos alapként ezen eszköz elnevezéséhez vagy észleléséhez.

A régebbi VT firmware, amely a VT3 Prónál (`1215/4415`) dokumentált, ehelyett egy 7 bájtos jelentést küld ugyanezen az `FF00:0002` használaton:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

Ennél a régi formátumnál az 1/2 állapotok jelentése merülés/töltés. A `7F` töltési százalék ismeretlent jelent, és ismeretlenként marad meg. A 0 átmeneti állapot, a nem kapcsolódó `BC` jelentések, a hibás csomagok és a 100 feletti százalékok figyelmen kívül maradnak. A régi támogatás automatizált lefedettséggel rendelkezik, de itt nem lett ellenőrizve fizikai régi egérrel. Ez az értelmezés a `1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) termékazonosítókra és azok 7 bájtos bemeneti gyűjteményére korlátozódik.

A VT1 Pro Max (`24AE:1233` vevő, `24AE:4433` kábel, 222-es egér-firmware, 213-as adapter-firmware) a tulajdonosa által a #136-os hibajegyhez csatolt USBPcap rögzítésekből lett hozzáadva. A `--dump` kimenet felsorolja a 7 bájtos `FF00:0002` gyűjteményt az 1. interfészen, és a rögzítések azt mutatják, hogy a Rapoo alkalmazás kérése nélkül küldi:

```text
BB B0 71 84 03 01 64   vevő, ~3,2 másodpercenként; a Rapoo alkalmazás 100%-ot mutatott
BB B0 71 84 03 02 5F   kábel, töltődik, 95%; a Rapoo alkalmazás „Charging”-et mutatott
```

Kábelen a jelentés egy 16 másodperces rögzítésben csak egyszer volt látható, így egy csak kábeles mérés egyes frissítéseknél időtúllépéssel leállhat; a vevő rendszeresen küldi. A Nordic profil sosem értelmez `BB` csomagokat.

Ez **nem** alapoz meg támogatást minden Rapoo eszközhöz. A CH584 modellek, mint a VT1 SE és VT7 SE, a `08`-as jelentést használják a hivatalos illesztőprogramban, és ez a dekóder nem támogatja őket. Más Telink verziók eltérően értelmezik a `BB` jelzőket, egyes irodai modellek aktív akkumulátor-lekérdezést használnak, és a Bluetooth modellek csak a Windows akkumulátor-tulajdonságát tehetik közzé. Ezek a meglévő tartalékoknál maradnak, vagy külön igazolt implementációt igényelnek. Ne küldj rájuk találgatott lekérdezéseket.

## Lekérdezés és azonosság

- Az olvasás passzív. Az egyező `FF00:0002` leírók nyitva maradnak a lekérdezések között (összhangban a `PollXenta`-val), így a Windows puffereli a 60 másodperces frissítési időköz alatt érkező állapotkereteket; minden lekérdezés kiüríti a sorban álló kereteket (megtartva a legújabb érvényes akkumulátor-mérést), mielőtt első megnyitáskor vagy üres sor esetén 5 másodperces várakozásra térne vissza. A kihúzott eszközök eltávolításra kerülnek és leíróik bezáródnak. A nem kapcsolódó csomagok nem indítják újra a határidőt.
- A beágyazott egér-PID, vagy a régi eszközöknél egy ismert kábel/vevő pár, ugyanazt a felületi kulcsot adja kábelcsere esetén is. A kábeles és vevős mérések egyetlen bejegyzésbe egyesülnek, előnyben részesítve a kábel állapotát, miközben megőrzik az érvényes vevő-százalékot, ha a kábel ismeretlen szintet jelent.
- Az időtúllépés nem talál ki százalékot és nem foglalja le az eszközt. Sikeres olvasás után a meglévő felület halványítva megtarthatja azt a mérést 30 perc csend erejéig.
- A program meglévő VID/PID-alapú azonosságmodellje nem tudja megkülönböztetni ugyanazon modellazonosítóval rendelkező több azonos egeret. A fizikai egyidejű kábel/vevő működés nem lett tesztelve; mindkét bemenet egyesítését a szimulált átviteli teszt fedi le.

## Ellenőrzés

A `make test` lefuttat egy hordozható dekódertesztet és egy Windows illesztőprogram-tesztet szimulált HID-válaszokkal. A lefedettség tartalmazza a valódi rögzítést, a 0%-ot és 100%-ot, a töltést, a hiányzó szinteket, az érvénytelen/csonka kereteket, a nem támogatott gyűjteményeket/gyártókat, a protokoll-profilok elkülönítését, az időtúllépéseket, a stabil kulcsokat és a kábel/vevő duplikációmentesítést ismert százalék eldobása nélkül.

A teljes alkalmazás helyben lett lefordítva MSVC C++17 és Windows SDK segítségével, és a `--list` / `--dump` lefutott a valódi egéren. A karbantartott MinGW build tartalmazza a `rapoo.cpp` fájlt a `build.bat`-ban; a Makefile automatikusan felfedezi. Maga a MinGW nem volt telepítve a tesztkörnyezetben.

## Protokollforrások

- [Hivatalos Rapoo Hub](https://hub.rapoo.cn/), megvizsgálva 2026-11-16-án: csomagolt [JavaScript illesztőprogram és jegyzékfájlok](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js). A releváns dekóderek a `py`/`Hk` a `VT_nrf54L`-hez és a `qM`/`QM` a kapcsolat és az akkumulátor-állapot jelentéseihez. A különálló `VT_CH584` kezelő a `08`-as jelentést fogyasztja, és kívül esik ezen az implementáción. A minifikált nevek jövőbeli kiadásokban változhatnak.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs), a régi VT3 Pro jelentésekhez, töltésállapothoz és az ismeretlen szint jelzőértékéhez.
- #136-os hibajegy USBPcap rögzítései (VT1 Pro Max vevőn és kábelen töltés közben).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js) függetlenül megerősíti a passzív `07`-es állapotadásokat és az akkumulátor-eltolást. Az ő értelmezője levágja az érvénytelen százalékokat; ez az implementáció inkább elutasítja őket.


---

<a id="sec-rawm"></a>
> 📄 **Szakasz:** RAWM (`docs/rawm.md`) · [Angol eredeti](../../docs/rawm.md) · [↑ Elejére](#top)

# RAWM protokoll-megjegyzések

A RAWM egerek (és a platformon osztozó SADES Dagger) egy gyártói HID-gyűjteményen, az `FF00:0001`-en kommunikálnak a RAWM HUB alkalmazással, 64 bájtos számozatlan bemeneti és kimeneti jelentésekkel (65 bájt a jelentésazonosítóval). A vevők és egerek a Nordic `1915` gyártóazonosítóját használják.

Forrás: a RAWM HUB webes alkalmazás, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), és annak szkriptje `https://hub.miracletek.net/hub/js/library.min.js` (obfuszkált; az alábbi függvény- és konstansnevek magának a szkriptnek a nevei). A támogatott termékazonosítók az alkalmazás által letöltött eszköztáblázatból származnak (`https://www.miracletek.net/game/device.php`). A Leviathan V4 GT és NYX60 a Hub Web 3.0-t használják a `373E` VID-on, ami egy eltérő protokoll.

## Csomagok

Minden jelentés 0. bájtja (a jelentésazonosító után):

| Felső bitek | Jelentés |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | az alsó 6 bit a hasznos teher mérete; a hasznos teher folytatja az eseményfolyamot |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | folyamatvezérlés (szabad pufferméretek); itt figyelmen kívül hagyva |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | az alsó 6 bit egy ESB csatorna; a jelentés többi része egy csomag ehhez a csatornához. A vevő mögötti egér a 0. csatorna |

A hasznos terhek események bájtfolyamát alkotják:

```
FF FF FF FF                      szinkron (csak eszköztől a gazdagép felé)
cmd | ((len >> 4) & 0xF0), len   a len tartalmazza ezt a két bájtot (12 bit)
törzs ...
```

## Az akkumulátor olvasása

Az illesztőprogram megismétli azt, amit az alkalmazás tesz, amikor egy vevő csatlakozik (`send_event_query`, `send_event_ping`):

1. A vevőnek: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), majd `00 84 0E 04 00 00` pingek. Az eszköz csak akkor küld, amíg a gazdagép ír, ezért a gazdagép pingel. A vevő `CMD_QUERY_RESULT` (`02`) üzenettel válaszol JSON formátumban, pl. `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. Ugyanez a lekérdezés és pingek a 0. csatornára, `C0` előtaggal. Az egér egy ~550 bájtos JSON objektummal válaszol 30 bájtos ESB darabokban, pl. `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`. A `battery` százalékérték (a RAWM HUB úgy jeleníti meg, ahogy van), a `chr` töltés közben 1.
3. A későbbi változások `CMD_NOTIFY` (`0B`) `17`-es típusként érkeznek: `[17, percent, charging]`.

Az illesztőprogram mindig először a vevőt kérdezi meg, ahogy az alkalmazás is teszi (egy teszt során a csak a 0. csatornára küldött lekérdezés nem kapott választ). Az alvó egér egyáltalán nem válaszol; a vevő továbbra is válaszol.

A lekérdezés hordozza a PC óráját, mert az alkalmazás így küldi el; semmi más nem kerül kiírásra. Az egerek `"crc":1`-et jelentenek, ami azt mondja az alkalmazásnak, hogy a későbbi parancsokat (konfiguráció) CRC-16 keretbe csomagolja; a lekérdezés és a pingek e nélkül is elfogadásra kerülnek, mivel az alkalmazás azelőtt küldi őket, hogy ezt tudná.

Tesztelve egy Leviathan V4 egéren (1.2.0 firmware) a `1915:2346` RAWM HS Receiverrel (2.0.2 firmware).


---

<a id="sec-vaxee"></a>
> 📄 **Szakasz:** VAXEE (`docs/vaxee.md`) · [Angol eredeti](../../docs/vaxee.md) · [↑ Elejére](#top)

# VAXEE 4K/8K vevők és ZYGEN NP-01S V2

## Hatókör és hardveres ellenőrzés

Ez az illesztőprogram támogatja a VAXEE 4K `3057:1002` vevőt, a VAXEE 8K `3057:2002` vevőt és a ZYGEN NP-01S V2 Wireless egeret USB-kábelen (`3057:1011`), az `FF05:0001` gyártói gyűjteményükön 64 bájtos feature jelentéssel. Más VAXEE vevők, más kábeles termékazonosítók és a ZOWIE eszközök szándékosan nincsenek szondázva.

A 8K vevő (`VAXEE 8K Wireless`, egy NP-01 Ergo Wireless 8K-val párosítva) tesztelve lett Windowson, és ugyanezen a protokollon keresztül jelentett:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

A vevő közös az összes VAXEE 8K egér között, és nem jelenti, melyik van párosítva, így saját nevén jelenik meg. A 8K vevőn a töltésállapot még nem volt megfigyelhető hardveren.

Egy valódi 4K vevő tesztelve lett Windowson:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

Az integrált alkalmazás szintén ezt jelentette:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

Ugyanezt az egeret ezután közvetlenül USB-n csatlakoztatták, és a Windows `ZYGEN NP-01S V2 Wireless` (`3057:1011`) néven azonosította. A frissített éles illesztőprogram ezt jelentette:

```
VAXEE battery: 75%; charging: yes
```

A tálca-widget sikeresen létrejött a kezdeti vevő-buildben. Mind az akkumulátoros vevőüzem, mind a vezetékes töltés megfigyelésre került; a teljes töltöttségi átmenetek és az alvási/kikapcsolási viselkedés nem lett tesztelve hardveren. A töltés dekódolását és az érvénytelen válaszokat szimulált válaszok fedik le.

## Protokoll

Forrás: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

A kérés egy nullával kitöltött 64 bájtos HID feature jelentés:

| Bájt | Érték |
|---|---|
| 0 | `0E`, jelentésazonosító |
| 1 | `A5`, fejléc |
| 2 | `0B` akkumulátorszinthez; `10` töltésállapothoz |
| 3 | `01`, olvasási jelző (soha nem `02`, írás) |
| 4 | `01`, adathossz |
| 5–63 | `00` |

A kérés `HidD_SetFeature`-rel történő elküldése után várj 100 ms-ot, majd olvasd be a `0E` jelentést a `HidD_GetFeature`-rel. Legalább hat bájtra, valamint az elvárt jelentésazonosítóra, fejlécre, parancsvisszhangra és adathosszra van szükség.

Akkumulátor esetén az 5. válaszbájtnak 0–20 között kell lennie, és öttel szorzódik, ami 0–100%-ot ad 5%-os lépésekben. Töltés esetén az 5. bájt nem nulla töltés közben. Egy sikertelen töltés-lekérdezés nem dobja el az egyébként érvényes akkumulátormérést.

Az illesztőprogram egyszer újrapróbálja az akkumulátor-kérést. Egyező gyűjteményenként legfeljebb három olvasási kérés van (két akkumulátor-próbálkozás és egy töltés-lekérdezés), összesen 300 ms explicit késleltetéssel. Nem küld beállítási, párosítási, firmware- vagy világítási parancsokat.

Ha nem érkezik érvényes akkumulátorválasz, az illesztőprogram nem jelent semmit, és lefoglalatlanul hagyja az eszközt. Amíg az USB-gyűjtemény jelen marad, a felület halványítva megtart egy korábbi sikeres mérést legfeljebb 30 percig a meglévő türelmi idős viselkedéssel. Ha a fizikai gyűjtemény eltűnik, az illesztőprogram kibocsát egy leválasztott állapotot a türelmi idő azonnali lezárásához. Ez megakadályozza, hogy egy elavult vevőikon ott maradjon, amikor a kábelt átteszik az egérre.

## Tesztek

A `make test` tartalmazza a `tests/vaxee_driver_test.cpp` tesztet, amely az éles illesztőprogramot szimulált HID-átvitelhez kapcsolja. Ellenőrzi a pontos kimenő csak olvasható kéréseket, a százalék-átváltást, a töltés dekódolását, az érvénytelen és hiányzó válaszokat, a már lefoglalt eszközöket és a pontos gyűjteményszűrést.
