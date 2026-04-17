// lambda_sort_comparator.cpp
// purpose               = demonstrate lambdas as custom comparators for std::sort
// topics                = comparator rules, ascending/descending, struct sorting, captures
// best practice         = use lambdas for short, local comparison logic

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    // ------------------------------------------------------------
    // basic descending sort using a lambda comparator
    // ------------------------------------------------------------
    std::vector<int> v{3, 4, 6, 3, 6, 7};

    std::sort(v.begin(), v.end(),
        [](int a, int b) {
            return a > b;   // true means "a comes before b"
        }
    );

    for (int i : v)
        std::cout << i << "\n";


    // ------------------------------------------------------------
    // ascending sort (equivalent to default)
    // ------------------------------------------------------------
    std::sort(v.begin(), v.end(),
        [](int a, int b) {
            return a < b;
        }
    );


    // ------------------------------------------------------------
    // sorting a struct with a lambda comparator
    // ------------------------------------------------------------
    struct Item {
        int id;
        int score;
    };

    std::vector<Item> items{
        {1, 50},
        {2, 10},
        {3, 75},
        {4, 30}
    };

    // sort by score descending
    std::sort(items.begin(), items.end(),
        [](const Item& a, const Item& b) {
            return a.score > b.score;
        }
    );

    for (const auto& it : items)
        std::cout << it.id << " : " << it.score << "\n";


    // ------------------------------------------------------------
    // sorting with a captured value
    // ------------------------------------------------------------
    int threshold = 40;

    // items with score >= threshold come first
    std::sort(items.begin(), items.end(),
        [threshold](const Item& a, const Item& b) {
            bool a_ok = a.score >= threshold;
            bool b_ok = b.score >= threshold;

            if (a_ok != b_ok)
                return a_ok;   // true means a comes first

            return a.score > b.score; // fallback
        }
    );

    std::cout << "\nwith threshold sort:\n";
    for (const auto& it : items)
        std::cout << it.id << " : " << it.score << "\n";


    return 0;
}
