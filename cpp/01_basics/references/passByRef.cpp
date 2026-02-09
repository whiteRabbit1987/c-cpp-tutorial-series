#include <iostream>

// references & addresses   =   Demonstrates how passing variables by reference
//                              allows functions to modify the original data,
//                              while passing by value creates independent copies.
//
//                              Using '&' in a function parameter means the
//                              function receives the actual variable, not a copy.
//                              This is useful for operations like swapping values.
//
//                              Also shows how variable addresses differ when
//                              passed by value vs. by reference, and how local
//                              copies inside functions occupy different memory.


void swap(std::string &x, std::string &y);
void showAddr(std::string x, std::string y);

int main(){

    std::string x = "Kool-Aid";
    std::string y = "Water";

    //swap(x, y);

    // std::cout << "X: " << x << '\n';
    // std::cout << "Y: " << y << '\n';

    std::cout << "X: " << &x << '\n';
    std::cout << "Y: " << &y << '\n';

    return 0;
}
// void swap(std::string &x, std::string &y){
//         std::string temp;
//         temp = x;
//         x = y;
//         y = temp;
// }
void showAddr(std::string x, std::string y){
        std::cout << "X: " << &x << '\n';
        std::cout << "Y: " << &y << '\n';
}