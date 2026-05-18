#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

// Atomic Operations                  =   Guarantee indivisible read‑modify‑write behavior.
//                                       Prevents data races without using a mutex.

// Memory Ordering                    =   Controls how operations on different threads become
//                                       visible to each other. Determines synchronization behavior.

// Sequential Consistency             =   The strongest ordering. All threads observe operations
//                                       in the same order. Easiest to reason about.

// Relaxed Ordering                   =   Allows reordering and weaker visibility guarantees.
//                                       Useful for performance‑critical counters.

// Acquire / Release                  =   Acquire prevents reads/writes from moving before it.
//                                       Release prevents reads/writes from moving after it.
//                                       Together they form a synchronization boundary.

// Demonstration Purpose              =   Show how atomic operations behave with different
//                                       memory orderings and how visibility changes across threads.

std::atomic<bool> ready{false};
std::atomic<int> value{0};

void writer() {
    value.store(42, std::memory_order_relaxed);     // write value (relaxed)
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    ready.store(true, std::memory_order_release);   // publish update
}

void reader() {
    while (!ready.load(std::memory_order_acquire)) {
        // spin until writer publishes
    }
    std::cout << "Reader sees value = " << value.load(std::memory_order_relaxed) << "\n";
}

int main() {

    std::thread t1(writer);
    std::thread t2(reader);

    t1.join();
    t2.join();

    std::cout << "Atomic memory model demonstration complete.\n";
    return 0;
}
