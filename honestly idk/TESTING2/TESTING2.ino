#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"
//WRITE WITH TWO BUTTONS
#define PIN 4
#define LED_COUNT 30
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
int buttonOne = 7;
int buttonTwo = 8;
int oldButtonOneVal = 0;
int oldButtonTwoVal = 0;
int nPatterns = 4;
int lightOnePattern = 1;
int lightTwoPattern = 1;
int i = 0;
void setup()
{
  // put your setup code here, to run once:
  leds.begin();
  pinMode(buttonOne, INPUT_PULLUP);
  pinMode(buttonTwo, INPUT_PULLUP);
  Serial.begin (115200);
}

void loop()
{
  if (6 <= i || 3 > i)
  {
    for (int v = i; v <= i ; v++)
    {
      leds.setPixelColor(v, RED);
      leds.show();
    }
  }
  else
  {
    for (int j = i; j <= i; j++)
    {
      leds.setPixelColor(j, BLUE);
      leds.show();
    }
  }
  delay (10);
  i++;
}
