#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

// overview = scheduling determines which thread runs at any moment
//                      OS uses time slices (quanta)
//                      runnable threads rotate through CPU access

// overview = factors influencing scheduling
//                      thread priority
//                      CPU availability
//                      blocking on I/O or sleep
//                      number of runnable threads

// overview = this demonstration shows
//                      two threads competing for CPU time
//                      scheduler interleaving their progress
//                      different workloads producing different results

std::atomic<bool> active(true);

void fast_worker() {
    unsigned long ops = 0;
    while (active.load()) {
        ops++; // tight loop, CPU‑bound
    }
    std::cout << "Fast worker ops: " << ops << "\n";
}

void slow_worker() {
    unsigned long ops = 0;
    while (active.load()) {
        ops++;
        if (ops % 5000 == 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(50));
        }
    }
    std::cout << "Slow worker ops: " << ops << "\n";
}

int main() {
    std::thread t1(fast_worker);
    std::thread t2(slow_worker);

    std::this_thread::sleep_for(std::chrono::seconds(1));
    active.store(false);

    t1.join();
    t2.join();

    std::cout << "Scheduling demonstration complete.\n";
    return 0;
}
