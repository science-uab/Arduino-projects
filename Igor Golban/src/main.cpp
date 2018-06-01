#include <Arduino.h>
#include <LiquidCrystal.h>

#define  SWITCH_BUTTON 3
#define  INC_BUTTON 2

#define LED_RED     A0
#define LED_GREEN   A1
#define LED_BLUE    A2

#define INC_STEP    255

// RS, E, DB4, DB5, DB6, DB7
LiquidCrystal lcd(4, 5, 9, 10, 11, 12);

int rgb[3] = {0, 0, 0};
int selected_color_index = 0;


void printColorValue(int color_index /* R-0, G-1, B-2 */, bool blank = false){
    int start_position;
    switch(color_index){
        case 1:
                start_position = 9;
            break;
        case 2:
                start_position = 13;
            break;
        default:
                start_position = 5;
            break;
    }

    lcd.setCursor(start_position, 1);

    if(blank){
        lcd.print("   ");
    }else{
        lcd.print(rgb[color_index]);
    }
}

void blinkColorValue(int color_index /* R-0, G-1, B-2 */){
    delay(200);
    printColorValue(color_index, true);
    delay(200);
    printColorValue(color_index);
}

void setup() {
    // Setun pins
    pinMode(SWITCH_BUTTON, INPUT_PULLUP);
    pinMode(INC_BUTTON, INPUT_PULLUP);
    // led
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_BLUE, OUTPUT);


    lcd.begin(16,2);
    lcd.print("Select color:");

    lcd.setCursor(0, 1);
    lcd.print("RGB  "); 
    
    lcd.setCursor(8, 1);
    lcd.print(",");
    lcd.setCursor(12, 1);
    lcd.print(",");


    // Show default values without blinking
    printColorValue(0);
    printColorValue(1);
    printColorValue(2);

    Serial.begin(9600);
}

void loop() {
    if(selected_color_index > 2) selected_color_index = 0; // reset if more then 2 (3 colors)
    // ======================
    blinkColorValue(selected_color_index);
    // ======================

    if(! digitalRead(SWITCH_BUTTON)) selected_color_index++; // switch color index

    if(! digitalRead(INC_BUTTON)){
        rgb[selected_color_index] += INC_STEP; // increase color value

        if(rgb[selected_color_index] > 255) rgb[selected_color_index] = 0; // reset to 0 if color value is more then 255
    }


    // Color the LED
    analogWrite(LED_RED,    rgb[0]);
    analogWrite(LED_GREEN,  rgb[1]);
    analogWrite(LED_BLUE,   rgb[2]);
}