#include <iostream>

#define DEBUG

int main(){

    //#ifdef  =  runs code only if something was defined before

    #ifdef DEBUG
        std::cout << "Debug mode is ON" << std::endl;
    #endif

    return 0;
}