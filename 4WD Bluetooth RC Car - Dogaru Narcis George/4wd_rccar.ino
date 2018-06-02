//Author Dogaru Narcis George

#include "mycommands.h"

#define MOTORLATCH 12
#define MOTORCLK 4
#define MOTORENABLE 7
#define MOTORDATA 8

#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR3_A 5
#define MOTOR3_B 7
#define MOTOR4_A 0
#define MOTOR4_B 6

#define MOTOR1_PWM 11
#define MOTOR2_PWM 3
#define MOTOR3_PWM 6
#define MOTOR4_PWM 5

int redPin= A1;
int greenPin = A3;
int bluePin = A2;

void setup() {
  Serial.begin(38400);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  char c;
  String serial;
  
  while(Serial.available() > 0) {
    c = ((byte)Serial.read());
    if(c == ':') {
      break;
    } else {
      serial += c;
    }
  }

  if(serial != "") {
    Serial.println(serial);
    int type = serial.substring(0,3).toInt();

    if(type == TYPE_A) {
      typeaController(serial);
    } else if(type == TYPE_B) {
      typebController(serial);
    }else {
      setColor(255,0,0);
    }
  } 
  delay(100);
}

void typeaController(String data) {
  
  int cmd = data.substring(3,6).toInt();  
   
   switch(cmd) {
      case GO_FO:
      {
        setColor(0,255,0);  
        int speed = data.substring(6,9).toInt();
        if(speed <= 255) {
          motor(1, GO_FO, speed); 
          motor(2, GO_FO, speed); 
          motor(3, GO_FO, speed); 
          motor(4, GO_FO, speed);
        }
        break;
      } 
      
      case GO_LEFT:
      {
        setColor(255,255,0); 
        int rotate_direction = data.substring(7,10).toInt();

        switch(rotate_direction) {
          case ROTATE_D:
              motor(1, BRAKE, 0);
              motor(2, BRAKE, 0); 
              motor(3, GO_FO, 255); 
              motor(4, GO_FO, 255);
            break;
          case ROTATE_R:
              motor(1, GO_BA, 255); 
              motor(2, GO_BA, 255);
              motor(3, BRAKE, 0); 
              motor(4, BRAKE, 0);
            break;
        }
        break;
      }
      
      case GO_RIGHT:
      {
        setColor(0,255,255); 
        int rotate_direction = data.substring(7,10).toInt();

        switch(rotate_direction) {
          case ROTATE_D:
            motor(1, GO_FO, 255); 
            motor(2, GO_FO, 255); 
            motor(3, BRAKE, 0); 
            motor(4, BRAKE, 0);
            break;
          case ROTATE_R: 
            motor(1, BRAKE, 0);
            motor(2, BRAKE, 0); 
            motor(3, GO_BA, 255);
            motor(4, GO_BA, 255);
            break;
        }
        break;
      } 
      case GO_BA:
      {
        setColor(0,0,255);
        int speed = data.substring(6,9).toInt();
        if(speed <= 255) {
          motor(1, GO_BA, speed);
          motor(2, GO_BA, speed);
          motor(3, GO_BA, speed);
          motor(4, GO_BA, speed);
        }
        break;
      }
      case STOP:
        setColor(255,0,0); 
        motor(1, STOP, 0); 
        motor(2, STOP, 0); 
        motor(3, STOP, 0); 
        motor(4, STOP, 0);
        break;
        
      case BRAKE:
        setColor(255,0,255);
        motor(1, BRAKE, 0); 
        motor(2, BRAKE, 0); 
        motor(3, BRAKE, 0);
        motor(4, BRAKE, 0);
        break;
        
      default:
        setColor(255,0,0);
        motor(1, STOP, 0); 
        motor(2, STOP, 0); 
        motor(3, STOP, 0); 
        motor(4, STOP, 0); 
        break;
    }
}

