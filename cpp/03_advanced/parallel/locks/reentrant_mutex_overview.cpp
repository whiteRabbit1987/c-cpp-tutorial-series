#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Recursive Mutex                    =   Allows the same thread to acquire the mutex multiple times.
//                                       Prevents self-deadlock in nested or recursive calls.

// Internal Lock Count                =   Each lock() increments an internal counter. The mutex is
//                                       only released when unlock() has been called the same number
//                                       of times by the owning thread.

// Use Cases                          =   Nested functions that lock the same resource.
//                                       Recursive algorithms requiring synchronized access.

// Considerations                     =   Can simplify integration of locks into existing code,
//                                       but may hide design issues if overused.

std::recursive_mutex rec_mutex;
int shared_value = 0;

void recursive_add(int depth) {

    rec_mutex.lock();
    std::cout << "Locked at depth " << depth << "\n";

    if (depth > 0) {
        recursive_add(depth - 1);                   // safe repeated locking
    }

    shared_value++;
    rec_mutex.unlock();
}

int main() {

    std::thread t(recursive_add, 3);
    t.join();

    std::cout << "Final value: " << shared_value << "\n";
    return 0;
}
