#include <iostream>
#include <string>

int main(){

    char op = '\n';
    double num1;
    double num2;
    double result;

    std::cout << "$$$*** Funculator ***$$$" << '\n' << '\n';

    std::cout << "Enter the #1: ";
    std::cin >> num1;
    

    std::cout << "Enter the operator ( + - * / ): ";
    std::cin >> op;

    std::cout << "Enter the #2: ";
    std::cin >> num2;

    switch(op){
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            std::cout << "Invalid input detected!" << '\n';
            return 1;
    }

    std::cout  << "result: " << result;

    return 0;
}