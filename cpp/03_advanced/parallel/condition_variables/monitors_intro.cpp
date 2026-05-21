#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

// Monitor Concept                    =   A structure that bundles shared data, a mutex, and
//                                       condition variables to safely coordinate thread actions.

// Purpose of Intro                   =   Show the simplest monitor-like pattern using a mutex
//                                       and a condition variable to protect a shared queue.

std::mutex mtx;
std::condition_variable cv;
std::queue<int> q;

void producer() {
    std::lock_guard<std::mutex> lock(mtx);
    q.push(42);                                       // shared data update
    cv.notify_one();                                  // signal waiting thread
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [] { return !q.empty(); });         // wait for condition
    int value = q.front();
    q.pop();
    std::cout << "Consumed: " << value << "\n";
}

int main() {

    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