void typebController(String data) {
  int cmd = data.substring(3,6).toInt();

  switch(cmd) {
      case ACCELERATE:
      {
        setColor(0,255,0);
          motor(1, GO_FO, 250); 
          motor(2, GO_FO, 250); 
          motor(3, GO_FO, 250); 
          motor(4, GO_FO, 250); 
        break;
      }
      case REVERSE:
      {
        setColor(0,0,255);
          motor(1, GO_BA, 250); 
          motor(2, GO_BA, 250);
          motor(3, GO_BA, 250);
          motor(4, GO_BA, 250);
        break;
      }
      case GO_LEFT_B:
      {
        setColor(255,255,0);
        int speed = data.substring(6,9).toInt();
        int rotateSensitivity = data.substring(9).toInt();

        switch(rotateSensitivity) {
          case 2:
          {
            int rotateSpeed = speed - 40;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
            
            motor(1, GO_FO, rotateSpeed); 
            motor(2, GO_FO, rotateSpeed);
            motor(3, GO_FO, speed); 
            motor(4, GO_FO, speed); 
            break;
            
          }
          case 3:
          {
            int rotateSpeed = speed - 80;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_FO, rotateSpeed); 
            motor(2, GO_FO, rotateSpeed);
            motor(3, GO_FO, speed); 
            motor(4, GO_FO, speed); 
            break;
          }
          case 4:
          {
            int rotateSpeed = speed - 100;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_FO, rotateSpeed); 
            motor(2, GO_FO, rotateSpeed); 
            motor(3, GO_FO, speed); 
            motor(4, GO_FO, speed); 
            break;
          }
          case 5:
          {
            int rotateSpeed = speed - 120;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_FO, rotateSpeed); 
            motor(2, GO_FO, rotateSpeed); 
            motor(3, GO_FO, speed); 
            motor(4, GO_FO, speed); 
            break;
          }
          case 6:
          {     
            motor(1, BRAKE, 0); 
            motor(2, BRAKE, 0); 
            motor(3, GO_FO, speed); 
            motor(4, GO_FO, speed); 
            break;
          }
            
        }
        break;
      }
      case GO_RIGHT_B:
      {
        setColor(0,255,255);
        
        int speed = data.substring(6,9).toInt();
        int rotateSensitivity = data.substring(9).toInt();

        switch(rotateSensitivity) {
          case 2:
          {
            int rotateSpeed = speed - 40;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_FO, speed); 
            motor(2, GO_FO, speed);
            motor(3, GO_FO, rotateSpeed); 
            motor(4, GO_FO, rotateSpeed);
            break;
            
          }
          case 3:
          {
            int rotateSpeed = speed - 80;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_FO, speed); 
            motor(2, GO_FO, speed); 
            motor(3, GO_FO, rotateSpeed); 
            motor(4, GO_FO, rotateSpeed); 
            break;
          }
          case 4:
          {
            int rotateSpeed = speed - 100;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_FO, speed); 
            motor(2, GO_FO, speed);
            motor(3, GO_FO, rotateSpeed); 
            motor(4, GO_FO, rotateSpeed);
            break;
          }
          case 5:
          {
            int rotateSpeed = speed - 120;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_FO, speed); 
            motor(2, GO_FO, speed); 
            motor(3, GO_FO, rotateSpeed); 
            motor(4, GO_FO, rotateSpeed); 
            break;
          }
          case 6:
          {     
            motor(1, GO_FO, speed); 
            motor(2, GO_FO, speed); 
            motor(3, BRAKE, 0); 
            motor(4, BRAKE, 0); 
            break;
          }
            
        }
        break;
      }
      case GO_RIGHT_R:
      {
        setColor(255,255,0);   
        int speed = data.substring(6,9).toInt();
        int rotateSensitivity = data.substring(9).toInt();

        switch(rotateSensitivity) {
          case 2:
          {
            int rotateSpeed = speed - 40;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
            
            motor(1, GO_BA, rotateSpeed); 
            motor(2, GO_BA, rotateSpeed);
            motor(3, GO_BA, speed); 
            motor(4, GO_BA, speed); 
            break;
            
          }
          case 3:
          {
            int rotateSpeed = speed - 80;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_BA, rotateSpeed); 
            motor(2, GO_BA, rotateSpeed); 
            motor(3, GO_BA, speed); 
            motor(4, GO_BA, speed); 
            break;
          }
          case 4:
          {
            int rotateSpeed = speed - 100;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_BA, rotateSpeed); 
            motor(2, GO_BA, rotateSpeed); 
            motor(3, GO_BA, speed); 
            motor(4, GO_BA, speed); 
            break;
          }
          case 5:
          {
            int rotateSpeed = speed - 120;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_BA, rotateSpeed); 
            motor(2, GO_BA, rotateSpeed); 
            motor(3, GO_BA, speed); 
            motor(4, GO_BA, speed); 
            break;
          }
          case 6:
          {     
            motor(1, BRAKE, 0); 
            motor(2, BRAKE, 0); 
            motor(3, GO_BA, speed); 
            motor(4, GO_BA, speed); 
            break;
          }
            
        }
        break;
      }
      case GO_LEFT_R:
      {
        setColor(0,255,255);
        
        int speed = data.substring(6,9).toInt();
        int rotateSensitivity = data.substring(9).toInt();

        switch(rotateSensitivity) {
          case 2:
          {
            int rotateSpeed = speed - 40;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_BA, speed); 
            motor(2, GO_BA, speed); 
            motor(3, GO_BA, rotateSpeed);
            motor(4, GO_BA, rotateSpeed);
            break;
            
          }
          case 3:
          {
            int rotateSpeed = speed - 80;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_BA, speed); 
            motor(2, GO_BA, speed); 
            motor(3, GO_BA, rotateSpeed); 
            motor(4, GO_BA, rotateSpeed);
            break;
          }
          case 4:
          {
            int rotateSpeed = speed - 100;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_BA, speed); 
            motor(2, GO_BA, speed); 
            motor(3, GO_BA, rotateSpeed);
            motor(4, GO_BA, rotateSpeed); 
            break;
          }
          case 5:
          {
            int rotateSpeed = speed - 120;

            if(rotateSpeed < 120) {
              rotateSpeed = 120;
            }
        
            motor(1, GO_BA, speed); 
            motor(2, GO_BA, speed); 
            motor(3, GO_BA, rotateSpeed); 
            motor(4, GO_BA, rotateSpeed); 
            break;
          }
          case 6:
          {     
            motor(1, GO_BA, speed); 
            motor(2, GO_BA, speed); 
            motor(3, BRAKE, 0); 
            motor(4, BRAKE, 0); 
            break;
          }
            
        }
        break;
      }
      case BRAKE_B:
        setColor(255,0,255);
        motor(1, STOP, 0); 
        motor(2, STOP, 0); 
        motor(3, STOP, 0); 
        motor(4, STOP, 0); 
        break;
        
      default:
        setColor(255,0,0);
        motor(1, STOP, 0); 
        motor(2, STOP, 0); 
        motor(3, STOP, 0); 
        motor(4, STOP, 0); 
        break; 
  }  
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void motor(int nMotor, int command, int speed)
{
  int motorA, motorB;

  if (nMotor >= 1 && nMotor <= 4)
  {  
    switch (nMotor)
    {
      case 1:
        motorA   = MOTOR1_A;
        motorB   = MOTOR1_B;
        break;
      case 2:
        motorA   = MOTOR2_A;
        motorB   = MOTOR2_B;
        break;
      case 3:
        motorA   = MOTOR3_A;
        motorB   = MOTOR3_B;
        break;
      case 4:
        motorA   = MOTOR4_A;
        motorB   = MOTOR4_B;
        break;
      default:
        break;
    }

    switch (command)
    {
      case GO_FO:
        motor_output (motorA, LOW, speed);
        motor_output (motorB, HIGH, -1);
        break;  
      case GO_BA:
        motor_output (motorA, HIGH, speed);
        motor_output (motorB, LOW, -1);
        break;
       case BRAKE:
        motor_output (motorA, LOW, 255);
        motor_output (motorB, LOW, -1);
        break;
      case STOP:
        motor_output (motorA, LOW, 0); 
        motor_output (motorB, LOW, -1);
        break;
      default:
        break;
    }
  }
}

