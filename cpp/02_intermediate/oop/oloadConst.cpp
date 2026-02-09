// overloaded constructors  =   multiple constructors w/ same name but different parameters
//                              allows for varying arguments when instantiating an object

#include <iostream>

class Pizza{
    public:
        std::string topping1;
        std::string topping2;
        
    Pizza(std::string topping1){
        this->topping1 = topping1;
    }
    Pizza(std::string topping1, std::string topping2){
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
};

int main(){

    Pizza pizza1("Pepperoni");
    std::cout << "I like " << pizza1.topping1 << " pizza!\n";

    Pizza pizza2("Pepperoni", "Olives");
    std::cout << "I like " << pizza2.topping1 << " pizza with " << pizza2.topping2 << "!\n";

    return 0;
}