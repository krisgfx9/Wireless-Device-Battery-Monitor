# TaskbarX compatibility patch — experimental widget mode

This branch is based on the safe fallback branch and adds an opt-in experiment for Windows 10 systems running TaskbarX.

## Modes

- **Safe default:** if `TaskbarX.exe` or legacy `FalconX.exe` is detected, the widget is not created; battery indicators use tray icons.
- **Experimental opt-in:** the menu item *Experimental: keep widget on taskbar with TaskbarX (may overlap)* allows the widget to be created beside the notification area. In this mode, Wireless Battery deliberately does not resize `ReBarWindow32`, avoiding direct interference with TaskbarX's task-button layout. The widget may overlap app buttons if the taskbar is crowded; this has to be tested on the user's setup.
- With TaskbarX stopped, the normal widget behavior remains, including reserving space when needed.

The setting is stored at `HKCU\\Software\\WirelessBattery\\TaskbarXExperimentalWidget` and defaults to off. Changing it takes effect immediately; turn it off to return to tray icons when TaskbarX is active.

## Keeping the patch after upstream updates

- Keep the fork's `main` branch synchronized with upstream as usual.
- Bring the updated `main` into this compatibility branch (merge or rebase).
- If `src/widget.cpp` conflicts, retain `TaskbarXRunning()`, the experimental flag, the early return when experimental mode is off, and the logic that leaves `g_rebar` null while TaskbarX is active. Re-check taskbar positioning and layout code if upstream changes it.
- Keep the menu setting and its registry persistence in `src/main.cpp`, plus the API in `src/widget.h`.
- Run the `TaskbarX experimental widget build` workflow after updating this branch.

This is an experiment, not a guarantee of collision-free placement. The initial verification target is Windows 10 22H2 / TaskbarX 1.7.8.0.


## User validation (2026-11-18)

Tested by the user on Windows 10 22H2 (build 19045) with TaskbarX 1.7.8.0 and Wireless Device Battery Monitor 1.0.8.

- The experimental setting was enabled and the widget behaved as intended: it remained on the taskbar while TaskbarX was running.
- The user confirmed the widget worked as expected in the test (including the previously tested demo mode).
- **Known limitation confirmed:** the widget can overlap application taskbar icons.
- This is acceptable for the user's workflow, which normally uses icon-only taskbar buttons and does not keep many applications open. The user also expects to connect relatively few 2.4 GHz devices.
- The setting remains opt-in and off by default. If the overlap is inconvenient, disable the experimental setting to revert to tray icons while TaskbarX is active.

This is a successful user-environment test of the intended behavior, with the overlap limitation documented; it is not a claim that placement is collision-free for all taskbar layouts.
