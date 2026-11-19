// Linux driver orchestration.
//
// Runs every portable vendor driver in the exact priority order from src/devices.cpp so shared
// vendor IDs (e.g. 3554, 3710, 373E, 248A, 1532, 046D) are claimed in the right order, plus
// Linux-specific serial, Bluetooth RFCOMM, and 4-tier kernel/UPower/BlueZ/HID power fallbacks.
#include "../devices.h"

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cwchar>
#include <fstream>
#include <string>
#include <utility>
#include <vector>

#include "../drivers/drivers.h"
#include "../hid.h"
#include "power_linux.h"

#ifdef __linux__
#include <linux/hidraw.h>
#include <sys/ioctl.h>
#ifndef HIDIOCGINPUT
#define HIDIOCGINPUT(len) _IOC(_IOC_READ | _IOC_WRITE, 'H', 0x0A, len)
#endif
#endif

bool HidDev::GetInputReport(BYTE reportId, std::vector<BYTE>& out) {
    if (!ok() || !c_.inLen()) return false;
#ifdef __linux__
    out.assign(c_.inLen(), 0);
    out[0] = reportId;
    if (ioctl(fd_, HIDIOCGINPUT(out.size()), out.data()) >= 0) return true;
#endif
    return Read(out, 50) > 0;
}

namespace {

std::string ConfigFilePath() {
    const char* xdg = std::getenv("XDG_CONFIG_HOME");
    if (xdg && *xdg) return std::string(xdg) + "/wireless-battery/config.ini";
    const char* home = std::getenv("HOME");
    if (home && *home) return std::string(home) + "/.config/wireless-battery/config.ini";
    return "config.ini";
}

std::string TrimAscii(const std::string& s) {
    size_t a = 0, b = s.size();
    while (a < b && std::isspace((unsigned char)s[a])) a++;
    while (b > a && std::isspace((unsigned char)s[b - 1])) b--;
    return s.substr(a, b - a);
}

// $XDG_CONFIG_HOME/wireless-battery/config.ini ([general] ignore-devices): "VID:PID" pairs in hex,
// separated by spaces, commas or semicolons (e.g. "28BD:0947, 046D:C547"). Matching devices are
// filtered out before any driver runs (issue #232).
std::vector<std::pair<USHORT, USHORT>> IgnoredDevices() {
    std::vector<std::pair<USHORT, USHORT>> out;
    std::ifstream f(ConfigFilePath());
    if (!f.is_open()) return out;

    bool inGeneral = false;
    std::string rawValue;
    std::string line;
    while (std::getline(f, line)) {
        std::string t = TrimAscii(line);
        if (t.empty() || t[0] == '#' || t[0] == ';') continue;
        if (t.front() == '[' && t.back() == ']') {
            std::string sec = TrimAscii(t.substr(1, t.size() - 2));
            inGeneral = (sec == "general");
            continue;
        }
        if (!inGeneral) continue;
        size_t eq = t.find('=');
        if (eq == std::string::npos) continue;
        std::string key = TrimAscii(t.substr(0, eq));
        if (key == "ignore-devices") {
            rawValue = TrimAscii(t.substr(eq + 1));
            break;
        }
    }

    for (const char* p = rawValue.c_str(); *p;) {
        unsigned vid = 0, pid = 0;
        int used = 0;
        if (std::sscanf(p, " %x:%x%n", &vid, &pid, &used) == 2 && used > 0) {
            out.push_back({ (USHORT)vid, (USHORT)pid });
            p += used;
        } else {
            p++;
        }
        while (*p == ',' || *p == ';' || *p == ' ' || *p == '\t') p++;
    }
    return out;
}

}  // namespace

