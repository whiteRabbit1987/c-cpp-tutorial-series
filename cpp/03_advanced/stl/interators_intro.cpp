// 03_advanced/stl/iterators_intro.cpp
// iterators overview
// purpose               = introduce the 5 major iterator categories with examples
// input iterator        = read-only, single-pass (streams)
// output iterator       = write-only, single-pass (streams, inserters)
// forward iterator      = read/write, multi-pass (forward_list)
// bidirectional         = forward + backward movement (list, set, map)
// random access         = full pointer-like arithmetic (vector, deque)
// reverse iterators     = iterate backwards using rbegin/rend
// best practice         = choose iterator based on container capabilities and required operations

#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>
#include <algorithm>
#include <sstream>   // needed for istringstream

int main() {

    // ------------------------------------------------------------
    // input iterator
    // ------------------------------------------------------------
    // suited for: reading data from streams, parsing input
    // properties: read-only, single-pass, cannot go backwards

    std::istringstream iss("10 20 30");
    std::istream_iterator<int> inBegin(iss);
    std::istream_iterator<int> inEnd;

    std::cout << "Input iterator values: ";
    for (auto it = inBegin; it != inEnd; ++it)
        std::cout << *it << " ";
    std::cout << "\n";


    // ------------------------------------------------------------
    // output iterator
    // ------------------------------------------------------------
    // suited for: writing to streams, output ranges, algorithms
    // properties: write-only, single-pass

    std::cout << "Output iterator: ";
    std::ostream_iterator<int> out(std::cout, " ");
    *out = 1;
    *out = 2;
    *out = 3;
    std::cout << "\n";


    // ------------------------------------------------------------
    // forward iterator
    // ------------------------------------------------------------
    // suited for: multi-pass algorithms, reading/writing
    // properties: can move forward, can revisit elements

    std::forward_list<int> fl = {1, 2, 3};
    std::cout << "Forward iterator: ";
    for (auto it = fl.begin(); it != fl.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";


    // ------------------------------------------------------------
    // bidirectional iterator
    // ------------------------------------------------------------
    // suited for: containers that allow forward/backward traversal
    // properties: can move both directions, multi-pass

    std::list<int> lst = {4, 5, 6};

    std::cout << "Bidirectional forward: ";
    for (auto it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";

    std::cout << "Bidirectional backward: ";
    for (auto it = std::prev(lst.end()); ; --it) {
        std::cout << *it << " ";
        if (it == lst.begin()) break;
    }
    std::cout << "\n";


    // ------------------------------------------------------------
    // random access iterator
    // ------------------------------------------------------------
    // suited for: fast indexing, pointer-like arithmetic
    // properties: supports +, -, <, >, [], it[n]

    std::vector<int> v = {7, 8, 9, 10};
    auto it = v.begin();

    std::cout << "Random access: ";
    std::cout << it[0] << " ";     // 7
    std::cout << it[2] << " ";     // 9
    std::cout << *(it + 3) << " "; // 10
    std::cout << "\n";


    // ------------------------------------------------------------
    // reverse iterators (rbegin/rend)
    // ------------------------------------------------------------
    // suited for: reverse traversal without manual prev()
    // properties: behave like random/bidirectional depending on container

    std::cout << "Reverse iteration: ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
        std::cout << *rit << " ";
    std::cout << "\n";

    return 0;
}
