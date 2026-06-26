#include <iostream>
#include <set>
#include <string>

// set_basics.cpp
// purpose               = demonstrate std::set ordered unique elements
// container             = std::set<std::string> for sorted, non‑duplicate values
// ordering              = ascending order by key (strict weak ordering)
// operations            = insert(), find(), erase(), count(), iteration
// notes                 = duplicates ignored; iterators are bidirectional

int main() {

    std::set<std::string> names;

    // insert elements (duplicates ignored)
    names.insert("Alice");
    names.insert("Bob");
    names.insert("Carol");
    names.insert("Bob");      // ignored

    std::cout << "names:\n";
    for (auto& n : names)
        std::cout << "  " << n << "\n";

    // lookup
    if (names.count("Carol") == 1)
        std::cout << "\nCarol found\n";

    // find() returns iterator
    auto it = names.find("Bob");
    if (it != names.end())
        std::cout << "Bob found via iterator\n";

    // erase
    names.erase("Alice");

    std::cout << "\nafter erase:\n";
    for (auto& n : names)
        std::cout << "  " << n << "\n";

    return 0;
}
