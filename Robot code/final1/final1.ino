
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"
//WRITE WITH TWO BUTTONS
#define PIN 4
#define UNDERPIN 6
#define PLATEPIN 8
#define ASLPIN 10
#define LED_COUNT 36
#define LED_COUNT_UNDER 77
#define LED_COUNT_PLATE 34
#define LED_COUNT_ASL 1
Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledsUnderglow = Adafruit_NeoPixel(LED_COUNT_UNDER, UNDERPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ledsPlate = Adafruit_NeoPixel(LED_COUNT_PLATE, PLATEPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel asled = Adafruit_NeoPixel(LED_COUNT_ASL, ASLPIN, NEO_GRB + NEO_KHZ800);
int i = 0;
int under = 0;
int lp = 0;
int hopper = 0;
int incomingByte = 65;
int bar = 0;
int hop = 48;
int blinker = 0;
void setup()
{
  // put your setup code here, to run once:
  leds.begin();
  ledsPlate.begin();
  ledsUnderglow.begin();
  asled.begin();
  Serial.begin(9600);
  while (!Serial)
  {
  }
}
void loop()
{
  asled.setPixelColor(0, DEEPPINK);
  asled.show();
  for (int waiting = 0; waiting < 10; waiting++)
  {
    incomingByte = Serial.read();
    if (incomingByte == 'A')                              //VARIABLES
    {
      under = 0;
    }
    if (incomingByte == 'B')
    {
      under = 1;
    }
    if (incomingByte == 'R')
    {
      under = 2;
    }
    if (incomingByte == 'E')
    {
      under = 3;
    }
    if (incomingByte == 'L')
    {
      lp = 0;
    }
    if (incomingByte == 'H')
    {
      lp = 1;
    }
    if (incomingByte == 'a')
    {
      lp = 2;
    }
    if (incomingByte == 'b')
    {
      lp = 3;
    }
    if (incomingByte == 'c')
    {
      lp = 4;
    }
    if (incomingByte == 'd')
    {
      lp = 5;
    }
    if (incomingByte == 'e')
    {
      lp = 6;
    }
    if (incomingByte == 'f')
    {
      lp = 7;
    }
    if (incomingByte >= 48 && incomingByte <= 57)
    {
      hop = incomingByte;
    }
    if (incomingByte == 'S')
    {
      hop = 22;
    }
    if (incomingByte == 'F')
    {
      hop = 23;
    }
    switch (under)                                        //SWITCH CASE
    {
      case 0:
        rotate (PURPLE, BLUE, 3);
        rotateUnder (PURPLE, BLUE, 3);
        rotatePlate (PURPLE, BLUE, 3);
        break;
      case 1:
        for (int a = 0; a < 78; a++)
        {
          ledsUnderglow.setPixelColor(a, BLUE);
        }
        ledsUnderglow.show();
        licensePlate (DARKSLATEGRAY, MEDIUMVIOLETRED);
        hopperValue (hop);
        break;
      case 2:
        for (int b = 0; b < 78; b++)
        {
          ledsUnderglow.setPixelColor(b, RED);
        }
        ledsUnderglow.show();
        licensePlate (DARKSLATEGRAY, MEDIUMVIOLETRED);
        hopperValue (hop);
        break;
      case 3:
        rainbow (i);
        LPrainbow (i);
        UNDrainbow (i);
        break;
    }
  }
  // put your main code here, to run repeatedly:
  i = i + 1;
  if (i > 72)
  {
    i = 0;
  }
  blinker = blinker + 1;
  if (blinker > 2)
  {
    blinker = 0;
  }
}

void rotate (unsigned long colora, unsigned long colorb, byte longshort)    //ROTATE HOPPER
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

void rotateUnder (unsigned long colorc, unsigned long colord, byte shortlong)   //ROTATE UNDERGLOW
{
  for (int p = i; p < LED_COUNT_UNDER; p = p + shortlong * 2)
  {
    for (int q = 0; q < shortlong; q++)
    {
      ledsUnderglow.setPixelColor(p + q, colorc);
    }
    for (int r = shortlong; r < shortlong * 2; r++)
    {
      ledsUnderglow.setPixelColor(p + r, colord);
    }
  }
  for (int s = i; s > 0; s = s - shortlong * 2)
  {
    for (int q = 0; q < shortlong; q++)
    {
      ledsUnderglow.setPixelColor(s - q - 1, colord);
    }
    for (int r = shortlong; r < shortlong * 2; r++)
    {
      ledsUnderglow.setPixelColor(s - r - 1, colorc);
    }
  }
  ledsUnderglow.show();
}
void rotatePlate (unsigned long colora, unsigned long colorb, byte longshort)   //ROTATE LICENSE PLATE
{
  for (int j = i; j < LED_COUNT_PLATE; j = j + longshort * 2)
  {
    for (int k = 0; k < longshort; k++)
    {
      ledsPlate.setPixelColor(j + k, colora);
    }
    for (int m = longshort; m < longshort * 2; m++)
    {
      ledsPlate.setPixelColor(j + m, colorb);
    }
  }
  for (int n = i; n > 0; n = n - longshort * 2)
  {
    for (int k = 0; k < longshort; k++)
    {
      ledsPlate.setPixelColor(n - k - 1, colorb);
    }
    for (int m = longshort; m < longshort * 2; m++)
    {
      ledsPlate.setPixelColor(n - m - 1, colora);
    }
  }
  ledsPlate.show();
}

void hopperValue (unsigned long height)                       //HOPPER CODE
{
  if ( height - 48 == 0)
  {
    rotate (PURPLE, BLUE, 3);
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
      }
    }
    if (height - 48 >= 7 && height - 48 <= 10)
    {
      for (int w = 6 + bar; w <= height - 49 + bar; w ++)
      {
        leds.setPixelColor(w, GREEN);
      }
      for (int c = 0 + bar; c < 3 + bar; c++)
      {
        leds.setPixelColor(c, RED);
      }
      for (int d = 3 + bar; d < 6 + bar; d++)
      {
        leds.setPixelColor(d, GOLD);
      }
    }
    if (height - 48 > 3 && height - 48 < 7)
    {
      for (int x = 3 + bar; x <= height - 49 + bar; x ++)
      {
        leds.setPixelColor(x, GOLD);
      }
      for (int e = 0 + bar; e < 3 + bar; e++)
      {
        leds.setPixelColor(e, RED);
      }
    }
    if ( height == 22)
    {
      for (int y = 0; y < 36; y++)
      {
        leds.setPixelColor(y, LIME);
      }
    }
    if ( height == 23)
    {
      rotate (LIME, WHITE, 4);
    }
  }
  bar = bar + 9;
  if (bar > 27)
  {
    bar = 0;
  }
  leds.show();
}

