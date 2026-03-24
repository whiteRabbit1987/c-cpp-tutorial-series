// 04_math/transforms/transforms_basics.cpp
// transforms fundamentals
// purpose               = apply translation, rotation, and scaling to 2d vectors
// transform2d           = combined affine transform (scale * rotation * translation)
// apply                 = multiply vector by transform
// best practice         = compose transforms by multiplying matrices in correct order

#include <iostream>
#include <cmath>

struct Vec2 {
    float x;
    float y;
};

// 3x3 matrix for 2d affine transforms
struct Mat3 {
    float m[3][3];

    // multiply matrix by vector (homogeneous)
    Vec2 apply(const Vec2& v) const {
        float nx = m[0][0] * v.x + m[0][1] * v.y + m[0][2];
        float ny = m[1][0] * v.x + m[1][1] * v.y + m[1][2];
        return {nx, ny};
    }

    // matrix-matrix multiplication
    Mat3 operator*(const Mat3& o) const {
        Mat3 r{};
        for (int row = 0; row < 3; ++row)
            for (int col = 0; col < 3; ++col)
                r.m[row][col] =
                    m[row][0] * o.m[0][col] +
                    m[row][1] * o.m[1][col] +
                    m[row][2] * o.m[2][col];
        return r;
    }

    // identity
    static Mat3 identity() {
        return {{
            {1,0,0},
            {0,1,0},
            {0,0,1}
        }};
    }

    // translation
    static Mat3 translation(float tx, float ty) {
        return {{
            {1,0,tx},
            {0,1,ty},
            {0,0,1}
        }};
    }

    // scaling
    static Mat3 scale(float sx, float sy) {
        return {{
            {sx,0,0},
            {0,sy,0},
            {0,0,1}
        }};
    }

    // rotation
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

// build a combined transform
Mat3 build_transform(const Vec2& position, float rotationRadians, const Vec2& scale) {
    Mat3 T = Mat3::translation(position.x, position.y);
    Mat3 R = Mat3::rotation(rotationRadians);
    Mat3 S = Mat3::scale(scale.x, scale.y);

    // final = T * R * S
    return T * R * S;
}

int main() {
    Vec2 point{1.0f, 0.0f};

    Vec2 position{5.0f, 2.0f};
    float rotation = 3.14159f * 0.5f; // 90 degrees
    Vec2 scale{2.0f, 1.0f};

    Mat3 transform = build_transform(position, rotation, scale);
    Vec2 result = transform.apply(point);

    std::cout << "Transformed Vec2: (" << result.x << ", " << result.y << ")\n";

    return 0;
}
