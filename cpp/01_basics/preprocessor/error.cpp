#include <iostream>

#define AGE_LIMIT 17

#if AGE_LIMIT < 18
    #error AGE_LIMIT must be 18 or higher
#endif

int main(){

    //#error  =  stops compilation and shows a custom error message

    std::cout << "Program compiled successfully" << std::endl;

    return 0;
}