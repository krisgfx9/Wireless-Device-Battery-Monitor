<!--
  Bản dịch đầy đủ tài liệu BatteryHub (Tiếng Việt)
  Nguồn: docs/i18n/_template.md
-->
<a id="top"></a>

<!-- lang-switcher:start -->
🌐 **Ngôn ngữ:** [English](../../README.md) | [العربية](ar.md) | [Deutsch](de.md) | [Español](es.md) | [فارسی](fa.md) | [Français](fr.md) | [עברית](he.md) | [Magyar](hu.md) | [日本語](ja.md) | [한국어](ko.md) | [Polski](pl.md) | [Português (Brasil)](pt-BR.md) | [Русский](ru.md) | [Svenska](sv.md) | [Türkçe](tr.md) | [Українська](uk.md) | **Tiếng Việt** | [简体中文](zh-CN.md) | [繁體中文](zh-TW.md) | [Thêm ngôn ngữ](README.md)
<!-- lang-switcher:end -->

# BatteryHub — Tài liệu đầy đủ (Tiếng Việt)

> Tệp Markdown độc lập duy nhất này tổng hợp toàn bộ tài liệu hiển thị trong kho lưu trữ để người dịch chỉ cần duy trì **một tệp cho mỗi ngôn ngữ**.

## Mục lục

