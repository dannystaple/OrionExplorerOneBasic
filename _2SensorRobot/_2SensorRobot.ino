

/* Sensing robot */
#include "MotorControl.h"

class SR04 {
  private:
    int _trigPin;
    int _echoPin;
  public:
    SR04(int trigPin, int echoPin) {
      _trigPin = trigPin;
      _echoPin = echoPin;
      pinMode(_trigPin, OUTPUT);
      pinMode(_echoPin, INPUT);
    }
    
    void trigger() {
      // the sr04 is triggered by a HIGH pulse of 10 or more microseconds.
      // Short low pulse, clean high, then low.
      digitalWrite(_trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(_trigPin, HIGH);
      delayMicroseconds(11);
      digitalWrite(_trigPin, LOW);
    }

    long microsecondsToCentimeters(long microseconds)
    {
      // The speed of sound is 340 m/s or 29 microseconds per centimeter.
      // The ping travels out and back, so to find the distance of the
      // object we take half of the distance travelled.
      return microseconds / 58; // (use 148 for inches) 
    }
    
    long readDist() {
      trigger();
      // The echo pin is used to read the signal from the hc-sr04. A HIGH
      // pulse whose duration is the time (in microseconds) from the sending
      // of the ping to the reception of its echo off of an object.
      long duration = pulseIn(_echoPin, HIGH);
      // convert the time into a distance
      int cm = microsecondsToCentimeters(duration);
      return cm;
    }
};

#define LED 13

Motor motorLeft(3, 4, 5);
Motor motorRight(10, 8, 9);
SR04 sensorLeft(11, 12);
SR04 sensorRight(6, 7);

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
//  motorLeft.forward();
//  motorRight.forward();
  Serial.begin(9600);
}

void debug_loop() {
  int l = sensorLeft.readDist();
  int r = sensorRight.readDist();
  Serial.print("Left:");
  Serial.println(l);
  Serial.print("Right:");
  Serial.println(r);
}

#define SENSOR_AVOID_DIST 30
#define SENSOR_FOLLOW_DIST 80

void two_sensor_loop() {
  int l = sensorLeft.readDist();
  int r = sensorRight.readDist();
  while(l < SENSOR_AVOID_DIST || r < SENSOR_AVOID_DIST) {
    digitalWrite(LED, HIGH);
    // If the closest object is left, we want the right motor to back
    if (l < r) {
      motorRight.forward();
      motorLeft.back();
    } else {
      motorLeft.forward();
      motorRight.back();
    }
    delay(60);
    l = sensorLeft.readDist();
    r = sensorRight.readDist();
  }
//  if(l < SENSOR_FOLLOW_DIST || r< SENSOR_FOLLOW_DIST) {
//    if (l <
//    r) {
//      motorLeft.back();
//      motorRight.forward();
//    } else {
//      motorRight.back();
//      motorLeft.forward();
//    }
//  }
    
  digitalWrite(LED, LOW);
  motorLeft.forward();
  motorRight.forward();
}

void loop() {
  two_sensor_loop();
//  debug_loop();
}

