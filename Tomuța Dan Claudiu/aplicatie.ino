//Tomuta Dan Claudiu
#include <cactus_io_AM2302.h>
#include <PCD8544.h>

static PCD8544 lcd; // obiectul lcd de tip PCD8544
int pinSenzor = 2;
AM2302 senzorT(pinSenzor);
int trigPin= 8;
int echoPin = 9;
int pinLed = 10;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(pinLed, OUTPUT);
  senzorT.begin();
  lcd.begin(84, 48); // rezolutie display
  introducere();
}

void loop() {
  lcd.setCursor(0, 0);
  emitePuls();
  int dist = (int)masoaraDistanta();
  senzorT.readHumidity();
  senzorT.readTemperature();
  if(dist<4) {
    lcd.print("Obiectul este prea apropiat");
    digitalWrite(pinLed, HIGH);
  }
  if(dist>100) {
    lcd.print("Obiectul este prea departat");
    digitalWrite(pinLed, HIGH);
  }
  if ((dist>=4) and (dist<=100)) {
    delay(300);
    digitalWrite(pinLed, LOW);
    lcd.clear();
    lcd.print("Distanta: ");
    lcd.print(dist);
    lcd.print("cm");
  }
  lcd.setCursor(0, 2);
  lcd.print(" Temperatura:   ");
  lcd.print((int)senzorT.temperature_C);
  lcd.print(" grade C");
  lcd.print("    Umiditate:        ");
  lcd.print((int)senzorT.humidity);
  lcd.print(" %");
}

void introducere() {
  lcd.setCursor(15, 20);
  lcd.print("Salut !!!");
  delay(1500);
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("Aceasta este  prezentarea  mea in Arduino    (Dany)");
  delay(3000);
  lcd.clear();
}

void emitePuls() { 
  //emite un ultrasunet, care se reflecta din obiectul x
  digitalWrite(trigPin, LOW);
  //pe low este oprit ultrasunetul
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  //pe high este pornit ultrasunetul
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
}

float masoaraDistanta() {
  int durata = pulseIn(echoPin, HIGH);
  float distanta = durata*0.034/2;     
  //distanta = timp * viteza_sunetului_in _aer / 2
  return distanta;
}

