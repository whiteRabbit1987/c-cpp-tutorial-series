// bridge_overview.cpp
// Bridge Pattern — Extensive Overview
// This file demonstrates:
// - The problem of exploding class hierarchies
// - Full abstraction hierarchy
// - Full implementation hierarchy
// - Multiple shapes
// - Multiple renderers
// - Runtime switching of implementations
// - Why Bridge is used in real systems

#include <iostream>
#include <memory>

// ------------------------------------------------------------
// IMPLEMENTATION HIERARCHY (Implementor)
// ------------------------------------------------------------
class Renderer {
public:
    virtual void renderCircle(float x, float y, float radius) = 0;
    virtual void renderSquare(float x, float y, float size) = 0;
    virtual void renderTriangle(float x, float y, float base, float height) = 0;
    virtual ~Renderer() = default;
};

class RasterRenderer : public Renderer {
public:
    void renderCircle(float x, float y, float radius) override {
        std::cout << "[Raster] Circle at (" << x << ", " << y << ") radius " << radius << "\n";
    }
    void renderSquare(float x, float y, float size) override {
        std::cout << "[Raster] Square at (" << x << ", " << y << ") size " << size << "\n";
    }
    void renderTriangle(float x, float y, float base, float height) override {
        std::cout << "[Raster] Triangle at (" << x << ", " << y << ") base " << base
                  << " height " << height << "\n";
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
    void renderTriangle(float x, float y, float base, float height) override {
        std::cout << "[Vector] Triangle at (" << x << ", " << y << ") base " << base
                  << " height " << height << "\n";
    }
};

// ------------------------------------------------------------
// ABSTRACTION HIERARCHY (Abstraction)
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

class Triangle : public Shape {
private:
    float x, y, base, height;
public:
    Triangle(Renderer& r, float x, float y, float base, float height)
        : Shape(r), x(x), y(y), base(base), height(height) {}

    void draw() override {
        renderer.renderTriangle(x, y, base, height);
    }
};

// ------------------------------------------------------------
// WHY BRIDGE MATTERS
// ------------------------------------------------------------
// - Avoids class explosion (ShapeType × RendererType)
// - Lets you add new shapes without touching renderers
// - Lets you add new renderers without touching shapes
// - Enables runtime switching of implementations
// - Used in graphics engines, UI toolkits, OS abstraction layers

// ------------------------------------------------------------
// EXAMPLE USAGE
// ------------------------------------------------------------
int main() {
    RasterRenderer raster;
    VectorRenderer vector;

    Circle c(raster, 5, 5, 3);
    Square s(vector, 10, 10, 4);
    Triangle t(raster, 0, 0, 6, 3);

    c.draw();
    s.draw();
    t.draw();

    // Runtime switching
    Shape* dynamicShape = new Circle(vector, 20, 20, 10);
    dynamicShape->draw();
    delete dynamicShape;

    return 0;
}
// use case examples        =   graphics engines (separate shapes from renderers)
//                             UI toolkits (widgets separated from platform backends)
//                             device drivers (abstraction layer over hardware APIs)
//                             cross‑platform libraries (logic separated from OS implementation)
//                             game engines (rendering abstraction over DirectX/OpenGL/Vulkan)
//                             enterprise apps (separate business rules from data providers)
