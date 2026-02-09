#include <iostream>

int main(){

    // sizeof() =   determines the size in bytes of a:
    //              variable, data type, class, objects, etc.

    std::string name = "Dave"; // reference data type always 32 bytes
    double gpa = 3.7;
    int age = 38;
    char grade = 'B';
    bool isStudent = true;
    char grades[] = {'A', 'B', 'C', 'D', 'F'};
    std::string students[] = {"Spongebob", "Patrick", "Squidward"};

    std::cout << "Size of double: " << sizeof(gpa) << " bytes\n";
    std::cout << "Size of int: " << '\t' << sizeof(age) << " bytes\n";
    std::cout << "Size of string: " << sizeof(name) << " bytes\n";
    std::cout << "Size of char: " << '\t' << sizeof(grade) << " bytes\n";
    std::cout << "Size of bool: " << '\t' << sizeof(isStudent) << " bytes\n";
    std::cout << "Size of array: " << '\t' << sizeof(grades) << " elemnts\n";
    std::cout << "String[]: " << '\t' << sizeof(students)/sizeof(std::string) << " strings\n";

    return 0;
}