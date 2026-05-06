// composite_intro.cpp
// Composite Pattern (Basic Intro)
// Goal: Treat individual objects and groups of objects uniformly.

#include <iostream>
#include <vector>
#include <memory>

// Component interface
class Graphic {
public:
    virtual void draw() = 0;
    virtual ~Graphic() = default;
};

// Leaf
class Circle : public Graphic {
public:
    void draw() override {
        std::cout << "Drawing Circle\n";
    }
};

// Composite
class GraphicGroup : public Graphic {
private:
    std::vector<std::shared_ptr<Graphic>> children;
public:
    void add(const std::shared_ptr<Graphic>& g) {
        children.push_back(g);
    }

    void draw() override {
        for (auto& c : children)
            c->draw();
    }
};

int main() {
    auto circle1 = std::make_shared<Circle>();
    auto circle2 = std::make_shared<Circle>();

    GraphicGroup group;
    group.add(circle1);
    group.add(circle2);

    group.draw();
    return 0;
}
