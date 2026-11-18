#include "refresh_scheduler.h"

RefreshScheduler::RefreshScheduler() : wake_(CreateEventW(nullptr, FALSE, FALSE, nullptr)) {}

RefreshScheduler::~RefreshScheduler() {
    if (wake_) CloseHandle(wake_);
}

void RefreshScheduler::RequestRefresh(RefreshReason why, std::uint32_t delayMs) {
    {
        std::lock_guard<std::mutex> lock(m_);
        plan_.Add(why, GetTickCount64(), delayMs);
    }
    SetEvent(wake_);
}

RefreshReasons RefreshScheduler::WaitForDue(HANDLE stop) {
    for (;;) {
        std::uint64_t waitMs;
        {
            std::lock_guard<std::mutex> lock(m_);
            std::uint64_t now = GetTickCount64();
            RefreshReasons due = plan_.TakeDue(now);
            if (!due.Empty()) return due;
            waitMs = plan_.WaitMs(now);
        }
        DWORD timeout = waitMs >= INFINITE ? INFINITE : (DWORD)waitMs;
        HANDLE hs[2] = { stop, wake_ };
        if (WaitForMultipleObjects(2, hs, FALSE, timeout) == WAIT_OBJECT_0) return {};
    }
}
