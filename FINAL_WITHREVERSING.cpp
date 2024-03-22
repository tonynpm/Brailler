#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"
#include <RemoteXY.h>
#include <Vector.h>
#include <Stepper.h>
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =   // 99 bytes
  { 255,32,0,0,0,92,0,17,0,0,0,31,1,106,200,1,1,5,0,130,
  2,3,101,193,0,30,129,14,34,72,12,8,66,114,97,105,108,108,101,32,
  80,114,105,110,116,101,114,0,129,6,73,54,6,8,83,101,110,100,32,84,
  101,120,116,32,84,111,32,66,114,97,105,108,108,101,58,0,7,4,83,96,
  9,37,16,26,6,31,1,36,110,24,24,0,24,31,83,69,78,68,0 };
  
// this structure defines all the variables and events of your control interface 
struct {
    // input variables
  char text[31]; // string UTF8 end zero
  uint8_t button_01; // =1 if button pressed, else =0
    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0
} RemoteXY;
#pragma pack(pop)
#define PIN_BUTTON_01 3

//000 = 0, 001 = 1, 010 = 2, 011 = 3, 100 = 4, 101 = 5, 110 = 6, 111 = 7

//CHANGE TEXT TO: BRAILLING when motors stat to turn, "Continue Brailling" when length is less than 22, "Braille now" when length is 22

//SEND TEXT BACK TELLING USERS TO WAIT WHEN counter > 26
//ROTATE SECONDARY MOTORS (8-x) from excl if x is 0
//ROTATE PRIMARY MOTORS
//SEND TEXT BACK TELLING USERS To BRaille again

const int stepsPerRevolution = 1024;
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);
Stepper mnStepper(stepsPerRevolution, 26, 33, 25, 32);

void turnSecondary(int rotations){
  for(int i = 0; i<rotations; i++){
    mnStepper.step(stepsPerRevolution);
    mnStepper.step(stepsPerRevolution);
    RemoteXY_delay(100);
  }
 RemoteXY_delay(500);
}

void turnPrimary(bool isLarge, short back = 1){
  short magnitude = 7;
  if(!isLarge){
    myStepper.step(93*magnitude*back);
    myStepper.step(93*magnitude*back); //1-11
  }
  else{
    myStepper.step(140*magnitude*back);
    myStepper.step(140*magnitude*back); //1-7
  }
  RemoteXY_delay(500);
}

void setup(){
  Serial.begin(9600);
  RemoteXY_Init (); 
  pinMode (PIN_BUTTON_01, OUTPUT);
  myStepper.setSpeed(20);
  mnStepper.setSpeed(20);
}
const int MAX = 22;
int storage_array[MAX];
Vector<int> arr(storage_array);
static short times = 0;

void convert(char character){
  Serial.println(character);
  int holderA = 0;
  int holderB = 0;
  switch(character){
    case 'A':
      holderA = (1); 
      holderB = (0); 
      break;

    case 'B': 
      holderA = (3); 
      holderB = (0); 
      break;

    case 'C': 
      holderA = (1); 
      holderB = (1); 
      break;

    case 'D': 
      holderA = (1); 
      holderB = (3);  
      break;

    case 'E': 
      holderA = (1); 
      holderB = (2); 
      break;

    case 'F': 
      holderA = (3); 
      holderB = (1); 
      break;

    case 'G': 
      holderA = (3);
      holderB = (3); 
      break;

    case 'H': 
      holderA = (3); 
      holderB = (2); 
      break;

    case 'I': 
      holderA = (2); 
      holderB = (1); 
      break;

    case 'J': 
      holderA = (2); 
      holderB = (3); 
      break;

    case 'K': 
      holderA = (5); 
      holderB = (0); 
      break;

    case 'L': 
      holderA = (7); 
      holderB = (0); 
      break;

    case 'M': 
      holderA = (5); 
      holderB = (1); 
      break;

    case 'N': 
      holderA = (5); 
      holderB = (3); 
      break;

    case 'O': 
      holderA = (5); 
      holderB = (2); 
      break;

    case 'P': 
      holderA = (7); 
      holderB = (1); 
      break;

    case 'Q': 
      holderA = (7); 
      holderB = (3); 
      break;

    case 'R': 
      holderA = (7); 
      holderB = (2); 
      break;

    case 'S': 
      holderA = (6); 
      holderB = (1); 
      break;

    case 'T': 
      holderA = (6); 
      holderB = (3); 
      break;

    case 'U': 
      holderA = (5); 
      holderB = (4); 
      break;

    case 'V': 
      holderA = (3); 
      holderB = (4); 
      break;

    case 'W': 
      holderA = (2);
      holderB = (7); 
      break;
      
    case 'X': 
      holderA = (5);
      holderB = (5);
      break;

    case 'Y': 
      holderA = (5);
      holderB = (7);
      break;

    case 'Z': 
      holderA = (5);
      holderB = (6);
      break;

    case ' ':
      holderA = (0);
      holderB = (0);
      break;

    case '1':
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7);
      arr.push_back(4);
      arr.push_back(7);
      holderA = (1);
      holderB = (0);
      times+=2;
      break;

    case '2':
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7);
      arr.push_back(4);
      arr.push_back(7);
      holderA = (3);
      holderB = (0);
      times+=2;
      break;
      
    case '3':
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7); 
      arr.push_back(4);
      arr.push_back(7);
      holderA = (1);
      holderB = (1);
      times+=2;
      break;
      
    case '4':
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7); 
      arr.push_back(4);
      arr.push_back(7);
      holderA = (1);
      holderB = (3);
      times+=2;
      break;
      
    case '5':
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7); 
      arr.push_back(4);
      arr.push_back(7);
      holderA = (1);
      holderB = (2);
      times+=2;
      break;
      
    case '6':
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7); 
      arr.push_back(4);
      arr.push_back(7);
      holderA = (3);
      holderB = (1);
      times+=2;
      break;
      
    case '7':
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7); 
      arr.push_back(4);
      arr.push_back(7);
      holderA = (3);
      holderB = (3);
      times+=2;
      break;
      
    case '8':
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7); 
      arr.push_back(4);
      arr.push_back(7);
      holderA = (3);
      holderB = (2);
      times+=2;
      break;
      
    case '9': 
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7);
      arr.push_back(4);
      arr.push_back(7);
      holderA = (2);
      holderB = (1);
      times+=2;
      break;
      
    case '0': 
      turnPrimary(1);
      turnSecondary(4);
      turnPrimary(0);
      turnSecondary(7);
      arr.push_back(4);
      arr.push_back(7);
      holderA = (2);
      holderB = (3);
      times+=2;
      break;
  }
  times+=2;
  turnPrimary(1);
  turnSecondary(holderA);
  turnPrimary(0);
  turnSecondary(holderB);
  arr.push_back(holderA);
  arr.push_back(holderB);
}

