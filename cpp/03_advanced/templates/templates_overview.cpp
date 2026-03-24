// 03_advanced/templates/templates_overview.cpp
// templates fundamentals
// function templates     = generic functions parameterized by type
// class templates        = generic classes parameterized by type
// template alias         = using alias for template types
// nested templates       = templates inside templates
// purpose                = write reusable, type-independent code

#include <iostream>
#include <string>
#include <vector>
#include <utility>

// function template
template <typename T>
int size_in_bits(const T& value) {
    return sizeof(value) * 8;
}

// class template
template <typename T>
class Point {
    T x, y;
public:
    Point(T xPos, T yPos) : x(xPos), y(yPos) {}
    void print() const {
        std::cout << "(" << x << ", " << y << ")\n";
    }
};

// template alias
template <typename T>
using Vec = std::vector<T>;

template <typename A, typename B>
using Pair = std::pair<A, B>;

int main() {
    std::cout << size_in_bits(42) << "\n";
    std::cout << size_in_bits(3.14) << "\n";

    Point<int> p1(10, 20);
    Point<float> p2(1.5f, 2.5f);
    p1.print();
    p2.print();

    Vec<Pair<std::string, int>> items = {
        {"Potion", 3},
        {"Shield", 1}
    };

    for (const auto& item : items)
        std::cout << item.first << ": " << item.second << "\n";

    return 0;
}
