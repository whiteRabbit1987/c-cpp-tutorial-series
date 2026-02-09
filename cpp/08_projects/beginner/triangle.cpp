#include <iostream>
#include <cmath>

int main(){

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    std::cout << "### Triangle hypotenuse calculator ###" << '\n';

    std::cout << "Enter side a: ";
    std::cin >> a;

    std::cout << "Enter side b: ";
    std::cin >> b;

    c = sqrt(a*a + b*b);

    std::cout << "The hypotenuse is: " << c;

    return 0;
}