#include <iostream>

// Class with static and non-static variables
// Static variable     = shared across all instances of the class
// Non-static variable = unique to each object
// print() method      = prints and increments static, prints non-static

class Class {
public:
    static int Static;   // static variable
    int NonStatic;       // non-static variable

    void print() {
        std::cout << "Static = " << ++Static
                  << ", NonStatic = " << NonStatic << std::endl;
    }
};

// Definition of static variable outside the class
int Class::Static = 0;

int main() {
    Class instance1, instance2;   // create two objects

    instance1.NonStatic = 10;     // set first object's non-static value
    instance2.NonStatic = 20;     // set second object's non-static value

    instance1.print();             // prints: Static = 1, NonStatic = 10
    instance2.print();             // prints: Static = 2, NonStatic = 20

    return 0;
}
