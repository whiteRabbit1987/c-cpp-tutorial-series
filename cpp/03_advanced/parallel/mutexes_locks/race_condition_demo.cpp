#include <iostream>
#include <thread>
#include <mutex>

// Race Condition Demo                =   Even with a mutex preventing data races, the final
//                                       result depends on thread execution order.

// Purpose of Demo                    =   Show that correct mutual exclusion does NOT guarantee
//                                       correct program logic.

std::mutex mtx;
int chips = 0;

void olivia() {
    std::lock_guard<std::mutex> lock(mtx);
    chips += 3;                                     // add 3 bags
}

void barron() {
    std::lock_guard<std::mutex> lock(mtx);
    chips *= 2;                                     // double chips
}

int main() {

    chips = 1;                                      // starting value

    std::thread t1(olivia);
    std::thread t2(barron);

    t1.join();
    t2.join();

    std::cout << "Final chips: " << chips << "\n";
    return 0;
}
