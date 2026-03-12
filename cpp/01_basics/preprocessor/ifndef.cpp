#include <iostream>

int main(){

    //#ifndef  =  runs code only if something was NOT defined before

    #ifndef TEST_MODE
        std::cout << "TEST_MODE is not defined" << std::endl;
    #endif

    return 0;
}