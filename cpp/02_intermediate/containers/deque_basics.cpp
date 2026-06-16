#include <iostream>
#include <deque>

// deque_basics.cpp
// purpose               = demonstrate std::deque operations and behavior
// container             = std::deque<int> for double-ended insertion/removal
// operations            = push_front, push_back, pop_front, pop_back
// access                = operator[], front(), back()
// notes                 = deque supports random access and fast growth at both ends

int main() {

    std::deque<int> d;

    // insert elements at both ends
    d.push_back(10);     // [10]
    d.push_front(5);     // [5, 10]
    d.push_back(20);     // [5, 10, 20]
    d.push_front(1);     // [1, 5, 10, 20]

    std::cout << "Deque: ";
    for (int v : d) std::cout << v << " ";
    std::cout << "\n";

    // element access
    std::cout << "front = " << d.front() << "\n";
    std::cout << "back  = " << d.back()  << "\n";
    std::cout << "index 2 = " << d[2]    << "\n";

    // remove from both ends
    d.pop_front();       // remove 1
    d.pop_back();        // remove 20

    std::cout << "After pops: ";
    for (int v : d) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
