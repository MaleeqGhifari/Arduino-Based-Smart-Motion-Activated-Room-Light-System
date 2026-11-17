#include <Servo.h>
Servo myServo;
const int PIR_PIN = 2;
const int LedPin1 = 7;
const int LedPin2 = 12;
const int svpin = 8;
int svpos = 120;
int sensorState = 0;
int lastSensorState = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  pinMode(LedPin1, OUTPUT);
  pinMode(LedPin2, OUTPUT);
  digitalWrite(LedPin1, LOW);
  digitalWrite(LedPin2, HIGH);
  
  myServo.attach(svpin);
  myServo.write(svpos);
  delay(10000);
  myServo.detach();
}

void loop() {
  sensorState = digitalRead(PIR_PIN);

  if (sensorState == HIGH && lastSensorState == LOW) {
    if (svpos == 120) {
      svpos = 40;
      digitalWrite(LedPin1, HIGH);
      digitalWrite(LedPin2, LOW);
    } else {
      svpos = 120;
      digitalWrite(LedPin1, LOW);
      digitalWrite(LedPin2, HIGH);
    }

    myServo.attach(svpin);
    myServo.write(svpos);
    delay(300);
    myServo.detach(); 
  } 
  
  lastSensorState = sensorState;
  delay(100);
}