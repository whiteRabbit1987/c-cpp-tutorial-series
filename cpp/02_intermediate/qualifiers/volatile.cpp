#include <iostream>

// volatile variables    = value may change unexpectedly (hardware/multithreading)
//                         compiler will not optimize accesses, ensuring each read/write occurs

int main() {
    volatile int enemyStatus = 0;

    std::cout << "Initial enemy status: " << enemyStatus << std::endl;

    enemyStatus = 5; // Simulate hardware/multithreaded change
    std::cout << "Updated enemy status: " << enemyStatus << std::endl;

    return 0;
}
