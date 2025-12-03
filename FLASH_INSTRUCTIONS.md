# Flashing Instructions

## Method 1: PlatformIO Flash (RECOMMENDED - SAFE)

**⚠️ DO NOT USE esptool - IT CAN BRICK THE BOOTLOADER ⚠️**

1. Install PlatformIO
2. Create new ESP32 Dev Module project
3. Replace `src/main.cpp` with provided `main.cpp`  
4. Put ESP32 in bootloader mode:
   - Hold BOOT button
   - Press RESET while holding BOOT
   - Keep BOOT held for 3+ seconds
   - Release BOOT
5. Flash: `pio run --target upload`

## Method 2: Build from Source

1. Install PlatformIO
2. Create new project for ESP32 Dev Module
3. Replace `src/main.cpp` with the provided `main.cpp`
4. Copy `platformio.ini` to project root
5. Build: `pio run`
6. Put ESP32 in bootloader mode (see above)
7. Flash: `pio run --target upload`

## After Flashing

- Device shows psychedelic effects (no clock initially)
- WiFi network "PsyClock" appears
- Connect with password: clockset123
- Browse to 192.168.4.1 for clock controls
- Press BOOT button to cycle effects