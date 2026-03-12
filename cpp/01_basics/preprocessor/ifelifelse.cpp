#include <iostream>

#define LEVEL 2

int main(){

    //#if  =  checks if a compile-time condition is true
    //#elif =  checks another condition if the first was false
    //#else =  runs if none of the above were true

    #if LEVEL == 1
        std::cout << "Level 1 selected" << std::endl;
    #elif LEVEL == 2
        std::cout << "Level 2 selected" << std::endl;
    #else
        std::cout << "Unknown level" << std::endl;
    #endif

    return 0;
}