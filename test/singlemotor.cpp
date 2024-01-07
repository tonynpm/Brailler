//2048 steps per revolution
//2ms delay per step
//500 steps per second

#include <Arduino.h>
#include <Stepper.h>

short p1 = 12;
short p2 = 14;
short p3 = 26;
short p4 = 27;

Stepper SecondaryStepper(2048, p1,p2,p3,p4);
void setup() {
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  SecondaryStepper.setSpeed(20);
}

void loop(){
  SecondaryStepper.step(2048);
  delay(1000);
}
  

