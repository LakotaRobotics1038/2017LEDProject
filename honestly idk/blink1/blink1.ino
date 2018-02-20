#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 4
#define LED_COUNT 36
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  // put your setup code here, to run once:
  leds.begin();
}

void loop()
{
  // put your main code here, to run repeatedly:
  blinking (SEAGREEN, RED, 1000, 1000);
}

void blinking (unsigned long color,unsigned long colorb, unsigned long on, unsigned long off)
{
  for (int i = 0; i < LED_COUNT; i++)
  {
    leds.setPixelColor(i, color);
  }
  leds.show();
  delay(on);
  for (int j = 0; j < LED_COUNT; j++)
  {
    leds.setPixelColor(j, colorb);
  }
  leds.show();
  delay(off);
}

