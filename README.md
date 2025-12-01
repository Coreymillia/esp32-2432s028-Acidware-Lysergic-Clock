# ESP32 Psychedelic Clock - 60 Visual Effects

Transform your ESP32-2432S028 into a mesmerizing display with 60 unique psychedelic effects.

## Quick Flash (Recommended)

```bash
# Flash the ready-to-use binary
esptool.py --chip esp32 --port /dev/ttyUSB0 write_flash 0x10000 PsyClockNov25_17-35.bin
```

**After flashing:**
- Device boots showing screensavers (no clock)
- Connect to "PsyClock" WiFi network (password: clockset123)
- Browse to 192.168.4.1 to toggle clock display and set time
- Press BOOT button to cycle through 60 effects

## Build from Source

1. Install PlatformIO
2. Put `main.cpp` in `src/` folder
3. Copy `platformio.ini` to project root
4. Build: `pio run`
5. Flash: `pio run --target upload`

## Hardware

- ESP32-2432S028 board
- 2.8" ILI9341 display (320x240)
- Touch controller (cycles effects)

## Features

- 60 unique visual effects
- WiFi AP for clock setup
- Clock overlay (optional)
- Touch and button control
- 896KB optimized firmware

## Effects Categories

Mathematical fractals, particle systems, cosmic displays, retro gaming nostalgia, natural phenomena, and abstract art.

Press BOOT button to cycle through all 60 effects manually.