int senzor1 = A0;
int senzor2 = A1;
int MOTOR2_PIN1 = 4;
int MOTOR2_PIN2 = 5;
int MOTOR1_PIN1 = 6;
int MOTOR1_PIN2 = 7;
int i;

void setup() {
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int s1 = analogRead(senzor1);
  Serial.println(" SENZOR 1: ");
  Serial.print(s1);
  int s2 = analogRead(senzor2);
  Serial.println(" SENZOR 2: ");
  Serial.print(s2);
  
  if (s1>300 && s2>300) 
 { 
   analogWrite(MOTOR1_PIN1,120); 
   analogWrite(MOTOR1_PIN2, 150);   
   analogWrite(MOTOR2_PIN1,150 ); 
   analogWrite(MOTOR2_PIN2,120);
   i=3;
  }   
  
 if (s1>s2) 
 { 
   analogWrite(MOTOR1_PIN1,0); 
   analogWrite(MOTOR1_PIN2, 0);   
   analogWrite(MOTOR2_PIN1,130 ); 
   analogWrite(MOTOR2_PIN2,100);
   i=2;
  }   
 
 //Left
 if (s2>s1) 
 { 
   analogWrite(MOTOR1_PIN1,100); 
   analogWrite(MOTOR1_PIN2,130 );   
   analogWrite(MOTOR2_PIN1,0 ); 
   analogWrite(MOTOR2_PIN2,0);
   i=3;
   //Right
  }
 if (i=2 && s1<200 && s2<200) 
 {
   analogWrite(MOTOR1_PIN1,100); 
   analogWrite(MOTOR1_PIN2,130 );   
   analogWrite(MOTOR2_PIN1,0 ); 
   analogWrite(MOTOR2_PIN2,0);
   i==i+5;
  }
  //If out Left do Right Moves
 if (i=3 && s1<200 && s2<200) 
 {
   analogWrite(MOTOR1_PIN1,0); 
   analogWrite(MOTOR1_PIN2,0 );   
   analogWrite(MOTOR2_PIN1,130 ); 
   analogWrite(MOTOR2_PIN2,100);
   i==i+5;
  }
  //If out Right do Left Moves
 if (i>500 && s1<200 && s2<200) 
 {
   analogWrite(MOTOR1_PIN1,0 ); 
   analogWrite(MOTOR1_PIN2,0 );   
   analogWrite(MOTOR2_PIN1,0 ); 
   analogWrite(MOTOR2_PIN2,0);
   delay(100); 
}
//Stop
}

 
 

