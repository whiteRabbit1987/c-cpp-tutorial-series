#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

// Monitor Definition                 =   A synchronization construct that encapsulates shared data,
//                                       a mutex for mutual exclusion, and condition variables for
//                                       waiting and signaling.

// Mutual Exclusion                   =   Only one thread may execute inside the monitor at a time.

// Condition Variables                =   Allow threads to sleep until a condition becomes true,
//                                       avoiding busy-waiting and enabling efficient coordination.

// Typical Use Case                   =   Producer-consumer queues, state machines, and any scenario
//                                       requiring threads to wait for specific conditions.

class MonitorQueue {
public:
    void push(int value) {
        std::lock_guard<std::mutex> lock(mtx_);
        queue_.push(value);
        cv_.notify_one();                             // signal waiting consumer
    }

    int pop() {
        std::unique_lock<std::mutex> lock(mtx_);
        cv_.wait(lock, [&] { return !queue_.empty(); });
        int value = queue_.front();
        queue_.pop();
        return value;
    }

private:
    std::mutex mtx_;
    std::condition_variable cv_;
    std::queue<int> queue_;
};

MonitorQueue mq;

void producer() {
    for (int i = 0; i < 3; i++) {
        mq.push(i);
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void consumer() {
    for (int i = 0; i < 3; i++) {
        int v = mq.pop();
        std::cout << "Consumed: " << v << "\n";
    }
}

int main() {

    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
