#include "i18n.h"

#include <windows.h>

#include <cwchar>

namespace {

struct Entry { const wchar_t* en; const wchar_t* tr; };

// Hebrew. To add a language, add a table and pick it in Table().
const Entry kHebrew[] = {
    { L"off / not connected", L"כבוי / לא מחובר" },
    { L"% (last known)", L"% (ערך אחרון ידוע)" },
    { L"unknown", L"לא ידוע" },
    { L", charging", L", בטעינה" },
    { L", asleep", L", במצב שינה" },
    { L"No devices with battery info found", L"לא נמצאו התקנים עם מידע על סוללה" },
    { L"Low battery", L"סוללה חלשה" },
    { L"%s is at %d%%", L"%s: נשארו %d%%" },
    { L"Point at a device to show, hide or move it", L"הצבע על התקן כדי להציג, להסתיר או להזיז אותו" },
    { L"Show on the taskbar", L"הצג בשורת המשימות" },
    { L"Show in the tray", L"הצג במגש המערכת" },
    { L"Move left", L"הזז שמאלה" },
    { L"Move right", L"הזז ימינה" },
    { L"Move up", L"הזז למעלה" },
    { L"Move down", L"הזז למטה" },
    { L"Hide last known / asleep devices", L"הסתר התקנים במצב שינה או עם ערך אחרון ידוע" },
    { L"Show on the taskbar (icon + percentage)", L"הצג בשורת המשימות (סמל + אחוזים)" },
    { L"Show as tray icons", L"הצג כסמלים במגש המערכת" },
    { L"Background behind taskbar text (for transparent taskbars)", L"רקע מאחורי הטקסט בשורת המשימות (לשורת משימות שקופה)" },
    { L"Show the widget on", L"הצג את הווידג'ט על" },
    { L"All monitors", L"כל המסכים" },
    { L"Main monitor only", L"המסך הראשי בלבד" },
    { L"%s only", L"%s בלבד" },
    { L"Chosen monitor (not connected, shown on main)", L"המסך שנבחר (לא מחובר, מוצג בראשי)" },
    { L"Display ", L"מסך " },
    { L"Other monitor", L"מסך אחר" },
    { L" (left)", L" (משמאל)" },
    { L" (right)", L" (מימין)" },
    { L" (above)", L" (למעלה)" },
    { L" (below)", L" (למטה)" },
    { L"Refresh now", L"רענן עכשיו" },
    { L"Start with Windows", L"הפעל עם Windows" },
    { L"Request support for a device...", L"בקשת תמיכה בהתקן..." },
    { L"Support the project...", L"תמיכה בפרויקט..." },
    { L"Exit", L"יציאה" },
    // Parts of a device with several batteries (earbuds).
    { L"L", L"שמאל" },
    { L"R", L"ימין" },
    { L"case", L"נרתיק" },
    // Request support for a device
    { L"Wireless Battery: request support for a device", L"Wireless Battery: בקשת תמיכה בהתקן" },
    { L"Is one of your devices not shown? Pick it below and send it to us. It goes on the public request list at "
      L"krisgfx.com/tools, and we'll look into supporting it.",
      L"אחד ההתקנים שלך לא מוצג? בחר אותו כאן ושלח אותו אלינו. הבקשה תופיע ברשימת הבקשות הציבורית ב-krisgfx.com/tools, "
      L"ונבדוק איך לתמוך בו." },
    { L"Device", L"התקן" },
    { L"Scanning devices...", L"סורק התקנים..." },
    { L"Device name (as it's sold)", L"שם ההתקן (כפי שהוא נמכר)" },
    { L"Type", L"סוג" },
    { L"mouse", L"עכבר" },
    { L"keyboard", L"מקלדת" },
    { L"headset", L"אוזניות" },
    { L"controller", L"בקר משחק" },
    { L"other", L"אחר" },
    { L"Your name (optional, kept private and never shown)", L"השם שלך (לא חובה, נשמר פרטי ולא מוצג אף פעם)" },
    { L"Anything else we should know? (optional)", L"עוד משהו שכדאי שנדע? (לא חובה)" },
    { L"This is exactly what will be sent:", L"זה בדיוק מה שיישלח:" },
    { L"Scanning your devices...", L"סורק את ההתקנים שלך..." },
    { L"Copy full report", L"העתק דוח מלא" },
    { L"Send", L"שלח" },
    { L"Close", L"סגור" },
    { L"My device is not in this list", L"ההתקן שלי לא ברשימה" },
    { L"Pick the device that isn't shown. Devices with a vendor-specific interface are listed first.",
      L"בחר את ההתקן שלא מוצג. התקנים עם ממשק ייעודי של היצרן מופיעים ראשונים." },
    { L"Device: ", L"התקן: " },
    { L"(type the device name)", L"(הקלד את שם ההתקן)" },
    { L"Type: ", L"סוג: " },
    { L"Your name: ", L"השם שלך: " },
    { L"(not sent)", L"(לא נשלח)" },
    { L" (kept private)", L" (נשמר פרטי)" },
    { L"Notes: ", L"הערות: " },
    { L"Sending...", L"שולח..." },
    { L"Collecting the full report (this takes about 10 seconds)...", L"אוסף את הדוח המלא (זה לוקח כ-10 שניות)..." },
    { L"The full report is copied. Paste it into a GitHub issue if we ask for more details.",
      L"הדוח המלא הועתק. הדבק אותו ב-issue ב-GitHub אם נבקש פרטים נוספים." },
    { L"Thank you! Your request was sent. You can follow it at %s.", L"תודה! הבקשה נשלחה. אפשר לעקוב אחריה ב-%s." },
    { L"You already sent this device in the last 24 hours, so it's on the list. Thank you!",
      L"כבר שלחת את ההתקן הזה ב-24 השעות האחרונות, כך שהוא כבר ברשימה. תודה!" },
    { L"The request was not accepted: ", L"הבקשה לא התקבלה: " },
    { L"please check the fields.", L"בדוק את השדות." },
    { L"Too many requests from your network. Please try again in an hour.", L"יותר מדי בקשות מהרשת שלך. נסה שוב בעוד שעה." },
    { L"Couldn't reach krisgfx.com. Check your connection, or use \"Copy full report\" and post it on GitHub.",
      L"אין חיבור ל-krisgfx.com. בדוק את החיבור, או לחץ על \"העתק דוח מלא\" ופרסם את הדוח ב-GitHub." },
    { L"The site answered with an error (%d). Please try again later.", L"האתר החזיר שגיאה (%d). נסה שוב מאוחר יותר." },
    // Battery levels of devices that only report a coarse level.
    { L"Full", L"מלאה" },
    { L"Good", L"טובה" },
    { L"Medium", L"בינונית" },
    { L"Low", L"חלשה" },
    { L"Critical", L"קריטית" },
    { L"Empty", L"ריקה" },
    // How a device is connected (DeviceStatus::via).
    { L"USB cable", L"כבל USB" },
    { L"2.4 GHz receiver", L"מקלט 2.4GHz" },
    { L"2.4 GHz receiver / USB", L"מקלט 2.4GHz / USB" },
    { L"2.4 GHz receiver or USB", L"מקלט 2.4GHz או USB" },
    { L"USB base station", L"תחנת בסיס USB" },
    { L"Jabra Link dongle", L"מתאם Jabra Link" },
    { L"Logitech receiver", L"מקלט Logitech" },
    { L"Razer receiver", L"מקלט Razer" },
    { L"Corsair receiver", L"מקלט Corsair" },
    { L"Wireless adapter", L"מתאם אלחוטי" },
    { L"UWB base station", L"תחנת בסיס UWB" },
};

LANGID UiLang() { return PRIMARYLANGID(GetUserDefaultUILanguage()); }

}  // namespace

const wchar_t* T(const wchar_t* en) {
    if (UiLang() != LANG_HEBREW) return en;
    for (const auto& e : kHebrew)
        if (!wcscmp(e.en, en)) return e.tr;
    return en;
}

bool UiRtl() {
    LANGID l = UiLang();
    return l == LANG_HEBREW || l == LANG_ARABIC || l == LANG_PERSIAN || l == LANG_URDU;
}
