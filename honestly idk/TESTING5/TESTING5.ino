
#include <Adafruit_NeoPixel.h>

#define PIN 4


// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...
Adafruit_NeoPixel leds = Adafruit_NeoPixel(150, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
  // put your setup code here, to run once:
leds.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
for (int i=0; i<150; i++)
  {
    leds.setPixelColor(i, 0x800000);
  }
  leds.show();
}
