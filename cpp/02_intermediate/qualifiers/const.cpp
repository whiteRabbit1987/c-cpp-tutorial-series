    // The const keyword specifies that a variable's value is constant
    // tells the compiler to prevent anything from modifying it
    // (read-only)

    // const double PI = 3.14150;
    // double radius = 10;
    // double circumference = 2 * PI * radius;

    // std::cout << circumference << "cm" << '\n';

#include <iostream>

void printInfo(const std::string &name, const int &age);

int main(){

    // const parameter  =   parameter that is effectively read-only
    //                      code is more secure & conveys intent
    //                      useful for references and pointers

    std::string name = "Bro";
    int age = 21;

    printInfo(name, age);

    return 0;
}
void printInfo(const std::string &name, const int &age){
    // can't re-assign or alter const variables
    //name = "Sis";
    //age = 99;
    std::cout << name << "\n";
    std::cout << age << "\n";
}