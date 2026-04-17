// lambda_captures.cpp
// purpose               = demonstrate lambda capture modes and their behavior
// topics                = capture by copy, capture by reference, capture all,
//                         mixed captures, mutation rules
// best practice         = choose captures intentionally; prefer explicit over implicit

#include <iostream>

int main() {

    int a = 10;
    int b = 20;

    // ------------------------------------------------------------
    // capture by copy: [a]
    // ------------------------------------------------------------
    auto copy_a = [a]() {
        return a;   // stored inside closure object
    };

    a = 99; // does NOT affect the lambda (captured by value)

    std::cout << "copy_a(): " << copy_a() << "\n"; // prints 10


    // ------------------------------------------------------------
    // capture by reference: [&a]
    // ------------------------------------------------------------
    auto ref_a = [&a]() {
        return a;   // refers to external variable
    };

    a = 123; // DOES affect the lambda (captured by reference)

    std::cout << "ref_a(): " << ref_a() << "\n"; // prints 123


    // ------------------------------------------------------------
    // capture all by copy: [=]
    // ------------------------------------------------------------
    auto all_copy = [=]() {
        return a + b;   // both captured by value
    };

    a = 1;
    b = 1; // no effect on all_copy()

    std::cout << "all_copy(): " << all_copy() << "\n"; // prints old a+b (123 + 20)


    // ------------------------------------------------------------
    // capture all by reference: [&]
    // ------------------------------------------------------------
    auto all_ref = [&]() {
        return a + b;   // both refer to external variables
    };

    a = 5;
    b = 7;

    std::cout << "all_ref(): " << all_ref() << "\n"; // prints 12


    // ------------------------------------------------------------
    // mixed captures: [=, &a]  (copy everything, but reference a)
    // ------------------------------------------------------------
    int x = 10, y = 20;

    auto mix1 = [=, &x]() {
        return x + y;   // x by ref, y by copy
    };

    x = 100;
    y = 200; // does NOT affect y inside lambda

    std::cout << "mix1(): " << mix1() << "\n"; // prints 100 + 20 = 120


    // ------------------------------------------------------------
    // mixed captures: [&, y]  (reference everything, but copy y)
    // ------------------------------------------------------------
    int p = 3, q = 4;

    auto mix2 = [&, y]() {
        return p + q + y;   // p,q by ref, y by copy
    };

    p = 30;
    q = 40;
    y = 999; // does NOT affect y inside lambda

    std::cout << "mix2(): " << mix2() << "\n"; // prints 30 + 40 + 20 = 90


    // ------------------------------------------------------------
    // mutation inside lambda requires 'mutable' when capturing by copy
    // ------------------------------------------------------------
    int z = 5;

    auto mutate_copy = [z]() mutable {
        z += 10;       // allowed because of 'mutable'
        return z;
    };

    std::cout << "mutate_copy(): " << mutate_copy() << "\n"; // prints 15
    std::cout << "z outside: " << z << "\n";                  // still 5

    return 0;
}
