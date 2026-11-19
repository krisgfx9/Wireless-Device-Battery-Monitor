// UI translations from plain text files on Linux. See src/i18n.h.
#include "../i18n.h"
#include "../platform_compat.h"

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <wchar.h>

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <cwctype>
#include <fstream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace {

struct Source {
    std::wstring code, name;
    bool rtl = false;
    std::vector<std::string> texts;  // UTF-8 file contents: built-in first, then user files
};

std::map<std::wstring, Source> g_sources;                  // by lower-case code
std::unordered_map<std::wstring, std::wstring> g_phrases;  // English -> translation, for the active language
std::wstring g_choice;                                     // saved choice, "" = automatic
bool g_rtl = false;
std::string g_template;                                    // lang/_template.txt, every English phrase

std::wstring Lower(std::wstring s) {
    for (auto& c : s) c = (wchar_t)towlower(c);
    return s;
}

std::string LowerAscii(std::string s) {
    for (auto& c : s) {
        if (c >= 'A' && c <= 'Z') c = (char)(c - 'A' + 'a');
    }
    return s;
}

std::wstring Wide(const std::string& s) {
    return Utf8ToWide(s);
}

std::wstring Trim(const std::wstring& s) {
    size_t a = 0, b = s.size();
    while (a < b && (iswspace(s[a]) || s[a] == 0xFEFF)) a++;
    while (b > a && iswspace(s[b - 1])) b--;
    return s.substr(a, b - a);
}

std::string TrimUtf8(const std::string& s) {
    size_t a = 0, b = s.size();
    while (a < b && (unsigned char)s[a] <= ' ') a++;
    while (b > a && (unsigned char)s[b - 1] <= ' ') b--;
    return s.substr(a, b - a);
}

// "\n" -> line break, "\\" -> backslash.
std::wstring Unescape(const std::wstring& s) {
    std::wstring out;
    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == L'\\' && i + 1 < s.size()) {
            wchar_t n = s[++i];
            out += n == L'n' ? L'\n' : n;
        } else {
            out += s[i];
        }
    }
    return out;
}

// Calls fn(key, value) for every "key = value" line; metadata keys start with '@'.
template <class Fn>
void ForEachLine(const std::string& utf8, Fn fn) {
    std::wstring text = Wide(utf8);
    size_t pos = 0;
    while (pos <= text.size()) {
        size_t end = text.find(L'\n', pos);
        if (end == std::wstring::npos) end = text.size();
        std::wstring line = Trim(text.substr(pos, end - pos));
        pos = end + 1;
        if (line.empty() || line[0] == L'#') continue;
        size_t eq = line.find(L" = ");
        if (eq == std::wstring::npos) continue;
        fn(Trim(line.substr(0, eq)), Trim(line.substr(eq + 3)));
    }
}

void AddSource(const std::string& utf8, const std::wstring& fallbackCode) {
    std::wstring code = fallbackCode, name;
    bool rtl = false;
    ForEachLine(utf8, [&](const std::wstring& k, const std::wstring& v) {
        if (k == L"@code") code = v;
        else if (k == L"@name") name = v;
        else if (k == L"@rtl") rtl = v == L"1" || Lower(v) == L"yes" || Lower(v) == L"true";
    });
    if (code.empty() || Lower(code) == L"en") return;
    Source& s = g_sources[Lower(code)];
    if (s.code.empty()) s.code = code;
    if (!name.empty()) s.name = name;
    if (rtl) s.rtl = true;
    // Avoid duplicating exact identical text payloads when scanning multiple search paths
    for (const auto& existing : s.texts) {
        if (existing == utf8) return;
    }
    s.texts.push_back(utf8);
}

std::string XdgConfigHome() {
    const char* xdg = std::getenv("XDG_CONFIG_HOME");
    if (xdg && *xdg) return std::string(xdg);
    const char* home = std::getenv("HOME");
    if (home && *home) return std::string(home) + "/.config";
    return "/tmp";
}

std::string ConfigFilePath() {
    return XdgConfigHome() + "/wireless-battery/config.ini";
}

std::string UserLangFolder() {
    return XdgConfigHome() + "/wireless-battery/lang";
}

void EnsureDirRecursive(const std::string& dir) {
    if (dir.empty()) return;
    std::string cur;
    if (dir[0] == '/') cur = "/";
    size_t pos = 0;
    while (pos < dir.size()) {
        size_t slash = dir.find('/', pos);
        std::string part = slash == std::string::npos ? dir.substr(pos) : dir.substr(pos, slash - pos);
        if (!part.empty()) {
            if (!cur.empty() && cur.back() != '/') cur += '/';
            cur += part;
            mkdir(cur.c_str(), 0700);
        }
        if (slash == std::string::npos) break;
        pos = slash + 1;
    }
}

