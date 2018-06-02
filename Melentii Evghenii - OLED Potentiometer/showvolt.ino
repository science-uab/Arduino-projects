
#define sclk 13
#define mosi 11
#define cs   10
#define rst  9
#define dc   8

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1331.h>
#include <SPI.h>
#include <string.h>

Adafruit_SSD1331 display = Adafruit_SSD1331(cs, dc, mosi, sclk, rst);  


#define  BLACK           0x0000
#define BLUE            0x001F
#define RED             0xF800
#define GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0  
#define WHITE           0xFFFF

String st;
void setup(void) {
  display.begin();
  Serial.begin(9600);
}

void loop() {
  display.fillScreen(BLACK);
  display.setCursor(0,20);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  Serial.println(analogRead(A0));
  st = (analogRead(A0)*0.00488); //to 5 Volt transformation
  Serial.println(st);
  display.print(st+" V");
  delay(1000);
}
