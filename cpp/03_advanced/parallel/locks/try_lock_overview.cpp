#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// try_lock                           =   Non-blocking lock attempt. Returns immediately.
//                                       Useful when threads have alternative work to perform.

// Behavior                           =   true  → lock acquired
//                                       false → lock busy, thread continues without waiting

// Efficiency Benefit                 =   Prevents threads from wasting time blocked on a mutex.
//                                       Ideal when tasks are independent or optional.

// Use Cases                          =   Work-stealing loops, periodic tasks, background updates.

std::mutex mtx;
int shared_value = 0;

void worker(const char* name) {

    for (int i = 0; i < 5; i++) {

        if (mtx.try_lock()) {
            shared_value++;
            std::cout << name << " acquired lock\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(20));
            mtx.unlock();
        } else {
            std::cout << name << " could not lock, doing other work\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

int main() {

    std::thread a(worker, "A");
    std::thread b(worker, "B");

    a.join();
    b.join();

    std::cout << "Final value: " << shared_value << "\n";
    return 0;
}
