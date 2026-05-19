#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>

// Livelock Definition                =   Threads remain active but continuously interfere with
//                                       each other, preventing progress.

// Deadlock vs Livelock               =   Deadlock → threads blocked.
//                                       Livelock → threads active but stuck in a loop.

// Prevention Strategies              =   Random backoff, priority assignment, or ensuring only
//                                       one thread attempts conflict resolution.

std::atomic<bool> flag_a{false};
std::atomic<bool> flag_b{false};

void polite_worker(const char* name, std::atomic<bool>& self, std::atomic<bool>& other) {
    for (int i = 0; i < 10; i++) {
        self = true;
        if (!other.load()) {
            std::cout << name << " proceeds.\n";
            return;
        }
        std::cout << name << " backs off.\n";
        self = false;
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

int main() {

    std::thread t1(polite_worker, "A", std::ref(flag_a), std::ref(flag_b));
    std::thread t2(polite_worker, "B", std::ref(flag_b), std::ref(flag_a));

    t1.join();
    t2.join();

    return 0;
}
