// The scheduler across threads: a request from another thread wakes a waiting worker, and
// stopping returns an empty set.
#include "../src/refresh_scheduler.h"

#include <cassert>
#include <cstdio>

struct Args {
    RefreshScheduler* s;
    DWORD sleepMs;
    RefreshReason why;
};

DWORD WINAPI Later(LPVOID p) {
    auto* a = static_cast<Args*>(p);
    Sleep(a->sleepMs);
    a->s->RequestRefresh(a->why, 0);
    return 0;
}

int main() {
    HANDLE stop = CreateEventW(nullptr, TRUE, FALSE, nullptr);
    RefreshScheduler s;

    // A worker waiting on a 60 s timer is woken early by a request from another thread.
    s.RequestRefresh(RefreshReason::Timer, 60000);
    Args a{ &s, 100, RefreshReason::Manual };
    HANDLE t = CreateThread(nullptr, 0, Later, &a, 0, nullptr);
    ULONGLONG start = GetTickCount64();
    RefreshReasons due = s.WaitForDue(stop);
    ULONGLONG took = GetTickCount64() - start;
    assert(due.Has(RefreshReason::Manual) && due.Has(RefreshReason::Timer));
    assert(took < 2000);
    WaitForSingleObject(t, INFINITE);
    CloseHandle(t);

    // A delayed request is honoured on time, not early.
    s.RequestRefresh(RefreshReason::DeviceEvent, 300);
    start = GetTickCount64();
    due = s.WaitForDue(stop);
    took = GetTickCount64() - start;
    assert(due.Has(RefreshReason::DeviceEvent) && took >= 250 && took < 2000);

    // Stop wins over an idle wait.
    SetEvent(stop);
    assert(s.WaitForDue(stop).Empty());

    CloseHandle(stop);
    std::puts("refresh_scheduler_test: ok");
    return 0;
}
