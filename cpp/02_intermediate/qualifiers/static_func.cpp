#include <iostream>

// static functions      = restricts function visibility to the current source file
//                         helps encapsulate helper functions, not exposed externally

static void helper() {
    std::cout << "This is a static helper function." << std::endl;
}

int main() {
    helper();
    return 0;
}
