<!-- lang-switcher:start -->
🌐 **Languages:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md)
<!-- lang-switcher:end -->

# BatteryHub Multi-Language Index & Localization Guide

Every visible document in this repository is collected into **one standalone Markdown file per language** inside [`docs/i18n/`](.), while all runtime application strings live in **static editable JSON files** inside [`lang/`](../../lang) (shared by Windows and Linux) and Windows installer strings live in [`installer/lang/`](../../installer/lang).

## Supported Languages (19)

| Code | Language | Complete Documentation | App UI (Windows & Linux) | Windows Installer |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (source strings) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
| `ar` | العربية | [ar.md](ar.md) | [`lang/ar.json`](../../lang/ar.json) | [`installer/lang/ar.isl`](../../installer/lang/ar.isl) |
| `de` | Deutsch | [de.md](de.md) | [`lang/de.json`](../../lang/de.json) | [`installer/lang/de.isl`](../../installer/lang/de.isl) |
| `es` | Español | [es.md](es.md) | [`lang/es.json`](../../lang/es.json) | [`installer/lang/es.isl`](../../installer/lang/es.isl) |
| `fa` | فارسی | [fa.md](fa.md) | [`lang/fa.json`](../../lang/fa.json) | [`installer/lang/fa.isl`](../../installer/lang/fa.isl) |
| `fr` | Français | [fr.md](fr.md) | [`lang/fr.json`](../../lang/fr.json) | [`installer/lang/fr.isl`](../../installer/lang/fr.isl) |
| `he` | עברית | [he.md](he.md) | [`lang/he.json`](../../lang/he.json) | [`installer/lang/he.isl`](../../installer/lang/he.isl) |
| `hu` | Magyar | [hu.md](hu.md) | [`lang/hu.json`](../../lang/hu.json) | [`installer/lang/hu.isl`](../../installer/lang/hu.isl) |
| `ja` | 日本語 | [ja.md](ja.md) | [`lang/ja.json`](../../lang/ja.json) | [`installer/lang/ja.isl`](../../installer/lang/ja.isl) |
| `ko` | 한국어 | [ko.md](ko.md) | [`lang/ko.json`](../../lang/ko.json) | [`installer/lang/ko.isl`](../../installer/lang/ko.isl) |
| `pl` | Polski | [pl.md](pl.md) | [`lang/pl.json`](../../lang/pl.json) | [`installer/lang/pl.isl`](../../installer/lang/pl.isl) |
| `pt-BR` | Português (Brasil) | [pt-BR.md](pt-BR.md) | [`lang/pt-BR.json`](../../lang/pt-BR.json) | [`installer/lang/pt-BR.isl`](../../installer/lang/pt-BR.isl) |
| `ru` | Русский | [ru.md](ru.md) | [`lang/ru.json`](../../lang/ru.json) | [`installer/lang/ru.isl`](../../installer/lang/ru.isl) |
| `sv` | Svenska | [sv.md](sv.md) | [`lang/sv.json`](../../lang/sv.json) | [`installer/lang/sv.isl`](../../installer/lang/sv.isl) |
| `tr` | Türkçe | [tr.md](tr.md) | [`lang/tr.json`](../../lang/tr.json) | [`installer/lang/tr.isl`](../../installer/lang/tr.isl) |
| `uk` | Українська | [uk.md](uk.md) | [`lang/uk.json`](../../lang/uk.json) | [`installer/lang/uk.isl`](../../installer/lang/uk.isl) |
| `vi` | Tiếng Việt | [vi.md](vi.md) | [`lang/vi.json`](../../lang/vi.json) | [`installer/lang/vi.isl`](../../installer/lang/vi.isl) |
| `zh-CN` | 简体中文 | [zh-CN.md](zh-CN.md) | [`lang/zh-CN.json`](../../lang/zh-CN.json) | [`installer/lang/zh-CN.isl`](../../installer/lang/zh-CN.isl) |
| `zh-TW` | 繁體中文 | [zh-TW.md](zh-TW.md) | [`lang/zh-TW.json`](../../lang/zh-TW.json) | [`installer/lang/zh-TW.isl`](../../installer/lang/zh-TW.isl) |

---

## How Language Switching Works in Practice

### 1. Windows App (`BatteryHub.exe`)
- **Automatic detection:** When set to *Language → Automatic (Windows language)*, BatteryHub queries Windows `GetUserPreferredUILanguages` and matches the closest static `*.json` file.
- **Manual switching:** Click the taskbar widget or tray icon → **Language** → pick a language. The UI updates immediately and persists in `HKCU\Software\WirelessBattery\Language`.
- **Static external files (editable without rebuilding):** `BatteryHub.exe` loads `<exe>\lang\*.json` first, then `%APPDATA%\WirelessBattery\lang\*.json`. Any file in the user folder with the same `@code` overrides matching phrases, and reopening the menu reloads files from disk live.
- **CLI `--help`:** `BatteryHub.exe --help` shows the help dialog in your active UI language (`--list`, `--json`, and `--dump` intentionally stay English for GitHub issue reports).