void reverseMotors(){
  /*char textToSend[15]; //ISSUE: not same length
  if(times == 22){
    textToSend = "Braille Now   ";
  }
  else{
    textToSend = "Exceeded limit";
  }*/
  RemoteXY_delay(200000);
  Serial.println("Commencing reversing process ...."); //20 seconds to embosss
  //textToSend = "Please wait !!!";
  for (int i = 0; i<22; i++){
    int pos = 22-i;
    turnPrimary(1,-1);
    if(arr.at(pos)!=0){
      turnSecondary(8-(arr.at(pos)) );
      arr.assign(pos, 0);      
    }
    turnPrimary(0, -1);
    if(arr.at(pos-1)!= 0){
      turnSecondary(8- (arr.at(pos-1)));
      arr.assign(pos-1, 0);
    }
    i++;    
  }
  times = 0;
  Serial.println("Finised reversing!!");
}

void loop(){ 
   RemoteXY_Handler(); // Handle RemoteXY communication // Read the value of the button 
   if (RemoteXY.button_01 == 1) {
     Serial.println("-- SENT --");
     if (RemoteXY.text[0] != '\0') {
       Serial.print("Text input: "); 
       Serial.println(RemoteXY.text); 
    }
    RemoteXY_delay(3000);
    if(RemoteXY.button_01 == 1){
      Serial.println("-- CANCELLED --");
      RemoteXY_delay(2000);
    }
    else{
      Serial.println("-- BRAILLING --");
      for(int i = 0; RemoteXY.text[i] !='\0';i++){
        int length  = 0;
        for (char c: RemoteXY.text){
          if(c =='\0') break;
          length++;
        }
        if(times+length>=22){
          reverseMotors();
          break;
        }
        if(((char) toupper(RemoteXY.text[i])) == 'A' && ((char) toupper(RemoteXY.text[i+1])) == 'N' && ((char) toupper(RemoteXY.text[i+2])) == 'D'){
          turnPrimary(1);
          turnSecondary(7);
          turnPrimary(0);
          turnSecondary(5);
          arr.push_back(7); 
          arr.push_back(5);
          i=i+2;
          
        }
        else if (((char) toupper(RemoteXY.text[i])) == 'F' && ((char) toupper(RemoteXY.text[i+1])) == 'O' && ((char) toupper(RemoteXY.text[i+2])) == 'R'){
          turnPrimary(1);
          turnSecondary(7);
          turnPrimary(0);
          turnSecondary(7);
          arr.push_back(7); 
          arr.push_back(7);
          i=i+2;
        }
        else if (((char) toupper(RemoteXY.text[i])) == 'T' && ((char) toupper(RemoteXY.text[i+1])) == 'H' && ((char) toupper(RemoteXY.text[i+2])) == 'E'){
          turnPrimary(1);
          turnSecondary(6);
          turnPrimary(0);
          turnSecondary(5);
          arr.push_back(6); 
          arr.push_back(5);
          i=i+2;
        }
        else if (((char) toupper(RemoteXY.text[i])) == 'O' && ((char) toupper(RemoteXY.text[i+1])) == 'F'){
          turnPrimary(1);
          turnSecondary(7);
          turnPrimary(0);
          turnSecondary(6);
          arr.push_back(7); 
          arr.push_back(6);
          i=i+1;
        }
        else{
          convert((char) toupper(RemoteXY.text[i]));
        }
      RemoteXY_delay(2000);
    for(int i = 0; i<22; i++){
      Serial.print(arr.at(i));
    }
    Serial.println();
      }
     }
    } // use the RemoteXY structure for data transfer and do not call delay(), use instead RemoteXY_delay() 
}
