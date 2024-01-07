
#include <Arduino.h>
#include <Stepper.h>

short p1 = 12;
short p2 = 14;
short p3 = 26;
short p4 = 27;
short total1 = 0;
bool r1 = 0;
bool r2 = 0;
bool r3 = 0;
int rots;
short i;


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

//MAPS code from getState to the number of times the secondary motor made a full revolution

int mapFunction(int total){
    int x = 0;
    if(total = 1){
        x = 1;
    }
    else if(total = 10){
        x = 2;
    }
    else if(total = 11){
        x = 3;
    }
    else if(total = 100){
        x = 4;
    }
    else if(total = 101){
        x = 5;
    }
    else if(total = 110){
        x = 6;
    }
    else if(total = 111){
        x = 7;
    }
    return x;
}


Stepper SecondaryStepper(2048, p1,p3,p2,p4); //PINS MUST BE IN ORDER OF 1,3,2,4
void setup() {
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  SecondaryStepper.setSpeed(20);
  pinMode(33,INPUT);
  pinMode(32,INPUT);
  pinMode(35,INPUT);
  pinMode(34,INPUT);
  digitalWrite(33,LOW);
  digitalWrite(32,LOW);
  digitalWrite(35,LOW);
  digitalWrite(34,LOW);
  Serial.begin(9600);
}

void loop(){
  getState(33,32,35,total1,r1,r2,r3);
  Serial.println(digitalRead(34));
  if(digitalRead(34)){
    
    delay(3000);
    if(digitalRead(34)){
       r1 = 0;
	     r2 = 0;
       r3 = 0;
      total1 = 0;
      delay(2000);
    }
    else{
      Serial.println(total1);
      rots = mapFunction(total1);
      Serial.println(rots);
      for(i = 0; i>rots; i++){
        SecondaryStepper.step(2048);
        delay(50);
      }
       r1 = 0;
	     r2 = 0;
       r3 = 0;
       total1 = 0;
    }
  }
  delay(500);
}
  
