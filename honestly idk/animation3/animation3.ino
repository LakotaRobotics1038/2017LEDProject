#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 4
#define LED_COUNT 30
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
  // put your setup code here, to run once:
  leds.begin();
  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  rotate (RED, PURPLE, 100);
}

void rotate (unsigned long colora, unsigned long colorb, byte wait)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    leds.setPixelColor(i - 29, colora);  // Set fourth LED to full red, no green, full blue
    leds.setPixelColor(i - 28, colora);
    leds.setPixelColor(i - 27, colorb);
    leds.setPixelColor(i - 26, colorb);
    leds.setPixelColor(i - 25, colorb);
    leds.setPixelColor(i - 24, colora);
    leds.setPixelColor(i - 23, colora);
    leds.setPixelColor(i - 22, colora);
    leds.setPixelColor(i - 21, colorb);
    leds.setPixelColor(i - 20, colorb);
    leds.setPixelColor(i - 19, colorb);
    leds.setPixelColor(i - 18, colora);
    leds.setPixelColor(i - 17, colora);
    leds.setPixelColor(i - 16, colora);
    leds.setPixelColor(i - 15, colorb);
    leds.setPixelColor(i - 14, colorb);
    leds.setPixelColor(i - 13, colorb);
    leds.setPixelColor(i - 12, colora);
    leds.setPixelColor(i - 11, colora);
    leds.setPixelColor(i - 10, colora);
    leds.setPixelColor(i - 9, colorb);
    leds.setPixelColor(i - 8, colorb);
    leds.setPixelColor(i - 7, colorb);
    leds.setPixelColor(i - 6, colora);
    leds.setPixelColor(i - 5, colora);
    leds.setPixelColor(i - 4, colora);
    leds.setPixelColor(i - 3, colorb);
    leds.setPixelColor(i - 2, colorb);
    leds.setPixelColor(i - 1, colorb);
    leds.setPixelColor(i, colora);
    leds.setPixelColor(i + 1, colora);
    leds.setPixelColor(i + 2, colora);
    leds.setPixelColor(i + 3, colorb);
    leds.setPixelColor(i + 4, colorb);
    leds.setPixelColor(i + 5, colorb);
    leds.setPixelColor(i + 6, colora);
    leds.setPixelColor(i + 7, colora);
    leds.setPixelColor(i + 8, colora);
    leds.setPixelColor(i + 9, colorb);
    leds.setPixelColor(i + 10, colorb);
    leds.setPixelColor(i + 11, colorb);
    leds.setPixelColor(i + 12, colora);
    leds.setPixelColor(i + 13, colora);
    leds.setPixelColor(i + 14, colora);
    leds.setPixelColor(i + 15, colorb);
    leds.setPixelColor(i + 16, colorb);
    leds.setPixelColor(i + 17, colorb);
    leds.setPixelColor(i + 18, colora);
    leds.setPixelColor(i + 19, colora);
    leds.setPixelColor(i + 20, colora);
    leds.setPixelColor(i + 21, colorb);
    leds.setPixelColor(i + 22, colorb);
    leds.setPixelColor(i + 23, colorb);
    leds.setPixelColor(i + 24, colora);
    leds.setPixelColor(i + 25, colora);
    leds.setPixelColor(i + 26, colora);
    leds.setPixelColor(i + 27, colorb);
    leds.setPixelColor(i + 28, colorb);
    leds.setPixelColor(i + 29, colorb);
    leds.show();
    delay (wait);
  }
}
