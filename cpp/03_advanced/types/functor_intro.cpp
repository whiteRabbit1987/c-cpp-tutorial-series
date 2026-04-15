// functor_intro.cpp
// purpose               = introduce functors (function objects) and how they behave
// topics                = operator(), stateful functors, using functors with STL algorithms
// best practice         = use functors when you need stateful callable behavior

#include <iostream>
#include <vector>
#include <algorithm>

// ------------------------------------------------------------
// basic functor: defines operator() so the object can be "called"
// ------------------------------------------------------------
struct Adder {
    int operator()(int a, int b) const {
        return a + b;
    }
};

// ------------------------------------------------------------
// stateful functor: stores data and uses it when called
// ------------------------------------------------------------
struct Incrementer {
    int amount;

    Incrementer(int amt) : amount(amt) {}

    int operator()(int x) const {
        return x + amount;
    }
};

// ------------------------------------------------------------
// functor used with STL algorithms
// ------------------------------------------------------------
struct PrintValue {
    void operator()(int x) const {
        std::cout << "value: " << x << "\n";
    }
};

int main() {

    // ------------------------------------------------------------
    // using a basic functor
    // ------------------------------------------------------------
    Adder add;
    std::cout << add(3, 4) << "\n"; // 7


    // ------------------------------------------------------------
    // using a stateful functor
    // ------------------------------------------------------------
    Incrementer inc5(5);
    std::cout << inc5(10) << "\n"; // 15


    // ------------------------------------------------------------
    // functor with STL algorithm
    // ------------------------------------------------------------
    std::vector<int> nums{1, 2, 3, 4, 5};

    std::for_each(nums.begin(), nums.end(), PrintValue());


    // ------------------------------------------------------------
    // functor vs lambda (quick comparison)
    // ------------------------------------------------------------
    auto lambda_inc5 = [=](int x) { return x + 5; };
    std::cout << lambda_inc5(10) << "\n"; // 15

    return 0;
}
