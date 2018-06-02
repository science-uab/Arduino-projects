//Oancea Maria-Nicoleta

#include "variables.h"

void setup() {
  Serial.begin(9600);

  pinMode(MOTORLATCH, OUTPUT);
  pinMode(MOTORENABLE, OUTPUT);
  pinMode(MOTORDATA, OUTPUT);
  pinMode(MOTORCLK, OUTPUT);
  
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  commandRobot();
  commandLed(); 
}

void loop() {
  valueSerial = "";
  while (Serial.available()) {
    char c = Serial.read();
    valueSerial += c;
  }
  
  if (valueSerial != ""){
    values[0] = valueSerial.charAt(0);
    values[1] = valueSerial.charAt(1);
    values[2] = valueSerial.substring(2, valueSerial.length());
    
    //defining the travel command
    getGomand(); 
  }

  //detect distance from obstacle
  objectDistance = getDistance();
  Serial.println(values[0]+ ">>" + objectDistance);
  
  // control robot
  if (command != commandAux){
    commandRobot();  
    commandLed(); 
    commandAux = command;
  }
  if (values[0] == "3") {
    if (objectDistance != objectDistanceAux){
      commandRobot();
      commandLed(); 
      objectDistanceAux = objectDistance;
    }
    if (values[2].toInt() != faceDistanceAux){
      commandRobot();
      commandLed(); 
      faceDistanceAux = values[2].toInt();
    }
  }
  
  delay(100);
}

