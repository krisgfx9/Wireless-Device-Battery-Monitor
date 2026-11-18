#pragma once
// The collector: a thread-safe IRefreshSink in front of RefreshPlan, which the worker blocks on.
#include <windows.h>

#include <mutex>

#include "refresh.h"

class RefreshScheduler final : public IRefreshSink {
public:
    RefreshScheduler();
    ~RefreshScheduler() override;
    RefreshScheduler(const RefreshScheduler&) = delete;
    RefreshScheduler& operator=(const RefreshScheduler&) = delete;

    void RequestRefresh(RefreshReason why, std::uint32_t delayMs) override;

    // Blocks until a poll is due and returns why, or returns an empty set once `stop` is signalled.
    RefreshReasons WaitForDue(HANDLE stop);

private:
    std::mutex m_;
    RefreshPlan plan_;
    HANDLE wake_;  // auto-reset: a new request may have moved the deadline earlier
};
