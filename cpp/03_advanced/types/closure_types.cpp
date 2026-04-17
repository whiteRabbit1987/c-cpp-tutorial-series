// closure_types.cpp
// purpose               = explain closure type + closure object created by lambdas
// topics                = compiler-generated type, stored state, captures, invocation
// best practice         = understand that every lambda is a unique type with operator()

#include <iostream>

int main() {

    // ------------------------------------------------------------
    // lambda with capture
    // ------------------------------------------------------------
    int x = 10;

    auto lambda = [x](int y) {
        return x + y;
    };

    // ------------------------------------------------------------
    // closure object
    // ------------------------------------------------------------
    // 'lambda' is a *closure object*.
    // It is an instance of a compiler-generated class.
    //
    // Conceptually, the compiler generates something like:
    //
    //   struct __Lambda_1 {
    //       int x;                 // captured variable stored as member
    //       int operator()(int y) const {
    //           return x + y;
    //       }
    //   };
    //
    // And 'lambda' is an object of that type:
    //
    //   __Lambda_1 lambda = __Lambda_1{x};
    //
    // This is the closure object.

    std::cout << lambda(5) << "\n"; // prints 15


    // ------------------------------------------------------------
    // closure type
    // ------------------------------------------------------------
    // The type of the lambda is the *closure type*.
    // It is unique and unnamed.
    //
    // You cannot write it manually.
    // You cannot spell it out.
    //
    // But you can refer to it using 'auto' or 'decltype(lambda)'.

    using ClosureType = decltype(lambda);

    ClosureType another = lambda; // same closure type, new object

    std::cout << another(7) << "\n"; // prints 17


    // ------------------------------------------------------------
    // closure object stores captured state
    // ------------------------------------------------------------
    int a = 3;
    auto store = [a]() {
        return a;
    };

    a = 99; // does NOT affect the closure object (captured by value)

    std::cout << store() << "\n"; // prints 3


    // ------------------------------------------------------------
    // closure type is different for each lambda expression
    // ------------------------------------------------------------
    auto L1 = [](int v) { return v * 2; };
    auto L2 = [](int v) { return v * 2; };

    // Even though they look identical, L1 and L2 have DIFFERENT closure types.
    // Each lambda expression generates its own unique type.

    return 0;
}
