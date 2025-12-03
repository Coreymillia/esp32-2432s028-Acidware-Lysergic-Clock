# ESP32 Psychedelic Clock - 60 Visual Effects

**Transform your ESP32-2432S028 into a mesmerizing psychedelic art display!**

This project converts a cheap yellow Chinese ESP32 display module into a hypnotic screensaver with 60 unique visual effects plus an optional digital clock overlay. Perfect for ambient room lighting, art installations, or just because it looks absolutely trippy.

## What This Project Does

🎨 **60 Psychedelic Effects** - Mathematical fractals, plasma fields, particle systems, kaleidoscopes  
🕐 **Digital Clock Overlay** - Web-configurable time display with 5 position options  
📱 **WiFi Control** - Set time and toggle clock via simple web interface  
🔄 **Button Control** - Press BOOT button to cycle through all effects  
💾 **Settings Memory** - Clock preferences survive power cycles (NEW hardware only)  
🖥️ **Plug & Play** - Just flash and enjoy, no complex setup required

## 🎯 Project Status: COMPLETE ✅
- **60 Visual Effects** - Full screensaver collection
- **Clock Overlay** - Stable sprite-like clock display  
- **Settings Persistence** - Clock preferences survive reboots
- **Web Interface** - Easy configuration via WiFi
  

## 📦 Four Firmware Versions Available

⚠️ **HARDWARE LOTTERY: Chinese manufacturers use different LCD panels in identical ESP32-2432S028 boards!**

### **Step 1: Determine Your Hardware Type**
**Try OLD Version First:** `OLDversion_psyclock_12-2.bin`
- If backgrounds are **BLACK** ✅ → You have OLD hardware
- If backgrounds are **WHITE** ❌ → You have NEW hardware  

### **Step 2: Choose Your Version**

#### For OLD Hardware (Black Backgrounds)
- **Basic:** `OLDversion_psyclock_12-2.bin` + `OLDversion_source_12-2.cpp`
- **Features:** 60 effects, clock overlay, web interface
- **Note:** No persistence - clock settings reset on reboot

#### For NEW Hardware (White Backgrounds) 
- **Basic:** `NEWversion_psyclock_12-2.bin` + `NEWversion_source_12-2.cpp`
- **PERSISTENCE:** `psychedelic_clock_PERSISTENCE_12-2_15-06.bin` + `PERSISTENCE_source_12-2.cpp` ⭐
- **Features:** Same as OLD + clock settings persist across reboots
- 
----There is also a version without a clock at all---
  Hardware with Persistence**
The persistence version saves your clock on/off setting permanently! Unfortunately... not the time. 

## 🚀 Flash Instructions

⚠️ **CRITICAL: DO NOT USE esptool.py DIRECTLY**
- **Use ESP32 Flash Tool or PlatformIO only**
  

### Method 1: ESP32 Flash Download Tool (Easiest)
1. **Download** ESP32 Flash Tool from Espressif official site
2. **Connect** ESP32 via USB
3. **Select** your COM port 
4. **Set** baud rate to 115200
5. **Add** .bin file at address **0x10000**
6. **Put ESP32 in boot mode:** Hold BOOT button, press RESET, hold BOOT for 3+ seconds, release
7. **Click START** in flash tool
8. **Wait** for "FINISH" message

### Method 2: PlatformIO (For Developers)
```bash
# Use provided source code and platformio.ini
# Put ESP32 in boot mode first
pio run --target upload
```

## 🎮 Usage Instructions

### Initial Setup
1. **Power On** - Device starts with random screensaver
2. **Connect to WiFi** - SSID: `PsyClock`, Password: `clockset123`
3. **Open Browser** - Go to `192.168.4.1`
4. **Set Time** - Use web interface to set current time
5. **Configure Clock** - Toggle clock on/off, adjust position

### Controls
- **Boot Button (GPIO 0)** - Cycle through 60 effects
- **Web Interface** - Full clock control and time setting
- **Auto-Cycle** - Effects change automatically (optional)

### ⚠️ Important Usage Notes
- **Time Limitation** - Clock resets to default when unplugged (no RTC battery)
- **Setup Required** - Set time via web interface after each power cycle
- **Settings Persist** - Clock on/off and position settings survive reboots
- **Instructions for Buyers** - "Don't unplug the clock or you have to reset the time"

## 🎨 Visual Effects (60 Total)

**Categories:**
- **Plasma Fields** - Mathematical wave patterns
- **Fractals** - Mandelbrot, Sierpinski, Julia sets  
- **Particle Systems** - Fire, starfield, bouncing balls
- **Geometric** - Spirals, kaleidoscope, matrix rain
- **Abstract** - Lava lamps, psychedelic waves, color cycles

**All effects optimized for smooth 20 FPS performance**

## 🔧 Hardware Requirements

### ESP32-2432S028 Display Module
- **ESP32 DevKit** - 240MHz dual-core
- **2.8" ILI9341 TFT** - 240x320 pixels
- **Touch Screen** - XPT2046 controller
- **USB-C Power** - 5V input

### Optional: DS3231 RTC Module
- **Real-time Clock** - For accurate timekeeping
- **No Battery Required** - Software clock fallback
- **I2C Connection** - SDA/SCL pins

## 📡 Web Interface Features

### Clock Settings
- **Toggle On/Off** - Show/hide clock display
- **Position Control** - 5 position options
- **Time Setting** - Manual time input via web form
- **Background Box** - Optional clock background

### Network Configuration  
- **Access Point Mode** - Creates `PsyClock` WiFi network
- **Web Server** - Responds on `192.168.4.1`
- **Simple Interface** - No complex setup required

- 60 unique visual effects
- Web-controlled clock
- Persistent settings
- Professional quality
- Simple user instructions

- Plug-and-play operation
- No complex setup required
- Mesmerizing visual display
- Clock functionality included
  

## 🎉 Final Thoughts

This was my first commercial-quality (for my eBay store) ESP32 project, and I'm pretty stoked with how it turned out! What started as a simple screensaver idea turned into a full-featured psychedelic display system.  The clock could use improvements but it was the best I could do. 

**For Makers:** The code is well-commented and modular. Easy to add new effects or modify existing ones. PlatformIO project included for easy building.

 You're getting 60 unique visual effects that I spent some time perfecting. Well, they are not all perfect. Each one is mathematically generated in real-time - no pre-recorded videos here!

**Technical Achievement:** 
- 752KB optimized firmware running 60 effects at 20 FPS
- Sprite-like clock overlay system that solved flickering issues  
- Web interface with persistent settings
- Hardware compatibility layer for manufacturing variations

## 💡 Use Cases

- **Ambient Room Lighting** - Endless variety, never gets boring
- **Art Installations** - Professional quality visual effects  
- **Meditation/Relaxation** - Hypnotic patterns for stress relief
- **Party Atmosphere** - Psychedelic visuals for gatherings
- **Desk Clock** - Functional timepiece with style
- **Gift for Techies** - Unique conversation starter

## 📞 Support & Contact
--Nothing to see here-- Good Luck!
**Project Status: COMPLETE For now. 

*Quick setup: Connect to "PsyClock" WiFi → Browse to 192.168.4.1 → Set time → Enjoy!*

---
*Built with ❤️ and way too much coffee. Hope you enjoy the trip! 🌈*
