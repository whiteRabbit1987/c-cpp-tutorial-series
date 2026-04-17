// lambda_init_and_mutable.cpp
// purpose               = demonstrate init-captures and mutable lambdas
// topics                = init capture, move capture, reference capture,
//                         mutable behavior, closure object state
// best practice         = use init-captures for clarity and safe state transfer

#include <iostream>
#include <vector>
#include <memory>

int main() {

    int a = 10;
    int b = 20;

    // ------------------------------------------------------------
    // init-capture: [x = a]
    // ------------------------------------------------------------
    auto cap_init = [x = a]() {
        return x;   // x is a new member inside the closure object
    };

    a = 99; // does NOT affect x inside lambda

    std::cout << "cap_init(): " << cap_init() << "\n"; // prints 10


    // ------------------------------------------------------------
    // reference init-capture: [&ref = b]
    // ------------------------------------------------------------
    auto cap_ref_init = [&ref = b]() {
        return ref;   // ref is an alias to b
    };

    b = 123; // DOES affect lambda

    std::cout << "cap_ref_init(): " << cap_ref_init() << "\n"; // prints 123


    // ------------------------------------------------------------
    // move capture: [ptr = std::move(p)]
    // ------------------------------------------------------------
    auto p = std::make_unique<int>(42);

    auto cap_move = [ptr = std::move(p)]() {
        return *ptr;   // ptr is now owned by the closure object
    };

    std::cout << "cap_move(): " << cap_move() << "\n"; // prints 42
    // p is now null


    // ------------------------------------------------------------
    // mutable lambda: allows modifying captured-by-copy values
    // ------------------------------------------------------------
    int z = 5;

    auto cap_mutable = [z]() mutable {
        z += 10;   // allowed because of 'mutable'
        return z;
    };

    std::cout << "cap_mutable(): " << cap_mutable() << "\n"; // prints 15
    std::cout << "z outside: " << z << "\n";                  // still 5


    // ------------------------------------------------------------
    // init-capture + mutable
    // ------------------------------------------------------------
    int base = 100;

    auto cap_init_mut = [val = base]() mutable {
        val += 50;
        return val;
    };

    std::cout << "cap_init_mut(): " << cap_init_mut() << "\n"; // prints 150
    std::cout << "base outside: " << base << "\n";             // still 100


    // ------------------------------------------------------------
    // capturing this safely: [self = this]
    // ------------------------------------------------------------
    struct Obj {
        int value = 7;

        auto make_lambda() {
            return [self = this]() {
                return self->value;
            };
        }
    };

    Obj obj;
    auto lam = obj.make_lambda();
    std::cout << "capture this safely: " << lam() << "\n"; // prints 7


    return 0;
}
