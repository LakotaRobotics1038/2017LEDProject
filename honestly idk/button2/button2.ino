#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"
//WRITE WITH TWO BUTTONS
#define PIN 4
#define LED_COUNT 30
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
int buttonOne = 7;
int buttonTwo = 8;
int lightPattern = 1;
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
    if (buttonOneVal == LOW && buttonTwoVal == HIGH)
    {
      lightPattern = 2;
      Serial.println("Light");
      Serial.print (lightPattern, DEC);
    }
    if (buttonTwoVal == LOW && buttonOneVal == HIGH)
    {
      lightPattern = 3;
      Serial.println("Light");
      Serial.print (lightPattern, DEC);
    }
    if (buttonOneVal == LOW && buttonTwoVal == LOW)
    {
      lightPattern = 4;
      Serial.println("Light");
      Serial.print (lightPattern, DEC);
    }
    if (buttonOneVal == HIGH && buttonTwoVal == HIGH)
    {
      lightPattern = 1;
      Serial.println("Light");
      Serial.print (lightPattern, DEC);
    }
    delay (1);
  }
  switch (lightPattern)
  {
    case 1:
      rotate (TURQUOISE, GREEN, 6);
      i = i - 1;
      break;
    case 2:
      rotate (BLUE, TAN, 10);
      i = i + 1;
      break;
    case 3:
      rotate (PURPLE, LIGHTBLUE, 3);
      i = i + 1;
      break;
    case 4:
      rotate (RED, WHITE, 5);
      i = i + 1;
      break;
  }
}

void rotate (unsigned long colora, unsigned long colorb, byte longshort)
{
  for (int j = i; j < LED_COUNT; j = j + longshort * 2)
  {
    for (int k = 0; k < longshort; k++)
    {
      leds.setPixelColor(j + k, colora);
    }
    for (int m = longshort; m < longshort * 2; m++)
    {
      leds.setPixelColor(j + m, colorb);
    }
  }
  for (int n = i; n > 0; n = n - longshort * 2)
  {
    for (int k = 0; k < longshort; k++)
    {
      leds.setPixelColor(n - k - 1, colorb);
    }
    for (int m = longshort; m < longshort * 2; m++)
    {
      leds.setPixelColor(n - m - 1, colora);
    }
  }
  leds.show();
}