void licensePlate (unsigned long colore, unsigned long colorf)                    //LICENSE PLATE CODE
{
  if (lp == 0)
  {
    for (int y = 0; y < 36; y++)
    {
      ledsPlate.setPixelColor(y, colore);
    }
  Serial.println ("low");
  }
  if (lp == 1)
  {
    for (int z = 0; z < 36; z++)
    {
      ledsPlate.setPixelColor(z, colorf);
    }
  Serial.println ("high");
  }
  if (lp == 2)
  {
    LPrainbow(i);
  Serial.println ("do nothing");
  }
  if (lp == 3)
  {
    for (int z = 0; z < 36; z++)
    {
      ledsPlate.setPixelColor(z, DARKORANGE);
    }
  Serial.println ("baseline");
  }
  if (lp == 4)
  {
    for (int z = 0; z < 36; z++)
    {
      ledsPlate.setPixelColor(z, GOLDENROD);
    }
  Serial.println ("gear");
  }
  if (lp == 5)
  {
    for (int z = 0; z < 36; z++)
    {
      rotatePlate (GOLDENROD, RED, 18);
    }
  Serial.println ("gear shoot");
  }
  if (lp == 6)
  {
    for (int z = 0; z < 36; z++)
    {
      ledsPlate.setPixelColor(z, RED);
    }
  Serial.println ("shoot");
  }
  if (lp == 7)
  {
    for (int z = 0; z < 36; z++)
    {
      rotatePlate (RED, TEAL, 18);
    }
  Serial.println ("shoot dump");
  }
  ledsPlate.show();
}

void rainbow(byte startPosition)                                                    //HOPPER RAINBOW
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    leds.setPixelColor(i, rainbowOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  leds.show();
}

