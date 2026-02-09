#include <iostream>
#include <string>

int main(){

    // while loop =  repeat code block if condition is (still) true
    //               condition must be true to enter the loop

    std::string name;

    while(name.empty()){
        std::cout << "Enter your name: ";
        std::getline(std::cin, name);
    }

    std::cout << "Hello, " << name;

    return 0;
}