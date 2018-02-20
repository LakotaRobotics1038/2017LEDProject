#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"
//WRITE WITH TWO BUTTONS
#define PIN 8
#define UNDERPIN 6
#define PLATEPIN 4
#define LED_COUNT 36
#define LED_COUNT_UNDER 78
#define LED_COUNT_PLATE 36
Adafruit_NeoPixel ledsPlate = Adafruit_NeoPixel(LED_COUNT_PLATE, PLATEPIN, NEO_GRB + NEO_KHZ800);
int i = 0;
int under = 0;
int lp = 0;
int hopper = 0;
int incomingByte = 65;
int bar = 0;
int hop = 48;
void setup() {
  // put your setup code here, to run once:
  ledsPlate.begin();
  Serial.begin(9600);
  while (!Serial)
  {
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  incomingByte = Serial.read();
  Serial.println (incomingByte, DEC);
  Serial.println (lp, DEC);
  if (incomingByte == 76)
  {
    lp = 0;
    Serial.println ("LOW");
    Serial.println (incomingByte, DEC);
  }
  if (incomingByte == 72)
  {
    lp = 1;
    Serial.println ("HIGH");
    Serial.println (incomingByte, DEC);
  }
  licensePlate (MAGENTA, ROYALBLUE);
}
void licensePlate (unsigned long colore, unsigned long colorf)
{
  if (lp == 0)
  {
    for (int y = 0; y < 36; y++)
    {
      ledsPlate.setPixelColor(y, colore);
    }
  }
  if (lp == 1)
  {
    for (int z = 0; z < 36; z++)
    {
      ledsPlate.setPixelColor(z, colorf);
    }
  }
  ledsPlate.show();
}
