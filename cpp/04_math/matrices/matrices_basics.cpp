// 04_math/matrices/matrices_basics.cpp
// matrices fundamentals
// purpose               = small matrix utilities for 2d operations
// mat2                  = 2x2 matrix for rotation and scaling
// mat3                  = 3x3 matrix for affine transforms
// multiply              = matrix-vector and matrix-matrix multiplication
// best practice         = keep matrices immutable and operations pure

#include <iostream>
#include <cmath>

struct Vec2 {
    float x;
    float y;
};

// 2x2 matrix
struct Mat2 {
    float m00, m01;
    float m10, m11;

    // multiply matrix by vector
    Vec2 multiply(const Vec2& v) const {
        return {
            m00 * v.x + m01 * v.y,
            m10 * v.x + m11 * v.y
        };
    }

    // matrix-matrix multiplication
    Mat2 operator*(const Mat2& other) const {
        return {
            m00 * other.m00 + m01 * other.m10,
            m00 * other.m01 + m01 * other.m11,
            m10 * other.m00 + m11 * other.m10,
            m10 * other.m01 + m11 * other.m11
        };
    }

    // create rotation matrix
    static Mat2 rotation(float radians) {
        float c = std::cos(radians);
        float s = std::sin(radians);
        return { c, -s, s, c };
    }

    // create scaling matrix
    static Mat2 scale(float sx, float sy) {
        return { sx, 0.0f, 0.0f, sy };
    }
};

// 3x3 matrix for 2d affine transforms
struct Mat3 {
    float m[3][3];

    // multiply matrix by vector (homogeneous)
    Vec2 multiply(const Vec2& v) const {
        float x = m[0][0] * v.x + m[0][1] * v.y + m[0][2];
        float y = m[1][0] * v.x + m[1][1] * v.y + m[1][2];
        return {x, y};
    }

    // matrix-matrix multiplication
    Mat3 operator*(const Mat3& o) const {
        Mat3 r{};
        for (int row = 0; row < 3; ++row)
            for (int col = 0; col < 3; ++col)
                r.m[row][col] = m[row][0] * o.m[0][col] +
                                m[row][1] * o.m[1][col] +
                                m[row][2] * o.m[2][col];
        return r;
    }

    // identity matrix
    static Mat3 identity() {
        return {{
            {1,0,0},
            {1,0,0},
            {0,0,1}
        }};
    }

    // translation matrix
    static Mat3 translation(float tx, float ty) {
        return {{
            {1,0,tx},
            {0,1,ty},
            {0,0,1}
        }};
    }

    // scaling matrix
    static Mat3 scale(float sx, float sy) {
        return {{
            {sx,0,0},
            {0,sy,0},
            {0,0,1}
        }};
    }

    // rotation matrix
    static Mat3 rotation(float radians) {
        float c = std::cos(radians);
        float s = std::sin(radians);
        return {{
            {c,-s,0},
            {s, c,0},
            {0, 0,1}
        }};
    }
};

int main() {
    Vec2 v{1.0f, 0.0f};

    Mat2 rot = Mat2::rotation(3.14159f * 0.5f);
    Vec2 rotated = rot.multiply(v);
    std::cout << "Rotated Vec2: (" << rotated.x << ", " << rotated.y << ")\n";

    Mat3 t = Mat3::translation(5.0f, 2.0f);
    Vec2 moved = t.multiply(v);
    std::cout << "Translated Vec2: (" << moved.x << ", " << moved.y << ")\n";

    return 0;
}
