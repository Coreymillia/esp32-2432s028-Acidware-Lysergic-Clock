# ESP32 Psychedelic Clock ✨

**Successfully created and tested on November 21, 2024**

## 🎉 What We Built
Converted Python screensaver programs into a stunning psychedelic clock for ESP32-2432S028 display!

## ✅ Files Created
- `psychedelic_clock_v1.0.bin` - **Ready-to-flash firmware** (333KB)
- `psychedelic_clock_v2.ino` - Arduino source code (improved version)
- `psychedelic_clock_pio/` - PlatformIO project folder

## 🎨 Features
- **3 Psychedelic Animation Modes:**
  - **Plasma Field**: Mathematical sine wave patterns with flowing colors
  - **Kaleidoscope**: Rotating mirrored symmetrical patterns
  - **Mandelbrot Set**: Animated fractal zoom and pan
- **Internal Clock**: Shows uptime timer (HH:MM:SS from boot)
- **Button Control**: Press BOOT button to cycle through modes
- **Smooth Animation**: ~20 FPS for fluid motion
- **Low Memory Usage**: Only 7.2% RAM, 25.4% Flash

## 📱 Hardware Compatibility
- **ESP32-2432S028** ("Cheap Yellow Display")
- **240x320 ILI9341 Display** ✅
- **Built-in buttons** for mode switching
- **Optional**: DS3231 RTC module for real-time clock

## ⚡ Quick Flash Instructions
```bash
# Put ESP32 in bootloader mode:
# 1. Hold BOOT button
# 2. Press RESET while holding BOOT  
# 3. Keep BOOT held for 3+ seconds
# 4. Release BOOT button

# Flash the firmware:
esptool.py --port /dev/ttyUSB0 --baud 460800 write_flash 0x1000 psychedelic_clock_v1.0.bin
```

## 🎯 Controls
- **BOOT Button**: Cycle through animation modes
- **Power Cycle**: Reset to Mode 0 (Plasma Field)

## 🌈 Technical Details
- **Color Palette**: 256-color RGB565 psychedelic gradients
- **Mathematical Algorithms**: Ported from Python screensaver collection
- **Real-time Generation**: All patterns computed live (no pre-stored animations)
- **Memory Optimized**: Direct pixel manipulation for maximum performance

## 🔧 Build Environment
- **PlatformIO Core 6.1.15** 
- **ESP32 Arduino Core 2.0.6**
- **GFX Library for Arduino 1.4.7**
- **RTClib 2.1.4**

## 🎊 Success Story
**"Wow. it looks great. lets save this as our starting .bin and good job!"** - Project complete!

---
*Psychedelic patterns meet practical timekeeping on embedded hardware* 🚀