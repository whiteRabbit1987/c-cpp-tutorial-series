#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <chrono>

// Condition Variable                 =   A synchronization primitive that allows threads to
//                                       wait efficiently for a condition to become true.

// Why They Matter                    =   Avoid busy-waiting, reduce CPU usage, and enable
//                                       coordinated thread behavior (producer/consumer, state machines).

// Monitor Pattern                    =   A mutex + condition variable + shared data.
//                                       Ensures mutual exclusion and controlled waiting.

// Typical Use Case                   =   Producer-consumer queues, bounded buffers, event signaling.

class BoundedQueue {
public:
    void push(int value) {
        std::unique_lock<std::mutex> lock(mtx_);

        not_full_.wait(lock, [&] { return queue_.size() < max_size_; });

        queue_.push(value);
        not_empty_.notify_one();                    // signal consumer
    }

    int pop() {
        std::unique_lock<std::mutex> lock(mtx_);

        not_empty_.wait(lock, [&] { return !queue_.empty(); });

        int value = queue_.front();
        queue_.pop();
        not_full_.notify_one();                     // signal producer
        return value;
    }

private:
    std::mutex mtx_;
    std::condition_variable not_empty_;
    std::condition_variable not_full_;
    std::queue<int> queue_;
    const size_t max_size_ = 3;
};

BoundedQueue bq;

void producer() {
    for (int i = 0; i < 5; i++) {
        bq.push(i);
        std::cout << "Produced: " << i << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void consumer() {
    for (int i = 0; i < 5; i++) {
        int v = bq.pop();
        std::cout << "Consumed: " << v << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
}

int main() {

    std::thread t1(consumer);
    std::thread t2(producer);

    t1.join();
    t2.join();

    return 0;
}
