// 04_math/vectors/vectors_basics.cpp
// vectors fundamentals
// purpose               = core 2d vector operations for movement and direction
// add/subtract          = combine or compare positions and directions
// scale                 = adjust magnitude
// dot product           = projection and alignment
// perpendicular         = build orthogonal directions
// normalization         = convert to unit vector
// best practice         = keep vector math small, pure, and reusable

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

    // perpendicular vector (90 degrees)
    Vec2 perpendicular() const {
        return {-y, x};
    }
};

// project vector a onto vector b
Vec2 project(const Vec2& a, const Vec2& b) {
    float denom = b.dot(b);
    if (denom == 0.0f) return {0.0f, 0.0f};
    float t = a.dot(b) / denom;
    return b * t;
}

int main() {
    Vec2 a{3.0f, 4.0f};
    Vec2 b{1.0f, 0.0f};

    std::cout << "Length of a: " << a.length() << "\n";

    Vec2 n = a.normalized();
    std::cout << "Normalized a: (" << n.x << ", " << n.y << ")\n";

    Vec2 p = project(a, b);
    std::cout << "Projection of a onto b: (" << p.x << ", " << p.y << ")\n";

    Vec2 perp = a.perpendicular();
    std::cout << "Perpendicular to a: (" << perp.x << ", " << perp.y << ")\n";

    return 0;
}
