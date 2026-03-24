// 04_math/physics_math/physics_math_basics.cpp
// physics math fundamentals
// purpose               = core kinematic equations and vector operations
// velocity              = rate of change of position
// acceleration          = rate of change of velocity
// integration           = update position and velocity over time
// drag                  = simple damping model
// best practice         = keep physics updates deterministic and time-based

#include <iostream>

struct Vec2 {
    float x;
    float y;

    Vec2 operator+(const Vec2& other) const {
        return {x + other.x, y + other.y};
    }

    Vec2 operator-(const Vec2& other) const {
        return {x - other.x, y - other.y};
    }

    Vec2 operator*(float s) const {
        return {x * s, y * s};
    }
};

// apply drag to velocity
Vec2 apply_drag(const Vec2& velocity, float drag, float dt) {
    return velocity * (1.0f - drag * dt);
}

// integrate velocity and position
void integrate(Vec2& position, Vec2& velocity, const Vec2& acceleration, float dt) {
    velocity = velocity + acceleration * dt;
    position = position + velocity * dt;
}

int main() {
    Vec2 position{0.0f, 0.0f};
    Vec2 velocity{5.0f, 0.0f};
    Vec2 acceleration{0.0f, -9.8f};

    float dt = 0.016f; // 60 updates per second
    float drag = 0.1f;

    integrate(position, velocity, acceleration, dt);
    velocity = apply_drag(velocity, drag, dt);

    std::cout << "Position: (" << position.x << ", " << position.y << ")\n";
    std::cout << "Velocity: (" << velocity.x << ", " << velocity.y << ")\n";

    return 0;
}
