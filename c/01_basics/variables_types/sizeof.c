#include <stdbool.h>
#include <stdio.h>

// sizeof  =   Unary operator that returns the size (in bytes) of a type or variable
//              Helps understand memory layout of data types
//              Essential for learning pointers
//
// size_t  =   Unsigned type that stores sizes of objects in memory
//              Guaranteed to hold the size of the largest possible object
//              Returned by the sizeof operator
//
// Assignment:
// 1. Print sizeof(char)
// 2. Then print sizeof(bool), int, float, double, size_t
// 3. Observe that char and bool are typically 1 byte (8 bits)

int main() {

  // Use %zu for printing sizeof results (size_t type)
  printf("sizeof(char)   = %zu\n", sizeof(char));
  printf("sizeof(bool)   = %zu\n", sizeof(bool));
  printf("sizeof(int)    = %zu\n", sizeof(int));
  printf("sizeof(float)  = %zu\n", sizeof(float));
  printf("sizeof(double) = %zu\n", sizeof(double));
  printf("sizeof(size_t) = %zu\n", sizeof(size_t));

  return 0;
}
