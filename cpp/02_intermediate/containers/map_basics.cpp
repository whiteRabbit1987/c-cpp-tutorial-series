#include <iostream>
#include <map>
#include <string>

// map_basics.cpp
// purpose               = demonstrate std::map key/value storage and ordered lookup
// container             = std::map<std::string, int> for sorted associative pairs
// operations            = insert(), operator[], find(), erase(), iteration
// ordering              = keys stored in ascending sorted order
// notes                 = operator[] inserts default value if key not present

int main() {

    std::map<std::string, int> scores;

    // insert key/value pairs
    scores["Alice"] = 90;
    scores["Bob"]   = 75;
    scores["Carol"] = 88;

    // insert using insert()
    scores.insert({"Dave", 82});

    // lookup
    std::cout << "Alice score = " << scores["Alice"] << "\n";

    // find() returns iterator or end()
    auto it = scores.find("Carol");
    if (it != scores.end())
        std::cout << "Carol score = " << it->second << "\n";

    // iteration (sorted by key)
    std::cout << "\nAll scores:\n";
    for (auto& p : scores)
        std::cout << p.first << " = " << p.second << "\n";

    // erase by key
    scores.erase("Bob");

    std::cout << "\nAfter erasing Bob:\n";
    for (auto& p : scores)
        std::cout << p.first << " = " << p.second << "\n";

    return 0;
}
