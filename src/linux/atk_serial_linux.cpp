// Linux serial implementation for ATK virtual COM port devices:
//   - ATK RS7 / RS7 Pro keyboards (VID 373B, PID 110D): 115200 8N1, 17-byte request
//     {0x08, 0x04, 0,0,0,0,0,0,0,0,0,0,0,0,0,0, 0x49}
//   - ATK N9 Pro (VID 373B: dongle 11CB, wired 11CA) and N9 Ultra (dongle 1204, wired 1203)
//     headsets: 9600 8N1, 64-byte frames (same protocol as src/drivers/atk_serial.cpp).
#include "../drivers/drivers.h"

#include <fcntl.h>
#include <poll.h>
#include <termios.h>
#include <unistd.h>

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace {

struct Model {
    USHORT pid;
    const wchar_t* name;
    DeviceKind kind;
    bool wired;
    bool rs7Protocol;  // true = 115200 17-byte RS7 frame, false = 9600 64-byte N9 frame
};

constexpr Model kModels[] = {
    { 0x110D, L"ATK RS7 Pro",   DeviceKind::Keyboard, false, true  },
    { 0x11CB, L"ATK N9 Pro",    DeviceKind::Headset,  false, false },
    { 0x11CA, L"ATK N9 Pro",    DeviceKind::Headset,  true,  false },
    { 0x1204, L"ATK N9 Ultra",  DeviceKind::Headset,  false, false },
    { 0x1203, L"ATK N9 Ultra",  DeviceKind::Headset,  true,  false },
};

struct Port {
    std::string devNode;
    const Model* model;
};

bool ReadHexFile(const fs::path& p, USHORT& out) {
    std::ifstream f(p);
    if (!f.is_open()) return false;
    std::string s;
    if (!(f >> s)) return false;
    unsigned val = 0;
    if (sscanf(s.c_str(), "%x", &val) != 1) return false;
    out = (USHORT)val;
    return true;
}

bool FindUsbIds(const fs::path& ttySysPath, USHORT& vid, USHORT& pid) {
    std::error_code ec;
    fs::path cur = fs::canonical(ttySysPath / "device", ec);
    if (ec) cur = fs::canonical(ttySysPath, ec);
    if (ec) return false;

    for (int depth = 0; depth < 8 && !cur.empty() && cur != cur.root_path(); ++depth) {
        if (ReadHexFile(cur / "idVendor", vid) && ReadHexFile(cur / "idProduct", pid))
            return true;
        cur = cur.parent_path();
    }
    return false;
}

std::vector<Port> FindPorts() {
    std::vector<Port> out;
    std::error_code ec;
    fs::directory_iterator it("/sys/class/tty", ec), end;
    if (ec) return out;
    for (; it != end; it.increment(ec)) {
        if (ec) break;
        std::string ttyName = it->path().filename().string();
        if (ttyName.rfind("ttyACM", 0) != 0 && ttyName.rfind("ttyUSB", 0) != 0) continue;
        USHORT vid = 0, pid = 0;
        if (!FindUsbIds(it->path(), vid, pid) || vid != 0x373B) continue;
        for (const Model& m : kModels) {
            if (m.pid == pid) {
                out.push_back({ "/dev/" + ttyName, &m });
                break;
            }
        }
    }
    return out;
}

class LinuxSerial {
public:
    LinuxSerial(const std::string& devNode, speed_t baud) {
        fd_ = ::open(devNode.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK | O_CLOEXEC);
        if (fd_ < 0) return;

        struct termios tio{};
        if (tcgetattr(fd_, &tio) != 0) {
            Close();
            return;
        }
        cfmakeraw(&tio);
        cfsetispeed(&tio, baud);
        cfsetospeed(&tio, baud);
        tio.c_cflag &= ~(PARENB | CSTOPB | CSIZE | CRTSCTS);
        tio.c_cflag |= (CS8 | CLOCAL | CREAD);
        tio.c_cc[VMIN] = 0;
        tio.c_cc[VTIME] = 0;

        if (tcsetattr(fd_, TCSANOW, &tio) != 0) {
            Close();
            return;
        }
        tcflush(fd_, TCIOFLUSH);
    }

    ~LinuxSerial() { Close(); }
    bool ok() const { return fd_ >= 0; }

    bool WriteAll(const BYTE* data, size_t len) {
        size_t sent = 0;
        while (sent < len) {
            struct pollfd pfd{ fd_, POLLOUT, 0 };
            if (::poll(&pfd, 1, 300) <= 0 || !(pfd.revents & POLLOUT)) return false;
            ssize_t n = ::write(fd_, data + sent, len - sent);
            if (n <= 0) return false;
            sent += (size_t)n;
        }
        return true;
    }

    int ReadSome(BYTE* buf, size_t maxLen, int timeoutMs) {
        struct pollfd pfd{ fd_, POLLIN, 0 };
        int r = ::poll(&pfd, 1, timeoutMs);
        if (r <= 0 || !(pfd.revents & POLLIN)) return 0;
        ssize_t n = ::read(fd_, buf, maxLen);
        return n > 0 ? (int)n : 0;
    }

    // 64-byte frame command used by ATK N9 Pro / N9 Ultra headsets.
    bool Command64(BYTE cmd, BYTE sub, std::vector<BYTE>& data) {
        BYTE frame[64] = { 2, cmd, sub };
        if (!WriteAll(frame, sizeof(frame))) return false;
        std::vector<BYTE> buf;
        ULONGLONG end = GetTickCount64() + 800;
        while ((LONGLONG)end - (LONGLONG)GetTickCount64() > 0) {
            int rem = (int)std::max<LONGLONG>(1, (LONGLONG)end - (LONGLONG)GetTickCount64());
            BYTE chunk[128];
            int n = ReadSome(chunk, sizeof(chunk), std::min(rem, 100));
            if (n <= 0) continue;
            buf.insert(buf.end(), chunk, chunk + n);
            while (buf.size() >= 64) {
                if (buf[1] == cmd && buf[2] == sub) {
                    data.assign(buf.begin() + 3, buf.begin() + 64);
                    return true;
                }
                buf.erase(buf.begin(), buf.begin() + 64);
            }
        }
        return false;
    }

    // 17-byte frame command used by ATK RS7 / RS7 Pro keyboards (373b:110d).
    bool QueryRs7Battery(int& percent, bool& charging) {
        static constexpr BYTE kReq[17] = {
            0x08, 0x04, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0x49
        };
        if (!WriteAll(kReq, sizeof(kReq))) return false;
        std::vector<BYTE> buf;
        ULONGLONG end = GetTickCount64() + 800;
        while ((LONGLONG)end - (LONGLONG)GetTickCount64() > 0) {
            int rem = (int)std::max<LONGLONG>(1, (LONGLONG)end - (LONGLONG)GetTickCount64());
            BYTE chunk[64];
            int n = ReadSome(chunk, sizeof(chunk), std::min(rem, 100));
            if (n <= 0) continue;
            buf.insert(buf.end(), chunk, chunk + n);
            while (buf.size() >= 17) {
                if (buf[0] == 0x08 && buf[1] == 0x04) {
                    // Standard 17-byte reply: battery % in byte 6 (or byte 2/3 depending on firmware),
                    // charging in byte 7 (or bit 7 of battery byte).
                    int pct = -1;
                    bool chg = false;
                    if (buf[6] > 0 && buf[6] <= 100) {
                        pct = buf[6];
                        chg = buf[7] != 0;
                    } else if ((buf[3] & 0x7F) > 0 && (buf[3] & 0x7F) <= 100) {
                        pct = buf[3] & 0x7F;
                        chg = (buf[3] & 0x80) != 0 || buf[4] != 0;
                    } else if ((buf[2] & 0x7F) > 0 && (buf[2] & 0x7F) <= 100) {
                        pct = buf[2] & 0x7F;
                        chg = (buf[2] & 0x80) != 0 || buf[3] != 0;
                    }
                    if (pct >= 0) {
                        percent = Clamp100(pct);
                        charging = chg;
                        return true;
                    }
                }
                buf.erase(buf.begin());
            }
        }
        return false;
    }

private:
    void Close() {
        if (fd_ >= 0) ::close(fd_);
        fd_ = -1;
    }
    int fd_ = -1;
};

}  // namespace

