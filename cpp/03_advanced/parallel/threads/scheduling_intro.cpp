#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

// intro = the OS scheduler decides which thread runs next
//                      runnable threads rotate through CPU time slices
//                      switching is fast enough to appear simultaneous

// intro = thread lifecycle states demonstrated here
//                      NEW        (thread object created)
//                      RUNNABLE   (eligible for CPU scheduling)
//                      BLOCKED    (sleeping or waiting)
//                      TERMINATED (finished execution)

// intro = this example prints visible transitions
//                      shows scheduler interleaving
//                      shows joinable() state changes

std::atomic<bool> active(true);

void worker_task(const char* name, int pause_ms) {
    std::cout << name << " → RUNNABLE\n";

    unsigned long ops = 0;
    while (active.load()) {
        ops++;

        // simulate occasional blocking
        if (ops % 500000 == 0) {
            std::cout << name << " → BLOCKED (sleep)\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(pause_ms));
            std::cout << name << " → RUNNABLE (woke up)\n";
        }
    }

    std::cout << name << " → TERMINATED, ops=" << ops << "\n";
}

int main() {
    std::cout << "Main: creating threads (NEW)\n";

    std::thread t1(worker_task, "Worker A", 2);
    std::thread t2(worker_task, "Worker B", 5);

    std::cout << "  t1 joinable? " << (t1.joinable() ? "true" : "false") << "\n";
    std::cout << "  t2 joinable? " << (t2.joinable() ? "true" : "false") << "\n";

    std::cout << "Main: letting scheduler run threads...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Main: stopping workers\n";
    active.store(false);

    std::cout << "Main: waiting for threads to finish (join)\n";
    t1.join();
    t2.join();

    std::cout << "  t1 joinable? " << (t1.joinable() ? "false" : "false") << "\n";
    std::cout << "  t2 joinable? " << (t2.joinable() ? "false" : "false") << "\n";

    std::cout << "Main: all threads terminated\n";
    return 0;
}
