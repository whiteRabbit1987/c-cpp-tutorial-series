#include <iostream>

// constexpr variables   = value can be evaluated at compile time
//                         enables compiler optimizations and ensures constants
// constexpr functions   = function result can be evaluated at compile time if given constant arguments
//                         allows compile-time calculations for performance

constexpr int calculateExperience(int level) {
    return level * level * 100;
}

int main() {
    constexpr int exp = calculateExperience(5);
    std::cout << "Experience for level 5: " << exp << std::endl;
    return 0;
}
