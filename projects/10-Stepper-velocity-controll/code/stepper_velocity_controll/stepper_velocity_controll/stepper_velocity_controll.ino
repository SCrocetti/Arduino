#include <Stepper.h>

// this is calculated with the datasheet
const int stepsPerRevolution = 4096;
const int maxSpeed = 5;

// maximun  latency in ms, its the time it freezes to do the steps
const int maxDelay=30;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
}

void loop() {
  int pot = analogRead(A0);
  int speed=0;
  int direction=0;
  if(pot==511 || pot==512){
    return;
  }
  if(pot>512){
    direction=-1;
    speed=map(pot,512,1023,0,maxSpeed);
  }
  else if(pot<511){
    direction=1;
    speed=map(pot,0,511,0,maxSpeed);
  }

  myStepper.setSpeed(speed);
  // t_step = 60 / (speed × stepsPerRevolution)
  // maxDelay=steps*t_step
  // steps= maxDelay/t_step
  // steps= (30/1000*60/speed*stepsPerRevolution)
  int steps=speed*stepsPerRevolution/2000;
  myStepper.step(steps*direction); 
}