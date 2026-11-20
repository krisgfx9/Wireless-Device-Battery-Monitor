#pragma once
// UI translations from static external UTF-8 JSON files.
//
// A language is a flat JSON object mapping each English phrase to its translation:
//     {
//         "@code": "tr",
//         "@name": "Türkçe",
//         "Refresh now": "Şimdi yenile",
//         "{name} is at {percent}%": "{name}: %{percent} kaldı"
//     }
// Placeholders are named ({name}, {percent}), so a mistake in a translation can never crash the app.
// Empty or missing phrases stay English. Set "@rtl": true for right-to-left scripts.
//
// Where static language files come from (editable directly without rebuilding):
//  * Windows: a "lang" folder next to BatteryHub.exe, then %APPDATA%\WirelessBattery\lang (user files win).
//  * Linux: /usr/share/wireless-battery/lang, /usr/local/share/wireless-battery/lang,
//           $XDG_DATA_HOME/wireless-battery/lang, <exe>/lang, and $XDG_CONFIG_HOME/wireless-battery/lang.
// The --list / --dump output stays English on purpose (it is pasted into GitHub issues).
#include <initializer_list>
#include <string>
#include <utility>
#include <vector>

namespace i18n {

struct Language {
    std::wstring code;  // "tr", "pt-BR", ...
    std::wstring name;  // in the language itself: "Türkçe", "Português (Brasil)"
};

// Finds the static language files and applies the saved choice; call once at startup (or to refresh).
void Init();
// Every language that can be picked, English first.
std::vector<Language> Available();
// The saved choice: empty = follow the system display language.
std::wstring Choice();
// Saves the choice ("" = automatic) and switches to it.
void SetChoice(const std::wstring& code);
// True for right-to-left languages (Hebrew, Arabic, Persian): menus are laid out from the right.
bool Rtl();
// Prepares the user language folder with a fresh _template.json (and opens it on Windows).
void OpenUserFolder();
#ifndef _WIN32
// Creates $XDG_CONFIG_HOME/wireless-battery/lang with _template.json and returns its path.
std::string PrepareUserFolder();
#endif

}  // namespace i18n

// The translation of an English UI phrase, or the phrase itself.
const wchar_t* T(const wchar_t* en);
std::wstring T(const std::wstring& en);
// T() with named placeholders: TF(L"{name} is at {percent}%", { { L"name", n }, { L"percent", L"40" } }).
std::wstring TF(const wchar_t* en, std::initializer_list<std::pair<const wchar_t*, std::wstring>> args);
