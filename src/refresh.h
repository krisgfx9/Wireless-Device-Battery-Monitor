#pragma once
// When to poll, and why. Free of Win32 so the coalescing rules can be unit tested.
//
//   emitters                          collector                     consumer
//   WndProc (USB, resume, menu) --.
//   HidppListener (0x41)        --+--> IRefreshSink --> RefreshScheduler --> Worker --> PollAllDevices
//   Worker (next timer tick)    --'                    (RefreshPlan inside)
//
// Emitters only know IRefreshSink. The plan is a conflating mailbox: each reason keeps one slot,
// so twenty USB arrivals in a burst become one poll, and one poll answers every pending reason.
#include <algorithm>
#include <cstdint>

enum class RefreshReason : std::uint8_t { Startup, Timer, Manual, DeviceChange, Resume, DeviceEvent, Count };

inline const char* RefreshReasonName(RefreshReason r) {
    static const char* const names[] = { "startup", "timer", "manual", "device change", "resume", "device event" };
    return r < RefreshReason::Count ? names[(int)r] : "?";
}

class RefreshReasons {
public:
    void Add(RefreshReason r) { bits_ |= Bit(r); }
    bool Has(RefreshReason r) const { return (bits_ & Bit(r)) != 0; }
    bool Empty() const { return bits_ == 0; }

private:
    static std::uint32_t Bit(RefreshReason r) { return 1u << (int)r; }
    std::uint32_t bits_ = 0;
};

// Anything that wants the devices polled. Safe to call from any thread.
struct IRefreshSink {
    virtual ~IRefreshSink() = default;
    virtual void RequestRefresh(RefreshReason why, std::uint32_t delayMs) = 0;
};

class RefreshPlan {
public:
    static constexpr std::uint64_t kNever = UINT64_MAX;

    void Add(RefreshReason why, std::uint64_t now, std::uint32_t delayMs) {
        Slot& s = slots_[(int)why];
        const Policy& p = PolicyFor(why);
        std::uint64_t want = now + delayMs;
        if (!s.pending) {
            s = { true, want, now };
        } else if (p.debounce) {
            // Trailing debounce: wait for the burst to end, but never past first + maxDefer, so a
            // device that keeps flapping cannot postpone the poll forever.
            s.due = std::min(want, s.first + p.maxDeferMs);
        } else {
            s.due = std::min(s.due, want);
        }
    }

    // Milliseconds until the next poll is due, 0 if overdue, kNever if nothing is pending.
    std::uint64_t WaitMs(std::uint64_t now) const {
        std::uint64_t due = EarliestDue();
        return due == kNever ? kNever : (due > now ? due - now : 0);
    }

    // When a poll is due, returns every pending reason and clears them all (one poll serves
    // them all). Returns an empty set otherwise.
    RefreshReasons TakeDue(std::uint64_t now) {
        RefreshReasons out;
        if (EarliestDue() > now) return out;
        for (int i = 0; i < (int)RefreshReason::Count; ++i)
            if (slots_[i].pending) {
                out.Add((RefreshReason)i);
                slots_[i] = {};
            }
        return out;
    }

private:
    struct Slot {
        bool pending = false;
        std::uint64_t due = 0, first = 0;
    };
    struct Policy {
        bool debounce;
        std::uint32_t maxDeferMs;
    };
    // The coalescing rule of each reason lives here and nowhere else.
    static const Policy& PolicyFor(RefreshReason r) {
        static const Policy table[] = {
            { false, 0 },     // Startup: as soon as possible
            { false, 0 },     // Timer: re-armed after every poll
            { false, 0 },     // Manual: the user is waiting
            { true, 10000 },  // DeviceChange: USB enumeration comes in bursts
            { true, 10000 },  // Resume: devices reappear one by one
            { true, 10000 },  // DeviceEvent: a receiver reports each of its devices
        };
        static_assert(sizeof(table) / sizeof(table[0]) == (int)RefreshReason::Count, "one policy per reason");
        return table[(int)r];
    }
    std::uint64_t EarliestDue() const {
        std::uint64_t due = kNever;
        for (const Slot& s : slots_)
            if (s.pending) due = std::min(due, s.due);
        return due;
    }

    Slot slots_[(int)RefreshReason::Count];
};