void PollAtkSerial(PollContext& ctx) {
    for (const Port& p : FindPorts()) {
        USHORT pid = p.model->pid;
        if (ctx.IsClaimed(0x373B, pid)) continue;
        if (p.model->rs7Protocol) {
            LinuxSerial port(p.devNode, B115200);
            if (!port.ok()) continue;
            int pct = -1;
            bool chg = false;
            if (!port.QueryRs7Battery(pct, chg)) continue;
            DeviceStatus s;
            s.key = L"atk-serial:" + Hex4(pid);
            s.name = p.model->name;
            s.kind = p.model->kind;
            s.via = L"2.4 GHz receiver";
            s.connected = true;
            s.percent = pct;
            s.charging = chg;
            ctx.Add(s, 0x373B, pid);
        } else {
            LinuxSerial port(p.devNode, B9600);
            if (!port.ok()) continue;
            std::vector<BYTE> data;
            if (!port.Command64(0x00, 0x04, data)) continue;
            DeviceStatus s;
            s.key = L"atk-serial:" + Hex4(pid);
            s.name = p.model->name;
            s.kind = p.model->kind;
            s.via = p.model->wired ? L"USB cable" : L"2.4 GHz receiver";
            s.connected = data.size() > 1 && data[1] == 1;
            if (s.connected && port.Command64(0x00, 0x03, data) && data.size() > 1) {
                s.percent = Clamp100(data[1] & 0x7F);
                s.charging = (data[1] & 0x80) != 0;
            }
            ctx.Add(s, 0x373B, pid);
        }
    }
}
