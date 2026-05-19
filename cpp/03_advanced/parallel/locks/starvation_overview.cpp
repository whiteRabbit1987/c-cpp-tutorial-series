#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Starvation Definition              =   A thread is perpetually denied access to a resource,
//                                       preventing it from making progress.

// Priority Scheduling                =   High-priority threads may run more often, starving
//                                       lower-priority threads.

// Fairness Mechanisms                =   Some mutex implementations provide fairness guarantees
//                                       to prevent starvation.

std::mutex mtx;
int shared_value = 0;

void high_priority() {
    for (int i = 0; i < 50; i++) {
        mtx.lock();
        shared_value++;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
        mtx.unlock();
    }
}

void low_priority() {
    for (int i = 0; i < 50; i++) {
        if (mtx.try_lock()) {
            shared_value++;
            mtx.unlock();
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(1));
        }
    }
}

int main() {

    std::thread t1(high_priority);
    std::thread t2(low_priority);

    t1.join();
    t2.join();

    std::cout << "Final value: " << shared_value << "\n";
    return 0;
}