void motor_output (int output, int high_low, int speed)
{
  int motorPWM;
  
  switch (output){
    case MOTOR1_A:
    case MOTOR1_B:
      motorPWM = MOTOR1_PWM;
      break;
    case MOTOR2_A:
    case MOTOR2_B:
      motorPWM = MOTOR2_PWM;
      break;
    case MOTOR3_A:
    case MOTOR3_B:
      motorPWM = MOTOR3_PWM;
      break;
    case MOTOR4_A:
    case MOTOR4_B:
      motorPWM = MOTOR4_PWM;
      break;
    default:
    speed = -1000;
    break;
  }

  if (speed != -1000)
  {
    shiftWrite(output, high_low);
    if (speed >= 0 && speed <= 255)    
    {
      analogWrite(motorPWM, speed);
    }
    
  } 
}

void shiftWrite(int output, int high_low)
{
  static int latch_copy;
  static int shift_register_initialized = false;

  if (!shift_register_initialized)
  {
    pinMode(MOTORLATCH, OUTPUT);
    pinMode(MOTORENABLE, OUTPUT);
    pinMode(MOTORDATA, OUTPUT);
    pinMode(MOTORCLK, OUTPUT);

    digitalWrite(MOTORDATA, LOW);
    digitalWrite(MOTORLATCH, LOW);
    digitalWrite(MOTORCLK, LOW);

    digitalWrite(MOTORENABLE, LOW);

    latch_copy = 0;
    shift_register_initialized = true;
  }

  bitWrite(latch_copy, output, high_low);
  
  shiftOut(MOTORDATA, MOTORCLK, MSBFIRST, latch_copy);
  delayMicroseconds(5);
  digitalWrite(MOTORLATCH, HIGH);
  delayMicroseconds(5);
  digitalWrite(MOTORLATCH, LOW);
}

