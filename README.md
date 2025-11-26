:

🌈 Acidware Lysergic Clock – Psychonaut Visualization Toy 🌈
🌀 Mood-Shifting Visual Playground 🌀

The Acidware Lysergic Clock turns your ESP32-2432S028 into a psychonaut’s display companion. With 60 unique visual effects, it’s a portable mood device—mathematics, physics, and cosmic art colliding to create mind-altering visuals.


🎨 What You Get
Your ESP32 becomes a psychedelic toy, delivering:

60 Distinct Visual Effects – Each one a different state of mind

Fractal Explorations – Mandelbrot blooms, Julia vines, dragon curves, spirals

Physics-Based Moodscapes – Fire, lightning, lava, aurora, ocean waves

Cosmic Journeys – Starfields, wormholes, tunnels into infinity

Retro Nostalgia – Matrix rain, Tetris glyphs, geometric throwbacks

Smooth Performance – 30+ FPS tuned for ESP32 hardware

🚀 Quick Start
WiFi Version (Recommended – Set time via web interface)
bash
esptool.py --chip esp32 --port /dev/ttyUSB0 write_flash 0x10000 psychedelic_clock_wifi/psychedelic_clock_CLEAN_CLOCK_SET.bin
# Connect to "ClockAP" WiFi, browse to 192.168.4.1 to set time
Pure Visual Version (Effects only)
bash
esptool.py --chip esp32 --port /dev/ttyUSB0 write_flash 0x10000 firmware.bin
Build from Source
Install PlatformIO

Clone this repository

Choose version: psychedelic_clock_pio or psychedelic_clock_wifi

Build and upload to your ESP32-2432S028

🔧 Hardware
ESP32-2432S028 development board (Sunton/CYD)

2.8" ILI9341 TFT Display (320x240)

XPT2046 Touch Controller

USB-C programming cable

🎯 Effect Categories
Fractal Explorations (1–20)
Plasma fields, Mandelbrot zooms, Julia sets, dragon curves, spirals, wave interference, cellular automata.

Natural Moodscapes (21–40)
Fire, lightning, aurora borealis, ocean waves, lava flows, tornados, rainbow prisms, snow cascades, meteor showers, volcanic eruptions.

Particle Journeys (41–60)
Fireworks bursts, fountains, smoke dynamics, starfields, cosmic tunnels, matrix rain, retro geometry.

See EFFECTS_LIST_60.txt for the complete catalog.

⚙️ Specs
Platform: ESP32 (240MHz dual-core)

Display: ILI9341 320x240 TFT

Memory Usage: 31.3% RAM (102KB), 29.8% Flash (390KB)

Performance: 30+ FPS across all effects

Code Size: 4,800+ lines of optimized C++

Power: USB or battery

🎮 Controls
Touch Screen: Tap to cycle effects (disabled for now)

Auto Mode: Effects shift every 30 seconds (disabled for now)

Boot Button: Cycle through screens (active as of 11-26-2025)

📁 Repository
Code
psychedelic_clock_pio/          # Original 60-effects version
├── src/
│   └── main.cpp               # Complete source code (4,800+ lines)
└── platformio.ini             # Build configuration

psychedelic_clock_wifi/         # WiFi-enabled version with web interface
├── src/
│   └── main.cpp               # WiFi + web interface code
├── platformio.ini             # Build configuration
├── psychedelic_clock_CLEAN_CLOCK_SET.bin  # Pre-built firmware
├── README.md                  # WiFi version docs
└── INSTALL.md                 # WiFi installation guide

firmware.bin                   # Pre-built original version
EFFECTS_LIST_60.txt            # Complete effect documentation  
README.md                      # This file
INSTALL.md                     # Installation guide
🏆 Achievements
✅ 60 Mood Effects – Complete collection

✅ Fractal Explorations – Advanced math-driven visuals

✅ Natural Moodscapes – Physics-based simulations

✅ Optimized Performance – 30+ FPS on ESP32 hardware

✅ Memory Efficient – <32% RAM usage

✅ Production Ready – Stable, tested, documented

📜 License
MIT License – Free for personal and commercial use.

✨ Transform your ESP32 into a psychonaut’s visualization toy—mathematics, physics, and cosmic art for mood exploration. ✨

Completed November 23, 2025 – Forged with mathematics, perception, and expressive design.
