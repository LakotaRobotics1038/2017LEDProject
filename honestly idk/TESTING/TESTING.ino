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
  // put your main code here, to run repeatedly:
  int buttonOneVal;
  int buttonTwoVal;
  for (int waiting = 0; waiting < 100; waiting++)
  {
    buttonOneVal = digitalRead(buttonOne);
    buttonTwoVal = digitalRead(buttonTwo);
    if (buttonOneVal == LOW && oldButtonOneVal == HIGH)
    {
      lightOnePattern = lightOnePattern + 1;
      Serial.println("Light1");
      Serial.print (lightOnePattern, DEC);
    }

    oldButtonOneVal = buttonOneVal;
    if (lightOnePattern > nPatterns)
    {
      lightOnePattern = 1;
    }
    if (buttonTwoVal == LOW && oldButtonTwoVal == HIGH)
    {
      lightTwoPattern = lightTwoPattern + 1;
      Serial.println("Light2");
      Serial.print (lightTwoPattern, DEC);
    }

    oldButtonTwoVal = buttonTwoVal;
    if (lightTwoPattern > nPatterns)
    {
      lightTwoPattern = 1;
    }
  }
  switch (lightOnePattern)
  {
    case 1:
      leds.setPixelColor(0, RED);
      break;
    case 2:
      leds.setPixelColor(0, BLUE);
      break;
    case 3:
      leds.setPixelColor(0, GREEN);
      break;
    case 4:
      leds.setPixelColor(0, PINK);
      break;
  }
  switch (lightTwoPattern)
  {
    case 1:
      leds.setPixelColor(3, PINK);
      break;
    case 2:
      leds.setPixelColor(3, GREEN);
      break;
    case 3:
      leds.setPixelColor(3, BLUE);
      break;
    case 4:
      leds.setPixelColor(3, RED);
      break;
  }
  leds.show();
}
