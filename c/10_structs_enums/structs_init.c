#include <stdio.h>

// structs      =   User-defined data type that groups related variables
//                  Allows bundling multiple values into one logical unit
//
// initializer  =   Syntax used to create and assign values to a struct
//                  Designated initializer (.field = value) is clearer and safer
//
// designated   =   Uses field names during initialization
//                  Order does NOT matter
//                  Easier to maintain if struct changes

// Define a struct type
struct Coordinate {
    int x;
    int y;
    int z;
};

// function     =   Returns a struct using designated initializer
//                  Cleaner and avoids ordering mistakes
struct Coordinate new_coord(int x, int y, int z) {

    return (struct Coordinate){
        .x = x,
        .y = y,
        .z = z
    };
}

int main() {

    // create instance using function
    struct Coordinate point1 = new_coord(10, 20, 30);

    // access fields using dot operator
    printf("X: %d\n", point1.x);
    printf("Y: %d\n", point1.y);
    printf("Z: %d\n", point1.z);

    // practice: manual designated initializer
    struct Coordinate point2 = {
        .x = -5,
        .y = 15,
        .z = 0
    };

    printf("\nSecond Coordinate:\n");
    printf("X: %d, Y: %d, Z: %d\n", point2.x, point2.y, point2.z);

    return 0;
}
