#include <iostream>
#include <thread>
#include <chrono>

// demo = two threads increment the same shared counter
//                      without synchronization
//                      causing a data race

// demo = increment is not atomic
//                      read → modify → write
//                      threads interleave these steps unpredictably

unsigned int shared_counter = 0;

void add_work(const char* name) {
    for (int i = 0; i < 5'000'000; i++) {
        shared_counter++; // unsafe: data race
        if (i % 1'000'000 == 0) {
            std::cout << name << " reached " << i << "\n";
        }
    }
}

int main() {
    std::cout << "Starting data race demo...\n";

    std::thread t1(add_work, "Thread A");
    std::thread t2(add_work, "Thread B");

    t1.join();
    t2.join();

    std::cout << "Final counter value: " << shared_counter << "\n";
    std::cout << "Expected value:      " << 10'000'000 << "\n";

    return 0;
}
