#include <Stepper.h>

// this is calculated with the datasheet
const int stepsPerRevolution = 2048;
const int maxSpeed = 5;

// maximun  latency in ms, its the time it freezes to do the steps
const int maxDelay=30;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
}

void loop() {
  int pot = analogRead(A0);

  if (abs(pot - 512) < 5) return;

  int direction;
  int speed;

  if (pot > 512) {
    direction = -1;
    speed = map(pot, 512, 1023, 0, maxSpeed);
  } else {
    direction = 1;
    speed = map(pot, 511, 0, 0, maxSpeed);
  }

  if(speed==0)
    return

  myStepper.setSpeed(speed);
  int steps=maxDelay*speed*stepsPerRevolution/60000;
  myStepper.step(steps*direction );
}