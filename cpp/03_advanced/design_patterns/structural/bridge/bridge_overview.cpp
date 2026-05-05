// bridge_overview.cpp
// Structural Pattern: Bridge
// This file demonstrates:
// 1. The problem: exploding class hierarchies
// 2. The Bridge solution: separate abstraction from implementation
// 3. Implementor hierarchy
// 4. Abstraction hierarchy
// 5. Why Bridge is useful in real systems

#include <iostream>

// ------------------------------------------------------------
// 1. The problem: exploding class hierarchies
// ------------------------------------------------------------
// Without Bridge, you might create classes like:
//   RasterCircle, VectorCircle, RasterSquare, VectorSquare, ...
// This grows exponentially as shapes and renderers increase.

// ------------------------------------------------------------
// 2. Implementor interface
// ------------------------------------------------------------
class Renderer {
public:
    virtual void renderCircle(float x, float y, float radius) = 0;
    virtual void renderSquare(float x, float y, float size) = 0;
    virtual ~Renderer() = default;
};

// ------------------------------------------------------------
// 3. Concrete Implementors
// ------------------------------------------------------------
class RasterRenderer : public Renderer {
public:
    void renderCircle(float x, float y, float radius) override {
        std::cout << "[Raster] Circle at (" << x << ", " << y << ") radius " << radius << "\n";
    }

    void renderSquare(float x, float y, float size) override {
        std::cout << "[Raster] Square at (" << x << ", " << y << ") size " << size << "\n";
    }
};

class VectorRenderer : public Renderer {
public:
    void renderCircle(float x, float y, float radius) override {
        std::cout << "[Vector] Circle at (" << x << ", " << y << ") radius " << radius << "\n";
    }

    void renderSquare(float x, float y, float size) override {
        std::cout << "[Vector] Square at (" << x << ", " << y << ") size " << size << "\n";
    }
};

// ------------------------------------------------------------
// 4. Abstraction hierarchy
// ------------------------------------------------------------
class Shape {
protected:
    Renderer& renderer;
public:
    Shape(Renderer& r) : renderer(r) {}
    virtual void draw() = 0;
    virtual ~Shape() = default;
};

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

class Square : public Shape {
private:
    float x, y, size;
public:
    Square(Renderer& r, float x, float y, float size)
        : Shape(r), x(x), y(y), size(size) {}

    void draw() override {
        renderer.renderSquare(x, y, size);
    }
};

// ------------------------------------------------------------
// 5. Why Bridge matters (practical notes)
// ------------------------------------------------------------
// - Avoids class explosion
// - Lets you mix and match abstractions and implementations
// - Useful for graphics APIs, drivers, UI toolkits, OS abstraction layers
// - Lets you change implementation at runtime
// - Keeps code flexible and maintainable

// ------------------------------------------------------------
// 6. Example usage
// ------------------------------------------------------------
int main() {
    RasterRenderer raster;
    VectorRenderer vector;

    Circle c1(raster, 5, 5, 2);
    Square s1(vector, 10, 10, 4);

    c1.draw();
    s1.draw();

    return 0;
}
