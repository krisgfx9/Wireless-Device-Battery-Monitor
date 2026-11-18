#pragma once
// UI translations. English is the source text and the key; T() returns the translation for the
// Windows display language, or the English text when there is none.
#include <string>

const wchar_t* T(const wchar_t* en);
inline std::wstring T(const std::wstring& en) { return T(en.c_str()); }
// True when the display language is written right to left (menus and tooltips must be mirrored).
bool UiRtl();
