//MAPS code from getState to the number of times the secondary motor made a full revolution

int mapFunction(int total){
    int x = 0;
    if(total == 1){
        x = 1;
    }
    else if(total == 10){
        x = 2;
    }
    else if(total == 11){
        x = 3;
    }
    else if(total == 100){
        x = 4;
    }
    else if(total == 101){
        x = 5;
    }
    else if(total == 110){
        x = 6;
    }
    else if(total == 111){
        x = 7;
    }
    return x;
}
