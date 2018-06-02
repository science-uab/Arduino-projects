//Oancea Maria-Nicoleta

void commandRobot(){
  switch(command){
    case STOP: 
      motor(1, STOP, speed); 
      motor(2, STOP, speed); 
      motor(3, STOP, speed); 
      motor(4, STOP, speed); 
      break;
    case FORWARD: 
      motor(1, FORWARD, speed); 
      motor(2, FORWARD, speed); 
      motor(3, FORWARD, speed); 
      motor(4, FORWARD, speed); 
      break;
    case FORWARD_RIGHT: 
      motor(1, FORWARD, speed); 
      motor(2, FORWARD, speed); 
      motor(3, BREAK, speed); 
      motor(4, BREAK, speed); 
      break;
    case BACKWARD_RIGHT: 
      motor(1, BACKWARD, speed); 
      motor(2, BACKWARD, speed); 
      motor(3, BREAK, speed); 
      motor(4, BREAK, speed); 
      break;
    case BACKWARD: 
      motor(1, BACKWARD, speed); 
      motor(2, BACKWARD, speed); 
      motor(3, BACKWARD, speed); 
      motor(4, BACKWARD, speed); 
      break;
    case BACKWARD_LEFT: 
      motor(1, BREAK, speed); 
      motor(2, BREAK, speed); 
      motor(3, BACKWARD, speed); 
      motor(4, BACKWARD, speed); 
      break;
    case FORWARD_LEFT: 
      motor(1, BREAK, speed); 
      motor(2, BREAK, speed); 
      motor(3, FORWARD, speed); 
      motor(4, FORWARD, speed); 
      break;
    case BREAK: 
      motor(1, BREAK, speed); 
      motor(2, BREAK, speed); 
      motor(3, BREAK, speed); 
      motor(4, BREAK, speed); 
      break;
    default:
      break;
  }
}

void motor(int motorNumber, int command, int speed){
  int motorA;
  int motorB;

  switch(motorNumber) {
    case 1:
      motorA = MOTOR1_A;
      motorB = MOTOR1_B;
      break;
    case 2:
      motorA = MOTOR2_A;
      motorB = MOTOR2_B;
      break;
    case 3:
      motorA = MOTOR3_A;
      motorB = MOTOR3_B;
      break;
    case 4:
      motorA = MOTOR4_A;
      motorB = MOTOR4_B;
      break;
    default:
      break;
  }

  switch(command){
    case STOP:
      motorOutput (motorA, LOW, 0);  
      motorOutput (motorB, LOW, -1); 
      break;
    case FORWARD:
      motorOutput (motorA, LOW, speed);  
      motorOutput (motorB, HIGH, -1); 
      break;
    case BACKWARD:
      motorOutput (motorA, HIGH, speed);  
      motorOutput (motorB, LOW, -1); 
      break;
    case BREAK:
      motorOutput (motorA, LOW, 255);  
      motorOutput (motorB, LOW, -1); 
      break;
    default:
      break;
  }  
}

void motorOutput(int pin, int power, int speed){
  int motorPWM;
  boolean wrong = false;

  switch(pin){
    case MOTOR1_A:
      motorPWM = MOTOR1_PWM;
      break;
    case MOTOR1_B:
      motorPWM = MOTOR1_PWM;
      break;
    case MOTOR2_A:
      motorPWM = MOTOR2_PWM;
      break;
    case MOTOR2_B:
      motorPWM = MOTOR2_PWM;
      break;
    case MOTOR3_A:
      motorPWM = MOTOR3_PWM;
      break;
    case MOTOR3_B:
      motorPWM = MOTOR3_PWM;
      break;
    case MOTOR4_A:
      motorPWM = MOTOR4_PWM;
      break;
    case MOTOR4_B:
      motorPWM = MOTOR4_PWM;
      break;
    default:
      wrong = true;
      break;
  }

  if (!wrong){
    pinWrite(pin, power);
    if (speed >= 0 && speed <= 255){
      analogWrite(motorPWM, speed);
    }
  }
}

void pinWrite(int pin, int power){
  static int latch;
  static boolean initialized = false;

  if (! initialized){
    digitalWrite(MOTORDATA, LOW);
    digitalWrite(MOTORLATCH, LOW);
    digitalWrite(MOTORCLK, LOW);
    digitalWrite(MOTORENABLE, LOW);
    latch = 0;
    initialized = true;
  }

  bitWrite(latch, pin, power);
  shiftOut(MOTORDATA, MOTORCLK, MSBFIRST, latch);
  delayMicroseconds(5);
  digitalWrite(MOTORLATCH, HIGH);
  delayMicroseconds(5);
  digitalWrite(MOTORLATCH, LOW);
}

