#include <iostream>
#include <thread>
#include <mutex>

// Abandoned Lock                     =   A thread acquires a mutex and exits before releasing it,
//                                       leaving other threads blocked forever.

// Purpose of Intro                   =   Show how a thread terminating early can cause a lock
//                                       to remain held indefinitely.

std::mutex mtx;
int shared_value = 0;

void bad_worker() {
    mtx.lock();
    shared_value++;
    return;                                            // exits without unlock()
}

void waiting_worker() {
    mtx.lock();                                        // waits forever
    shared_value++;
    mtx.unlock();
}

int main() {

    std::thread t1(bad_worker);
    std::thread t2(waiting_worker);

    t1.join();
    t2.join();

    return 0;
}
