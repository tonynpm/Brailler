#include <Arduino.h>





short int total1 = 0;
short int total2 = 0;
bool r1 = 0;
bool r2 = 0;
bool r3 = 0;
bool r4 = 0;
bool r5 = 0;
bool r6 = 0;

void getState(short int p1, short int p2, short int p3, short int  &total,bool  &r1,bool  &r2,bool  &r3){
  short int i = digitalRead(p1);
  short int j = digitalRead(p2);
  short int k = digitalRead(p3); 

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

void setup()
{
  pinMode(12,INPUT);
  pinMode(26,INPUT);
  pinMode(14,INPUT);
  pinMode(25,INPUT);
  pinMode(27,INPUT);
  pinMode(35,INPUT);
  pinMode(34,INPUT);
  Serial.begin(9600);
  digitalWrite(12,LOW);
  digitalWrite(26,LOW);
  digitalWrite(14,LOW);
  digitalWrite(25,LOW);
  digitalWrite(27,LOW);
  digitalWrite(35,LOW);
  digitalWrite(34,LOW);

}

void loop()
{
  getState(26,25,35,total1,r1,r2,r3);
  getState(12,14,27,total2,r4,r5,r6);

  if(digitalRead(34)){
    delay(3000);
    if(digitalRead(34)){
      Serial.println("Cancelled");
      r1 = 0;
	   r2 = 0;
       r3 = 0;
       r4 = 0;
       r5 = 0;
       r6 = 0;
      total1 = 0;
      total2 = 0;
      delay(2000);
    }
    else{
      Serial.println(total1);
      Serial.println(total2);
       r1 = 0;
	   r2 = 0;
       r3 = 0;
       r4 = 0;
       r5 = 0;
       r6 = 0;
      total1 = 0;
      total2 = 0;
    }
  }
  delay(50);
}



/*
//14,27,26,25,33,35
#include <Arduino.h>
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


const short int sbp = 12; //Pin number for send button
const short int bp1 = 14 ;//Pin number for 1st button
const short int bp2 = 27 ;//Pin number for 2nd button
const short int bp3 = 26 ;//Pin number for 3rd button
const short int bp4 = 25 ;//Pin number for 4rd button
const short int bp5 = 35 ;//Pin number for 5th button
const short int bp6 = 34;//Pin number for 6th button
short int total1 = 0; //the total for the first three pins
short int total2 = 0; //the total for the last three pins
short int sbp_state = 0; // the current state of the send button
bool r1=0; //keeps track of whether the 1st button has been pressed at last one before the send button has been pressed
bool r2=0; //keeps track of whether the 2nd button has been pressed at last one before the send button has been pressed
bool r3=0; //keeps track of whether the 3rd button has been pressed at last one before the send button has been pressed
bool r4=0;  //keeps track of whether the 4th button has been pressed at last one before the send button has been pressed
bool r5=0;  //keeps track of whether the 5th button has been pressed at last one before the send button has been pressed
bool r6=0;  //keeps track of whether the 6th button has been pressed at last one before the send button has been pressed

void setup() {
  pinMode(sbp, INPUT_PULLUP);
  pinMode(bp1, INPUT_PULLUP);
  pinMode(bp2, INPUT_PULLUP);
  pinMode(bp3, INPUT_PULLUP);
  pinMode(bp4, INPUT_PULLUP);
  pinMode(bp5, INPUT_PULLUP);
  pinMode(bp6, INPUT_PULLUP);
  pinMode(32, OUTPUT);
  digitalWrite(32, LOW);
  Serial.begin(9600);
}

void loop(){
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
            Serial.println(total1);
            Serial.println(total2);
            if(total1>99){
                digitalWrite(32, HIGH);
            }
            else{
                digitalWrite(32, LOW);
            }
        }
    }
  delay(50);
}
*/
