#include "MathFunctions.h"

// Namespace Implementation      =   Demonstrates two ways to define functions within a namespace: 
//                                  using the Scope Resolution Operator (::) and using the namespace block {}.

// Geometry2D::add              =   Implementation using the explicit Scope Resolution Operator (::).

// Physics3D { ... }            =   Implementation using the namespace block style.

// Implementation using the Scope Resolution Operator (::)
int Geometry2D::add(int a, int b) {
    return a + b;
}

// Implementation using the namespace block {}
namespace Physics3D {
    float add(float a, float b, float c) {
        return a + b + c;
    }
}