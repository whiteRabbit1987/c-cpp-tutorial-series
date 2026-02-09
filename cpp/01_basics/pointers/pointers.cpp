#include <iostream>

int main(){

    // pointers =   variable that stores a memory address of another variable
    //              sometimes it's easier to work with an address

    // & address-of operator
    // * dereference operator

    std::string name = "Bro";               
    std::string *pName = &name;             
    std::cout << "Pointer to name: " << pName << '\n';
    std::cout << "Value of name: " << *pName << '\n';   

    int age = 21;
    int *pAge = &age;
    std::cout << "Pointer to age: " << pAge << '\n';
    std::cout << "Value of age: " << *pAge << '\n';   

    std::string freePizzas[5] = {"pizza1", "pizza2", "pizza3", "pizza4", "pizza5"};
    std::string *pFreePizzas = freePizzas;
    std::cout << "Pointer to free pizzas: " << pFreePizzas << '\n';
    std::cout << "Value of free pizzas: " << *pFreePizzas << '\n';

    return 0;
}