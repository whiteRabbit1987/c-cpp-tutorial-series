#include <iostream>
#include <thread>
#include <semaphore>
#include <vector>
#include <chrono>

// Semaphore Definition               =   A synchronization primitive with an internal counter.
//                                       Threads acquire (decrement) and release (increment) the counter.

// Counting Semaphores                =   Allow multiple threads to access a resource pool.
//                                       Block when counter reaches zero.

// Binary Semaphores                  =   Counter is 0 or 1. Similar to a mutex, but any thread
//                                       may release it, making it suitable for signaling.

// Use Cases                          =   Resource pools, rate limiting, producer-consumer pipelines,
//                                       and thread signaling.

std::counting_semaphore<3> sem(3);     // pool of 3 resources
int active_workers = 0;
std::mutex cout_mtx;

void worker(int id) {
    sem.acquire();                     // wait for available slot

    {
        std::lock_guard<std::mutex> lock(cout_mtx);
        active_workers++;
        std::cout << "Worker " << id << " entered (active: " << active_workers << ")\n";
    }

    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    {
        std::lock_guard<std::mutex> lock(cout_mtx);
        active_workers--;
        std::cout << "Worker " << id << " leaving (active: " << active_workers << ")\n";
    }

    sem.release();                     // free slot
}

int main() {

    std::vector<std::thread> threads;

    for (int i = 0; i < 8; i++) {
        threads.emplace_back(worker, i);
    }

    for (auto& t : threads) t.join();

    return 0;
}
