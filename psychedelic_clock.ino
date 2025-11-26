// Psychedelic Clock for ESP32-2432S028 Display
// Converted from Python screensaver programs
// Use board "ESP32 Dev Module"

#include <Arduino_GFX_Library.h>
#include <RTClib.h>
#include <math.h>
#include <WiFi.h>
#include <WebServer.h>

// Display pins
#define BL_PIN 21
#define BOOT_PIN 0
#define BOOT_BUTTON_DEBOUNCE_TIME 400

// Display speed
#define DISPLAY_SPI_SPEED 80000000L

// RTC module (DS3231 or DS1307)
RTC_DS3231 rtc;

// Display setup
Arduino_DataBus *bus = new Arduino_HWSPI(2 /* DC */, 15 /* CS */, 14 /* SCK */, 13 /* MOSI */, 12 /* MISO */);
Arduino_GFX *gfx = new Arduino_ILI9341(bus);

// Animation modes
enum AnimationMode {
  PLASMA_FIELD = 0,
  KALEIDOSCOPE = 1,
  MANDELBROT = 2,
  MODE_COUNT = 3
};

// Global variables
volatile bool skipRequested = false;
volatile uint32_t isrTick = 0;
uint32_t lastPress = 0;
AnimationMode currentMode = PLASMA_FIELD;
float animationTime = 0;
int frameCount = 0;

// Plasma field variables
uint8_t plasmaBuffer[240 * 320]; // Full screen buffer for plasma values
uint16_t plasmaPalette[256];

// Clock display variables
bool showClock = true;
unsigned long lastClockUpdate = 0;
const unsigned long clockUpdateInterval = 1000; // Update clock every second
String clockPosition = "bottom-right";
uint16_t clockColor = 0xFFFF; // White
bool clockBackground = false;

// WiFi AP settings
const char* ap_ssid = "PsychedelicClock";
const char* ap_password = "clockset123";
WebServer server(80);

void IRAM_ATTR onButtonPress() {
  skipRequested = true;
  isrTick = xTaskGetTickCountFromISR();
}

void setup() {
  Serial.begin(115200);
  
  // Display backlight
  pinMode(BL_PIN, OUTPUT);
  digitalWrite(BL_PIN, HIGH);
  
  // Display initialization
  Serial.println("Initializing Psychedelic Clock...");
  if (!gfx->begin(DISPLAY_SPI_SPEED)) {
    Serial.println("Display initialization failed!");
    while (true) delay(1000);
  }
  
  gfx->setRotation(0); // Portrait mode
  gfx->fillScreen(RGB565_BLACK);
  Serial.printf("Display size: %dx%d\n", gfx->width(), gfx->height());
  
  // WiFi AP setup
  WiFi.softAP(ap_ssid, ap_password);
  Serial.println("AP started");
  Serial.print("AP IP: ");
  Serial.println(WiFi.softAPIP());
  
  server.on("/", handleRoot);
  server.on("/toggle", handleToggleClock);  
  server.on("/settime", handleSetTime);
  server.begin();
  
  // RTC initialization
  Serial.println("Initializing RTC...");
  
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    gfx->fillScreen(RGB565_BLACK);
    gfx->setTextColor(RGB565_WHITE);
    gfx->setTextSize(2);
    gfx->setCursor(10, 100);
    gfx->print("RTC ERROR!");
    gfx->setCursor(10, 120);
    gfx->print("Check wiring");
    while (true) delay(1000);
  }
  
  // Check if RTC lost power and if so, set the time
  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting time!");
    
    // Set to compile time (you can modify this)
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    
    // Alternative: Set to a specific date/time
    // rtc.adjust(DateTime(2024, 11, 22, 6, 37, 0)); // Nov 22, 2024 6:37:00 AM
  }
  
  Serial.println("RTC initialized!");
  
  // Initialize palettes
  initializePlasmaPalette();
  
  // Button setup
  pinMode(BOOT_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(BOOT_PIN), onButtonPress, FALLING);
  
  // Clear screen completely before starting
  gfx->fillScreen(RGB565_BLACK);
  

  
  Serial.println("Psychedelic Clock ready!");
}

void loop() {
  // Handle web server
  server.handleClient();
  
  // Handle mode switching
  if (skipRequested) {
    uint32_t now = millis();
    if (now - lastPress >= BOOT_BUTTON_DEBOUNCE_TIME) {
      currentMode = (AnimationMode)((currentMode + 1) % MODE_COUNT);
      animationTime = 0; // Reset animation
      Serial.printf("Switched to mode %d\n", currentMode);
      lastPress = now;
    }
    skipRequested = false;
  }
  
  // Draw current animation mode
  switch (currentMode) {
    case PLASMA_FIELD:
      drawPlasmaField();
      break;
    case KALEIDOSCOPE:
      drawKaleidoscope();
      break;
    case MANDELBROT:
      drawMandelbrot();
      break;
  }
  
  // Draw clock overlay
  // Clock removed
  
  // Handle web server
  server.handleClient();
  
  // Update animation time
  animationTime += 0.05f;
  frameCount++;
  
  delay(50); // ~20 FPS
}

