#include <iostream>
#include <list>
#include <string>

// list_splice.cpp
// purpose               = demonstrate std::list::splice for moving nodes between lists
// container             = std::list<std::string> for ordered elements
// splice behavior       = transfers nodes in O(1) without copying
// operations            = splice(pos, other), splice(pos, other, it), splice(pos, other, first, last)
// notes                 = iterators remain valid; ownership of nodes changes lists

int main() {

    std::list<std::string> A = {"alpha", "beta", "gamma"};
    std::list<std::string> B = {"red", "green", "blue"};

    std::cout << "A before splice: ";
    for (auto& s : A) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "B before splice: ";
    for (auto& s : B) std::cout << s << " ";
    std::cout << "\n\n";

    // ------------------------------------------------------------
    // splice entire list B into A at A.begin()
    // ------------------------------------------------------------
    A.splice(A.begin(), B);

    std::cout << "A after splice(A.begin(), B): ";
    for (auto& s : A) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "B after splice (should be empty): ";
    for (auto& s : B) std::cout << s << " ";
    std::cout << "\n\n";

    // ------------------------------------------------------------
    // repopulate B for more splice examples
    // ------------------------------------------------------------
    B.push_back("cyan");
    B.push_back("magenta");
    B.push_back("yellow");

    // move a single element from A to B
    auto it = A.begin();
    ++it; // points to second element
    B.splice(B.begin(), A, it);

    std::cout << "A after single-element splice: ";
    for (auto& s : A) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "B after single-element splice: ";
    for (auto& s : B) std::cout << s << " ";
    std::cout << "\n\n";

    // ------------------------------------------------------------
    // splice a range from A into B
    // ------------------------------------------------------------
    auto first = A.begin();
    auto last  = A.end();
    --last; // exclude last element

    B.splice(B.end(), A, first, last);

    std::cout << "A after range splice: ";
    for (auto& s : A) std::cout << s << " ";
    std::cout << "\n";

    std::cout << "B after range splice: ";
    for (auto& s : B) std::cout << s << " ";
    std::cout << "\n";

    return 0;
}
