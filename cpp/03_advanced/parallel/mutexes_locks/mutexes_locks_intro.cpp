#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// Shared Counter                     =   A global variable incremented by multiple threads.
//                                       Without protection, this leads to a data race.

// Mutex (Mutual Exclusion)           =   Ensures only one thread at a time can enter the
//                                       critical section, preventing concurrent modification.

// Critical Section                   =   The increment operation. It must be protected so the
//                                       read → modify → write sequence happens atomically.

// Manual Lock / Unlock               =   lock() acquires the mutex; unlock() releases it.
//                                       This intro uses the simplest form for clarity.

unsigned int shared_counter = 0;
std::mutex counter_mutex;

void counter_func() {

    for (int i = 0; i < 5; i++) {
        printf("This thread is currently thinking id(%d)\n", std::this_thread::get_id());
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        counter_mutex.lock();                               // acquire exclusive access
        shared_counter++;                                   // safe increment (protected)
        counter_mutex.unlock();                             // release access
    }
}

int main() {

    std::thread thread_a(counter_func);
    std::thread thread_b(counter_func);

    thread_a.join();
    thread_b.join();

    printf("We counted %u increments.\n", shared_counter);

    return 0;
}
