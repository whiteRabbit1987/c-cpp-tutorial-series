#include <iostream>
#include <thread>
#include <mutex>

// try_lock                           =   Attempts to acquire a mutex without blocking.
//                                       Returns true if lock acquired, false otherwise.

// Purpose of Intro                   =   Show the simplest possible non-blocking lock attempt.

std::mutex mtx;
int shared_counter = 0;

void worker() {

    if (mtx.try_lock()) {                           // non-blocking attempt
        shared_counter++;
        mtx.unlock();
    } else {
        std::cout << "Lock busy, doing something else.\n";
    }
}

int main() {

    std::thread t1(worker);
    std::thread t2(worker);

    t1.join();
    t2.join();

    std::cout << "Counter: " << shared_counter << "\n";
    return 0;
}
