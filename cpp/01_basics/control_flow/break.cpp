#include <iostream>


int main(){

    // break    =   break out of a loop
    // continue =   skip current iteration

    for(int i = 0; i < 50; i+=5){
        if(i == 15) continue; // skips
        else if (i == 45) break; // ends loop
        std::cout << i << " - ";
    }

    return 0;
}