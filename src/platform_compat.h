#pragma once
// Small portability layer so the shared vendor drivers compile unchanged on both platforms.
// On Windows this is just <windows.h> plus a couple of UTF-8 helpers. On Linux it supplies the
// handful of Windows typedefs/builtins the drivers use, implemented with the C++ standard library.
//
// NOTE FOR REVIEWERS: nothing here changes the Windows code path. It only gives the Linux build
// the same spellings for a few types and functions.

#include <string>

#ifdef _WIN32

#include <windows.h>

// Convert between UTF-8 and the platform's wchar_t (UTF-16 on Windows).
inline std::wstring Utf8ToWide(const std::string& s) {
    if (s.empty()) return {};
    int n = MultiByteToWideChar(CP_UTF8, 0, s.c_str(), (int)s.size(), nullptr, 0);
    std::wstring out(n, 0);
    MultiByteToWideChar(CP_UTF8, 0, s.c_str(), (int)s.size(), out.data(), n);
    return out;
}
inline std::string WideToUtf8(const std::wstring& s) {
    if (s.empty()) return {};
    int n = WideCharToMultiByte(CP_UTF8, 0, s.c_str(), (int)s.size(), nullptr, 0, nullptr, nullptr);
    std::string out(n, 0);
    WideCharToMultiByte(CP_UTF8, 0, s.c_str(), (int)s.size(), out.data(), n, nullptr, nullptr);
    return out;
}
inline unsigned long long PlatNowMs() { return GetTickCount64(); }
inline void PlatSleep(unsigned long ms) { Sleep(ms); }

#else  // __linux__

#include <chrono>
#include <cerrno>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cwchar>
#include <mutex>
#include <shared_mutex>
#include <thread>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

// Types used by the shared drivers that originally came from <windows.h>.
using BYTE = unsigned char;
using USHORT = unsigned short;
using SHORT = short;
using ULONG = unsigned long;
using LONG = long;
using UINT = unsigned int;
using DWORD = unsigned long;
using ULONGLONG = unsigned long long;
using LONGLONG = long long;
using BOOL = int;
using LPVOID = void*;
using HANDLE = void*;

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif
#ifndef WINAPI
#define WINAPI
#endif
#ifndef MAX_PATH
#define MAX_PATH 4096
#endif
#ifndef CP_UTF8
#define CP_UTF8 65001
#endif
#ifndef INVALID_FILE_ATTRIBUTES
#define INVALID_FILE_ATTRIBUTES ((DWORD)-1)
#endif
#ifndef INVALID_HANDLE_VALUE
#define INVALID_HANDLE_VALUE ((HANDLE)(intptr_t)-1)
#endif
#ifndef _countof
template <typename T, size_t N>
constexpr size_t _countof(T (&)[N]) noexcept { return N; }
#endif

inline int _wcsicmp(const wchar_t* a, const wchar_t* b) { return wcscasecmp(a, b); }
inline int _wcsnicmp(const wchar_t* a, const wchar_t* b, size_t n) { return wcsncasecmp(a, b, n); }
inline int _stricmp(const char* a, const char* b) { return strcasecmp(a, b); }
inline int _strnicmp(const char* a, const char* b, size_t n) { return strncasecmp(a, b, n); }
inline DWORD GetLastError() { return (DWORD)errno; }

inline ULONGLONG GetTickCount64() {
    using namespace std::chrono;
    return (ULONGLONG)duration_cast<milliseconds>(steady_clock::now().time_since_epoch()).count();
}
inline void Sleep(DWORD ms) { std::this_thread::sleep_for(std::chrono::milliseconds(ms)); }
inline unsigned long long PlatNowMs() { return GetTickCount64(); }
inline void PlatSleep(unsigned long ms) { Sleep((DWORD)ms); }

