<!-- lang-switcher:start -->
🌐 **Languages:** **English** | [العربية](i18n/ar.md#sec-ardor-fury-v2) | [Deutsch](i18n/de.md#sec-ardor-fury-v2) | [Español](i18n/es.md#sec-ardor-fury-v2) | [فارسی](i18n/fa.md#sec-ardor-fury-v2) | [Français](i18n/fr.md#sec-ardor-fury-v2) | [עברית](i18n/he.md#sec-ardor-fury-v2) | [Magyar](i18n/hu.md#sec-ardor-fury-v2) | [日本語](i18n/ja.md#sec-ardor-fury-v2) | [한국어](i18n/ko.md#sec-ardor-fury-v2) | [Polski](i18n/pl.md#sec-ardor-fury-v2) | [Português (Brasil)](i18n/pt-BR.md#sec-ardor-fury-v2) | [Русский](i18n/ru.md#sec-ardor-fury-v2) | [Svenska](i18n/sv.md#sec-ardor-fury-v2) | [Türkçe](i18n/tr.md#sec-ardor-fury-v2) | [Українська](i18n/uk.md#sec-ardor-fury-v2) | [Tiếng Việt](i18n/vi.md#sec-ardor-fury-v2) | [简体中文](i18n/zh-CN.md#sec-ardor-fury-v2) | [繁體中文](i18n/zh-TW.md#sec-ardor-fury-v2) | [Add a language](i18n/README.md)
<!-- lang-switcher:end -->

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
