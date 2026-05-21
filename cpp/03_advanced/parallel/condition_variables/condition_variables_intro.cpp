#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

// Condition Variable                 =   Allows a thread to wait (sleep) until a specific
//                                       condition becomes true, avoiding busy-waiting.

// Purpose of Intro                   =   Show the simplest producer/consumer example using
//                                       one mutex and one condition variable.

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void producer() {
    std::lock_guard<std::mutex> lock(mtx);
    ready = true;                                   // update shared state
    cv.notify_one();                                // wake waiting thread
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return ready; });            // wait until condition is true
    std::cout << "Condition met.\n";
}

int main() {

    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
