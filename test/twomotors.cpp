//2048 steps per revolution
//2ms delay per step
//500 steps per second

#include <Arduino.h>
#include <Stepper.h>

short p1 = 12;
short p2 = 14;
short p3 = 26;
short p4 = 27;

short p5 = 25;
short p6 = 33;
short p7 = 32;
short p8 = 35;


Stepper PrimaryStepper(2048, p5,p7,p6,p8);
Stepper SecondaryStepper(2048, p1,p3,p2,p4); //PINS MUST BE IN ORDER OF 1,3,2,4
void setup() {
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  pinMode(p5, OUTPUT);
  pinMode(p6, OUTPUT);
  pinMode(p7, OUTPUT);
  pinMode(p8, OUTPUT);
  SecondaryStepper.setSpeed(20);
  PrimaryStepper.setSpeed(20);

}

void loop(){
  SecondaryStepper.step(2048);
  PrrimaryStepper.step(-2048);
  delay(20);
}
  
