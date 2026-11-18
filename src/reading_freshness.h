#pragma once
// Battery reading age policy. Only an actual, connected, non-sleeping percentage
// sample updates the timestamp. Missing/offline/cached samples are not fresh data.
// Portable C++17: no Windows APIs and no I/O.
#include <cstdint>

namespace reading_freshness {

constexpr std::uint64_t kDelayedAfterMs = 3ULL * 60 * 1000;
constexpr std::uint64_t kStaleAfterMs = 10ULL * 60 * 1000;

enum class State { Unknown, Fresh, Delayed, Stale };

inline bool Confirmed(int percent, bool connected, bool asleep) {
    return connected && !asleep && percent >= 0 && percent <= 100;
}

// GetTickCount64() is monotonic across wall-clock changes. Zero means never read.
inline std::uint64_t AgeMs(std::uint64_t lastTick, std::uint64_t now) {
    return !lastTick || now < lastTick ? 0 : now - lastTick;
}

inline std::uint64_t AgeMinutes(std::uint64_t lastTick, std::uint64_t now) {
    return AgeMs(lastTick, now) / (60ULL * 1000);
}

inline State Classify(std::uint64_t lastTick, std::uint64_t now) {
    if (!lastTick) return State::Unknown;
    const auto age = AgeMs(lastTick, now);
    if (age >= kStaleAfterMs) return State::Stale;
    if (age >= kDelayedAfterMs) return State::Delayed;
    return State::Fresh;
}

inline bool ShouldDim(int currentPercent, bool asleep, std::uint64_t lastTick, std::uint64_t now) {
    return currentPercent < 0 || asleep || Classify(lastTick, now) == State::Stale;
}

} // namespace reading_freshness