### 2. Linux App (`wireless-battery`)
- **Automatic detection:** Follows POSIX locale variables in order: `LANGUAGE` (colon-separated list) → `LC_ALL` → `LC_MESSAGES` → `LANG` (unless overridden by `LC_ALL=C` / `POSIX`).
- **Manual switching:** Right-click the tray icon → **Language** → pick **Automatic (system language)** or any installed language. Saved under `[general] language=` in `$XDG_CONFIG_HOME/wireless-battery/config.ini` (default `~/.config/wireless-battery/config.ini`).
- **Static search paths (lowest to highest priority):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (default `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (default `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help` prints translated CLI help based on `config.ini` or system locale; `--list` and `--dump` stay English.

### 3. Windows Installer (`BatteryHub-Setup-<version>.exe`)
- Prompts with a language selector (`ShowLanguageDialog=yes`) pre-selected from your Windows UI language (`LanguageDetectionMethod=uilanguage`).
- Installs the full static `lang\*.json` directory into `{app}\lang\` alongside `BatteryHub.exe` (and the portable ZIP likewise ships `lang\*.json`).

---

## How to Add or Update a Language (Step-by-Step)

You do **not** need any build tools to translate the app UI or the documentation, and only Inno Setup 6 if you want to test-compile the Windows installer.

### Step 1 — App UI Strings (`lang/<code>.json`)
1. Open the user language folder from the tray menu (**Language → Add your own language...**) or copy [`lang/_template.json`](../../lang/_template.json) to `lang/<code>.json` (e.g. `lang/it.json`).
2. Fill in the metadata keys and `"Original English": "Translation"` pairs:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
   - Set `"@rtl": true` only for right-to-left scripts (Arabic, Hebrew, Persian, etc.).
   - Keep placeholders like `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}` verbatim.
   - Use `\n` inside JSON strings for explicit line breaks.
   - Save as valid **UTF-8 (no BOM)** JSON.
   - Re-open the BatteryHub tray menu to preview immediately — no rebuild required!

### Step 2 — Windows Installer (`installer/lang/<code>.isl`)
1. Copy [`installer/lang/_template.isl`](../../installer/lang/_template.isl) to `installer/lang/<code>.isl`.
2. **CRITICAL:** Save the file as **UTF-8 with BOM (`EF BB BF`)** so Inno Setup decodes Unicode characters reliably regardless of legacy Windows code pages.
3. Choose the matching pattern:
   - **Inno Setup already ships your language** (check `C:\Program Files (x86)\Inno Setup 6\Languages\`): keep only `[CustomMessages]` and translate the 6 lines (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, preserving `%1` and `%n`). Register in `installer/BatteryHub.iss` under `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup does not ship your language**: copy `installer/lang/zh-CN.isl` as a full reference, set `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, optional `RightToLeft=yes`), translate `[Messages]` and `[CustomMessages]`, and register after `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Note: `[Languages]` `Name:` identifiers must contain only ASCII letters, digits, and underscores (use `ptBR`, not `pt-BR`).

### Step 3 — Linux Desktop Launcher (`linux/wireless-battery.desktop`)
Add a localized `Comment[<code>]=...` line (use underscores for regional tags in `.desktop` files, e.g. `Comment[zh_CN]=...`).

### Step 4 — Complete Single-File Documentation (`docs/i18n/<code>.md`)
1. Copy [`docs/i18n/_template.md`](_template.md) to `docs/i18n/<code>.md` (zero generator scripts needed — only this one file!).
2. Translate the Table of Contents and all 17 sections in full while keeping:
   - All `<a id="sec-..."></a>` anchor tags and `<a id="top"></a>` intact
   - All code blocks, CLI flags (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), USB `VID:PID`s, HID usage pages, hex packets, registry keys, file paths, and URLs verbatim
   - Relative image/file paths intact (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE`, etc.)
3. Update the top `<!-- lang-switcher:start -->` bar in `docs/i18n/<code>.md` (bold your own language, link all others), add your language link to the switcher bars in `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md`, and sibling `docs/i18n/*.md` files.
4. For right-to-left languages (`ar`, `fa`, `he`), write standard Markdown without wrapping the whole file in `<div dir="rtl">` so tables and code blocks render cleanly.
