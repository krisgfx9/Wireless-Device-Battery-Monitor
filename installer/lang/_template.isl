; BatteryHub Inno Setup language template.
; IMPORTANT: Save every .isl file as UTF-8 WITH BOM (EF BB BF) so Inno Setup reads Unicode properly!
;
; Case A — Language IS bundled in Inno Setup's built-in Languages\ folder:
;   1. Copy the [CustomMessages] section below to installer\lang\<code>.isl and translate the 6 lines.
;   2. Add one line under [Languages] in installer\BatteryHub.iss:
;      Name: "<code>"; MessagesFile: "compiler:Languages\<Language>.isl,lang\<code>.isl"
;      (Note: identifier names under [Languages] may only contain letters, digits, and underscores.)
;
; Case B — Language is NOT bundled in Inno Setup's Languages\ folder (e.g. zh-CN, zh-TW, fa, vi):
;   1. Copy installer\lang\zh-CN.isl (or include [LangOptions], [Messages], and [CustomMessages])
;      to installer\lang\<code>.isl.
;   2. Fill in LanguageName, LanguageID (hex Windows LCID, e.g. $0410), LanguageCodePage=0, and
;      RightToLeft=yes if applicable, then translate [Messages] and [CustomMessages].
;   3. Add one line under [Languages] in installer\BatteryHub.iss:
;      Name: "<code>"; MessagesFile: "compiler:Default.isl,lang\<code>.isl"
;
; Keep %1 and %n placeholders unchanged.

;[LangOptions]
;LanguageName=English
;LanguageID=$0409
;LanguageCodePage=0
;RightToLeft=yes

[CustomMessages]
AutostartTask=Start BatteryHub when I sign in to Windows
LaunchApp=Start BatteryHub now
SupportProject=Enjoying BatteryHub? Support it on Ko-fi
CloseFailed=BatteryHub could not close. Close it and try updating again.
DirNotWritableAdmin=Setup cannot create or write to this folder:%n%1%n%nPlease choose a different folder.
DirNotWritableUser=Your account cannot create or write to this folder without administrator rights:%n%1%n%nChoose a folder you own (the default one always works), or close Setup, run it again and pick "Install for all users".
