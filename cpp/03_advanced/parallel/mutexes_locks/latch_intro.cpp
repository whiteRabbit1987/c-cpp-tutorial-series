#include <iostream>
#include <thread>
#include <latch>

// Latch Intro                        =   A latch allows threads to wait until a counter reaches
//                                       zero. Unlike a barrier, it cannot be reused.

// Purpose of Intro                   =   Show a simple one-time synchronization point.

std::latch ready(1);
int value = 0;

void worker() {
    ready.wait();                                   // wait for main thread
    value = 42;
}

int main() {

    std::thread t(worker);

    // simulate setup work
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    ready.count_down();                             // release worker

    t.join();

    std::cout << "Value: " << value << "\n";
    return 0;
}
