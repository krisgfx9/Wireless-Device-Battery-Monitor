// UI translations from static external text files on Windows. See i18n.h and i18n_core.h.
#include "i18n.h"
#include "i18n_core.h"

#include <windows.h>
#include <shellapi.h>
#include <shlobj.h>

#include <algorithm>
#include <string>
#include <vector>

namespace {

const wchar_t kSettingsKey[] = L"Software\\WirelessBattery";
constexpr DWORD kMaxLangBytes = 512 * 1024;

i18n_core::Catalog g_catalog;
std::wstring g_choice;

std::string ReadUtf8File(const std::wstring& path, DWORD maxBytes) {
    HANDLE h = CreateFileW(path.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, 0, nullptr);
    if (h == INVALID_HANDLE_VALUE) return {};
    LARGE_INTEGER sz{};
    if (!GetFileSizeEx(h, &sz) || sz.QuadPart <= 0 || sz.QuadPart > maxBytes) {
        CloseHandle(h);
        return {};
    }
    std::string data(static_cast<size_t>(sz.QuadPart), '\0');
    DWORD got = 0;
    BOOL ok = ReadFile(h, data.data(), static_cast<DWORD>(data.size()), &got, nullptr);
    CloseHandle(h);
    if (!ok) return {};
    data.resize(got);
    return data;
}

void WriteUtf8File(const std::wstring& path, const std::string& data) {
    HANDLE h = CreateFileW(path.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (h == INVALID_HANDLE_VALUE) return;
    DWORD written = 0;
    WriteFile(h, data.data(), static_cast<DWORD>(data.size()), &written, nullptr);
    CloseHandle(h);
}

std::wstring UserFolder() {
    wchar_t path[MAX_PATH] = {};
    if (FAILED(SHGetFolderPathW(nullptr, CSIDL_APPDATA, nullptr, 0, path))) return L"";
    return std::wstring(path) + L"\\WirelessBattery\\lang";
}

std::wstring ExeFolder() {
    wchar_t path[MAX_PATH] = {};
    GetModuleFileNameW(nullptr, path, MAX_PATH);
    std::wstring p = path;
    size_t slash = p.find_last_of(L'\\');
    return slash == std::wstring::npos ? L"" : p.substr(0, slash);
}

void LoadFolder(const std::wstring& dir) {
    if (dir.empty()) return;
    WIN32_FIND_DATAW fd;
    HANDLE f = FindFirstFileW((dir + L"\\*.json").c_str(), &fd);
    if (f == INVALID_HANDLE_VALUE) return;
    std::vector<std::wstring> files;
    do {
        std::wstring file = fd.cFileName;
        if (file.empty() || file[0] == L'_' || fd.nFileSizeHigh != 0 || fd.nFileSizeLow > kMaxLangBytes) continue;
        files.push_back(file);
    } while (FindNextFileW(f, &fd));
    FindClose(f);
    std::sort(files.begin(), files.end());
    for (const auto& file : files) {
        std::string data = ReadUtf8File(dir + L"\\" + file, kMaxLangBytes);
        if (!data.empty() && file.size() > 5) {
            g_catalog.AddSource(data, file.substr(0, file.size() - 5));
        }
    }
}

std::vector<std::wstring> PreferredWindowsLanguages() {
    std::vector<std::wstring> out;
    ULONG count = 0, size = 0;
    if (!GetUserPreferredUILanguages(MUI_LANGUAGE_NAME, &count, nullptr, &size) || !size) return out;
    std::wstring buf(size, 0);
    if (!GetUserPreferredUILanguages(MUI_LANGUAGE_NAME, &count, buf.data(), &size)) return out;
    for (const wchar_t* p = buf.c_str(); *p; p += wcslen(p) + 1) {
        out.emplace_back(p);
    }
    return out;
}

void Apply() {
    g_catalog.Apply(g_choice, PreferredWindowsLanguages());
}

}  // namespace

namespace i18n {

void Init() {
    g_catalog.Clear();
    LoadFolder(ExeFolder() + L"\\lang");
    LoadFolder(UserFolder());
    wchar_t buf[64] = {};
    DWORD size = sizeof(buf) - sizeof(wchar_t);
    g_choice = RegGetValueW(HKEY_CURRENT_USER, kSettingsKey, L"Language", RRF_RT_REG_SZ, nullptr, buf, &size) == ERROR_SUCCESS ? buf : L"";
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
    RegSetKeyValueW(HKEY_CURRENT_USER, kSettingsKey, L"Language", REG_SZ, code.c_str(), (DWORD)((code.size() + 1) * sizeof(wchar_t)));
    Apply();
}

bool Rtl() { return g_catalog.Rtl(); }

void OpenUserFolder() {
    std::wstring dir = UserFolder();
    if (dir.empty()) return;
    SHCreateDirectoryExW(nullptr, dir.c_str(), nullptr);
    std::string tmpl = ReadUtf8File(ExeFolder() + L"\\lang\\_template.json", kMaxLangBytes);
    if (!tmpl.empty()) {
        WriteUtf8File(dir + L"\\_template.json", tmpl);
    }
    ShellExecuteW(nullptr, L"open", dir.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

}  // namespace i18n

const wchar_t* T(const wchar_t* en) { return g_catalog.Translate(en); }

std::wstring T(const std::wstring& en) { return T(en.c_str()); }

std::wstring TF(const wchar_t* en, std::initializer_list<std::pair<const wchar_t*, std::wstring>> args) {
    return g_catalog.Format(en, args);
}
