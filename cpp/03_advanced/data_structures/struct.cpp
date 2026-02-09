// struct   =   A structure that group related variables under one name
//              structs can contain many different data types (string, int, double, bool, etc.)
//              variables in a struct are known as "members"
//              members can be accessed with . "Class Member Access Operator"

#include <iostream>

struct student{
    std::string name;
    double gpa;
    bool enrolled = false;
};

int main(){

    student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.2;
    student1.enrolled = true;

    student student2;
    student2.name = "Patrick";
    student2.gpa = 2.1;
    student2.enrolled = true;

    student student3;
    student3.name = "Squidward";
    student3.gpa = 1.5;

    std::cout << "Student information: ";
    std::cout << student1.name << ((student1.enrolled) ? " is enrolled" : " is NOT enrolled") << " and has a gpa of: " << student1.gpa << '\n';
    std::cout << "Student information: ";
    std::cout << student2.name << ((student2.enrolled) ? " is enrolled" : " is NOT enrolled") << " and has a gpa of: " << student2.gpa << '\n';
    std::cout << "Student information: ";
    std::cout << student3.name << ((student3.enrolled) ? " is enrolled" : " is NOT enrolled") << " and has a gpa of: " << student3.gpa << '\n';

    return 0;
}