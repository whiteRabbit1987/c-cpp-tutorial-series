#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Deadlock Definition                =   A state where two or more threads wait indefinitely
//                                       for resources held by each other, preventing progress.

// Circular Wait                      =   The key condition for deadlock: each thread holds one
//                                       resource and waits for another held by a different thread.

// Lock Ordering Solution             =   Enforce a consistent lock acquisition order to prevent
//                                       circular wait and guarantee progress.

std::mutex mtx_a;
std::mutex mtx_b;

void safe_task_one() {
    std::lock(mtx_a, mtx_b);                           // acquire both without deadlock
    std::lock_guard<std::mutex> lk1(mtx_a, std::adopt_lock);
    std::lock_guard<std::mutex> lk2(mtx_b, std::adopt_lock);
    std::cout << "Task one completed.\n";
}

void safe_task_two() {
    std::lock(mtx_a, mtx_b);                           // same order → safe
    std::lock_guard<std::mutex> lk1(mtx_a, std::adopt_lock);
    std::lock_guard<std::mutex> lk2(mtx_b, std::adopt_lock);
    std::cout << "Task two completed.\n";
}

int main() {

    std::thread t1(safe_task_one);
    std::thread t2(safe_task_two);

    t1.join();
    t2.join();

    return 0;
}
