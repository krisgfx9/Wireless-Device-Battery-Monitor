<!--
  Traducción completa de la documentación de BatteryHub (Español)
  Fuente: docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Idiomas:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | **Español** | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Añadir un idioma](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Documentación completa (Español)

> Este archivo Markdown independiente reúne toda la documentación visible del repositorio para que los traductores solo tengan que mantener **un archivo por idioma**.

## Índice

1. [Descripción general de BatteryHub, dispositivos compatibles, instalación, línea de comandos y compilación (`README.md`)](#sec-readme)
2. [Guía de contribución (`CONTRIBUTING.md`)](#sec-contributing)
3. [Plantilla de Pull Request (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Guía de publicación y firma (`docs/releasing.md`)](#sec-releasing)
5. [Parche de firmware 2.4 GHz para teclados Keychron (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [Soporte BLE para GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Guía de uso multilingüe y localización (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Receptor Areson 25A7 (`docs/areson.md`)](#sec-areson)
10. [Receptor DARKRIM SHADOW (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Receptor Inphic IN10 / KP 8K (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Soporte de batería para ratones Rapoo (`docs/rapoo.md`)](#sec-rapoo)
16. [Notas sobre el protocolo RAWM (`docs/rawm.md`)](#sec-rawm)
17. [Receptores VAXEE 4K/8K (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Sección:** Descripción general de BatteryHub (`README.md`) · [Original en inglés](../../README.md) · [↑ Arriba](#top)

# BatteryHub

*Antes llamado **Wireless Battery**. La versión 1.1.0 renombró la aplicación; al actualizar se conservan tu configuración, tu preferencia de inicio automático y tu historial de batería.*

[![Apóyame en Ko-fi](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Donar con PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Únete a nuestro Discord](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Dar estrella en GitHub](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Compartir en Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Reportar un dispositivo](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Ayudar a traducir](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Los niveles de batería de tu ratón, auriculares, teclado y mando inalámbricos, directamente en la barra de tareas de Windows.

![BatteryHub en la barra de tareas](../screenshot.png)

> **¿Solo quieres que funcione?** Descarga **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** desde la última versión, ejecútalo y sigue el asistente. Eso es todo.
>
> **Los usuarios avanzados** pueden descargar el archivo ZIP portable, usar las [opciones de línea de comandos](#línea-de-comandos), o [compilarlo desde el código fuente](#compilación) con `make` o `build.bat`.
>
> **¿Te gusta?** BatteryHub es gratuito y de código abierto. Si te ahorra tener que abrir el software del fabricante, puedes apoyar el proyecto en [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) o [GitHub Sponsors](https://github.com/sponsors/krisgfx9). Me ayuda a mantener mis aplicaciones gratuitas mientras estudio. ¿No puedes donar? Dar una ⭐ estrella, compartirlo o reportar un dispositivo no compatible con `--dump` ayuda exactamente igual.

- **Diminuto**: una aplicación de ~350 KB que usa unos 2 MB de RAM. Es puro C++/Win32, sin entorno de ejecución ni servicio en segundo plano, y se instala en segundos sin permisos de administrador.
- **Sin software del fabricante**: habla directamente con los dispositivos. G HUB, Synapse, iCUE, GG y NGenuity pueden quedarse cerrados (o seguir ejecutándose; no entran en conflicto).
- **Muchas marcas**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, mandos de PlayStation y Xbox, Samsung Galaxy Buds, cualquier dispositivo Bluetooth del que Windows conozca el nivel de batería y todos los auriculares compatibles con el [HeadsetControl](https://github.com/Sapd/HeadsetControl) incluido.

## Visualización

**En la barra de tareas (predeterminado):** `🎧 30%  🖱 93%` junto al área de notificación, dibujado con la fuente de iconos de Windows.
- **Batería baja:** un número en rojo indica 15% o menos.
- **Cargando:** aparece un rayo azul ⚡ junto al número. Cuando el dispositivo alcanza la carga completa y sigue conectado a la corriente, cambia a una marca verde ✓.
- **En reposo:** el texto atenuado indica que el dispositivo está en reposo y se muestra el último valor conocido.
- **Desconectado (opcional):** activa *Mostrar dispositivos desconectados* para ver una `×` atenuada en los dispositivos cuyo controlador informe explícitamente de un enlace inalámbrico sin conexión. Esto no deduce la desconexión a partir de un sondeo de batería fallido; el comportamiento predeterminado sigue siendo ocultar los dispositivos sin conexión.
- **Dos dispositivos del mismo tipo:** si tienes dos ratones (o dos mandos...), ambos tendrían el mismo icono, así que cada uno recibe una pequeña etiqueta de hasta 3 letras en la esquina de su icono, tomada de su nombre (`MX`, `PRO`), o un número cuando los nombres no bastan para distinguirlos. Un dispositivo que es único de su tipo no muestra ninguna etiqueta.
- **Tema:** sigue el modo claro/oscuro y el escalado PPP (DPI) de Windows.
- **Temas de barra de tareas transparente** (por ejemplo, Taskbar Styler de Windhawk): activa *Fondo detrás del texto de la barra de tareas* en el menú para que el texto siga siendo legible sobre el fondo de pantalla.
- **Varios monitores:** el widget aparece en la barra de tareas de cada monitor, junto a su reloj, para que siga visible cuando ejecutas un juego en pantalla completa. En el menú, *Mostrar el widget en* permite elegir *Todos los monitores*, *Solo el monitor principal* o una pantalla concreta (por ejemplo, solo *Pantalla 3*).
- **Más opciones de visualización:** *Iconos encima de los porcentajes* apila cada icono sobre su nivel para ahorrar ancho; *Colores de marca* muestra las marcas conocidas en su color (verde Razer, rojo HyperX, ...) con una pequeña barra de nivel; dos dispositivos del mismo tipo muestran una pequeña etiqueta para diferenciarlos; las barras de tareas situadas a la izquierda o derecha muestran los dispositivos en columna.
- **Idiomas:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 y 繁體中文. Tanto la aplicación de Windows como la de Linux siguen el idioma de visualización del sistema; *Idioma* en el menú permite elegir otro, y el instalador de Windows también admite los 19 idiomas. Las frases de la interfaz residen en archivos estáticos editables `lang/*.json`, y la documentación completa traducida se encuentra en [`docs/i18n/`](README.md). Consulta [Traducciones](#traducciones) para editar o añadir un idioma.
- **Colores de marca:** los dispositivos de 15 marcas conocidas adoptan el color de su fabricante, con un brillo suave y una fina barra de nivel bajo el porcentaje: verde Razer, azul Logitech, naranja SteelSeries, amarillo Corsair, rojo HyperX / ROG / ZOWIE, PlayStation, Xbox, Samsung, Apple, Jabra, JBL, Cooler Master y Steam. Cada color tiene un tono para barra de tareas oscura y otro para barra clara. La marca se obtiene del controlador que detectó el dispositivo, luego del ID de proveedor (VID) y después del nombre; los colores y reglas están en `src/brands.cpp`. Puedes desactivarlo con *Colores de marca* en el menú.

**Iconos en la bandeja:** un icono por dispositivo con el número dibujado en su interior, además de una notificación de «Batería baja» al 15%. La aplicación cambia automáticamente a este modo cuando la barra de tareas es vertical o no se encuentra.

**Nombres personalizados de dispositivos:** abre el submenú del dispositivo y selecciona *Renombrar dispositivo...* para definir un nombre (de hasta 64 caracteres). Este nombre aparece en la descripción emergente y etiqueta del widget de la barra de tareas, en la descripción emergente y notificaciones de la bandeja, y en el menú del dispositivo. Usa *Restablecer nombre original* para restaurar el nombre del controlador. Los nombres se guardan localmente en el Registro de Windows del usuario actual (`Software\WirelessBattery`, `DeviceAliases`), usando la clave estable del dispositivo. Renombrar nunca altera la coincidencia de controladores, las consultas de protocolo ni la salida de diagnóstico de `--list` / `--dump`. No se requiere ninguna cuenta ni acceso a la red.

Pasa el cursor por encima para ver detalles. Haz clic para abrir el menú: todos los dispositivos (haz clic en uno para ocultarlo o mostrarlo), modo de visualización, *Actualizar ahora*, *Iniciar con Windows* y *Salir*. Los niveles se actualizan cada 60 segundos (*Comprobar batería cada* en el menú cambia este intervalo) y de inmediato cuando se conecta un dispositivo o el equipo sale de suspensión.

## Alertas de batería inteligentes (experimental)

Puedes establecer un **umbral de notificación de batería baja por dispositivo** desde el submenú de cada dispositivo: **Alertas de batería** → *Usar valor predeterminado (15%)*, *Desactivar notificaciones*, o uno de los valores 5%, 10%, 15%, 20%, 25%, 30%, 35% o 40%. El valor predeterminado de 15% se mantiene sin cambios salvo que elijas una anulación. Los ajustes se guardan por clave de dispositivo en el Registro de Windows del usuario actual (`Software\WirelessBattery`, `AlertThresholds`).

Una alerta se dispara únicamente a partir de una lectura real y reciente de batería de 0 a 100% cuando el dispositivo está conectado, activo y no se está cargando. La alerta se emite una sola vez y volverá a armarse cuando el nivel suba más de 10 puntos porcentuales por encima del umbral elegido (o cuando comience a cargar). Las lecturas ausentes o los dispositivos en reposo no vuelven a disparar alertas. Los dispositivos ocultos no generan notificaciones. Desactivar las notificaciones de un dispositivo no lo oculta ni modifica su porcentaje.

Tanto el modo de widget en la barra de tareas como el modo de iconos en la bandeja admiten notificaciones. Dado que Windows necesita un icono en el área de notificación para mostrar un globo clásico, el modo de widget puede mostrar un icono de notificación temporal durante un máximo de un minuto después de una alerta. Los colores del widget y el resaltado de batería baja siguen usando el umbral global original de 15% del proyecto, de forma independiente de la configuración de notificaciones.

## Historial de batería e información

Haz clic derecho en un dispositivo dentro del widget de la barra de tareas o en el menú de la bandeja y elige **Historial de batería...**. El visor nativo adaptado a PPP (que sigue el tema claro/oscuro de Windows) muestra los niveles de batería registrados con líneas que conectan las muestras durante las últimas **24 horas**, **7 días** o **30 días**, junto con la lectura más reciente, el nivel mínimo/máximo, la variación en puntos porcentuales y el recuento de muestras. Desde el visor puedes borrar el historial del dispositivo seleccionado.

El historial se registra **solo localmente** para los dispositivos conectados y activos que informan de un porcentaje numérico. Las lecturas se muestrean como máximo una vez cada 30 minutos por dispositivo (salvo en transiciones del estado de carga, con un mínimo de 60 segundos). Los datos se conservan hasta 30 días y el archivo local se mantiene por debajo de unos 2 MB. La aplicación nunca sondea el hardware más allá de su intervalo habitual, no envía datos del historial por la red y calcula una estimación conservadora y aproximada del tiempo restante únicamente a partir de observaciones de descarga recientes. Se requieren al menos cuatro puntos, dos horas, un descenso de tres puntos porcentuales, una lectura reciente y un tramo de descarga estable. Cargar el dispositivo, lecturas antiguas o datos insuficientes suprimen la estimación; el tiempo restante informado por el propio dispositivo no está disponible. La estimación no constituye una garantía. Los datos faltantes del gráfico se muestran como huecos y no se interpolan.

Desactiva **Registrar historial de batería** en el menú para dejar de guardar lecturas; lo ya guardado permanece hasta que lo borres en el visor. El archivo se guarda en `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Sus identidades de dispositivo están codificadas (no cifradas); el archivo es local a tu cuenta de Windows. Con `--demo`, el gráfico usa datos sintéticos que nunca se guardan. **Nota:** el historial comienza a recopilarse únicamente después de instalar esta función y de que la aplicación lleve un tiempo en ejecución.

## Dispositivos compatibles

| Fabricante | Dispositivos | Cómo |
|---|---|---|
| **NuPhy** | WH80 por cable USB (`19F5:A011`) o Bluetooth (`19F5:324A`), probado en hardware | USB: consulta de batería NuPhyIO de solo lectura; Bluetooth: nivel de batería de Windows con clasificación de teclado ([notas de protocolo](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) en su receptor USB `3654:6901` (probado en hardware) | Consulta de batería de solo lectura verificada con CRC e indicador de carga; lecturas aproximadas observadas en pasos del 10%, precisión más fina sin verificar ([notas de protocolo](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX en el receptor KP 8K (`1D57:FA65`; modelo `73` probado en hardware, modelo `74` sin probar) | Informes pasivos de estado Xenta; dos tramas coincidentes confirman el nivel ([notas de protocolo](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, probado), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` probado, `002D`/`002A`), A50 Gen 3 (`9886:0015` probado, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), a través de la estación base USB | Porcentaje de batería, estado de carga y de acoplamiento en la base |
| **Logitech** | Ratones y teclados en receptores Unifying, Bolt, Lightspeed (incluido el receptor PRO X3 SUPERSTRIKE `046D:C54F`) y Nano, por USB o Bluetooth; auriculares G (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 en el receptor más reciente `046D:0ADF` | HID++ 1.0 / 2.0 con detección de funciones: batería unificada, nivel de batería, voltaje, ADC; G435: informes del fabricante con trama CRC-16, `GET_BATTERY` en mV |
| **Razer** | Ratones, teclados y receptores inalámbricos; auriculares BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X, V3 Pro for Xbox (receptor `1532:0A55`, cable `0A4E`); Barracuda X (2022) en su receptor de 2.4 GHz (`1532:0550` o `1532:0552`); Barracuda Pro (`1532:053A`) | Protocolo de informes de características de Razer; protocolos del fabricante BlackShark (V3 / V3 Pro / V3 X consultados cada 5 min); Barracuda X: consultas de batería Airoha y estado de cable a través del receptor |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (incluido `1038:225D`), Arctis Nova Elite (estación base `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, sin probar), Aerox 3 Wireless CS2 Dragon Lore Edition (receptor `1038:1878`, cable `187A`), Aerox 3 Wireless Gen 2 (receptor `1038:1890`, cable `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Informes HID del fabricante; Aerox/Prime y Rival 650 comparten una única entrada entre receptor y cable USB, dando prioridad a la lectura por cable cuando ambos responden |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 inalámbricos; dispositivos Bragi (Virtuoso, Void V2, HS80 MAX, ratones y teclados Slipstream, incluido el receptor Slipstream más reciente `1B1C:2B00`, p. ej. Scimitar Elite SE Wireless, y Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, sin probar) | Informes HID del fabricante, Bragi `GET` (solo lectura), protocolo de batería Compx de 17 bytes (solo lectura) |
| **Cooler Master** | MM712, MM731 (receptor de 2.4 GHz o cable USB) | Informe HID de estado del fabricante (solo lectura) |
| **Press Play** | ICARUS V2 Nearlink en su receptor de 2.4 GHz `7768:6434` (controlador probado en hardware al 90%; protocolo capturado al 100% y al 90%) | Informe de salida de solo lectura `06 05` en `FFB2:0001`; porcentaje de batería en el byte 14 de la respuesta |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` para PS, sin probar), Cloud Flight S, Cloud Stinger Core Wireless (incluido DTS `03F0:0A8E`, probado), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (receptor de 2.4 GHz), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (receptor de 2.4 GHz) (receptor de 2.4 GHz `03F0:0F98`, probado; `0D97` sin probar) | Informes HID del fabricante (Haste 2: [notas de protocolo](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Informe de características del fabricante |
| **Hitscan** | Hyperlight X, Hyperlight N | Informe de características del fabricante (mismo protocolo que Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Ratones inalámbricos Kysona M600 / Mercury, Pulsar y ATK VXE (p. ej. VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (receptor 3554:F512) | Protocolo compartido del fabricante con respuestas verificadas mediante suma de comprobación |
| **Pulsar X2 V3** | X2 V3 en el receptor 1K (`3710:5402`) o cable USB (`3710:3402`); X2 V3 eS en el receptor 8K (`3710:5403`) o cable USB (`3710:3406`) | Informe de características del fabricante de 64 bytes, registro de batería `08 81 01` (solo lectura) |
| **ATK / VXE NK** | VXE R1 NK y otros ratones NearLink en el receptor NK mouse NANO (`373B:1216`) | Informe de salida ATK BITMOUSE `08` en `FF05:0001` (batería y carga) |
| **ATK 8K Nano** | Ratones ATK / VXE en el receptor ATK 8K Nano Dongle (`373B:1178`) | Informe de características Holtek GetConfigData (`82`) en `FF10:0001` (de ATK HUB; batería y carga) |
| **Auriculares ATK** | ATK N9 Pro, N9 Ultra (primera generación) | Protocolo de puerto COM virtual (la aplicación de escritorio de ATK debe estar cerrada) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK y sus receptores 8K | Protocolo Glorious o Kysona, según el modelo |
| **Ratones Keychron** | M4 y otros ratones Keychron en el receptor de 2.4 GHz; ratones 4K (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) en el receptor Keychron 4K Link (`3434:D038`); ratones 8K (M5 8K, G6 HE 8K ...) en el receptor TurboLink 8K; ratones 8K en el receptor Ultra-Link 8K (`3434:D028`); ratones anteriores (M1, M2, M3, M3 mini, M6, M7 ...) en el receptor 1K (`3434:D030` / `D031`); trackball Nape Pro en el receptor Link-KM o por cable | Informe del fabricante desde Keychron Launcher (receptor 1K: informe de características 51 06, tal como lo usa la aplicación de escritorio de Keychron; Ultra-Link 8K: informes B5 03 / B3 06 en `FFC1`; Nape Pro: HID sin procesar A7 31) |
| **Teclados Keychron** | K5 Max (`3434:0A50`, probado) en el receptor Keychron Link (`3434:D030`) o por cable USB; otros teclados inalámbricos Keychron QMK una vez compilados con el mismo parche | HID sin procesar en `FF60:0061`: `B2` pregunta al receptor qué teclado está enlazado y `A4` devuelve nivel, voltaje y estado de carga. **Requiere firmware del teclado parcheado:** consulta [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). El firmware de fábrica solo informa por Bluetooth |
| **CHERRY** | Teclado MX 3.0S Wireless en su receptor de 2.4 GHz (`046A:00EA`, probado) o cable USB (`046A:00E3`, probado) | Consulta HID del fabricante `1A` en `FF1C:0092` (solo lectura), con estado de alimentación USB. El modo Bluetooth está cubierto por el soporte Bluetooth |
| **CHERRY** | Ratón inalámbrico Cherry XTRFY en el receptor 1K (`046A:0330`, probado) | Protocolo de batería CompX de 17 bytes (`08 03` estado de enlace, `08 04` GetPower), misma trama que el Corsair Sabre V2 Pro (solo lectura) |
| **Arbiter Studio** | Akitsu (`373E:000A` receptor 8K, `373E:0009` cable), Akitsu 3950 (`373E:0039` receptor 8K, `373E:0038` cable), Akitsu Medium (`373E:0067` receptor 8K y `373E:0066` cable, ambos probados) | Informe de características del fabricante de solo lectura `0x83` en `FFFF:0000` desde Arbiter Web HUB (batería y carga) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (cable, receptores 1K y 4K/8K) | Informe de características del fabricante desde LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) en el receptor 4K; XM2we en su receptor original (`3367:1961`) | Informe de características del fabricante `A1`, comando de batería `B4` (solo lectura) |
| **Teclados ATK / VGN / Evision** | ATK V75X y teclados VGN / VXE (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) en el receptor compartido de 2.4 GHz (`320F:5088`) o cable USB (`320F:5055`), reconocidos por nombre de producto; teclados cuyo receptor `320F:5088` se llama «Wireless Gaming Keyboard», p. ej. Feker Alice80 (probado) | Informe de salida Evision `04`, comando de batería `1A` (desde ATK HUB y VGN HUB); consultado como máximo cada 10 minutos a través del receptor |
| **Redragon (Evision)** | K1NG M999 (probado) en el receptor de 2.4 GHz `320F:226F`; el ID del receptor puede estar compartido con otros modelos | Mismo protocolo Evision que los teclados ATK (informe `04`, comando `1A` en `FF1C:0092`), consultado en cada sondeo; la carga se muestra en la base magnética; con el cable USB conectado el receptor sigue repitiendo el nivel anterior y no muestra estado de carga |
| **Audeze** | Maxwell en el receptor USB (`3329:4B19`) o cable USB-C (`3329:4B1A`); Maxwell 2 en el receptor USB (`3329:4B29`, probado); los ID de Xbox están sin probar | Informe del fabricante `06` / informe de entrada `07`, atributo de batería `0CD6` (una sola consulta de solo lectura) |
| **ENDORFY** | Viro Wireless en su receptor de 2.4 GHz (`3738:0072`, sin probar) | Airoha RACE «get battery» (`0CD6`) en informe del fabricante `06` / informe de entrada `07`, la misma consulta de solo lectura que los receptores Audeze y Skullcandy; sin estado de carga |
| **Turtle Beach** | Stealth 700 Gen 3 en el transmisor USB (`10F5:2251`, probado en HaloBattery; versión PC `10F5:2262`, sin probar) o el propio cable USB de los auriculares (`10F5:2253`) | RACE `0x9942` (activa el cliente CoAP) y una petición CoAP `GET /GSI` tunelizada en RACE `0x9902`, como hace Swarm II; batería en la clave `240` (sin indicador de carga) |
| **AKG** | N9 Hybrid en su receptor USB (`0ECB:20D9`, probado) | Airoha RACE en `FF13:0001`: informe de salida `06`, informe de entrada `07`, atributo de batería `0CD6` (una sola consulta de solo lectura) |
| **NZXT** | Lift Elite Wireless en su receptor (`1E71:2101`) o cable USB (`1E71:2129`) | Lectura del fabricante `4E 02 81 .. B0` (a partir de capturas de NZXT CAM) |
| **Poly / Plantronics** | Voyager 8200 UC y otros auriculares detrás del adaptador BT600 (`047F:02EE` / `02F7`) | Protocolo get/set del informe `07`, elemento de batería `0A 1A` (solo lectura) |
| **WLMouse** | YING Magnesium (receptor YING 8K `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (receptor o cable; no el Beast X 4K); Beast X V2 (receptor 8K `36A7:A856`); Beast G (receptor 8K `36A7:A860` o cable `36A7:A861`; sin probar) | Informe de características del fabricante, comando de estado `0x83` (YING: mismo protocolo que Glorious) |
| **Finalmouse** | UltralightX en su receptor de 2.4 GHz (`361D:0100`, probado); Starlight X en su receptor (`361D:0300` / `0301`, probado). No funciona mediante el cable propio del ratón | Informes del fabricante xpanel en `FF00`: GETs de solo lectura y luego *wake/all* (`0xE0`); voltaje de batería en la curva de xpanel, o porcentaje propio del Starlight X, más estado de carga |
| **VAXEE** | Ratón inalámbrico en el receptor VAXEE 4K (`3057:1002`) o receptor 8K (`3057:2002`, p. ej. NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless por cable USB (`3057:1011`) | Informe de características del fabricante de solo lectura `0E` en `FF05:0001`; batería en pasos del 5% y estado de carga ([notas de protocolo](#sec-vaxee)) |
| **Scyrox** | V12M en su receptor de 2.4 GHz (`395A:0006`) | Lectura de perfil S-Center 2.0 (informe de salida `08`, comando `01`) en `FF00:0002`; solo batería, sin estado de carga |
| **HECATE** | G5M PRO y otros ratones HECATE en el mismo receptor, y cable USB `35BB:D3FA / D3FC / D3FD` | Protocolo Kysona |
| **Redragon** | Ratones inalámbricos basados en Compx: M916 Pro 1K (probado), M913 Impact Elite (tri-modo), G49 (receptor o cable) | Protocolo Kysona (los receptores Areson `25A7` figuran bajo Areson) |
| **Taidu (钛度)** | TSG808 en su receptor Compx de 2.4 GHz `3554:F5D5` (probado) | Protocolo Kysona |
| **Areson (Redragon)** | M915RGB-WL (probado), M913 Impact Elite original y otros ratones en el receptor `25A7:FA07` / `FA08` | Informe de características `GetPower` de 17 bytes; nivel en pasos del 10% e indicador de carga |
| **Ninjutso** | Sora V2 en el receptor 1K (`1915:AE1C`, probado) o cable USB (`1915:AE11`, probado); Ten Air (receptor `093A:EB01` y cable USB `093A:E020`, probados) / Ten (`093A:EB01` / `E020`, sin probar) | Informe de características NinjaForce `0x05` (`0x15` para Sora V2) y `0x06` (`0x13`/`0x12`/`0x11` para Ten / Ten Air) |
| **Sprime** | PM1 en el receptor de 2.4 GHz (`1915:AC1C`, probado; `1915:AD8C`) o cable USB | Mismo informe de características `0x05`, comando de estado `0x15`, del controlador web de Sprime (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 en el receptor RAWM HS Receiver (`1915:2346`, probado); ratones ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* y SADES Dagger en sus receptores RAWM (`1915:232A`–`234B`) o cable USB | Consulta de información del dispositivo de RAWM HUB 2.0 a través del receptor (JSON con % de batería y carga), solo lectura ([notas de protocolo](#sec-rawm)) |
| **AULA** | Teclados inalámbricos F75 / F87 Pro / F99 en el receptor de 2.4 GHz | Trama de informe `0x13`, comando `0x4A`, suma de comprobación por adición (modos Bluetooth y cableado sin probar) |
| **Ratones AULA** | X9 Ultra (probado) en el receptor AULA-8K Dongle `320F:22A0`; ID de receptor compartido con modelos V9 | Informe `04`, comando de batería de solo lectura `1A` entre START `01` / END `02` en `FF1C:0092`; solo 2.4 GHz |
| **Teclados SONiX (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (probado), EPOMAKER EA75 (probado), AULA F108 Pro en el receptor 2.4G `05AC:024F`; AJAZZ AK980 V2 en el receptor `0C45:FEFE`; AJAZZ AK820 Pro en el receptor `0C45:FDFD` o `0C45:FEFE`; EPOMAKER P75 en `342D:E479` (sin probar en hardware) | Informe del fabricante `20 01` en la página de uso `FF60`, suma de comprobación por adición (solo modo 2.4G; sin indicación de carga) |
| **Receptores SONiX adicionales (sin probar en hardware)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | Misma consulta `20 01` solo de batería; requiere VID:PID exacto y colección `FF60:0061` con informes de 33 bytes; solo 2.4G, sin indicación de carga |
| **Teclados 36B0 (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB en el receptor 2.4G `36B0:3002` o cable USB `36B0:3009` (protocolo probado en ambos por el autor del reporte #343); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) en el mismo receptor o cable (sin probar); URX Core75 en el receptor (confirmado en HaloBattery); EVO80 (sin probar) | Firmware PMO Hub: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` en la página de uso `FF60`, desde pmohub.cn. Firmware URX / VIA: VIA custom-get `08 00 07` (canal 0, valor 7), desde URX HUB vía HaloBattery. Sin indicación de carga |
| **DAREU** | EM901X en el receptor de 2.4 GHz `260D:1074` o cable USB `260D:1090` (lectura de batería probada en ambos; transiciones del indicador de carga al acoplar/desacoplar en el receptor probadas) | Informe de características solo de batería `08`, comando `04`; respuesta `09` en una colección del fabricante aparte. Requiere un par entrada/característica inequívoco por ID de producto. Da prioridad a una lectura USB válida cuando ambos están conectados; el receptor puede devolver telemetría en caché incluso con el ratón apagado |
| **DAREU** | Teclado A84 (`260D:0022`, sin probar) | Informe de características SONiX en la interfaz 0, comando `04 F6` (la lectura de batería oficial del controlador del A84); nivel en porcentaje, sin indicador de carga |
| **DAREU** | A980 Pro en el receptor multirratón `260D:1131` y en su cable USB (`260D:1148`) (nivel de batería probado en hardware; indicador de carga confirmado al enchufar) | Protocolo Togran: informe de características de 65 bytes `0A` en la colección de control de consumo; consulta de ranura (clase 0 / `A0`) y luego consulta de batería (clase 7 / `80`), en la ranura 0 por cable. Solo lectura |
| **Sharkoon** | Skiller SGM50W en `260D:1125` (sin probar) | Misma consulta Compx que el DAREU EM901X (informe de características `08`, comando `04`; respuesta `09` en `FF01:0000`); el actualizador de firmware de Sharkoon para este modelo es una herramienta Compx en el VID `260D` |
| **Zenith** | Zenith Pro en el receptor de 2.4 GHz `260D:1114` (lectura de batería probada; carga sin probar) o cable USB `260D:1143` (sin probar) | Mismo comando Compx (`08`, `04`) como informe de salida en `FF02:0002`; respuesta `08 04` en la misma colección con porcentaje, indicador de carga y milivoltios, verificada mediante suma de bytes `0x55` |
| **AJAZZ AK992** | Receptor Telink de 2.4 GHz `320F:50C3` (probado) | Consulta de batería EVision en la colección HID `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, serie DW (U2-DW, S2-DW ...) y U2 en su receptor de 2.4 GHz | Comandos de solo lectura del fabricante documentados por la comunidad |
| **Royal Kludge (RK)** | MG6 Pro en el receptor de 2.4 GHz (`2E3C:00A6` / `00E6`) o cable USB (`2E3C:00A5` / `00E5`) | Trama QiWang de 64 bytes del controlador web de RK, lectura `GET_BATTER_VOL` (porcentaje, voltaje, carga) |
| **ASUS ROG** | Teclados Strix Scope II 96 (RX), Azoth, Falchion; ratones Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact; auriculares Pelta (receptor de 2.4 GHz); auriculares intraurales Cetra Open Wireless (receptor SpeedNova `0B05:1CAC`, I / D / estuche); el receptor Omni Receiver | Consulta de batería HID ROG |
| **Machenike** | L7 Arctic / L7 Mix en el receptor de 2.4 GHz `248A:FF4C` o cable USB `248A:FF4E` (ambos probados) | Informe de características de solo lectura `51`, comando de estado `06`; batería y carga. [Notas de protocolo](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS en su receptor de 2.4 GHz (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (receptor de 2.4 GHz `0DB0:0D3C`, probado; cable USB `0DB0:0D3B`) y CLUTCH GM41 Lightweight Wireless (receptor `0DB0:0D4C` / cable `0DB0:0D4B`, a partir de capturas de un propietario) | Consulta de solo lectura del fabricante `0F 20` en `FF0D:00B0` y `FF00:0001`; batería e indicador de carga en un solo byte (protocolo del módulo Gaming Gear de MSI Center); GM41: informes pasivos `A0 xx 07 …` en `FF10:0006` |
| **MCHOSE** | Ratones L7 / L7 Pro / L7 Ultra (L7 Ultra probado), M7 / M7 Ultra, A7 / A7 Ultra, K7 en el receptor de 2.4 GHz o cable USB; A5 V2 Ultra (receptor de 2.4 GHz `3837:100C`, probado), K7 Ultra (receptor de 2.4 GHz `3837:1001`, probado; se espera que A7 V2 Ultra+ `3837:100B` funcione, issue 227); G3 V2 (receptor de 2.4 GHz `3837:4245` y cable USB `3837:418C`); K7 V2 Ultra+ en el receptor de 2.4 GHz `3837:1014` o en su cable USB `3837:4028` (ambos probados; los demás ID de receptor de la nueva familia `1018`, `1016`, `102C`, `102D` están sin probar) | Informe de características del fabricante con carga útil invertida (protocolo de alexfrih/mchose-linux); los receptores Realtek `3837` responden a la misma consulta con el campo `vid` fijado en `41E4` (A5 V2 Ultra) o `3837` (K7 Ultra); G3 V2: consulta de solo lectura del fabricante en `FF01:0010`; K7 V2 Ultra+: informe de 64 bytes `0x4D`, comando de información del dispositivo `0x0900` en `FF01:0001` (protocolo del controlador web de M HUB) |
| **MCHOSE A5 (primera generación)** | A5 Pro / A5 Pro Max en el receptor de 2.4 GHz 1K o 4K (`2023:F013`, `2023:F015`, `2023:F018`) o el cable USB (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); sin probar aquí | Comando de batería de solo lectura `0x83` (página 0) en un informe de características de 64 bytes en `FFFF`, respuesta marcada `0xA1` (protocolo del controlador web A5 Pro Max de z750sasr y HaloBattery, IDs de Klegus/mchose-macos) |
| **Auriculares MCHOSE** | V9 Pro 2 en el receptor de 2.4 GHz (`3837:6011`, probado) | Trama de batería «MC» de solo lectura de M HUB (informe `0x55`, subcomando `0x0B`) en `FF07:0222`; batería e indicador de carga en un byte (protocolo del controlador web de M HUB) |
| **Teclados AULA / MCHOSE / Redragon** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 y demás teclados de M HUB; Redragon Horus Pro / Pro V2 (K618RGB-PRO) en el receptor de 2.4 GHz (`3554:FA09`, `41E4:2001`); MCHOSE K87 en el receptor `05AC:024F` (disposición BY en la interfaz 1, no la de SONiX) | Trama de informe `0x13`, comando `0x4A` (modelos MCHOSE y Redragon identificados mediante el comando `0x05`, como en M HUB); modos Bluetooth y cableado no cubiertos |
| **Teclados MCHOSE** | G75 V2 en el receptor de 2.4 GHz `3837:3033` (probado); el mismo receptor acompaña al G87 V2 y K99 V3 (mismo protocolo, sin probar); el K87S empareja el mismo ID de receptor con un protocolo distinto y no está cubierto | Consulta de configuración de funciones «GLW» de solo lectura de M HUB en la colección sin ID de 64 bytes `0001:0000`: indicador de petición `0x55`, comando `0x05`, batería en el byte 32 de carga útil (bit 7 = carga), suma de comprobación aditiva |
| **AULA SC580** | Ratón SC580 / SC580X por cable USB (`088D:062E`, probado) o su receptor de 2.4 GHz (`089D:062F`, probado) | Comando de solo lectura `0x30` (información del dispositivo) en la colección del fabricante de 33 bytes `FF02:0000`, suma de comprobación por adición; mientras carga el ratón informa un valor fijo de 100, por lo que se muestra el último nivel conocido; modo Bluetooth no cubierto |
| **AULA HERO 68 Air** | HERO 68 Air en el receptor 8K Wireless Receiver (`372E:106C`) | Tramas de 20 bytes con confirmación en la página de uso `FF60` (cuatro tramas de datos y una cola por mensaje), comando de batería de solo lectura `0x87`, indicador de carga `0x10` tras el nivel; modos Bluetooth y cableado no cubiertos |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra y S9 Max / Pro / Ultra / Ultra+ en el receptor «Gaming 2.4G» (`372E:103D`); S9 Ultra en su cable USB (`372E:1027`) | Informe de características de solo lectura `03` en `FF00:0001`: comprobación de enlace `47`, datos básicos del dispositivo `4F 81` (porcentaje de batería y bit de carga), del controlador web de EWEADN |
| **Rapoo VT** | VT3 Max Gen 2 (probado); VT9 Gen 2 (probado); otros ratones Nordic 54L VT que expongan la misma interfaz de estado; VT3 Pro antiguo (experimental); VT1 Pro Max (a partir de capturas USB del propietario) | Informe pasivo HID de estado `07` en `FF00:0002` (16 o 19 bytes; 13 bytes en algunos receptores VT3 Max Gen 2); protocolo antiguo `BB` restringido a VT3 Pro `1215/4415` y VT1 Pro Max `1233/4433`. Receptor y cable USB, con estado de carga |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (modelos Xenta 30/50; antiguo 3D), Delux M800 Pro, familia Ajazz AJ179; AJ159 y otros ratones de la serie AJ en el receptor 3151; AJ139 V2 MC (receptor `A8A5:2255`, cable `A8A4:2255`) | Informes del fabricante (M900 Pro: emisiones pasivas de estado o consulta de características, eventos Xenta 40/41; serie AJ: sondeo de estado `0xF7` y luego informe de características `0x05`) |
| **Incott** | G23 V2 / G24 (receptor `093A:522C`, cable `093A:622C`) | Informe de características de estado de solo lectura `09` |
| **Attack Shark y otras marcas chinas** | Receptores Rongyuan (81 modelos: Attack Shark R3 y AJAZZ AJ179 Pro en `3151:402D`, K86, X82 PRO HE, teclados Ajazz, algunos MSI y otros; el K86 por Bluetooth aparece como teclado); receptores Xenta (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; el X6 también en `1D57:FA61`, sin probar); teclados Semico 1A2C (Attack Shark X98 en el receptor `1A2C:8FFF`, probado, y cable `1A2C:A034`; AJAZZ AK820 Max Plus en `1A2C:8FFF` / `1A2C:A036`) | Informe de estado Rongyuan; emisiones pasivas Xenta; consulta de estado Semico de solo lectura `0x0E` (`AA 55 CC 33` en `FF02:0002`; se omite el indicador de carga porque el X98 informa `state=1` tanto con batería como cargando) |
| **Wraith** | W1 / W1 Freestyle (receptor `093A:522C`, cable `093A:622C`; mismos ID que Incott, diferenciados por el código de modelo) | Lecturas por botón de solo lectura `86` (informe de características `09`) en todos los botones y luego el informe de entrada de estado enviado `09` |
| **Fantech** | Helios Go XD5 (cable `25A7:FA7B`, receptor `25A7:FA7C`); Raigor III (probado), Raigor II WG10 y otros dispositivos genéricos «2.4G Mouse» en el receptor reutilizado `1EA7:0066` / `1EA7:0064` | Helios Go XD5: informe de características del fabricante `08`, comando `04`, suma de comprobación hasta `0x55`. Raigor / 2.4G Mouse: consulta de solo lectura `B5` en la página de estado `FFB5:0001`, bloque `94` = último porcentaje informado (puede quedar desactualizado en reposo, apagado o cargando; sin estado de carga) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, adaptador inalámbrico); auriculares INZONE H9 II y H5; auriculares intraurales INZONE Buds (receptor USB-C) | Informe de entrada; protocolo del fabricante INZONE |
| **Fractal Design** | Auriculares Scape en su receptor de 2.4 GHz o cable USB-C | Consulta `GET_DEVICE_STATE` del fabricante de la aplicación web Adjust Pro de Fractal (página de uso `FF00`) |
| **Jabra** | Todos los auriculares Jabra que hablan el protocolo GN (Evolve2 / Evolve3 y otros), con su propio cable USB o detrás de un receptor Jabra Link; sin lista cerrada de IDs de producto, quedan fuera las bases DECT (Engage, PRO 9xx, GO 6400, Link 400); el nombre se lee desde los auriculares | Consulta de estado GNP (clase 12 / op 02) en la página de uso `FF00`, uso `05` o `01`, en la dirección GNP `08` (USB) o `04` (receptor) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), receptor de 2.4 GHz o USB; Apex 5 (`37D7:2501`), receptor de 2.4 GHz o USB | Consulta HID de información del fabricante en `FFA0:0001`; nivel de batería 0–5 asignado a 0–100% en pasos del 20%, con estado de carga; no requiere el servicio Space Station |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite en el receptor de 2.4 GHz; Nova 2 Lite por USB; G7 Pro (probado: edición Zenless Zone Zero, receptor `3537:105E`) y otros mandos GameSir en modo Xbox (GIP); Cyclone 2 (modo XInput, receptor o cable); Cyclone Pro en su receptor de 2.4 GHz (`3537:1015`, empareja el mando con Windows por Bluetooth una vez) | Consulta de información del dispositivo del fabricante (página de uso `FF7A`); informe de batería `Windows.Gaming.Input` (% real) en modo Xbox; Cyclone 2: petición de batería del fabricante (página de uso `FFF0`); Cyclone Pro: petición de información base de la app de GameSir por Bluetooth LE (servicio `0x8650`), leída cada 2 min |
| **BEITONG** | KP20 / BTP-KP20 en su receptor de 2.4 GHz (`20BC:5128`, modo XInput, probado) y KP40D / BTP-KP40D en su receptor (`20BC:515C`, modo XInput); no requiere BEITONG iControl | Consulta del fabricante «get base info» en la página de uso `00FF` (informe `02`, carga útil con nibbles permutados), con estado de carga |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` probado en receptor de 2.4 GHz, D-input `2DC8:6012` — mantén pulsado B al encenderlo, firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Consulta HID de estado del fabricante (`FF7A`/`FFA0`) e informe de entrada de mando SDL `01`/`04`, con estado de carga |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Trama de estado que los auriculares envían a través del servicio RFCOMM (SPP) de Samsung, solo lectura. La bandeja muestra el auricular con menos carga; la descripción emergente lista izquierdo, derecho y estuche. La aplicación Galaxy Buds debe estar cerrada |
| **Nothing / CMF** | Nothing Ear (3a) (probado), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Consulta de batería de solo lectura `0xC007` en el servicio RFCOMM NT Link de Nothing (`aeac4a03-dff5-498f-843a-34487cf133eb`). La bandeja muestra el auricular con menos carga; la descripción emergente lista izquierdo, derecho y estuche |
| **Akko** | Akko Air 01 (`3151:5006`, receptor de 2.4 GHz, probado) y Akko V9 Dash Pro (`38EE:000C`, receptor de 2.4 GHz, probado) | Air 01: informe de estado Rongyuan `0xF7`; V9 Dash Pro: consulta de estado de solo lectura de 64 bytes `0x1A` en `FF1C:0092` con estado de carga |
| **MOONDROP** | Auriculares GM01 Pro en su receptor de 2.4 GHz (`35D8:0133`); en su cable USB aparece como cargando con el último nivel conocido | Comando de lectura del fabricante WalkPlay en el informe `4B` (solo lectura) |
| **VGN** | Auriculares OMNISOUND (ZHOUTING) en su receptor de 2.4 GHz (`372E:10BB`, probado) | Consulta V HUB «ZHOU»: informe de salida `55` con carga útil `65 01` en la colección de control `000C:0001` (informes de entrada de 32 bytes y de salida de 64 bytes); el porcentaje vuelve en la respuesta (solo lectura) |
| **JBL** | Quantum 650 Wireless (probado, receptor de 2.4 GHz); Quantum 520, 650X, 850, 950, 950X Wireless (receptor o cable USB, mismo protocolo, sin probar) | Consulta de información del dispositivo JBL «HIDV3» para la función de batería (página de uso `FF12`), con estado de carga |
| **JBL** | Quantum 350 Wireless (probado en Windows con el receptor de 2.4 GHz `0ECB:206B`); Quantum 610 Wireless (receptor de 2.4 GHz `0ECB:205C`, sin probar en Windows); Quantum 360 Wireless (receptor de 2.4 GHz `0ECB:2115`, sin probar) | Informes de características HIDV1 para conexión inalámbrica y porcentaje de batería |
| **Xbox** | Mandos en el adaptador inalámbrico Xbox Wireless, USB o Bluetooth; auriculares conectados a un mando | Informe de batería `Windows.Gaming.Input` (% real), respaldo XInput |
| **Compatibles con Switch Pro** | Mandos que se presentan como `057E:2009` (probado: GameSir Tarantula Pro a través del receptor de 2.4 GHz en modo Switch) | Cinco niveles de batería desde el informe HID `0x30` después de que Steam Input u otro host active los informes completos |
| **Apple AirPods / Beats** | AirPods Max (probado, `200A` Lightning y `201F` USB-C), AirPods Pro 3 (probado, `2027`), AirPods Pro 1 / 2, AirPods 1–5 y auriculares/intraurales Beats | Difusiones BLE de «emparejamiento por proximidad» (`0x07`) (batería única para AirPods Max y auriculares de diadema Beats; izquierdo, derecho y estuche para intraurales, en pasos del 10% con estado de carga), emparejados con el modelo vinculado |
| **Teléfonos (Enlace Móvil)** | Cualquier teléfono Android vinculado con Enlace Móvil de Microsoft, por Wi-Fi o Bluetooth (probado: Nothing Phone (4a) Pro) | Batería y estado de carga obtenidos de la tarjeta del menú Inicio de Windows 11 de Enlace Móvil (`StartMenuCompanion.json`); no requiere Bluetooth |
| **Darmoshark** | M3 (`248A:FF30`) y M3S (`248A:FF31`) en sus receptores de 2.4 GHz en Windows | Informe de características HID para identidad del ratón y batería |
| **Darmoshark** | M3S Pro en el receptor Nordic 1K (`1915:0723`) | Consulta HID de estado del fabricante en la colección `FF0A` |
| **Alienware** | Auriculares AW920H en su receptor de 2.4 GHz (`413C:A515`, probado); por Bluetooth está cubierto por la fila de Bluetooth | Consulta del fabricante `06 C0 0A` en `FF13:0001`, informe de respuesta `07` con suma de comprobación XOR; campos de nivel, carga y nivel crítico decodificados igual que en el complemento AW920H de Alienware Command Center |
| **Niceboy** | MW400 en su receptor de 2.4 GHz (`248A:FA02`, probado) | Consulta `24 FA 48` de solo lectura en el informe `05`; voltaje de batería asignado a pasos del 10% según la tabla de la aplicación del fabricante, indicador de carga |
| **Bluetooth** | Cualquier dispositivo que muestre batería en *Configuración → Bluetooth y dispositivos* (intraurales, auriculares, ratones y teclados BLE). Los auriculares Google Fast Pair (Jabra Elite 8 Active probado; Pixel Buds y muchos modelos de Sony / JBL / Bose) también obtienen niveles izquierdo, derecho y del estuche | Propiedad de dispositivo de Windows; difusiones de batería Fast Pair (datos de servicio BLE `FE2C`), emparejadas con el dispositivo vinculado mediante dirección Bluetooth |
| **HID genérico** | Dispositivos que informan el uso HID estándar *Battery Strength* | Página de uso HID `0x06` / `0x85` |
| **HeadsetControl** | [Todos los auriculares compatibles](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, Logitech recientes y más) | Incluido; ejecuta `headsetcontrol -o json` |
| **MAONO PD200W** | Receptor de 2.4 GHz (`352F:040E`) | Porcentaje de batería; probado en hardware |


**Probado en hardware real:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (receptor PlayStation `0951:1713`; carga sin probar), HyperX Cloud Core Wireless DTS (receptor `0951:173F`; nivel de carga completa sin probar), HyperX Pulsefire Haste 2 Core Wireless (receptor `03F0:0AB5`; los receptores del Haste 2 Wireless están sin probar), Cooler Master MM712 (receptor), Rapoo VT3 Max Gen 2 (receptor `24AE:1417` y cable USB `24AE:4617`; otros modelos de Rapoo están sin probar, consulta las [notas de protocolo de Rapoo](#sec-rapoo)), Redragon M916 Pro 1K (receptor `3554:F55D`), Taidu TSG808 (receptor `3554:F5D5`), Redragon M915RGB-WL (receptor `25A7:FA07`; otros modelos Areson están sin probar, consulta las [notas de protocolo de Areson](#sec-areson)), SteelSeries Rival 650 Wireless (receptor `1038:1726` y cable USB `1038:172B`), SteelSeries Arctis Nova Pro Wireless (estación base `1038:225D`; lectura de batería probada, carga y transiciones de encendido sin probar), HECATE G5M PRO (receptor `35BB:D3FB`), WLMouse YING Magnesium (receptor 8K `36A7:A874`), ATK N9 Ultra (receptor `373B:1204`), Corsair Scimitar Elite SE Wireless (receptor Slipstream `1B1C:2B00`), Corsair Dark Core RGB Pro SE (receptor Slipstream `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (receptor de 2.4 GHz `1B1C:2B2A`; lectura de batería verificada), DAREU EM901X (receptor `260D:1074`; carga y reposo/reactivación sin probar), Jabra Evolve3 75 en un Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (receptor `3837:4245` y cable USB `3837:418C`), MCHOSE K7 Ultra (receptor `3837:1001`), MCHOSE K7 V2 Ultra+ (receptor `3837:1014` y cable USB `3837:4028`; carga mostrada mientras está enchufado), MSI VERSA 300 ELITE WIRELESS (receptor `0DB0:9E22`; gestión de carga y reposo sin probar), MSI Clutch GM31 Lightweight Wireless (receptor `0DB0:0D3C`; el GM41 usa el mismo controlador a partir de capturas de un propietario), AJAZZ AK820 MAX (receptor `05AC:024F`), AULA HERO 68 Air (receptor 8K Wireless Receiver `372E:106C`), AULA SC580 (cable USB `088D:062E` y receptor `089D:062F`, incluyendo carga y reposo), AirPods Pro 3 (Bluetooth, modelo `2027`), AirPods Max (Bluetooth, modelo `200A`), Sprime PM1 (receptor `1915:AC1C`), Ninjutso Ten Air (receptor `093A:EB01` y cable USB `093A:E020`), MOONDROP GM01 Pro (receptor `35D8:0133`), Delux M800 Pro (receptor `248A:5B2F`), Razer Barracuda X (2022) (receptor `1532:0550`; nivel de batería leído, transiciones de carga sin probar), Razer BlackShark V3 X (receptor HyperSpeed `1532:057D`), Fantech Helios Go XD5 (receptor `25A7:FA7C`), Fantech Raigor III (receptor `1EA7:0066`; el firmware no informa la carga), Finalmouse UltralightX (receptor `361D:0100`), Finalmouse Starlight X (en su receptor) y Chimera V2 (receptor `3554:F512`; nivel de batería y carga leídos).
También probado en hardware: Machenike L7 Arctic / L7 Mix (receptor `248A:FF4C` y cable `248A:FF4E`), incluyendo carga y supresión de duplicados entre cable y receptor. Bluetooth y los límites de batería baja/carga completa no se probaron en hardware.
También probado en hardware: MCHOSE V9 Pro 2 (receptor `3837:6011`); nivel de batería leído, carga y reposo sin probar.
También probado en hardware: EPOMAKER EA75 en su receptor de 2.4 GHz `05AC:024F`, usando el controlador SONiX existente de [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). Se verificaron el porcentaje de batería, la reconexión del receptor y la recuperación al encender. Este controlador no admite indicación de carga ni informe de batería por cable; el informe de batería por Bluetooth no se probó. El porcentaje informado puede saltar al 100% cuando se conecta alimentación USB, lo cual no es un indicador de carga fiable.
También probado en hardware: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (receptor `1038:1878` y cable USB `1038:187A`), incluyendo carga, apagado (el último nivel permanece visible, atenuado) y con SteelSeries GG ejecutándose; GG solo muestra una barra de tres niveles, con la que el nivel coincidía.
También probado en hardware: RAWM Leviathan V4 (receptor RAWM HS Receiver `1915:2346`; nivel de batería leído, carga sin probar).
**Implementado a partir de documentación de protocolos y otros proyectos, aún sin probar:** todo lo demás, incluido el Fantech Raigor II WG10 (mismo receptor `1EA7:0066` y misma colección que el Raigor III probado, así que debería funcionar). Si tienes uno de estos dispositivos, por favor indícanos si funciona [abriendo un issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues).

## Instalación

[![Última versión](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Descarga **`BatteryHub-Setup-<version>.exe`** desde la [última versión](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. Ejecútalo, elige cualquiera de los 19 idiomas de instalación compatibles y sigue el asistente. **No necesita permisos de administrador** ni **ningún otro software instalado**: ni entornos de ejecución, ni controladores, ni aplicaciones del fabricante. HeadsetControl viene incluido y la carpeta editable `lang\` se instala junto a `BatteryHub.exe`.

El instalador añade una entrada en el menú Inicio y un desinstalador (*Configuración → Aplicaciones*), y puede iniciar la aplicación al iniciar sesión. ¿Prefieres no usar instalador? Descarga `BatteryHub-<version>-portable.zip`, descomprímelo en cualquier lugar (conserva la carpeta `lang\` junto a `BatteryHub.exe` para las traducciones de la interfaz) y ejecuta `BatteryHub.exe`.

**Notas:**
- **Advertencia de SmartScreen:** el ejecutable no está firmado digitalmente, por lo que Windows puede mostrar «Windows protegió su PC». Haz clic en *Más información → Ejecutar de todas formas*, o compílalo tú mismo.
- **Modo de iconos en la bandeja en Windows 11:** los iconos nuevos aparecen en el área oculta `^`. Arrástralos a la barra de tareas o actívalos en *Configuración → Personalización → Barra de tareas → Otros iconos de la bandeja del sistema*.
- **Mantener la aplicación apartada de un dispositivo:** si un dispositivo funciona de forma anómala mientras la aplicación está ejecutándose, añádelo al valor de cadena del Registro `IgnoreDevices` bajo `HKCU\Software\WirelessBattery` como pares `VID:PID` (en hexadecimal, separados por comas, p. ej. `28BD:0947, 1234:ABCD`; `--dump` muestra los IDs). La aplicación no volverá a abrirlo jamás. Las tabletas gráficas se omiten automáticamente.

## Actualizaciones en Windows

Las compilaciones estables oficiales para Windows comprueban en segundo plano la última versión estable publicada del proyecto: 30 segundos después de iniciarse y luego cada 24 horas mientras la aplicación sigue ejecutándose. Abre el menú para ver **Actualización disponible: vX.Y.Z...**, o selecciona **Buscar actualizaciones...** manualmente. La información de actualización aparece únicamente en este menú: los iconos de batería, los porcentajes y las descripciones emergentes permanecen iguales, y las comprobaciones automáticas nunca muestran notificaciones ni cuadros de diálogo. Desactiva **Buscar actualizaciones automáticamente** en el menú para deshabilitar las comprobaciones en segundo plano.

En una copia instalada, haz clic en la entrada de actualización y luego en **Descargar e instalar**. No se instala nada sin ese clic. La aplicación descarga el archivo `SHA256SUMS.txt` de la versión y su firma, verifica la firma con la clave pública del mantenedor integrada en la aplicación, descarga el instalador de Windows y lo ejecuta únicamente si su SHA-256 coincide con el de la lista firmada (y el que indica GitHub para ese archivo). A continuación actualiza la instalación existente. La configuración y la preferencia de inicio automático se conservan, y la aplicación vuelve a abrirse al finalizar la instalación. Una instalación para todos los usuarios puede solicitar permisos de administrador. **Notas de la versión** abre la página oficial del lanzamiento; **Más tarde** mantiene tu versión actual. Las copias portables dirigen a la página del lanzamiento para descargar el ZIP manualmente.

Las comprobaciones consultan la API pública de GitHub sin necesidad de cuenta ni token. No se envía información de dispositivos ni de batería. Los fallos sin conexión y los límites de tasa de GitHub dejan la supervisión de batería funcionando con normalidad; una versión encontrada previamente permanece en el menú hasta que una comprobación correcta la sustituya o se instale. Al cancelar una descarga, se espera a que la operación de red en curso alcance su tiempo límite finito. El instalador nunca reinicia Windows automáticamente.

**Por qué las actualizaciones son seguras de instalar:** la clave de firma nunca se sube a GitHub. El mantenedor firma la lista de sumas de comprobación de cada lanzamiento en su propio equipo (consulta [docs/releasing.md](#sec-releasing)), de modo que ni siquiera alguien que tomara el control de la cuenta de GitHub o de su flujo de compilación podría publicar una actualización que la aplicación aceptara instalar. Una versión sin firma válida se muestra en el menú, pero solo puede descargarse manualmente. La firma no sustituye los avisos propios de SmartScreen o UAC de Windows.

Instala manualmente una vez la primera versión que incluya esta función. Las compilaciones de desarrollo o prueba desactivan las comprobaciones oficiales de actualización para evitar sobrescribir accidentalmente los cambios locales. Las actualizaciones en Linux y la sustitución automática de copias portables quedan aplazadas.

## Línea de comandos

```
BatteryHub.exe --list     # imprime cada dispositivo y su nivel de batería, luego sale
BatteryHub.exe --json     # imprime un array JSON de dispositivos y niveles de batería, luego sale
BatteryHub.exe --dump     # lista cada colección HID, dispositivos HID que no pudieron abrirse, todos los
                               # dispositivos USB (también los que no tienen interfaz HID) y Bluetooth; también se guarda en %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # abre la ventana «Solicitar soporte para un dispositivo»
BatteryHub.exe --demo     # muestra dispositivos de ejemplo de cada marca en lugar de los reales (capturas, comprobación de colores)
BatteryHub.exe --quit     # cierra la instancia en ejecución
```

La compilación de Linux usa las mismas opciones con `wireless-battery` en lugar de `BatteryHub.exe`, y también admite `--help`. `--json` imprime un array estable que scripts y widgets de barra pueden analizar:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` indica durante cuánto tiempo sigue mostrando la aplicación el último nivel conocido mientras el dispositivo está en reposo. Añadir nuevos campos es retrocompatible.

**¿No aparece tu dispositivo?** Haz clic derecho en el widget o icono de la bandeja y elige **Solicitar soporte para un dispositivo...**. Selecciona el dispositivo, revisa lo que se enviará (se muestra palabra por palabra: nombre del dispositivo, tipo, IDs USB/HID y disposición de interfaces, además de tu nombre y notas opcionales) y haz clic en **Enviar**. Se añade a la lista pública en [krisgfx.com/tools](https://krisgfx.com/tools/#requested) y abre o actualiza un issue en GitHub. **Copiar informe completo** copia el `--dump` completo al portapapeles para el issue. Los datos del informe solo se envían cuando haces clic en Enviar. Las compilaciones oficiales de Windows también pueden contactar con GitHub para buscar actualizaciones, como se describe en [Actualizaciones en Windows](#actualizaciones-en-windows); las comprobaciones de actualización no envían información sobre dispositivos ni baterías.

## Compilación

Necesitas [MinGW-w64](https://www.mingw-w64.org/), por ejemplo desde [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # compilación de desarrollo, versión 0.0.0
build.bat                                 # cmd estándar con g++ y windres en el PATH
make VERSION=1.2.3 CHANNEL=test            # compilación con versión, actualizaciones oficiales desactivadas
build.bat 1.2.3 test                       # compilación equivalente en cmd con versión
make test VERSION=1.2.3 CHANNEL=test       # pruebas de regresión de dispositivos y actualizador
```

Para generar el instalador y el ZIP portable, instala [Inno Setup](https://jrsoftware.org/isinfo.php), compila primero con la versión deseada (por ejemplo `make VERSION=1.2.3 CHANNEL=test`) y luego ejecuta `powershell -File installer\build-installer.ps1 -Version 1.2.3`. El empaquetado rechaza una versión que difiera de la del ejecutable. Descarga la versión fijada de HeadsetControl y verifica su suma de comprobación. GitHub Actions hace todo esto automáticamente: subir una etiqueta como `v1.0.0` publica un lanzamiento con el instalador, el ZIP portable y el código fuente de HeadsetControl (como exige su licencia GPL).

Las compilaciones de Windows también necesitan PowerShell para generar el archivo de versión compartido entre el ejecutable y los recursos. Las etiquetas de versión del repositorio oficial compilan con `CHANNEL=stable`; las compilaciones locales usan `dev` de forma predeterminada. Los forks y las pull requests no activan las actualizaciones oficiales automáticamente.

`BatteryHub.exe` también funciona por sí solo. Sin `headsetcontrol.exe` al lado (o en `PATH`), únicamente pierdes el soporte de los auriculares adicionales.

## Linux (experimental)

Existe una compilación para Linux junto a la aplicación de Windows. Utiliza los mismos controladores de fabricantes con un backend HID basado en hidraw y un icono de bandeja GTK4 StatusNotifierItem; la ruta de código de Windows no cambia. Todos los archivos exclusivos de Linux están en `linux/` y `src/linux/`, y `build-linux.sh` la compila (Windows sigue usando `build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Compilador y make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

No se necesita ninguna biblioteca HID adicional (se usa hidraw directamente).

```sh
./build-linux.sh
./build-linux.sh test         # prueba unitaria del analizador de descriptores de informe HID
./wireless-battery --list     # imprime los niveles detectados y sale
./wireless-battery --dump     # lista las colecciones HID
./wireless-battery --quit     # cierra la instancia en ejecución en la bandeja
```

El acceso HID necesita una regla udev; de lo contrario, la aplicación se inicia pero no encuentra dispositivos:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# cierra sesión y vuelve a iniciarla
```

El icono de la bandeja funciona de forma nativa en KDE Plasma; GNOME necesita un host AppIndicator como `gnome-shell-extension-appindicator`. El cambio de idioma funciona desde el submenú *Idioma* (siguiendo `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` por defecto y traduciendo también `--help`). Al ejecutar `make -f linux/Makefile.linux install` se instala el binario, `lang/*.json` en `$(PREFIX)/share/wireless-battery/lang/`, así como el lanzador de escritorio (`linux/wireless-battery.desktop`) y `linux/wireless-battery.svg` en `$(PREFIX)` (por defecto `~/.local`); las anulaciones de idioma del usuario van en `~/.config/wireless-battery/lang/`.

La fase 1 cubre Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious, Finalmouse y los protocolos compartidos Kysona/Pulsar/ATK/G-Wolves. Los respaldos Bluetooth/UPower, HeadsetControl y los demás fabricantes están previstos en fases posteriores.

## Limitaciones

- **Barras de tareas saturadas:** con una barra de tareas centrada de Windows 11 muy llena, los botones de aplicaciones pueden alcanzar al widget. En Windows 10 el área de botones de tareas se estrecha automáticamente.
- **Teléfonos:** se lee de un archivo que Enlace Móvil escribe para la tarjeta complementaria del menú Inicio, lo cual no es una API documentada y puede cambiar con actualizaciones de Enlace Móvil. El teléfono se muestra mientras Enlace Móvil lo reporta como conectado; una tarjeta con más de 3 horas de antigüedad se muestra atenuada. La tarjeta también indica cuando el teléfono se está cargando, lo que se muestra con el rayo de carga.
- **Dispositivos en reposo:** un dispositivo en reposo puede no responder. Su último valor permanece visible, atenuado. Los receptores Logitech desconectan del enlace a los dispositivos en reposo, por lo que su último valor se conserva durante 30 minutos.
- **Auriculares HECATE G2 Wireless 7.1** (receptor de 2.4 GHz `35BB:A009` / `A209`): aún no hay ninguna consulta de batería documentada para su receptor, por lo que no se leen. Una captura USB mientras el software HECATE muestra la batería de los auriculares (consulta CONTRIBUTING.md) es la forma de añadirlos.
- **Teclados Keychron:** con el firmware de fábrica solo informan su batería por Bluetooth (mostrada mediante el soporte Bluetooth). Por el receptor de 2.4 GHz o por cable necesitan un firmware con el parche de batería ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); actualizar el teclado desde Keychron Launcher lo elimina. Los ratones Keychron sí son compatibles.
- **Auriculares Baseus AeQur GH02:** el receptor de 2.4 GHz (`10D6:4802`, chip Actions) solo transporta audio, teclas multimedia y el canal de actualización de firmware del chip, no la batería. Conecta los auriculares por Bluetooth para ver su nivel (mostrado mediante el soporte Bluetooth cuando Windows lo informa).
- **Teclado Weikav Lucky65 v1:** el firmware no informa su batería a través del receptor de 2.4 GHz (`0603:0351`, chip Novatek). El teclado no tiene ningún atajo para consultar la batería y el configurador oficial solo se conecta por cable USB, no a través del receptor, así que no hay lectura de batería que mostrar.
- **Rapoo:** los ratones VT compatibles envían su estado de forma pasiva, por lo que una actualización puede esperar hasta 4 segundos por interfaz coincidente. Los ratones en reposo pueden permanecer atenuados con su última lectura hasta 30 minutos. El soporte cubre el informe Nordic 54L `07` y el antiguo `BB` (VT3 Pro, VT1 Pro Max); el informe `08` CH584, los ratones de oficina de la serie MT/M y otros protocolos de firmware no están cubiertos por este controlador.
- **GameSir Cyclone Pro:** el receptor no transporta ningún nivel de batería, así que se lee desde el mando por Bluetooth LE. Empareja el mando con Windows una vez (Configuración > Bluetooth y dispositivos > Agregar dispositivo > Bluetooth > `GameSir-Cyclone Pro`) y sigue jugando a través del receptor. El PC necesita Bluetooth. El nivel se actualiza cada 2 minutos y no hay porcentaje mientras carga. Sin emparejamiento, el receptor aparece como un mando Xbox al «100% / Llena». Detalles en [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM:** se consulta al ratón a través de su receptor, por lo que un ratón en reposo no responde; permanece atenuado con su última lectura hasta 30 minutos y añade alrededor de un segundo a cada actualización mientras duerme. Solo se ha probado el Leviathan V4 en el receptor RAWM HS Receiver (`1915:2346`); los demás modelos proceden de la tabla de dispositivos de RAWM HUB. El Leviathan V4 GT y el NYX60 (VID `373E`, RAWM HUB 3.0) y los teclados RAWM HS usan otros protocolos y no están cubiertos.
- **Flydigi:** este controlador está orientado al Vader 5 Pro y Apex 5; Bluetooth y otros modelos Flydigi (por ejemplo Apex 6) no están cubiertos. Los porcentajes representan niveles aproximados de batería. El Apex 5 se probó en hardware real mediante el receptor de 2.4 GHz y cable USB; el Vader 5 Pro sigue los controladores de SDL y trazas de hardware de Windows.
- **Todavía no compatibles:** ratones inalámbricos MSI distintos del VERSA 300 ELITE y el CLUTCH GM31 / GM41, teclados inalámbricos MSI, auriculares Razer Kraken y los modelos Barracuda distintos del Barracuda X (2022) en `1532:0550`, ratones HyperX Pulsefire distintos del Haste 2 Wireless / Haste 2 Core Wireless y los auriculares Xbox Wireless Headset en el adaptador de Xbox: sus protocolos de batería no están documentados. Los Xbox Wireless Headset funcionan por Bluetooth. Una captura USB de un propietario (consulta CONTRIBUTING.md) es la forma de añadirlos.
- **Otros dispositivos:** algunos dispositivos de 2.4 GHz utilizan protocolos sin documentar y aún no son compatibles. Consulta [CONTRIBUTING.md](#sec-contributing) para saber cómo ayudar a añadir uno.

## Cómo funciona

Cada controlador de fabricante en [`src/drivers/`](../../src/drivers) reconoce sus dispositivos por ID de proveedor y producto USB, y únicamente envía consultas de batería de solo lectura. Nunca se escribe en dispositivos desconocidos. Los respaldos genéricos (uso HID de batería, Bluetooth, XInput, HeadsetControl) solo examinan dispositivos que ningún controlador de fabricante ha reclamado.

El widget de la barra de tareas es una ventana hija con capas de `Shell_TrayWnd`, situada a la izquierda de `TrayNotifyWnd`. Si el Explorador de Windows se reinicia, se vuelve a crear.

## Traducciones

Cada idioma de la interfaz es un archivo de texto UTF-8 estático y sencillo en [`lang/`](../../lang): inglés a la izquierda y la traducción a la derecha. Los archivos de idioma se cargan desde el disco en tiempo de ejecución en lugar de compilarse dentro del ejecutable, por lo que puedes editarlos directamente sin recompilar.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **Interfaz de la app (Windows y Linux):**
  - Edita o añade archivos `.json` directamente dentro de la carpeta `lang/` junto a `BatteryHub.exe` (o `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/`, o `./lang/` en Linux).
  - O elige *Idioma → Añadir tu propio idioma...* en el menú para preparar tu carpeta de anulaciones de usuario (`%APPDATA%\WirelessBattery\lang` en Windows, `~/.config/wireless-battery/lang` en Linux) con `_template.json`. Copia `_template.json`, por ejemplo a `it.json`, rellena `@code`, `@name` y las traducciones, y aparecerá en el menú (sin necesidad de reiniciar). Los archivos en la carpeta del usuario anulan las frases integradas que tengan el mismo `@code`.
  - Mantén intactos los `{placeholders}` y añade `"@rtl": true` para escrituras de derecha a izquierda. Las frases que se dejen vacías permanecen en inglés, así que una traducción parcial también es válida.
  - La salida de `--list` y `--dump` se mantiene en inglés a propósito: se pega en los issues de GitHub.
- **Instalador de Windows:** las traducciones de Inno Setup viven en [`installer/lang/`](../../installer/lang) (guardadas como UTF-8 con BOM) y se registran bajo `[Languages]` en `installer/BatteryHub.iss`.
- **Documentación:** cada documento visible del proyecto se traduce como un único archivo Markdown independiente por idioma en [`docs/i18n/`](README.md) (consulta [`docs/i18n/_template.md`](_template.md) para añadir un idioma nuevo sin necesidad de scripts de compilación).
- **Compártelo con todo el mundo:** envía una pull request añadiendo tus archivos en `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` y `docs/i18n/`. Consulta [`docs/i18n/README.md`](README.md) para ver la lista paso a paso.

## Créditos

Icono de la aplicación por [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

Los protocolos provienen de la investigación de estos proyectos:

- [Especificación Google Fast Pair](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): difusiones de batería izquierdo / derecho / estuche de auriculares Fast Pair
- [Controladores Astro de HeadsetControl](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) y [AstroBar](https://github.com/nichtlegacy/AstroBar): protocolos de batería de Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): lectura de estado `0x72` del A50 Gen 3
- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): comandos de batería y carga de VAXEE ([documentación del protocolo](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))
- [HeadsetControl](https://github.com/Sapd/HeadsetControl): auriculares SteelSeries, Corsair, HyperX, Logitech y Sony INZONE
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) e [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) y la documentación Logitech HID++ 2.0: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) y [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (receptor `0ADF`)
- [rivalcfg](https://github.com/flozz/rivalcfg): ratones SteelSeries (Rival Pro de su pull request #294)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) y [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Configurador web de Hitscan ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- `hid-kysona` de Linux (Lode Willems): Kysona, Pulsar y ATK
- Configurador web de ATK ([hub.atk.pro](https://hub.atk.pro)): ratones ATK y auriculares N9 Pro / N9 Ultra
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 y [mouse-battery](https://github.com/qwr79/mouse-battery): receptor ATK / VXE NK NANO
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X y Endgame Gear XM2we, adaptados desde sus proveedores (cada controlador indica su fuente)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` y [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (solo hallazgos): familia de dispositivos Turtle Beach Swarm II
- Controlador web de G-Wolves ([mouse.xyz](https://mouse.xyz)): modelos G-Wolves y sus protocolos
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): teclados CHERRY en el receptor de 2.4 GHz (formato de trama y consulta de batería)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): ratones Keychron
- [NinjaForce](https://www.ninjaforce.co/) y [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): consultas de características de Ninjutso Ten / Ten Air
- [nape_pro](https://github.com/nvalis/nape_pro) y [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro en el receptor Link-KM
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): ratones LAMZU
- [vole](https://github.com/johanneszab/vole) y [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): ratones Endgame Gear 4K
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) y [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) y [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (desde xpanel de Finalmouse)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) y [g49-web-control](https://github.com/pingpingjinping/g49-web-control): IDs de Redragon
- [m913-ctl](https://github.com/Qehbr/m913-ctl) y [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): formato de trama Areson `25A7` y comando `GetPower`
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) y [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW y DW
- Controlador web de RK ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) y [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (docs): MCHOSE A5 Pro / A5 Pro Max (primera generación, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): informes del receptor CompX para Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) y [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) y [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- El controlador web de Wraith ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 y [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 y [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) y [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) en el receptor `1532:0550`; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): trama del receptor `1532:0552`
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): receptores Rongyuan y Xenta (Attack Shark y otros)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): teclados SONiX en su receptor 2.4G (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) y [ak820-studio](https://github.com/usharik/ak820-studio): receptor AJAZZ AK820 Pro `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) y [Kraber](https://github.com/AkashPanja/Kraber): protocolo de estado Semico `1A2C` (`AA 55 CC 33` / `0x0E`) para Attack Shark X98 y AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) y [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 y MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) y [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): petición de batería «base info» de GameSir Cyclone Pro por Bluetooth LE
- [jabridge](https://github.com/Watchdog0x/jabridge): protocolo Jabra GNP (receptores Link 380 / 390)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): protocolo de página de estado `1EA7:0066` (Fantech Raigor III y otros dispositivos genéricos «2.4G Mouse»)
- `hid-playstation` de Linux: formato de informe DualShock 4 / DualSense
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): protocolo del fabricante AULA SC580 / SC580X
- Aplicación web RAWM HUB ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) y su tabla de dispositivos: ratones RAWM y SADES Dagger
- [Controlador HID Flydigi de SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) y [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): formato de consulta y estructura de batería para Vader 5 Pro y Apex 5
- [Controlador HID 8BitDo de SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): byte de batería de 8BitDo Ultimate 2
- BEITONG iControl (sus páginas de KP20 y KP40D y el tráfico USB del receptor KP20): consulta de batería y permutación de carga útil de BEITONG KP20 / KP40D
- [Controlador HID 8BitDo de SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) y [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): byte de batería y protocolo HID del fabricante 8BitDo
- JBL QuantumENGINE (sus mensajes HIDV3 de información del dispositivo): auriculares JBL Quantum
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, protocolo Compx en `FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) y [BrimDeck](https://github.com/MoFeng2223/BrimDeck): lectura de perfil de Scyrox V12M
- JBL QuantumENGINE: informes de conexión y batería HIDV1 para Quantum 350, y mensajes HIDV3 de información del dispositivo para auriculares Quantum más recientes
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): informes de batería y enlace HIDV1 del JBL Quantum 610, y la línea Quantum (360 como modelo de receptor HIDV1)

## Licencia

[Licencia Pública General de GNU v3.0 o posterior](../../LICENSE). Puedes usar, modificar y redistribuir este software, pero cualquier obra basada en él que distribuyas debe publicarse bajo la misma licencia, junto con su código fuente.


---

<a id="sec-contributing"></a>
> 📄 **Sección:** Contribuir (`CONTRIBUTING.md`) · [Original en inglés](../../CONTRIBUTING.md) · [↑ Arriba](#top)

# Contribuir

## Informar si un dispositivo funciona

La mayoría de los controladores se escribieron a partir de documentación de protocolos y no pudieron probarse en todos los modelos. Abre un issue indicando:

- el nombre del dispositivo, y si está conectado por receptor, cable o Bluetooth
- la salida de `BatteryHub.exe --list`
- la salida de `BatteryHub.exe --dump`
- lo que muestra el software propio del fabricante como nivel de batería

## Añadir un dispositivo

1. Ejecuta `BatteryHub.exe --dump` y busca el ID de proveedor (VID) y producto (PID) de tu dispositivo, así como las colecciones definidas por el fabricante (página de uso `FFxx`) con sus tamaños de informe.
2. Encuentra el protocolo de batería. Buenos sitios donde buscar: HeadsetControl, OpenRazer, Solaar, rivalcfg, OpenRGB, OpenLinkHub, o una captura USB del software del fabricante (Wireshark + USBPcap).
3. Si el fabricante ya tiene un controlador en `src/drivers/`, añade ahí el ID de producto (y cualquier diferencia). De lo contrario, crea `src/drivers/<fabricante>.cpp`:

   ```cpp
   #include "drivers.h"

   void PollAcme(PollContext& ctx) {
       for (auto [vid, pid] : ctx.Products(0x1234)) {           // unclaimed products of this vendor
           for (const HidColl* c : ctx.Find(vid, pid, [](const HidColl& c) { return c.page() == 0xFF00; })) {
               HidDev d;
               if (!d.Open(*c)) continue;
               std::vector<BYTE> r;
               if (!d.Write({ 0x01, 0x02 }) || d.Read(r, 500) < 3) continue;   // hidapi-style buffers
               DeviceStatus s;
               s.key = L"acme:" + Hex4(pid);
               s.name = HidProduct(*c);
               s.kind = DeviceKind::Mouse;
               s.via = L"2.4 GHz receiver";
               s.percent = Clamp100(r[2]);
               ctx.Add(s, vid, pid);
               break;
           }
       }
   }
   ```

4. Declara la función en `src/drivers/drivers.h` y llámala desde `PollAllDevices()` en `src/devices.cpp` (antes de los respaldos genéricos). `build.bat` y el Makefile detectan los archivos nuevos automáticamente.
5. Actualiza la tabla de dispositivos en `README.md`.

### Reglas para los controladores

- **Solo lectura:** envía únicamente peticiones que lean estado. Nunca cambies ajustes, iluminación ni modos.
- **Coincidencia exacta:** comunícate únicamente con dispositivos que reconozcas por ID de proveedor y producto, o por una colección específica del fabricante que sea exclusiva del protocolo.
- **Tiempo de espera siempre limitado:** un dispositivo ausente no debe bloquear el sondeo más de aproximadamente un segundo. Los protocolos pasivos pueden necesitar más tiempo para cubrir un intervalo de envío documentado (por ejemplo, Delux y Rapoo). Mantén un único plazo límite absoluto de como máximo 4 segundos por colección coincidente, no lo reinicies ante informes no relacionados y documenta por qué es necesaria la excepción.
- **Cita las fuentes:** indica de dónde procede el protocolo en un comentario al principio del archivo.

## Traducciones

Los idiomas de la interfaz son archivos de texto UTF-8 estáticos y sencillos en `lang/` cargados desde disco en tiempo de ejecución tanto en Windows como en Linux (copia `lang/_template.json` a `lang/<code>.json`, rellena `@code`, `@name` y las frases; no requiere recompilar). Los textos nuevos de la interfaz en el código pasan por `T(L"...")`, o `TF(L"... {name} ...", { { L"name", value } })` cuando contienen valores; nunca construyas frases traducidas uniendo fragmentos. Después de añadir frases, añádelas también a `lang/_template.json`.

Las traducciones del instalador de Windows viven en `installer/lang/*.isl` (guardadas como UTF-8 con BOM y registradas en `installer/BatteryHub.iss`), los comentarios del lanzador de Linux viven en `linux/wireless-battery.desktop`, y las traducciones completas de la documentación viven en `docs/i18n/<code>.md` (un único archivo independiente copiado de `docs/i18n/_template.md`). Consulta [`docs/i18n/README.md`](README.md) para ver la guía completa para colaboradores.

## Estilo de código

C++17, solo Win32, sin dependencias de terceros. Mantén el binario pequeño. Formatea aproximadamente igual que el código existente (sangría de 4 espacios, líneas de 120 columnas).

## Desarrollo del actualizador de Windows

El actualizador es solo para Windows y usa WinHTTP, BCrypt y el instalador existente de Inno Setup. Mantén el estado de actualización exclusivamente en el menú. No añadas iconos de actualización, insignias, cambios en la descripción emergente de batería, globos, avisos flotantes ni cuadros de diálogo automáticos. El sondeo de dispositivos se ejecuta separado del trabajo de red.

La versión de compilación y el canal se comparten entre C++ y el recurso de Windows mediante el archivo generado `build/version.h`. Usa `make VERSION=1.2.3 CHANNEL=test` o `build.bat 1.2.3 test` para pruebas locales; `dev` es el predeterminado y `stable` habilita las comprobaciones oficiales de lanzamientos. Los componentes de versión deben caber en 0..65535. Solo el flujo de trabajo de etiquetas de lanzamiento del repositorio oficial selecciona `stable` automáticamente. No conviertas accidentalmente la compilación de un fork en un canal de actualizaciones oficial.

Ejecuta `make test VERSION=1.2.3 CHANNEL=test` para las pruebas de dispositivos existentes más el análisis estricto de versiones, orden de versiones, programación de comprobaciones, verificaciones reales de archivos SHA-256, comillado de argumentos y protecciones del asistente. Las pruebas de regresión del actualizador también cubren la cancelación al completarse la descarga, protecciones de diálogos y fallos al configurar tiempos de espera o restricciones de redirección HTTP. La prueba de Windows incluye las implementaciones, siguiendo el patrón existente de pruebas del backend de Linux, y sustituye el envío HTTP para que estas pruebas no puedan contactar con GitHub. No se añaden puntos de entrada de control solo para pruebas en producción. Los objetivos individuales son `make test-update-core` y `make test-update-win`. Las pruebas nativas del actualizador enlazan el recurso de la aplicación para activar Common Controls v6. Las pruebas usan datos locales y no descargan, elevan privilegios, instalan ni modifican la configuración de inicio del usuario. El punto final de producción de la aplicación no puede sobrescribirse para pruebas.

Antes de empaquetar, ejecuta `powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`. `installer/build-installer.ps1 -Version 1.2.3` también ejecuta esta comprobación antes de descargar dependencias. La ruta del instalador `/WBUPDATE=1` conserva el inicio automático y la configuración existentes y deja el relanzamiento al asistente temporal. Ese asistente permanece bajo el usuario original, elevando privilegios solo en una instalación global. Los identificadores WinHTTP pertenecen al hilo trabajador; la cancelación es cooperativa entre llamadas con tiempo de espera finito. El cierre final de la aplicación espera a ese hilo trabajador y, por lo tanto, puede aguardar un tiempo de espera de red en curso.

Para una revisión de lanzamiento, usa una cuenta de Windows o máquina virtual desechable para probar dos versiones reales del instalador, ámbito por usuario/global, cancelación de UAC, inicio automático activado/desactivado, rutas personalizadas, fallo de instalación y relanzamiento. Las pruebas unitarias y la compilación de un paquete no verifican esos efectos del instalador. La revisión visual de menús/temas y las comprobaciones reales de extremo a extremo del instalador/UAC siguen siendo puertas manuales de lanzamiento; no las marques como superadas a menos que se hayan observado realmente. Nunca hagas pruebas sobrescribiendo la instalación del usuario diario.

## Comprobación automática de seguridad

Cada pull request es analizada por la «PR safety check» en busca de cosas que esta aplicación nunca debería hacer (acceso a la red, ejecución de programas, lectura de teclado/portapapeles/pantalla, entradas de inicio, binarios, cambios de compilación o lanzamiento). Una marca de aviso no es un rechazo: simplemente explica las líneas señaladas en la descripción de la PR.

Usar herramientas de IA está bien, pero por favor elimina las líneas `Co-authored-by` que les den crédito (por ejemplo `Co-authored-by: Claude ...`) de tus mensajes de commit. La comprobación falla mientras estén presentes.


---

<a id="sec-pr-template"></a>
> 📄 **Sección:** Plantilla de Pull Request (`.github/pull_request_template.md`) · [Original en inglés](../../.github/pull_request_template.md) · [↑ Arriba](#top)

## Qué añade esto

<!-- Dispositivo(s) e IDs de proveedor/producto, p. ej. "Acme M1 (1234:5678)". -->

## De dónde proviene el protocolo

<!-- Enlaza la fuente (otro proyecto, un controlador web del fabricante, tu propia captura USB). -->

## ¿Probado en hardware real?

<!-- Sí (qué dispositivo, qué imprimió --list) / No -->

## Lista de verificación

- [ ] Solo se envían consultas de batería de solo lectura; no se cambian ajustes, iluminación ni firmware
- [ ] Solo se accede a dispositivos reconocidos por ID de proveedor/producto (o una colección específica del protocolo)
- [ ] Sin acceso a la red, sin lanzar otros programas, sin archivos nuevos fuera de `src/`, `docs/` o `README.md`
- [ ] No se incluyen binarios ni archivos generados
- [ ] Sin líneas `Co-authored-by` que acrediten herramientas de IA (Claude, Copilot, ChatGPT ...) en los mensajes de commit
- [ ] Los cambios en `.github/`, `installer/`, `build.bat` o `Makefile` se explican arriba


---

<a id="sec-releasing"></a>
> 📄 **Sección:** Publicación y firma (`docs/releasing.md`) · [Original en inglés](../../docs/releasing.md) · [↑ Arriba](#top)

# Publicación de versiones

La aplicación se actualiza a sí misma desde los lanzamientos de GitHub, pero solo instala un instalador cuyo SHA-256 aparezca en un archivo `SHA256SUMS.txt` firmado con la clave de lanzamiento. Esa clave vive en el PC del mantenedor, nunca en GitHub: una cuenta, token o flujo de trabajo comprometido puede publicar archivos, pero no una firma que la aplicación acepte.

## Una sola vez: crear la clave de lanzamiento

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Pide una contraseña (de 12+ caracteres) y escribe la clave privada cifrada en `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- Coloca la clave pública en `src\update_public_key.h`. Haz commit de ese archivo. Las compilaciones oficiales rechazan compilar sin una clave dentro.
- **Haz una copia de seguridad del archivo de clave y guarda la contraseña** (un gestor de contraseñas es un buen lugar para ambos). Si se pierde cualquiera de los dos, las aplicaciones instaladas ya no podrán actualizarse solas: tendrías que crear una clave nueva y cada usuario tendría que instalar una versión manualmente.

## Cada lanzamiento

1. Sube una etiqueta de versión (`git tag v1.2.3 && git push origin v1.2.3`). La CI compila el instalador, el ZIP portable y `SHA256SUMS.txt`, y publica el lanzamiento.
2. Firma la lista de sumas de comprobación:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Descarga `SHA256SUMS.txt` del lanzamiento, lo muestra, pide confirmación, pide la contraseña de la clave y escribe `SHA256SUMS.txt.sig`. Si tienes los mismos archivos en `dist\` (una compilación local de esa versión), muestra si coinciden.
3. Sube `SHA256SUMS.txt.sig` al lanzamiento (el script abre la página de edición). A partir de ese momento la aplicación ofrece **Descargar e instalar**. Antes de eso muestra la actualización, pero solo enlaza a la página del lanzamiento.

Firma únicamente una lista de un lanzamiento que hayas publicado tú mismo. La firma dice «estos archivos exactos son el lanzamiento», por lo que firmar es el paso donde se detectaría una carga maliciosa.

## Cambiar la clave

Ejecuta `new-release-key.ps1` con un nuevo `-KeyFile`: añade la nueva clave pública junto a la antigua en `src\update_public_key.h`. Publica una versión firmada con la clave antigua que contenga ambas, luego firma con la nueva clave a partir del siguiente lanzamiento y elimina la clave antigua más adelante. Una clave perdida o filtrada no puede retirarse de esta manera: elimínala de la cabecera, y los usuarios de versiones anteriores tendrán que instalar el siguiente lanzamiento manualmente.

## Qué comprueba la aplicación antes de ejecutar un instalador

- El lanzamiento es el último del repositorio, no es un borrador ni versión preliminar, y es más reciente que la aplicación.
- `SHA256SUMS.txt.sig` es una firma ECDSA P-256 válida de `SHA256SUMS.txt` realizada por una clave en `src\update_public_key.h` (BCrypt de Windows, sin código de terceros).
- La lista firmada nombra a `BatteryHub-Setup-<version>.exe` exactamente una vez, con el mismo SHA-256 que GitHub indica para el archivo.
- El instalador descargado tiene exactamente ese tamaño y SHA-256. Una copia de la aplicación vuelve a comprobarlo justo antes de iniciarlo, y mantiene el archivo bloqueado para que no pueda cambiarse en medio.
- Las descargas solo usan HTTPS hacia `github.com`, `objects.githubusercontent.com` y `release-assets.githubusercontent.com`, verificando cada redirección.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Sección:** Firmware de teclado Keychron (`docs/keychron_keyboard_firmware/README.md`) · [Original en inglés](../../docs/keychron_keyboard_firmware/README.md) · [↑ Arriba](#top)

# Batería de teclados Keychron a través del receptor de 2.4 GHz

El firmware de fábrica de Keychron solo informa de la batería del teclado por Bluetooth. Con el pequeño cambio de QMK en [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch), el teclado también responde a una consulta de batería (`A4`) a través del receptor Keychron Link y por el cable USB, y BatteryHub muestra su nivel, voltaje y estado de carga.

Probado en el **Keychron K5 Max ANSI RGB** (`3434:0A50`) con el receptor Keychron Link (`3434:D030`).

## Qué cambia el parche

Basado en la rama `2025q3` de [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) (commit `57e682c`):

- añade el comando HID sin procesar `KC_GET_BATTERY` (`0xA4`) de [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1):
  respuesta `[A4][porcentaje][mV lo][mV hi][carga: 0 batería / 1 cargando / 2 completa][transporte][id de modelo]`;
- pasa las peticiones HID sin procesar que llegan por el enlace inalámbrico al mismo manejador;
- en `keyboards/keychron/k5_max/config.h`: `#define WILRESS_RAW_ENABLE` (escrito así en el código de Keychron) y `#define KC_BATTERY_MODEL_ID 0`.

No cambia nada más: los mapas de teclas, la iluminación y Keychron Launcher siguen funcionando.

## Opción 1: flashear el firmware ya compilado del K5 Max

Hay una compilación **exclusiva para K5 Max ANSI RGB** adjunta en [este lanzamiento](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1) (`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`). No lo flashees en otro modelo o distribución.

## Opción 2: compilarlo tú mismo

Necesita Git y Docker (o una [configuración QMK](https://docs.qmk.fm/newbs_getting_started) funcional).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

El resultado es `keychron_k5_max_ansi_rgb_keychron.bin` en la raíz del repositorio. En Windows, una copia de trabajo montada por volumen (`bind mount`) es muy lenta en Docker; clonar dentro del contenedor (o en WSL) es mucho más rápido.

**Otros teclados inalámbricos Keychron** (Q/V/K Max y otros modelos en el árbol `2025q3` con `LK_WIRELESS_ENABLE`): los cambios bajo `keyboards/keychron/common/` se aplican tal cual. Añade las dos líneas `#define` al `config.h` de tu teclado en lugar del de K5 Max, y compila tu propio objetivo, p. ej. `make keychron/<model>/<layout>/<variant>:keychron`. Actualmente la aplicación identifica por nombre de modelo un K5 Max (`0A50`–`0A58`) y llama a cualquier otro «Keychron keyboard».

## Flasheo

1. Pon el interruptor de modo en **Cable** y desconecta el cable USB.
2. Mantén pulsada la tecla **Esc** mientras enchufas el cable. El teclado entra en el cargador de arranque STM32.
3. Flashea el `.bin` con [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (o `dfu-util`).
4. Vuelve a cambiar a **2.4 GHz** y compruébalo con `BatteryHub.exe --list`:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Actualizar el teclado desde Keychron Launcher sustituye este firmware y elimina el informe de batería. Para deshacerlo, flashea el firmware oficial de Keychron de la misma manera.

## Licencia

QMK es GPL-2.0-or-later; el parche está bajo la misma licencia. Cualquiera que reciba un binario compilado a partir de él también debe poder obtener este cambio de código fuente.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Sección:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [Original en inglés](../../docs/gamesir_cyclone_pro.md) · [↑ Arriba](#top)

# Soporte de batería para GameSir Cyclone Pro

## Por qué el mando aparecía como un mando Xbox completo

El Cyclone Pro (modelo T4cp) funciona a través de un receptor de 2.4 GHz, `3537:1015`. El receptor se presenta ante Windows como un mando de Xbox 360 con cable (XUSB, `Xbox 360 Controller for Windows`). XInput responde a su consulta de batería con «Full», por lo que el respaldo de XInput lo listaba como `Xbox controller 1` al 100% fuera cual fuera la carga real.

El receptor no transporta información de batería:
- su única colección HID es el controlador de juegos XInput (`HID\VID_3537&PID_1015&IG_00`)
- no tiene ninguna colección definida por el fabricante como el Nova (`FF7A`) o el Cyclone 2 (`FFF0`)

## Dónde está el nivel

Mientras funciona a través del receptor, el mando también se anuncia por Bluetooth LE como `GameSir-Cyclone Pro`, que es el enlace que usa la aplicación móvil de GameSir. Su petición «get base info» devuelve la batería:

| Paso | Detalle |
|---|---|
| Servicio | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Característica | `0x865F` (notificación, escritura sin respuesta) |
| Petición | habilitar notificaciones, escribir `01 01` |
| Respuesta | notificación de 19 bytes (algunos firmwares la anteponen con `C9`, 20 bytes) |

Estructura de la respuesta:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

El byte 18 es la batería en porcentaje (0-100), o `FF` mientras carga. No se informa ningún nivel mientras se carga, así que se conserva el último porcentaje conocido y se muestra con el rayo de carga.

El mando también dispone del servicio `0xFF10`, que es el canal de actualización de firmware de GameSir. El controlador nunca lo abre. El mando no tiene un Servicio de Batería estándar (`0x180F`), motivo por el cual la página de Bluetooth de Windows y el respaldo de Bluetooth no muestran ningún nivel para él.

Fuente: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), donde el protocolo se dedujo a partir de la aplicación Android de GameSir (`BluetoothLeService`, «get base info»).

## Cómo funciona el controlador

`src/drivers/gamesir_ble.cpp`, llamado antes que el respaldo de XInput:

1. **Localizar el mando.** Busca interfaces de dispositivo de la clase `{00008650-0000-1000-8000-00805F9B34FB}`. Windows crea una para cada servicio GATT de un dispositivo BLE emparejado. Solo utiliza aquellas cuyo nodo padre `BTHLE\DEV_…` se llama `GameSir-Cyclone…`.
2. **Leer la batería.** Abre ese servicio con la API GATT de Win32 (`bluetoothleapis.h`, `-lbluetoothapis`), se suscribe a `0x865F` y escribe `01 01`. Espera hasta 3 segundos la respuesta y luego vuelve a desactivar las notificaciones.
3. **Mantener rápido el sondeo.** La conexión BLE puede tardar segundos o agotar el tiempo de espera mientras el mando está en reposo, por lo que la consulta se ejecuta en su propio hilo:
   - como máximo cada 2 minutos tras una lectura correcta, o cada minuto tras una fallida
   - el sondeo informa la lectura en caché y deja de informarla cuando tiene 6 minutos de antigüedad
   - `graceSec` la mantiene entonces visible, atenuada, como en reposo
   - solo el primer sondeo de una ejecución espera al hilo, una única vez, con un plazo límite absoluto de 4 segundos, para que el nivel se muestre al arrancar y en `--list`
4. **Ocultar la entrada Xbox falsa.** Cuando el receptor está presente, el controlador reclama `3537:1015`:
   - la ruta `Windows.Gaming.Input` ahora omite los IDs de proveedor/producto reclamados
   - la ruta XInput obtiene el ID de proveedor/producto de cada ranura mediante `XInputGetCapabilitiesEx` (xinput1_4 ordinal 108) y omite los reclamados
   - cuando esa exportación falta, XInput se comporta como antes

## Hardware probado

Windows 11, Cyclone Pro en su receptor (`3537:1015`), emparejado una vez por Bluetooth, el 2026-11-18:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Mientras el mando estaba en reposo, la entrada «Xbox controller 1 / Full» dejó de aparecer y no se mostró nada para el mando.

## Limitaciones

- **Emparejamiento:** el mando debe emparejarse con Windows una vez (Configuración > Bluetooth y dispositivos > Agregar dispositivo > Bluetooth > `GameSir-Cyclone Pro`). Los mandos sin emparejar no tienen interfaz de dispositivo GATT. El emparejamiento añade entradas de mando Bluetooth, pero no envían entrada mientras el mando juega a través del receptor.
- **Bluetooth obligatorio:** el PC necesita Bluetooth LE.
- **Un mando:** solo se lee un Cyclone Pro por PC.
- **Carga:** no hay porcentaje mientras se carga.


---

<a id="sec-localization-guide"></a>
> 📄 **Sección:** Guía de uso multilingüe y localización (`docs/i18n/README.md`) · [Original en inglés](../../docs/i18n/README.md) · [↑ Arriba](#top)

# Índice multilingüe y guía de localización de BatteryHub

Todos los documentos visibles de este repositorio están reunidos en **un archivo Markdown independiente por idioma** dentro de `docs/i18n/`, mientras que todas las cadenas de la aplicación en tiempo de ejecución viven en **archivos de texto estáticos editables** dentro de [`lang/`](../../lang) (compartidos por Windows y Linux) y las cadenas del instalador de Windows viven en [`installer/lang/`](../../installer/lang).

## Idiomas compatibles (19)

| Código | Idioma | Documentación completa | Interfaz de la app (Windows y Linux) | Instalador de Windows |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (cadenas origen) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Cómo funciona en la práctica el cambio de idioma

### 1. Aplicación de Windows (`BatteryHub.exe`)
- **Detección automática:** cuando está configurado en *Idioma → Automático (idioma de Windows)*, BatteryHub consulta `GetUserPreferredUILanguages` de Windows y busca el archivo estático `*.json` más cercano.
- **Cambio manual:** haz clic en el widget de la barra de tareas o en el icono de la bandeja → **Idioma** → elige un idioma. La interfaz se actualiza de inmediato y se guarda en `HKCU\Software\WirelessBattery\Language`.
- **Archivos externos estáticos (editables sin recompilar):** `BatteryHub.exe` carga primero `<exe>\lang\*.json` y después `%APPDATA%\WirelessBattery\lang\*.json`. Cualquier archivo en la carpeta del usuario con el mismo `@code` sobrescribe las frases coincidentes, y al volver a abrir el menú se recargan los archivos desde el disco en vivo.
- **CLI `--help`:** `BatteryHub.exe --help` muestra el cuadro de ayuda en tu idioma de interfaz activo (`--list`, `--json` y `--dump` permanecen en inglés a propósito para los informes de issues en GitHub).

### 2. Aplicación de Linux (`wireless-battery`)
- **Detección automática:** sigue las variables de configuración regional POSIX en orden: `LANGUAGE` (lista separada por dos puntos) → `LC_ALL` → `LC_MESSAGES` → `LANG` (salvo que esté anulada por `LC_ALL=C` / `POSIX`).
- **Cambio manual:** haz clic derecho en el icono de la bandeja → **Idioma** → elige **Automático (idioma del sistema)** o cualquier idioma instalado. Se guarda bajo `[general] language=` en `$XDG_CONFIG_HOME/wireless-battery/config.ini` (por defecto `~/.config/wireless-battery/config.ini`).
- **Rutas de búsqueda estáticas (de menor a mayor prioridad):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (por defecto `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (por defecto `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help` imprime la ayuda CLI traducida según `config.ini` o la configuración regional del sistema; `--list` y `--dump` permanecen en inglés.

### 3. Instalador de Windows (`BatteryHub-Setup-<version>.exe`)
- Muestra un selector de idioma (`ShowLanguageDialog=yes`) preseleccionado según el idioma de interfaz de Windows (`LanguageDetectionMethod=uilanguage`).
- Instala la carpeta estática completa `lang\*.json` en `{app}\lang\` junto a `BatteryHub.exe` (y el ZIP portable también incluye `lang\*.json`).

---

## Cómo añadir o actualizar un idioma (paso a paso)

**No** necesitas ninguna herramienta de compilación para traducir la interfaz de la aplicación o la documentación, y solo Inno Setup 6 si deseas compilar una prueba del instalador de Windows.

### Paso 1 — Cadenas de la interfaz de la app (`lang/<code>.json`)
1. Abre la carpeta de idioma del usuario desde el menú de la bandeja (**Idioma → Añadir tu propio idioma...**) o copia [`lang/_template.json`](../../lang/_template.json) a `lang/<code>.json` (p. ej. `lang/it.json`).
2. Rellena la cabecera de metadatos:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Traduce la parte derecha después de ` = ` en cada línea.
   - Mantén literales los marcadores de posición como `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}`.
   - Usa `\n` para los saltos de línea explícitos.
   - Guarda el archivo como **UTF-8 (sin BOM)**.
   - Vuelve a abrir el menú de bandeja de BatteryHub para previsualizarlo al instante — ¡sin recompilar!

### Paso 2 — Instalador de Windows (`installer/lang/<code>.isl`)
1. Copia [`installer/lang/_template.isl`](../../installer/lang/_template.isl) a `installer/lang/<code>.isl`.
2. **CRÍTICO:** guarda el archivo como **UTF-8 con BOM (`EF BB BF`)** para que Inno Setup decodifique correctamente los caracteres Unicode independientemente de las páginas de códigos heredadas de Windows.
3. Elige el patrón adecuado:
   - **Inno Setup ya incluye tu idioma** (comprueba `C:\Program Files (x86)\Inno Setup 6\Languages\`): conserva solo `[CustomMessages]` y traduce las 6 líneas (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, manteniendo `%1` y `%n`). Regístralo en `installer/BatteryHub.iss` bajo `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup no incluye tu idioma**: copia `installer/lang/zh-CN.isl` como referencia completa, configura `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, opcionalmente `RightToLeft=yes`), traduce `[Messages]` y `[CustomMessages]`, y regístralo después de `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Nota: los identificadores `Name:` bajo `[Languages]` solo pueden contener letras ASCII, dígitos y guiones bajos (usa `ptBR`, no `pt-BR`).

### Paso 3 — Lanzador de escritorio de Linux (`linux/wireless-battery.desktop`)
Añade una línea localizada `Comment[<code>]=...` (usa guiones bajos para etiquetas regionales en archivos `.desktop`, p. ej. `Comment[zh_CN]=...`).

### Paso 4 — Documentación completa en un solo archivo (`docs/i18n/<code>.md`)
1. Copia [`docs/i18n/_template.md`](_template.md) a `docs/i18n/<code>.md` (no requiere ningún script generador — ¡solo este archivo!).
2. Traduce el Índice y las 17 secciones por completo manteniendo intactos:
   - Todas las etiquetas de ancla `<a id="sec-..."></a>` y `<a id="top"></a>`
   - Todos los bloques de código, opciones CLI (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), `VID:PID` USB, páginas de uso HID, paquetes hexadecimales, claves del Registro, rutas de archivos y URLs literales
   - Rutas relativas de imágenes y archivos intactas (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE`, etc.)
3. Actualiza la barra superior `<!-- lang-switcher:start -->` en `docs/i18n/<code>.md` (pon en negrita tu propio idioma y enlaza todos los demás) y añade el enlace de tu idioma a las barras selectoras en `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` y los archivos hermanos `docs/i18n/*.md`.
4. Para idiomas de derecha a izquierda (`ar`, `fa`, `he`), escribe Markdown estándar sin envolver todo el archivo en `<div dir="rtl">` para que las tablas y los bloques de código se muestren limpiamente.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Sección:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [Original en inglés](../../docs/ardor_fury_v2.md) · [↑ Arriba](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

El receptor de 2.4 GHz expone la página de uso HID `000A`, uso `0000`, y un informe de entrada de 5 bytes. Emite datos por difusión; no se envían comandos HID.

Informes observados en hardware real:

| Informe | Batería |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

El nibble alto del byte 3 codifica el nivel (`1`, `3`, `7`, `F` para 25, 50, 75 y 100 por ciento). Los informes para 25% y 100% se deducen de la lógica de decodificación de la aplicación del fabricante; el usuario final confirmó posteriormente que los niveles restantes se muestran correctamente en la aplicación compilada. El quinto byte no es constante y no se usa como firma.

El oyente requiere dos niveles de batería decodificados coincidentes, en lugar de dos informes completos idénticos. El último valor confirmado se conserva durante un máximo de 45 segundos. El intervalo global de actualización automática cambia a 15 segundos.

Validado por el usuario final en Windows con ARDOR Fury V2 y Logitech G733: capturas al 50% y 75%, actualización automática periódica, comprobaciones visuales de 25%/100% y arranque portable. Los informes para 25% y 100% no llegaron a capturarse.


---

<a id="sec-areson"></a>
> 📄 **Sección:** Areson `25A7` (`docs/areson.md`) · [Original en inglés](../../docs/areson.md) · [↑ Arriba](#top)

# Soporte de batería para receptores Areson 25A7

## Por qué el programa original no detectaba el ratón

El Redragon M915RGB-WL se conecta mediante un receptor Areson/CompX `25A7:FA07` «2.4G Wireless Receiver». Su batería no se expone como un uso HID estándar *Battery Strength* y Windows no tiene ninguna propiedad de batería Bluetooth para él, porque el enlace es propietario de 2.4 GHz. En su lugar, el ratón responde a una petición activa `GetPower`, por lo que ni el respaldo HID genérico ni el respaldo Bluetooth podían verlo. No existía controlador para el fabricante, así que el receptor quedaba sin reclamar y en silencio.

## Hardware y paquetes observados

Probado en Windows 11 con un Redragon M915RGB-WL el 2026-11-17:

| Dirección | VID:PID | Interfaz | Página de uso:uso | Tamaño de informe |
|---|---|---|---|---|
| petición (característica) | `25A7:FA07` | 1 | `FF02:0002` | 17 bytes |
| respuesta (entrada) | `25A7:FA07` | 1 | `FF01:0000` | 17 bytes |

La respuesta llega por una colección de nivel superior distinta de aquella en la que se escribe la petición. En Windows son `MI_01&COL07` (característica) y `MI_01&COL05` (entrada), motivo por el cual el controlador abre ambos manejadores.

Petición capturada (`GetPower`, ID de informe `08`, comando `04`; la suma de comprobación hace que la trama sume `0x55`):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Respuesta capturada:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Los desplazamientos siguientes cuentan el ID de informe como byte cero:

| Byte(s) | Significado | Ejemplo |
|---|---|---|
| 0 | ID de informe de respuesta | `09` |
| 1 | Eco del comando | `04` |
| 2 | Estado, 0 = OK | `00` |
| 3–4 | Dirección, sin uso para `GetPower` | `00 00` |
| 5 | Longitud de datos (2) | `02` |
| 6 | Nivel de batería, 0–10, en pasos del 10% | `08` = 80% |
| 7 | Indicador de carga, cualquier valor distinto de cero | `00` = sin cargar |
| 16 | Suma de comprobación; los 17 bytes suman `0x55` (mod 256) | `3E` |

El propio software del fabricante mostró un 80% para esa misma trama, lo que confirma la escala ×10. `GetConnectStatus` (`08 03 …`) responde con una carga útil de 1 byte e informó al mismo tiempo de que el ratón estaba enlazado.

## Otros ratones Areson

Los receptores más antiguos `FA7B` / `FA7C` usados por el Redragon M693 informan de la carga directamente como un porcentaje entero en el mismo desplazamiento de respuesta. Aplicar allí la escala ×10 de este controlador mostraría un 800%, por lo que esos IDs de producto no se reclaman intencionadamente. Solo se gestionan `FA07` y `FA08`; `FA08` es la identidad alternativa de la misma familia y no se ha verificado en este equipo.

## Sondeo e identidad

- El controlador solo envía la petición de solo lectura `GetPower`. Nunca escribe configuración, iluminación ni datos de DPI.
- Cada actualización abre la colección de características con acceso cero y la colección de entrada para lectura, envía la petición y espera hasta 1.8 s por una respuesta, con dos intentos y un vaciado de cola entre ambos para que no pueda confundirse un informe antiguo con la respuesta.
- Una lectura fallida no reclama nada, por lo que un ratón en reposo conserva el último valor en la interfaz. La entrada usa un período de gracia de 30 minutos, en línea con los demás controladores pasivos.
- La clave del dispositivo se deriva del ID de proveedor y producto (`areson:25A7:FA07`), por lo que sobrevive al ciclo recepción/reposo y a reconectar el receptor.

## Validación

La aplicación completa se compiló con MSVC C++17 y el SDK de Windows y se ejecutó contra el ratón real. `BatteryHub.exe --list` devolvió:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

La lectura coincidió con el porcentaje mostrado por el software oficial de Redragon en ese mismo momento. El archivo `build.bat` de MinGW incluye el nuevo archivo fuente; el `Makefile` lo detecta mediante su comodín.

## Fuentes del protocolo

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): tramas de 17 bytes, separación característica/entrada y la regla de suma de comprobación `0x55`, recuperadas de capturas USB del software de Redragon.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): comando `GetPower` y escala de nivel del 10% en `25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md): formato de respuesta y la escala porcentual distinta en la familia `FA7B` / `FA7C`.


---

<a id="sec-darkrim"></a>
> 📄 **Sección:** DARKRIM SHADOW (`docs/darkrim.md`) · [Original en inglés](../../docs/darkrim.md) · [↑ Arriba](#top)

# Receptor DARKRIM SHADOW / 寸渊影弑

Probado en hardware con `3654:6901`, fabricante `Jieli Technology`, versión `0100`. Usa la interfaz **3**, uso `FF02:0002`, cargas útiles de entrada/salida de 64 bytes sin numerar (tamaños de informe HID en Windows de 65 bytes). La interfaz 4 también tiene `FF02:0002`, pero usa el ID de informe 2 y no respondió a este protocolo; se excluye deliberadamente.

Fuente del protocolo: la [descarga oficial de PC Hub](https://app.darkrim.net/hub/zh.html), `DARKRIM-0.1.26-x64-setup.rar`, descargada y descomprimida estáticamente sin instalar ni iniciar el software del fabricante. SHA-256 del `DARKRIM.exe` extraído: `f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Direcciones útiles en ese binario:

- `140124C80`: `sendGetBasicInfo(infoType)` envía el comando `0010`, Request `01`, carga útil `[infoType, 00]`. El selector de batería es `01`.
- `140118D30`, `140119200`: generación de cabecera de trama y CRC.
- `140126DB0`: analizador TLV de información del dispositivo; el TLV `01` es la batería.
- `1400F5660`, `1400FA700`: consumidores de batería; los siete bits bajos dan el porcentaje, el bit alto es el estado de carga. El mismo valor de batería también llega en `0011` Notify `03`.

Cabecera: `FE seq cmdLE type index count lengthLE`, seguida de la carga útil y CRC-16/CCITT-FALSE (polinomio `1021`, inicial `FFFF`, almacenado en big-endian). La secuencia es un contador de cuatro bits distinto de cero; el cifrado no se utiliza.

Cargas útiles reales de petición/respuesta, antes del relleno con ceros HID:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

El TLV de respuesta `01 01 28` da **40%, sin cargar**. El controlador C++ de producción devolvió ese valor en tres consultas consecutivas sin software del fabricante. El receptor emite notificaciones de arranque antes de la respuesta coincidente, medidas en unos 406 ms. Usa un único plazo límite de respuesta de 800 ms (más un máximo de 200 ms para escritura), sin reiniciarlo por notificaciones no relacionadas. No se requiere latido (*heartbeat*).

El controlador solo envía el GET de batería. Acepta únicamente una respuesta sin cifrar con secuencia/comando/tipo coincidentes, índice cero, recuento cero o uno (el hardware usa cero), longitud/CRC válidos y un único TLV de batería bien formado. Las respuestas fragmentadas, no solicitadas, malformadas o fuera de rango se descartan.

## Precisión de batería observada y estado de carga

Considera el porcentaje como una **estimación aproximada, no como un medidor verificado con resolución del 1%**. La unidad del propietario mostró el progreso de carga en pasos de 10 puntos porcentuales desde el 40% hasta el 90%. Al 90%, cinco respuestas GET de batería y una notificación no solicitada llevaron todas `DA`: `DA & 7F = 90`, con el bit 7 indicando carga. Después de que el propietario desconectara el cable de carga y siguiera usando el receptor de 2.4 GHz, otras cinco respuestas GET y una notificación llevaron todas `5A`: seguía siendo 90%, ahora con el bit de carga despejado. Las doce tramas superaron la verificación CRC.

Respuestas representativas de consulta (secuencia 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Tanto el controlador como la aplicación oficial toman el porcentaje directamente de los siete bits bajos. El controlador no redondea a decenas, ni multiplica un nivel por diez, ni interpola valores intermedios; los informes sintéticos del 47% y 95% permanecen en 47% y 95% en el analizador de producción. Por tanto, las lecturas aproximadas observadas tienen su origen antes del analizador, en el reporte de los auriculares o del receptor. No se han observado lecturas de hardware más precisas. No se ha registrado una curva de descarga completa, así que no está confirmado un paso fijo del 10% en todos los niveles de descarga ni en otro firmware.

Los estados de carga y posterior ausencia de carga al 90% se han comprobado en hardware. Los límites bajo/completo, el comportamiento de apagado de los auriculares, el Bluetooth y el modo de datos por cable USB no se han probado en hardware. No se afirma compatibilidad para esos modos. No se incluyen actualizaciones de firmware, cambios de configuración, comandos de ecualización, cambios de emparejamiento, reinicios ni binarios del fabricante en esta implementación.

Prueba: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Sección:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [Original en inglés](../../docs/hyperx_haste_2.md) · [↑ Arriba](#top)

# Protocolo de batería de HyperX Pulsefire Haste 2 Wireless

Leído por `HasteWireless` en `src/drivers/hyperx.cpp`. Las consultas proceden de [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) y son las mismas que utiliza NGENUITY.

Verificado en hardware:

- Pulsefire Haste 2 Core Wireless, receptor `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, receptor `03F0:0F98`, por uzumakiprime (PR #312). El nivel coincidió con HyperX NGENUITY.

Se espera que el receptor `03F0:0D97` funcione igual, pero está sin probar.

## Colección HID

| Campo | Valor (`0F98`) |
|---|---|
| Interfaz USB | `MI_02` (interfaz 2) |
| Página de uso : uso | `FF00:0001` |
| Longitud de informe entrada / salida / característica | 64 / 64 / 64 bytes |

El receptor también expone las colecciones estándar de ratón y control de consumo. El controlador solo abre una colección del fabricante (página de uso `FF00` o superior) con informes de entrada de al menos 8 bytes.

## Consultas

Ambas son informes de salida: los dos primeros bytes indicados abajo, rellenados con ceros hasta la longitud del informe. Cada respuesta es un informe de entrada cuyo primer byte es el comando más uno. Cada consulta espera como máximo un segundo su respuesta y descarta informes no relacionados (tras una reconexión el receptor envía informes `44 xx`, `45 xx` y `FB xx` por su cuenta).

| Petición | Respuesta | Significado |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0 cuando el ratón está apagado o fuera de alcance |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100; `charge` 1 = cargando, 2 = carga completa en el cargador; voltaje en mV, little endian (0 en el Core) |

- Si falta la respuesta de enlace, decide la respuesta de batería.
- Si el enlace informa 0, no se envía consulta de batería y el ratón se muestra como apagado.
- Durante unos segundos tras encender el ratón, informa alrededor de un 40%. Cualquier lectura dentro de los 6 s posteriores a levantarse el enlace se ignora, y la bandeja conserva el último valor.

Ambas peticiones solo leen estado. Nada cambia ajustes, iluminación ni modos.


---

<a id="sec-inphic"></a>
> 📄 **Sección:** Inphic IN10 (`docs/inphic.md`) · [Original en inglés](../../docs/inphic.md) · [↑ Arriba](#top)

# Familia Inphic IN10, receptor KP 8K

El dispositivo conectado, identificado por su propietario como IN10 MAX, se enumera como `Inphic KP 8K`, `1D57:FA65`, versión `0116`. Su colección de estado es la interfaz 2, uso `000A:0000`, longitud de entrada 5 (incluido el ID de informe 03).

Observado aproximadamente cada cuatro segundos, sin enviar ninguna petición:

```text
03 73 41 01 64
```

El analizador Xenta existente reconoce este formato: modelo, evento, estado de batería y porcentaje. Se requieren dos informes iguales antes de mostrar 100%; el primer informe tras enlazar puede ser una lectura engañosa de carga completa en receptores relacionados. Este cambio conserva esa salvaguarda y el comportamiento existente de carga/reposo.

El paquete oficial de [Inphic HUB](https://hub.inphic.cn/) `assets/index-BcHQx9B6.js` asigna el modelo decimal 115 (`73`) a `IN10RMax`, y 116 (`74`) a `IN10Max`. Usa el estado de batería 1 para porcentaje, 2 para carga completa y 3 para cargando. Usa el nombre de modelo del firmware en lugar de asignar `73` a IN10 MAX y etiquetar erróneamente otros dispositivos que comparten este receptor.

Antes de este cambio la aplicación listaba el ratón conectado como `Wireless mouse`. El transporte Xenta ya manejaba sus tramas de batería; el cambio aporta los nombres de modelo faltantes. Un `--list` recién ejecutado puede mostrar «en reposo» porque su observación inicial de cinco segundos puede recibir solo un informe de cada cuatro segundos. La aplicación residente mantiene el oyente y confirma el valor en un sondeo posterior.

Verificado en hardware: informes pasivos, nivel repetido del 100% e identificación del modelo por el controlador nativo. No se han verificado las transiciones de carga, los límites de batería baja, el Bluetooth ni el modo por cable. El modelo `74` procede de la tabla oficial y no se ha probado en otro hardware aparte.


---

<a id="sec-machenike"></a>
> 📄 **Sección:** Machenike L7 (`docs/machenike.md`) · [Original en inglés](../../docs/machenike.md) · [↑ Arriba](#top)

# Machenike L7 Arctic / L7 Mix

Verificado en un L7 Arctic que se identifica como **L7 Mix**:

| Conexión | VID:PID | Interfaz | Uso | Entrada / salida / característica máx. |
| --- | --- | --- | --- | --- |
| Receptor de 2.4 GHz | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| Cable USB | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

El controlador también comprueba el nombre de producto HID `L7 Mix`. Otros modelos Machenike, otros IDs de receptor y las consultas del fabricante por Bluetooth no están habilitados.

## Fuente del protocolo

Análisis de interoperabilidad del software oficial **Machenike L7 Mix 1.0.0.8**, disponible en la [página de controladores del fabricante](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/), y consultas de solo lectura en el ratón real. SHA-256 de `DeviceDriver.exe`: `A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

En ese ejecutable de 32 bits (base de imagen `00400000`), la función en VA `00436750` construye la petición de estado; `004494F0` la envía mediante `HidD_SetFeature` y lee la respuesta de característica. El analizador de estado `00410C20` extrae los campos siguientes y pasa los campos de batería y carga a la interfaz. Estas son direcciones virtuales, no desplazamientos de archivo. No se incluye aquí ningún ejecutable, código de aplicación ni recursos propietarios.

## Consulta de lectura de estado

Envía **21 bytes**, ID de informe `51`, comando `06`, todos los demás bytes a cero:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Lee el informe de características `51`, usando también 21 bytes. El tamaño máximo de característica de la colección es 1001 para otros informes; no es la longitud del informe de estado. El controlador espera 10 ms antes de leer y usa un único plazo límite de 200 ms por producto, incluyendo respuestas no relacionadas. No envía comandos de ajustes, modo, macros ni firmware.

Los índices incluyen el ID de informe:

| Bytes | Significado / valores observados |
| --- | --- |
| 0–1 | `51 06`, eco de comando obligatorio |
| 4–7 | `8A 24 4E FF`, firma verificada del dispositivo L7 |
| 10, bits 0–2 | Modo de trabajo: 1 en receptor, 0 en cable |
| 10, bit 3 | Ratón inalámbrico conectado; en cero también por cable USB |
| 11 | Porcentaje de batería, 0–100 (cero es válido) |
| 12 | Indicador de carga: 0 descargando, 1 cargando |

Otros campos y la semántica de suma de comprobación no están establecidos. El controlador no inventa ninguna suma de comprobación. Valida el comando, la longitud, la firma del dispositivo, el modo y los rangos de batería/carga en estado conectado antes de publicar una lectura.

Respuesta capturada del receptor, también 64% en la aplicación oficial:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Respuesta capturada por cable USB mientras cargaba (74%):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

En ese momento el receptor seguía devolviendo su 64% en caché, pero con su bit de enlace despejado:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Esta lectura desconectada no debe exponer valores de batería/carga en caché. El cable tiene prioridad cuando ambos transportes están presentes, y la clave estable del dispositivo se comparte entre transportes. Un L7 conocido queda reservado incluso si la consulta falla para que el controlador posterior de Ajazz no pueda sondearlo con un protocolo distinto sobre el VID compartido.

## Límites de validación

Las pruebas con capturas fijas y transporte simulado cubren lecturas capturadas, carga, valores válidos 0%/100%, receptores desconectados, respuestas malformadas/antiguas, coincidencia estricta, fallos de transporte, supresión de duplicados y bucles de reintento acotados. Esas pruebas no implican validación en vivo de 0%/100% ni de todas las variantes de reposo/firmware.


---

<a id="sec-nuphy"></a>
> 📄 **Sección:** NuPhy WH80 (`docs/nuphy.md`) · [Original en inglés](../../docs/nuphy.md) · [↑ Arriba](#top)

# NuPhy WH80 (cable USB y Bluetooth)

Probado en hardware con `19F5:A011`, versión de firmware `0116`, interfaz 1, uso `0001:0000`, cargas útiles de entrada/salida de 64 bytes sin numerar (65 bytes en las capacidades HID de Windows).

Fuente del protocolo: [NuPhyIO](https://drive.nuphy.io/), paquete `main.b3fb29e0.js`, funciones del SDK `getBatteryState(0)`, `getDataPackage` y `createCommand`. Solo se solicita `GetFunc` (`05`), desplazamiento `0020`, longitud `01`. No se necesitan comandos de inicialización, configuración, iluminación ni firmware.

Carga útil de petición, rellenada con ceros hasta 64 bytes:

```text
55 05 00 21 01 20 00 00
```

Carga útil de respuesta real:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

El byte 3 es el byte bajo de la suma de los bytes 4..63. La batería es el byte 8: `value & 7F` es el porcentaje, `value & 80` es el indicador de carga del SDK. El controlador nativo en C++ devolvió **100%, cargando** en el teclado conectado. Las transiciones de carga y los límites bajo/completo no se han probado en hardware; las notas oficiales del firmware describen las lecturas del WH80 en incrementos del 10%. El funcionamiento a través del receptor queda fuera del alcance de este controlador.

## Bluetooth

Por Bluetooth el mismo teclado usa el ID HID `19F5:324A` (versión `0129`) y anuncia un nombre visible para el usuario como `NuPhy WH80 - 1`. Expone dos colecciones de teclado y una colección de ratón. La heurística HID genérica da prioridad a los ratones, por lo que hay que añadir este ID Bluetooth exacto a las anulaciones de teclado existentes.

El informe de batería sigue usando la propiedad de batería Bluetooth de Windows. Tras desconectar el USB, Windows informó **95%** en el teclado conectado. Una lectura sin caché del Battery Level GATT estándar (`180F` / `2A19`) también devolvió **95%** directamente desde el teclado. Esta es una lectura de dispositivo/transporte distinta de la observación de 100% por cable; no debe sustituirse por un valor asumido de carga completa ni reescalarse. No se ha determinado el motivo de la diferencia entre las lecturas del firmware.

El controlador verifica el producto, la interfaz y los tamaños de informe exactos, la cabecera de respuesta, el desplazamiento, la longitud, la suma de comprobación y el rango porcentual. Usa un plazo límite de respuesta de 400 ms e ignora respuestas no relacionadas dentro de ese mismo plazo.

Prueba de regresión:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Sección:** Rapoo (`docs/rapoo.md`) · [Original en inglés](../../docs/rapoo.md) · [↑ Arriba](#top)

# Soporte de batería para ratones Rapoo

## Por qué el programa original no detectaba el ratón

`PollAllDevices()` enumera las colecciones HID de nivel superior de Windows una vez por actualización. Cada controlador de fabricante reconoce un protocolo, añade un `DeviceStatus` y reclama su VID/PID para que los controladores genéricos no lo añadan de nuevo. La interfaz de usuario ya maneja el porcentaje, el estado de carga y la última lectura durante el reposo.

No existía un controlador de Rapoo. El VT3 Max Gen 2 envía su batería en un informe de entrada definido por el fabricante, no mediante el uso HID estándar *Battery Strength* ni mediante una propiedad de batería Bluetooth de Windows. Por lo tanto, los respaldos genéricos HID/Bluetooth existentes no pueden decodificar su receptor USB.

## Hardware y paquetes observados

Probado en Windows con el VT3 Max Gen 2 del propietario el 2026-11-16:

| Conexión | VID:PID | Interfaz | Página de uso:uso | Tamaño entrada / salida |
|---|---|---|---|---|
| Receptor de 2.4 GHz | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 bytes |
| Cable USB | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 bytes |

Ambos se identifican como `Rapoo Gaming Device`. Las demás colecciones incluyen entradas estándar de ratón, teclado y multimedia, colecciones de configuración del fabricante y una interfaz de firmware de 513 bytes. El controlador de batería solo abre `FF00:0002` con un tamaño de entrada reconocido. Nunca abre la interfaz de firmware y nunca envía un informe de salida, informe de características, apretón de manos ni comando de configuración.

Informe inalámbrico capturado, incluyendo el ID de informe:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Informe por cable/cargando capturado:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Los desplazamientos siguientes cuentan el ID de informe como byte cero, coincidiendo con `HidDev::Read()` de este proyecto:

| Byte(s) | Significado | Ejemplo |
|---|---|---|
| 0 | ID de informe | `07` |
| 1 nibble bajo | Conexión: 0 receptor, 1 Bluetooth, 2 cable | `20` / `22` |
| 1 nibble alto | Información del sensor; no forma parte del tipo de conexión | `2` |
| 2 | Nivel actual de DPI | `03` |
| 3–4, 5–6 | DPI X/Y, little endian | `0320` = 800 |
| 7 | Estado de batería: 0 no válido, 1 descargando, 2 cargando | `01` / `02` |
| 8 | Porcentaje de batería, 0–100 | `19` = 25% |
| 13–14 | ID de producto del ratón, little endian, cuando está presente | `4617` |

La captura en vivo del receptor informó `25%`, y la aplicación completa devolvió posteriormente `27%, charging` por el cable. La prueba del analizador incluye la captura inalámbrica real. La carga y la conectividad por cable también se verificaron frente a hardware real; no se deducen simplemente de que haya un dispositivo USB presente. Después de que el propietario desconectara el cable y reconectara el receptor, el ejecutable final devolvió `52%` por `2.4 GHz receiver`, sin el indicador de carga, y conservó la misma clave `rapoo:4617`. Esto también verifica la transición de cable a receptor en hardware real.

También probado en Windows con un **VT9 Gen 2** el 2026-11-17:

| Conexión | VID:PID | Interfaz | Página de uso:uso | Tamaño entrada / salida |
|---|---|---|---|---|
| Receptor de 2.4 GHz | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 bytes |
| Cable USB | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 bytes |

El receptor del VT9 Gen 2 expone un informe `FF00:0002` de **16 bytes** en lugar de 19 bytes, utilizando exactamente la misma estructura `07` de Nordic 54L (incluido el PID `4614` incrustado en los bytes 13–14). Tramas capturadas:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receptor: 100%, descargando
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # cable USB (interruptor ON): 100%, cargando
```

Por cable USB se observaron informes de estado al interactuar (p. ej. cambio de DPI); con el interruptor de encendido inferior apagado (OFF) mientras estaba enchufado, el ratón informó `state=2, percent=1` en lugar del porcentaje real de batería.

### Receptor VT3 Max Gen 2 con una colección de 13 bytes (issue #1396)

Un informe del formulario de solicitud de dispositivo para el mismo ID de receptor `24AE:1417` listaba una disposición de interfaces distinta: `FF00:0002` con **13 / 13** bytes (en lugar de 19) y `FF00:000E` con 33 / 33 bytes, sin colección de firmware de 513 bytes. Esto parece corresponder a otra revisión de firmware del receptor. El software de Rapoo seguía mostrando la batería, por lo que el controlador ignoraba un canal de estado funcional.

El decodificador `VT_nrf54L` (`py`) de Rapoo Hub es adaptable a la longitud: siempre lee los DPI, el estado de la batería y el porcentaje, y lee los campos posteriores (PID del ratón en `n[12..13]`, información RF, ...) únicamente cuando el informe es lo bastante largo. El manifiesto de VT3 MAX (`productId: [17943, 5143]`) no tiene ningún tipo especial de informe de entrada, por lo que el informe `07` también pasa por ese decodificador en este receptor. Un informe de 13 bytes (ID más 12 bytes) sigue llevando el estado en el byte 7 y el porcentaje en el byte 8; únicamente falta el PID incrustado del ratón, por lo que la lectura usa el PID del receptor y conserva la clave `rapoo:4617`.

La longitud de 13 bytes se acepta **solo para `24AE:1417`**. Las tramas deben seguir pasando las mismas comprobaciones (informe `07`, nibble de conexión 0–2, estado 1/2, porcentaje 0–100). Todavía no se ha capturado ninguna trama real de 13 bytes; las pruebas utilizan la captura probada de 19 bytes recortada a 13 bytes.

## Otros ratones Rapoo

El Rapoo Hub oficial utiliza esta estructura `07` para su controlador de ratones Nordic 54L. Sus manifiestos enumeran VT0, VT1, VT2, VT3, VT3S, VT7, VT9 y variantes adicionales. La inspección del paquete actual identificó 69 variantes VT que usan `VT_nrf54L`; esto evidencia un protocolo compartido, no 69 validaciones en hardware ni una afirmación de cubrir la mayor parte del catálogo completo de Rapoo. El soporte se selecciona por el VID de Rapoo, la colección dedicada, la longitud de entrada y un informe de estado válido, por lo que un modelo no listado con el mismo protocolo puede seguir informando de su batería. Una pequeña tabla de nombres cubre modelos comunes; otros conservan su nombre de producto HID o muestran `Rapoo wireless mouse`.

Los nombres de producto y los IDs varían entre generaciones y regiones. El par probado `1417/4617` se llama `VT3 MAX` en el manifiesto oficial actual; el propietario lo identifica como VT3 Max Gen 2. El `VT3 MAX V2` independiente del manifiesto actual tiene los IDs `1B06/4B06`. Las tablas comunitarias que asignan `1417` al VT9 Pro no deben utilizarse como única base para nombrar o detectar este dispositivo.

El firmware VT anterior, documentado para el VT3 Pro (`1215/4415`), envía en su lugar de forma pasiva un informe de 7 bytes en el mismo uso `FF00:0002`:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

Para este formato antiguo, los estados 1/2 significan descargando/cargando. Un porcentaje de carga de `7F` significa desconocido y se conserva como desconocido. El estado de transición 0, los informes `BC` no relacionados, los paquetes malformados y los porcentajes superiores a 100 se descartan. El soporte antiguo tiene cobertura automatizada, pero no se ha verificado aquí con un ratón físico antiguo. Esta interpretación está restringida a los IDs de producto `1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) y su colección de entrada de 7 bytes.

El VT1 Pro Max (receptor `24AE:1233`, cable `24AE:4433`, firmware del ratón 222, firmware del receptor 213) se añadió a partir de capturas USBPcap que su propietario adjuntó al issue #136. La salida de `--dump` lista la colección de 7 bytes `FF00:0002` en la interfaz 1, y las capturas muestran que la envía de forma pasiva sin petición de la aplicación Rapoo:

```text
BB B0 71 84 03 01 64   receptor, cada ~3.2 s; la app Rapoo mostraba 100%
BB B0 71 84 03 02 5F   cable, cargando, 95%; la app Rapoo mostraba "Charging"
```

Por cable el informe se vio solo una vez en una captura de 16 segundos, por lo que una lectura únicamente por cable puede agotar el tiempo de espera en algunas actualizaciones; el receptor lo envía de forma regular. El perfil Nordic nunca interpreta paquetes `BB`.

Esto **no** garantiza soporte para todos los dispositivos Rapoo. Los modelos CH584 como VT1 SE y VT7 SE usan el informe `08` en el controlador oficial y no son compatibles con este decodificador. Otras revisiones Telink usan una interpretación diferente de los indicadores `BB`, algunos modelos de oficina usan consultas activas de batería y los modelos Bluetooth pueden exponer únicamente la propiedad de batería de Windows. Estos permanecen en los respaldos existentes o requieren una implementación verificada aparte. No envíes consultas adivinadas a esos dispositivos.

## Sondeo e identidad

- La lectura es pasiva. Los manejadores `FF00:0002` coincidentes permanecen abiertos entre sondeos (igual que `PollXenta`) para que Windows almacene en búfer las tramas de estado que llegan durante el intervalo de actualización de 60 segundos; cada sondeo vacía las tramas en cola (conservando la lectura de batería válida más reciente) antes de recurrir a una espera de 5 segundos al abrir por primera vez o si la cola está vacía. Los dispositivos desenchufados se eliminan y sus manejadores se cierran. Los paquetes no relacionados no reinician el plazo límite.
- El PID incrustado del ratón, o un par cable/receptor conocido para dispositivos antiguos, proporciona la misma clave de interfaz entre cambios de cable. Las lecturas por cable y receptor se fusionan en una sola entrada, dando preferencia al estado del cable y conservando un porcentaje válido del receptor si el cable informa de un nivel desconocido.
- Un tiempo de espera agotado no inventa ningún porcentaje ni reclama el dispositivo. Tras una lectura exitosa, la interfaz existente puede conservar esa lectura, atenuada, durante 30 minutos de silencio.
- El modelo de identidad existente del programa basado en VID/PID no puede distinguir varios ratones idénticos con el mismo ID de modelo. No se probó el funcionamiento físico simultáneo de cable y receptor; la fusión de ambas entradas está cubierta por la prueba de transporte simulado.

## Validación

`make test` ejecuta una prueba portátil del decodificador y una prueba del controlador de Windows con respuestas HID simuladas. La cobertura incluye la captura real, 0% y 100%, carga, niveles ausentes, tramas no válidas o truncadas, colecciones/fabricantes no compatibles, aislamiento de perfiles de protocolo, tiempos de espera agotados, claves estables y deduplicación entre cable y receptor sin descartar un porcentaje conocido.

La aplicación completa se compiló localmente con MSVC C++17 y el SDK de Windows, y se ejecutaron `--list` / `--dump` frente al ratón real. La compilación mantenida de MinGW incluye `rapoo.cpp` en `build.bat`; el Makefile lo detecta automáticamente. MinGW en sí no estaba instalado en el entorno de pruebas.

## Fuentes del protocolo

- [Rapoo Hub oficial](https://hub.rapoo.cn/), inspeccionado el 2026-11-16: [controlador JavaScript y manifiestos incluidos](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js). Los decodificadores relevantes son `py`/`Hk` para `VT_nrf54L` y `qM`/`QM` para los significados de conexión y estado de batería. El manejador independiente `VT_CH584` consume el informe `08` y queda fuera de esta implementación. Los nombres minificados pueden cambiar en futuras versiones.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs), para los informes antiguos del VT3 Pro, estado de carga y el valor centinela de nivel desconocido.
- Capturas USBPcap del issue #136 (VT1 Pro Max en receptor y por cable mientras cargaba).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js) corrobora de forma independiente las difusiones de estado pasivas `07` y el desplazamiento de la batería. Su analizador recorta porcentajes no válidos; esta implementación los rechaza en su lugar.


---

<a id="sec-rawm"></a>
> 📄 **Sección:** RAWM (`docs/rawm.md`) · [Original en inglés](../../docs/rawm.md) · [↑ Arriba](#top)

# Notas sobre el protocolo RAWM

Los ratones RAWM (y el SADES Dagger, que comparte la plataforma) se comunican con la aplicación RAWM HUB a través de una colección HID del fabricante, `FF00:0001`, con informes de entrada y salida de 64 bytes sin numerar (65 bytes con el ID de informe). Los receptores y ratones utilizan el ID de proveedor de Nordic `1915`.

Fuente: la aplicación web RAWM HUB, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), y su script `https://hub.miracletek.net/hub/js/library.min.js` (ofuscado; los nombres de funciones y constantes indicados abajo son los del propio script). Los IDs de producto compatibles proceden de la tabla de dispositivos que descarga la aplicación (`https://www.miracletek.net/game/device.php`). Leviathan V4 GT y NYX60 usan Hub Web 3.0 en el VID `373E`, que es un protocolo distinto.

## Paquetes

Byte 0 de cada informe (después del ID de informe):

| Bits superiores | Significado |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | los 6 bits inferiores son un tamaño de carga útil; la carga útil continúa el flujo de eventos |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | control de flujo (tamaños de búfer libre); se ignora aquí |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | los 6 bits inferiores son un canal ESB; el resto del informe es un paquete para ese canal. El ratón detrás de un receptor es el canal 0 |

Las cargas útiles forman un flujo de bytes de eventos:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## Lectura de la batería

El controlador repite lo que hace la aplicación cuando se conecta un receptor (`send_event_query`, `send_event_ping`):

1. Al receptor: `00 8D 01 0D 03 00 00 <hora unix, 8 bytes LE>` (`CMD_QUERY`, OS = PC), seguido de pings `00 84 0E 04 00 00`. El dispositivo solo envía mientras el host sigue escribiendo, por lo que el host envía pings. El receptor responde `CMD_QUERY_RESULT` (`02`) con JSON, p. ej. `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. La misma consulta y pings para el canal 0, prefijados con `C0`. El ratón responde con un objeto JSON de ~550 bytes en fragmentos ESB de 30 bytes, p. ej. `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`. `battery` es un porcentaje (RAWM HUB lo muestra tal cual) y `chr` vale 1 mientras está cargando.
3. Los cambios posteriores llegan como `CMD_NOTIFY` (`0B`) tipo `17`: `[17, percent, charging]`.

El controlador siempre pregunta primero al receptor, tal como hace la aplicación (en una prueba, una consulta enviada únicamente al canal 0 no recibió respuesta). Un ratón en reposo no responde en absoluto; el receptor sí lo hace.

La consulta transporta el reloj del PC porque la aplicación la envía así; no se escribe nada más. Los ratones informan `"crc":1`, lo que indica a la aplicación que envuelva comandos posteriores (configuración) en una trama CRC-16; la consulta y los pings se aceptan sin ella, ya que la aplicación los envía antes de saberlo.

Probado en un Leviathan V4 (firmware 1.2.0) con el receptor RAWM HS Receiver `1915:2346` (firmware 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **Sección:** VAXEE (`docs/vaxee.md`) · [Original en inglés](../../docs/vaxee.md) · [↑ Arriba](#top)

# Receptores VAXEE 4K/8K y ZYGEN NP-01S V2

## Alcance y validación en hardware

Este controlador admite el receptor VAXEE 4K `3057:1002`, el receptor VAXEE 8K `3057:2002` y el ZYGEN NP-01S V2 Wireless por cable USB (`3057:1011`), en su colección del fabricante `FF05:0001` con un informe de características de 64 bytes. Otros receptores VAXEE, otros IDs de producto por cable y los dispositivos ZOWIE no se sondean intencionadamente.

El receptor 8K (`VAXEE 8K Wireless`, emparejado con un NP-01 Ergo Wireless 8K) se probó en Windows e informó a través del mismo protocolo:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

El receptor es compartido por todos los ratones VAXEE 8K y no informa qué modelo está emparejado, por lo que se muestra con su propio nombre. El estado de carga en el receptor 8K aún no se ha observado en hardware.

Se probó un receptor 4K real en Windows:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

La aplicación integrada también informó:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

A continuación se conectó el mismo ratón directamente por USB y Windows lo identificó como `ZYGEN NP-01S V2 Wireless` (`3057:1011`). El controlador de producción actualizado informó:

```
VAXEE battery: 75%; charging: yes
```

El widget de la barra de tareas se creó correctamente en la compilación inicial para el receptor. Se han observado tanto el funcionamiento con batería a través del receptor como la carga por cable; las transiciones de carga completa y el comportamiento en reposo/apagado no se han probado en hardware. La decodificación de carga y las respuestas no válidas están cubiertas mediante respuestas simuladas.

## Protocolo

Fuente: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

Una petición es un informe de características HID de 64 bytes rellenado con ceros:

| Byte | Valor |
|---|---|
| 0 | `0E`, ID de informe |
| 1 | `A5`, cabecera |
| 2 | `0B` para nivel de batería; `10` para estado de carga |
| 3 | `01`, indicador de lectura (nunca `02`, escritura) |
| 4 | `01`, longitud de datos |
| 5–63 | `00` |

Tras enviar la petición con `HidD_SetFeature`, espera 100 ms y lee el informe `0E` con `HidD_GetFeature`. Exige al menos seis bytes y el ID de informe, cabecera, eco de comando y longitud de datos esperados.

Para la batería, el byte 5 de la respuesta debe estar entre 0 y 20 y se multiplica por cinco, dando 0–100% en pasos del 5%. Para la carga, el byte 5 es distinto de cero cuando está cargando. Una consulta de carga fallida no descarta una lectura de batería por lo demás válida.

El controlador reintenta la petición de batería una vez. Hay como máximo tres peticiones de lectura por colección coincidente (dos intentos de batería y una consulta de carga), con un retardo explícito total de 300 ms. No envía comandos de ajustes, emparejamiento, firmware ni iluminación.

Si no se recibe ninguna respuesta válida de batería, el controlador no informa nada y deja el dispositivo sin reclamar. Mientras la colección USB siga presente, la interfaz conserva una lectura válida previa, atenuada, hasta 30 minutos usando su comportamiento existente de período de gracia. Si la colección física desaparece, el controlador emite un estado de desconexión para finalizar ese período de gracia de inmediato. Esto evita que un icono antiguo del receptor permanezca cuando el cable se traslada al ratón.

## Pruebas

`make test` incluye `tests/vaxee_driver_test.cpp`, que enlaza el controlador de producción con un transporte HID simulado. Comprueba las peticiones exactas de solo lectura enviadas, la conversión de porcentaje, la decodificación de carga, respuestas no válidas o ausentes, dispositivos ya reclamados y el filtrado exacto de colecciones.