void initializePlasmaPalette() {
  for (int i = 0; i < 256; i++) {
    float t = i / 255.0f;
    
    // Classic plasma colors with mathematical waves
    int r = (int)(128 + 127 * sin(t * M_PI * 2));
    int g = (int)(128 + 127 * sin(t * M_PI * 2 + M_PI / 3));
    int b = (int)(128 + 127 * sin(t * M_PI * 2 + 2 * M_PI / 3));
    
    // Boost psychedelic colors
    if (t > 0.2f && t < 0.4f) { // Enhance magentas
      r = min(255, (int)(r * 1.3f));
      b = min(255, (int)(b * 1.2f));
    } else if (t > 0.6f && t < 0.8f) { // Enhance cyans
      g = min(255, (int)(g * 1.3f));
      b = min(255, (int)(b * 1.3f));
    }
    
    plasmaPalette[i] = gfx->color565(r, g, b);
  }
}

void drawPlasmaField() {
  int width = gfx->width();
  int height = gfx->height();
  int centerX = width / 2;
  int centerY = height / 2;
  
  // Calculate plasma field
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      float value = 0;
      
      // Multiple sine waves for classic plasma effect
      value += sin((x + animationTime * 30) / 16.0f);
      value += sin((y + animationTime * 20) / 8.0f);
      value += sin((x + y + animationTime * 25) / 16.0f);
      
      // Circular patterns
      float dist = sqrt((x - centerX) * (x - centerX) + (y - centerY) * (y - centerY));
      value += sin(dist / 8.0f + animationTime * 15);
      
      // Rotating pattern
      float angle = atan2(y - centerY, x - centerX);
      value += sin(angle * 3 + animationTime * 10);
      
      // Normalize to 0-255
      int plasmaValue = (int)((value + 5) / 10 * 255) % 256;
      
      // Draw pixel
      gfx->drawPixel(x, y, plasmaPalette[plasmaValue]);
    }
  }
}

void drawKaleidoscope() {
  int width = gfx->width();
  int height = gfx->height();
  int centerX = width / 2;
  int centerY = height / 2;
  int radius = min(width, height) / 2 - 10;
  
  gfx->fillScreen(RGB565_BLACK);
  
  // Kaleidoscope parameters
  int segments = 6;
  float segmentAngle = 2 * M_PI / segments;
  
  // Draw kaleidoscope pattern
  for (int seg = 0; seg < segments; seg++) {
    float baseAngle = animationTime * 0.5f + seg * segmentAngle;
    
    // Draw multiple elements per segment
    for (int elem = 0; elem < 8; elem++) {
      float elemAngle = baseAngle + elem * M_PI / 4;
      float distance = 20 + 60 * sin(animationTime + elem);
      
      int x = centerX + distance * cos(elemAngle);
      int y = centerY + distance * sin(elemAngle);
      
      // Psychedelic colors
      int colorIndex = (elem + (int)(animationTime * 10)) % 256;
      uint16_t color = plasmaPalette[colorIndex];
      
      // Draw shape with pulsing size
      int size = 3 + 2 * sin(animationTime * 2 + elem);
      gfx->fillCircle(x, y, size, color);
      
      // Draw mirror reflection
      float mirrorAngle = baseAngle - (elemAngle - baseAngle);
      int mx = centerX + distance * cos(mirrorAngle);
      int my = centerY + distance * sin(mirrorAngle);
      gfx->fillCircle(mx, my, size, color);
    }
  }
}

void drawMandelbrot() {
  int width = gfx->width();
  int height = gfx->height();
  
  // Mandelbrot parameters with animation
  float zoom = 0.5f + 0.3f * sin(animationTime * 0.1f);
  float offsetX = -0.7f + 0.2f * cos(animationTime * 0.05f);
  float offsetY = 0.0f + 0.1f * sin(animationTime * 0.03f);
  
  for (int py = 0; py < height; py++) {
    for (int px = 0; px < width; px++) {
      // Convert pixel to complex plane
      float x0 = (px - width/2.0f) / (width/4.0f) * zoom + offsetX;
      float y0 = (py - height/2.0f) / (height/4.0f) * zoom + offsetY;
      
      float x = 0, y = 0;
      int iteration = 0;
      int maxIter = 50;
      
      // Mandelbrot calculation
      while (x*x + y*y <= 4 && iteration < maxIter) {
        float xtemp = x*x - y*y + x0;
        y = 2*x*y + y0;
        x = xtemp;
        iteration++;
      }
      
      // Color based on iteration count
      if (iteration == maxIter) {
        gfx->drawPixel(px, py, RGB565_BLACK);
      } else {
        int colorIndex = (iteration * 8 + (int)(animationTime * 20)) % 256;
        gfx->drawPixel(px, py, plasmaPalette[colorIndex]);
      }
    }
  }
}

