#include <iostream>

#define SQUARE(x) ((x) * (x))

int main(){

    //#define macro_function  =  creates reusable code with parameters
    //                           text is replaced before compilation

    std::cout << "Square of 5: " << SQUARE(5) << std::endl;

    return 0;
}