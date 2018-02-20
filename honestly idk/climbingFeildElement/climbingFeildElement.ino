#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"
//WRITE WITH TWO BUTTONS
#define PIN 4
#define LED_COUNT 30
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
int buttonPin = 7;
int i = 0;
void setup() {
  // put your setup code here, to run once:
  leds.begin();
  pinMode(buttonPin, INPUT);
  Serial.begin (115200);
}

void loop()
{ // put your main code here, to run repeatedly:
  if (buttonPin == HIGH)
  {
    i++;
    delay (1);
    if (i <= 1000)
    {
      leds.setPixelColor(0, BLACK);
    }
    if (i > 1000)
    {
      leds.setPixelColor(0, RED);
    }
  }
  if (buttonPin == LOW)
  {
    i = 0;
  }
}