// std::wstring is UTF-32 on Linux; hidapi/sysfs paths and names are UTF-8.
inline std::wstring Utf8ToWide(const std::string& s) {
    std::wstring out;
    out.reserve(s.size());
    size_t i = 0;
    while (i < s.size()) {
        unsigned char c = (unsigned char)s[i];
        unsigned int cp = 0;
        int len = 0;
        if (c < 0x80) { cp = c; len = 1; }
        else if ((c & 0xE0) == 0xC0) { cp = c & 0x1F; len = 2; }
        else if ((c & 0xF0) == 0xE0) { cp = c & 0x0F; len = 3; }
        else if ((c & 0xF8) == 0xF0) { cp = c & 0x07; len = 4; }
        else { cp = 0xFFFD; len = 1; }
        if (i + (size_t)len > s.size()) { cp = 0xFFFD; len = 1; }
        for (int k = 1; k < len; k++) {
            unsigned char d = (unsigned char)s[i + k];
            if ((d & 0xC0) != 0x80) { cp = 0xFFFD; break; }
            cp = (cp << 6) | (d & 0x3F);
        }
        out.push_back((wchar_t)cp);
        i += (size_t)len;
    }
    return out;
}
inline std::string WideToUtf8(const std::wstring& s) {
    std::string out;
    out.reserve(s.size() * 2);
    for (wchar_t wc : s) {
        unsigned int cp = (unsigned int)wc;
        if (cp < 0x80) out.push_back((char)cp);
        else if (cp < 0x800) {
            out.push_back((char)(0xC0 | (cp >> 6)));
            out.push_back((char)(0x80 | (cp & 0x3F)));
        } else if (cp < 0x10000) {
            out.push_back((char)(0xE0 | (cp >> 12)));
            out.push_back((char)(0x80 | ((cp >> 6) & 0x3F)));
            out.push_back((char)(0x80 | (cp & 0x3F)));
        } else if (cp < 0x110000) {
            out.push_back((char)(0xF0 | (cp >> 18)));
            out.push_back((char)(0x80 | ((cp >> 12) & 0x3F)));
            out.push_back((char)(0x80 | ((cp >> 6) & 0x3F)));
            out.push_back((char)(0x80 | (cp & 0x3F)));
        } else out.push_back((char)0xEF), out.push_back((char)0xBF), out.push_back((char)0xBD);
    }
    return out;
}

inline int MultiByteToWideChar(UINT, DWORD, const char* src, int srcLen, wchar_t* dst, int dstLen) {
    if (!src || srcLen == 0) return 0;
    std::string s = srcLen < 0 ? std::string(src) : std::string(src, (size_t)srcLen);
    std::wstring w = Utf8ToWide(s);
    if (srcLen < 0) w.push_back(L'\0');
    if (!dst || dstLen == 0) return (int)w.size();
    int n = (int)w.size() < dstLen ? (int)w.size() : dstLen;
    memcpy(dst, w.data(), (size_t)n * sizeof(wchar_t));
    return n;
}

inline DWORD GetModuleFileNameW(HANDLE, wchar_t* buf, DWORD size) {
    if (!buf || size == 0) return 0;
    char path[4096] = {};
    ssize_t len = ::readlink("/proc/self/exe", path, sizeof(path) - 1);
    if (len <= 0) {
        buf[0] = L'\0';
        return 0;
    }
    path[len] = '\0';
    std::wstring w = Utf8ToWide(path);
    DWORD copyLen = w.size() < (size_t)(size - 1) ? (DWORD)w.size() : (size - 1);
    memcpy(buf, w.data(), copyLen * sizeof(wchar_t));
    buf[copyLen] = L'\0';
    return copyLen;
}

inline DWORD GetFileAttributesW(const wchar_t* path) {
    if (!path) return INVALID_FILE_ATTRIBUTES;
    std::string u = WideToUtf8(path);
    if (u.size() > 4 && u.compare(u.size() - 4, 4, ".exe") == 0) {
        std::string noExe = u.substr(0, u.size() - 4);
        struct stat st{};
        if (::stat(noExe.c_str(), &st) == 0) return 0x80;
    }
    struct stat st{};
    return ::stat(u.c_str(), &st) == 0 ? 0x80 : INVALID_FILE_ATTRIBUTES;
}

