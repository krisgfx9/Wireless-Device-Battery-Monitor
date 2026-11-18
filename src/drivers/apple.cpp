// AirPods / Beats over Bluetooth. Windows has no battery level for them, but the buds keep sending
// Apple "proximity pairing" BLE advertisements with the levels of both buds and the case. A passive
// advertisement watcher (receive only, nothing is sent) keeps the strongest recent one.
#include "drivers.h"

#include <roapi.h>
#include <winstring.h>
#include <robuffer.h>
#include <windows.devices.bluetooth.advertisement.h>

#include <mutex>

#include "apple_protocol.h"

namespace {

using namespace ABI::Windows::Devices::Bluetooth::Advertisement;
using ABI::Windows::Storage::Streams::IBuffer;
using Windows::Storage::Streams::IBufferByteAccess;
using Handler = ABI::Windows::Foundation::ITypedEventHandler<BluetoothLEAdvertisementWatcher*, BluetoothLEAdvertisementReceivedEventArgs*>;

constexpr short kMinRssi = -60;          // only buds in the room, not a neighbour's (same as OpenPods)
constexpr ULONGLONG kFreshMs = 2 * 60 * 1000;

std::mutex g_mu;
Apple::PodsBattery g_last;
short g_lastRssi = -128;
ULONGLONG g_lastTick = 0;

template <class T>
void Release(T*& p) {
    if (p) p->Release();
    p = nullptr;
}

void OnAdvertisement(IBluetoothLEAdvertisementReceivedEventArgs* args) {
    INT16 rssi = -128;
    if (FAILED(args->get_RawSignalStrengthInDBm(&rssi)) || rssi < kMinRssi) return;
    IBluetoothLEAdvertisement* adv = nullptr;
    __FIVector_1_Windows__CDevices__CBluetooth__CAdvertisement__CBluetoothLEManufacturerData* list = nullptr;
    if (SUCCEEDED(args->get_Advertisement(&adv)) && adv && SUCCEEDED(adv->get_ManufacturerData(&list)) && list) {
        UINT32 n = 0;
        list->get_Size(&n);
        for (UINT32 i = 0; i < n; i++) {
            IBluetoothLEManufacturerData* md = nullptr;
            IBuffer* buf = nullptr;
            IBufferByteAccess* bytes = nullptr;
            UINT16 company = 0;
            UINT32 len = 0;
            BYTE* data = nullptr;
            Apple::PodsBattery b;
            if (SUCCEEDED(list->GetAt(i, &md)) && md && SUCCEEDED(md->get_CompanyId(&company)) && company == 0x004C &&
                SUCCEEDED(md->get_Data(&buf)) && buf && SUCCEEDED(buf->get_Length(&len)) &&
                SUCCEEDED(buf->QueryInterface(__uuidof(IBufferByteAccess), (void**)&bytes)) && SUCCEEDED(bytes->Buffer(&data)) &&
                Apple::DecodeProximityPairing(data, len, b)) {
                std::lock_guard<std::mutex> lock(g_mu);
                ULONGLONG now = GetTickCount64();
                // Prefer the strongest signal; a weaker one only replaces it once that has gone stale.
                if (rssi >= g_lastRssi || now - g_lastTick > 10000) {
                    g_last = b;
                    g_lastRssi = rssi;
                    g_lastTick = now;
                }
            }
            Release(bytes);
            Release(buf);
            Release(md);
        }
    }
    Release(list);
    Release(adv);
}

class ReceivedHandler : public Handler {
    LONG ref_ = 1;
public:
    virtual ~ReceivedHandler() = default;
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** p) override {
        if (iid == __uuidof(IUnknown) || iid == __uuidof(IAgileObject) || iid == __uuidof(Handler)) {
            *p = this;
            AddRef();
            return S_OK;
        }
        *p = nullptr;
        return E_NOINTERFACE;
    }
    ULONG STDMETHODCALLTYPE AddRef() override { return InterlockedIncrement(&ref_); }
    ULONG STDMETHODCALLTYPE Release() override {
        LONG r = InterlockedDecrement(&ref_);
        if (!r) delete this;
        return r;
    }
    HRESULT STDMETHODCALLTYPE Invoke(IBluetoothLEAdvertisementWatcher*, IBluetoothLEAdvertisementReceivedEventArgs* args) override {
        if (args) OnAdvertisement(args);
        return S_OK;
    }
};

// Started on first use and kept running: the buds advertise every second or so.
bool StartWatcher() {
    static bool started = false, tried = false;
    if (tried) return started;
    tried = true;
    RoInitialize(RO_INIT_MULTITHREADED);  // our poll thread; harmless if already initialised
    HSTRING cls = nullptr;
    IInspectable* insp = nullptr;
    IBluetoothLEAdvertisementWatcher* w = nullptr;
    const wchar_t* name = RuntimeClass_Windows_Devices_Bluetooth_Advertisement_BluetoothLEAdvertisementWatcher;
    if (SUCCEEDED(WindowsCreateString(name, (UINT32)wcslen(name), &cls)) && SUCCEEDED(RoActivateInstance(cls, &insp)) &&
        SUCCEEDED(insp->QueryInterface(__uuidof(IBluetoothLEAdvertisementWatcher), (void**)&w))) {
        auto* h = new ReceivedHandler;
        EventRegistrationToken token;
        started = SUCCEEDED(w->add_Received(h, &token)) && SUCCEEDED(w->Start());
        h->Release();
        if (!started) Release(w);  // on success the watcher lives as long as the app
    }
    Release(insp);
    if (cls) WindowsDeleteString(cls);
    return started;
}

}  // namespace

bool IsAppleAudioName(const std::wstring& name) {
    return name.find(L"AirPods") != std::wstring::npos || name.find(L"Beats") != std::wstring::npos ||
           name.find(L"Powerbeats") != std::wstring::npos;
}

bool AppleBudsStatus(DeviceStatus& s) {
    static bool first = true;
    if (!StartWatcher()) return false;
    if (first) {  // right after starting the watcher, give the buds a moment to be heard (also for --list)
        first = false;
        for (int i = 0; i < 30; i++) {
            {
                std::lock_guard<std::mutex> lock(g_mu);
                if (g_lastTick) break;
            }
            Sleep(100);
        }
    }
    std::lock_guard<std::mutex> lock(g_mu);
    if (!g_lastTick || GetTickCount64() - g_lastTick > kFreshMs) return false;
    const auto& b = g_last;
    int buds = b.left < 0 ? b.right : b.right < 0 ? b.left : (b.left < b.right ? b.left : b.right);
    if (buds < 0) return false;  // both buds in the case: nothing worth showing on the taskbar
    s.percent = buds;
    s.charging = b.chargingLeft || b.chargingRight;
    s.kind = DeviceKind::Headset;
    s.detail.clear();
    auto add = [&](const wchar_t* part, int pct) {
        if (pct < 0) return;
        if (!s.detail.empty()) s.detail += L", ";
        s.detail += std::wstring(part) + L" " + std::to_wstring(pct) + L"%";  // main.cpp translates the part names
    };
    add(L"L", b.left);
    add(L"R", b.right);
    add(L"case", b.box);
    return true;
}
