// ranges_filter_pipe.cpp
// purpose               = demonstrate C++20 pipe operator with std::ranges::views::filter
// topics                = ranges, views, lazy evaluation, pipeline syntax, lambda predicates
// best practice         = use ranges for clear, functional-style transformations

#include <iostream>
#include <vector>
#include <ranges>

int main() {

    std::vector<int> v{3, 4, 6, 3, 6, 7};

    // ------------------------------------------------------------
    // filter: keep only even numbers
    // ------------------------------------------------------------
    auto evens =
        v
        | std::ranges::views::filter([](int x) {
              return x % 2 == 0;   // predicate: keep even numbers
          });

    // ------------------------------------------------------------
    // print using for_each-like range-for
    // ------------------------------------------------------------
    for (int x : evens)
        std::cout << x << "\n";


    // ------------------------------------------------------------
    // filter + transform pipeline
    // ------------------------------------------------------------
    auto doubled_evens =
        v
        | std::ranges::views::filter([](int x) {
              return x % 2 == 0;
          })
        | std::ranges::views::transform([](int x) {
              return x * 2;
          });

    std::cout << "\ndoubled evens:\n";
    for (int x : doubled_evens)
        std::cout << x << "\n";


    // ------------------------------------------------------------
    // filter with a captured value
    // ------------------------------------------------------------
    int threshold = 5;

    auto above_threshold =
        v
        | std::ranges::views::filter([threshold](int x) {
              return x > threshold;
          });

    std::cout << "\nabove threshold:\n";
    for (int x : above_threshold)
        std::cout << x << "\n";

    return 0;
}
