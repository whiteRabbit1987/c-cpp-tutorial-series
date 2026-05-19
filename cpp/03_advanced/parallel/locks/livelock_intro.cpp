#include <iostream>
#include <thread>
#include <atomic>

// Livelock Example                   =   Two threads repeatedly react to each other in a way
//                                       that prevents either from making progress.

// Purpose of Intro                   =   Show the simplest livelock scenario using two flags.

std::atomic<bool> flag_a{false};
std::atomic<bool> flag_b{false};

void polite_a() {
    while (true) {
        flag_a = true;
        if (!flag_b.load()) break;                     // sees other thread active → backs off
        flag_a = false;
    }
    std::cout << "A proceeds.\n";
}

void polite_b() {
    while (true) {
        flag_b = true;
        if (!flag_a.load()) break;
        flag_b = false;
    }
    std::cout << "B proceeds.\n";
}

int main() {

    std::thread t1(polite_a);
    std::thread t2(polite_b);

    t1.join();
    t2.join();

    return 0;
}
