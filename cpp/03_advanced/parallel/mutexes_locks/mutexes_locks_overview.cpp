#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Critical Section                  =   Code that accesses shared data. If executed by multiple threads
//                                      simultaneously, it can cause corruption or inconsistent results.

// Mutex Purpose                     =   Ensures only one thread enters the critical section at a time,
//                                      enforcing mutual exclusion and preventing data races.

// Thread Blocking                   =   When a thread attempts to lock a mutex already held by another
//                                      thread, it blocks until the mutex becomes available.

// lock_guard                        =   A safe RAII mechanism that locks a mutex upon creation and
//                                      unlocks it automatically when the scope ends.

// Correctness Guarantee             =   By serializing access to shared_value, each update becomes
//                                      atomic and deterministic.

unsigned int shared_value = 0;
std::mutex value_lock;

void safe_increment(const char* name, int pause_ms) {
    for (int i = 0; i < 3; i++) {

        std::cout << name << " attempting to lock...\n";

        {
            std::lock_guard<std::mutex> guard(value_lock);
            std::cout << name << " acquired lock\n";

            unsigned int temp = shared_value;
            std::this_thread::sleep_for(std::chrono::milliseconds(pause_ms));
            shared_value = temp + 1;

            std::cout << name << " updated value to " << shared_value << "\n";
        }

        std::cout << name << " released lock\n";
    }
}

int main() {
    std::cout << "Mutex overview demonstration\n";

    std::thread t1(safe_increment, "Worker A", 50);
    std::thread t2(safe_increment, "Worker B", 20);

    t1.join();
    t2.join();

    std::cout << "Final shared value: " << shared_value << "\n";
    return 0;
}
