<!--
  Documentação completa do BatteryHub em arquivo único (Português (Brasil) / pt-BR)
  Traduzido a partir de docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Idiomas:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | **Português (Brasil)** | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Adicionar idioma](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Documentação Completa

> Este arquivo Markdown independente reúne todos os documentos visíveis do repositório para que os tradutores precisem manter apenas **um arquivo por idioma**.

## Índice

1. [Visão geral do BatteryHub, Dispositivos suportados, Instalação, CLI e Compilação (`README.md`)](#sec-readme)
2. [Guia de contribuição (`CONTRIBUTING.md`)](#sec-contributing)
3. [Modelo de Pull Request (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Guia de lançamento e assinatura (`docs/releasing.md`)](#sec-releasing)
5. [Patch de firmware 2.4 GHz para teclados Keychron (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [Suporte BLE ao GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Uso em vários idiomas e guia de localização (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Receptor Areson 25A7 (`docs/areson.md`)](#sec-areson)
10. [Receptor DARKRIM SHADOW (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Inphic IN10 / Receptor KP 8K (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Suporte à bateria de mouses Rapoo (`docs/rapoo.md`)](#sec-rapoo)
16. [Notas de protocolo RAWM (`docs/rawm.md`)](#sec-rawm)
17. [Receptores VAXEE 4K/8K (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Seção:** Visão geral do BatteryHub (`README.md`) · [Original em inglês](../../README.md) · [↑ Topo](#top)

# BatteryHub

*Anteriormente **Wireless Battery**. A versão 1.1.0 renomeou o aplicativo; a atualização mantém suas configurações, a opção de inicialização e o histórico da bateria.*

[![Apoie no Ko-fi](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Doar com PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![Patrocinar no GitHub](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Entrar no Discord](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Dar estrela no GitHub](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Compartilhar no Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Informar um dispositivo](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Ajudar a traduzir](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Níveis de bateria do seu mouse, headset, teclado e controle sem fio, direto na barra de tarefas do Windows.

![BatteryHub na barra de tarefas](../screenshot.png)

> **Só quer que funcione?** Baixe o **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** na versão mais recente, execute e avance pela instalação. Só isso.
>
> **Usuários avançados** podem baixar o zip portátil, usar as [opções de linha de comando](#linha-de-comando) ou [compilar a partir do código-fonte](#compilação) com `make` ou `build.bat`.
>
> **Gostou?** O BatteryHub é gratuito e de código aberto. Se ele poupou você de abrir o software do fabricante, você pode apoiá-lo no [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) ou [GitHub Sponsors](https://github.com/sponsors/krisgfx9). Isso me ajuda a manter meus aplicativos gratuitos enquanto concilio com os estudos. Não pode doar? Uma ⭐ estrela, compartilhar o projeto ou informar um dispositivo ainda não suportado com `--dump` ajuda igualmente.

- **Minúsculo**: um aplicativo de ~350 KB que usa cerca de 2 MB de RAM. É C++/Win32 puro, sem runtime e sem serviço em segundo plano, e instala em segundos sem privilégios de administrador.
- **Sem precisar do software do fabricante**: conversa diretamente com os dispositivos. G HUB, Synapse, iCUE, GG e NGenuity podem ficar fechados (ou continuar abertos; não há conflito).
- **Muitas marcas**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, controles de PlayStation e Xbox, Samsung Galaxy Buds, qualquer dispositivo Bluetooth cujo nível de bateria o Windows conheça e todo headset suportado pelo [HeadsetControl](https://github.com/Sapd/HeadsetControl) incluído no pacote.

## Exibição

**Na barra de tarefas (padrão):** `🎧 30%  🖱 93%` ao lado da área de notificação, desenhado com a fonte de ícones do Windows.
- **Bateria fraca:** um número em vermelho indica 15% ou menos.
- **Carregando:** um ⚡ azul aparece ao lado do número. Quando o dispositivo estiver totalmente carregado e ainda conectado à energia, ele vira um ✓ verde.
- **Em repouso:** texto esmaecido significa que o dispositivo está em repouso e o último valor conhecido está sendo exibido.
- **Desconectado (opcional):** ative *Mostrar dispositivos desconectados* para exibir um `×` esmaecido para dispositivos cujo driver informa explicitamente um link sem fio offline. Isso não infere desconexão a partir de uma consulta de bateria perdida; o padrão continua sendo ocultar dispositivos offline.
- **Dois dispositivos do mesmo tipo:** com dois mouses (ou dois controles...), ambos teriam o mesmo ícone, então cada um recebe uma pequena legenda de até 3 letras no canto do ícone, retirada do nome (`MX`, `PRO`), ou um número quando os nomes não os diferenciam. Um dispositivo único do seu tipo não exibe legenda.
- **Tema:** segue o modo claro/escuro e a escala de DPI.
- **Temas de barra de tarefas transparente** (por exemplo, Taskbar Styler do Windhawk): ative *Fundo atrás do texto da barra de tarefas* no menu para manter o texto legível sobre o papel de parede.
- **Vários monitores:** o widget aparece na barra de tarefas de cada monitor, ao lado do relógio, permanecendo visível enquanto um jogo roda em tela cheia. *Mostrar o widget em* no menu escolhe *Todos os monitores*, *Somente o monitor principal* ou um único monitor (por exemplo, *Somente Monitor 3*).
- **Mais opções de exibição:** *Ícones acima das porcentagens* empilha cada ícone sobre seu nível para economizar largura; *Cores das marcas* exibe marcas conhecidas em suas cores (verde Razer, vermelho HyperX, ...) com uma pequena barra de nível; dois dispositivos do mesmo tipo recebem uma pequena legenda para diferenciação; barras de tarefas laterais (esquerda/direita) exibem uma coluna de dispositivos.
- **Idiomas:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 e 繁體中文. Tanto o app do Windows quanto o do Linux seguem o idioma de exibição do sistema; *Idioma* no menu escolhe outro, e o instalador do Windows também oferece suporte a todos os 19 idiomas. As frases da interface ficam em arquivos estáticos editáveis `lang/*.json`, e a documentação traduzida completa fica em [`docs/i18n/`](README.md). Veja [Traduções](#traduções) para editar ou adicionar um idioma.
- **Cores das marcas:** dispositivos de 15 marcas conhecidas recebem a cor do fabricante, com um brilho suave e uma barra fina de nível abaixo da
  porcentagem: verde Razer, azul Logitech, laranja SteelSeries, amarelo Corsair, vermelho HyperX / ROG / ZOWIE, PlayStation,
  Xbox, Samsung, Apple, Jabra, JBL, Cooler Master e Steam. Cada cor tem uma tonalidade para barra escura e outra para barra clara. A marca
  vem do driver que detectou o dispositivo, depois do vendor ID e depois do nome; cores e regras estão em
  `src/brands.cpp`. Desative com *Cores das marcas* no menu.

**Ícones na bandeja:** um ícone por dispositivo com o número desenhado dentro dele, além de uma notificação de "Bateria fraca" em 15%. O aplicativo muda para este modo automaticamente quando a barra de tarefas é vertical ou não pode ser encontrada.

**Nomes personalizados de dispositivos:** abra o submenu do dispositivo e selecione *Renomear dispositivo...* para definir um nome
(até 64 caracteres). O nome é exibido na dica/legenda do widget da barra de tarefas,
na dica e notificações da bandeja e no menu do dispositivo. Use *Restaurar nome original*
para restaurar o nome do driver. Os nomes são salvos localmente no Registro do Windows do usuário atual
(`Software\WirelessBattery`, `DeviceAliases`), usando a chave estável
do dispositivo. Renomear nunca altera a correspondência de drivers, consultas de protocolo ou a saída de diagnóstico de `--list` /
`--dump`. Não requer conta nem acesso à rede.

Passe o mouse para ver detalhes. Clique para abrir o menu: cada dispositivo (clique em um para ocultar ou exibir), modo de exibição, *Atualizar agora*, *Iniciar com o Windows* e *Sair*. Os níveis são atualizados a cada 60 segundos (*Verificar bateria a cada* no menu altera isso), e imediatamente quando um dispositivo é conectado ou o PC sai da suspensão.

## Alertas inteligentes de bateria (experimental)

Você pode definir um **limite de notificação de bateria fraca por dispositivo** no submenu de cada dispositivo:
**Alertas de bateria** → *Usar padrão (15%)*, *Desativar notificações*,
ou um valor entre 5%, 10%, 15%, 20%, 25%, 30%, 35% e 40%. O padrão existente de 15% permanece
inalterado, a menos que você escolha um valor específico. As configurações são salvas por chave de dispositivo no
Registro do Windows do usuário atual (`Software\WirelessBattery`, `AlertThresholds`).

Um alerta é disparado apenas a partir de uma leitura real e recente de 0–100% quando o
dispositivo está conectado, ativo e não está carregando. O alerta é emitido uma única vez e será
rearmado depois que o nível subir mais de 10 pontos percentuais acima do limite escolhido
(ou quando o carregamento começar). Leituras ausentes ou dispositivos em repouso não
disparam alertas novamente. Dispositivos ocultos não geram notificações. Desativar as
notificações para um dispositivo não o oculta nem altera sua porcentagem.

Tanto o modo widget na barra de tarefas quanto o modo de ícones na bandeja oferecem suporte a notificações. Como o Windows
precisa de um ícone na área de notificação para exibir um balão legado, o modo widget pode
exibir um ícone de notificação temporário por até um minuto após um alerta.
As cores do widget e o destaque de bateria fraca continuam usando o limite
global original de 15% do projeto, independentemente da configuração de notificação.

## Histórico da bateria e estatísticas

Clique com o botão direito em um dispositivo no widget da barra de tarefas ou no menu da bandeja e escolha **Histórico da bateria...**.
O visualizador nativo, compatível com DPI (e que segue o tema claro/escuro do Windows), mostra os níveis de bateria registrados com linhas conectando as amostras nas últimas **24 horas**, **7 dias** ou **30 dias**, junto com a leitura mais recente, o nível mínimo/máximo, a variação em pontos percentuais e a contagem de amostras. Você pode limpar o histórico do dispositivo selecionado no próprio visualizador.

O histórico é gravado **apenas localmente** para dispositivos conectados e ativos que reportam uma porcentagem numérica. As leituras são amostradas no máximo uma vez a cada 30 minutos por dispositivo (exceto em transições de estado de carregamento, com mínimo de 60 segundos). Os dados são mantidos por até 30 dias e o arquivo local fica abaixo de cerca de 2 MB. O aplicativo nunca sonda o hardware além de suas consultas existentes, não envia dados de histórico pela rede e faz uma estimativa conservadora e aproximada de tempo até descarregar apenas com base em observações recentes de descarga. São necessários pelo menos quatro pontos, duas horas, uma queda de três pontos percentuais, uma leitura recente e um segmento de descarga estável. Carregamento, leituras antigas ou dados insuficientes suprimem a estimativa; o tempo restante informado pelo próprio dispositivo não está disponível. A estimativa não é uma garantia. Dados ausentes no gráfico são exibidos como lacunas, não interpolados.

Desative **Registrar histórico da bateria** no menu para parar de salvar leituras; o que já foi salvo permanece até você limpar no visualizador. O arquivo é salvo em `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Suas identidades de dispositivo são codificadas (não criptografadas); o arquivo é local à sua conta do Windows. Em `--demo`, o gráfico usa dados sintéticos que nunca são salvos. **Nota:** o histórico só começa a ser coletado após este recurso estar instalado e o aplicativo estar em execução por algum tempo.

## Dispositivos suportados

| Fabricante | Dispositivos | Como |
|---|---|---|
| **NuPhy** | WH80 por cabo USB (`19F5:A011`) ou Bluetooth (`19F5:324A`), testado em hardware | USB: consulta de bateria NuPhyIO somente leitura; Bluetooth: nível de bateria do Windows com classificação de teclado ([notas de protocolo](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) em seu receptor USB `3654:6901` (testado em hardware) | Consulta de bateria verificada por CRC e sinalizador de carregamento somente leitura; leituras brutas observadas em passos de 10%, precisão mais fina não verificada ([notas de protocolo](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX no receptor KP 8K (`1D57:FA65`; modelo `73` testado em hardware, modelo `74` não testado) | Relatórios de status passivos Xenta; dois quadros correspondentes confirmam o nível ([notas de protocolo](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, testado), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` testado, `002D`/`002A`), A50 Gen 3 (`9886:0015` testado, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), via estação base USB | Porcentagem da bateria, carregamento e status na base |
| **Logitech** | Mouses e teclados em receptores Unifying, Bolt, Lightspeed (incluindo o dongle PRO X3 SUPERSTRIKE `046D:C54F`) e Nano, por USB ou Bluetooth; headsets G (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 no dongle mais recente `046D:0ADF` | HID++ 1.0 / 2.0 com descoberta de recursos: bateria unificada, nível de bateria, tensão, ADC; G435: relatórios de fabricante com quadro CRC-16, `GET_BATTERY` em mV |
| **Razer** | Mouses, teclados e dongles sem fio; headsets BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X, V3 Pro para Xbox (receptor `1532:0A55`, cabo `0A4E`); Barracuda X (2022) em seu receptor 2.4 GHz (`1532:0550` ou `1532:0552`); Barracuda Pro (`1532:053A`) | Protocolo de feature report da Razer; protocolos de fabricante BlackShark (V3 / V3 Pro / V3 X consultados a cada 5 min); Barracuda X: consultas Airoha de bateria e cabo pelo receptor |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (incluindo `1038:225D`), Arctis Nova Elite (estação base `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, não testado), Aerox 3 Wireless CS2 Dragon Lore Edition (receptor `1038:1878`, cabo `187A`), Aerox 3 Wireless Gen 2 (receptor `1038:1890`, cabo `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Relatórios HID do fabricante; Aerox/Prime e Rival 650 compartilham uma entrada entre receptor e cabo USB, preferindo a leitura do cabo quando ambos respondem |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 sem fio; dispositivos Bragi (Virtuoso, Void V2, HS80 MAX, mouses e teclados Slipstream, incluindo o receptor Slipstream mais recente `1B1C:2B00`, ex.: Scimitar Elite SE Wireless, e Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, não testado) | Relatórios HID do fabricante, Bragi `GET` (somente leitura), protocolo de bateria Compx de 17 bytes (somente leitura) |
| **Cooler Master** | MM712, MM731 (dongle 2.4 GHz ou cabo USB) | Relatório HID de status do fabricante (somente leitura) |
| **Press Play** | ICARUS V2 Nearlink em seu receptor 2.4 GHz `7768:6434` (driver testado em hardware a 90%; protocolo capturado a 100% e 90%) | Output report somente leitura `06 05` em `FFB2:0001`; porcentagem da bateria no byte 14 da resposta |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` para PS, não testado), Cloud Flight S, Cloud Stinger Core Wireless (incluindo DTS `03F0:0A8E`, testado), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (dongle 2.4 GHz), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (dongle 2.4 GHz) (dongle 2.4 GHz `03F0:0F98`, testado; `0D97` não testado) | Relatórios HID do fabricante (Haste 2: [notas de protocolo](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Feature report do fabricante |
| **Hitscan** | Hyperlight X, Hyperlight N | Feature report do fabricante (mesmo protocolo da Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, mouses sem fio Pulsar e ATK VXE (ex.: VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (receptor 3554:F512) | Protocolo compartilhado de fabricante com respostas verificadas por checksum |
| **Pulsar X2 V3** | X2 V3 no dongle 1K (`3710:5402`) ou cabo USB (`3710:3402`); X2 V3 eS no dongle 8K (`3710:5403`) ou cabo USB (`3710:3406`) | Feature report do fabricante de 64 bytes, registrador de bateria `08 81 01` (somente leitura) |
| **ATK / VXE NK** | VXE R1 NK e outros mouses NearLink no dongle NK mouse NANO (`373B:1216`) | Output report 08 ATK BITMOUSE em `FF05:0001` (bateria e carregamento) |
| **ATK 8K Nano** | Mouses ATK / VXE no ATK 8K Nano Dongle (`373B:1178`) | Feature report Holtek GetConfigData (`82`) em `FF10:0001` (do ATK HUB; bateria e carregamento) |
| **Headsets ATK** | ATK N9 Pro, N9 Ultra (primeira geração) | Protocolo de porta COM virtual (o app desktop ATK deve estar fechado) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK e seus dongles 8K | Protocolo Glorious ou Kysona, dependendo do modelo |
| **Mouses Keychron** | M4 e outros mouses Keychron no receptor 2.4 GHz; mouses 4K (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) no receptor Keychron 4K Link (`3434:D038`); mouses 8K (M5 8K, G6 HE 8K ...) no receptor TurboLink 8K; mouses 8K no receptor Ultra-Link 8K (`3434:D028`); mouses mais antigos (M1, M2, M3, M3 mini, M6, M7 ...) no receptor 1K (`3434:D030` / `D031`); trackball Nape Pro no receptor Link-KM ou cabo | Relatório do fabricante pelo Keychron Launcher (receptor 1K: feature report 51 06, como usado pelo app desktop da Keychron; Ultra-Link 8K: relatórios B5 03 / B3 06 em `FFC1`; Nape Pro: raw HID A7 31) |
| **Teclados Keychron** | K5 Max (`3434:0A50`, testado) no receptor Keychron Link (`3434:D030`) ou cabo USB; outros teclados sem fio Keychron QMK compilados com o mesmo patch | Raw HID em `FF60:0061`: `B2` pergunta ao receptor qual teclado está vinculado, `A4` retorna nível, tensão e carregamento. **Requer firmware de teclado com patch:** veja [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). O firmware original só reporta via Bluetooth |
| **CHERRY** | Teclado MX 3.0S Wireless em seu dongle 2.4 GHz (`046A:00EA`, testado) ou cabo USB (`046A:00E3`, testado) | Consulta HID do fabricante `1A` em `FF1C:0092` (somente leitura), com estado alimentado por USB. O modo Bluetooth é coberto pelo suporte Bluetooth |
| **CHERRY** | Mouse sem fio Cherry XTRFY no receptor 1K (`046A:0330`, testado) | Protocolo de bateria CompX de 17 bytes (`08 03` status do link, `08 04` GetPower), mesmo enquadramento do Corsair Sabre V2 Pro (somente leitura) |
| **Arbiter Studio** | Akitsu (receptor 8K `373E:000A`, cabo `373E:0009`), Akitsu 3950 (receptor 8K `373E:0039`, cabo `373E:0038`), Akitsu Medium (receptor 8K `373E:0067` e cabo `373E:0066`, ambos testados) | Feature report do fabricante somente leitura `0x83` em `FFFF:0000` do Arbiter Web HUB (bateria e carregamento) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (cabo, dongles 1K e 4K/8K) | Feature report do fabricante do LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) no dongle 4K; XM2we em seu receptor original (`3367:1961`) | Feature report do fabricante `A1`, comando de bateria `B4` (somente leitura) |
| **Teclados ATK / VGN / Evision** | Teclados ATK V75X e VGN / VXE (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) no receptor 2.4 GHz compartilhado (`320F:5088`) ou cabo USB (`320F:5055`), reconhecidos pelo nome do produto; teclados cujo receptor `320F:5088` se chama "Wireless Gaming Keyboard", ex.: Feker Alice80 (testado) | Output report Evision `04`, comando de bateria `1A` (do ATK HUB e VGN HUB); consultado no máximo a cada 10 minutos pelo receptor |
| **Redragon (Evision)** | K1NG M999 (testado) no receptor 2.4 GHz `320F:226F`; o ID do receptor pode ser compartilhado por outros modelos | Mesmo protocolo Evision dos teclados ATK (relatório `04`, comando `1A` em `FF1C:0092`), consultado a cada atualização; carregamento mostrado na base magnética; com o cabo USB conectado, o receptor continua repetindo o nível antigo sem estado de carregamento |
| **Audeze** | Maxwell no dongle USB (`3329:4B19`) ou cabo USB-C (`3329:4B1A`); Maxwell 2 no dongle USB (`3329:4B29`, testado); IDs de Xbox não testados | Relatório de fabricante `06` / input report `07`, atributo de bateria `0CD6` (consulta única somente leitura) |
| **ENDORFY** | Viro Wireless em seu dongle 2.4 GHz (`3738:0072`, não testado) | Airoha RACE "get battery" (`0CD6`) no relatório de fabricante `06` / input report `07`, mesma consulta somente leitura dos dongles Audeze e Skullcandy; sem estado de carregamento |
| **Turtle Beach** | Stealth 700 Gen 3 no transmissor USB (`10F5:2251`, testado no HaloBattery; versão PC `10F5:2262`, não testada) ou cabo USB próprio do headset (`10F5:2253`) | RACE `0x9942` (habilita o cliente CoAP) e um CoAP `GET /GSI` encapsulado em RACE `0x9902`, como faz o Swarm II; bateria pela chave `240` (sem sinalizador de carregamento) |
| **AKG** | N9 Hybrid em seu dongle USB (`0ECB:20D9`, testado) | Airoha RACE em `FF13:0001`: output report `06`, input report `07`, atributo de bateria `0CD6` (consulta única somente leitura) |
| **NZXT** | Lift Elite Wireless em seu dongle (`1E71:2101`) ou cabo USB (`1E71:2129`) | Leitura do fabricante `4E 02 81 .. B0` (de capturas do NZXT CAM) |
| **Poly / Plantronics** | Voyager 8200 UC e outros headsets atrás do adaptador BT600 (`047F:02EE` / `02F7`) | Protocolo get/set no relatório `07`, item de bateria `0A 1A` (somente leitura) |
| **WLMouse** | YING Magnesium (receptor YING 8K `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (receptor ou cabo; não o Beast X 4K); Beast X V2 (receptor 8K `36A7:A856`); Beast G (receptor 8K `36A7:A860` ou cabo `36A7:A861`; não testado) | Feature report do fabricante, comando de status `0x83` (YING: mesmo protocolo da Glorious) |
| **Finalmouse** | UltralightX em seu dongle 2.4 GHz (`361D:0100`, testado); Starlight X em seu dongle (`361D:0300` / `0301`, testado). Não no cabo próprio do mouse | Relatórios do fabricante xpanel em `FF00`: GETs somente leitura e depois *wake/all* (`0xE0`); tensão da bateria na curva do xpanel ou porcentagem própria do Starlight X, além do estado de carregamento |
| **VAXEE** | Mouse sem fio no receptor VAXEE 4K (`3057:1002`) ou receptor 8K (`3057:2002`, ex.: NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless via cabo USB (`3057:1011`) | Feature report do fabricante somente leitura `0E` em `FF05:0001`; bateria em passos de 5%, estado de carregamento ([notas de protocolo](#sec-vaxee)) |
| **Scyrox** | V12M em seu receptor 2.4 GHz (`395A:0006`) | Leitura de perfil do S-Center 2.0 (output report `08`, comando `01`) em `FF00:0002`; apenas bateria, sem estado de carregamento |
| **HECATE** | G5M PRO e outros mouses HECATE no mesmo receptor e cabo USB `35BB:D3FA / D3FC / D3FD` | Protocolo Kysona |
| **Redragon** | Mouses sem fio baseados em Compx: M916 Pro 1K (testado), M913 Impact Elite (tri-mode), G49 (receptor ou cabo) | Protocolo Kysona (os receptores Areson `25A7` estão listados em Areson) |
| **Taidu (钛度)** | TSG808 em seu receptor 2.4 GHz Compx `3554:F5D5` (testado) | Protocolo Kysona |
| **Areson (Redragon)** | M915RGB-WL (testado), M913 Impact Elite original e outros mouses no receptor `25A7:FA07` / `FA08` | Feature report `GetPower` de 17 bytes; nível em passos de 10% e sinalizador de carregamento |
| **Ninjutso** | Sora V2 no receptor 1K (`1915:AE1C`, testado) ou cabo USB (`1915:AE11`, testado); Ten Air (receptor `093A:EB01` e cabo USB `093A:E020`, testados) / Ten (`093A:EB01` / `E020`, não testado) | Feature report NinjaForce `0x05` (`0x15` para Sora V2) e `0x06` (`0x13`/`0x12`/`0x11` para Ten / Ten Air) |
| **Sprime** | PM1 no receptor 2.4 GHz (`1915:AC1C`, testado; `1915:AD8C`) ou cabo USB | Mesmo feature report 0x05, comando de status 0x15, do driver web da Sprime (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 no RAWM HS Receiver (`1915:2346`, testado); ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* e mouses SADES Dagger em seus receptores RAWM (`1915:232A`–`234B`) ou cabo USB | Consulta de informações do dispositivo RAWM HUB 2.0 pelo receptor (JSON com % de bateria e carregamento), somente leitura ([notas de protocolo](#sec-rawm)) |
| **AULA** | Teclados sem fio F75 / F87 Pro / F99 no receptor 2.4 GHz | Quadro de relatório 0x13, comando 0x4A, checksum por soma (modos Bluetooth e com fio não testados) |
| **Mouses AULA** | X9 Ultra (testado) no AULA-8K Dongle `320F:22A0`; ID do receptor compartilhado com modelos V9 | Relatório `04`, comando de bateria somente leitura `1A` entre START `01` / END `02` em `FF1C:0092`; apenas 2.4 GHz |
| **Teclados SONiX (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (testado), EPOMAKER EA75 (testado), AULA F108 Pro no dongle 2.4G `05AC:024F`; AJAZZ AK980 V2 no dongle `0C45:FEFE`; AJAZZ AK820 Pro no dongle `0C45:FDFD` ou `0C45:FEFE`; EPOMAKER P75 em `342D:E479` (não testado em hardware) | Relatório de fabricante `20 01` na usage page FF60, checksum por soma (somente modo 2.4G; sem indicação de carregamento) |
| **Receptores SONiX adicionais (não testados em hardware)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | Mesma consulta `20 01` somente bateria; requer exatamente o VID:PID e a coleção FF60:0061 com relatórios de 33 bytes; somente 2.4G, sem indicação de carregamento |
| **Teclados 36B0 (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB no dongle 2.4G `36B0:3002` ou cabo USB `36B0:3009` (protocolo testado em ambos pelo autor da issue #343); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) no mesmo dongle ou cabo (não testados); URX Core75 no dongle (confirmado no HaloBattery); EVO80 (não testado) | Firmware PMO Hub: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` na usage page FF60, de pmohub.cn. Firmware URX / VIA: VIA custom-get `08 00 07` (canal 0, valor 7), do URX HUB via HaloBattery. Sem indicação de carregamento |
| **DAREU** | EM901X no receptor 2.4 GHz `260D:1074` ou cabo USB `260D:1090` (leitura de bateria testada em ambos; transições do sinalizador de carregamento ao acoplar/desacoplar no receptor testadas) | Feature report somente bateria `08`, comando `04`; resposta `09` em uma coleção de fabricante separada. Requer um par entrada/feature inequívoco por ID de produto. Prefere uma leitura USB válida quando ambos estão conectados; o receptor pode retornar telemetria em cache mesmo com o mouse desligado |
| **DAREU** | Teclado A84 (`260D:0022`, não testado) | Feature report SONiX na interface 0, comando `04 F6` (leitura de bateria do driver oficial do A84); nível em porcentagem, sem sinalizador de carregamento |
| **DAREU** | A980 Pro no receptor multi-mouse `260D:1131` e em seu cabo USB (`260D:1148`) (nível de bateria testado em hardware; sinalizador de carregamento confirmado enquanto conectado) | Protocolo Togran: feature report de 65 bytes `0A` na coleção consumer-control; consulta de slot (classe 0 / `A0`) e depois consulta de bateria (classe 7 / `80`), no slot 0 pelo cabo. Somente leitura |
| **Sharkoon** | Skiller SGM50W em `260D:1125` (não testado) | Mesma consulta Compx do DAREU EM901X (feature report `08`, comando `04`; resposta `09` em `FF01:0000`); o atualizador de firmware da Sharkoon para ele é uma ferramenta Compx no VID `260D` |
| **Zenith** | Zenith Pro no receptor 2.4 GHz `260D:1114` (leitura de bateria testada; carregamento não testado) ou cabo USB `260D:1143` (não testado) | Mesmo comando Compx (`08`, `04`) como output report em `FF02:0002`; resposta `08 04` na mesma coleção com porcentagem, sinalizador de carregamento e milivolts, verificado pela soma de bytes `0x55` |
| **AJAZZ AK992** | Receptor 2.4 GHz Telink `320F:50C3` (testado) | Consulta de bateria EVision na coleção HID `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, série DW (U2-DW, S2-DW ...) e U2 em seu receptor 2.4 GHz | Comandos de fabricante somente leitura documentados pela comunidade |
| **Royal Kludge (RK)** | MG6 Pro no dongle 2.4 GHz (`2E3C:00A6` / `00E6`) ou cabo USB (`2E3C:00A5` / `00E5`) | Quadro QiWang de 64 bytes do driver web da RK, leitura `GET_BATTER_VOL` (porcentagem, tensão, carregamento) |
| **ASUS ROG** | Teclados Strix Scope II 96 (RX), Azoth, Falchion; mouses Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact; headset Pelta (dongle 2.4 GHz); fones intra-auriculares Cetra Open Wireless (dongle SpeedNova `0B05:1CAC`, E / D / estojo); o Omni Receiver | Consulta de bateria ROG HID |
| **Machenike** | L7 Arctic / L7 Mix no receptor 2.4 GHz `248A:FF4C` ou cabo USB `248A:FF4E` (ambos testados) | Feature report somente leitura `51`, comando de status `06`; bateria e carregamento. [Notas de protocolo](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS em seu dongle 2.4 GHz (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (receptor 2.4 GHz `0DB0:0D3C`, testado; cabo USB `0DB0:0D3B`) e CLUTCH GM41 Lightweight Wireless (receptor `0DB0:0D4C` / cabo `0DB0:0D4B`, a partir das capturas de um usuário) | Consulta de fabricante somente leitura `0F 20` em `FF0D:00B0` e `FF00:0001`; bateria e sinalizador de carregamento em um byte (protocolo do módulo Gaming Gear do MSI Center); GM41: relatórios passivos `A0 xx 07 …` em `FF10:0006` |
| **MCHOSE** | Mouses L7 / L7 Pro / L7 Ultra (L7 Ultra testado), M7 / M7 Ultra, A7 / A7 Ultra, K7 no receptor 2.4 GHz ou cabo USB; A5 V2 Ultra (receptor 2.4 GHz `3837:100C`, testado), K7 Ultra (receptor 2.4 GHz `3837:1001`, testado; A7 V2 Ultra+ `3837:100B` esperado funcionar, issue 227); G3 V2 (receptor 2.4 GHz `3837:4245` e cabo USB `3837:418C`); K7 V2 Ultra+ no receptor 2.4 GHz `3837:1014` ou em seu cabo USB `3837:4028` (ambos testados; os outros IDs de receptor da nova família `1018`, `1016`, `102C`, `102D` não foram testados) | Feature report do fabricante, payload invertido (protocolo de alexfrih/mchose-linux); dongles Realtek `3837` respondem à mesma consulta com o campo vid definido como `41E4` (A5 V2 Ultra) ou `3837` (K7 Ultra); G3 V2: consulta de fabricante somente leitura em `FF01:0010`; K7 V2 Ultra+: relatório de 64 bytes `0x4D`, comando de info do dispositivo `0x0900` em `FF01:0001` (protocolo do driver web M HUB) |
| **MCHOSE A5 (primeira geração)** | A5 Pro / A5 Pro Max no receptor 2.4 GHz 1K ou 4K (`2023:F013`, `2023:F015`, `2023:F018`) ou no cabo USB (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); não testado aqui | Comando de bateria somente leitura `0x83` (página 0) em um feature report de 64 bytes em `FFFF`, resposta marcada com `0xA1` (protocolo do driver web z750sasr A5 Pro Max e HaloBattery, IDs de Klegus/mchose-macos) |
| **Headsets MCHOSE** | V9 Pro 2 no dongle 2.4 GHz (`3837:6011`, testado) | Quadro de bateria "MC" somente leitura do M HUB (relatório `0x55`, subcomando `0x0B`) em `FF07:0222`; bateria e sinalizador de carregamento em um byte (protocolo do driver web M HUB) |
| **Teclados AULA / MCHOSE / Redragon** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 e outros teclados do M HUB; Redragon Horus Pro / Pro V2 (K618RGB-PRO) no receptor 2.4 GHz (`3554:FA09`, `41E4:2001`); MCHOSE K87 no receptor `05AC:024F` (layout BY na interface 1, não o SONiX) | Quadro de relatório 0x13, comando 0x4A (modelos MCHOSE e Redragon identificados pelo comando 0x05, como no M HUB); modos Bluetooth e com fio não cobertos |
| **Teclados MCHOSE** | G75 V2 no receptor 2.4 GHz `3837:3033` (testado); o mesmo receptor acompanha o G87 V2 e o K99 V3 (mesmo protocolo, não testado); o K87S combina o mesmo ID de receptor com outro protocolo e não é coberto | Consulta "GLW" func-config somente leitura do M HUB na coleção sem ID de 64 bytes `0001:0000`: flag de solicitação `0x55`, comando `0x05`, bateria no byte 32 do payload (bit 7 = carregando), checksum aditivo |
| **AULA SC580** | Mouse SC580 / SC580X por cabo USB (`088D:062E`, testado) ou seu receptor 2.4 GHz (`089D:062F`, testado) | Comando somente leitura `0x30` (informações do dispositivo) na coleção de fabricante de 33 bytes FF02:0000, checksum por soma; durante o carregamento o mouse informa 100 fixo, então o último nível é exibido; modo Bluetooth não coberto |
| **AULA HERO 68 Air** | HERO 68 Air no Receptor Sem Fio 8K (`372E:106C`) | Quadros de 20 bytes com confirmação na usage page FF60 (quatro quadros de dados e um trailer por mensagem), comando de bateria somente leitura 0x87, flag de carregamento 0x10 após o nível; modos Bluetooth e com fio não cobertos |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra e S9 Max / Pro / Ultra / Ultra+ no receptor "Gaming 2.4G" (`372E:103D`); S9 Ultra em seu cabo USB (`372E:1027`) | Feature report somente leitura `03` em `FF00:0001`: verificação de link `47`, dados básicos do dispositivo `4F 81` (porcentagem da bateria e bit de carregamento), do driver web da EWEADN |
| **Rapoo VT** | VT3 Max Gen 2 (testado); VT9 Gen 2 (testado); outros mouses Nordic 54L VT que expõem a mesma interface de status; VT3 Pro legado (experimental); VT1 Pro Max (a partir das capturas USB do proprietário) | Relatório HID passivo de status `07` em `FF00:0002` (16 ou 19 bytes; 13 bytes em alguns receptores VT3 Max Gen 2); `BB` legado restrito ao VT3 Pro `1215/4415` e VT1 Pro Max `1233/4433`. Receptor e cabo USB, com estado de carregamento |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (modelos Xenta 30/50; legado 3D), Delux M800 Pro, família Ajazz AJ179; AJ159 e outros mouses da série AJ no receptor 3151; AJ139 V2 MC (receptor `A8A5:2255`, cabo `A8A4:2255`) | Relatórios do fabricante (M900 Pro: transmissões passivas de status ou feature query, eventos Xenta 40/41; série AJ: consulta de status 0xF7 e depois feature report 0x05) |
| **Incott** | G23 V2 / G24 (receptor `093A:522C`, cabo `093A:622C`) | Feature report de status somente leitura 09 |
| **Attack Shark e outras marcas chinesas** | Receptores Rongyuan (81 modelos: Attack Shark R3 e AJAZZ AJ179 Pro em `3151:402D`, K86, X82 PRO HE, teclados Ajazz, alguns MSI e outros; o K86 via Bluetooth é exibido como teclado); receptores Xenta (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; o X6 também em `1D57:FA61`, não testado); teclados Semico 1A2C (Attack Shark X98 no dongle `1A2C:8FFF`, testado, e cabo `1A2C:A034`; AJAZZ AK820 Max Plus em `1A2C:8FFF` / `1A2C:A036`) | Relatório de status Rongyuan; transmissões passivas Xenta; consulta de status Semico somente leitura `0x0E` (`AA 55 CC 33` em `FF02:0002`; flag de carregamento omitida porque o X98 reporta `state=1` tanto na bateria quanto carregando) |
| **Wraith** | W1 / W1 Freestyle (receptor `093A:522C`, cabo `093A:622C`; mesmos IDs do Incott, diferenciados pelo código do modelo) | Leituras por botão somente leitura `86` (feature report 09) para todos os botões e depois o input report de status enviado 09 |
| **Fantech** | Helios Go XD5 (com fio `25A7:FA7B`, dongle `25A7:FA7C`); Raigor III (testado), Raigor II WG10 e outros dispositivos genéricos 2.4G Mouse no dongle reutilizado `1EA7:0066` / `1EA7:0064` | Helios Go XD5: feature report do fabricante `08`, comando `04`, checksum de soma igual a `0x55`. Raigor/2.4G Mouse: consulta somente leitura na página de status `B5` em `FFB5:0001`, bloco `94` = última porcentagem reportada (pode ficar desatualizado em repouso, desligado ou carregando; sem estado de carregamento) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, adaptador sem fio); headsets INZONE H9 II e H5; INZONE Buds (dongle USB-C) | Input report; protocolo de fabricante INZONE |
| **Fractal Design** | Headset Scape em seu dongle 2.4 GHz ou cabo USB-C | Consulta do fabricante `GET_DEVICE_STATE` do aplicativo web Adjust Pro da Fractal (usage page FF00) |
| **Jabra** | Todo headset Jabra que utiliza o protocolo GN (Evolve2 / Evolve3 e outros), em seu próprio cabo USB ou atrás de um dongle Jabra Link; sem lista fixa de product IDs, bases DECT (Engage, PRO 9xx, GO 6400, Link 400) ficam de fora; nome lido do headset | Consulta de status GNP (classe 12 / op 02) na usage page FF00, usage 05 ou 01, no endereço GNP 08 (USB) ou 04 (dongle) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), receptor 2.4 GHz ou USB; Apex 5 (`37D7:2501`), receptor 2.4 GHz ou USB | Consulta HID de informações do fabricante em `FFA0:0001`; nível de bateria de 0–5 mapeado para 0–100% em passos de 20%, com estado de carregamento; sem exigir o serviço Space Station |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite no receptor 2.4 GHz; Nova 2 Lite via USB; G7 Pro (testado: edição Zenless Zone Zero, receptor `3537:105E`) e outros controles GameSir no modo Xbox (GIP); Cyclone 2 (modo XInput, receptor ou cabo); Cyclone Pro em seu dongle 2.4 GHz (`3537:1015`, pareie o controle com o Windows via Bluetooth uma vez) | Consulta de informações do dispositivo do fabricante (usage page FF7A); relatório de bateria Windows.Gaming.Input (% real) no modo Xbox; Cyclone 2: solicitação de bateria do fabricante (usage page FFF0); Cyclone Pro: solicitação base-info do app GameSir via Bluetooth LE (serviço `0x8650`), lida a cada 2 min |
| **BEITONG** | KP20 / BTP-KP20 em seu receptor 2.4 GHz (`20BC:5128`, modo XInput, testado) e KP40D / BTP-KP40D em seu receptor (`20BC:515C`, modo XInput); BEITONG iControl não necessário | Consulta do fabricante "get base info" na usage page `00FF` (relatório `02`, payload embaralhado por nibbles), com estado de carregamento |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` testado no dongle 2.4 GHz, D-input `2DC8:6012` — segure B ao ligar, firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Consulta HID de status do fabricante (`FF7A`/`FFA0`) e input report de gamepad SDL `01`/`04`, com estado de carregamento |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Quadro de status que os fones enviam pelo serviço RFCOMM (SPP) da Samsung, somente leitura. A bandeja mostra o fone com menor carga; a dica lista esquerdo, direito e estojo. O aplicativo Galaxy Buds deve estar fechado |
| **Nothing / CMF** | Nothing Ear (3a) (testado), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Consulta de bateria somente leitura `0xC007` no serviço RFCOMM NT Link da Nothing (`aeac4a03-dff5-498f-843a-34487cf133eb`). A bandeja mostra o fone com menor carga; a dica lista esquerdo, direito e estojo |
| **Akko** | Akko Air 01 (`3151:5006`, receptor 2.4 GHz, testado) e Akko V9 Dash Pro (`38EE:000C`, receptor 2.4 GHz, testado) | Air 01: relatório de status Rongyuan `0xF7`; V9 Dash Pro: consulta de status somente leitura de 64 bytes `0x1A` em `FF1C:0092` com estado de carregamento |
| **MOONDROP** | Headset GM01 Pro em seu dongle 2.4 GHz (`35D8:0133`); no cabo USB aparece carregando com o último nível | Comando de leitura do fabricante WalkPlay no relatório `4B` (somente leitura) |
| **VGN** | Headset OMNISOUND (ZHOUTING) em seu dongle 2.4 GHz (`372E:10BB`, testado) | Consulta "ZHOU" do V HUB: output report `55` com payload `65 01` na coleção de controle `000C:0001` (input reports de 32 bytes, output reports de 64 bytes); a porcentagem retorna na resposta (somente leitura) |
| **JBL** | Quantum 650 Wireless (testado, dongle 2.4 GHz); Quantum 520, 650X, 850, 950, 950X Wireless (dongle ou cabo USB, mesmo protocolo, não testados) | Consulta de informações do dispositivo JBL "HIDV3" para o recurso de bateria (usage page FF12), com estado de carregamento |
| **JBL** | Quantum 350 Wireless (testado no Windows com o receptor 2.4 GHz `0ECB:206B`); Quantum 610 Wireless (dongle 2.4 GHz `0ECB:205C`, não testado no Windows); Quantum 360 Wireless (dongle 2.4 GHz `0ECB:2115`, não testado) | Feature reports HIDV1 para conexão sem fio e porcentagem da bateria |
| **Xbox** | Controles no adaptador Xbox Wireless, USB ou Bluetooth; headsets conectados a um controle | Relatório de bateria Windows.Gaming.Input (% real), fallback XInput |
| **Compatíveis com Switch Pro** | Controles que se apresentam como `057E:2009` (testado: GameSir Tarantula Pro pelo receptor 2.4 GHz no modo Switch) | Cinco níveis de bateria do relatório HID `0x30` depois que o Steam Input ou outro host habilita relatórios completos |
| **Apple AirPods / Beats** | AirPods Max (testado, `200A` Lightning e `201F` USB-C), AirPods Pro 3 (testado, `2027`), AirPods Pro 1 / 2, AirPods 1–5 e fones/headsets Beats | Transmissões BLE "proximity pairing" (`0x07`) (bateria única para AirPods Max e fones Beats; esquerdo, direito e estojo para intra-auriculares, em passos de 10% com estado de carregamento), associados ao modelo pareado |
| **Celulares (Vincular ao Celular)** | Qualquer celular Android vinculado ao Microsoft Vincular ao Celular (Phone Link), por Wi-Fi ou Bluetooth (testado: Nothing Phone (4a) Pro) | Bateria e estado de carregamento do cartão do menu Iniciar do Windows 11 do Vincular ao Celular (`StartMenuCompanion.json`); não precisa de Bluetooth |
| **Darmoshark** | M3 (`248A:FF30`) e M3S (`248A:FF31`) em seus receptores 2.4 GHz no Windows | Feature report HID para identidade e bateria do mouse |
| **Darmoshark** | M3S Pro no receptor Nordic 1K (`1915:0723`) | Consulta HID de status do fabricante na coleção `FF0A` |
| **Alienware** | Headset AW920H em seu dongle 2.4 GHz (`413C:A515`, testado); via Bluetooth é coberto pela linha Bluetooth | Consulta do fabricante `06 C0 0A` em `FF13:0001`, relatório de resposta `07` com checksum XOR; campos de nível, carregamento e nível crítico conforme decodificados pelo plugin AW920H do Alienware Command Center |
| **Niceboy** | MW400 em seu receptor 2.4 GHz (`248A:FA02`, testado) | Consulta somente leitura no relatório `05` `24 FA 48`; tensão da bateria mapeada em passos de 10% com a tabela do aplicativo do fabricante, sinalizador de carregamento |
| **Bluetooth** | Qualquer dispositivo que exiba bateria em *Configurações → Bluetooth e dispositivos* (fones, headsets, mouses e teclados BLE). Fones Google Fast Pair (Jabra Elite 8 Active testado; Pixel Buds e muitos modelos Sony / JBL / Bose) também obtêm níveis de esquerdo, direito e estojo | Propriedade de dispositivo do Windows; transmissões de bateria Fast Pair (dados de serviço BLE `FE2C`), associadas ao dispositivo pareado pelo endereço Bluetooth |
| **HID genérico** | Dispositivos que reportam o usage padrão HID *Battery Strength* | HID usage page 0x06 / 0x85 |
| **HeadsetControl** | [Todos os headsets suportados por ele](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, Logitech mais recentes e outros) | Incluído no pacote; executa `headsetcontrol -o json` |
| **MAONO PD200W** | Receptor 2.4 GHz (352F:040E) | Porcentagem da bateria; testado em hardware |


**Testados em hardware real:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (receptor PlayStation `0951:1713`; carregamento não testado), HyperX Cloud Core Wireless DTS (receptor `0951:173F`; nível de carga total não testado), HyperX Pulsefire Haste 2 Core Wireless (dongle `03F0:0AB5`; os dongles do Haste 2 Wireless não foram testados), Cooler Master MM712 (dongle), Rapoo VT3 Max Gen 2 (receptor `24AE:1417` e cabo USB `24AE:4617`; outros modelos Rapoo não foram testados, veja [notas de protocolo Rapoo](#sec-rapoo)), Redragon M916 Pro 1K (receptor `3554:F55D`), Taidu TSG808 (receptor `3554:F5D5`), Redragon M915RGB-WL (receptor `25A7:FA07`; outros modelos Areson não foram testados, veja [notas de protocolo Areson](#sec-areson)), SteelSeries Rival 650 Wireless (receptor `1038:1726` e cabo USB `1038:172B`), SteelSeries Arctis Nova Pro Wireless (estação base `1038:225D`; leitura da bateria testada, carregamento e transições de energia não testados), HECATE G5M PRO (receptor `35BB:D3FB`), WLMouse YING Magnesium (receptor 8K `36A7:A874`), ATK N9 Ultra (receptor `373B:1204`), Corsair Scimitar Elite SE Wireless (receptor Slipstream `1B1C:2B00`), Corsair Dark Core RGB Pro SE (receptor Slipstream `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (receptor 2.4 GHz `1B1C:2B2A`; leitura de bateria verificada), DAREU EM901X (receptor `260D:1074`; carregamento e repouso/despertar não testados), Jabra Evolve3 75 em um Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (receptor `3837:4245` e cabo USB `3837:418C`), MCHOSE K7 Ultra (receptor `3837:1001`), MCHOSE K7 V2 Ultra+ (receptor `3837:1014` e cabo USB `3837:4028`; carregamento exibido enquanto conectado), MSI VERSA 300 ELITE WIRELESS (dongle `0DB0:9E22`; carregamento e tratamento de repouso não testados), MSI Clutch GM31 Lightweight Wireless (receptor `0DB0:0D3C`; o GM41 usa o mesmo driver a partir das capturas de um usuário), AJAZZ AK820 MAX (dongle `05AC:024F`), AULA HERO 68 Air (Receptor Sem Fio 8K `372E:106C`), AULA SC580 (cabo USB `088D:062E` e receptor `089D:062F`, incluindo carregamento e repouso), AirPods Pro 3 (Bluetooth, modelo `2027`), AirPods Max (Bluetooth, modelo `200A`), Sprime PM1 (receptor `1915:AC1C`), Ninjutso Ten Air (receptor `093A:EB01` e cabo USB `093A:E020`), MOONDROP GM01 Pro (dongle `35D8:0133`), Delux M800 Pro (receptor `248A:5B2F`), Razer Barracuda X (2022) (receptor `1532:0550`; nível da bateria lido, transições de carregamento não testadas), Razer BlackShark V3 X (dongle HyperSpeed `1532:057D`), Fantech Helios Go XD5 (dongle `25A7:FA7C`), Fantech Raigor III (dongle `1EA7:0066`; carregamento não reportado pelo firmware), Finalmouse UltralightX (dongle `361D:0100`), Finalmouse Starlight X (em seu dongle) e Chimera V2 (receptor `3554:F512`; nível da bateria e carregamento lidos).
Também testado em hardware: Machenike L7 Arctic / L7 Mix (receptor `248A:FF4C` e cabo `248A:FF4E`), incluindo carregamento e supressão de duplicidade entre cabo/receptor. Bluetooth e limites de bateria fraca/carga total não foram testados em hardware.
Também testado em hardware: MCHOSE V9 Pro 2 (dongle `3837:6011`); nível da bateria lido, carregamento e repouso não testados.
Também testado em hardware: EPOMAKER EA75 em seu receptor 2.4 GHz `05AC:024F`, usando o driver SONiX existente do [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). Porcentagem da bateria, reconexão do receptor e recuperação ao ligar foram verificadas. Indicação de carregamento e relatório de bateria via cabo não são suportados por este driver; o relatório de bateria via Bluetooth não foi testado. A porcentagem reportada pode saltar para 100% quando a energia USB é conectada, o que não é um indicador confiável de carregamento.
Também testado em hardware: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (receptor `1038:1878` e cabo USB `1038:187A`), incluindo carregamento, desligamento (o último nível permanece esmaecido) e com o SteelSeries GG em execução; o GG mostra apenas uma barra de três níveis, com a qual o nível coincidiu.
Também testado em hardware: RAWM Leviathan V4 (RAWM HS Receiver `1915:2346`; nível da bateria lido, carregamento não testado).
**Implementado a partir da documentação do protocolo e de outros projetos, ainda não testado:** todo o restante, incluindo o Fantech Raigor II WG10 (mesmo dongle `1EA7:0066` e coleção do Raigor III testado, portanto deve funcionar). Se você possui um desses dispositivos, informe se funciona [abrindo uma issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues).

## Instalação

[![Última versão](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Baixe **`BatteryHub-Setup-<version>.exe`** na [última versão](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. Execute, escolha qualquer um dos 19 idiomas suportados pelo instalador e avance. Não exige **direitos de administrador** nem **nada mais instalado**: sem
   runtimes, sem drivers, sem aplicativos de fabricantes. O HeadsetControl vem incluído, e a pasta editável `lang\` é instalada ao lado de `BatteryHub.exe`.

O instalador adiciona um atalho no Menu Iniciar e um desinstalador (*Configurações → Aplicativos*), e pode iniciar o aplicativo
quando você entrar no Windows. Prefere sem instalador? Baixe `BatteryHub-<version>-portable.zip`, descompacte em
qualquer lugar (mantenha a pasta `lang\` ao lado de `BatteryHub.exe` para as traduções da interface) e execute `BatteryHub.exe`.

**Observações:**
- **Aviso do SmartScreen:** o executável não tem assinatura de código, então o Windows pode exibir "O Windows protegeu o computador". Clique em *Mais informações → Executar mesmo assim*, ou compile você mesmo.
- **Modo de ícones na bandeja no Windows 11:** novos ícones na bandeja vão para o menu excedente `^`. Arraste-os para a barra de tarefas ou ative-os em *Configurações → Personalização → Barra de tarefas → Outros ícones da bandeja do sistema*.
- **Mantendo o aplicativo afastado de um dispositivo:** se um dispositivo se comportar de forma inadequada enquanto o aplicativo estiver em execução, liste-o na string do Registro `IgnoreDevices` em `HKCU\Software\WirelessBattery` como pares `VID:PID` (em hexadecimal, separados por vírgula, por exemplo `28BD:0947, 1234:ABCD`; `--dump` mostra os IDs). O aplicativo então nunca o abrirá. Mesas digitalizadoras são ignoradas automaticamente.

## Atualizações no Windows

Compilações oficiais estáveis para Windows verificam a versão estável publicada mais recente do projeto em
segundo plano, 30 segundos após a inicialização e depois a cada 24 horas enquanto o aplicativo estiver em execução. Abra o
menu para ver **Atualização disponível: vX.Y.Z...** ou escolha **Verificar atualizações...** manualmente.
As informações de atualização aparecem apenas neste menu: ícones de bateria, porcentagens e dicas permanecem os
mesmos, e verificações automáticas nunca exibem notificações nem caixas de diálogo. Desative
**Verificar atualizações automaticamente** no menu para desabilitar verificações em segundo plano.

Em uma cópia instalada, clique na entrada de atualização e em **Baixar e instalar**. Nada é instalado
sem esse clique. O aplicativo baixa o arquivo `SHA256SUMS.txt` da versão e sua assinatura, verifica a
assinatura usando a chave pública do mantenedor incorporada no aplicativo, baixa o instalador do Windows
e o executa somente se seu SHA-256 for o que consta na lista assinada (e o que o GitHub lista para ele). Ele
então atualiza a instalação existente. As configurações e a preferência de inicialização são
preservadas, e o aplicativo reabre após a instalação. Uma instalação para todos os usuários pode solicitar
permissão de administrador. **Notas da versão** abre a página oficial de lançamento; **Mais tarde** mantém
sua versão atual. Cópias portáteis oferecem a página de lançamento para baixar o ZIP manualmente.

As verificações acessam a API pública do GitHub sem conta nem token. Nenhuma informação de dispositivo ou bateria
é enviada. Falhas de rede e limites de taxa do GitHub mantêm o monitoramento de bateria funcionando; uma versão encontrada
anteriormente permanece no menu até que uma verificação bem-sucedida a substitua ou ela seja instalada.
Cancelar um download aguarda a operação de rede atual concluir seu tempo limite finito.
O instalador nunca reinicia o Windows automaticamente.

**Por que as atualizações são seguras para instalar:** a chave de assinatura nunca vai para o GitHub. O mantenedor assina
a lista de checksums de cada versão em seu próprio PC (veja [docs/releasing.md](#sec-releasing)), portanto
mesmo alguém que assumisse a conta do GitHub ou seu fluxo de compilação não conseguiria publicar uma atualização
que o aplicativo aceitasse instalar. Uma versão sem assinatura válida aparece no menu, mas só pode ser
baixada manualmente. A assinatura não substitui os próprios avisos de SmartScreen ou UAC do Windows.

Instale manualmente uma vez a primeira versão que contém este recurso. Compilações de desenvolvimento/teste desativam
verificações oficiais de atualização para que alterações locais não sejam substituídas acidentalmente. Atualizações para Linux e
substituição automática de cópias portáteis ficam para etapas futuras.

## Linha de comando

```
BatteryHub.exe --list     # exibe cada dispositivo e seu nível de bateria e encerra
BatteryHub.exe --json     # exibe um array JSON de dispositivos e níveis de bateria e encerra
BatteryHub.exe --dump     # todas as coleções HID, dispositivos HID que não puderam ser abertos, todos os dispositivos USB (também os
                               # sem interface HID) e dispositivos Bluetooth; também salvo em %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # abre a janela "Pedir suporte para um dispositivo"
BatteryHub.exe --demo     # dispositivos de exemplo de todas as marcas em vez de dispositivos reais (capturas de tela, conferir cores)
BatteryHub.exe --quit     # fecha a instância em execução
```

A compilação Linux usa as mesmas opções com `wireless-battery` no lugar de `BatteryHub.exe`, e
também aceita `--help`. `--json` imprime um array estável que scripts e widgets de barra podem analisar:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` é por quanto tempo o aplicativo continua exibindo o último nível conhecido enquanto o dispositivo está em repouso.
A adição de novos campos mantém compatibilidade retroativa.

**Dispositivo não aparece?** Clique com o botão direito no widget ou no ícone da bandeja e escolha **Pedir suporte para um dispositivo...**. Escolha o dispositivo, confira
o que será enviado (tudo é mostrado palavra por palavra: o nome do dispositivo, seu tipo, seus IDs USB/HID e layout de interface, além do seu nome
e observações opcionais) e clique em **Enviar**. Ele vai para a lista pública em [krisgfx.com/tools](https://krisgfx.com/tools/#requested) e
abre ou atualiza uma issue no GitHub. **Copiar relatório completo** coloca o `--dump` completo na área de transferência para a issue.
Os dados do relatório são enviados somente quando você clica em Enviar. Compilações oficiais para Windows também podem acessar o GitHub
para verificar atualizações, conforme descrito em [Atualizações no Windows](#atualizações-no-windows); verificações de atualização
não enviam informações de dispositivo nem de bateria.

## Compilação

Você precisa do [MinGW-w64](https://www.mingw-w64.org/), por exemplo via [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # compilação de desenvolvimento, versão 0.0.0
build.bat                                 # cmd simples com g++ e windres no PATH
make VERSION=1.2.3 CHANNEL=test            # compilação versionada, atualizações oficiais desativadas
build.bat 1.2.3 test                       # compilação equivalente no cmd com versão
make test VERSION=1.2.3 CHANNEL=test       # testes de regressão de dispositivos e atualizador
```

Para gerar o instalador e o zip portátil, instale o [Inno Setup](https://jrsoftware.org/isinfo.php),
compile primeiro com a versão pretendida (por exemplo `make VERSION=1.2.3 CHANNEL=test`) e depois execute
`powershell -File installer\build-installer.ps1 -Version 1.2.3`. O empacotamento rejeita uma versão que
difira do executável. Ele baixa a versão fixada do
HeadsetControl e verifica seu checksum. O GitHub Actions faz tudo isso automaticamente:
enviar uma tag como `v1.0.0` publica um lançamento com o instalador, o zip portátil e o
código-fonte do HeadsetControl (conforme exigido por sua licença GPL).

Compilações para Windows também exigem PowerShell para gerar a versão compartilhada entre executável e recursos.
As tags de versão do repositório oficial compilam com `CHANNEL=stable`; compilações locais usam `dev` por
padrão. Forks e pull requests não habilitam atualizações oficiais automaticamente.

`BatteryHub.exe` também funciona sozinho. Sem `headsetcontrol.exe` ao lado dele (ou no `PATH`), você
apenas perde os headsets extras.

## Linux (experimental)

Uma compilação para Linux acompanha o aplicativo Windows. Ela usa os mesmos drivers de fabricante com um backend HID baseado em hidraw
e um ícone de bandeja GTK4 StatusNotifierItem; o caminho de código do Windows não é alterado.
Todos os arquivos exclusivos do Linux ficam em `linux/` e `src/linux/`, e `build-linux.sh` o compila (o Windows continua usando `build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Compilador & make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

Nenhuma biblioteca HID extra é necessária (hidraw é usado diretamente).

```sh
./build-linux.sh
./build-linux.sh test         # teste unitário do analisador de descritor de relatório HID
./wireless-battery --list     # imprime os níveis detectados e encerra
./wireless-battery --dump     # lista coleções HID
./wireless-battery --quit     # fecha a instância em execução na bandeja
```

O acesso HID precisa de uma regra udev; caso contrário o aplicativo inicia, mas não encontra dispositivos:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# saia da sessão e entre novamente
```

O ícone da bandeja funciona nativamente no KDE Plasma; o GNOME precisa de um host AppIndicator como
`gnome-shell-extension-appindicator`. A troca de idiomas funciona pelo submenu *Idioma*
(seguindo `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` por padrão e traduzindo também o `--help`).
Executar `make -f linux/Makefile.linux install` instala o binário, `lang/*.json` em
`$(PREFIX)/share/wireless-battery/lang/` e o lançador desktop (`linux/wireless-battery.desktop`)
mais `linux/wireless-battery.svg` em `$(PREFIX)` (o padrão é `~/.local`); substituições de idioma do usuário
ficam em `~/.config/wireless-battery/lang/`.

A Fase 1 cobre Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious,
Finalmouse e os protocolos compartilhados Kysona/Pulsar/ATK/G-Wolves. Fallbacks Bluetooth/UPower, HeadsetControl e
os demais fabricantes estão planejados para as próximas fases.

## Limitações

- **Barras de tarefas cheias:** em uma barra de tarefas centralizada do Windows 11 muito cheia, os botões dos aplicativos podem alcançar o widget. No Windows 10, a área de botões de tarefas é estreitada automaticamente.
- **Celulares:** lido de um arquivo que o Vincular ao Celular (Phone Link) grava para o cartão complementar do menu Iniciar, que não é uma API documentada e pode mudar com atualizações do Vincular ao Celular. O celular aparece enquanto o Vincular ao Celular o informa como conectado; um cartão com mais de 3 horas é mostrado esmaecido. O cartão também informa quando o celular está carregando, o que aparece como o raio de carregamento.
- **Dispositivos em repouso:** um dispositivo em repouso pode não responder. Seu último valor permanece visível, esmaecido. Receptores Logitech removem dispositivos em repouso do link, portanto seu último valor é mantido por 30 minutos.
- **Headset HECATE G2 Wireless 7.1** (dongle 2.4 GHz `35BB:A009` / `A209`): ainda não há consulta de bateria documentada para o seu dongle, portanto ele não é lido. Uma captura USB enquanto o software da HECATE exibe a bateria do headset (veja CONTRIBUTING.md) é o caminho para adicioná-lo.
- **Teclados Keychron:** com o firmware original, eles só reportam a bateria via Bluetooth (exibido pelo suporte Bluetooth). Pelo receptor 2.4 GHz ou pelo cabo, precisam de firmware com o patch de bateria ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); atualizar o teclado pelo Keychron Launcher remove o patch. Mouses Keychron são suportados.
- **Headset Baseus AeQur GH02:** o dongle 2.4 GHz (`10D6:4802`, chip Actions) transporta apenas áudio, teclas de mídia e o canal de atualização de firmware do chip, não a bateria. Conecte o headset por Bluetooth para ver seu nível (exibido pelo suporte Bluetooth quando o Windows informa um).
- **Teclado Weikav Lucky65 v1:** o firmware não reporta sua bateria pelo dongle 2.4 GHz (`0603:0351`, chip Novatek). O teclado não possui atalho de verificação de bateria, e o configurador oficial só conecta pelo cabo USB, não pelo dongle, então não há leitura de bateria para exibir.
- **Rapoo:** os mouses VT suportados enviam seu status passivamente, então uma atualização pode aguardar até 4 segundos por interface correspondente. Mouses em repouso podem permanecer esmaecidos com sua última leitura por até 30 minutos. O suporte abrange o relatório `07` do Nordic 54L e o legado `BB` (VT3 Pro, VT1 Pro Max); relatório `08` do CH584, mouses de escritório série MT/M e outros protocolos de firmware não são cobertos por este driver.
- **GameSir Cyclone Pro:** o dongle não carrega o nível de bateria, então ele é lido do controle via Bluetooth LE. Pareie o controle com o Windows uma vez (Configurações > Bluetooth e dispositivos > Adicionar dispositivo > Bluetooth > `GameSir-Cyclone Pro`) e continue jogando pelo dongle. O PC precisa de Bluetooth. O nível é atualizado a cada 2 minutos e não há porcentagem durante o carregamento. Sem o pareamento, o dongle aparece como um controle Xbox em "Cheia". Detalhes em [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM:** o mouse é consultado através do receptor, então um mouse em repouso não responde; ele permanece esmaecido com sua última leitura por até 30 minutos e adiciona cerca de um segundo a uma atualização enquanto estiver em repouso. Apenas o Leviathan V4 no RAWM HS Receiver (`1915:2346`) foi testado; os outros modelos foram obtidos da tabela de dispositivos do RAWM HUB. O Leviathan V4 GT e o NYX60 (VID `373E`, RAWM HUB 3.0) e os teclados RAWM HS usam outros protocolos e não são cobertos.
- **Flydigi:** este driver visa o Vader 5 Pro e o Apex 5; Bluetooth e outros modelos Flydigi (por exemplo, Apex 6) não são cobertos. As porcentagens representam níveis aproximados de bateria. O Apex 5 foi testado em hardware real pelo receptor 2.4 GHz e cabo USB; o Vader 5 Pro segue o SDL e rastreamentos de hardware no Windows.
- **Ainda não suportados:** mouses sem fio MSI além do VERSA 300 ELITE e dos CLUTCH GM31 / GM41, teclados sem fio MSI, headsets Razer Kraken e modelos Barracuda além do Barracuda X (2022) em `1532:0550`, mouses HyperX Pulsefire além do Haste 2 Wireless / Haste 2 Core Wireless e o Xbox Wireless Headset no adaptador Xbox: seus protocolos de bateria não são documentados. O Xbox Wireless Headset funciona via Bluetooth. Uma captura USB de um proprietário (veja CONTRIBUTING.md) é o caminho para adicioná-los.
- **Outros dispositivos:** alguns dispositivos 2.4 GHz usam protocolos não documentados e ainda não são suportados. Veja [CONTRIBUTING.md](#sec-contributing) para saber como ajudar a adicionar um.

## Como funciona

Cada driver de fabricante em [`src/drivers/`](../../src/drivers) reconhece seus dispositivos pelo vendor ID e product ID USB, e só envia consultas de bateria somente leitura. Dispositivos desconhecidos nunca recebem escrita. Os fallbacks genéricos (HID battery usage, Bluetooth, XInput, HeadsetControl) verificam apenas dispositivos que nenhum driver de fabricante reivindicou.

O widget da barra de tarefas é uma janela filha com camadas de `Shell_TrayWnd`, posicionada à esquerda de `TrayNotifyWnd`. Se o Explorer reiniciar, ela é recriada.

## Traduções

Cada idioma de interface é um arquivo de texto UTF-8 estático simples em [`lang/`](../../lang): inglês à esquerda, tradução à direita. Os arquivos de idioma são carregados do disco em tempo de execução em vez de compilados no executável, então você pode editá-los diretamente sem recompilar.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **Interface do app (Windows e Linux):**
  - Edite ou adicione arquivos `.json` diretamente dentro da pasta `lang/` ao lado de `BatteryHub.exe` (ou `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/`, ou `./lang/` no Linux).
  - Ou escolha *Idioma → Adicionar seu próprio idioma...* no menu para preparar sua pasta de substituição de usuário (`%APPDATA%\WirelessBattery\lang` no Windows, `~/.config/wireless-battery/lang` no Linux) com `_template.json`. Copie `_template.json` para, por exemplo, `it.json`, preencha `@code`, `@name` e as traduções, e ele aparecerá no menu (sem precisar reiniciar). Arquivos na pasta do usuário substituem frases integradas com o mesmo `@code`.
  - Mantenha os `{placeholders}` exatamente como estão e adicione `"@rtl": true` para escritas da direita para a esquerda. Frases deixadas vazias continuam em inglês, portanto uma tradução parcial funciona perfeitamente.
  - As saídas de `--list` e `--dump` permanecem em inglês propositalmente: elas são coladas em issues do GitHub.
- **Instalador do Windows:** as traduções do Inno Setup ficam em [`installer/lang/`](../../installer/lang) (salvas como UTF-8 com BOM) e são registradas em `[Languages]` no `installer/BatteryHub.iss`.
- **Documentação:** todo documento visível do projeto é traduzido em um único arquivo Markdown independente por idioma em [`docs/i18n/`](README.md) (veja [`docs/i18n/_template.md`](_template.md) para adicionar um novo idioma sem precisar de scripts de build).
- **Compartilhe com todos:** envie um pull request adicionando seus arquivos em `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` e `docs/i18n/`. Veja [`docs/i18n/README.md`](README.md) para o checklist passo a passo.

## Créditos

Ícone do app por [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

Os protocolos vêm das pesquisas destes projetos:

- [Especificação Google Fast Pair](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): transmissões de bateria esquerdo / direito / estojo de fones Fast Pair
- [Drivers Astro do HeadsetControl](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) e [AstroBar](https://github.com/nichtlegacy/AstroBar): protocolos de bateria Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): leitura de status `0x72` do A50 Gen 3

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): comandos de bateria e carregamento VAXEE ([documentação do protocolo](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): headsets SteelSeries, Corsair, HyperX, Logitech e Sony INZONE
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) e [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) e os documentos HID++ 2.0 da Logitech: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) e [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (dongle `0ADF`)
- [rivalcfg](https://github.com/flozz/rivalcfg): mouses SteelSeries (Rival Pro do pull request #294)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) e [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Configurador web da Hitscan ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- `hid-kysona` do Linux (Lode Willems): Kysona, Pulsar e ATK
- Configurador web da ATK ([hub.atk.pro](https://hub.atk.pro)): mouses ATK e os headsets N9 Pro / N9 Ultra
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 e [mouse-battery](https://github.com/qwr79/mouse-battery): dongle ATK / VXE NK NANO
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X e Endgame Gear XM2we, portados a partir de seus provedores (cada driver cita sua fonte)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` e [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (apenas descobertas): a família de dispositivos Turtle Beach Swarm II
- Driver web da G-Wolves ([mouse.xyz](https://mouse.xyz)): modelos G-Wolves e seus protocolos
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): teclados CHERRY no dongle 2.4 GHz (formato de quadro e consulta de bateria)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): mouses Keychron
- [NinjaForce](https://www.ninjaforce.co/) e [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): consultas de recurso Ninjutso Ten / Ten Air
- [nape_pro](https://github.com/nvalis/nape_pro) e [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro no receptor Link-KM
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): mouses LAMZU
- [vole](https://github.com/johanneszab/vole) e [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): mouses Endgame Gear 4K
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) e [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) e [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (do xpanel da Finalmouse)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) e [g49-web-control](https://github.com/pingpingjinping/g49-web-control): IDs Redragon
- [m913-ctl](https://github.com/Qehbr/m913-ctl) e [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): layout de quadro Areson `25A7` e comando `GetPower`
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) e [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW e DW
- Driver web da RK ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) e [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (docs): MCHOSE A5 Pro / A5 Pro Max (primeira geração, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): relatórios do receptor CompX para Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) e [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) e [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- O driver web da Wraith ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 e [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 e [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) e [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) no receptor `1532:0550`; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): enquadramento do receptor `1532:0552`
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): receptores Rongyuan e Xenta (Attack Shark e outros)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): teclados SONiX em seu dongle 2.4G (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) e [ak820-studio](https://github.com/usharik/ak820-studio): receptor AJAZZ AK820 Pro `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) e [Kraber](https://github.com/AkashPanja/Kraber): protocolo de status Semico `1A2C` (`AA 55 CC 33` / `0x0E`) para Attack Shark X98 e AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) e [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 e MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) e [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): solicitação de bateria "base info" Bluetooth LE do GameSir Cyclone Pro
- [jabridge](https://github.com/Watchdog0x/jabridge): protocolo Jabra GNP (dongles Link 380 / 390)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): protocolo da página de status `1EA7:0066` (Fantech Raigor III e outros dispositivos genéricos 2.4G Mouse)
- `hid-playstation` do Linux: layout de relatório do DualShock 4 / DualSense
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): protocolo de fabricante AULA SC580 / SC580X
- Aplicativo web RAWM HUB ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) e sua tabela de dispositivos: mouses RAWM e SADES Dagger
- [Driver HID Flydigi do SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) e [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): enquadramento de consulta e layout de bateria do Vader 5 Pro e Apex 5
- [Driver HID 8BitDo do SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): byte de bateria do 8BitDo Ultimate 2
- BEITONG iControl (suas páginas KP20 e KP40D e o tráfego USB do receptor KP20): consulta de bateria e embaralhamento de payload do BEITONG KP20 / KP40D
- [Driver HID 8BitDo do SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) e [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): byte de bateria e protocolo HID de fabricante da 8BitDo
- JBL QuantumENGINE (suas mensagens de informações do dispositivo HIDV3): headsets JBL Quantum
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, protocolo Compx em `FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) e [BrimDeck](https://github.com/MoFeng2223/BrimDeck): leitura de perfil do Scyrox V12M
- JBL QuantumENGINE: relatórios de conexão e bateria HIDV1 para o Quantum 350, e mensagens de informações do dispositivo HIDV3 para headsets Quantum mais recentes
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): relatórios HIDV1 de bateria e link do JBL Quantum 610 e a linha Quantum (360 como modelo de dongle HIDV1)

## Licença

[GNU General Public License v3.0 ou posterior](../../LICENSE). Você pode usar, modificar e redistribuir este
software, mas qualquer coisa que você distribuir baseada nele deverá ser lançada sob a mesma licença,
com o respectivo código-fonte.


---

<a id="sec-contributing"></a>
> 📄 **Seção:** Guia de contribuição (`CONTRIBUTING.md`) · [Original em inglês](../../CONTRIBUTING.md) · [↑ Topo](#top)

# Contribuindo

## Informando se um dispositivo funciona

A maioria dos drivers foi escrita a partir de documentação de protocolo e não pôde ser testada em todos os modelos.
Abra uma issue com:

- o nome do dispositivo e se ele está conectado por receptor, cabo ou Bluetooth
- a saída de `BatteryHub.exe --list`
- a saída de `BatteryHub.exe --dump`
- o que o software próprio do fabricante exibe como nível de bateria

## Adicionando um dispositivo

1. Execute `BatteryHub.exe --dump` e encontre o vendor ID e o product ID do seu dispositivo, além das
   coleções definidas pelo fabricante (usage page `FFxx`) com seus tamanhos de relatório.
2. Descubra o protocolo de bateria. Bons lugares para procurar: HeadsetControl, OpenRazer, Solaar, rivalcfg,
   OpenRGB, OpenLinkHub ou uma captura USB do software do fabricante (Wireshark + USBPcap).
3. Se o fabricante já tiver um driver em `src/drivers/`, adicione o product ID (e quaisquer diferenças) lá.
   Caso contrário, crie `src/drivers/<vendor>.cpp`:

   ```cpp
   #include "drivers.h"

   void PollAcme(PollContext& ctx) {
       for (auto [vid, pid] : ctx.Products(0x1234)) {           // produtos ainda não reivindicados deste fabricante
           for (const HidColl* c : ctx.Find(vid, pid, [](const HidColl& c) { return c.page() == 0xFF00; })) {
               HidDev d;
               if (!d.Open(*c)) continue;
               std::vector<BYTE> r;
               if (!d.Write({ 0x01, 0x02 }) || d.Read(r, 500) < 3) continue;   // buffers no estilo hidapi
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

4. Declare a função em `src/drivers/drivers.h` e chame-a em `PollAllDevices()` em
   `src/devices.cpp` (antes dos fallbacks genéricos). O `build.bat` e o Makefile detectam novos arquivos automaticamente.
5. Atualize a tabela de dispositivos no `README.md`.

### Regras para drivers

- **Somente leitura:** envie apenas solicitações que leem o estado. Nunca altere configurações, iluminação ou modos.
- **Correspondência exata:** comunique-se apenas com dispositivos reconhecidos por vendor e product ID, ou por uma
  coleção específica do fabricante que seja exclusiva do protocolo.
- **Sempre use timeout:** um dispositivo ausente não pode travar a consulta por mais de cerca de um segundo.
  Protocolos passivos podem precisar de mais tempo para cobrir um intervalo de envio documentado (por exemplo, Delux e
  Rapoo). Mantenha um único prazo absoluto de no máximo 4 segundos por coleção correspondente, não o
  reinicie por relatórios não relacionados e documente por que a exceção é necessária.
- **Dê crédito às fontes:** cite de onde vem o protocolo em um comentário no topo do arquivo.

## Traduções

Os idiomas da interface são arquivos de texto UTF-8 estáticos simples em `lang/` carregados do disco em tempo de execução no Windows e no Linux (copie `lang/_template.json` para `lang/<code>.json`, preencha `@code`, `@name` e as frases — sem precisar recompilar). Novos textos de interface no código passam por `T(L"...")` ou `TF(L"... {name} ...", { { L"name", value } })` quando contêm valores; nunca monte frases traduzidas a partir de pedaços. Após adicionar frases, adicione-as também em `lang/_template.json`.

As traduções do instalador do Windows ficam em `installer/lang/*.isl` (salvas como UTF-8 com BOM e registradas em `installer/BatteryHub.iss`), os comentários do lançador Linux ficam em `linux/wireless-battery.desktop` e as traduções completas da documentação ficam em `docs/i18n/<code>.md` (arquivo único independente copiado de `docs/i18n/_template.md`). Veja [`docs/i18n/README.md`](README.md) para o guia completo do contribuidor.

## Estilo de código

C++17, apenas Win32, sem dependências de terceiros. Mantenha o binário pequeno. Formate de modo semelhante ao
código existente (indentação de 4 espaços, linhas de 120 colunas).

## Desenvolvimento do atualizador do Windows

O atualizador é exclusivo para Windows e usa WinHTTP, BCrypt e o instalador Inno Setup existente.
Mantenha o status de atualização exclusivamente no menu. Não adicione ícones de atualização, emblemas, alterações na dica
da bateria, balões, toasts ou caixas de diálogo automáticas. A consulta aos dispositivos roda separadamente do trabalho de rede.

A versão de compilação e o canal são compartilhados entre C++ e o recurso do Windows através do arquivo gerado
`build/version.h`. Use `make VERSION=1.2.3 CHANNEL=test` ou `build.bat 1.2.3 test` para testes locais;
`dev` é o padrão e `stable` habilita verificações oficiais de lançamento. Os componentes da versão
devem caber em 0..65535. Apenas o fluxo de trabalho de tag de lançamento do repositório oficial seleciona `stable`
automaticamente. Não transforme acidentalmente uma compilação de fork em um canal oficial de atualização.

Execute `make test VERSION=1.2.3 CHANNEL=test` para rodar os testes de dispositivos existentes mais análise rigorosa de lançamento,
ordenação de versões, agendamento de verificação, verificações reais de arquivos SHA-256, escape de argumentos e proteções do assistente.
Regressões do atualizador também cobrem cancelamento na conclusão do download, proteções de diálogo e falha ao
configurar timeouts HTTP/restrições de redirecionamento. O teste do Windows inclui as implementações,
seguindo o padrão de teste do backend Linux existente, e substitui o envio HTTP para que esses testes
não consigam acessar o GitHub. Nenhum ponto de entrada de controlador exclusivo para testes é adicionado à produção.
Os alvos individuais são `make test-update-core` e `make test-update-win`. Os testes nativos do atualizador
vinculam o recurso do aplicativo para ativar o Common Controls v6. Os testes usam dados locais e não
baixam, elevam privilégios, instalam nem alteram as configurações de inicialização do usuário. O endpoint de produção do aplicativo
não pode ser substituído nos testes.

Antes de empacotar, execute
`powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`.
`installer/build-installer.ps1 -Version 1.2.3` também executa essa verificação antes de baixar dependências.
O caminho do instalador `/WBUPDATE=1` preserva a inicialização/configurações existentes e deixa o reinício a cargo do
assistente temporário. Esse assistente permanece sob o usuário original, elevando apenas uma instalação global.
Os handles WinHTTP pertencem ao worker; o cancelamento é cooperativo entre chamadas com timeout finito.
O encerramento final do aplicativo aguarda a conclusão desse worker e, portanto, pode esperar por um timeout de rede em andamento.

Para uma revisão de lançamento, use uma conta ou VM descartável do Windows para exercitar duas versões reais do
instalador, escopo por usuário/global, cancelamento de UAC, inicialização ativada/desativada, caminhos personalizados, falha na instalação
e reabertura. Testes unitários e compilar um pacote não verificam esses efeitos do instalador. A revisão visual de
menu/tema e os testes ponta a ponta reais de instalador/UAC continuam sendo portões manuais de lançamento; não os
marque como aprovados a menos que realmente observados. Nunca teste sobrescrevendo a instalação diária do usuário.

## Verificação automática de segurança

Todo pull request é examinado pelo "PR safety check" em busca de coisas que este aplicativo nunca deve fazer (acesso à rede,
execução de programas, leitura de teclado/área de transferência/tela, entradas de inicialização, binários, alterações de compilação ou
lançamento). Uma sinalização não é uma rejeição: apenas explique as linhas sinalizadas na descrição do PR.

Usar ferramentas de IA é permitido, mas remova linhas `Co-authored-by` que deem crédito a elas (por exemplo
`Co-authored-by: Claude ...`) das mensagens de commit. A verificação falha enquanto elas estiverem presentes.


---

<a id="sec-pr-template"></a>
> 📄 **Seção:** Modelo de Pull Request (`.github/pull_request_template.md`) · [Original em inglês](../../.github/pull_request_template.md) · [↑ Topo](#top)

## O que isto adiciona

<!-- Dispositivo(s) e vendor/product IDs, ex.: "Acme M1 (1234:5678)". -->

## De onde vem o protocolo

<!-- Informe o link da fonte (outro projeto, um driver web do fabricante, sua própria captura USB). -->

## Testado em hardware real?

<!-- Sim (qual dispositivo, o que o --list imprimiu) / Não -->

## Checklist

- [ ] Apenas consultas de bateria somente leitura são enviadas; nenhuma configuração, iluminação ou firmware é alterado
- [ ] Apenas dispositivos reconhecidos por vendor/product ID (ou uma coleção específica do protocolo) são acessados
- [ ] Sem acesso à rede, sem executar outros programas, sem novos arquivos fora de `src/`, `docs/` ou `README.md`
- [ ] Nenhum binário ou arquivo gerado está incluído
- [ ] Nenhuma linha `Co-authored-by` dando crédito a ferramentas de IA (Claude, Copilot, ChatGPT ...) nas mensagens de commit
- [ ] Alterações em `.github/`, `installer/`, `build.bat` ou `Makefile` estão explicadas acima


---

<a id="sec-releasing"></a>
> 📄 **Seção:** Lançamentos (`docs/releasing.md`) · [Original em inglês](../../docs/releasing.md) · [↑ Topo](#top)

# Lançamentos

O aplicativo se atualiza a partir dos lançamentos do GitHub, mas só instala um executável de instalação cujo SHA-256 esteja listado em
um `SHA256SUMS.txt` assinado com a chave de lançamento. Essa chave fica no PC do mantenedor, nunca no
GitHub: uma conta, token ou workflow comprometidos podem publicar arquivos, mas não uma assinatura que o aplicativo aceite.

## Uma única vez: criar a chave de lançamento

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Solicita uma senha (12+ caracteres) e grava a chave privada criptografada em
  `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- Coloca a chave pública em `src\update_public_key.h`. Faça commit desse arquivo. Compilações oficiais recusam
  compilar sem uma chave nele.
- **Faça backup do arquivo da chave e guarde a senha** (um gerenciador de senhas é um bom lugar para ambos).
  Se qualquer um deles for perdido, os aplicativos instalados não poderão mais se atualizar sozinhos: você teria de criar uma nova
  chave e cada usuário precisaria instalar uma versão manualmente.

## A cada lançamento

1. Envie uma tag de versão (`git tag v1.2.3 && git push origin v1.2.3`). A CI compila o instalador, o
   zip portátil e o `SHA256SUMS.txt`, e publica o lançamento.
2. Assine a lista de checksums:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Ele baixa `SHA256SUMS.txt` do lançamento, exibe o conteúdo, pede sua confirmação, solicita a senha da chave
   e grava `SHA256SUMS.txt.sig`. Se você tiver os mesmos arquivos em `dist\` (uma compilação local dessa
   versão), ele mostra se eles conferem.
3. Envie `SHA256SUMS.txt.sig` para o lançamento (o script abre a página de edição). A partir daí o aplicativo
   oferece **Baixar e instalar**. Antes disso, ele mostra a atualização, mas apenas aponta para a página de lançamento.

Assine apenas a lista de um lançamento que você mesmo publicou. A assinatura afirma "estes arquivos exatos são o
lançamento", portanto a assinatura é a etapa em que um envio malicioso seria detectado.

## Trocando a chave

Execute `new-release-key.ps1` com um novo `-KeyFile`: ele adiciona a nova chave pública ao lado da antiga em
`src\update_public_key.h`. Lance uma versão assinada com a chave antiga que contenha ambas, depois assine
com a nova chave a partir do próximo lançamento e remova a chave antiga mais tarde. Uma chave perdida ou vazada
não pode ser aposentada dessa forma: remova-a do cabeçalho, e usuários de versões mais antigas precisarão instalar
o próximo lançamento manualmente.

## O que o aplicativo verifica antes de executar um instalador

- O lançamento é o mais recente do repositório, não é rascunho nem pré-lançamento, e é mais novo que o aplicativo.
- `SHA256SUMS.txt.sig` é uma assinatura ECDSA P-256 válida de `SHA256SUMS.txt` por uma chave em
  `src\update_public_key.h` (Windows BCrypt, sem código de terceiros).
- A lista assinada cita `BatteryHub-Setup-<version>.exe` exatamente uma vez, com o mesmo SHA-256
  que o GitHub informa para o arquivo.
- O instalador baixado tem exatamente esse tamanho e SHA-256. Uma cópia do aplicativo o verifica novamente
  logo antes de iniciá-lo, e mantém o arquivo bloqueado para que não possa ser substituído no intervalo.
- Os downloads usam apenas HTTPS para `github.com`, `objects.githubusercontent.com` e
  `release-assets.githubusercontent.com`, com cada redirecionamento verificado.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Seção:** Firmware para teclados Keychron (`docs/keychron_keyboard_firmware/README.md`) · [Original em inglês](../../docs/keychron_keyboard_firmware/README.md) · [↑ Topo](#top)

# Bateria de teclado Keychron pelo receptor 2.4 GHz

O firmware original da Keychron só reporta a bateria do teclado via Bluetooth. Com a pequena alteração de QMK em
[`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch), o teclado também responde a uma consulta de bateria (`A4`) pelo
receptor Keychron Link e pelo cabo USB, e o BatteryHub mostra seu nível, tensão e estado de carregamento.

Testado no **Keychron K5 Max ANSI RGB** (`3434:0A50`) com o receptor Keychron Link (`3434:D030`).

## O que o patch altera

Baseado no branch `2025q3` de [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) (commit `57e682c`):

- adiciona o comando raw HID `KC_GET_BATTERY` (`0xA4`) de [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1):
  resposta `[A4][porcentagem][mV lo][mV hi][carregando: 0 bateria / 1 carregando / 2 cheio][transporte][id do modelo]`;
- encaminha requisições raw HID que chegam pelo link sem fio para o mesmo manipulador;
- em `keyboards/keychron/k5_max/config.h`: `#define WILRESS_RAW_ENABLE` (escrito assim no código da Keychron) e
  `#define KC_BATTERY_MODEL_ID 0`.

Nada mais muda: mapas de teclas, iluminação e o Keychron Launcher continuam funcionando.

## Opção 1: gravar o firmware pronto do K5 Max

Uma compilação **apenas para o K5 Max ANSI RGB** está anexada a
[este lançamento](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1)
(`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`).
Não grave em outro modelo ou layout.

## Opção 2: compilar você mesmo

Precisa do Git e do Docker (ou de um [ambiente QMK](https://docs.qmk.fm/newbs_getting_started) funcionando).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

O resultado é `keychron_k5_max_ansi_rgb_keychron.bin` na raiz do repositório. No Windows, um checkout com
bind-mount é muito lento no Docker; clonar dentro do contêiner (ou no WSL) é muito mais rápido.

**Outros teclados sem fio Keychron** (Q/V/K Max e outros modelos na árvore `2025q3` com `LK_WIRELESS_ENABLE`):
as alterações em `keyboards/keychron/common/` se aplicam como estão. Adicione as duas linhas `#define` ao `config.h`
do seu teclado em vez do K5 Max e compile seu próprio alvo, por exemplo `make keychron/<model>/<layout>/<variant>:keychron`.
Atualmente o aplicativo nomeia um K5 Max (`0A50`–`0A58`) pelo modelo e qualquer outro como "Keychron keyboard".

## Gravação (Flashing)

1. Coloque a chave de modo em **Cable** e desconecte o cabo USB.
2. Segure **Esc** enquanto conecta o cabo. O teclado entra no bootloader STM32.
3. Grave o `.bin` com o [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (ou `dfu-util`).
4. Volte para **2.4 GHz** e confira com `BatteryHub.exe --list`:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Atualizar o teclado pelo Keychron Launcher substitui este firmware e remove o relatório de bateria. Para desfazer,
grave o firmware oficial da Keychron da mesma maneira.

## Licença

O QMK está sob GPL-2.0-or-later; o patch está sob a mesma licença. Qualquer pessoa que receba um binário compilado a partir dele também
deve poder obter esta alteração do código-fonte.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Seção:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [Original em inglês](../../docs/gamesir_cyclone_pro.md) · [↑ Topo](#top)

# Suporte à bateria do GameSir Cyclone Pro

## Por que o controle aparecia como um controle Xbox com carga cheia

O Cyclone Pro (modelo T4cp) funciona por meio de um dongle 2.4 GHz, `3537:1015`. O dongle se apresenta
ao Windows como um controle Xbox 360 com fio (XUSB, `Xbox 360 Controller for Windows`). O XInput responde
à consulta de bateria como "Full", então o fallback XInput o listava como `Xbox controller 1` em 100%,
qualquer que fosse a carga real.

O dongle não carrega nenhuma informação de bateria:
- sua única coleção HID é o controle de jogo XInput (`HID\VID_3537&PID_1015&IG_00`)
- ele não possui coleção definida pelo fabricante como o Nova (`FF7A`) ou o Cyclone 2 (`FFF0`)

## Onde está o nível

Enquanto funciona pelo dongle, o controle também anuncia via Bluetooth LE como
`GameSir-Cyclone Pro`, que é o enlace usado pelo app de celular da GameSir. Sua solicitação "get base info"
retorna a bateria:

| Etapa | Detalhe |
|---|---|
| Serviço | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Característica | `0x865F` (notify, write without response) |
| Solicitação | habilitar notificações, escrever `01 01` |
| Resposta | notificação de 19 bytes (alguns firmwares prefixam com `C9`, 20 bytes) |

Layout da resposta:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

O byte 18 é a bateria em porcentagem (0-100), ou `FF` enquanto carrega. Nenhum nível é informado enquanto
carrega, então a última porcentagem conhecida é mantida e exibida com o raio de carregamento.

O controle também tem o serviço `0xFF10`, que é o canal de atualização de firmware da GameSir. O driver nunca o
abre. O controle não tem o Battery Service padrão (`0x180F`), razão pela qual a página de Bluetooth do Windows e
o fallback Bluetooth não exibem nível para ele.

Fonte: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), onde o protocolo foi
descoberto a partir do aplicativo Android da GameSir (`BluetoothLeService`, "get base info").

## Como o driver funciona

`src/drivers/gamesir_ble.cpp`, chamado antes do fallback XInput:

1. **Encontrar o controle.** Ele procura interfaces de dispositivo da classe `{00008650-0000-1000-8000-00805F9B34FB}`.
   O Windows cria uma para cada serviço GATT de um dispositivo BLE pareado. Ele usa apenas aquelas cujo nó pai
   `BTHLE\DEV_…` se chama `GameSir-Cyclone…`.
2. **Ler a bateria.** Ele abre esse serviço com a API Win32 GATT (`bluetoothleapis.h`,
   `-lbluetoothapis`), assina `0x865F` e grava `01 01`. Aguarda até 3 segundos pela
   resposta e depois desativa as notificações.
3. **Manter a consulta rápida.** A conexão BLE pode levar segundos ou expirar enquanto o controle está
   em repouso, então a consulta roda em sua própria thread:
   - no máximo a cada 2 minutos após uma leitura bem-sucedida, ou a cada minuto após uma falha
   - a consulta reporta a leitura em cache e para de reportá-la quando tiver 6 minutos de idade
   - `graceSec` então a mantém visível, esmaecida, como em repouso
   - apenas a primeira consulta de uma execução aguarda pela thread, uma vez, com prazo absoluto de 4 segundos,
     para que o nível apareça ao iniciar e no `--list`
4. **Ocultar a entrada Xbox falsa.** Quando o dongle está presente, o driver reivindica `3537:1015`:
   - o caminho Windows.Gaming.Input agora ignora vendor/product IDs reivindicados
   - o caminho XInput obtém o vendor/product ID de cada slot via `XInputGetCapabilitiesEx` (xinput1_4
     ordinal 108) e ignora os reivindicados
   - quando esse export está ausente, o XInput se comporta como antes

## Hardware testado

Windows 11, Cyclone Pro em seu dongle (`3537:1015`), pareado uma vez via Bluetooth, em 2026-11-18:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Enquanto o controle estava em repouso, a entrada "Xbox controller 1 / Full" não aparecia mais e nada era
exibido para o controle.

## Limitações

- **Pareamento:** o controle deve ser pareado com o Windows uma vez (Configurações > Bluetooth e dispositivos > Adicionar dispositivo >
  Bluetooth > `GameSir-Cyclone Pro`). Controles não pareados não têm interface de dispositivo GATT. O pareamento adiciona
  entradas de gamepad Bluetooth, mas elas não enviam entrada enquanto o controle funciona pelo dongle.
- **Bluetooth obrigatório:** o PC precisa de Bluetooth LE.
- **Um controle:** apenas um Cyclone Pro por PC é lido.
- **Carregamento:** não há porcentagem durante o carregamento.


---

<a id="sec-localization-guide"></a>
> 📄 **Seção:** Uso em vários idiomas e guia de localização (`docs/i18n/README.md`) · [Original em inglês](../../docs/i18n/README.md) · [↑ Topo](#top)

# Índice multilíngue e guia de localização do BatteryHub

Todo documento visível neste repositório é reunido em **um arquivo Markdown independente por idioma** dentro de `docs/i18n/`, enquanto todas as strings de execução do aplicativo ficam em **arquivos de texto estáticos editáveis** dentro de [`lang/`](../../lang) (compartilhados por Windows e Linux) e as strings do instalador do Windows ficam em [`installer/lang/`](../../installer/lang).

## Idiomas suportados (19)

| Código | Idioma | Documentação completa | Interface do app (Windows e Linux) | Instalador do Windows |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (strings de origem) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Como a troca de idioma funciona na prática

### 1. App Windows (`BatteryHub.exe`)
- **Detecção automática:** Quando definido para *Idioma → Automático (idioma do Windows)*, o BatteryHub consulta `GetUserPreferredUILanguages` do Windows e seleciona o arquivo estático `*.json` mais próximo.
- **Troca manual:** Clique no widget da barra de tarefas ou no ícone da bandeja → **Idioma** → escolha um idioma. A interface atualiza imediatamente e é salva em `HKCU\Software\WirelessBattery\Language`.
- **Arquivos externos estáticos (editáveis sem recompilar):** `BatteryHub.exe` carrega `<exe>\lang\*.json` primeiro e depois `%APPDATA%\WirelessBattery\lang\*.json`. Qualquer arquivo na pasta do usuário com o mesmo `@code` substitui as frases correspondentes, e reabrir o menu recarrega os arquivos do disco em tempo real.
- **CLI `--help`:** `BatteryHub.exe --help` exibe a caixa de diálogo de ajuda no seu idioma de interface ativo (`--list`, `--json` e `--dump` permanecem em inglês propositalmente para relatórios de issues no GitHub).

### 2. App Linux (`wireless-battery`)
- **Detecção automática:** Segue as variáveis de locale POSIX em ordem: `LANGUAGE` (lista separada por dois-pontos) → `LC_ALL` → `LC_MESSAGES` → `LANG` (a menos que seja substituído por `LC_ALL=C` / `POSIX`).
- **Troca manual:** Clique com o botão direito no ícone da bandeja → **Idioma** → escolha **Automático (idioma do sistema)** ou qualquer idioma instalado. Salvo em `[general] language=` em `$XDG_CONFIG_HOME/wireless-battery/config.ini` (padrão `~/.config/wireless-battery/config.ini`).
- **Caminhos de busca estáticos (da menor para a maior prioridade):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (padrão `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (padrão `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help` imprime a ajuda da CLI traduzida com base em `config.ini` ou no locale do sistema; `--list` e `--dump` permanecem em inglês.

### 3. Instalador do Windows (`BatteryHub-Setup-<version>.exe`)
- Solicita com um seletor de idioma (`ShowLanguageDialog=yes`) pré-selecionado a partir do idioma da interface do Windows (`LanguageDetectionMethod=uilanguage`).
- Instala todo o diretório estático `lang\*.json` em `{app}\lang\` ao lado de `BatteryHub.exe` (e o ZIP portátil também traz `lang\*.json`).

---

## Como adicionar ou atualizar um idioma (passo a passo)

Você **não** precisa de nenhuma ferramenta de compilação para traduzir a interface do app ou a documentação, e só precisa do Inno Setup 6 se quiser testar a compilação do instalador do Windows.

### Passo 1 — Strings da interface do app (`lang/<code>.json`)
1. Abra a pasta de idiomas do usuário pelo menu da bandeja (**Idioma → Adicionar seu próprio idioma...**) ou copie [`lang/_template.json`](../../lang/_template.json) para `lang/<code>.json` (por exemplo `lang/it.json`).
2. Preencha o cabeçalho de metadados:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Traduza o lado direito após ` = ` em cada linha.
   - Mantenha placeholders como `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}` exatamente como estão.
   - Use `\n` para quebras de linha explícitas.
   - Salve como **UTF-8 (sem BOM)**.
   - Reabra o menu da bandeja do BatteryHub para pré-visualizar imediatamente — sem precisar recompilar!

### Passo 2 — Instalador do Windows (`installer/lang/<code>.isl`)
1. Copie [`installer/lang/_template.isl`](../../installer/lang/_template.isl) para `installer/lang/<code>.isl`.
2. **CRÍTICO:** Salve o arquivo como **UTF-8 com BOM (`EF BB BF`)** para que o Inno Setup decodifique caracteres Unicode de maneira confiável, independentemente das páginas de código legadas do Windows.
3. Escolha o padrão correspondente:
   - **O Inno Setup já inclui seu idioma** (verifique em `C:\Program Files (x86)\Inno Setup 6\Languages\`): mantenha apenas `[CustomMessages]` e traduza as 6 linhas (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, preservando `%1` e `%n`). Registre em `installer/BatteryHub.iss` em `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **O Inno Setup não inclui seu idioma**: copie `installer/lang/zh-CN.isl` como referência completa, defina `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, opcional `RightToLeft=yes`), traduza `[Messages]` e `[CustomMessages]`, e registre após `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Nota: identificadores `Name:` em `[Languages]` devem conter apenas letras ASCII, dígitos e sublinhados (use `ptBR`, não `pt-BR`).

### Passo 3 — Lançador desktop do Linux (`linux/wireless-battery.desktop`)
Adicione uma linha localizada `Comment[<code>]=...` (use sublinhados para tags regionais em arquivos `.desktop`, por exemplo `Comment[zh_CN]=...`).

### Passo 4 — Documentação completa em arquivo único (`docs/i18n/<code>.md`)
1. Copie [`docs/i18n/_template.md`](_template.md) para `docs/i18n/<code>.md` (zero scripts geradores necessários — apenas este arquivo!).
2. Traduza o Índice e todas as 17 seções na íntegra mantendo:
   - Todas as tags âncora `<a id="sec-..."></a>` e `<a id="top"></a>` intactas
   - Todos os blocos de código, flags de CLI (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), `VID:PID`s USB, usage pages HID, pacotes hexadecimais, chaves do Registro, caminhos de arquivo e URLs exatamente como estão
   - Caminhos relativos de imagens/arquivos intactos (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE` etc.)
3. Atualize a barra superior `<!-- lang-switcher:start -->` em `docs/i18n/<code>.md` (coloque seu próprio idioma em negrito e vincule todos os demais), adicione o link do seu idioma às barras seletoras em `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` e nos arquivos irmãos `docs/i18n/*.md`.
4. Para idiomas da direita para a esquerda (`ar`, `fa`, `he`), escreva Markdown padrão sem envolver o arquivo inteiro em `<div dir="rtl">` para que tabelas e blocos de código sejam renderizados corretamente.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Seção:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [Original em inglês](../../docs/ardor_fury_v2.md) · [↑ Topo](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

O receptor 2.4 GHz expõe a usage page HID `000A`, usage `0000`, e um
input report de 5 bytes. Ele transmite dados passivamente; nenhum comando HID é enviado.

Relatórios observados em hardware real:

| Relatório | Bateria |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

O nibble alto do byte 3 codifica o nível (`1`, `3`, `7`, `F` para
25, 50, 75 e 100 por cento). Os relatórios de 25% e 100% são inferidos
a partir da lógica de decodificação do aplicativo do fabricante; posteriormente o usuário final
confirmou que os níveis restantes são exibidos corretamente no aplicativo compilado.
O quinto byte não é constante e não é usado como assinatura.

O ouvinte precisa de dois níveis de bateria decodificados concordantes, em vez de dois
relatórios inteiros idênticos. O último valor confirmado é mantido por até
45 segundos. O intervalo global de atualização automática muda para 15 segundos.

Validado pelo usuário final no Windows com ARDOR Fury V2 e Logitech G733:
capturas de 50% e 75%, atualização automática periódica, verificações visuais de 25%/100%
e inicialização portátil. Os relatórios de 25% e 100% não foram capturados.


---

<a id="sec-areson"></a>
> 📄 **Seção:** Areson `25A7` (`docs/areson.md`) · [Original em inglês](../../docs/areson.md) · [↑ Topo](#top)

# Suporte à bateria de receptores Areson 25A7

## Por que o programa original não detectava o mouse

O Redragon M915RGB-WL se conecta através de um "2.4G Wireless Receiver" Areson/CompX `25A7:FA07`.
Sua bateria não é exposta como um usage HID padrão *Battery Strength* e o Windows não tem
propriedade de bateria Bluetooth para ele, porque o link é proprietário de 2.4 GHz. O mouse
responde a uma solicitação ativa `GetPower`, portanto nem o fallback HID genérico nem o
fallback Bluetooth conseguiam enxergá-lo. Não havia driver para o fabricante, então o receptor permanecia
não reivindicado e silencioso.

## Hardware e pacotes observados

Testado no Windows 11 com um Redragon M915RGB-WL em 2026-11-17:

| Direção | VID:PID | Interface | Usage page:usage | Tamanho do relatório |
|---|---|---|---|---|
| solicitação (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 bytes |
| resposta (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 bytes |

A resposta chega em uma top-level collection diferente daquela para a qual a solicitação é gravada.
No Windows elas são `MI_01&COL07` (feature) e `MI_01&COL05` (input), razão pela qual o driver
abre ambos os handles.

Solicitação capturada (`GetPower`, report ID `08`, comando `04`, o checksum faz a soma do quadro ser `0x55`):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Resposta capturada:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Os deslocamentos abaixo contam o report ID como byte zero:

| Byte(s) | Significado | Exemplo |
|---|---|---|
| 0 | Report ID da resposta | `09` |
| 1 | Eco do comando | `04` |
| 2 | Status, 0 = OK | `00` |
| 3–4 | Endereço, não usado para `GetPower` | `00 00` |
| 5 | Tamanho dos dados (2) | `02` |
| 6 | Nível da bateria, 0–10, em passos de 10% | `08` = 80% |
| 7 | Sinalizador de carregamento, qualquer valor diferente de zero | `00` = não está carregando |
| 16 | Checksum; todos os 17 bytes somam `0x55` (mod 256) | `3E` |

O próprio software do fabricante exibia 80% para o mesmo quadro, o que estabelece a escala ×10.
`GetConnectStatus` (`08 03 …`) responde com um payload de 1 byte e informou o mouse como
vinculado no mesmo momento.

## Outros mouses Areson

Os receptores mais antigos `FA7B` / `FA7C` usados pelo Redragon M693 informam a carga diretamente como uma
porcentagem inteira no mesmo deslocamento da resposta. Aplicar a escala ×10 deste driver lá mostraria
800%, portanto esses product IDs não são reivindicados propositalmente. Apenas `FA07` e `FA08` são tratados;
`FA08` é a identidade alternativa da mesma família e não foi verificada nesta máquina.

## Consulta e identidade

- O driver envia apenas a solicitação somente leitura `GetPower`. Ele nunca grava dados de configuração,
  iluminação ou DPI.
- Cada atualização abre a coleção feature com acesso zero e a coleção input para
  leitura, envia a solicitação e aguarda até 1,8 s por uma resposta, com duas tentativas e uma limpeza
  de fila entre elas para que um relatório antigo não seja confundido com a resposta.
- Uma leitura que falha não reivindica nada, então um mouse em repouso mantém o último valor na interface. A entrada
  usa um período de tolerância de 30 minutos, igual ao dos outros drivers passivos.
- A chave do dispositivo é derivada do vendor e do product ID (`areson:25A7:FA07`), de modo que sobrevive ao
  ciclo de recepção/repouso e à reconexão do receptor.

## Validação

O aplicativo completo foi compilado com MSVC C++17 e o Windows SDK e executado contra o mouse
real. `BatteryHub.exe --list` retornou:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

A leitura coincidiu com a porcentagem exibida pelo software oficial da Redragon no mesmo
instante. O `build.bat` do MinGW inclui o novo arquivo-fonte; o `Makefile` o descobre por meio do
seu curinga.

## Fontes do protocolo

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): quadros de 17 bytes, separação feature/input e a
  regra de checksum `0x55`, recuperados de capturas USB do software Redragon.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray):
  comando `GetPower` e a escala de nível de 10% em `25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md):
  layout da resposta e a escala de porcentagem diferente na família `FA7B` / `FA7C`.


---

<a id="sec-darkrim"></a>
> 📄 **Seção:** DARKRIM SHADOW (`docs/darkrim.md`) · [Original em inglês](../../docs/darkrim.md) · [↑ Topo](#top)

# Receptor DARKRIM SHADOW / 寸渊影弑

Testado em hardware em `3654:6901`, fabricante `Jieli Technology`, release `0100`.
Use a interface **3**, usage `FF02:0002`, payloads de entrada/saída não numerados de 64 bytes
(tamanhos de relatório HID do Windows de 65 bytes). A interface 4 também possui `FF02:0002`, mas usa
report ID 2 e não respondeu a este protocolo; ela é excluída propositalmente.

Fonte do protocolo: o [download oficial do PC Hub](https://app.darkrim.net/hub/zh.html),
`DARKRIM-0.1.26-x64-setup.rar`, baixado e descompactado estaticamente sem
instalar nem iniciar o software do fabricante. SHA-256 do `DARKRIM.exe` extraído:
`f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Endereços úteis nesse binário:

- `140124C80`: `sendGetBasicInfo(infoType)` envia o comando `0010`, Request `01`,
  payload `[infoType, 00]`. O seletor de bateria é `01`.
- `140118D30`, `140119200`: cabeçalho do quadro e geração de CRC.
- `140126DB0`: analisador TLV de informações do dispositivo; TLV `01` é bateria.
- `1400F5660`, `1400FA700`: consumidores de bateria; os sete bits inferiores dão a porcentagem,
  o bit superior indica carregamento. O mesmo valor de bateria também chega em `0011` Notify `03`.

Cabeçalho: `FE seq cmdLE type index count lengthLE`, seguido pelo payload e
CRC-16/CCITT-FALSE (polinômio `1021`, inicial `FFFF`, armazenado em big-endian).
A sequência é um contador de quatro bits diferente de zero; criptografia não é usada.

Payloads reais de solicitação/resposta, antes do preenchimento com zeros do HID:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

O TLV de resposta `01 01 28` resulta em **40%, sem carregar**. O driver C++ de produção
retornou esse valor em três consultas consecutivas sem software do fabricante.
O receptor emite notificações de inicialização antes da resposta correspondente, medidas
em cerca de 406 ms. Use um único prazo de resposta de 800 ms (mais no máximo 200 ms para escrita),
sem reiniciá-lo para notificações não relacionadas. Nenhum heartbeat é necessário.

O driver envia apenas o GET de bateria. Ele aceita somente uma resposta não criptografada
com sequência/comando/tipo correspondentes, índice zero, contagem zero ou um (o
hardware usa zero), comprimento/CRC válidos e um único TLV de bateria bem formado.
Respostas fragmentadas, não solicitadas, malformadas e fora do intervalo são ignoradas.

## Precisão da bateria e estado de carregamento observados

Trate a porcentagem como uma **estimativa aproximada, não como um medidor verificado com resolução de 1%**.
A unidade do proprietário exibiu o progresso de carregamento em passos de 10 pontos percentuais de
40% a 90%. Em 90%, cinco respostas GET de bateria e uma notificação não solicitada
trouxeram `DA`: `DA & 7F = 90`, com o bit 7 indicando carregamento. Depois que o proprietário
desconectou o cabo de carregamento e continuou usando o receptor 2.4 GHz, outras
cinco respostas GET e uma notificação trouxeram `5A`: ainda 90%, agora com
o bit de carregamento limpo. Todos os doze quadros passaram na verificação de CRC.

Respostas representativas da consulta (sequência 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Tanto o driver quanto o aplicativo oficial obtêm a porcentagem diretamente dos
sete bits inferiores. O driver não arredonda para dezenas, não multiplica um nível por dez nem
interpola valores intermediários; relatórios sintéticos de 47% e 95% continuam como 47% e
95% no analisador de produção. As leituras brutas observadas têm origem, portanto,
antes do analisador, no reporte do headset/receptor. Leituras mais finas de
hardware não foram observadas. Uma curva completa de descarga não foi registrada,
portanto um passo fixo de 10% em todo nível de descarga ou em outro firmware não está confirmado.

O carregamento e os estados subsequentes sem carregamento em 90% foram verificados em hardware.
Limites baixo/cheio, comportamento ao desligar o headset, Bluetooth
e modo de dados por cabo USB não foram testados em hardware. Nenhuma alegação de suporte é feita
para esses modos. Nenhuma atualização de firmware, alteração de configuração, comando de EQ,
alteração de pareamento, redefinição ou binário do fabricante está incluída nesta implementação.

Teste: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Seção:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [Original em inglês](../../docs/hyperx_haste_2.md) · [↑ Topo](#top)

# Protocolo de bateria do HyperX Pulsefire Haste 2 Wireless

Lido por `HasteWireless` em `src/drivers/hyperx.cpp`. As consultas vêm do
[ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) e são as mesmas usadas pelo NGENUITY.

Verificado em hardware:

- Pulsefire Haste 2 Core Wireless, dongle `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, dongle `03F0:0F98`, por uzumakiprime (PR #312). O nível coincidiu com o HyperX NGENUITY.

Espera-se que o dongle `03F0:0D97` funcione da mesma maneira, mas ele não foi testado.

## Coleção HID

| Campo | Valor (`0F98`) |
|---|---|
| Interface USB | `MI_02` (interface 2) |
| Usage page : usage | `FF00:0001` |
| Comprimento de relatório input / output / feature | 64 / 64 / 64 bytes |

O dongle também expõe as coleções padrão de mouse e consumer-control. O driver abre apenas uma coleção
do fabricante (usage page `FF00` ou superior) com input reports de pelo menos 8 bytes.

## Consultas

Ambas são output reports: os dois primeiros bytes abaixo, preenchidos com zeros até o comprimento do relatório. Cada resposta é um input
report cujo primeiro byte é o comando mais um. Cada consulta aguarda no máximo um segundo pela resposta e ignora
relatórios não relacionados (após uma reconexão o dongle envia relatórios `44 xx`, `45 xx` e `FB xx` por conta própria).

| Solicitação | Resposta | Significado |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0 quando o mouse está desligado ou fora de alcance |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100; `charge` 1 = carregando, 2 = cheio no carregador; tensão em mV, little endian (0 no Core) |

- Se a resposta do link estiver ausente, a resposta da bateria decide.
- Se o link reportar 0, nenhuma consulta de bateria é enviada e o mouse aparece como desligado.
- Durante alguns segundos após o mouse ligar, ele reporta cerca de 40%. Uma leitura dentro de 6 s após o link subir é
  ignorada, e a bandeja mantém o último valor.

Ambas as solicitações apenas leem o estado. Nada altera configurações, iluminação ou modos.


---

<a id="sec-inphic"></a>
> 📄 **Seção:** Inphic IN10 (`docs/inphic.md`) · [Original em inglês](../../docs/inphic.md) · [↑ Topo](#top)

# Família Inphic IN10, receptor KP 8K

O dispositivo conectado, identificado por seu proprietário como IN10 MAX, enumera como
`Inphic KP 8K`, `1D57:FA65`, release `0116`. Sua coleção de status é a
interface 2, usage `000A:0000`, comprimento de entrada 5 (incluindo report ID 03).

Observado aproximadamente a cada quatro segundos, sem enviar nenhuma solicitação:

```text
03 73 41 01 64
```

O analisador Xenta existente reconhece esse formato: modelo, evento, estado da bateria,
porcentagem. Dois relatórios iguais são exigidos antes de exibir 100%; o primeiro
relatório após vincular pode ser uma leitura cheia enganosa em receptores relacionados.
Esta alteração preserva essa proteção e o comportamento existente de carregamento/repouso.

O pacote oficial do [Inphic HUB](https://hub.inphic.cn/) `assets/index-BcHQx9B6.js`
mapeia o modelo decimal 115 (`73`) para `IN10RMax`, e 116 (`74`) para `IN10Max`.
Ele usa estado de bateria 1 para porcentagem, 2 para cheio e 3 para carregando.
Use o nome do modelo do firmware em vez de atribuir `73` a IN10 MAX e
rotular incorretamente outros dispositivos que compartilham este receptor.

Antes desta alteração o aplicativo listava o mouse conectado como `Wireless mouse`.
O transporte Xenta já tratava seus quadros de bateria; a alteração fornece
os nomes de modelo ausentes. Um `--list` recém-executado pode mostrar em repouso porque sua observação inicial
de cinco segundos pode receber apenas um relatório de quatro segundos. O aplicativo residente
mantém o ouvinte e confirma o valor em uma atualização posterior.

Verificado em hardware: relatórios passivos, nível de 100% repetido e identificação nativa do modelo pelo
driver. Transições de carregamento, limites de bateria fraca, modo Bluetooth e modo cabo
não foram verificados. O modelo `74` foi obtido da tabela oficial e
não foi testado em hardware separado.


---

<a id="sec-machenike"></a>
> 📄 **Seção:** Machenike L7 (`docs/machenike.md`) · [Original em inglês](../../docs/machenike.md) · [↑ Topo](#top)

# Machenike L7 Arctic / L7 Mix

Verificado em um L7 Arctic que se identifica como **L7 Mix**:

| Conexão | VID:PID | Interface | Usage | Input / output / max feature |
| --- | --- | --- | --- | --- |
| Receptor 2.4 GHz | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| Cabo USB | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

O driver também verifica o nome de produto HID `L7 Mix`. Outros modelos Machenike,
IDs de receptores diferentes e consultas de fabricante via Bluetooth não estão habilitados.

## Fonte do protocolo

Análise de interoperabilidade do software oficial **Machenike L7 Mix 1.0.0.8**,
disponível na [página de drivers do fabricante](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/),
e consultas somente leitura no mouse real. SHA-256 do `DeviceDriver.exe`:
`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

Nesse executável de 32 bits (base de imagem `00400000`), a função VA `00436750` monta
a solicitação de status; `004494F0` a envia via `HidD_SetFeature` e lê a
resposta de feature. O analisador de status `00410C20` extrai os campos abaixo e passa os
campos de bateria e carga para a interface. Estes são endereços virtuais, não deslocamentos de arquivo.
Nenhum executável proprietário, código de aplicativo ou recurso está incluído aqui.

## Consulta de leitura de estado

Envie **21 bytes**, report ID `51`, comando `06`, todos os outros bytes zero:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Leia o feature report `51`, também usando 21 bytes. O tamanho máximo de feature da coleção
é 1001 para outros relatórios; esse não é o comprimento do relatório de status.
O driver aguarda 10 ms antes de ler e usa um único prazo de 200 ms por produto,
incluindo respostas não relacionadas. Ele não envia comandos de configuração, modo, macro ou firmware.

Os índices incluem o report ID:

| Bytes | Significado / valores observados |
| --- | --- |
| 0–1 | `51 06`, eco obrigatório do comando |
| 4–7 | `8A 24 4E FF`, a assinatura verificada do dispositivo L7 |
| 10, bits 0–2 | Modo de trabalho: 1 no receptor, 0 no cabo |
| 10, bit 3 | Mouse sem fio conectado; também zerado no cabo USB |
| 11 | Porcentagem da bateria, 0–100 (zero é válido) |
| 12 | Sinalizador de carga: 0 descarregando, 1 carregando |

Outros campos e a semântica de checksum não estão estabelecidos. O driver não
inventa um checksum. Ele valida o comando, comprimento, assinatura do dispositivo, modo e
intervalos de bateria/carga do estado conectado antes de publicar uma leitura.

Resposta capturada do receptor, também 64% no aplicativo oficial:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Resposta capturada do cabo USB durante carregamento (74%):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

Naquele momento o receptor ainda retornava seu valor em cache de 64%, mas limpava seu bit de link:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Essa leitura desconectada não deve expor valores em cache de bateria/carregamento. O
cabo tem precedência quando ambos os transportes estão presentes, e a chave estável do dispositivo
é compartilhada entre transportes. Um L7 conhecido é reservado mesmo em caso de falha na consulta para que
o driver Ajazz executado depois não possa sondá-lo com um protocolo diferente no VID compartilhado.

## Limites de validação

Fixtures e testes de transporte simulados cobrem leituras capturadas, carregamento,
0%/100% válidos, receptores desconectados, respostas malformadas/obsoletas, correspondência estrita,
falha de transporte, supressão de duplicatas e loops de repetição limitados. 0%/100% ao vivo
e todas as variantes de repouso/firmware não são garantidas por esses testes.


---

<a id="sec-nuphy"></a>
> 📄 **Seção:** NuPhy WH80 (`docs/nuphy.md`) · [Original em inglês](../../docs/nuphy.md) · [↑ Topo](#top)

# NuPhy WH80 (cabo USB e Bluetooth)

Testado em hardware com `19F5:A011`, release de firmware `0116`, interface 1,
usage `0001:0000`, payloads de entrada/saída não numerados de 64 bytes (65 bytes nas capacidades HID do Windows).

Fonte do protocolo: [NuPhyIO](https://drive.nuphy.io/), pacote `main.b3fb29e0.js`,
SDK `getBatteryState(0)`, `getDataPackage` e `createCommand`.
Apenas `GetFunc` (`05`), deslocamento `0020`, comprimento `01` é solicitado. Nenhum comando de inicialização,
configuração, iluminação ou firmware é necessário.

Payload da solicitação, preenchido com zeros até 64 bytes:

```text
55 05 00 21 01 20 00 00
```

Payload real da resposta:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

O byte 3 é o byte menos significativo da soma dos bytes 4..63. A bateria é o byte 8:
`value & 7F` é a porcentagem, `value & 80` é o sinalizador de carregamento do SDK.
O driver C++ nativo retornou **100%, carregando** no teclado conectado.
Transições de carregamento e limites baixo/cheio não foram testados em hardware;
as notas oficiais do firmware descrevem leituras do WH80 em incrementos de 10%.
A operação pelo receptor está fora do escopo deste driver.

## Bluetooth

No Bluetooth o mesmo teclado usa o ID HID `19F5:324A` (release `0129`) e
anuncia um nome visível ao usuário como `NuPhy WH80 - 1`. Ele expõe duas coleções de teclado
e uma coleção de mouse. A heurística HID genérica prioriza mouses,
então este ID Bluetooth exato foi adicionado às substituições de teclado existentes.

O relatório de bateria continua usando a propriedade de bateria Bluetooth do Windows.
Após desconectar o USB, o Windows informou **95%** no teclado conectado. Uma
leitura sem cache do GATT Battery Level padrão (`180F` / `2A19`) também retornou
**95%** diretamente do teclado. Essa
é uma leitura separada por dispositivo/transporte em relação à observação de 100% com fio; não a
substitua por um valor cheio presumido nem a reescale. A razão para as leituras
diferentes do firmware não está estabelecida.

O driver verifica exatamente o produto/interface/tamanhos de relatório, cabeçalho da resposta,
deslocamento, comprimento, checksum e intervalo de porcentagem. Ele usa um prazo de resposta de 400 ms
e ignora respostas não relacionadas dentro desse mesmo prazo.

Teste de regressão:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Seção:** Rapoo (`docs/rapoo.md`) · [Original em inglês](../../docs/rapoo.md) · [↑ Topo](#top)

# Suporte à bateria de mouses Rapoo

## Por que o programa original não detectava o mouse

`PollAllDevices()` enumera as top-level collections HID do Windows uma vez por atualização. Cada driver de
fabricante reconhece um protocolo, adiciona um `DeviceStatus` e reivindica seu VID/PID para que os drivers genéricos
não o adicionem novamente. A interface já trata porcentagem, carregamento e a última leitura enquanto em repouso.

Não havia driver para Rapoo. O VT3 Max Gen 2 envia sua bateria em um input report definido pelo fabricante,
não no usage padrão HID Battery Strength nem em uma propriedade de bateria Bluetooth do Windows. Os
fallbacks genéricos de HID/Bluetooth existentes, portanto, não conseguem decodificar seu receptor USB.

## Hardware e pacotes observados

Testado no Windows com o VT3 Max Gen 2 do proprietário em 2026-11-16:

| Conexão | VID:PID | Interface | Usage page:usage | Tamanho input / output |
|---|---|---|---|---|
| Receptor 2.4 GHz | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 bytes |
| Cabo USB | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 bytes |

Ambos se identificam como `Rapoo Gaming Device`. As outras coleções incluem entradas padrão de mouse,
teclado e mídia, coleções de configuração do fabricante e uma interface de firmware de 513 bytes.
O driver de bateria abre apenas `FF00:0002` com um tamanho de entrada reconhecido. Ele nunca abre a interface de
firmware e nunca envia output report, feature report, handshake ou comando de configuração.

Relatório sem fio capturado, incluindo o report ID:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Relatório de cabo/carregamento capturado:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Os deslocamentos abaixo contam o report ID como byte zero, correspondendo ao `HidDev::Read()` deste projeto:

| Byte(s) | Significado | Exemplo |
|---|---|---|
| 0 | Report ID | `07` |
| 1 nibble baixo | Conexão: 0 receptor, 1 Bluetooth, 2 cabo | `20` / `22` |
| 1 nibble alto | Informação do sensor; não faz parte do tipo de conexão | `2` |
| 2 | Nível atual de DPI | `03` |
| 3–4, 5–6 | DPI X/Y, little endian | `0320` = 800 |
| 7 | Estado da bateria: 0 inválido, 1 descarregando, 2 carregando | `01` / `02` |
| 8 | Porcentagem da bateria, 0–100 | `19` = 25% |
| 13–14 | Product ID do mouse, little endian, quando presente | `4617` |

A captura ao vivo do receptor informou `25%`, e o aplicativo completo retornou em seguida
`27%, charging` pelo cabo. O teste do analisador inclui a captura sem fio real. O carregamento e a conectividade por cabo
também foram verificados contra hardware real; eles não são inferidos apenas pela presença de um dispositivo USB.
Depois que o proprietário desconectou o cabo e reconectou o receptor, o executável final retornou
`52%` em `2.4 GHz receiver`, sem o sinalizador de carregamento, e manteve a mesma chave `rapoo:4617`.
Isso também verifica a transição de cabo para receptor contra hardware real.

Também testado no Windows com um **VT9 Gen 2** em 2026-11-17:

| Conexão | VID:PID | Interface | Usage page:usage | Tamanho input / output |
|---|---|---|---|---|
| Receptor 2.4 GHz | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 bytes |
| Cabo USB | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 bytes |

O receptor do VT9 Gen 2 expõe um relatório `FF00:0002` de **16 bytes** em vez de 19 bytes, usando exatamente o
mesmo layout `07` do Nordic 54L (incluindo o PID `4614` embutido nos bytes 13–14). Quadros capturados:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receptor: 100%, descarregando
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # cabo USB (chave LIGADA): 100%, carregando
```

Pelo cabo USB, relatórios de status foram observados durante interação (ex.: mudança de DPI); com a chave
de energia inferior desligada (OFF) enquanto conectado, o mouse informou `state=2, percent=1` em vez da
porcentagem real da bateria.

### Receptor VT3 Max Gen 2 com coleção de 13 bytes (issue #1396)

Um relato no formulário de solicitação de dispositivo para o mesmo ID de receptor `24AE:1417` listou um layout de
interface diferente: `FF00:0002` com **13 / 13** bytes (em vez de 19) e `FF00:000E` com 33 / 33 bytes,
sem a coleção de firmware de 513 bytes. Isso parece ser outra revisão de firmware do receptor. O
software da Rapoo continuava exibindo a bateria, então o driver estava ignorando um canal de status funcional.

O decodificador `VT_nrf54L` do Rapoo Hub (`py`) é adaptável ao comprimento: ele sempre lê o DPI, o estado da bateria
e a porcentagem, e lê os campos posteriores (PID do mouse em `n[12..13]`, informações de RF, ...) somente
quando o relatório é longo o bastante. O manifesto do VT3 MAX (`productId: [17943, 5143]`) não tem um tipo especial
de input-report, então o relatório `07` passa por esse decodificador neste receptor também. Um relatório de 13 bytes
(ID mais 12 bytes) ainda traz o estado no byte 7 e a porcentagem no byte 8; apenas o PID embutido do mouse
fica ausente, então a leitura usa o PID do receptor e mantém a chave `rapoo:4617`.

O comprimento de 13 bytes é aceito **apenas para `24AE:1417`**. Os quadros ainda devem passar nas mesmas verificações
(relatório `07`, nibble de conexão 0–2, estado 1/2, porcentagem 0–100). Nenhum quadro de 13 bytes ao vivo foi
capturado ainda; os testes usam a captura testada de 19 bytes cortada para 13 bytes.

## Outros mouses Rapoo

O Rapoo Hub oficial usa este layout `07` para seu driver de mouses Nordic 54L. Seus manifestos
listam VT0, VT1, VT2, VT3, VT3S, VT7, VT9 e variantes adicionais. A inspeção do pacote atual
identificou 69 variantes VT usando `VT_nrf54L`; isso é evidência de um protocolo compartilhado, não 69 validações
em hardware nem afirmação de cobrir a maior parte de todo o catálogo da Rapoo. O suporte é selecionado pelo VID da Rapoo,
pela coleção dedicada, pelo comprimento de entrada e por um relatório de status válido, de modo que um modelo não listado no mesmo
protocolo ainda possa reportar sua bateria. Uma pequena tabela de nomes cobre modelos comuns; outros mantêm seu
nome de produto HID ou exibem `Rapoo wireless mouse`.

Nomes de produtos e IDs variam entre gerações e regiões. O par testado `1417/4617` é chamado de
`VT3 MAX` no manifesto oficial atual; o proprietário o identifica como VT3 Max Gen 2. O
`VT3 MAX V2` separado do manifesto atual tem IDs `1B06/4B06`. Tabelas da comunidade que atribuem `1417` ao VT9 Pro
não devem ser usadas como base única para nomear ou detectar este dispositivo.

Firmwares VT mais antigos, documentados para o VT3 Pro (`1215/4415`), em vez disso enviam um relatório de 7 bytes no mesmo
usage `FF00:0002`:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

Para esse formato legado, os estados 1/2 significam descarregando/carregando. Uma porcentagem de carregamento `7F` significa
desconhecido e é preservada como desconhecida. Estado de transição 0, relatórios `BC` não relacionados, pacotes malformados
e porcentagens acima de 100 são ignorados. O suporte legado tem cobertura automatizada, mas não foi
verificado com um mouse legado físico aqui. Essa interpretação é restrita aos product IDs
`1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) e sua coleção de entrada de 7 bytes.

O VT1 Pro Max (receptor `24AE:1233`, cabo `24AE:4433`, firmware do mouse 222, firmware do dongle 213)
foi adicionado a partir de capturas USBPcap que seu proprietário anexou à issue #136. A saída do `--dump` lista a
coleção `FF00:0002` de 7 bytes na interface 1, e as capturas a mostram enviando continuamente, sem solicitação
do aplicativo Rapoo:

```text
BB B0 71 84 03 01 64   receptor, a cada ~3,2 s; app Rapoo mostrava 100%
BB B0 71 84 03 02 5F   cabo, carregando, 95%; app Rapoo mostrava "Charging"
```

No cabo o relatório foi visto apenas uma vez em uma captura de 16 segundos, então uma leitura apenas por cabo pode
expirar em algumas atualizações; o receptor o envia regularmente. O perfil Nordic nunca interpreta pacotes `BB`.

Isso **não** estabelece suporte para todos os dispositivos Rapoo. Modelos CH584 como VT1 SE e VT7 SE
usam o relatório `08` no driver oficial e não são suportados por este decodificador. Outras revisões Telink usam uma
interpretação diferente das flags `BB`, alguns modelos de escritório usam consultas ativas de bateria e modelos Bluetooth
podem expor apenas a propriedade de bateria do Windows. Estes permanecem com os fallbacks existentes ou precisam de uma
implementação verificada separada. Não envie consultas adivinhadas para eles.

## Consulta e identidade

- A leitura é passiva. Handles `FF00:0002` correspondentes permanecem abertos entre as consultas (como em `PollXenta`)
  para que o Windows armazene em buffer os quadros de status que chegam durante o intervalo de atualização de 60 segundos; cada consulta drena
  quaisquer quadros enfileirados (mantendo a leitura válida de bateria mais recente) antes de recorrer a uma espera de 5 segundos
  na primeira abertura ou em fila vazia. Dispositivos desconectados são removidos e seus handles fechados.
  Pacotes não relacionados não reiniciam o prazo.
- O PID embutido do mouse, ou um par cabo/receptor conhecido para dispositivos legados, fornece a mesma chave de interface
  entre trocas de cabo. Leituras de cabo e receptor são mescladas em uma única entrada, preferindo o estado do
  cabo enquanto preserva uma porcentagem válida do receptor se o cabo reportar nível desconhecido.
- Um timeout não inventa porcentagem nem reivindica o dispositivo. Após uma leitura bem-sucedida, a
  interface existente pode reter essa leitura, esmaecida, por 30 minutos de silêncio.
- O modelo de identidade baseado em VID/PID existente no programa não consegue distinguir vários mouses idênticos
  com o mesmo ID de modelo. A operação física simultânea por cabo/receptor não foi testada; a mesclagem
  de ambas as entradas é coberta pelo teste de transporte simulado.

## Validação

`make test` executa um teste de decodificador portátil e um teste de driver Windows com respostas HID simuladas.
A cobertura inclui a captura real, 0% e 100%, carregamento, níveis ausentes, quadros inválidos/truncados,
coleções/fabricantes não suportados, isolamento de perfil de protocolo, timeouts, chaves estáveis e desduplicação de cabo/receptor
sem descartar uma porcentagem conhecida.

O aplicativo completo foi compilado localmente com MSVC C++17 e o Windows SDK, e `--list` / `--dump`
foram executados contra o mouse real. A compilação mantida para MinGW inclui `rapoo.cpp` no `build.bat`;
o Makefile o descobre automaticamente. O MinGW em si não estava instalado no ambiente de teste.

## Fontes do protocolo

- [Rapoo Hub oficial](https://hub.rapoo.cn/), inspecionado em 2026-11-16:
  [driver JavaScript e manifestos](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js) incluídos no pacote.
  Os decodificadores relevantes são `py`/`Hk` para `VT_nrf54L` e `qM`/`QM` para os significados de conexão e estado da bateria.
  O manipulador separado `VT_CH584` consome o relatório `08` e está fora desta implementação.
  Nomes minificados podem mudar em versões futuras.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs),
  para relatórios legados do VT3 Pro, estado de carregamento e o sentinela de nível desconhecido.
- Capturas USBPcap da issue #136 (VT1 Pro Max no receptor e no cabo durante carregamento).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js)
  corrobora de forma independente as transmissões passivas de status `07` e o deslocamento da bateria. Seu analisador
  limita porcentagens inválidas; esta implementação as rejeita em vez disso.


---

<a id="sec-rawm"></a>
> 📄 **Seção:** RAWM (`docs/rawm.md`) · [Original em inglês](../../docs/rawm.md) · [↑ Topo](#top)

# Notas do protocolo RAWM

Mouses RAWM (e o SADES Dagger, que compartilha a plataforma) conversam com o app RAWM HUB por uma
coleção HID de fabricante, `FF00:0001`, com input e output reports não numerados de 64 bytes (65 bytes
com o report ID). Os receptores e mouses usam o vendor ID da Nordic `1915`.

Fonte: o app web RAWM HUB, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), e seu script
`https://hub.miracletek.net/hub/js/library.min.js` (ofuscado; os nomes de funções e constantes abaixo
são do próprio script). Os product IDs suportados vêm da tabela de dispositivos que o app baixa
(`https://www.miracletek.net/game/device.php`). O Leviathan V4 GT e o NYX60 usam o Hub Web 3.0 no VID
`373E`, que é um protocolo diferente.

## Pacotes

Byte 0 de cada relatório (após o report ID):

| Bits superiores | Significado |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | os 6 bits inferiores são um tamanho de payload; o payload continua o fluxo de eventos |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | controle de fluxo (tamanhos de buffer livres); ignorado aqui |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | os 6 bits inferiores são um canal ESB; o restante do relatório é um pacote para esse canal. O mouse atrás de um receptor é o canal 0 |

Os payloads formam um fluxo de bytes de eventos:

```
FF FF FF FF                      sincronização (apenas dispositivo para host)
cmd | ((len >> 4) & 0xF0), len   len inclui esses dois bytes (12 bits)
body ...
```

## Lendo a bateria

O driver repete o que o app faz quando um receptor é conectado (`send_event_query`, `send_event_ping`):

1. Para o receptor: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), depois
   pings `00 84 0E 04 00 00`. O dispositivo só envia enquanto o host continua escrevendo, então o host envia pings.
   O receptor responde `CMD_QUERY_RESULT` (`02`) com JSON, por exemplo
   `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. A mesma consulta e pings para o canal 0, prefixados com `C0`. O mouse responde com um objeto JSON de ~550 bytes
   em blocos ESB de 30 bytes, por exemplo `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`.
   `battery` é uma porcentagem (o RAWM HUB a exibe como está), `chr` é 1 durante o carregamento.
3. Alterações posteriores chegam como `CMD_NOTIFY` (`0B`) tipo `17`: `[17, percent, charging]`.

O driver sempre consulta o receptor primeiro, como o app faz (em um teste, uma consulta enviada apenas ao canal 0
não obteve resposta). Um mouse em repouso não responde de forma alguma; o receptor ainda responde.

A consulta carrega o relógio do PC porque o app envia dessa maneira; nada mais é gravado.
Os mouses informam `"crc":1`, o que instrui o app a envolver comandos posteriores (configuração) em um quadro CRC-16;
a consulta e os pings são aceitos sem um, pois o app os envia antes de saber disso.

Testado em um Leviathan V4 (firmware 1.2.0) com o RAWM HS Receiver `1915:2346` (firmware 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **Seção:** VAXEE (`docs/vaxee.md`) · [Original em inglês](../../docs/vaxee.md) · [↑ Topo](#top)

# Receptores VAXEE 4K/8K e ZYGEN NP-01S V2

## Escopo e validação em hardware

Este driver oferece suporte ao receptor VAXEE 4K `3057:1002`, ao receptor VAXEE 8K
`3057:2002` e ao ZYGEN NP-01S V2 Wireless via cabo USB (`3057:1011`), em
sua coleção de fabricante `FF05:0001` com feature report de 64 bytes. Outros receptores
VAXEE, outros product IDs de cabo e dispositivos ZOWIE propositalmente não são
sondados.

O receptor 8K (`VAXEE 8K Wireless`, pareado com um NP-01 Ergo Wireless 8K)
foi testado no Windows e respondeu pelo mesmo protocolo:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

O receptor é compartilhado por todos os mouses VAXEE 8K e não informa qual deles está
pareado, portanto é exibido com seu próprio nome. O status de carregamento no receptor 8K ainda não foi observado em hardware.

Um receptor 4K real foi testado no Windows:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

O aplicativo integrado também informou:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

O mesmo mouse foi então conectado diretamente via USB e o Windows o identificou
como `ZYGEN NP-01S V2 Wireless` (`3057:1011`). O driver de produção atualizado
informou:

```
VAXEE battery: 75%; charging: yes
```

O widget da barra de tarefas foi criado com sucesso na compilação inicial do receptor.
Tanto a operação na bateria pelo receptor quanto o carregamento com fio foram observados;
transições de carga completa e comportamento de repouso/desligamento não foram testados em
hardware. A decodificação de carregamento e respostas inválidas são cobertas por respostas
simuladas.

## Protocolo

Fonte: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

Uma solicitação é um feature report HID de 64 bytes preenchido com zeros:

| Byte | Valor |
|---|---|
| 0 | `0E`, report ID |
| 1 | `A5`, cabeçalho |
| 2 | `0B` para nível da bateria; `10` para status de carregamento |
| 3 | `01`, flag de leitura (nunca `02`, escrita) |
| 4 | `01`, tamanho dos dados |
| 5–63 | `00` |

Após enviar a solicitação com `HidD_SetFeature`, aguarde 100 ms e leia o relatório
`0E` com `HidD_GetFeature`. Exija pelo menos seis bytes e o report ID,
cabeçalho, eco do comando e tamanho de dados esperados.

Para bateria, o byte 5 da resposta deve estar entre 0 e 20 e é multiplicado por cinco, fornecendo
0–100% em passos de 5%. Para carregamento, o byte 5 é diferente de zero quando está carregando. Uma consulta
de carregamento que falha não descarta uma leitura de bateria válida.

O driver tenta novamente a solicitação de bateria uma vez. Há no máximo três solicitações
de leitura por coleção correspondente (duas tentativas de bateria e uma consulta de
carregamento), com 300 ms de atraso explícito total. Ele não envia comandos de configuração, pareamento,
firmware ou iluminação.

Se nenhuma resposta válida de bateria for recebida, o driver não informa nada e deixa
o dispositivo não reivindicado. Enquanto a coleção USB permanecer presente, a interface mantém
uma leitura anteriormente bem-sucedida, esmaecida, por até 30 minutos usando seu comportamento existente
de período de tolerância. Se a coleção física desaparecer, o driver emite
um status desconectado para encerrar esse período de tolerância imediatamente. Isso evita que
um ícone obsoleto do receptor permaneça quando o cabo é movido para o mouse.

## Testes

`make test` inclui `tests/vaxee_driver_test.cpp`, que vincula o driver de produção
a um transporte HID simulado. Ele verifica exatamente as solicitações somente leitura
enviadas, conversão de porcentagem, decodificação de carregamento, respostas inválidas e
ausentes, dispositivos já reivindicados e filtragem exata de coleções.
