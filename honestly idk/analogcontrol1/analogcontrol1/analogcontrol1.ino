#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"
#define PIN 4
#define LED_COUNT 30
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
const int analogInPin = A0;
int sensorValue = 0;
int ledCount = 0;

void setup()
{
  // put your setup code here, to run once:
  leds.begin();
  Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(analogInPin);
  ledCount = map(sensorValue, 10, 90, 0, 30);
  if (ledCount < 30)
  {
    for (int i = 0; i < ledCount; i++)
    {
      leds.setPixelColor(i, GREEN);
    }
    for (int j = ledCount + 1; j < 30; j++)
    {
      leds.setPixelColor(j, BLACK);
    }
  }
  if (ledCount > 30)
  {
    for (int k = 0; k < 30; k++)
    {
      leds.setPixelColor(k, RED);
    }
  }
  leds.show();
  Serial.println(sensorValue);
  delay(10);
}
