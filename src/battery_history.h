#pragma once
#include <windows.h>
#include <string>

namespace battery_history {
// Called once before polling starts. Demo data is ephemeral and never written to disk.
void Initialize(bool demo);
// Stores only valid, connected and awake readings (the caller enforces connection state).
void Observe(const std::wstring& key, int percent, bool charging);
// Non-modal native Win32 history viewer; device identity remains the original key.
void Show(HWND owner, const std::wstring& key, const std::wstring& displayName);
// The viewer's "Estimated time to empty" as text ("~2 d 5 h"), or empty when there is none.
std::wstring TimeToEmpty(const std::wstring& key);
} // namespace battery_history
