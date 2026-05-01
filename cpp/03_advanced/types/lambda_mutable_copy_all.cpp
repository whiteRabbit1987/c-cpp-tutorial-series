#include <iostream>

int main() {

    int a = 10;
    int b = 20;

    auto lam = [=]() mutable {
        // a and b are captured BY COPY
        // mutable allows modifying the *copies* inside the closure object
        a += 5;
        b += 5;
        return a + b;
    };

    std::cout << lam() << "\n"; // prints 40
    std::cout << a << " " << b << "\n"; // prints 10 20 (unchanged)

    return 0;
}
