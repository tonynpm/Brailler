#include <Arduino.h>
//The function below is used to decipher which buttons are pressed

//1. RECIEVE PINS OF BUTTONS IN ARGUMENTS
//2. DETECT IF SENT BUTTON PRESSED ONCE IN 2S
//3. DETECT IF SENT BUTTON PRESSED TWICE IN 2S


void getState(short int p1, short int p2, short int p3, short int  &total,bool  &r1,bool  &r2,bool  &r3){
  int i = digitalRead(p1);
  int j = digitalRead(p2);
  int k = digitalRead(p3); 

  if(i==HIGH && r1==0){
    total += 1;
    r1 = 1;
    
  }
  if(j==HIGH && r2==0){
    total += 10;
    r2 = 1;
  }
  if(k==HIGH && r3 ==0){
    total += 100;
    r3 = 1;
  }
}

//in main program 
//1. run detect state twice using different pins
//2. store these results in variables x and y,
//3. In a vector store these numbers everytime turnPMotor is run
//4. Run a for each loop on the vector, starting at the end position
//5. make sprfm negative to move pmotor anticlockise
//6. Map the vecor value to its total with the times it has been rotated
//7. DO 8 - (the value of step 6)
//8. In a seperate subroutine rotate the secondary motor for the full revolution (step 7) times
//9. Move a smal gap
//10. In a seperate subroutine rotate the secondary motor for the full revolution (step 7) times
//11. Move a big gap
//12. Move on in the loop

//1 -> rotated once so to get back to it's original position 8-1