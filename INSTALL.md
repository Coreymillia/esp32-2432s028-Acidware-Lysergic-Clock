# Installation Guide - ESP32 Psychedelic Clock

## 🚀 Quick Flash (Recommended)

### Prerequisites
- ESP32-2432S028 board
- USB-C cable
- Computer with USB port

### Method 1: ESPTool (Command Line)
```bash
# Install esptool
pip install esptool

# Flash the firmware
esptool.py --chip esp32 --port /dev/ttyUSB0 --baud 460800 write_flash -z 0x10000 firmware.bin

# Windows users use COM port instead:
# esptool.py --chip esp32 --port COM3 --baud 460800 write_flash -z 0x10000 firmware.bin
```

### Method 2: PlatformIO
```bash
# Install PlatformIO
pip install platformio

# Navigate to project directory
cd psychedelic_clock_pio

# Upload firmware
pio run -t upload
```

## 🛠️ Build from Source

### Steps
1. **Clone Repository**:
```bash
git clone <repository-url>
cd esp32-psychedelic-clock
```

2. **Open in PlatformIO**:
```bash
cd psychedelic_clock_pio
# Open in VS Code with PlatformIO extension
# or use PlatformIO CLI
```

3. **Build and Upload**:
```bash
pio run -t upload
```

## 📱 Hardware Setup

### ESP32-2432S028 Board
- **Display**: 2.8" ILI9341 TFT (320x240)
- **Touch**: XPT2046 resistive touch
- **Power**: USB-C or external 5V
- **Programming**: USB-C (CH340 chip)

### No Wiring Required
Everything is built into the ESP32-2432S028 board!

### First Boot
1. Power on the device
2. Display shows first effect (Plasma Field)
3. Touch screen to cycle through all 60 effects
4. Auto-cycles every 30 seconds

## 🔧 Troubleshooting

### Upload Issues
- **Port not found**: Check USB cable and drivers
- **Permission denied**: `sudo chmod 666 /dev/ttyUSB0` (Linux)
- **Upload failed**: Hold BOOT button during upload

### Display Issues  
- **Black screen**: Check 5V power supply
- **Garbled display**: Verify ESP32-2432S028 board type
- **No touch**: Clean screen surface

## 📊 Memory Usage
- **RAM**: 31.3% (102KB/327KB)
- **Flash**: 29.8% (390KB/1310KB)

## 🔋 Power
- **Active**: ~200mA @ 5V
- **Battery**: 2000mAh = 6-8 hours runtime

## 📞 Getting Help

1. Check hardware connections  
2. Try reflashing firmware
3. Open GitHub issue with error details

---

**Ready to experience 60 psychedelic effects!** 🎨✨