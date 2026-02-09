#include <iostream>

int main(){
    
    // int (single precision number)
    int x; //declaration
    x = 5; //assignment
    int y = 6;
    int sum = x + y;
    std::cout << "Integer: " << sum << std::endl;

    // double (number including decimal)
    double price = 10.99;
    std::cout << "Double precision: " << price << '\n';
    
    // float (number including decimal with less precision)
    float num = 1.32;
    std::cout << "Floating point: " << num << '\n';

    // single character
    char grade = 'A';
    std::cout << "Single character: " << grade << '\n';

    // boolean (true or false)
    bool isStudent = true;
    std::cout << "Boolean value: " << isStudent << std::endl;

    // string (objects that represents a sequence of text)
    std::string name = "Bro";
    std::cout << "String: " << name << std::endl;


    return 0;
}