# TaskbarX compatibility patch

This branch carries a small compatibility patch for Windows 10 systems running TaskbarX.

## Behavior

If `TaskbarX.exe` or the legacy `FalconX.exe` process is detected, Wireless Battery does not create its taskbar widget. It uses the existing system-tray icon mode instead, avoiding its normal `ReBarWindow32` resizing logic, which can compete with TaskbarX's taskbar layout changes.

The widget's `Alive()` check also re-detects TaskbarX so the app can reconcile the display mode when TaskbarX is started or stopped while Wireless Battery is already running.

## Keeping this patch after upstream updates

- Keep the fork's `main` branch synchronized with upstream as usual.
- Bring the updated `main` into this compatibility branch (merge or rebase).
- If `src/widget.cpp` conflicts, retain the `TaskbarXRunning()` helper, the early return in `widget::Create()`, and the TaskbarX check in `widget::Alive()`. Re-check the surrounding taskbar-widget code if upstream changes it.
- Run the `TaskbarX compatibility test build` workflow after updating this branch.

This is a conservative fallback, not a claim that every TaskbarX version has been tested. The actual behavior still needs verification on the Windows 10 22H2 / TaskbarX 1.7.8.0 setup that reported the conflict.
