// This file contains a subrouine for rotating the secondary motor (used to rotate the dies)
#include <Arduino.h>
#include <Stepper.h>

void turnMotor(Stepper stepm, short int spfr,short int total){
    //delay needed ?
    int rotated;
    switch (total){
        case 0:
            stepm.step(0);
            rotated = 0;
        case 1:
            stepm.step(spfr);
             rotated = 1;
        case 10:
            stepm.step(spfr);
            stepm.step(spfr);
             rotated = 2;
        case 11:
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
             rotated = 3;
        case 100:
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            rotated = 4;
        case 101:
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            rotated = 5;
        case 110:
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            rotated = 6;
        case 111:
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            stepm.step(spfr);
            rotated = 7;
    }
    
}
