// 03_advanced/stl/algorithms_basics.cpp
// stl algorithms fundamentals
// sort                   = reorder elements in ascending order
// find                   = linear search for a value
// count                  = count occurrences of a value
// iterators              = begin/end define algorithm ranges
// purpose                = demonstrate core stl algorithms

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> items = {
        "potion", "shield", "sword", "shield", "potion"
    };

    std::sort(items.begin(), items.end());

    for (const auto& i : items)
        std::cout << i << " ";
    std::cout << "\n";

    auto it = std::find(items.begin(), items.end(), "shield");
    if (it != items.end())
        std::cout << "Found: " << *it << "\n";

    int countPotion = std::count(items.begin(), items.end(), "potion");
    std::cout << "Potions: " << countPotion << "\n";

    return 0;
}
