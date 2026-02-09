#include <iostream>

void sing(std::string);
void space();

int main(){
    // function =   a block of reusable code

    std::string name;
    std::cout << "What is your name: ";
    std::cin >> name;

    sing(name);
    space();
    sing(name);
    space();
    sing(name);
    space();

    return 0;
}

void sing(std::string name){
    std::cout << "\n#########################";
    std::cout << "\nHappy birthday to you\n";
    std::cout << "Happy birthday to you\n";
    std::cout << "Happy birthday dear " << name << '\n';
    std::cout << "Happy birthday to you\n";
    std::cout << "#########################\n";
}

void space(){
    std::cout << "\n\n\n";
}