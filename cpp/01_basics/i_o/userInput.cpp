#include <iostream>
#include <string>

// cout << (insertion operator)
// cin  >> (extraction operator)

int main(){

    std::string name = "";
    int age = 0;

    std::cout << "How old are you: ";
    std::cin >> age;

    std::cout << "Hello, what is your name: ";
    //std::cin >> name; only takes a string until it encounters a space
    std::getline(std::cin >> std::ws, name); // requires <string> library
    
    std::cout << "Hello, " << name << '\n';
    std::cout << "You are " << age << " years old.";

    return 0;
}