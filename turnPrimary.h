//This file contains a subroutine used to rotate the primary motor (used to move the secondary motor in a pulley)
//should also store a tracking dictionary which keeps track of how many times each braille cell has been rotated so it can be reversed
#include <Arduino.h>
#include <Stepper.h>
#include "../src/subroutines/turnSecondary.h"
void rotatePMotor(Stepper stepm, Stepper stepn, short int spfr, short int total1, short int total2){

    // The ratio between the steps per full revolution and a small gap (between half braille cells);
    short int small_gap = spfr/50; //4 steps
    // The ratio between the steps per full revolution and a big gap (between braille cells);
    short int big_gap = spfr/40; //5 steps
    //number of character
    stepm.step(big_gap);
    turnMotor(stepn,spfr, total1);
    stepm.step(small_gap);
    turnMotor(stepn, spfr, total2);
    
    //TEST TO SEE HOW MANY ROTATIONS CAN MOVE THE SECOND MOTOR ACROSS THE PULLEY BELT : loops
};