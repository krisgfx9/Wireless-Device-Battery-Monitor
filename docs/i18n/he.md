<!--
  תרגום מלא של תיעוד BatteryHub (עברית)
  מקור: docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **שפות:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | **עברית** | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [הוספת שפה](README.md)
<!-- lang-switcher:end -->

# BatteryHub — תיעוד מלא (עברית)

> קובץ Markdown עצמאי יחיד זה מאגד את כל המסמכים הגלויים במאגר, כך שמתרגמים צריכים לתחזק **קובץ אחד בלבד לכל שפה**.

## תוכן עניינים

1. [סקירת BatteryHub, התקנים נתמכים, התקנה, שורת פקודה ובנייה (`README.md`)](#sec-readme)
2. [מדריך לתורמים (`CONTRIBUTING.md`)](#sec-contributing)
3. [תבנית Pull Request (`.github/pull_request_template.md`)](#sec-pr-template)
4. [מדריך שחרור וחתימה (`docs/releasing.md`)](#sec-releasing)
5. [תיקון קושחת 2.4 GHz למקלדות Keychron (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [תמיכת BLE בבקר GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [מדריך שימוש בריבוי שפות ולוקליזציה (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [מקלט Areson 25A7 (`docs/areson.md`)](#sec-areson)
10. [מקלט DARKRIM SHADOW (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [מקלט Inphic IN10 / KP 8K (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [תמיכת סוללה לעכברי Rapoo (`docs/rapoo.md`)](#sec-rapoo)
16. [הערות פרוטוקול RAWM (`docs/rawm.md`)](#sec-rawm)
17. [מקלטי VAXEE 4K/8K (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **מדור:** סקירת BatteryHub (`README.md`) · [מקור באנגלית](../../README.md) · [↑ לראש הדף](#top)

# BatteryHub

*לשעבר **Wireless Battery**. בגרסה 1.1.0 שונה שם האפליקציה; עדכון שומר על ההגדרות, בחירת ההפעלה האוטומטית והיסטוריית הסוללה שלך.*

[![תמיכה ב-Ko-fi](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![תרומה דרך PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![הצטרפות ל-Discord שלנו](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![כוכב ב-GitHub](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![שיתוף ב-Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![דיווח על התקן](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![עזרה בתרגום](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

רמות הסוללה של העכבר, האוזניות, המקלדת והבקר האלחוטיים שלך — ישירות על שורת המשימות של Windows.

![BatteryHub בשורת המשימות](../screenshot.png)

> **רוצה רק שזה יעבוד?** הורד את **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** מהגרסה האחרונה, הרץ ולחץ "הבא". זה הכול.
>
> **משתמשים מתקדמים** יכולים להוריד את גרסת ה-ZIP הניידת, להשתמש ב[אפשרויות שורת הפקודה](#שורת-הפקודה) או [לבנות מקוד המקור](#בנייה) באמצעות `make` או `build.bat`.
>
> **אהבת?** BatteryHub הוא חינמי ובקוד פתוח. אם הוא חוסך לך פתיחה של תוכנות יצרן, תוכל לתמוך בו דרך [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) או [GitHub Sponsors](https://github.com/sponsors/krisgfx9). זה עוזר לי לשמור על האפליקציות שלי בחינם לצד הלימודים. לא יכול לתרום? ⭐ כוכב, שיתוף, או דיווח על התקן שאינו נתמך בצירוף פלט `--dump` עוזרים לא פחות.

- **זעיר**: אפליקציה בגודל ~350 KB הצורכת כ-2 MB זיכרון RAM. כתובה ב-C++/Win32 נקי, ללא סביבת ריצה וללא שירות רקע, ומותקנת תוך שניות ללא הרשאות מנהל.
- **ללא צורך בתוכנת יצרן**: היא מדברת ישירות עם ההתקנים. G HUB, Synapse, iCUE, GG ו-NGenuity יכולות להישאר סגורות (או לפעול ברקע; הן אינן מתנגשות).
- **מותגים רבים**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, בקרי PlayStation ו-Xbox, Samsung Galaxy Buds, כל התקן Bluetooth ש-Windows יודע את רמת הסוללה שלו, וכל אוזנייה הנתמכת על ידי [HeadsetControl](https://github.com/Sapd/HeadsetControl) המצורפת.

## תצוגה

**בשורת המשימות (ברירת מחדל):** `🎧 30%  🖱 93%` ליד אזור ההודעות, מצויר באמצעות גופן הסמלים של Windows.
- **סוללה חלשה:** מספר אדום פירושו 15% ומטה.
- **בטעינה:** ברק כחול ⚡ מופיע ליד המספר. לאחר שההתקן טעון במלואו ועדיין מחובר לחשמל, הוא הופך ל-✓ ירוק.
- **במצב שינה:** טקסט מעומעם מציין שההתקן במצב שינה ומוצג הערך האחרון הידוע.
- **מנותק (אופציונלי):** הפעל את *הצג התקנים מנותקים* כדי להציג `×` מעומעם עבור התקנים שהדרייבר שלהם מדווח במפורש על קישור אלחוטי לא מקוון. אפשרות זו אינה מסיקה על ניתוק מדגימת סוללה שהוחמצה; ברירת המחדל נותרת הסתרה של התקנים לא מקוונים.
- **שני התקנים מאותו סוג:** עם שני עכברים (או שני בקרים...) שניהם היו מקבלים את אותו סמל, ולכן כל אחד מקבל כיתוב זעיר של עד 3 אותיות בפינת הסמל שלו, הלקוח משמו (`MX`, `PRO`), או מספר כאשר השמות אינם מבחינים ביניהם. התקן שהוא יחיד מסוגו אינו מציג כיתוב.
- **ערכת נושא:** עוקב אחר מצב בהיר/כהה והתאמת קנה מידה (DPI).
- **ערכות נושא שקופות לשורת המשימות** (למשל Taskbar Styler של Windhawk): הפעל *רקע מאחורי הטקסט בשורת המשימות* בתפריט כדי שהטקסט יישאר קריא מעל הטפט.
- **מספר מסכים:** הווידג'ט מופיע על שורת המשימות של כל מסך, ליד השעון שלו, כך שהוא נשאר גלוי גם כאשר משחק פועל במסך מלא. האפשרות *הצג את הווידג'ט על* בתפריט בוחרת *כל המסכים*, *המסך הראשי בלבד*, או מסך אחד (למשל *מסך 3 בלבד*).
- **אפשרויות תצוגה נוספות:** *סמלים מעל האחוזים* מציב כל סמל מעל הרמה שלו כדי לחסוך ברוחב; *צבעי מותג* מציג מותגים מוכרים בצבע שלהם (ירוק של Razer, אדום של HyperX, ...) עם פס רמה קטן; שני התקנים מאותו סוג מקבלים כיתוב זעיר כדי להבדיל ביניהם; שורות משימות אנכיות משמאל ומימין מקבלות עמודת התקנים.
- **שפות:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 ו-繁體中文. הן האפליקציה ל-Windows והן האפליקציה ל-Linux עוקבות אחר שפת התצוגה של המערכת; *שפה* בתפריט בוחרת שפה אחרת, ומתקין ה-Windows תומך אף הוא בכל 19 השפות. מחרוזות הממשק נשמרות בקבצי `lang/*.json` סטטיים הניתנים לעריכה, והתיעוד המתורגם המלא נמצא ב-[`docs/i18n/`](README.md). ראה [תרגומים](#תרגומים) לעריכה או הוספה של שפה.
- **צבעי מותג:** התקנים של 15 מותגים מוכרים מקבלים את צבע היצרן שלהם, עם הילה עדינה ופס רמה דק מתחת לאחוזים: ירוק של Razer, כחול של Logitech, כתום של SteelSeries, צהוב של Corsair, אדום של HyperX / ROG / ZOWIE, PlayStation, Xbox, Samsung, Apple, Jabra, JBL, Cooler Master ו-Steam. לכל צבע יש גוון לשורת משימות כהה וגוון לשורת משימות בהירה. המותג נקבע לפי הדרייבר שמצא את ההתקן, אחר כך לפי מזהה הספק (VID), ולאחר מכן לפי השם; הצבעים והכללים נמצאים ב-`src/brands.cpp`. ניתן לכבות זאת דרך *צבעי מותג* בתפריט.

**סמלים במגש המערכת:** סמל אחד לכל התקן עם המספר מצויר בתוכו, בתוספת התראת "סוללה חלשה" ב-15%. האפליקציה עוברת למצב זה אוטומטית כאשר שורת המשימות אנכית או לא נמצאת.

**שמות התקנים מותאמים אישית:** פתח את תת-התפריט של ההתקן ובחר *שנה שם התקן...* כדי להגדיר שם (עד 64 תווים). השם מוצג בתיאור הכלי (tooltip) ובכיתוב של ווידג'ט שורת המשימות, בתיאור הכלי וההתראות של מגש המערכת ובתפריט ההתקן. השתמש ב-*אפס לשם המקורי* כדי לשחזר את שם הדרייבר. השמות נשמרים מקומית ברישום (Registry) של משתמש ה-Windows הנוכחי (`Software\WirelessBattery`, `DeviceAliases`), לפי מפתח ההתקן היציב. שינוי השם אינו משנה לעולם התאמת דרייברים, שאילתות פרוטוקול או פלט אבחון של `--list` / `--dump`. אין צורך בחשבון או בגישה לרשת.

רחף לפרטים. לחץ לפתיחת התפריט: כל התקן (לחץ על התקן כדי להסתיר או להציג אותו), מצב תצוגה, *רענן עכשיו*, *הפעל עם Windows* ו-*יציאה*. הרמות מתרעננות כל 60 שניות (*בדוק סוללה כל* בתפריט משנה זאת), ומיד כאשר התקן מחובר או שהמחשב מתעורר משינה.

## התראות סוללה חכמות (ניסיוני)

באפשרותך להגדיר **סף התראת סוללה חלשה לכל התקן** מתוך תת-התפריט של כל התקן: **התראות סוללה** → *שימוש בברירת המחדל (15%)*, *השבת התראות*, או אחד מהערכים 5%, 10%, 15%, 20%, 25%, 30%, 35%, 40%. ברירת המחדל הקיימת של 15% נותרת ללא שינוי אלא אם תבחר דריסה מותאמת. ההגדרות נשמרות לפי מפתח התקן ברישום ה-Windows של המשתמש הנוכחי (`Software\WirelessBattery`, `AlertThresholds`).

התראה מופעלת רק מתוך קריאת סוללה אמיתית ועדכנית של 0–100% כאשר ההתקן מחובר, ער ואינו בטעינה. התראה נשלחת פעם אחת, ותידרך מחדש לאחר שהרמה תעלה ביותר מ-10 נקודות אחוז מעל הסף שנבחר (או כאשר מתחילה טעינה). קריאות חסרות או התקנים במצב שינה אינם מפעילים מחדש התראות. התקנים מוסתרים אינם מפיקים התראות. השבתת התראות עבור התקן אחד אינה מסתירה אותו ואינה משנה את האחוזים שלו.

הן מצב ווידג'ט שורת המשימות והן מצב סמלי מגש המערכת תומכים בהתראות. מאחר ש-Windows זקוק לסמל באזור ההודעות כדי להציג בלון התראה קלאסי, מצב ווידג'ט עשוי להציג סמל התראה זמני למשך עד דקה אחת לאחר ההתראה. צבעי הווידג'ט והדגשת הסוללה החלשה עדיין משתמשים בסף הגלובלי המקורי של 15% של הפרויקט, באופן בלתי תלוי בהגדרת ההתראה.

## היסטוריית סוללה ותובנות

לחץ לחיצה ימנית על התקן בווידג'ט שורת המשימות או בתפריט מגש המערכת ובחר **היסטוריית סוללה...**.
המציג המקומי המודע ל-DPI (העוקב אחר ערכת הנושא הבהירה/כהה של Windows) מציג את רמות הסוללה המתועדות עם קווים מחברים בין דגימות במהלך **24 השעות האחרונות**, **7 הימים האחרונים** או **30 הימים האחרונים**, יחד עם הקריאה האחרונה, הרמה הנמוכה/הגבוהה ביותר, השינוי בנקודות אחוז ומספר הדגימות. באפשרותך לנקות את ההיסטוריה של ההתקן הנבחר מתוך המציג.

ההיסטוריה מתועדת **מקומית בלבד** עבור התקנים מחוברים וערים המדווחים אחוז מספרי. קריאות נדגמות לכל היותר אחת ל-30 דקות לכל התקן (למעט מעברי מצב טעינה, עם מרווח מינימלי של 60 שניות). הנתונים נשמרים עד 30 יום והקובץ המקומי נשמר מתחת לכ-2 MB. האפליקציה לעולם אינה מתשאלת חומרה מעבר לדגימה הקיימת שלה, אינה שולחת נתוני היסטוריה ברשת, ומחשבת הערכה שמרנית ומקורבת של זמן התרוקנות על בסיס תצפיות פריקה אחרונות בלבד. נדרשות לפחות ארבע נקודות, שעתיים, ירידה של שלוש נקודות אחוז, קריאה עדכנית ומקטע פריקה יציב. טעינה, קריאות ישנות או נתונים לא מספיקים משהים את ההערכה; זמן פעולה המדווח ישירות על ידי ההתקן אינו זמין. ההערכה אינה בגדר התחייבות. נתונים חסרים בגרף מוצגים כפערים ואינם מושלמים באינטרפולציה.

כבה את **תעד היסטוריית סוללה** בתפריט כדי להפסיק לשמור קריאות; מה שכבר נשמר יישאר עד שתנקה אותו במציג. הקובץ נשמר ב-`%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. מזהי ההתקנים שבו מקודדים (לא מוצפנים); הקובץ הוא מקומי לחשבון ה-Windows שלך. במצב `--demo`, הגרף משתמש בנתונים סינתטיים שלעולם אינם נשמרים. **הערה:** איסוף ההיסטוריה מתחיל רק לאחר שתכונה זו מותקנת והאפליקציה פועלת במשך זמן מה.

## התקנים נתמכים

| יצרן | התקנים | אופן העבודה |
|---|---|---|
| **NuPhy** | WH80 דרך כבל USB (`19F5:A011`) או Bluetooth (`19F5:324A`), נבדק בחומרה | USB: שאילתת סוללה לקריאה בלבד של NuPhyIO; Bluetooth: רמת סוללה של Windows עם סיווג כמקלדת ([הערות פרוטוקול](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) על מקלט ה-USB שלו `3654:6901` (נבדק בחומרה) | שאילתת סוללה מאומתת CRC לקריאה בלבד ודגל טעינה; נצפו קריאות גסות בצעדים של 10%, רמת דיוק עדינה יותר לא אומתה ([הערות פרוטוקול](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX על מקלט KP 8K (`1D57:FA65`; דגם `73` נבדק בחומרה, דגם `74` לא נבדק) | דוחות מצב פסיביים של Xenta; שתי מסגרות תואמות מאשרות את הרמה ([הערות פרוטוקול](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, נבדק), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` נבדק, `002D`/`002A`), A50 Gen 3 (`9886:0015` נבדק, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), דרך תחנת בסיס USB | אחוז סוללה, מצב טעינה ומצב עגינה |
| **Logitech** | עכברים ומקלדות על מקלטי Unifying, Bolt, Lightspeed (כולל דונגל PRO X3 SUPERSTRIKE `046D:C54F`) ו-Nano, דרך USB או Bluetooth; אוזניות G (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 על הדונגל החדש יותר `046D:0ADF` | HID++ 1.0 / 2.0 עם גילוי תכונות: unified battery, רמת סוללה, מתח, ADC; G435: דוחות יצרן במסגרות CRC-16, `GET_BATTERY` ביחידות mV |
| **Razer** | עכברים אלחוטיים, מקלדות ודונגלים; אוזניות BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X, V3 Pro for Xbox (מקלט `1532:0A55`, כבל `0A4E`); Barracuda X (2022) על מקלט ה-2.4 GHz שלה (`1532:0550` או `1532:0552`); Barracuda Pro (`1532:053A`) | פרוטוקול דוח מאפיינים של Razer; פרוטוקולי יצרן של BlackShark (V3 / V3 Pro / V3 X מתושאלים כל 5 דקות); Barracuda X: שאילתות סוללה וכבל של Airoha דרך המקלט |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (כולל `1038:225D`), Arctis Nova Elite (תחנת בסיס `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, לא נבדק), Aerox 3 Wireless CS2 Dragon Lore Edition (מקלט `1038:1878`, כבל `187A`), Aerox 3 Wireless Gen 2 (מקלט `1038:1890`, כבל `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | דוחות HID של היצרן; Aerox/Prime ו-Rival 650 חולקים רשומה אחת בין המקלט לכבל ה-USB, תוך העדפת הקריאה מהכבל כאשר שניהם עונים |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 wireless; התקני Bragi (Virtuoso, Void V2, HS80 MAX, עכברים ומקלדות Slipstream, כולל מקלט ה-Slipstream החדש יותר `1B1C:2B00`, למשל Scimitar Elite SE Wireless, ו-Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, לא נבדק) | דוחות HID של היצרן, Bragi `GET` (לקריאה בלבד), פרוטוקול סוללה של Compx באורך 17 בייטים (לקריאה בלבד) |
| **Cooler Master** | MM712, MM731 (דונגל 2.4 GHz או כבל USB) | דוח מצב HID של היצרן (לקריאה בלבד) |
| **Press Play** | ICARUS V2 Nearlink על מקלט ה-2.4 GHz שלו `7768:6434` (הדרייבר נבדק בחומרה ב-90%; הפרוטוקול נלכד ב-100% וב-90%) | דוח פלט לקריאה בלבד `06 05` ב-`FFB2:0001`; אחוז הסוללה בבייט 14 של התשובה |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` עבור PS, לא נבדק), Cloud Flight S, Cloud Stinger Core Wireless (כולל DTS `03F0:0A8E`, נבדק), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (דונגל 2.4 GHz), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (דונגל 2.4 GHz) (דונגל 2.4 GHz `03F0:0F98`, נבדק; `0D97` לא נבדק) | דוחות HID של היצרן (Haste 2: [הערות פרוטוקול](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | דוח מאפיינים של היצרן |
| **Hitscan** | Hyperlight X, Hyperlight N | דוח מאפיינים של היצרן (אותו פרוטוקול כמו Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, עכברים אלחוטיים של Pulsar ושל ATK VXE (למשל VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (מקלט 3554:F512) | פרוטוקול יצרן משותף עם תשובות בעלות סכום ביקורת |
| **Pulsar X2 V3** | X2 V3 על דונגל 1K (`3710:5402`) או כבל USB (`3710:3402`); X2 V3 eS על דונגל 8K (`3710:5403`) או כבל USB (`3710:3406`) | דוח מאפיינים של היצרן באורך 64 בייטים, רגיסטר סוללה `08 81 01` (לקריאה בלבד) |
| **ATK / VXE NK** | VXE R1 NK ועכברי NearLink אחרים על דונגל NK mouse NANO (`373B:1216`) | דוח פלט 08 של ATK BITMOUSE ב-`FF05:0001` (סוללה וטעינה) |
| **ATK 8K Nano** | עכברי ATK / VXE על דונגל ATK 8K Nano (`373B:1178`) | דוח מאפיינים Holtek GetConfigData (`82`) ב-`FF10:0001` (מתוך ATK HUB; סוללה וטעינה) |
| **אוזניות ATK** | ATK N9 Pro, N9 Ultra (דור ראשון) | פרוטוקול יציאת COM וירטואלית (יש לסגור את אפליקציית שולחן העבודה של ATK) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK והדונגלים 8K שלהם | פרוטוקול Glorious או Kysona, בהתאם לדגם |
| **עכברי Keychron** | M4 ועכברי Keychron אחרים על מקלט ה-2.4 GHz; עכברי 4K (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) על מקלט Keychron 4K Link (`3434:D038`); עכברי 8K (M5 8K, G6 HE 8K ...) על מקלט TurboLink 8K; עכברי 8K על מקלט Ultra-Link 8K (`3434:D028`); עכברים ישנים יותר (M1, M2, M3, M3 mini, M6, M7 ...) על מקלט 1K (`3434:D030` / `D031`); כדור עקיבה Nape Pro על מקלט Link-KM או כבל | דוח יצרן מתוך Keychron Launcher (מקלט 1K: דוח מאפיינים 51 06, כפי שמשתמשת אפליקציית שולחן העבודה של Keychron; Ultra-Link 8K: דוחות B5 03 / B3 06 ב-`FFC1`; Nape Pro: raw HID A7 31) |
| **מקלדות Keychron** | K5 Max (`3434:0A50`, נבדק) על מקלט Keychron Link (`3434:D030`) או כבל USB; מקלדות QMK אלחוטיות אחרות של Keychron לאחר שנבנו עם אותו תיקון | Raw HID ב-`FF60:0061`: `B2` שואל את המקלט איזו מקלדת מקושרת, `A4` מחזיר רמה, מתח ומצב טעינה. **מצריך קושחת מקלדת מתוקנת:** ראה [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). קושחת המקור מדווחת רק דרך Bluetooth |
| **CHERRY** | מקלדת MX 3.0S Wireless על דונגל ה-2.4 GHz שלה (`046A:00EA`, נבדק) או כבל USB (`046A:00E3`, נבדק) | שאילתת HID של היצרן `1A` ב-`FF1C:0092` (לקריאה בלבד), עם מצב הזנה מ-USB. Bluetooth מכוסה על ידי תמיכת ה-Bluetooth |
| **CHERRY** | עכבר אלחוטי Cherry XTRFY על מקלט 1K (`046A:0330`, נבדק) | פרוטוקול סוללה של CompX באורך 17 בייטים (`08 03` מצב קישור, `08 04` GetPower), אותה מסגרת כמו Corsair Sabre V2 Pro (לקריאה בלבד) |
| **Arbiter Studio** | Akitsu (מקלט 8K `373E:000A`, כבל `373E:0009`), Akitsu 3950 (מקלט 8K `373E:0039`, כבל `373E:0038`), Akitsu Medium (מקלט 8K `373E:0067` וכבל `373E:0066`, שניהם נבדקו) | דוח מאפיינים של היצרן לקריאה בלבד `0x83` ב-`FFFF:0000` מתוך Arbiter Web HUB (סוללה וטעינה) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (כבל, דונגלים של 1K ו-4K/8K) | דוח מאפיינים של היצרן מתוך LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) על דונגל 4K; XM2we על המקלט המקורי שלו (`3367:1961`) | דוח מאפיינים של היצרן `A1`, פקודת סוללה `B4` (לקריאה בלבד) |
| **מקלדות ATK / VGN / Evision** | ATK V75X ומקלדות VGN / VXE (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) על מקלט ה-2.4 GHz המשותף (`320F:5088`) או כבל USB (`320F:5055`), המזוהות לפי שם המוצר; מקלדות שמקלט ה-`320F:5088` שלהן נקרא "Wireless Gaming Keyboard", למשל Feker Alice80 (נבדק) | דוח פלט Evision `04`, פקודת סוללה `1A` (מתוך ATK HUB ו-VGN HUB); נשאל לכל היותר אחת ל-10 דקות דרך המקלט |
| **Redragon (Evision)** | K1NG M999 (נבדק) על מקלט ה-2.4 GHz `320F:226F`; מזהה המקלט עשוי להיות משותף לדגמים נוספים | אותו פרוטוקול Evision כמו מקלדות ATK (דוח `04`, פקודה `1A` ב-`FF1C:0092`), נשאל בכל דגימה; הטעינה מוצגת על תחנת העגינה המגנטית; כאשר כבל ה-USB מחובר המקלט ממשיך לחזור על הרמה הישנה ללא מצב טעינה |
| **Audeze** | Maxwell על דונגל ה-USB (`3329:4B19`) או כבל USB-C (`3329:4B1A`); Maxwell 2 על דונגל ה-USB (`3329:4B29`, נבדק); מזהי Xbox לא נבדקו | דוח יצרן `06` / דוח קלט `07`, תכונת סוללה `0CD6` (שאילתה יחידה לקריאה בלבד) |
| **ENDORFY** | Viro Wireless על דונגל ה-2.4 GHz שלה (`3738:0072`, לא נבדק) | Airoha RACE "get battery" (`0CD6`) על דוח יצרן `06` / דוח קלט `07`, אותה שאילתה לקריאה בלבד כמו דונגלים של Audeze ו-Skullcandy; ללא מצב טעינה |
| **Turtle Beach** | Stealth 700 Gen 3 על משדר ה-USB (`10F5:2251`, נבדק ב-HaloBattery; גרסת PC `10F5:2262`, לא נבדק) או כבל ה-USB של האוזניות עצמן (`10F5:2253`) | RACE `0x9942` (הפעלת לקוח ה-CoAP) ו-CoAP `GET /GSI` המועבר במנהור בתוך RACE `0x9902`, כפי שעושה Swarm II; סוללה מתוך מפתח `240` (ללא דגל טעינה) |
| **AKG** | N9 Hybrid על דונגל ה-USB שלה (`0ECB:20D9`, נבדק) | Airoha RACE ב-`FF13:0001`: דוח פלט `06`, דוח קלט `07`, תכונת סוללה `0CD6` (שאילתה יחידה לקריאה בלבד) |
| **NZXT** | Lift Elite Wireless על הדונגל שלה (`1E71:2101`) או כבל USB (`1E71:2129`) | קריאת יצרן `4E 02 81 .. B0` (מלכידות של NZXT CAM) |
| **Poly / Plantronics** | Voyager 8200 UC ואוזניות אחרות מאחורי מתאם BT600 (`047F:02EE` / `02F7`) | פרוטוקול get/set של דוח `07`, פריט סוללה `0A 1A` (לקריאה בלבד) |
| **WLMouse** | YING Magnesium (מקלט 8K `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (מקלט או כבל; לא Beast X 4K); Beast X V2 (מקלט 8K `36A7:A856`); Beast G (מקלט 8K `36A7:A860` או כבל `36A7:A861`; לא נבדק) | דוח מאפיינים של היצרן, פקודת מצב `0x83` (YING: אותו פרוטוקול כמו Glorious) |
| **Finalmouse** | UltralightX על דונגל ה-2.4 GHz שלו (`361D:0100`, נבדק); Starlight X על הדונגל שלו (`361D:0300` / `0301`, נבדק). לא על הכבל של העכבר עצמו | דוחות יצרן של xpanel ב-`FF00`: בקשות GET לקריאה בלבד, ואז *wake/all* (`0xE0`); מתח סוללה לפי העקומה של xpanel, או האחוז של Starlight X עצמו, בתוספת מצב טעינה |
| **VAXEE** | עכבר אלחוטי על מקלט VAXEE 4K (`3057:1002`) או מקלט 8K (`3057:2002`, למשל NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless דרך כבל USB (`3057:1011`) | דוח מאפיינים של היצרן לקריאה בלבד `0E` ב-`FF05:0001`; סוללה בצעדים של 5%, מצב טעינה ([הערות פרוטוקול](#sec-vaxee)) |
| **Scyrox** | V12M על מקלט ה-2.4 GHz שלו (`395A:0006`) | קריאת פרופיל S-Center 2.0 (דוח פלט `08`, פקודה `01`) ב-`FF00:0002`; סוללה בלבד, ללא מצב טעינה |
| **HECATE** | G5M PRO ועכברי HECATE אחרים על אותו מקלט, וכבל USB `35BB:D3FA / D3FC / D3FD` | פרוטוקול Kysona |
| **Redragon** | עכברים אלחוטיים מבוססי Compx: M916 Pro 1K (נבדק), M913 Impact Elite (תלת-מצבי), G49 (מקלט או כבל) | פרוטוקול Kysona (מקלטי Areson `25A7` מופיעים תחת Areson) |
| **Taidu (钛度)** | TSG808 על מקלט ה-2.4 GHz של Compx שלו `3554:F5D5` (נבדק) | פרוטוקול Kysona |
| **Areson (Redragon)** | M915RGB-WL (נבדק), M913 Impact Elite המקורי ועכברים נוספים על מקלט `25A7:FA07` / `FA08` | דוח מאפיינים `GetPower` באורך 17 בייטים; רמה בצעדים של 10% ודגל טעינה |
| **Ninjutso** | Sora V2 על מקלט 1K (`1915:AE1C`, נבדק) או כבל USB (`1915:AE11`, נבדק); Ten Air (מקלט `093A:EB01` וכבל USB `093A:E020`, נבדק) / Ten (`093A:EB01` / `E020`, לא נבדק) | דוחות מאפיינים של NinjaForce `0x05` (`0x15` עבור Sora V2) ו-`0x06` (`0x13`/`0x12`/`0x11` עבור Ten / Ten Air) |
| **Sprime** | PM1 על מקלט ה-2.4 GHz (`1915:AC1C`, נבדק; `1915:AD8C`) או כבל USB | אותו דוח מאפיינים 0x05, פקודת מצב 0x15, מדרייבר הרשת של Sprime (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 על מקלט RAWM HS (`1915:2346`, נבדק); ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, עכברי SA-* ו-SADES Dagger על מקלטי ה-RAWM שלהם (`1915:232A`–`234B`) או כבל USB | שאילתת פרטי-התקן של RAWM HUB 2.0 דרך המקלט (JSON עם אחוז סוללה וטעינה), לקריאה בלבד ([הערות פרוטוקול](#sec-rawm)) |
| **AULA** | מקלדות אלחוטיות F75 / F87 Pro / F99 על מקלט ה-2.4 GHz | מסגרת דוח 0x13, פקודה 0x4A, סכום ביקורת חיבורי (מצבי Bluetooth וחוטי לא נבדקו) |
| **עכברי AULA** | X9 Ultra (נבדק) על דונגל AULA-8K `320F:22A0`; מזהה המקלט משותף עם דגמי V9 | דוח `04`, פקודת סוללה לקריאה בלבד `1A` בין START `01` / END `02` ב-`FF1C:0092`; 2.4 GHz בלבד |
| **מקלדות SONiX (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (נבדק), EPOMAKER EA75 (נבדק), AULA F108 Pro על דונגל 2.4G `05AC:024F`; AJAZZ AK980 V2 על דונגל `0C45:FEFE`; AJAZZ AK820 Pro על דונגל `0C45:FDFD` או `0C45:FEFE`; EPOMAKER P75 ב-`342D:E479` (לא נבדק בחומרה) | דוח יצרן `20 01` בדף שימוש FF60, סכום ביקורת חיבורי (מצב 2.4G בלבד; ללא חיווי טעינה) |
| **מקלטי SONiX נוספים (לא נבדקו בחומרה)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | אותה שאילתה לסוללה בלבד `20 01`; נדרש VID:PID מדויק ואוסף `FF60:0061` עם דוחות באורך 33 בייטים; 2.4G בלבד, ללא חיווי טעינה |
| **מקלדות 36B0 (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB על דונגל 2.4G `36B0:3002` או כבל USB `36B0:3009` (הפרוטוקול נבדק בשניהם על ידי המדווח ב-#343); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) על אותו דונגל או כבל (לא נבדקו); URX Core75 על הדונגל (אומת ב-HaloBattery); EVO80 (לא נבדק) | קושחת PMO Hub: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` בדף שימוש FF60, מתוך pmohub.cn. קושחת URX / VIA: VIA custom-get `08 00 07` (ערוץ 0, ערך 7), מתוך URX HUB דרך HaloBattery. ללא חיווי טעינה |
| **DAREU** | EM901X על מקלט ה-2.4 GHz `260D:1074` או כבל USB `260D:1090` (קריאת הסוללה נבדקה בשניהם; מעברי דגל טעינה בהנחה והרמה מתחנת העגינה של המקלט נבדקו) | דוח מאפיינים לסוללה בלבד `08`, פקודה `04`; תשובה `09` באוסף יצרן נפרד. מצריך זוג קלט/מאפיינים חד-משמעי אחד לכל מזהה מוצר. מעדיף קריאת USB תקינה כאשר שניהם מחוברים; המקלט עלול להחזיר טלמטריה שמורה במטמון גם כשהעכבר כבוי |
| **DAREU** | מקלדת A84 (`260D:0022`, לא נבדק) | דוח מאפיינים SONiX בממשק 0, פקודה `04 F6` (קריאת הסוללה של הדרייבר הרשמי של A84); רמה באחוזים, ללא דגל טעינה |
| **DAREU** | A980 Pro על המקלט מרובה-העכברים `260D:1131` ועל כבל ה-USB שלו (`260D:1148`) (רמת הסוללה נבדקה בחומרה; דגל הטעינה אומת בעת חיבור לחשמל) | פרוטוקול Togran: דוח מאפיינים באורך 65 בייטים `0A` באוסף בקרת הצרכן (consumer-control); שאילתת חריץ (מחלקה 0 / `A0`) ולאחריה שאילתת סוללה (מחלקה 7 / `80`), בחריץ 0 דרך הכבל. לקריאה בלבד |
| **Sharkoon** | Skiller SGM50W ב-`260D:1125` (לא נבדק) | אותה שאילתת Compx כמו ב-DAREU EM901X (דוח מאפיינים `08`, פקודה `04`; תשובה `09` ב-`FF01:0000`); מעדכן הקושחה של Sharkoon עבורה הוא כלי של Compx על VID `260D` |
| **Zenith** | Zenith Pro על מקלט ה-2.4 GHz `260D:1114` (קריאת הסוללה נבדקה; טעינה לא נבדקה) או כבל USB `260D:1143` (לא נבדק) | אותה פקודת Compx (`08`, `04`) כדוח פלט ב-`FF02:0002`; תשובה `08 04` באותו אוסף עם אחוז, דגל טעינה ומילי-וולטים, מאומתת לפי סכום הבייטים `0x55` |
| **AJAZZ AK992** | מקלט 2.4 GHz של Telink `320F:50C3` (נבדק) | שאילתת סוללה של EVision באוסף HID `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, סדרת DW (U2-DW, S2-DW ...) ו-U2 על מקלט ה-2.4 GHz שלה | פקודות יצרן לקריאה בלבד המתועדות על ידי הקהילה |
| **Royal Kludge (RK)** | MG6 Pro על דונגל ה-2.4 GHz (`2E3C:00A6` / `00E6`) או כבל USB (`2E3C:00A5` / `00E5`) | מסגרת QiWang באורך 64 בייטים מדרייבר הרשת של RK, קריאת `GET_BATTER_VOL` (אחוז, מתח, טעינה) |
| **ASUS ROG** | מקלדות Strix Scope II 96 (RX), Azoth, Falchion; עכברי Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact; אוזניות Pelta (דונגל 2.4 GHz); אוזניות תוך-אוזן Cetra Open Wireless (דונגל SpeedNova `0B05:1CAC`, שמאל / ימין / מארז); מקלט Omni Receiver | שאילתת סוללה ROG HID |
| **Machenike** | L7 Arctic / L7 Mix על מקלט ה-2.4 GHz `248A:FF4C` או כבל USB `248A:FF4E` (שניהם נבדקו) | דוח מאפיינים לקריאה בלבד `51`, פקודת מצב `06`; סוללה וטעינה. [הערות פרוטוקול](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS על דונגל ה-2.4 GHz שלו (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (מקלט 2.4 GHz `0DB0:0D3C`, נבדק; כבל USB `0DB0:0D3B`) ו-CLUTCH GM41 Lightweight Wireless (מקלט `0DB0:0D4C` / כבל `0DB0:0D4B`, מלכידות של בעלים) | שאילתת יצרן לקריאה בלבד `0F 20` ב-`FF0D:00B0` ו-`FF00:0001`; סוללה ודגל טעינה בבייט אחד (הפרוטוקול ממודול Gaming Gear של MSI Center); GM41: דוחות פסיביים `A0 xx 07 …` ב-`FF10:0006` |
| **MCHOSE** | עכברי L7 / L7 Pro / L7 Ultra (L7 Ultra נבדק), M7 / M7 Ultra, A7 / A7 Ultra, K7 על מקלט ה-2.4 GHz או כבל USB; A5 V2 Ultra (מקלט 2.4 GHz `3837:100C`, נבדק), K7 Ultra (מקלט 2.4 GHz `3837:1001`, נבדק; A7 V2 Ultra+ `3837:100B` צפוי לעבוד, issue 227); G3 V2 (מקלט 2.4 GHz `3837:4245` וכבל USB `3837:418C`); K7 V2 Ultra+ על מקלט ה-2.4 GHz `3837:1014` או על כבל ה-USB שלו `3837:4028` (שניהם נבדקו; שאר מזהי המקלטים מהמשפחה החדשה `1018`, `1016`, `102C`, `102D` לא נבדקו) | דוח מאפיינים של היצרן, מטען הפוך (inverted payload, פרוטוקול מ-alexfrih/mchose-linux); דונגלי Realtek `3837` עונים לאותה שאילתה עם שדה vid מוגדר ל-`41E4` (A5 V2 Ultra) או `3837` (K7 Ultra); G3 V2: שאילתת יצרן לקריאה בלבד ב-`FF01:0010`; K7 V2 Ultra+: דוח באורך 64 בייטים `0x4D`, פקודת פרטי התקן `0x0900` ב-`FF01:0001` (פרוטוקול מדרייבר הרשת של M HUB) |
| **MCHOSE A5 (דור ראשון)** | A5 Pro / A5 Pro Max על מקלט ה-2.4 GHz של 1K או 4K (`2023:F013`, `2023:F015`, `2023:F018`) או כבל ה-USB (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); לא נבדק כאן | פקודת סוללה לקריאה בלבד `0x83` (דף 0) בדוח מאפיינים באורך 64 בייטים ב-`FFFF`, תשובה מסומנת ב-`0xA1` (פרוטוקול מדרייבר הרשת z750sasr A5 Pro Max ומ-HaloBattery, מזהים מ-Klegus/mchose-macos) |
| **אוזניות MCHOSE** | V9 Pro 2 על דונגל ה-2.4 GHz (`3837:6011`, נבדק) | מסגרת סוללה "MC" לקריאה בלבד של M HUB (דוח `0x55`, תת-פקודה `0x0B`) ב-`FF07:0222`; סוללה ודגל טעינה בבייט אחד (פרוטוקול מדרייבר הרשת של M HUB) |
| **מקלדות AULA / MCHOSE / Redragon** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 ושאר מקלדות M HUB; Redragon Horus Pro / Pro V2 (K618RGB-PRO) על מקלט ה-2.4 GHz (`3554:FA09`, `41E4:2001`); MCHOSE K87 על מקלט `05AC:024F` (פריסת BY בממשק 1, לא זו של SONiX) | מסגרת דוח 0x13, פקודה 0x4A (דגמי MCHOSE ו-Redragon מזוהים באמצעות פקודה 0x05, כמו ב-M HUB); מצבי Bluetooth וחוטי אינם מכוסים |
| **מקלדות MCHOSE** | G75 V2 על מקלט ה-2.4 GHz `3837:3033` (נבדק); אותו מקלט משווק עם G87 V2 ו-K99 V3 (אותו פרוטוקול, לא נבדקו); K87S משדך אותו מזהה מקלט לפרוטוקול שונה ואינו מכוסה | שאילתת func-config לקריאה בלבד "GLW" של M HUB באוסף `0001:0000` ללא מזהה באורך 64 בייטים: דגל בקשה `0x55`, פקודה `0x05`, סוללה בבייט 32 של המטען (סיבית 7 = טעינה), סכום ביקורת חיבורי |
| **AULA SC580** | עכבר SC580 / SC580X דרך כבל USB (`088D:062E`, נבדק) או מקלט ה-2.4 GHz שלו (`089D:062F`, נבדק) | פקודה לקריאה בלבד `0x30` (פרטי התקן) באוסף היצרן בן 33 הבייטים FF02:0000, סכום ביקורת חיבורי; בעת טעינה העכבר מדווח ערך קבוע 100, ולכן מוצגת הרמה האחרונה; מצב Bluetooth אינו מכוסה |
| **AULA HERO 68 Air** | HERO 68 Air על מקלט האלחוטי 8K (`372E:106C`) | מסגרות מאושרות באורך 20 בייטים בדף שימוש FF60 (ארבע מסגרות נתונים וסיומת לכל הודעה), פקודת סוללה לקריאה בלבד 0x87, דגל טעינה 0x10 לאחר הרמה; מצבי Bluetooth וחוטי אינם מכוסים |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra ו-S9 Max / Pro / Ultra / Ultra+ על מקלט "Gaming 2.4G" (`372E:103D`); S9 Ultra על כבל ה-USB שלו (`372E:1027`) | דוח מאפיינים לקריאה בלבד `03` ב-`FF00:0001`: בדיקת קישור `47`, נתוני בסיס של ההתקן `4F 81` (אחוז סוללה וסיבית טעינה), מדרייבר הרשת של EWEADN |
| **Rapoo VT** | VT3 Max Gen 2 (נבדק); VT9 Gen 2 (נבדק); עכברי Nordic 54L VT נוספים החושפים את אותו ממשק מצב; VT3 Pro מדור קודם (ניסיוני); VT1 Pro Max (מלכידות ה-USB של הבעלים) | דוח מצב HID פסיבי `07` ב-`FF00:0002` (16 או 19 בייטים; 13 בייטים בחלק ממקלטי VT3 Max Gen 2); פרוטוקול `BB` ישן מוגבל ל-VT3 Pro `1215/4415` ול-VT1 Pro Max `1233/4433`. מקלט וכבל USB, עם מצב טעינה |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (דגמי Xenta 30/50; ישן 3D), Delux M800 Pro, משפחת Ajazz AJ179; AJ159 ועכברי סדרת AJ נוספים על מקלט 3151; AJ139 V2 MC (מקלט `A8A5:2255`, כבל `A8A4:2255`) | דוחות יצרן (M900 Pro: שידורי מצב פסיביים או שאילתת מאפיינים, אירועי Xenta 40/41; סדרת AJ: דגימת מצב 0xF7, ולאחריה דוח מאפיינים 0x05) |
| **Incott** | G23 V2 / G24 (מקלט `093A:522C`, כבל `093A:622C`) | דוח מאפיינים מצב לקריאה בלבד 09 |
| **Attack Shark ומותגים סיניים נוספים** | מקלטי Rongyuan (81 דגמים: Attack Shark R3 ו-AJAZZ AJ179 Pro על `3151:402D`, K86, X82 PRO HE, מקלדות Ajazz, חלק מדגמי MSI ואחרים; ה-K86 דרך Bluetooth מוצג כמקלדת); מקלטי Xenta (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; ה-X6 גם ב-`1D57:FA61`, לא נבדק); מקלדות Semico 1A2C (Attack Shark X98 על דונגל `1A2C:8FFF`, נבדק, וכבל `1A2C:A034`; AJAZZ AK820 Max Plus ב-`1A2C:8FFF` / `1A2C:A036`) | דוח מצב Rongyuan; שידורים פסיביים של Xenta; שאילתת מצב Semico לקריאה בלבד `0x0E` (`AA 55 CC 33` ב-`FF02:0002`; דגל הטעינה מושמט מפני ש-X98 מדווח `state=1` הן על סוללה והן בעת טעינה) |
| **Wraith** | W1 / W1 Freestyle (מקלט `093A:522C`, כבל `093A:622C`; אותם מזהים כמו Incott, מובדלים לפי קוד הדגם) | קריאות לפי לחצן לקריאה בלבד `86` (דוח מאפיינים 09) על פני כל הלחצנים, ולאחריהן דוח הקלט הנדחף 09 |
| **Fantech** | Helios Go XD5 (חוטי `25A7:FA7B`, דונגל `25A7:FA7C`); Raigor III (נבדק), Raigor II WG10 והתקני 2.4G Mouse גנריים נוספים על דונגל `1EA7:0066` / `1EA7:0064` בשימוש חוזר | Helios Go XD5: דוח מאפיינים של היצרן `08`, פקודה `04`, סכום ביקורת המשלים ל-`0x55`. Raigor/2.4G Mouse: שאילתת דף מצב לקריאה בלבד `B5` ב-`FFB5:0001`, מקטע `94` = האחוז האחרון שדווח (עלול להיות לא מעודכן במצב שינה, כיבוי או טעינה; ללא מצב טעינה) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, מתאם אלחוטי); אוזניות INZONE H9 II ו-H5; אוזניות תוך-אוזן INZONE Buds (דונגל USB-C) | דוח קלט; פרוטוקול יצרן INZONE |
| **Fractal Design** | אוזניות Scape על דונגל ה-2.4 GHz שלהן או כבל USB-C | שאילתת יצרן `GET_DEVICE_STATE` מאפליקציית הרשת Adjust Pro של Fractal (דף שימוש FF00) |
| **Jabra** | כל אוזניית Jabra המדברת בפרוטוקול GN (Evolve2 / Evolve3 ואחרות), על כבל ה-USB שלה או מאחורי דונגל Jabra Link; ללא רשימת מזהי מוצר, בסיסי DECT (Engage, PRO 9xx, GO 6400, Link 400) אינם כלולים; השם נקרא מתוך האוזנייה | שאילתת מצב GNP (מחלקה 12 / פעולה 02) בדף שימוש FF00, שימוש 05 או 01, בכתובת GNP 08 (USB) או 04 (דונגל) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), מקלט 2.4 GHz או USB; Apex 5 (`37D7:2501`), מקלט 2.4 GHz או USB | שאילתת מידע HID של היצרן ב-`FFA0:0001`; רמת סוללה 0–5 ממופה ל-0–100% בצעדים של 20%, עם מצב טעינה; ללא צורך בשירות Space Station |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite על מקלט ה-2.4 GHz; Nova 2 Lite על USB; G7 Pro (נבדק: מהדורת Zenless Zone Zero, מקלט `3537:105E`) ובקרי GameSir אחרים במצב Xbox (GIP); Cyclone 2 (מצב XInput, מקלט או כבל); Cyclone Pro על דונגל ה-2.4 GHz שלו (`3537:1015`, יש לצמד את הבקר ל-Windows דרך Bluetooth פעם אחת) | שאילתת פרטי התקן של היצרן (דף שימוש FF7A); דוח סוללה של Windows.Gaming.Input (אחוז אמיתי) במצב Xbox; Cyclone 2: בקשת סוללה של היצרן (דף שימוש FFF0); Cyclone Pro: בקשת base-info של אפליקציית GameSir דרך Bluetooth LE (שירות `0x8650`), נקראת כל 2 דקות |
| **BEITONG** | KP20 / BTP-KP20 על מקלט ה-2.4 GHz שלו (`20BC:5128`, מצב XInput, נבדק) ו-KP40D / BTP-KP40D על המקלט שלו (`20BC:515C`, מצב XInput); אין צורך ב-BEITONG iControl | שאילתת "get base info" של היצרן בדף שימוש `00FF` (דוח `02`, מטען בערבול ניבלים), עם מצב טעינה |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` נבדק על דונגל 2.4 GHz, D-input `2DC8:6012` — החזק B בעת ההפעלה, קושחה 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | שאילתת מצב HID של היצרן (`FF7A`/`FFA0`) ודוח קלט בקר משחק SDL `01`/`04`, עם מצב טעינה |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | מסגרת מצב שהאוזניות דוחפות בשירות RFCOMM (SPP) של Samsung, לקריאה בלבד. מגש המערכת מציג את האוזנייה הנמוכה יותר; תיאור הכלי (tooltip) מפרט שמאל, ימין ומארז. אפליקציית Galaxy Buds חייבת להיות סגורה |
| **Nothing / CMF** | Nothing Ear (3a) (נבדק), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | שאילתת סוללה לקריאה בלבד `0xC007` בשירות NT Link RFCOMM של Nothing (`aeac4a03-dff5-498f-843a-34487cf133eb`). מגש המערכת מציג את האוזנייה הנמוכה יותר; תיאור הכלי מפרט שמאל, ימין ומארז |
| **Akko** | Akko Air 01 (`3151:5006`, מקלט 2.4 GHz, נבדק) ו-Akko V9 Dash Pro (`38EE:000C`, מקלט 2.4 GHz, נבדק) | Air 01: דוח מצב Rongyuan `0xF7`; V9 Dash Pro: שאילתת מצב לקריאה בלבד באורך 64 בייטים `0x1A` ב-`FF1C:0092` עם מצב טעינה |
| **MOONDROP** | אוזניות GM01 Pro על דונגל ה-2.4 GHz שלהן (`35D8:0133`); על כבל ה-USB הן מוצגות כבטעינה עם הרמה האחרונה | פקודת קריאת יצרן WalkPlay בדוח `4B` (לקריאה בלבד) |
| **VGN** | אוזניות OMNISOUND (ZHOUTING) על דונגל ה-2.4 GHz שלהן (`372E:10BB`, נבדק) | שאילתת "ZHOU" של V HUB: דוח פלט `55` עם מטען `65 01` באוסף הבקרה `000C:0001` (דוחות קלט באורך 32 בייטים, פלט באורך 64 בייטים); האחוז חוזר בתשובה (לקריאה בלבד) |
| **JBL** | Quantum 650 Wireless (נבדק, דונגל 2.4 GHz); Quantum 520, 650X, 850, 950, 950X Wireless (דונגל או כבל USB, אותו פרוטוקול, לא נבדקו) | שאילתת פרטי-התקן JBL "HIDV3" עבור תכונת הסוללה (דף שימוש FF12), עם מצב טעינה |
| **JBL** | Quantum 350 Wireless (נבדק ב-Windows עם מקלט ה-2.4 GHz `0ECB:206B`); Quantum 610 Wireless (דונגל 2.4 GHz `0ECB:205C`, לא נבדק ב-Windows); Quantum 360 Wireless (דונגל 2.4 GHz `0ECB:2115`, לא נבדק) | דוחות מאפיינים HIDV1 עבור חיבור אלחוטי ואחוז סוללה |
| **Xbox** | בקרים על מתאם Xbox Wireless, USB או Bluetooth; אוזניות המחוברות לבקר | דוח סוללה Windows.Gaming.Input (אחוז אמיתי), גיבוי XInput |
| **תואמי Switch Pro** | בקרים המזדהים כ-`057E:2009` (נבדק: GameSir Tarantula Pro דרך מקלט ה-2.4 GHz במצב Switch) | חמש רמות סוללה מתוך דוח HID `0x30` לאחר ש-Steam Input או מארח אחר מפעיל דוחות מלאים |
| **Apple AirPods / Beats** | AirPods Max (נבדק, `200A` Lightning ו-`201F` USB-C), AirPods Pro 3 (נבדק, `2027`), AirPods Pro 1 / 2, AirPods 1–5 ואוזניות קשת/תוך-אוזן של Beats | שידורי BLE "proximity pairing" (`0x07`) (סוללה יחידה עבור AirPods Max ואוזניות קשת של Beats; שמאל, ימין ומארז עבור אוזניות תוך-אוזן, בצעדים של 10% עם מצב טעינה), מותאמים לדגם המצומד |
| **טלפונים (Phone Link)** | כל טלפון Android המקושר ל-Microsoft Phone Link, דרך Wi-Fi או Bluetooth (נבדק: Nothing Phone (4a) Pro) | סוללה ומצב טעינה מתוך כרטיס תפריט ההתחלה של Phone Link ב-Windows 11 (`StartMenuCompanion.json`); ללא צורך ב-Bluetooth |
| **Darmoshark** | M3 (`248A:FF30`) ו-M3S (`248A:FF31`) על מקלטי ה-2.4 GHz שלהם ב-Windows | דוח מאפיינים HID לזיהוי עכבר ולסוללה |
| **Darmoshark** | M3S Pro על מקלט Nordic 1K (`1915:0723`) | שאילתת מצב HID של היצרן באוסף `FF0A` |
| **Alienware** | אוזניות AW920H על דונגל ה-2.4 GHz שלהן (`413C:A515`, נבדק); דרך Bluetooth הן מכוסות על ידי שורת ה-Bluetooth | שאילתת יצרן `06 C0 0A` ב-`FF13:0001`, דוח תשובה `07` עם סכום ביקורת XOR; שדות רמה, טעינה ורמה קריטית כפי שפוענחו מתוסף AW920H של Alienware Command Center |
| **Niceboy** | MW400 על מקלט ה-2.4 GHz שלו (`248A:FA02`, נבדק) | שאילתת דוח לקריאה בלבד `05` `24 FA 48`; מתח סוללה ממופה לצעדים של 10% לפי הטבלה של אפליקציית היצרן, דגל טעינה |
| **Bluetooth** | כל התקן שמציג סוללה תחת *הגדרות → Bluetooth והתקנים* (אוזניות תוך-אוזן, אוזניות קשת, עכברי ומקלדות BLE). אוזניות Google Fast Pair (נבדק: Jabra Elite 8 Active; Pixel Buds ודגמי Sony / JBL / Bose רבים) מקבלות גם רמות שמאל, ימין ומארז | מאפיין התקן של Windows; שידורי סוללה Fast Pair (נתוני שירות BLE `FE2C`), מותאמים להתקן המצומד לפי כתובת ה-Bluetooth |
| **HID גנרי** | התקנים המדווחים על שימוש ה-HID התקני *Battery Strength* | דף שימוש HID 0x06 / 0x85 |
| **HeadsetControl** | [כל אוזנייה שהוא תומך בה](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, Logitech חדשות יותר ועוד) | מצורף; מריץ `headsetcontrol -o json` |
| **MAONO PD200W** | מקלט 2.4 GHz (352F:040E) | אחוז סוללה; נבדק בחומרה |


**נבדק על חומרה אמיתית:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (מקלט PlayStation `0951:1713`; טעינה לא נבדקה), HyperX Cloud Core Wireless DTS (מקלט `0951:173F`; רמת טעינה מלאה לא נבדקה), HyperX Pulsefire Haste 2 Core Wireless (דונגל `03F0:0AB5`; דונגלי Haste 2 Wireless לא נבדקו), Cooler Master MM712 (דונגל), Rapoo VT3 Max Gen 2 (מקלט `24AE:1417` וכבל USB `24AE:4617`; דגמי Rapoo אחרים לא נבדקו, ראה [הערות פרוטוקול Rapoo](#sec-rapoo)), Redragon M916 Pro 1K (מקלט `3554:F55D`), Taidu TSG808 (מקלט `3554:F5D5`), Redragon M915RGB-WL (מקלט `25A7:FA07`; דגמי Areson אחרים לא נבדקו, ראה [הערות פרוטוקול Areson](#sec-areson)), SteelSeries Rival 650 Wireless (מקלט `1038:1726` וכבל USB `1038:172B`), SteelSeries Arctis Nova Pro Wireless (תחנת בסיס `1038:225D`; קריאת סוללה נבדקה, טעינה ומעברי הפעלה לא נבדקו), HECATE G5M PRO (מקלט `35BB:D3FB`), WLMouse YING Magnesium (מקלט 8K `36A7:A874`), ATK N9 Ultra (מקלט `373B:1204`), Corsair Scimitar Elite SE Wireless (מקלט Slipstream `1B1C:2B00`), Corsair Dark Core RGB Pro SE (מקלט Slipstream `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (מקלט 2.4 GHz `1B1C:2B2A`; קריאת סוללה אומתה), DAREU EM901X (מקלט `260D:1074`; טעינה ושינה/התעוררות לא נבדקו), Jabra Evolve3 75 על Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (מקלט `3837:4245` וכבל USB `3837:418C`), MCHOSE K7 Ultra (מקלט `3837:1001`), MCHOSE K7 V2 Ultra+ (מקלט `3837:1014` וכבל USB `3837:4028`; טעינה מוצגת בעת חיבור), MSI VERSA 300 ELITE WIRELESS (דונגל `0DB0:9E22`; טיפול בטעינה ובשינה לא נבדק), MSI Clutch GM31 Lightweight Wireless (מקלט `0DB0:0D3C`; ה-GM41 משתמש באותו דרייבר מלכידות של בעלים), AJAZZ AK820 MAX (דונגל `05AC:024F`), AULA HERO 68 Air (מקלט אלחוטי 8K `372E:106C`), AULA SC580 (כבל USB `088D:062E` ומקלט `089D:062F`, כולל טעינה ושינה), AirPods Pro 3 (Bluetooth, דגם `2027`), AirPods Max (Bluetooth, דגם `200A`), Sprime PM1 (מקלט `1915:AC1C`), Ninjutso Ten Air (מקלט `093A:EB01` וכבל USB `093A:E020`), MOONDROP GM01 Pro (דונגל `35D8:0133`), Delux M800 Pro (מקלט `248A:5B2F`), Razer Barracuda X (2022) (מקלט `1532:0550`; רמת סוללה נקראה, מעברי טעינה לא נבדקו), Razer BlackShark V3 X (דונגל HyperSpeed `1532:057D`), Fantech Helios Go XD5 (דונגל `25A7:FA7C`), Fantech Raigor III (דונגל `1EA7:0066`; טעינה אינה מדווחת על ידי הקושחה), Finalmouse UltralightX (דונגל `361D:0100`), Finalmouse Starlight X (על הדונגל שלו), ו-Chimera V2 (מקלט `3554:F512`; רמת סוללה וטעינה נקראו).
נבדק גם בחומרה: Machenike L7 Arctic / L7 Mix (מקלט `248A:FF4C` וכבל `248A:FF4E`), כולל טעינה ומניעת כפילות בין כבל למקלט. Bluetooth וגבולות סוללה חלשה/טעונה במלואה לא נבדקו בחומרה.
נבדק גם בחומרה: MCHOSE V9 Pro 2 (דונגל `3837:6011`); רמת סוללה נקראה, טעינה ושינה לא נבדקו.
נבדק גם בחומרה: EPOMAKER EA75 על מקלט ה-2.4 GHz שלו `05AC:024F`, באמצעות דרייבר ה-SONiX הקיים מתוך [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). אחוז הסוללה, חיבור מחדש למקלט והתאוששות מהדלקה אומתו. חיווי טעינה ודיווח סוללה חוטי אינם נתמכים על ידי דרייבר זה; דיווח סוללה ב-Bluetooth לא נבדק. האחוז המדווח עלול לקפוץ ל-100% בעת חיבור מתח USB, שאינו חיווי טעינה אמין.
נבדק גם בחומרה: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (מקלט `1038:1878` וכבל USB `1038:187A`), כולל טעינה, כיבוי (הרמה האחרונה נשארת, מעומעמת) ועם SteelSeries GG פועל ברקע; GG מציג רק סרגל בן שלושה שלבים, שהרמה תאמה לו.
נבדק גם בחומרה: RAWM Leviathan V4 (מקלט RAWM HS `1915:2346`; רמת סוללה נקראה, טעינה לא נבדקה).
**יושם על בסיס תיעוד פרוטוקול ופרויקטים אחרים, טרם נבדק:** כל השאר, כולל Fantech Raigor II WG10 (אותו דונגל `1EA7:0066` ואותו אוסף כמו ה-Raigor III שנבדק, כך שהוא אמור לעבוד). אם ברשותך אחד מהתקנים אלה, אנא דווח אם הוא עובד באמצעות [פתיחת Issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues).

## התקנה

[![הגרסה האחרונה](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. הורד את **`BatteryHub-Setup-<version>.exe`** מתוך [הגרסה האחרונה](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. הרץ אותו, בחר כל אחת מ-19 שפות ההתקנה הנתמכות, ולחץ "הבא". אין צורך ב**הרשאות מנהל** ו**אין צורך בהתקנת רכיבים נוספים**: ללא סביבות ריצה, ללא דרייברים וללא תוכנות יצרן. HeadsetControl מגיע מצורף, ותיקיית `lang\` הניתנת לעריכה מותקנת לצד `BatteryHub.exe`.

המתקין מוסיף קיצור דרך בתפריט ההתחלה ורשומת הסרה (*הגדרות → אפליקציות*), ויכול להפעיל את האפליקציה בעת הכניסה למערכת. מעדיף ללא מתקין? הורד את `BatteryHub-<version>-portable.zip`, חלץ אותו לכל מקום (שמור את תיקיית `lang\` לצד `BatteryHub.exe` עבור תרגומי הממשק) והפעל את `BatteryHub.exe`.

**הערות:**
- **אזהרת SmartScreen:** קובץ ה-exe אינו חתום בקוד, ולכן Windows עשוי להציג "Windows protected your PC" ("Windows הגן על המחשב שלך"). לחץ על *מידע נוסף → הפעל בכל זאת* (*More info → Run anyway*), או בנה אותו בעצמך.
- **מצב סמלי מגש המערכת ב-Windows 11:** סמלים חדשים במגש המערכת עוברים לתפריט הגלישה `^`. גרור אותם לשורת המשימות או הפעל אותם תחת *הגדרות → התאמה אישית → שורת המשימות → סמלים אחרים של מגש המערכת*.
- **הרחקת האפליקציה מהתקן מסוים:** אם התקן מתנהג בצורה לא תקינה בזמן שהאפליקציה פועלת, רשום אותו במחרוזת הרישום `IgnoreDevices` תחת `HKCU\Software\WirelessBattery` כזוגות `VID:PID` (בהקסדצימלי, מופרדים בפסיקים, למשל `28BD:0947, 1234:ABCD`; הפקודה `--dump` מציגה את המזהים). האפליקציה לעולם לא תפתח אותו. לוחות ציור (drawing tablets) מדולגים אוטומטית.

## עדכונים ב-Windows

גרסאות בנייה יציבות רשמיות של Windows בודקות ברקע את הגרסה היציבה האחרונה שפורסמה בפרויקט, 30 שניות לאחר ההפעלה ולאחר מכן כל 24 שעות בזמן שהאפליקציה פועלת. פתח את התפריט כדי לראות **עדכון זמין: vX.Y.Z...**, או בחר **בדוק עדכונים...** בעצמך. מידע על עדכונים מופיע רק בתפריט זה: סמלי הסוללה, האחוזים ותיאורי הכלים נשארים ללא שינוי, ובדיקות אוטומטיות לעולם אינן מציגות התראה או תיבת דו-שיח. כבה את **בדוק עדכונים אוטומטית** בתפריט כדי להשבית בדיקות רקע.

עבור עותק מותקן, לחץ על רשומת העדכון ועל **הורד והתקן**. דבר אינו מותקן ללא לחיצה זו. האפליקציה מורידה את קובץ `SHA256SUMS.txt` של הגרסה ואת חתימתו, מאמתת את החתימה מול המפתח הציבורי של המתחזק המובנה באפליקציה, מורידה את מתקין ה-Windows ומריצה אותו רק אם גיבוב ה-SHA-256 שלו תואם לזה שברשימה החתומה (ולזה ש-GitHub מציג עבורו). לאחר מכן היא מעדכנת את ההתקנה הקיימת. ההגדרות והעדפת ההפעלה האוטומטית נשמרות, והאפליקציה נפתחת מחדש לאחר ההתקנה. התקנה עבור כל המשתמשים עשויה לבקש הרשאת מנהל. **הערות גרסה** פותח את דף הגרסאות הרשמי; **מאוחר יותר** שומר על הגרסה הנוכחית שלך. עותקים ניידים מציעים קישור לדף הגרסאות להורדה ידנית של קובץ ה-ZIP.

הבדיקות פונות ל-API הציבורי של GitHub ללא חשבון וללא אסימון (token). לא נשלח שום מידע על התקנים או על סוללה. כשלי חיבור לא מקוונים ומגבלות קצב של GitHub משאירים את ניטור הסוללה פעיל; גרסה שנמצאה קודם לכן נשארת בתפריט עד שבדיקה מוצלחת תחליף אותה או עד שתותקן. ביטול הורדה ממתין לסיום פעולת הרשת הנוכחית תוך הזמן הקצוב הסופי שלה. המתקין לעולם אינו מפעיל מחדש את Windows אוטומטית.

**מדוע עדכונים בטוחים להתקנה:** מפתח החתימה לעולם אינו מגיע ל-GitHub. המתחזק חותם על רשימת סכומי הביקורת של כל גרסה במחשב האישי שלו (ראה [docs/releasing.md](#sec-releasing)), כך שגם מי שהיה משתלט על חשבון ה-GitHub או על תהליך הבנייה שלו לא היה יכול לפרסם עדכון שהאפליקציה תתקין. גרסה ללא חתימה תקפה מוצגת בתפריט אך ניתנת להורדה ידנית בלבד. החתימה אינה מחליפה את בקשות SmartScreen או UAC של Windows עצמה.

התקן ידנית פעם אחת את הגרסה הראשונה הכוללת תכונה זו. גרסאות פיתוח/בדיקה משביתות בדיקות עדכון רשמיות כדי שלא יהיה ניתן להחליף שינויים מקומיים בטעות. עדכונים ל-Linux והחלפה אוטומטית של עותקים ניידים נדחו לשלב מאוחר יותר.

## שורת הפקודה

```
BatteryHub.exe --list     # print every device and its battery level, then exit
BatteryHub.exe --json     # print a JSON array of devices and battery levels, then exit
BatteryHub.exe --dump     # every HID collection, HID devices that could not be opened, all USB devices (also ones
                               # without a HID interface) and Bluetooth devices; also saved to %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # open the "Request support for a device" window
BatteryHub.exe --demo     # sample devices of every brand instead of real ones (screenshots, checking colors)
BatteryHub.exe --quit     # close the running instance
```

גרסת ה-Linux משתמשת באותם דגלים עם `wireless-battery` במקום `BatteryHub.exe`, ומקבלת גם `--help`. הדגל `--json` מדפיס מערך יציב שסקריפטים ווידג'טים של שורת מצב יכולים לפענח:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` מציין כמה זמן האפליקציה ממשיכה להציג את הרמה האחרונה הידועה בזמן שההתקן במצב שינה. הוספת שדות חדשים היא תואמת לאחור.

**ההתקן לא מופיע?** לחץ לחיצה ימנית על הווידג'ט או על סמל מגש המערכת ובחר **בקשת תמיכה בהתקן...**. בחר את ההתקן, בדוק מה יישלח (התוכן מוצג מילה במילה: שם ההתקן, סוגו, מזהי ה-USB/HID ופריסת הממשקים שלו, והשם וההערות האופציונליים שלך) ולחץ על **שלח**. הבקשה תתווסף לרשימה הציבורית ב-[krisgfx.com/tools](https://krisgfx.com/tools/#requested) ותפתח או תעדכן GitHub Issue. **העתק דוח מלא** מעתיק את פלט ה-`--dump` המלא ללוח עבור ה-Issue. נתוני הדיווח נשלחים רק כאשר אתה לוחץ על שלח. גרסאות בנייה רשמיות של Windows עשויות גם לפנות ל-GitHub כדי לבדוק עדכונים, כמתואר תחת [עדכונים ב-Windows](#עדכונים-ב-windows); בדיקות עדכונים אינן שולחות מידע על התקנים או על סוללות.

## בנייה

דרוש [MinGW-w64](https://www.mingw-w64.org/), למשל דרך [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # development build, version 0.0.0
build.bat                                 # plain cmd with g++ and windres on PATH
make VERSION=1.2.3 CHANNEL=test            # versioned build, official updates disabled
build.bat 1.2.3 test                       # equivalent versioned cmd build
make test VERSION=1.2.3 CHANNEL=test       # device and updater regression tests
```

כדי לבנות את המתקין ואת קובץ ה-ZIP הנייד, התקן את [Inno Setup](https://jrsoftware.org/isinfo.php), בנה תחילה עם הגרסה המיועדת (לדוגמה `make VERSION=1.2.3 CHANNEL=test`), ולאחר מכן הרץ `powershell -File installer\build-installer.ps1 -Version 1.2.3`. תהליך האריזה דוחה גרסה השונה מזו של קובץ ההפעלה. הוא מוריד את גרסת HeadsetControl המקובעת ומאמת את סכום הביקורת שלה. GitHub Actions מבצע את כל זה אוטומטית: דחיפת תגית כמו `v1.0.0` מפרסמת גרסה עם המתקין, ה-ZIP הנייד וקוד המקור של HeadsetControl (כפי שדורש רישיון ה-GPL שלו).

בניות ב-Windows דורשות גם PowerShell לצורך יצירת גרסת קובץ ההפעלה והמשאבים המשותפת. תגיות גרסה של המאגר הרשמי נבנות עם `CHANNEL=stable`; בניות מקומיות משתמשות כברירת מחדל ב-`dev`. פיצולים (Forks) ו-Pull Requests אינם מפעילים עדכונים רשמיים אוטומטית.

`BatteryHub.exe` עובד גם בפני עצמו. ללא `headsetcontrol.exe` לצדו (או ב-`PATH`), פשוט תאבד את התמיכה באוזניות הנוספות.

## Linux (ניסיוני)

בנייה ל-Linux קיימת לצד אפליקציית ה-Windows. היא משתמשת באותם דרייברי יצרן עם מנגנון HID מבוסס hidraw וסמל מגש GTK4 מסוג StatusNotifierItem; נתיב הקוד של Windows נותר ללא שינוי. כל הקבצים הייעודיים ל-Linux נמצאים ב-`linux/` וב-`src/linux/`, ו-`build-linux.sh` בונה אותה (Windows ממשיך להשתמש ב-`build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| מהדר ו-make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

אין צורך בספריית HID נוספת (נעשה שימוש ישיר ב-hidraw).

```sh
./build-linux.sh
./build-linux.sh test         # unit test for the HID report-descriptor parser
./wireless-battery --list     # print detected levels and exit
./wireless-battery --dump     # list HID collections
./wireless-battery --quit     # close the running tray instance
```

גישה ל-HID דורשת כלל udev, אחרת האפליקציה עולה אך אינה מוצאת התקנים:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# log out and back in
```

סמל מגש המערכת עובד באופן מקורי ב-KDE Plasma; סביבת GNOME דורשת מארח AppIndicator כגון `gnome-shell-extension-appindicator`. החלפת ריבוי שפות פועלת דרך תת-התפריט *שפה* (עוקב אחר `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` כברירת מחדל, וממקם גם את `--help`). הרצת `make -f linux/Makefile.linux install` מתקינה את הקובץ הבינארי, את `lang/*.json` לתוך `$(PREFIX)/share/wireless-battery/lang/`, ואת מפעיל שולחן העבודה (`linux/wireless-battery.desktop`) יחד עם `linux/wireless-battery.svg` לתוך `$(PREFIX)` (ברירת המחדל היא `~/.local`); דריסות שפה של המשתמש נשמרות ב-`~/.config/wireless-battery/lang/`.

שלב 1 מכסה את Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious, Finalmouse ואת הפרוטוקולים המשותפים של Kysona/Pulsar/ATK/G-Wolves. גיבויי Bluetooth/UPower, HeadsetControl ושאר היצרנים מתוכננים לשלבי המשך.

## מגבלות

- **שורות משימות עמוסות:** בשורת משימות ממורכזת ועמוסה מאוד ב-Windows 11, לחצני האפליקציות עלולים להגיע אל הווידג'ט. ב-Windows 10 אזור לחצני המשימות מוצר אוטומטית.
- **טלפונים:** נקרא מקובץ ש-Phone Link כותב עבור כרטיס הליווי בתפריט ההתחלה, שאינו API מתועד ועשוי להשתנות בעדכוני Phone Link. הטלפון מוצג בזמן ש-Phone Link מדווח שהוא מחובר; כרטיס שגילו מעל 3 שעות מוצג מעומעם. הכרטיס גם מציין מתי הטלפון בטעינה, דבר המוצג כברק טעינה.
- **התקנים במצב שינה:** התקן הנמצא במצב שינה עלול שלא לענות. הערך האחרון שלו נשאר גלוי, מעומעם. מקלטי Logitech מסירים התקנים ישנים מהקישור, ולכן הערך האחרון שלהם נשמר למשך 30 דקות.
- **אוזניות HECATE G2 Wireless 7.1** (דונגל 2.4 GHz `35BB:A009` / `A209`): טרם תועדה שאילתת סוללה עבור הדונגל שלהן, ולכן היא אינה נקראת. לכידת USB בזמן שתוכנת HECATE מציגה את סוללת האוזניות (ראה CONTRIBUTING.md) היא הדרך להוסיף אותה.
- **מקלדות Keychron:** עם קושחת המקור הן מדווחות את הסוללה רק דרך Bluetooth (מוצג דרך תמיכת ה-Bluetooth). דרך מקלט ה-2.4 GHz או הכבל הן זקוקות לקושחה עם תיקון הסוללה ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); עדכון המקלדת מתוך Keychron Launcher מסיר אותו. עכברי Keychron נתמכים.
- **אוזניות Baseus AeQur GH02:** דונגל ה-2.4 GHz (`10D6:4802`, שבב Actions) מעביר רק שמע, מקשי מדיה ואת ערוץ עדכון הקושחה של השבב, ללא הסוללה. חבר את האוזניות דרך Bluetooth כדי לראות את הרמה שלהן (מוצג דרך תמיכת ה-Bluetooth כאשר Windows מדווח עליה).
- **מקלדת Weikav Lucky65 v1:** הקושחה אינה מדווחת את הסוללה שלה דרך דונגל ה-2.4 GHz (`0603:0351`, שבב Novatek). למקלדת אין קיצור מקשים לבדיקת סוללה, ותוכנת ההגדרה הרשמית מתחברת רק דרך כבל ה-USB ולא דרך הדונגל, כך שאין קריאת סוללה להצגה.
- **Rapoo:** עכברי VT נתמכים דוחפים את מצבם באופן פסיבי, ולכן רענון עשוי להמתין עד 4 שניות לכל ממשק תואם. עכברים ישנים עשויים להישאר מעומעמים עם הקריאה האחרונה שלהם עד 30 דקות. התמיכה היא עבור דוח Nordic 54L `07` ו-`BB` ישן (VT3 Pro, VT1 Pro Max); דוח CH584 `08`, עכברי משרד מסדרות MT/M ופרוטוקולי קושחה אחרים אינם מכוסים על ידי דרייבר זה.
- **GameSir Cyclone Pro:** הדונגל אינו מעביר רמת סוללה, ולכן היא נקראת מהבקר דרך Bluetooth LE. צמד את הבקר ל-Windows פעם אחת (הגדרות > Bluetooth והתקנים > הוסף התקן > Bluetooth > `GameSir-Cyclone Pro`), והמשך לשחק דרך הדונגל. המחשב זקוק ל-Bluetooth. הרמה מתרעננת כל 2 דקות, ואין אחוזים בזמן טעינה. ללא צימוד, הדונגל מוצג כבקר Xbox במצב "מלאה". פרטים נוספים ב-[docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM:** העכבר מתושאל דרך המקלט שלו, כך שעכבר במצב שינה אינו עונה; הוא נשאר מעומעם עם הקריאה האחרונה שלו למשך עד 30 דקות ומוסיף כשנייה לרענון בזמן שהוא ישן. רק ה-Leviathan V4 על מקלט ה-RAWM HS (`1915:2346`) נבדק; שאר הדגמים נלקחו מטבלת ההתקנים של RAWM HUB. דגמי Leviathan V4 GT ו-NYX60 (VID `373E`, RAWM HUB 3.0) ומקלדות RAWM HS משתמשים בפרוטוקולים אחרים ואינם מכוסים.
- **Flydigi:** דרייבר זה מכוון ל-Vader 5 Pro ול-Apex 5; Bluetooth ודגמי Flydigi אחרים (למשל Apex 6) אינם מכוסים. האחוזים מייצגים רמות סוללה גסות. Apex 5 נבדק על חומרה אמיתית דרך מקלט ה-2.4 GHz וכבל USB; Vader 5 Pro מבוסס על SDL ועל עקבות חומרה מ-Windows.
- **טרם נתמכים:** עכברי MSI אלחוטיים מלבד VERSA 300 ELITE ו-CLUTCH GM31 / GM41, מקלדות MSI אלחוטיות, אוזניות Razer Kraken ודגמי Barracuda מלבד Barracuda X (2022) ב-`1532:0550`, עכברי HyperX Pulsefire מלבד Haste 2 Wireless / Haste 2 Core Wireless, ואוזניות Xbox Wireless על מתאם ה-Xbox: פרוטוקולי הסוללה שלהם אינם מתועדים. אוזניות Xbox Wireless עובדות דרך Bluetooth. לכידת USB מבעלים (ראה CONTRIBUTING.md) היא הדרך להוסיף אותם.
- **התקנים אחרים:** חלק מהתקני 2.4 GHz משתמשים בפרוטוקולים לא מתועדים וטרם נתמכים. ראה [CONTRIBUTING.md](#sec-contributing) כדי ללמוד איך לעזור להוסיף התקן.

## איך זה עובד

כל דרייבר יצרן ב-[`src/drivers/`](../../src/drivers) מזהה את ההתקנים שלו לפי מזהה ספק ומוצר USB (VID/PID), ושולח אך ורק שאילתות סוללה לקריאה בלבד. התקנים לא מוכרים אינם נכתבים לעולם. מנגנוני הגיבוי הגנריים (שימוש סוללת HID, Bluetooth, XInput, HeadsetControl) בוחנים רק התקנים שאף דרייבר יצרן לא תבע.

ווידג'ט שורת המשימות הוא חלון בן מרובד (layered child window) של `Shell_TrayWnd`, הממוקם משמאל ל-`TrayNotifyWnd`. אם Explorer מופעל מחדש, הוא נוצר מחדש.

## תרגומים

כל שפת ממשק היא קובץ טקסט סטטי רגיל בקידוד UTF-8 בתוך [`lang/`](../../lang): אנגלית משמאל, התרגום מימין. קובצי השפה נטענים מהדיסק בזמן ריצה ולא מהודרים לתוך קובץ ההפעלה, כך שניתן לערוך אותם ישירות ללא בנייה מחדש.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **ממשק האפליקציה (Windows ו-Linux):**
  - ערוך או הוסף קובצי `.json` ישירות בתוך תיקיית `lang/` שלצד `BatteryHub.exe` (או `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/`, או `./lang/` ב-Linux).
  - או בחר *שפה → הוסף שפה משלך...* בתפריט כדי להכין את תיקיית הדריסה של המשתמש (`%APPDATA%\WirelessBattery\lang` ב-Windows, `~/.config/wireless-battery/lang` ב-Linux) עם `_template.json`. העתק את `_template.json` למשל אל `it.json`, מלא את `@code`, `@name` ואת התרגומים, והשפה תופיע בתפריט (אין צורך בהפעלה מחדש). קבצים בתיקיית המשתמש דורסים מחרוזות מובנות עם אותו `@code`.
  - השאר `{placeholders}` כמות שהם, והוסף `"@rtl": true` עבור כתבים מימין לשמאל. מחרוזות שנשארו ריקות נשארות באנגלית, כך שגם תרגום חלקי עובד היטב.
  - פלט `--list` ו-`--dump` נשאר באנגלית בכוונה: הוא מודבק לתוך GitHub Issues.
- **מתקין Windows:** תרגומי Inno Setup נמצאים ב-[`installer/lang/`](../../installer/lang) (נשמרים כ-UTF-8 עם BOM) ונרשמים תחת `[Languages]` בקובץ `installer/BatteryHub.iss`.
- **תיעוד:** כל מסמך גלוי בפרויקט מתורגם כקובץ Markdown עצמאי יחיד לכל שפה ב-[`docs/i18n/`](README.md) (ראה [`docs/i18n/_template.md`](_template.md) להוספת שפה חדשה ללא צורך בסקריפטי בנייה).
- **שתף עם כולם:** שלח Pull Request המוסיף את הקבצים שלך ב-`lang/`, `installer/lang/`, `linux/wireless-battery.desktop` ו-`docs/i18n/`. ראה [`docs/i18n/README.md`](README.md) לרשימת הבדיקה שלב אחר שלב.

## קרדיטים

סמל האפליקציה נוצר על ידי [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

הפרוטוקולים מבוססים על המחקר של הפרויקטים הבאים:

- [מפרט Google Fast Pair](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): שידורי סוללה של שמאל / ימין / מארז באוזניות Fast Pair
- [דרייברי Astro של HeadsetControl](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty), ו-[AstroBar](https://github.com/nichtlegacy/AstroBar): פרוטוקולי סוללה של Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): קריאת מצב `0x72` של A50 Gen 3

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): פקודות סוללה וטעינה של VAXEE ([תיעוד פרוטוקול](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): אוזניות SteelSeries, Corsair, HyperX, Logitech ו-Sony INZONE
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) ו-[inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) ומסמכי Logitech HID++ 2.0: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) ו-[logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (דונגל `0ADF`)
- [rivalcfg](https://github.com/flozz/rivalcfg): עכברי SteelSeries (Rival Pro מתוך pull request #294 שלו)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) ו-[glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- תוכנת ההגדרה ברשת של Hitscan ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- `hid-kysona` ב-Linux (Lode Willems): Kysona, Pulsar ו-ATK
- תוכנת ההגדרה ברשת של ATK ([hub.atk.pro](https://hub.atk.pro)): עכברי ATK ואוזניות N9 Pro / N9 Ultra
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 ו-[mouse-battery](https://github.com/qwr79/mouse-battery): דונגל ATK / VXE NK NANO
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X ו-Endgame Gear XM2we, שהוסבו מספקי הפרוטוקול שלו (כל דרייבר מציין את מקורו)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` ו-[halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (ממצאים בלבד): משפחת התקני Turtle Beach Swarm II
- דרייבר הרשת של G-Wolves ([mouse.xyz](https://mouse.xyz)): דגמי G-Wolves והפרוטוקולים שלהם
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): מקלדות CHERRY על דונגל ה-2.4 GHz (מבנה המסגרת ושאילתת הסוללה)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): עכברי Keychron
- [NinjaForce](https://www.ninjaforce.co/) ו-[ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): שאילתות מאפיינים של Ninjutso Ten / Ten Air
- [nape_pro](https://github.com/nvalis/nape_pro) ו-[KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro על מקלט Link-KM
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): עכברי LAMZU
- [vole](https://github.com/johanneszab/vole) ו-[Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): עכברי Endgame Gear 4K
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) ו-[HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) ו-[FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (מתוך xpanel של Finalmouse)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) ו-[g49-web-control](https://github.com/pingpingjinping/g49-web-control): מזהי Redragon
- [m913-ctl](https://github.com/Qehbr/m913-ctl) ו-[redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): מבנה מסגרת Areson `25A7` ופקודת `GetPower`
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) ו-[zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW ו-DW
- דרייבר הרשת של RK ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) ו-[OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (תיעוד): MCHOSE A5 Pro / A5 Pro Max (דור ראשון, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): דוחות מקלט CompX עבור Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) ו-[AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) ו-[MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- דרייבר הרשת של Wraith ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 ו-[omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 ו-[HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) ו-[barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) על מקלט `1532:0550`; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): מסגור של מקלט `1532:0552`
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): מקלטי Rongyuan ו-Xenta (Attack Shark ואחרים)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): מקלדות SONiX על דונגל ה-2.4G שלהן (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) ו-[ak820-studio](https://github.com/usharik/ak820-studio): מקלט AJAZZ AK820 Pro `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) ו-[Kraber](https://github.com/AkashPanja/Kraber): פרוטוקול מצב Semico `1A2C` (`AA 55 CC 33` / `0x0E`) עבור Attack Shark X98 ו-AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) ו-[MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 ו-MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) ו-[Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): בקשת הסוללה "base info" של GameSir Cyclone Pro ב-Bluetooth LE
- [jabridge](https://github.com/Watchdog0x/jabridge): פרוטוקול Jabra GNP (דונגלי Link 380 / 390)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): פרוטוקול דף-מצב `1EA7:0066` (Fantech Raigor III והתקני 2.4G Mouse גנריים נוספים)
- Linux `hid-playstation`: מבנה דוח DualShock 4 / DualSense
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): פרוטוקול יצרן AULA SC580 / SC580X
- אפליקציית הרשת RAWM HUB ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) וטבלת ההתקנים שלה: עכברי RAWM ו-SADES Dagger
- [דרייבר Flydigi HID של SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) ו-[HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): מסגור השאילתה ומבנה הסוללה של Vader 5 Pro ו-Apex 5
- [דרייבר 8BitDo HID של SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): בייט הסוללה של 8BitDo Ultimate 2
- BEITONG iControl (דפי ה-KP20 וה-KP40D שלו ותעבורת ה-USB של מקלט KP20): שאילתת סוללה וערבול מטען של BEITONG KP20 / KP40D
- [דרייבר 8BitDo HID של SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) ו-[8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): בייט הסוללה של 8BitDo ופרוטוקול יצרן HID
- JBL QuantumENGINE (הודעות פרטי-ההתקן HIDV3 שלו): אוזניות JBL Quantum
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, פרוטוקול Compx ב-`FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) ו-[BrimDeck](https://github.com/MoFeng2223/BrimDeck): קריאת פרופיל Scyrox V12M
- JBL QuantumENGINE: דוחות חיבור וסוללה HIDV1 עבור Quantum 350, והודעות פרטי-התקן HIDV3 עבור אוזניות Quantum חדשות יותר
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): דוחות סוללה וקישור HIDV1 של JBL Quantum 610, וליין Quantum (360 כדגם דונגל HIDV1)

## רישיון

[GNU General Public License v3.0 ומעלה](../../LICENSE). באפשרותך להשתמש בתוכנה זו, לשנותה ולהפיצה מחדש, אך כל דבר שתפיץ המבוסס עליה חייב להשתחרר תחת אותו רישיון, יחד עם קוד המקור שלו.


---

<a id="sec-contributing"></a>
> 📄 **מדור:** מדריך לתורמים (`CONTRIBUTING.md`) · [מקור באנגלית](../../CONTRIBUTING.md) · [↑ לראש הדף](#top)

# תרומה לפרויקט

## דיווח האם התקן עובד

רוב הדרייברים נכתבו מתוך תיעוד פרוטוקול ולא ניתן היה לבדוק אותם על כל דגם.
אנא פתח Issue עם:

- שם ההתקן, והאם הוא מחובר באמצעות מקלט, כבל או Bluetooth
- הפלט של `BatteryHub.exe --list`
- הפלט של `BatteryHub.exe --dump`
- מה מציגה תוכנת היצרן עצמה כרמת הסוללה

## הוספת התקן

1. הרץ `BatteryHub.exe --dump` ומצא את מזהי הספק והמוצר (VID/PID) של ההתקן שלך, ואת האוספים המוגדרים על ידי היצרן (דף שימוש `FFxx`) עם אורכי הדוחות שלהם.
2. מצא את פרוטוקול הסוללה. מקומות טובים לחפש בהם: HeadsetControl, OpenRazer, Solaar, rivalcfg, OpenRGB, OpenLinkHub, או לכידת USB של תוכנת היצרן (Wireshark + USBPcap).
3. אם ליצרן כבר יש דרייבר ב-`src/drivers/`, הוסף שם את מזהה המוצר (ואת כל ההבדלים). אחרת צור את `src/drivers/<vendor>.cpp`:

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

4. הצהר על הפונקציה ב-`src/drivers/drivers.h`, וקרא לה מתוך `PollAllDevices()` בקובץ `src/devices.cpp` (לפני מנגנוני הגיבוי הגנריים). `build.bat` וה-Makefile מזהים קבצים חדשים אוטומטית.
5. עדכן את טבלת ההתקנים ב-`README.md`.

### כללים לדרייברים

- **לקריאה בלבד:** שלח רק בקשות שקוראות מצב. לעולם אל תשנה הגדרות, תאורה או מצבים.
- **התאמה מדויקת:** תקשר רק עם התקנים שאתה מזהה לפי מזהה ספק ומוצר (VID/PID), או לפי אוסף ייעודי ליצרן הייחודי לפרוטוקול.
- **תמיד עם פסק זמן (timeout):** התקן חסר אסור שיעכב את הדגימה ליותר מכשנייה אחת. פרוטוקולים פסיביים עשויים להזדקק לזמן ארוך יותר כדי לכסות מרווח דחיפה מתועד (לדוגמה, Delux ו-Rapoo). שמור על מועד סופי מוחלט יחיד של לכל היותר 4 שניות לכל אוסף תואם, אל תאתחל אותו עבור דוחות לא קשורים, ותעד מדוע נדרש החריג.
- **מתן קרדיט למקורות:** ציין מאיפה מגיע הפרוטוקול בהערה בראש הקובץ.

## תרגומים

שפות הממשק הן קובצי טקסט סטטיים רגילים בקידוד UTF-8 בתיקיית `lang/`, הנטענים מהדיסק בזמן ריצה הן ב-Windows והן ב-Linux (העתק את `lang/_template.json` אל `lang/<code>.json`, מלא את `@code`, `@name` ואת המחרוזות — אין צורך בבנייה מחדש). טקסט ממשק חדש בקוד עובר דרך `T(L"...")`, או `TF(L"... {name} ...", { { L"name", value } })` כשהוא מכיל ערכים; לעולם אל תרכיב משפטים מתורגמים מחלקים. לאחר הוספת מחרוזות, הוסף אותן גם ל-`lang/_template.json`.

תרגומי מתקין ה-Windows נמצאים ב-`installer/lang/*.isl` (נשמרים כ-UTF-8 עם BOM ונרשמים ב-`installer/BatteryHub.iss`), הערות מפעיל שולחן העבודה של Linux נמצאות ב-`linux/wireless-battery.desktop`, ותרגומי תיעוד מלאים נמצאים ב-`docs/i18n/<code>.md` (קובץ עצמאי יחיד שהועתק מ-`docs/i18n/_template.md`). ראה [`docs/i18n/README.md`](README.md) למדריך המלא לתורמים.

## סגנון קוד

C++17, Win32 בלבד, ללא תלויות צד שלישי. שמור על קובץ בינארי קטן. עצב בערך כפי שעושה הקוד הקיים (הזחה של 4 רווחים, שורות ברוחב 120 תווים).

## פיתוח המעדכן ל-Windows

המעדכן מיועד ל-Windows בלבד ומשתמש ב-WinHTTP, ב-BCrypt ובמתקין Inno Setup הקיים. שמור על מצב העדכון בתפריט בלבד. אל תוסיף סמלי עדכון, תגים, שינויים בתיאור הכלי של הסוללה, בלונים, הודעות toast או תיבות דו-שיח אוטומטיות. דגימת ההתקנים רצה בנפרד מעבודת הרשת.

גרסת הבנייה והערוץ משותפים בין C++ למשאב ה-Windows באמצעות הקובץ שנוצר `build/version.h`. השתמש ב-`make VERSION=1.2.3 CHANNEL=test` או ב-`build.bat 1.2.3 test` לבדיקות מקומיות; `dev` הוא ברירת המחדל ו-`stable` מאפשר בדיקות שחרור רשמיות. רכיבי הגרסה חייבים להיכנס בטווח `0..65535`. רק זרימת העבודה של תגית השחרור במאגר הרשמי בוחרת ב-`stable` אוטומטית. אל תהפוך בניית מזלג (fork) לערוץ עדכון רשמי בטעות.

הרץ `make test VERSION=1.2.3 CHANNEL=test` לבדיקות ההתקנים הקיימות בתוספת פיענוח גרסאות קפדני, סדר גרסאות, תזמון בדיקות, בדיקות SHA-256 אמיתיות לקבצים, ציטוט ארגומנטים והגנות מסייע. בדיקות הרגרסיה של המעדכן מכסות גם ביטול בעת השלמת הורדה, הגנות דו-שיח וכשל בהגדרת פסקי זמן/הגבלות הפניה של HTTP. בדיקת ה-Windows כוללת את המימושים, לפי תבנית בדיקת הקצה העורפי של Linux הקיימת, ומחליפה את שליחת ה-HTTP כך שבדיקות אלו לא יוכלו ליצור קשר עם GitHub. לא נוספות לייצור נקודות כניסה של בקר המיועדות לבדיקה בלבד. יעדים פרטניים הם `make test-update-core` ו-`make test-update-win`. בדיקות מעדכן מקומיות מקשרות את משאב היישום כדי להפעיל את Common Controls v6. הבדיקות משתמשות בנתונים מקומיים ואינן מורידות, מעלות הרשאות, מתקינות או משנות את הגדרות ההפעלה של המשתמש. לא ניתן לעקוף את נקודת הקצה הייצורית של היישום עבור בדיקות.

לפני האריזה, הרץ `powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`. גם `installer/build-installer.ps1 -Version 1.2.3` מריץ בדיקה זו לפני הורדת תלויות. נתיב המתקין `/WBUPDATE=1` שומר על ההפעלה וההגדרות הקיימות ומשאיר את ההפעלה מחדש למסייע הזמני. מסייע זה נשאר תחת המשתמש המקורי, ומעלה הרשאות רק עבור התקנה גלובלית. ידיות (handles) של WinHTTP שייכות לתהליכון העובד (worker); הביטול שיתופי בין קריאות עם פסק זמן סופי. כיבוי סופי של האפליקציה ממתין לתהליכון העובד (join) ולכן עלול להמתין לפסק זמן רשת שכבר נמצא בביצוע.

עבור סקירת שחרור, השתמש בחשבון Windows חד-פעמי או במכונה וירטואלית כדי לבדוק שתי גרסאות מתקין אמיתיות, היקף משתמש-יחיד/גלובלי, ביטול UAC, הפעלה באתחול פעילה/כבויה, נתיבים מותאמים אישית, כשל התקנה והפעלה מחדש. בדיקות יחידה והידור חבילה אינם מאמתים את השפעות המתקין הללו. סקירה חזותית של תפריטים/ערכות נושא ובדיקות מקצה לקצה אמיתיות של מתקין/UAC נותרות שערי שחרור ידניים; אל תסמן אותן כעוברות אלא אם נצפו בפועל. לעולם אל תבדוק על ידי דריסת ההתקנה היומיומית של המשתמש.

## בדיקת בטיחות אוטומטית

כל Pull Request נסרק על ידי "PR safety check" לחיפוש דברים שאסור לאפליקציה זו לעשות לעולם (גישה לרשת, הפעלת תוכניות, קריאת מקלדת/לוח/מסך, רשומות הפעלה אוטומטית, קבצים בינאריים, שינויי בנייה או שחרור). סימון דגל אינו דחייה: פשוט הסבר את השורות המסומנות בתיאור ה-PR.

שימוש בכלי AI הוא בסדר גמור, אך אנא הסר שורות `Co-authored-by` הנותנות להם קרדיט (לדוגמה `Co-authored-by: Claude ...`) מהודעות ה-commit שלך. הבדיקה נכשלת כל עוד הן קיימות.


---

<a id="sec-pr-template"></a>
> 📄 **מדור:** תבנית Pull Request (`.github/pull_request_template.md`) · [מקור באנגלית](../../.github/pull_request_template.md) · [↑ לראש הדף](#top)

## מה שינוי זה מוסיף

<!-- התקן/ים ומזהי ספק/מוצר, למשל "Acme M1 (1234:5678)". -->

## מאיפה מגיע הפרוטוקול

<!-- קשר אל המקור (פרויקט אחר, דרייבר רשת של היצרן, לכידת USB שלך). -->

## נבדק על חומרה אמיתית?

<!-- כן (איזה התקן, מה הדפיסה --list) / לא -->

## רשימת בדיקה

- [ ] נשלחות רק שאילתות סוללה לקריאה בלבד; שום הגדרות, תאורה או קושחה אינן משתנות
- [ ] נוגעים רק בהתקנים המזוהים לפי מזהה ספק/מוצר (או אוסף ייחודי לפרוטוקול)
- [ ] ללא גישה לרשת, ללא הפעלת תוכניות אחרות, ללא קבצים חדשים מחוץ ל-`src/`, `docs/` או `README.md`
- [ ] ללא קבצים בינאריים או קבצים שנוצרו אוטומטית
- [ ] ללא שורות `Co-authored-by` המזכות כלי AI (Claude, Copilot, ChatGPT ...) בהודעות ה-commit
- [ ] שינויים ב-`.github/`, `installer/`, `build.bat` או `Makefile` מוסברים למעלה


---

<a id="sec-releasing"></a>
> 📄 **מדור:** שחרור גרסאות (`docs/releasing.md`) · [מקור באנגלית](../../docs/releasing.md) · [↑ לראש הדף](#top)

# שחרור גרסאות

האפליקציה מעדכנת את עצמה מתוך גרסאות GitHub, אך היא מתקינה רק מתקין שה-SHA-256 שלו מופיע בקובץ `SHA256SUMS.txt` החתום במפתח השחרור. מפתח זה שמור במחשב של המתחזק, ולעולם אינו נמצא ב-GitHub: חשבון פרוץ, אסימון או תהליך עבודה יכולים לפרסם קבצים, אך לא חתימה שהאפליקציה מקבלת.

## חד-פעמי: יצירת מפתח השחרור

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- מבקש סיסמה (12+ תווים) וכותב את המפתח הפרטי המוצפן אל `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- מציב את המפתח הציבורי בתוך `src\update_public_key.h`. בצע commit לקובץ זה. גרסאות בנייה רשמיות מסרבות להדר ללא מפתח בתוכו.
- **גבה את קובץ המפתח ושמור על הסיסמה** (מנהל סיסמאות הוא מקום טוב לשניהם). אם אחד מהם יאבד, האפליקציות המותקנות לא יוכלו עוד לעדכן את עצמן: תצטרך ליצור מפתח חדש וכל משתמש יצטרך להתקין גרסה אחת ידנית.

## בכל שחרור

1. דחוף תגית גרסה (`git tag v1.2.3 && git push origin v1.2.3`). CI בונה את המתקין, את ה-ZIP הנייד ואת `SHA256SUMS.txt`, ומפרסם את הגרסה.
2. חתום על רשימת סכומי הביקורת:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   הסקריפט מוריד את `SHA256SUMS.txt` מהגרסה, מציג אותו, מבקש ממך לאשר, מבקש את סיסמת המפתח וכותב את `SHA256SUMS.txt.sig`. אם יש לך את אותם קבצים ב-`dist\` (בנייה מקומית של אותה גרסה), הוא מציג אם הם תואמים.
3. העלה את `SHA256SUMS.txt.sig` אל הגרסה (הסקריפט פותח את דף העריכה). מרגע זה האפליקציה מציעה **הורד והתקן**. לפני כן היא מציגה את העדכון אך רק מקשרת לדף הגרסה.

חתום רק על רשימה של גרסה שפרסמת בעצמך. החתימה אומרת "קבצים מדויקים אלו הם הגרסה", כך שהחתימה היא השלב שבו העלאה זדונית תיתפס.

## החלפת המפתח

הרץ `new-release-key.ps1` עם `-KeyFile` חדש: זה מוסיף את המפתח הציבורי החדש לצד הישן ב-`src\update_public_key.h`. שחרר גרסה החתומה במפתח הישן המכילה את שניהם, ולאחר מכן חתום במפתח החדש החל מהגרסה הבאה והסר את המפתח הישן מאוחר יותר. מפתח שאבד או דלף אינו ניתן להוצאה משימוש בדרך זו: הסר אותו מקובץ הכותרת, ומשתמשי גרסאות ישנות יותר יצטרכו להתקין את הגרסה הבאה ידנית.

## מה האפליקציה בודקת לפני הרצת מתקין

- הגרסה היא האחרונה במאגר, אינה טיוטה או טרום-שחרור (prerelease), והיא חדשה מהאפליקציה.
- `SHA256SUMS.txt.sig` היא חתימת ECDSA P-256 תקפה של `SHA256SUMS.txt` באמצעות מפתח ב-`src\update_public_key.h` (Windows BCrypt, ללא קוד צד שלישי).
- הרשימה החתומה מציינת את `BatteryHub-Setup-<version>.exe` בדיוק פעם אחת, עם אותו SHA-256 ש-GitHub מדווח עבור הקובץ.
- למתקין שהורד יש בדיוק אותו גודל ו-SHA-256. עותק של האפליקציה בודק זאת שוב מיד לפני הפעלתו, ושומר על הקובץ נעול כך שלא ניתן להחליף אותו באמצע.
- ההורדות משתמשות ב-HTTPS בלבד אל `github.com`, `objects.githubusercontent.com` ו-`release-assets.githubusercontent.com`, עם בדיקת כל הפניה מחדש (redirect).


---

<a id="sec-keychron-firmware"></a>
> 📄 **מדור:** קושחת מקלדות Keychron (`docs/keychron_keyboard_firmware/README.md`) · [מקור באנגלית](../../docs/keychron_keyboard_firmware/README.md) · [↑ לראש הדף](#top)

# סוללת מקלדות Keychron דרך מקלט ה-2.4 GHz

קושחת המקור של Keychron מדווחת על סוללת המקלדת רק דרך Bluetooth. עם השינוי הקטן ב-QMK שבקובץ [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch), המקלדת עונה גם לשאילתת סוללה (`A4`) דרך מקלט ה-Keychron Link ודרך כבל ה-USB, ו-BatteryHub מציג את הרמה, המתח ומצב הטעינה שלה.

נבדק על **Keychron K5 Max ANSI RGB** (`3434:0A50`) עם מקלט ה-Keychron Link (`3434:D030`).

## מה התיקון משנה

מבוסס על [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) ענף `2025q3` (commit `57e682c`):

- מוסיף את פקודת ה-raw HID `KC_GET_BATTERY` (`0xA4`) מתוך [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1): תשובה `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`;
- מעביר בקשות raw HID המגיעות דרך הקישור האלחוטי לאותו מטפל;
- בקובץ `keyboards/keychron/k5_max/config.h`: `#define WILRESS_RAW_ENABLE` (מאוית כך בקוד של Keychron) ו-`#define KC_BATTERY_MODEL_ID 0`.

שום דבר אחר אינו משתנה: מיפויי מקשים, תאורה ו-Keychron Launcher ממשיכים לעבוד.

## אפשרות 1: צריבת קושחת K5 Max המוכנה

בנייה עבור **K5 Max ANSI RGB בלבד** מצורפת אל [גרסה זו](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1) (`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`).
אין לצרוב אותה על דגם או פריסה אחרים.

## אפשרות 2: בנייה עצמית

מצריך Git ו-Docker (או [סביבת QMK פעילה](https://docs.qmk.fm/newbs_getting_started)).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

התוצאה היא `keychron_k5_max_ansi_rgb_keychron.bin` בתיקיית השורש של המאגר. ב-Windows, עותק בעגינת bind איטי מאוד ב-Docker; שיבוט (clone) בתוך המכולה (או ב-WSL) מהיר בהרבה.

**מקלדות אלחוטיות אחרות של Keychron** (Q/V/K Max ודגמים נוספים בעץ `2025q3` עם `LK_WIRELESS_ENABLE`): השינויים תחת `keyboards/keychron/common/` חלים כמות שהם. הוסף את שתי שורות ה-`#define` אל קובץ ה-`config.h` של המקלדת שלך במקום זה של ה-K5 Max, ובנה את היעד שלך, למשל `make keychron/<model>/<layout>/<variant>:keychron`. האפליקציה מזהה כרגע בשם את K5 Max (`0A50`–`0A58`) לפי דגם וכל מקלדת אחרת כ-"Keychron keyboard".

## צריבה

1. העבר את מתג המצב ל-**Cable** ונתק את כבל ה-USB.
2. החזק את מקש **Esc** בזמן חיבור הכבל. המקלדת נכנסת ל-bootloader של STM32.
3. צרוב את קובץ ה-`.bin` באמצעות [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (או `dfu-util`).
4. העבר בחזרה ל-**2.4 GHz** ובדוק עם `BatteryHub.exe --list`:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

עדכון המקלדת מתוך Keychron Launcher מחליף קושחה זו ומסיר את דיווח הסוללה. כדי לבטל את השינוי, צרוב את הקושחה הרשמית של Keychron באותה דרך.

## רישיון

QMK תחת רישיון GPL-2.0-or-later; התיקון נמצא תחת אותו רישיון. כל מי שמקבל קובץ בינארי שנבנה ממנו חייב להיות מסוגל לקבל גם שינוי קוד מקור זה.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **מדור:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [מקור באנגלית](../../docs/gamesir_cyclone_pro.md) · [↑ לראש הדף](#top)

# תמיכת סוללה ב-GameSir Cyclone Pro

## מדוע הבקר הופיע כבקר Xbox מלא

ה-Cyclone Pro (דגם T4cp) פועל דרך דונגל 2.4 GHz, `3537:1015`. הדונגל מציג את עצמו בפני Windows כבקר Xbox 360 חוטי (XUSB, `Xbox 360 Controller for Windows`). XInput עונה לשאילתת הסוללה שלו ב-"Full", ולכן גיבוי ה-XInput הציג אותו כ-`Xbox controller 1` ב-100% ללא קשר לטעינה האמיתית.

הדונגל אינו נושא שום מידע על הסוללה:
- אוסף ה-HID היחיד שלו הוא בקר המשחק XInput (`HID\VID_3537&PID_1015&IG_00`)
- אין לו אוסף מוגדר-יצרן כמו ל-Nova (`FF7A`) או ל-Cyclone 2 (`FFF0`)

## היכן נמצאת רמת הסוללה

בזמן שהוא פועל דרך הדונגל, הבקר גם מפרסם את עצמו דרך Bluetooth LE בשם `GameSir-Cyclone Pro`, שזהו הקישור שבו משתמשת אפליקציית הטלפון של GameSir. בקשת ה-"get base info" שלו מחזירה את הסוללה:

| שלב | פרטים |
|---|---|
| שירות (Service) | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| מאפיין (Characteristic) | `0x865F` (הודעה, כתיבה ללא תשובה) |
| בקשה | הפעלת התראות, כתיבת `01 01` |
| תשובה | התראה באורך 19 בייטים (חלק מהקושחות מקדימות לה `C9`, 20 בייטים) |

מבנה התשובה:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

בייט 18 הוא הסוללה באחוזים (0-100), או `FF` בזמן טעינה. לא מדווחת רמה בזמן שהוא נטען, ולכן האחוז האחרון הידוע נשמר ומוצג עם ברק הטעינה.

לבקר יש גם את השירות `0xFF10`, שהוא ערוץ עדכון הקושחה של GameSir. הדרייבר לעולם אינו פותח אותו. לבקר אין שירות סוללה תקני (`0x180F`), וזו הסיבה שדף ה-Bluetooth של Windows וגיבוי ה-Bluetooth אינם מציגים עבורו רמה.

מקור: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), שם פוענח הפרוטוקול מתוך אפליקציית ה-Android של GameSir (`BluetoothLeService`, "get base info").

## איך הדרייבר עובד

`src/drivers/gamesir_ble.cpp`, הנקרא לפני גיבוי ה-XInput:

1. **איתור הבקר.** הוא מחפש ממשקי התקנים ממחלקה `{00008650-0000-1000-8000-00805F9B34FB}`. Windows יוצר אחד עבור כל שירות GATT של התקן BLE מצומד. הוא משתמש רק באלה שצומת האב `BTHLE\DEV_…` שלהם נקרא `GameSir-Cyclone…`.
2. **קריאת הסוללה.** הוא פותח שירות זה באמצעות ממשק ה-GATT של Win32 (`bluetoothleapis.h`, `-lbluetoothapis`), נרשם להתראות ב-`0x865F` וכותב `01 01`. הוא ממתין עד 3 שניות לתשובה, ולאחר מכן מכבה בחזרה את ההתראות.
3. **שמירה על דגימה מהירה.** חיבור ה-BLE עלול להימשך שניות, או להסתיים בפסק זמן כשהבקר במצב שינה, ולכן השאילתה רצה בתהליכון משלה:
   - לכל היותר כל 2 דקות לאחר קריאה תקינה, או כל דקה לאחר קריאה שנכשלה
   - הדגימה מדווחת את הקריאה השמורה במטמון, ומפסיקה לדווח עליה ברגע שהיא בת 6 דקות
   - `graceSec` שומר אותה אז גלויה, מעומעמת, כבמצב שינה
   - רק הדגימה הראשונה של ריצה ממתינה לתהליכון, פעם אחת, עם מועד סופי מוחלט של 4 שניות, כך שהרמה מופיעה בהפעלה וב-`--list`
4. **הסתרת רשומת ה-Xbox המזויפת.** כשהדונגל נוכח, הדרייבר תובע את `3537:1015`:
   - נתיב `Windows.Gaming.Input` מדלג כעת על מזהי ספק/מוצר שנתבעו
   - נתיב XInput מקבל את מזהה הספק/מוצר של כל חריץ מתוך `XInputGetCapabilitiesEx` (`xinput1_4` ordinal 108) ומדלג על אלה שנתבעו
   - כשייצוא זה חסר, XInput מתנהג כבעבר

## חומרה שנבדקה

Windows 11, Cyclone Pro על הדונגל שלו (`3537:1015`), מצומד פעם אחת דרך Bluetooth, בתאריך 2026-11-18:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

כשהבקר היה במצב שינה, הרשומה "Xbox controller 1 / Full" לא הופיעה עוד ושום דבר לא הוצג עבור הבקר.

## מגבלות

- **צימוד:** יש לצמד את הבקר ל-Windows פעם אחת (הגדרות > Bluetooth והתקנים > הוסף התקן > Bluetooth > `GameSir-Cyclone Pro`). לבקרים לא מצומדים אין ממשק התקן GATT. הצימוד מוסיף רשומות בקר משחק Bluetooth, אך אלה אינן שולחות קלט בזמן שהבקר פועל דרך הדונגל.
- **נדרש Bluetooth:** המחשב זקוק ל-Bluetooth LE.
- **בקר אחד:** נקרא Cyclone Pro אחד בלבד לכל מחשב.
- **טעינה:** אין אחוזים בזמן טעינה.


---

<a id="sec-localization-guide"></a>
> 📄 **מדור:** מדריך שימוש בריבוי שפות ולוקליזציה (`docs/i18n/README.md`) · [מקור באנגלית](../../docs/i18n/README.md) · [↑ לראש הדף](#top)

# מדריך אינדקס ריבוי שפות ולוקליזציה של BatteryHub

כל מסמך גלוי במאגר זה מרוכז בתוך **קובץ Markdown עצמאי אחד לכל שפה** בתוך `docs/i18n/`, בעוד שכל מחרוזות זמן הריצה של האפליקציה נמצאות ב**קובצי טקסט סטטיים הניתנים לעריכה** בתוך [`lang/`](../../lang) (משותפים ל-Windows ול-Linux) ומחרוזות מתקין ה-Windows נמצאות ב-[`installer/lang/`](../../installer/lang).

## שפות נתמכות (19)

| קוד | שפה | תיעוד מלא | ממשק האפליקציה (Windows ו-Linux) | מתקין Windows |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (מחרוזות מקור) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## איך החלפת השפות עובדת בפועל

### 1. אפליקציית Windows (`BatteryHub.exe`)
- **זיהוי אוטומטי:** כאשר מוגדר *שפה → אוטומטי (שפת Windows)*, BatteryHub מתשאל את פונקציית `GetUserPreferredUILanguages` של Windows ומתאים את קובץ ה-`*.json` הסטטי הקרוב ביותר.
- **החלפה ידנית:** לחץ על ווידג'ט שורת המשימות או על סמל מגש המערכת → **שפה** → בחר שפה. הממשק מתעדכן מיד ונשמר ב-`HKCU\Software\WirelessBattery\Language`.
- **קבצים חיצוניים סטטיים (ניתנים לעריכה ללא בנייה מחדש):** `BatteryHub.exe` טוען תחילה את `<exe>\lang\*.json`, ולאחר מכן את `%APPDATA%\WirelessBattery\lang\*.json`. כל קובץ בתיקיית המשתמש עם אותו `@code` דורס מחרוזות תואמות, ופתיחה מחדש של התפריט טוענת מחדש את הקבצים מהדיסק בזמן אמת.
- **`--help` בשורת הפקודה:** `BatteryHub.exe --help` מציג את חלון העזרה בשפת הממשק הפעילה שלך (`--list`, `--json` ו-`--dump` נשארים באנגלית בכוונה עבור דיווחי Issue ב-GitHub).

### 2. אפליקציית Linux (`wireless-battery`)
- **זיהוי אוטומטי:** עוקבת אחר משתני הלוקאל של POSIX לפי הסדר: `LANGUAGE` (רשימה מופרדת בנקודתיים) → `LC_ALL` → `LC_MESSAGES` → `LANG` (אלא אם נעקף על ידי `LC_ALL=C` / `POSIX`).
- **החלפה ידנית:** לחץ לחיצה ימנית על סמל מגש המערכת → **שפה** → בחר **אוטומטי (שפת המערכת)** או כל שפה מותקנת. נשמר תחת `[general] language=` בקובץ `$XDG_CONFIG_HOME/wireless-battery/config.ini` (ברירת מחדל `~/.config/wireless-battery/config.ini`).
- **נתיבי חיפוש סטטיים (מהעדיפות הנמוכה לגבוהה):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (ברירת מחדל `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (ברירת מחדל `~/.config/wireless-battery/lang/`)
- **`--help` בשורת הפקודה:** `wireless-battery --help` מדפיס עזרת CLI מתורגמת על סמך `config.ini` או לוקאל המערכת; `--list` ו-`--dump` נשארים באנגלית.

### 3. מתקין Windows (`BatteryHub-Setup-<version>.exe`)
- מציג בורר שפות (`ShowLanguageDialog=yes`) הנבחר מראש מתוך שפת הממשק של Windows שלך (`LanguageDetectionMethod=uilanguage`).
- מתקין את תיקיית `lang\*.json` הסטטית המלאה אל `{app}\lang\` לצד `BatteryHub.exe` (וגם קובץ ה-ZIP הנייד כוללים את `lang\*.json`).

---

## איך להוסיף או לעדכן שפה (שלב אחר שלב)

אינך זקוק לשום כלי בנייה כדי לתרגם את ממשק האפליקציה או את התיעוד, ורק ל-Inno Setup 6 אם ברצונך להריץ בניית ניסיון של מתקין ה-Windows.

### שלב 1 — מחרוזות ממשק האפליקציה (`lang/<code>.json`)
1. פתח את תיקיית השפה של המשתמש מתוך תפריט מגש המערכת (**שפה → הוסף שפה משלך...**) או העתק את [`lang/_template.json`](../../lang/_template.json) אל `lang/<code>.json` (לדוגמה `lang/it.json`).
2. מלא את כותרת המטא-נתונים:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. תרגם את הצד הימני אחרי ` = ` בכל שורה.
   - השאר מצייני מיקום (placeholders) כמו `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}` בדיוק כפי שהם.
   - השתמש ב-`\n` למעבר שורה מפורש.
   - שמור כ-**UTF-8 (ללא BOM)**.
   - פתח מחדש את תפריט מגש המערכת של BatteryHub כדי לראות תצוגה מקדימה מיד — ללא צורך בבנייה מחדש!

### שלב 2 — מתקין Windows (`installer/lang/<code>.isl`)
1. העתק את [`installer/lang/_template.isl`](../../installer/lang/_template.isl) אל `installer/lang/<code>.isl`.
2. **קריטי:** שמור את הקובץ כ-**UTF-8 עם BOM (`EF BB BF`)** כך ש-Inno Setup יפענח תווי Unicode באופן אמין ללא קשר לדפי קוד ישנים של Windows.
3. בחר את התבנית המתאימה:
   - **Inno Setup כבר כוללת את השפה שלך** (בדוק ב-`C:\Program Files (x86)\Inno Setup 6\Languages\`): שמור רק על `[CustomMessages]` ותרגם את 6 השורות (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, תוך שמירה על `%1` ו-`%n`). רשום ב-`installer/BatteryHub.iss` תחת `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup אינה כוללת את השפה שלך**: העתק את `installer/lang/zh-CN.isl` כקובץ ייחוס מלא, הגדר `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, ובמידת הצורך `RightToLeft=yes`), תרגם את `[Messages]` ואת `[CustomMessages]`, ורשום אחרי `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - הערה: מזהי `Name:` תחת `[Languages]` רשאים להכיל רק אותיות ASCII, ספרות וקווים תחתונים (השתמש ב-`ptBR`, לא ב-`pt-BR`).

### שלב 3 — מפעיל שולחן העבודה של Linux (`linux/wireless-battery.desktop`)
הוסף שורת `Comment[<code>]=...` מתורגמת (השתמש בקו תחתון לתגיות אזוריות בקובצי `.desktop`, למשל `Comment[zh_CN]=...`).

### שלב 4 — תיעוד מלא בקובץ יחיד (`docs/i18n/<code>.md`)
1. העתק את [`docs/i18n/_template.md`](_template.md) אל `docs/i18n/<code>.md` (ללא צורך בסקריפטים מחוללים — רק קובץ אחד זה!).
2. תרגם את תוכן העניינים ואת כל 17 המדורים במלואם תוך שמירה על:
   - כל תגיות העוגן `<a id="sec-..."></a>` ו-`<a id="top"></a>` ללא שינוי
   - כל בלוקי הקוד, דגלי ה-CLI (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), מזהי USB `VID:PID`, דפי שימוש HID, חבילות הקסדצימליות, מפתחות רישום, נתיבי קבצים וכתובות URL ללא שינוי
   - נתיבים יחסיים לתמונות/קבצים ללא שינוי (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE` וכו')
3. עדכן את סרגל `<!-- lang-switcher:start -->` העליון ב-`docs/i18n/<code>.md` (הדגש את השפה שלך, קשר לכל השאר), הוסף קישור לשפה שלך בסרגלי החלפת השפה ב-`README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` ובקבצי `docs/i18n/*.md` המקבילים.
4. עבור שפות מימין לשמאל (`ar`, `fa`, `he`), כתוב Markdown תקני מבלי לעטוף את הקובץ כולו ב-`<div dir="rtl">` כדי שטבלאות ובלוקי קוד יוצגו בצורה נקייה.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **מדור:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [מקור באנגלית](../../docs/ardor_fury_v2.md) · [↑ לראש הדף](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

מקלט ה-2.4 GHz חושף דף שימוש HID `000A`, שימוש `0000`, ודוח קלט בן 5 בייטים. הוא משדר נתונים באופן פסיבי; לא נשלחות פקודות HID.

דוחות שנצפו מחומרה אמיתית:

| דוח | סוללה |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

הניבל העליון של בייט 3 מקודד את המדרגה (`1`, `3`, `7`, `F` עבור 25, 50, 75 ו-100 אחוז). הדוחות עבור 25% ו-100% מוסקים מתוך לוגיקת הפענוח של אפליקציית היצרן; משתמש הקצה אישר בהמשך ששאר הרמות מוצגות כראוי באפליקציה הבנויה. הבייט החמישי אינו קבוע ואינו משמש כחתימה.

המאזין דורש שתי מדרגות סוללה מפוענחות מסכימות, במקום שני דוחות שלמים זהים. הערך המאושר האחרון נשמר למשך עד 45 שניות. מרווח הרענון האוטומטי הגלובלי משתנה ל-15 שניות.

אומת על ידי משתמש קצה ב-Windows עם ARDOR Fury V2 ו-Logitech G733: לכידות של 50% ו-75%, עדכון אוטומטי תקופתי, בדיקות חזותיות של 25%/100%, והפעלה בגרסה הניידת. הדוחות עבור 25% ו-100% לא נלכדו.


---

<a id="sec-areson"></a>
> 📄 **מדור:** Areson `25A7` (`docs/areson.md`) · [מקור באנגלית](../../docs/areson.md) · [↑ לראש הדף](#top)

# תמיכת סוללה למקלט Areson 25A7

## מדוע התוכנה המקורית החמיצה את העכבר

ה-Redragon M915RGB-WL מתחבר דרך מקלט "2.4G Wireless Receiver" של Areson/CompX במזהה `25A7:FA07`. הסוללה שלו אינה נחשפת כשימוש HID תקני מסוג *Battery Strength* ול-Windows אין מאפיין סוללת Bluetooth עבורו, מאחר שהקישור הוא קנייני ב-2.4 GHz. העכבר עונה במקום זאת לבקשת `GetPower` אקטיבית, ולכן לא גיבוי ה-HID הגנרי ולא גיבוי ה-Bluetooth יכלו לראות אותו. לא היה דרייבר ליצרן, ולכן המקלט נשאר לא תבוע ושקט.

## חומרה וחבילות שנצפו

נבדק ב-Windows 11 עם Redragon M915RGB-WL בתאריך 2026-11-17:

| כיוון | VID:PID | ממשק | דף שימוש:שימוש | גודל דוח |
|---|---|---|---|---|
| בקשה (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 בייטים |
| תשובה (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 בייטים |

התשובה מגיעה באוסף עליון (top-level collection) שונה מזה שאליו נכתבת הבקשה. ב-Windows אלה הם `MI_01&COL07` (feature) ו-`MI_01&COL05` (input), וזו הסיבה שהדרייבר פותח את שתי הידיות (handles).

בקשה שנלכדה (`GetPower`, מזהה דוח `08`, פקודה `04`, סכום הביקורת גורם למסגרת להסתכם ב-`0x55`):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

תשובה שנלכדה:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

ההיסטים שלהלן סופרים את מזהה הדוח כבייט אפס:

| בייט(ים) | משמעות | דוגמה |
|---|---|---|
| 0 | מזהה דוח תשובה | `09` |
| 1 | הד פקודה | `04` |
| 2 | מצב, 0 = תקין (OK) | `00` |
| 3–4 | כתובת, לא בשימוש עבור `GetPower` | `00 00` |
| 5 | אורך נתונים (2) | `02` |
| 6 | רמת סוללה, 0–10, בצעדים של 10% | `08` = 80% |
| 7 | דגל טעינה, כל ערך שונה מאפס | `00` = לא בטעינה |
| 16 | סכום ביקורת; כל 17 הבייטים מסתכמים ב-`0x55` (מודולו 256) | `3E` |

תוכנת היצרן עצמה הציגה 80% עבור אותה מסגרת, מה שמבסס את קנה המידה של ×10. `GetConnectStatus` (`08 03 …`) עונה במטען בן בייט אחד ודיווחה על העכבר כמקושר באותו זמן.

## עכברי Areson אחרים

מקלטי `FA7B` / `FA7C` הישנים יותר שבהם משתמש Redragon M693 מדווחים את הטעינה ישירות כאחוז שלם באותו היסט בתשובה. הפעלת קנה המידה ×10 של דרייבר זה שם הייתה מציגה 800%, ולכן מזהי מוצר אלה אינם נתבעים במכוון. רק `FA07` ו-`FA08` מטופלים; `FA08` הוא הזהות החלופית של אותה משפחה ולא אומת על מכונה זו.

## דגימה וזהות

- הדרייבר שולח רק את בקשת ה-`GetPower` לקריאה בלבד. הוא לעולם אינו כותב נתוני תצורה, תאורה או DPI.
- בכל רענון הוא פותח את אוסף ה-feature עם גישה אפסית ואת אוסף ה-input לקריאה, שולח את הבקשה וממתין עד 1.8 שניות לתשובה, עם שני ניסיונות וניקוי תור ביניהם כך שדוח ישן לא יתפרש בטעות כתשובה.
- קריאה שנכשלת אינה תובעת דבר, כך שעכבר במצב שינה שומר על הערך האחרון בממשק המשתמש. הרשומה משתמשת בתקופת חסד של 30 דקות, בדומה לשאר הדרייברים הפסיביים.
- מפתח ההתקן נגזר ממזהה הספק והמוצר (`areson:25A7:FA07`), כך שהוא שורד את מחזור הקליטה/שינה וניתוק/חיבור מחדש של המקלט.

## אימות

האפליקציה המלאה נבנתה עם MSVC C++17 ו-Windows SDK והורצה מול העכבר האמיתי. `BatteryHub.exe --list` החזיר:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

הקריאה תאמה לאחוז שהוצג על ידי תוכנת Redragon הרשמית באותו רגע. קובץ `build.bat` של MinGW כולל את קובץ המקור החדש; ה-`Makefile` מגלה אותו באמצעות תו הכללה (wildcard).

## מקורות פרוטוקול

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): מסגרות בנות 17 בייטים, פיצול feature/input וכלל סכום הביקורת `0x55`, ששוחזרו מלכידות USB של תוכנת Redragon.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): פקודת `GetPower` וקנה המידה של 10% ב-`25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md): מבנה התשובה וקנה המידה השונה של האחוזים במשפחת `FA7B` / `FA7C`.


---

<a id="sec-darkrim"></a>
> 📄 **מדור:** DARKRIM SHADOW (`docs/darkrim.md`) · [מקור באנגלית](../../docs/darkrim.md) · [↑ לראש הדף](#top)

# מקלט DARKRIM SHADOW / 寸渊影弑

נבדק בחומרה ב-`3654:6901`, יצרן `Jieli Technology`, גרסה `0100`.
השתמש בממשק **3**, שימוש `FF02:0002`, מטעני קלט/פלט ללא מספר דוח באורך 64 בייטים (גודלי דוח HID של 65 בייטים ב-Windows). גם לממשק 4 יש `FF02:0002`, אך הוא משתמש במזהה דוח 2 ולא ענה לפרוטוקול זה; הוא מוחרג במכוון.

מקור הפרוטוקול: [הורדת PC Hub הרשמית](https://app.darkrim.net/hub/zh.html), `DARKRIM-0.1.26-x64-setup.rar`, שהורדה ונפרסה סטטית מבלי להתקין או להפעיל את תוכנת היצרן. ערך SHA-256 של `DARKRIM.exe` שחולץ: `f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

כתובות שימושיות באותו קובץ בינארי:

- `140124C80`: `sendGetBasicInfo(infoType)` שולחת פקודה `0010`, בקשה `01`, מטען `[infoType, 00]`. בורר הסוללה הוא `01`.
- `140118D30`, `140119200`: יצירת כותרת מסגרת ו-CRC.
- `140126DB0`: מנתח TLV של פרטי התקן; TLV `01` הוא הסוללה.
- `1400F5660`, `1400FA700`: צרכני סוללה; שבע הסיביות התחתונות נותנות את האחוז, הסיבית העליונה היא טעינה. אותו ערך סוללה מגיע גם ב-`0011` Notify `03`.

כותרת: `FE seq cmdLE type index count lengthLE`, ואחריה מטען ו-CRC-16/CCITT-FALSE (פולינום `1021`, ערך התחלתי `FFFF`, מאוחסן ב-big-endian). הרצף הוא מונה של ארבע סיביות שונה מאפס; הצפנה אינה בשימוש.

מטעני בקשה/תשובה בפועל, לפני ריפוד אפסים של HID:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

ה-TLV של התשובה `01 01 28` נותן **40%, לא בטעינה**. דרייבר ה-C++ הייצורי החזיר ערך זה בשלוש שאילתות רצופות ללא תוכנת היצרן. המקלט פולט הודעות אתחול לפני התשובה התואמת, שנמדדו בכ-406 אלפיות שנייה. השתמש במועד סופי יחיד של 800 אלפיות שנייה לתשובה (ועד 200 אלפיות שנייה לכתיבה), מבלי לאתחל אותו עבור הודעות לא קשורות. אין צורך באות חיים (heartbeat).

הדרייבר שולח רק את ה-GET של הסוללה. הוא מקבל רק תשובה לא מוצפנת עם רצף/פקודה/סוג תואמים, אינדקס אפס, מונה אפס או אחד (החומרה משתמשת באפס), אורך/CRC תקינים, ו-TLV סוללה בודד ובנוי כהלכה. תשובות מפוצלות, לא מבוקשות, משובשות ומחוץ לטווח מתקבלות בהתעלמות.

## דיוק סוללה ומצב טעינה שנצפו

התייחס לאחוז כאל **הערכה גסה, ולא מד ברזולוציה מאומתת של 1%**. היחידה של הבעלים הציגה התקדמות טעינה בצעדים של 10 נקודות אחוז מ-40% עד 90%. ב-90%, חמש תשובות GET לסוללה והודעה לא מבוקשת אחת נשאו כולן `DA`: `DA & 7F = 90`, כשסיבית 7 מציינת טעינה. לאחר שהבעלים ניתק את כבל הטעינה והמשיך להשתמש במקלט ה-2.4 GHz, חמש תשובות GET נוספות והודעה אחת נשאו כולן `5A`: עדיין 90%, כעת עם סיבית הטעינה מאופסת. כל שתים עשרה המסגרות עברו אימות CRC.

תשובות שאילתה מייצגות (רצף 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

הן הדרייבר והן האפליקציה הרשמית לוקחים את האחוז ישירות משבע הסיביות התחתונות. הדרייבר אינו מעגל לעשרות, אינו מכפיל מדרגה בעשר, ואינו מבצע אינטרפולציה לערכי ביניים; דוחות סינתטיים של 47% ו-95% נשארים 47% ו-95% במפענח הייצורי. הקריאות הגסות שנצפו נובעות אפוא לפני המפענח, בדיווח של האוזניות/מקלט עצמם. לא נצפו קריאות חומרה עדינות יותר. עקומת פריקה מלאה לא תועדה, ולכן צעד קבוע של 10% בכל רמת פריקה או בקושחה אחרת אינו מאושר.

מצבי טעינה ולאחריה אי-טעינה ב-90% נבדקו בחומרה. גבולות סוללה נמוכה/מלאה, התנהגות בכיבוי האוזניות, Bluetooth ומצב נתונים של כבל USB לא נבדקו בחומרה. לא נטענת שום תמיכה עבור מצבים אלה. שום עדכוני קושחה, שינויי תצורה, פקודות EQ, שינויי צימוד, איפוסים או קבצים בינאריים של היצרן אינם כלולים במימוש זה.

בדיקה: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **מדור:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [מקור באנגלית](../../docs/hyperx_haste_2.md) · [↑ לראש הדף](#top)

# פרוטוקול הסוללה של HyperX Pulsefire Haste 2 Wireless

נקרא על ידי `HasteWireless` ב-`src/drivers/hyperx.cpp`. השאילתות מגיעות מ-[ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) והן זהות לאלה ש-NGENUITY משתמש בהן.

אומת על חומרה:

- Pulsefire Haste 2 Core Wireless, דונגל `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, דונגל `03F0:0F98`, על ידי uzumakiprime (PR #312). הרמה תאמה ל-HyperX NGENUITY.

הדונגל `03F0:0D97` צפוי לעבוד באותו אופן אך לא נבדק.

## אוסף HID

| שדה | ערך (`0F98`) |
|---|---|
| ממשק USB | `MI_02` (ממשק 2) |
| דף שימוש : שימוש | `FF00:0001` |
| אורך דוח input / output / feature | 64 / 64 / 64 בייטים |

הדונגל חושף גם את אוספי העכבר ובקרת הצרכן התקניים. הדרייבר פותח רק אוסף יצרן (דף שימוש `FF00` ומעלה) עם דוחות קלט של לפחות 8 בייטים.

## שאילתות

שתיהן דוחות פלט: שני הבייטים הראשונים להלן, מרופדים באפסים עד לאורך הדוח. כל תשובה היא דוח קלט שהבייט הראשון שלו הוא הפקודה ועוד אחת. כל שאילתה ממתינה לכל היותר שנייה אחת לתשובה שלה ומדלגת על דוחות לא קשורים (לאחר חיבור מחדש הדונגל שולח דוחות `44 xx`, `45 xx` ו-`FB xx` מעצמו).

| בקשה | תשובה | משמעות |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0 כשהעכבר כבוי או מחוץ לטווח |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100; `charge` 1 = בטעינה, 2 = מלא על המטען; מתח ב-mV, little endian (0 בדגם Core) |

- אם תשובת הקישור חסרה, תשובת הסוללה מכריעה.
- אם הקישור מדווח 0, לא נשלחת שאילתת סוללה והעכבר מוצג ככבוי.
- במשך שניות ספורות לאחר שהעכבר נדלק הוא מדווח כ-40%. קריאה בתוך 6 שניות מעליית הקישור מתקבלת בהתעלמות, ומגש המערכת שומר את הערך האחרון.

שתי הבקשות רק קוראות מצב. שום דבר אינו משנה הגדרות, תאורה או מצבים.


---

<a id="sec-inphic"></a>
> 📄 **מדור:** Inphic IN10 (`docs/inphic.md`) · [מקור באנגלית](../../docs/inphic.md) · [↑ לראש הדף](#top)

# משפחת Inphic IN10, מקלט KP 8K

ההתקן המחובר, שזוהה על ידי בעליו כ-IN10 MAX, מופיע במערכת כ-`Inphic KP 8K`, `1D57:FA65`, גרסה `0116`. אוסף המצב שלו הוא ממשק 2, שימוש `000A:0000`, אורך קלט 5 (כולל מזהה דוח 03).

נצפה בערך כל ארבע שניות, מבלי לשלוח שום בקשה:

```text
03 73 41 01 64
```

מפענח ה-Xenta הקיים מזהה פורמט זה: דגם, אירוע, מצב סוללה, אחוז. נדרשים שני דוחות זהים לפני הצגת 100%; הדוח הראשון לאחר הקישור עלול להיות קריאת "מלא" מטעה במקלטים דומים. שינוי זה שומר על מנגנון הגנה זה ועל התנהגות הטעינה והשינה הקיימת.

החבילה הרשמית של [Inphic HUB](https://hub.inphic.cn/) `assets/index-BcHQx9B6.js` ממפה דגם 115 עשרוני (`73`) ל-`IN10RMax`, ו-116 (`74`) ל-`IN10Max`. היא משתמשת במצב סוללה 1 עבור אחוז, 2 עבור מלא ו-3 עבור טעינה. יש להשתמש בשם הדגם של הקושחה במקום לשייך את `73` ל-IN10 MAX ולסכן תיוג שגוי של התקנים אחרים החולקים מקלט זה.

לפני שינוי זה האפליקציה הציגה את העכבר המחובר כ-`Wireless mouse`. תובלת Xenta כבר טיפלה במסגרות הסוללה שלו; השינוי מספק את שמות הדגמים החסרים. הרצת `--list` טרייה עלולה להציג מצב שינה מאחר שתצפית ההתחלה בת חמש השניות שלה עשויה לקבל דוח אחד של ארבע שניות בלבד. האפליקציה השוכנת בזיכרון שומרת על המאזין ומאשרת את הערך בדגימה מאוחרת יותר.

אומת בחומרה: דוחות פסיביים, רמת 100% חוזרת וזיהוי דגם מדרייבר מקורי. מעברי טעינה, גבולות סוללה חלשה, מצב Bluetooth ומצב כבל לא אומתו. דגם `74` מקורו בטבלה הרשמית ולא נבדק על חומרה נפרדת.


---

<a id="sec-machenike"></a>
> 📄 **מדור:** Machenike L7 (`docs/machenike.md`) · [מקור באנגלית](../../docs/machenike.md) · [↑ לראש הדף](#top)

# Machenike L7 Arctic / L7 Mix

אומת על L7 Arctic המזדהה כ-**L7 Mix**:

| חיבור | VID:PID | ממשק | שימוש | קלט / פלט / מאפיין מקסימלי |
| --- | --- | --- | --- | --- |
| מקלט 2.4 GHz | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| כבל USB | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

הדרייבר בודק גם את שם מוצר ה-HID `L7 Mix`. דגמי Machenike אחרים, מזהי מקלט שונים ושאילתות יצרן ב-Bluetooth אינם מופעלים.

## מקור הפרוטוקול

ניתוח תאימות של התוכנה הרשמית **Machenike L7 Mix 1.0.0.8**, הזמינה מ[דף הדרייברים של היצרן](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/), ושאילתות לקריאה בלבד על העכבר האמיתי. SHA-256 של `DeviceDriver.exe`:
`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

בקובץ הפעלה 32-סיביות זה (בסיס תמונה `00400000`), הפונקציה בכתובת VA `00436750` בונה את בקשת המצב; `004494F0` שולחת אותה דרך `HidD_SetFeature` וקוראת את תשובת ה-feature. מנתח המצב `00410C20` מחלץ את השדות שלהלן ומעביר את שדות הסוללה והטעינה לממשק המשתמש. אלה הן כתובות וירטואליות, לא היסטים בקובץ. שום קובץ הפעלה קנייני, קוד אפליקציה או משאבים אינם כלולים כאן.

## שאילתת קריאת מצב

שלח **21 בייטים**, מזהה דוח `51`, פקודה `06`, כל שאר הבייטים אפס:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

קרא דוח feature `51`, גם הוא באמצעות 21 בייטים. גודל ה-feature המרבי של האוסף הוא 1001 עבור דוחות אחרים; זהו אינו האורך של דוח המצב. הדרייבר ממתין 10 אלפיות שנייה לפני הקריאה ומשתמש במועד סופי יחיד של 200 אלפיות שנייה לכל מוצר, כולל תשובות לא קשורות. הוא אינו שולח שום פקודות הגדרה, מצב, מאקרו או קושחה.

האינדקסים כוללים את מזהה הדוח:

| בייטים | משמעות / ערכים שנצפו |
| --- | --- |
| 0–1 | `51 06`, הד פקודה נדרש |
| 4–7 | `8A 24 4E FF`, חתימת ההתקן המאומתת של L7 |
| 10, סיביות 0–2 | מצב עבודה: 1 על מקלט, 0 על כבל |
| 10, סיבית 3 | עכבר אלחוטי מחובר; מאופסת גם על כבל ה-USB |
| 11 | אחוז סוללה, 0–100 (אפס הוא ערך תקין) |
| 12 | דגל טעינה: 0 בפריקה, 1 בטעינה |

שדות אחרים וסמנטיקה של סכום ביקורת אינם מבוססים. הדרייבר אינו ממציא סכום ביקורת. הוא מאמת את הפקודה, האורך, חתימת ההתקן, המצב וטווחי הסוללה/טעינה במצב מחובר לפני פרסום קריאה.

תשובת מקלט שנלכדה, גם 64% באפליקציה הרשמית:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

תשובת כבל USB שנלכדה בזמן טעינה (74%):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

באותו זמן המקלט עדיין החזיר את ה-64% השמורים במטמון שלו, אך איפס את סיבית הקישור שלו:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

קריאה מנותקת זו אסור שתחשוף ערכי סוללה/טעינה שמורים במטמון. הכבל מקבל עדיפות כאשר שתי התובלות נוכחות, ומפתח ההתקן היציב משותף בין התובלות. L7 מוכר נשמר גם בכשל שאילתה כדי שדרייבר Ajazz המאוחר יותר לא יוכל לדגום אותו עם פרוטוקול שונה על ה-VID המשותף.

## גבולות אימות

רשומות בדיקה (fixtures) ובדיקות תובלה מדומות מכסות קריאות שנלכדו, טעינה, 0%/100% תקינים, מקלטים מנותקים, תשובות משובשות/ישנות, התאמה קפדנית, כשל תובלה, מניעת כפילויות ולולאות ניסיון חוזר חסומות. ערכי 0%/100% חיים וכל גרסאות השינה/קושחה אינם משתמעים מבדיקות אלה.


---

<a id="sec-nuphy"></a>
> 📄 **מדור:** NuPhy WH80 (`docs/nuphy.md`) · [מקור באנגלית](../../docs/nuphy.md) · [↑ לראש הדף](#top)

# NuPhy WH80 (כבל USB ו-Bluetooth)

נבדק בחומרה עם `19F5:A011`, גרסת קושחה `0116`, ממשק 1, שימוש `0001:0000`, מטעני קלט/פלט ללא מספר דוח באורך 64 בייטים (65 בייטים ביכולות ה-HID של Windows).

מקור הפרוטוקול: [NuPhyIO](https://drive.nuphy.io/), חבילה `main.b3fb29e0.js`, SDK `getBatteryState(0)`, `getDataPackage` ו-`createCommand`.
מבוקש רק `GetFunc` (`05`), היסט `0020`, אורך `01`. אין צורך בפקודות אתחול, תצורה, תאורה או קושחה.

מטען בקשה, מרופד באפסים ל-64 בייטים:

```text
55 05 00 21 01 20 00 00
```

מטען תשובה בפועל:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

בייט 3 הוא הבייט התחתון של סכום הבייטים 4..63. הסוללה נמצאת בבייט 8: `value & 7F` הוא האחוז, `value & 80` הוא דגל הטעינה של ה-SDK. דרייבר ה-C++ המקומי החזיר **100%, בטעינה** על המקלדת המחוברת. מעברי טעינה וגבולות סוללה נמוכה/מלאה לא נבדקו בחומרה; הערות הקושחה הרשמיות מתארות קריאות של WH80 במדרגות של 10%. פעולת המקלט נמצאת מחוץ להיקף דרייבר זה.

## Bluetooth

ב-Bluetooth אותה מקלדת משתמשת במזהה HID `19F5:324A` (גרסה `0129`) ומפרסמת שם גלוי למשתמש כגון `NuPhy WH80 - 1`. היא חושפת שני אוספי מקלדת ואוסף עכבר. ההיוריסטיקה הגנרית של HID מתעדפת עכברים, ולכן יש להוסיף מזהה Bluetooth מדויק זה לדריסות המקלדת הקיימות.

דיווח הסוללה ממשיך להשתמש במאפיין סוללת ה-Bluetooth של Windows. לאחר ניתוק ה-USB, Windows דיווח **95%** על המקלדת המחוברת. קריאה לא-שמורה במטמון של רמת סוללת GATT תקנית (`180F` / `2A19`) החזירה גם היא **95%** ישירות מהמקלדת. זוהי קריאת התקן/תובלה נפרדת מהתצפית החוטית של 100%; אל תחליף אותה בערך מלא משוער ואל תשנה לה קנה מידה. הסיבה להבדל בקריאות הקושחה אינה ידועה.

הדרייבר בודק את גודלי המוצר/ממשק/דוח המדויקים, כותרת התשובה, ההיסט, האורך, סכום הביקורת וטווח האחוזים. הוא משתמש במועד סופי של 400 אלפיות שנייה לתשובה ומתעלם מתשובות לא קשורות בתוך אותו מועד סופי.

בדיקת רגרסיה:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **מדור:** Rapoo (`docs/rapoo.md`) · [מקור באנגלית](../../docs/rapoo.md) · [↑ לראש הדף](#top)

# תמיכת סוללה לעכברי Rapoo

## מדוע התוכנה המקורית החמיצה את העכבר

`PollAllDevices()` מונה את האוספים העליונים של Windows HID פעם אחת בכל רענון. כל דרייבר יצרן מזהה פרוטוקול, מוסיף `DeviceStatus`, ותובע את ה-VID/PID שלו כך שהדרייברים הגנריים לא יוסיפו אותו שוב. ממשק המשתמש כבר מטפל באחוזים, בטעינה ובקריאה האחרונה במצב שינה.

לא היה דרייבר של Rapoo. ה-VT3 Max Gen 2 שולח את הסוללה שלו בדוח קלט מוגדר-יצרן, ולא בשימוש התקני HID Battery Strength או במאפיין סוללת Bluetooth של Windows. לכן מנגנוני הגיבוי הגנריים של HID/Bluetooth אינם יכולים לפענח את מקלט ה-USB שלו.

## חומרה וחבילות שנצפו

נבדק ב-Windows עם ה-VT3 Max Gen 2 של הבעלים בתאריך 2026-11-16:

| חיבור | VID:PID | ממשק | דף שימוש:שימוש | גודל קלט / פלט |
|---|---|---|---|---|
| מקלט 2.4 GHz | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 בייטים |
| כבל USB | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 בייטים |

שניהם מזדהים כ-`Rapoo Gaming Device`. שאר האוספים כוללים קלט עכבר, מקלדת ומדיה תקניים, אוספי תצורת יצרן, וממשק קושחה בן 513 בייטים. דרייבר הסוללה פותח רק את `FF00:0002` עם גודל קלט מוכר. הוא לעולם אינו פותח את ממשק הקושחה ולעולם אינו שולח דוח פלט, דוח מאפיינים, לחיצת יד או פקודת תצורה.

דוח אלחוטי שנלכד, כולל מזהה דוח:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

דוח כבל/טעינה שנלכד:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

ההיסטים שלהלן סופרים את מזהה הדוח כבייט אפס, בהתאמה ל-`HidDev::Read()` של פרויקט זה:

| בייט(ים) | משמעות | דוגמה |
|---|---|---|
| 0 | מזהה דוח | `07` |
| 1 ניבל תחתון | חיבור: 0 מקלט, 1 Bluetooth, 2 כבל | `20` / `22` |
| 1 ניבל עליון | מידע חיישן; אינו חלק מסוג החיבור | `2` |
| 2 | דרגת DPI נוכחית | `03` |
| 3–4, 5–6 | DPI בציר X/Y, little endian | `0320` = 800 |
| 7 | מצב סוללה: 0 לא תקין, 1 בפריקה, 2 בטעינה | `01` / `02` |
| 8 | אחוז סוללה, 0–100 | `19` = 25% |
| 13–14 | מזהה מוצר העכבר, little endian, כשנוכח | `4617` |

הלכידה החיה של המקלט דיווחה `25%`, והאפליקציה המלאה החזירה בהמשך `27%, charging` דרך הכבל. בדיקת המפענח כוללת את הלכידה האלחוטית הממשית. טעינה וקישוריות כבל אומתו גם הן מול חומרה חיה; אלה אינן מוסקות רק מנוכחות התקן USB. לאחר שהבעלים ניתק את הכבל וחיבר מחדש את המקלט, קובץ ההפעלה הסופי החזיר `52%` דרך `2.4 GHz receiver`, ללא דגל הטעינה, ושמר על אותו מפתח `rapoo:4617`. דבר זה מאמת גם את המעבר מכבל למקלט מול חומרה חיה.

נבדק גם ב-Windows עם **VT9 Gen 2** בתאריך 2026-11-17:

| חיבור | VID:PID | ממשק | דף שימוש:שימוש | גודל קלט / פלט |
|---|---|---|---|---|
| מקלט 2.4 GHz | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 בייטים |
| כבל USB | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 בייטים |

מקלט ה-VT9 Gen 2 חושף דוח `FF00:0002` באורך **16 בייטים** במקום 19 בייטים, תוך שימוש בדיוק באותו מבנה `07` של Nordic 54L (כולל ה-PID המשובץ `4614` בבייטים 13–14). מסגרות שנלכדו:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

דרך כבל USB, דוחות מצב נצפו בעת אינטראקציה (למשל שינוי DPI); כאשר מתג ההפעלה התחתון כבוי בעת החיבור לחשמל, העכבר דיווח `state=2, percent=1` במקום אחוז הסוללה האמיתי.

### מקלט VT3 Max Gen 2 עם אוסף בן 13 בייטים (issue #1396)

דיווח מטופס בקשת התקן עבור אותו מזהה מקלט `24AE:1417` פירט פריסת ממשק שונה: `FF00:0002` עם **13 / 13** בייטים (במקום 19), ו-`FF00:000E` עם 33 / 33 בייטים, ללא אוסף קושחה בן 513 בייטים. זה נראה כמו מהדורת קושחה אחרת של המקלט. תוכנת Rapoo עדיין הציגה את הסוללה, כך שהדרייבר התעלם מערוץ מצב פעיל.

המפענח `VT_nrf54L` (`py`) של Rapoo Hub הוא מותאם-אורך: הוא תמיד קורא את ה-DPI, מצב הסוללה והאחוז, וקורא את השדות המאוחרים יותר (PID של העכבר ב-`n[12..13]`, מידע RF, ...) רק כשהדוח ארוך מספיק. למניפסט של VT3 MAX (`productId: [17943, 5143]`) אין סוג דוח קלט מיוחד, כך שדוח `07` עובר דרך מפענח זה גם במקלט זה. דוח בן 13 בייטים (מזהה ועוד 12 בייטים) עדיין נושא את המצב בבייט 7 ואת האחוז בבייט 8; רק ה-PID המשובץ של העכבר חסר, ולכן הקריאה משתמשת ב-PID של המקלט ושומרת על המפתח `rapoo:4617`.

האורך בן 13 הבייטים מתקבל **רק עבור `24AE:1417`**. מסגרות חייבות עדיין לעבור את אותן בדיקות (דוח `07`, ניבל חיבור 0–2, מצב 1/2, אחוז 0–100). טרם נלכדה מסגרת חיה בת 13 בייטים; הבדיקות משתמשות בלכידה שנבדקה בת 19 הבייטים מקוצצת ל-13 בייטים.

## עכברי Rapoo אחרים

Rapoo Hub הרשמי משתמש במבנה `07` זה עבור דרייבר עכברי ה-Nordic 54L שלו. המניפסטים שלו מפרטים VT0, VT1, VT2, VT3, VT3S, VT7, VT9 וגרסאות נוספות. בדיקה של החבילה הנוכחית זיהתה 69 גרסאות VT המשתמשות ב-`VT_nrf54L`; זוהי ראיה לפרוטוקול משותף, ולא 69 אימותי חומרה או טענה לכיסוי רוב הקטלוג של Rapoo. התמיכה נבחרת לפי VID של Rapoo, האוסף הייעודי, אורך הקלט ודוח מצב תקין, כך שדגם שאינו רשום על אותו פרוטוקול עדיין יכול לדווח את הסוללה שלו. טבלת שמות קטנה מכסה דגמים נפוצים; אחרים שומרים על שם מוצר ה-HID שלהם או מציגים `Rapoo wireless mouse`.

שמות מוצר ומזהים משתנים בין דורות ואזורים. הצמד שנבדק `1417/4617` נקרא `VT3 MAX` במניפסט הרשמי הנוכחי; הבעלים מזהה אותו כ-VT3 Max Gen 2. ה-`VT3 MAX V2` הנפרד במניפסט הנוכחי הוא בעל מזהים `1B06/4B06`. טבלאות קהילה המשייכות את `1417` ל-VT9 Pro אסור שישמשו כבסיס היחיד למתן שם או לזיהוי התקן זה.

קושחת VT ישנה יותר, המתועדת עבור VT3 Pro (`1215/4415`), דוחפת במקום זאת דוח בן 7 בייטים באותו שימוש `FF00:0002`:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

בפורמט ישן זה, מצבים 1/2 משמעותם פריקה/טעינה. אחוז טעינה של `7F` משמעותו לא ידוע והוא נשמר כלא ידוע. מצב מעבר 0, דוחות `BC` לא קשורים, חבילות משובשות ואחוזים מעל 100 מתקבלים בהתעלמות. לתמיכה בדור קודם יש כיסוי אוטומטי, אך היא לא אומתה כאן עם עכבר ישן פיזי. פרשנות זו מוגבלת למזהי המוצר `1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) ולאוסף הקלט בן 7 הבייטים שלהם.

VT1 Pro Max (מקלט `24AE:1233`, כבל `24AE:4433`, קושחת עכבר 222, קושחת דונגל 213) נוסף מתוך לכידות USBPcap שבעליו צירף אל issue #136. פלט `--dump` מפרט את אוסף `FF00:0002` בן 7 הבייטים בממשק 1, והלכידות מראות אותו נדחף, ללא בקשה מאפליקציית Rapoo:

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

דרך הכבל הדוח נראה פעם אחת בלבד בלכידה של 16 שניות, כך שקריאת כבל בלבד עלולה להיכשל בפסק זמן בחלק מהרענונים; המקלט דוחף אותו בקביעות. פרופיל ה-Nordic לעולם אינו מפרש חבילות `BB`.

אין בכך **כדי לבסס** תמיכה בכל התקן Rapoo. דגמי CH584 כגון VT1 SE ו-VT7 SE משתמשים בדוח `08` בדרייבר הרשמי ואינם נתמכים על ידי מפענח זה. מהדורות Telink אחרות משתמשות בפרשנות שונה של דגלי ה-`BB`, חלק מדגמי המשרד משתמשים בשאילתות סוללה אקטיביות, ודגמי Bluetooth עשויים לחשוף רק את מאפיין הסוללה של Windows. אלה נשארים עם מנגנוני הגיבוי הקיימים או זקוקים למימוש נפרד ומאומת. אל תשלח אליהם שאילתות מנוחשות.

## דגימה וזהות

- הקריאה היא פסיבית. ידיות (handles) תואמות של `FF00:0002` נשארות פתוחות בין דגימות (בדומה ל-`PollXenta`) כך ש-Windows מאגר מסגרות מצב המגיעות במהלך מרווח הרענון של 60 השניות; כל דגימה מרוקנת מסגרות שבתור (תוך שמירת קריאת הסוללה התקינה החדשה ביותר) לפני שהיא עוברת להמתנה של 5 שניות בפתיחה ראשונה או בתור ריק. התקנים מנותקים מוסרים והידיות שלהם נסגרות. חבילות לא קשורות אינן מאתחלות את המועד הסופי.
- ה-PID המשובץ של העכבר, או צמד כבל/מקלט מוכר עבור התקנים מדור קודם, נותן את אותו מפתח ממשק משתמש במעברי כבל. קריאות כבל ומקלט ממוזגות לרשומה אחת, תוך העדפת מצב הכבל ושמירת אחוז מקלט תקין אם הכבל מדווח רמה לא ידועה.
- פסק זמן אינו ממציא אחוז ואינו תובע את ההתקן. לאחר קריאה מוצלחת, ממשק המשתמש הקיים יכול לשמור קריאה זו, מעומעמת, במשך 30 דקות של דממה.
- מודל הזהות הקיים של התוכנה המבוסס על VID/PID אינו יכול להבחין בין מספר עכברים זהים בעלי אותו מזהה דגם. הפעלה פיזית בו-זמנית של כבל ומקלט לא נבדקה; מיזוג שני הקלטים מכוסה על ידי בדיקת התובלה המדומה.

## אימות

`make test` מריץ בדיקת מפענח ניידת ובדיקת דרייבר Windows עם תשובות HID מדומות. הכיסוי כולל את הלכידה הממשית, 0% ו-100%, טעינה, רמות חסרות, מסגרות לא תקינות/קטועות, אוספים/יצרנים לא נתמכים, בידוד פרופילי פרוטוקול, פסקי זמן, מפתחות יציבים, וביטול כפילויות כבל/מקלט מבלי להשליך אחוז ידוע.

האפליקציה המלאה נבנתה מקומית עם MSVC C++17 ו-Windows SDK, ו-`--list` / `--dump` הורצו מול העכבר האמיתי. בניית ה-MinGW המתוחזקת כוללת את `rapoo.cpp` ב-`build.bat`; ה-Makefile מגלה אותו אוטומטית. MinGW עצמו לא היה מותקן בסביבת הבדיקה.

## מקורות פרוטוקול

- [Rapoo Hub הרשמי](https://hub.rapoo.cn/), נבדק בתאריך 2026-11-16: [דרייבר JavaScript ומניפסטים מצורפים](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js). המפענחים הרלוונטיים הם `py`/`Hk` עבור `VT_nrf54L` ו-`qM`/`QM` עבור משמעויות החיבור ומצב הסוללה. המטפל הנפרד `VT_CH584` צורך את דוח `08` ונמצא מחוץ למימוש זה. שמות מקוצרים (minified) עשויים להשתנות בגרסאות עתידיות.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs), עבור דוחות VT3 Pro מדור קודם, מצב טעינה וסמן הרמה הלא ידועה.
- לכידות USBPcap מ-Issue #136 (VT1 Pro Max על מקלט ועל כבל בזמן טעינה).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js) מאמת באופן בלתי תלוי שידורי מצב פסיביים `07` ואת היסט הסוללה. המפענח שלו חותך אחוזים לא תקינים לגבולות; מימוש זה דוחה אותם במקום זאת.


---

<a id="sec-rawm"></a>
> 📄 **מדור:** RAWM (`docs/rawm.md`) · [מקור באנגלית](../../docs/rawm.md) · [↑ לראש הדף](#top)

# הערות פרוטוקול RAWM

עכברי RAWM (ו-SADES Dagger, החולק את הפלטפורמה) מתקשרים עם אפליקציית RAWM HUB דרך אוסף HID של היצרן, `FF00:0001`, עם דוחות קלט ופלט ללא מספר דוח באורך 64 בייטים (65 בייטים עם מזהה הדוח). המקלטים והעכברים משתמשים במזהה הספק של Nordic `1915`.

מקור: אפליקציית הרשת RAWM HUB, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), והסקריפט שלה `https://hub.miracletek.net/hub/js/library.min.js` (מעורפל; שמות הפונקציות והקבועים להלן הם של הסקריפט עצמו). מזהי המוצר הנתמכים מגיעים מטבלת ההתקנים שהאפליקציה מורידה (`https://www.miracletek.net/game/device.php`). Leviathan V4 GT ו-NYX60 משתמשים ב-Hub Web 3.0 ב-VID `373E`, שהוא פרוטוקול שונה.

## חבילות

בייט 0 של כל דוח (אחרי מזהה הדוח):

| סיביות עליונות | משמעות |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | 6 הסיביות התחתונות הן גודל המטען; המטען ממשיך את זרם האירועים |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | בקרת זרימה (גודלי חוצץ פנויים); מתעלמים כאן |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | 6 הסיביות התחתונות הן ערוץ ESB; שאר הדוח הוא חבילה עבור אותו ערוץ. העכבר מאחורי מקלט הוא ערוץ 0 |

המטענים יוצרים זרם בייטים של אירועים:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## קריאת הסוללה

הדרייבר חוזר על מה שהאפליקציה עושה כשמקלט מחובר (`send_event_query`, `send_event_ping`):

1. אל המקלט: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), ולאחר מכן פינגים `00 84 0E 04 00 00`. ההתקן שולח רק בזמן שהמארח ממשיך לכתוב, ולכן המארח שולח פינג. המקלט עונה `CMD_QUERY_RESULT` (`02`) עם JSON, למשל `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. אותה שאילתה ואותם פינגים עבור ערוץ 0, עם קידומת `C0`. העכבר עונה באובייקט JSON בן ~550 בייטים במקטעי ESB בני 30 בייטים, למשל `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`. `battery` הוא אחוז (RAWM HUB מציג אותו כמות שהוא), `chr` הוא 1 בזמן טעינה.
3. שינויים מאוחרים יותר מגיעים כ-`CMD_NOTIFY` (`0B`) מסוג `17`: `[17, percent, charging]`.

הדרייבר תמיד שואל קודם את המקלט, כפי שעושה האפליקציה (בבדיקה אחת, שאילתה שנשלחה רק לערוץ 0 לא קיבלה תשובה). עכבר במצב שינה אינו עונה כלל; המקלט עדיין עונה.

השאילתה נושאת את שעון המחשב מפני שכך האפליקציה שולחת אותה; דבר נוסף אינו נכתב. עכברים מדווחים `"crc":1`, מה שאומר לאפליקציה לעטוף פקודות מאוחרות יותר (תצורה) במסגרת CRC-16; השאילתה והפינגים מתקבלים ללא אחת כזו, מאחר שהאפליקציה שולחת אותם לפני שהיא יודעת זאת.

נבדק על Leviathan V4 (קושחה 1.2.0) עם מקלט ה-RAWM HS `1915:2346` (קושחה 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **מדור:** VAXEE (`docs/vaxee.md`) · [מקור באנגלית](../../docs/vaxee.md) · [↑ לראש הדף](#top)

# מקלטי VAXEE 4K/8K ו-ZYGEN NP-01S V2

## היקף ואימות חומרה

דרייבר זה תומך במקלט VAXEE 4K `3057:1002`, במקלט VAXEE 8K `3057:2002` וב-ZYGEN NP-01S V2 Wireless דרך כבל USB (`3057:1011`), באוסף היצרן שלהם `FF05:0001` עם דוח feature בן 64 בייטים. מקלטי VAXEE אחרים, מזהי מוצר אחרים של כבל והתקני ZOWIE אינם נבדקים במכוון.

מקלט ה-8K (`VAXEE 8K Wireless`, מצומד ל-NP-01 Ergo Wireless 8K) נבדק ב-Windows ודיווח דרך אותו פרוטוקול:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

המקלט משותף לכל עכברי VAXEE 8K ואינו מדווח איזה מהם מצומד, ולכן הוא מוצג בשם שלו עצמו. מצב טעינה על מקלט ה-8K טרם נצפה בחומרה.

מקלט 4K אמיתי נבדק ב-Windows:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

האפליקציה המשולבת דיווחה גם:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

אותו עכבר חובר לאחר מכן ישירות דרך USB ו-Windows זיהה אותו כ-`ZYGEN NP-01S V2 Wireless` (`3057:1011`). הדרייבר הייצורי המעודכן דיווח:

```
VAXEE battery: 75%; charging: yes
```

ווידג'ט שורת המשימות נוצר בהצלחה בבניית המקלט הראשונית. הן פעולה על סוללה דרך המקלט והן טעינה חוטית נצפו; מעברי טעינה מלאה והתנהגות בשינה/כיבוי לא נבדקו בחומרה. פענוח טעינה ותשובות לא תקינות מכוסים על ידי תשובות מדומות.

## פרוטוקול

מקור: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

בקשה היא דוח HID feature בן 64 בייטים מרופד באפסים:

| בייט | ערך |
|---|---|
| 0 | `0E`, מזהה דוח |
| 1 | `A5`, כותרת |
| 2 | `0B` עבור רמת סוללה; `10` עבור מצב טעינה |
| 3 | `01`, דגל קריאה (לעולם לא `02`, כתיבה) |
| 4 | `01`, אורך נתונים |
| 5–63 | `00` |

לאחר שליחת הבקשה עם `HidD_SetFeature`, המתן 100 אלפיות שנייה וקרא דוח `0E` עם `HidD_GetFeature`. דרוש לפחות שישה בייטים ואת מזהה הדוח, הכותרת, הד הפקודה ואורך הנתונים הצפויים.

עבור סוללה, בייט 5 בתשובה חייב להיות 0–20 והוא מוכפל בחמש, מה שנותן 0–100% בצעדים של 5%. עבור טעינה, בייט 5 שונה מאפס בעת טעינה. שאילתת טעינה שנכשלה אינה משליכה קריאת סוללה תקינה כשלעצמה.

הדרייבר מנסה שוב את בקשת הסוללה פעם אחת. יש לכל היותר שלוש בקשות קריאה לכל אוסף תואם (שני ניסיונות סוללה ושאילתת טעינה אחת), עם עיכוב מפורש כולל של 300 אלפיות שנייה. הוא אינו שולח שום פקודות הגדרות, צימוד, קושחה או תאורה.

אם לא מתקבלת תשובת סוללה תקינה, הדרייבר אינו מדווח דבר ומשאיר את ההתקן לא תבוע. בזמן שאוסף ה-USB נשאר נוכח, ממשק המשתמש שומר על קריאה מוצלחת קודמת, מעומעמת, למשך עד 30 דקות באמצעות התנהגות תקופת החסד הקיימת שלו. אם האוסף הפיזי נעלם, הדרייבר פולט מצב מנותק אחד כדי לסיים תקופת חסד זו מיד. דבר זה מונע מסמל מקלט ישן להישאר כאשר הכבל מועבר לעכבר.

## בדיקות

`make test` כולל את `tests/vaxee_driver_test.cpp`, המקשר את הדרייבר הייצורי מול תובלת HID מדומה. הוא בודק את הבקשות היוצאות לקריאה בלבד המדויקות, המרת האחוזים, פענוח הטעינה, תשובות לא תקינות וחסרות, התקנים שכבר נתבעו וסינון אוסף מדויק.
