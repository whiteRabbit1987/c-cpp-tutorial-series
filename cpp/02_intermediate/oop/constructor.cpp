// constructor  =   special method that is automatically called when an object is instantiated
//                  useful for assigning values to attributes as arguments

#include <iostream>

class Student{
    public:
        std::string name;
        int age;
        double gpa;

    Student(std::string name = " ", int age = 0, double gpa = 0.0){
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }
};

int main(){

    Student student1("Spongebob", 25, 3.2);

    std::cout << student1.name << '\n';
    std::cout << student1.age << '\n';
    std::cout << student1.gpa << '\n';

    Student blanks;
    std::cout << blanks.name << '\n';
    std::cout << blanks.age << '\n';
    std::cout << blanks.gpa << '\n';
    
    return 0;
}