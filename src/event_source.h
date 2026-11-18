#pragma once
// Something that notices device activity by itself and asks for a refresh: an emitter.
// New push channels (HID++ 2.0 battery events, Bluetooth GATT notifications, ...) are added as
// new IEventSource classes; the scheduler and the worker do not change.
#include "refresh.h"

struct IEventSource {
    virtual ~IEventSource() = default;
    virtual bool Start(IRefreshSink& sink) = 0;
    virtual void Stop() = 0;
    // The set of HID devices changed (arrival, removal, resume): reopen whatever is held.
    virtual void DevicesChanged() = 0;
};
