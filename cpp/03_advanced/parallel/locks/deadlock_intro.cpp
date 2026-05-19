#include <iostream>
#include <thread>
#include <mutex>

// Deadlock Example                   =   Two threads each acquire one mutex and then wait for
//                                       the other mutex, causing both threads to block forever.

// Purpose of Intro                   =   Show the simplest possible deadlock scenario using
//                                       two mutexes and two threads.

std::mutex mtx_a;
std::mutex mtx_b;

void task_one() {
    mtx_a.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    mtx_b.lock();                                     // waits forever
}

void task_two() {
    mtx_b.lock();
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    mtx_a.lock();                                     // waits forever
}

int main() {

    std::thread t1(task_one);
    std::thread t2(task_two);

    t1.join();
    t2.join();

    return 0;
}
