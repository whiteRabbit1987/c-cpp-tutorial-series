#include <iostream>
#include <string>

int main(){

    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;

    for(int i = name.length(); i > 0; --i){
        std::cout << name.substr(0, i) << '\n';
    }

    return 0;
}