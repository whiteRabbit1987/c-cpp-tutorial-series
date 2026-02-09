#include <iostream>

void bakePizza();
void bakePizza(std::string topping1);
void bakePizza(int amount);

int main(){

    // functions can share the same name as long as:
    // they each have a unique set of parameters

    bakePizza();
    bakePizza("Salamie");
    bakePizza(5);

    return 0;
}

void bakePizza(){
    std::cout << "Here is your pizza!\n";
}

void bakePizza(std::string topping1){
    std::cout << "Here is your " <<  topping1 << " pizza!\n";
}

void bakePizza(int amount){
    std::cout << "Here are your " << amount << " pizza's!\n";
}