// Memory leaks occur when dynamically allocated memory is not released.
// Constructors may allocate resources; destructors must release them.
// Automatic objects are destroyed when they go out of scope.
// When an object is destroyed, its destructor is called automatically.
// The destructor has the same name as the class, prefixed with ~.
// Destructors have no return type and take no parameters.
// ~Class() is responsible for cleaning up memory allocated by Class().
// Proper use of destructors prevents memory leaks.

#include <iostream>

class Class {
public:
    Class(int val) {
        value = new int[val];
        std::cout << "Allocation (" << val << ") done." << std::endl;
    }

    ~Class() {
        delete[] value;
        std::cout << "Deletion done." << std::endl;
    }

    int* value;
};

void MakeALeak(void) {
    Class object(1000);
}

int main(void) {
    MakeALeak();
    return 0;
}
