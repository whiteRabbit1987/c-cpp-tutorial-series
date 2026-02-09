#include <iostream>

std::string scopeVar = "Global variable value: ";
void printNum();

int main(){

    // Local variables  =   declared inside a function or block {}.
    // Global variables =   declared outside of all functions

    std::string scopeVar = "Local variable value: ";
    printNum();                                        // functions outside main uses global
    std::cout << ::scopeVar << "inside main" << '\n';  // function inside main will use local unless preceded with :: scope resolution operator

    return 0;
}

void printNum(){
    std::cout << scopeVar << "user defined funciton" << '\n';
}