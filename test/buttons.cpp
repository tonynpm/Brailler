#include <Arduino.h>

short int total1 = 0;
short int total2 = 0;
bool r1 = 0;
bool r2 = 0;
bool r3 = 0;
bool r4 = 0;
bool r5 = 0;
bool r6 = 0;

void getState(short int p1, short int p2, short int p3, short int  &total,bool  &r1,bool  &r2,bool  &r3){ //converts the states of 3 buttons into a single number from 0,1,10,11,100,101,110,111
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
  pinMode(33,INPUT);
  pinMode(26,INPUT);
  pinMode(32,INPUT);
  pinMode(25,INPUT);
  pinMode(27,INPUT);
  pinMode(35,INPUT);
  pinMode(34,INPUT);
  Serial.begin(9600);
  digitalWrite(33,LOW);
  digitalWrite(26,LOW);
  digitalWrite(32,LOW);
  digitalWrite(25,LOW);
  digitalWrite(27,LOW);
  digitalWrite(35,LOW);
  digitalWrite(34,LOW);

}

void loop()
{
  getState(27,26,25,total1,r1,r2,r3);
  getState(33,32,35,total2,r4,r5,r6);

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

