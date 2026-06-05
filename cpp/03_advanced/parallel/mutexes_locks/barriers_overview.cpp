#include <iostream>
#include <thread>
#include <barrier>
#include <vector>
#include <chrono>

// Barrier Definition                 =   A synchronization mechanism ensuring that all threads
//                                       reach a specific point before any may proceed.

// Why Barriers Matter                =   They enforce ordering without relying on mutex timing,
//                                       preventing race conditions caused by nondeterministic
//                                       execution order.

// Completion Function                =   Optional callback executed once per phase when all
//                                       threads arrive.

int chips = 1;

std::barrier sync_point(2, [] {
    // This runs once when both threads reach the barrier.
    std::cout << "Both threads reached the barrier.\n";
});

void olivia() {
    chips += 3;
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    sync_point.arrive_and_wait();
}

void barron() {
    sync_point.arrive_and_wait();
    chips *= 2;
}

int main() {

    std::thread t1(olivia);
    std::thread t2(barron);

    t1.join();
    t2.join();

    std::cout << "Final chips: " << chips << "\n";
    return 0;
}
