#define PIN 4
#define LED_COUNT 30

// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
   leds.begin();  // Call this to start up the LED strip.
 
  
  // put your setup code here, to run once:

}

void loop() {
  leds.setPixelColor(1, MINTCREAM);    // Set fourth LED to full red, no green, full blue
  leds.setPixelColor(2, CORAL);
  leds.setPixelColor(3, MINTCREAM);
  leds.setPixelColor(4, CORAL);
  leds.setPixelColor(5, MINTCREAM);
  leds.setPixelColor(6, CORAL);
  leds.setPixelColor(7, MINTCREAM);
  leds.setPixelColor(8, CORAL);
  leds.setPixelColor(9, MINTCREAM);
  leds.setPixelColor(10, CORAL);
  leds.setPixelColor(11, MINTCREAM);
  leds.setPixelColor(12, CORAL);
  leds.setPixelColor(13, MINTCREAM);
  leds.setPixelColor(14, CORAL);
  leds.setPixelColor(15, MINTCREAM);
  leds.setPixelColor(16, CORAL);
  leds.setPixelColor(17, MINTCREAM);
  leds.setPixelColor(18, CORAL);
  leds.setPixelColor(19, MINTCREAM);
  leds.setPixelColor(20, CORAL);
  leds.setPixelColor(21, MINTCREAM);
  leds.setPixelColor(22, CORAL);
  leds.setPixelColor(23, MINTCREAM);
  leds.setPixelColor(24, CORAL);
  leds.setPixelColor(25, MINTCREAM);
  leds.setPixelColor(26, CORAL);
  leds.setPixelColor(27, MINTCREAM);
  leds.setPixelColor(28, CORAL);
  leds.setPixelColor(29, MINTCREAM);
  leds.setPixelColor(0, CORAL);
  leds.show();   // ...but the LEDs don't actually update until you call this.
}