// Input a value 0 to 191 to get a color value.
// The colors are a transition red->yellow->green->aqua->blue->fuchsia->red...
//  Adapted from Wheel function in the Adafruit_NeoPixel library example sketch
uint32_t rainbowOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return leds.Color(0xFF, position * 8, 0);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return leds.Color(0xFF - position * 8, 0xFF, 0);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    return leds.Color(0, 0xFF, position * 8);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    return leds.Color(0, 0xFF - position * 8, 0xFF);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    return leds.Color(position * 8, 0, 0xFF);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    return leds.Color(0xFF, 0x00, 0xFF - position * 8);
  }
}

void UNDrainbow(byte startPosition)                                                       //UNDERGLOW RAINBOW
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT_UNDER;

  // Next we setup each pixel with the right color
  for (int i = 0; i < LED_COUNT_UNDER; i++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    ledsUnderglow.setPixelColor(i, UNDrainbowOrder((rainbowScale * (i + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  ledsUnderglow.show();
}

// Input a value 0 to 191 to get a color value.
// The colors are a transition red->yellow->green->aqua->blue->fuchsia->red...
//  Adapted from Wheel function in the Adafruit_NeoPixel library example sketch
uint32_t UNDrainbowOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return ledsUnderglow.Color(0xFF, position * 8, 0);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return ledsUnderglow.Color(0xFF - position * 8, 0xFF, 0);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    return ledsUnderglow.Color(0, 0xFF, position * 8);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    return ledsUnderglow.Color(0, 0xFF - position * 8, 0xFF);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    return ledsUnderglow.Color(position * 8, 0, 0xFF);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    return ledsUnderglow.Color(0xFF, 0x00, 0xFF - position * 8);
  }
}

void LPrainbow(byte startPosition)                                                             //LICENSE PLATE RAINBOW
{
  // Need to scale our rainbow. We want a variety of colors, even if there
  // are just 10 or so pixels.
  int rainbowScale = 192 / LED_COUNT_PLATE;

  // Next we setup each pixel with the right color
  for (int j = 0; j < LED_COUNT_PLATE; j++)
  {
    // There are 192 total colors we can get out of the rainbowOrder function.
    // It'll return a color between red->orange->green->...->violet for 0-191.
    ledsPlate.setPixelColor(j, LPrainbowOrder((rainbowScale * (j + startPosition)) % 192));
  }
  // Finally, actually turn the LEDs on:
  ledsPlate.show();
}

// Input a value 0 to 191 to get a color value.
// The colors are a transition red->yellow->green->aqua->blue->fuchsia->red...
//  Adapted from Wheel function in the Adafruit_NeoPixel library example sketch
uint32_t LPrainbowOrder(byte position)
{
  // 6 total zones of color change:
  if (position < 31)  // Red -> Yellow (Red = FF, blue = 0, green goes 00-FF)
  {
    return ledsPlate.Color(0xFF, position * 8, 0);
  }
  else if (position < 63)  // Yellow -> Green (Green = FF, blue = 0, red goes FF->00)
  {
    position -= 31;
    return ledsPlate.Color(0xFF - position * 8, 0xFF, 0);
  }
  else if (position < 95)  // Green->Aqua (Green = FF, red = 0, blue goes 00->FF)
  {
    position -= 63;
    return ledsPlate.Color(0, 0xFF, position * 8);
  }
  else if (position < 127)  // Aqua->Blue (Blue = FF, red = 0, green goes FF->00)
  {
    position -= 95;
    return ledsPlate.Color(0, 0xFF - position * 8, 0xFF);
  }
  else if (position < 159)  // Blue->Fuchsia (Blue = FF, green = 0, red goes 00->FF)
  {
    position -= 127;
    return ledsPlate.Color(position * 8, 0, 0xFF);
  }
  else  //160 <position< 191   Fuchsia->Red (Red = FF, green = 0, blue goes FF->00)
  {
    position -= 159;
    return ledsPlate.Color(0xFF, 0x00, 0xFF - position * 8);
  }
}

void blinking (unsigned long color, unsigned long colorb)                         //BLINK (LICENSE PLATE ONLY)
{
  if (blinker == 0 )
    for (int j = 0; j < LED_COUNT_PLATE; j++)
    {
      ledsPlate.setPixelColor(j, color);
    }
  ledsPlate.show();
  if (blinker == 1)
    for (int j = 0; j < LED_COUNT_PLATE; j++)
    {
      ledsPlate.setPixelColor(j, colorb);
    }
  ledsPlate.show();
}

