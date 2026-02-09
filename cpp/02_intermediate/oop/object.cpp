// object   =   A collection of attributes and methods
//              They can have characteristics and could perform actions
//              Can be used to mimic real world items (ex. Phone, Book, Dog)
//              Created from a class which acts as a "blue-print"

#include <iostream>

class Human{
    public:
        std::string name;
        std::string occupation;
        int age;

        void speak(){
            std::cout << "My name is: " << name << "\n";
            std::cout << "I am " << age << " years old" << "\n";
            std::cout << "And I work as a " << occupation << "\n";
        }
};

int main(){

    Human person1;
    person1.name = "Spongebob";
    person1.occupation = "Cook";
    person1.age = 27;
    person1.speak();

    return 0;
}