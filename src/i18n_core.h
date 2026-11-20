#pragma once
// Shared cross-platform UI translation loader and resolver (no OS UI headers).
#include "platform_compat.h"

#include <algorithm>
#include <cstdint>
#include <cstring>
#include <cwctype>
#include <initializer_list>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace i18n_core {

struct LanguageInfo {
    std::wstring code;  // "tr", "pt-BR", ...
    std::wstring name;  // in the language itself: "Türkçe", "Português (Brasil)"
};

struct Source {
    std::wstring code, name;
    bool rtl = false;
    std::vector<std::string> texts;  // UTF-8 JSON contents, lowest to highest precedence
};

inline std::wstring Lower(std::wstring s) {
    for (auto& c : s) {
        if (c >= L'A' && c <= L'Z') c = (wchar_t)(c - L'A' + L'a');
        else c = (wchar_t)std::towlower(c);
    }
    return s;
}

inline bool IsSpaceOrBom(wchar_t c) {
    return c == 0xFEFF || c == L' ' || c == L'\t' || c == L'\r' || c == L'\n' || c == L'\v' || c == L'\f' ||
           std::iswspace(c) != 0;
}

inline std::wstring Trim(const std::wstring& s) {
    size_t a = 0, b = s.size();
    while (a < b && IsSpaceOrBom(s[a])) a++;
    while (b > a && IsSpaceOrBom(s[b - 1])) b--;
    return s.substr(a, b - a);
}

// Normalizes locale tags: trims, strips ".encoding" / "@modifier", replaces '_' with '-', lowercases.
inline std::wstring NormalizeTag(std::wstring s) {
    s = Trim(s);
    size_t cut = std::wstring::npos;
    for (wchar_t sep : { L'.', L'@' }) {
        size_t pos = s.find(sep);
        if (pos != std::wstring::npos && (cut == std::wstring::npos || pos < cut)) cut = pos;
    }
    if (cut != std::wstring::npos) s.resize(cut);
    for (auto& c : s) {
        if (c == L'_') c = L'-';
    }
    return Lower(Trim(s));
}

