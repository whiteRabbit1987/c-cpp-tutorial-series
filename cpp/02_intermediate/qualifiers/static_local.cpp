#include <iostream>

// static local variables = retain their value across multiple function calls
//                          lifetime extends for the duration of the program

void generateUniqueID() {
    static int id = 0;
    ++id;
    std::cout << "Generated ID: " << id << std::endl;
}

int main() {
    generateUniqueID();
    generateUniqueID();
    generateUniqueID();
    return 0;
}
