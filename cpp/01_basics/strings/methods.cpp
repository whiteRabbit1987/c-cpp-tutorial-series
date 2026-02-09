#include <iostream>
#include <string>

int main(){

    std::string name;
    std::string cat = "Must be human to work here!\n";
    std::cout << "Enter you name: ";
    std::getline(std::cin, name);

    if(name == "Hicks"){
        std::cout << cat;
        name.clear();
    }

    while(name.empty()){
        std::cout << "Can't leave name field blank!\n";
        std::cout << "Enter you name: ";
        std::getline(std::cin, name);
        
        if(name == "Hicks"){
            std::cout << cat;
            name.clear();
        }
    }

    if(name.length() > 25){
        std::cout << "Your name can't be over 12 characters\n";
    } else {
        std::cout << "Welcome, " << name << '\n';
        name.append("@gmail.com");
        name.erase(name.find(' ') -3, 3);
        name.erase(name.find(' ') +3, 3);
        name.insert(name.find(' '), "_");
        std::cout << "Your email is now : " << name << '\n';
    }

    return 0;
}