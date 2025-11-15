#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "smiley.h"

int soilSensor = 14;
int moistureValue = 0;

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void moisturelvl(int moistureValue);

void setup()
{
  pinMode(soilSensor, INPUT);
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 Allocation FAILED :("));
    for(;;);
  }
  
  

}

void loop()
{
  moistureValue = analogRead(soilSensor);
  moisturelvl(moistureValue);
  delay(5000);
}

void moisturelvl(int moistureValue)
{

  if( moistureValue < 510 && moistureValue > 480 )
  {
    Serial.printf("Dry: %d\n", moistureValue);
    display.clearDisplay();
    display.display();
  }
  else  if( moistureValue < 480 && moistureValue > 350 )
  {
    Serial.printf("Moist: %d\n", moistureValue);
    display.clearDisplay();
    display.drawBitmap(0,0, smiley, 128, 64, SSD1306_WHITE);
    display.display();
  }
  else if(moistureValue < 350 && moistureValue > 0)
  {
    Serial.printf("too wet: %d\n", moistureValue);
    display.clearDisplay();
    display.display();
  }
}