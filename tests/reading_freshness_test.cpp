// Battery Reading Freshness policy tests: independent of Win32/device hardware.
#include "../src/reading_freshness.h"
#include <cassert>
#include <cstdio>

int main() {
    using namespace reading_freshness;
    constexpr std::uint64_t minute = 60000;
    constexpr std::uint64_t start = 1000;

    assert(Confirmed(0, true, false));
    assert(Confirmed(100, true, false));
    assert(!Confirmed(-1, true, false));
    assert(!Confirmed(101, true, false));
    assert(!Confirmed(42, false, false));
    assert(!Confirmed(42, true, true));

    assert(Classify(0, start) == State::Unknown);
    assert(Classify(start, start) == State::Fresh);
    assert(Classify(start, start + 3 * minute - 1) == State::Fresh);
    assert(Classify(start, start + 3 * minute) == State::Delayed);
    assert(Classify(start, start + 10 * minute - 1) == State::Delayed);
    assert(Classify(start, start + 10 * minute) == State::Stale);
    assert(Classify(start, start + 24 * 60 * minute) == State::Stale);

    assert(AgeMinutes(start, start + minute - 1) == 0);
    assert(AgeMinutes(start, start + minute) == 1);
    assert(AgeMinutes(start, start + 11 * minute) == 11);
    assert(AgeMs(start, start - 1) == 0); // defensive clock regression
    assert(Classify(start, start - 1) == State::Fresh);

    assert(!ShouldDim(50, false, start, start + 2 * minute));
    assert(!ShouldDim(50, false, start, start + 3 * minute));
    assert(ShouldDim(50, false, start, start + 10 * minute));
    assert(ShouldDim(-1, false, start, start + minute));
    assert(ShouldDim(50, true, start, start + minute));
    assert(ShouldDim(-1, true, 0, start));

    // Invalid polls must not advance the tick; a real sample resets the age.
    std::uint64_t latest = start;
    if (Confirmed(-1, true, false)) latest = start + 12 * minute;
    assert(Classify(latest, start + 12 * minute) == State::Stale);
    if (Confirmed(52, true, false)) latest = start + 12 * minute;
    assert(Classify(latest, start + 12 * minute) == State::Fresh);
    if (Confirmed(52, true, true)) latest = start + 30 * minute;
    assert(Classify(latest, start + 30 * minute) == State::Stale);

    puts("Battery Reading Freshness policy tests passed");
    return 0;
}