1. [Tổng quan BatteryHub, Thiết bị hỗ trợ, Cài đặt, Dòng lệnh & Biên dịch (`README.md`)](#sec-readme)
2. [Hướng dẫn đóng góp (`CONTRIBUTING.md`)](#sec-contributing)
3. [Mẫu Pull Request (`.github/pull_request_template.md`)](#sec-pr-template)
4. [Hướng dẫn phát hành & ký số (`docs/releasing.md`)](#sec-releasing)
5. [Bản vá Firmware 2.4 GHz cho bàn phím Keychron (`docs/keychron_keyboard_firmware/README.md`)](#sec-keychron-firmware)
6. [Hỗ trợ BLE cho GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`)](#sec-gamesir-cyclone-pro)
7. [Hướng dẫn sử dụng đa ngôn ngữ & bản địa hóa (`docs/i18n/README.md`)](#sec-localization-guide)
8. [ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`)](#sec-ardor-fury-v2)
9. [Bộ thu Areson 25A7 (`docs/areson.md`)](#sec-areson)
10. [Bộ thu DARKRIM SHADOW (`docs/darkrim.md`)](#sec-darkrim)
11. [HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`)](#sec-hyperx-haste-2)
12. [Bộ thu Inphic IN10 / KP 8K (`docs/inphic.md`)](#sec-inphic)
13. [Machenike L7 Arctic / L7 Mix (`docs/machenike.md`)](#sec-machenike)
14. [NuPhy WH80 (`docs/nuphy.md`)](#sec-nuphy)
15. [Hỗ trợ pin chuột Rapoo (`docs/rapoo.md`)](#sec-rapoo)
16. [Ghi chú giao thức RAWM (`docs/rawm.md`)](#sec-rawm)
17. [Bộ thu VAXEE 4K/8K (`docs/vaxee.md`)](#sec-vaxee)


---

<a id="sec-readme"></a>
> 📄 **Mục:** Tổng quan BatteryHub (`README.md`) · [Bản gốc tiếng Anh](../../README.md) · [↑ Lên đầu trang](#top)

# BatteryHub

*Trước đây có tên là **Wireless Battery**. Phiên bản 1.1.0 đã đổi tên ứng dụng; khi cập nhật sẽ vẫn giữ nguyên thiết lập, tùy chọn khởi động cùng hệ thống và lịch sử pin của bạn.*

[![Ủng hộ tôi trên Ko-fi](https://img.shields.io/badge/Ko--fi-Support%20me-FF5E5B?logo=ko-fi&logoColor=white)](https://ko-fi.com/krisgfx)
[![Quyên góp qua PayPal](https://img.shields.io/badge/PayPal-Donate-00457C?logo=paypal&logoColor=white)](https://www.paypal.com/paypalme/krisgfx)
[![GitHub Sponsors](https://img.shields.io/badge/GitHub-Sponsor-EA4AAA?logo=githubsponsors&logoColor=white)](https://github.com/sponsors/krisgfx9)
[![Tham gia Discord của chúng tôi](https://img.shields.io/badge/Discord-Join%20us-5865F2?logo=discord&logoColor=white)](https://discord.gg/ZgDDUPP8ye)
[![Gắn sao trên GitHub](https://img.shields.io/github/stars/krisgfx9/Wireless-Device-Battery-Monitor?style=flat&logo=github&label=Star)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor)
[![Chia sẻ trên Reddit](https://img.shields.io/badge/Reddit-Share-FF4500?logo=reddit&logoColor=white)](https://www.reddit.com/submit?url=https%3A%2F%2Fgithub.com%2Fkrisgfx9%2FWireless-Device-Battery-Monitor&title=Wireless%20Battery%3A%20battery%20levels%20of%20your%20wireless%20devices%20on%20the%20Windows%20taskbar)
[![Báo cáo thiết bị](https://img.shields.io/badge/Report-a%20device-2EA44F?logo=github&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues/new)
[![Hỗ trợ dịch thuật](https://img.shields.io/badge/Help-translate-6F42C1?logo=googletranslate&logoColor=white)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/129)

Hiển thị mức pin của chuột, tai nghe, bàn phím và tay cầm chơi game không dây ngay trên thanh tác vụ (Taskbar) của Windows.

![BatteryHub trên thanh tác vụ](../screenshot.png)

> **Chỉ muốn dùng ngay?** Hãy tải **[BatteryHub-Setup](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)** từ bản phát hành mới nhất, chạy tệp cài đặt và bấm qua các bước. Vậy là xong.
>
> **Người dùng có kinh nghiệm** có thể tải bản ZIP di động (portable), sử dụng [các tùy chọn dòng lệnh](#dòng-lệnh), hoặc [tự biên dịch từ mã nguồn](#biên-dịch) bằng `make` hoặc `build.bat`.
>
> **Bạn thích ứng dụng này?** BatteryHub hoàn toàn miễn phí và mã nguồn mở. Nếu nó giúp bạn đỡ phải mở phần mềm nặng nề của hãng, bạn có thể ủng hộ dự án trên [Ko-fi](https://ko-fi.com/krisgfx), [PayPal](https://www.paypal.com/paypalme/krisgfx) hoặc [GitHub Sponsors](https://github.com/sponsors/krisgfx9). Điều đó giúp tôi duy trì các ứng dụng miễn phí song song với việc học. Không thể quyên góp? Một ⭐ sao trên GitHub, chia sẻ ứng dụng hoặc báo cáo thiết bị chưa được hỗ trợ kèm kết quả `--dump` cũng giúp ích không kém.

- **Siêu nhẹ**: ứng dụng ~350 KB, chỉ tiêu tốn khoảng 2 MB RAM. Viết bằng C++/Win32 thuần, không cần runtime phụ, không dịch vụ chạy ngầm và cài đặt chỉ trong vài giây mà không cần quyền quản trị viên.
- **Không cần phần mềm của hãng**: giao tiếp trực tiếp với thiết bị. G HUB, Synapse, iCUE, GG và NGenuity có thể giữ trạng thái tắt (hoặc chạy song song; chúng không xung đột).
- **Hỗ trợ nhiều thương hiệu**: Logitech, Razer, SteelSeries, Corsair, HyperX, Glorious, Jabra, JBL, tay cầm PlayStation và Xbox, Samsung Galaxy Buds, bất kỳ thiết bị Bluetooth nào mà Windows nhận biết được mức pin, cùng mọi tai nghe được [HeadsetControl](https://github.com/Sapd/HeadsetControl) tích hợp sẵn hỗ trợ.

## Hiển thị

**Trên thanh tác vụ (mặc định):** `🎧 30%  🖱 93%` ngay cạnh vùng thông báo, được vẽ bằng phông chữ biểu tượng của Windows.
- **Pin yếu:** số màu đỏ nghĩa là pin còn từ 15% trở xuống.
- **Đang sạc:** biểu tượng ⚡ màu xanh dương xuất hiện bên cạnh con số. Khi thiết bị đã sạc đầy và vẫn đang cắm nguồn, biểu tượng chuyển thành dấu ✓ màu xanh lá.
- **Đang ngủ (Sleep):** chữ mờ đi nghĩa là thiết bị đang ở chế độ ngủ và giá trị ghi nhận gần nhất đang được hiển thị.
- **Đã ngắt kết nối (tùy chọn):** bật *Hiện thiết bị đã ngắt kết nối* để hiển thị dấu `×` mờ cho các thiết bị mà trình điều khiển báo cáo rõ ràng rằng liên kết không dây đang ngoại tuyến. Tính năng này không tự suy đoán ngắt kết nối chỉ vì lỡ một lần hỏi pin; mặc định vẫn ẩn các thiết bị ngoại tuyến.
- **Hai thiết bị cùng loại:** khi có hai con chuột (hoặc hai tay cầm...) cả hai sẽ dùng chung một biểu tượng, vì vậy mỗi thiết bị được gắn một nhãn nhỏ tối đa 3 ký tự ở góc biểu tượng lấy từ tên thiết bị (`MX`, `PRO`), hoặc một con số nếu tên không phân biệt được. Thiết bị đứng một mình cùng loại sẽ không hiện nhãn nhỏ.
- **Giao diện:** tự động theo chế độ sáng/tối và tỷ lệ DPI của Windows.
- **Giao diện Taskbar trong suốt** (ví dụ Taskbar Styler của Windhawk): bật *Đổ nền chữ Taskbar* trong menu để chữ luôn dễ đọc trên nền hình nền.
- **Nhiều màn hình:** widget hiển thị trên thanh tác vụ của mọi màn hình cạnh đồng hồ, giúp luôn nhìn thấy ngay cả khi chơi game toàn màn hình. Mục *Hiển thị Widget trên* trong menu cho phép chọn *Tất cả màn hình*, *Chỉ màn hình chính*, hoặc một màn hình cụ thể (ví dụ chỉ *Màn hình 3*).
- **Tùy chọn hiển thị khác:** *Icon nằm trên % Pin* xếp chồng từng biểu tượng lên trên mức pin để tiết kiệm chiều ngang; *Màu theo thương hiệu* hiển thị các thương hiệu quen thuộc theo màu đặc trưng (xanh lá Razer, đỏ HyperX, ...) kèm thanh mức pin mảnh; hai thiết bị cùng loại có nhãn nhỏ để phân biệt; thanh tác vụ đặt bên trái hoặc phải sẽ hiển thị thành cột thiết bị.
- **Ngôn ngữ:** English, العربية, Deutsch, Español, فارسی, Français, עברית, 日本語, 한국어, Magyar, Polski, Português (Brasil), Русский, Svenska, Tiếng Việt, Türkçe, Українська, 简体中文 và 繁體中文. Cả ứng dụng Windows lẫn Linux đều tự theo ngôn ngữ hiển thị hệ thống; mục *Ngôn ngữ* trong menu cho phép chọn ngôn ngữ khác, và trình cài đặt Windows cũng hỗ trợ đầy đủ cả 19 ngôn ngữ. Câu chữ giao diện nằm trong các tệp tĩnh `lang/*.json` có thể chỉnh sửa trực tiếp, còn tài liệu dịch đầy đủ nằm trong [`docs/i18n/`](README.md). Xem [Bản dịch](#bản-dịch) để chỉnh sửa hoặc thêm ngôn ngữ mới.
- **Màu theo thương hiệu:** thiết bị của 15 thương hiệu phổ biến sẽ mang màu sắc của hãng kèm hiệu ứng phát sáng nhẹ và thanh mức pin mảnh bên dưới phần trăm: Razer xanh lá, Logitech xanh dương, SteelSeries cam, Corsair vàng, HyperX / ROG / ZOWIE đỏ, PlayStation, Xbox, Samsung, Apple, Jabra, JBL, Cooler Master và Steam. Mỗi màu đều có sắc độ riêng cho taskbar tối và sáng. Thương hiệu được xác định lần lượt theo trình điều khiển đã tìm ra thiết bị, mã nhà sản xuất (VID), rồi đến tên; bảng màu và quy tắc nằm trong `src/brands.cpp`. Có thể tắt bằng mục *Màu theo thương hiệu* trong menu.

**Icon ở khay hệ thống (Tray):** mỗi thiết bị có một biểu tượng riêng vẽ sẵn con số bên trong, kèm thông báo "Pin yếu" khi đạt mức 15%. Ứng dụng tự động chuyển sang chế độ này nếu taskbar đặt dọc hoặc không tìm thấy taskbar.

**Đặt tên thiết bị tùy chỉnh:** mở menu con của thiết bị và chọn *Đổi tên thiết bị...* để đặt tên (tối đa 64 ký tự). Tên này được dùng trong chú giải/nhãn của widget taskbar, chú giải và thông báo ở khay hệ thống, cũng như trong menu thiết bị. Dùng *Đặt lại tên ban đầu* để khôi phục tên từ trình điều khiển. Tên được lưu cục bộ trong registry Windows của người dùng hiện tại (`Software\WirelessBattery`, `DeviceAliases`), gắn với khóa thiết bị ổn định. Việc đổi tên không bao giờ làm thay đổi khớp nối driver, truy vấn giao thức hay đầu ra chẩn đoán `--list` / `--dump`. Không cần tài khoản hay kết nối mạng.

Di chuột để xem chi tiết. Nhấp chuột để mở menu: danh sách mọi thiết bị (nhấp vào một thiết bị để ẩn hoặc hiện), chế độ hiển thị, *Làm mới ngay*, *Khởi động cùng Windows* và *Thoát*. Mức pin tự cập nhật mỗi 60 giây (*Tần suất kiểm tra pin* trong menu chỉnh được khoảng này), và cập nhật ngay lập tức khi cắm thiết bị hoặc máy tính thức dậy.

## Cảnh báo pin thông minh (thử nghiệm)

Bạn có thể đặt **ngưỡng thông báo pin yếu riêng cho từng thiết bị** từ menu con của từng thiết bị: **Cảnh báo pin** → *Mặc định (15%)*, *Tắt thông báo*, hoặc một trong các mức 5%, 10%, 15%, 20%, 25%, 30%, 35%, 40%. Ngưỡng mặc định 15% vẫn giữ nguyên trừ khi bạn chọn giá trị ghi đè. Thiết lập được lưu theo khóa thiết bị trong registry Windows của người dùng hiện tại (`Software\WirelessBattery`, `AlertThresholds`).

Cảnh báo chỉ kích hoạt từ một giá trị pin 0–100% thực tế, mới nhận được khi thiết bị đang kết nối, đang thức và không sạc. Cảnh báo chỉ phát một lần và sẽ chỉ sẵn sàng kích hoạt lại sau khi mức pin tăng lên cao hơn ngưỡng đã chọn trên 10 điểm phần trăm (hoặc khi bắt đầu sạc). Thiếu dữ liệu hoặc thiết bị đang ngủ sẽ không kích hoạt lại cảnh báo. Thiết bị đang bị ẩn sẽ không tạo thông báo. Tắt thông báo cho một thiết bị không làm ẩn thiết bị đó hay thay đổi con số phần trăm của nó.

Cả hai chế độ widget trên thanh tác vụ và biểu tượng khay hệ thống đều hỗ trợ thông báo. Vì Windows cần một biểu tượng ở vùng thông báo để hiện bong bóng thông báo kiểu truyền thống, chế độ widget có thể tạm thời hiện một biểu tượng ở khay hệ thống trong tối đa một phút sau khi phát cảnh báo. Màu sắc widget và tô sáng pin yếu vẫn sử dụng ngưỡng 15% toàn cục ban đầu của dự án, độc lập với thiết lập thông báo.

## Lịch sử pin & thống kê

Nhấp chuột phải vào một thiết bị trong widget taskbar hoặc menu khay hệ thống và chọn **Lịch sử pin...**.
Trình xem gốc theo kịp DPI (tự theo giao diện sáng/tối của Windows) hiển thị các mức pin đã ghi nhận bằng đường nối điểm trong **24 giờ qua**, **7 ngày qua** hoặc **30 ngày qua**, cùng với mức mới nhất, thấp nhất/cao nhất, biến động theo điểm phần trăm và số lần ghi. Bạn có thể xóa lịch sử của thiết bị đang chọn ngay trong trình xem.

Lịch sử chỉ được ghi **cục bộ** cho các thiết bị đang kết nối, đang thức và có báo cáo phần trăm bằng số. Dữ liệu được lấy mẫu tối đa mỗi 30 phút một lần cho mỗi thiết bị (trừ khi chuyển đổi trạng thái sạc, với khoảng tối thiểu 60 giây). Dữ liệu được lưu tối đa 30 ngày và tệp cục bộ được giữ dưới khoảng 2 MB. Ứng dụng không bao giờ thăm dò phần cứng ngoài chu kỳ hỏi pin hiện có, không gửi bất kỳ dữ liệu lịch sử nào qua mạng, và đưa ra ước tính thời gian hết pin gần đúng một cách thận trọng chỉ dựa trên các lần quan sát mức xả gần đây. Cần tối thiểu 4 điểm dữ liệu, 2 giờ, mức giảm 3 điểm phần trăm, một lần đọc mới và một đoạn xả pin ổn định. Đang sạc, dữ liệu cũ hoặc chưa đủ dữ liệu sẽ không hiển thị ước tính; thời lượng pin do thiết bị tự báo không khả dụng. Ước tính này không phải cam kết chính xác tuyệt đối. Dữ liệu biểu đồ bị thiếu được hiển thị thành khoảng trống chứ không tự nội suy.

Tắt **Ghi lại lịch sử pin** trong menu để ngừng lưu dữ liệu mới; dữ liệu đã lưu trước đó vẫn giữ nguyên cho đến khi bạn xóa trong trình xem. Tệp được lưu tại `%LOCALAPPDATA%\WirelessBattery\battery_history.tsv`. Mã định danh thiết bị trong tệp được mã hóa nhận dạng (không mã hóa mật mã); tệp thuộc phạm vi cục bộ của tài khoản Windows hiện tại. Khi chạy `--demo`, biểu đồ dùng dữ liệu mẫu giả lập và không bao giờ được lưu. **Lưu ý:** lịch sử chỉ bắt đầu tích lũy sau khi cài đặt tính năng này và ứng dụng đã chạy được một thời gian.

## Thiết bị được hỗ trợ

| Hãng | Thiết bị | Cách thức |
|---|---|---|
| **NuPhy** | WH80 qua cáp USB (`19F5:A011`) hoặc Bluetooth (`19F5:324A`), đã thử nghiệm trên phần cứng thật | USB: truy vấn pin NuPhyIO chỉ đọc; Bluetooth: mức pin Windows có phân loại bàn phím ([ghi chú giao thức](#sec-nuphy)) |
| **DARKRIM** | SHADOW (寸渊影弑) qua đầu thu USB `3654:6901` (đã thử nghiệm trên phần cứng thật) | Truy vấn pin chỉ đọc có kiểm tra CRC và cờ đang sạc; quan sát thấy giá trị nhảy theo bước 10%, độ chia mịn hơn chưa được kiểm chứng ([ghi chú giao thức](#sec-darkrim)) |
| **Inphic** | IN10R MAX / IN10 MAX qua đầu thu KP 8K (`1D57:FA65`; mẫu `73` đã thử nghiệm phần cứng thật, mẫu `74` chưa thử) | Báo cáo trạng thái Xenta thụ động; hai khung trùng khớp xác nhận mức pin ([ghi chú giao thức](#sec-inphic)) |
| **ASTRO** | A50 X (`046D:0B0B`, đã thử), A50 Gen 5 (`046D:0B1C`), A50 Gen 4 (`9886:002C` đã thử, `002D`/`002A`), A50 Gen 3 (`9886:0015` đã thử, `0014`/`0018`/`001D`/`0026`), A20 Wireless (`9886:0037`–`0045`), qua trạm đế USB | Phần trăm pin, trạng thái đang sạc và đặt trên đế sạc |
| **Logitech** | Chuột và bàn phím trên đầu thu Unifying, Bolt, Lightspeed (bao gồm dongle PRO X3 SUPERSTRIKE `046D:C54F`) và Nano, qua USB hoặc Bluetooth; tai nghe dòng G (G533, G535, G633/G635/G733/G933/G935, G PRO/PRO X); G435 trên dongle đời mới `046D:0ADF` | HID++ 1.0 / 2.0 với cơ chế dò tìm tính năng: unified battery, mức pin, điện áp, ADC; G435: báo cáo hãng đóng khung CRC-16, `GET_BATTERY` theo mV |
| **Razer** | Chuột, bàn phím và dongle không dây; tai nghe BlackShark V2 HyperSpeed, V2 Pro (2020/2023), V3 / V3 Pro / V3 X, V3 Pro for Xbox (đầu thu `1532:0A55`, cáp `0A4E`); Barracuda X (2022) trên đầu thu 2.4 GHz (`1532:0550` hoặc `1532:0552`); Barracuda Pro (`1532:053A`) | Giao thức feature-report của Razer; giao thức riêng cho BlackShark (V3 / V3 Pro / V3 X được hỏi mỗi 5 phút); Barracuda X: truy vấn pin Airoha và trạng thái cáp qua đầu thu |
| **SteelSeries** | Arctis 1/7/7+/9/Pro/Pro Wireless, Arctis Nova 3P/5/7/7X/7P/Pro Wireless (gồm `1038:225D`), Arctis Nova Elite (trạm đế `1038:2244`), GameBuds; Aerox 3/5/9 Wireless (Aerox 5 Diablo IV `1038:1860`, chưa thử), Aerox 3 Wireless CS2 Dragon Lore Edition (đầu thu `1038:1878`, cáp `187A`), Aerox 3 Wireless Gen 2 (đầu thu `1038:1890`, cáp `1892`), Prime Wireless, Rival 3 Wireless (Gen 2), Rival 650, Rival Pro | Báo cáo HID của hãng; Aerox/Prime và Rival 650 dùng chung một mục giữa đầu thu và cáp USB, ưu tiên giá trị qua cáp nếu cả hai đều trả lời |
| **Corsair** | Tai nghe không dây Void / Void Pro / Void Elite / HS70 / HS80; thiết bị Bragi (Virtuoso, Void V2, HS80 MAX, chuột và bàn phím Slipstream, bao gồm đầu thu Slipstream mới hơn `1B1C:2B00` như Scimitar Elite SE Wireless và Dark Core RGB Pro SE); Sabre V2 Pro Ultralight Wireless (`1B1C:2B2A`), Sabre v2 PRO WIRELESS MG (`1B1C:2B34`, chưa thử) | Báo cáo HID của hãng, lệnh Bragi `GET` (chỉ đọc), giao thức pin 17 byte của Compx (chỉ đọc) |
| **Cooler Master** | MM712, MM731 (dongle 2.4 GHz hoặc cáp USB) | Báo cáo trạng thái HID của hãng (chỉ đọc) |
| **Press Play** | ICARUS V2 Nearlink trên đầu thu 2.4 GHz `7768:6434` (driver đã thử trên phần cứng thật ở mức 90%; gói giao thức ghi nhận ở 100% và 90%) | Output report chỉ đọc `06 05` trên `FFB2:0001`; phần trăm pin nằm ở byte 14 của phản hồi |
| **HyperX** | Cloud III Wireless, Cloud III S Wireless, Cloud II Wireless (HP, Kingston, DTS), Cloud II Core Wireless, Cloud Alpha Wireless, Cloud Alpha 2 Wireless, Cloud Flight (`03F0:0C8C` bản PS, chưa thử), Cloud Flight S, Cloud Stinger Core Wireless (bao gồm bản DTS `03F0:0A8E`, đã thử), Cloud Core Wireless DTS, Pulsefire Haste 2 Core Wireless (dongle 2.4 GHz), Pulsefire Haste 2 Wireless, Pulsefire Haste 2 Mini (dongle 2.4 GHz `03F0:0F98` đã thử; `0D97` chưa thử) | Báo cáo HID của hãng (Haste 2: [ghi chú giao thức](#sec-hyperx-haste-2)) |
| **Glorious** | Model O / O- / D / D- Wireless, Model O 2 / D 2 PRO | Feature report của hãng |
| **Hitscan** | Hyperlight X, Hyperlight N | Feature report của hãng (cùng giao thức với Glorious) |
| **Kysona / Pulsar / ATK (VXE) / Hitscan** | Chuột không dây Kysona M600 / Mercury, Pulsar và ATK VXE (ví dụ VXE X3 Pro, VXE Dragonfly R1 / R1 Pro Max / R1 SE+, ATK F1 Extreme), Hitscan Hyperlight, Chimera V2 (đầu thu 3554:F512) | Giao thức hãng dùng chung có phản hồi kiểm tra checksum |
| **Pulsar X2 V3** | X2 V3 trên dongle 1K (`3710:5402`) hoặc cáp USB (`3710:3402`); X2 V3 eS trên dongle 8K (`3710:5403`) hoặc cáp USB (`3710:3406`) | Feature report hãng 64 byte, thanh ghi pin `08 81 01` (chỉ đọc) |
| **ATK / VXE NK** | VXE R1 NK và các chuột NearLink khác trên dongle NK mouse NANO (`373B:1216`) | Output report 08 của ATK BITMOUSE trên `FF05:0001` (pin và đang sạc) |
| **ATK 8K Nano** | Chuột ATK / VXE trên ATK 8K Nano Dongle (`373B:1178`) | Feature report Holtek GetConfigData (`82`) trên `FF10:0001` (từ ATK HUB; pin và đang sạc) |
| **Tai nghe ATK** | ATK N9 Pro, N9 Ultra (thế hệ đầu) | Giao thức cổng COM ảo (phải đóng ứng dụng desktop của ATK) |
| **G-Wolves** | Fenrir, Fenrir Pro / Max / Asym, HTX, HTS, HSK, HTR, HT-S2, Lycan, WARG, VUK và các dongle 8K đi kèm | Giao thức Glorious hoặc Kysona tùy mẫu máy |
| **Chuột Keychron** | M4 và các chuột Keychron khác trên đầu thu 2.4 GHz; chuột 4K (M4 4K, M3 4K, M3 mini 4K, M6 4K ...) trên đầu thu Keychron 4K Link (`3434:D038`); chuột 8K (M5 8K, G6 HE 8K ...) trên đầu thu TurboLink 8K; chuột 8K trên đầu thu Ultra-Link 8K (`3434:D028`); chuột đời cũ (M1, M2, M3, M3 mini, M6, M7 ...) trên đầu thu 1K (`3434:D030` / `D031`); trackball Nape Pro trên đầu thu Link-KM hoặc cáp | Báo cáo hãng từ Keychron Launcher (đầu thu 1K: feature report 51 06 như ứng dụng Keychron dùng; Ultra-Link 8K: báo cáo B5 03 / B3 06 trên `FFC1`; Nape Pro: HID thô A7 31) |
| **Bàn phím Keychron** | K5 Max (`3434:0A50`, đã thử) trên đầu thu Keychron Link (`3434:D030`) hoặc cáp USB; các bàn phím không dây Keychron QMK khác nếu được biên dịch cùng bản vá tương tự | Raw HID trên `FF60:0061`: `B2` hỏi đầu thu bàn phím nào đang liên kết, `A4` trả về mức pin, điện áp và trạng thái sạc. **Cần firmware bàn phím đã vá:** xem [docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware). Firmware gốc chỉ báo pin qua Bluetooth |
| **CHERRY** | Bàn phím MX 3.0S Wireless trên dongle 2.4 GHz (`046A:00EA`, đã thử) hoặc cáp USB (`046A:00E3`, đã thử) | Truy vấn HID hãng `1A` trên `FF1C:0092` (chỉ đọc), kèm trạng thái cấp nguồn USB. Bluetooth được hỗ trợ qua mục Bluetooth |
| **CHERRY** | Chuột không dây Cherry XTRFY trên đầu thu 1K (`046A:0330`, đã thử) | Giao thức pin 17 byte CompX (`08 03` trạng thái kết nối, `08 04` GetPower), cùng cấu trúc khung với Corsair Sabre V2 Pro (chỉ đọc) |
| **Arbiter Studio** | Akitsu (đầu thu 8K `373E:000A`, cáp `373E:0009`), Akitsu 3950 (đầu thu 8K `373E:0039`, cáp `373E:0038`), Akitsu Medium (đầu thu 8K `373E:0067` và cáp `373E:0066`, cả hai đã thử) | Feature report hãng chỉ đọc `0x83` trên `FFFF:0000` từ Arbiter Web HUB (pin và đang sạc) |
| **LAMZU** | Maya X, Maya, Maya M, Tachi, Inca, Paro, Thorn, Atlantis Mini / OG Champion, Orcus (cáp, dongle 1K và 4K/8K) | Feature report hãng từ LAMZU Aurora |
| **Endgame Gear** | OP1w 4k (v1 / v2), XM2w 4k (v1 / v2) trên dongle 4K; XM2we trên đầu thu gốc (`3367:1961`) | Feature report hãng `A1`, lệnh pin `B4` (chỉ đọc) |
| **Bàn phím ATK / VGN / Evision** | ATK V75X và bàn phím VGN / VXE (S99, V98 Pro / V98 Pro V2, N75 Pro, VXE75 / VXE75 V2, VXE V87) trên đầu thu 2.4 GHz dùng chung (`320F:5088`) hoặc cáp USB (`320F:5055`), nhận diện theo tên sản phẩm; các bàn phím có đầu thu `320F:5088` mang tên "Wireless Gaming Keyboard", ví dụ Feker Alice80 (đã thử) | Output report Evision `04`, lệnh pin `1A` (từ ATK HUB và VGN HUB); qua đầu thu hỏi tối đa mỗi 10 phút |
| **Redragon (Evision)** | K1NG M999 (đã thử) trên đầu thu 2.4 GHz `320F:226F`; ID đầu thu này có thể dùng chung trên các mẫu khác | Cùng giao thức Evision như bàn phím ATK (báo cáo `04`, lệnh `1A` trên `FF1C:0092`), hỏi ở mỗi lần cập nhật; hiển thị đang sạc trên đế sạc nam châm; khi cắm cáp USB, đầu thu cứ lặp lại mức pin cũ và không báo trạng thái sạc |
| **Audeze** | Maxwell trên dongle USB (`3329:4B19`) hoặc cáp USB-C (`3329:4B1A`); Maxwell 2 trên dongle USB (`3329:4B29`, đã thử); ID bản Xbox chưa thử | Báo cáo hãng `06` / input report `07`, thuộc tính pin `0CD6` (truy vấn đơn chỉ đọc) |
| **ENDORFY** | Viro Wireless trên dongle 2.4 GHz (`3738:0072`, chưa thử) | Lệnh Airoha RACE "get battery" (`0CD6`) trên báo cáo hãng `06` / input report `07`, cùng truy vấn chỉ đọc như dongle Audeze và Skullcandy; không có trạng thái sạc |
| **Turtle Beach** | Stealth 700 Gen 3 trên bộ phát USB (`10F5:2251`, đã thử trong HaloBattery; bản PC `10F5:2262`, chưa thử) hoặc cáp USB riêng của tai nghe (`10F5:2253`) | RACE `0x9942` (bật client CoAP) và lệnh CoAP `GET /GSI` đóng gói qua RACE `0x9902` giống Swarm II; mức pin lấy từ khóa `240` (không có cờ đang sạc) |
| **AKG** | N9 Hybrid trên dongle USB (`0ECB:20D9`, đã thử) | Airoha RACE trên `FF13:0001`: output report `06`, input report `07`, thuộc tính pin `0CD6` (truy vấn đơn chỉ đọc) |
| **NZXT** | Lift Elite Wireless trên dongle (`1E71:2101`) hoặc cáp USB (`1E71:2129`) | Lệnh đọc hãng `4E 02 81 .. B0` (từ bản bắt gói tin của NZXT CAM) |
| **Poly / Plantronics** | Voyager 8200 UC và các tai nghe khác qua bộ chuyển đổi BT600 (`047F:02EE` / `02F7`) | Giao thức get/set báo cáo `07`, mục pin `0A 1A` (chỉ đọc) |
| **WLMouse** | YING Magnesium (đầu thu YING 8K `36A7:A874`); Beast X 8K, Beast X Mini / Mini Pro, Beast X Pro, Beast MAX, Sword X 8K (đầu thu hoặc cáp; không hỗ trợ Beast X 4K); Beast X V2 (đầu thu 8K `36A7:A856`); Beast G (đầu thu 8K `36A7:A860` hoặc cáp `36A7:A861`; chưa thử) | Feature report hãng, lệnh trạng thái `0x83` (YING: cùng giao thức với Glorious) |
| **Finalmouse** | UltralightX trên dongle 2.4 GHz (`361D:0100`, đã thử); Starlight X trên dongle (`361D:0300` / `0301`, đã thử). Không hỗ trợ qua dây cáp riêng của chuột | Báo cáo hãng xpanel trên `FF00`: các lệnh GET chỉ đọc, rồi *wake/all* (`0xE0`); điện áp pin theo đường cong của xpanel hoặc phần trăm riêng của Starlight X, kèm trạng thái sạc |
| **VAXEE** | Chuột không dây trên đầu thu VAXEE 4K (`3057:1002`) hoặc 8K (`3057:2002`, ví dụ NP-01 Ergo Wireless 8K); ZYGEN NP-01S V2 Wireless qua cáp USB (`3057:1011`) | Feature report hãng chỉ đọc `0E` trên `FF05:0001`; mức pin theo bước 5%, có trạng thái sạc ([ghi chú giao thức](#sec-vaxee)) |
| **Scyrox** | V12M trên đầu thu 2.4 GHz (`395A:0006`) | Đọc cấu hình S-Center 2.0 (output report `08`, lệnh `01`) trên `FF00:0002`; chỉ có pin, không có trạng thái sạc |
| **HECATE** | G5M PRO và các chuột HECATE khác trên cùng đầu thu, cùng cáp USB `35BB:D3FA / D3FC / D3FD` | Giao thức Kysona |
| **Redragon** | Chuột không dây dùng nền tảng Compx: M916 Pro 1K (đã thử), M913 Impact Elite (tri-mode), G49 (đầu thu hoặc cáp) | Giao thức Kysona (các đầu thu Areson `25A7` được liệt kê riêng ở mục Areson) |
| **Taidu (钛度)** | TSG808 trên đầu thu 2.4 GHz Compx `3554:F5D5` (đã thử) | Giao thức Kysona |
| **Areson (Redragon)** | M915RGB-WL (đã thử), M913 Impact Elite bản đầu và các chuột khác trên đầu thu `25A7:FA07` / `FA08` | Feature report `GetPower` 17 byte; mức pin theo bước 10% và cờ đang sạc |
| **Ninjutso** | Sora V2 trên đầu thu 1K (`1915:AE1C`, đã thử) hoặc cáp USB (`1915:AE11`, đã thử); Ten Air (đầu thu `093A:EB01` và cáp USB `093A:E020`, đã thử) / Ten (`093A:EB01` / `E020`, chưa thử) | Feature report NinjaForce `0x05` (`0x15` cho Sora V2) và `0x06` (`0x13`/`0x12`/`0x11` cho Ten / Ten Air) |
| **Sprime** | PM1 trên đầu thu 2.4 GHz (`1915:AC1C`, đã thử; `1915:AD8C`) hoặc cáp USB | Cùng feature report 0x05, lệnh trạng thái 0x15 từ web driver của Sprime (sprime.pro) |
| **RAWM / SADES** | Leviathan V4 trên đầu thu RAWM HS (`1915:2346`, đã thử); ES21 / ES21 Pro / ES21M, ER21 / ER21 Pro / ER21M, ES11, G11 / G11 Plus / G11 Pro, dòng SA-* và chuột SADES Dagger trên đầu thu RAWM (`1915:232A`–`234B`) hoặc cáp USB | Truy vấn thông tin thiết bị RAWM HUB 2.0 qua đầu thu (JSON chứa % pin và trạng thái sạc), chỉ đọc ([ghi chú giao thức](#sec-rawm)) |
| **AULA** | Bàn phím không dây F75 / F87 Pro / F99 trên đầu thu 2.4 GHz | Khung báo cáo 0x13, lệnh 0x4A, checksum tổng (chế độ Bluetooth và có dây chưa thử) |
| **Chuột AULA** | X9 Ultra (đã thử) trên AULA-8K Dongle `320F:22A0`; ID đầu thu dùng chung với các mẫu V9 | Báo cáo `04`, lệnh pin chỉ đọc `1A` kẹp giữa START `01` / END `02` trên `FF1C:0092`; chỉ hỗ trợ 2.4 GHz |
| **Bàn phím SONiX (AJAZZ / AULA / EPOMAKER)** | AJAZZ AK820 MAX (đã thử), EPOMAKER EA75 (đã thử), AULA F108 Pro trên dongle 2.4G `05AC:024F`; AJAZZ AK980 V2 trên dongle `0C45:FEFE`; AJAZZ AK820 Pro trên dongle `0C45:FDFD` hoặc `0C45:FEFE`; EPOMAKER P75 trên `342D:E479` (chưa thử phần cứng thật) | Báo cáo hãng `20 01` trên usage page FF60, checksum tổng (chỉ chế độ 2.4G; không có báo trạng thái sạc) |
| **Các đầu thu SONiX bổ sung (chưa thử phần cứng thật)** | RK Royal Kludge R75 (`342D:E485`); Redragon Arlokks K742B (`342D:E4BC`); M1 V5 VIA (`342D:E4C2`); Lucky65V2 (`342D:E407`); Lofree Flow2 (`388D:0003`); MSI FORGE TKL W FRIEREN EDITION (`0DB0:0CA0`); Essential75 (`36B0:30BD`); NUT65 (`342D:E51A`); RK 2.4G Dongle (`342D:E487`); WEIKAV MAX102 (`342D:E537`); Lofree Flow2 (`388D:0002`); NuPhy Air75V2 (`19F5:3245`); SKN Qinglong (`362D:D028`); Lemokey Link (`362D:D030`); Wireless Link (`362D:D101`); Spade65-QMK-2.4GHz (`342D:E49F`) | Cùng truy vấn chỉ đọc pin `20 01`; yêu cầu khớp chính xác VID:PID và tập `FF60:0061` với báo cáo 33 byte; chỉ 2.4G, không có báo sạc |
| **Bàn phím 36B0 (PMO / WOBKEY / URX / EVO80)** | PMO (WOBKEY) Wave 75 RGB trên dongle 2.4G `36B0:3002` hoặc cáp USB `36B0:3009` (giao thức đã được người báo lỗi #343 thử trên cả hai); Aurora 80 (`3004`), PMO P75 (`302B`), PMO 80 (`3012`) trên cùng dongle hoặc cáp (chưa thử); URX Core75 trên dongle (đã xác nhận trong HaloBattery); EVO80 (chưa thử) | Firmware PMO Hub: `START_COMM` / `GET_BATTERY` (`AA 30`) / `STOP_COMM` trên usage page FF60, từ pmohub.cn. Firmware URX / VIA: VIA custom-get `08 00 07` (kênh 0, giá trị 7), từ URX HUB qua HaloBattery. Không có báo sạc |
| **DAREU** | EM901X trên đầu thu 2.4 GHz `260D:1074` hoặc cáp USB `260D:1090` (đã thử đọc pin trên cả hai; đã thử chuyển đổi cờ sạc khi đặt/nhấc khỏi dock của đầu thu) | Feature report chỉ đọc pin `08`, lệnh `04`; phản hồi `09` trên một tập vendor khác. Cần đúng một cặp input/feature rõ ràng theo mã sản phẩm. Ưu tiên giá trị USB hợp lệ khi cả hai cùng cắm; đầu thu có thể vẫn trả về dữ liệu cũ ngay cả khi đã tắt chuột |
| **DAREU** | Bàn phím A84 (`260D:0022`, chưa thử) | Feature report SONiX trên interface 0, lệnh `04 F6` (lệnh đọc pin của trình điều khiển A84 chính thức); mức pin theo phần trăm, không có cờ sạc |
| **DAREU** | A980 Pro trên đầu thu đa chuột `260D:1131` và trên cáp USB (`260D:1148`) (mức pin đã thử trên phần cứng thật; cờ sạc đã xác nhận khi cắm dây) | Giao thức Togran: feature report 65 byte `0A` trên tập consumer-control; hỏi slot (lớp 0 / `A0`) rồi hỏi pin (lớp 7 / `80`), trên slot 0 khi qua cáp. Chỉ đọc |
| **Sharkoon** | Skiller SGM50W trên `260D:1125` (chưa thử) | Cùng truy vấn Compx như DAREU EM901X (feature report `08`, lệnh `04`; phản hồi `09` trên `FF01:0000`); công cụ cập nhật firmware của Sharkoon cho mẫu này là công cụ Compx trên VID `260D` |
| **Zenith** | Zenith Pro trên đầu thu 2.4 GHz `260D:1114` (đã thử đọc pin; phần sạc chưa thử) hoặc cáp USB `260D:1143` (chưa thử) | Cùng lệnh Compx (`08`, `04`) dưới dạng output report trên `FF02:0002`; phản hồi `08 04` trên cùng tập kèm phần trăm, cờ sạc và mili-vôn, kiểm tra bằng tổng byte `0x55` |
| **AJAZZ AK992** | Đầu thu 2.4 GHz Telink `320F:50C3` (đã thử) | Truy vấn pin EVision trên tập HID `FF1C:0092` |
| **ZOWIE** | EC1/EC2/EC3-CW, dòng DW (U2-DW, S2-DW ...) và U2 trên đầu thu 2.4 GHz đi kèm | Lệnh hãng chỉ đọc do cộng đồng ghi nhận |
| **Royal Kludge (RK)** | MG6 Pro trên dongle 2.4 GHz (`2E3C:00A6` / `00E6`) hoặc cáp USB (`2E3C:00A5` / `00E5`) | Khung QiWang 64 byte từ web driver của RK, lệnh đọc `GET_BATTER_VOL` (phần trăm, điện áp, đang sạc) |
| **ASUS ROG** | Bàn phím Strix Scope II 96 (RX), Azoth, Falchion; chuột Keris, Harpe, Gladius, Chakram, Spatha, Pugio, Strix Impact; tai nghe Pelta (dongle 2.4 GHz); tai nghe nhét tai Cetra Open Wireless (dongle SpeedNova `0B05:1CAC`, trái / phải / hộp); đầu thu Omni Receiver | Truy vấn pin ROG HID |
| **Machenike** | L7 Arctic / L7 Mix trên đầu thu 2.4 GHz `248A:FF4C` hoặc cáp USB `248A:FF4E` (cả hai đã thử) | Feature report chỉ đọc `51`, lệnh trạng thái `06`; pin và đang sạc. [Ghi chú giao thức](#sec-machenike) |
| **MSI** | VERSA 300 ELITE WIRELESS trên dongle 2.4 GHz (`0DB0:9E22`); CLUTCH GM31 Lightweight Wireless (đầu thu 2.4 GHz `0DB0:0D3C` đã thử; cáp USB `0DB0:0D3B`) và CLUTCH GM41 Lightweight Wireless (đầu thu `0DB0:0D4C` / cáp `0DB0:0D4B`, từ bản bắt gói tin của chủ sở hữu) | Truy vấn hãng chỉ đọc `0F 20` trên `FF0D:00B0` và `FF00:0001`; pin và cờ sạc nằm chung trong một byte (giao thức từ mô-đun Gaming Gear của MSI Center); GM41: báo cáo thụ động `A0 xx 07 …` trên `FF10:0006` |
| **MCHOSE** | Chuột L7 / L7 Pro / L7 Ultra (đã thử L7 Ultra), M7 / M7 Ultra, A7 / A7 Ultra, K7 trên đầu thu 2.4 GHz hoặc cáp USB; A5 V2 Ultra (đầu thu 2.4 GHz `3837:100C`, đã thử), K7 Ultra (đầu thu 2.4 GHz `3837:1001`, đã thử; A7 V2 Ultra+ `3837:100B` dự kiến chạy được, issue 227); G3 V2 (đầu thu 2.4 GHz `3837:4245` và cáp USB `3837:418C`); K7 V2 Ultra+ trên đầu thu 2.4 GHz `3837:1014` hoặc cáp USB `3837:4028` (cả hai đã thử; các ID đầu thu thế hệ mới khác `1018`, `1016`, `102C`, `102D` chưa thử) | Feature report hãng, payload đảo bit (giao thức từ alexfrih/mchose-linux); dongle Realtek `3837` trả lời cùng truy vấn với trường vid đặt là `41E4` (A5 V2 Ultra) hoặc `3837` (K7 Ultra); G3 V2: truy vấn hãng chỉ đọc trên `FF01:0010`; K7 V2 Ultra+: báo cáo 64 byte `0x4D`, lệnh thông tin thiết bị `0x0900` trên `FF01:0001` (giao thức từ web driver của M HUB) |
| **MCHOSE A5 (thế hệ đầu)** | A5 Pro / A5 Pro Max trên đầu thu 2.4 GHz 1K hoặc 4K (`2023:F013`, `2023:F015`, `2023:F018`) hoặc cáp USB (`2023:F017` A5 Pro, `2023:F019` A5 Pro Max); chưa thử trên máy thực tế tại đây | Lệnh pin chỉ đọc `0x83` (trang 0) trong feature report 64 byte trên `FFFF`, phản hồi đánh dấu `0xA1` (giao thức từ web driver A5 Pro Max của z750sasr và HaloBattery, danh sách ID từ Klegus/mchose-macos) |
| **Tai nghe MCHOSE** | V9 Pro 2 trên dongle 2.4 GHz (`3837:6011`, đã thử) | Khung pin "MC" chỉ đọc của M HUB (báo cáo `0x55`, lệnh phụ `0x0B`) trên `FF07:0222`; mức pin và cờ sạc nằm trong một byte (giao thức từ web driver của M HUB) |
| **Bàn phím AULA / MCHOSE / Redragon** | AULA F75 / F87 Pro / F99; MCHOSE K99 V2, G75 Pro, X75 và các bàn phím M HUB khác; Redragon Horus Pro / Pro V2 (K618RGB-PRO) trên đầu thu 2.4 GHz (`3554:FA09`, `41E4:2001`); MCHOSE K87 trên đầu thu `05AC:024F` (bố cục BY ở interface 1, không phải loại SONiX) | Khung báo cáo 0x13, lệnh 0x4A (mẫu MCHOSE và Redragon được phân biệt bằng lệnh 0x05 như trong M HUB); không hỗ trợ chế độ Bluetooth và có dây |
| **Bàn phím MCHOSE** | G75 V2 trên đầu thu 2.4 GHz `3837:3033` (đã thử); cùng đầu thu đi kèm G87 V2 và K99 V3 (cùng giao thức, chưa thử); K87S dùng cùng ID đầu thu nhưng giao thức khác nên không được hỗ trợ | Truy vấn func-config "GLW" chỉ đọc của M HUB trên tập không ID 64 byte `0001:0000`: cờ yêu cầu `0x55`, lệnh `0x05`, pin nằm ở byte 32 của payload (bit 7 = đang sạc), checksum cộng |
| **AULA SC580** | Chuột SC580 / SC580X qua cáp USB (`088D:062E`, đã thử) hoặc đầu thu 2.4 GHz (`089D:062F`, đã thử) | Lệnh chỉ đọc `0x30` (thông tin thiết bị) trên tập vendor 33 byte `FF02:0000`, checksum tổng; khi đang sạc chuột luôn báo cố định 100 nên ứng dụng giữ hiển thị mức trước đó; không hỗ trợ chế độ Bluetooth |
| **AULA HERO 68 Air** | HERO 68 Air trên đầu thu 8K Wireless Receiver (`372E:106C`) | Các khung 20 byte có xác nhận trên usage page FF60 (bốn khung dữ liệu và một khung kết thúc cho mỗi bản tin), lệnh pin chỉ đọc 0x87, cờ sạc 0x10 sau mức pin; không hỗ trợ chế độ Bluetooth và có dây |
| **EWEADN (前行者)** | S7 Max / Pro / Ultra và S9 Max / Pro / Ultra / Ultra+ trên đầu thu "Gaming 2.4G" (`372E:103D`); S9 Ultra trên cáp USB (`372E:1027`) | Feature report chỉ đọc `03` trên `FF00:0001`: kiểm tra liên kết `47`, thông tin cơ bản `4F 81` (phần trăm pin và bit sạc), từ web driver của EWEADN |
| **Rapoo VT** | VT3 Max Gen 2 (đã thử); VT9 Gen 2 (đã thử); các chuột VT dùng chip Nordic 54L khác có cùng giao diện trạng thái; VT3 Pro đời cũ (thử nghiệm); VT1 Pro Max (từ bản bắt gói tin USB của chủ sở hữu) | Báo cáo trạng thái HID thụ động `07` trên `FF00:0002` (16 hoặc 19 byte; 13 byte trên một số đầu thu VT3 Max Gen 2); định dạng `BB` đời cũ chỉ giới hạn cho VT3 Pro `1215/4415` và VT1 Pro Max `1233/4433`. Hỗ trợ đầu thu và cáp USB, kèm trạng thái sạc |
| **Motospeed / Delux / Ajazz** | Motospeed X6, Delux M900 Pro (mẫu Xenta 30/50; đời cũ 3D), Delux M800 Pro, dòng Ajazz AJ179; AJ159 và các chuột dòng AJ khác trên đầu thu 3151; AJ139 V2 MC (đầu thu `A8A5:2255`, cáp `A8A4:2255`) | Báo cáo của hãng (M900 Pro: gói trạng thái phát thụ động hoặc truy vấn feature, sự kiện Xenta 40/41; dòng AJ: hỏi trạng thái 0xF7 rồi feature report 0x05) |
| **Incott** | G23 V2 / G24 (đầu thu `093A:522C`, cáp `093A:622C`) | Feature report trạng thái chỉ đọc 09 |
| **Attack Shark và các hãng Trung Quốc khác** | Đầu thu Rongyuan (81 mẫu: Attack Shark R3 và AJAZZ AJ179 Pro trên `3151:402D`, K86, X82 PRO HE, bàn phím Ajazz, một số mẫu MSI và hãng khác; K86 qua Bluetooth hiển thị dưới dạng bàn phím); đầu thu Xenta (Attack Shark X6 / R1, X11, X3 Max, V3 Pro, V6; bản X6 cũng có trên `1D57:FA61`, chưa thử); bàn phím Semico 1A2C (Attack Shark X98 trên dongle `1A2C:8FFF` đã thử và cáp `1A2C:A034`; AJAZZ AK820 Max Plus trên `1A2C:8FFF` / `1A2C:A036`) | Báo cáo trạng thái Rongyuan; gói phát thụ động Xenta; truy vấn trạng thái chỉ đọc Semico `0x0E` (`AA 55 CC 33` trên `FF02:0002`; bỏ qua cờ sạc vì X98 luôn báo `state=1` cả khi dùng pin lẫn khi đang sạc) |
| **Wraith** | W1 / W1 Freestyle (đầu thu `093A:522C`, cáp `093A:622C`; trùng ID với Incott, phân biệt bằng mã mẫu) | Đọc từng nút chỉ đọc `86` (feature report 09) qua toàn bộ các nút, sau đó đọc input report trạng thái 09 được đẩy lên |
| **Fantech** | Helios Go XD5 (có dây `25A7:FA7B`, dongle `25A7:FA7C`); Raigor III (đã thử), Raigor II WG10 và các thiết bị 2.4G Mouse phổ thông khác dùng chung dongle `1EA7:0066` / `1EA7:0064` | Helios Go XD5: feature report hãng `08`, lệnh `04`, checksum cộng bằng `0x55`. Raigor/2.4G Mouse: truy vấn trang trạng thái chỉ đọc `B5` trên `FFB5:0001`, phần `94` = phần trăm báo gần nhất (có thể giữ giá trị cũ khi ngủ, tắt hoặc đang sạc; không có trạng thái sạc) |
| **Sony** | DualShock 4, DualSense, DualSense Edge (USB, Bluetooth, bộ thu không dây); tai nghe INZONE H9 II và H5; tai nghe nhét tai INZONE Buds (dongle USB-C) | Input report; giao thức riêng của INZONE |
| **Fractal Design** | Tai nghe Scape trên dongle 2.4 GHz hoặc cáp USB-C | Truy vấn hãng `GET_DEVICE_STATE` từ ứng dụng web Adjust Pro của Fractal (usage page FF00) |
| **Jabra** | Mọi tai nghe Jabra hỗ trợ GN Protocol (Evolve2 / Evolve3 và các dòng khác), qua cáp USB riêng hoặc qua dongle Jabra Link; không dùng danh sách product ID cứng, loại trừ các đế DECT (Engage, PRO 9xx, GO 6400, Link 400); đọc tên trực tiếp từ tai nghe | Truy vấn trạng thái GNP (lớp 12 / op 02) trên usage page FF00, usage 05 hoặc 01, tại địa chỉ GNP 08 (USB) hoặc 04 (dongle) |
| **Flydigi** | Vader 5 Pro / 黑武士 5 Pro (`37D7:2401`), đầu thu 2.4 GHz hoặc USB; Apex 5 (`37D7:2501`), đầu thu 2.4 GHz hoặc USB | Truy vấn thông tin HID hãng trên `FFA0:0001`; mức pin 0–5 ánh xạ sang 0–100% theo bước 20%, kèm trạng thái sạc; không cần dịch vụ Space Station |
| **GameSir** | Nova Lite, Nova 2, Nova 2 Lite trên đầu thu 2.4 GHz; Nova 2 Lite qua USB; G7 Pro (đã thử: bản Zenless Zone Zero, đầu thu `3537:105E`) và các tay cầm GameSir khác ở chế độ Xbox (GIP); Cyclone 2 (chế độ XInput, đầu thu hoặc cáp); Cyclone Pro trên dongle 2.4 GHz (`3537:1015`, ghép nối tay cầm với Windows qua Bluetooth một lần) | Truy vấn thông tin thiết bị hãng (usage page FF7A); báo cáo pin `Windows.Gaming.Input` (% thật) ở chế độ Xbox; Cyclone 2: yêu cầu pin hãng (usage page FFF0); Cyclone Pro: yêu cầu base-info của ứng dụng GameSir qua Bluetooth LE (dịch vụ `0x8650`), đọc mỗi 2 phút |
| **BEITONG** | KP20 / BTP-KP20 trên đầu thu 2.4 GHz (`20BC:5128`, chế độ XInput, đã thử) và KP40D / BTP-KP40D trên đầu thu (`20BC:515C`, chế độ XInput); không cần BEITONG iControl | Truy vấn hãng "get base info" trên usage page `00FF` (báo cáo `02`, payload tráo nibble), kèm trạng thái sạc |
| **8BitDo** | Ultimate 2 Wireless (X-input `2DC8:310B` đã thử trên dongle 2.4 GHz, D-input `2DC8:6012` — giữ nút B khi bật nguồn, firmware 1.03+), Ultimate 2C Wireless, Ultimate 3-mode, Ultimate 2.4G, Ultimate Bluetooth, Pro 3, Pro 2, SN30 Pro, SF30 Pro | Truy vấn trạng thái HID hãng (`FF7A`/`FFA0`) và input report tay cầm SDL `01`/`04`, kèm trạng thái sạc |
| **Samsung** | Galaxy Buds, Buds+, Buds Live, Buds Pro, Buds2, Buds2 Pro, Buds FE, Buds Core, Buds3 / Buds3 Pro / Buds3 FE (Bluetooth) | Khung trạng thái do tai nghe tự đẩy qua dịch vụ RFCOMM (SPP) của Samsung, chỉ đọc. Khay hệ thống hiển thị tai bên thấp pin hơn; chú giải liệt kê tai trái, tai phải và hộp sạc. Phải đóng ứng dụng Galaxy Buds |
| **Nothing / CMF** | Nothing Ear (3a) (đã thử), Ear (a), Ear (2), Ear, CMF Buds (Bluetooth) | Truy vấn pin chỉ đọc `0xC007` trên dịch vụ NT Link RFCOMM của Nothing (`aeac4a03-dff5-498f-843a-34487cf133eb`). Khay hệ thống hiển thị tai bên thấp pin hơn; chú giải liệt kê tai trái, tai phải và hộp sạc |
| **Akko** | Akko Air 01 (`3151:5006`, đầu thu 2.4 GHz, đã thử) và Akko V9 Dash Pro (`38EE:000C`, đầu thu 2.4 GHz, đã thử) | Air 01: báo cáo trạng thái Rongyuan `0xF7`; V9 Dash Pro: truy vấn trạng thái 64 byte chỉ đọc `0x1A` trên `FF1C:0092` kèm trạng thái sạc |
| **MOONDROP** | Tai nghe GM01 Pro trên dongle 2.4 GHz (`35D8:0133`); khi cắm cáp USB hiển thị đang sạc kèm mức pin gần nhất | Lệnh đọc hãng WalkPlay trên báo cáo `4B` (chỉ đọc) |
| **VGN** | Tai nghe OMNISOUND (ZHOUTING) trên dongle 2.4 GHz (`372E:10BB`, đã thử) | Truy vấn "ZHOU" của V HUB: output report `55` với payload `65 01` trên tập điều khiển `000C:0001` (input 32 byte, output 64 byte); phần trăm pin trả về trong phản hồi (chỉ đọc) |
| **JBL** | Quantum 650 Wireless (đã thử, dongle 2.4 GHz); Quantum 520, 650X, 850, 950, 950X Wireless (dongle hoặc cáp USB, cùng giao thức, chưa thử) | Truy vấn thông tin thiết bị JBL "HIDV3" cho tính năng pin (usage page FF12), kèm trạng thái sạc |
| **JBL** | Quantum 350 Wireless (đã thử trên Windows với đầu thu 2.4 GHz `0ECB:206B`); Quantum 610 Wireless (dongle 2.4 GHz `0ECB:205C`, chưa thử trên Windows); Quantum 360 Wireless (dongle 2.4 GHz `0ECB:2115`, chưa thử) | Feature report HIDV1 cho kết nối không dây và phần trăm pin |
| **Xbox** | Tay cầm qua bộ chuyển đổi không dây Xbox, USB hoặc Bluetooth; tai nghe cắm vào tay cầm | Báo cáo pin `Windows.Gaming.Input` (% thật), dự phòng qua XInput |
| **Tương thích Switch Pro** | Tay cầm khai báo ID `057E:2009` (đã thử: GameSir Tarantula Pro qua đầu thu 2.4 GHz ở chế độ Switch) | 5 mức pin từ báo cáo HID `0x30` sau khi Steam Input hoặc host khác bật chế độ báo cáo đầy đủ |
| **Apple AirPods / Beats** | AirPods Max (đã thử, `200A` Lightning và `201F` USB-C), AirPods Pro 3 (đã thử, `2027`), AirPods Pro 1 / 2, AirPods 1–5 và tai nghe chụp/nhét tai Beats | Gói quảng bá BLE "proximity pairing" (`0x07`) (một mức pin cho AirPods Max và tai nghe chụp tai Beats; tai trái, tai phải và hộp sạc cho tai nghe nhét tai theo bước 10% kèm trạng thái sạc), đối khớp với thiết bị đã ghép đôi |
| **Điện thoại (Phone Link)** | Bất kỳ điện thoại Android nào liên kết qua Microsoft Phone Link, qua Wi-Fi hoặc Bluetooth (đã thử: Nothing Phone (4a) Pro) | Pin và trạng thái sạc lấy từ thẻ Start Menu của Phone Link trên Windows 11 (`StartMenuCompanion.json`); không cần Bluetooth |
| **Darmoshark** | M3 (`248A:FF30`) và M3S (`248A:FF31`) trên đầu thu 2.4 GHz trên Windows | Feature report HID lấy danh tính chuột và pin |
| **Darmoshark** | M3S Pro trên đầu thu Nordic 1K (`1915:0723`) | Truy vấn trạng thái HID hãng trên tập `FF0A` |
| **Alienware** | Tai nghe AW920H trên dongle 2.4 GHz (`413C:A515`, đã thử); qua Bluetooth được xử lý ở mục Bluetooth | Truy vấn hãng `06 C0 0A` trên `FF13:0001`, báo cáo phản hồi `07` với checksum XOR; mức pin, đang sạc và mức pin tới hạn được giải mã theo plugin AW920H của Alienware Command Center |
| **Niceboy** | MW400 trên đầu thu 2.4 GHz (`248A:FA02`, đã thử) | Truy vấn báo cáo chỉ đọc `05` `24 FA 48`; điện áp pin ánh xạ sang bước 10% bằng bảng của ứng dụng hãng, kèm cờ đang sạc |
| **Bluetooth** | Mọi thiết bị hiển thị pin trong *Settings → Bluetooth & devices* (tai nghe nhét tai, tai nghe chụp, chuột và bàn phím BLE). Tai nghe hỗ trợ Google Fast Pair (đã thử Jabra Elite 8 Active; Pixel Buds và nhiều mẫu Sony / JBL / Bose) còn hiển thị mức pin trái, phải và hộp sạc | Thuộc tính thiết bị Windows; gói quảng bá pin Fast Pair (dữ liệu dịch vụ BLE `FE2C`), khớp theo địa chỉ Bluetooth của thiết bị đã ghép đôi |
| **HID chung (Generic HID)** | Các thiết bị báo cáo chuẩn HID *Battery Strength* | HID usage page 0x06 / 0x85 |
| **HeadsetControl** | [Mọi tai nghe mà công cụ này hỗ trợ](https://github.com/Sapd/HeadsetControl#supported-headsets) (Audeze, Jabra, Sony INZONE, Logitech đời mới và nhiều hãng khác) | Đóng gói sẵn; chạy lệnh `headsetcontrol -o json` |
| **MAONO PD200W** | Đầu thu 2.4 GHz (352F:040E) | Phần trăm pin; đã thử nghiệm trên phần cứng thật |


**Đã thử nghiệm trên phần cứng thật:** Glorious Model O Wireless, HyperX Cloud III Wireless, HyperX Cloud Stinger Core Wireless (đầu thu PlayStation `0951:1713`; chưa thử sạc), HyperX Cloud Core Wireless DTS (đầu thu `0951:173F`; chưa thử mức sạc đầy), HyperX Pulsefire Haste 2 Core Wireless (dongle `03F0:0AB5`; các dongle của Haste 2 Wireless chưa thử), Cooler Master MM712 (dongle), Rapoo VT3 Max Gen 2 (đầu thu `24AE:1417` và cáp USB `24AE:4617`; các mẫu Rapoo khác chưa thử, xem [ghi chú giao thức Rapoo](#sec-rapoo)), Redragon M916 Pro 1K (đầu thu `3554:F55D`), Taidu TSG808 (đầu thu `3554:F5D5`), Redragon M915RGB-WL (đầu thu `25A7:FA07`; các mẫu Areson khác chưa thử, xem [ghi chú giao thức Areson](#sec-areson)), SteelSeries Rival 650 Wireless (đầu thu `1038:1726` và cáp USB `1038:172B`), SteelSeries Arctis Nova Pro Wireless (trạm đế `1038:225D`; đã thử đọc pin, chưa thử sạc và chuyển trạng thái nguồn), HECATE G5M PRO (đầu thu `35BB:D3FB`), WLMouse YING Magnesium (đầu thu 8K `36A7:A874`), ATK N9 Ultra (đầu thu `373B:1204`), Corsair Scimitar Elite SE Wireless (đầu thu Slipstream `1B1C:2B00`), Corsair Dark Core RGB Pro SE (đầu thu Slipstream `1B1C:1BDC`), Corsair Sabre V2 Pro Ultralight (đầu thu 2.4 GHz `1B1C:2B2A`; đã kiểm chứng đọc pin), DAREU EM901X (đầu thu `260D:1074`; chưa thử sạc và ngủ/thức), Jabra Evolve3 75 trên Link 390 (`0B0E:2E51`), MCHOSE G3 V2 (đầu thu `3837:4245` và cáp USB `3837:418C`), MCHOSE K7 Ultra (đầu thu `3837:1001`), MCHOSE K7 V2 Ultra+ (đầu thu `3837:1014` và cáp USB `3837:4028`; hiển thị đang sạc khi cắm dây), MSI VERSA 300 ELITE WIRELESS (dongle `0DB0:9E22`; chưa thử sạc và xử lý ngủ), MSI Clutch GM31 Lightweight Wireless (đầu thu `0DB0:0D3C`; mẫu GM41 dùng chung driver từ bản bắt gói tin của chủ sở hữu), AJAZZ AK820 MAX (dongle `05AC:024F`), AULA HERO 68 Air (đầu thu không dây 8K `372E:106C`), AULA SC580 (cáp USB `088D:062E` và đầu thu `089D:062F`, bao gồm cả sạc và ngủ), AirPods Pro 3 (Bluetooth, mã `2027`), AirPods Max (Bluetooth, mã `200A`), Sprime PM1 (đầu thu `1915:AC1C`), Ninjutso Ten Air (đầu thu `093A:EB01` và cáp USB `093A:E020`), MOONDROP GM01 Pro (dongle `35D8:0133`), Delux M800 Pro (đầu thu `248A:5B2F`), Razer Barracuda X (2022) (đầu thu `1532:0550`; đã đọc mức pin, chưa thử chuyển đổi sạc), Razer BlackShark V3 X (dongle HyperSpeed `1532:057D`), Fantech Helios Go XD5 (dongle `25A7:FA7C`), Fantech Raigor III (dongle `1EA7:0066`; firmware không báo trạng thái sạc), Finalmouse UltralightX (dongle `361D:0100`), Finalmouse Starlight X (trên dongle), và Chimera V2 (đầu thu `3554:F512`; đã đọc mức pin và trạng thái sạc).
Cũng đã thử trên phần cứng thật: Machenike L7 Arctic / L7 Mix (đầu thu `248A:FF4C` và cáp `248A:FF4E`), bao gồm sạc và chống trùng lặp giữa cáp/đầu thu. Bluetooth và các ngưỡng pin cạn/sạc đầy chưa được thử trên phần cứng thật.
Cũng đã thử trên phần cứng thật: MCHOSE V9 Pro 2 (dongle `3837:6011`); đã đọc mức pin, chưa thử sạc và ngủ.
Cũng đã thử trên phần cứng thật: EPOMAKER EA75 trên đầu thu 2.4 GHz `05AC:024F`, sử dụng driver SONiX có sẵn từ [PR #60](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/pull/60). Đã kiểm chứng phần trăm pin, kết nối lại đầu thu và phục hồi khi bật nguồn. Driver này không hỗ trợ chỉ báo sạc và báo pin qua dây; báo pin qua Bluetooth chưa được thử. Phần trăm báo cáo có thể nhảy lên 100% khi cắm nguồn USB, đây không phải chỉ báo sạc đáng tin cậy.
Cũng đã thử trên phần cứng thật: SteelSeries Aerox 3 Wireless CS2 Dragon Lore Edition (đầu thu `1038:1878` và cáp USB `1038:187A`), bao gồm sạc, tắt công tắc (giữ mức cuối, làm mờ) và khi chạy song song với SteelSeries GG; GG chỉ hiện thanh 3 nấc và khớp với mức pin đọc được.
Cũng đã thử trên phần cứng thật: RAWM Leviathan V4 (đầu thu RAWM HS `1915:2346`; đã đọc mức pin, chưa thử sạc).
**Được triển khai từ tài liệu giao thức và các dự án khác, chưa thử trực tiếp:** tất cả các mẫu còn lại, bao gồm Fantech Raigor II WG10 (cùng dongle `1EA7:0066` và tập HID với Raigor III đã thử nên nhiều khả năng hoạt động). Nếu bạn sở hữu một trong các thiết bị này, hãy báo lại kết quả hoạt động bằng cách [mở một issue](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/issues).

## Cài đặt

[![Phiên bản mới nhất](https://img.shields.io/github/v/release/krisgfx9/Wireless-Device-Battery-Monitor?label=latest%20version&style=for-the-badge)](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest)

1. Tải **`BatteryHub-Setup-<version>.exe`** từ [bản phát hành mới nhất](https://github.com/krisgfx9/Wireless-Device-Battery-Monitor/releases/latest).
2. Chạy tệp cài đặt, chọn một trong 19 ngôn ngữ cài đặt được hỗ trợ và bấm tiếp qua các bước. Ứng dụng **không cần quyền quản trị viên** và **không cần cài thêm thành phần nào khác**: không cần runtime, không cần driver, không cần phần mềm hãng. HeadsetControl đã được đóng gói sẵn, và thư mục `lang\` có thể chỉnh sửa được cài ngay cạnh `BatteryHub.exe`.

Trình cài đặt thêm mục vào Start Menu cùng trình gỡ cài đặt (*Settings → Apps*), và có thể cấu hình tự khởi động ứng dụng khi bạn đăng nhập. Không muốn dùng trình cài đặt? Hãy tải `BatteryHub-<version>-portable.zip`, giải nén vào bất kỳ đâu (giữ thư mục `lang\` cạnh `BatteryHub.exe` để dùng bản dịch giao diện) và chạy `BatteryHub.exe`.

**Lưu ý:**
- **Cảnh báo SmartScreen:** tệp `.exe` không có chữ ký số nên Windows có thể hiện thông báo "Windows protected your PC". Hãy bấm *More info → Run anyway*, hoặc tự biên dịch từ mã nguồn.
- **Chế độ biểu tượng khay hệ thống trên Windows 11:** các biểu tượng khay mới sẽ nằm trong menu tràn `^`. Hãy kéo chúng ra thanh tác vụ hoặc bật trong *Settings → Personalization → Taskbar → Other system tray icons*.
- **Ngăn ứng dụng chạm vào một thiết bị cụ thể:** nếu có thiết bị hoạt động bất thường khi ứng dụng chạy, hãy liệt kê nó trong chuỗi registry `IgnoreDevices` tại `HKCU\Software\WirelessBattery` dưới dạng các cặp `VID:PID` (hệ thập lục phân, cách nhau bởi dấu phẩy, ví dụ `28BD:0947, 1234:ABCD`; chạy `--dump` để xem các ID). Khi đó ứng dụng sẽ không bao giờ mở thiết bị đó. Bảng vẽ điện tử được bỏ qua tự động.

## Cập nhật trên Windows

Các bản phát hành ổn định chính thức trên Windows kiểm tra bản phát hành ổn định mới nhất của dự án ở chế độ nền, 30 giây sau khi khởi động và sau đó mỗi 24 giờ khi ứng dụng đang chạy. Mở menu để xem **Có bản cập nhật mới: vX.Y.Z...**, hoặc tự chọn **Kiểm tra cập nhật...**.
Thông tin cập nhật chỉ hiển thị trong menu này: biểu tượng pin, phần trăm và chú giải vẫn giữ nguyên, và việc kiểm tra tự động không bao giờ bật thông báo hay hộp thoại bất ngờ. Tắt **Tự động kiểm tra bản cập nhật** trong menu để ngừng kiểm tra ngầm.

Đối với bản đã cài đặt, bấm vào mục cập nhật rồi chọn **Tải về và cài đặt**. Không có gì được cài nếu bạn không bấm nút đó. Ứng dụng tải tệp `SHA256SUMS.txt` của bản phát hành cùng chữ ký đi kèm, xác thực chữ ký bằng khóa công khai của người bảo trì tích hợp sẵn trong ứng dụng, tải trình cài đặt Windows về, và chỉ chạy nó nếu mã SHA-256 trùng khớp với danh sách đã ký (và trùng với mã GitHub liệt kê cho tệp đó). Sau đó trình cài đặt cập nhật bản cài hiện có. Mọi thiết lập và tùy chọn khởi động cùng Windows đều được giữ nguyên, và ứng dụng tự mở lại sau khi cài xong. Bản cài đặt cho tất cả người dùng có thể sẽ yêu cầu quyền quản trị viên. **Nhật ký cập nhật (Release notes)** mở trang phát hành chính thức; **Để sau** giữ nguyên phiên bản hiện tại. Các bản di động (portable) sẽ mở trang phát hành để bạn tự tải tệp ZIP thủ công.

Quá trình kiểm tra chỉ truy vấn API công khai của GitHub mà không cần tài khoản hay token. Không có dữ liệu thiết bị hay pin nào được gửi đi. Lỗi ngoại tuyến hoặc giới hạn tần suất của GitHub vẫn để bộ theo dõi pin tiếp tục chạy bình thường; phiên bản tìm thấy trước đó vẫn lưu trong menu cho đến khi có lần kiểm tra mới thành công hoặc được cài đặt. Việc hủy tải xuống sẽ chờ thao tác mạng hiện tại kết thúc thời gian chờ hữu hạn của nó. Trình cài đặt không bao giờ tự động khởi động lại Windows.

**Vì sao cập nhật an toàn để cài đặt:** khóa ký số không bao giờ được đưa lên GitHub. Người bảo trì tự ký danh sách checksum của từng bản phát hành trên máy cá nhân (xem [docs/releasing.md](#sec-releasing)), nên ngay cả khi có ai chiếm được tài khoản GitHub hay quy trình build thì cũng không thể phát hành bản cập nhật nào mà ứng dụng chấp nhận cài. Bản phát hành không có chữ ký hợp lệ vẫn hiện trong menu nhưng chỉ có thể tải về thủ công. Chữ ký số này không thay thế các lời nhắc SmartScreen hoặc UAC của chính Windows.

Hãy cài thủ công một lần đối với bản phát hành đầu tiên có tính năng này. Các bản build phát triển/thử nghiệm tự động tắt kiểm tra cập nhật chính thức để tránh ghi đè nhầm các thay đổi cục bộ. Tính năng cập nhật cho Linux và thay thế tự động bản portable hiện được dời sang giai đoạn sau.

## Dòng lệnh

```
BatteryHub.exe --list     # in mọi thiết bị và mức pin của chúng, rồi thoát
BatteryHub.exe --json     # in mảng JSON gồm các thiết bị và mức pin, rồi thoát
BatteryHub.exe --dump     # mọi tập HID, thiết bị HID không thể mở, mọi thiết bị USB (kể cả thiết bị
                               # không có giao diện HID) và thiết bị Bluetooth; cũng lưu vào %TEMP%\BatteryHub-dump.txt
BatteryHub.exe --report   # mở cửa sổ "Yêu cầu hỗ trợ thêm thiết bị"
BatteryHub.exe --demo     # hiển thị thiết bị mẫu của mọi thương hiệu thay cho thiết bị thật (chụp ảnh, kiểm tra màu)
BatteryHub.exe --quit     # đóng phiên bản đang chạy
```

Bản Linux dùng các cờ tương tự với `wireless-battery` thay cho `BatteryHub.exe`, và hỗ trợ thêm `--help`. `--json` in ra một mảng ổn định để các script và thanh trạng thái phân tích cú pháp:

```json
[{"key":"kysona:373B:1085","name":"CX Wireless mouse","via":"2.4 GHz receiver","kind":"mouse",
  "percent":85,"level":"","detail":"","charging":false,"asleep":false,"connected":true,
  "millivolts":4029,"graceSec":1800}]
```

`graceSec` là khoảng thời gian (giây) ứng dụng giữ hiển thị mức pin biết gần nhất khi thiết bị đang ngủ. Việc bổ sung trường mới đảm bảo tương thích ngược.

**Thiết bị không hiển thị?** Nhấp chuột phải vào widget hoặc biểu tượng khay hệ thống và chọn **Yêu cầu hỗ trợ thêm thiết bị...**. Chọn thiết bị, kiểm tra chính xác nội dung sẽ được gửi (hiển thị nguyên văn: tên thiết bị, loại thiết bị, ID USB/HID và bố cục giao diện, cùng tên và ghi chú không bắt buộc của bạn) rồi bấm **Gửi yêu cầu**. Thông tin sẽ lên danh sách công khai tại [krisgfx.com/tools](https://krisgfx.com/tools/#requested) và mở hoặc cập nhật một GitHub issue. **Sao chép báo cáo chi tiết** chép toàn bộ kết quả `--dump` vào bảng tạm để dán vào issue. Dữ liệu báo cáo chỉ được gửi đi khi bạn bấm Gửi. Các bản build Windows chính thức cũng có thể liên hệ GitHub để kiểm tra cập nhật như mô tả ở mục [Cập nhật trên Windows](#cập-nhật-trên-windows); quá trình kiểm tra cập nhật không gửi thông tin thiết bị hay pin.

## Biên dịch

Bạn cần [MinGW-w64](https://www.mingw-w64.org/), ví dụ cài từ [MSYS2](https://www.msys2.org/) (`pacman -S mingw-w64-x86_64-gcc make`).

```
make                                      # bản build phát triển, phiên bản 0.0.0
build.bat                                 # cmd thuần với g++ và windres trong PATH
make VERSION=1.2.3 CHANNEL=test            # bản build có phiên bản, tắt cập nhật chính thức
build.bat 1.2.3 test                       # bản build cmd có phiên bản tương đương
make test VERSION=1.2.3 CHANNEL=test       # chạy các bài kiểm thử hồi quy cho thiết bị và trình cập nhật
```

Để đóng gói trình cài đặt và tệp ZIP portable, hãy cài [Inno Setup](https://jrsoftware.org/isinfo.php), trước tiên biên dịch với phiên bản mong muốn (ví dụ `make VERSION=1.2.3 CHANNEL=test`), rồi chạy `powershell -File installer\build-installer.ps1 -Version 1.2.3`. Quá trình đóng gói sẽ từ chối nếu phiên bản khác với tệp thực thi. Script sẽ tải bản phát hành HeadsetControl đã ghim và xác minh checksum. GitHub Actions tự động hóa toàn bộ quá trình này: đẩy một tag như `v1.0.0` sẽ phát hành bản release kèm trình cài đặt, bản ZIP portable và mã nguồn HeadsetControl (theo yêu cầu của giấy phép GPL).

Bản build Windows cũng cần PowerShell để tạo thông tin phiên bản dùng chung giữa tệp thực thi và tài nguyên. Các tag phiên bản của kho lưu trữ chính thức được biên dịch với `CHANNEL=stable`; bản build cục bộ mặc định dùng `dev`. Các bản fork và pull request không tự động bật cập nhật chính thức.

Bản thân `BatteryHub.exe` vẫn chạy độc lập được. Nếu thiếu `headsetcontrol.exe` nằm cạnh (hoặc trong `PATH`), bạn chỉ mất phần hỗ trợ các tai nghe bổ sung đó thôi.

## Linux (thử nghiệm)

Một bản build cho Linux được phát triển song song với ứng dụng Windows. Nó sử dụng cùng các trình điều khiển hãng nhưng chạy trên backend HID dựa vào hidraw và biểu tượng khay hệ thống GTK4 StatusNotifierItem; đường code của Windows không bị ảnh hưởng. Toàn bộ tệp chỉ dành cho Linux nằm trong `linux/` và `src/linux/`, được biên dịch bằng `build-linux.sh` (Windows vẫn dùng `build.bat`).

| | Fedora | Ubuntu / Debian |
|---|---|---|
| Trình biên dịch & make | `sudo dnf install gcc-c++ make` | `sudo apt install g++ make` |
| GTK4 + Cairo | `sudo dnf install gtk4-devel cairo-devel` | `sudo apt install libgtk-4-dev libcairo2-dev` |

Không cần thêm thư viện HID nào khác (sử dụng hidraw trực tiếp).

```sh
./build-linux.sh
./build-linux.sh test         # kiểm thử đơn vị cho trình phân tích mô tả báo cáo HID
./wireless-battery --list     # in mức pin phát hiện được rồi thoát
./wireless-battery --dump     # liệt kê các tập HID
./wireless-battery --quit     # đóng phiên bản khay hệ thống đang chạy
```

Quyền truy cập HID cần một quy tắc udev, nếu không ứng dụng vẫn khởi chạy nhưng không tìm thấy thiết bị nào:

```sh
sudo cp linux/99-wireless-battery.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger
# đăng xuất rồi đăng nhập lại
```

Biểu tượng khay hoạt động sẵn trên KDE Plasma; GNOME cần thêm tiện ích hỗ trợ AppIndicator như `gnome-shell-extension-appindicator`. Việc chuyển đổi đa ngôn ngữ hoạt động qua menu con *Ngôn ngữ* (mặc định theo `LANGUAGE`/`LC_ALL`/`LC_MESSAGES`/`LANG`, và cũng bản địa hóa cả `--help`). Chạy `make -f linux/Makefile.linux install` để cài tệp thực thi, `lang/*.json` vào `$(PREFIX)/share/wireless-battery/lang/`, cùng trình khởi chạy desktop (`linux/wireless-battery.desktop`) và `linux/wireless-battery.svg` vào `$(PREFIX)` (mặc định `~/.local`); các bản ghi đè ngôn ngữ của người dùng nằm tại `~/.config/wireless-battery/lang/`.

Giai đoạn 1 bao gồm Logitech, Razer, SteelSeries, Corsair, HyperX, PlayStation, Cooler Master, Glorious, Finalmouse và nhóm giao thức chung Kysona/Pulsar/ATK/G-Wolves. Các kênh dự phòng Bluetooth/UPower, HeadsetControl và các hãng còn lại nằm trong các giai đoạn tiếp theo theo kế hoạch.

## Giới hạn

- **Taskbar quá chật:** với thanh tác vụ Windows 11 căn giữa có quá nhiều nút, các nút ứng dụng có thể chạm vào widget. Trên Windows 10 vùng nút tác vụ được tự động thu hẹp lại.
- **Điện thoại:** đọc từ tệp do Phone Link ghi ra cho thẻ đồng hành ở Start Menu, đây không phải API được tài liệu hóa chính thức và có thể thay đổi theo các bản cập nhật Phone Link. Điện thoại hiển thị khi Phone Link báo đang kết nối; thẻ cũ hơn 3 giờ sẽ hiện mờ. Thẻ này cũng cho biết khi điện thoại đang sạc để hiển thị tia sét sạc.
- **Thiết bị đang ngủ:** thiết bị đang ngủ có thể không trả lời. Giá trị cuối cùng vẫn được giữ hiển thị ở trạng thái mờ. Các đầu thu Logitech ngắt thiết bị đang ngủ khỏi liên kết nên giá trị cuối của chúng được giữ trong 30 phút.
- **Tai nghe HECATE G2 Wireless 7.1** (dongle 2.4 GHz `35BB:A009` / `A209`): chưa có tài liệu về truy vấn pin cho dongle này nên chưa đọc được. Cần một bản bắt gói tin USB khi phần mềm HECATE hiển thị pin tai nghe (xem CONTRIBUTING.md) để bổ sung hỗ trợ.
- **Bàn phím Keychron:** với firmware gốc, chúng chỉ báo pin qua Bluetooth (hiển thị qua hỗ trợ Bluetooth). Qua đầu thu 2.4 GHz hoặc cáp USB, cần firmware có bản vá pin ([docs/keychron_keyboard_firmware/README.md](#sec-keychron-firmware)); cập nhật bàn phím từ Keychron Launcher sẽ làm mất bản vá này. Chuột Keychron được hỗ trợ sẵn.
- **Tai nghe Baseus AeQur GH02:** dongle 2.4 GHz (`10D6:4802`, chip Actions) chỉ truyền âm thanh, phím đa phương tiện và kênh cập nhật firmware của chip chứ không truyền dữ liệu pin. Hãy kết nối tai nghe qua Bluetooth để xem mức pin (hiển thị qua hỗ trợ Bluetooth khi Windows báo được mức pin).
- **Bàn phím Weikav Lucky65 v1:** firmware không báo cáo pin qua dongle 2.4 GHz (`0603:0351`, chip Novatek). Bàn phím không có phím tắt kiểm tra pin, còn trình cấu hình chính thức chỉ kết nối qua cáp USB chứ không qua dongle, nên không có dữ liệu pin nào để hiển thị.
- **Rapoo:** các mẫu chuột VT được hỗ trợ chủ động đẩy trạng thái, nên mỗi lần làm mới có thể chờ tối đa 4 giây cho mỗi giao diện khớp. Chuột đang ngủ có thể giữ hiển thị mờ giá trị gần nhất trong tối đa 30 phút. Hỗ trợ áp dụng cho báo cáo Nordic 54L `07` và định dạng cũ `BB` (VT3 Pro, VT1 Pro Max); báo cáo CH584 `08`, chuột văn phòng dòng MT/M và các giao thức firmware khác không nằm trong phạm vi trình điều khiển này.
- **GameSir Cyclone Pro:** dongle không mang thông tin mức pin nên mức pin được đọc từ tay cầm qua Bluetooth LE. Hãy ghép nối tay cầm với Windows một lần (Settings > Bluetooth & devices > Add device > Bluetooth > `GameSir-Cyclone Pro`), rồi tiếp tục chơi qua dongle. PC cần có Bluetooth. Mức pin cập nhật mỗi 2 phút và không có phần trăm khi đang sạc. Nếu chưa ghép nối, dongle sẽ hiện như một tay cầm Xbox ở mức "Full". Chi tiết xem tại [docs/gamesir_cyclone_pro.md](#sec-gamesir-cyclone-pro).
- **RAWM:** chuột được hỏi thông qua đầu thu nên khi chuột ngủ sẽ không trả lời; nó được giữ hiển thị mờ với giá trị cuối tối đa 30 phút và làm tăng thêm khoảng 1 giây cho mỗi lần làm mới khi đang ngủ. Mới chỉ có Leviathan V4 trên đầu thu RAWM HS (`1915:2346`) được thử nghiệm; các mẫu khác được lấy từ bảng thiết bị của RAWM HUB. Leviathan V4 GT và NYX60 (VID `373E`, RAWM HUB 3.0) cùng các bàn phím RAWM HS dùng giao thức khác và không được hỗ trợ.
- **Flydigi:** trình điều khiển này nhắm tới Vader 5 Pro và Apex 5; Bluetooth và các mẫu Flydigi khác (ví dụ Apex 6) không nằm trong phạm vi hỗ trợ. Phần trăm hiển thị tương ứng với các nấc pin thô. Apex 5 đã được thử nghiệm trên phần cứng thật qua đầu thu 2.4 GHz và cáp USB; Vader 5 Pro dựa theo SDL và bản ghi phần cứng Windows.
- **Chưa hỗ trợ:** các chuột không dây MSI ngoài VERSA 300 ELITE và CLUTCH GM31 / GM41, bàn phím không dây MSI, tai nghe Razer Kraken và các mẫu Barracuda ngoài Barracuda X (2022) trên `1532:0550`, chuột HyperX Pulsefire ngoài Haste 2 Wireless / Haste 2 Core Wireless và Xbox Wireless Headset trên bộ chuyển đổi Xbox: giao thức pin của chúng chưa được tài liệu hóa. Xbox Wireless Headset hoạt động được qua Bluetooth. Một bản bắt gói tin USB từ người sở hữu (xem CONTRIBUTING.md) là cách để thêm hỗ trợ cho chúng.
- **Các thiết bị khác:** một số thiết bị 2.4 GHz dùng giao thức không công khai nên chưa được hỗ trợ. Xem [CONTRIBUTING.md](#sec-contributing) để biết cách giúp bổ sung thiết bị mới.

## Cơ chế hoạt động

Mỗi trình điều khiển hãng trong [`src/drivers/`](../../src/drivers) nhận diện thiết bị bằng mã USB Vendor ID và Product ID, và chỉ bao giờ gửi các truy vấn đọc pin ở chế độ chỉ đọc. Các thiết bị lạ không bao giờ bị ghi dữ liệu. Các cơ chế dự phòng chung (HID battery usage, Bluetooth, XInput, HeadsetControl) chỉ kiểm tra những thiết bị chưa được trình điều khiển hãng nào nhận quản lý.

Widget trên thanh tác vụ là một cửa sổ con dạng layered của `Shell_TrayWnd`, đặt bên trái `TrayNotifyWnd`. Nếu Explorer khởi động lại, widget sẽ tự được tạo lại.

## Bản dịch

Mỗi ngôn ngữ giao diện là một tệp văn bản UTF-8 tĩnh thuần túy trong [`lang/`](../../lang): tiếng Anh ở bên trái, bản dịch ở bên phải. Tệp ngôn ngữ được nạp từ đĩa lúc chạy thay vì biên dịch cứng vào tệp thực thi, nên bạn có thể sửa trực tiếp mà không cần biên dịch lại.

```json
{
    "@code": "it",
    "@name": "Italiano",
    "@rtl": false,
    "Refresh now": "Aggiorna ora",
    "{name} is at {percent}%": "{name} è al {percent}%"
}
```

- **Giao diện ứng dụng (Windows & Linux):**
  - Sửa hoặc thêm các tệp `.json` trực tiếp bên trong thư mục `lang/` cạnh `BatteryHub.exe` (hoặc `/usr/share/wireless-battery/lang/`, `/usr/local/share/wireless-battery/lang/`, `$XDG_DATA_HOME/wireless-battery/lang/`, hay `./lang/` trên Linux).
  - Hoặc chọn *Ngôn ngữ → Thêm ngôn ngữ tùy chỉnh...* trong menu để chuẩn bị sẵn thư mục ghi đè của người dùng (`%APPDATA%\WirelessBattery\lang` trên Windows, `~/.config/wireless-battery/lang` trên Linux) kèm `_template.json`. Sao chép `_template.json` thành ví dụ `it.json`, điền `@code`, `@name` cùng các câu dịch, và ngôn ngữ đó sẽ xuất hiện trong menu (không cần khởi động lại). Các tệp trong thư mục người dùng sẽ ghi đè các câu có cùng `@code` tích hợp sẵn.
  - Giữ nguyên các `{placeholder}` như cũ, và thêm `"@rtl": true` cho các chữ viết từ phải sang trái. Các câu bỏ trống sẽ giữ nguyên tiếng Anh, nên bản dịch chưa đầy đủ 100% vẫn dùng bình thường.
  - Đầu ra `--list` và `--dump` cố ý giữ bằng tiếng Anh: để tiện dán vào các GitHub issue.
- **Trình cài đặt Windows:** bản dịch Inno Setup nằm trong [`installer/lang/`](../../installer/lang) (lưu ở định dạng UTF-8 có BOM) và được đăng ký dưới mục `[Languages]` trong `installer/BatteryHub.iss`.
- **Tài liệu:** toàn bộ tài liệu hiển thị của dự án được dịch trong một tệp Markdown độc lập duy nhất cho mỗi ngôn ngữ tại [`docs/i18n/`](README.md) (xem [`docs/i18n/_template.md`](_template.md) để thêm ngôn ngữ mới mà không cần bất kỳ script tạo tệp nào).
- **Chia sẻ với mọi người:** hãy gửi một pull request bổ sung các tệp của bạn trong `lang/`, `installer/lang/`, `linux/wireless-battery.desktop` và `docs/i18n/`. Xem [`docs/i18n/README.md`](README.md) để làm theo từng bước.

## Ghi nhận đóng góp

Biểu tượng ứng dụng do [nik-txt](https://github.com/nik-txt) thiết kế ([`res/app.svg`](../../res/app.svg)).

Các giao thức được xây dựng từ công sức nghiên cứu của những dự án sau:

- [Tài liệu đặc tả Google Fast Pair](https://developers.google.com/nearby/fast-pair/specifications/extensions/batterynotification): gói quảng bá pin tai trái / tai phải / hộp sạc của tai nghe Fast Pair
- [Trình điều khiển Astro của HeadsetControl](https://github.com/Sapd/HeadsetControl/blob/master/lib/devices/logitech_astro_a50.hpp), [eh-fifty](https://github.com/tdryer/eh-fifty) và [AstroBar](https://github.com/nichtlegacy/AstroBar): giao thức pin Astro A50 X / Gen 5 / Gen 4 / Gen 3 / A20; [OpenAstroCC](https://github.com/BenStein1/OpenAstroCC): lệnh đọc trạng thái `0x72` của A50 Gen 3

- [mouse-battery-monitor](https://github.com/stuffz/mouse-battery-monitor) (stuffz): các lệnh pin và trạng thái sạc VAXEE ([tài liệu giao thức](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md))

- [HeadsetControl](https://github.com/Sapd/HeadsetControl): tai nghe SteelSeries, Corsair, HyperX, Logitech và Sony INZONE
- [inzone-buds-battery-tray](https://github.com/kinako19/inzone-buds-battery-tray) (kinako19) và [inzone-buds-battery-tray](https://github.com/takamachi66/inzone-buds-battery-tray) (takamachi66): Sony INZONE Buds
- [OpenRazer](https://github.com/openrazer/openrazer): Razer
- [Solaar](https://github.com/pwr-Solaar/Solaar) và tài liệu Logitech HID++ 2.0: Logitech
- [g435-battery-percentage](https://github.com/portyporty/g435-battery-percentage) và [logitech-g435-battery](https://github.com/deddroid/logitech-g435-battery): Logitech G435 (dongle `0ADF`)
- [rivalcfg](https://github.com/flozz/rivalcfg): chuột SteelSeries (Rival Pro từ pull request #294)
- [glorious-indicator](https://github.com/ikajdan/glorious-indicator) và [glorious-ctl](https://github.com/louis4craft/glorious-ctl): Glorious
- Trình cấu hình web của Hitscan ([control.hitscan.com](https://control.hitscan.com)): Hitscan
- `hid-kysona` trên Linux (Lode Willems): Kysona, Pulsar và ATK
- Trình cấu hình web của ATK ([hub.atk.pro](https://hub.atk.pro)): chuột ATK và tai nghe N9 Pro / N9 Ultra
- [PulsarBattery](https://github.com/darthsoup/PulsarBattery): Pulsar X2 V3 / X2 V3 eS
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) PR #350 và [mouse-battery](https://github.com/qwr79/mouse-battery): dongle ATK / VXE NK NANO
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT): Audeze Maxwell, NZXT Lift Elite, Poly BT600, Razer Barracuda Pro, SteelSeries Arctis Nova Elite, ATK V75X và Endgame Gear XM2we, được chuyển thể từ các provider của dự án (mỗi trình điều khiển ghi rõ nguồn)
- [HaloBattery](https://github.com/HeyOkay/HaloBattery) `providers/turtlebeach.py` và [halobattery-stealth700](https://github.com/PaulRichez/halobattery-stealth700) (PaulRichez, MIT): Turtle Beach Stealth 700 Gen 3; [Neap](https://github.com/lykosapps/Neap) (chỉ tham khảo phát hiện giao thức): dòng thiết bị Turtle Beach Swarm II
- Trình điều khiển web của G-Wolves ([mouse.xyz](https://mouse.xyz)): các mẫu G-Wolves và giao thức tương ứng
- [BatteryWatch](https://github.com/B1Chat/BatteryWatch): bàn phím CHERRY trên dongle 2.4 GHz (định dạng khung và truy vấn pin)
- Keychron Launcher ([launcher.keychron.com](https://launcher.keychron.com)): chuột Keychron
- [NinjaForce](https://www.ninjaforce.co/) và [ninjutso-battery-tray](https://github.com/DrStopor/ninjutso-battery-tray): truy vấn feature của Ninjutso Ten / Ten Air
- [nape_pro](https://github.com/nvalis/nape_pro) và [KeychronNapeBatteryWidget](https://github.com/gtun/KeychronNapeBatteryWidget): Keychron Nape Pro trên đầu thu Link-KM
- LAMZU Aurora ([lamzu.net](https://www.lamzu.net)): chuột LAMZU
- [vole](https://github.com/johanneszab/vole) và [Endgame_Gear_Web_Configurator](https://github.com/Janlhin/Endgame_Gear_Web_Configurator): chuột Endgame Gear 4K
- [mouse-gauge](https://github.com/djnawara/mouse-gauge) và [HaloBattery](https://github.com/Waturus/HaloBattery): WLMouse
- [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) và [FinalmousePollingRateSwitcher](https://github.com/xBambooz/FinalmousePollingRateSwitcher): Finalmouse UltralightX / Starlight X (từ xpanel của Finalmouse)
- [redragon-battery-omarchy](https://github.com/EliottV17/redragon-battery-omarchy) và [g49-web-control](https://github.com/pingpingjinping/g49-web-control): các ID của Redragon
- [m913-ctl](https://github.com/Qehbr/m913-ctl) và [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): bố cục khung Areson `25A7` và lệnh `GetPower`
- [peripheral-battery-tray](https://github.com/SteveWang92/peripheral-battery-tray) / [G-Helper](https://github.com/seerge/g-helper): ASUS ROG; [pelta-control](https://github.com/jimm0thy/pelta-control) / [BatteryWatch](https://github.com/B1Chat/BatteryWatch): ROG Pelta
- [zowie-battery](https://github.com/yleshchuk/zowie-battery) và [zowie-battery-tray](https://github.com/IgnacioBarb/zowie-battery-tray): ZOWIE EC-CW và DW
- Web driver của RK ([drive.rkgaming.com](https://drive.rkgaming.com)): Royal Kludge MG6 Pro
- [MCHOSE-Monitor](https://github.com/Jstdi001/MCHOSE-Monitor): MCHOSE G3 V2
- [mchose-a5-pro-max-web-driver](https://github.com/z750sasr/mchose-a5-pro-max-web-driver) (MIT), [HaloBattery](https://github.com/HeyOkay/HaloBattery) (MIT), [mchose-macos](https://github.com/Klegus/mchose-macos) (MIT) và [OpenMouse mouse-protocol](https://github.com/OpenMouse-Project/mouse-protocol) (tài liệu): MCHOSE A5 Pro / A5 Pro Max (thế hệ đầu, VID `2023`)
- [LGSTrayBattery-MotospeedX6](https://github.com/Jacobz888/LGSTrayBattery-MotospeedX6), [omarchy-delux-m900](https://github.com/AeonArcHQ/omarchy-delux-m900), [aj179-linux](https://github.com/Rockeyxx/aj179-linux): Motospeed, Delux, Ajazz
- [AreYouLowBattery](https://github.com/ryan-mant/AreYouLowBattery): báo cáo đầu thu CompX cho Delux M900 Pro
- [ajazz-aj139-macos](https://github.com/werquess/ajazz-aj139-macos) và [AjazzAJ139V2](https://github.com/nico2525nn/AjazzAJ139V2): Ajazz AJ139 V2
- [Incott-Manager](https://github.com/OmarK6/Incott-Manager), [incott-mouse-app](https://github.com/HeHaoren/incott-mouse-app) và [MouseBattery](https://github.com/FelixNg21/MouseBattery): Incott
- Web driver của Wraith ([w1.software](https://www.w1.software/)): Wraith W1
- OpenRazer PR #2794 và [omarchy-blackshark-v3](https://github.com/ReedME/omarchy-blackshark-v3): BlackShark V3
- OpenRazer PR #2862 và [HaloBattery](https://github.com/HeyOkay/HaloBattery): BlackShark V2 Pro (2023)
- [razer-barracuda-x-battery](https://github.com/mehdibouchami/razer-barracuda-x-battery) và [barracuda-x-battery](https://github.com/nightdevx/barracuda-x-battery): Razer Barracuda X (2022) trên đầu thu `1532:0550`; [razer-barracuda-battery-tray](https://github.com/KhromotozzDevOut/razer-barracuda-battery-tray): cấu trúc khung của đầu thu `1532:0552`
- [OpenRazer PR #2899](https://github.com/openrazer/openrazer/pull/2899): BlackShark V3 X
- [HyperXWM](https://github.com/Medprj/HyperXWM): HyperX Cloud III Wireless
- [HyperHeadset](https://github.com/LennardKittner/HyperHeadset): HyperX Cloud III S, Cloud II Core, Cloud Flight S
- [HyperBatteryMonitor](https://github.com/davidsantanaalves/HyperBatteryMonitor): HyperX Cloud Stinger Core Wireless
- [BatteryTray](https://github.com/qu1ncky/BatteryTray): các đầu thu Rongyuan và Xenta (Attack Shark và các hãng khác)
- [sonix-keyboard-studio](https://github.com/donglover69/sonix-keyboard-studio): bàn phím SONiX trên dongle 2.4G (AJAZZ AK820 MAX, AK980 V2, AULA F108 Pro); [ak820-rs](https://github.com/deddroid/ak820-rs) và [ak820-studio](https://github.com/usharik/ak820-studio): đầu thu AJAZZ AK820 Pro `0C45:FDFD`
- [openajazz](https://github.com/shrey715/openajazz) và [Kraber](https://github.com/AkashPanja/Kraber): giao thức trạng thái Semico `1A2C` (`AA 55 CC 33` / `0x0E`) cho Attack Shark X98 và AJAZZ AK820 Max Plus
- [coolermaster-usb-protocol](https://github.com/syntactic-spice/coolermaster-usb-protocol) và [MM731-Controller](https://github.com/riVFerd/MM731-Controller): Cooler Master MM712 và MM731
- [GamesirBatteryTray](https://github.com/WWWyyy452/GamesirBatteryTray) và [Gamesir-Nova-2-Lite-Battery-Detection](https://github.com/AJAY0406/Gamesir-Nova-2-Lite-Battery-Detection): GameSir Nova
- [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery): yêu cầu pin "base info" qua Bluetooth LE của GameSir Cyclone Pro
- [jabridge](https://github.com/Watchdog0x/jabridge): giao thức Jabra GNP (dongle Link 380 / 390)
- [xd5-go-web](https://github.com/jarjut/xd5-go-web): Fantech Helios Go XD5
- [t20-battery](https://github.com/tuttizpro218/t20-battery): giao thức trang trạng thái `1EA7:0066` (Fantech Raigor III và các thiết bị 2.4G Mouse phổ thông khác)
- `hid-playstation` của Linux: bố cục báo cáo DualShock 4 / DualSense
- [omarchy-aula-SC580](https://github.com/Crucialjun/omarchy-aula-SC580): giao thức hãng AULA SC580 / SC580X
- Ứng dụng web RAWM HUB ([rawmtech.com/hub.html](https://www.rawmtech.com/hub.html), Hub Web 2.0) và bảng thiết bị của nó: chuột RAWM và SADES Dagger
- [Trình điều khiển HID Flydigi của SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_flydigi.c) và [HaloBattery issue #191](https://github.com/HeyOkay/HaloBattery/issues/191): cấu trúc khung truy vấn và bố cục pin Vader 5 Pro và Apex 5
- [Trình điều khiển HID 8BitDo của SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c): byte pin 8BitDo Ultimate 2
- BEITONG iControl (các trang KP20 và KP40D cùng lưu lượng USB của đầu thu KP20): truy vấn pin và cách xáo trộn payload của BEITONG KP20 / KP40D
- [Trình điều khiển HID 8BitDo của SDL](https://github.com/libsdl-org/SDL/blob/main/src/joystick/hidapi/SDL_hidapi_8bitdo.c) và [8bitdo-ultimate2-linux](https://github.com/MiguelSanzBr/8bitdo-ultimate2-linux): byte pin 8BitDo và giao thức HID hãng
- JBL QuantumENGINE (các bản tin thông tin thiết bị HIDV3): tai nghe JBL Quantum
- [HaloBattery](https://github.com/HeyOkay/HaloBattery/blob/main/docs/protocols.md): Corsair Sabre V2 Pro Ultralight, giao thức Compx trên `FF02:0002`
- [MouseDock](https://github.com/late-autumn-gif/mousedock) (MIT) và [BrimDeck](https://github.com/MoFeng2223/BrimDeck): đọc cấu hình Scyrox V12M
- JBL QuantumENGINE: báo cáo kết nối và pin HIDV1 cho Quantum 350, cùng các bản tin thông tin thiết bị HIDV3 cho các tai nghe Quantum đời mới hơn
- [jbl-quantum-linux](https://github.com/Tymon3310/jbl-quantum-linux/blob/main/docs/QUANTUM610_PACKETS.md): báo cáo pin và liên kết HIDV1 của JBL Quantum 610, cùng dòng sản phẩm Quantum (360 là mẫu dongle HIDV1)

## Giấy phép

[GNU General Public License v3.0 or later](../../LICENSE). Bạn có thể sử dụng, chỉnh sửa và phân phối lại phần mềm này, nhưng mọi sản phẩm phân phối dựa trên nó đều phải được phát hành theo cùng giấy phép kèm mã nguồn.


---

<a id="sec-contributing"></a>
> 📄 **Mục:** Đóng góp (`CONTRIBUTING.md`) · [Bản gốc tiếng Anh](../../CONTRIBUTING.md) · [↑ Lên đầu trang](#top)

# Đóng góp

## Báo cáo thiết bị có hoạt động hay không

Hầu hết trình điều khiển được viết dựa trên tài liệu giao thức và không thể thử nghiệm trên tất cả mọi mẫu thiết bị.
Vui lòng mở một issue kèm theo:

- tên thiết bị và hình thức kết nối (đầu thu không dây, cáp hay Bluetooth)
- kết quả đầu ra của `BatteryHub.exe --list`
- kết quả đầu ra của `BatteryHub.exe --dump`
- mức pin mà phần mềm chính thức của hãng đang hiển thị

## Thêm hỗ trợ thiết bị mới

1. Chạy `BatteryHub.exe --dump` để tìm Vendor ID và Product ID của thiết bị, cùng các tập dành riêng cho hãng (usage page `FFxx`) và kích thước báo cáo tương ứng.
2. Tìm giao thức đọc pin. Những nơi đáng tham khảo gồm: HeadsetControl, OpenRazer, Solaar, rivalcfg, OpenRGB, OpenLinkHub, hoặc tự bắt gói tin USB của phần mềm hãng (Wireshark + USBPcap).
3. Nếu hãng đã có trình điều khiển trong `src/drivers/`, hãy bổ sung Product ID (và mọi điểm khác biệt nếu có) vào đó.
   Nếu chưa, hãy tạo tệp `src/drivers/<vendor>.cpp`:

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

4. Khai báo hàm trong `src/drivers/drivers.h`, gọi nó từ `PollAllDevices()` trong `src/devices.cpp` (trước các cơ chế dự phòng chung). `build.bat` và Makefile sẽ tự động nhận diện các tệp mới.
5. Cập nhật bảng thiết bị trong `README.md`.

### Quy tắc cho trình điều khiển

- **Chỉ đọc:** chỉ gửi các yêu cầu đọc trạng thái. Tuyệt đối không thay đổi thiết lập, đèn LED hay chế độ hoạt động.
- **Khớp chính xác:** chỉ giao tiếp với thiết bị nhận diện được qua Vendor ID và Product ID, hoặc qua một tập đặc thù của hãng gắn liền duy nhất với giao thức đó.
- **Luôn có thời gian chờ (timeout):** thiết bị bị mất kết nối không được làm kẹt chu kỳ quét quá khoảng một giây. Các giao thức thụ động có thể cần lâu hơn để bao phủ chu kỳ đẩy gói tin đã ghi nhận (ví dụ Delux và Rapoo). Hãy giữ một mốc thời hạn tuyệt đối duy nhất tối đa 4 giây cho mỗi tập khớp, không đặt lại mốc thời gian khi gặp các báo cáo không liên quan, và ghi rõ lý do cần ngoại lệ này.
- **Ghi nguồn tham khảo:** trích dẫn nguồn gốc giao thức trong phần chú thích ở đầu tệp.

## Bản dịch

Ngôn ngữ giao diện là các tệp văn bản UTF-8 tĩnh thuần túy trong `lang/` được nạp từ đĩa lúc chạy trên cả Windows và Linux (sao chép `lang/_template.json` thành `lang/<code>.json`, điền `@code`, `@name` và các câu dịch — không cần biên dịch lại). Văn bản giao diện mới trong mã nguồn phải đi qua `T(L"...")`, hoặc `TF(L"... {name} ...", { { L"name", value } })` khi có biến chèn vào; tuyệt đối không ghép câu dịch từ các mảnh rời rạc. Sau khi thêm câu mới, hãy thêm chúng vào `lang/_template.json`.

Bản dịch trình cài đặt Windows nằm trong `installer/lang/*.isl` (lưu ở định dạng UTF-8 có BOM và đăng ký trong `installer/BatteryHub.iss`), mô tả trình khởi chạy Linux nằm trong `linux/wireless-battery.desktop`, và bản dịch tài liệu đầy đủ nằm trong `docs/i18n/<code>.md` (một tệp độc lập sao chép từ `docs/i18n/_template.md`). Xem [`docs/i18n/README.md`](README.md) để đọc hướng dẫn chi tiết cho cộng tác viên.

## Phong cách mã nguồn

C++17, chỉ dùng Win32, không phụ thuộc bên thứ ba. Giữ kích thước tệp thực thi nhỏ gọn. Định dạng tương đồng mã nguồn hiện tại (thụt lề 4 khoảng trắng, độ dài dòng 120 cột).

## Phát triển trình cập nhật Windows

Trình cập nhật chỉ có trên Windows và dùng WinHTTP, BCrypt cùng trình cài đặt Inno Setup hiện có. Giữ trạng thái cập nhật chỉ hiển thị trong menu. Không thêm biểu tượng cập nhật, huy hiệu, thay đổi chú giải pin, thông báo bong bóng, toast hay hộp thoại tự động bật lên. Việc quét thiết bị chạy tách biệt khỏi tác vụ mạng.

Số phiên bản build và kênh phát hành được dùng chung giữa C++ và tài nguyên Windows thông qua tệp tự sinh `build/version.h`. Dùng `make VERSION=1.2.3 CHANNEL=test` hoặc `build.bat 1.2.3 test` để thử nghiệm cục bộ; `dev` là mặc định còn `stable` bật kiểm tra bản phát hành chính thức. Các thành phần phiên bản phải nằm trong khoảng 0..65535. Chỉ quy trình release-tag của kho lưu trữ chính thức mới tự chọn `stable`. Tránh vô tình biến bản build từ fork thành kênh cập nhật chính thức.

Chạy `make test VERSION=1.2.3 CHANNEL=test` để chạy các bài kiểm thử thiết bị hiện có cùng bộ kiểm thử phân tích phát hành nghiêm ngặt, so sánh thứ tự phiên bản, lập lịch kiểm tra, kiểm tra SHA-256 tệp thật, xử lý trích dẫn tham số và các lớp bảo vệ helper. Các bài kiểm thử hồi quy của trình cập nhật cũng bao phủ trường hợp hủy ngay lúc tải xong, bảo vệ hộp thoại và lỗi cấu hình timeout HTTP/hạn chế chuyển hướng. Bộ test Windows nạp trực tiếp các phần triển khai theo mẫu test backend Linux hiện có và thay thế phần gửi HTTP để không bao giờ kết nối tới GitHub. Không thêm điểm vào điều khiển chỉ phục vụ test vào bản phát hành chính thức. Các mục tiêu riêng lẻ gồm `make test-update-core` và `make test-update-win`. Bộ test trình cập nhật gốc liên kết tài nguyên ứng dụng để kích hoạt Common Controls v6. Các bài test dùng dữ liệu cục bộ và không tải xuống, nâng quyền, cài đặt hay thay đổi thiết lập khởi động của người dùng. Không thể ghi đè endpoint sản phẩm của ứng dụng cho mục đích test.

Trước khi đóng gói, chạy `powershell -NoProfile -File scripts/verify-windows-version.ps1 -ExpectedVersion 1.2.3`. `installer/build-installer.ps1 -Version 1.2.3` cũng tự chạy bước kiểm tra này trước khi tải các thành phần phụ thuộc. Nhánh cài đặt `/WBUPDATE=1` giữ nguyên tùy chọn khởi động/cài đặt hiện có và giao việc mở lại ứng dụng cho trình trợ giúp tạm thời. Trình trợ giúp đó chạy dưới tài khoản người dùng ban đầu, chỉ xin nâng quyền khi cài đặt ở phạm vi toàn máy. Các handle WinHTTP thuộc về worker; việc hủy mang tính hợp tác giữa các lệnh gọi có timeout hữu hạn. Khi thoát hẳn ứng dụng, tiến trình sẽ join worker đó nên có thể phải chờ một lệnh mạng đang chạy hết timeout.

Khi đánh giá bản phát hành, hãy dùng một tài khoản Windows dùng một lần hoặc máy ảo (VM) để kiểm thử thực tế hai phiên bản trình cài đặt, phạm vi từng người dùng/toàn máy, hủy UAC, bật/tắt khởi động cùng Windows, đường dẫn tùy chỉnh, cài đặt thất bại và mở lại ứng dụng. Kiểm thử đơn vị và biên dịch gói cài đặt không thể xác minh các hiệu ứng trình cài đặt đó. Đánh giá trực quan menu/giao diện và kiểm thử end-to-end trình cài đặt/UAC thực tế vẫn là cổng kiểm duyệt thủ công bắt buộc khi phát hành; không đánh dấu đạt nếu chưa quan sát trực tiếp. Tuyệt đối không test bằng cách ghi đè lên bản cài đặt dùng hằng ngày của người dùng.

## Kiểm tra an toàn tự động

Mỗi pull request đều được quét bởi "PR safety check" nhằm phát hiện những hành vi ứng dụng không bao giờ được phép làm (truy cập mạng, khởi chạy chương trình khác, đọc bàn phím/clipboard/màn hình, mục khởi động, tệp nhị phân, thay đổi quy trình build hoặc phát hành). Việc bị gắn cờ không đồng nghĩa bị từ chối: chỉ cần giải thích rõ các dòng bị gắn cờ trong phần mô tả PR.

Bạn hoàn toàn có thể dùng công cụ AI hỗ trợ, nhưng vui lòng xóa các dòng `Co-authored-by` ghi công cụ (ví dụ `Co-authored-by: Claude ...`) khỏi thông điệp commit. Bộ kiểm tra sẽ báo lỗi nếu các dòng đó vẫn còn.


---

<a id="sec-pr-template"></a>
> 📄 **Mục:** Mẫu Pull Request (`.github/pull_request_template.md`) · [Bản gốc tiếng Anh](../../.github/pull_request_template.md) · [↑ Lên đầu trang](#top)

## Phần bổ sung này thêm gì

<!-- Thiết bị và vendor/product ID, ví dụ "Acme M1 (1234:5678)". -->

## Nguồn gốc giao thức

<!-- Dẫn liên kết nguồn (dự án khác, web driver của hãng, bản bắt gói tin USB do bạn tự ghi). -->

## Đã thử nghiệm trên phần cứng thật chưa?

<!-- Có (thiết bị nào, --list in ra gì) / Chưa -->

## Danh sách kiểm tra

- [ ] Chỉ gửi các truy vấn đọc pin ở chế độ chỉ đọc; không thay đổi thiết lập, đèn LED hay firmware
- [ ] Chỉ đụng tới các thiết bị nhận diện theo vendor/product ID (hoặc một tập đặc thù riêng của giao thức)
- [ ] Không truy cập mạng, không khởi chạy chương trình khác, không tạo tệp mới ngoài `src/`, `docs/` hoặc `README.md`
- [ ] Không bao gồm tệp nhị phân hoặc tệp tự sinh
- [ ] Không có dòng `Co-authored-by` ghi nhận công cụ AI (Claude, Copilot, ChatGPT ...) trong thông điệp commit
- [ ] Mọi thay đổi với `.github/`, `installer/`, `build.bat` hoặc `Makefile` đã được giải thích ở trên


---

<a id="sec-releasing"></a>
> 📄 **Mục:** Phát hành (`docs/releasing.md`) · [Bản gốc tiếng Anh](../../docs/releasing.md) · [↑ Lên đầu trang](#top)

# Phát hành phiên bản

Ứng dụng tự cập nhật từ các bản phát hành trên GitHub, nhưng nó chỉ cài đặt bộ cài có mã SHA-256 được liệt kê trong tệp `SHA256SUMS.txt` đã được ký bằng khóa phát hành. Khóa đó chỉ nằm trên máy tính cá nhân của người bảo trì, không bao giờ nằm trên GitHub: ngay cả khi tài khoản, token hay workflow bị chiếm quyền cũng chỉ có thể tải tệp lên chứ không thể tạo ra chữ ký mà ứng dụng chấp nhận.

## Thực hiện một lần: tạo khóa phát hành

```
powershell -ExecutionPolicy Bypass -File scripts\new-release-key.ps1
```

- Yêu cầu nhập mật khẩu (từ 12 ký tự trở lên) và ghi khóa riêng tư đã mã hóa vào `%USERPROFILE%\.wirelessbattery\release-key.wbk`.
- Đưa khóa công khai vào `src\update_public_key.h`. Commit tệp này. Các bản build chính thức sẽ từ chối biên dịch nếu thiếu khóa trong tệp này.
- **Sao lưu tệp khóa và lưu giữ mật khẩu cẩn thận** (trình quản lý mật khẩu là nơi phù hợp cho cả hai). Nếu mất một trong hai thứ đó, các ứng dụng đã cài đặt sẽ không thể tự cập nhật được nữa: bạn sẽ phải tạo khóa mới và mọi người dùng đều phải tự cài đặt thủ công một bản phát hành mới.

## Mỗi lần phát hành

1. Đẩy một tag phiên bản (`git tag v1.2.3 && git push origin v1.2.3`). CI sẽ biên dịch trình cài đặt, bản ZIP portable và `SHA256SUMS.txt`, rồi xuất bản bản phát hành.
2. Ký danh sách checksum:

   ```
   powershell -ExecutionPolicy Bypass -File scripts\sign-release.ps1 -Version 1.2.3
   ```

   Script sẽ tải `SHA256SUMS.txt` từ bản phát hành, hiển thị ra, yêu cầu bạn xác nhận, hỏi mật khẩu của khóa và ghi ra `SHA256SUMS.txt.sig`. Nếu bạn có các tệp tương tự trong `dist\` (từ bản build cục bộ của phiên bản đó), nó cũng cho biết chúng có khớp hay không.
3. Tải `SHA256SUMS.txt.sig` lên bản phát hành (script tự mở sẵn trang chỉnh sửa). Từ thời điểm đó trở đi ứng dụng sẽ hiện nút **Tải về và cài đặt**. Trước đó ứng dụng chỉ báo có bản cập nhật kèm liên kết mở trang phát hành.

Chỉ ký danh sách cho bản phát hành do chính bạn xuất bản. Chữ ký mang ý nghĩa "chính xác những tệp này là bản phát hành", vì vậy bước ký số là nơi ngăn chặn mọi tệp tải lên độc hại.

## Thay đổi khóa

Chạy `new-release-key.ps1` với tham số `-KeyFile` mới: nó sẽ thêm khóa công khai mới bên cạnh khóa cũ trong `src\update_public_key.h`. Hãy phát hành một phiên bản được ký bằng khóa cũ có chứa cả hai khóa công khai, sau đó từ bản phát hành tiếp theo trở đi dùng khóa mới để ký và gỡ khóa cũ ở bản sau nữa. Không thể thu hồi khóa bị mất hoặc bị lộ theo cách này: hãy xóa khóa đó khỏi tệp header, và người dùng các phiên bản cũ hơn sẽ phải cài thủ công bản phát hành tiếp theo.

## Những gì ứng dụng kiểm tra trước khi chạy trình cài đặt

- Bản phát hành là bản mới nhất của kho lưu trữ, không phải bản nháp (draft) hay thử nghiệm (prerelease), và có số phiên bản mới hơn ứng dụng hiện tại.
- `SHA256SUMS.txt.sig` là chữ ký ECDSA P-256 hợp lệ của `SHA256SUMS.txt` từ một khóa nằm trong `src\update_public_key.h` (sử dụng Windows BCrypt, không dùng mã nguồn bên thứ ba).
- Danh sách đã ký liệt kê `BatteryHub-Setup-<version>.exe` đúng một lần, với cùng mã SHA-256 mà GitHub báo cho tệp đó.
- Trình cài đặt tải về có kích thước và mã SHA-256 khớp chính xác. Một bản sao của ứng dụng sau đó kiểm tra lại lần nữa ngay trước khi khởi chạy tệp, đồng thời giữ khóa tệp để không thể bị đánh tráo giữa chừng.
- Việc tải xuống chỉ sử dụng HTTPS tới `github.com`, `objects.githubusercontent.com` và `release-assets.githubusercontent.com`, với từng bước chuyển hướng đều được kiểm tra.


---

<a id="sec-keychron-firmware"></a>
> 📄 **Mục:** Firmware bàn phím Keychron (`docs/keychron_keyboard_firmware/README.md`) · [Bản gốc tiếng Anh](../../docs/keychron_keyboard_firmware/README.md) · [↑ Lên đầu trang](#top)

# Đọc pin bàn phím Keychron qua đầu thu 2.4 GHz

Firmware gốc của Keychron chỉ báo cáo pin bàn phím qua Bluetooth. Với thay đổi nhỏ trong QMK ở tệp [`k5_max_battery.patch`](../keychron_keyboard_firmware/k5_max_battery.patch), bàn phím cũng sẽ trả lời truy vấn pin (`A4`) qua đầu thu Keychron Link và qua cáp USB, giúp BatteryHub hiển thị mức pin, điện áp và trạng thái sạc.

Đã thử nghiệm trên **Keychron K5 Max ANSI RGB** (`3434:0A50`) với đầu thu Keychron Link (`3434:D030`).

## Bản vá thay đổi những gì

Dựa trên nhánh `2025q3` của [Keychron/qmk_firmware](https://github.com/Keychron/qmk_firmware) (commit `57e682c`):

- thêm lệnh raw HID `KC_GET_BATTERY` (`0xA4`) từ [ldkv/qmk_firmware#1](https://github.com/ldkv/qmk_firmware/pull/1):
  phản hồi `[A4][percent][mV lo][mV hi][charging: 0 battery / 1 charging / 2 full][transport][model id]`;
- chuyển tiếp các yêu cầu raw HID đi qua liên kết không dây tới cùng bộ xử lý đó;
- trong `keyboards/keychron/k5_max/config.h`: thêm `#define WILRESS_RAW_ENABLE` (đúng chính tả như trong mã của Keychron) và `#define KC_BATTERY_MODEL_ID 0`.

Không có gì khác thay đổi: keymap, đèn nền và Keychron Launcher vẫn hoạt động bình thường.

## Cách 1: nạp firmware K5 Max dựng sẵn

Một bản dựng **chỉ dành cho K5 Max ANSI RGB** được đính kèm tại [bản phát hành này](https://github.com/jtentis/Wireless-Device-Battery-Monitor/releases/tag/v1.0.8-k5.1) (`k5_max_ansi_rgb_battery.bin`, SHA256 `5971a3429ca38805e1dc40b97a9fc9faf0ae1be59e673dc03acbb74eeb277abd`).
Không nạp tệp này cho mẫu bàn phím hay bố cục (layout) khác.

## Cách 2: tự biên dịch

Cần Git và Docker (hoặc một môi trường [QMK hoàn chỉnh](https://docs.qmk.fm/newbs_getting_started)).

```sh
git clone --recurse-submodules -b 2025q3 https://github.com/Keychron/qmk_firmware.git
cd qmk_firmware
git checkout 57e682c && git submodule update --init --recursive
git apply /path/to/k5_max_battery.patch
docker run --rm -v "$PWD":/qmk_firmware -w /qmk_firmware ghcr.io/qmk/qmk_cli \
    make keychron/k5_max/ansi/rgb:keychron
```

Kết quả là tệp `keychron_k5_max_ansi_rgb_keychron.bin` ở thư mục gốc của kho lưu trữ. Trên Windows, thư mục mount dạng bind từ hệ thống tệp chủ chạy rất chậm trong Docker; clone trực tiếp bên trong container (hoặc WSL) sẽ nhanh hơn nhiều.

**Các bàn phím không dây Keychron khác** (Q/V/K Max và các mẫu khác trên cây mã `2025q3` có `LK_WIRELESS_ENABLE`):
các thay đổi trong `keyboards/keychron/common/` áp dụng trực tiếp được ngay. Thêm hai dòng `#define` vào `config.h` của bàn phím bạn thay cho K5 Max, và biên dịch mục tiêu tương ứng, ví dụ `make keychron/<model>/<layout>/<variant>:keychron`. Ứng dụng hiện đặt tên K5 Max (`0A50`–`0A58`) theo đúng mẫu và mọi mẫu còn lại là "Keychron keyboard".

## Nạp firmware

1. Gạt công tắc chế độ sang **Cable** và rút cáp USB ra.
2. Nhấn giữ phím **Esc** trong khi cắm cáp USB vào. Bàn phím sẽ vào chế độ bootloader STM32.
3. Nạp tệp `.bin` bằng [QMK Toolbox](https://github.com/qmk/qmk_toolbox/releases) (hoặc `dfu-util`).
4. Gạt công tắc về **2.4 GHz** và kiểm tra bằng `BatteryHub.exe --list`:
   `Keychron K5 Max  [2.4 GHz receiver]  52%, 3743 mV`.

Cập nhật bàn phím từ Keychron Launcher sẽ ghi đè firmware này và làm mất tính năng báo pin. Để hoàn tác, hãy nạp lại firmware chính thức của Keychron theo đúng các bước trên.

## Giấy phép

QMK dùng giấy phép GPL-2.0-or-later; bản vá cũng tuân theo cùng giấy phép đó. Bất kỳ ai nhận được tệp nhị phân biên dịch từ bản vá này cũng phải có quyền tiếp cận phần mã nguồn thay đổi tương ứng.


---

<a id="sec-gamesir-cyclone-pro"></a>
> 📄 **Mục:** GameSir Cyclone Pro (`docs/gamesir_cyclone_pro.md`) · [Bản gốc tiếng Anh](../../docs/gamesir_cyclone_pro.md) · [↑ Lên đầu trang](#top)

# Hỗ trợ pin cho GameSir Cyclone Pro

## Vì sao tay cầm từng hiển thị như tay cầm Xbox đầy pin

Cyclone Pro (mã mẫu T4cp) chơi qua dongle 2.4 GHz `3537:1015`. Dongle này khai báo với Windows như một tay cầm Xbox 360 có dây (XUSB, `Xbox 360 Controller for Windows`). XInput luôn trả lời truy vấn pin của nó là "Full", nên cơ chế dự phòng XInput liệt kê nó là `Xbox controller 1` ở mức 100% bất kể mức pin thực tế là bao nhiêu.

Bản thân dongle không chứa thông tin pin:
- tập HID duy nhất của nó là tay cầm XInput (`HID\VID_3537&PID_1015&IG_00`)
- nó không có tập riêng của hãng như Nova (`FF7A`) hay Cyclone 2 (`FFF0`)

## Mức pin nằm ở đâu

Trong lúc chơi qua dongle, tay cầm đồng thời phát quảng bá qua Bluetooth LE với tên `GameSir-Cyclone Pro`, đây là liên kết mà ứng dụng điện thoại của GameSir sử dụng. Yêu cầu "get base info" của nó trả về mức pin:

| Bước | Chi tiết |
|---|---|
| Dịch vụ (Service) | `0x8650` (`00008650-0000-1000-8000-00805f9b34fb`) |
| Đặc tính (Characteristic) | `0x865F` (notify, write without response) |
| Yêu cầu | bật thông báo (notifications), ghi `01 01` |
| Phản hồi | thông báo 19 byte (một số firmware thêm tiền tố `C9`, thành 20 byte) |

Cấu trúc gói phản hồi:

```text
[0..5] MAC  [6..7] hardware ver  [8..9] BT ver  [10..11] firmware ver  [12..17] build date  [18] battery
```

Byte 18 là phần trăm pin (0-100), hoặc `FF` khi đang sạc. Khi sạc thiết bị không báo mức phần trăm, nên mức phần trăm gần nhất được giữ lại kèm tia sét sạc.

Tay cầm còn có dịch vụ `0xFF10` là kênh cập nhật firmware của GameSir. Trình điều khiển không bao giờ mở dịch vụ này. Tay cầm không có Battery Service chuẩn (`0x180F`), đó là lý do trang Bluetooth của Windows và cơ chế dự phòng Bluetooth không hiện pin của nó.

Nguồn: [GameSirBattery](https://github.com/bpbp-boop/GameSirBattery), nơi giao thức được giải mã từ ứng dụng Android của GameSir (`BluetoothLeService`, "get base info").

## Cách trình điều khiển hoạt động

`src/drivers/gamesir_ble.cpp`, được gọi trước cơ chế dự phòng XInput:

1. **Tìm tay cầm.** Tìm các giao diện thiết bị thuộc lớp `{00008650-0000-1000-8000-00805F9B34FB}`. Windows tạo một giao diện cho mỗi dịch vụ GATT của thiết bị BLE đã ghép nối. Trình điều khiển chỉ dùng các giao diện có nút cha `BTHLE\DEV_…` mang tên `GameSir-Cyclone…`.
2. **Đọc mức pin.** Mở dịch vụ đó bằng Win32 GATT API (`bluetoothleapis.h`, `-lbluetoothapis`), đăng ký nhận thông báo từ `0x865F` và ghi `01 01`. Đợi tối đa 3 giây để nhận phản hồi rồi tắt thông báo.
3. **Giữ chu kỳ quét nhanh.** Kết nối BLE có thể mất vài giây hoặc quá hạn khi tay cầm đang ngủ, nên truy vấn chạy trên luồng riêng:
   - tối đa mỗi 2 phút sau một lần đọc thành công, hoặc mỗi 1 phút sau một lần thất bại
   - vòng quét báo cáo giá trị lưu đệm và ngừng báo giá trị đó sau 6 phút cũ
   - `graceSec` sau đó giữ nó hiển thị mờ ở trạng thái đang ngủ
   - chỉ lần quét đầu tiên của một phiên chạy mới đợi luồng đó một lần với hạn chót tuyệt đối 4 giây, giúp mức pin hiện ngay khi khởi động và trong `--list`
4. **Ẩn mục Xbox giả.** Khi dongle hiện diện, trình điều khiển nhận quyền quản lý `3537:1015`:
   - luồng `Windows.Gaming.Input` bỏ qua các vendor/product ID đã có driver nhận
   - luồng XInput lấy vendor/product ID của từng khe qua `XInputGetCapabilitiesEx` (xinput1_4 ordinal 108) và bỏ qua những ID đã được nhận
   - khi hàm xuất đó không tồn tại, XInput hoạt động như trước đây

## Phần cứng đã thử nghiệm

Windows 11, Cyclone Pro trên dongle (`3537:1015`), đã ghép nối một lần qua Bluetooth, vào ngày 2026-11-18:

```text
GameSir Cyclone Pro  [2.4 GHz receiver (battery over Bluetooth LE)]  100%   (gamesir-ble:A05A598D2224)
```

Khi tay cầm ngủ, mục "Xbox controller 1 / Full" không còn xuất hiện và không hiển thị gì cho tay cầm nữa.

## Giới hạn

- **Ghép nối:** phải ghép nối tay cầm với Windows một lần (Settings > Bluetooth & devices > Add device > Bluetooth > `GameSir-Cyclone Pro`). Tay cầm chưa ghép nối không có giao diện thiết bị GATT. Việc ghép nối tạo thêm các mục gamepad Bluetooth nhưng chúng không gửi tín hiệu điều khiển trong khi tay cầm đang chơi qua dongle.
- **Yêu cầu Bluetooth:** PC cần có Bluetooth LE.
- **Một tay cầm:** mỗi PC chỉ đọc được một tay cầm Cyclone Pro.
- **Đang sạc:** không có phần trăm pin khi đang sạc.


---

<a id="sec-localization-guide"></a>
> 📄 **Mục:** Hướng dẫn sử dụng đa ngôn ngữ & bản địa hóa (`docs/i18n/README.md`) · [Bản gốc tiếng Anh](../../docs/i18n/README.md) · [↑ Lên đầu trang](#top)

# Chỉ mục đa ngôn ngữ & Hướng dẫn bản địa hóa BatteryHub

Mỗi tài liệu hiển thị trong kho lưu trữ này được gom thành **một tệp Markdown độc lập duy nhất cho mỗi ngôn ngữ** bên trong `docs/i18n/`, trong khi toàn bộ chuỗi văn bản chạy lúc vận hành của ứng dụng nằm trong **các tệp văn bản tĩnh có thể chỉnh sửa** bên trong [`lang/`](../../lang) (dùng chung cho Windows và Linux) và chuỗi văn bản của trình cài đặt Windows nằm trong [`installer/lang/`](../../installer/lang).

## Các ngôn ngữ được hỗ trợ (19)

| Mã | Ngôn ngữ | Tài liệu đầy đủ | Giao diện ứng dụng (Windows & Linux) | Trình cài đặt Windows |
|---|---|---|---|---|
| `en` | English | [README.md](../../README.md) | [`lang/_template.json`](../../lang/_template.json) (chuỗi nguồn) | [`installer/lang/en.isl`](../../installer/lang/en.isl) |
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

## Cách chuyển đổi ngôn ngữ hoạt động trong thực tế

### 1. Ứng dụng Windows (`BatteryHub.exe`)
- **Nhận diện tự động:** Khi đặt ở *Ngôn ngữ → Tự động (Theo ngôn ngữ Windows)*, BatteryHub truy vấn `GetUserPreferredUILanguages` của Windows và chọn tệp tĩnh `*.json` khớp gần nhất.
- **Chuyển thủ công:** Nhấp vào widget taskbar hoặc biểu tượng khay hệ thống → **Ngôn ngữ** → chọn một ngôn ngữ. Giao diện cập nhật ngay lập tức và lưu bền vững tại `HKCU\Software\WirelessBattery\Language`.
- **Tệp ngoài tĩnh (sửa được không cần biên dịch lại):** `BatteryHub.exe` nạp `<exe>\lang\*.json` trước, sau đó nạp `%APPDATA%\WirelessBattery\lang\*.json`. Mọi tệp trong thư mục người dùng có cùng `@code` sẽ ghi đè các câu tương ứng, và việc mở lại menu sẽ tự nạp lại tệp từ đĩa trực tiếp.
- **CLI `--help`:** `BatteryHub.exe --help` hiển thị hộp thoại trợ giúp bằng ngôn ngữ giao diện đang kích hoạt (`--list`, `--json` và `--dump` cố ý giữ bằng tiếng Anh để tiện gửi báo cáo lỗi GitHub).

### 2. Ứng dụng Linux (`wireless-battery`)
- **Nhận diện tự động:** Tuân theo thứ tự biến môi trường POSIX locale: `LANGUAGE` (danh sách phân tách bằng dấu hai chấm) → `LC_ALL` → `LC_MESSAGES` → `LANG` (trừ khi bị ghi đè bởi `LC_ALL=C` / `POSIX`).
- **Chuyển thủ công:** Nhấp chuột phải vào biểu tượng khay → **Ngôn ngữ** → chọn **Tự động (Theo ngôn ngữ hệ thống)** hoặc bất kỳ ngôn ngữ nào đã cài. Được lưu dưới khóa `[general] language=` trong `$XDG_CONFIG_HOME/wireless-battery/config.ini` (mặc định `~/.config/wireless-battery/config.ini`).
- **Đường dẫn tìm kiếm tĩnh (ưu tiên từ thấp đến cao):**
  1. `/usr/share/wireless-battery/lang/`
  2. `/usr/local/share/wireless-battery/lang/`
  3. `$XDG_DATA_HOME/wireless-battery/lang/` (mặc định `~/.local/share/wireless-battery/lang/`)
  4. `<executable_dir>/lang/`
  5. `$XDG_CONFIG_HOME/wireless-battery/lang/` (mặc định `~/.config/wireless-battery/lang/`)
- **CLI `--help`:** `wireless-battery --help` in hướng dẫn CLI đã dịch dựa theo `config.ini` hoặc locale hệ thống; `--list` và `--dump` vẫn giữ tiếng Anh.

### 3. Trình cài đặt Windows (`BatteryHub-Setup-<version>.exe`)
- Hiển thị hộp thoại chọn ngôn ngữ (`ShowLanguageDialog=yes`) chọn sẵn theo ngôn ngữ giao diện Windows của bạn (`LanguageDetectionMethod=uilanguage`).
- Cài đặt đầy đủ thư mục tĩnh `lang\*.json` vào `{app}\lang\` cạnh `BatteryHub.exe` (và bản ZIP portable cũng đóng gói kèm `lang\*.json`).

---

## Cách thêm hoặc cập nhật ngôn ngữ (từng bước)

Bạn **không** cần bất kỳ công cụ biên dịch nào để dịch giao diện ứng dụng hay tài liệu, và chỉ cần Inno Setup 6 nếu muốn tự biên dịch thử trình cài đặt Windows.

### Bước 1 — Chuỗi giao diện ứng dụng (`lang/<code>.json`)
1. Mở thư mục ngôn ngữ người dùng từ menu khay hệ thống (**Ngôn ngữ → Thêm ngôn ngữ tùy chỉnh...**) hoặc sao chép [`lang/_template.json`](../../lang/_template.json) thành `lang/<code>.json` (ví dụ `lang/it.json`).
2. Điền phần đầu siêu dữ liệu:
   ```json
   {
       "@code": "it",
       "@name": "Italiano",
       "@rtl": false,
       "Refresh now": "Aggiorna ora",
       "{name} is at {percent}%": "{name} è al {percent}%"
   }
   ```
3. Dịch phần vế phải sau dấu ` = ` trên mỗi dòng.
   - Giữ nguyên vẹn các placeholder như `{name}`, `{percent}`, `{version}`, `{days}`, `{hours}`, `{rate}`, `{count}`, `{monitor}`, `{number}`, `{seconds}`, `{minutes}`, `{page}`, `{reason}`, `{code}`.
   - Dùng `\n` khi cần ngắt dòng tường minh.
   - Lưu ở định dạng **UTF-8 (không BOM)**.
   - Mở lại menu khay hệ thống BatteryHub để xem trước ngay lập tức — không cần biên dịch lại!

### Bước 2 — Trình cài đặt Windows (`installer/lang/<code>.isl`)
1. Sao chép [`installer/lang/_template.isl`](../../installer/lang/_template.isl) thành `installer/lang/<code>.isl`.
2. **QUAN TRỌNG:** Lưu tệp ở định dạng **UTF-8 có BOM (`EF BB BF`)** để Inno Setup giải mã chuẩn các ký tự Unicode bất kể code page Windows cũ của máy.
3. Chọn mẫu phù hợp:
   - **Nếu Inno Setup đã tích hợp sẵn ngôn ngữ của bạn** (kiểm tra trong `C:\Program Files (x86)\Inno Setup 6\Languages\`): chỉ giữ lại `[CustomMessages]` và dịch 6 dòng (`AutostartTask`, `LaunchApp`, `SupportProject`, `CloseFailed`, `DirNotWritableAdmin`, `DirNotWritableUser`, giữ nguyên `%1` và `%n`). Đăng ký trong `installer/BatteryHub.iss` dưới mục `[Languages]`:
     ```ini
     Name: "it"; MessagesFile: "compiler:Languages\Italian.isl,lang\it.isl"
     ```
   - **Nếu Inno Setup chưa có sẵn ngôn ngữ của bạn**: sao chép `installer/lang/zh-CN.isl` làm mẫu tham chiếu đầy đủ, thiết lập `[LangOptions]` (`LanguageName`, `LanguageID`, `LanguageCodePage=0`, tùy chọn `RightToLeft=yes`), dịch `[Messages]` và `[CustomMessages]`, rồi đăng ký sau `Default.isl`:
     ```ini
     Name: "my"; MessagesFile: "compiler:Default.isl,lang\my.isl"
     ```
   - Lưu ý: định danh `Name:` trong `[Languages]` chỉ được chứa chữ cái ASCII, chữ số và dấu gạch dưới (dùng `ptBR`, không dùng `pt-BR`).

### Bước 3 — Trình khởi chạy Desktop Linux (`linux/wireless-battery.desktop`)
Thêm một dòng `Comment[<code>]=...` đã bản địa hóa (dùng dấu gạch dưới cho mã vùng trong tệp `.desktop`, ví dụ `Comment[zh_CN]=...`).

### Bước 4 — Tài liệu hoàn chỉnh trong một tệp (`docs/i18n/<code>.md`)
1. Sao chép [`docs/i18n/_template.md`](_template.md) thành `docs/i18n/<code>.md` (không cần bất kỳ script sinh tệp nào — chỉ cần duy nhất một tệp này!).
2. Dịch đầy đủ Mục lục và tất cả 17 mục trong khi giữ nguyên:
   - Tất cả thẻ neo `<a id="sec-..."></a>` và `<a id="top"></a>`
   - Tất cả khối mã, cờ CLI (`--list`, `--json`, `--dump`, `--report`, `--demo`, `--quit`, `--help`), USB `VID:PID`, HID usage page, gói tin hex, khóa registry, đường dẫn tệp và URL nguyên văn
   - Các đường dẫn ảnh/tệp tương đối nguyên văn (`../screenshot.png`, `../keychron_keyboard_firmware/k5_max_battery.patch`, `../../LICENSE`, v.v.)
3. Cập nhật thanh `<!-- lang-switcher:start -->` ở đầu tệp `docs/i18n/<code>.md` (in đậm ngôn ngữ của chính bạn, gắn liên kết cho mọi ngôn ngữ khác), đồng thời thêm liên kết tới ngôn ngữ của bạn trong các thanh chuyển đổi ngôn ngữ ở `README.md`, `CONTRIBUTING.md`, `docs/*.md`, `docs/keychron_keyboard_firmware/README.md`, `docs/i18n/README.md` và các tệp `docs/i18n/*.md` cùng cấp.
4. Đối với các ngôn ngữ viết từ phải sang trái (`ar`, `fa`, `he`), hãy viết Markdown chuẩn mà không bọc toàn bộ tệp trong `<div dir="rtl">` để bảng biểu và khối mã hiển thị gọn gàng.


---

<a id="sec-ardor-fury-v2"></a>
> 📄 **Mục:** ARDOR GAMING Fury V2 (`docs/ardor_fury_v2.md`) · [Bản gốc tiếng Anh](../../docs/ardor_fury_v2.md) · [↑ Lên đầu trang](#top)

# ARDOR GAMING Fury V2 (1D57:FA60)

Đầu thu 2.4 GHz phơi bày HID usage page `000A`, usage `0000`, với một input report dài 5 byte. Thiết bị tự phát quảng bá dữ liệu; không cần gửi bất kỳ lệnh HID nào.

Các báo cáo ghi nhận được từ phần cứng thật:

| Báo cáo | Pin |
|---|---|
| `03 00 40 33 07` | 50% |
| `03 00 40 73 08` | 75% |

Nibble cao của byte 3 mã hóa nấc pin (`1`, `3`, `7`, `F` tương ứng với 25, 50, 75 và 100 phần trăm). Các báo cáo cho mức 25% và 100% được suy ra từ logic giải mã của ứng dụng hãng; người dùng cuối sau đó đã xác nhận các mức còn lại hiển thị chính xác trong bản ứng dụng đã biên dịch. Byte thứ năm không cố định và không được dùng làm chữ ký nhận diện.

Bộ lắng nghe yêu cầu hai nấc pin đã giải mã khớp nhau, thay vì bắt buộc hai báo cáo toàn phần phải giống hệt nhau. Giá trị xác nhận gần nhất được giữ trong tối đa 45 giây. Chu kỳ tự động làm mới toàn cục đổi thành 15 giây.

Đã được người dùng cuối xác thực trên Windows với ARDOR Fury V2 và Logitech G733: bản ghi 50% và 75%, tự động cập nhật định kỳ, kiểm tra trực quan 25%/100% và khởi chạy bản portable. Các báo cáo thô cho 25% và 100% chưa được bắt gói tin trực tiếp.


---

<a id="sec-areson"></a>
> 📄 **Mục:** Areson `25A7` (`docs/areson.md`) · [Bản gốc tiếng Anh](../../docs/areson.md) · [↑ Lên đầu trang](#top)

# Hỗ trợ pin cho đầu thu Areson 25A7

## Vì sao chương trình ban đầu bỏ sót con chuột này

Redragon M915RGB-WL kết nối thông qua "2.4G Wireless Receiver" Areson/CompX `25A7:FA07`. Pin của nó không được khai báo qua HID *Battery Strength* chuẩn và Windows cũng không có thuộc tính pin Bluetooth cho nó, vì liên kết là kết nối riêng 2.4 GHz. Thay vào đó chuột trả lời một yêu cầu chủ động `GetPower`, nên cả cơ chế dự phòng HID chung lẫn Bluetooth đều không thấy nó. Trước đây chưa có trình điều khiển cho hãng này, nên đầu thu vẫn bị bỏ trống và im lặng.

## Phần cứng và gói tin ghi nhận được

Đã thử nghiệm trên Windows 11 với Redragon M915RGB-WL vào ngày 2026-11-17:

| Chiều | VID:PID | Giao diện | Usage page:usage | Kích thước báo cáo |
|---|---|---|---|---|
| yêu cầu (feature) | `25A7:FA07` | 1 | `FF02:0002` | 17 byte |
| phản hồi (input) | `25A7:FA07` | 1 | `FF01:0000` | 17 byte |

Phản hồi trả về trên một top-level collection khác với tập mà yêu cầu được ghi vào. Trên Windows đó là `MI_01&COL07` (feature) và `MI_01&COL05` (input), đó là lý do trình điều khiển mở cả hai handle.

Yêu cầu đã bắt được (`GetPower`, report ID `08`, lệnh `04`, checksum làm cho tổng cả khung bằng `0x55`):

```text
08 04 00 00 00 00 00 00 00 00 00 00 00 00 00 00 49
```

Phản hồi đã bắt được:

```text
09 04 00 00 00 02 08 00 00 00 00 00 00 00 00 00 3E
```

Các vị trí dưới đây tính cả report ID là byte số 0:

| Byte | Ý nghĩa | Ví dụ |
|---|---|---|
| 0 | Report ID phản hồi | `09` |
| 1 | Lặp lại mã lệnh (echo) | `04` |
| 2 | Trạng thái, 0 = OK | `00` |
| 3–4 | Địa chỉ, không dùng cho `GetPower` | `00 00` |
| 5 | Độ dài dữ liệu (2) | `02` |
| 6 | Mức pin, 0–10, theo bước 10% | `08` = 80% |
| 7 | Cờ đang sạc, bất kỳ giá trị khác 0 nào | `00` = không sạc |
| 16 | Checksum; tổng tất cả 17 byte bằng `0x55` (mod 256) | `3E` |

Phần mềm của chính hãng hiển thị 80% cho cùng khung dữ liệu này, qua đó khẳng định hệ số nhân ×10. `GetConnectStatus` (`08 03 …`) trả lời bằng payload 1 byte và đồng thời báo chuột đang liên kết.

## Các chuột Areson khác

Các đầu thu cũ hơn `FA7B` / `FA7C` dùng trên Redragon M693 báo cáo mức pin trực tiếp dưới dạng phần trăm nguyên tại cùng vị trí phản hồi. Áp dụng hệ số ×10 của trình điều khiển này lên chúng sẽ ra 800%, nên các product ID đó cố tình không được nhận quản lý. Chỉ xử lý `FA07` và `FA08`; `FA08` là định danh thay thế của cùng dòng sản phẩm và chưa được kiểm chứng trên máy thử nghiệm này.

## Chu kỳ hỏi và định danh

- Trình điều khiển chỉ gửi yêu cầu `GetPower` ở chế độ chỉ đọc. Không bao giờ ghi cấu hình, đèn LED hay dữ liệu DPI.
- Mỗi lần làm mới mở tập feature với quyền truy cập zero access và tập input để đọc, gửi yêu cầu và chờ tối đa 1,8 giây để nhận phản hồi, với hai lần thử kèm xóa hàng đợi ở giữa để tránh nhầm báo cáo cũ thành câu trả lời mới.
- Một lần đọc thất bại không nhận quản lý gì, nên chuột đang ngủ vẫn giữ giá trị cuối trên giao diện. Mục này dùng thời gian ân hạn 30 phút, khớp với các trình điều khiển thụ động khác.
- Khóa thiết bị được tạo từ vendor và product ID (`areson:25A7:FA07`), nên nó bền vững qua chu kỳ nhận/ngủ và khi rút cắm lại đầu thu.

## Kiểm chứng

Toàn bộ ứng dụng đã được biên dịch bằng MSVC C++17 cùng Windows SDK và chạy thử với con chuột thật. `BatteryHub.exe --list` trả về:

```text
Redragon wireless mouse  [2.4 GHz receiver]  80%   (areson:25A7:FA07)
HyperX Cloud II Wireless [2.4 GHz receiver]  14%, 3661 mV
```

Giá trị đọc được khớp với phần trăm hiển thị trên phần mềm Redragon chính thức tại cùng thời điểm. Tệp `build.bat` của MinGW đã bao gồm tệp nguồn mới; `Makefile` tự động phát hiện nó qua ký tự đại diện (wildcard).

## Nguồn giao thức

- [Qehbr/m913-ctl](https://github.com/Qehbr/m913-ctl): khung 17 byte, tách biệt feature/input và quy tắc checksum `0x55`, khôi phục từ bản bắt gói tin USB của phần mềm Redragon.
- [redragon-m913-battery-tray](https://github.com/Doomguy-BFG9000/redragon-m913-battery-tray): lệnh `GetPower` và thang chia bước 10% trên `25A7:FA07`.
- [redragon-mouse-linux PROTOCOL.md](https://github.com/rajchauhan28/redragon-mouse-linux/blob/main/PROTOCOL.md): bố cục phản hồi và thang phần trăm khác biệt trên dòng `FA7B` / `FA7C`.


---

<a id="sec-darkrim"></a>
> 📄 **Mục:** DARKRIM SHADOW (`docs/darkrim.md`) · [Bản gốc tiếng Anh](../../docs/darkrim.md) · [↑ Lên đầu trang](#top)

# Đầu thu DARKRIM SHADOW / 寸渊影弑

Đã thử nghiệm trên phần cứng thật với `3654:6901`, nhà sản xuất `Jieli Technology`, phiên bản phát hành `0100`. Dùng giao diện **3**, usage `FF02:0002`, payload input/output 64 byte không đánh số report ID (kích thước báo cáo Windows HID 65 byte). Giao diện 4 cũng có `FF02:0002`, nhưng dùng report ID 2 và không phản hồi giao thức này; nó bị loại trừ có chủ đích.

Nguồn giao thức: gói tải [PC Hub chính thức](https://app.darkrim.net/hub/zh.html), `DARKRIM-0.1.26-x64-setup.rar`, tải về và giải nén tĩnh mà không cài đặt hay khởi chạy phần mềm của hãng. Mã SHA-256 của tệp `DARKRIM.exe` trích xuất được:
`f20802587632dd3b36d0d602324931bc62174d55524d71277ab7a3c3ebecd86d`.

Các địa chỉ hữu ích trong tệp nhị phân đó:

- `140124C80`: `sendGetBasicInfo(infoType)` gửi lệnh `0010`, Request `01`, payload `[infoType, 00]`. Bộ chọn pin là `01`.
- `140118D30`, `140119200`: tạo phần đầu khung (frame header) và CRC.
- `140126DB0`: bộ phân tích TLV thông tin thiết bị; TLV `01` là pin.
- `1400F5660`, `1400FA700`: các hàm tiêu thụ dữ liệu pin; 7 bit thấp cho phần trăm, bit cao nhất là trạng thái đang sạc. Cùng giá trị pin đó cũng đi qua gói `0011` Notify `03`.

Phần đầu khung: `FE seq cmdLE type index count lengthLE`, theo sau bởi payload và CRC-16/CCITT-FALSE (đa thức `1021`, giá trị khởi đầu `FFFF`, lưu theo thứ tự big-endian). Số thứ tự `seq` là bộ đếm 4-bit khác 0; không sử dụng mã hóa.

Payload yêu cầu/phản hồi thực tế, trước khi đệm số 0 theo chuẩn HID:

```text
GET battery:  FE 03 10 00 01 00 01 02 00 01 00 9B 15
Response:     FE 03 10 00 02 00 00 03 00 01 01 28 96 0D
Notification: FE 00 11 00 03 00 00 03 00 01 01 28 C6 61
```

TLV phản hồi `01 01 28` cho **40%, không sạc**. Trình điều khiển C++ bản chính thức đã trả về đúng giá trị đó qua ba truy vấn liên tiếp mà không cần phần mềm hãng. Đầu thu phát ra các thông báo khởi động trước phản hồi khớp lệnh, đo được khoảng 406 ms. Dùng một mốc thời hạn phản hồi duy nhất 800 ms (cộng tối đa 200 ms cho thao tác ghi), không đặt lại mốc thời gian khi gặp các thông báo không liên quan. Không cần gửi gói heartbeat.

Trình điều khiển chỉ gửi gói GET pin. Nó chỉ chấp nhận phản hồi không mã hóa có đúng sequence/command/type khớp, index bằng 0, count bằng 0 hoặc 1 (phần cứng dùng 0), độ dài/CRC hợp lệ, và một TLV pin đúng cấu trúc. Các phản hồi bị phân mảnh, tự phát không đúng yêu cầu, sai định dạng hoặc vượt ngưỡng đều bị bỏ qua.

## Độ chính xác pin và trạng thái sạc ghi nhận được

Hãy coi phần trăm này là **ước tính thô, chưa được kiểm chứng ở độ phân giải 1%**. Thiết bị của chủ sở hữu hiển thị tiến trình sạc theo bước 10 điểm phần trăm từ 40% đến 90%. Ở mức 90%, năm phản hồi GET pin và một thông báo tự phát đều mang giá trị `DA`: `DA & 7F = 90`, với bit 7 chỉ báo đang sạc. Sau khi chủ sở hữu rút cáp sạc và tiếp tục dùng đầu thu 2.4 GHz, năm phản hồi GET tiếp theo và một thông báo nữa đều mang `5A`: vẫn là 90%, lúc này bit sạc đã xóa về 0. Cả mười hai khung đều vượt qua kiểm tra CRC.

Các phản hồi truy vấn tiêu biểu (số thứ tự 4):

```text
Charging:     FE 04 10 00 02 00 00 03 00 01 01 DA 70 ED
Not charging: FE 04 10 00 02 00 00 03 00 01 01 5A E1 65
```

Cả trình điều khiển lẫn ứng dụng chính thức đều lấy phần trăm trực tiếp từ 7 bit thấp. Trình điều khiển không làm tròn hàng chục, không nhân nấc với mười hay nội suy giá trị trung gian; các báo cáo giả lập 47% và 95% vẫn giữ nguyên là 47% và 95% trong bộ phân tích chính thức. Do đó các giá trị thô quan sát được bắt nguồn từ phía trên bộ phân tích, tức từ báo cáo của tai nghe/đầu thu. Hiện chưa quan sát thấy giá trị phần cứng chia nhỏ hơn. Một đường cong xả pin đầy đủ chưa được ghi lại, nên việc có cố định bước 10% ở mọi mức xả hay trên các bản firmware khác hay không vẫn chưa được xác nhận.

Trạng thái đang sạc và không sạc ngay sau đó ở mức 90% đã được kiểm tra trên phần cứng thật. Các ngưỡng pin cạn/đầy, hành vi khi tắt nguồn tai nghe, Bluetooth và chế độ truyền dữ liệu qua cáp USB chưa được thử nghiệm trên phần cứng thật. Không đưa ra cam kết hỗ trợ nào cho các chế độ đó. Không có lệnh cập nhật firmware, thay đổi cấu hình, lệnh EQ, thay đổi ghép nối, đặt lại thiết bị hay tệp nhị phân nào của hãng nằm trong phần triển khai này.

Kiểm thử: `g++ -std=c++17 tests/darkrim_driver_test.cpp src/drivers/darkrim.cpp -o build/darkrim_driver_test.exe`.


---

<a id="sec-hyperx-haste-2"></a>
> 📄 **Mục:** HyperX Pulsefire Haste 2 Wireless (`docs/hyperx_haste_2.md`) · [Bản gốc tiếng Anh](../../docs/hyperx_haste_2.md) · [↑ Lên đầu trang](#top)

# Giao thức pin HyperX Pulsefire Haste 2 Wireless

Được đọc bởi `HasteWireless` trong `src/drivers/hyperx.cpp`. Các truy vấn lấy từ [ngenuity-linux-cli](https://github.com/PMarinov1994/ngenuity-linux-cli) và giống hệt những gì NGENUITY sử dụng.

Đã kiểm chứng trên phần cứng thật:

- Pulsefire Haste 2 Core Wireless, dongle `03F0:0AB5`.
- Pulsefire Haste 2 Wireless, dongle `03F0:0F98`, bởi uzumakiprime (PR #312). Mức pin khớp với HyperX NGENUITY.

Dongle `03F0:0D97` dự kiến hoạt động tương tự nhưng chưa được thử nghiệm.

## Tập HID (HID collection)

| Trường | Giá trị (`0F98`) |
|---|---|
| Giao diện USB | `MI_02` (giao diện 2) |
| Usage page : usage | `FF00:0001` |
| Độ dài input / output / feature report | 64 / 64 / 64 byte |

Dongle cũng phơi bày các tập chuột và consumer-control tiêu chuẩn. Trình điều khiển chỉ mở một tập vendor (usage page từ `FF00` trở lên) có input report dài tối thiểu 8 byte.

## Các truy vấn

Cả hai đều là output report: hai byte đầu như bên dưới, phần còn lại đệm số 0 cho đủ độ dài báo cáo. Mỗi phản hồi là một input report có byte đầu tiên bằng mã lệnh cộng một. Mỗi truy vấn chờ tối đa một giây cho phản hồi và bỏ qua các báo cáo không liên quan (sau khi kết nối lại, dongle tự phát các báo cáo `44 xx`, `45 xx` và `FB xx`).

| Yêu cầu | Phản hồi | Ý nghĩa |
|---|---|---|
| `52 01` | `53 01 <linked>` | `linked` = 0 khi chuột đang tắt hoặc ngoài tầm phủ sóng |
| `50 02` | `51 02 <percent> <charge> .. .. <mV low> <mV high>` | `percent` 0-100; `charge` 1 = đang sạc, 2 = đầy trên đế sạc; điện áp tính bằng mV, little endian (bằng 0 trên bản Core) |

- Nếu thiếu phản hồi trạng thái liên kết, phản hồi pin sẽ quyết định.
- Nếu trạng thái liên kết báo 0, không gửi truy vấn pin và chuột hiển thị là đã tắt.
- Trong vài giây đầu sau khi chuột bật nguồn, nó báo khoảng 40%. Giá trị đọc được trong vòng 6 giây kể từ lúc liên kết được thiết lập sẽ bị bỏ qua, và khay hệ thống giữ nguyên giá trị cũ.

Cả hai yêu cầu chỉ đọc trạng thái. Không có gì làm thay đổi thiết lập, đèn LED hay chế độ hoạt động.


---

<a id="sec-inphic"></a>
> 📄 **Mục:** Inphic IN10 (`docs/inphic.md`) · [Bản gốc tiếng Anh](../../docs/inphic.md) · [↑ Lên đầu trang](#top)

# Dòng Inphic IN10, đầu thu KP 8K

Thiết bị gắn kèm, được chủ sở hữu xác nhận là IN10 MAX, khai báo là `Inphic KP 8K`, `1D57:FA65`, phiên bản phát hành `0116`. Tập trạng thái của nó nằm ở giao diện 2, usage `000A:0000`, độ dài input 5 (bao gồm report ID 03).

Quan sát thấy phát mỗi khoảng bốn giây mà không cần gửi yêu cầu nào:

```text
03 73 41 01 64
```

Bộ phân tích Xenta hiện có nhận diện định dạng này: mẫu máy, sự kiện, trạng thái pin, phần trăm. Cần hai báo cáo giống nhau trước khi hiển thị 100%; báo cáo đầu tiên ngay sau khi kết nối có thể là một giá trị đầy pin sai lệch trên các đầu thu cùng họ. Thay đổi này vẫn giữ cơ chế bảo vệ đó cùng hành vi sạc/ngủ hiện có.

Gói nguồn [Inphic HUB](https://hub.inphic.cn/) chính thức `assets/index-BcHQx9B6.js` ánh xạ mã mẫu thập phân 115 (`73`) sang `IN10RMax`, và 116 (`74`) sang `IN10Max`. Nó dùng trạng thái pin 1 cho phần trăm, 2 cho đầy pin và 3 cho đang sạc. Nên dùng tên mẫu từ firmware thay vì gán cứng `73` cho IN10 MAX và có nguy cơ gắn nhầm nhãn cho các thiết bị khác dùng chung đầu thu này.

Trước thay đổi này, ứng dụng liệt kê con chuột gắn kèm là `Wireless mouse`. Lớp truyền tải Xenta vốn đã xử lý các khung pin của nó; thay đổi này bổ sung tên mẫu còn thiếu. Một lần chạy `--list` mới tinh có thể hiện trạng thái đang ngủ vì cửa sổ quan sát ban đầu dài năm giây có thể chỉ kịp nhận một báo cáo chu kỳ bốn giây. Ứng dụng chạy nền sẽ giữ bộ lắng nghe mở và xác nhận giá trị ở các lần quét tiếp theo.

Đã kiểm chứng trên phần cứng thật: báo cáo thụ động, lặp lại mức 100% và nhận diện tên mẫu qua trình điều khiển gốc. Chuyển đổi trạng thái sạc, ngưỡng pin yếu, chế độ Bluetooth và chế độ cắm cáp chưa được kiểm chứng. Mẫu `74` được lấy từ bảng chính thức và chưa được thử nghiệm trên phần cứng riêng biệt.


---

<a id="sec-machenike"></a>
> 📄 **Mục:** Machenike L7 (`docs/machenike.md`) · [Bản gốc tiếng Anh](../../docs/machenike.md) · [↑ Lên đầu trang](#top)

# Machenike L7 Arctic / L7 Mix

Đã kiểm chứng trên một chiếc L7 Arctic tự khai báo là **L7 Mix**:

| Kết nối | VID:PID | Giao diện | Usage | Input / output / max feature |
| --- | --- | --- | --- | --- |
| Đầu thu 2.4 GHz | `248A:FF4C` | 1 | `008C:0001` | 33 / 33 / 1001 |
| Cáp USB | `248A:FF4E` | 2 | `008C:0001` | 33 / 33 / 1001 |

Trình điều khiển cũng kiểm tra tên sản phẩm HID `L7 Mix`. Các mẫu Machenike khác, ID đầu thu khác và truy vấn riêng qua Bluetooth hiện chưa được bật.

## Nguồn giao thức

Phân tích khả năng tương tác của phần mềm chính thức **Machenike L7 Mix 1.0.0.8**, tải từ [trang trình điều khiển của nhà sản xuất](https://haieronline.ru/catalog/computer-technology/accessories/l7-arctic/drivers/), và các truy vấn chỉ đọc trên chuột thật. Mã SHA-256 của `DeviceDriver.exe`:
`A73DF7F5199712E754864397630A2EAC198D0D238450A09ADE8851D2DA31B50D`.

Trong tệp thực thi 32-bit đó (image base `00400000`), hàm tại VA `00436750` dựng yêu cầu trạng thái; `004494F0` gửi nó qua `HidD_SetFeature` và đọc phản hồi feature. Bộ phân tích trạng thái `00410C20` trích xuất các trường bên dưới rồi chuyển trường pin và sạc lên giao diện. Đây là các địa chỉ ảo (virtual addresses), không phải offset trong tệp. Không có tệp thực thi độc quyền, mã nguồn ứng dụng hay tài nguyên nào của hãng được đưa vào đây.

## Truy vấn đọc trạng thái

Gửi **21 byte**, report ID `51`, lệnh `06`, tất cả các byte còn lại bằng 0:

```text
51 06 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
```

Đọc feature report `51`, cũng dài 21 byte. Kích thước feature tối đa 1001 của tập là dành cho các báo cáo khác; đó không phải độ dài của báo cáo trạng thái. Trình điều khiển đợi 10 ms trước khi đọc và dùng một mốc thời hạn duy nhất 200 ms cho mỗi sản phẩm, tính cả các phản hồi không liên quan. Nó không gửi bất kỳ lệnh thiết lập, chế độ, macro hay firmware nào.

Chỉ số byte tính cả report ID:

| Byte | Ý nghĩa / giá trị quan sát được |
| --- | --- |
| 0–1 | `51 06`, echo mã lệnh bắt buộc |
| 4–7 | `8A 24 4E FF`, chữ ký thiết bị L7 đã kiểm chứng |
| 10, bit 0–2 | Chế độ làm việc: 1 trên đầu thu, 0 trên cáp |
| 10, bit 3 | Chuột không dây đã kết nối; cũng bằng 0 khi cắm cáp USB |
| 11 | Phần trăm pin, 0–100 (giá trị 0 là hợp lệ) |
| 12 | Cờ sạc: 0 đang xả, 1 đang sạc |

Ý nghĩa các trường khác và checksum chưa được xác lập. Trình điều khiển không tự bịa ra checksum. Nó kiểm tra mã lệnh, độ dài, chữ ký thiết bị, chế độ và dải giá trị pin/sạc khi đã kết nối trước khi phát hành kết quả đọc.

Phản hồi đầu thu ghi nhận được, cũng trùng 64% trên ứng dụng chính thức:

```text
51 06 01 00 8A 24 4E FF 05 01 09 40 00 00 00 00 00 00 00 00 00
```

Phản hồi cáp USB ghi nhận được khi đang sạc (74%):

```text
51 06 01 00 8A 24 4E FF 05 01 00 4A 01 00 00 00 00 00 00 00 00
```

Tại thời điểm đó đầu thu vẫn trả về giá trị lưu đệm cũ 64%, nhưng đã xóa bit liên kết về 0:

```text
51 06 01 00 8A 24 4E FF 05 01 01 40 01 00 00 00 00 00 00 00 00
```

Giá trị đọc khi ngắt kết nối này không được phép làm lộ giá trị pin/sạc lưu đệm. Cáp được ưu tiên khi cả hai kết nối cùng hiện diện, và khóa thiết bị ổn định được dùng chung qua cả hai phương thức truyền tải. Một thiết bị L7 đã biết vẫn được giữ quyền sở hữu ngay cả khi truy vấn lỗi để trình điều khiển Ajazz chạy phía sau không thăm dò nó bằng giao thức khác trên cùng VID dùng chung.

## Phạm vi kiểm chứng

Bộ dữ liệu mẫu và kiểm thử truyền tải mô phỏng bao phủ các bản đọc đã bắt gói tin, trạng thái sạc, mức 0%/100% hợp lệ, đầu thu mất kết nối, phản hồi sai định dạng/cũ, khớp chặt chẽ, lỗi truyền tải, khử trùng lặp và vòng lặp thử lại có giới hạn. Mức 0%/100% trên thiết bị sống cùng mọi biến thể ngủ/firmware không được mặc nhiên suy ra từ các bài test đó.


---

<a id="sec-nuphy"></a>
> 📄 **Mục:** NuPhy WH80 (`docs/nuphy.md`) · [Bản gốc tiếng Anh](../../docs/nuphy.md) · [↑ Lên đầu trang](#top)

# NuPhy WH80 (cáp USB và Bluetooth)

Đã thử nghiệm trên phần cứng thật với `19F5:A011`, bản firmware `0116`, giao diện 1, usage `0001:0000`, payload input/output 64 byte không đánh số report ID (65 byte trong thông số HID của Windows).

Nguồn giao thức: [NuPhyIO](https://drive.nuphy.io/), gói `main.b3fb29e0.js`, hàm SDK `getBatteryState(0)`, `getDataPackage` và `createCommand`. Chỉ yêu cầu `GetFunc` (`05`), offset `0020`, độ dài `01`. Không cần bất kỳ lệnh khởi tạo, cấu hình, đèn LED hay firmware nào.

Payload yêu cầu, đệm số 0 cho đủ 64 byte:

```text
55 05 00 21 01 20 00 00
```

Payload phản hồi thực tế:

```text
AA 05 00 05 01 20 00 00 E4 00 ...
```

Byte 3 là byte thấp của tổng các byte 4..63. Pin nằm ở byte 8: `value & 7F` là phần trăm, `value & 80` là cờ đang sạc của SDK. Trình điều khiển C++ gốc đã trả về **100%, đang sạc** trên bàn phím đang gắn. Chuyển đổi trạng thái sạc và các ngưỡng cạn/đầy chưa được thử nghiệm trên phần cứng thật; ghi chú firmware chính thức mô tả giá trị đọc của WH80 theo bước nhảy 10%. Hoạt động qua đầu thu nằm ngoài phạm vi của trình điều khiển này.

## Bluetooth

Trên Bluetooth, cùng chiếc bàn phím đó dùng HID ID `19F5:324A` (bản `0129`) và phát tên hiển thị cho người dùng dạng như `NuPhy WH80 - 1`. Nó phơi bày hai tập bàn phím và một tập chuột. Bộ phỏng đoán HID chung ưu tiên chuột, nên hãy thêm chính xác ID Bluetooth này vào danh sách ghi đè phân loại bàn phím hiện có.

Việc báo pin tiếp tục dùng thuộc tính pin Bluetooth của Windows. Sau khi rút dây USB, Windows báo **95%** trên bàn phím đang kết nối. Một lần đọc không qua bộ đệm đối với GATT Battery Level chuẩn (`180F` / `2A19`) cũng trả về **95%** trực tiếp từ bàn phím. Đây là kết quả đọc của thiết bị/phương thức truyền tải tách biệt so với lần quan sát 100% qua dây; không được thay thế nó bằng giá trị giả định đầy hay quy đổi tỷ lệ lại. Nguyên nhân dẫn đến sự khác biệt giữa hai giá trị firmware hiện chưa được làm rõ.

Trình điều khiển kiểm tra chính xác mã sản phẩm/giao diện/kích thước báo cáo, phần đầu phản hồi, offset, độ dài, checksum và dải phần trăm. Nó dùng hạn chót phản hồi 400 ms và bỏ qua các phản hồi không liên quan trong cùng hạn chót đó.

Kiểm thử hồi quy:

```text
g++ -std=c++17 tests/nuphy_driver_test.cpp src/drivers/nuphy.cpp -o build/nuphy_driver_test.exe
build/nuphy_driver_test.exe
```


---

<a id="sec-rapoo"></a>
> 📄 **Mục:** Rapoo (`docs/rapoo.md`) · [Bản gốc tiếng Anh](../../docs/rapoo.md) · [↑ Lên đầu trang](#top)

# Hỗ trợ pin chuột Rapoo

## Vì sao chương trình ban đầu bỏ sót con chuột này

`PollAllDevices()` liệt kê các HID top-level collection của Windows một lần mỗi chu kỳ làm mới. Mỗi trình điều khiển hãng nhận diện một giao thức, thêm một `DeviceStatus` và nhận quyền sở hữu VID/PID của nó để các trình điều khiển chung không thêm trùng lại. Giao diện đã xử lý sẵn phần trăm, trạng thái sạc và giá trị gần nhất khi đang ngủ.

Trước đây chưa có trình điều khiển Rapoo. Chuột VT3 Max Gen 2 gửi mức pin trong một input report riêng của hãng chứ không dùng HID Battery Strength chuẩn hay thuộc tính pin Bluetooth của Windows. Do đó các cơ chế dự phòng HID/Bluetooth hiện có không thể giải mã đầu thu USB của nó.

## Phần cứng và gói tin ghi nhận được

Đã thử nghiệm trên Windows với chuột VT3 Max Gen 2 của chủ sở hữu vào ngày 2026-11-16:

| Kết nối | VID:PID | Giao diện | Usage page:usage | Kích thước input / output |
|---|---|---|---|---|
| Đầu thu 2.4 GHz | `24AE:1417` | 1 | `FF00:0002` | 19 / 19 byte |
| Cáp USB | `24AE:4617` | 1 | `FF00:0002` | 19 / 19 byte |

Cả hai đều tự nhận là `Rapoo Gaming Device`. Các tập khác bao gồm các ngõ vào chuột, bàn phím và đa phương tiện chuẩn, các tập cấu hình của hãng và một giao diện firmware 513 byte. Trình điều khiển pin chỉ mở `FF00:0002` với kích thước input được công nhận. Nó không bao giờ mở giao diện firmware và không bao giờ gửi output report, feature report, gói bắt tay hay lệnh cấu hình nào.

Báo cáo không dây ghi nhận được, bao gồm cả report ID:

```text
07 20 03 20 03 20 03 01 19 00 04 84 00 17 46 00 02 03 BC
```

Báo cáo qua cáp/đang sạc ghi nhận được:

```text
07 22 03 20 03 20 03 02 19 00 04 84 00 17 46 00 02 03 00
```

Các vị trí dưới đây tính report ID là byte số 0, khớp với `HidDev::Read()` của dự án:

| Byte | Ý nghĩa | Ví dụ |
|---|---|---|
| 0 | Report ID | `07` |
| 1 nibble thấp | Kết nối: 0 đầu thu, 1 Bluetooth, 2 cáp | `20` / `22` |
| 1 nibble cao | Thông tin cảm biến; không phải phần loại kết nối | `2` |
| 2 | Nấc DPI hiện tại | `03` |
| 3–4, 5–6 | DPI X/Y, little endian | `0320` = 800 |
| 7 | Trạng thái pin: 0 không hợp lệ, 1 đang xả, 2 đang sạc | `01` / `02` |
| 8 | Phần trăm pin, 0–100 | `19` = 25% |
| 13–14 | Product ID của chuột, little endian, khi có mặt | `4617` |

Bản bắt trực tiếp từ đầu thu báo `25%`, và ứng dụng hoàn chỉnh sau đó trả về `27%, đang sạc` qua cáp. Bài kiểm thử bộ phân tích có chứa bản bắt gói tin không dây thực tế. Trạng thái sạc và kết nối qua cáp cũng đã được kiểm chứng trên phần cứng thật; chúng không được suy đoán chỉ từ việc thấy thiết bị USB đang cắm. Sau khi chủ sở hữu rút cáp và cắm lại đầu thu, tệp thực thi hoàn chỉnh trả về `52%` qua `2.4 GHz receiver`, không còn cờ sạc và vẫn giữ nguyên khóa `rapoo:4617`. Điều này cũng xác minh quá trình chuyển đổi từ cáp sang đầu thu trên phần cứng thật.

Cũng đã thử nghiệm trên Windows với một chiếc **VT9 Gen 2** vào ngày 2026-11-17:

| Kết nối | VID:PID | Giao diện | Usage page:usage | Kích thước input / output |
|---|---|---|---|---|
| Đầu thu 2.4 GHz | `24AE:1414` | 1 | `FF00:0002` | 16 / 16 byte |
| Cáp USB | `24AE:4614` | 1 | `FF00:0002` | 19 / 19 byte |

Đầu thu VT9 Gen 2 phơi bày báo cáo `FF00:0002` dài **16 byte** thay vì 19 byte, nhưng dùng chung hoàn toàn bố cục Nordic 54L `07` (bao gồm cả PID `4614` nhúng ở các byte 13–14). Các khung đã bắt được:

```text
07 10 03 40 06 40 06 01 64 00 03 01 00 14 46 01             # receiver: 100%, discharging
07 12 04 80 0C 80 0C 02 64 00 03 01 00 14 46 01 02 02 00    # USB cable (switch ON): 100%, charging
```

Qua cáp USB, các báo cáo trạng thái được quan sát thấy phát ra khi có tương tác (ví dụ đổi DPI); khi công tắc nguồn ở đáy chuột gạt sang OFF trong lúc vẫn cắm dây, chuột báo `state=2, percent=1` thay cho phần trăm pin thực tế.

### Đầu thu VT3 Max Gen 2 với tập dài 13 byte (issue #1396)

Một báo cáo từ biểu mẫu yêu cầu thiết bị cho cùng ID đầu thu `24AE:1417` đã liệt kê một bố cục giao diện khác: `FF00:0002` dài **13 / 13** byte (thay vì 19), và `FF00:000E` dài 33 / 33 byte, không có tập firmware 513 byte. Đây có vẻ là một bản firmware khác của đầu thu. Phần mềm Rapoo vẫn hiển thị được pin, tức là trình điều khiển cũ đã bỏ qua một kênh trạng thái hoạt động bình thường.

Bộ giải mã `VT_nrf54L` (`py`) của Rapoo Hub thích ứng theo độ dài: nó luôn đọc DPI, trạng thái pin và phần trăm, và chỉ đọc các trường phía sau (PID chuột tại `n[12..13]`, thông tin RF, ...) khi báo cáo đủ dài. Bản kê của VT3 MAX (`productId: [17943, 5143]`) không có kiểu input-report đặc biệt nào, nên báo cáo `07` cũng đi qua bộ giải mã đó trên đầu thu này. Một báo cáo dài 13 byte (ID cộng 12 byte) vẫn mang trạng thái ở byte 7 và phần trăm ở byte 8; chỉ thiếu PID chuột nhúng bên trong, nên giá trị đọc dùng PID đầu thu và vẫn giữ khóa `rapoo:4617`.

Độ dài 13 byte **chỉ được chấp nhận riêng cho `24AE:1417`**. Các khung vẫn phải vượt qua những bước kiểm tra tương tự (báo cáo `07`, nibble kết nối 0–2, trạng thái 1/2, phần trăm 0–100). Chưa bắt được khung 13 byte trực tiếp từ phần cứng thật; các bài kiểm thử dùng bản bắt 19 byte đã thử nghiệm cắt gọn xuống 13 byte.

## Các chuột Rapoo khác

Rapoo Hub chính thức dùng bố cục `07` này cho trình điều khiển chuột Nordic 54L. Các bản kê của nó liệt kê VT0, VT1, VT2, VT3, VT3S, VT7, VT9 và nhiều biến thể bổ sung. Kiểm tra gói phần mềm hiện tại phát hiện 69 biến thể VT sử dụng `VT_nrf54L`; đây là bằng chứng cho một giao thức dùng chung, chứ không phải 69 lần kiểm chứng trên phần cứng thật hay cam kết bao phủ hầu hết danh mục sản phẩm Rapoo. Hỗ trợ được kích hoạt dựa theo Rapoo VID, tập chuyên dụng, độ dài input và báo cáo trạng thái hợp lệ, nên một mẫu chưa liệt kê nhưng chạy cùng giao thức vẫn có thể báo pin. Một bảng tên nhỏ bao phủ các mẫu phổ biến; các mẫu khác giữ nguyên tên sản phẩm HID hoặc hiển thị `Rapoo wireless mouse`.

Tên sản phẩm và ID có thể khác nhau tùy thế hệ và khu vực. Cặp `1417/4617` đã thử nghiệm được gọi là `VT3 MAX` trong bản kê chính thức hiện hành; chủ sở hữu xác nhận nó là VT3 Max Gen 2. Một mẫu riêng `VT3 MAX V2` trong bản kê hiện hành lại có ID `1B06/4B06`. Các bảng do cộng đồng tổng hợp gán `1417` cho VT9 Pro không được dùng làm cơ sở duy nhất để đặt tên hay nhận diện thiết bị này.

Firmware VT đời cũ hơn, được ghi nhận cho VT3 Pro (`1215/4415`), lại đẩy một báo cáo 7 byte trên cùng usage `FF00:0002`:

```text
BB B0 [mode] [DPI low] [DPI high] [battery state] [percentage]
```

Với định dạng cũ này, trạng thái 1/2 nghĩa là đang xả/đang sạc. Phần trăm khi sạc bằng `7F` nghĩa là không rõ và được giữ nguyên là không rõ. Trạng thái chuyển tiếp 0, các báo cáo `BC` không liên quan, gói sai định dạng và phần trăm lớn hơn 100 đều bị bỏ qua. Hỗ trợ định dạng cũ đã có kiểm thử tự động, nhưng chưa được xác minh trực tiếp trên chuột đời cũ tại đây. Cách diễn giải này bị giới hạn nghiêm ngặt cho các product ID `1215/4415` (VT3 Pro), `1233/4433` (VT1 Pro Max) và tập input 7 byte của chúng.

Mẫu VT1 Pro Max (đầu thu `24AE:1233`, cáp `24AE:4433`, firmware chuột 222, firmware dongle 213) được bổ sung từ các bản bắt USBPcap do chủ sở hữu đính kèm trong issue #136. Đầu ra `--dump` liệt kê tập `FF00:0002` dài 7 byte trên giao diện 1, và các bản bắt gói tin cho thấy nó tự đẩy lên mà không cần yêu cầu nào từ ứng dụng Rapoo:

```text
BB B0 71 84 03 01 64   receiver, every ~3.2 s; Rapoo app showed 100%
BB B0 71 84 03 02 5F   cable, charging, 95%; Rapoo app showed "Charging"
```

Trên cáp, báo cáo này chỉ xuất hiện một lần trong bản bắt dài 16 giây, nên việc đọc chỉ qua cáp có thể quá hạn ở một số lần làm mới; còn đầu thu thì đẩy đều đặn. Hồ sơ Nordic không bao giờ diễn giải các gói `BB`.

Điều này **không** đồng nghĩa hỗ trợ mọi thiết bị Rapoo. Các mẫu dùng chip CH584 như VT1 SE và VT7 SE dùng báo cáo `08` trong trình điều khiển chính thức và không được bộ giải mã này hỗ trợ. Các phiên bản Telink khác dùng cách hiểu khác đối với cờ `BB`, một số mẫu văn phòng dùng truy vấn pin chủ động, còn các mẫu Bluetooth có thể chỉ lộ thuộc tính pin của Windows. Những thiết bị đó vẫn dùng các cơ chế dự phòng hiện có hoặc cần một phần triển khai riêng đã kiểm chứng. Không được gửi các truy vấn đoán mò tới chúng.

## Chu kỳ hỏi và định danh

- Việc đọc là thụ động. Các handle `FF00:0002` khớp được giữ mở giữa các lần quét (tương tự `PollXenta`) để Windows lưu đệm các khung trạng thái gửi tới trong suốt khoảng làm mới 60 giây; mỗi lần quét sẽ rút sạch mọi khung đang xếp hàng (giữ lại kết quả pin hợp lệ mới nhất) trước khi lùi về chờ 5 giây ở lần mở đầu tiên hoặc khi hàng đợi rỗng. Thiết bị bị rút ra sẽ được gỡ bỏ và đóng handle. Các gói tin không liên quan không làm đặt lại mốc thời hạn.
- PID chuột nhúng bên trong, hoặc cặp cáp/đầu thu đã biết đối với thiết bị đời cũ, mang lại cùng một khóa giao diện qua các lần thay đổi dây cáp. Giá trị đọc qua cáp và đầu thu được gộp thành một mục duy nhất, ưu tiên trạng thái của cáp trong khi vẫn giữ phần trăm hợp lệ từ đầu thu nếu cáp báo mức không rõ.
- Hết thời gian chờ (timeout) không tự bịa ra phần trăm hay chiếm quyền quản lý thiết bị. Sau khi đọc thành công một lần, giao diện hiện có thể giữ lại giá trị đó ở trạng thái mờ trong 30 phút im lặng.
- Mô hình định danh theo VID/PID hiện tại của chương trình không thể phân biệt nhiều con chuột giống hệt nhau có cùng mã mẫu. Chưa thử nghiệm cắm đồng thời cáp và đầu thu trên phần cứng thật; việc hợp nhất cả hai đầu vào được kiểm thử qua bài test truyền tải mô phỏng.

## Kiểm chứng

`make test` chạy bài kiểm thử bộ giải mã đa nền tảng và bài kiểm thử trình điều khiển Windows với phản hồi HID mô phỏng. Phạm vi kiểm thử bao gồm bản bắt gói tin thực tế, 0% và 100%, đang sạc, thiếu mức pin, khung không hợp lệ/bị cắt cụt, tập/hãng không được hỗ trợ, cô lập hồ sơ giao thức, timeout, khóa ổn định và khử trùng lặp cáp/đầu thu mà không làm mất phần trăm đã biết.

Toàn bộ ứng dụng đã được biên dịch cục bộ bằng MSVC C++17 và Windows SDK, đồng thời chạy `--list` / `--dump` trực tiếp với con chuột thật. Bản dựng MinGW được duy trì đã đưa `rapoo.cpp` vào `build.bat`; Makefile tự động nhận diện nó. Bản thân MinGW chưa được cài trong môi trường kiểm thử.

## Nguồn giao thức

- [Rapoo Hub chính thức](https://hub.rapoo.cn/), kiểm tra ngày 2026-11-16: [trình điều khiển JavaScript và bảng kê đóng gói sẵn](https://hid.rapoo.cn/AHUB_WEB/dist/assets/js/index-exv-sdE5.js). Các bộ giải mã liên quan là `py`/`Hk` cho `VT_nrf54L` và `qM`/`QM` cho ý nghĩa kết nối và trạng thái pin. Bộ xử lý riêng `VT_CH584` đọc báo cáo `08` và nằm ngoài phần triển khai này. Tên hàm bị rút gọn (minified) có thể thay đổi ở các bản phát hành sau.
- [Device-Battery-Info: RapooProtocol.cs](https://github.com/PyFlat/Device-Battery-Info/blob/4553297903ecfb20e55116014b8ec437deaf640d/src/DeviceBatteryInfo/Sources/Rapoo/RapooProtocol.cs), cho báo cáo VT3 Pro đời cũ, trạng thái sạc và giá trị đánh dấu mức không rõ.
- Các bản bắt gói tin USBPcap ở issue #136 (VT1 Pro Max trên đầu thu và trên cáp khi đang sạc).
- [ClickSync: protocol_api_rapoo.js](https://github.com/Nuitfanee/ClickSync/blob/3a945428b25bf6b2db0e8750f819666caff9cda5/src/protocols/protocol_api_rapoo.js) xác thực độc lập các gói trạng thái thụ động `07` và vị trí byte pin. Bộ phân tích của dự án đó ép biên các phần trăm không hợp lệ; phần triển khai ở đây chọn loại bỏ chúng.


---

<a id="sec-rawm"></a>
> 📄 **Mục:** RAWM (`docs/rawm.md`) · [Bản gốc tiếng Anh](../../docs/rawm.md) · [↑ Lên đầu trang](#top)

# Ghi chú giao thức RAWM

Chuột RAWM (và SADES Dagger dùng chung nền tảng) giao tiếp với ứng dụng RAWM HUB qua một tập HID của hãng, `FF00:0001`, với các input và output report 64 byte không đánh số report ID (65 byte nếu tính cả report ID). Đầu thu và chuột sử dụng Vendor ID của Nordic là `1915`.

Nguồn: ứng dụng web RAWM HUB, Hub Web 2.0 (<https://www.rawmtech.com/hub.html>), và script của nó `https://hub.miracletek.net/hub/js/library.min.js` (đã làm rối mã; tên hàm và hằng số bên dưới là tên gốc trong script đó). Các product ID được hỗ trợ lấy từ bảng thiết bị mà ứng dụng tải về (`https://www.miracletek.net/game/device.php`). Leviathan V4 GT và NYX60 dùng Hub Web 3.0 trên VID `373E`, đây là một giao thức khác.

## Gói tin

Byte 0 của mỗi báo cáo (sau report ID):

| Các bit cao | Ý nghĩa |
|---|---|
| `0x80` (`PACKET_TYPE_EVENT_DATA`) | 6 bit thấp là kích thước payload; payload nối tiếp luồng sự kiện |
| `0x40` (`PACKET_TYPE_BUFFER_SIZE`) | kiểm soát luồng (kích thước bộ đệm trống); bỏ qua ở đây |
| `0xC0` (`PACKET_TYPE_EXTENDED`) | 6 bit thấp là kênh ESB; phần còn lại của báo cáo là gói tin cho kênh đó. Chuột phía sau đầu thu là kênh 0 |

Các payload tạo thành một luồng byte gồm các sự kiện:

```
FF FF FF FF                      sync (device to host only)
cmd | ((len >> 4) & 0xF0), len   len includes these two bytes (12 bits)
body ...
```

## Đọc mức pin

Trình điều khiển lặp lại đúng thao tác ứng dụng làm khi đầu thu được kết nối (`send_event_query`, `send_event_ping`):

1. Gửi tới đầu thu: `00 8D 01 0D 03 00 00 <unix time, 8 bytes LE>` (`CMD_QUERY`, OS = PC), sau đó ping `00 84 0E 04 00 00`. Thiết bị chỉ gửi dữ liệu khi máy chủ còn tiếp tục ghi, nên máy chủ phải ping. Đầu thu trả lời `CMD_QUERY_RESULT` (`02`) bằng JSON, ví dụ `{"r":"2.0.2","rc":4,"dn":"RAWM HS Receiver","pi":9030,"vi":6421,...}`.
2. Thực hiện cùng truy vấn và các gói ping cho kênh 0, thêm tiền tố `C0`. Chuột trả lời bằng một đối tượng JSON ~550 byte chia thành các đoạn ESB 30 byte, ví dụ `{"r":"1.2.0","dn":"LEVIATHAN V4","pi":9034,"vi":6421,"battery":100,"chr":0,...}`. `battery` là phần trăm (RAWM HUB hiển thị nguyên giá trị này), `chr` bằng 1 khi đang sạc.
3. Các thay đổi về sau đến dưới dạng `CMD_NOTIFY` (`0B`) loại `17`: `[17, percent, charging]`.

Trình điều khiển luôn hỏi đầu thu trước giống như ứng dụng hãng (trong một thử nghiệm, gửi truy vấn chỉ tới kênh 0 không nhận được phản hồi nào). Chuột đang ngủ sẽ không trả lời gì cả; còn đầu thu thì vẫn trả lời.

Truy vấn có mang đồng hồ PC vì ứng dụng hãng gửi theo cách đó; không có gì khác được ghi xuống thiết bị. Chuột báo `"crc":1`, báo cho ứng dụng biết cần bọc các lệnh sau đó (cấu hình) trong khung CRC-16; truy vấn và các gói ping được chấp nhận không cần CRC, giống cách ứng dụng gửi trước khi biết giá trị đó.

Đã thử nghiệm trên Leviathan V4 (firmware 1.2.0) với đầu thu RAWM HS Receiver `1915:2346` (firmware 2.0.2).


---

<a id="sec-vaxee"></a>
> 📄 **Mục:** VAXEE (`docs/vaxee.md`) · [Bản gốc tiếng Anh](../../docs/vaxee.md) · [↑ Lên đầu trang](#top)

# Đầu thu VAXEE 4K/8K và ZYGEN NP-01S V2

## Phạm vi và kiểm chứng phần cứng

Trình điều khiển này hỗ trợ đầu thu VAXEE 4K `3057:1002`, đầu thu VAXEE 8K `3057:2002` và chuột ZYGEN NP-01S V2 Wireless qua cáp USB (`3057:1011`), trên tập vendor `FF05:0001` của chúng với feature report 64 byte. Các đầu thu VAXEE khác, các product ID cáp khác và các thiết bị ZOWIE cố tình không bị thăm dò.

Đầu thu 8K (`VAXEE 8K Wireless`, ghép đôi với NP-01 Ergo Wireless 8K) đã được thử nghiệm trên Windows và báo pin qua cùng giao thức:

```
VAXEE 8K Wireless  [2.4 GHz receiver]  70%
```

Đầu thu này dùng chung cho mọi chuột VAXEE 8K và không báo cáo cụ thể con chuột nào đang ghép đôi, nên nó hiển thị bằng tên của chính đầu thu. Trạng thái sạc trên đầu thu 8K hiện chưa được quan sát trực tiếp trên phần cứng thật.

Một đầu thu 4K thật đã được thử nghiệm trên Windows:

```
VAXEE collection: page=FF05 usage=0001 featureLength=64
VAXEE battery: 70%; charging: no
```

Ứng dụng tích hợp cũng báo cáo:

```
VAXEE wireless mouse  [2.4 GHz receiver]  70%
```

Sau đó cắm trực tiếp chính con chuột đó qua USB và Windows nhận diện nó là `ZYGEN NP-01S V2 Wireless` (`3057:1011`). Trình điều khiển bản chính thức đã cập nhật báo cáo:

```
VAXEE battery: 75%; charging: yes
```

Widget trên thanh tác vụ đã được tạo thành công trong bản build đầu thu ban đầu. Cả hoạt động dùng pin qua đầu thu lẫn sạc có dây đều đã được quan sát; chuyển đổi khi sạc đầy và hành vi ngủ/tắt nguồn chưa được thử nghiệm trên phần cứng thật. Phần giải mã trạng thái sạc và xử lý phản hồi không hợp lệ được bao phủ bằng các phản hồi mô phỏng.

## Giao thức

Nguồn: [stuffz/mouse-battery-monitor, docs/VAXEE.md](https://github.com/stuffz/mouse-battery-monitor/blob/main/docs/VAXEE.md).

Mỗi yêu cầu là một HID feature report 64 byte đệm số 0:

| Byte | Giá trị |
|---|---|
| 0 | `0E`, report ID |
| 1 | `A5`, phần đầu (header) |
| 2 | `0B` cho mức pin; `10` cho trạng thái sạc |
| 3 | `01`, cờ đọc (không bao giờ dùng `02`, ghi) |
| 4 | `01`, độ dài dữ liệu |
| 5–63 | `00` |

Sau khi gửi yêu cầu bằng `HidD_SetFeature`, đợi 100 ms rồi đọc báo cáo `0E` bằng `HidD_GetFeature`. Yêu cầu tối thiểu sáu byte cùng report ID, header, echo mã lệnh và độ dài dữ liệu khớp đúng kỳ vọng.

Với pin, byte 5 của phản hồi phải nằm trong khoảng 0–20 và được nhân với năm, cho kết quả 0–100% theo bước 5%. Với trạng thái sạc, byte 5 khác 0 nghĩa là đang sạc. Một truy vấn trạng thái sạc bị lỗi không làm hủy bỏ kết quả đọc pin hợp lệ.

Trình điều khiển thử lại yêu cầu pin một lần. Tối đa có ba yêu cầu đọc cho mỗi tập khớp (hai lần thử đọc pin và một truy vấn trạng thái sạc), với tổng thời gian trễ chủ động là 300 ms. Nó không gửi bất kỳ lệnh thiết lập, ghép nối, firmware hay đèn LED nào.

Nếu không nhận được phản hồi pin hợp lệ, trình điều khiển không báo cáo gì và để thiết bị ở trạng thái chưa nhận quản lý. Trong khi tập USB vẫn hiện diện, giao diện giữ lại mức đọc thành công trước đó ở trạng thái mờ trong tối đa 30 phút bằng cơ chế thời gian ân hạn sẵn có. Nếu tập vật lý biến mất, trình điều khiển phát ra một trạng thái ngắt kết nối để kết thúc ngay thời gian ân hạn đó. Điều này ngăn biểu tượng đầu thu cũ bị kẹt lại khi người dùng chuyển dây cáp sang cắm trực tiếp vào chuột.

## Kiểm thử

`make test` bao gồm `tests/vaxee_driver_test.cpp`, liên kết trình điều khiển bản chính thức với lớp truyền tải HID mô phỏng. Bài test kiểm tra chính xác các yêu cầu chỉ đọc gửi ra, quy đổi phần trăm, giải mã đang sạc, phản hồi sai hoặc thiếu, thiết bị đã có driver nhận và lọc chính xác tập HID.
