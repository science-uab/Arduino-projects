#include <dht11.h>

#define pin 2 
dht11 dht;
 
void setup(){
 
  Serial.begin(9600);
  delay(500);
  Serial.println("Senzor de temperatura si umiditate\n\n");
  delay(1000);
 
}//end "setup()"
 
void loop(){
 
    dht.read(pin);
    
    Serial.print("Umiditate curenta = ");
    Serial.print(dht.humidity);
    Serial.print("%  ");
    Serial.print("Temperatura curenta = ");
    Serial.print(dht.temperature); 
    Serial.println("C  ");
    
    delay(1000);
 
}// end loop() 
