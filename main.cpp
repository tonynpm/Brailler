#include <Arduino.h>
#include <Vector.h>
#include <Stepper.h>
#include "../src/subroutines/getState.h"
#include "../src/subroutines/turnPrimary.h"
#include "../src/subroutines/mapFunction.h"
const short int lp1 = 17;
const short int lp2 = 18;
const short int sbp = 2; //Pin number for send button
const short int bp1 = 3 ;//Pin number for 1st button
const short int bp2 = 4 ;//Pin number for 2nd button
const short int bp3 = 5 ;//Pin number for 3rd button
const short int bp4 = 6 ;//Pin number for 4rd button
const short int bp5 = 7 ;//Pin number for 5th button
const short int bp6 = 8 ;//Pin number for 6th button
const short int stepsPerRevolution = 200; //Number of steps needed for a motor to complete one full revolution

Stepper primary(stepsPerRevolution, 9,10,11,12); //The Primary motor (moves the pulley belt)
Stepper secondary(stepsPerRevolution, 13,14,15,16); //The Secondary motor (moves the die)
short int times = 0; //counts how many times a character has been changed
short int maxCharacters = 20; //the number of max characters achieved before restarting
short int sbp_state = 0; // the current state of the send button
short int total1 = 0; //the total for the first three pins
short int total2 = 0; //the total for the last three pins

bool r1=0; //keeps track of whether the 1st button has been pressed at last one before the send button has been pressed
bool r2=0; //keeps track of whether the 2nd button has been pressed at last one before the send button has been pressed
bool r3=0; //keeps track of whether the 3rd button has been pressed at last one before the send button has been pressed
bool r4=0;  //keeps track of whether the 4th button has been pressed at last one before the send button has been pressed
bool r5=0;  //keeps track of whether the 5th button has been pressed at last one before the send button has been pressed
bool r6=0;  //keeps track of whether the 6th button has been pressed at last one before the send button has been pressed
Vector<int> totals; // stores all the totals



void setup() {
  pinMode(sbp, INPUT_PULLUP);
  pinMode(bp1, INPUT_PULLUP);
  pinMode(bp2, INPUT_PULLUP);
  pinMode(bp3, INPUT_PULLUP);
  pinMode(bp4, INPUT_PULLUP);
  pinMode(bp5, INPUT_PULLUP);
  pinMode(bp6, INPUT_PULLUP);
  pinMode(lp1, OUTPUT);
  pinMode(lp2, OUTPUT);
  primary.setSpeed(20);
  secondary.setSpeed(20);
  digitalWrite(lp1, LOW);
  digitalWrite(lp2, LOW);

}

void changeSendButton(){ //reads the values of all buttons, acts whether send button is pressed once or held for more than 2s
  digitalWrite(lp1, HIGH);
  getState(bp1, bp2, bp3, total1, r1, r2, r3);
  getState(bp4, bp5, bp6, total2, r4, r5, r6);
  sbp_state = digitalRead(sbp);
  if (sbp_state==HIGH){
    delay(2000); // wait two seconds
    sbp_state = digitalRead(sbp);
    if (sbp_state==HIGH){
      total1 = 0;
      total2 = 0;
      r1 = 0;
      r2 = 0;
      r3 = 0;
      r4 = 0;
      r5 = 0;
      r6 = 0;
    }
    else{
      run();
      //main program
    }
  }
  delay(50);
}



void loop() {
  changeSendButton();
}


void run(){
    totals.push_back(total1);
    totals.push_back(total2);
    rotatePMotor(primary,secondary,stepsPerRevolution, total1, total2);
    times +=1;
    if(times >= maxCharacters){
      digitalWrite(lp2, HIGH);
      for(int i = 0; i<totals.size(); i+=1){ //for every character code int our totals vector
          //111
          int x  = mapFunction(totals.at(totals.size()-i)); //gets how many time the secondary motor has rotated the die
          if(x){ //if x is not 0 - if the secondary motor DID rotate a die
            for(int rotations = 0; rotations<8-x; rotations+=1){
                secondary.step(stepsPerRevolution);
            }
          }
          if(i%2){ //If we start at the last (half braille cell) we need to move a small gap to get to the next half
              primary.step(-4); //SMALL GAP
          }
          else{//move between different braille cells
              primary.step(-5); //BIG GAP
          }
          
      }
      times = 0;
      totals.clear();
      digitalWrite(lp2, LOW);
    }
}