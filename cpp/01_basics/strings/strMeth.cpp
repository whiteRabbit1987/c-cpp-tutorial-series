#include <iostream>
#include <string>

// string methods =   functions built into std::string for modifying or checking text
// common methos  =   .length()  .size()  .empty()  .clear()  .append() .at()
//                    .erase()   .insert()  .replace()  .substr()  .find() .compare()


int main(){
    std::string name;
    std::cout << "Welcome to Jurassic Park!\n";
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);

    if(name.empty()){
        std::cout << "You did not enter a name....exiting....";
        return 1;
    } else if(!(name.compare(0, name.size(), "Fuck"))){
        std::cout << "Ha, ha, very funny!";
        return 1;
    }

    std::string firstName = name.substr(0, name.find(' '));
    std::cout << "Your first name is " << firstName << std::endl;

    std::string lastName = name.substr(name.find(' ') +1, (name.length()));
    std::cout << "Your last name is " << lastName << std::endl;
    
    std::string official = firstName + '_' + lastName + "@jp93"; 
    official.append(".com");
    std::cout << "Your work public work email is: " << official << std::endl;
    std::string email = official;
    email.insert(email.find(".com"), ".park");
    std::cout << "Your work internal work email is: " << email << std::endl;

    std::string local = email;
    local.replace(local.find('_'), 1, "-");
    local.erase(local.find(".park"));
    std::cout << "Your domain name is: " << local << std::endl;

    std::string initials = std::string(1, firstName.at(0)) + std::string(1, lastName.at(0));
    std::cout << "Your initals are: " << initials << std::endl;

    return 0;
}