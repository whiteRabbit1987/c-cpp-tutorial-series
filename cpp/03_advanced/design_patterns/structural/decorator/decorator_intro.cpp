#include <iostream>

// decorator pattern      =   attach additional responsibilities to an object dynamically
//                           provides a flexible alternative to subclassing for extending behavior
// component              =   defines the interface for objects that can have responsibilities added
// concrete component     =   the original object being wrapped
// decorator              =   wraps a component and adds behavior before/after delegating
// dynamic extension      =   behavior can be added at runtime by stacking decorators

class Coffee {
public:
    virtual double cost() = 0;
    virtual ~Coffee() = default;
};

class BasicCoffee : public Coffee {
public:
    double cost() override {
        return 2.0;
    }
};

class CoffeeDecorator : public Coffee {
protected:
    Coffee* wrappee;
public:
    CoffeeDecorator(Coffee* c) : wrappee(c) {}
};

class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* c) : CoffeeDecorator(c) {}

    double cost() override {
        return wrappee->cost() + 0.5;
    }
};

class Sugar : public CoffeeDecorator {
public:
    Sugar(Coffee* c) : CoffeeDecorator(c) {}

    double cost() override {
        return wrappee->cost() + 0.2;
    }
};

int main() {
    Coffee* c = new BasicCoffee();
    c = new Milk(c);
    c = new Sugar(c);

    std::cout << "Total cost: " << c->cost() << "\n";

    delete c;
    return 0;
}
