#include <LiquidCrystal.h> // includes the LiquidCrystal Library 

int trig = 2;
int echo = 3;
long lecture_echo;
long cm;
LiquidCrystal lcd(1, 10, 4, 5, 6, 7); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

void setup() {
  lcd.begin(16,1);
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  
}

void loop() {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  cm = pulseIn(echo,HIGH) /58;
  
  printLog(cm);
  checkDistance(cm);
}

void checkDistance(int cm) {
    if (cm < 10) {
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    displayLcd("NOT OK");

  } else {
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
     displayLcd("OK");
  }
}

void printLog(int cm) {
  Serial.print("Distance en cm :");
  Serial.println(cm);
}

void displayLcd(String info) {
  lcd.clear();
  delay(100);
  lcd.home();
  lcd.print(info);
  delay(4000);
  
}
