#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <qrcode.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void generateAndDisplayQR(const char *text) {
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(1)];  // Version 1 QR (21x21)

  qrcode_initText(&qrcode, qrcodeData, 1, ECC_LOW, text);

  int scale = 3;                       // Size of each QR module (pixel block)
  int qrSize = qrcode.size;            // Normally 21 for version 1
  int quietZone = 4;                   // Required quiet zone (blank border)
  int totalSize = (qrSize + 2 * quietZone) * scale;  // Total size including quiet zone

  // Perfect centering calculation (no random magic numbers):
  int xOffset = (SCREEN_WIDTH - totalSize) / 2;
  int yOffset = (SCREEN_HEIGHT - totalSize) / 2;

  display.clearDisplay();

  for (int y = -quietZone; y < qrSize + quietZone; y++) {
    for (int x = -quietZone; x < qrSize + quietZone; x++) {
      int color = WHITE;  // Background
      if (x >= 0 && y >= 0 && x < qrSize && y < qrSize) {
        color = qrcode_getModule(&qrcode, x, y) ? BLACK : WHITE;
      }
      display.fillRect(xOffset + x * scale, yOffset + y * scale, scale, scale, color);
    }
  }

  display.display();
}

void setup() {
  Serial.begin(9600);  // Must match Python code
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (1);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("Waiting for input...");
  display.display();
}

void loop() {
  if (Serial.available() > 0) {
    char received = Serial.read();

    if (received == '1') {
      generateAndDisplayQR("Recyclable");
    } else if (received == '0') {
      generateAndDisplayQR("Non-Recyclable");
    } else {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0, 10);
      display.println("Unknown Input");
      display.display();
    }
  }
}
