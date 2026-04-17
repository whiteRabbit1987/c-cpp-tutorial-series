// lambda_sort_for_each.cpp
// purpose               = demonstrate std::for_each after sorting with a lambda comparator
// topics                = custom comparator, for_each, callable usage
// best practice         = use for_each for short, local iteration logic

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> v{3, 4, 6, 3, 6, 7};

    // ------------------------------------------------------------
    // sort descending using a lambda comparator
    // ------------------------------------------------------------
    std::sort(v.begin(), v.end(),
        [](int a, int b) {
            return a > b;   // true means "a comes before b"
        }
    );

    // ------------------------------------------------------------
    // print using std::for_each + lambda
    // ------------------------------------------------------------
    std::for_each(v.begin(), v.end(),
        [](int value) {
            std::cout << value << "\n";
        }
    );

    return 0;
}
