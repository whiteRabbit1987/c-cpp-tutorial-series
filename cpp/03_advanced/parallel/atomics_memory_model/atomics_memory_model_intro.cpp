#include <iostream>
#include <thread>
#include <atomic>

// Atomic Variable                    =   A type that guarantees safe concurrent access without
//                                       requiring a mutex. Each operation is indivisible.

// Atomic Increment                   =   The ++ operation on std::atomic is performed as a single
//                                       atomic read‑modify‑write step.

// Purpose of Intro                   =   Show the simplest possible use of std::atomic to fix
//                                       a data race without introducing the full memory model.

std::atomic<unsigned int> counter{0};

void increment_func() {
    for (int i = 0; i < 1'000'000; i++) {
        counter++;                                  // atomic increment (safe)
    }
}

int main() {

    std::thread t1(increment_func);
    std::thread t2(increment_func);

    t1.join();
    t2.join();

    std::cout << "Final atomic counter: " << counter.load() << "\n";

    return 0;
}
