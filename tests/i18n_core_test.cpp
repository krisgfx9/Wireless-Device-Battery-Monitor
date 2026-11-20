#include "i18n_core.h"
#ifdef TEST_LINUX_I18N
#include "i18n.h"
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <set>
#include <string>
#include <vector>

#ifndef _WIN32
#include <unistd.h>
#endif

namespace fs = std::filesystem;

static std::string ReadBytes(const fs::path& p) {
    std::ifstream in(p, std::ios::binary);
    assert(in && "Failed to open file");
    return std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
}

static std::vector<std::wstring> ExtractPlaceholders(const std::wstring& s) {
    std::vector<std::wstring> out;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == L'{') {
            size_t end = s.find(L'}', i + 1);
            if (end != std::wstring::npos) {
                out.push_back(s.substr(i, end - i + 1));
                i = end;
            }
        }
    }
    std::sort(out.begin(), out.end());
    return out;
}

static void TestParsingAndEscaping() {
    i18n_core::Catalog cat;
    const std::string data =
        "\xEF\xBB\xBF"
        "{\r\n"
        "  \"@code\": \"ar\",\r\n"
        "  \"@name\": \"العربية\",\r\n"
        "  \"@rtl\": true,\r\n"
        "  \"_comment\": [\"ignored\", {\"nested\": true}],\r\n"
        "  \"Refresh now\": \"تحديث الآن\",\r\n"
        "  \"Line\\nBreak\": \"سطر\\nجديد\\\\\\\"اقتباس\\\"\",\r\n"
        "  \"Unicode\": \"\\u0645\\u0631\\u062D\\u0628\\u0627\",\r\n"
        "  \"Emoji\": \"\\uD83D\\uDD0B\",\r\n"
        "  \"EmptyValue\": \"\",\r\n"
        "  \"NullValue\": null\r\n"
        "}\r\n";
    cat.AddSource(data, L"fallback");
    cat.Apply(L"ar", {});
    assert(cat.Rtl());
    assert(cat.ActiveCode() == L"ar");
    assert(std::wstring(cat.Translate(L"Refresh now")) == L"تحديث الآن");
    assert(std::wstring(cat.Translate(L"Line\nBreak")) == L"سطر\nجديد\\\"اقتباس\"");
    assert(std::wstring(cat.Translate(L"Unicode")) == L"مرحبا");
    assert(std::wstring(cat.Translate(L"Emoji")) == Utf8ToWide("\xF0\x9F\x94\x8B"));
    assert(std::wstring(cat.Translate(L"EmptyValue")) == L"EmptyValue");
    assert(std::wstring(cat.Translate(L"NullValue")) == L"NullValue");
    assert(std::wstring(cat.Translate(L"Untranslated")) == L"Untranslated");

    // Ignore English ("en") source
    cat.AddSource("{\"@code\": \"en\", \"@name\": \"English\", \"Refresh now\": \"Ignored\"}", L"en");
    assert(cat.Available().size() == 2);
}

static void TestOverridePrecedence() {
    i18n_core::Catalog cat;
    cat.AddSource("{\"@code\": \"fr\", \"@name\": \"Français\", \"@rtl\": false, \"Save\": \"Enregistrer\", \"Cancel\": \"Annuler\"}", L"fr");
    cat.AddSource("{\"@code\": \"fr\", \"Cancel\": \"Fermer\", \"Save\": \"\"}", L"fr");
    cat.Apply(L"fr", {});
    assert(!cat.Rtl());
    assert(std::wstring(cat.Translate(L"Save")) == L"Enregistrer");
    assert(std::wstring(cat.Translate(L"Cancel")) == L"Fermer");
}

