#include <iostream>

// inline functions      = suggests compiler replace function call with function code
//                         reduces call overhead, especially for small functions

inline int calculateDamage(int base, int modifier) {
    return base + modifier;
}

int main() {
    int total = calculateDamage(50, 10);
    std::cout << "Total damage: " << total << std::endl;
    return 0;
}
