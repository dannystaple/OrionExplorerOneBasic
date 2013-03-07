#include "MotorControl.h"

//Setup the motor pins
Motor motorA(3, 2, 4);
Motor motorB(5, 6, 7);

void setup() {
  motorA.setup();
  motorB.setup();
  //Start here
  
  motorA.move(FORWARD, 255);
  motorB.move(FORWARD, 255);
  delay(2000);
  
  //stop!
  motorA.move(STOP, 0);
  motorB.move(STOP, 0);
}

void loop() {

}
