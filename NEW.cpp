//NEW
#define REMOTEXY_MODE__ESP32CORE_BLE
#include <BLEDevice.h>
#define REMOTEXY_BLUETOOTH_NAME "RemoteXY"
#include <RemoteXY.h>
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

/*
000 = 0
001 = 1
010 = 2
011 = 3
100 = 4
101 = 5
110 = 6
111 = 7
*/

void setup() 
{
  Serial.begin(9600);
  RemoteXY_Init (); 
  pinMode (PIN_BUTTON_01, OUTPUT);
  
  // TODO you setup code
  
}
short arr[20][2];
short times = 0;
void convert(char character){
  Serial.println(character);
  switch(character){
  case 'A':
    arr[times][0] = 1; 
    arr[times][1] = 0; 
    break; 
  case 'B': 
    arr[times][0] = 3; 
    arr[times][1] = 0; 
    break;     
  case 'C': 
    arr[times][0] = 1; 
    arr[times][1] = 1; 
    break;
  case 'D': 
    arr[times][0] = 1; 
    arr[times][1] = 3;  
    break;
  case 'E': 
    arr[times][0] = 1; 
    arr[times][1] = 2; 
    break;
  case 'F': 
    arr[times][0] = 3; 
    arr[times][1] = 1; 
    break;
  case 'G': 
    arr[times][0] = 3; 
    arr[times][1] = 3; 
    break;
  case 'H': 
    arr[times][0] = 3; 
    arr[times][1] = 2; 
    break;
  case 'I': 
    arr[times][0] = 2; 
    arr[times][1] = 1; 
    break;
  case 'J': 
    arr[times][0] = 2; 
    arr[times][1] = 3; 
    break;
  case 'K': 
    arr[times][0] = 5; 
    arr[times][1] = 0; 
    break;
  case 'L': 
    arr[times][0] = 7; 
    arr[times][1] = 0; 
    break;
  case 'M': 
    arr[times][0] = 5; 
    arr[times][1] = 1; 
    break;
  case 'N': 
    arr[times][0] = 5; 
    arr[times][1] = 3; 
    break;
  case 'O': 
    arr[times][0] = 5; 
    arr[times][1] = 2; 
    break;
  case 'P': 
    arr[times][0] = 7; 
    arr[times][1] = 1; 
    break;
  case 'Q': 
    arr[times][0] = 7; 
    arr[times][1] = 3; 
    break;
  case 'R': 
    arr[times][0] = 7; 
    arr[times][1] = 2; 
    break;
  case 'S': 
    arr[times][0] = 6; 
    arr[times][1] = 1; 
    break;
  case 'T': 
    arr[times][0] = 6; 
    arr[times][1] = 3; 
    break;
  case 'U': 
    arr[times][0] = 5; 
    arr[times][1] = 4; 
    break;
  case 'V': 
    arr[times][0] = 7; 
    arr[times][1] = 4; 
    break;
  case 'W': 
    arr[times][0] = 2; 
    arr[times][1] = 7; 
    break;
  case 'X': 
    arr[times][0] = 5; 
    arr[times][1] = 5; 
    break;
  case 'Y': 
    arr[times][0] = 5; 
    arr[times][1] = 7; 
    break;
  case 'Z': 
    arr[times][0] = 5; 
    arr[times][1] = 6; 
    break;
  case ' ':
    arr[times][0] = 0;
    arr[times][0] = 0;
  case '1': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 1;
    arr[times][1] = 0;
    break;
  case '2': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 3;
    arr[times][1] = 0;
    break;
   case '3': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 1;
    arr[times][1] = 1;
    break;
   case '4': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 1;
    arr[times][1] = 3;
    break;
   case '5': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 1;
    arr[times][1] = 2;
    break;
   case '6': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 3;
    arr[times][1] = 1;
    break;
   case '7': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 3;
    arr[times][1] = 3;
    break;
   case '8': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 3;
    arr[times][1] = 2;
    break;
   case '9': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 2;
    arr[times][1] = 1;
    break;
   case '0': 
    arr[times][0] = 4; 
    arr[times][1] = 7;
    times++;
    arr[times][0] = 2;
    arr[times][1] = 3;
    break;
  
  }
 
}
//numbers times++ again in each case

void loop() 
{ 
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
      if(((char) toupper(RemoteXY.text[i])) == "A" && ((char) toupper(RemoteXY.text[i+1])) == "N" && ((char) toupper(RemoteXY.text[i+2])) == "D"){
        arr[times][0] = 1; 
        arr[times][1] = 5;
        
      }
      else if (((char) toupper(RemoteXY.text[i])) == "F" && ((char) toupper(RemoteXY.text[i+1])) == "O" && ((char) toupper(RemoteXY.text[i+2])) == "R"){
        arr[times][0] = 1; 
        arr[times][1] = 1;
      }
      else if (((char) toupper(RemoteXY.text[i])) == "T" && ((char) toupper(RemoteXY.text[i+1])) == "H" && ((char) toupper(RemoteXY.text[i+2])) == "E"){
        arr[times][0] = 6; 
        arr[times][1] = 5;
      }
      else if (((char) toupper(RemoteXY.text[i])) == "O" && ((char) toupper(RemoteXY.text[i+1])) == "F"){
        arr[times][0] = 1; 
        arr[times][1] = 6;
      }
      else{
      convert((char) toupper(RemoteXY.text[i]));
      }
      Serial.println(arr[times][0], arr[times][1]);
       times++;
      }
    }
    } 
    

  
  
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


}
