# HyperX Pulsefire Haste 2 Wireless battery protocol

Verified on a HyperX Pulsefire Haste 2 Wireless using its 2.4 GHz receiver. The battery percentage returned by this protocol matched the percentage shown by HyperX NGENUITY during testing.

## HID collection

| Field | Value |
|---|---|
| VID:PID | `03F0:0F98` |
| USB interface | `MI_02` (interface 2) |
| Usage page | `FF00` |
| Usage | `0001` |
| Input report length | 64 bytes |
| Output report length | 64 bytes |
| Feature report length | 64 bytes |

The receiver also exposes standard mouse and consumer-control collections. The battery protocol is on the vendor-defined `FF00:0001` collection.

## Battery query

Send a 64-byte output report whose first two bytes are `50 02` and whose remaining bytes are zero-padded. The matching input report starts with `51 02`; the battery percentage is at byte index 2 (zero-based). Accept values from 0 through 100.

The driver uses a one-second absolute response timeout and performs no configuration, lighting, or mode changes.
