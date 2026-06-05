#include <iostream>
#include <thread>
#include <barrier>

// Barrier Intro                      =   A synchronization point where threads wait until all
//                                       participating threads have arrived.

// Purpose of Intro                   =   Show two threads meeting at a barrier before continuing.

std::barrier sync_point(2);

int chips = 1;

void olivia() {
    chips += 3;                                     // add chips
    sync_point.arrive_and_wait();                   // wait for Barron
}

void barron() {
    sync_point.arrive_and_wait();                   // wait for Olivia
    chips *= 2;                                     // double chips
}

int main() {

    std::thread t1(olivia);
    std::thread t2(barron);

    t1.join();
    t2.join();

    std::cout << "Final chips: " << chips << "\n";
    return 0;
}
