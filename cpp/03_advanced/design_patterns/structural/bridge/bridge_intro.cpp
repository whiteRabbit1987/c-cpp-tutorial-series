// bridge_intro.cpp
// Structural Pattern: Bridge
// Purpose: Decouple an abstraction from its implementation so both can vary independently.
// When to use: When you have exploding class hierarchies or want to separate WHAT you do from HOW you do it.

#include <iostream>

// Implementation interface (the "Implementor")
class Renderer {
public:
    virtual void renderCircle(float x, float y, float radius) = 0;
    virtual ~Renderer() = default;
};

// Concrete Implementations
class RasterRenderer : public Renderer {
public:
    void renderCircle(float x, float y, float radius) override {
        std::cout << "Rasterizing circle at (" << x << ", " << y << ") radius " << radius << "\n";
    }
};

class VectorRenderer : public Renderer {
public:
    void renderCircle(float x, float y, float radius) override {
        std::cout << "Drawing vector circle at (" << x << ", " << y << ") radius " << radius << "\n";
    }
};

// Abstraction
class Shape {
protected:
    Renderer& renderer;
public:
    Shape(Renderer& r) : renderer(r) {}
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

// Refined Abstraction
class Circle : public Shape {
private:
    float x, y, radius;
public:
    Circle(Renderer& r, float x, float y, float radius)
        : Shape(r), x(x), y(y), radius(radius) {}

    void draw() override {
        renderer.renderCircle(x, y, radius);
    }
};

int main() {
    RasterRenderer raster;
    VectorRenderer vector;

    Circle c1(raster, 10, 10, 5);
    Circle c2(vector, 20, 20, 10);

    c1.draw();
    c2.draw();

    return 0;
}
