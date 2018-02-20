#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"
//WRITE WITH TWO BUTTONS
#define PIN 4
#define UNDERPIN 6
#define PLATEPIN 2
#define LED_COUNT 36
#define LED_COUNT_UNDER 78
#define LED_COUNT_PLATE 36
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
int i = 0;
int under = 0;
int lp = 0;
int hopper = 0;
int incomingByte = 65;
int bar = 0;
int hop = 48;
void setup() {
  // put your setup code here, to run once:
  leds.begin();
  Serial.begin(9600);
  while (!Serial)
  {
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  incomingByte = Serial.read();
  if (incomingByte >= 48 && incomingByte <= 57)
  {
    hop = incomingByte;
  }
  hopperValue (hop);
}
void hopperValue (unsigned long height)
{
  if ( height - 48 == 0)
  {
    for (int t = 0; t < 36; t++)
    {
      leds.setPixelColor(t, BLACK);
      Serial.println ("All Off");
    }
  }
  else
  {
    for (int u = height - 48 + bar; u < 9 + bar; u++)
    {
      leds.setPixelColor(u, BLACK);
    }
    if (height - 48 <= 3)
    {
      for (int v = 0 + bar; v <= height - 49 + bar; v ++)
      {
        leds.setPixelColor(v, RED);
        Serial.println ("Red");
      }
    }
    if (height - 48 >= 7)
    {
      for (int w = 6 + bar; w <= height - 49 + bar; w ++)
      {
        leds.setPixelColor(w, GREEN);
        Serial.println ("Green1");
        Serial.println (w);
      }
      for (int c = 0 + bar; c < 3 + bar; c++)
      {
        leds.setPixelColor(c, RED);
        Serial.println ("Green2");
      }
      for (int d = 3 + bar; d < 6 + bar; d++)
      {
        leds.setPixelColor(d, YELLOW);
        Serial.println ("Green3");
      }
      Serial.println ("Green");
    }
    if (height - 48 > 3 && height - 48 < 7)
    {
      for (int x = 3 + bar; x <= height - 49 + bar; x ++)
      {
        leds.setPixelColor(x, YELLOW);
      }
      for (int e = 0 + bar; e < 3 + bar; e++)
      {
        leds.setPixelColor(e, RED);
      }
      Serial.println ("Yellow");
    }

  }
  bar = bar + 9;
  if (bar > 27)
  {
    bar = 0;
    Serial.println ("bar");
  }
  leds.show();
}
