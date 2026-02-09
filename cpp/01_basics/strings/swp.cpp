#include <iostream>
#include <string>

int main(void){

    std::string fName = "";
    std::cout << "Enter your first name: ";
    std::getline(std::cin, fName);
    
    std::string lName = "";
    std::cout << "Enter your last name: ";
    std::cin >> lName;

    fName.swap(lName);

    std::cout << "Your first name: " << fName << "\nYour last name: " << lName;

    return 0;
}