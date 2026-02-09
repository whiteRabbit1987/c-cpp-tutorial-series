#ifndef MATHFUNCTIONS_H
#define MATHFUNCTIONS_H

// Namespaces                =   Used to group related declarations and definitions under a unique name, 
//                               preventing naming conflicts with identical names in other code libraries.

// Geometry2D Namespace      =   Holds functions related to 2-dimensional geometry.
//                               Contains a function named 'add' for simple vector addition.

// Physics3D Namespace       =   Holds functions related to 3-dimensional physics simulation.
//                               Contains a function named 'add' for 3D vector addition.

namespace Geometry2D {
    // Function to add two integers (e.g., for 2D coordinates)
    int add(int a, int b); 
}

namespace Physics3D {
    // Function to add three floats (e.g., for 3D coordinates)
    float add(float a, float b, float c);
}

#endif // MATHFUNCTIONS_H