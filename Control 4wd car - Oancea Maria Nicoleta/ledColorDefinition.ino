//Oancea Maria-Nicoleta

void commandLed(){
  if (command == 0 || command == 7) setColor(255, 0, 0);
  if (command == 1) setColor(0, 255, 0);
  if (command == 4) setColor(0, 255, 255);
  if (command == 2 || command == 3 || command == 5 || command == 6) setColor(255, 153, 0);
}