std::string ExeFolder() {
    char buf[4096] = {};
    ssize_t n = readlink("/proc/self/exe", buf, sizeof(buf) - 1);
    if (n <= 0) return "";
    buf[n] = '\0';
    std::string p(buf);
    size_t slash = p.find_last_of('/');
    return slash == std::string::npos ? "" : p.substr(0, slash);
}

bool ReadFileToString(const std::string& path, std::string& out) {
    struct stat st{};
    if (stat(path.c_str(), &st) != 0 || !S_ISREG(st.st_mode) || st.st_size > 512 * 1024) return false;
    std::ifstream in(path, std::ios::binary);
    if (!in) return false;
    std::ostringstream ss;
    ss << in.rdbuf();
    out = ss.str();
    return true;
}

void LoadFolder(const std::string& dir) {
    if (dir.empty()) return;
    DIR* d = opendir(dir.c_str());
    if (!d) return;
    std::vector<std::string> files;
    while (struct dirent* ent = readdir(d)) {
        std::string name = ent->d_name;
        if (name.size() > 4 && name.substr(name.size() - 4) == ".txt") {
            files.push_back(name);
        }
    }
    closedir(d);
    std::sort(files.begin(), files.end());
    for (const std::string& file : files) {
        std::string full = dir + "/" + file;
        std::string data;
        if (!ReadFileToString(full, data)) continue;
        if (file == "_template.txt") {
            if (g_template.empty()) g_template = data;
            continue;
        }
        if (file[0] == '_') continue;
        std::string stem = file.substr(0, file.size() - 4);
        AddSource(data, Wide(stem));
    }
}

// Built-in embedded Uzbek fallback & template so out-of-the-box execution works even if lang/ isn't in CWD.
const char* kEmbeddedTemplate =
    "# BatteryHub UI phrases. To add a language:\n"
    "#  1. Copy this file to xx.txt (xx = language code, e.g. \"it\" or \"pt-BR\") in the lang folder.\n"
    "#  2. Fill in @code and @name (the language in its own words); add \"@rtl = 1\" for right-to-left scripts.\n"
    "#  3. Write the translation after \" = \" on each line. Lines left empty stay English.\n"
    "@code = \n"
    "@name = \n\n"
    "off / not connected = \n"
    "{percent}% (last known) = \n"
    "unknown = \n"
    "charging = \n"
    "fully charged = \n"
    "asleep = \n"
    "No devices with battery info found = \n"
    "Low battery = \n"
    "Battery alerts = \n"
    "Battery alert = \n"
    "Use default (15%) = \n"
    "Default ({percent}%) = \n"
    "Disable notifications = \n"
    "Off = \n"
    "{name} is at {percent}% = \n"
    "Rename device... = \n"
    "Reset to original name = \n"
    "Reset to default = \n"
    "Device display name: = \n"
    "Rename device = \n"
    "Save = \n"
    "Cancel = \n"
    "Enter a name (1-64 characters). = \n"
    "Battery history... = \n"
    "Battery history = \n"
    "Last 24 hours = \n"
    "Last 7 days = \n"
    "Last 30 days = \n"
    "Hide last known / asleep devices = \n"
    "Hide sleeping / offline devices = \n"
    "Brand colors (Razer green, Logitech blue, ...) = \n"
    "Brand accent colors = \n"
    "Automatic (Windows language) = \n"
    "Automatic = \n"
    "Add your own language... = \n"
    "Language = \n"
    "Refresh now = \n"
    "Start with Windows = \n"
    "Start at login = \n"
    "Exit = \n"
    "Quit = \n";

