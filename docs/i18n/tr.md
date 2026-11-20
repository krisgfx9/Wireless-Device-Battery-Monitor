<!--
  BatteryHub Belgelerinin Tam Çevirisi (Türkçe)
  Kaynak: docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Diller:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | **Türkçe** | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Dil ekle](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Tam Dokümantasyon (Türkçe)

> Bu tek ve bağımsız Markdown dosyası depodaki tüm görünür belgeleri bir araya getirir; böylece çevirmenlerin **dil başına yalnızca bir dosya** sürdürmesi yeterli olur.

## İçindekiler

1. [BatteryHub Genel Bakış, Desteklenen Cihazlar, Kurulum, Komut Satırı ve Derleme (`README.md`)](#sec-readme)
2. [Katkıda Bulunma Kılavuzu (`CONTRIBUTING.md`)](#sec-contributing)
3. [Pull Request Şablonu (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Sürüm Yayınlama ve İmzalama Kılavuzu (`docs/releasing.md`)](#sec-releasing)
5. [Keychron Klavye 2.4 GHz Donanım Yazılımı Yaması (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [GameSir Cyclone Pro BLE Desteği (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Çok Dilli Kullanım ve Yerelleştirme Kılavuzu (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Areson 25A7 Alıcısı (`docs/areson.md`)](#sec-areson)
10. [DARKRIM SHADOW Alıcısı (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Inphic IN10 / KP 8K Alıcısı (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Rapoo Fare Pil Desteği (`docs/rapoo.md`)](#sec-rapoo)
16. [RAWM Protokol Notları (`docs/rawm.md`)](#sec-rawm)
17. [VAXEE 4K/8K Alıcıları (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Bölüm:** BatteryHub Genel Bakış (`README.md`) · [İngilizce orijinal](../../README.md) · [↑ Başa dön](#top)

# BatteryHub

*Eski adıyla **Wireless Battery**. Uygulama 1.1.0 sürümüyle yeniden adlandırıldı; güncelleme yaptığınızda ayarlarınız, başlangıç tercihiniz ve pil geçmişiniz korunur.*

[![Ko-fi üzerinden destekleyin](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![PayPal ile bağış yapın](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Discord sunucumuza katılın](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![GitHub'da yıldız verin](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Reddit'te paylaşın](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Cihaz bildirin](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Çeviriye yardım edin](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Kablosuz farenizin, kulaklığınızın, klavyenizin ve oyun kumandanızın pil düzeyleri doğrudan Windows görev çubuğunda.

![Görev çubuğunda BatteryHub](../screenshot.png)

> **Sadece çalışmasını mı istiyorsunuz?** En son sürümden **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** dosyasını indirin, çalıştırın ve kurulum adımlarını ilerleyin. Hepsi bu kadar.
>
> **Deneyimli kullanıcılar** taşınabilir ZIP arşivini edinebilir, [komut satırı seçeneklerini](#komut-satırı) kullanabilir ya da `make` veya `build.bat` ile [kaynak koddan derleyebilir](#derleme).
>
> **Beğendiniz mi?** BatteryHub ücretsiz ve açık kaynaklıdır. Üretici yazılımlarına girme zahmetinden kurtarıyorsa [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) veya [GitHub Sponsors](https://github.com/sponsors/krisgfx9) üzerinden destek olabilirsiniz. Bu, eğitimim sırasında uygulamalarımı ücretsiz tutmama yardımcı oluyor. Bağış yapamıyor musunuz? Bir ⭐ yıldız vermek, paylaşmak ya da `--dump` çıktısıyla desteklenmeyen bir cihazı bildirmek de aynı ölçüde yardımcı olur.

- **Küçük**: Yaklaşık 2 MB RAM kullanan ~350 KB boyutunda bir uygulama. Saf C++/Win32 ile yazılmıştır; çalışma zamanı kitaplığı veya arka plan hizmeti gerektirmez ve yönetici hakları olmadan saniyeler içinde kurulur.
- **Üretici yazılımına gerek yok**: Cihazlarla doğrudan konuşur. G HUB, Synapse, iCUE, GG ve NGenuity kapalı kalabilir (ya da çalışmaya devam edebilir; çakışma olmaz).
- **Birçok marka**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, PlayStation ve Xbox oyun kumandaları, Samsung Galaxy Buds, Windows'un pil düzeyini bildiği her türlü Bluetooth cihazı ve birlikte gelen [HeadsetControl](https://github.com/Sapd/HeadsetControl) aracının desteklediği tüm kulaklıklar.

## Görünüm

**Görev çubuğunda (varsayılan):** Bildirim alanının yanında Windows simge yazı tipiyle çizilen `🎧 30%  🖱 93%`.
- **Düşük pil:** Kırmızı sayı %15 veya daha düşük anlamına gelir.
- **Şarj oluyor:** Sayının yanında mavi bir ⚡ görünür. Cihaz tam şarj olup hâlâ güç bağlantısında kaldığında yeşil bir ✓ simgesine dönüşür.
- **Uykuda:** Soluk metin cihazın uykuda olduğunu ve bilinen son değerin gösterildiğini belirtir.
- **Bağlantısı kesilen (isteğe bağlı):** Sürücüsü açıkça çevrimdışı bir kablosuz bağlantı bildiren cihazlar için soluk bir `×` göstermek üzere *Bağlantısı kesilen cihazları göster* seçeneğini açın. Bu seçenek kaçırılan bir pil yoklamasından bağlantı kopması çıkarımı yapmaz; varsayılan davranış çevrimdışı cihazları gizlemektir.
- **Aynı türden iki cihaz:** İki fare (veya iki oyun kumandası...) olduğunda ikisi de aynı simgeyi alacağından, her biri kendi simgesinin köşesinde adından alınan en fazla 3 harflik minik bir etiket (`MX`, `PRO`) ya da adlar birbirinden ayırt edilemediğinde bir sayı alır. Türünden tek başına olan cihazlarda etiket gösterilmez.
- **Tema:** Açık/koyu modu ve DPI ölçeklendirmesini takip eder.
- **Saydam görev çubuğu temaları** (ör. Windhawk Taskbar Styler): Duvar kâğıdı üzerinde yazının okunaklı kalması için menüden *Görev çubuğu yazısının arkasına zemin* seçeneğini açın.
- **Birden fazla ekran:** Bileşen, oyunlar tam ekranda çalışırken bile görünür kalması için her ekranın görev çubuğunda saatin yanında gösterilir. Menüdeki *Bileşeni şurada göster* ayarı *Tüm ekranlar*, *Yalnızca ana ekran* veya tek bir ekran (ör. yalnızca *Ekran 3*) seçmenizi sağlar.
- **Daha fazla görünüm seçeneği:** *Simgeler yüzdelerin üstünde* genişlikten tasarruf etmek için her simgeyi pil düzeyinin üstüne yerleştirir; *Marka renkleri* bilinen markaları kendi renginde (Razer yeşili, HyperX kırmızısı, ...) ince bir düzey çubuğuyla gösterir; aynı türden iki cihaz ayırt edilebilmesi için minik bir etiket alır; sol ve sağ görev çubuklarında cihazlar dikey bir sütunda listelenir.
- **Diller:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 ve 繁體中文. Hem Windows hem de Linux uygulaması sistem görüntüleme dilini izler; menüdeki *Dil* seçeneğinden başka bir dil seçilebilir ve Windows yükleyicisi de 19 dilin tümünü destekler. Arayüz metinleri düzenlenebilir statik `lang/*.json` dosyalarında, çevrilmiş tam dokümantasyon ise [`docs/i18n/`](README.md) içinde yer alır. Bir dili düzenlemek veya eklemek için [Çeviriler](#çeviriler) bölümüne bakın.
- **Marka renkleri:** Bilinen 15 markanın cihazları, yüzde değerinin altında yumuşak bir parlama ve ince bir düzey çubuğuyla üreticisinin rengini alır: Razer yeşili, Logitech mavisi, SteelSeries turuncusu, Corsair sarısı, HyperX / ROG / ZOWIE kırmızısı, PlayStation, Xbox, Samsung, Apple, Jabra, JBL, Cooler Master ve Steam. Her rengin koyu ve açık görev çubuğu tonu vardır. Marka; cihazı bulan sürücüden, ardından üretici kimliğinden (VID) ve sonrasında cihaz adından belirlenir; renkler ve kurallar `src/brands.cpp` dosyasındadır. Menüdeki *Marka renkleri* seçeneğiyle kapatabilirsiniz.

**Bildirim alanı simgeleri:** Her cihaz için içinde sayı çizili bir simge ve %15'te "Düşük pil" bildirimi. Görev çubuğu dikey olduğunda veya bulunamadığında uygulama otomatik olarak bu moda geçer.

**Özel cihaz adları:** Cihaz alt menüsünü açıp *Cihazı yeniden adlandır...* seçeneğini belirleyerek bir ad (en fazla 64 karakter) tanımlayabilirsiniz. Bu ad görev çubuğu bileşeninin ipucu/etiketinde, bildirim alanı ipucunda ve bildirimlerinde ve cihaz menüsünde gösterilir. Sürücünün sağladığı adı geri yüklemek için *Özgün ada sıfırla* seçeneğini kullanın. Adlar kararlı cihaz anahtarı kullanılarak yerel olarak geçerli kullanıcının Windows kayıt defterinde (`Software\WirelessBattery`, `DeviceAliases`) saklanır. Yeniden adlandırma hiçbir zaman sürücü eşleşmesini, protokol sorgularını veya `--list` / `--dump` tanılama çıktılarını değiştirmez. Hesap ya da ağ erişimi gerekmez.

Ayrıntılar için üzerine gelin. Menü için tıklayın: her cihaz (gizlemek veya göstermek için tıklayın), görünüm modu, *Şimdi yenile*, *Windows ile başlat* ve *Çıkış*. Düzeyler her 60 saniyede bir (menüdeki *Pil kontrol sıklığı* bunu değiştirir) ve bir cihaz takıldığında ya da bilgisayar uykudan uyandığında hemen yenilenir.

## Akıllı Pil Uyarıları (deneysel)

Her cihazın alt menüsünden **cihaz bazlı düşük pil bildirim eşiği** belirleyebilirsiniz: **Pil uyarıları** → *Varsayılanı kullan (%15)*, *Bildirimleri devre dışı bırak* veya %5, %10, %15, %20, %25, %30, %35, %40 değerlerinden biri. Bir geçersiz kılma seçmediğiniz sürece mevcut %15 varsayılanı değişmeden kalır. Ayarlar cihaz anahtarına göre geçerli kullanıcının Windows kayıt defterinde (`Software\WirelessBattery`, `AlertThresholds`) saklanır.

Bir uyarı yalnızca cihaz bağlı, uyanık ve şarj olmuyor durumdayken alınan gerçek ve güncel bir %0–100 pil ölçümünden tetiklenir. Uyarı bir kez verilir ve pil düzeyi seçilen eşiğin 10 yüzde puanından fazla üzerine çıktığında (veya şarj başladığında) yeniden etkinleşir. Eksik ölçümler veya uyku durumundaki cihazlar uyarıları yeniden tetiklemez. Gizlenen cihazlar bildirim üretmez. Bir cihaz için bildirimleri devre dışı bırakmak cihazı gizlemez veya yüzdesini değiştirmez.

Hem görev çubuğu bileşeni hem de bildirim alanı simgesi modları bildirimleri destekler. Windows klasik bir balon bildirimi gösterebilmek için bildirim alanında bir simgeye ihtiyaç duyduğundan, bileşen modu bir uyarıdan sonra en fazla bir dakika boyunca geçici bir bildirim simgesi gösterebilir. Bileşen renkleri ve düşük pil vurgusu, bildirim ayarından bağımsız olarak projenin özgün genel %15 eşiğini kullanmaya devam eder.

## Pil geçmişi ve içgörüler

Görev çubuğu bileşeninde veya bildirim alanı menüsünde bir cihaza sağ tıklayıp **Pil geçmişi...** seçeneğini seçin. DPI uyumlu yerel görüntüleyici (Windows açık/koyu temasını izler), son **24 saat**, **7 gün** veya **30 gün** boyunca kaydedilen pil düzeylerini birbirine bağlı örnek çizgileriyle birlikte en son ölçümü, en düşük/en yüksek düzeyi, yüzde puanı cinsinden değişimi ve ölçüm sayısını gösterir. Seçili cihazın geçmişini görüntüleyici içinden temizleyebilirsiniz.

Geçmiş, sayısal bir yüzde bildiren bağlı ve uyanık cihazlar için **yalnızca yerel olarak** kaydedilir. Ölçümler cihaz başına en fazla 30 dakikada bir örneklenir (şarj durumu geçişleri hariç; bu durumda en az 60 saniye aralıklıdır). Veriler en fazla 30 gün tutulur ve yerel dosya yaklaşık 2 MB altında tutulur. Uygulama mevcut yoklamasının ötesinde donanım sorgulamaz, ağ üzerinden hiçbir geçmiş verisi göndermez ve yalnızca yakın tarihli deşarj gözlemlerinden ihtiyatlı, yaklaşık bir tükenme süresi tahmini üretir. En az dört nokta, iki saat, üç yüzde puanı düşüş, güncel bir ölçüm ve kararlı bir deşarj dilimi gereklidir. Şarj olma, eski ölçümler veya yetersiz veri tahmini gizler; cihaz tarafından bildirilen çalışma süresi mevcut değildir. Tahmin bir garanti değildir. Eksik grafik verileri enterpolasyon yapılmadan boşluk olarak gösterilir.

Ölçüm kaydetmeyi durdurmak için menüden **Pil geçmişini kaydet** seçeneğini kapatın; önceden kaydedilenler siz görüntüleyicide temizleyene kadar kalır. Dosya `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv` konumunda saklanır. İçindeki cihaz kimlikleri kodlanmıştır (şifrelenmemiştir); dosya Windows hesabınıza özeldir. `--demo` modunda grafik hiçbir zaman kaydedilmeyen sentetik veriler kullanır. **Not:** Geçmiş toplama yalnızca bu özellik kurulduktan ve uygulama bir süre çalıştıktan sonra başlar.

## Desteklenen cihazlar

| Üretici | Cihazlar | Nasıl |
|---|---|---|
| **NuPhy** | USB kablosu (`19F5:A011`) veya Bluetooth (`19F5:324A`) üzerinden WH80, donanımda test edildi | USB: salt okunur NuPhyIO pil sorgusu; Bluetooth: klavye sınıflandırmalı Windows pil düzeyi ([protokol notları](#sec-nuphy)) |
| **DARKRIM** | `3654:6901` USB alıcısı üzerinde SHADOW (寸渊影弑) (donanımda test edildi) | CRC doğrulamalı salt okunur pil sorgusu ve şarj bayrağı; %10 adımlarla kaba ölçümler gözlemlendi, daha ince hassasiyet doğrulanmadı ([protokol notları](#sec-darkrim)) |
| **Inphic** | KP 8K alıcısı üzerinde IN10R MAX / IN10 MAX (`1D57:FA65`; model `73` donanımda test edildi, model `74` test edilmedi) | Pasif Xenta durum raporları; eşleşen iki çerçeve düzeyi onaylar ([protokol notları](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, test edildi), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` test edildi, `002D`/`002A`), A50 Gen 3 (`9886:0015` test edildi, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), USB baz istasyonu üzerinden | Pil yüzdesi, şarj ve istasyona yerleştirme durumu |
| **Logitech** | USB veya Bluetooth üzerinden Unifying, Bolt, Lightspeed (PRO X3 SUPERSTRIKE alıcısı `046D:C54F` dahil) ve Nano alıcılardaki fareler ve klavyeler; G kulaklıklar (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); daha yeni `046D:0ADF` alıcısı üzerinde G435 | Özellik keşifli HID++ 1.0 / 2.0: birleşik pil, pil düzeyi, voltaj, ADC; G435: CRC-16 çerçeveli üretici raporları, mV cinsinden `GET_BATTERY` |
| **Razer** | Kablosuz fareler, klavyeler ve alıcılar; BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X kulaklıklar, Xbox için V3 Pro (`1532:0A55` alıcı, `0A4E` kablo); 2.4 GHz alıcısı (`1532:0550` veya `1532:0552`) üzerinde Barracuda X (2022); Barracuda Pro (`1532:053A`) | Razer özellik raporu protokolü; BlackShark üretici protokolleri (V3 / V3 Pro / V3 X her 5 dk sorgulanır); Barracuda X: alıcı üzerinden Airoha pil ve kablo sorguları |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (`1038:225D` dahil), Arctis Nova Elite (baz istasyonu `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, test edilmedi), Aerox 3 Wireless CS2 Dragon Lore Edition (alıcı `1038:1878`, kablo `187A`), Aerox 3 Wireless Gen 2 (alıcı `1038:1890`, kablo `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Üretici HID raporları; Aerox/Prime ve Rival 650 alıcı ve USB kablosu arasında tek bir girdiyi paylaşır, ikisi de yanıt verdiğinde kablo ölçümünü tercih eder |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 kablosuz; Bragi cihazları (Virtuoso, Void V2, HS80 MAX, yeni Slipstream alıcısı `1B1C:2B00` dahil Slipstream fareler ve klavyeler, ör. Scimitar Elite SE Wireless ve Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, test edilmedi) | Üretici HID raporları, Bragi `GET` (salt okunur), Compx 17 baytlık pil protokolü (salt okunur) |
| **Cooler Master** | MM712, MM731 (2.4 GHz alıcı veya USB kablosu) | Üretici HID durum raporu (salt okunur) |
| **Press Play** | `7768:6434` 2.4 GHz alıcısı üzerinde ICARUS V2 Nearlink (sürücü donanımda %90 düzeyinde test edildi; protokol %100 ve %90'da yakalandı) | `FFB2:0001` üzerinde salt okunur çıkış raporu `06 05`; pil yüzdesi yanıtın 14. baytında |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (PS için `03F0:0C8C`, test edilmedi), Cloud Flight S, Cloud Stinger Core Wireless (DTS `03F0:0A8E` dahil, test edildi), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (2.4 GHz alıcı), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (2.4 GHz alıcı) (2.4 GHz alıcısı `03F0:0F98`, test edildi; `0D97` test edilmedi) | Üretici HID raporları (Haste 2: [protokol notları](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Üretici özellik raporu |
| **Hitscan** | Hyperlight X, Hyperlight N | Üretici özellik raporu (Glorious ile aynı protokol) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, Pulsar ve ATK VXE kablosuz fareler (ör. VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (alıcı 3554:F512) | Sağlama toplamlı yanıtlarla paylaşılan üretici protokolü |
| **Pulsar X2 V3** | 1K alıcı (`3710:5402`) veya USB kablosu (`3710:3402`) üzerinde X2 V3; 8K alıcı (`3710:5403`) veya USB kablosu (`3710:3406`) üzerinde X2 V3 eS | 64 baytlık üretici özellik raporu, pil yazmacı `08 81 01` (salt okunur) |
| **ATK / VXE NK** | NK mouse NANO alıcısı (`373B:1216`) üzerinde VXE R1 NK ve diğer NearLink fareler | `FF05:0001` üzerinde ATK BITMOUSE çıkış raporu 08 (pil ve şarj) |
| **ATK 8K Nano** | ATK 8K Nano Alıcısı (`373B:1178`) üzerinde ATK / VXE fareler | `FF10:0001` üzerinde Holtek GetConfigData (`82`) özellik raporu (ATK HUB'dan; pil ve şarj) |
| **ATK kulaklıklar** | ATK N9 Pro, N9 Ultra (birinci nesil) | Sanal COM bağlantı noktası protokolü (ATK masaüstü uygulaması kapalı olmalıdır) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK ve 8K alıcıları | Modele bağlı olarak Glorious veya Kysona protokolü |
| **Keychron fareler** | 2.4 GHz alıcısı üzerinde M4 ve diğer Keychron fareler; Keychron 4K Link alıcısı (`3434:D038`) üzerinde 4K fareler (M4 4K, M3 4K, M3 mini 4K, M6 4K ...); TurboLink 8K alıcısı üzerinde 8K fareler (M5 8K, G6 HE 8K ...); Ultra-Link 8K alıcısı (`3434:D028`) üzerinde 8K fareler; 1K alıcı (`3434:D030` / `D031`) üzerinde eski fareler (M1, M2, M3, M3 mini, M6, M7 ...); Link-KM alıcısı veya kablosu üzerinde Nape Pro iztopu | Keychron Launcher'dan üretici raporu (1K alıcı: Keychron masaüstü uygulamasının kullandığı özellik raporu 51 06; Ultra-Link 8K: `FFC1` üzerinde B5 03 / B3 06 raporları; Nape Pro: ham HID A7 31) |
| **Keychron klavyeler** | Keychron Link alıcısı (`3434:D030`) veya USB kablosu üzerinde K5 Max (`3434:0A50`, test edildi); aynı yamayla derlendikten sonra diğer Keychron QMK kablosuz klavyeler | `FF60:0061` üzerinde ham HID: `B2` alıcıya hangi klavyenin bağlı olduğunu sorar, `A4` düzey, voltaj ve şarj durumunu döndürür. **Yamalanmış klavye donanım yazılımı gerektirir:** bkz. [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). Stok donanım yazılımı yalnızca Bluetooth üzerinden bildirir |
| **CHERRY** | 2.4 GHz alıcısı (`046A:00EA`, test edildi) veya USB kablosu (`046A:00E3`, test edildi) üzerinde MX 3.0S Wireless klavye | USB ile beslenme durumuyla birlikte `FF1C:0092` üzerinde salt okunur üretici HID sorgusu `1A`. Bluetooth ise Bluetooth desteği kapsamında ele alınır |
| **CHERRY** | 1K alıcı (`046A:0330`, test edildi) üzerinde Cherry XTRFY kablosuz fare | CompX 17 baytlık pil protokolü (`08 03` bağlantı durumu, `08 04` GetPower), Corsair Sabre V2 Pro ile aynı çerçeveleme (salt okunur) |
| **Arbiter Studio** | Akitsu (`373E:000A` 8K alıcı, `373E:0009` kablo), Akitsu 3950 (`373E:0039` 8K alıcı, `373E:0038` kablo), Akitsu Medium (`373E:0067` 8K alıcı ve `373E:0066` kablo, her ikisi de test edildi) | Arbiter Web HUB'dan `FFFF:0000` üzerinde salt okunur üretici özellik raporu `0x83` (pil ve şarj) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (kablo, 1K ve 4K/8K alıcılar) | LAMZU Aurora'dan üretici özellik raporu |
| **Endgame Gear** | 4K alıcı üzerinde OP1w 4k (v1 / v2), XM2w 4k (v1 / v2); kendi özgün alıcısı (`3367:1961`) üzerinde XM2we | Üretici özellik raporu `A1`, pil komutu `B4` (salt okunur) |
| **ATK / VGN / Evision klavyeler** | Paylaşılan 2.4 GHz alıcı (`320F:5088`) veya USB kablosu (`320F:5055`) üzerinde ürün adına göre tanınan ATK V75X ve VGN / VXE klavyeler (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87); `320F:5088` alıcısı "Wireless Gaming Keyboard" olarak adlandırılan klavyeler, ör. Feker Alice80 (test edildi) | Evision çıkış raporu `04`, pil komutu `1A` (ATK HUB ve VGN HUB'dan); alıcı üzerinden en fazla 10 dakikada bir sorulur |
| **Redragon (Evision)** | `320F:226F` 2.4 GHz alıcısı üzerinde K1NG M999 (test edildi); alıcı kimliği diğer modellerle paylaşılıyor olabilir | ATK klavyelerle aynı Evision protokolü (`FF1C:0092` üzerinde rapor `04`, komut `1A`), her yoklamada sorulur; manyetik yuvada şarj durumu gösterilir; USB kablosu takılıyken alıcı eski düzeyi tekrarlamaya devam eder ve şarj durumu göstermez |
| **Audeze** | USB alıcısı (`3329:4B19`) veya USB-C kablosu (`3329:4B1A`) üzerinde Maxwell; USB alıcısı (`3329:4B29`, test edildi) üzerinde Maxwell 2; Xbox kimlikleri test edilmedi | Üretici raporu `06` / giriş raporu `07`, pil özniteliği `0CD6` (tek salt okunur sorgu) |
| **ENDORFY** | 2.4 GHz alıcısı (`3738:0072`, test edilmedi) üzerinde Viro Wireless | Üretici raporu `06` / giriş raporu `07` üzerinde Airoha RACE "pil al" (`0CD6`), Audeze ve Skullcandy alıcılarıyla aynı salt okunur sorgu; şarj durumu yok |
| **Turtle Beach** | USB vericisi (`10F5:2251`, HaloBattery'de test edildi; PC sürümü `10F5:2262`, test edilmedi) veya kulaklığın kendi USB kablosu (`10F5:2253`) üzerinde Stealth 700 Gen 3 | Swarm II'nin yaptığı gibi RACE `0x9942` (CoAP istemcisini etkinleştir) ve RACE `0x9902` içinde tünellenmiş CoAP `GET /GSI`; pil değeri `240` anahtarından alınır (şarj bayrağı yok) |
| **AKG** | USB alıcısı (`0ECB:20D9`, test edildi) üzerinde N9 Hybrid | `FF13:0001` üzerinde Airoha RACE: çıkış raporu `06`, giriş raporu `07`, pil özniteliği `0CD6` (tek salt okunur sorgu) |
| **NZXT** | Alıcısı (`1E71:2101`) veya USB kablosu (`1E71:2129`) üzerinde Lift Elite Wireless | Üretici okuması `4E 02 81 .. B0` (NZXT CAM yakalamalarından) |
| **Poly / Plantronics** | BT600 adaptörü (`047F:02EE` / `02F7`) arkasındaki Voyager 8200 UC ve diğer kulaklıklar | Rapor `07` get/set protokolü, pil öğesi `0A 1A` (salt okunur) |
| **WLMouse** | YING Magnesium (YING 8K alıcısı `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (alıcı veya kablo; Beast X 4K değil); Beast X V2 (8K alıcısı `36A7:A856`); Beast G (8K alıcısı `36A7:A860` veya kablo `36A7:A861`; test edilmedi) | Üretici özellik raporu, durum komutu `0x83` (YING: Glorious ile aynı protokol) |
| **Finalmouse** | 2.4 GHz alıcısı (`361D:0100`, test edildi) üzerinde UltralightX; alıcısı (`361D:0300` / `0301`, test edildi) üzerinde Starlight X. Farenin kendi kablosu üzerinde desteklenmez | `FF00` üzerinde xpanel üretici raporları: salt okunur GET'ler, ardından *wake/all* (`0xE0`); xpanel eğrisi üzerinden pil voltajı veya Starlight X'in kendi yüzdesi ve şarj durumu |
| **VAXEE** | VAXEE 4K alıcısı (`3057:1002`) veya 8K alıcısı (`3057:2002`, ör. NP-01 Ergo Wireless 8K) üzerinde kablosuz fare; USB kablosu (`3057:1011`) üzerinden ZYGEN NP-01S V2 Wireless | `FF05:0001` üzerinde salt okunur üretici özellik raporu `0E`; %5 adımlarla pil ve şarj durumu ([protokol notları](#sec-vaxee)) |
| **Scyrox** | 2.4 GHz alıcısı (`395A:0006`) üzerinde V12M | `FF00:0002` üzerinde S-Center 2.0 profil okuması (çıkış raporu `08`, komut `01`); yalnızca pil, şarj durumu yok |
| **HECATE** | Aynı alıcı üzerinde G5M PRO ve diğer HECATE fareler ile `35BB:D3FA / D3FC / D3FD` USB kablosu | Kysona protokolü |
| **Redragon** | Compx tabanlı kablosuz fareler: M916 Pro 1K (test edildi), M913 Impact Elite (üç modlu), G49 (alıcı veya kablo) | Kysona protokolü (Areson `25A7` alıcıları Areson altında listelenmiştir) |
| **Taidu (钛度)** | Compx 2.4 GHz alıcısı `3554:F5D5` (test edildi) üzerinde TSG808 | Kysona protokolü |
| **Areson (Redragon)** | `25A7:FA07` / `FA08` alıcısı üzerinde M915RGB-WL (test edildi), özgün M913 Impact Elite ve diğer fareler | 17 baytlık `GetPower` özellik raporu; %10 adımlarla düzey ve şarj bayrağı |
| **Ninjutso** | 1K alıcısı (`1915:AE1C`, test edildi) veya USB kablosu (`1915:AE11`, test edildi) üzerinde Sora V2; Ten Air (alıcı `093A:EB01` ve USB kablosu `093A:E020`, test edildi) / Ten (`093A:EB01` / `E020`, test edilmedi) | NinjaForce özellik raporu `0x05` (Sora V2 için `0x15`) ve `0x06` (Ten / Ten Air için `0x13`/`0x12`/`0x11`) |
| **Sprime** | 2.4 GHz alıcısı (`1915:AC1C`, test edildi; `1915:AD8C`) veya USB kablosu üzerinde PM1 | Sprime'ın web sürücüsünden (sprime.pro) aynı özellik raporu 0x05, durum komutu 0x15 |
| **RAWM / SADES** | RAWM HS Receiver (`1915:2346`, test edildi) üzerinde Leviathan V4; RAWM alıcıları (`1915:232A`–`234B`) veya USB kablosu üzerinde ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* ve SADES Dagger fareler | Alıcı üzerinden RAWM HUB 2.0 cihaz bilgisi sorgusu (pil % ve şarj durumu içeren JSON), salt okunur ([protokol notları](#sec-rawm)) |
| **AULA** | 2.4 GHz alıcısı üzerinde F75 / F87 Pro / F99 kablosuz klavyeler | Rapor 0x13 çerçevesi, komut 0x4A, toplam sağlama toplamı (Bluetooth ve kablolu modlar test edilmedi) |
| **AULA fareler** | AULA-8K Alıcısı `320F:22A0` üzerinde X9 Ultra (test edildi); alıcı kimliği V9 modelleriyle paylaşılır | Rapor `04`, `FF1C:0092` üzerinde START `01` / END `02` arasında salt okunur pil komutu `1A`; yalnızca 2.4 GHz |
| **SONiX klavyeler (AJAZZ / AULA / EPOMAKER)** | `05AC:024F` 2.4G alıcısı üzerinde AJAZZ AK820 MAX (test edildi), EPOMAKER EA75 (test edildi), AULA F108 Pro; `0C45:FEFE` alıcısı üzerinde AJAZZ AK980 V2; `0C45:FDFD` veya `0C45:FEFE` alıcısı üzerinde AJAZZ AK820 Pro; `342D:E479` üzerinde EPOMAKER P75 (donanımda test edilmedi) | Kullanım sayfası FF60 üzerinde üretici raporu `20 01`, toplam sağlama toplamı (yalnızca 2.4G modu; şarj göstergesi yok) |
| **Ek SONiX alıcıları (donanımda test edilmedi)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | Aynı yalnızca pillik `20 01` sorgusu; tam VID:PID ve 33 baytlık raporlu FF60:0061 koleksiyonu gerektirir; yalnızca 2.4G, şarj göstergesi yok |
| **36B0 klavyeler (PMO / WOBKEY / URX / EVO80)** | `36B0:3002` 2.4G alıcısı veya `36B0:3009` USB kablosu üzerinde PMO (WOBKEY) Wave 75 RGB (#343 bildirimini yapan kişi tarafından ikisinde de protokol test edildi); aynı alıcı veya kabloda Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) (test edilmedi); alıcı üzerinde URX Core75 (HaloBattery'de doğrulandı); EVO80 (test edilmedi) | PMO Hub donanım yazılımı: pmohub.cn'den kullanım sayfası FF60 üzerinde `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM`. URX / VIA donanım yazılımı: HaloBattery aracılığıyla URX HUB'dan VIA özel okuma `08 00 07` (kanal 0, değer 7). Şarj göstergesi yok |
| **DAREU** | `260D:1074` 2.4 GHz alıcısı veya `260D:1090` USB kablosu üzerinde EM901X (pil okuması ikisinde de test edildi; alıcıda yuvaya koyma/çıkarma şarj bayrağı geçişleri test edildi) | Yalnızca pillik özellik raporu `08`, komut `04`; ayrı bir üretici koleksiyonunda yanıt `09`. Ürün kimliği başına belirsizliği olmayan tek bir giriş/özellik çifti gerektirir. İkisi de bağlıyken geçerli bir USB ölçümünü tercih eder; alıcı fare kapalıyken bile önbelleğe alınmış telemetri döndürebilir |
| **DAREU** | A84 klavye (`260D:0022`, test edilmedi) | Arayüz 0 üzerinde SONiX özellik raporu, komut `04 F6` (resmi A84 sürücüsünün pil okuması); yüzde olarak düzey, şarj bayrağı yok |
| **DAREU** | `260D:1131` çoklu fare alıcısı ve USB kablosu (`260D:1148`) üzerinde A980 Pro (pil düzeyi donanımda test edildi; kablo takılıyken şarj bayrağı doğrulandı) | Togran protokolü: tüketici denetim koleksiyonunda 65 baytlık özellik raporu `0A`; önce yuva sorgusu (sınıf 0 / `A0`), ardından kablo üzerinden yuva 0'da pil sorgusu (sınıf 7 / `80`). Salt okunur |
| **Sharkoon** | `260D:1125` üzerinde Skiller SGM50W (test edilmedi) | DAREU EM901X ile aynı Compx sorgusu (özellik raporu `08`, komut `04`; `FF01:0000` üzerinde yanıt `09`); Sharkoon'un bunun için sağladığı donanım yazılımı güncelleyici VID `260D` üzerinde bir Compx aracıdır |
| **Zenith** | `260D:1114` 2.4 GHz alıcısı (pil okuması test edildi; şarj test edilmedi) veya `260D:1143` USB kablosu (test edilmedi) üzerinde Zenith Pro | `FF02:0002` üzerinde çıkış raporu olarak aynı Compx komutu (`08`, `04`); aynı koleksiyon üzerinde yüzde, şarj bayrağı ve milivolt değerleriyle yanıt `08 04`, `0x55` bayt toplamı ile denetlenir |
| **AJAZZ AK992** | Telink 2.4 GHz alıcısı `320F:50C3` (test edildi) | HID koleksiyonu `FF1C:0092` üzerinde EVision pil sorgusu |
| **ZOWIE** | 2.4 GHz alıcısı üzerinde EC1/EC2/EC3-CW, DW serisi (U2-DW, S2-DW ...) ve U2 | Topluluk tarafından belgelenmiş salt okunur üretici komutları |
| **Royal Kludge (RK)** | 2.4 GHz alıcısı (`2E3C:00A6` / `00E6`) veya USB kablosu (`2E3C:00A5` / `00E5`) üzerinde MG6 Pro | RK web sürücüsünden QiWang 64 baytlık çerçeve, `GET_BATTER_VOL` okuması (yüzde, voltaj, şarj) |
| **ASUS ROG** | Strix Scope II 96 (RX), Azoth, Falchion klavyeler; Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact fareler; Pelta kulaklık (2.4 GHz alıcısı); Cetra Open Wireless kulak içi kulaklık (SpeedNova alıcısı `0B05:1CAC`, Sol / Sağ / kutu); Omni Receiver | ROG HID pil sorgusu |
| **Machenike** | `248A:FF4C` 2.4 GHz alıcısı veya `248A:FF4E` USB kablosu üzerinde L7 Arctic / L7 Mix (ikisi de test edildi) | Salt okunur özellik raporu `51`, durum komutu `06`; pil ve şarj. [Protokol notları](#sec-machenike) |
| **MSI** | 2.4 GHz alıcısı (`0DB0:9E22`) üzerinde VERSA 300 ELITE WIRELESS; CLUTCH GM31 Lightweight Wireless (2.4 GHz alıcısı `0DB0:0D3C`, test edildi; USB kablosu `0DB0:0D3B`) ve CLUTCH GM41 Lightweight Wireless (alıcı `0DB0:0D4C` / kablo `0DB0:0D4B`, bir kullanıcının yakalamalarından) | `FF0D:00B0` ve `FF00:0001` üzerinde salt okunur üretici sorgusu `0F 20`; tek baytta pil ve şarj bayrağı (MSI Center'ın Gaming Gear modülünden protokol); GM41: `FF10:0006` üzerinde pasif `A0 xx 07 …` raporları |
| **MCHOSE** | 2.4 GHz alıcısı veya USB kablosu üzerinde L7 / L7 Pro / L7 Ultra (L7 Ultra test edildi), M7 / M7 Ultra, A7 / A7 Ultra, K7 fareler; A5 V2 Ultra (2.4 GHz alıcısı `3837:100C`, test edildi), K7 Ultra (2.4 GHz alıcısı `3837:1001`, test edildi; A7 V2 Ultra+ `3837:100B` çalışması beklenir, konu 227); G3 V2 (2.4 GHz alıcısı `3837:4245` ve USB kablosu `3837:418C`); `3837:1014` 2.4 GHz alıcısı veya `3837:4028` USB kablosu üzerinde K7 V2 Ultra+ (ikisi de test edildi; yeni aileye ait diğer alıcı kimlikleri `1018`, `1016`, `102C`, `102D` test edilmedi) | Üretici özellik raporu, ters çevrilmiş yük (alexfrih/mchose-linux protokolü); Realtek `3837` alıcıları aynı sorguya `vid` alanı `41E4` (A5 V2 Ultra) veya `3837` (K7 Ultra) olarak ayarlı şekilde yanıt verir; G3 V2: `FF01:0010` üzerinde salt okunur üretici sorgusu; K7 V2 Ultra+: `FF01:0001` üzerinde 64 baytlık rapor `0x4D`, cihaz bilgisi komutu `0x0900` (M HUB web sürücüsünden protokol) |
| **MCHOSE A5 (birinci nesil)** | 1K veya 4K 2.4 GHz alıcısı (`2023:F013`, `2023:F015`, `2023:F018`) veya USB kablosu (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max) üzerinde A5 Pro / A5 Pro Max; burada test edilmedi | `FFFF` üzerinde 64 baytlık özellik raporunda salt okunur pil komutu `0x83` (sayfa 0), `0xA1` işaretli yanıt (protokol z750sasr A5 Pro Max web sürücüsünden ve HaloBattery'den, kimlikler Klegus/mchose-macos'tan) |
| **MCHOSE kulaklıklar** | 2.4 GHz alıcısı (`3837:6011`, test edildi) üzerinde V9 Pro 2 | `FF07:0222` üzerinde M HUB'ın salt okunur "MC" pil çerçevesi (rapor `0x55`, alt komut `0x0B`); tek baytta pil ve şarj bayrağı (M HUB web sürücüsünden protokol) |
| **AULA / MCHOSE / Redragon klavyeler** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 ve diğer M HUB klavyeleri; 2.4 GHz alıcısı (`3554:FA09`, `41E4:2001`) üzerinde Redragon Horus Pro / Pro V2 (K618RGB-PRO); `05AC:024F` alıcısı üzerinde MCHOSE K87 (SONiX olan değil, arayüz 1 üzerindeki BY düzeni) | Rapor 0x13 çerçevesi, komut 0x4A (MCHOSE ve Redragon modelleri M HUB'da olduğu gibi komut 0x05 ile tanınır); Bluetooth ve kablolu modlar kapsanmaz |
| **MCHOSE klavyeler** | `3837:3033` 2.4 GHz alıcısı üzerinde G75 V2 (test edildi); aynı alıcı G87 V2 ve K99 V3 ile gelir (aynı protokol, test edilmedi); K87S aynı alıcı kimliğini farklı bir protokolle eşleştirir ve kapsanmaz | Kimliksiz 64 baytlık `0001:0000` koleksiyonunda M HUB'ın salt okunur "GLW" func-config sorgusu: istek bayrağı `0x55`, komut `0x05`, yük baytı 32'de pil (bit 7 = şarj), toplamsal sağlama toplamı |
| **AULA SC580** | USB kablosu (`088D:062E`, test edildi) veya 2.4 GHz alıcısı (`089D:062F`, test edildi) üzerinde SC580 / SC580X fare | 33 baytlık üretici koleksiyonu FF02:0000 üzerinde salt okunur komut `0x30` (cihaz bilgisi), toplam sağlama toplamı; şarj olurken fare sabit 100 bildirir, bu nedenle son düzey gösterilir; Bluetooth modu kapsanmaz |
| **AULA HERO 68 Air** | 8K Wireless Receiver (`372E:106C`) üzerinde HERO 68 Air | Kullanım sayfası FF60 üzerinde onaylı 20 baytlık çerçeveler (mesaj başına dört veri çerçevesi ve bir sonluk), salt okunur pil komutu 0x87, düzeyin ardından şarj bayrağı 0x10; Bluetooth ve kablolu modlar kapsanmaz |
| **EWEADN (前行者)** | "Gaming 2.4G" alıcısı (`372E:103D`) üzerinde S7 Max / Pro / Ultra ve S9 Max / Pro / Ultra / Ultra+; USB kablosu (`372E:1027`) üzerinde S9 Ultra | `FF00:0001` üzerinde salt okunur özellik raporu `03`: bağlantı denetimi `47`, cihaz temel bilgileri `4F 81` (pil yüzdesi ve şarj biti), EWEADN web sürücüsünden |
| **Rapoo VT** | VT3 Max Gen 2 (test edildi); VT9 Gen 2 (test edildi); aynı durum arayüzünü sunan diğer Nordic 54L VT fareler; eski VT3 Pro (deneysel); VT1 Pro Max (kullanıcının USB yakalamalarından) | `FF00:0002` üzerinde pasif HID durum raporu `07` (16 veya 19 bayt; bazı VT3 Max Gen 2 alıcılarında 13 bayt); eski `BB` biçimi yalnızca VT3 Pro `1215/4415` ve VT1 Pro Max `1233/4433` ile sınırlıdır. Alıcı ve USB kablosu, şarj durumuyla birlikte |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (Xenta modelleri 30/50; eski 3D), Delux M800 Pro, Ajazz AJ179 ailesi; 3151 alıcısı üzerinde AJ159 ve diğer AJ serisi fareler; AJ139 V2 MC (`A8A5:2255` alıcı, `A8A4:2255` kablo) | Üretici raporları (M900 Pro: pasif durum yayınları veya özellik sorgusu, Xenta olayları 40/41; AJ serisi: 0xF7 durum yoklaması, ardından özellik raporu 0x05) |
| **Incott** | G23 V2 / G24 (`093A:522C` alıcı, `093A:622C` kablo) | Salt okunur durum özellik raporu 09 |
| **Attack Shark ve diğer Çinli markalar** | Rongyuan alıcıları (`3151:402D` üzerinde Attack Shark R3 ve AJAZZ AJ179 Pro dahil 81 model, K86, X82 PRO HE, Ajazz klavyeler, bazı MSI ve diğerleri; Bluetooth üzerinden K86 klavye olarak gösterilir); Xenta alıcıları (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; `1D57:FA61` üzerinde X6 da dahil, test edilmedi); Semico 1A2C klavyeler (`1A2C:8FFF` alıcısında Attack Shark X98, test edildi ve `1A2C:A034` kablo; `1A2C:8FFF` / `1A2C:A036` üzerinde AJAZZ AK820 Max Plus) | Rongyuan durum raporu; Xenta pasif yayınları; Semico salt okunur `0x0E` durum sorgusu (`FF02:0002` üzerinde `AA 55 CC 33`; X98 hem pildeyken hem şarj olurken `state=1` bildirdiğinden şarj bayrağı atlanır) |
| **Wraith** | W1 / W1 Freestyle (`093A:522C` alıcı, `093A:622C` kablo; Incott ile aynı kimlikler, model koduyla ayırt edilir) | Tüm düğmeler üzerinde salt okunur düğme başına okuma `86` (özellik raporu 09), ardından gönderilen durum giriş raporu 09 |
| **Fantech** | Helios Go XD5 (kablolu `25A7:FA7B`, alıcı `25A7:FA7C`); yeniden kullanılan `1EA7:0066` / `1EA7:0064` alıcısı üzerinde Raigor III (test edildi), Raigor II WG10 ve diğer genel 2.4G Fare cihazları | Helios Go XD5: üretici özellik raporu `08`, komut `04`, toplamı `0x55` eden sağlama toplamı. Raigor/2.4G Mouse: `FFB5:0001` üzerinde salt okunur `B5` durum sayfası sorgusu, parça `94` = bildirilen son yüzde (uykuda, kapalı veya şarj olurken bayat kalabilir; şarj durumu yok) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, kablosuz adaptör); INZONE H9 II ve H5 kulaklıklar; INZONE Buds (USB-C alıcı) | Giriş raporu; INZONE üretici protokolü |
| **Fractal Design** | 2.4 GHz alıcısı veya USB-C kablosu üzerinde Scape kulaklık | Fractal'ın Adjust Pro web uygulamasından üretici `GET_DEVICE_STATE` sorgusu (kullanım sayfası FF00) |
| **Jabra** | Kendi USB kablosu veya bir Jabra Link alıcısı arkasında GN Protokolünü konuşan tüm Jabra kulaklıklar (Evolve2 / Evolve3 ve diğerleri); ürün kimliği listesi yok, DECT baz istasyonları (Engage, PRO 9xx, GO 6400, Link 400) hariç tutulmuştur; ad kulaklıktan okunur | GNP adresi 08 (USB) veya 04 (alıcı) üzerinde kullanım sayfası FF00, kullanım 05 veya 01'de GNP durum sorgusu (sınıf 12 / op 02) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), 2.4 GHz alıcı veya USB; Apex 5 (`37D7:2501`), 2.4 GHz alıcı veya USB | `FFA0:0001` üzerinde üretici HID bilgi sorgusu; %20 adımlarla %0–100 aralığına eşlenen 0–5 pil düzeyi ve şarj durumu; Space Station hizmeti gerekmez |
| **GameSir** | 2.4 GHz alıcısı üzerinde Nova Lite, Nova 2, Nova 2 Lite; USB üzerinde Nova 2 Lite; Xbox (GIP) modunda G7 Pro (test edildi: Zenless Zone Zero sürümü, alıcı `3537:105E`) ve diğer GameSir kumandaları; Cyclone 2 (XInput modu, alıcı veya kablo); 2.4 GHz alıcısı (`3537:1015`) üzerinde Cyclone Pro (kumandayı Bluetooth ile Windows'a bir kez eşleştirin) | Üretici cihaz bilgisi sorgusu (kullanım sayfası FF7A); Xbox modunda Windows.Gaming.Input pil raporu (gerçek %); Cyclone 2: üretici pil isteği (kullanım sayfası FFF0); Cyclone Pro: Bluetooth LE (hizmet `0x8650`) üzerinden GameSir uygulaması temel bilgi isteği, her 2 dk okunur |
| **BEITONG** | 2.4 GHz alıcısı (`20BC:5128`, XInput modu, test edildi) üzerinde KP20 / BTP-KP20 ve alıcısı (`20BC:515C`, XInput modu) üzerinde KP40D / BTP-KP40D; BEITONG iControl gerekmez | Kullanım sayfası `00FF` üzerinde üretici "temel bilgi al" sorgusu (rapor `02`, yarım bayt karıştırmalı yük), şarj durumuyla birlikte |
| **8BitDo** | Ultimate 2 Wireless (2.4 GHz alıcı üzerinde X-input `2DC8:310B` test edildi, D-input `2DC8:6012` — açarken B tuşunu basılı tutun, donanım yazılımı 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Üretici HID durum sorgusu (`FF7A`/`FFA0`) ve SDL oyun kumandası giriş raporu `01`/`04`, şarj durumuyla birlikte |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Kulaklıkların Samsung'un RFCOMM (SPP) hizmetinde gönderdiği durum çerçevesi, salt okunur. Bildirim alanı daha düşük olan kulaklığı gösterir; ipucu sol, sağ ve kutuyu listeler. Galaxy Buds uygulaması kapalı olmalıdır |
| **Nothing / CMF** | Nothing Ear (3a) (test edildi), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Nothing'in NT Link RFCOMM hizmeti (`aeac4a03-dff5-498f-843a-34487cf133eb`) üzerinde salt okunur `0xC007` pil sorgusu. Bildirim alanı daha düşük olan kulaklığı gösterir; ipucu sol, sağ ve kutuyu listeler |
| **Akko** | Akko Air 01 (`3151:5006`, 2.4 GHz alıcı, test edildi) ve Akko V9 Dash Pro (`38EE:000C`, 2.4 GHz alıcı, test edildi) | Air 01: Rongyuan `0xF7` durum raporu; V9 Dash Pro: şarj durumuyla birlikte `FF1C:0092` üzerinde salt okunur 64 baytlık `0x1A` durum sorgusu |
| **MOONDROP** | 2.4 GHz alıcısı (`35D8:0133`) üzerinde GM01 Pro kulaklık; USB kablosunda son düzeyle birlikte şarj oluyor olarak görünür | Rapor `4B` üzerinde WalkPlay üretici okuma komutu (salt okunur) |
| **VGN** | 2.4 GHz alıcısı (`372E:10BB`, test edildi) üzerinde OMNISOUND (ZHOUTING) kulaklık | V HUB "ZHOU" sorgusu: denetim koleksiyonu `000C:0001` (32 bayt giriş, 64 bayt çıkış raporları) üzerinde `65 01` yüklü çıkış raporu `55`; yüzde değeri yanıtta döner (salt okunur) |
| **JBL** | Quantum 650 Wireless (test edildi, 2.4 GHz alıcısı); Quantum 520, 650X, 850, 950, 950X Wireless (alıcı veya USB kablosu, aynı protokol, test edilmedi) | Pil özelliği için JBL "HIDV3" cihaz bilgisi sorgusu (kullanım sayfası FF12), şarj durumuyla birlikte |
| **JBL** | Quantum 350 Wireless (`0ECB:206B` 2.4 GHz alıcısı ile Windows'ta test edildi); Quantum 610 Wireless (`0ECB:205C` 2.4 GHz alıcısı, Windows'ta test edilmedi); Quantum 360 Wireless (`0ECB:2115` 2.4 GHz alıcısı, test edilmedi) | Kablosuz bağlantı ve pil yüzdesi için HIDV1 özellik raporları |
| **Xbox** | Xbox Wireless adaptörü, USB veya Bluetooth üzerindeki kumandalar; bir kumandaya takılı kulaklıklar | Windows.Gaming.Input pil raporu (gerçek %), XInput geri dönüşü |
| **Switch Pro uyumlu** | `057E:2009` olarak görünen kumandalar (test edildi: Switch modunda 2.4 GHz alıcı üzerinden GameSir Tarantula Pro) | Steam Input veya başka bir ana bilgisayar tam raporları etkinleştirdikten sonra HID raporu `0x30`'dan beş pil düzeyi |
| **Apple AirPods / Beats** | AirPods Max (test edildi, `200A` Lightning ve `201F` USB-C), AirPods Pro 3 (test edildi, `2027`), AirPods Pro 1 / 2, AirPods 1–5 ve Beats kulak üstü/kulak içi kulaklıklar | Eşleştirilen modele göre eşlenen BLE "yakınlık eşleştirme" (`0x07`) yayınları (AirPods Max ve Beats kulak üstü kulaklıklar için tek pil; kulak içi kulaklıklar için şarj durumuyla birlikte %10 adımlarla sol, sağ ve kutu) |
| **Telefonlar (Telefon Bağlantısı)** | Wi-Fi veya Bluetooth üzerinden Microsoft Telefon Bağlantısı ile bağlanan tüm Android telefonlar (test edildi: Nothing Phone (4a) Pro) | Telefon Bağlantısı'nın Windows 11 Başlat menüsü kartından (`StartMenuCompanion.json`) pil ve şarj durumu; Bluetooth gerekmez |
| **Darmoshark** | Windows'ta 2.4 GHz alıcıları üzerinde M3 (`248A:FF30`) ve M3S (`248A:FF31`) | Fare kimliği ve pil için HID özellik raporu |
| **Darmoshark** | Nordic 1K alıcısı (`1915:0723`) üzerinde M3S Pro | `FF0A` koleksiyonu üzerinde üretici HID durum sorgusu |
| **Alienware** | 2.4 GHz alıcısı (`413C:A515`, test edildi) üzerinde AW920H kulaklık; Bluetooth üzerinden Bluetooth satırı kapsamındadır | `FF13:0001` üzerinde üretici sorgusu `06 C0 0A`, XOR sağlama toplamlı yanıt raporu `07`; Alienware Command Center'ın AW920H eklentisi tarafından çözüldüğü biçimiyle düzey, şarj ve kritik düzey alanları |
| **Niceboy** | 2.4 GHz alıcısı (`248A:FA02`, test edildi) üzerinde MW400 | Salt okunur rapor `05` sorgusu `24 FA 48`; üretici uygulamasının tablosuyla %10 adımlara eşlenen pil voltajı, şarj bayrağı |
| **Bluetooth** | *Ayarlar → Bluetooth ve cihazlar* altında pil gösteren her şey (kulak içi kulaklıklar, kulaklıklar, BLE fareler ve klavyeler). Google Fast Pair kulak içi kulaklıklar (Jabra Elite 8 Active test edildi; Pixel Buds ve birçok Sony / JBL / Bose modeli) sol, sağ ve kutu düzeylerini de alır | Windows cihaz özelliği; Bluetooth adresiyle eşleştirilen cihaza göre eşlenen Fast Pair pil yayınları (BLE hizmet verisi `FE2C`) |
| **Genel HID** | Standart HID *Battery Strength* kullanımını bildiren cihazlar | HID kullanım sayfası 0x06 / 0x85 |
| **HeadsetControl** | [Desteklediği tüm kulaklıklar](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, daha yeni Logitech modelleri ve daha fazlası) | Birlikte gelir; `headsetcontrol -o json` çalıştırır |
| **MAONO PD200W** | 2.4 GHz alıcısı (352F:040E) | Pil yüzdesi; donanımda test edildi |


**Gerçek donanımda test edilenler:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (PlayStation alıcısı `0951:1713`; şarj test edilmedi), HyperX Cloud Core Wireless DTS (alıcı `0951:173F`; tam şarj düzeyi test edilmedi), HyperX Pulsefire Haste 2 Core Wireless (alıcı `03F0:0AB5`; Haste 2 Wireless alıcıları test edilmedi), Cooler Master MM712 (alıcı), Rapoo VT3 Max Gen 2 (alıcı `24AE:1417` ve USB kablosu `24AE:4617`; diğer Rapoo modelleri test edilmedi, bkz. [Rapoo protokol notları](#sec-rapoo)), Redragon M916 Pro 1K (alıcı `3554:F55D`), Taidu TSG808 (alıcı `3554:F5D5`), Redragon M915RGB-WL (alıcı `25A7:FA07`; diğer Areson modelleri test edilmedi, bkz. [Areson protokol notları](#sec-areson)), SteelSeries Rival 650 Wireless (alıcı `1038:1726` ve USB kablosu `1038:172B`), SteelSeries Arctis Nova Pro Wireless (baz istasyonu `1038:225D`; pil okuması test edildi, şarj ve güç geçişleri test edilmedi), HECATE G5M PRO (alıcı `35BB:D3FB`), WLMouse YING Magnesium (8K alıcısı `36A7:A874`), ATK N9 Ultra (alıcı `373B:1204`), Corsair Scimitar Elite SE Wireless (Slipstream alıcısı `1B1C:2B00`), Corsair Dark Core RGB Pro SE (Slipstream alıcısı `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (2.4 GHz alıcısı `1B1C:2B2A`; pil okuması doğrulandı), DAREU EM901X (alıcı `260D:1074`; şarj ve uyku/uyanma test edilmedi), Link 390 (`0B0E:2E51`) üzerinde Jabra Evolve3 75, MCHOSE G3 V2 (alıcı `3837:4245` ve USB kablosu `3837:418C`), MCHOSE K7 Ultra (alıcı `3837:1001`), MCHOSE K7 V2 Ultra+ (alıcı `3837:1014` ve USB kablosu `3837:4028`; kablo takılıyken şarj gösterildi), MSI VERSA 300 ELITE WIRELESS (alıcı `0DB0:9E22`; şarj ve uyku yönetimi test edilmedi), MSI Clutch GM31 Lightweight Wireless (alıcı `0DB0:0D3C`; GM41 bir kullanıcının yakalamalarından aynı sürücüyü kullanır), AJAZZ AK820 MAX (alıcı `05AC:024F`), AULA HERO 68 Air (8K Wireless Receiver `372E:106C`), AULA SC580 (USB kablosu `088D:062E` ve alıcı `089D:062F`, şarj ve uyku dahil), AirPods Pro 3 (Bluetooth, model `2027`), AirPods Max (Bluetooth, model `200A`), Sprime PM1 (alıcı `1915:AC1C`), Ninjutso Ten Air (alıcı `093A:EB01` ve USB kablosu `093A:E020`), MOONDROP GM01 Pro (alıcı `35D8:0133`), Delux M800 Pro (alıcı `248A:5B2F`), Razer Barracuda X (2022) (alıcı `1532:0550`; pil düzeyi okundu, şarj geçişleri test edilmedi), Razer BlackShark V3 X (HyperSpeed alıcısı `1532:057D`), Fantech Helios Go XD5 (alıcı `25A7:FA7C`), Fantech Raigor III (alıcı `1EA7:0066`; şarj donanım yazılımı tarafından bildirilmez), Finalmouse UltralightX (alıcı `361D:0100`), Finalmouse Starlight X (kendi alıcısında) ve Chimera V2 (alıcı `3554:F512`; pil düzeyi ve şarj okundu).
Ayrıca donanımda test edilenler: Machenike L7 Arctic / L7 Mix (`248A:FF4C` alıcı ve `248A:FF4E` kablo), şarj ve kablo/alıcı yinelenen girdi bastırması dahil. Bluetooth ve düşük pil/tam şarj sınırları donanımda test edilmedi.
Ayrıca donanımda test edilenler: MCHOSE V9 Pro 2 (`3837:6011` alıcı); pil düzeyi okundu, şarj ve uyku test edilmedi.
Ayrıca donanımda test edilenler: [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60)'taki mevcut SONiX sürücüsünü kullanarak `05AC:024F` 2.4 GHz alıcısı üzerinde EPOMAKER EA75. Pil yüzdesi, alıcı yeniden bağlanması ve güç açılışı kurtarması doğrulandı. Şarj göstergesi ve kablolu pil bildirimi bu sürücü tarafından desteklenmez; Bluetooth pil bildirimi test edilmedi. USB gücü bağlandığında bildirilen yüzde %100'e sıçrayabilir; bu güvenilir bir şarj göstergesi değildir.
Ayrıca donanımda test edilenler: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (alıcı `1038:1878` ve USB kablosu `1038:187A`), şarj etme, kapatma (son düzey soluk şekilde kalır) ve SteelSeries GG çalışırken dahil; GG yalnızca üç adımlı bir çubuk gösterir ve düzey bununla eşleşti.
Ayrıca donanımda test edilenler: RAWM Leviathan V4 (RAWM HS Receiver `1915:2346`; pil düzeyi okundu, şarj test edilmedi).
**Protokol belgelerinden ve diğer projelerden uygulanan, henüz test edilmeyenler:** Fantech Raigor II WG10 (test edilen Raigor III ile aynı `1EA7:0066` alıcısı ve koleksiyonu, dolayısıyla çalışmalıdır) dahil geri kalan tüm cihazlar. Bu cihazlardan birine sahipseniz lütfen [bir issue açarak](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues) çalışıp çalışmadığını bildirin.

## Kurulum

[![Son sürüm](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. [Son sürümden](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest) **`BatteryHub-Setup-<version>.exe`** dosyasını indirin.
2. Çalıştırın, desteklenen 19 kurulum dilinden birini seçin ve ilerleyin. **Yönetici hakları gerektirmez** ve **başka hiçbir ek bileşen kurulmasına gerek yoktur**: çalışma zamanı kitaplıkları, ek sürücüler veya üretici uygulamaları gerekmez. HeadsetControl birlikte gelir ve düzenlenebilir `lang\` klasörü `BatteryHub.exe` yanına kurulur.

Yükleyici bir Başlat menüsü kısayolu ile bir kaldırıcı (*Ayarlar → Uygulamalar*) ekler ve oturum açtığınızda uygulamayı başlatabilir. Yükleyici istemiyor musunuz? `BatteryHub-<version>-portable.zip` dosyasını indirin, istediğiniz bir yere açın (arayüz çevirileri için `lang\` klasörünü `BatteryHub.exe` yanında tutun) ve `BatteryHub.exe` dosyasını çalıştırın.

**Notlar:**
- **SmartScreen uyarısı:** `.exe` dosyası dijital olarak imzalanmadığından Windows "Windows kişisel bilgisayarınızı korudu" uyarısı gösterebilir. *Ek bilgi → Yine de çalıştır* seçeneğine tıklayın veya uygulamayı kendiniz derleyin.
- **Windows 11'de bildirim alanı simgesi modu:** Yeni bildirim alanı simgeleri `^` taşma alanına gider. Bunları görev çubuğuna sürükleyin veya *Ayarlar → Kişiselleştirme → Görev çubuğu → Diğer sistem tepsisi simgeleri* altından etkinleştirin.
- **Uygulamayı bir cihazdan uzak tutma:** Bir cihaz uygulama çalışırken hatalı davranıyorsa, bunu `HKCU\Software\WirelessBattery` altındaki `IgnoreDevices` kayıt defteri dizesine `VID:PID` çiftleri halinde ekleyin (onaltılık, virgülle ayrılmış, ör. `28BD:0947, 1234:ABCD`; `--dump` kimlikleri gösterir). Uygulama bundan sonra o cihazı hiç açmaz. Çizim tabletleri otomatik olarak atlanır.

## Windows güncellemeleri

Resmi kararlı Windows derlemeleri, başlangıçtan 30 saniye sonra ve ardından uygulama çalışırken her 24 saatte bir arka planda projenin yayımlanan en son kararlı sürümünü denetler. **Güncelleme mevcut: vX.Y.Z...** girdisini görmek için menüyü açın veya kendiniz **Güncellemeleri denetle...** seçeneğini seçin. Güncelleme bilgileri yalnızca bu menüde görünür: pil simgeleri, yüzdeler ve ipuçları aynı kalır ve otomatik denetimler hiçbir zaman bildirim ya da iletişim kutusu göstermez. Arka plan denetimlerini devre dışı bırakmak için menüden **Güncellemeleri otomatik olarak denetle** seçeneğini kapatın.

Kurulu bir kopyada güncelleme girdisine ve ardından **İndir ve yükle** düğmesine tıklayın. Bu tıklama olmadan hiçbir şey kurulmaz. Uygulama sürümün `SHA256SUMS.txt` dosyasını ve imzasını indirir, imzayı uygulamanın içine gömülü geliştirici ortak anahtarıyla doğrular, Windows yükleyicisini indirir ve yalnızca SHA-256 değeri imzalı listedekiyle (ve GitHub'ın dosya için listelediğiyle) eşleşirse çalıştırır. Ardından mevcut kurulumu günceller. Ayarlar ve başlangıç tercihi korunur ve kurulumdan sonra uygulama yeniden açılır. Tüm kullanıcılar için yapılan bir kurulum yönetici izni isteyebilir. **Sürüm notları** resmi sürüm sayfasını açar; **Daha sonra** mevcut sürümünüzü korur. Taşınabilir kopyalar ZIP dosyasını elle indirmeniz için sürüm sayfasını sunar.

Denetimler hesap veya belirteç olmadan GitHub'ın herkese açık API'si ile iletişim kurar. Hiçbir cihaz veya pil bilgisi gönderilmez. Çevrimdışı hatalar ve GitHub hız sınırları pil izlemeyi kesintiye uğratmaz; önceden bulunan bir sürüm, başarılı bir denetim onun yerini alana veya kurulana kadar menüde kalır. İndirmeyi iptal etmek, geçerli ağ işleminin sınırlı zaman aşımını tamamlamasını bekler. Yükleyici hiçbir zaman Windows'u otomatik olarak yeniden başlatmaz.

**Güncellemelerin kurulumu neden güvenlidir:** İmzalama anahtarı hiçbir zaman GitHub'a gönderilmez. Bakımcı her sürümün sağlama toplamı listesini kendi bilgisayarında imzalar (bkz. [docs/releasing.md](#sec-releasing)); dolayısıyla GitHub hesabını veya derleme iş akışını ele geçiren biri bile uygulamanın kuracağı bir güncelleme yayımlayamaz. Geçerli bir imzası olmayan bir sürüm menüde gösterilir ancak yalnızca elle indirilebilir. İmza, Windows'un kendi SmartScreen veya UAC istemlerinin yerini almaz.

Bu özelliği içeren ilk sürümü bir kez elle kurun. Geliştirme/test derlemeleri, yerel değişikliklerin yanlışlıkla üzerine yazılmaması için resmi güncelleme denetimlerini devre dışı bırakır. Linux güncellemeleri ve taşınabilir kopyaların otomatik değiştirilmesi ileri bir tarihe ertelenmiştir.

## Komut satırı

```
BatteryHub.exe --list     # her cihazı ve pil düzeyini yazdır, ardından çık
BatteryHub.exe --json     # cihazların ve pil düzeylerinin JSON dizisini yazdır, ardından çık
BatteryHub.exe --dump     # her HID koleksiyonu, açılamayan HID cihazları, tüm USB cihazları (HID arayüzü
                               # olmayanlar da) ve Bluetooth cihazları; ayrıca %TEMP%\BatteryHub-dump.txt içine kaydedilir
BatteryHub.exe --report   # "Bir cihaz için destek iste" penceresini aç
BatteryHub.exe --demo     # gerçek cihazlar yerine her markadan örnek cihazlar göster (ekran görüntüleri, renkleri kontrol etme)
BatteryHub.exe --quit     # çalışan örneği kapat
```

Linux derlemesi `BatteryHub.exe` yerine `wireless-battery` ile aynı bayrakları kullanır ve ayrıca `--help` seçeneğini kabul eder. `--json`, betiklerin ve durum çubuğu bileşenlerinin ayrıştırabileceği kararlı bir dizi yazdırır:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec`, cihaz uykudayken uygulamanın bilinen son düzeyi ne kadar süre göstermeye devam edeceğini belirtir. Yeni alanlar eklemek geriye dönük uyumludur.

**Cihaz görünmüyor mu?** Bileşene veya bildirim alanı simgesine sağ tıklayıp **Bir cihaz için destek iste...** seçeneğini seçin. Cihazı seçin, neyin gönderileceğini kontrol edin (kelimesi kelimesine gösterilir: cihaz adı, türü, USB/HID kimlikleri ve arayüz düzeni ile isteğe bağlı adınız ve notlarınız) ve **Gönder** düğmesine tıklayın. İstek [krisgfx.com/tools](https://krisgfx.com/tools/#requested) adresindeki herkese açık listeye eklenir ve bir GitHub issue'su açar ya da günceller. **Tam raporu kopyala**, issue için tam `--dump` çıktısını panoya kopyalar. Rapor verileri yalnızca Gönder'e tıkladığınızda gönderilir. Resmi Windows derlemeleri ayrıca [Windows güncellemeleri](#windows-güncellemeleri) bölümünde açıklandığı gibi güncellemeleri denetlemek için GitHub ile iletişim kurabilir; güncelleme denetimleri cihaz veya pil bilgisi göndermez.

## Derleme

[MinGW-w64](https://www.mingw-w64.org/) aracına, örneğin [MSYS2](https://www.msys2.org/) üzerinden (`pacman -S mingw-w64-x86_64-gcc make`) ihtiyacınız vardır.

```
make                                      # geliştirme derlemesi, sürüm 0.0.0
build.bat                                 # PATH üzerinde g++ ve windres bulunan düz cmd
make VERSION=1.2.3 CHANNEL=test            # sürümlendirilmiş derleme, resmi güncellemeler devre dışı
build.bat 1.2.3 test                       # eşdeğer sürümlendirilmiş cmd derlemesi
make test VERSION=1.2.3 CHANNEL=test       # cihaz ve güncelleyici regresyon testleri
```

Yükleyiciyi ve taşınabilir ZIP arşivini oluşturmak için [Inno Setup](https://jrsoftware.org/isinfo.php) kurun, önce hedeflenen sürümle derleyin (örneğin `make VERSION=1.2.3 CHANNEL=test`), ardından `powershell -File installer\build-installer.ps1 -Version 1.2.3` komutunu çalıştırın. Paketleme, yürütülebilir dosyadan farklı bir sürümü reddeder. Sabitlenmiş HeadsetControl sürümünü indirir ve sağlama toplamını doğrular. GitHub Actions bunların tümünü otomatik yapar: `v1.0.0` gibi bir etiket göndermek (push), yükleyici, taşınabilir ZIP ve HeadsetControl kaynak kodunu (GPL lisansının gerektirdiği şekilde) içeren bir sürüm yayımlar.

Windows derlemeleri ayrıca paylaşılan yürütülebilir/kaynak sürümünü oluşturmak için PowerShell gerektirir. Resmi deponun sürüm etiketleri `CHANNEL=stable` ile derlenir; yerel derlemeler varsayılan olarak `dev` kullanır. Çatallar (fork) ve pull request'ler resmi güncellemeleri otomatik olarak etkinleştirmez.

`BatteryHub.exe` tek başına da çalışır. Yanında (veya `PATH` içinde) `headsetcontrol.exe` olmadan yalnızca ek kulaklıkları kaybedersiniz.

## Linux (deneysel)

Windows uygulamasının yanında bir Linux derlemesi de yer alır. Aynı üretici sürücülerini `hidraw` tabanlı bir HID arka ucu ve bir GTK4 StatusNotifierItem bildirim alanı simgesiyle kullanır; Windows kod yolu değişmemiştir. Yalnızca Linux'a özel tüm dosyalar `linux/` ve `src/linux/` içindedir ve bunu `build-linux.sh` derler (Windows `build.bat` kullanmayı sürdürür).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Derleyici ve make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

Ek bir HID kitaplığına gerek yoktur (`hidraw` doğrudan kullanılır).

```sh
./build-linux.sh
./build-linux.sh test         # HID rapor tanımlayıcı ayrıştırıcısı için birim testi
./wireless-battery --list     # algılanan düzeyleri yazdır ve çık
./wireless-battery --dump     # HID koleksiyonlarını listele
./wireless-battery --quit     # çalışan bildirim alanı örneğini kapat
```

HID erişimi bir udev kuralı gerektirir; aksi halde uygulama başlar ancak hiç cihaz bulamaz:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# oturumu kapatıp yeniden açın
```

Bildirim alanı simgesi KDE Plasma'da yerel olarak çalışır; GNOME için `gnome-shell-extension-appindicator` gibi bir AppIndicator barındırıcısı gerekir. Çok dilli geçiş *Dil* alt menüsü üzerinden çalışır (varsayılan olarak `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` değişkenlerini izler ve `--help` çıktısını da yerelleştirir). `make -f linux/Makefile.linux install` komutunu çalıştırmak ikili dosyayı, `lang/*.json` dosyalarını `$(PREFIX)/share/wireless-battery/lang/` içine ve masaüstü başlatıcısı (`linux/wireless-battery.desktop`) ile `linux/wireless-battery.svg` dosyasını `$(PREFIX)` (varsayılan: `~/.local`) içine kurar; kullanıcı dil geçersiz kılmaları `~/.config/wireless-battery/lang/` içinde tutulur.

1. aşama Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious, Finalmouse ve paylaşılan Kysona/Pulsar/ATK/G-Wolves protokollerini kapsar. Bluetooth/UPower geri dönüşleri, HeadsetControl ve kalan üreticiler sonraki aşamalar için planlanmıştır.

## Sınırlamalar

- **Kalabalık görev çubukları:** Çok dolu ve ortalanmış bir Windows 11 görev çubuğunda uygulama düğmeleri bileşene kadar uzanabilir. Windows 10'da görev düğmesi alanı otomatik olarak daraltılır.
- **Telefonlar:** Telefon Bağlantısı'nın Başlat menüsü yardımcı kartı için yazdığı bir dosyadan okunur; bu belgelenmiş bir API değildir ve Telefon Bağlantısı güncellemeleriyle değişebilir. Telefon Bağlantısı telefonu bağlı olarak bildirdiği sürece telefon gösterilir; 3 saatten eski bir kart soluk gösterilir. Kart ayrıca telefonun şarj olup olmadığını da bildirir ve bu şarj şimşeği olarak gösterilir.
- **Uyuyan cihazlar:** Uyku durumundaki bir cihaz yanıt vermeyebilir. Son değeri soluk olarak görünür kalır. Logitech alıcıları uyuyan cihazları bağlantıdan düşürür, bu nedenle son değerleri 30 dakika boyunca saklanır.
- **HECATE G2 Wireless 7.1 kulaklık** (2.4 GHz alıcısı `35BB:A009` / `A209`): Alıcısı için henüz bir pil sorgusu belgelenmediğinden okunmaz. HECATE yazılımı kulaklığın pilini gösterirken alınan bir USB yakalaması (bkz. `CONTRIBUTING.md`), bunu eklemenin yoludur.
- **Keychron klavyeler:** Stok donanım yazılımıyla pillerini yalnızca Bluetooth üzerinden bildirirler (Bluetooth desteğiyle gösterilir). 2.4 GHz alıcısı veya kablo üzerinden pil yamasını içeren donanım yazılımı gerekir ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); klavyeyi Keychron Launcher'dan güncellemek bu yamayı kaldırır. Keychron fareler desteklenir.
- **Baseus AeQur GH02 kulaklık:** 2.4 GHz alıcısı (`10D6:4802`, Actions yongası) yalnızca ses, medya tuşları ve yonganın donanım yazılımı güncelleme kanalını taşır; pil bilgisini taşımaz. Düzeyini görmek için kulaklığı Bluetooth üzerinden bağlayın (Windows bildirdiğinde Bluetooth desteğiyle gösterilir).
- **Weikav Lucky65 v1 klavye:** Donanım yazılımı pil bilgisini 2.4 GHz alıcısı (`0603:0351`, Novatek yongası) üzerinden bildirmez. Klavyenin pil kontrol kısayolu yoktur ve resmi yapılandırıcı yalnızca USB kablosu üzerinden bağlanır, alıcı üzerinden bağlanmaz; bu nedenle gösterilecek bir pil ölçümü yoktur.
- **Rapoo:** Desteklenen VT fareler durumlarını kendileri gönderdiğinden (push), bir yenileme eşleşen arayüz başına 4 saniyeye kadar bekleyebilir. Uyuyan fareler son ölçümleriyle 30 dakikaya kadar soluk kalabilir. Destek Nordic 54L raporu `07` ve eski `BB` (VT3 Pro, VT1 Pro Max) içindir; CH584 raporu `08`, ofis MT/M serisi fareler ve diğer donanım yazılımı protokolleri bu sürücü tarafından kapsanmaz.
- **GameSir Cyclone Pro:** Alıcı pil düzeyi taşımadığından pil, kumandadan Bluetooth LE üzerinden okunur. Kumandayı Windows ile bir kez eşleştirin (Ayarlar > Bluetooth ve cihazlar > Cihaz ekle > Bluetooth > `GameSir-Cyclone Pro`) ve alıcı üzerinden oynamaya devam edin. Bilgisayarda Bluetooth gerekir. Düzey 2 dakikada bir yenilenir ve şarj olurken yüzde değeri yoktur. Eşleştirme olmadan alıcı "Dolu" gösteren bir Xbox kumandası olarak görünür. Ayrıntılar [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro) içindedir.
- **RAWM:** Fare alıcısı üzerinden sorgulanır, bu nedenle uyuyan bir fare yanıt vermez; 30 dakikaya kadar son ölçümüyle soluk kalır ve uyurken bir yenilemeye yaklaşık bir saniye ekler. Yalnızca RAWM HS Receiver (`1915:2346`) üzerindeki Leviathan V4 test edilmiştir; diğer modeller RAWM HUB'ın cihaz tablosundan alınmıştır. Leviathan V4 GT ve NYX60 (VID `373E`, RAWM HUB 3.0) ile RAWM HS klavyeler başka protokoller kullanır ve kapsanmaz.
- **Flydigi:** Bu sürücü Vader 5 Pro ve Apex 5'i hedefler; Bluetooth ve diğer Flydigi modelleri (örneğin Apex 6) kapsanmaz. Yüzdeler kaba pil düzeylerini temsil eder. Apex 5 gerçek donanımda 2.4 GHz alıcısı ve USB kablosu üzerinden test edildi; Vader 5 Pro, SDL ve Windows donanım izlerini takip eder.
- **Henüz desteklenmeyenler:** VERSA 300 ELITE ve CLUTCH GM31 / GM41 dışındaki MSI kablosuz fareler, MSI kablosuz klavyeler, Razer Kraken kulaklıklar ve `1532:0550` üzerindeki Barracuda X (2022) dışındaki Barracuda modelleri, Haste 2 Wireless / Haste 2 Core Wireless dışındaki HyperX Pulsefire fareler ve Xbox adaptöründeki Xbox Wireless Headset: pil protokolleri belgelenmemiştir. Xbox Wireless Headset Bluetooth üzerinden çalışır. Bir sahibinden alınan USB yakalaması (bkz. `CONTRIBUTING.md`) bunları eklemenin yoludur.
- **Diğer cihazlar:** Bazı 2.4 GHz cihazlar belgelenmemiş protokoller kullanır ve henüz desteklenmemektedir. Bir cihazın eklenmesine nasıl yardımcı olacağınızı görmek için [CONTRIBUTING.md](#sec-contributing) bölümüne bakın.

## Nasıl çalışır

[`src/drivers/`](../../src/drivers) içindeki her üretici sürücüsü cihazlarını USB üretici ve ürün kimliğiyle (VID/PID) tanır ve yalnızca salt okunur pil sorguları gönderir. Bilinmeyen cihazlara hiçbir zaman yazma yapılmaz. Genel geri dönüşler (HID pil kullanımı, Bluetooth, XInput, HeadsetControl) yalnızca hiçbir üretici sürücüsünün sahiplenmediği cihazlara bakar.

Görev çubuğu bileşeni, `TrayNotifyWnd` soluna yerleştirilen `Shell_TrayWnd` penceresinin katmanlı bir alt penceresidir. Explorer yeniden başlarsa yeniden oluşturulur.

## Çeviriler

Her arayüz dili [`lang/`](../../lang) içinde düz bir statik UTF-8 metin dosyasıdır: solda İngilizce, sağda çeviri yer alır. Dil dosyaları yürütülebilir dosyaya derlenmek yerine çalışma zamanında diskten yüklenir; bu nedenle yeniden derlemeden doğrudan düzenleyebilirsiniz.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **Uygulama Arayüzü (Windows ve Linux):**
  - `.json` dosyalarını doğrudan `BatteryHub.exe` yanındaki `lang/` klasöründe (veya Linux'ta `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/` ya da `./lang/` içinde) düzenleyin veya ekleyin.
  - Ya da `_template.json` ile kullanıcı geçersiz kılma klasörünüzü (Windows'ta `%APPDATA%\WirelessBattery\lang`, Linux'ta `~/.config/wireless-battery/lang`) hazırlamak için menüden *Dil → Kendi dilini ekle...* seçeneğini seçin. `_template.json` dosyasını ör. `it.json` olarak kopyalayın, `@code`, `@name` ve çevirileri doldurun; menüde hemen görünür (yeniden başlatma gerekmez). Kullanıcı klasöründeki dosyalar aynı `@code` ile yerleşik ifadeleri geçersiz kılar.
  - `{placeholders}` yer tutucularını oldukları gibi bırakın ve sağdan sola yazılan alfabeler için `"@rtl": true` ekleyin. Boş bırakılan ifadeler İngilizce kalır, yani kısmi çeviri de sorunsuzdur.
  - `--list` ve `--dump` çıktıları bilerek İngilizce kalır: bunlar GitHub issue'larına yapıştırılır.
- **Windows yükleyicisi:** Inno Setup çevirileri [`installer/lang/`](../../installer/lang) içinde yaşar (UTF-8 with BOM olarak kaydedilir) ve `installer/BatteryHub.iss` içinde `[Languages]` altında kayıtlıdır.
- **Dokümantasyon:** Her görünür proje belgesi [`docs/i18n/`](README.md) içinde dil başına tek bir bağımsız Markdown dosyası olarak çevrilir (hiçbir derleme betiği gerektirmeden yeni bir dil eklemek için [`docs/i18n/_template.md`](_template.md) dosyasına bakın).
- **Herkesle paylaşın:** `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` ve `docs/i18n/` içindeki dosyalarınızı ekleyen bir pull request gönderin. Adım adım kontrol listesi için [`docs/i18n/README.md`](README.md) belgesine bakın.

## Katkı Sağlayanlar ve Kaynaklar

Uygulama simgesi [nik-txt](https://github.com/nik-txt) tarafından yapılmıştır ([`res/app.svg`](../../res/app.svg)).

Protokoller şu projelerin araştırmalarından gelmektedir:

- [Google Fast Pair belirtimi](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): Fast Pair kulak içi kulaklıkların sol / sağ / kutu pil yayınları
- [HeadsetControl Astro sürücüleri](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) ve [AstroBar](https://github.com/nichtlegacy/AstroBar): Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 pil protokolleri; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): A50 Gen 3 `0x72` durum okuması

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): VAXEE pil ve şarj komutları ([protokol dokümantasyonu](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): SteelSeries, Corsair, HyperX, Logitech ve Sony INZONE kulaklıklar
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) ve [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) ve Logitech HID++ 2.0 belgeleri: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) ve [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (`0ADF` alıcısı)
- [rivalcfg](https://github.com/flozz/rivalcfg): SteelSeries fareler (294 numaralı pull request'ten Rival Pro)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) ve [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Hitscan web yapılandırıcısı ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- Linux `hid-kysona` (Lode Willems): Kysona, Pulsar ve ATK
- ATK web yapılandırıcısı ([hub.atk.pro](https://hub.atk.pro)): ATK fareler ve N9 Pro / N9 Ultra kulaklıklar
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 ve [mouse-battery](https://github.com/qwr79/mouse-battery): ATK / VXE NK NANO alıcısı
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X ve Endgame Gear XM2we, sağlayıcılarından uyarlanmıştır (her sürücü kendi kaynağını belirtir)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` ve [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (yalnızca bulgular): Turtle Beach Swarm II cihaz ailesi
- G-Wolves web sürücüsü ([mouse.xyz](https://mouse.xyz)): G-Wolves modelleri ve protokolleri
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): 2.4 GHz alıcısı üzerinde CHERRY klavyeler (çerçeve biçimi ve pil sorgusu)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): Keychron fareler
- [NinjaForce](https://www.ninjaforce.co/) ve [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): Ninjutso Ten / Ten Air özellik sorguları
- [nape_pro](https://github.com/nvalis/nape_pro) ve [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Link-KM alıcısı üzerinde Keychron Nape Pro
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): LAMZU fareler
- [vole](https://github.com/johanneszab/vole) ve [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): Endgame Gear 4K fareler
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) ve [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) ve [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (Finalmouse xpanel'den)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) ve [g49-web-control](https://github.com/pingpingjinping/g49-web-control): Redragon kimlikleri
- [m913-ctl](https://github.com/Qehbr/m913-ctl) ve [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): Areson `25A7` çerçeve düzeni ve `GetPower` komutu
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) ve [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW ve DW
- RK web sürücüsü ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) ve [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (belgeler): MCHOSE A5 Pro / A5 Pro Max (birinci nesil, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): Delux M900 Pro için CompX alıcı raporları
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) ve [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) ve [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- Wraith web sürücüsü ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 ve [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 ve [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) ve [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): `1532:0550` alıcısı üzerinde Razer Barracuda X (2022); [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): `1532:0552` alıcısının çerçevelemesi
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): Rongyuan ve Xenta alıcıları (Attack Shark ve diğerleri)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): 2.4G alıcılarında SONiX klavyeler (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) ve [ak820-studio](https://github.com/usharik/ak820-studio): AJAZZ AK820 Pro alıcısı `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) ve [Kraber](https://github.com/AkashPanja/Kraber): Attack Shark X98 ve AJAZZ AK820 Max Plus için Semico `1A2C` (`AA 55 CC 33` / `0x0E`) durum protokolü
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) ve [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 ve MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) ve [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): GameSir Cyclone Pro Bluetooth LE "base info" pil isteği
- [jabridge](https://github.com/Watchdog0x/jabridge): Jabra GNP protokolü (Link 380 / 390 alıcılar)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): `1EA7:0066` durum sayfası protokolü (Fantech Raigor III ve diğer genel 2.4G Mouse cihazları)
- Linux `hid-playstation`: DualShock 4 / DualSense rapor düzeni
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): AULA SC580 / SC580X üretici protokolü
- RAWM HUB web uygulaması ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) ve cihaz tablosu: RAWM fareler ve SADES Dagger
- [SDL Flydigi HID sürücüsü](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) ve [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): Vader 5 Pro ve Apex 5 sorgu çerçevelemesi ve pil düzeni
- [SDL 8BitDo HID sürücüsü](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): 8BitDo Ultimate 2 pil baytı
- BEITONG iControl (KP20 ve KP40D sayfaları ile KP20 alıcısının USB trafiği): BEITONG KP20 / KP40D pil sorgusu ve yük karıştırması
- [SDL 8BitDo HID sürücüsü](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) ve [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): 8BitDo pil baytı ve üretici HID protokolü
- JBL QuantumENGINE (HIDV3 cihaz bilgisi mesajları): JBL Quantum kulaklıklar
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, `FF02:0002` üzerinde Compx protokolü
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) ve [BrimDeck](https://github.com/MoFeng2223/BrimDeck): Scyrox V12M profil okuması
- JBL QuantumENGINE: Quantum 350 için HIDV1 bağlantı ve pil raporları ve daha yeni Quantum kulaklıklar için HIDV3 cihaz bilgisi mesajları
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): JBL Quantum 610 HIDV1 pil ve bağlantı raporları ve Quantum serisi (HIDV1 alıcılı model olarak 360)

## Lisans

[GNU Genel Kamu Lisansı v3.0 veya sonrası](../../LICENSE). Bu yazılımı kullanabilir, değiştirebilir ve yeniden dağıtabilirsiniz; ancak ona dayalı olarak dağıttığınız her şey, kaynak koduyla birlikte aynı lisans altında yayımlanmalıdır.


---

<a id="sec-contributing"></a>
> 📄 **Bölüm:** Katkıda Bulunma (`CONTRIBUTING.md`) · [İngilizce orijinal](../../CONTRIBUTING.md) · [↑ Başa dön](#top)

# Katkıda Bulunma

## Bir cihazın çalışıp çalışmadığını bildirme

Çoğu sürücü protokol dokümantasyonundan yazılmıştır ve her modelde test edilememiştir. Lütfen şu bilgilerle bir issue açın:

- cihazın adı ve alıcı, kablo ya da Bluetooth üzerinden bağlanıp bağlanmadığı
- `BatteryHub.exe --list` çıktısı
- `BatteryHub.exe --dump` çıktısı
- üreticinin kendi yazılımının pil düzeyi olarak ne gösterdiği

## Cihaz ekleme

1. `BatteryHub.exe --dump` komutunu çalıştırın ve cihazınızın üretici ile ürün kimliklerini (VID/PID) ve rapor boyutlarıyla birlikte üretici tanımlı koleksiyonlarını (kullanım sayfası `FFxx`) bulun.
2. Pil protokolünü bulun. Bakılabilecek iyi yerler: HeadsetControl, OpenRazer, Solaar, rivalcfg, OpenRGB, OpenLinkHub veya üretici yazılımının bir USB yakalaması (Wireshark + USBPcap).
3. Üreticinin `src/drivers/` içinde zaten bir sürücüsü varsa ürün kimliğini (ve farkları) oraya ekleyin. Aksi halde `src/drivers/<vendor>.cpp` dosyasını oluşturun:

   ```cpp
   #include "drivers.h"

   void PollAcme(PollContext& ctx) {
       for (auto [vid, pid] : ctx.Products(0x1234)) {           // bu üreticinin sahiplenilmemiş ürünleri
           for (const HidColl* c : ctx.Find(vid, pid, [](const HidColl& c) { return c.page() == 0xFF00; })) {
               HidDev d;
               if (!d.Open(*c)) continue;
               std::vector<BYTE> r;
               if (!d.Write({ 0x01, 0x02 }) || d.Read(r, 500) < 3) continue;   // hidapi tarzı arabellekler
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

4. İşlevi `src/drivers/drivers.h` içinde bildirin ve `src/devices.cpp` içindeki `PollAllDevices()` fonksiyonundan (genel geri dönüşlerden önce) çağırın. `build.bat` ve Makefile yeni dosyaları otomatik olarak alır.
5. `README.md` içindeki cihaz tablosunu güncelleyin.

### Sürücüler için kurallar

- **Salt okunur:** yalnızca durum okuyan istekler gönderin. Asla ayarları, aydınlatmayı veya modları değiştirmeyin.
- **Kesin eşleştirme:** yalnızca üretici ve ürün kimliğiyle veya protokole özgü benzersiz bir üretici koleksiyonuyla tanıdığınız cihazlarla konuşun.
- **Her zaman zaman aşımı kullanın:** eksik bir cihaz yoklamayı yaklaşık bir saniyeden uzun süre bekletmemelidir. Pasif protokoller belgelenmiş bir gönderim (push) aralığını kapsamak için daha uzun süre gerektirebilir (örneğin Delux ve Rapoo). Eşleşen koleksiyon başına en fazla 4 saniyelik tek bir mutlak son süre kullanın, ilgisiz raporlar için bunu yeniden başlatmayın ve istisnanın neden gerekli olduğunu belgeleyin.
- **Kaynakları belirtin:** dosyanın başındaki bir yorumda protokolün nereden geldiğini kaynak gösterin.

## Çeviriler

Arayüz dilleri, hem Windows hem de Linux'ta çalışma zamanında diskten yüklenen düz statik UTF-8 metin dosyalarıdır (`lang/_template.json` dosyasını `lang/<code>.json` konumuna kopyalayın, `@code`, `@name` ve ifadeleri doldurun — yeniden derleme gerekmez). Koddaki yeni arayüz metinleri `T(L"...")` veya değer içerdiğinde `TF(L"... {name} ...", { { L"name", value } })` üzerinden geçer; çevrilmiş cümleleri asla parçalardan birleştirerek oluşturmayın. İfadeler ekledikten sonra bunları `lang/_template.json` dosyasına da ekleyin.

Windows yükleyicisi çevirileri `installer/lang/*.isl` içinde yer alır (UTF-8 with BOM olarak kaydedilir ve `installer/BatteryHub.iss` içine kaydedilir), Linux başlatıcı açıklamaları `linux/wireless-battery.desktop` içinde yer alır ve tam dokümantasyon çevirileri `docs/i18n/<code>.md` içinde yer alır (`docs/i18n/_template.md` dosyasından kopyalanan tek bağımsız dosya). Eksiksiz katkıda bulunan kılavuzu için [`docs/i18n/README.md`](README.md) belgesine bakın.

## Kod stili

C++17, yalnızca Win32, üçüncü taraf bağımlılık yok. İkili dosyayı küçük tutun. Kabaca mevcut kod gibi biçimlendirin (4 boşluk girinti, 120 sütunluk satırlar).

## Windows güncelleyici geliştirme

Güncelleyici yalnızca Windows içindir ve WinHTTP, BCrypt ve mevcut Inno Setup yükleyicisini kullanır. Güncelleme durumunu yalnızca menüde tutun. Güncelleme simgeleri, rozetler, pil ipucu değişiklikleri, balon bildirimleri, toast bildirimleri veya otomatik iletişim kutuları eklemeyin. Cihaz yoklama ağ işlemlerinden ayrı çalışır.

Derleme sürümü ve kanalı, üretilen `build/version.h` üzerinden C++ ve Windows kaynağı tarafından paylaşılır. Yerel test için `make VERSION=1.2.3 CHANNEL=test` veya `build.bat 1.2.3 test` kullanın; `dev` varsayılandır ve `stable` resmi sürüm denetimlerini etkinleştirir. Sürüm bileşenleri 0..65535 aralığına sığmalıdır. Yalnızca resmi deponun sürüm etiketi iş akışı `stable` kanalını otomatik seçer. Bir çatal (fork) derlemesini yanlışlıkla resmi güncelleme kanalına dönüştürmeyin.

Mevcut cihaz testlerine ek olarak katı sürüm ayrıştırma, sürüm sıralama, denetim zamanlama, gerçek SHA-256 dosya denetimleri, argüman tırnaklama ve yardımcı korumaları için `make test VERSION=1.2.3 CHANNEL=test` çalıştırın. Güncelleyici regresyon testleri ayrıca indirme tamamlandığında iptali, iletişim kutusu korumalarını ve HTTP zaman aşımları/yönlendirme kısıtlamalarının yapılandırılamamasını da kapsar. Windows testi, mevcut Linux arka uç testi kalıbını izleyerek uygulamaları doğrudan dahil eder ve bu testlerin GitHub ile iletişime geçmemesi için HTTP gönderimini değiştirir. Üretime yalnızca test amaçlı hiçbir denetleyici giriş noktası eklenmez. Bireysel hedefler `make test-update-core` ve `make test-update-win` şeklindedir. Yerel güncelleyici testleri Common Controls v6'yı etkinleştirmek için uygulama kaynağını bağlar. Testler yerel veriler kullanır ve indirme yapmaz, yetki yükseltmez, kurulum yapmaz veya kullanıcının başlangıç ayarlarını değiştirmez. Uygulamanın üretim uç noktası testler için geçersiz kılınamaz.

Paketlemeden önce `powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3` komutunu çalıştırın. `installer/build-installer.ps1 -Version 1.2.3` de bağımlılıkları indirmeden önce bu denetimi çalıştırır. `/WBUPDATE=1` yükleyici yolu mevcut başlangıç/ayarları korur ve yeniden başlatmayı geçici yardımcıya bırakır. Bu yardımcı özgün kullanıcı altında kalır ve yalnızca genel bir kurulumda yetki yükseltir. WinHTTP tanıtıcıları çalışan iş parçacığına aittir; iptal sonlu zaman aşımına sahip çağrılar arasında işbirlikçidir. Son uygulama kapanışı bu çalışan iş parçacığına katılır (join) ve bu nedenle devam eden bir ağ zaman aşımını bekleyebilir.

Bir sürüm incelemesi için iki gerçek yükleyici sürümünü, kullanıcı başına/genel kapsamı, UAC iptalini, başlangıcın açık/kapalı durumunu, özel yolları, kurulum hatasını ve yeniden başlatmayı sınamak üzere tek kullanımlık bir Windows hesabı veya sanal makine kullanın. Birim testleri ve bir paketi derlemek bu yükleyici etkilerini doğrulamaz. Görsel menü/tema incelemesi ve gerçek yükleyici/UAC uçtan uca denetimleri el ile yapılan sürüm geçitleri olarak kalır; gerçekten gözlemlenmedikçe bunları geçti olarak işaretlemeyin. Asla günlük kullanıcının kurulumunun üzerine yazarak test etmeyin.

## Otomatik güvenlik denetimi

Her pull request, bu uygulamanın asla yapmaması gereken şeyler (ağ erişimi, program başlatma, klavye/pano/ekran okuma, başlangıç girdileri, ikili dosyalar, derleme veya sürüm değişiklikleri) için "PR safety check" tarafından taranır. Bir uyarı reddedilme değildir: işaretlenen satırları PR açıklamasında açıklamanız yeterlidir.

Yapay zekâ araçlarını kullanmak sorun değildir, ancak lütfen commit mesajlarınızdan onlara atıf yapan `Co-authored-by` satırlarını (örneğin `Co-authored-by: Claude ...`) kaldırın. Bunlar mevcutken denetim başarısız olur.


---

<a id="sec-pr-template"></a>
> 📄 **Bölüm:** Pull Request Şablonu (`.github/pull_request_template.md`) · [İngilizce orijinal](../../.github/pull_request_template.md) · [↑ Başa dön](#top)

## Neler ekliyor

<!-- Cihaz(lar) ve üretici/ürün kimlikleri, ör. "Acme M1 (1234:5678)". -->

## Protokol nereden geliyor

<!-- Kaynağa bağlantı verin (başka bir proje, üreticinin web sürücüsü, kendi USB yakalamanız). -->

## Gerçek donanımda test edildi mi?

<!-- Evet (hangi cihaz, --list çıktısı ne yazdırdığı) / Hayır -->

## Kontrol listesi

- [ ] Yalnızca salt okunur pil sorguları gönderilir; hiçbir ayar, aydınlatma veya donanım yazılımı değiştirilmez
- [ ] Yalnızca üretici/ürün kimliği (veya protokole özgü bir koleksiyon) ile tanınan cihazlara dokunulur
- [ ] Ağ erişimi yok, başka program başlatma yok, `src/`, `docs/` veya `README.md` dışında yeni dosya yok
- [ ] İkili dosyalar veya üretilen dosyalar dahil edilmemiştir
- [ ] Commit mesajlarında yapay zekâ araçlarına (Claude, Copilot, ChatGPT ...) atıf yapan `Co-authored-by` satırı yok
- [ ] `.github/`, `installer/`, `build.bat` veya `Makefile` değişiklikleri yukarıda açıklanmıştır


---

<a id="sec-releasing"></a>
> 📄 **Bölüm:** Sürüm Yayınlama (`docs/releasing.md`) · [İngilizce orijinal](../../docs/releasing.md) · [↑ Başa dön](#top)

# Sürüm Yayınlama

Uygulama kendini GitHub sürümlerinden günceller, ancak yalnızca SHA-256 değeri sürüm anahtarıyla imzalanmış bir `SHA256SUMS.txt` dosyasında listelenen bir kurulumu yükler. Bu anahtar bakımcının bilgisayarında tutulur, asla GitHub'da değil: ele geçirilmiş bir hesap, belirteç veya iş akışı dosya yayımlayabilir, ancak uygulamanın kabul edeceği bir imzayı üretemez.

## Bir kez: sürüm anahtarını oluşturun

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Bir parola (12+ karakter) ister ve şifrelenmiş özel anahtarı `%USERPROFILE%\.wirelessbattery\release-key.wbk` konumuna yazar.
- Ortak anahtarı `src\update_public_key.h` içine koyar. Bu dosyayı commit edin. Resmi derlemeler içinde anahtar olmadan derlenmeyi reddeder.
- **Anahtar dosyasını yedekleyin ve parolayı saklayın** (ikisi için de bir parola yöneticisi iyi bir yerdir). İkisinden biri kaybolursa kurulu uygulamalar artık kendilerini güncelleyemez: yeni bir anahtar oluşturmanız gerekir ve her kullanıcının bir sürümü elle kurması gerekir.

## Her sürümde

1. Bir sürüm etiketi gönderin (`git tag v1.2.3 && git push origin v1.2.3`). CI kurulum dosyasını, taşınabilir ZIP arşivini ve `SHA256SUMS.txt` dosyasını derler ve sürümü yayımlar.
2. Sağlama toplamı listesini imzalayın:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Sürümden `SHA256SUMS.txt` dosyasını indirir, gösterir, onaylamanızı ister, anahtar parolasını sorar ve `SHA256SUMS.txt.sig` dosyasını yazar. `dist\` içinde aynı dosyalara sahipseniz (o sürümün yerel bir derlemesi), eşleşip eşleşmediklerini gösterir.
3. `SHA256SUMS.txt.sig` dosyasını sürüme yükleyin (betik düzenleme sayfasını açar). O andan itibaren uygulama **İndir ve yükle** seçeneğini sunar. Bundan önce güncellemeyi gösterir ancak yalnızca sürüm sayfasına bağlantı verir.

Yalnızca kendinizin yayımladığı bir sürüm için liste imzalayın. İmza "bu dosyaların tam olarak kendisi sürümdür" anlamına gelir; dolayısıyla imzalama kötü niyetli bir yüklemenin yakalanacağı adımdır.

## Anahtarı değiştirme

`new-release-key.ps1` betiğini yeni bir `-KeyFile` ile çalıştırın: yeni ortak anahtarı `src\update_public_key.h` içindeki eski anahtarın yanına ekler. İkisini de içeren ve eski anahtarla imzalanmış bir sürüm yayımlayın, ardından bir sonraki sürümden itibaren yeni anahtarla imzalayın ve eski anahtarı daha sonra kaldırın. Kaybolmuş veya sızdırılmış bir anahtar bu şekilde emekliye ayrılamaz: onu başlık dosyasından kaldırın; eski sürümlerin kullanıcıları bir sonraki sürümü elle kurmak zorunda kalacaktır.

## Uygulama bir kurulumu çalıştırmadan önce neleri denetler

- Sürüm deponun en son sürümüdür, taslak veya ön sürüm değildir ve uygulamadan daha yenidir.
- `SHA256SUMS.txt.sig`, `src\update_public_key.h` içindeki bir anahtar tarafından `SHA256SUMS.txt` için oluşturulmuş geçerli bir ECDSA P-256 imzasıdır (Windows BCrypt, üçüncü taraf kod yok).
- İmzalı liste `BatteryHub-Setup-<version>.exe` dosyasını GitHub'ın dosya için bildirdiği aynı SHA-256 ile tam olarak bir kez adlandırır.
- İndirilen kurulum dosyası tam olarak o boyuta ve SHA-256 değerine sahiptir. Uygulamanın bir kopyası onu başlatmadan hemen önce tekrar kontrol eder ve arada değiştirilememesi için dosyayı kilitli tutar.
- İndirmeler yalnızca `github.com`, `objects.githubusercontent.com` ve `release-assets.githubusercontent.com` adreslerine her yönlendirmesi kontrol edilen HTTPS kullanır.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Bölüm:** Keychron Klavye Donanım Yazılımı (`docs/keychron_keyboard_firmware/README.md`) · [İngilizce orijinal](../../docs/keychron_keyboard_firmware/README.md) · [↑ Başa dön](#top)

# 2.4 GHz alıcı üzerinden Keychron klavye pili

Keychron'un stok donanım yazılımı klavyenin pilini yalnızca Bluetooth üzerinden bildirir. [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch) içindeki küçük QMK değişikliğiyle klavye Keychron Link alıcısı ve USB kablosu üzerinden de bir pil sorgusunu (`A4`) yanıtlar ve BatteryHub düzeyini, voltajını ve şarj durumunu gösterir.

Keychron Link alıcısı (`3434:D030`) ile **Keychron K5 Max ANSI RGB** (`3434:0A50`) üzerinde test edilmiştir.

## Yama neleri değiştirir

[Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) `2025q3` dalını (commit `57e682c`) temel alır:

- [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1)'den `KC_GET_BATTERY` (`0xA4`) ham HID komutunu ekler:
  yanıt `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`;
- kablosuz bağlantı üzerinden gelen ham HID isteklerini aynı işleyiciye geçirir;
- `keyboards/keychron/k5_max/config.h` içinde: `#define WILRESS_RAW_ENABLE` (Keychron'un kodunda bu şekilde yazılmıştır) ve `#define KC_BATTERY_MODEL_ID 0`.

Başka hiçbir şey değişmez: tuş haritaları, aydınlatma ve Keychron Launcher çalışmaya devam eder.

## Seçenek 1: hazır derlenmiş K5 Max donanım yazılımını yükleyin

**Yalnızca K5 Max ANSI RGB** için bir derleme [bu sürüme](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1) eklenmiştir (`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`). Başka bir modele veya tuş düzenine yüklemeyin.

## Seçenek 2: kendiniz derleyin

Git ve Docker (veya çalışan bir [QMK kurulumu](https://docs.qmk.fm/newbs_getting_started)) gerektirir.

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

Sonuç depo kök dizinindeki `keychron_k5_max_ansi_rgb_keychron.bin` dosyasıdır. Windows'ta bind-mount edilmiş bir çalışma kopyası Docker'da çok yavaştır; konteynerin (veya WSL'nin) içinde klonlamak çok daha hızlıdır.

**Diğer Keychron kablosuz klavyeler** (`LK_WIRELESS_ENABLE` ile `2025q3` ağacındaki Q/V/K Max ve diğer modeller): `keyboards/keychron/common/` altındaki değişiklikler olduğu gibi uygulanır. K5 Max dosyası yerine kendi klavyenizin `config.h` dosyasına iki `#define` satırını ekleyin ve kendi hedefinizi derleyin, ör. `make keychron/<model>/<layout>/<variant>:keychron`. Uygulama şu anda bir K5 Max'i (`0A50`–`0A58`) model adıyla, diğerlerini ise "Keychron keyboard" olarak adlandırır.

## Donanım yazılımını yükleme (Flashing)

1. Mod anahtarını **Cable** konumuna getirin ve USB kablosunu çıkarın.
2. Kabloyu takarken **Esc** tuşunu basılı tutun. Klavye STM32 önyükleyicisine girer.
3. `.bin` dosyasını [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (veya `dfu-util`) ile yükleyin.
4. Tekrar **2.4 GHz** konumuna geçin ve `BatteryHub.exe --list` ile kontrol edin:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Klavyeyi Keychron Launcher'dan güncellemek bu donanım yazılımının yerini alır ve pil bildirimini kaldırır. Geri almak için Keychron'un resmi donanım yazılımını aynı şekilde yükleyin.

## Lisans

QMK, GPL-2.0-or-later lisanslıdır; yama da aynı lisans altındadır. Ondan derlenen bir ikili dosyayı alan herkes bu kaynak değişikliğini de alabilmelidir.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Bölüm:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [İngilizce orijinal](../../docs/gamesir_cyclone_pro.md) · [↑ Başa dön](#top)

# GameSir Cyclone Pro pil desteği

## Oyun kumandası neden dolu bir Xbox kumandası olarak görünüyordu

Cyclone Pro (model T4cp), `3537:1015` 2.4 GHz alıcısı üzerinden çalışır. Alıcı kendisini Windows'a kablolu bir Xbox 360 kumandası (XUSB, `Xbox 360 Controller for Windows`) olarak tanıtır. XInput, pil sorgusuna "Full" yanıtı verdiğinden XInput geri dönüşü gerçek şarj ne olursa olsun kumandayı %100 düzeyinde `Xbox controller 1` olarak listeliyordu.

Alıcı hiçbir pil bilgisi taşımaz:
- tek HID koleksiyonu XInput oyun kumandasıdır (`HID\VID_3537&PID_1015&IG_00`)
- Nova (`FF7A`) veya Cyclone 2 (`FFF0`) gibi üretici tanımlı bir koleksiyonu yoktur

## Pil düzeyi nerede

Kumanda alıcı üzerinden çalışırken aynı zamanda Bluetooth LE üzerinden `GameSir-Cyclone Pro` adıyla yayın yapar; bu, GameSir telefon uygulamasının kullandığı bağlantıdır. "get base info" isteği pil bilgisini döndürür:

| Adım | Ayrıntı |
|---|---|
| Hizmet (Service) | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Karakteristik (Characteristic) | `0x865F` (bildirim, yanıtsız yazma) |
| İstek | bildirimleri etkinleştir, `01 01` yaz |
| Yanıt | 19 baytlık bildirim (bazı donanım yazılımları başına `C9` ekler, 20 bayt) |

Yanıt düzeni:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

18. bayt yüzde cinsinden pildir (0-100) veya şarj olurken `FF` olur. Şarj olurken düzey bildirilmez, bu nedenle bilinen son yüzde korunur ve şarj şimşeği ile birlikte gösterilir.

Kumanda ayrıca GameSir'in donanım yazılımı güncelleme kanalı olan `0xFF10` hizmetine de sahiptir. Sürücü bunu asla açmaz. Kumandada standart Pil Hizmeti (`0x180F`) yoktur; Windows'un Bluetooth sayfasının ve Bluetooth geri dönüşünün bunun için bir düzey göstermemesinin nedeni budur.

Kaynak: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery); burada protokol GameSir'in Android uygulamasından (`BluetoothLeService`, "get base info") çıkarılmıştır.

## Sürücü nasıl çalışır

`src/drivers/gamesir_ble.cpp`, XInput geri dönüşünden önce çağrılır:

1. **Kumandayı bulma.** `{00008650-0000-1000-8000-00805F9B34FB}` sınıfındaki cihaz arayüzlerini arar. Windows, eşleştirilmiş bir BLE cihazının her GATT hizmeti için bir tane oluşturur. Yalnızca üst `BTHLE\DEV_…` düğümü `GameSir-Cyclone…` olarak adlandırılanları kullanır.
2. **Pili okuma.** Bu hizmeti Win32 GATT API'si (`bluetoothleapis.h`, `-lbluetoothapis`) ile açar, `0x865F` karakteristiğine abone olur ve `01 01` yazar. Yanıt için en fazla 3 saniye bekler, ardından bildirimleri tekrar kapatır.
3. **Yoklamayı hızlı tutma.** BLE bağlantısı saniyeler sürebilir veya kumanda uykudayken zaman aşımına uğrayabilir, bu nedenle sorgu kendi iş parçacığında çalışır:
   - başarılı bir okumadan sonra en fazla 2 dakikada bir veya başarısız bir okumadan sonra her dakika
   - yoklama önbelleğe alınmış ölçümü bildirir ve 6 dakika eskidiğinde bildirmeyi durdurur
   - `graceSec` ardından bunu uykuda olarak soluk biçimde görünür tutar
   - başlangıçta ve `--list` çıktısında düzeyin görünmesi için yalnızca bir çalıştırmanın ilk yoklaması, bir kez, 4 saniyelik mutlak bir son süreyle iş parçacığını bekler
4. **Sahte Xbox girdisini gizleme.** Alıcı mevcutken sürücü `3537:1015` kimliğini sahiplenir:
   - Windows.Gaming.Input yolu artık sahiplenilmiş üretici/ürün kimliklerini atlar
   - XInput yolu her yuvanın üretici/ürün kimliğini `XInputGetCapabilitiesEx` (xinput1_4 sıra numarası 108) üzerinden alır ve sahiplenilenleri atlar
   - bu dışa aktarma eksik olduğunda XInput eskisi gibi davranır

## Test edilen donanım

Windows 11, kendi alıcısı (`3537:1015`) üzerinde Cyclone Pro, Bluetooth üzerinden bir kez eşleştirilmiş, 2026-11-18 tarihinde:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Kumanda uykudayken "Xbox controller 1 / Full" girdisi artık görünmedi ve kumanda için hiçbir şey gösterilmedi.

## Sınırlamalar

- **Eşleştirme:** Kumanda Windows ile bir kez eşleştirilmelidir (Ayarlar > Bluetooth ve cihazlar > Cihaz ekle > Bluetooth > `GameSir-Cyclone Pro`). Eşleştirilmemiş kumandaların GATT cihaz arayüzü yoktur. Eşleştirme Bluetooth oyun kumandası girdileri ekler, ancak kumanda alıcı üzerinden çalışırken bunlar herhangi bir giriş göndermez.
- **Bluetooth gereklidir:** Bilgisayarda Bluetooth LE bulunmalıdır.
- **Tek kumanda:** Bilgisayar başına yalnızca bir Cyclone Pro okunur.
- **Şarj olma:** Şarj olurken yüzde değeri yoktur.


---

<a id="sec-localization-guide"></a>
> 📄 **Bölüm:** Çok Dilli Kullanım ve Yerelleştirme Kılavuzu (`docs/i18n/README.md`) · [İngilizce orijinal](../../docs/i18n/README.md) · [↑ Başa dön](#top)

# BatteryHub Çok Dilli Dizin ve Yerelleştirme Kılavuzu

Bu depodaki tüm görünür belgeler `docs/i18n/` içinde **dil başına tek bir bağımsız Markdown dosyası** olarak toplanmıştır; tüm çalışma zamanı uygulama dizeleri ise [`lang/`](../../lang) içindeki **statik düzenlenebilir metin dosyalarında** (Windows ve Linux tarafından paylaşılır) ve Windows yükleyicisi dizeleri [`installer/lang/`](../../installer/lang) içinde tutulur.

## Desteklenen Diller (19)

| Kod | Dil | Tam Dokümantasyon | Uygulama Arayüzü (Windows ve Linux) | Windows Yükleyicisi |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (kaynak dizeler) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Dil Değiştirme Uygulamada Nasıl Çalışır

### 1. Windows Uygulaması (`BatteryHub.exe`)
- **Otomatik algılama:** *Dil → Otomatik (Windows dili)* seçili olduğunda BatteryHub, Windows `GetUserPreferredUILanguages` API'sini sorgular ve en yakın statik `*.json` dosyasını eşleştirir.
- **El ile değiştirme:** Görev çubuğu bileşenine veya bildirim alanı simgesine tıklayın → **Dil** → bir dil seçin. Arayüz anında güncellenir ve `HKCU\Software\WirelessBattery\Language` içinde kalıcı olarak saklanır.
- **Statik harici dosyalar (yeniden derlemeden düzenlenebilir):** `BatteryHub.exe` önce `<exe>\lang\*.json`, ardından `%APPDATA%\WirelessBattery\lang\*.json` dosyalarını yükler. Kullanıcı klasöründe aynı `@code` değerine sahip herhangi bir dosya eşleşen ifadeleri geçersiz kılar ve menüyü yeniden açmak dosyaları diskten canlı olarak yeniden yükler.
- **CLI `--help`:** `BatteryHub.exe --help`, yardım iletişim kutusunu etkin arayüz dilinizde gösterir (`--list`, `--json` ve `--dump` GitHub issue raporları için bilerek İngilizce kalır).

### 2. Linux Uygulaması (`wireless-battery`)
- **Otomatik algılama:** POSIX yerel ayar değişkenlerini sırayla izler: `LANGUAGE` (iki nokta üst üste ile ayrılmış liste) → `LC_ALL` → `LC_MESSAGES` → `LANG` (`LC_ALL=C` / `POSIX` ile geçersiz kılınmadıkça).
- **El ile değiştirme:** Bildirim alanı simgesine sağ tıklayın → **Dil** → **Otomatik (sistem dili)** veya kurulu herhangi bir dili seçin. `$XDG_CONFIG_HOME/wireless-battery/config.ini` (varsayılan `~/.config/wireless-battery/config.ini`) içinde `[general] language=` altında kaydedilir.
- **Statik arama yolları (en düşükten en yüksek önceliğe):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (varsayılan `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (varsayılan `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help`, `config.ini` veya sistem yerel ayarına göre çevrilmiş CLI yardımını yazdırır; `--list` ve `--dump` İngilizce kalır.

### 3. Windows Yükleyicisi (`BatteryHub-Setup-<version>.exe`)
- Windows arayüz dilinizden (`LanguageDetectionMethod=uilanguage`) önceden seçilmiş bir dil seçici (`ShowLanguageDialog=yes`) ile başlar.
- `BatteryHub.exe` yanına `{app}\lang\` içine tam statik `lang\*.json` dizinini kurar (ve taşınabilir ZIP de aynı şekilde `lang\*.json` içerir).

---

## Nasıl Dil Eklenir veya Güncellenir (Adım Adım)

Uygulama arayüzünü veya dokümantasyonu çevirmek için hiçbir derleme aracına ihtiyacınız **yoktur**; yalnızca Windows yükleyicisini test derlemek isterseniz Inno Setup 6 gerekir.

### Adım 1 — Uygulama Arayüzü Dizeleri (`lang/<code>.json`)
1. Bildirim alanı menüsünden kullanıcı dil klasörünü açın (**Dil → Kendi dilini ekle...**) veya [`lang/_template.json`](../../lang/_template.json) dosyasını `lang/<code>.json` (ör. `lang/it.json`) olarak kopyalayın.
2. Üst veri başlığını doldurun:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Her satırda ` = ` işaretinden sonraki sağ tarafı çevirin.
   - `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}` gibi yer tutucuları olduğu gibi koruyun.
   - Açık satır sonları için `\n` kullanın.
   - **UTF-8 (BOM olmadan)** olarak kaydedin.
   - Anında önizlemek için BatteryHub bildirim alanı menüsünü yeniden açın — yeniden derleme gerekmez!

### Adım 2 — Windows Yükleyicisi (`installer/lang/<code>.isl`)
1. [`installer/lang/_template.isl`](../../installer/lang/_template.isl) dosyasını `installer/lang/<code>.isl` olarak kopyalayın.
2. **KRİTİK:** Inno Setup'ın eski Windows kod sayfalarından bağımsız olarak Unicode karakterleri güvenilir biçimde çözebilmesi için dosyayı **UTF-8 with BOM (`EF BB BF`)** olarak kaydedin.
3. Uygun kalıbı seçin:
   - **Inno Setup dilinizi zaten içeriyorsa** (`C:\Program Files (x86)\Inno Setup 6\Languages\` konumuna bakın): yalnızca `[CustomMessages]` bölümünü tutun ve 6 satırı çevirin (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, `%1` ve `%n` değerlerini koruyarak). `installer/BatteryHub.iss` içinde `[Languages]` altına kaydedin:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup dilinizi içermiyorsa**: tam bir başvuru olarak `installer/lang/zh-CN.isl` dosyasını kopyalayın, `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, isteğe bağlı `RightToLeft=yes`) ayarlayın, `[Messages]` ve `[CustomMessages]` bölümlerini çevirin ve `Default.isl` sonrasında kaydedin:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Not: `[Languages]` `Name:` tanımlayıcıları yalnızca ASCII harfler, rakamlar ve alt çizgi içermelidir (`pt-BR` değil `ptBR` kullanın).

### Adım 3 — Linux Masaüstü Başlatıcısı (`linux/wireless-battery.desktop`)
Yerelleştirilmiş bir `Comment[<code>]=...` satırı ekleyin (`.desktop` dosyalarında bölgesel etiketler için alt çizgi kullanın, ör. `Comment[zh_CN]=...`).

### Adım 4 — Tek Dosyalık Tam Dokümantasyon (`docs/i18n/<code>.md`)
1. [`docs/i18n/_template.md`](_template.md) dosyasını `docs/i18n/<code>.md` olarak kopyalayın (hiçbir üreteç betiği gerekmez — yalnızca bu tek dosya!).
2. İçindekileri ve tüm 17 bölümü eksiksiz çevirin ve şunları olduğu gibi koruyun:
   - Tüm `<a id="sec-..."></a>` bağlantı çapa etiketleri ve `<a id="top"></a>`
   - Tüm kod blokları, CLI bayrakları (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), USB `VID:PID` değerleri, HID kullanım sayfaları, onaltılık paketler, kayıt defteri anahtarları, dosya yolları ve URL'ler
   - Göreli görsel/dosya yolları (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE` vb.)
3. `docs/i18n/<code>.md` içindeki üst `<!-- lang-switcher:start -->` çubuğunu güncelleyin (kendi dilinizi kalın yapın, diğerlerine bağlantı verin) ve `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` ile kardeş `docs/i18n/*.md` dosyalarındaki değiştirici çubuklarına dil bağlantınızı ekleyin.
4. Sağdan sola diller (`ar`, `fa`, `he`) için tabloların ve kod bloklarının düzgün görüntülenmesi amacıyla tüm dosyayı `<div dir="rtl">` içine sarmadan standart Markdown yazın.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Bölüm:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [İngilizce orijinal](../../docs/ardor_fury_v2.md) · [↑ Başa dön](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

2.4 GHz alıcı `000A` HID kullanım sayfasını, `0000` kullanımını ve 5 baytlık bir giriş raporunu sunar. Veriyi yayınlar; hiçbir HID komutu gönderilmez.

Gerçek donanımdan gözlemlenen raporlar:

| Rapor | Pil |
|---|---|
| `03 00 40 33 07` | %50 |
| `03 00 40 73 08` | %75 |

3. baytın yüksek yarım baytı kademeyi kodlar (yüzde 25, 50, 75 ve 100 için `1`, `3`, `7`, `F`). %25 ve %100 raporları üretici uygulamasının çözme mantığından çıkarılmıştır; son kullanıcı daha sonra kalan düzeylerin derlenen uygulamada doğru görüntülendiğini doğrulamıştır. Beşinci bayt sabit değildir ve imza olarak kullanılmaz.

Dinleyici iki özdeş tam rapor yerine uyuşan iki çözümlenmiş pil kademesi gerektirir. Onaylanan son değer en fazla 45 saniye boyunca tutulur. Genel otomatik yenileme aralığı 15 saniyeye değişir.

Son kullanıcı tarafından Windows'ta ARDOR Fury V2 ve Logitech G733 ile doğrulandı: %50 ve %75 yakalamaları, periyodik otomatik güncelleme, %25/%100 görsel kontrolleri ve taşınabilir başlatma. %25 ve %100 raporları yakalanmadı.


---

<a id="sec-areson"></a>
> 📄 **Bölüm:** Areson `25A7` (`docs/areson.md`) · [İngilizce orijinal](../../docs/areson.md) · [↑ Başa dön](#top)

# Areson 25A7 alıcısı pil desteği

## Özgün program fareyi neden kaçırıyordu

Redragon M915RGB-WL, Areson/CompX `25A7:FA07` "2.4G Wireless Receiver" üzerinden bağlanır. Bağlantı tescilli bir 2.4 GHz bağlantısı olduğu için pili standart bir HID *Battery Strength* kullanımı olarak sunulmaz ve Windows'ta bunun için bir Bluetooth pil özelliği yoktur. Fare bunun yerine etkin bir `GetPower` isteğine yanıt verir; dolayısıyla ne genel HID geri dönüşü ne de Bluetooth geri dönüşü onu görebiliyordu. Üretici için bir sürücü olmadığından alıcı sahiplenilmemiş ve sessiz kalıyordu.

## Gözlemlenen donanım ve paketler

2026-11-17 tarihinde Windows 11 üzerinde bir Redragon M915RGB-WL ile test edildi:

| Yön | VID:PID | Arayüz | Kullanım sayfası:kullanım | Rapor boyutu |
|---|---|---|---|---|
| istek (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 bayt |
| yanıt (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 bayt |

Yanıt, isteğin yazıldığı üst düzey koleksiyondan farklı bir koleksiyona gelir. Windows'ta bunlar `MI_01&COL07` (feature) ve `MI_01&COL05` (input) şeklindedir; sürücünün her iki tanıtıcıyı da açmasının nedeni budur.

Yakalanan istek (`GetPower`, rapor kimliği `08`, komut `04`, sağlama toplamı çerçevenin toplamını `0x55` yapar):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Yakalanan yanıt:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Aşağıdaki konumlar rapor kimliğini sıfırıncı bayt olarak sayar:

| Bayt(lar) | Anlam | Örnek |
|---|---|---|
| 0 | Yanıt rapor kimliği | `09` |
| 1 | Komut yankısı | `04` |
| 2 | Durum, 0 = Tamam | `00` |
| 3–4 | Adres, `GetPower` için kullanılmaz | `00 00` |
| 5 | Veri uzunluğu (2) | `02` |
| 6 | Pil düzeyi, 0–10, %10 adımlarla | `08` = %80 |
| 7 | Şarj bayrağı, sıfır olmayan herhangi bir değer | `00` = şarj olmuyor |
| 16 | Sağlama toplamı; tüm 17 baytın toplamı `0x55` (mod 256) | `3E` |

Üreticinin kendi yazılımı aynı çerçeve için %80 gösterdi; ×10 ölçeğini doğrulayan da budur. `GetConnectStatus` (`08 03 …`) 1 baytlık bir yükle yanıt verir ve aynı anda farenin bağlı olduğunu bildirir.

## Diğer Areson fareler

Redragon M693 tarafından kullanılan daha eski `FA7B` / `FA7C` alıcıları şarjı aynı yanıt konumunda doğrudan tam yüzde olarak bildirir. Bu sürücünün ×10 ölçeğini orada uygulamak %800 göstereceğinden bu ürün kimlikleri bilerek sahiplenilmez. Yalnızca `FA07` ve `FA08` işlenir; `FA08` aynı ailenin alternatif kimliğidir ve bu makinede doğrulanmamıştır.

## Yoklama ve kimlik

- Sürücü yalnızca salt okunur `GetPower` isteğini gönderir. Asla yapılandırma, aydınlatma veya DPI verisi yazmaz.
- Her yenileme özellik koleksiyonunu sıfır erişimle ve giriş koleksiyonunu okuma için açar, isteği gönderir ve bayat bir raporun yanıtla karıştırılmaması için aralarında bir kuyruk boşaltma ile iki denemede yanıt için en fazla 1.8 sn bekler.
- Başarısız bir okuma hiçbir şeyi sahiplenmez, böylece uyuyan bir fare arayüzdeki son değeri korur. Girdi diğer pasif sürücülerle uyumlu olarak 30 dakikalık bir yetkisiz bırakma (grace) süresi kullanır.
- Cihaz anahtarı üretici ve ürün kimliğinden (`areson:25A7:FA07`) türetilir; dolayısıyla alma/uyku döngüsünde ve alıcının çıkarılıp takılmasında korunur.

## Doğrulama

Tam uygulama MSVC C++17 ve Windows SDK ile derlendi ve gerçek fareye karşı çalıştırıldı. `BatteryHub.exe --list` şunu döndürdü:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

Ölçüm aynı anda resmi Redragon yazılımının gösterdiği yüzdeyle eşleşti. MinGW `build.bat` yeni kaynak dosyasını içerir; `Makefile` ise onu joker karakteri aracılığıyla keşfeder.

## Protokol kaynakları

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): Redragon yazılımının USB yakalamalarından elde edilen 17 baytlık çerçeveler, feature/input ayrımı ve `0x55` sağlama toplamı kuralı.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): `25A7:FA07` üzerinde `GetPower` komutu ve %10 düzey ölçeği.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md): yanıt düzeni ve `FA7B` / `FA7C` ailesindeki farklı yüzde ölçeği.


---

<a id="sec-darkrim"></a>
> 📄 **Bölüm:** DARKRIM SHADOW (`docs/darkrim.md`) · [İngilizce orijinal](../../docs/darkrim.md) · [↑ Başa dön](#top)

# DARKRIM SHADOW / 寸渊影弑 alıcısı

`3654:6901`, üretici `Jieli Technology`, sürüm `0100` üzerinde donanımda test edilmiştir. Arayüz **3**, kullanım `FF02:0002`, numarasız 64 baytlık giriş/çıkış yükleri (Windows HID rapor boyutları 65 bayt) kullanılır. Arayüz 4 de `FF02:0002` taşır ancak rapor kimliği 2 kullanır ve bu protokole yanıt vermemiştir; bilerek hariç tutulmuştur.

Protokol kaynağı: üretici yazılımı kurulmadan veya başlatılmadan indirilip statik olarak açılan resmi [PC Hub indirmesi](https://app.darkrim.net/hub/zh.html), `DARKRIM-0.1.26-x64-setup.rar`. Çıkarılan `DARKRIM.exe` SHA-256 değeri: `f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Bu ikili dosyadaki yararlı adresler:

- `140124C80`: `sendGetBasicInfo(infoType)` komut `0010`, Request `01`, yük `[infoType, 00]` gönderir. Pil seçicisi `01`'dir.
- `140118D30`, `140119200`: çerçeve başlığı ve CRC üretimi.
- `140126DB0`: cihaz bilgisi TLV ayrıştırıcısı; TLV `01` pildir.
- `1400F5660`, `1400FA700`: pil tüketicileri; alt yedi bit yüzdeyi verir, yüksek bit şarj durumudur. Aynı pil değeri `0011` Notify `03` içinde de gelir.

Başlık: `FE seq cmdLE type index count lengthLE`, ardından yük ve CRC-16/CCITT-FALSE (polinom `1021`, başlangıç `FFFF`, big-endian olarak saklanır). Sıra numarası (sequence) sıfır olmayan dört bitlik bir sayaçtır; şifreleme kullanılmaz.

HID sıfır dolgusundan önce gerçek istek/yanıt yükleri:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

Yanıt TLV'si `01 01 28` **%40, şarj olmuyor** değerini verir. Üretim C++ sürücüsü üretici yazılımı olmadan art arda üç sorguda bu değeri döndürdü. Alıcı eşleşen yanıttan önce yaklaşık 406 ms olarak ölçülen başlangıç bildirimleri yayar. İlgisiz bildirimler için yeniden başlatmadan tek bir 800 ms yanıt son süresi (artı yazma için en fazla 200 ms) kullanın. Kalp atışı (heartbeat) gerekmez.

Sürücü yalnızca pil GET isteğini gönderir. Yalnızca eşleşen sıra/komut/tür, indeks sıfır, sayaç sıfır veya bir (donanım sıfır kullanır), geçerli uzunluk/CRC ve tek bir düzgün biçimli pil TLV'si içeren şifrelenmemiş bir yanıtı kabul eder. Parçalanmış, istenmeyen, bozuk ve aralık dışı yanıtlar yok sayılır.

## Gözlemlenen pil hassasiyeti ve şarj durumu

Yüzdeyi **doğrulanmış %1 çözünürlüklü bir gösterge değil, kaba bir tahmin** olarak değerlendirin. Sahibinin birimi %40'tan %90'a kadar 10 yüzde puanlık adımlarla şarj ilerlemesi gösterdi. %90'da beş pil GET yanıtı ve bir istenmeyen bildirim tümüyle `DA` taşıdı: `DA & 7F = 90`, bit 7 şarjı gösterir. Sahibi şarj kablosunu çıkardıktan ve 2.4 GHz alıcıyı kullanmaya devam ettikten sonra başka beş GET yanıtı ve bir bildirim tümüyle `5A` taşıdı: hâlâ %90, artık şarj biti temizlenmiş durumda. On iki çerçevenin tümü CRC doğrulamasından geçti.

Temsili sorgu yanıtları (sıra 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Sürücü ve resmi uygulama her ikisi de yüzdeyi doğrudan alt yedi bitten alır. Sürücü onluklara yuvarlamaz, bir kademeyi onla çarpmaz veya ara değerleri enterpole etmez; sentetik %47 ve %95 raporları üretim ayrıştırıcısında %47 ve %95 olarak kalır. Dolayısıyla gözlemlenen kaba ölçümler ayrıştırıcının yukarısından, kulaklığın/alıcının bildiriminden kaynaklanır. Daha ince donanım ölçümleri gözlemlenmemiştir. Tam bir deşarj eğrisi kaydedilmemiştir, bu nedenle her deşarj düzeyinde veya başka donanım yazılımlarında sabit %10'luk bir adım olduğu doğrulanmamıştır.

%90 düzeyindeki şarj ve sonrasındaki şarj olmama durumları donanımda denetlenmiştir. Düşük/dolu sınırları, kulaklık kapanma davranışı, Bluetooth ve USB kablosu veri modu donanımda test edilmemiştir. Bu modlar için hiçbir destek iddiasında bulunulmaz. Bu uygulamada hiçbir donanım yazılımı güncellemesi, yapılandırma değişikliği, EQ komutu, eşleştirme değişikliği, sıfırlama veya üretici ikili dosyası yer almaz.

Test: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Bölüm:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [İngilizce orijinal](../../docs/hyperx_haste_2.md) · [↑ Başa dön](#top)

# HyperX Pulsefire Haste 2 Wireless pil protokolü

`src/drivers/hyperx.cpp` içindeki `HasteWireless` tarafından okunur. Sorgular [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) projesinden gelir ve NGENUITY'nin kullandıklarıyla aynıdır.

Donanımda doğrulananlar:

- Pulsefire Haste 2 Core Wireless, alıcı `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, alıcı `03F0:0F98`, uzumakiprime tarafından (PR #312). Düzey HyperX NGENUITY ile eşleşti.

`03F0:0D97` alıcısının da aynı şekilde çalışması beklenir ancak test edilmemiştir.

## HID koleksiyonu

| Alan | Değer (`0F98`) |
|---|---|
| USB arayüzü | `MI_02` (arayüz 2) |
| Kullanım sayfası : kullanım | `FF00:0001` |
| Giriş / çıkış / özellik rapor uzunluğu | 64 / 64 / 64 bayt |

Alıcı ayrıca standart fare ve tüketici denetim koleksiyonlarını da sunar. Sürücü yalnızca en az 8 baytlık giriş raporlarına sahip bir üretici koleksiyonunu (kullanım sayfası `FF00` veya üzeri) açar.

## Sorgular

İkisi de çıkış raporudur: aşağıdaki ilk iki bayt, rapor uzunluğuna kadar sıfırlarla doldurulur. Her yanıt, ilk baytı komut artı bir olan bir giriş raporudur. Her sorgu yanıtı için en fazla bir saniye bekler ve ilgisiz raporları atlar (yeniden bağlanmanın ardından alıcı kendiliğinden `44 xx`, `45 xx` ve `FB xx` raporları gönderir).

| İstek | Yanıt | Anlam |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = fare kapalıyken veya menzil dışındayken 0 |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100; `charge` 1 = şarj oluyor, 2 = şarj cihazında dolu; voltaj mV cinsinden, little endian (Core modelinde 0) |

- Bağlantı yanıtı eksikse pil yanıtı karar verir.
- Bağlantı 0 bildirirse pil sorgusu gönderilmez ve fare kapalı olarak gösterilir.
- Fare açıldıktan sonraki birkaç saniye boyunca yaklaşık %40 bildirir. Bağlantı kurulduktan sonraki 6 sn içindeki bir ölçüm yok sayılır ve bildirim alanı son değeri korur.

Her iki istek de yalnızca durumu okur. Hiçbir şey ayarları, aydınlatmayı veya modları değiştirmez.


---

<a id="sec-inphic"></a>
> 📄 **Bölüm:** Inphic IN10 (`docs/inphic.md`) · [İngilizce orijinal](../../docs/inphic.md) · [↑ Başa dön](#top)

# Inphic IN10 ailesi, KP 8K alıcısı

Sahibi tarafından IN10 MAX olarak tanımlanan bağlı cihaz, `Inphic KP 8K`, `1D57:FA65`, sürüm `0116` olarak listelenir. Durum koleksiyonu arayüz 2, kullanım `000A:0000`, giriş uzunluğu 5 (rapor kimliği 03 dahil) şeklindedir.

Herhangi bir istek gönderilmeden yaklaşık dört saniyede bir gözlemlenen rapor:

```text
03 73 41 01 64
```

Mevcut Xenta ayrıştırıcısı bu biçimi tanır: model, olay, pil durumu, yüzde. %100 göstermeden önce iki eşit rapor gereklidir; ilgili alıcılarda bağlantı kurulduktan sonraki ilk rapor yanıltıcı bir dolu ölçümü olabilir. Bu değişiklik bu korumayı ve mevcut şarj/uyku davranışını korur.

Resmi [Inphic HUB](https://hub.inphic.cn/) paketi `assets/index-BcHQx9B6.js`, ondalık 115 (`73`) modelini `IN10RMax` ile ve 116 (`74`) modelini `IN10Max` ile eşler. Yüzde için pil durumu 1, dolu için 2 ve şarj için 3 kullanır. `73`'ü IN10 MAX'e atayıp bu alıcıyı paylaşan diğer cihazları yanlış etiketlemek yerine donanım yazılımının model adını kullanın.

Bu değişiklikten önce uygulama bağlı fareyi `Wireless mouse` olarak listeliyordu. Xenta aktarımı pil çerçevelerini zaten işliyordu; değişiklik eksik model adlarını sağlar. Taze bir `--list` çağrısı uykuda gösterebilir çünkü beş saniyelik ilk gözlemi yalnızca bir tane dört saniyelik rapor alabilir. Yerleşik uygulama dinleyiciyi açık tutar ve sonraki bir yoklamada değeri onaylar.

Donanımda doğrulananlar: pasif raporlar, tekrarlanan %100 düzeyi ve yerel sürücü model tanımlaması. Şarj geçişleri, düşük pil sınırları, Bluetooth ve kablo modu doğrulanmamıştır. Model `74` resmi tablodan alınmıştır ve ayrı donanımda test edilmemiştir.


---

<a id="sec-machenike"></a>
> 📄 **Bölüm:** Machenike L7 (`docs/machenike.md`) · [İngilizce orijinal](../../docs/machenike.md) · [↑ Başa dön](#top)

# Machenike L7 Arctic / L7 Mix

Kendini **L7 Mix** olarak tanıtan bir L7 Arctic üzerinde doğrulandı:

| Bağlantı | VID:PID | Arayüz | Kullanım | Giriş / çıkış / maks özellik |
| --- | --- | --- | --- | --- |
| 2.4 GHz alıcı | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| USB kablosu | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

Sürücü ayrıca `L7 Mix` HID ürün adını da denetler. Diğer Machenike modelleri, farklı alıcı kimlikleri ve Bluetooth üretici sorguları etkin değildir.

## Protokol kaynağı

[Üreticinin sürücü sayfasından](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/) edinilebilen resmi **Machenike L7 Mix 1.0.0.8** yazılımının birlikte çalışabilirlik analizi ve gerçek fare üzerindeki salt okunur sorgular. `DeviceDriver.exe` SHA-256 değeri: `A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

Bu 32 bitlik yürütülebilir dosyada (görüntü tabanı `00400000`), `00436750` sanal adresindeki işlev durum isteğini oluşturur; `004494F0` bunu `HidD_SetFeature` üzerinden gönderir ve özellik yanıtını okur. Durum ayrıştırıcısı `00410C20` aşağıdaki alanları çıkarır ve pil ile şarj alanlarını arayüze aktarır. Bunlar dosya ofsetleri değil, sanal adreslerdir. Burada hiçbir tescilli yürütülebilir dosya, uygulama kodu veya kaynak yer almaz.

## Durum okuma sorgusu

**21 bayt** gönderin, rapor kimliği `51`, komut `06`, diğer tüm baytlar sıfır:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Yine 21 bayt kullanarak özellik raporu `51`'i okuyun. Koleksiyonun maksimum özellik boyutu olan 1001 diğer raporlar içindir; durum raporunun uzunluğu değildir. Sürücü okumadan önce 10 ms bekler ve ilgisiz yanıtlar dahil olmak üzere ürün başına tek bir 200 ms son süre kullanır. Hiçbir ayar, mod, makro veya donanım yazılımı komutu göndermez.

İndeksler rapor kimliğini içerir:

| Baytlar | Anlam / gözlemlenen değerler |
| --- | --- |
| 0–1 | `51 06`, zorunlu komut yankısı |
| 4–7 | `8A 24 4E FF`, doğrulanan L7 cihaz imzası |
| 10, bitler 0–2 | Çalışma modu: alıcıda 1, kabloda 0 |
| 10, bit 3 | Kablosuz fare bağlı; USB kablosunda da sıfırlanır |
| 11 | Pil yüzdesi, 0–100 (sıfır geçerlidir) |
| 12 | Şarj bayrağı: 0 deşarj oluyor, 1 şarj oluyor |

Diğer alanlar ve sağlama toplamı anlamları belirlenmemiştir. Sürücü bir sağlama toplamı uydurmaz. Bir ölçümü yayımlamadan önce komutu, uzunluğu, cihaz imzasını, modu ve bağlı durum pil/şarj aralıklarını doğrular.

Yakalanan alıcı yanıtı, resmi uygulamada da %64:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Şarj olurken yakalanan USB kablosu yanıtı (%74):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

Bu sırada alıcı hâlâ önbellekteki %64 değerini döndürdü ancak bağlantı bitini temizledi:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Bu bağlantısı kesilmiş ölçüm önbelleğe alınmış pil/şarj değerlerini göstermemelidir. Her iki aktarım da mevcut olduğunda kablo öncelik alır ve kararlı cihaz anahtarı aktarımlar arasında paylaşılır. Bilinen bir L7, sonraki Ajazz sürücüsünün paylaşılan VID üzerinde farklı bir protokolle onu yoklamaması için sorgu başarısızlığında bile ayrılır.

## Doğrulama sınırları

Sabit test verileri ve benzetilmiş aktarım testleri yakalanan ölçümleri, şarjı, geçerli %0/%100 değerlerini, bağlantısı kesilmiş alıcıları, bozuk/bayat yanıtları, katı eşleştirmeyi, aktarım hatasını, yinelenen girdi bastırmayı ve sınırlı yeniden deneme döngülerini kapsar. Gerçek %0/%100 ve tüm uyku/donanım yazılımı varyantları bu testler tarafından garanti edilmez.


---

<a id="sec-nuphy"></a>
> 📄 **Bölüm:** NuPhy WH80 (`docs/nuphy.md`) · [İngilizce orijinal](../../docs/nuphy.md) · [↑ Başa dön](#top)

# NuPhy WH80 (USB kablosu ve Bluetooth)

`19F5:A011`, donanım yazılımı sürümü `0116`, arayüz 1, kullanım `0001:0000`, numarasız 64 baytlık giriş/çıkış yükleri (Windows HID yeteneklerinde 65 bayt) ile donanımda test edilmiştir.

Protokol kaynağı: [NuPhyIO](https://drive.nuphy.io/), paket `main.b3fb29e0.js`, SDK `getBatteryState(0)`, `getDataPackage` ve `createCommand`. Yalnızca `GetFunc` (`05`), ofset `0020`, uzunluk `01` istenir. Hiçbir başlatma, yapılandırma, aydınlatma veya donanım yazılımı komutu gerekmez.

64 bayta kadar sıfırlarla doldurulmuş istek yükü:

```text
55 05 00 21 01 20 00 00
```

Gerçek yanıt yükü:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

3. bayt, 4..63. baytların toplamının düşük baytıdır. Pil 8. bayttır: `value & 7F` yüzde, `value & 80` ise SDK şarj bayrağıdır. Yerel C++ sürücüsü bağlı klavyede **%100, şarj oluyor** değerini döndürdü. Şarj geçişleri ve düşük/dolu sınırları donanımda test edilmemiştir; resmi donanım yazılımı notları WH80 ölçümlerini %10 artışlarla tanımlar. Alıcı üzerinden çalışma bu sürücünün kapsamı dışındadır.

## Bluetooth

Bluetooth üzerinde aynı klavye `19F5:324A` HID kimliğini (sürüm `0129`) kullanır ve `NuPhy WH80 - 1` gibi kullanıcı tarafından görülebilen bir ad yayınlar. İki klavye koleksiyonu ve bir fare koleksiyonu sunar. Genel HID sezgisi farelere öncelik verir, bu nedenle bu tam Bluetooth kimliğini mevcut klavye geçersiz kılmalarına ekleyin.

Pil bildirimi Windows Bluetooth pil özelliğini kullanmaya devam eder. USB çıkarıldıktan sonra Windows bağlı klavyede **%95** bildirdi. Standart GATT Battery Level (`180F` / `2A19`) önbelleksiz okuması da doğrudan klavyeden **%95** döndürdü. Bu, kablolu %100 gözleminden ayrı bir cihaz/aktarım ölçümüdür; bunu varsayılan bir dolu değerle değiştirmeyin veya yeniden ölçeklendirmeyin. Farklı donanım yazılımı ölçümlerinin nedeni belirlenmemiştir.

Sürücü tam ürün/arayüz/rapor boyutlarını, yanıt başlığını, ofseti, uzunluğu, sağlama toplamını ve yüzde aralığını denetler. 400 ms'lik bir yanıt son süresi kullanır ve aynı son süre içindeki ilgisiz yanıtları yok sayar.

Regresyon testi:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Bölüm:** Rapoo (`docs/rapoo.md`) · [İngilizce orijinal](../../docs/rapoo.md) · [↑ Başa dön](#top)

# Rapoo fare pil desteği

## Özgün program fareyi neden kaçırıyordu

`PollAllDevices()` her yenilemede Windows HID üst düzey koleksiyonlarını bir kez numaralandırır. Her üretici sürücüsü bir protokolü tanır, bir `DeviceStatus` ekler ve genel sürücülerin tekrar eklememesi için VID/PID'sini sahiplenir. Arayüz zaten yüzdeyi, şarjı ve uykudayken son ölçümü işler.

Rapoo sürücüsü yoktu. VT3 Max Gen 2 pilini standart HID Battery Strength kullanımı veya bir Windows Bluetooth pil özelliği yerine üretici tanımlı bir giriş raporunda gönderir. Bu nedenle mevcut genel HID/Bluetooth geri dönüşleri onun USB alıcısını çözemiyordu.

## Gözlemlenen donanım ve paketler

2026-11-16 tarihinde sahibinin VT3 Max Gen 2 faresiyle Windows üzerinde test edildi:

| Bağlantı | VID:PID | Arayüz | Kullanım sayfası:kullanım | Giriş / çıkış boyutu |
|---|---|---|---|---|
| 2.4 GHz alıcı | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 bayt |
| USB kablosu | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 bayt |

İkisi de kendisini `Rapoo Gaming Device` olarak tanıtır. Diğer koleksiyonlar standart fare, klavye ve medya girişlerini, üretici yapılandırma koleksiyonlarını ve 513 baytlık bir donanım yazılımı arayüzünü içerir. Pil sürücüsü yalnızca tanınan giriş boyutuna sahip `FF00:0002` koleksiyonunu açar. Donanım yazılımı arayüzünü asla açmaz ve asla bir çıkış raporu, özellik raporu, el sıkışma veya yapılandırma komutu göndermez.

Rapor kimliği dahil yakalanan kablosuz raporu:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Yakalanan kablo/şarj raporu:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Aşağıdaki konumlar, bu projenin `HidDev::Read()` işleviyle eşleşecek biçimde rapor kimliğini sıfırıncı bayt olarak sayar:

| Bayt(lar) | Anlam | Örnek |
|---|---|---|
| 0 | Rapor kimliği | `07` |
| 1 düşük yarım bayt | Bağlantı: 0 alıcı, 1 Bluetooth, 2 kablo | `20` / `22` |
| 1 yüksek yarım bayt | Sensör bilgisi; bağlantı türünün parçası değildir | `2` |
| 2 | Geçerli DPI kademesi | `03` |
| 3–4, 5–6 | X/Y DPI, little endian | `0320` = 800 |
| 7 | Pil durumu: 0 geçersiz, 1 deşarj oluyor, 2 şarj oluyor | `01` / `02` |
| 8 | Pil yüzdesi, 0–100 | `19` = %25 |
| 13–14 | Mevcut olduğunda fare ürün kimliği, little endian | `4617` |

Canlı alıcı yakalaması `%25` bildirdi ve tam uygulama ardından kablo üzerinden `%27, şarj oluyor` değerini döndürdü. Ayrıştırıcı testi gerçek kablosuz yakalamayı içerir. Şarj ve kablo bağlantısı da canlı donanıma karşı doğrulandı; bunlar yalnızca bir USB cihazının mevcut olmasından çıkarılmaz. Sahibi kabloyu çıkarıp alıcıyı tekrar bağladıktan sonra son yürütülebilir dosya şarj bayrağı olmadan `2.4 GHz alıcı` üzerinden `%52` döndürdü ve aynı `rapoo:4617` anahtarını korudu. Bu da kablodan alıcıya geçişi canlı donanıma karşı doğrular.

2026-11-17 tarihinde Windows'ta bir **VT9 Gen 2** ile de test edildi:

| Bağlantı | VID:PID | Arayüz | Kullanım sayfası:kullanım | Giriş / çıkış boyutu |
|---|---|---|---|---|
| 2.4 GHz alıcı | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 bayt |
| USB kablosu | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 bayt |

VT9 Gen 2 alıcısı, tam olarak aynı Nordic 54L `07` düzenini (13–14. baytlardaki gömülü `4614` PID dahil) kullanarak 19 bayt yerine **16 baytlık** bir `FF00:0002` raporu sunar. Yakalanan çerçeveler:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # alıcı: %100, deşarj oluyor
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB kablosu (anahtar AÇIK): %100, şarj oluyor
```

USB kablosu üzerinden etkileşim sırasında (ör. DPI değişikliği) durum raporları gözlemlendi; takılıyken alt güç anahtarı KAPALI konuma getirildiğinde fare gerçek pil yüzdesi yerine `state=2, percent=1` bildirdi.

### 13 baytlık koleksiyona sahip VT3 Max Gen 2 alıcısı (issue #1396)

Aynı alıcı kimliği `24AE:1417` için gönderilen bir cihaz isteği formu raporu farklı bir arayüz düzeni listeledi: 19 yerine **13 / 13** baytlık `FF00:0002` ve 33 / 33 baytlık `FF00:000E`, 513 baytlık donanım yazılımı koleksiyonu olmadan. Bu başka bir alıcı donanım yazılımı revizyonu gibi görünüyor. Rapoo yazılımı pili hâlâ gösterdiğinden sürücü çalışan bir durum kanalını göz ardı etmiş oluyordu.

Rapoo Hub'ın `VT_nrf54L` çözücüsü (`py`) uzunluk uyarlamalıdır: DPI, pil durumu ve yüzdeyi her zaman okur; sonraki alanları (`n[12..13]` konumundaki fare PID'si, RF bilgisi, ...) ise yalnızca rapor yeterince uzun olduğunda okur. VT3 MAX bildirimi (`productId: [17943, 5143]`) özel bir giriş raporu türüne sahip değildir, dolayısıyla bu alıcıda da `07` raporu o çözücüden geçer. 13 baytlık bir rapor (kimlik artı 12 bayt) yine 7. baytta durumu ve 8. baytta yüzdeyi taşır; yalnızca gömülü fare PID'si eksiktir, bu nedenle ölçüm alıcı PID'sini kullanır ve `rapoo:4617` anahtarını korur.

13 bayt uzunluğu **yalnızca `24AE:1417` için** kabul edilir. Çerçeveler yine aynı denetimlerden geçmelidir (rapor `07`, bağlantı yarım baytı 0–2, durum 1/2, yüzde 0–100). Henüz canlı bir 13 baytlık çerçeve yakalanmamıştır; testler test edilen 19 baytlık yakalamanın 13 bayta kesilmiş halini kullanır.

## Diğer Rapoo fareler

Resmi Rapoo Hub, Nordic 54L fare sürücüsü için bu `07` düzenini kullanır. Bildirimleri VT0, VT1, VT2, VT3, VT3S, VT7, VT9 ve ek varyantları listeler. Geçerli paketin incelenmesi `VT_nrf54L` kullanan 69 VT varyantı belirlemiştir; bu, paylaşılan bir protokolün kanıtıdır, 69 donanım doğrulaması veya tüm Rapoo kataloğunun çoğunu kapsama iddiası değildir. Destek; Rapoo VID'si, ayrılmış koleksiyon, giriş uzunluğu ve geçerli bir durum raporuyla seçilir, bu nedenle aynı protokoldeki listelenmemiş bir model de pilini bildirebilir. Küçük bir ad tablosu yaygın modelleri kapsar; diğerleri HID ürün adlarını korur veya `Rapoo wireless mouse` gösterir.

Ürün adları ve kimlikleri nesiller ve bölgeler arasında değişiklik gösterir. Test edilen `1417/4617` çifti geçerli resmi bildirimde `VT3 MAX` olarak adlandırılır; sahibi onu VT3 Max Gen 2 olarak tanımlar. Geçerli bildirimdeki ayrı `VT3 MAX V2`, `1B06/4B06` kimliklerine sahiptir. `1417`'yi VT9 Pro'ya atayan topluluk tabloları bu cihazı adlandırmak veya algılamak için tek temel olarak kullanılmamalıdır.

VT3 Pro (`1215/4415`) için belgelenen daha eski VT donanım yazılımı bunun yerine aynı `FF00:0002` kullanımında 7 baytlık bir rapor gönderir:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

Bu eski biçim için 1/2 durumları deşarj oluyor/şarj oluyor anlamına gelir. `7F` şarj yüzdesi bilinmiyor anlamına gelir ve bilinmiyor olarak korunur. Geçiş durumu 0, ilgisiz `BC` raporları, bozuk paketler ve 100'ün üzerindeki yüzdeler yok sayılır. Eski destek otomatik test kapsamına sahiptir, ancak burada fiziksel bir eski fareyle doğrulanmamıştır. Bu yorumlama `1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) ürün kimlikleri ve bunların 7 baytlık giriş koleksiyonlarıyla sınırlıdır.

VT1 Pro Max (alıcı `24AE:1233`, kablo `24AE:4433`, fare donanım yazılımı 222, alıcı donanım yazılımı 213) sahibinin issue #136'ya eklediği USBPcap yakalamalarından eklendi. `--dump` çıktısı arayüz 1 üzerinde 7 baytlık `FF00:0002` koleksiyonunu listeler ve yakalamalar Rapoo uygulamasından hiçbir istek olmadan gönderim yaptığını gösterir:

```text
BB B0 71 84 03 01 64   alıcı, her ~3.2 sn; Rapoo uygulaması %100 gösterdi
BB B0 71 84 03 02 5F   kablo, şarj oluyor, %95; Rapoo uygulaması "Charging" gösterdi
```

Kablo üzerinde rapor 16 saniyelik yakalamada yalnızca bir kez görüldü, bu nedenle yalnızca kablolu bir ölçüm bazı yenilemelerde zaman aşımına uğrayabilir; alıcı düzenli olarak gönderir. Nordic profili `BB` paketlerini asla yorumlamaz.

Bu, her Rapoo cihazı için destek **anlamına gelmez**. VT1 SE ve VT7 SE gibi CH584 modelleri resmi sürücüde `08` raporunu kullanır ve bu çözücü tarafından desteklenmez. Diğer Telink revizyonları `BB` bayrakları için farklı bir yorumlama kullanır, bazı ofis modelleri etkin pil sorguları kullanır ve Bluetooth modelleri yalnızca Windows pil özelliğini sunabilir. Bunlar mevcut geri dönüşlerde kalır veya ayrı bir doğrulanmış uygulama gerektirir. Onlara tahmin edilmiş sorgular göndermeyin.

## Yoklama ve kimlik

- Okuma pasiftir. Eşleşen `FF00:0002` tanıtıcıları yoklamalar arasında açık kalır (`PollXenta` ile uyumlu olarak), böylece Windows 60 saniyelik yenileme aralığında gelen durum çerçevelerini arabelleğe alır; her yoklama ilk açılışta veya boş bir kuyrukta 5 saniyelik beklemeye geçmeden önce kuyruktaki çerçeveleri boşaltır (en yeni geçerli pil ölçümünü tutarak). Çıkarılan cihazlar kaldırılır ve tanıtıcıları kapatılır. İlgisiz paketler son süreyi yeniden başlatmaz.
- Gömülü fare PID'si veya eski cihazlar için bilinen bir kablo/alıcı çifti, kablo değişiklikleri boyunca aynı arayüz anahtarını verir. Kablo ve alıcı ölçümleri tek bir girdide birleştirilir; kablo bilinmeyen bir düzey bildirdiğinde geçerli bir alıcı yüzdesi korunurken kablonun durumu tercih edilir.
- Zaman aşımı bir yüzde uydurmaz veya cihazı sahiplenmez. Başarılı bir okumanın ardından mevcut arayüz bu ölçümü mevcut 30 dakikalık sessizlik boyunca soluk olarak tutabilir.
- Programın mevcut VID/PID tabanlı kimlik modeli aynı model kimliğine sahip birden fazla özdeş fareyi ayırt edemez. Fiziksel eşzamanlı kablo/alıcı çalışması test edilmedi; her iki girişi birleştirme benzetilmiş aktarım testiyle kapsanmaktadır.

## Doğrulama

`make test`, taşınabilir bir çözücü testi ve benzetilmiş HID yanıtlarıyla bir Windows sürücü testi çalıştırır. Kapsam; gerçek yakalamayı, %0 ve %100'ü, şarjı, eksik düzeyleri, geçersiz/kesilmiş çerçeveleri, desteklenmeyen koleksiyonları/üreticileri, protokol profili yalıtımını, zaman aşımlarını, kararlı anahtarları ve bilinen bir yüzdeyi atmadan kablo/alıcı tekilleştirmesini içerir.

Tam uygulama yerel olarak MSVC C++17 ve Windows SDK ile derlendi ve gerçek fareye karşı `--list` / `--dump` çalıştırıldı. Sürdürülen MinGW derlemesi `build.bat` içinde `rapoo.cpp` dosyasını içerir; Makefile onu otomatik keşfeder. Test ortamında MinGW'nin kendisi kurulu değildi.

## Protokol kaynakları

- [Resmi Rapoo Hub](https://hub.rapoo.cn/), 2026-11-16 tarihinde incelendi: paketlenmiş [JavaScript sürücüsü ve bildirimleri](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js). İlgili çözücüler `VT_nrf54L` için `py`/`Hk` ve bağlantı ile pil durumu anlamları için `qM`/`QM`'dir. Ayrı `VT_CH584` işleyicisi `08` raporunu tüketir ve bu uygulamanın kapsamı dışındadır. Küçültülmüş (minified) adlar gelecek sürümlerde değişebilir.
- Eski VT3 Pro raporları, şarj durumu ve bilinmeyen düzey işaretçisi için [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs).
- Issue #136 USBPcap yakalamaları (alıcı üzerinde ve şarj olurken kablo üzerinde VT1 Pro Max).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js) pasif `07` durum yayınlarını ve pil ofsetini bağımsız olarak doğrular. Onun ayrıştırıcısı geçersiz yüzdeleri sınırlar; bu uygulama bunun yerine onları reddeder.


---

<a id="sec-rawm"></a>
> 📄 **Bölüm:** RAWM (`docs/rawm.md`) · [İngilizce orijinal](../../docs/rawm.md) · [↑ Başa dön](#top)

# RAWM protokol notları

RAWM fareler (ve platformu paylaşan SADES Dagger), RAWM HUB uygulamasıyla 64 baytlık numarasız giriş ve çıkış raporlarına sahip (rapor kimliğiyle 65 bayt) bir üretici HID koleksiyonu olan `FF00:0001` üzerinden konuşur. Alıcılar ve fareler Nordic'in üretici kimliği `1915`'i kullanır.

Kaynak: RAWM HUB web uygulaması, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>) ve betiği `https://hub.miracletek.net/hub/js/library.min.js` (gizlenmiş/obfuscated; aşağıdaki işlev ve sabit adları betiğin kendi adlarıdır). Desteklenen ürün kimlikleri uygulamanın indirdiği cihaz tablosundan (`https://www.miracletek.net/game/device.php`) gelir. Leviathan V4 GT ve NYX60, farklı bir protokol olan VID `373E` üzerinde Hub Web 3.0 kullanır.

## Paketler

Her raporun 0. baytı (rapor kimliğinden sonra):

| Üst bitler | Anlam |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | alt 6 bit yük boyutudur; yük olay akışını sürdürür |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | akış denetimi (boş arabellek boyutları); burada yok sayılır |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | alt 6 bit bir ESB kanalıdır; raporun geri kalanı o kanal için bir pakettir. Alıcı arkasındaki fare kanal 0'dır |

Yükler bir olay bayt akışı oluşturur:

```
FF FF FF FF                      eşzamanlama (yalnızca cihazdan ana bilgisayara)
cmd | ((len >> 4) & 0xF0), len   len bu iki baytı içerir (12 bit)
gövde ...
```

## Pili okuma

Sürücü, bir alıcı bağlandığında uygulamanın yaptıklarını tekrarlar (`send_event_query`, `send_event_ping`):

1. Alıcıya: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), ardından `00 84 0E 04 00 00` pingleri. Cihaz yalnızca ana bilgisayar yazmaya devam ettiği sürece gönderir, bu nedenle ana bilgisayar ping atar. Alıcı JSON ile `CMD_QUERY_RESULT` (`02`) yanıtı verir, ör. `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. Başına `C0` eklenmiş olarak kanal 0 için aynı sorgu ve pingler. Fare 30 baytlık ESB parçaları halinde ~550 baytlık bir JSON nesnesiyle yanıt verir, ör. `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`. `battery` bir yüzdedir (RAWM HUB bunu olduğu gibi gösterir), `chr` şarj olurken 1'dir.
3. Sonraki değişiklikler `CMD_NOTIFY` (`0B`) tür `17` olarak gelir: `[17, percent, charging]`.

Sürücü, uygulamanın yaptığı gibi her zaman önce alıcıya sorar (bir testte yalnızca kanal 0'a gönderilen bir sorgu yanıt alamadı). Uyuyan bir fare hiç yanıt vermez; alıcı ise yanıt vermeye devam eder.

Sorgu, uygulama o şekilde gönderdiği için bilgisayarın saatini taşır; başka hiçbir şey yazılmaz. Fareler `"crc":1` bildirir, bu da uygulamaya sonraki komutları (yapılandırma) bir CRC-16 çerçevesine sarmasını söyler; sorgu ve pingler, uygulama bunu bilmeden önce gönderdiği gibi CRC olmadan kabul edilir.

RAWM HS Receiver `1915:2346` (donanım yazılımı 2.0.2) ile bir Leviathan V4 (donanım yazılımı 1.2.0) üzerinde test edilmiştir.


---

<a id="sec-vaxee"></a>
> 📄 **Bölüm:** VAXEE (`docs/vaxee.md`) · [İngilizce orijinal](../../docs/vaxee.md) · [↑ Başa dön](#top)

# VAXEE 4K/8K alıcıları ve ZYGEN NP-01S V2

## Kapsam ve donanım doğrulaması

Bu sürücü, 64 baytlık özellik raporuna sahip `FF05:0001` üretici koleksiyonları üzerinden VAXEE 4K alıcısı `3057:1002`, VAXEE 8K alıcısı `3057:2002` ve USB kablosu üzerindeki ZYGEN NP-01S V2 Wireless (`3057:1011`) modellerini destekler. Diğer VAXEE alıcıları, diğer kablo ürün kimlikleri ve ZOWIE cihazları bilerek yoklanmaz.

8K alıcısı (`VAXEE 8K Wireless`, bir NP-01 Ergo Wireless 8K ile eşleştirilmiş) Windows'ta test edildi ve aynı protokol üzerinden bildirim yaptı:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

Alıcı tüm VAXEE 8K fareler tarafından paylaşılır ve hangisinin eşleştirildiğini bildirmez, bu nedenle kendi adıyla gösterilir. 8K alıcısı üzerinde şarj durumu henüz donanımda gözlemlenmemiştir.

Gerçek bir 4K alıcısı Windows'ta test edildi:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

Tümleşik uygulama da şunu bildirdi:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

Aynı fare daha sonra doğrudan USB üzerinden bağlandı ve Windows onu `ZYGEN NP-01S V2 Wireless` (`3057:1011`) olarak tanıdı. Güncellenen üretim sürücüsü şunu bildirdi:

```
VAXEE battery: 75%; charging: yes
```

İlk alıcı derlemesinde görev çubuğu bileşeni başarıyla oluşturuldu. Hem pille alıcı çalışması hem de kablolu şarj gözlemlenmiştir; tam şarj geçişleri ve uyku/kapalı davranışı donanımda test edilmemiştir. Şarj çözme ve geçersiz yanıtlar benzetilmiş yanıtlarla kapsanmaktadır.

## Protokol

Kaynak: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

Bir istek sıfırla doldurulmuş 64 baytlık bir HID özellik raporudur:

| Bayt | Değer |
|---|---|
| 0 | `0E`, rapor kimliği |
| 1 | `A5`, başlık |
| 2 | Pil düzeyi için `0B`; şarj durumu için `10` |
| 3 | `01`, okuma bayrağı (asla yazma olan `02` değil) |
| 4 | `01`, veri uzunluğu |
| 5–63 | `00` |

İsteği `HidD_SetFeature` ile gönderdikten sonra 100 ms bekleyin ve `HidD_GetFeature` ile `0E` raporunu okuyun. En az altı bayt ve beklenen rapor kimliği, başlık, komut yankısı ile veri uzunluğunu gerektirir.

Pil için 5. yanıt baytı 0–20 aralığında olmalıdır ve beşle çarpılarak %5 adımlarla %0–100 verir. Şarj için şarj olurken 5. bayt sıfırdan farklıdır. Başarısız bir şarj sorgusu, aksi halde geçerli olan bir pil ölçümünü atmaz.

Sürücü pil isteğini bir kez yeniden dener. Eşleşen koleksiyon başına toplam 300 ms açık gecikme ile en fazla üç okuma isteği vardır (iki pil denemesi ve bir şarj sorgusu). Hiçbir ayar, eşleştirme, donanım yazılımı veya aydınlatma komutu göndermez.

Geçerli bir pil yanıtı alınmazsa sürücü hiçbir şey bildirmez ve cihazı sahiplenilmemiş bırakır. USB koleksiyonu mevcut kaldığı sürece arayüz, mevcut yetkisiz bırakma (grace) süresi davranışını kullanarak önceden başarılı olmuş bir ölçümü en fazla 30 dakika boyunca soluk olarak korur. Fiziksel koleksiyon kaybolursa sürücü bu yetkisiz bırakma süresini hemen sonlandırmak için bir bağlantısı kesilmiş durumu yayar. Bu, kablo fareye takıldığında bayat bir alıcı simgesinin asılı kalmasını önler.

## Testler

`make test`, üretim sürücüsünü benzetilmiş bir HID aktarımına bağlayan `tests/vaxee_driver_test.cpp` testini içerir. Tam giden salt okunur istekleri, yüzde dönüşümünü, şarj çözümlemesini, geçersiz ve eksik yanıtları, zaten sahiplenilmiş cihazları ve kesin koleksiyon filtrelemesini denetler.