std::vector<DeviceStatus> PollAllDevices() {
    PollContext ctx;
    ctx.colls = EnumHid();
    auto ignored = IgnoredDevices();
    if (!ignored.empty())
        ctx.colls.erase(std::remove_if(ctx.colls.begin(), ctx.colls.end(), [&](const HidColl& c) {
                            return std::find(ignored.begin(), ignored.end(), std::make_pair(c.vid, c.pid)) != ignored.end();
                        }),
                        ctx.colls.end());

    PollGlorious(ctx);
    PollAula(ctx);       // before Kysona (shares the 3554 vendor id) and SONiX (shares 05AC:024F)
    PollAulaMouse(ctx);
    PollEweadn(ctx);     // EWEADN S7 / S9 mice on 372E:103D / 1027 (AULA keeps 372E:106C)
    PollDareu(ctx);
    PollZenith(ctx);
    PollDarmoshark(ctx);
    PollDarmosharkNrf(ctx);
    PollAtkSerial(ctx);  // before Kysona, which shares the ATK vendor id
    PollAtkKeyboard(ctx);
    PollRedragonEvision(ctx);
    PollPulsar(ctx);     // before Kysona, which also scans the 3710 vendor id
    PollAtkBitmouse(ctx);  // before Kysona, which would probe the NK dongle with the wrong protocol
    PollChimera(ctx);      // Chimera V2 mouse (3554:F512), before Kysona which shares the 3554 vendor id
    PollKysona(ctx);
    PollKeychron(ctx);
    PollCherry(ctx);
    PollNuphy(ctx);
    PollArbiter(ctx);    // before Lamzu, which shares the 373E vendor id
    PollLamzu(ctx);
    PollEndgame(ctx);
    PollEndgameWe(ctx);
    PollVaxee(ctx);
    PollWlmouse(ctx);
    PollFinalmouse(ctx);
    PollScyrox(ctx);
    PollNinjutso(ctx);
    PollSprime(ctx);
    PollRawm(ctx);
    PollAkko(ctx);
    PollRongyuan(ctx);
    PollSonix(ctx);
    PollViaDongle(ctx);
    PollSemico(ctx);
    PollAjazzAk992(ctx);
    PollSonyInzone(ctx);
    PollFractal(ctx);
    PollJabra(ctx);
    PollJbl(ctx);
    PollRog(ctx);
    PollZowie(ctx);
    PollRoyalKludge(ctx);
    PollMchose(ctx);
    PollMchoseA5(ctx);
    PollRapoo(ctx);
    PollAreson(ctx);
    PollMchoseG3(ctx);
    PollMsi(ctx);
    PollMachenike(ctx);  // before Ajazz in PollMiscMice, which shares the L7's 248A vendor id
    PollNiceboy(ctx);    // exact 248A:FA02 match, also before the Ajazz / Delux pollers
    PollMchoseModern(ctx);
    PollMchoseHeadset(ctx);
    PollVgn(ctx);
    PollMchoseKeyboard(ctx);  // 3837:3033 receiver, before the generic fallbacks
    PollMiscMice(ctx);
    PollFantech(ctx);
    PollRazerHeadsets(ctx);  // before the generic Razer driver, which shares the vendor id
    PollBarracudaPro(ctx);   // before the generic Razer driver as well
    PollHyperX(ctx);
    PollLogitechG435(ctx);  // before the HID++ driver, which shares the vendor id
    PollAstro(ctx);
    PollLogitech(ctx);
    PollRazer(ctx);
    PollSteelSeriesElite(ctx);
    PollSteelSeries(ctx);
    PollAudeze(ctx);
    PollEndorfy(ctx);
    PollTurtleBeach(ctx);
    PollAkg(ctx);
    PollNzxt(ctx);
    PollPlantronics(ctx);
    PollCorsair(ctx);
    PollCoolerMaster(ctx);
    PollPlayStation(ctx);
    PollSwitchPro(ctx);
    PollSteamController(ctx);
    PollGameSir(ctx);
    PollFlydigi(ctx);
    PollGameSirCyclone(ctx);
    Poll8BitDo(ctx);
    PollBeitong(ctx);
    PollGalaxyBuds(ctx);
    PollNothingEar(ctx);
    PollMoondrop(ctx);
    PollDarkrim(ctx);
    PollAlienware(ctx);
    PollMaono(ctx);  // MAONO PD200W receiver (352F:040E), experimental battery query
    PollHeadsetControl(ctx);
    PollLinuxPower(ctx);
    return ctx.out;
}

std::wstring DumpHidCollections() {
    std::wstring out = L"VID:PID    IF  UsagePg:Usage  In  Out Feat  Product\n";
    for (const auto& c : EnumHid()) {
        wchar_t line[256];
        swprintf(line, 256, L"%04X:%04X  %2d  %04X:%04X    %3u %3u %3u   ", c.vid, c.pid, c.iface,
                 c.page(), c.usage(), c.inLen(), c.outLen(), c.featLen());
        out += line + HidProduct(c) + L"\n";
    }
    out += DumpXentaFrames();
    out += DumpAstroFrames();
    out += DumpLinuxPower();
    return out;
}