static void TestLocaleResolution() {
    i18n_core::Catalog cat;
    cat.AddSource("{\"@code\": \"zh-CN\", \"@name\": \"简体中文\", \"Exit\": \"退出\"}", L"zh-CN");
    cat.AddSource("{\"@code\": \"zh-TW\", \"@name\": \"繁體中文\", \"Exit\": \"結束\"}", L"zh-TW");
    cat.AddSource("{\"@code\": \"pt-BR\", \"@name\": \"Português (Brasil)\", \"Exit\": \"Sair\"}", L"pt-BR");
    cat.AddSource("{\"@code\": \"de\", \"@name\": \"Deutsch\", \"Exit\": \"Beenden\"}", L"de");
    cat.AddSource("{\"@code\": \"fr\", \"@name\": \"Français\", \"Exit\": \"Quitter\"}", L"fr");
    cat.AddSource("{\"@code\": \"ar\", \"@name\": \"العربية\", \"@rtl\": 1, \"Exit\": \"خروج\"}", L"ar");

    assert(cat.ResolveAuto({ L"zh-Hant-TW" }) == L"zh-tw");
    assert(cat.ResolveAuto({ L"zh_HK.UTF-8" }) == L"zh-tw");
    assert(cat.ResolveAuto({ L"zh_MO" }) == L"zh-tw");
    assert(cat.ResolveAuto({ L"zh_CN.UTF-8" }) == L"zh-cn");
    assert(cat.ResolveAuto({ L"zh-SG" }) == L"zh-cn");
    assert(cat.ResolveAuto({ L"pt_PT" }) == L"pt-br");
    assert(cat.ResolveAuto({ L"de_DE.UTF-8@euro" }) == L"de");
    assert(cat.ResolveAuto({ L"en_US.UTF-8", L"fr_FR" }) == L"");
    assert(cat.ResolveAuto({ L"fr-CA" }) == L"fr");
    assert(cat.ResolveAuto({ L"ar-SA" }) == L"ar");

    cat.Apply(L"", { L"ar_EG.UTF-8" });
    assert(cat.Rtl());
    assert(std::wstring(cat.Translate(L"Exit")) == L"خروج");

    cat.Apply(L"en", { L"fr_FR" });
    assert(!cat.Rtl());
    assert(std::wstring(cat.Translate(L"Exit")) == L"Exit");
}

static void TestPosixLocaleEnv() {
    auto v1 = i18n_core::ParsePosixLocaleEnv("fr:de", nullptr, nullptr, nullptr);
    assert(v1.size() == 2 && v1[0] == L"fr" && v1[1] == L"de");

    auto v2 = i18n_core::ParsePosixLocaleEnv("fr:de", "C", nullptr, "ja_JP.UTF-8");
    assert(v2.empty());

    auto v3 = i18n_core::ParsePosixLocaleEnv(nullptr, "POSIX", nullptr, "de_DE.UTF-8");
    assert(v3.empty());

    auto v4 = i18n_core::ParsePosixLocaleEnv(nullptr, nullptr, "C", "de_DE.UTF-8");
    assert(v4.empty());

    auto v5 = i18n_core::ParsePosixLocaleEnv(nullptr, nullptr, "uk_UA.UTF-8", "ru_RU.UTF-8");
    assert(v5.size() == 2 && v5[0] == L"uk_UA.UTF-8" && v5[1] == L"ru_RU.UTF-8");

    auto v6 = i18n_core::ParsePosixLocaleEnv("zh_TW:en_US", nullptr, nullptr, "C.UTF-8");
    assert(v6.size() == 2 && v6[0] == L"zh_TW" && v6[1] == L"en_US");
}

static void TestFormatAndSorting() {
    i18n_core::Catalog cat;
    cat.AddSource("{\"@code\": \"tr\", \"@name\": \"Türkçe\", \"{name} is at {percent}%\": \"%{percent}: {name}\"}", L"tr");
    cat.AddSource("{\"@code\": \"de\", \"@name\": \"Deutsch\"}", L"de");

    auto avail = cat.Available();
    assert(avail.size() == 3);
    assert(avail[0].code == L"en" && avail[0].name == L"English");
    assert(avail[1].code == L"de");
    assert(avail[2].code == L"tr");

    cat.Apply(L"tr", {});
    std::wstring formatted = cat.Format(L"{name} is at {percent}%", { { L"name", L"Mouse" }, { L"percent", L"42" } });
    assert(formatted == L"%42: Mouse");
}