inline DWORD SearchPathW(const wchar_t*, const wchar_t* file, const wchar_t*, DWORD bufLen, wchar_t* buf, wchar_t**) {
    if (!file || !buf || bufLen == 0) return 0;
    std::string name = WideToUtf8(file);
    if (name.size() > 4 && name.compare(name.size() - 4, 4, ".exe") == 0)
        name.resize(name.size() - 4);
    const char* pathEnv = std::getenv("PATH");
    if (!pathEnv) return 0;
    std::string paths(pathEnv);
    size_t start = 0;
    while (start <= paths.size()) {
        size_t colon = paths.find(':', start);
        std::string dir = paths.substr(start, colon == std::string::npos ? std::string::npos : colon - start);
        if (!dir.empty()) {
            std::string full = dir + "/" + name;
            if (::access(full.c_str(), X_OK) == 0) {
                std::wstring w = Utf8ToWide(full);
                if (w.size() + 1 <= (size_t)bufLen) {
                    memcpy(buf, w.data(), w.size() * sizeof(wchar_t));
                    buf[w.size()] = L'\0';
                    return (DWORD)w.size();
                }
            }
        }
        if (colon == std::string::npos) break;
        start = colon + 1;
    }
    return 0;
}

inline DWORD GetEnvironmentVariableW(const wchar_t* name, wchar_t* buf, DWORD size) {
    if (!name) return 0;
    const char* val = std::getenv(WideToUtf8(name).c_str());
    if (!val) return 0;
    std::wstring w = Utf8ToWide(val);
    if (!buf || size == 0) return (DWORD)w.size() + 1;
    DWORD n = w.size() < (size_t)(size - 1) ? (DWORD)w.size() : (size - 1);
    memcpy(buf, w.data(), n * sizeof(wchar_t));
    buf[n] = L'\0';
    return n;
}

// Minimal Win32 pipe / process / SRWLOCK / thread shims for headsetcontrol.cpp on Linux.
struct SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    BOOL bInheritHandle;
};

#define HANDLE_FLAG_INHERIT 0x00000001
#define STARTF_USESTDHANDLES 0x00000100
#define CREATE_NO_WINDOW 0x08000000

struct STARTUPINFOW {
    DWORD cb;
    DWORD dwFlags;
    HANDLE hStdInput;
    HANDLE hStdOutput;
    HANDLE hStdError;
};

struct PROCESS_INFORMATION {
    HANDLE hProcess;
    HANDLE hThread;
    DWORD dwProcessId;
    DWORD dwThreadId;
};

inline HANDLE PlatFdToHandle(int fd) { return (HANDLE)(intptr_t)(fd + 1); }
inline int PlatHandleToFd(HANDLE h) { return (int)((intptr_t)h - 1); }
inline HANDLE PlatPidToHandle(pid_t pid) { return (HANDLE)(intptr_t)(-(intptr_t)pid); }
inline pid_t PlatHandleToPid(HANDLE h) { return (pid_t)(-(intptr_t)h); }

inline BOOL CreatePipe(HANDLE* rd, HANDLE* wr, SECURITY_ATTRIBUTES*, DWORD) {
    int fds[2];
    if (::pipe(fds) != 0) return FALSE;
    *rd = PlatFdToHandle(fds[0]);
    *wr = PlatFdToHandle(fds[1]);
    return TRUE;
}

inline BOOL SetHandleInformation(HANDLE h, DWORD, DWORD) {
    int fd = PlatHandleToFd(h);
    if (fd >= 0) ::fcntl(fd, F_SETFD, FD_CLOEXEC);
    return TRUE;
}