const char* kEmbeddedUz =
    "@code = uz\n"
    "@name = O'zbekcha\n"
    "off / not connected = o'chirilgan / ulanmagan\n"
    "{percent}% (last known) = {percent}% (oxirgi ma'lum)\n"
    "unknown = noma'lum\n"
    "charging = quvvatlanmoqda\n"
    "fully charged = to'liq quvvatlangan\n"
    "asleep = uyqu rejimida\n"
    "No devices with battery info found = Batareya ma'lumotiga ega qurilmalar topilmadi\n"
    "Low battery = Quvvat kam\n"
    "Battery alerts = Batareya bildirishnomalari\n"
    "Battery alert = Batareya bildirishnomasi\n"
    "Use default (15%) = Standart (15%)\n"
    "Default ({percent}%) = Standart ({percent}%)\n"
    "Default (15%) = Standart (15%)\n"
    "Disable notifications = Bildirishnomalarni o'chirish\n"
    "Off = O'chirilgan\n"
    "{name} is at {percent}% = {name} quvvati: {percent}%\n"
    "Rename device... = Qurilma nomini o'zgartirish...\n"
    "Reset to original name = Asl nomini tiklash\n"
    "Reset to default = Standart holatga qaytarish\n"
    "Device display name: = Qurilmaning ko'rsatiladigan nomi:\n"
    "Rename device = Qurilma nomini o'zgartirish\n"
    "Save = Saqlash\n"
    "Cancel = Bekor qilish\n"
    "Enter a name (1-64 characters). = Nom kiriting (1-64 ta belgi).\n"
    "Battery history... = Batareya tarixi...\n"
    "Battery history = Batareya tarixi\n"
    "Last 24 hours = Oxirgi 24 soat\n"
    "Last 7 days = Oxirgi 7 kun\n"
    "Last 30 days = Oxirgi 30 kun\n"
    "Latest = Oxirgi\n"
    "Lowest = Eng past\n"
    "Highest = Eng yuqori\n"
    "Change = O'zgarish\n"
    "Readings = O'lchovlar\n"
    "pp = f.p.\n"
    "24h ago = 24 soat oldin\n"
    "{days} days ago = {days} kun oldin\n"
    "Blue: battery level; green: charging = Ko'k: batareya darajasi; yashil: quvvatlanish\n"
    "No readings yet. Keep BatteryHub running to collect history. = Hozircha ma'lumot yo'q. Tarixni yig'ish uchun BatteryHub ishlab tursin.\n"
    "No readings in this period = Ushbu davrda ma'lumotlar yo'q\n"
    "Now = Hozir\n"
    "Estimated time to empty = Quvvat tugashigacha taxminiy vaqt\n"
    "~{days} d {hours} h = ~{days} k {hours} soat\n"
    "~{hours} h = ~{hours} soat\n"
    "Recent discharge: {rate} pp/day · {count} readings = So'nggi sarf: kuniga {rate} f.p. · {count} ta o'lchov\n"
    "Currently charging = Hozir quvvatlanmoqda\n"
    "No remaining-time estimate while charging. = Quvvatlanish vaqtida qolgan vaqt hisoblanmaydi.\n"
    "No recent readings = So'nggi ma'lumotlar yo'q\n"
    "Connect the device to resume forecasting. = Prognozni davom ettirish uchun qurilmani ulang.\n"
    "Insufficient decline = Quvvat kamayishi yetarli emas\n"
    "A measurable discharge trend is required. = O'lchab bo'ladigan quvvat sarfi tendensiyasi talab qilinadi.\n"
    "Collecting data = Ma'lumotlar yig'ilmoqda\n"
    "Requires 4 readings, 2 hours and 3 percentage points of decline. = Kamida 4 ta o'lchov, 2 soat va 3 foiz punkt kamayish talab qilinadi.\n"
    "Clear device history = Qurilma tarixini tozalash\n"
    "Clear battery history for this device? = Ushbu qurilmaning batareya tarixi tozalansinmi?\n"
    "Hide last known / asleep devices = Oxirgi ma'lum / uyqudagi qurilmalarni yashirish\n"
    "Hide sleeping / offline devices = Uyqudagi / uzilgan qurilmalarni yashirish\n"
    "Show disconnected devices = Uzilgan qurilmalarni ko'rsatish\n"
    "Record battery history = Batareya tarixini yozib borish\n"
    "Brand colors (Razer green, Logitech blue, ...) = Brend ranglari (Razer yashili, Logitech ko'ki, ...)\n"
    "Brand accent colors = Brend aksent ranglari\n"
    "Automatic (Windows language) = Avtomatik (tizim tili)\n"
    "Automatic = Avtomatik\n"
    "Add your own language... = O'z tilingizni qo'shing...\n"
    "Language = Til\n"
    "Refresh now = Hozir yangilash\n"
    "Start with Windows = Tizim bilan birga ishga tushirish\n"
    "Start at login = Tizimga kirganda ishga tushirish\n"
    "Exit = Chiqish\n"
    "Quit = Chiqish\n"
    "Close = Yopish\n"
    "Full = To'liq\n"
    "Good = Yaxshi\n"
    "Medium = O'rtacha\n"
    "Low = Past\n"
    "Critical = Juda past\n"
    "Empty = Bo'sh\n";

