#include <iostream>

// references & addresses   =   Demonstrates how passing variables by value, reference, 
//                              and const reference affects the original data and memory usage.
//
//                              - Passing by value creates a local copy; changes inside the 
//                                function do not affect the original variable.
//                              - Passing by reference ('&') allows the function to modify 
//                                the original variable directly.
//                              - Passing by const reference ('const &') avoids copying 
//                                large objects for better performance, while preventing 
//                                modifications to the original.
//
//                              This also illustrates memory differences between local copies 
//                              and references.

void copyValue(int number) {
    // Local copy; modifying this does NOT affect the original variable
    number += 10;
    std::cout << "[copyValue] number inside function: " << number 
              << " (address: " << &number << ")" << std::endl;
}

void refValue(int& number) {
    // Reference; modifying this WILL affect the original variable
    number += 10;
    std::cout << "[refValue] number inside function: " << number 
              << " (address: " << &number << ")" << std::endl;
}

void constRefValue(const int& number) {
    // Const reference; cannot modify the variable, avoids copying
    std::cout << "[constRefValue] number inside function: " << number 
              << " (address: " << &number << ")" << std::endl;
}

int main() {
    int number = 5;
    std::cout << "Number at start: " << number 
              << " (address: " << &number << ")" << std::endl;

    copyValue(number);
    std::cout << "Number after copyValue: " << number << std::endl;

    refValue(number);
    std::cout << "Number after refValue: " << number << std::endl;

    constRefValue(number);
    std::cout << "Number after constRefValue (unchanged): " << number << std::endl;

    return 0;
}
