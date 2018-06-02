//Oancea Maria-Nicoleta

int getDistance() {
  digitalWrite(TRIGGER, LOW);
  delayMicroseconds(5);
  
  digitalWrite(TRIGGER, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(TRIGGER, LOW);

  int duration = pulseIn(ECHO, HIGH);
  return (duration / 58);
}

