/* Sensing robot */
#include "MotorControl.h"

Motor motorA(3, 4, 5);
Motor motorB(10, 8, 9);

void setup() {
  motorA.forward();
  motorB.forward();
  delay(2000);
  motorA.forward();
  motorB.back();
  delay(1000);
  motorA.forward();
  motorB.forward();
  delay(2000);
  motorA.stop();
  motorB.stop();
}

void loop() {
//
}
