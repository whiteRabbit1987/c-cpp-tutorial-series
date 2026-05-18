#include <iostream>
#include <thread>
#include <mutex>

// Recursive Mutex                    =   A mutex that allows the same thread to lock it multiple
//                                       times without deadlocking. Tracks internal lock count.

// Purpose of Intro                   =   Show the simplest possible use of std::recursive_mutex
//                                       to prevent self-deadlock in nested calls.

std::recursive_mutex rec_mutex;
int shared_value = 0;

void inner() {
    rec_mutex.lock();
    shared_value++;
    rec_mutex.unlock();
}

void outer() {
    rec_mutex.lock();
    inner();                                        // safe: same thread locks again
    rec_mutex.unlock();
}

int main() {

    std::thread t(outer);
    t.join();

    std::cout << "Final value: " << shared_value << "\n";
    return 0;
}
