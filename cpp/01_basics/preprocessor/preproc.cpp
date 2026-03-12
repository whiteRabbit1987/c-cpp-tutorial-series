#include <iostream>

#define PI 3.14159
#define SQUARE(x) ((x) * (x))
#define DEBUG
#define LEVEL 2
#define VERSION 1

int main(){

    //#include  =  used to include a library or file
    //             so we can use its features

    //#define  =  creates a macro
    //            replaces text before compilation

    //#ifdef  =  runs code only if something was defined

    //#ifndef  =  runs code only if something was NOT defined

    //#if / #elif / #else  =  checks compile-time conditions

    //#undef  =  removes a macro definition

    std::cout << "PI: " << PI << std::endl;
    std::cout << "Square of 4: " << SQUARE(4) << std::endl;

    #ifdef DEBUG
        std::cout << "Debug mode is ON" << std::endl;
    #endif

    #ifndef TEST_MODE
        std::cout << "TEST_MODE is not defined" << std::endl;
    #endif

    #if LEVEL == 1
        std::cout << "Level 1 selected" << std::endl;
    #elif LEVEL == 2
        std::cout << "Level 2 selected" << std::endl;
    #else
        std::cout << "Unknown level" << std::endl;
    #endif

    #undef VERSION

    #ifndef VERSION
        std::cout << "VERSION is now undefined" << std::endl;
    #endif

    return 0;
}