#include <iostream>

int main(){
    using std::cout;

    // ternary operator ?:  =   replacement to an if/else statement
    //                          condition ? expression1 : expression2;

    int grade = 75;
    grade >= 60 ? cout << "Pass" : cout << "Fail"; //condition ? if true : if false;

    int num;
    std::cout << '\n' << "Enter a number: ";
    std::cin >> num;

    num >= 18 ? cout << "Adult" : cout << "Child";

    std::cout << '\n';

    cout << (num % 2 == 0 ? "Even" : "Odd");

    return 0;
}