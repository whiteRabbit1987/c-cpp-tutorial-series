#include <iostream>
#include <thread>
#include <mutex>

// Starvation Example                 =   One thread repeatedly acquires a mutex, preventing
//                                       another thread from ever making progress.

// Purpose of Intro                   =   Show a simple scenario where a "greedy" thread
//                                       starves another thread.

std::mutex mtx;
int shared_value = 0;

void greedy() {
    for (int i = 0; i < 100000; i++) {
        mtx.lock();
        shared_value++;
        mtx.unlock();
    }
}

void starving() {
    for (int i = 0; i < 100000; i++) {
        if (mtx.try_lock()) {
            shared_value++;
            mtx.unlock();
        }
    }
}

int main() {

    std::thread t1(greedy);
    std::thread t2(starving);

    t1.join();
    t2.join();

    std::cout << "Final value: " << shared_value << "\n";
    return 0;
}