void drawClock() {
  // Clock completely removed - no display at all
}

// Helper function to set RTC time manually via Serial
void setRTCTime() {
  Serial.println("Enter time in format: YYYY MM DD HH MM SS");
  Serial.println("Example: 2024 11 22 18 30 00");
  
  // You can call this function to set time manually
  // For now, it sets to a default time - modify as needed
  DateTime newTime(2024, 11, 22, 18, 30, 0); // Nov 22, 2024, 6:30:00 PM
  rtc.adjust(newTime);
  Serial.println("RTC time set!");
}

// WiFi AP Web Server Functions
void handleRoot() {
  DateTime now = rtc.now();
  String currentTime = String(now.hour()) + ":" + String(now.minute());
  
  String html = "<html><body><h1>Clock Setup</h1>";
  html += "<form action='/save' method='POST'>";
  
  html += "Clock: <select name='clockEnabled'>";
  html += "<option value='1'" + String(showClock ? " selected" : "") + ">On</option>";
  html += "<option value='0'" + String(!showClock ? " selected" : "") + ">Off</option>";
  html += "</select><br><br>";
  
  // Format time for HTML input (HH:MM)
  String timeValue = "";
  if (now.hour() < 10) timeValue += "0";
  timeValue += String(now.hour()) + ":";
  if (now.minute() < 10) timeValue += "0";
  timeValue += String(now.minute());
  
  html += "Set Time: <input type='time' name='clockTime' value='" + timeValue + "'><br><br>";
  
  html += "<input type='submit' value='Save Settings'>";
  html += "</form></body></html>";
  
  server.send(200, "text/html", html);
}

void handleSave() {
  if (server.hasArg("clockEnabled")) {
    showClock = server.arg("clockEnabled") == "1";
  }
  
  if (server.hasArg("clockTime")) {
    String timeStr = server.arg("clockTime");
    int hour = timeStr.substring(0, 2).toInt();
    int minute = timeStr.substring(3, 5).toInt();
    
    DateTime now = rtc.now();
    DateTime newTime(now.year(), now.month(), now.day(), hour, minute, 0);
    rtc.adjust(newTime);
  }
  
  if (server.hasArg("clockPosition")) {
    clockPosition = server.arg("clockPosition");
  }
  
  if (server.hasArg("clockColor")) {
    String color = server.arg("clockColor");
    if (color == "white") clockColor = 0xFFFF;
    else if (color == "red") clockColor = 0xF800;
    else if (color == "green") clockColor = 0x07E0;
    else if (color == "blue") clockColor = 0x001F;
    else if (color == "yellow") clockColor = 0xFFE0;
  }
  
  if (server.hasArg("clockBackground")) {
    clockBackground = server.arg("clockBackground") == "1";
  }
  
  server.send(200, "text/html", "<html><body><h1>Settings Saved!</h1><a href='/'>Back to Settings</a></body></html>");
}

void handleRoot() {
  String html = "<html><body><h1>Clock Settings</h1>";
  html += "<p>Clock: " + String(showClock ? "ON" : "OFF") + "</p>";
  html += "<a href='/toggle'><button>Toggle Clock</button></a><br><br>";
  html += "<form action='/settime' method='get'>";
  html += "Hour: <input type='number' name='hour' min='0' max='23' value='12'><br>";
  html += "Minute: <input type='number' name='minute' min='0' max='59' value='0'><br>";
  html += "<input type='submit' value='Set Time'>";
  html += "</form></body></html>";
  server.send(200, "text/html", html);
}

void handleToggleClock() {
  showClock = !showClock;
  server.send(200, "text/html", "<html><body><h1>Clock Toggled!</h1><a href='/'>Back</a></body></html>");
}

void handleSetTime() {
  if (server.hasArg("hour") && server.hasArg("minute")) {
    int hour = server.arg("hour").toInt();
    int minute = server.arg("minute").toInt();
    rtc.adjust(DateTime(2023, 11, 23, hour, minute, 0));
  }
  server.send(200, "text/html", "<html><body><h1>Time Set!</h1><a href='/'>Back</a></body></html>");
}
}