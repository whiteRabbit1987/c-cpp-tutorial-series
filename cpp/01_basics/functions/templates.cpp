// function template    =   describes what a function looks like.
//                          Can be used to generte as many overloaded functions
//                          as needed, each using different data types

#include <iostream>
template <typename T, typename U>

auto max(T x, U y){
    return (x > y) ? x : y;
}

int main(){

    std::cout << max(1, 2) << '\n';
    std::cout << max(1, 2.6) << '\n';
    std::cout << max(1.5, 2.7) << '\n';
    std::cout << max('G', 'Q') << '\n';

    return 0;
}