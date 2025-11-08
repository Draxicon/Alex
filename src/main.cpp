#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "smiley.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 Allocation FAILED :("));
    for(;;);
  }
  
  display.clearDisplay();
  display.drawBitmap(0,0, smiley, 128, 64, SSD1306_WHITE);
  display.display();
  delay(5000);
}

void loop()
{

}