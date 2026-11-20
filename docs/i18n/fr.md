<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Langues :** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | **Français** | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | [Tiếng Việt](vi.md) | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Ajouter une langue](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Documentation complète (Français)

> Ce fichier Markdown autonome regroupe l'ensemble de la documentation visible du dépôt afin que les traducteurs n'aient à maintenir **qu'un seul fichier par langue**.

## Table des matières

1. [Présentation de BatteryHub, appareils pris en charge, installation, ligne de commande et compilation (`README.md`)](#sec-readme)
2. [Guide de contribution (`CONTRIBUTING.md`)](#sec-contributing)
3. [Modèle de Pull Request (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Guide de publication et de signature (`docs/releasing.md`)](#sec-releasing)
5. [Correctif de firmware 2,4 GHz pour clavier Keychron (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [Prise en charge BLE du GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Guide multilingue et de localisation (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Récepteur Areson 25A7 (`docs/areson.md`)](#sec-areson)
10. [Récepteur DARKRIM SHADOW (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Récepteur Inphic IN10 / KP 8K (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Prise en charge de la batterie des souris Rapoo (`docs/rapoo.md`)](#sec-rapoo)
16. [Notes sur le protocole RAWM (`docs/rawm.md`)](#sec-rawm)
17. [Récepteurs VAXEE 4K/8K (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Section :** Présentation de BatteryHub (`README.md`) · [Original en anglais](../../README.md) · [↑ Haut](#top)

# BatteryHub

*Anciennement **Wireless Battery**. La version 1.1.0 a renommé l'application ; une mise à jour conserve vos paramètres, votre choix de démarrage et votre historique de batterie.*

[![Soutenir sur Ko-fi](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Faire un don via PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Rejoindre notre Discord](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Étoile sur GitHub](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Partager sur Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Signaler un appareil](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Aider à traduire](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Les niveaux de batterie de votre souris, casque, clavier et manette sans fil, directement dans la barre des tâches Windows.

![BatteryHub dans la barre des tâches](../screenshot.png)

> **Vous voulez juste que ça fonctionne ?** Téléchargez **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** depuis la dernière version, lancez-le et suivez l'assistant. C'est tout.
>
> **Les utilisateurs avancés** peuvent récupérer l'archive ZIP portable, utiliser les [options en ligne de commande](#ligne-de-commande), ou [compiler depuis les sources](#compilation) avec `make` ou `build.bat`.
>
> **Vous l'appréciez ?** BatteryHub est gratuit et open source. S'il vous évite d'ouvrir les logiciels des fabricants, vous pouvez le soutenir sur [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) ou [GitHub Sponsors](https://github.com/sponsors/krisgfx9). Cela m'aide à garder mes applications gratuites pendant mes études. Vous ne pouvez pas faire de don ? Une ⭐ étoile, un partage ou le signalement d'un appareil non pris en charge avec `--dump` aide tout autant.

- **Minuscule** : une application d'environ ~350 Ko utilisant environ 2 Mo de RAM. C'est du pur C++/Win32, sans runtime ni service en arrière-plan, et elle s'installe en quelques secondes sans droits d'administrateur.
- **Aucun logiciel fabricant requis** : elle dialogue directement avec les appareils. G HUB, Synapse, iCUE, GG et NGenuity peuvent rester fermés (ou continuer de tourner ; ils n'entrent pas en conflit).
- **De nombreuses marques** : Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, les manettes PlayStation et Xbox, les Samsung Galaxy Buds, tout appareil Bluetooth dont Windows connaît le niveau de batterie, et chaque casque pris en charge par [HeadsetControl](https://github.com/Sapd/HeadsetControl) (inclus).

## Affichage

**Dans la barre des tâches (par défaut) :** `🎧 30%  🖱 93%` à côté de la zone de notification, dessiné avec la police d'icônes Windows.
- **Batterie faible :** un chiffre rouge indique 15 % ou moins.
- **En charge :** un éclair bleu ⚡ apparaît à côté du chiffre. Une fois l'appareil complètement chargé et toujours branché, il devient une coche verte ✓.
- **En veille :** un texte estompé indique que l'appareil est en veille et que la dernière valeur connue est affichée.
- **Déconnecté (facultatif) :** activez *Afficher les appareils déconnectés* pour afficher un `×` estompé pour les appareils dont le pilote signale explicitement une liaison sans fil hors ligne. Cela ne déduit pas une déconnexion d'un relevé manqué ; le comportement par défaut reste de masquer les appareils hors ligne.
- **Deux appareils d'un même type :** avec deux souris (ou deux manettes...), les deux auraient la même icône ; chacun reçoit donc une minuscule légende de 3 lettres maximum dans le coin de son icône, tirée de son nom (`MX`, `PRO`), ou un numéro lorsque les noms ne permettent pas de les distinguer. Un appareil seul de son type n'affiche aucune légende.
- **Thème :** suit le mode clair/sombre et la mise à l'échelle DPI.
- **Thèmes de barre des tâches transparente** (ex. Taskbar Styler de Windhawk) : activez *Fond derrière le texte de la barre des tâches* dans le menu pour garder le texte lisible sur le fond d'écran.
- **Plusieurs écrans :** le widget s'affiche sur la barre des tâches de chaque écran, à côté de son horloge, afin de rester visible lorsqu'un jeu tourne en plein écran. *Afficher le widget sur* dans le menu permet de choisir *Tous les écrans*, *Écran principal uniquement*, ou un écran précis (ex. uniquement *Écran 3*).
- **Plus d'options d'affichage :** *Icônes au-dessus des pourcentages* empile chaque icône au-dessus de son niveau pour réduire la largeur ; *Couleurs des marques* affiche les marques connues dans leur couleur (vert Razer, rouge HyperX, ...) avec une fine barre de niveau ; deux appareils de même type reçoivent une petite légende pour les différencier ; les barres des tâches à gauche et à droite affichent les appareils en colonne.
- **Langues :** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 et 繁體中文. Les applications Windows et Linux suivent toutes deux la langue d'affichage du système ; *Langue* dans le menu permet d'en choisir une autre, et l'installateur Windows prend également en charge les 19 langues. Les textes de l'interface résident dans des fichiers statiques modifiables `lang/*.json`, et la documentation traduite complète se trouve dans [`docs/i18n/`](README.md). Consultez [Traductions](#traductions) pour modifier ou ajouter une langue.
- **Couleurs des marques :** les appareils de 15 marques connues adoptent la couleur de leur fabricant, avec une légère lueur et une fine barre de niveau sous le pourcentage : vert Razer, bleu Logitech, orange SteelSeries, jaune Corsair, rouge HyperX / ROG / ZOWIE, PlayStation, Xbox, Samsung, Apple, Jabra, JBL, Cooler Master et Steam. Chaque couleur dispose d'une nuance pour barre des tâches sombre et claire. La marque provient du pilote qui a détecté l'appareil, puis du Vendor ID, puis du nom ; les couleurs et règles se trouvent dans `src/brands.cpp`. Désactivez-les via *Couleurs des marques* dans le menu.

**Icônes de notification :** une icône par appareil avec le chiffre dessiné à l'intérieur, plus une notification « Batterie faible » à 15 %. L'application bascule automatiquement vers ce mode lorsque la barre des tâches est verticale ou introuvable.

**Noms personnalisés des appareils :** ouvrez le sous-menu d'un appareil et sélectionnez *Renommer l'appareil...* pour définir un nom (jusqu'à 64 caractères). Ce nom s'affiche dans l'info-bulle et la légende du widget de la barre des tâches, l'info-bulle et les notifications de la zone de notification, ainsi que le menu de l'appareil. Utilisez *Rétablir le nom d'origine* pour restaurer le nom fourni par le pilote. Les noms sont stockés localement dans le Registre Windows de l'utilisateur courant (`Software\WirelessBattery`, `DeviceAliases`), à l'aide de la clé stable de l'appareil. Renommer un appareil ne modifie jamais la correspondance des pilotes, les requêtes de protocole ni les sorties de diagnostic `--list` / `--dump`. Aucun compte ni accès réseau n'est nécessaire.

Survolez pour voir les détails. Cliquez pour ouvrir le menu : chaque appareil (cliquez sur l'un d'eux pour le masquer ou l'afficher), le mode d'affichage, *Actualiser*, *Démarrer avec Windows* et *Quitter*. Les niveaux sont actualisés toutes les 60 secondes (*Vérifier la batterie toutes les* dans le menu permet de modifier ce délai), et immédiatement lorsqu'un appareil est branché ou que le PC sort de veille.

## Alertes intelligentes de batterie (expérimental)

Vous pouvez définir un **seuil de notification de batterie faible par appareil** depuis le sous-menu de chaque appareil : **Alertes de batterie** → *Valeur par défaut (15 %)*, *Désactiver les notifications*, ou l'un des seuils suivants : 5 %, 10 %, 15 %, 20 %, 25 %, 30 %, 35 %, 40 %. La valeur par défaut de 15 % reste inchangée sauf si vous choisissez un seuil personnalisé. Les réglages sont enregistrés par clé d'appareil dans le Registre Windows de l'utilisateur courant (`Software\WirelessBattery`, `AlertThresholds`).

Une alerte n'est déclenchée qu'à partir d'une mesure réelle et récente de batterie entre 0 et 100 % lorsque l'appareil est connecté, éveillé et n'est pas en charge. L'alerte est émise une seule fois et se réarme après que le niveau remonte de plus de 10 points de pourcentage au-dessus du seuil choisi (ou lorsque la charge commence). Les mesures manquantes ou les appareils en veille ne redéclenchent pas d'alertes. Les appareils masqués ne génèrent pas de notifications. La désactivation des notifications pour un appareil ne le masque pas et ne modifie pas son pourcentage.

Les modes widget de barre des tâches et icônes de notification prennent tous deux en charge les notifications. Comme Windows exige une icône dans la zone de notification pour afficher une info-bulle classique, le mode widget peut afficher une icône de notification temporaire jusqu'à une minute après une alerte. Les couleurs du widget et la mise en évidence de batterie faible continuent d'utiliser le seuil global d'origine de 15 %, indépendamment du paramètre de notification.

## Historique de la batterie et statistiques

Faites un clic droit sur un appareil dans le widget de la barre des tâches ou le menu de la zone de notification et choisissez **Historique de la batterie...**. La visionneuse native adaptée au DPI (elle suit le thème clair/sombre de Windows) affiche les niveaux de batterie enregistrés avec des courbes reliant les mesures sur les dernières **24 heures**, les **7 derniers jours** ou les **30 derniers jours**, ainsi que le dernier relevé, les niveaux minimal et maximal, la variation en points de pourcentage et le nombre de mesures. Vous pouvez effacer l'historique de l'appareil sélectionné depuis la visionneuse.

L'historique est enregistré **uniquement en local** pour les appareils connectés et éveillés signalant un pourcentage numérique. Les mesures sont échantillonnées au maximum une fois toutes les 30 minutes par appareil (sauf lors des changements d'état de charge, avec un minimum de 60 secondes). Les données sont conservées jusqu'à 30 jours et le fichier local reste inférieur à environ 2 Mo. L'application n'interroge jamais le matériel au-delà de son cycle habituel, n'envoie aucune donnée d'historique sur le réseau et effectue une estimation prudente et approximative de l'autonomie restante uniquement à partir des observations récentes de décharge. Au moins quatre points, deux heures, une baisse de trois points de pourcentage, une mesure récente et un segment de décharge stable sont nécessaires. La charge, des relevés anciens ou des données insuffisantes masquent l'estimation ; la durée restante signalée par l'appareil n'est pas disponible. L'estimation ne constitue pas une garantie. Les données manquantes apparaissent sous forme de coupures sur le graphique et ne sont pas interpolées.

Désactivez **Enregistrer l'historique de batterie** dans le menu pour arrêter d'enregistrer des mesures ; ce qui a déjà été sauvegardé reste conservé jusqu'à ce que vous l'effaciez dans la visionneuse. Le fichier est stocké dans `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Les identifiants d'appareils y sont encodés (non chiffrés) ; le fichier est propre à votre compte Windows. Avec `--demo`, le graphique utilise des données synthétiques qui ne sont jamais enregistrées. **Remarque :** la collecte d'historique ne commence qu'après l'installation de cette fonctionnalité et une certaine durée d'exécution de l'application.

## Appareils pris en charge

| Fabricant | Appareils | Fonctionnement |
|---|---|---|
| **NuPhy** | WH80 par câble USB (`19F5:A011`) ou Bluetooth (`19F5:324A`), testé sur matériel | USB : requête de batterie NuPhyIO en lecture seule ; Bluetooth : niveau de batterie Windows avec classification clavier ([notes sur le protocole](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) sur son récepteur USB `3654:6901` (testé sur matériel) | Requête de batterie en lecture seule vérifiée par CRC et indicateur de charge ; relevés grossiers observés par paliers de 10 %, précision plus fine non vérifiée ([notes sur le protocole](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX sur le récepteur KP 8K (`1D57:FA65` ; modèle `73` testé sur matériel, modèle `74` non testé) | Rapports d'état Xenta passifs ; deux trames concordantes confirment le niveau ([notes sur le protocole](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, testé), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` testé, `002D`/`002A`), A50 Gen 3 (`9886:0015` testé, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), via station de base USB | Pourcentage de batterie, état de charge et de placement sur la station |
| **Logitech** | Souris et claviers sur récepteurs Unifying, Bolt, Lightspeed (y compris le dongle PRO X3 SUPERSTRIKE `046D:C54F`) et Nano, par USB ou Bluetooth ; casques G (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X) ; G435 sur le nouveau dongle `046D:0ADF` | HID++ 1.0 / 2.0 avec découverte des fonctionnalités : batterie unifiée, niveau de batterie, tension, ADC ; G435 : rapports constructeur encadrés par CRC-16, `GET_BATTERY` en mV |
| **Razer** | Souris, claviers et dongles sans fil ; casques BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X, V3 Pro pour Xbox (récepteur `1532:0A55`, câble `0A4E`) ; Barracuda X (2022) sur son récepteur 2,4 GHz (`1532:0550` ou `1532:0552`) ; Barracuda Pro (`1532:053A`) | Protocole de rapports de fonctionnalités Razer ; protocoles constructeur BlackShark (V3 / V3 Pro / V3 X interrogés toutes les 5 min) ; Barracuda X : requêtes Airoha de batterie et de câble via le récepteur |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (dont `1038:225D`), Arctis Nova Elite (station de base `1038:2244`), GameBuds ; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, non testé), Aerox 3 Wireless CS2 Dragon Lore Edition (récepteur `1038:1878`, câble `187A`), Aerox 3 Wireless Gen 2 (récepteur `1038:1890`, câble `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Rapports HID constructeur ; Aerox/Prime et Rival 650 partagent une seule entrée entre récepteur et câble USB, privilégiant la lecture par câble lorsque les deux répondent |
| **Corsair** | Void / Void Pro / Void Elite / HS70 / HS80 sans fil ; appareils Bragi (Virtuoso, Void V2, HS80 MAX, souris et claviers Slipstream, y compris le nouveau récepteur Slipstream `1B1C:2B00`, ex. Scimitar Elite SE Wireless, et Dark Core RGB Pro SE) ; Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, non testé) | Rapports HID constructeur, Bragi `GET` (lecture seule), protocole de batterie Compx sur 17 octets (lecture seule) |
| **Cooler Master** | MM712, MM731 (récepteur 2,4 GHz ou câble USB) | Rapport d'état HID constructeur (lecture seule) |
| **Press Play** | ICARUS V2 Nearlink sur son récepteur 2,4 GHz `7768:6434` (pilote testé sur matériel à 90 % ; protocole capturé à 100 % et 90 %) | Rapport de sortie en lecture seule `06 05` sur `FFB2:0001` ; pourcentage de batterie dans l'octet 14 de la réponse |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` pour PS, non testé), Cloud Flight S, Cloud Stinger Core Wireless (y compris DTS `03F0:0A8E`, testé), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (dongle 2,4 GHz), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (dongle 2,4 GHz) (dongle 2,4 GHz `03F0:0F98`, testé ; `0D97` non testé) | Rapports HID constructeur (Haste 2 : [notes sur le protocole](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Rapport de fonctionnalités constructeur |
| **Hitscan** | Hyperlight X, Hyperlight N | Rapport de fonctionnalités constructeur (même protocole que Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Kysona M600 / Mercury, souris sans fil Pulsar et ATK VXE (ex. VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (récepteur 3554:F512) | Protocole constructeur partagé avec réponses à somme de contrôle |
| **Pulsar X2 V3** | X2 V3 sur le dongle 1K (`3710:5402`) ou câble USB (`3710:3402`) ; X2 V3 eS sur le dongle 8K (`3710:5403`) ou câble USB (`3710:3406`) | Rapport de fonctionnalités constructeur sur 64 octets, registre de batterie `08 81 01` (lecture seule) |
| **ATK / VXE NK** | VXE R1 NK et autres souris NearLink sur le dongle NK mouse NANO (`373B:1216`) | Rapport de sortie ATK BITMOUSE `08` sur `FF05:0001` (batterie et charge) |
| **ATK 8K Nano** | Souris ATK / VXE sur le dongle ATK 8K Nano (`373B:1178`) | Rapport de fonctionnalités Holtek GetConfigData (`82`) sur `FF10:0001` (issu d'ATK HUB ; batterie et charge) |
| **Casques ATK** | ATK N9 Pro, N9 Ultra (première génération) | Protocole sur port COM virtuel (l'application de bureau ATK doit être fermée) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK et leurs dongles 8K | Protocole Glorious ou Kysona, selon le modèle |
| **Souris Keychron** | M4 et autres souris Keychron sur le récepteur 2,4 GHz ; souris 4K (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) sur le récepteur Keychron 4K Link (`3434:D038`) ; souris 8K (M5 8K, G6 HE 8K ...) sur le récepteur TurboLink 8K ; souris 8K sur le récepteur Ultra-Link 8K (`3434:D028`) ; anciennes souris (M1, M2, M3, M3 mini, M6, M7 ...) sur le récepteur 1K (`3434:D030` / `D031`) ; trackball Nape Pro sur le récepteur Link-KM ou par câble | Rapport constructeur issu de Keychron Launcher (récepteur 1K : rapport de fonctionnalités 51 06, utilisé par l'application de bureau Keychron ; Ultra-Link 8K : rapports B5 03 / B3 06 sur `FFC1` ; Nape Pro : HID brut A7 31) |
| **Claviers Keychron** | K5 Max (`3434:0A50`, testé) sur le récepteur Keychron Link (`3434:D030`) ou câble USB ; autres claviers sans fil Keychron QMK compilés avec le même correctif | HID brut sur `FF60:0061` : `B2` demande au récepteur quel clavier est appairé, `A4` renvoie niveau, tension et état de charge. **Nécessite un firmware de clavier modifié :** voir [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). Le firmware d'origine ne rapporte la batterie qu'en Bluetooth |
| **CHERRY** | Clavier MX 3.0S Wireless sur son dongle 2,4 GHz (`046A:00EA`, testé) ou câble USB (`046A:00E3`, testé) | Requête HID constructeur `1A` sur `FF1C:0092` (lecture seule), avec état d'alimentation USB. Le Bluetooth est géré par la prise en charge Bluetooth |
| **CHERRY** | Souris sans fil Cherry XTRFY sur le récepteur 1K (`046A:0330`, testé) | Protocole de batterie CompX sur 17 octets (`08 03` état de liaison, `08 04` GetPower), même tramage que la Corsair Sabre V2 Pro (lecture seule) |
| **Arbiter Studio** | Akitsu (récepteur 8K `373E:000A`, câble `373E:0009`), Akitsu 3950 (récepteur 8K `373E:0039`, câble `373E:0038`), Akitsu Medium (récepteur 8K `373E:0067` et câble `373E:0066`, tous deux testés) | Rapport de fonctionnalités constructeur en lecture seule `0x83` sur `FFFF:0000` issu d'Arbiter Web HUB (batterie et charge) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (câble, dongles 1K et 4K/8K) | Rapport de fonctionnalités constructeur issu de LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) sur le dongle 4K ; XM2we sur son récepteur d'origine (`3367:1961`) | Rapport de fonctionnalités constructeur `A1`, commande de batterie `B4` (lecture seule) |
| **Claviers ATK / VGN / Evision** | Claviers ATK V75X et VGN / VXE (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) sur le récepteur 2,4 GHz partagé (`320F:5088`) ou câble USB (`320F:5055`), reconnus par le nom du produit ; claviers dont le récepteur `320F:5088` est nommé « Wireless Gaming Keyboard », ex. Feker Alice80 (testé) | Rapport de sortie Evision `04`, commande de batterie `1A` (issu d'ATK HUB et VGN HUB) ; interrogé au maximum toutes les 10 minutes via le récepteur |
| **Redragon (Evision)** | K1NG M999 (testé) sur le récepteur 2,4 GHz `320F:226F` ; l'identifiant du récepteur peut être partagé par d'autres modèles | Même protocole Evision que les claviers ATK (rapport `04`, commande `1A` sur `FF1C:0092`), interrogé à chaque cycle ; charge affichée sur la station magnétique ; avec le câble USB branché, le récepteur répète l'ancien niveau sans état de charge |
| **Audeze** | Maxwell sur le dongle USB (`3329:4B19`) ou câble USB-C (`3329:4B1A`) ; Maxwell 2 sur le dongle USB (`3329:4B29`, testé) ; identifiants Xbox non testés | Rapport constructeur `06` / rapport d'entrée `07`, attribut de batterie `0CD6` (requête unique en lecture seule) |
| **ENDORFY** | Viro Wireless sur son dongle 2,4 GHz (`3738:0072`, non testé) | Commande Airoha RACE « get battery » (`0CD6`) sur rapport constructeur `06` / rapport d'entrée `07`, même requête en lecture seule que les dongles Audeze et Skullcandy ; sans état de charge |
| **Turtle Beach** | Stealth 700 Gen 3 sur l'émetteur USB (`10F5:2251`, testé dans HaloBattery ; version PC `10F5:2262`, non testé) ou le câble USB du casque (`10F5:2253`) | RACE `0x9942` (activation du client CoAP) et un `GET /GSI` CoAP encapsulé dans RACE `0x9902`, comme le fait Swarm II ; batterie dans la clé `240` (sans indicateur de charge) |
| **AKG** | N9 Hybrid sur son dongle USB (`0ECB:20D9`, testé) | Airoha RACE sur `FF13:0001` : rapport de sortie `06`, rapport d'entrée `07`, attribut de batterie `0CD6` (requête unique en lecture seule) |
| **NZXT** | Lift Elite Wireless sur son dongle (`1E71:2101`) ou câble USB (`1E71:2129`) | Lecture constructeur `4E 02 81 .. B0` (d'après les captures de NZXT CAM) |
| **Poly / Plantronics** | Voyager 8200 UC et autres casques derrière l'adaptateur BT600 (`047F:02EE` / `02F7`) | Protocole get/set sur rapport `07`, élément de batterie `0A 1A` (lecture seule) |
| **WLMouse** | YING Magnesium (récepteur 8K `36A7:A874`) ; Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (récepteur ou câble ; pas la Beast X 4K) ; Beast X V2 (récepteur 8K `36A7:A856`) ; Beast G (récepteur 8K `36A7:A860` ou câble `36A7:A861` ; non testé) | Rapport de fonctionnalités constructeur, commande d'état `0x83` (YING : même protocole que Glorious) |
| **Finalmouse** | UltralightX sur son dongle 2,4 GHz (`361D:0100`, testé) ; Starlight X sur son dongle (`361D:0300` / `0301`, testé). Pas sur le câble de la souris | Rapports constructeur xpanel sur `FF00` : requêtes GET en lecture seule, puis *wake/all* (`0xE0`) ; tension de batterie selon la courbe xpanel, ou pourcentage propre de la Starlight X, plus état de charge |
| **VAXEE** | Souris sans fil sur le récepteur VAXEE 4K (`3057:1002`) ou 8K (`3057:2002`, ex. NP-01 Ergo Wireless 8K) ; ZYGEN NP-01S V2 Wireless par câble USB (`3057:1011`) | Rapport de fonctionnalités constructeur en lecture seule `0E` sur `FF05:0001` ; batterie par paliers de 5 %, état de charge ([notes sur le protocole](#sec-vaxee)) |
| **Scyrox** | V12M sur son récepteur 2,4 GHz (`395A:0006`) | Lecture de profil S-Center 2.0 (rapport de sortie `08`, commande `01`) sur `FF00:0002` ; batterie uniquement, sans état de charge |
| **HECATE** | G5M PRO et autres souris HECATE sur le même récepteur, et câble USB `35BB:D3FA / D3FC / D3FD` | Protocole Kysona |
| **Redragon** | Souris sans fil basées sur Compx : M916 Pro 1K (testé), M913 Impact Elite (tri-mode), G49 (récepteur ou câble) | Protocole Kysona (les récepteurs Areson `25A7` sont listés sous Areson) |
| **Taidu (钛度)** | TSG808 sur son récepteur Compx 2,4 GHz `3554:F5D5` (testé) | Protocole Kysona |
| **Areson (Redragon)** | M915RGB-WL (testé), M913 Impact Elite d'origine et autres souris sur le récepteur `25A7:FA07` / `FA08` | Rapport de fonctionnalités `GetPower` sur 17 octets ; niveau par paliers de 10 % et indicateur de charge |
| **Ninjutso** | Sora V2 sur le récepteur 1K (`1915:AE1C`, testé) ou câble USB (`1915:AE11`, testé) ; Ten Air (récepteur `093A:EB01` et câble USB `093A:E020`, testés) / Ten (`093A:EB01` / `E020`, non testé) | Rapport de fonctionnalités NinjaForce `0x05` (`0x15` pour Sora V2) et `0x06` (`0x13`/`0x12`/`0x11` pour Ten / Ten Air) |
| **Sprime** | PM1 sur le récepteur 2,4 GHz (`1915:AC1C`, testé ; `1915:AD8C`) ou câble USB | Même rapport de fonctionnalités 0x05, commande d'état 0x15, issu du pilote web de Sprime (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 sur le récepteur RAWM HS (`1915:2346`, testé) ; souris ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, SA-* et SADES Dagger sur leurs récepteurs RAWM (`1915:232A`–`234B`) ou câble USB | Requête d'informations d'appareil RAWM HUB 2.0 via le récepteur (JSON avec % de batterie et charge), lecture seule ([notes sur le protocole](#sec-rawm)) |
| **AULA** | Claviers sans fil F75 / F87 Pro / F99 sur le récepteur 2,4 GHz | Trame de rapport 0x13, commande 0x4A, somme de contrôle additive (modes Bluetooth et filaire non testés) |
| **Souris AULA** | X9 Ultra (testé) sur le dongle AULA-8K `320F:22A0` ; identifiant du récepteur partagé avec les modèles V9 | Rapport `04`, commande de batterie en lecture seule `1A` entre START `01` / END `02` sur `FF1C:0092` ; 2,4 GHz uniquement |
| **Claviers SONiX (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (testé), EPOMAKER EA75 (testé), AULA F108 Pro sur le dongle 2,4G `05AC:024F` ; AJAZZ AK980 V2 sur le dongle `0C45:FEFE` ; AJAZZ AK820 Pro sur le dongle `0C45:FDFD` ou `0C45:FEFE` ; EPOMAKER P75 sur `342D:E479` (non testé sur matériel) | Rapport constructeur `20 01` sur la page d'usage FF60, somme de contrôle additive (mode 2,4G uniquement ; sans indication de charge) |
| **Récepteurs SONiX supplémentaires (non testés sur matériel)** | RK Royal Kludge R75 (`342D:E485`) ; Redragon Arlokks K742B (`342D:E4BC`) ; M1 V5 VIA (`342D:E4C2`) ; Lucky65V2 (`342D:E407`) ; Lofree Flow2 (`388D:0003`) ; MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`) ; Essential75 (`36B0:30BD`) ; NUT65 (`342D:E51A`) ; RK 2.4G Dongle (`342D:E487`) ; WEIKAV MAX102 (`342D:E537`) ; Lofree Flow2 (`388D:0002`) ; NuPhy Air75V2 (`19F5:3245`) ; SKN Qinglong (`362D:D028`) ; Lemokey Link (`362D:D030`) ; Wireless Link (`362D:D101`) ; Spade65-QMK-2.4GHz (`342D:E49F`) | Même requête `20 01` pour batterie seule ; VID:PID exact et collection FF60:0061 avec rapports de 33 octets requis ; 2,4G uniquement, sans indication de charge |
| **Claviers 36B0 (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB sur le dongle 2,4G `36B0:3002` ou câble USB `36B0:3009` (protocole testé sur les deux par l'auteur de #343) ; Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) sur le même dongle ou câble (non testés) ; URX Core75 sur le dongle (confirmé dans HaloBattery) ; EVO80 (non testé) | Firmware PMO Hub : `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` sur la page d'usage FF60, issu de pmohub.cn. Firmware URX / VIA : VIA custom-get `08 00 07` (canal 0, valeur 7), issu d'URX HUB via HaloBattery. Sans indication de charge |
| **DAREU** | EM901X sur le récepteur 2,4 GHz `260D:1074` ou câble USB `260D:1090` (relevé de batterie testé sur les deux ; transitions de charge sur station du récepteur testées) | Rapport de fonctionnalités batterie seule `08`, commande `04` ; réponse `09` sur une collection constructeur distincte. Nécessite une paire entrée/fonctionnalité univoque par identifiant de produit. Privilégie une mesure USB valide lorsque les deux sont connectés ; le récepteur peut renvoyer des données en cache même souris éteinte |
| **DAREU** | Clavier A84 (`260D:0022`, non testé) | Rapport de fonctionnalités SONiX sur l'interface 0, commande `04 F6` (lecture de batterie du pilote officiel A84) ; niveau en pourcentage, sans indicateur de charge |
| **DAREU** | A980 Pro sur le récepteur multi-souris `260D:1131` et sur son câble USB (`260D:1148`) (niveau de batterie testé sur matériel ; indicateur de charge confirmé lorsque branché) | Protocole Togran : rapport de fonctionnalités sur 65 octets `0A` sur la collection consumer-control ; requête d'emplacement (classe 0 / `A0`) puis requête de batterie (classe 7 / `80`), sur l'emplacement 0 par câble. Lecture seule |
| **Sharkoon** | Skiller SGM50W sur `260D:1125` (non testé) | Même requête Compx que la DAREU EM901X (rapport de fonctionnalités `08`, commande `04` ; réponse `09` sur `FF01:0000`) ; l'outil de mise à jour de firmware de Sharkoon est un outil Compx sur le VID `260D` |
| **Zenith** | Zenith Pro sur le récepteur 2,4 GHz `260D:1114` (relevé de batterie testé ; charge non testée) ou câble USB `260D:1143` (non testé) | Même commande Compx (`08`, `04`) en rapport de sortie sur `FF02:0002` ; réponse `08 04` sur la même collection avec pourcentage, indicateur de charge et millivolts, vérifiée par somme d'octets égale à `0x55` |
| **AJAZZ AK992** | Récepteur Telink 2,4 GHz `320F:50C3` (testé) | Requête de batterie EVision sur la collection HID `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, série DW (U2-DW, S2-DW ...) et U2 sur son récepteur 2,4 GHz | Commandes constructeur en lecture seule documentées par la communauté |
| **Royal Kludge (RK)** | MG6 Pro sur le dongle 2,4 GHz (`2E3C:00A6` / `00E6`) ou câble USB (`2E3C:00A5` / `00E5`) | Trame QiWang sur 64 octets issue du pilote web RK, lecture `GET_BATTER_VOL` (pourcentage, tension, charge) |
| **ASUS ROG** | Claviers Strix Scope II 96 (RX), Azoth, Falchion ; souris Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact ; casque Pelta (dongle 2,4 GHz) ; écouteurs Cetra Open Wireless (dongle SpeedNova `0B05:1CAC`, G / D / boîtier) ; l'Omni Receiver | Requête de batterie HID ROG |
| **Machenike** | L7 Arctic / L7 Mix sur le récepteur 2,4 GHz `248A:FF4C` ou câble USB `248A:FF4E` (tous deux testés) | Rapport de fonctionnalités en lecture seule `51`, commande d'état `06` ; batterie et charge. [Notes sur le protocole](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS sur son dongle 2,4 GHz (`0DB0:9E22`) ; CLUTCH GM31 Lightweight Wireless (récepteur 2,4 GHz `0DB0:0D3C`, testé ; câble USB `0DB0:0D3B`) et CLUTCH GM41 Lightweight Wireless (récepteur `0DB0:0D4C` / câble `0DB0:0D4B`, d'après les captures d'un propriétaire) | Requête constructeur en lecture seule `0F 20` sur `FF0D:00B0` et `FF00:0001` ; batterie et indicateur de charge dans un octet (protocole issu du module Gaming Gear de MSI Center) ; GM41 : rapports passifs `A0 xx 07 …` sur `FF10:0006` |
| **MCHOSE** | Souris L7 / L7 Pro / L7 Ultra (L7 Ultra testée), M7 / M7 Ultra, A7 / A7 Ultra, K7 sur le récepteur 2,4 GHz ou câble USB ; A5 V2 Ultra (récepteur 2,4 GHz `3837:100C`, testé), K7 Ultra (récepteur 2,4 GHz `3837:1001`, testé ; A7 V2 Ultra+ `3837:100B` censé fonctionner, issue 227) ; G3 V2 (récepteur 2,4 GHz `3837:4245` et câble USB `3837:418C`) ; K7 V2 Ultra+ sur le récepteur 2,4 GHz `3837:1014` ou sur son câble USB `3837:4028` (tous deux testés ; les autres identifiants de récepteurs de la nouvelle famille `1018`, `1016`, `102C`, `102D` ne sont pas testés) | Rapport de fonctionnalités constructeur, charge utile inversée (protocole issu d'alexfrih/mchose-linux) ; les dongles Realtek `3837` répondent à la même requête avec le champ vid défini à `41E4` (A5 V2 Ultra) ou `3837` (K7 Ultra) ; G3 V2 : requête constructeur en lecture seule sur `FF01:0010` ; K7 V2 Ultra+ : rapport sur 64 octets `0x4D`, commande d'infos d'appareil `0x0900` sur `FF01:0001` (protocole issu du pilote web M HUB) |
| **MCHOSE A5 (première génération)** | A5 Pro / A5 Pro Max sur le récepteur 2,4 GHz 1K ou 4K (`2023:F013`, `2023:F015`, `2023:F018`) ou le câble USB (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max) ; non testé ici | Commande de batterie en lecture seule `0x83` (page 0) dans un rapport de fonctionnalités sur 64 octets sur `FFFF`, réponse marquée `0xA1` (protocole issu du pilote web z750sasr A5 Pro Max et de HaloBattery, identifiants issus de Klegus/mchose-macos) |
| **Casques MCHOSE** | V9 Pro 2 sur le dongle 2,4 GHz (`3837:6011`, testé) | Trame de batterie « MC » en lecture seule de M HUB (rapport `0x55`, sous-commande `0x0B`) sur `FF07:0222` ; batterie et indicateur de charge dans un octet (protocole issu du pilote web M HUB) |
| **Claviers AULA / MCHOSE / Redragon** | AULA F75 / F87 Pro / F99 ; MCHOSE K99 V2, G75 Pro, X75 et les autres claviers M HUB ; Redragon Horus Pro / Pro V2 (K618RGB-PRO) sur le récepteur 2,4 GHz (`3554:FA09`, `41E4:2001`) ; MCHOSE K87 sur le récepteur `05AC:024F` (disposition BY sur l'interface 1, pas le SONiX) | Trame de rapport 0x13, commande 0x4A (modèles MCHOSE et Redragon identifiés par la commande 0x05, comme dans M HUB) ; modes Bluetooth et filaire non couverts |
| **Claviers MCHOSE** | G75 V2 sur le récepteur 2,4 GHz `3837:3033` (testé) ; le même récepteur est livré avec les G87 V2 et K99 V3 (même protocole, non testés) ; le K87S associe le même identifiant de récepteur à un autre protocole et n'est pas couvert | Requête func-config « GLW » en lecture seule de M HUB sur la collection sans ID sur 64 octets `0001:0000` : indicateur de requête `0x55`, commande `0x05`, batterie dans l'octet 32 de la charge utile (bit 7 = en charge), somme de contrôle additive |
| **AULA SC580** | Souris SC580 / SC580X par câble USB (`088D:062E`, testé) ou son récepteur 2,4 GHz (`089D:062F`, testé) | Commande en lecture seule `0x30` (infos d'appareil) sur la collection constructeur de 33 octets FF02:0000, somme de contrôle additive ; pendant la charge, la souris rapporte un 100 fixe, donc le dernier niveau est conservé ; mode Bluetooth non couvert |
| **AULA HERO 68 Air** | HERO 68 Air sur le récepteur sans fil 8K (`372E:106C`) | Trames acquittées de 20 octets sur la page d'usage FF60 (quatre trames de données et un pied de trame par message), commande de batterie en lecture seule 0x87, indicateur de charge 0x10 après le niveau ; modes Bluetooth et filaire non couverts |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra et S9 Max / Pro / Ultra / Ultra+ sur le récepteur « Gaming 2.4G » (`372E:103D`) ; S9 Ultra sur son câble USB (`372E:1027`) | Rapport de fonctionnalités en lecture seule `03` sur `FF00:0001` : vérification de liaison `47`, infos de base d'appareil `4F 81` (% de batterie et bit de charge), issu du pilote web EWEADN |
| **Rapoo VT** | VT3 Max Gen 2 (testé) ; VT9 Gen 2 (testé) ; autres souris Nordic 54L VT exposant la même interface d'état ; ancien VT3 Pro (expérimental) ; VT1 Pro Max (d'après les captures USB du propriétaire) | Rapport d'état HID passif `07` sur `FF00:0002` (16 ou 19 octets ; 13 octets sur certains récepteurs VT3 Max Gen 2) ; ancien protocole `BB` restreint au VT3 Pro `1215/4415` et VT1 Pro Max `1233/4433`. Récepteur et câble USB, avec état de charge |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (modèles Xenta 30/50 ; ancien 3D), Delux M800 Pro, famille Ajazz AJ179 ; AJ159 et autres souris de la série AJ sur le récepteur 3151 ; AJ139 V2 MC (récepteur `A8A5:2255`, câble `A8A4:2255`) | Rapports constructeur (M900 Pro : diffusions d'état passives ou requête de fonctionnalités, événements Xenta 40/41 ; série AJ : interrogation d'état 0xF7, puis rapport de fonctionnalités 0x05) |
| **Incott** | G23 V2 / G24 (récepteur `093A:522C`, câble `093A:622C`) | Rapport de fonctionnalités d'état en lecture seule 09 |
| **Attack Shark et autres marques chinoises** | Récepteurs Rongyuan (81 modèles : Attack Shark R3 et AJAZZ AJ179 Pro sur `3151:402D`, K86, X82 PRO HE, claviers Ajazz, certains MSI et autres ; le K86 en Bluetooth apparaît comme clavier) ; récepteurs Xenta (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6 ; la X6 aussi sur `1D57:FA61`, non testé) ; claviers Semico 1A2C (Attack Shark X98 sur dongle `1A2C:8FFF`, testé, et câble `1A2C:A034` ; AJAZZ AK820 Max Plus sur `1A2C:8FFF` / `1A2C:A036`) | Rapport d'état Rongyuan ; diffusions passives Xenta ; requête d'état Semico en lecture seule `0x0E` (`AA 55 CC 33` sur `FF02:0002` ; indicateur de charge omis car le X98 rapporte `state=1` sur batterie comme en charge) |
| **Wraith** | W1 / W1 Freestyle (récepteur `093A:522C`, câble `093A:622C` ; mêmes identifiants qu'Incott, distingués par le code modèle) | Lectures par bouton en lecture seule `86` (rapport de fonctionnalités 09) sur tous les boutons, puis rapport d'entrée d'état poussé 09 |
| **Fantech** | Helios Go XD5 (filaire `25A7:FA7B`, dongle `25A7:FA7C`) ; Raigor III (testé), Raigor II WG10 et autres souris génériques 2.4G Mouse sur le dongle réutilisé `1EA7:0066` / `1EA7:0064` | Helios Go XD5 : rapport de fonctionnalités constructeur `08`, commande `04`, somme de contrôle jusqu'à `0x55`. Raigor/2.4G Mouse : requête de page d'état `B5` en lecture seule sur `FFB5:0001`, bloc `94` = dernier pourcentage rapporté (peut être obsolète en veille, éteint ou en charge ; sans état de charge) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, adaptateur sans fil) ; casques INZONE H9 II et H5 ; INZONE Buds (dongle USB-C) | Rapport d'entrée ; protocole constructeur INZONE |
| **Fractal Design** | Casque Scape sur son dongle 2,4 GHz ou câble USB-C | Requête constructeur `GET_DEVICE_STATE` issue de l'application web Adjust Pro de Fractal (page d'usage FF00) |
| **Jabra** | Chaque casque Jabra parlant le protocole GN (Evolve2 / Evolve3 et autres), sur son propre câble USB ou derrière un dongle Jabra Link ; aucune liste d'identifiants de produit, bases DECT (Engage, PRO 9xx, GO 6400, Link 400) exclues ; nom lu depuis le casque | Requête d'état GNP (classe 12 / op 02) sur la page d'usage FF00, usage 05 ou 01, à l'adresse GNP 08 (USB) ou 04 (dongle) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), récepteur 2,4 GHz ou USB ; Apex 5 (`37D7:2501`), récepteur 2,4 GHz ou USB | Requête d'informations HID constructeur sur `FFA0:0001` ; niveau de batterie 0–5 converti en 0–100 % par paliers de 20 %, avec état de charge ; aucun service Space Station requis |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite sur le récepteur 2,4 GHz ; Nova 2 Lite en USB ; G7 Pro (testé : édition Zenless Zone Zero, récepteur `3537:105E`) et autres manettes GameSir en mode Xbox (GIP) ; Cyclone 2 (mode XInput, récepteur ou câble) ; Cyclone Pro sur son dongle 2,4 GHz (`3537:1015`, appairez la manette une fois avec Windows en Bluetooth) | Requête d'informations d'appareil constructeur (page d'usage FF7A) ; rapport de batterie Windows.Gaming.Input (% réel) en mode Xbox ; Cyclone 2 : requête de batterie constructeur (page d'usage FFF0) ; Cyclone Pro : requête base-info de l'application GameSir via Bluetooth LE (service `0x8650`), lue toutes les 2 min |
| **BEITONG** | KP20 / BTP-KP20 sur son récepteur 2,4 GHz (`20BC:5128`, mode XInput, testé) et KP40D / BTP-KP40D sur son récepteur (`20BC:515C`, mode XInput) ; BEITONG iControl non requis | Requête constructeur « get base info » sur la page d'usage `00FF` (rapport `02`, charge utile brouillée par quartets), avec état de charge |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` testé sur dongle 2,4 GHz, D-input `2DC8:6012` — maintenez B en l'allumant, firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Requête d'état HID constructeur (`FF7A`/`FFA0`) et rapport d'entrée de manette SDL `01`/`04`, avec état de charge |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Trame d'état poussée par les écouteurs sur le service RFCOMM (SPP) de Samsung, lecture seule. La zone de notification affiche l'écouteur le plus bas ; l'info-bulle détaille gauche, droit et boîtier. L'application Galaxy Buds doit être fermée |
| **Nothing / CMF** | Nothing Ear (3a) (testé), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Requête de batterie en lecture seule `0xC007` sur le service RFCOMM NT Link de Nothing (`aeac4a03-dff5-498f-843a-34487cf133eb`). La zone de notification affiche l'écouteur le plus bas ; l'info-bulle détaille gauche, droit et boîtier |
| **Akko** | Akko Air 01 (`3151:5006`, récepteur 2,4 GHz, testé) et Akko V9 Dash Pro (`38EE:000C`, récepteur 2,4 GHz, testé) | Air 01 : rapport d'état Rongyuan `0xF7` ; V9 Dash Pro : requête d'état en lecture seule sur 64 octets `0x1A` sur `FF1C:0092` avec état de charge |
| **MOONDROP** | Casque GM01 Pro sur son dongle 2,4 GHz (`35D8:0133`) ; sur son câble USB il s'affiche en charge avec le dernier niveau | Commande de lecture constructeur WalkPlay sur le rapport `4B` (lecture seule) |
| **VGN** | Casque OMNISOUND (ZHOUTING) sur son dongle 2,4 GHz (`372E:10BB`, testé) | Requête « ZHOU » de V HUB : rapport de sortie `55` avec charge utile `65 01` sur la collection de contrôle `000C:0001` (rapports d'entrée de 32 octets, de sortie de 64 octets) ; le pourcentage est renvoyé dans la réponse (lecture seule) |
| **JBL** | Quantum 650 Wireless (testé, dongle 2,4 GHz) ; Quantum 520, 650X, 850, 950, 950X Wireless (dongle ou câble USB, même protocole, non testés) | Requête d'informations d'appareil JBL « HIDV3 » pour la fonctionnalité batterie (page d'usage FF12), avec état de charge |
| **JBL** | Quantum 350 Wireless (testé sous Windows avec le récepteur 2,4 GHz `0ECB:206B`) ; Quantum 610 Wireless (dongle 2,4 GHz `0ECB:205C`, non testé sous Windows) ; Quantum 360 Wireless (dongle 2,4 GHz `0ECB:2115`, non testé) | Rapports de fonctionnalités HIDV1 pour la connexion sans fil et le pourcentage de batterie |
| **Xbox** | Manettes sur l'adaptateur sans fil Xbox, USB ou Bluetooth ; casques branchés sur une manette | Rapport de batterie Windows.Gaming.Input (% réel), repli XInput |
| **Compatible Switch Pro** | Manettes se présentant comme `057E:2009` (testé : GameSir Tarantula Pro via le récepteur 2,4 GHz en mode Switch) | Cinq niveaux de batterie issus du rapport HID `0x30` après activation des rapports complets par Steam Input ou un autre hôte |
| **Apple AirPods / Beats** | AirPods Max (testé, `200A` Lightning et `201F` USB-C), AirPods Pro 3 (testé, `2027`), AirPods Pro 1 / 2, AirPods 1–5 et casques/écouteurs Beats | Diffusions BLE « proximity pairing » (`0x07`) (batterie unique pour AirPods Max et casques Beats ; gauche, droit et boîtier pour les écouteurs, par paliers de 10 % avec état de charge), associées au modèle appairé |
| **Téléphones (Mobile connecté)** | Tout téléphone Android relié à Mobile connecté (Microsoft Phone Link), en Wi-Fi ou Bluetooth (testé : Nothing Phone (4a) Pro) | Batterie et état de charge issus de la carte du menu Démarrer Windows 11 de Mobile connecté (`StartMenuCompanion.json`) ; aucun Bluetooth requis |
| **Darmoshark** | M3 (`248A:FF30`) et M3S (`248A:FF31`) sur leurs récepteurs 2,4 GHz sous Windows | Rapport de fonctionnalités HID pour l'identité de la souris et la batterie |
| **Darmoshark** | M3S Pro sur le récepteur Nordic 1K (`1915:0723`) | Requête d'état HID constructeur sur la collection `FF0A` |
| **Alienware** | Casque AW920H sur son dongle 2,4 GHz (`413C:A515`, testé) ; en Bluetooth il est couvert par la ligne Bluetooth | Requête constructeur `06 C0 0A` sur `FF13:0001`, rapport de réponse `07` avec somme de contrôle XOR ; champs de niveau, charge et niveau critique tels que décodés par le plugin AW920H d'Alienware Command Center |
| **Niceboy** | MW400 sur son récepteur 2,4 GHz (`248A:FA02`, testé) | Requête sur rapport `05` en lecture seule `24 FA 48` ; tension de batterie convertie en paliers de 10 % selon la table de l'application constructeur, indicateur de charge |
| **Bluetooth** | Tout appareil affichant une batterie dans *Paramètres → Bluetooth et appareils* (écouteurs, casques, souris et claviers BLE). Les écouteurs Google Fast Pair (Jabra Elite 8 Active testé ; Pixel Buds et de nombreux modèles Sony / JBL / Bose) obtiennent aussi les niveaux gauche, droit et boîtier | Propriété d'appareil Windows ; diffusions de batterie Fast Pair (données de service BLE `FE2C`), associées à l'appareil appairé par adresse Bluetooth |
| **HID générique** | Appareils exposant l'usage HID standard *Battery Strength* | Page d'usage HID 0x06 / 0x85 |
| **HeadsetControl** | [Tous les casques qu'il prend en charge](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, Logitech récents et plus) | Inclus ; exécute `headsetcontrol -o json` |
| **MAONO PD200W** | Récepteur 2,4 GHz (352F:040E) | Pourcentage de batterie ; testé sur matériel |


**Testés sur du matériel réel :** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (récepteur PlayStation `0951:1713` ; charge non testée), HyperX Cloud Core Wireless DTS (récepteur `0951:173F` ; niveau de pleine charge non testé), HyperX Pulsefire Haste 2 Core Wireless (dongle `03F0:0AB5` ; les dongles Haste 2 Wireless ne sont pas testés), Cooler Master MM712 (dongle), Rapoo VT3 Max Gen 2 (récepteur `24AE:1417` et câble USB `24AE:4617` ; les autres modèles Rapoo ne sont pas testés, voir les [notes sur le protocole Rapoo](#sec-rapoo)), Redragon M916 Pro 1K (récepteur `3554:F55D`), Taidu TSG808 (récepteur `3554:F5D5`), Redragon M915RGB-WL (récepteur `25A7:FA07` ; les autres modèles Areson ne sont pas testés, voir les [notes sur le protocole Areson](#sec-areson)), SteelSeries Rival 650 Wireless (récepteur `1038:1726` et câble USB `1038:172B`), SteelSeries Arctis Nova Pro Wireless (station de base `1038:225D` ; lecture de batterie testée, transitions de charge et d'alimentation non testées), HECATE G5M PRO (récepteur `35BB:D3FB`), WLMouse YING Magnesium (récepteur 8K `36A7:A874`), ATK N9 Ultra (récepteur `373B:1204`), Corsair Scimitar Elite SE Wireless (récepteur Slipstream `1B1C:2B00`), Corsair Dark Core RGB Pro SE (récepteur Slipstream `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (récepteur 2,4 GHz `1B1C:2B2A` ; lecture de batterie vérifiée), DAREU EM901X (récepteur `260D:1074` ; charge et veille/réveil non testés), Jabra Evolve3 75 sur un Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (récepteur `3837:4245` et câble USB `3837:418C`), MCHOSE K7 Ultra (récepteur `3837:1001`), MCHOSE K7 V2 Ultra+ (récepteur `3837:1014` et câble USB `3837:4028` ; charge affichée lorsque branché), MSI VERSA 300 ELITE WIRELESS (dongle `0DB0:9E22` ; charge et gestion de la veille non testées), MSI Clutch GM31 Lightweight Wireless (récepteur `0DB0:0D3C` ; la GM41 utilise le même pilote d'après les captures d'un propriétaire), AJAZZ AK820 MAX (dongle `05AC:024F`), AULA HERO 68 Air (récepteur sans fil 8K `372E:106C`), AULA SC580 (câble USB `088D:062E` et récepteur `089D:062F`, y compris charge et veille), AirPods Pro 3 (Bluetooth, modèle `2027`), AirPods Max (Bluetooth, modèle `200A`), Sprime PM1 (récepteur `1915:AC1C`), Ninjutso Ten Air (récepteur `093A:EB01` et câble USB `093A:E020`), MOONDROP GM01 Pro (dongle `35D8:0133`), Delux M800 Pro (récepteur `248A:5B2F`), Razer Barracuda X (2022) (récepteur `1532:0550` ; niveau de batterie lu, transitions de charge non testées), Razer BlackShark V3 X (dongle HyperSpeed `1532:057D`), Fantech Helios Go XD5 (dongle `25A7:FA7C`), Fantech Raigor III (dongle `1EA7:0066` ; charge non signalée par le firmware), Finalmouse UltralightX (dongle `361D:0100`), Finalmouse Starlight X (sur son dongle), et Chimera V2 (récepteur `3554:F512` ; niveau de batterie et charge lus).
Également testés sur matériel : Machenike L7 Arctic / L7 Mix (récepteur `248A:FF4C` et câble `248A:FF4E`), y compris charge et suppression des doublons câble/récepteur. Le Bluetooth et les bornes batterie faible/pleine charge n'ont pas été testés sur matériel.
Également testé sur matériel : MCHOSE V9 Pro 2 (dongle `3837:6011`) ; niveau de batterie lu, charge et veille non testées.
Également testé sur matériel : EPOMAKER EA75 sur son récepteur 2,4 GHz `05AC:024F`, à l'aide du pilote SONiX existant issu de [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). Le pourcentage de batterie, la reconnexion du récepteur et la reprise après allumage ont été vérifiés. L'indication de charge et le rapport de batterie en filaire ne sont pas pris en charge par ce pilote ; le rapport de batterie en Bluetooth n'a pas été testé. Le pourcentage rapporté peut sauter à 100 % lorsque l'alimentation USB est branchée, ce qui n'est pas un indicateur de charge fiable.
Également testée sur matériel : SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (récepteur `1038:1878` et câble USB `1038:187A`), y compris la charge, l'extinction (le dernier niveau reste affiché, estompé) et avec SteelSeries GG en cours d'exécution ; GG n'affiche qu'une barre à trois niveaux, à laquelle le pourcentage correspondait.
Également testée sur matériel : RAWM Leviathan V4 (récepteur RAWM HS `1915:2346` ; niveau de batterie lu, charge non testée).
**Implémentés d'après la documentation des protocoles et d'autres projets, pas encore testés :** tout le reste, y compris la Fantech Raigor II WG10 (même dongle `1EA7:0066` et même collection que la Raigor III testée, elle devrait donc fonctionner). Si vous possédez l'un de ces appareils, merci de signaler s'il fonctionne en [ouvrant une issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues).

## Installation

[![Dernière version](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Téléchargez **`BatteryHub-Setup-<version>.exe`** depuis la [dernière version](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. Exécutez-le, choisissez l'une des 19 langues prises en charge par l'assistant et suivez les étapes. Il ne nécessite **aucun droit d'administrateur** et **aucune autre installation** : aucun runtime, aucun pilote, aucun logiciel fabricant. HeadsetControl est inclus et le dossier modifiable `lang\` est installé à côté de `BatteryHub.exe`.

L'installateur ajoute un raccourci dans le menu Démarrer et un programme de désinstallation (*Paramètres → Applications*), et peut lancer l'application à l'ouverture de votre session. Vous préférez éviter l'installateur ? Téléchargez `BatteryHub-<version>-portable.zip`, décompressez-le n'importe où (conservez le dossier `lang\` à côté de `BatteryHub.exe` pour les traductions de l'interface) et exécutez `BatteryHub.exe`.

**Remarques :**
- **Avertissement SmartScreen :** l'exécutable n'étant pas signé numériquement, Windows peut afficher « Windows a protégé votre ordinateur ». Cliquez sur *Informations complémentaires → Exécuter quand même*, ou compilez-le vous-même.
- **Mode icônes de notification sous Windows 11 :** les nouvelles icônes vont dans le menu de débordement `^`. Faites-les glisser sur la barre des tâches ou activez-les dans *Paramètres → Personnalisation → Barre des tâches → Autres icônes de la barre d'état système*.
- **Tenir l'application à l'écart d'un appareil :** si un appareil se comporte anormalement lorsque l'application tourne, ajoutez-le à la chaîne de Registre `IgnoreDevices` sous `HKCU\Software\WirelessBattery` sous forme de paires `VID:PID` (en hexadécimal, séparées par des virgules, ex. `28BD:0947, 1234:ABCD` ; `--dump` affiche les identifiants). L'application ne l'ouvrira alors jamais. Les tablettes graphiques sont automatiquement ignorées.

## Mises à jour sous Windows

Les versions officielles stables pour Windows recherchent en arrière-plan la dernière version stable publiée du projet, 30 secondes après le démarrage puis toutes les 24 heures tant que l'application est en cours d'exécution. Ouvrez le menu pour voir **Mise à jour disponible : vX.Y.Z...**, ou choisissez vous-même **Rechercher des mises à jour...**. Les informations de mise à jour n'apparaissent que dans ce menu : les icônes de batterie, pourcentages et info-bulles restent inchangés, et les vérifications automatiques n'affichent jamais de notification ni de boîte de dialogue. Désactivez **Rechercher les mises à jour automatiquement** dans le menu pour couper les vérifications en arrière-plan.

Pour une copie installée, cliquez sur l'entrée de mise à jour puis sur **Télécharger et installer**. Rien n'est installé sans ce clic. L'application télécharge le fichier `SHA256SUMS.txt` de la version et sa signature, vérifie la signature avec la clé publique du mainteneur intégrée à l'application, télécharge l'installateur Windows et ne l'exécute que si son SHA-256 correspond à celui de la liste signée (et à celui indiqué par GitHub). Il met ensuite à jour l'installation existante. Les paramètres et le choix de démarrage automatique sont conservés, et l'application se rouvre après l'installation. Une installation pour tous les utilisateurs peut demander les droits d'administrateur. **Notes de version** ouvre la page officielle des versions ; **Plus tard** conserve votre version actuelle. Les copies portables proposent la page des versions pour télécharger l'archive ZIP manuellement.

Les vérifications interrogent l'API publique de GitHub sans compte ni jeton. Aucune information sur vos appareils ou leurs batteries n'est envoyée. Les échecs hors ligne et les limites de débit de GitHub laissent la surveillance de batterie fonctionner ; une version précédemment détectée reste dans le menu jusqu'à ce qu'une vérification réussie la remplace ou qu'elle soit installée. L'annulation d'un téléchargement attend que l'opération réseau en cours atteigne son délai maximal fini. L'installateur ne redémarre jamais Windows automatiquement.

**Pourquoi les mises à jour sont sûres à installer :** la clé de signature ne va jamais sur GitHub. Le mainteneur signe la liste des sommes de contrôle de chaque version sur son propre PC (voir [docs/releasing.md](#sec-releasing)), de sorte que même une personne qui prendrait le contrôle du compte GitHub ou de son workflow de compilation ne pourrait pas publier une mise à jour que l'application installerait. Une version sans signature valide s'affiche dans le menu mais ne peut être téléchargée que manuellement. La signature ne remplace pas les invites SmartScreen ou UAC propres à Windows.

Installez manuellement une fois la première version incluant cette fonctionnalité. Les versions de développement/test désactivent les vérifications officielles afin que les modifications locales ne puissent pas être remplacées par erreur. Les mises à jour sous Linux et le remplacement automatique des copies portables sont reportés.

## Ligne de commande

```
BatteryHub.exe --list     # affiche chaque appareil et son niveau de batterie, puis quitte
BatteryHub.exe --json     # affiche un tableau JSON des appareils et niveaux de batterie, puis quitte
BatteryHub.exe --dump     # liste chaque collection HID, les périphériques HID impossibles à ouvrir, tous les
                          # périphériques USB (y compris sans interface HID) et Bluetooth ; enregistré aussi dans %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # ouvre la fenêtre « Demander la prise en charge d'un appareil »
BatteryHub.exe --demo     # affiche des appareils d'exemple de chaque marque (captures d'écran, vérification des couleurs)
BatteryHub.exe --quit     # ferme l'instance en cours d'exécution
```

La version Linux utilise les mêmes options avec `wireless-battery` au lieu de `BatteryHub.exe`, et accepte aussi `--help`. `--json` affiche un tableau stable que les scripts et widgets de barre peuvent analyser :

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` indique combien de temps l'application continue d'afficher le dernier niveau connu lorsque l'appareil est en veille. L'ajout de nouveaux champs est rétrocompatible.

**Appareil non affiché ?** Faites un clic droit sur le widget ou l'icône de notification et choisissez **Demander la prise en charge d'un appareil...**. Sélectionnez l'appareil, vérifiez ce qui sera envoyé (affiché mot pour mot : nom de l'appareil, type, identifiants USB/HID et structure des interfaces, ainsi que votre nom et vos remarques facultatifs) puis cliquez sur **Envoyer**. La demande rejoint la liste publique sur [krisgfx.com/tools](https://krisgfx.com/tools/#requested) et ouvre ou met à jour une issue GitHub. **Copier le rapport complet** place le `--dump` complet dans le presse-papiers pour l'issue. Les données du rapport ne sont envoyées que lorsque vous cliquez sur Envoyer. Les versions Windows officielles peuvent également contacter GitHub pour rechercher des mises à jour, comme décrit dans [Mises à jour sous Windows](#mises-à-jour-sous-windows) ; les vérifications de mise à jour n'envoient aucune information sur les appareils ou les batteries.

## Compilation

Vous aurez besoin de [MinGW-w64](https://www.mingw-w64.org/), par exemple via [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # compilation de développement, version 0.0.0
build.bat                                 # invite de commandes classique avec g++ et windres dans le PATH
make VERSION=1.2.3 CHANNEL=test            # compilation versionnée, mises à jour officielles désactivées
build.bat 1.2.3 test                       # compilation cmd versionnée équivalente
make test VERSION=1.2.3 CHANNEL=test       # tests de régression des appareils et de la mise à jour
```

Pour générer l'installateur et l'archive ZIP portable, installez [Inno Setup](https://jrsoftware.org/isinfo.php), compilez d'abord avec la version voulue (par exemple `make VERSION=1.2.3 CHANNEL=test`), puis exécutez `powershell -File installer\build-installer.ps1 -Version 1.2.3`. L'empaquetage refuse une version qui diffère de l'exécutable. Il télécharge la version figée de HeadsetControl et vérifie sa somme de contrôle. GitHub Actions automatise tout cela : pousser un tag tel que `v1.0.0` publie une version avec l'installateur, l'archive ZIP portable et les sources de HeadsetControl (comme l'exige sa licence GPL).

La compilation sous Windows nécessite également PowerShell pour générer la version partagée entre l'exécutable et les ressources. Les tags de version du dépôt officiel compilent avec `CHANNEL=stable` ; les compilations locales utilisent `dev` par défaut. Les forks et pull requests n'activent pas les mises à jour officielles automatiquement.

`BatteryHub.exe` fonctionne aussi seul. Sans `headsetcontrol.exe` à côté (ou dans le `PATH`), vous perdez simplement les casques supplémentaires pris en charge par celui-ci.

## Linux (expérimental)

Une version Linux accompagne l'application Windows. Elle utilise les mêmes pilotes constructeurs avec un backend HID basé sur hidraw et une icône de barre système GTK4 StatusNotifierItem ; le chemin de code Windows reste inchangé. Tous les fichiers propres à Linux se trouvent dans `linux/` et `src/linux/`, et `build-linux.sh` la compile (Windows continue d'utiliser `build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Compilateur et make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

Aucune bibliothèque HID supplémentaire n'est nécessaire (hidraw est utilisé directement).

```sh
./build-linux.sh
./build-linux.sh test         # test unitaire de l'analyseur de descripteur de rapport HID
./wireless-battery --list     # affiche les niveaux détectés et quitte
./wireless-battery --dump     # liste les collections HID
./wireless-battery --quit     # ferme l'instance active dans la barre système
```

L'accès HID nécessite une règle udev, sinon l'application démarre mais ne trouve aucun appareil :

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# déconnectez-vous puis reconnectez-vous à votre session
```

L'icône fonctionne nativement sous KDE Plasma ; GNOME nécessite un hôte AppIndicator tel que `gnome-shell-extension-appindicator`. Le changement de langue fonctionne via le sous-menu *Langue* (suivant `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG` par défaut, et traduisant aussi `--help`). L'exécution de `make -f linux/Makefile.linux install` installe le binaire, `lang/*.json` dans `$(PREFIX)/share/wireless-battery/lang/`, ainsi que le lanceur de bureau (`linux/wireless-battery.desktop`) et `linux/wireless-battery.svg` dans `$(PREFIX)` (`~/.local` par défaut) ; les surcharges utilisateur se placent dans `~/.config/wireless-battery/lang/`.

La phase 1 couvre Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious, Finalmouse et les protocoles partagés Kysona/Pulsar/ATK/G-Wolves. Les replis Bluetooth/UPower, HeadsetControl et les autres fabricants sont prévus pour les phases suivantes.

## Limitations

- **Barres des tâches chargées :** sur une barre des tâches Windows 11 centrée et très remplie, les boutons d'applications peuvent atteindre le widget. Sous Windows 10, la zone des boutons est automatiquement rétrécie.
- **Téléphones :** lu depuis un fichier que Mobile connecté écrit pour la carte associée du menu Démarrer, qui n'est pas une API documentée et peut changer lors des mises à jour de Mobile connecté. Le téléphone s'affiche tant que Mobile connecté le signale comme connecté ; une carte datant de plus de 3 heures s'affiche estompée. La carte indique également lorsque le téléphone charge, ce qui s'affiche avec l'éclair de charge.
- **Appareils en veille :** un appareil en veille peut ne pas répondre. Sa dernière valeur reste visible, estompée. Les récepteurs Logitech retirent les appareils en veille de la liaison, leur dernière valeur est donc conservée pendant 30 minutes.
- **Casque HECATE G2 Wireless 7.1** (dongle 2,4 GHz `35BB:A009` / `A209`) : aucune requête de batterie pour son dongle n'est encore documentée, il n'est donc pas lu. Une capture USB pendant que le logiciel HECATE affiche la batterie du casque (voir CONTRIBUTING.md) permettra de l'ajouter.
- **Claviers Keychron :** avec le firmware d'origine, ils ne signalent leur batterie qu'en Bluetooth (affichée via la prise en charge Bluetooth). Sur le récepteur 2,4 GHz ou par câble, ils nécessitent un firmware intégrant le correctif de batterie ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)) ; une mise à jour du clavier depuis Keychron Launcher supprime ce correctif. Les souris Keychron sont prises en charge.
- **Casque Baseus AeQur GH02 :** le dongle 2,4 GHz (`10D6:4802`, puce Actions) ne transporte que l'audio, les touches multimédias et le canal de mise à jour de firmware de la puce, pas la batterie. Connectez le casque en Bluetooth pour voir son niveau (affiché via la prise en charge Bluetooth lorsque Windows en signale un).
- **Clavier Weikav Lucky65 v1 :** le firmware ne signale pas sa batterie sur le dongle 2,4 GHz (`0603:0351`, puce Novatek). Le clavier n'a aucun raccourci de vérification de batterie, et le configurateur officiel ne se connecte qu'en câble USB, pas via le dongle ; il n'y a donc aucun relevé de batterie à afficher.
- **Rapoo :** les souris VT prises en charge poussent leur état, une actualisation peut donc attendre jusqu'à 4 secondes par interface correspondante. Les souris en veille peuvent rester estompées avec leur dernier relevé jusqu'à 30 minutes. La prise en charge concerne le rapport `07` Nordic 54L et l'ancien `BB` (VT3 Pro, VT1 Pro Max) ; le rapport `08` CH584, les souris bureautiques des séries MT/M et les autres protocoles de firmware ne sont pas couverts par ce pilote.
- **GameSir Cyclone Pro :** le dongle ne transporte aucun niveau de batterie, il est donc lu depuis la manette en Bluetooth LE. Appairez la manette avec Windows une fois (Paramètres > Bluetooth et appareils > Ajouter un appareil > Bluetooth > `GameSir-Cyclone Pro`), puis continuez de jouer via le dongle. Le PC doit disposer du Bluetooth. Le niveau est actualisé toutes les 2 minutes, et il n'y a aucun pourcentage pendant la charge. Sans appairage, le dongle apparaît comme une manette Xbox à « Pleine ». Détails dans [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM :** la souris est interrogée via son récepteur, donc une souris en veille ne répond pas ; elle reste estompée avec son dernier relevé jusqu'à 30 minutes et ajoute environ une seconde à une actualisation lorsqu'elle dort. Seule la Leviathan V4 sur le récepteur RAWM HS (`1915:2346`) est testée ; les autres modèles proviennent de la table d'appareils de RAWM HUB. Les Leviathan V4 GT et NYX60 (VID `373E`, RAWM HUB 3.0) ainsi que les claviers RAWM HS utilisent d'autres protocoles et ne sont pas couverts.
- **Flydigi :** ce pilote cible les Vader 5 Pro et Apex 5 ; le Bluetooth et les autres modèles Flydigi (par exemple Apex 6) ne sont pas couverts. Les pourcentages représentent des paliers de batterie grossiers. L'Apex 5 a été testée sur du matériel réel via le récepteur 2,4 GHz et un câble USB ; la Vader 5 Pro suit SDL et des traces matérielles Windows.
- **Pas encore pris en charge :** les souris sans fil MSI autres que la VERSA 300 ELITE et les CLUTCH GM31 / GM41, les claviers sans fil MSI, les casques Razer Kraken et les modèles Barracuda autres que le Barracuda X (2022) sur `1532:0550`, les souris HyperX Pulsefire autres que la Haste 2 Wireless / Haste 2 Core Wireless et le Xbox Wireless Headset sur l'adaptateur Xbox : leurs protocoles de batterie ne sont pas documentés. Le Xbox Wireless Headset fonctionne en Bluetooth. Une capture USB provenant d'un propriétaire (voir CONTRIBUTING.md) permettra de les ajouter.
- **Autres appareils :** certains appareils 2,4 GHz utilisent des protocoles non documentés et ne sont pas encore pris en charge. Consultez [CONTRIBUTING.md](#sec-contributing) pour savoir comment aider à en ajouter un.

## Fonctionnement

Chaque pilote constructeur dans [`src/drivers/`](../../src/drivers) reconnaît ses appareils par Vendor ID et Product ID USB, et n'envoie jamais que des requêtes de batterie en lecture seule. Aucun appareil inconnu ne reçoit d'écriture. Les replis génériques (usage HID batterie, Bluetooth, XInput, HeadsetControl) n'examinent que les appareils qu'aucun pilote constructeur n'a revendiqués.

Le widget de barre des tâches est une fenêtre enfant en couches (layered) de `Shell_TrayWnd`, placée à gauche de `TrayNotifyWnd`. Si Explorer redémarre, il est recréé.

## Traductions

Chaque langue d'interface est un simple fichier texte UTF-8 statique dans [`lang/`](../../lang) : l'anglais à gauche, la traduction à droite. Les fichiers de langue sont chargés depuis le disque à l'exécution plutôt que compilés dans l'exécutable, vous pouvez donc les modifier directement sans recompiler.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **Interface de l'application (Windows et Linux) :**
  - Modifiez ou ajoutez des fichiers `.json` directement dans le dossier `lang/` à côté de `BatteryHub.exe` (ou `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/`, ou `./lang/` sous Linux).
  - Ou choisissez *Langue → Ajouter votre propre langue...* dans le menu pour préparer votre dossier de surcharge utilisateur (`%APPDATA%\WirelessBattery\lang` sous Windows, `~/.config/wireless-battery/lang` sous Linux) avec `_template.json`. Copiez `_template.json` vers par exemple `it.json`, remplissez `@code`, `@name` et les traductions, et la langue apparaît dans le menu (sans redémarrage requis). Les fichiers du dossier utilisateur remplacent les phrases intégrées ayant le même `@code`.
  - Conservez les `{placeholders}` tels quels, et ajoutez `"@rtl": true` pour les écritures de droite à gauche. Les phrases laissées vides restent en anglais, une traduction partielle convient donc tout à fait.
  - La sortie de `--list` et `--dump` reste volontairement en anglais : elle sert à être collée dans les issues GitHub.
- **Installateur Windows :** les traductions Inno Setup résident dans [`installer/lang/`](../../installer/lang) (enregistrées en UTF-8 avec BOM) et sont déclarées sous `[Languages]` dans `installer/BatteryHub.iss`.
- **Documentation :** chaque document visible du projet est traduit dans un unique fichier Markdown autonome par langue dans [`docs/i18n/`](README.md) (voir [`docs/i18n/_template.md`](_template.md) pour ajouter une nouvelle langue sans aucun script de génération).
- **Partagez-la avec tout le monde :** envoyez une pull request ajoutant vos fichiers dans `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` et `docs/i18n/`. Consultez [`docs/i18n/README.md`](README.md) pour la liste de contrôle étape par étape.

## Crédits

Icône de l'application par [nik-txt](https://github.com/nik-txt) ([`res/app.svg`](../../res/app.svg)).

Les protocoles proviennent des recherches de ces projets :

- [Spécification Google Fast Pair](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification) : diffusions de batterie gauche / droit / boîtier des écouteurs Fast Pair
- [Pilotes Astro de HeadsetControl](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) et [AstroBar](https://github.com/nichtlegacy/AstroBar) : protocoles de batterie Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20 ; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC) : lecture d'état `0x72` de l'A50 Gen 3

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz) : commandes de batterie et de charge VAXEE ([documentation du protocole](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl) : casques SteelSeries, Corsair, HyperX, Logitech et Sony INZONE
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) et [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66) : Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer) : Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) et les documents Logitech HID++ 2.0 : Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) et [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery) : Logitech G435 (dongle `0ADF`)
- [rivalcfg](https://github.com/flozz/rivalcfg) : souris SteelSeries (Rival Pro issu de sa pull request #294)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) et [glorious-ctl](https://github.com/louis4craft/glorious-ctl) : Glorious
- Configurateur web de Hitscan ([control.hitscan.com](https://control.hitscan.com)) : Hitscan
- `hid-kysona` Linux (Lode Willems) : Kysona, Pulsar et ATK
- Configurateur web d'ATK ([hub.atk.pro](https://hub.atk.pro)) : souris ATK et casques N9 Pro / N9 Ultra
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery) : Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 et [mouse-battery](https://github.com/qwr79/mouse-battery) : dongle ATK / VXE NK NANO
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT) : Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X et Endgame Gear XM2we, portés depuis ses fournisseurs (chaque pilote cite sa source)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` et [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT) : Turtle Beach Stealth 700 Gen 3 ; [Neap](https://github.com/lykosapps/Neap) (résultats uniquement) : famille d'appareils Turtle Beach Swarm II
- Pilote web de G-Wolves ([mouse.xyz](https://mouse.xyz)) : modèles G-Wolves et leurs protocoles
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch) : claviers CHERRY sur dongle 2,4 GHz (format de trame et requête de batterie)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)) : souris Keychron
- [NinjaForce](https://www.ninjaforce.co/) et [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray) : requêtes de fonctionnalités Ninjutso Ten / Ten Air
- [nape_pro](https://github.com/nvalis/nape_pro) et [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget) : Keychron Nape Pro sur le récepteur Link-KM
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)) : souris LAMZU
- [vole](https://github.com/johanneszab/vole) et [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator) : souris Endgame Gear 4K
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) et [HaloBattery](https://github.com/Waturus/HaloBattery) : WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) et [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher) : Finalmouse UltralightX / Starlight X (issu du xpanel de Finalmouse)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) et [g49-web-control](https://github.com/pingpingjinping/g49-web-control) : identifiants Redragon
- [m913-ctl](https://github.com/Qehbr/m913-ctl) et [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray) : format de trame Areson `25A7` et commande `GetPower`
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper) : ASUS ROG ; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch) : ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) et [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray) : ZOWIE EC-CW et DW
- Pilote web de RK ([drive.rkgaming.com](https://drive.rkgaming.com)) : Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor) : MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) et [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (docs) : MCHOSE A5 Pro / A5 Pro Max (première génération, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux) : Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery) : rapports de récepteur CompX pour Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) et [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2) : Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) et [MouseBattery](https://github.com/FelixNg21/MouseBattery) : Incott
- Le pilote web de Wraith ([w1.software](https://www.w1.software/)) : Wraith W1
- OpenRazer PR #2794 et [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3) : BlackShark V3
- OpenRazer PR #2862 et [HaloBattery](https://github.com/HeyOkay/HaloBattery) : BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) et [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery) : Razer Barracuda X (2022) sur le récepteur `1532:0550` ; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray) : tramage du récepteur `1532:0552`
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899) : BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM) : HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset) : HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor) : HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray) : récepteurs Rongyuan et Xenta (Attack Shark et autres)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio) : claviers SONiX sur leur dongle 2,4G (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro) ; [ak820-rs](https://github.com/deddroid/ak820-rs) et [ak820-studio](https://github.com/usharik/ak820-studio) : récepteur AJAZZ AK820 Pro `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) et [Kraber](https://github.com/AkashPanja/Kraber) : protocole d'état Semico `1A2C` (`AA 55 CC 33` / `0x0E`) pour Attack Shark X98 et AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) et [MM731-Controller](https://github.com/riVFerd/MM731-Controller) : Cooler Master MM712 et MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) et [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection) : GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery) : requête de batterie « base info » Bluetooth LE du GameSir Cyclone Pro
- [jabridge](https://github.com/Watchdog0x/jabridge) : protocole Jabra GNP (dongles Link 380 / 390)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web) : Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery) : protocole de page d'état `1EA7:0066` (Fantech Raigor III et autres appareils génériques 2.4G Mouse)
- `hid-playstation` Linux : disposition des rapports DualShock 4 / DualSense
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580) : protocole constructeur AULA SC580 / SC580X
- Application web RAWM HUB ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) et sa table d'appareils : souris RAWM et SADES Dagger
- [Pilote HID Flydigi de SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) et [issue HaloBattery #191](https://github.com/HeyOkay/HaloBattery/issues/191) : tramage des requêtes et disposition de batterie des Vader 5 Pro et Apex 5
- [Pilote HID 8BitDo de SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) : octet de batterie du 8BitDo Ultimate 2
- BEITONG iControl (ses pages KP20 et KP40D et le trafic USB du récepteur KP20) : requête de batterie et brouillage de la charge utile BEITONG KP20 / KP40D
- [Pilote HID 8BitDo de SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) et [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux) : octet de batterie 8BitDo et protocole HID constructeur
- JBL QuantumENGINE (ses messages d'infos d'appareil HIDV3) : casques JBL Quantum
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md) : Corsair Sabre V2 Pro Ultralight, protocole Compx sur `FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) et [BrimDeck](https://github.com/MoFeng2223/BrimDeck) : lecture de profil Scyrox V12M
- JBL QuantumENGINE : rapports de connexion et de batterie HIDV1 pour le Quantum 350, et messages d'infos d'appareil HIDV3 pour les casques Quantum plus récents
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md) : rapports de batterie et de liaison HIDV1 du JBL Quantum 610, et gamme Quantum (360 comme modèle de dongle HIDV1)

## Licence

[Licence publique générale GNU v3.0 ou ultérieure](../../LICENSE). Vous pouvez utiliser, modifier et redistribuer ce logiciel, mais tout ce que vous distribuez qui en dérive doit être publié sous la même licence, avec son code source.


---

<a id="sec-contributing"></a>
> 📄 **Section :** Contribuer (`CONTRIBUTING.md`) · [Original en anglais](../../CONTRIBUTING.md) · [↑ Haut](#top)

# Contribuer

## Signaler si un appareil fonctionne

La plupart des pilotes ont été écrits à partir de la documentation des protocoles et n'ont pas pu être testés sur chaque modèle. Veuillez ouvrir une issue en indiquant :

- le nom de l'appareil, et s'il est connecté par récepteur, câble ou Bluetooth
- la sortie de `BatteryHub.exe --list`
- la sortie de `BatteryHub.exe --dump`
- le niveau de batterie affiché par le logiciel du fabricant

## Ajouter un appareil

1. Exécutez `BatteryHub.exe --dump` et repérez les identifiants fabricant (Vendor ID) et produit (Product ID) de votre appareil, ainsi que les collections propres au fabricant (page d'usage `FFxx`) avec leurs tailles de rapport.
2. Trouvez le protocole de batterie. Bonnes pistes : HeadsetControl, OpenRazer, Solaar, rivalcfg, OpenRGB, OpenLinkHub ou une capture USB du logiciel fabricant (Wireshark + USBPcap).
3. Si le fabricant possède déjà un pilote dans `src/drivers/`, ajoutez-y le Product ID (et toute différence éventuelle). Sinon, créez `src/drivers/<vendor>.cpp` :

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

4. Déclarez la fonction dans `src/drivers/drivers.h`, appelez-la depuis `PollAllDevices()` dans `src/devices.cpp` (avant les replis génériques). `build.bat` et le `Makefile` détectent automatiquement les nouveaux fichiers.
5. Mettez à jour le tableau des appareils dans `README.md`.

### Règles pour les pilotes

- **Lecture seule :** n'envoyez que des requêtes qui lisent l'état. Ne modifiez jamais de paramètres, d'éclairage ni de modes.
- **Correspondance exacte :** ne communiquez qu'avec les appareils identifiés par Vendor ID et Product ID, ou par une collection propre au fabricant qui soit unique au protocole.
- **Toujours avec délai maximal (timeout) :** un appareil absent ne doit pas bloquer l'interrogation plus d'environ une seconde. Les protocoles passifs peuvent nécessiter plus de temps pour couvrir un intervalle d'envoi documenté (par exemple, Delux et Rapoo). Conservez une échéance absolue unique d'au plus 4 secondes par collection correspondante, ne la réinitialisez pas sur des rapports sans lien, et documentez pourquoi cette exception est nécessaire.
- **Citer les sources :** indiquez d'où provient le protocole dans un commentaire en haut du fichier.

## Traductions

Les langues de l'interface sont de simples fichiers texte UTF-8 statiques dans `lang/`, chargés depuis le disque à l'exécution sous Windows comme sous Linux (copiez `lang/_template.json` vers `lang/<code>.json`, renseignez `@code`, `@name` et les phrases — aucune recompilation nécessaire). Tout nouveau texte d'interface dans le code passe par `T(L"...")`, ou `TF(L"... {name} ...", { { L"name", value } })` lorsqu'il contient des valeurs ; ne construisez jamais de phrases traduites par assemblage de morceaux. Après avoir ajouté des phrases, ajoutez-les également dans `lang/_template.json`.

Les traductions de l'installateur Windows résident dans `installer/lang/*.isl` (enregistrées en UTF-8 avec BOM et déclarées dans `installer/BatteryHub.iss`), les commentaires du lanceur Linux dans `linux/wireless-battery.desktop`, et les traductions complètes de la documentation dans `docs/i18n/<code>.md` (un seul fichier autonome copié depuis `docs/i18n/_template.md`). Consultez [`docs/i18n/README.md`](README.md) pour le guide complet des contributeurs.

## Style de code

C++17, Win32 uniquement, aucune dépendance tierce. Gardez le binaire léger. Formatez grosso modo comme le code existant (indentation de 4 espaces, lignes de 120 colonnes).

## Développement du module de mise à jour Windows

Le module de mise à jour est réservé à Windows et utilise WinHTTP, BCrypt et l'installateur Inno Setup existant. Conservez l'état de mise à jour exclusivement dans le menu. N'ajoutez pas d'icônes de mise à jour, de badges, de modifications aux info-bulles de batterie, d'info-bulles ballon, de notifications toast ni de boîtes de dialogue automatiques. L'interrogation des appareils s'exécute séparément du travail réseau.

La version et le canal de compilation sont partagés entre le C++ et les ressources Windows via le fichier généré `build/version.h`. Utilisez `make VERSION=1.2.3 CHANNEL=test` ou `build.bat 1.2.3 test` pour les tests locaux ; `dev` est la valeur par défaut et `stable` active les vérifications officielles de versions. Les composantes de version doivent tenir dans 0..65535. Seul le workflow de tag de version du dépôt officiel sélectionne `stable` automatiquement. Ne transformez pas accidentellement une compilation de fork en canal de mise à jour officiel.

Exécutez `make test VERSION=1.2.3 CHANNEL=test` pour lancer les tests existants des appareils ainsi que l'analyse stricte des versions, le classement des versions, la planification des vérifications, les vrais contrôles SHA-256 de fichiers, l'échappement des arguments et les garde-fous de l'assistant. Les tests de non-régression couvrent aussi l'annulation à la fin du téléchargement, les protections de boîtes de dialogue et l'échec de configuration des délais HTTP/restrictions de redirection. Le test Windows inclut les implémentations, suivant le modèle des tests Linux existants, et remplace l'envoi HTTP afin que ces tests ne puissent pas contacter GitHub. Aucun point d'entrée de contrôleur réservé aux tests n'est ajouté en production. Les cibles individuelles sont `make test-update-core` et `make test-update-win`. Les tests natifs du module de mise à jour lient la ressource de l'application pour activer Common Controls v6. Les tests utilisent des données locales et ne téléchargent pas, n'élèvent pas les privilèges, n'installent rien et ne modifient pas les réglages de démarrage de l'utilisateur. Le point de terminaison de production de l'application ne peut pas être remplacé pour les tests.

Avant d'empaqueter, exécutez `powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`. `installer/build-installer.ps1 -Version 1.2.3` exécute également cette vérification avant de télécharger les dépendances. Le chemin d'installation `/WBUPDATE=1` conserve les paramètres et le démarrage existants et laisse la relance à l'assistant temporaire. Cet assistant reste sous l'utilisateur d'origine, n'élevant les privilèges que pour une installation globale. Les handles WinHTTP appartiennent au thread de travail ; l'annulation est coopérative entre des appels à délai fini. L'arrêt final de l'application attend la fin de ce thread de travail et peut donc attendre l'expiration d'un délai réseau en cours.

Pour une revue de version, utilisez un compte Windows jetable ou une machine virtuelle afin de tester deux vraies versions d'installateur, la portée par utilisateur/globale, l'annulation UAC, le démarrage activé/désactivé, des chemins personnalisés, l'échec d'installation et la relance. Les tests unitaires et la compilation d'un paquet ne vérifient pas ces effets de l'installateur. La vérification visuelle du menu et des thèmes ainsi que les tests réels de bout en bout de l'installateur et de l'UAC restent des critères manuels de validation de version ; ne les marquez pas comme réussis sans les avoir réellement observés. Ne testez jamais en écrasant l'installation de votre compte quotidien.

## Vérification automatique de sécurité

Chaque pull request est analysée par le « PR safety check » afin de détecter ce que cette application ne doit jamais faire (accès réseau, lancement de programmes, lecture du clavier/presse-papiers/écran, entrées de démarrage, binaires, modifications de compilation ou de publication). Un signalement n'est pas un rejet : expliquez simplement les lignes signalées dans la description de la PR.

L'utilisation d'outils d'IA est acceptée, mais veuillez retirer les lignes `Co-authored-by` qui les créditent (par exemple `Co-authored-by: Claude ...`) de vos messages de commit. La vérification échoue tant qu'elles sont présentes.


---

<a id="sec-pr-template"></a>
> 📄 **Section :** Modèle de Pull Request (`.github/pull_request_template.md`) · [Original en anglais](../../.github/pull_request_template.md) · [↑ Haut](#top)

## Ce que cela ajoute

<!-- Appareil(s) et identifiants fabricant/produit, ex. "Acme M1 (1234:5678)". -->

## D'où provient le protocole

<!-- Indiquez le lien de la source (un autre projet, un pilote web du fabricant, votre propre capture USB). -->

## Testé sur du matériel réel ?

<!-- Oui (quel appareil, ce que --list a affiché) / Non -->

## Liste de contrôle

- [ ] Seules des requêtes de batterie en lecture seule sont envoyées ; aucun paramètre, éclairage ou firmware n'est modifié
- [ ] Seuls les appareils reconnus par identifiant fabricant/produit (ou par une collection propre au protocole) sont sollicités
- [ ] Aucun accès réseau, aucun lancement d'autres programmes, aucun nouveau fichier hors de `src/`, `docs/` ou `README.md`
- [ ] Aucun binaire ni fichier généré n'est inclus
- [ ] Aucune ligne `Co-authored-by` créditant des outils d'IA (Claude, Copilot, ChatGPT ...) dans les messages de commit
- [ ] Les modifications apportées à `.github/`, `installer/`, `build.bat` ou `Makefile` sont expliquées ci-dessus


---

<a id="sec-releasing"></a>
> 📄 **Section :** Publication (`docs/releasing.md`) · [Original en anglais](../../docs/releasing.md) · [↑ Haut](#top)

# Publication et signature

L'application se met à jour depuis les versions GitHub, mais elle n'installe qu'un programme d'installation dont le SHA-256 figure dans un fichier `SHA256SUMS.txt` signé avec la clé de publication. Cette clé réside sur le PC du mainteneur, jamais sur GitHub : un compte, un jeton ou un workflow compromis peut publier des fichiers, mais pas une signature acceptée par l'application.

## Une seule fois : créer la clé de publication

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Demande un mot de passe (12+ caractères) et écrit la clé privée chiffrée dans `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- Place la clé publique dans `src\update_public_key.h`. Commitez ce fichier. Les compilations officielles refusent de compiler sans clé à l'intérieur.
- **Sauvegardez le fichier de clé et conservez le mot de passe** (un gestionnaire de mots de passe est idéal pour les deux). Si l'un des deux est perdu, les applications installées ne pourront plus se mettre à jour automatiquement : vous devriez créer une nouvelle clé et chaque utilisateur devrait installer une version manuellement.

## À chaque version

1. Poussez un tag de version (`git tag v1.2.3 && git push origin v1.2.3`). La CI compile l'installateur, l'archive ZIP portable et `SHA256SUMS.txt`, puis publie la version.
2. Signez la liste des sommes de contrôle :

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Le script télécharge `SHA256SUMS.txt` depuis la version publiée, l'affiche, demande votre confirmation, demande le mot de passe de la clé et écrit `SHA256SUMS.txt.sig`. Si vous avez les mêmes fichiers dans `dist\` (une compilation locale de cette version), il indique s'ils correspondent.
3. Téléversez `SHA256SUMS.txt.sig` sur la version publiée (le script ouvre la page d'édition). À partir de là, l'application propose **Télécharger et installer**. Avant cela, elle affiche la mise à jour mais ne propose qu'un lien vers la page de la version.

Ne signez une liste que pour une version que vous avez publiée vous-même. La signature affirme « ces fichiers exacts constituent la version » ; la signature est donc l'étape où un téléversement malveillant serait intercepté.

## Changer de clé

Exécutez `new-release-key.ps1` avec un nouveau `-KeyFile` : cela ajoute la nouvelle clé publique à côté de l'ancienne dans `src\update_public_key.h`. Publiez une version signée avec l'ancienne clé qui contient les deux, puis signez avec la nouvelle clé à partir de la version suivante et retirez l'ancienne clé plus tard. Une clé perdue ou divulguée ne peut pas être révoquée de cette manière : retirez-la du fichier d'en-tête, et les utilisateurs des anciennes versions devront installer la version suivante manuellement.

## Ce que l'application vérifie avant d'exécuter un installateur

- La version est la plus récente du dépôt, n'est ni un brouillon ni une préversion, et est plus récente que l'application.
- `SHA256SUMS.txt.sig` est une signature ECDSA P-256 valide de `SHA256SUMS.txt` par une clé figurant dans `src\update_public_key.h` (Windows BCrypt, aucun code tiers).
- La liste signée nomme `BatteryHub-Setup-<version>.exe` exactement une fois, avec le même SHA-256 que celui indiqué par GitHub pour le fichier.
- L'installateur téléchargé a exactement cette taille et ce SHA-256. Une copie de l'application le revérifie juste avant de le lancer, et maintient le fichier verrouillé afin qu'il ne puisse pas être échangé entre-temps.
- Les téléchargements n'utilisent que HTTPS vers `github.com`, `objects.githubusercontent.com` et `release-assets.githubusercontent.com`, avec vérification de chaque redirection.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Section :** Firmware de clavier Keychron (`docs/keychron_keyboard_firmware/README.md`) · [Original en anglais](../../docs/keychron_keyboard_firmware/README.md) · [↑ Haut](#top)

# Batterie des claviers Keychron sur le récepteur 2,4 GHz

Le firmware d'origine de Keychron ne signale la batterie du clavier qu'en Bluetooth. Avec la petite modification QMK dans [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch), le clavier répond également à une requête de batterie (`A4`) via le récepteur Keychron Link et par le câble USB, et BatteryHub affiche son niveau, sa tension et son état de charge.

Testé sur le **Keychron K5 Max ANSI RGB** (`3434:0A50`) avec le récepteur Keychron Link (`3434:D030`).

## Ce que modifie le correctif

Basé sur [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) branche `2025q3` (commit `57e682c`) :

- ajoute la commande HID brute `KC_GET_BATTERY` (`0xA4`) issue de [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1) : réponse `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]` ;
- transmet les requêtes HID brutes arrivant par la liaison sans fil au même gestionnaire ;
- dans `keyboards/keychron/k5_max/config.h` : `#define WILRESS_RAW_ENABLE` (orthographié ainsi dans le code de Keychron) et `#define KC_BATTERY_MODEL_ID 0`.

Rien d'autre ne change : les dispositions de touches, l'éclairage et Keychron Launcher continuent de fonctionner.

## Option 1 : flasher le firmware prêt à l'emploi du K5 Max

Une compilation pour le **K5 Max ANSI RGB uniquement** est jointe à [cette version](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1) (`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`). Ne le flashez pas sur un autre modèle ou une autre disposition.

## Option 2 : le compiler vous-même

Nécessite Git et Docker (ou un [environnement QMK](https://docs.qmk.fm/newbs_getting_started) fonctionnel).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

Le résultat est `keychron_k5_max_ansi_rgb_keychron.bin` à la racine du dépôt. Sous Windows, un dépôt monté en bind-mount est très lent dans Docker ; cloner directement dans le conteneur (ou sous WSL) est beaucoup plus rapide.

**Autres claviers sans fil Keychron** (Q/V/K Max et autres modèles de l'arbre `2025q3` avec `LK_WIRELESS_ENABLE`) : les modifications sous `keyboards/keychron/common/` s'appliquent telles quelles. Ajoutez les deux lignes `#define` au `config.h` de votre clavier au lieu de celui du K5 Max, et compilez votre propre cible, par ex. `make keychron/<model>/<layout>/<variant>:keychron`. L'application nomme actuellement un K5 Max (`0A50`–`0A58`) par son modèle et tout autre modèle « Keychron keyboard ».

## Flashage

1. Réglez le sélecteur de mode sur **Cable** et débranchez le câble USB.
2. Maintenez **Esc** enfoncé tout en rebranchant le câble. Le clavier passe en mode bootloader STM32.
3. Flashez le `.bin` avec [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (ou `dfu-util`).
4. Repassez sur **2.4 GHz** et vérifiez avec `BatteryHub.exe --list` : `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Mettre à jour le clavier depuis Keychron Launcher remplace ce firmware et supprime le rapport de batterie. Pour revenir en arrière, flashez le firmware officiel de Keychron de la même manière.

## Licence

QMK est sous licence GPL-2.0-or-later ; le correctif est sous la même licence. Quiconque reçoit un binaire compilé à partir de celui-ci doit également pouvoir obtenir cette modification des sources.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Section :** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [Original en anglais](../../docs/gamesir_cyclone_pro.md) · [↑ Haut](#top)

# Prise en charge de la batterie du GameSir Cyclone Pro

## Pourquoi la manette apparaissait comme une manette Xbox complète

La Cyclone Pro (modèle T4cp) fonctionne via un dongle 2,4 GHz, `3537:1015`. Le dongle se présente à Windows comme une manette Xbox 360 filaire (XUSB, `Xbox 360 Controller for Windows`). XInput répond à sa requête de batterie par « Full », de sorte que le repli XInput l'affichait comme `Xbox controller 1` à 100 % quel que soit le niveau réel de charge.

Le dongle ne transporte aucune information de batterie :
- sa seule collection HID est le contrôleur de jeu XInput (`HID\VID_3537&PID_1015&IG_00`)
- il n'a aucune collection propre au fabricant comme la Nova (`FF7A`) ou la Cyclone 2 (`FFF0`)

## Où se trouve le niveau

Tout en fonctionnant via le dongle, la manette émet également en Bluetooth LE sous le nom `GameSir-Cyclone Pro`, qui est le lien utilisé par l'application mobile de GameSir. Sa requête « get base info » renvoie la batterie :

| Étape | Détail |
|---|---|
| Service | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Caractéristique | `0x865F` (notification, écriture sans réponse) |
| Requête | activer les notifications, écrire `01 01` |
| Réponse | notification de 19 octets (certains firmwares ajoutent le préfixe `C9`, 20 octets) |

Structure de la réponse :

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

L'octet 18 est la batterie en pourcentage (0-100), ou `FF` pendant la charge. Aucun niveau n'est signalé pendant la charge ; le dernier pourcentage connu est donc conservé et affiché avec l'éclair de charge.

La manette dispose aussi du service `0xFF10`, qui est le canal de mise à jour du firmware de GameSir. Le pilote ne l'ouvre jamais. La manette n'a pas de Battery Service standard (`0x180F`), ce qui explique pourquoi la page Bluetooth de Windows et le repli Bluetooth n'affichent aucun niveau pour elle.

Source : [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), où le protocole a été déduit de l'application Android de GameSir (`BluetoothLeService`, « get base info »).

## Fonctionnement du pilote

`src/drivers/gamesir_ble.cpp`, appelé avant le repli XInput :

1. **Trouver la manette.** Il recherche les interfaces de périphérique de classe `{00008650-0000-1000-8000-00805F9B34FB}`. Windows en crée une pour chaque service GATT d'un périphérique BLE appairé. Il n'utilise que celles dont le nœud parent `BTHLE\DEV_…` se nomme `GameSir-Cyclone…`.
2. **Lire la batterie.** Il ouvre ce service avec l'API GATT Win32 (`bluetoothleapis.h`, `-lbluetoothapis`), s'abonne à `0x865F` et écrit `01 01`. Il attend jusqu'à 3 secondes la réponse, puis désactive les notifications.
3. **Garder l'interrogation rapide.** La connexion BLE peut prendre plusieurs secondes, ou expirer lorsque la manette est en veille ; la requête s'exécute donc dans son propre thread :
   - au maximum toutes les 2 minutes après une lecture réussie, ou toutes les minutes après un échec
   - l'interrogation signale la mesure en cache, et cesse de la signaler une fois âgée de 6 minutes
   - `graceSec` la maintient ensuite visible, estompée, comme en veille
   - seule la première interrogation d'une session attend le thread, une seule fois, avec une échéance absolue de 4 secondes, afin que le niveau s'affiche au démarrage et dans `--list`
4. **Masquer la fausse entrée Xbox.** Lorsque le dongle est présent, le pilote revendique `3537:1015` :
   - le chemin `Windows.Gaming.Input` ignore désormais les identifiants fabricant/produit revendiqués
   - le chemin XInput récupère les identifiants fabricant/produit de chaque emplacement via `XInputGetCapabilitiesEx` (ordinal 108 de `xinput1_4`) et ignore ceux qui sont revendiqués
   - lorsque cet export est absent, XInput se comporte comme avant

## Matériel testé

Windows 11, Cyclone Pro sur son dongle (`3537:1015`), appairée une fois en Bluetooth, le 2026-11-18 :

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Lorsque la manette était en veille, l'entrée « Xbox controller 1 / Full » n'apparaissait plus et rien n'était affiché pour la manette.

## Limitations

- **Appairage :** la manette doit être appairée une fois avec Windows (Paramètres > Bluetooth et appareils > Ajouter un appareil > Bluetooth > `GameSir-Cyclone Pro`). Les manettes non appairées n'ont pas d'interface de périphérique GATT. L'appairage ajoute des entrées de manette Bluetooth, mais celles-ci n'envoient aucune entrée tant que la manette fonctionne via le dongle.
- **Bluetooth requis :** le PC doit disposer du Bluetooth LE.
- **Une seule manette :** une seule Cyclone Pro par PC est lue.
- **Charge :** aucun pourcentage n'est disponible pendant la charge.


---

<a id="sec-localization-guide"></a>
> 📄 **Section :** Guide multilingue et de localisation (`docs/i18n/README.md`) · [Original en anglais](../../docs/i18n/README.md) · [↑ Haut](#top)

# Index multilingue et guide de localisation de BatteryHub

Chaque document visible de ce dépôt est regroupé dans **un seul fichier Markdown autonome par langue** dans `docs/i18n/`, tandis que toutes les chaînes d'exécution de l'application résident dans des **fichiers texte statiques modifiables** dans [`lang/`](../../lang) (partagés entre Windows et Linux) et les chaînes de l'installateur Windows dans [`installer/lang/`](../../installer/lang).

## Langues prises en charge (19)

| Code | Langue | Documentation complète | Interface de l'application (Windows et Linux) | Installateur Windows |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (chaînes sources) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Fonctionnement du changement de langue en pratique

### 1. Application Windows (`BatteryHub.exe`)
- **Détection automatique :** lorsqu'il est réglé sur *Langue → Automatique (langue de Windows)*, BatteryHub interroge Windows `GetUserPreferredUILanguages` et sélectionne le fichier statique `*.json` le plus proche.
- **Changement manuel :** cliquez sur le widget de la barre des tâches ou l'icône de notification → **Langue** → choisissez une langue. L'interface se met à jour immédiatement et le choix est enregistré dans `HKCU\Software\WirelessBattery\Language`.
- **Fichiers externes statiques (modifiables sans recompiler) :** `BatteryHub.exe` charge d'abord `<exe>\lang\*.json`, puis `%APPDATA%\WirelessBattery\lang\*.json`. Tout fichier du dossier utilisateur ayant le même `@code` remplace les phrases correspondantes, et la réouverture du menu recharge les fichiers depuis le disque en direct.
- **CLI `--help` :** `BatteryHub.exe --help` affiche la fenêtre d'aide dans votre langue d'interface active (`--list`, `--json` et `--dump` restent volontairement en anglais pour les signalements sur GitHub).

### 2. Application Linux (`wireless-battery`)
- **Détection automatique :** suit les variables de locale POSIX dans l'ordre : `LANGUAGE` (liste séparée par des deux-points) → `LC_ALL` → `LC_MESSAGES` → `LANG` (sauf surcharge par `LC_ALL=C` / `POSIX`).
- **Changement manuel :** faites un clic droit sur l'icône de barre système → **Langue** → choisissez **Automatique (langue du système)** ou toute langue installée. Enregistré sous `[general] language=` dans `$XDG_CONFIG_HOME/wireless-battery/config.ini` (par défaut `~/.config/wireless-battery/config.ini`).
- **Chemins de recherche statiques (de la priorité la plus faible à la plus élevée) :**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (par défaut `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (par défaut `~/.config/wireless-battery/lang/`)
- **CLI `--help` :** `wireless-battery --help` affiche l'aide en ligne de commande traduite selon `config.ini` ou la locale système ; `--list` et `--dump` restent en anglais.

### 3. Installateur Windows (`BatteryHub-Setup-<version>.exe`)
- Affiche un sélecteur de langue (`ShowLanguageDialog=yes`) présélectionné selon votre langue d'interface Windows (`LanguageDetectionMethod=uilanguage`).
- Installe le dossier statique complet `lang\*.json` dans `{app}\lang\` à côté de `BatteryHub.exe` (et l'archive ZIP portable embarque également `lang\*.json`).

---

## Comment ajouter ou mettre à jour une langue (étape par étape)

Vous n'avez besoin d'**aucun** outil de compilation pour traduire l'interface de l'application ou la documentation, et uniquement d'Inno Setup 6 si vous souhaitez tester la compilation de l'installateur Windows.

### Étape 1 — Chaînes de l'interface de l'application (`lang/<code>.json`)
1. Ouvrez le dossier de langues utilisateur depuis le menu (**Langue → Ajouter votre propre langue...**) ou copiez [`lang/_template.json`](../../lang/_template.json) vers `lang/<code>.json` (ex. `lang/it.json`).
2. Remplissez l'en-tête de métadonnées :
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Traduisez la partie droite après ` = ` sur chaque ligne.
   - Conservez intacts les paramètres tels que `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}`.
   - Utilisez `\n` pour les sauts de ligne explicites.
   - Enregistrez en **UTF-8 (sans BOM)**.
   - Rouvrez le menu de BatteryHub pour prévisualiser immédiatement — aucune recompilation requise !

### Étape 2 — Installateur Windows (`installer/lang/<code>.isl`)
1. Copiez [`installer/lang/_template.isl`](../../installer/lang/_template.isl) vers `installer/lang/<code>.isl`.
2. **CRITIQUE :** enregistrez le fichier en **UTF-8 avec BOM (`EF BB BF`)** afin qu'Inno Setup décode correctement les caractères Unicode quelles que soient les pages de codes Windows historiques.
3. Choisissez le modèle correspondant :
   - **Inno Setup fournit déjà votre langue** (vérifiez `C:\Program Files (x86)\Inno Setup 6\Languages\`) : ne conservez que `[CustomMessages]` et traduisez les 6 lignes (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, en conservant `%1` et `%n`). Déclarez-la dans `installer/BatteryHub.iss` sous `[Languages]` :
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Inno Setup ne fournit pas votre langue** : copiez `installer/lang/zh-CN.isl` comme référence complète, renseignez `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, et `RightToLeft=yes` si applicable), traduisez `[Messages]` et `[CustomMessages]`, puis déclarez-la après `Default.isl` :
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Remarque : les identifiants `Name:` sous `[Languages]` ne doivent contenir que des lettres ASCII, des chiffres et des underscores (utilisez `ptBR`, et non `pt-BR`).

### Étape 3 — Lanceur de bureau Linux (`linux/wireless-battery.desktop`)
Ajoutez une ligne localisée `Comment[<code>]=...` (utilisez des underscores pour les variantes régionales dans les fichiers `.desktop`, ex. `Comment[zh_CN]=...`).

### Étape 4 — Documentation complète en fichier unique (`docs/i18n/<code>.md`)
1. Copiez [`docs/i18n/_template.md`](_template.md) vers `docs/i18n/<code>.md` (aucun script de génération requis — uniquement ce fichier !).
2. Traduisez intégralement la table des matières et les 17 sections tout en conservant :
   - Toutes les ancres `<a id="sec-..."></a>` et `<a id="top"></a>` intactes
   - Tous les blocs de code, options CLI (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), `VID:PID` USB, pages d'usage HID, paquets hexadécimaux, clés de Registre, chemins de fichiers et URL tels quels
   - Les chemins relatifs d'images et de fichiers intacts (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE`, etc.)
3. Mettez à jour la barre supérieure `<!-- lang-switcher:start -->` dans `docs/i18n/<code>.md` (mettez votre propre langue en gras, liez toutes les autres), et ajoutez un lien vers votre langue dans les barres de `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` et des fichiers frères `docs/i18n/*.md`.
4. Pour les langues s'écrivant de droite à gauche (`ar`, `fa`, `he`), rédigez du Markdown standard sans envelopper tout le fichier dans `<div dir="rtl">` afin que les tableaux et blocs de code s'affichent proprement.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Section :** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [Original en anglais](../../docs/ardor_fury_v2.md) · [↑ Haut](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

Le récepteur 2,4 GHz expose la page d'usage HID `000A`, l'usage `0000`, et un rapport d'entrée de 5 octets. Il diffuse des données ; aucune commande HID n'est envoyée.

Rapports observés sur du matériel réel :

| Rapport | Batterie |
|---|---|
| `03 00 40 33 07` | 50 % |
| `03 00 40 73 08` | 75 % |

Le quartet de poids fort de l'octet 3 encode le palier (`1`, `3`, `7`, `F` pour 25, 50, 75 et 100 pour cent). Les rapports pour 25 % et 100 % sont déduits de la logique de décodage de l'application du fabricant ; l'utilisateur final a confirmé par la suite que les autres niveaux s'affichent correctement dans l'application compilée. Le cinquième octet n'est pas constant et n'est pas utilisé comme signature.

L'écouteur exige deux paliers de batterie décodés concordants, plutôt que deux rapports complets identiques. La dernière valeur confirmée est conservée jusqu'à 45 secondes. L'intervalle global d'actualisation automatique passe à 15 secondes.

Validé par l'utilisateur final sous Windows avec une ARDOR Fury V2 et un Logitech G733 : captures à 50 % et 75 %, mise à jour automatique périodique, vérifications visuelles à 25 %/100 % et démarrage en version portable. Les rapports pour 25 % et 100 % n'ont pas été capturés.


---

<a id="sec-areson"></a>
> 📄 **Section :** Areson `25A7` (`docs/areson.md`) · [Original en anglais](../../docs/areson.md) · [↑ Haut](#top)

# Prise en charge de la batterie du récepteur Areson 25A7

## Pourquoi le programme d'origine manquait la souris

La Redragon M915RGB-WL se connecte via un « 2.4G Wireless Receiver » Areson/CompX `25A7:FA07`. Sa batterie n'est pas exposée via un usage HID standard *Battery Strength* et Windows ne dispose d'aucune propriété de batterie Bluetooth pour elle, car la liaison est une liaison propriétaire 2,4 GHz. La souris répond plutôt à une requête active `GetPower` ; ni le repli HID générique ni le repli Bluetooth ne pouvaient donc la détecter. Aucun pilote n'existait pour ce fabricant, le récepteur restait donc non revendiqué et silencieux.

## Matériel et paquets observés

Testé sous Windows 11 avec une Redragon M915RGB-WL le 2026-11-17 :

| Direction | VID:PID | Interface | Page d'usage : usage | Taille du rapport |
|---|---|---|---|---|
| requête (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 octets |
| réponse (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 octets |

La réponse arrive sur une collection de premier niveau différente de celle où la requête est écrite. Sous Windows il s'agit de `MI_01&COL07` (feature) et `MI_01&COL05` (input), raison pour laquelle le pilote ouvre les deux handles.

Requête capturée (`GetPower`, ID de rapport `08`, commande `04`, la somme de contrôle amène la somme de la trame à `0x55`) :

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Réponse capturée :

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Les décalages ci-dessous comptent l'ID de rapport comme octet zéro :

| Octet(s) | Signification | Exemple |
|---|---|---|
| 0 | ID du rapport de réponse | `09` |
| 1 | Écho de la commande | `04` |
| 2 | État, 0 = OK | `00` |
| 3–4 | Adresse, inutilisée pour `GetPower` | `00 00` |
| 5 | Longueur des données (2) | `02` |
| 6 | Niveau de batterie, 0–10, par paliers de 10 % | `08` = 80 % |
| 7 | Indicateur de charge, toute valeur non nulle | `00` = pas en charge |
| 16 | Somme de contrôle ; la somme des 17 octets vaut `0x55` (mod 256) | `3E` |

Le logiciel officiel du fabricant affichait 80 % pour la même trame, ce qui établit l'échelle ×10. `GetConnectStatus` (`08 03 …`) répond avec une charge utile de 1 octet et indiquait au même moment que la souris était connectée.

## Autres souris Areson

Les anciens récepteurs `FA7B` / `FA7C` utilisés par la Redragon M693 signalent la charge directement en pourcentage entier au même décalage de réponse. Appliquer l'échelle ×10 de ce pilote afficherait 800 %, ces identifiants de produit sont donc volontairement exclus. Seuls `FA07` et `FA08` sont gérés ; `FA08` est l'identifiant alternatif de la même famille et n'a pas été vérifié sur cette machine.

## Interrogation et identité

- Le pilote n'envoie que la requête en lecture seule `GetPower`. Il n'écrit jamais de données de configuration, d'éclairage ni de DPI.
- Chaque actualisation ouvre la collection feature avec un accès nul et la collection input en lecture, envoie la requête et attend jusqu'à 1,8 s une réponse, avec deux tentatives et une purge de file entre les deux afin qu'un rapport obsolète ne puisse pas être pris pour la réponse.
- Une lecture échouée ne revendique rien, de sorte qu'une souris en veille conserve la dernière valeur dans l'interface. L'entrée utilise un délai de grâce de 30 minutes, cohérent avec les autres pilotes passifs.
- La clé d'appareil est dérivée des identifiants fabricant et produit (`areson:25A7:FA07`), elle survit donc au cycle réception/veille et au rebranchement du récepteur.

## Validation

L'application complète a été compilée avec MSVC C++17 et le SDK Windows puis exécutée avec la véritable souris. `BatteryHub.exe --list` a renvoyé :

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

Le relevé correspondait exactement au pourcentage affiché par le logiciel officiel Redragon au même instant. Le script MinGW `build.bat` inclut le nouveau fichier source ; le `Makefile` le détecte via son motif générique.

## Sources du protocole

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl) : trames de 17 octets, séparation feature/input et règle de somme de contrôle `0x55`, extraites de captures USB du logiciel Redragon.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray) : commande `GetPower` et échelle de niveau de 10 % sur `25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md) : structure de réponse et échelle de pourcentage différente sur la famille `FA7B` / `FA7C`.


---

<a id="sec-darkrim"></a>
> 📄 **Section :** DARKRIM SHADOW (`docs/darkrim.md`) · [Original en anglais](../../docs/darkrim.md) · [↑ Haut](#top)

# Récepteur DARKRIM SHADOW / 寸渊影弑

Testé sur matériel avec `3654:6901`, fabricant `Jieli Technology`, révision `0100`. Utilisez l'interface **3**, usage `FF02:0002`, charges utiles d'entrée/sortie non numérotées de 64 octets (tailles de rapport HID Windows de 65 octets). L'interface 4 possède aussi `FF02:0002`, mais utilise l'ID de rapport 2 et n'a pas répondu à ce protocole ; elle est volontairement exclue.

Source du protocole : le [téléchargement PC Hub officiel](https://app.darkrim.net/hub/zh.html), `DARKRIM-0.1.26-x64-setup.rar`, téléchargé et décompressé statiquement sans installer ni lancer le logiciel fabricant. SHA-256 du fichier `DARKRIM.exe` extrait : `f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Adresses utiles dans ce binaire :

- `140124C80` : `sendGetBasicInfo(infoType)` envoie la commande `0010`, Request `01`, charge utile `[infoType, 00]`. Le sélecteur de batterie est `01`.
- `140118D30`, `140119200` : génération d'en-tête de trame et de CRC.
- `140126DB0` : analyseur TLV des infos d'appareil ; le TLV `01` est la batterie.
- `1400F5660`, `1400FA700` : consommateurs de batterie ; les sept bits faibles donnent le pourcentage, le bit fort indique la charge. La même valeur de batterie arrive aussi dans `0011` Notify `03`.

En-tête : `FE seq cmdLE type index count lengthLE`, suivi de la charge utile et du CRC-16/CCITT-FALSE (polynôme `1021`, valeur initiale `FFFF`, stocké en big-endian). La séquence est un compteur non nul sur quatre bits ; le chiffrement n'est pas utilisé.

Charges utiles réelles de requête/réponse, avant le remplissage HID par zéros :

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

Le TLV de réponse `01 01 28` donne **40 %, pas en charge**. Le pilote C++ de production a renvoyé cette valeur lors de trois requêtes consécutives sans logiciel fabricant. Le récepteur émet des notifications de démarrage avant la réponse correspondante, mesurées à environ 406 ms. Utilisez une échéance unique de réponse de 800 ms (plus au maximum 200 ms pour l'écriture), sans la réinitialiser lors des notifications sans rapport. Aucun battement de cœur (heartbeat) n'est nécessaire.

Le pilote n'envoie que le GET de batterie. Il n'accepte qu'une réponse non chiffrée avec séquence/commande/type concordants, un index à zéro, un compteur à zéro ou un (le matériel utilise zéro), une longueur et un CRC valides, et un seul TLV de batterie bien formé. Les réponses fragmentées, non sollicitées, malformées et hors plage sont ignorées.

## Précision observée de la batterie et état de charge

Considérez le pourcentage comme une **estimation grossière, et non comme une jauge vérifiée à 1 % de précision**. L'appareil du propriétaire a affiché la progression de charge par paliers de 10 points de pourcentage de 40 % à 90 %. À 90 %, cinq réponses GET de batterie et une notification non sollicitée portaient toutes `DA` : `DA & 7F = 90`, le bit 7 indiquant la charge. Après que le propriétaire a débranché le câble de charge et continué d'utiliser le récepteur 2,4 GHz, cinq autres réponses GET et une notification portaient toutes `5A` : toujours 90 %, mais avec le bit de charge remis à zéro. Toutes les douze trames ont réussi la vérification CRC.

Réponses de requête représentatives (séquence 4) :

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Le pilote et l'application officielle prélèvent tous deux le pourcentage directement sur les sept bits faibles. Le pilote n'arrondit pas aux dizaines, ne multiplie pas un palier par dix et n'interpole pas de valeurs intermédiaires ; des rapports synthétiques à 47 % et 95 % restent 47 % et 95 % dans l'analyseur de production. Les relevés grossiers observés proviennent donc en amont de l'analyseur, du signalement du casque ou du récepteur. Des relevés matériels plus fins n'ont pas été observés. Une courbe de décharge complète n'a pas été enregistrée ; un pas fixe de 10 % à chaque niveau de décharge ou sur d'autres firmwares n'est donc pas confirmé.

La charge et l'état de non-charge consécutif à 90 % ont été vérifiés sur matériel. Les bornes batterie faible/pleine, le comportement à l'extinction du casque, le Bluetooth et le mode données par câble USB n'ont pas été testés sur matériel. Aucune prise en charge n'est revendiquée pour ces modes. Aucune mise à jour de firmware, modification de configuration, commande d'égaliseur, modification d'appairage, réinitialisation ni binaire fabricant n'est inclus dans cette implémentation.

Test : `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Section :** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [Original en anglais](../../docs/hyperx_haste_2.md) · [↑ Haut](#top)

# Protocole de batterie HyperX Pulsefire Haste 2 Wireless

Lu par `HasteWireless` dans `src/drivers/hyperx.cpp`. Les requêtes proviennent de [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) et sont les mêmes que celles utilisées par NGENUITY.

Vérifié sur matériel :

- Pulsefire Haste 2 Core Wireless, dongle `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, dongle `03F0:0F98`, par uzumakiprime (PR #312). Le niveau correspondait à HyperX NGENUITY.

Le dongle `03F0:0D97` devrait fonctionner de la même manière mais n'est pas testé.

## Collection HID

| Champ | Valeur (`0F98`) |
|---|---|
| Interface USB | `MI_02` (interface 2) |
| Page d'usage : usage | `FF00:0001` |
| Longueur des rapports input / output / feature | 64 / 64 / 64 octets |

Le dongle expose aussi les collections standard souris et contrôle consommateur. Le pilote n'ouvre qu'une collection constructeur (page d'usage `FF00` ou supérieure) ayant des rapports d'entrée d'au moins 8 octets.

## Requêtes

Les deux sont des rapports de sortie : les deux premiers octets ci-dessous, complétés par des zéros jusqu'à la longueur du rapport. Chaque réponse est un rapport d'entrée dont le premier octet vaut la commande plus un. Chaque requête attend au plus une seconde sa réponse et ignore les rapports sans rapport (après une reconnexion, le dongle envoie de lui-même des rapports `44 xx`, `45 xx` et `FB xx`).

| Requête | Réponse | Signification |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0 lorsque la souris est éteinte ou hors de portée |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100 ; `charge` 1 = en charge, 2 = pleine sur le chargeur ; tension en mV, little endian (0 sur la Core) |

- Si la réponse de liaison manque, la réponse de batterie tranche.
- Si la liaison rapporte 0, aucune requête de batterie n'est envoyée et la souris est affichée comme éteinte.
- Pendant quelques secondes après la mise sous tension de la souris, elle rapporte environ 40 %. Une mesure dans les 6 s suivant l'établissement de la liaison est ignorée, et la zone de notification conserve la dernière valeur.

Les deux requêtes ne font que lire l'état. Rien ne modifie les paramètres, l'éclairage ni les modes.


---

<a id="sec-inphic"></a>
> 📄 **Section :** Inphic IN10 (`docs/inphic.md`) · [Original en anglais](../../docs/inphic.md) · [↑ Haut](#top)

# Famille Inphic IN10, récepteur KP 8K

L'appareil connecté, identifié par son propriétaire comme une IN10 MAX, s'énumère comme `Inphic KP 8K`, `1D57:FA65`, révision `0116`. Sa collection d'état est l'interface 2, usage `000A:0000`, longueur d'entrée 5 (y compris l'ID de rapport 03).

Observé environ toutes les quatre secondes, sans envoyer aucune requête :

```text
03 73 41 01 64
```

L'analyseur Xenta existant reconnaît ce format : modèle, événement, état de batterie, pourcentage. Deux rapports identiques sont exigés avant d'afficher 100 % ; sur les récepteurs apparentés, le premier rapport après la connexion peut être une fausse lecture à 100 %. Cette modification préserve cette protection ainsi que le comportement existant de charge et de veille.

Le bundle officiel [Inphic HUB](https://hub.inphic.cn/) `assets/index-BcHQx9B6.js` associe le modèle décimal 115 (`73`) à `IN10RMax`, et 116 (`74`) à `IN10Max`. Il utilise l'état de batterie 1 pour le pourcentage, 2 pour plein et 3 pour en charge. Utilisez le nom de modèle du firmware plutôt que d'attribuer `73` à IN10 MAX et de risquer de mal nommer d'autres appareils partageant ce récepteur.

Avant cette modification, l'application listait la souris connectée comme `Wireless mouse`. Le transport Xenta gérait déjà ses trames de batterie ; la modification fournit les noms de modèles manquants. Un `--list` à chaud peut afficher en veille parce que son observation initiale de cinq secondes peut ne recevoir qu'un seul rapport de quatre secondes. L'application résidente conserve l'écouteur et confirme la valeur lors d'un cycle ultérieur.

Vérifié sur matériel : rapports passifs, niveau répété à 100 % et identification de modèle par le pilote natif. Les transitions de charge, les bornes de batterie faible, le Bluetooth et le mode câble n'ont pas été vérifiés. Le modèle `74` provient de la table officielle et n'a pas été testé sur un autre matériel.


---

<a id="sec-machenike"></a>
> 📄 **Section :** Machenike L7 (`docs/machenike.md`) · [Original en anglais](../../docs/machenike.md) · [↑ Haut](#top)

# Machenike L7 Arctic / L7 Mix

Vérifié sur une L7 Arctic qui s'identifie comme **L7 Mix** :

| Connexion | VID:PID | Interface | Usage | Entrée / sortie / feature max |
| --- | --- | --- | --- | --- |
| Récepteur 2,4 GHz | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| Câble USB | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

Le pilote vérifie également le nom de produit HID `L7 Mix`. Les autres modèles Machenike, d'autres identifiants de récepteur et les requêtes constructeur Bluetooth ne sont pas activés.

## Source du protocole

Analyse d'interopérabilité du logiciel officiel **Machenike L7 Mix 1.0.0.8**, disponible depuis la [page de pilotes du fabricant](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/), et requêtes en lecture seule sur la véritable souris. SHA-256 de `DeviceDriver.exe` : `A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

Dans cet exécutable 32 bits (adresse de base `00400000`), la fonction à la VA `00436750` construit la requête d'état ; `004494F0` l'envoie via `HidD_SetFeature` et lit la réponse feature. L'analyseur d'état `00410C20` extrait les champs ci-dessous et transmet les champs batterie et charge à l'interface. Il s'agit d'adresses virtuelles, et non de décalages dans le fichier. Aucun exécutable propriétaire, code d'application ou ressource n'est inclus ici.

## Requête de lecture d'état

Envoyez **21 octets**, ID de rapport `51`, commande `06`, tous les autres octets à zéro :

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Lisez le rapport de fonctionnalités `51`, également sur 21 octets. La taille maximale de feature de la collection est de 1001 pour d'autres rapports ; ce n'est pas la longueur du rapport d'état. Le pilote attend 10 ms avant de lire et utilise une échéance unique de 200 ms par produit, incluant les réponses sans lien. Il n'envoie aucune commande de réglage, de mode, de macro ou de firmware.

Les indices incluent l'ID de rapport :

| Octets | Signification / valeurs observées |
| --- | --- |
| 0–1 | `51 06`, écho de commande requis |
| 4–7 | `8A 24 4E FF`, signature vérifiée de l'appareil L7 |
| 10, bits 0–2 | Mode de fonctionnement : 1 sur récepteur, 0 sur câble |
| 10, bit 3 | Souris sans fil connectée ; nul sur le câble USB également |
| 11 | Pourcentage de batterie, 0–100 (zéro est valide) |
| 12 | Indicateur de charge : 0 en décharge, 1 en charge |

Les autres champs et la sémantique de somme de contrôle ne sont pas établis. Le pilote n'invente pas de somme de contrôle. Il valide la commande, la longueur, la signature d'appareil, le mode et les plages de batterie/charge à l'état connecté avant de publier un relevé.

Réponse capturée du récepteur, également à 64 % dans l'application officielle :

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Réponse capturée sur câble USB pendant la charge (74 %) :

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

À ce moment-là, le récepteur renvoyait encore ses 64 % en cache, mais avait remis à zéro son bit de liaison :

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Cette mesure déconnectée ne doit pas exposer les valeurs de batterie/charge en cache. Le câble prévaut lorsque les deux transports sont présents, et la clé d'appareil stable est partagée entre les transports. Une L7 reconnue est réservée même en cas d'échec de requête afin que le pilote Ajazz ultérieur ne puisse pas l'interroger avec un autre protocole sur le VID partagé.

## Limites de validation

Les jeux de données et tests de transport simulé couvrent les relevés capturés, la charge, les valeurs valides 0 %/100 %, les récepteurs déconnectés, les réponses malformées/obsolètes, la correspondance stricte, les échecs de transport, la suppression des doublons et les boucles de réessai bornées. Les valeurs réelles 0 %/100 % et toutes les variantes de veille/firmware ne sont pas garanties par ces tests.


---

<a id="sec-nuphy"></a>
> 📄 **Section :** NuPhy WH80 (`docs/nuphy.md`) · [Original en anglais](../../docs/nuphy.md) · [↑ Haut](#top)

# NuPhy WH80 (câble USB et Bluetooth)

Testé sur matériel avec `19F5:A011`, révision de firmware `0116`, interface 1, usage `0001:0000`, charges utiles d'entrée/sortie non numérotées de 64 octets (65 octets dans les capacités HID Windows).

Source du protocole : [NuPhyIO](https://drive.nuphy.io/), bundle `main.b3fb29e0.js`, SDK `getBatteryState(0)`, `getDataPackage` et `createCommand`. Seul `GetFunc` (`05`), décalage `0020`, longueur `01` est demandé. Aucune commande d'initialisation, de configuration, d'éclairage ou de firmware n'est nécessaire.

Charge utile de requête, complétée par des zéros à 64 octets :

```text
55 05 00 21 01 20 00 00
```

Charge utile réelle de réponse :

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

L'octet 3 est l'octet faible de la somme des octets 4..63. La batterie est l'octet 8 : `value & 7F` donne le pourcentage, `value & 80` est l'indicateur de charge du SDK. Le pilote C++ natif a renvoyé **100 %, en charge** sur le clavier branché. Les transitions de charge et les bornes batterie faible/pleine n'ont pas été testées sur matériel ; les notes de firmware officielles décrivent les relevés du WH80 par incréments de 10 %. Le fonctionnement via récepteur sort du périmètre de ce pilote.

## Bluetooth

En Bluetooth, le même clavier utilise l'ID HID `19F5:324A` (révision `0129`) et annonce un nom visible tel que `NuPhy WH80 - 1`. Il expose deux collections clavier et une collection souris. L'heuristique HID générique donne la priorité aux souris ; ajoutez donc cet ID Bluetooth exact aux surcharges de clavier existantes.

Le rapport de batterie continue d'utiliser la propriété de batterie Bluetooth de Windows. Après avoir débranché l'USB, Windows a signalé **95 %** sur le clavier connecté. Une lecture sans cache de la caractéristique standard GATT Battery Level (`180F` / `2A19`) a également renvoyé **95 %** directement depuis le clavier. Il s'agit d'une mesure d'appareil/transport distincte de l'observation filaire à 100 % ; ne la remplacez pas par une pleine charge supposée et ne la remettez pas à l'échelle. La raison de l'écart entre ces relevés du firmware n'est pas établie.

Le pilote vérifie exactement le produit, l'interface, les tailles de rapport, l'en-tête de réponse, le décalage, la longueur, la somme de contrôle et la plage de pourcentage. Il utilise une échéance de réponse de 400 ms et ignore les réponses sans rapport dans cette même échéance.

Test de non-régression :

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Section :** Rapoo (`docs/rapoo.md`) · [Original en anglais](../../docs/rapoo.md) · [↑ Haut](#top)

# Prise en charge de la batterie des souris Rapoo

## Pourquoi le programme d'origine manquait la souris

`PollAllDevices()` énumère les collections HID de premier niveau de Windows une fois par actualisation. Chaque pilote constructeur reconnaît un protocole, ajoute un `DeviceStatus` et revendique son VID/PID afin que les pilotes génériques ne l'ajoutent pas à nouveau. L'interface gère déjà le pourcentage, la charge et la dernière mesure en veille.

Il n'y avait pas de pilote Rapoo. La VT3 Max Gen 2 envoie sa batterie dans un rapport d'entrée propre au fabricant, et non via l'usage HID standard Battery Strength ni via une propriété de batterie Bluetooth Windows. Les replis HID générique / Bluetooth existants ne pouvaient donc pas décoder son récepteur USB.

## Matériel et paquets observés

Testé sous Windows avec la VT3 Max Gen 2 du propriétaire le 2026-11-16 :

| Connexion | VID:PID | Interface | Page d'usage : usage | Taille entrée / sortie |
|---|---|---|---|---|
| Récepteur 2,4 GHz | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 octets |
| Câble USB | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 octets |

Les deux s'identifient comme `Rapoo Gaming Device`. Les autres collections comprennent les entrées standard souris, clavier et multimédia, des collections de configuration constructeur, et une interface de firmware de 513 octets. Le pilote de batterie n'ouvre que `FF00:0002` avec une taille d'entrée reconnue. Il n'ouvre jamais l'interface de firmware et n'envoie jamais de rapport de sortie, de rapport de fonctionnalités, de poignée de main ni de commande de configuration.

Rapport sans fil capturé, incluant l'ID de rapport :

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Rapport câble/charge capturé :

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Les décalages ci-dessous comptent l'ID de rapport comme octet zéro, conformément à `HidDev::Read()` de ce projet :

| Octet(s) | Signification | Exemple |
|---|---|---|
| 0 | ID de rapport | `07` |
| 1 quartet faible | Connexion : 0 récepteur, 1 Bluetooth, 2 câble | `20` / `22` |
| 1 quartet fort | Informations de capteur ; ne fait pas partie du type de connexion | `2` |
| 2 | Palier DPI courant | `03` |
| 3–4, 5–6 | DPI X/Y, little endian | `0320` = 800 |
| 7 | État de batterie : 0 invalide, 1 en décharge, 2 en charge | `01` / `02` |
| 8 | Pourcentage de batterie, 0–100 | `19` = 25 % |
| 13–14 | Product ID de la souris, little endian, si présent | `4617` |

La capture en direct du récepteur signalait `25%`, et l'application complète a ensuite renvoyé `27%, charging` par le câble. Le test de l'analyseur inclut la véritable capture sans fil. La charge et la connectivité par câble ont également été vérifiées sur du matériel réel ; elles ne sont pas simplement déduites de la présence d'un périphérique USB. Après que le propriétaire a débranché le câble et rebranché le récepteur, l'exécutable final a renvoyé `52%` sur `2.4 GHz receiver`, sans indicateur de charge, et a conservé la même clé `rapoo:4617`. Cela vérifie également la transition câble-vers-récepteur sur du matériel réel.

Également testé sous Windows avec une **VT9 Gen 2** le 2026-11-17 :

| Connexion | VID:PID | Interface | Page d'usage : usage | Taille entrée / sortie |
|---|---|---|---|---|
| Récepteur 2,4 GHz | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 octets |
| Câble USB | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 octets |

Le récepteur de la VT9 Gen 2 expose un rapport `FF00:0002` de **16 octets** au lieu de 19 octets, utilisant exactement la même structure `07` Nordic 54L (y compris le PID `4614` intégré aux octets 13–14). Trames capturées :

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

Par câble USB, des rapports d'état ont été observés lors d'interactions (ex. changement de DPI) ; avec l'interrupteur d'alimentation inférieur placé sur OFF tout en étant branchée, la souris rapportait `state=2, percent=1` au lieu du pourcentage réel de batterie.

### Récepteur VT3 Max Gen 2 avec collection de 13 octets (issue #1396)

Un formulaire de demande d'appareil pour le même identifiant de récepteur `24AE:1417` indiquait une disposition d'interfaces différente : `FF00:0002` avec **13 / 13** octets (au lieu de 19), et `FF00:000E` avec 33 / 33 octets, sans collection de firmware de 513 octets. Cela ressemble à une autre révision de firmware du récepteur. Le logiciel Rapoo affichait pourtant la batterie, le pilote ignorait donc un canal d'état fonctionnel.

Le décodeur `VT_nrf54L` (`py`) de Rapoo Hub est adaptatif en longueur : il lit toujours le DPI, l'état de batterie et le pourcentage, et ne lit les champs suivants (PID de la souris en `n[12..13]`, infos RF, ...) que lorsque le rapport est assez long. Le manifeste de la VT3 MAX (`productId: [17943, 5143]`) n'a pas de type de rapport d'entrée spécial, donc le rapport `07` passe également par ce décodeur sur ce récepteur. Un rapport de 13 octets (ID plus 12 octets) transporte toujours l'état à l'octet 7 et le pourcentage à l'octet 8 ; seul le PID intégré de la souris manque, le relevé utilise donc le PID du récepteur et conserve la clé `rapoo:4617`.

La longueur de 13 octets n'est acceptée **que pour `24AE:1417`**. Les trames doivent toujours réussir les mêmes contrôles (rapport `07`, quartet de connexion 0–2, état 1/2, pourcentage 0–100). Aucune trame de 13 octets en direct n'a encore été capturée ; les tests utilisent la capture testée de 19 octets tronquée à 13 octets.

## Autres souris Rapoo

Le Rapoo Hub officiel utilise cette structure `07` pour son pilote de souris Nordic 54L. Ses manifestes listent les VT0, VT1, VT2, VT3, VT3S, VT7, VT9 et d'autres variantes. L'inspection du bundle actuel a identifié 69 variantes VT utilisant `VT_nrf54L` ; c'est la preuve d'un protocole partagé, et non de 69 validations matérielles ni d'une promesse de couvrir la majeure partie du catalogue Rapoo. La prise en charge est sélectionnée selon le VID Rapoo, la collection dédiée, la longueur d'entrée et un rapport d'état valide, si bien qu'un modèle non listé utilisant le même protocole peut tout de même rapporter sa batterie. Une petite table de noms couvre les modèles courants ; les autres conservent leur nom de produit HID ou affichent `Rapoo wireless mouse`.

Les noms de produits et identifiants varient selon les générations et les régions. La paire testée `1417/4617` est appelée `VT3 MAX` dans le manifeste officiel actuel ; le propriétaire l'identifie comme VT3 Max Gen 2. Le modèle distinct `VT3 MAX V2` du manifeste actuel porte les identifiants `1B06/4B06`. Les tableaux communautaires attribuant `1417` à la VT9 Pro ne doivent pas servir de base unique pour nommer ou détecter cet appareil.

Les anciens firmwares VT, documentés pour la VT3 Pro (`1215/4415`), poussent plutôt un rapport de 7 octets sur le même usage `FF00:0002` :

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

Pour cet ancien format, les états 1/2 signifient en décharge/en charge. Un pourcentage de charge à `7F` signifie inconnu et est conservé comme inconnu. L'état de transition 0, les rapports `BC` sans lien, les paquets malformés et les pourcentages supérieurs à 100 sont ignorés. La prise en charge héritée dispose d'une couverture automatisée, mais n'a pas été vérifiée ici avec une ancienne souris physique. Cette interprétation est restreinte aux identifiants de produit `1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) et à leur collection d'entrée de 7 octets.

La VT1 Pro Max (récepteur `24AE:1233`, câble `24AE:4433`, firmware souris 222, firmware dongle 213) a été ajoutée à partir des captures USBPcap jointes par son propriétaire à l'issue #136. La sortie de `--dump` liste la collection `FF00:0002` de 7 octets sur l'interface 1, et les captures la montrent en train de pousser des trames sans aucune requête de l'application Rapoo :

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

Sur le câble, le rapport n'a été observé qu'une seule fois dans une capture de 16 secondes, donc une lecture uniquement sur câble peut expirer lors de certaines actualisations ; le récepteur l'envoie régulièrement. Le profil Nordic n'interprète jamais les paquets `BB`.

Cela n'établit **pas** la prise en charge de tous les appareils Rapoo. Les modèles CH584 tels que les VT1 SE et VT7 SE utilisent le rapport `08` dans le pilote officiel et ne sont pas pris en charge par ce décodeur. D'autres révisions Telink utilisent une interprétation différente des indicateurs `BB`, certains modèles bureautiques utilisent des requêtes actives de batterie, et les modèles Bluetooth peuvent n'exposer que la propriété de batterie Windows. Ceux-ci restent gérés par les replis existants ou nécessitent une implémentation distincte vérifiée. Ne leur envoyez pas de requêtes devinées.

## Interrogation et identité

- La lecture est passive. Les handles `FF00:0002` correspondants restent ouverts entre les cycles (comme dans `PollXenta`) afin que Windows mette en tampon les trames d'état arrivant durant l'intervalle d'actualisation de 60 secondes ; chaque cycle vide toutes les trames en attente (en conservant la lecture de batterie valide la plus récente) avant de recourir à une attente de 5 secondes à la première ouverture ou sur une file vide. Les appareils débranchés sont retirés et leurs handles fermés. Les paquets sans lien ne réinitialisent pas l'échéance.
- Le PID de souris intégré, ou une paire câble/récepteur connue pour les anciens appareils, fournit la même clé d'interface lors des changements de câble. Les mesures sur câble et sur récepteur sont fusionnées en une seule entrée, en privilégiant l'état du câble tout en préservant un pourcentage valide du récepteur si le câble signale un niveau inconnu.
- Un dépassement de délai n'invente pas de pourcentage et ne revendique pas l'appareil. Après une lecture réussie, l'interface existante peut conserver cette mesure, estompée, pendant 30 minutes de silence.
- Le modèle d'identité existant du programme basé sur VID/PID ne permet pas de distinguer plusieurs souris identiques ayant le même ID de modèle. Le fonctionnement physique simultané câble/récepteur n'a pas été testé ; la fusion des deux entrées est couverte par le test de transport simulé.

## Validation

`make test` exécute un test de décodeur portable et un test de pilote Windows avec des réponses HID simulées. La couverture inclut la capture réelle, 0 % et 100 %, la charge, les niveaux manquants, les trames invalides/tronquées, les collections/fabricants non pris en charge, l'isolation des profils de protocole, les dépassements de délai, les clés stables et la déduplication câble/récepteur sans jeter un pourcentage connu.

L'application complète a été compilée localement avec MSVC C++17 et le SDK Windows, et `--list` / `--dump` ont été exécutés avec la véritable souris. La compilation MinGW maintenue inclut `rapoo.cpp` dans `build.bat` ; le Makefile le découvre automatiquement. MinGW lui-même n'était pas installé dans l'environnement de test.

## Sources du protocole

- [Rapoo Hub officiel](https://hub.rapoo.cn/), inspecté le 2026-11-16 : [pilote JavaScript et manifestes](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js) embarqués. Les décodeurs pertinents sont `py`/`Hk` pour `VT_nrf54L` et `qM`/`QM` pour les significations de connexion et d'état de batterie. Le gestionnaire distinct `VT_CH584` consomme le rapport `08` et sort du cadre de cette implémentation. Les noms minifiés peuvent changer dans de futures versions.
- [Device-Battery-Info : RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs), pour les anciens rapports VT3 Pro, l'état de charge et la sentinelle de niveau inconnu.
- Captures USBPcap de l'issue #136 (VT1 Pro Max sur récepteur et sur câble pendant la charge).
- [ClickSync : protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js) corrobore indépendamment les diffusions d'état passives `07` et le décalage de batterie. Son analyseur borne les pourcentages invalides ; cette implémentation les rejette à la place.


---

<a id="sec-rawm"></a>
> 📄 **Section :** RAWM (`docs/rawm.md`) · [Original en anglais](../../docs/rawm.md) · [↑ Haut](#top)

# Notes sur le protocole RAWM

Les souris RAWM (et la SADES Dagger, qui partage la même plateforme) communiquent avec l'application RAWM HUB via une collection HID constructeur, `FF00:0001`, avec des rapports d'entrée et de sortie non numérotés de 64 octets (65 octets avec l'ID de rapport). Les récepteurs et les souris utilisent le Vendor ID de Nordic `1915`.

Source : l'application web RAWM HUB, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), et son script `https://hub.miracletek.net/hub/js/library.min.js` (obfusqué ; les noms de fonctions et de constantes ci-dessous proviennent du script). Les Product ID pris en charge proviennent de la table d'appareils téléchargée par l'application (`https://www.miracletek.net/game/device.php`). Les Leviathan V4 GT et NYX60 utilisent Hub Web 3.0 sur le VID `373E`, qui est un protocole différent.

## Paquets

Octet 0 de chaque rapport (après l'ID de rapport) :

| Bits de poids fort | Signification |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | les 6 bits faibles indiquent la taille de charge utile ; la charge utile poursuit le flux d'événements |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | contrôle de flux (tailles de tampon libres) ; ignoré ici |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | les 6 bits faibles sont un canal ESB ; le reste du rapport est un paquet pour ce canal. La souris derrière un récepteur est sur le canal 0 |

Les charges utiles forment un flux d'octets d'événements :

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## Lecture de la batterie

Le pilote répète ce que fait l'application lorsqu'un récepteur est connecté (`send_event_query`, `send_event_ping`) :

1. Vers le récepteur : `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), puis des pings `00 84 0E 04 00 00`. L'appareil n'envoie de données que tant que l'hôte continue d'écrire, donc l'hôte envoie des pings. Le récepteur répond `CMD_QUERY_RESULT` (`02`) avec du JSON, ex. `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. La même requête et les mêmes pings pour le canal 0, préfixés par `C0`. La souris répond par un objet JSON d'environ 550 octets en blocs ESB de 30 octets, ex. `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`. `battery` est un pourcentage (RAWM HUB l'affiche tel quel), `chr` vaut 1 pendant la charge.
3. Les changements ultérieurs arrivent en tant que `CMD_NOTIFY` (`0B`) type `17` : `[17, percent, charging]`.

Le pilote interroge toujours le récepteur en premier, comme le fait l'application (lors d'un test, une requête envoyée uniquement au canal 0 n'a obtenu aucune réponse). Une souris en veille ne répond pas du tout ; le récepteur, lui, continue de répondre.

La requête transporte l'horloge du PC parce que l'application l'envoie ainsi ; rien d'autre n'est écrit. Les souris signalent `"crc":1`, ce qui indique à l'application d'envelopper les commandes suivantes (configuration) dans une trame CRC-16 ; la requête initiale et les pings sont acceptés sans CRC, car l'application les envoie avant de le savoir.

Testé sur une Leviathan V4 (firmware 1.2.0) avec le récepteur RAWM HS `1915:2346` (firmware 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **Section :** VAXEE (`docs/vaxee.md`) · [Original en anglais](../../docs/vaxee.md) · [↑ Haut](#top)

# Récepteurs VAXEE 4K/8K et ZYGEN NP-01S V2

## Périmètre et validation matérielle

Ce pilote prend en charge le récepteur VAXEE 4K `3057:1002`, le récepteur VAXEE 8K `3057:2002` et la ZYGEN NP-01S V2 Wireless par câble USB (`3057:1011`), sur leur collection constructeur `FF05:0001` avec un rapport de fonctionnalités de 64 octets. Les autres récepteurs VAXEE, autres identifiants de produit en câble et appareils ZOWIE ne sont volontairement pas interrogés.

Le récepteur 8K (`VAXEE 8K Wireless`, appairé avec une NP-01 Ergo Wireless 8K) a été testé sous Windows et a renvoyé son état via le même protocole :

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

Le récepteur est partagé par toutes les souris VAXEE 8K et n'indique pas laquelle est appairée ; il est donc affiché sous son propre nom. L'état de charge sur le récepteur 8K n'a pas encore été observé sur matériel.

Un véritable récepteur 4K a été testé sous Windows :

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

L'application intégrée a également affiché :

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

La même souris a ensuite été branchée directement en USB et Windows l'a identifiée comme `ZYGEN NP-01S V2 Wireless` (`3057:1011`). Le pilote de production mis à jour a renvoyé :

```
VAXEE battery: 75%; charging: yes
```

Le widget de la barre des tâches a été créé avec succès dès la première version pour récepteur. Le fonctionnement sur batterie via récepteur et la charge filaire ont tous deux été observés ; les transitions de pleine charge et le comportement en veille/hors tension n'ont pas été testés sur matériel. Le décodage de la charge et les réponses invalides sont couverts par des réponses simulées.

## Protocole

Source : [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

Une requête est un rapport de fonctionnalités HID de 64 octets complété par des zéros :

| Octet | Valeur |
|---|---|
| 0 | `0E`, ID de rapport |
| 1 | `A5`, en-tête |
| 2 | `0B` pour le niveau de batterie ; `10` pour l'état de charge |
| 3 | `01`, indicateur de lecture (jamais `02`, écriture) |
| 4 | `01`, longueur des données |
| 5–63 | `00` |

Après avoir envoyé la requête avec `HidD_SetFeature`, attendez 100 ms et lisez le rapport `0E` avec `HidD_GetFeature`. Exigez au moins six octets ainsi que l'ID de rapport, l'en-tête, l'écho de commande et la longueur de données attendus.

Pour la batterie, l'octet 5 de la réponse doit être compris entre 0 et 20 et est multiplié par cinq, ce qui donne 0–100 % par paliers de 5 %. Pour la charge, l'octet 5 est non nul pendant la charge. Un échec de la requête de charge n'invalide pas un relevé de batterie par ailleurs valide.

Le pilote réessaie la requête de batterie une fois. Il y a au maximum trois requêtes de lecture par collection correspondante (deux tentatives de batterie et une requête de charge), avec un délai explicite total de 300 ms. Il n'envoie aucune commande de réglage, d'appairage, de firmware ou d'éclairage.

Si aucune réponse valide de batterie n'est reçue, le pilote ne signale rien et laisse l'appareil non revendiqué. Tant que la collection USB reste présente, l'interface conserve une lecture réussie précédente, estompée, jusqu'à 30 minutes grâce à son délai de grâce existant. Si la collection physique disparaît, le pilote émet un état déconnecté pour terminer immédiatement ce délai de grâce. Cela évite qu'une icône obsolète du récepteur ne persiste lorsque le câble est déplacé vers la souris.

## Tests

`make test` inclut `tests/vaxee_driver_test.cpp`, qui lie le pilote de production à un transport HID simulé. Il vérifie les requêtes sortantes exactes en lecture seule, la conversion en pourcentage, le décodage de la charge, les réponses invalides et manquantes, les appareils déjà revendiqués et le filtrage exact des collections.
