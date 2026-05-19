#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Abandoned Lock                     =   Occurs when a thread terminates while holding a mutex,
//                                       preventing other threads from ever acquiring it.

// Real-World Impact                  =   Can freeze entire systems if a critical lock is abandoned,
//                                       especially in long-running services.

// Prevention Strategies              =   Use RAII (lock_guard), avoid manual lock/unlock,
//                                       and ensure threads cannot exit while holding locks.

std::mutex mtx;
int shared_value = 0;

void worker_crash() {
    std::lock_guard<std::mutex> guard(mtx);
    shared_value++;
    std::terminate();                                   // simulates crash
}

void worker_wait() {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::cout << "Attempting to lock...\n";
    mtx.lock();                                         // never succeeds
    shared_value++;
    mtx.unlock();
}

int main() {

    std::thread t1(worker_crash);
    std::thread t2(worker_wait);

    t1.join();
    t2.join();

    return 0;
}
