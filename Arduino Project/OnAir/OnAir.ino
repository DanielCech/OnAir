#include <Adafruit_NeoPixel.h>

// Which pin on the ESP8266 is connected to the NeoPixels?
#define PIN            4

// How many NeoPixels are attached to the ESP8266?
#define NUMPIXELS      24

#define INTENSITY      0.6

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  // put your setup code here, to run once:
  pixels.begin(); // This initializes the NeoPixel library.
  Serial.begin(115200);
}

void loop() {

  unsigned long time = millis();

  double value = double(time) / 3000;

  for (int i = 0; i < NUMPIXELS; i++) {
    uint8_t red = uint8_t(INTENSITY * (128 + 128 * sin(value + i * 0.02)));
    uint8_t green = uint8_t(INTENSITY * (128 + 128 * sin(value * i * 1.01 + i * 0.02)));
    uint8_t blue = uint8_t(INTENSITY * (128 + 128 * sin(value * 1.03 * i + i * 0.02)));

    pixels.setPixelColor(i, pixels.Color(red, green, blue)); // Moderately bright green color.
    pixels.show(); // This sends the updated pixel color to the hardware.
  }
}