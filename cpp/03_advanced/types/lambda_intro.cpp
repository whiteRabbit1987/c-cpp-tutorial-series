// lambda_intro.cpp
// purpose               = introduce lambda expressions and capture behavior
// topics                = basic lambda syntax, captures, auto parameters,
//                         returning lambdas, storing lambdas
// best practice         = use lambdas for short, local callable logic

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {

    // ------------------------------------------------------------
    // basic lambda
    // ------------------------------------------------------------
    auto greet = []() {
        std::cout << "Hello from a lambda\n";
    };
    greet();


    // ------------------------------------------------------------
    // lambda with parameters
    // ------------------------------------------------------------
    auto add = [](int a, int b) {
        return a + b;
    };
    std::cout << add(3, 4) << "\n";


    // ------------------------------------------------------------
    // lambda with auto parameters (C++14+)
    // ------------------------------------------------------------
    auto multiply = [](auto x, auto y) {
        return x * y;
    };
    std::cout << multiply(2, 2.5) << "\n";


    // ------------------------------------------------------------
    // capturing variables
    // ------------------------------------------------------------
    int value = 10;

    auto capture_by_value = [value]() {
        std::cout << "Captured by value: " << value << "\n";
    };

    auto capture_by_reference = [&value]() {
        std::cout << "Captured by reference: " << value << "\n";
    };

    capture_by_value();
    capture_by_reference();

    value = 20; // affects reference capture only

    capture_by_value();      // still prints old value
    capture_by_reference();  // prints updated value


    // ------------------------------------------------------------
    // capturing everything
    // ------------------------------------------------------------
    int a = 1, b = 2;

    auto capture_all_by_value = [=]() {
        std::cout << a + b << "\n";
    };

    auto capture_all_by_reference = [&]() {
        std::cout << a + b << "\n";
    };


    // ------------------------------------------------------------
    // lambda used with STL algorithms
    // ------------------------------------------------------------
    std::vector<int> nums{1, 2, 3, 4, 5};

    std::for_each(nums.begin(), nums.end(), [](int n) {
        std::cout << "num: " << n << "\n";
    });


    // ------------------------------------------------------------
    // returning a lambda
    // ------------------------------------------------------------
    auto make_incrementer = [](int inc) {
        return [inc](int x) { return x + inc; };
    };

    auto inc5 = make_incrementer(5);
    std::cout << inc5(10) << "\n"; // 15


    // ------------------------------------------------------------
    // storing lambdas in std::function
    // ------------------------------------------------------------
    std::function<int(int)> doubler = [](int x) { return x * 2; };
    std::cout << doubler(7) << "\n";


    return 0;
}
