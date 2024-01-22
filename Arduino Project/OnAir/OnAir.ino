#include <Adafruit_NeoPixel.h>

// Which pin on the ESP8266 is connected to the NeoPixels?
#define PIN            4
// How many NeoPixels are attached to the ESP8266?
#define NUMPIXELS      24
#define HALFPIXELS     12
#define INTENSITY      0.15

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int offset;
float intensity = 0.0;

void setup() {
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(115200);
  offset = random(0, 9999);
}

void loop() {
  unsigned long time = millis();
  double value = double(time + offset) / 3000;

  if (intensity < double(INTENSITY)) {
    intensity = double(INTENSITY / 3000) * time;
  }
  
  for (int i = 0; i < NUMPIXELS; i++) {
    uint8_t red = uint8_t(intensity * (128 + 128 * sin(value + (i % HALFPIXELS) * 0.02)));
    uint8_t green = uint8_t(intensity * (128 + 128 * sin(value * (i % HALFPIXELS) * 1.01 + i * 0.02)));
    uint8_t blue = uint8_t(intensity * (128 + 128 * sin(value * 1.03 * (i % HALFPIXELS) + i * 0.02)));

    pixels.setPixelColor(i, pixels.Color(red, green, blue));
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}






