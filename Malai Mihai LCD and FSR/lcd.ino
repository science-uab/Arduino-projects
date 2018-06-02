//@atuhor Malai Mihai
#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int buttonPin = 9;
int fsrAnalogPin = 0;
int fsrReading = 0;

int buttonValue = 0;
int nrButtonPressed = 0;
int appStarted = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Press btn to start!");
}

void loop() { 
  fsrReading = analogRead(fsrAnalogPin);
 
   buttonValue = digitalRead(buttonPin);
   if (buttonValue == 1) {  
    appStarted = !appStarted;
   }

  if (appStarted == 1) {
      lcd.clear();
      lcd.print("App Status: On");
      lcd.setCursor(0,1);
      lcd.print(fsrReading);
   } else {
      lcd.clear();
      lcd.print("App Status: Off"); 
   }

   delay(200);
}