static void TestRepoStaticLangFiles() {
    fs::path langDir = fs::path("lang");
    assert(fs::exists(langDir / "_template.json") && "Run from repo root");

    std::string tmplUtf8 = ReadBytes(langDir / "_template.json");
    assert(tmplUtf8.rfind("\xEF\xBB\xBF", 0) != 0);

    std::vector<std::wstring> tmplKeys;
    i18n_core::ForEachJsonEntry(tmplUtf8, [&](const std::wstring& k, const std::wstring&) {
        if (!k.empty() && k[0] != L'@') tmplKeys.push_back(k);
    });
    assert(tmplKeys.size() >= 208);

    const std::vector<std::string> expectedCodes = {
        "ar", "de", "es", "fa", "fr", "he", "hu", "ja", "ko",
        "pl", "pt-BR", "ru", "sv", "tr", "uk", "vi", "zh-CN", "zh-TW"
    };
    const std::set<std::string> rtlCodes = { "ar", "fa", "he" };

    for (const auto& code : expectedCodes) {
        fs::path p = langDir / (code + ".json");
        assert(fs::exists(p) && "Missing language JSON file");
        std::string bytes = ReadBytes(p);
        assert(bytes.rfind("\xEF\xBB\xBF", 0) != 0 && "Unexpected UTF-8 BOM in lang/*.json");

        i18n_core::Catalog cat;
        std::wstring wcode = Utf8ToWide(code);
        cat.AddSource(bytes, wcode);
        auto avail = cat.Available();
        assert(avail.size() == 2);
        assert(i18n_core::NormalizeTag(avail[1].code) == i18n_core::NormalizeTag(wcode));
        assert(!avail[1].name.empty());

        cat.Apply(wcode, {});
        assert(cat.Rtl() == (rtlCodes.count(code) != 0));

        for (const auto& key : tmplKeys) {
            std::wstring tr = cat.Translate(key.c_str());
            assert(!tr.empty());
            if (tr == key) {
                bool foundNonEmpty = false;
                i18n_core::ForEachJsonEntry(bytes, [&](const std::wstring& fk, const std::wstring& fv) {
                    if (fk == key && !fv.empty()) foundNonEmpty = true;
                });
                if (!foundNonEmpty) {
                    std::fprintf(stderr, "Missing/empty key in %s: %ls\n", code.c_str(), key.c_str());
                    assert(false);
                }
            }
            assert(ExtractPlaceholders(tr) == ExtractPlaceholders(key));
        }
    }
}

#ifdef TEST_LINUX_I18N
static void TestLinuxI18nRuntime() {
    fs::path tmp = fs::temp_directory_path() / ("wb_i18n_test_" + std::to_string(getpid()));
    fs::remove_all(tmp);
    fs::path dataLang = tmp / "data" / "wireless-battery" / "lang";
    fs::path cfgDir = tmp / "cfg";
    fs::create_directories(dataLang);
    fs::create_directories(cfgDir);

    fs::copy_file("lang/_template.json", dataLang / "_template.json");
    fs::copy_file("lang/zh-CN.json", dataLang / "zh-CN.json");
    fs::copy_file("lang/ar.json", dataLang / "ar.json");

    setenv("XDG_DATA_HOME", (tmp / "data").c_str(), 1);
    setenv("XDG_CONFIG_HOME", cfgDir.c_str(), 1);
    setenv("LANGUAGE", "zh_CN", 1);

    i18n::Init();
    auto avail = i18n::Available();
    assert(avail.size() >= 3);
    assert(std::wstring(T(L"Refresh now")) != L"Refresh now");

    i18n::SetChoice(L"ar");
    assert(i18n::Rtl());
    i18n::SetChoice(L"en");
    assert(!i18n::Rtl());
    assert(std::wstring(T(L"Refresh now")) == L"Refresh now");

    std::string userDir = i18n::PrepareUserFolder();
    assert(!userDir.empty());
    assert(fs::exists(fs::path(userDir) / "_template.json"));

    fs::remove_all(tmp);
}
#endif

int main() {
    TestParsingAndEscaping();
    TestOverridePrecedence();
    TestLocaleResolution();
    TestPosixLocaleEnv();
    TestFormatAndSorting();
    TestRepoStaticLangFiles();
#ifdef TEST_LINUX_I18N
    TestLinuxI18nRuntime();
#endif
    std::puts("i18n core tests passed.");
    return 0;
}
