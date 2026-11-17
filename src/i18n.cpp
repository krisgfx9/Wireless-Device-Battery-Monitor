#include "i18n.h"

#include <windows.h>

#include <cwchar>

namespace {

struct Entry { const wchar_t* en; const wchar_t* tr; };

// Turkish. To add a language, add a table, a UiLanguage value and a case in Table().
const Entry kTurkish[] = {
    // Device status (tray tooltip, menu, taskbar tooltip).
    { L"off / not connected", L"kapalı / bağlı değil" },
    { L"% (last known)", L"% (son bilinen)" },
    { L"unknown", L"bilinmiyor" },
    { L", charging", L", şarj oluyor" },
    { L", asleep", L", uykuda" },
    { L"No devices with battery info found", L"Pil bilgisi veren cihaz bulunamadı" },
    { L"Low battery", L"Düşük pil" },
    { L"%s is at %d%%", L"%s: %d%% kaldı" },
    // Tray menu.
    { L"Point at a device to show, hide or move it", L"Göstermek, gizlemek ya da taşımak için cihazın üzerine gelin" },
    { L"Show on the taskbar", L"Görev çubuğunda göster" },
    { L"Show in the tray", L"Bildirim alanında göster" },
    { L"Move left", L"Sola taşı" },
    { L"Move right", L"Sağa taşı" },
    { L"Move up", L"Yukarı taşı" },
    { L"Move down", L"Aşağı taşı" },
    { L"Hide last known / asleep devices", L"Son bilinen / uykudaki cihazları gizle" },
    { L"Show on the taskbar (icon + percentage)", L"Görev çubuğunda göster (simge + yüzde)" },
    { L"Show as tray icons", L"Bildirim alanında simge olarak göster" },
    { L"Background behind taskbar text (for transparent taskbars)", L"Görev çubuğu yazısının arkasına zemin (saydam görev çubukları için)" },
    { L"Refresh now", L"Şimdi yenile" },
    { L"Start with Windows", L"Windows ile başlat" },
    { L"Language", L"Dil" },
    { L"Automatic (Windows language)", L"Otomatik (Windows dili)" },
    { L"Support the project...", L"Projeyi destekle..." },
    { L"Exit", L"Çıkış" },
    // Battery levels of devices that only report a coarse level.
    { L"Full", L"Dolu" },
    { L"Good", L"İyi" },
    { L"Medium", L"Orta" },
    { L"Low", L"Düşük" },
    { L"Critical", L"Kritik" },
    { L"Empty", L"Boş" },
    // How a device is connected (DeviceStatus::via). Product names (Bluetooth, Xbox, HeadsetControl ...) stay as they are.
    { L"USB cable", L"USB kablosu" },
    { L"2.4 GHz receiver", L"2.4 GHz alıcı" },
    { L"2.4 GHz receiver / USB", L"2.4 GHz alıcı / USB" },
    { L"2.4 GHz receiver or USB", L"2.4 GHz alıcı ya da USB" },
    { L"2.4 GHz dongle", L"2.4 GHz alıcı" },
    { L"2.4 GHz dongle or USB", L"2.4 GHz alıcı ya da USB" },
    { L"Logitech receiver", L"Logitech alıcı" },
    { L"Razer receiver", L"Razer alıcı" },
    { L"Corsair receiver", L"Corsair alıcı" },
    { L"Wireless adapter", L"Kablosuz adaptör" },
    { L"UWB base station", L"UWB baz istasyonu" },
    { L"USB base station", L"USB baz istasyonu" },
};

UiLanguage g_lang = UiLanguage::Automatic;

UiLanguage Effective() {
    if (g_lang != UiLanguage::Automatic) return g_lang;
    return PRIMARYLANGID(GetUserDefaultUILanguage()) == LANG_TURKISH ? UiLanguage::Turkish : UiLanguage::English;
}

}  // namespace

void SetUiLanguage(UiLanguage lang) { g_lang = lang; }
UiLanguage GetUiLanguage() { return g_lang; }

const wchar_t* T(const wchar_t* en) {
    if (Effective() != UiLanguage::Turkish) return en;
    for (const auto& e : kTurkish)
        if (!wcscmp(e.en, en)) return e.tr;
    return en;
}