inline BOOL CreateProcessW(const wchar_t*, wchar_t* cmdLine, SECURITY_ATTRIBUTES*, SECURITY_ATTRIBUTES*,
                           BOOL, DWORD, LPVOID, const wchar_t*, STARTUPINFOW* si, PROCESS_INFORMATION* pi) {
    if (!cmdLine || !si || !pi) return FALSE;
    std::string cmd = WideToUtf8(cmdLine);
    int outFd = PlatHandleToFd(si->hStdOutput);
    int errFd = PlatHandleToFd(si->hStdError);
    pid_t pid = ::fork();
    if (pid < 0) return FALSE;
    if (pid == 0) {
        if (outFd >= 0) ::dup2(outFd, STDOUT_FILENO);
        if (errFd >= 0) ::dup2(errFd, STDERR_FILENO);
        if (outFd >= 0) ::close(outFd);
        if (errFd >= 0 && errFd != outFd) ::close(errFd);
        ::execl("/bin/sh", "sh", "-c", cmd.c_str(), (char*)nullptr);
        ::_exit(127);
    }
    pi->hProcess = PlatPidToHandle(pid);
    pi->hThread = nullptr;
    pi->dwProcessId = (DWORD)pid;
    pi->dwThreadId = 0;
    return TRUE;
}

inline BOOL PeekNamedPipe(HANDLE h, LPVOID, DWORD, DWORD*, DWORD* avail, DWORD*) {
    int fd = PlatHandleToFd(h);
    if (fd < 0) return FALSE;
    struct pollfd pfd{ fd, POLLIN | POLLHUP | POLLERR, 0 };
    int r = ::poll(&pfd, 1, 0);
    if (r < 0) return FALSE;
    if (pfd.revents & POLLIN) {
        if (avail) *avail = 1;
        return TRUE;
    }
    if (pfd.revents & (POLLHUP | POLLERR | POLLNVAL)) return FALSE;
    if (avail) *avail = 0;
    return TRUE;
}

inline BOOL ReadFile(HANDLE h, LPVOID buf, DWORD toRead, DWORD* readOut, LPVOID) {
    int fd = PlatHandleToFd(h);
    if (fd < 0) return FALSE;
    ssize_t n = ::read(fd, buf, toRead);
    if (n < 0) return FALSE;
    if (readOut) *readOut = (DWORD)n;
    return TRUE;
}

inline BOOL TerminateProcess(HANDLE h, UINT) {
    pid_t pid = PlatHandleToPid(h);
    if (pid > 0) ::kill(pid, SIGKILL);
    return TRUE;
}

inline BOOL CloseHandle(HANDLE h) {
    if (!h || h == INVALID_HANDLE_VALUE) return TRUE;
    intptr_t v = (intptr_t)h;
    if (v < 0) {
        int status = 0;
        ::waitpid((pid_t)(-v), &status, 0);
    } else if (v > 0) {
        ::close((int)(v - 1));
    }
    return TRUE;
}

struct SRWLOCK {
    std::shared_mutex mu;
};
#define SRWLOCK_INIT {}

inline void AcquireSRWLockExclusive(SRWLOCK* l) { l->mu.lock(); }
inline void ReleaseSRWLockExclusive(SRWLOCK* l) { l->mu.unlock(); }
inline void AcquireSRWLockShared(SRWLOCK* l) { l->mu.lock_shared(); }
inline void ReleaseSRWLockShared(SRWLOCK* l) { l->mu.unlock_shared(); }

inline LONG InterlockedExchange(volatile LONG* target, LONG val) {
    return __atomic_exchange_n(target, val, __ATOMIC_SEQ_CST);
}
inline LONG InterlockedCompareExchange(volatile LONG* dst, LONG exch, LONG comp) {
    __atomic_compare_exchange_n(dst, &comp, exch, false, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST);
    return comp;
}

using LPTHREAD_START_ROUTINE = DWORD (*)(LPVOID);
inline HANDLE CreateThread(SECURITY_ATTRIBUTES*, size_t, LPTHREAD_START_ROUTINE fn, LPVOID param, DWORD, DWORD*) {
    try {
        std::thread([fn, param]() { fn(param); }).detach();
        return (HANDLE)nullptr;
    } catch (...) {
        return nullptr;
    }
}

#endif