namespace detail {

inline void SkipWs(const std::string& s, size_t& i) {
    while (i < s.size()) {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') ++i;
        else break;
    }
}

inline void AppendUtf8(std::string& out, uint32_t cp) {
    if (cp <= 0x7F) {
        out.push_back(static_cast<char>(cp));
    } else if (cp <= 0x7FF) {
        out.push_back(static_cast<char>(0xC0 | (cp >> 6)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else if (cp <= 0xFFFF) {
        out.push_back(static_cast<char>(0xE0 | (cp >> 12)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else if (cp <= 0x10FFFF) {
        out.push_back(static_cast<char>(0xF0 | (cp >> 18)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 12) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | ((cp >> 6) & 0x3F)));
        out.push_back(static_cast<char>(0x80 | (cp & 0x3F)));
    } else {
        out += "\xEF\xBF\xBD";
    }
}

inline bool ParseHex4(const std::string& s, size_t i, uint32_t& out) {
    if (i + 4 > s.size()) return false;
    uint32_t val = 0;
    for (size_t k = 0; k < 4; ++k) {
        char c = s[i + k];
        val <<= 4;
        if (c >= '0' && c <= '9') val |= static_cast<uint32_t>(c - '0');
        else if (c >= 'a' && c <= 'f') val |= static_cast<uint32_t>(c - 'a' + 10);
        else if (c >= 'A' && c <= 'F') val |= static_cast<uint32_t>(c - 'A' + 10);
        else return false;
    }
    out = val;
    return true;
}

inline bool ParseJsonString(const std::string& s, size_t& i, std::string& out) {
    out.clear();
    if (i >= s.size() || s[i] != '"') return false;
    ++i;
    while (i < s.size()) {
        char c = s[i++];
        if (c == '"') return true;
        if (c != '\\') {
            out.push_back(c);
            continue;
        }
        if (i >= s.size()) return false;
        char esc = s[i++];
        switch (esc) {
            case '"':  out.push_back('"'); break;
            case '\\': out.push_back('\\'); break;
            case '/':  out.push_back('/'); break;
            case 'b':  out.push_back('\b'); break;
            case 'f':  out.push_back('\f'); break;
            case 'n':  out.push_back('\n'); break;
            case 'r':  out.push_back('\r'); break;
            case 't':  out.push_back('\t'); break;
            case 'u': {
                uint32_t cp = 0;
                if (!ParseHex4(s, i, cp)) return false;
                i += 4;
                if (cp >= 0xD800 && cp <= 0xDBFF && i + 6 <= s.size() && s[i] == '\\' && s[i + 1] == 'u') {
                    uint32_t lo = 0;
                    if (ParseHex4(s, i + 2, lo) && lo >= 0xDC00 && lo <= 0xDFFF) {
                        cp = 0x10000 + (((cp - 0xD800) << 10) | (lo - 0xDC00));
                        i += 6;
                    }
                }
                AppendUtf8(out, cp);
                break;
            }
            default:
                out.push_back(esc);
                break;
        }
    }
    return false;
}

inline bool SkipJsonContainer(const std::string& s, size_t& i) {
    int depth = 0;
    std::string dummy;
    while (i < s.size()) {
        char c = s[i];
        if (c == '"') {
            if (!ParseJsonString(s, i, dummy)) return false;
            continue;
        }
        ++i;
        if (c == '{' || c == '[') {
            ++depth;
        } else if (c == '}' || c == ']') {
            if (--depth <= 0) return true;
        }
    }
    return false;
}

}  // namespace detail

// Calls fn(key, value) for every top-level entry in a flat UTF-8 JSON object.
template <class Fn>
inline void ForEachJsonEntry(const std::string& utf8, Fn fn) {
    size_t i = 0;
    if (utf8.size() >= 3 && static_cast<unsigned char>(utf8[0]) == 0xEF &&
        static_cast<unsigned char>(utf8[1]) == 0xBB && static_cast<unsigned char>(utf8[2]) == 0xBF) {
        i = 3;
    }
    detail::SkipWs(utf8, i);
    if (i >= utf8.size() || utf8[i] != '{') return;
    ++i;

    std::string keyUtf8, valUtf8;
    while (i < utf8.size()) {
        detail::SkipWs(utf8, i);
        if (i >= utf8.size() || utf8[i] == '}') break;

        if (!detail::ParseJsonString(utf8, i, keyUtf8)) break;
        detail::SkipWs(utf8, i);
        if (i >= utf8.size() || utf8[i] != ':') break;
        ++i;
        detail::SkipWs(utf8, i);
        if (i >= utf8.size()) break;

        char v = utf8[i];
        if (v == '"') {
            if (!detail::ParseJsonString(utf8, i, valUtf8)) break;
            fn(Utf8ToWide(keyUtf8), Utf8ToWide(valUtf8));
        } else if (utf8.compare(i, 4, "true") == 0) {
            i += 4;
            fn(Utf8ToWide(keyUtf8), std::wstring(L"true"));
        } else if (utf8.compare(i, 5, "false") == 0) {
            i += 5;
            fn(Utf8ToWide(keyUtf8), std::wstring(L"false"));
        } else if (utf8.compare(i, 4, "null") == 0) {
            i += 4;
            fn(Utf8ToWide(keyUtf8), std::wstring{});
        } else if (v == '{' || v == '[') {
            if (!detail::SkipJsonContainer(utf8, i)) break;
        } else {
            size_t start = i;
            while (i < utf8.size()) {
                char c = utf8[i];
                if ((c >= '0' && c <= '9') || c == '-' || c == '+' || c == '.' || c == 'e' || c == 'E') ++i;
                else break;
            }
            if (i == start) break;
            fn(Utf8ToWide(keyUtf8), Utf8ToWide(utf8.substr(start, i - start)));
        }

        detail::SkipWs(utf8, i);
        if (i < utf8.size() && utf8[i] == ',') {
            ++i;
            continue;
        }
        break;
    }
}

inline bool IsPosixCLocale(const char* s) {
    if (!s || !*s) return false;
    return std::strcmp(s, "C") == 0 || std::strcmp(s, "POSIX") == 0 || std::strncmp(s, "C.", 2) == 0;
}

// Extracts ordered preferred locale tags from POSIX environment variables.
inline std::vector<std::wstring> ParsePosixLocaleEnv(const char* language, const char* lcAll,
                                                     const char* lcMessages, const char* lang) {
    std::vector<std::wstring> tags;
    if (IsPosixCLocale(lcAll)) return tags;

    auto pushTag = [&](const std::string& raw) {
        if (raw.empty() || IsPosixCLocale(raw.c_str())) return;
        std::wstring w = Utf8ToWide(raw);
        if (!w.empty() && std::find(tags.begin(), tags.end(), w) == tags.end()) tags.push_back(std::move(w));
    };

    if (language && *language) {
        std::string s(language);
        size_t start = 0;
        while (start <= s.size()) {
            size_t colon = s.find(':', start);
            if (colon == std::string::npos) colon = s.size();
            pushTag(s.substr(start, colon - start));
            if (colon == s.size()) break;
            start = colon + 1;
        }
    }

    for (const char* v : { lcAll, lcMessages, lang }) {
        if (!v || !*v) continue;
        if (IsPosixCLocale(v)) break;
        pushTag(v);
    }
    return tags;
}

class Catalog {
public:
    void Clear() {
        sources_.clear();
        phrases_.clear();
        rtl_ = false;
        activeCode_.clear();
    }

    void AddSource(const std::string& utf8, const std::wstring& fallbackCode) {
        std::wstring code = fallbackCode, name;
        bool rtl = false;
        ForEachJsonEntry(utf8, [&](const std::wstring& k, const std::wstring& v) {
            if (k == L"@code" && !v.empty()) code = Trim(v);
            else if (k == L"@name") name = Trim(v);
            else if (k == L"@rtl") {
                std::wstring lv = Lower(Trim(v));
                rtl = (lv == L"1" || lv == L"yes" || lv == L"true");
            }
        });
        std::wstring key = NormalizeTag(code);
        if (key.empty() || key == L"en") return;  // English is the source text itself
        Source& s = sources_[key];
        if (s.code.empty()) s.code = Trim(code);
        if (!name.empty()) s.name = name;
        if (rtl) s.rtl = true;
        s.texts.push_back(utf8);
    }

    std::vector<LanguageInfo> Available() const {
        std::vector<LanguageInfo> out{ { L"en", L"English" } };
        for (const auto& [key, s] : sources_) {
            (void)key;
            out.push_back({ s.code, s.name.empty() ? s.code : s.name });
        }
        std::sort(out.begin() + 1, out.end(), [](const LanguageInfo& a, const LanguageInfo& b) {
            std::wstring la = Lower(a.name), lb = Lower(b.name);
            return la != lb ? la < lb : Lower(a.code) < Lower(b.code);
        });
        return out;
    }

    std::wstring ResolveAuto(const std::vector<std::wstring>& preferredTags) const {
        for (const auto& raw : preferredTags) {
            std::wstring tag = NormalizeTag(raw);
            if (tag.empty()) continue;
            if (tag == L"zh" || tag.rfind(L"zh-", 0) == 0) {
                bool trad = tag.find(L"hant") != std::wstring::npos || tag.find(L"-tw") != std::wstring::npos ||
                            tag.find(L"-hk") != std::wstring::npos || tag.find(L"-mo") != std::wstring::npos;
                std::wstring want = trad ? L"zh-tw" : L"zh-cn";
                if (sources_.count(want)) return want;
            }
            if (sources_.count(tag)) return tag;
            std::wstring base = tag.substr(0, tag.find(L'-'));
            if (base == L"en") return L"";
            if (sources_.count(base)) return base;
            for (const auto& [code, s] : sources_) {
                (void)s;
                if (code.rfind(base + L"-", 0) == 0) return code;
            }
        }
        return L"";
    }

    void Apply(const std::wstring& choice, const std::vector<std::wstring>& preferredTags) {
        phrases_.clear();
        rtl_ = false;
        activeCode_.clear();

        std::wstring code = choice.empty() ? ResolveAuto(preferredTags) : NormalizeTag(choice);
        if (code.empty() || code == L"en") return;
        auto it = sources_.find(code);
        if (it == sources_.end()) return;

        rtl_ = it->second.rtl;
        activeCode_ = it->second.code;
        for (const std::string& text : it->second.texts) {
            ForEachJsonEntry(text, [&](const std::wstring& k, const std::wstring& v) {
                if (!k.empty() && k[0] != L'@' && !v.empty()) {
                    phrases_[k] = v;
                }
            });
        }
    }

    const wchar_t* Translate(const wchar_t* en) const {
        if (!en || phrases_.empty()) return en;
        auto it = phrases_.find(en);
        return it == phrases_.end() ? en : it->second.c_str();
    }

    std::wstring Format(const wchar_t* en,
                        std::initializer_list<std::pair<const wchar_t*, std::wstring>> args) const {
        std::wstring s = Translate(en);
        for (const auto& [name, value] : args) {
            std::wstring tag = L"{" + std::wstring(name) + L"}";
            for (size_t at = s.find(tag); at != std::wstring::npos; at = s.find(tag, at + value.size())) {
                s.replace(at, tag.size(), value);
            }
        }
        return s;
    }

    bool Rtl() const { return rtl_; }
    std::wstring ActiveCode() const { return activeCode_; }

private:
    std::map<std::wstring, Source> sources_;
    std::unordered_map<std::wstring, std::wstring> phrases_;
    bool rtl_ = false;
    std::wstring activeCode_;
};

}  // namespace i18n_core
