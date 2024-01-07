//2048 steps per revolution
//2ms delay per step
//500 steps per second

#include <Arduino.h>
#include <Stepper.h>


short p1 = 33;
short p2 = 32;
short p3 = 13;
short p4 = 34;

short pp1 = 12;
short pp2 = 14;
short pp3 = 27;
short pp4 = 26;

Stepper PrimaryStepper(2048, p1,p3,p2,p4); 
Stepper XrimaryStepper(2048, pp1,pp3,pp2,pp4);

//PINS MUST BE IN ORDER OF 1,3,2,4
void setup() {
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(pp1, OUTPUT);
  pinMode(pp2, OUTPUT);
  pinMode(pp3, OUTPUT);
  pinMode(pp4, OUTPUT);
  PrimaryStepper.setSpeed(20);
  XrimaryStepper.setSpeed(20);
}

void loop(){
  PrimaryStepper.step(2048);
  XrimaryStepper.step(2048);
  delay(50);
}
  
