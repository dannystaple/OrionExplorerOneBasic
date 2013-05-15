/* Sensing robot */
#include "MotorControl.h"

Motor motorA(3, 4, 5);
Motor motorB(10, 8, 9);
#define LED 13

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  motorA.move(FORWARD, 255);
  motorB.move(FORWARD, 255);
  motorA.forward(255);
  motorB.forward(255);
  delay(2000);
  motorA.forward(255);
  motorB.back(255);
  delay(1000);
  motorA.forward(255);
  motorB.forward(255);
  delay(2000);
  motorA.stop();
  motorB.stop();
}

void loop() {
//
}
