#include <iostream>


int main(){

    // do while loop =  do some block of code first,
    //                  THEN repeat again if condition is true

    int age;
    std::string response;

    std::cout << "How old are you? ";
    std::cin >> age;

    if(age >= 18){
        do{
            std::cout << "Are you telling the truth?  ";
            std::cin >> response;
        } while (response == "y");
    }

    std::cout << "Thank for telling the truth kiddo!";
   
    return 0;
}