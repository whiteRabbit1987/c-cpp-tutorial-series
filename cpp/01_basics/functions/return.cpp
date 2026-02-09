#include <iostream>
#include <string>

std::string fullName(std::string name, std::string option);

int main(){

    // return   =   return a value back to the spot
    //              where you called the encompassing function

    std::string name;
    std::cout << "Please enter your full name: ";
    std::getline(std::cin, name);

    std::string fName = fullName(name, "first");
    std::cout << "Your first name is: " << fName << '\n';

    std::string lName = fullName(name, "last");
    std::cout << "Your last name is: " << lName;

    return 0;
}

std::string fullName(std::string name, std::string option){
    int pos = name.find(" ");
    if(option == "first"){
        return name.substr(0, pos);
    } else if (option == "last"){
        return name.substr(pos +1, std::string::npos);
    }
    
}
