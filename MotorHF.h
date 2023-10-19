#include <Arduino.h>
#include <Stepper.h>
#include <vector>

class Rotation{
  private:
    bool isValid = false;
    int counter = 1;
  public:
    Rotation(Stepper stepm, std::vector<int> array, int stepsPerRotation){
      std::vector<int> cmpr = {0,0,0};
      while(!isValid){
        if(array == cmpr){
          stepm.step(counter*stepsPerRotation); //should be counter*25
          isValid = true;
        }
        else{
          counter += 1;
          cmpr = changer(cmpr, counter);
      };
    };
    std::vector<int> changer(std::vector<int> cmpr, int counter){
        std::vector<int> temp;
        if(counter == 2){
          temp = {1,0,0};
        }
      else if(counter == 3){
          temp = {0,1,0};
        }
      else if(counter == 4){
          temp = {0,0,1};
        }
      else if(counter == 5){
          temp = {1,0,1};
        }
      else if(counter == 6){
          temp = {1,1,0};
        }
      else if(counter == 7){
          temp = {1,1,0};
        }
      else if(counter == 8){
          temp = {1,1,1};
        }
      return temp;
    };

};
