// for_each_intro.cpp
// purpose               = demonstrate std::for_each with functors, lambdas, and function pointers
// topics                = callable types, iteration behavior, modifying elements
// best practice         = use for_each when applying an operation to each element

#include <iostream>
#include <vector>
#include <algorithm>

// ------------------------------------------------------------
// functor example
// ------------------------------------------------------------
struct PrintValue {
    void operator()(int x) const {
        std::cout << "value: " << x << "\n";
    }
};

// ------------------------------------------------------------
// function pointer example
// ------------------------------------------------------------
void print_fn(int x) {
    std::cout << "fn: " << x << "\n";
}

int main() {

    std::vector<int> nums{1, 2, 3, 4, 5};

    // ------------------------------------------------------------
    // using a functor
    // ------------------------------------------------------------
    std::for_each(nums.begin(), nums.end(), PrintValue());


    // ------------------------------------------------------------
    // using a lambda
    // ------------------------------------------------------------
    std::for_each(nums.begin(), nums.end(), [](int x) {
        std::cout << "lambda: " << x << "\n";
    });


    // ------------------------------------------------------------
    // using a function pointer
    // ------------------------------------------------------------
    std::for_each(nums.begin(), nums.end(), print_fn);


    // ------------------------------------------------------------
    // modifying elements (lambda with reference)
    // ------------------------------------------------------------
    std::for_each(nums.begin(), nums.end(), [](int& x) {
        x *= 2; // double each element
    });

    std::cout << "after doubling:\n";
    for (int x : nums)
        std::cout << x << "\n";


    return 0;
}
