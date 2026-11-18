#include "../src/refresh.h"

#include <cassert>
#include <cstdio>

using R = RefreshReason;

int main() {
    // Idle: nothing due, nothing to wait for.
    {
        RefreshPlan p;
        assert(p.WaitMs(0) == RefreshPlan::kNever);
        assert(p.TakeDue(1000000).Empty());
    }
    // Startup at once; one poll consumes it.
    {
        RefreshPlan p;
        p.Add(R::Startup, 100, 0);
        assert(p.WaitMs(100) == 0);
        RefreshReasons due = p.TakeDue(100);
        assert(due.Has(R::Startup) && !due.Has(R::Timer));
        assert(p.TakeDue(100).Empty());
    }
    // Not due yet: wait the remaining time.
    {
        RefreshPlan p;
        p.Add(R::Timer, 0, 60000);
        assert(p.WaitMs(15000) == 45000);
        assert(p.TakeDue(59999).Empty());
        assert(p.TakeDue(60000).Has(R::Timer));
    }
    // Non-debounced reasons keep the earliest deadline.
    {
        RefreshPlan p;
        p.Add(R::Manual, 0, 500);
        p.Add(R::Manual, 100, 5000);
        assert(p.WaitMs(100) == 400);
    }
    // Debounced reasons wait for the burst to end (trailing).
    {
        RefreshPlan p;
        p.Add(R::DeviceChange, 0, 2500);
        p.Add(R::DeviceChange, 2000, 2500);  // another arrival: push to 4500
        assert(p.TakeDue(2600).Empty());
        assert(p.WaitMs(2600) == 1900);
        assert(p.TakeDue(4500).Has(R::DeviceChange));
    }
    // ...but never past first + 10 s, so a flapping device cannot starve the poll.
    {
        RefreshPlan p;
        for (std::uint64_t t = 0; t <= 20000; t += 1000) p.Add(R::DeviceEvent, t, 1500);
        assert(p.WaitMs(20000) == 0);  // capped at 0 + 10000, overdue
        assert(p.TakeDue(20000).Has(R::DeviceEvent));
    }
    // One poll answers every pending reason, even ones due later (conflation).
    {
        RefreshPlan p;
        p.Add(R::Timer, 0, 60000);
        p.Add(R::DeviceEvent, 1000, 1500);
        RefreshReasons due = p.TakeDue(2500);
        assert(due.Has(R::Timer) && due.Has(R::DeviceEvent));
        assert(p.WaitMs(2500) == RefreshPlan::kNever);
    }
    // A request made during a poll survives the timer re-arm that follows the poll.
    {
        RefreshPlan p;
        p.Add(R::Manual, 5000, 0);   // clicked while polling
        p.Add(R::Timer, 5100, 60000);  // worker re-arms after the poll
        assert(p.WaitMs(5100) == 0);
        RefreshReasons due = p.TakeDue(5100);
        assert(due.Has(R::Manual) && due.Has(R::Timer));
    }
    std::puts("refresh_plan_test: ok");
    return 0;
}