void LoadBuiltIn() {
    AddSource(kEmbeddedUz, L"uz");
    std::string exeDir = ExeFolder();
    if (!exeDir.empty()) {
        LoadFolder(exeDir + "/lang");
        LoadFolder(exeDir + "/../lang");
        LoadFolder(exeDir + "/../share/wireless-battery/lang");
    }
    LoadFolder("./lang");
    LoadFolder("/usr/local/share/wireless-battery/lang");
    LoadFolder("/usr/share/wireless-battery/lang");
    if (g_template.empty()) g_template = kEmbeddedTemplate;
}

std::wstring MatchLocaleString(const std::string& rawLocale) {
    if (rawLocale.empty()) return L"";
    // Strip encoding (.UTF-8) and modifier (@latin)
    std::string loc = rawLocale;
    size_t dot = loc.find('.');
    if (dot != std::string::npos) loc = loc.substr(0, dot);
    size_t at = loc.find('@');
    if (at != std::string::npos) loc = loc.substr(0, at);
    for (char& c : loc) {
        if (c == '_') c = '-';
    }
    loc = LowerAscii(TrimUtf8(loc));
    if (loc.empty() || loc == "c" || loc == "posix") return L"";

    std::wstring tag = Wide(loc);
    if (tag.rfind(L"zh-", 0) == 0) {
        bool trad = tag.find(L"hant") != std::wstring::npos || tag.find(L"-tw") != std::wstring::npos ||
                    tag.find(L"-hk") != std::wstring::npos || tag.find(L"-mo") != std::wstring::npos;
        std::wstring want = trad ? L"zh-tw" : L"zh-cn";
        if (g_sources.count(want)) return want;
    }
    if (g_sources.count(tag)) return tag;
    std::wstring base = tag.substr(0, tag.find(L'-'));
    if (base == L"en") return L"";
    if (g_sources.count(base)) return base;
    for (const auto& [code, s] : g_sources) {
        if (code.rfind(base + L"-", 0) == 0) return code;
    }
    return L"";
}

std::wstring AutoCode() {
    const char* vars[] = { "LC_ALL", "LC_MESSAGES", "LANGUAGE", "LANG" };
    for (const char* v : vars) {
        const char* val = std::getenv(v);
        if (!val || !*val) continue;
        std::string s(val);
        // LANGUAGE can be colon-separated list e.g. "uz_UZ:ru:en"
        size_t pos = 0;
        while (pos <= s.size()) {
            size_t colon = s.find(':', pos);
            std::string item = colon == std::string::npos ? s.substr(pos) : s.substr(pos, colon - pos);
            std::wstring matched = MatchLocaleString(item);
            if (!matched.empty()) return matched;
            // If explicitly English before any other language, stop
            std::string low = LowerAscii(TrimUtf8(item));
            if (low == "en" || low.rfind("en_", 0) == 0 || low.rfind("en-", 0) == 0) return L"";
            if (colon == std::string::npos) break;
            pos = colon + 1;
        }
    }
    return L"";
}

std::wstring ReadLanguageFromConfig() {
    std::string content;
    if (!ReadFileToString(ConfigFilePath(), content)) return L"";
    std::istringstream ss(content);
    std::string line;
    bool inGeneral = false;
    while (std::getline(ss, line)) {
        std::string t = TrimUtf8(line);
        if (t.empty() || t[0] == '#' || t[0] == ';') continue;
        if (t.front() == '[' && t.back() == ']') {
            inGeneral = (t == "[general]");
            continue;
        }
        if (!inGeneral) continue;
        size_t eq = t.find('=');
        if (eq == std::string::npos) continue;
        std::string k = TrimUtf8(t.substr(0, eq));
        std::string v = TrimUtf8(t.substr(eq + 1));
        if (k == "language") return Wide(v);
    }
    return L"";
}

