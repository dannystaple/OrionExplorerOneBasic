#include <Arduino.h> 
/* Use these constants with the move function */
const int FORWARD=1;
const int BACKWARD=2;
const int STOP=0;

/* This class represents a motor channel on an H-bridge. */
class Motor {
  public:
    int enable;
    int out1;
    int out2;
    
    //Construct the motor - this can be done globally if it's needed in setup and loop.
    Motor(int _enable, int _out1, int _out2) {
      enable = _enable;
      out1 = _out1;
      out2 = _out2;
    }
    
    //Call this to actually initialise the pins.
    void setup() {
      pinMode(enable, OUTPUT);
      pinMode(out1, OUTPUT);
      pinMode(out2, OUTPUT);
    }
   
    //Start the motor moving.
    //Call with directions FORWARD, BACKWARD or STOP.
    //Speed controls the PWM output - values below about 90 will probably make the motor stall.
    //255 is 100%.
    void move(int direction, byte speed) {
      switch(direction) {
        default:  // and STOP
          digitalWrite(out1, LOW);
          digitalWrite(out2, LOW);
          analogWrite(enable, 0);
          break;
        case FORWARD:
          digitalWrite(out1, LOW);
          digitalWrite(out2, HIGH);
          analogWrite(enable, speed);
          break;
        case BACKWARD:
          digitalWrite(out1, HIGH);
          digitalWrite(out2, LOW);
          analogWrite(enable, speed);
          break;
      }
  }
};
