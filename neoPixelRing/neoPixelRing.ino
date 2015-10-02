// from http://www.mathias-wilhelm.de/arduino/beginner/schritt-5-jetzt-wird-es-bunt/


#include "Adafruit_NeoPixel.h"
#define PIN 7
#define NUMBER_OF_PIXELS 12

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMBER_OF_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

int wc = 0;

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // knight rider LEDs
  int t;
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, Wheel(wc));
    t = i - 1;
    if (t < 0) t = strip.numPixels() - 1;
    strip.setPixelColor(t, strip.Color( 0, 0, 0));
    strip.show();
    delay(50);
  }
  for (int i = strip.numPixels()-1; i >= 0; i--) {
    strip.setPixelColor(i, Wheel(wc));
    t = i + 1;
    if (t >= strip.numPixels()) t = 0;
    strip.setPixelColor(t, strip.Color( 0, 0, 0));
    strip.show();
    delay(50);
  }
  wc++;
  if (wc>255) wc=0;
}

uint32_t Wheel(byte WheelPos) {
  int intensity=WheelPos/4;
  if (WheelPos < 85) {
    return strip.Color(intensity, intensity, 0);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(255 - intensity, 0, intensity);
  } else {
    WheelPos -= 170;
    return strip.Color(0, intensity, intensity);
  }
}
