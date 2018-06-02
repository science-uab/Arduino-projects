//Oancea Maria-Nicoleta

void getGomand(){
  if (values[0] == "0") {
    command = 0;
    speed = 0;
  }
  if (values[0] == "1") remoteControl();
  if (values[0] == "2") faceControl();
  if (values[0] == "3") automaticMode();
}

void remoteControl(){
  command = values[1].toInt();
  if ( (command == 1 || command == 2 || command == 6) && objectDistance <= 30) command = 0;
  else command = values[1].toInt();
  if (command == 1 || command == 4) speed = values[2].toInt();
  else {
    if (values[2].toInt() * 1.6 <= 255) speed = values[2].toInt() * 1.6;
    else speed = 255;
  }
}

void faceControl(){
  command = values[1].toInt();
  faceDistance = values[2].toInt();
  if ( (command == 1 || command == 2 || command == 6) && objectDistance <= 30) command = 0;
  else command = values[1].toInt();
  
  if (command == 1 || command == 4) {
    if (faceDistance < 50 ) speed = 150;
    else speed = 250;
  }else speed = 250;
}

void automaticMode(){
  command = values[1].toInt();
  
  if(command != 0){
    if (objectDistance <= 30 ){
      command = 6;
      speed = 250;
      if (objectDistance <= 20 &&  objectDistance >= 12){ 
        command = 4;
        speed = 230; 
      }
      if (objectDistance < 12 ) { 
        command = 5;
        speed = 250;
      }
    } 
  }
  
  if (command != 1 || command != 4){ 
    speed = 250;
  }
  else speed = 190;
}

