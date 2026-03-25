// 03_advanced/stl/function_objects_intro.cpp
// function objects (functors) overview
// purpose               = introduce functors, standard function objects, and lambdas
// functor               = object with operator() allowing function-call syntax
// stateful functor      = functor that stores data and uses it during calls
// std::functional       = header with predefined function objects (less, greater, plus, etc.)
// lambda expressions    = unnamed inline functions, often replacing simple functors
// best practice         = use functors for stateful behavior, lambdas for local one-off logic

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <string>

int main() {

    // ------------------------------------------------------------
    // basic functor
    // ------------------------------------------------------------
    // suited for: operations that need to store state or configuration
    // properties:
    //  - object with operator()
    //  - can hold data
    //  - can be reused across algorithms

    class MultiplyBy {
    public:
        explicit MultiplyBy(int factor) : factor_(factor) {}
        int operator()(int value) const { return value * factor_; }
    private:
        int factor_;
    };

    MultiplyBy times5(5);
    std::cout << "Multiply functor: " << times5(10) << "\n"; // 50


    // ------------------------------------------------------------
    // functor used in an algorithm
    // ------------------------------------------------------------
    // suited for: custom comparison, filtering, transformation

    struct SortByHealth {
        bool operator()(const std::pair<std::string,int>& a,
                        const std::pair<std::string,int>& b) const {
            return a.second < b.second;
        }
    };

    std::vector<std::pair<std::string,int>> enemies = {
        {"Zombie",100}, {"Mutant",150}, {"Ghoul",80}
    };

    std::sort(enemies.begin(), enemies.end(), SortByHealth());

    std::cout << "Sorted by health (functor): ";
    for (const auto& e : enemies)
        std::cout << e.first << ":" << e.second << " ";
    std::cout << "\n";


    // ------------------------------------------------------------
    // standard function objects (<functional>)
    // ------------------------------------------------------------
    // suited for: common operations (comparison, arithmetic)
    // examples: std::less, std::greater, std::plus, std::minus

    std::vector<int> scores = {10,40,20,50,30};
    std::sort(scores.begin(), scores.end(), std::greater<int>());

    std::cout << "Sorted descending (std::greater): ";
    for (int s : scores)
        std::cout << s << " ";
    std::cout << "\n";


    // ------------------------------------------------------------
    // lambda expressions
    // ------------------------------------------------------------
    // suited for: short, inline, one-off operations
    // properties:
    //  - unnamed function
    //  - can capture local variables
    //  - ideal for algorithms requiring small custom logic

    std::sort(enemies.begin(), enemies.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second;
        }
    );

    std::cout << "Sorted by health (lambda): ";
    for (const auto& e : enemies)
        std::cout << e.first << ":" << e.second << " ";
    std::cout << "\n";


    // ------------------------------------------------------------
    // when to use what
    // ------------------------------------------------------------
    // functor:
    //  - needs state
    //  - reusable logic
    //  - more explicit than lambdas
    //
    // lambda:
    //  - short, local logic
    //  - avoids creating a named functor type
    //
    // regular function:
    //  - simple reusable logic
    //  - no state

    return 0;
}
