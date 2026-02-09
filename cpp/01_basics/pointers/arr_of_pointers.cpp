#include <iostream>

// Array of Pointers (ptrarr)   =   A dynamically allocated array designed to hold the addresses
//                                  of the starting elements of each row of a 2D array. It is of type int**.
//                                  The outer dimension (rows) is allocated first.

// Dynamic Rows (Row Pointers)  =   Each element in 'ptrarr' is a pointer that points to a separate,
//                                  dynamically allocated 1D array, representing a single row (columns).
//                                  This allows the final array to be fully dynamic (both rows and cols).

// Deallocation (delete[])      =   Must be done in reverse order: first delete all the inner arrays (rows),
//                                  then delete the outer array of pointers (ptrarr) to prevent memory leaks.

int main() {
    
    // The number of rows and columns are determined at runtime.
    int rows = 3;
    int cols = 4;
    int count = 1;

    // First, declare and allocate the array of pointers (the rows).
    // The type is int** (pointer to a pointer to an int).
    int **ptrarr = new int*[rows];

    // Second, allocate the memory for each row (the columns) separately.
    for (int r = 0; r < rows; r++) {
        // Each element of ptrarr points to a new 1D array of size 'cols'
        ptrarr[r] = new int[cols];
    }
    
    // --- Data Initialization and Access ---

    // Populate the array using the clean ptrarr[r][c] notation
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            ptrarr[r][c] = count++;
        }
    }

    // Output the array contents
    std::cout << "Dynamic 2D Array (" << rows << "x" << cols << "):\n";
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            std::cout << ptrarr[r][c] << "\t";
        }
        std::cout << "\n";
    }

    // --- Deallocation (Crucial for memory management) ---

    // 1. Delete the memory for each individual row (the inner arrays)
    for (int r = 0; r < rows; r++) {
        delete[] ptrarr[r];
    }

    // 2. Delete the memory for the array of pointers (the outer array)
    delete[] ptrarr;
    ptrarr = nullptr; // Good practice to set pointer to null after deletion

    return 0;
}