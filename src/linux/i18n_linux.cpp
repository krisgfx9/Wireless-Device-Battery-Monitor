// UI translations from static external text files on Linux. See i18n.h and i18n_core.h.
#include "../i18n.h"
#include "../i18n_core.h"

#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#include <algorithm>
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <limits.h>
#include <string>
#include <vector>

namespace {

constexpr size_t kMaxLangBytes = 512 * 1024;

i18n_core::Catalog g_catalog;
std::wstring g_choice;

std::string ReadUtf8File(const std::string& path, size_t maxBytes) {
    struct stat st {};
    if (stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode) || st.st_size <= 0 ||
        static_cast<size_t>(st.st_size) > maxBytes) {
        return {};
    }
    std::ifstream in(path, std::ios::binary);
    if (!in) return {};
    std::string data(static_cast<size_t>(st.st_size), '\0');
    in.read(data.data(), static_cast<std::streamsize>(data.size()));
    if (in.gcount() <= 0) return {};
    data.resize(static_cast<size_t>(in.gcount()));
    return data;
}

bool MkdirP(const std::string& path) {
    if (path.empty()) return false;
    std::string cur;
    size_t i = 0;
    if (path[0] == '/') {
        cur = "/";
        i = 1;
    }
    while (i <= path.size()) {
        size_t slash = path.find('/', i);
        if (slash == std::string::npos) slash = path.size();
        if (slash > i) {
            cur += path.substr(i, slash - i);
            if (mkdir(cur.c_str(), 0700) != 0 && errno != EEXIST) return false;
            cur += '/';
        }
        i = slash + 1;
    }
    return true;
}

std::string ExeFolder() {
    char buf[PATH_MAX] = {};
    ssize_t len = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
    if (len <= 0) return {};
    std::string p(buf, static_cast<size_t>(len));
    size_t slash = p.find_last_of('/');
    return slash == std::string::npos ? std::string{} : p.substr(0, slash);
}

std::string EnvDir(const char* envName, const char* homeFallback) {
    const char* v = std::getenv(envName);
    if (v && *v) return v;
    const char* home = std::getenv("HOME");
    if (!home || !*home) return {};
    return std::string(home) + homeFallback;
}

std::string XdgDataLangDir() {
    std::string base = EnvDir("XDG_DATA_HOME", "/.local/share");
    return base.empty() ? std::string{} : base + "/wireless-battery/lang";
}

std::string UserLangDir() {
    std::string base = EnvDir("XDG_CONFIG_HOME", "/.config");
    return base.empty() ? std::string{} : base + "/wireless-battery/lang";
}

std::vector<std::string> StaticSearchDirsLowestFirst() {
    std::vector<std::string> dirs;
    dirs.emplace_back("/usr/share/wireless-battery/lang");
    dirs.emplace_back("/usr/local/share/wireless-battery/lang");
    if (std::string d = XdgDataLangDir(); !d.empty()) dirs.push_back(std::move(d));
    if (std::string e = ExeFolder(); !e.empty()) dirs.push_back(e + "/lang");
    return dirs;
}

void LoadFolder(const std::string& dir) {
    if (dir.empty()) return;
    DIR* d = opendir(dir.c_str());
    if (!d) return;
    std::vector<std::string> files;
    while (dirent* ent = readdir(d)) {
        std::string name = ent->d_name;
        if (name.empty() || name[0] == '.' || name[0] == '_') continue;
        if (name.size() <= 5 || name.compare(name.size() - 5, 5, ".json") != 0) continue;
        files.push_back(std::move(name));
    }
    closedir(d);
    std::sort(files.begin(), files.end());
    for (const auto& name : files) {
        std::string data = ReadUtf8File(dir + "/" + name, kMaxLangBytes);
        if (!data.empty()) {
            g_catalog.AddSource(data, Utf8ToWide(name.substr(0, name.size() - 5)));
        }
    }
}

void Apply() {
    auto preferred = i18n_core::ParsePosixLocaleEnv(
        std::getenv("LANGUAGE"), std::getenv("LC_ALL"), std::getenv("LC_MESSAGES"), std::getenv("LANG"));
    g_catalog.Apply(g_choice, preferred);
}

}  // namespace

namespace i18n {

void Init() {
    g_catalog.Clear();
    for (const auto& dir : StaticSearchDirsLowestFirst()) {
        LoadFolder(dir);
    }
    LoadFolder(UserLangDir());
    Apply();
}

std::vector<Language> Available() {
    std::vector<Language> out;
    for (const auto& item : g_catalog.Available()) {
        out.push_back({ item.code, item.name });
    }
    return out;
}

std::wstring Choice() { return g_choice; }

void SetChoice(const std::wstring& code) {
    g_choice = code;
    Apply();
}

bool Rtl() { return g_catalog.Rtl(); }

std::string PrepareUserFolder() {
    std::string dir = UserLangDir();
    if (dir.empty()) return {};
    MkdirP(dir);
    auto dirs = StaticSearchDirsLowestFirst();
    std::string tmpl;
    for (auto it = dirs.rbegin(); it != dirs.rend(); ++it) {
        tmpl = ReadUtf8File(*it + "/_template.json", kMaxLangBytes);
        if (!tmpl.empty()) break;
    }
    if (!tmpl.empty()) {
        std::ofstream out(dir + "/_template.json", std::ios::binary | std::ios::trunc);
        if (out) out.write(tmpl.data(), static_cast<std::streamsize>(tmpl.size()));
    }
    return dir;
}

void OpenUserFolder() {
    PrepareUserFolder();
}

}  // namespace i18n

const wchar_t* T(const wchar_t* en) { return g_catalog.Translate(en); }

std::wstring T(const std::wstring& en) { return T(en.c_str()); }

std::wstring TF(const wchar_t* en, std::initializer_list<std::pair<const wchar_t*, std::wstring>> args) {
    return g_catalog.Format(en, args);
}
