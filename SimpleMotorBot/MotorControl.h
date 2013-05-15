#include <Arduino.h> 

const int FORWARD=1;
const int BACK=2;
const int STOP=0;

class Motor {
  public:
    int enable;
    int out1;
    int out2;
    
    Motor(int _enable, int _out1, int _out2) {
      enable = _enable;
      out1 = _out1;
      out2 = _out2;
      pinMode(enable, OUTPUT);
      pinMode(out1, OUTPUT);
      pinMode(out2, OUTPUT);
    }
   
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
      case BACK:
        digitalWrite(out1, HIGH);
        digitalWrite(out2, LOW);
        analogWrite(enable, speed);
        break;
    }
  }
  
  void forward(byte speed=255) {
    move(FORWARD, speed);
  }
  
  void back(byte speed=255) {
    move(BACK, speed);
  }
 
  void stop() {
    move(STOP, 0);
  }
};
