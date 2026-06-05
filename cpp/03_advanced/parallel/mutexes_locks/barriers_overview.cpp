#include <iostream>
#include <thread>
#include <mutex>
#include <barrier>
#include <vector>
#include <chrono>

// Barrier Definition                 =   A synchronization mechanism ensuring that all threads
//                                       reach a specific point before any may proceed.

// Why Barriers Matter                =   They enforce ordering without relying on mutex timing,
//                                       preventing race conditions caused by nondeterministic
//                                       execution order.

// Barrier Hazard                     =   If a thread reaches a barrier WHILE holding a mutex,
//                                       and another thread needs that mutex BEFORE reaching the
//                                       barrier, the entire program deadlocks.

// This file demonstrates BOTH:
//   1) Correct use of barriers
//   2) Incorrect use: barrier + mutex = deadlock

// ------------------------------------------------------------
// CORRECT EXAMPLE (no deadlock)
// ------------------------------------------------------------

int chips_correct = 1;

std::barrier correct_barrier(2);

void ripley_correct() {
    chips_correct += 3;
    correct_barrier.arrive_and_wait();               // safe: no mutex held
}

void hicks_correct() {
    correct_barrier.arrive_and_wait();               // safe: no mutex held
    chips_correct *= 2;
}

// ------------------------------------------------------------
// DEADLOCK EXAMPLE (mutex held before barrier)
// ------------------------------------------------------------

int chips_deadlock = 1;
std::mutex pencil;
std::barrier deadlock_barrier(10);

void cpu_work(unsigned long units) {
    volatile unsigned long x = 0;
    for (unsigned long i = 0; i < units * 1000000; i++) {
        x++;
    }
}

void hicks_deadlock() {
    cpu_work(1);
    deadlock_barrier.arrive_and_wait();              // waits for Ripley
    std::scoped_lock lock(pencil);                   // needs mutex AFTER barrier
    chips_deadlock *= 2;
    std::cout << "Hicks doubled the chips.\n";
}

void ripley_deadlock() {
    cpu_work(1);
    {
        std::scoped_lock lock(pencil);               // holds mutex BEFORE barrier
        chips_deadlock += 3;
    }
    std::cout << "Ripley added 3 chips.\n";
    deadlock_barrier.arrive_and_wait();              // waits for Hicks
    // DEADLOCK:
    // - If Ripley held the mutex while waiting, Hicks could never reach the barrier
    //   because Hicks needs the mutex AFTER the barrier.
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------

int main() {

    // Correct example
    {
        std::thread t1(ripley_correct);
        std::thread t2(hicks_correct);
        t1.join();
        t2.join();
        std::cout << "Correct final chips: " << chips_correct << "\n";
    }

    // Deadlock example
    {
        std::thread shoppers[10];
        for (int i = 0; i < 10; i += 2) {
            shoppers[i] = std::thread(hicks_deadlock);
            shoppers[i + 1] = std::thread(ripley_deadlock);
        }

        for (auto& t : shoppers) {
            t.join();                                // program will hang here
        }

        std::cout << "Deadlock final chips: " << chips_deadlock << "\n";
    }

    return 0;
}
