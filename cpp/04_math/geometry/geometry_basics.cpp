// 04_math/geometry/geometry_basics.cpp
// geometry fundamentals
// purpose               = basic 2d geometry operations used in game development
// vector2               = position, direction, movement
// distance              = measure between two points
// dot product           = projection, angle checks, facing direction
// normalization         = convert vector to unit length
// best practice         = keep math functions small, pure, and reusable

#include <iostream>
#include <cmath>

struct Vec2 {
    float x;
    float y;

    // vector addition
    Vec2 operator+(const Vec2& other) const {
        return {x + other.x, y + other.y};
    }

    // vector subtraction
    Vec2 operator-(const Vec2& other) const {
        return {x - other.x, y - other.y};
    }

    // scalar multiplication
    Vec2 operator*(float s) const {
        return {x * s, y * s};
    }

    // dot product
    float dot(const Vec2& other) const {
        return x * other.x + y * other.y;
    }

    // length (magnitude)
    float length() const {
        return std::sqrt(x * x + y * y);
    }

    // normalized vector
    Vec2 normalized() const {
        float len = length();
        if (len == 0.0f) return {0.0f, 0.0f};
        return {x / len, y / len};
    }
};

// distance between two points
float distance(const Vec2& a, const Vec2& b) {
    return (b - a).length();
}

int main() {
    Vec2 player{2.0f, 3.0f};
    Vec2 enemy{7.0f, 9.0f};

    std::cout << "Distance: " << distance(player, enemy) << "\n";

    Vec2 dir = (enemy - player).normalized();
    std::cout << "Direction: (" << dir.x << ", " << dir.y << ")\n";

    float facing = dir.dot({1.0f, 0.0f});
    std::cout << "Dot with right vector: " << facing << "\n";

    return 0;
}