void WriteLanguageToConfig(const std::wstring& code) {
    std::string path = ConfigFilePath();
    std::string dir = path.substr(0, path.find_last_of('/'));
    EnsureDirRecursive(dir);

    std::string content;
    ReadFileToString(path, content);
    std::istringstream ss(content);
    std::vector<std::string> lines;
    std::string line;
    bool inGeneral = false;
    bool foundGeneral = false;
    bool wroteKey = false;
    std::string codeUtf8 = WideToUtf8(code);

    while (std::getline(ss, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();
        std::string t = TrimUtf8(line);
        if (!t.empty() && t.front() == '[' && t.back() == ']') {
            if (inGeneral && !wroteKey) {
                lines.push_back("language=" + codeUtf8);
                wroteKey = true;
            }
            inGeneral = (t == "[general]");
            if (inGeneral) foundGeneral = true;
            lines.push_back(line);
            continue;
        }
        if (inGeneral && !t.empty() && t[0] != '#' && t[0] != ';') {
            size_t eq = t.find('=');
            if (eq != std::string::npos && TrimUtf8(t.substr(0, eq)) == "language") {
                if (!wroteKey) {
                    lines.push_back("language=" + codeUtf8);
                    wroteKey = true;
                }
                continue;
            }
        }
        lines.push_back(line);
    }

    if (!foundGeneral) {
        if (!lines.empty() && !lines.back().empty()) lines.push_back("");
        lines.push_back("[general]");
        lines.push_back("language=" + codeUtf8);
    } else if (inGeneral && !wroteKey) {
        lines.push_back("language=" + codeUtf8);
    }

    std::ofstream out(path, std::ios::binary | std::ios::trunc);
    for (const auto& l : lines) {
        out << l << "\n";
    }
}

void Apply() {
    g_phrases.clear();
    g_rtl = false;
    std::wstring code = g_choice.empty() ? AutoCode() : Lower(g_choice);
    auto it = g_sources.find(code);
    if (it == g_sources.end()) return;  // English
    g_rtl = it->second.rtl;
    for (const std::string& text : it->second.texts) {
        ForEachLine(text, [](const std::wstring& k, const std::wstring& v) {
            if (!k.empty() && k[0] != L'@' && !v.empty()) g_phrases[Unescape(k)] = Unescape(v);
        });
    }
}

}  // namespace

namespace i18n {

void Init() {
    g_sources.clear();
    LoadBuiltIn();
    LoadFolder(UserLangFolder());
    g_choice = ReadLanguageFromConfig();
    Apply();
}

std::vector<Language> Available() {
    std::vector<Language> out{ { L"en", L"English" } };
    for (const auto& [code, s] : g_sources) {
        out.push_back({ s.code, s.name.empty() ? s.code : s.name });
    }
    std::sort(out.begin() + 1, out.end(), [](const Language& a, const Language& b) {
        return wcscasecmp(a.name.c_str(), b.name.c_str()) < 0;
    });
    return out;
}

std::wstring Choice() { return g_choice; }

void SetChoice(const std::wstring& code) {
    g_choice = code;
    WriteLanguageToConfig(code);
    Apply();
}

bool Rtl() { return g_rtl; }

void OpenUserFolder() {
    std::string dir = UserLangFolder();
    if (dir.empty()) return;
    EnsureDirRecursive(dir);
    std::string tmpl = dir + "/_template.txt";
    if (!g_template.empty()) {
        std::ofstream out(tmpl, std::ios::binary | std::ios::trunc);
        if (out) out.write(g_template.data(), (std::streamsize)g_template.size());
    }
    pid_t pid = fork();
    if (pid == 0) {
        execlp("xdg-open", "xdg-open", dir.c_str(), (char*)nullptr);
        _exit(0);
    }
}

// Convenience aliases for Linux callers
void Load() { Init(); }
void Reload() { Init(); }
std::vector<Language> Languages() { return Available(); }
std::wstring Current() { return Choice(); }
void Choose(const std::wstring& code) { SetChoice(code); }
bool IsRtl() { return Rtl(); }
void OpenFolder() { OpenUserFolder(); }
const wchar_t* Tr(const wchar_t* en) { return ::T(en); }
std::wstring Tr(const std::wstring& en) { return ::T(en); }
std::wstring Fmt(const wchar_t* en, std::initializer_list<std::pair<const wchar_t*, std::wstring>> args) {
    return ::TF(en, args);
}

}  // namespace i18n

const wchar_t* T(const wchar_t* en) {
    if (!en || g_phrases.empty()) return en;
    auto it = g_phrases.find(en);
    return it == g_phrases.end() ? en : it->second.c_str();
}

std::wstring T(const std::wstring& en) { return T(en.c_str()); }

std::wstring TF(const wchar_t* en, std::initializer_list<std::pair<const wchar_t*, std::wstring>> args) {
    std::wstring s = T(en);
    for (const auto& [name, value] : args) {
        std::wstring tag = L"{" + std::wstring(name) + L"}";
        for (size_t at = s.find(tag); at != std::wstring::npos; at = s.find(tag, at + value.size())) {
            s.replace(at, tag.size(), value);
        }
    }
    return s;
}
