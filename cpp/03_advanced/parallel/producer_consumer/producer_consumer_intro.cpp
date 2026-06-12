/**
 * Producer–Consumer Intro
 *
 * The producer–consumer pattern coordinates two types of tasks:
 *   - Producers generate data
 *   - Consumers process data
 *
 * A shared queue connects them.
 * Producers push work into the queue.
 * Consumers pull work out of the queue.
 *
 * This intro demonstrates:
 *   - A simple shared queue
 *   - A mutex + condition_variable
 *   - One producer and one consumer
 */

#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

std::queue<int> work_queue;
std::mutex mtx;
std::condition_variable cv;
bool done = false;

void producer() {
    for (int i = 0; i < 5; i++) {
        {
            std::scoped_lock lock(mtx);
            work_queue.push(i);
            printf("Producer: produced %d\n", i);
        }
        cv.notify_one();
    }

    {
        std::scoped_lock lock(mtx);
        done = true;
    }
    cv.notify_one();
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [] { return !work_queue.empty() || done; });

        if (!work_queue.empty()) {
            int item = work_queue.front();
            work_queue.pop();
            lock.unlock();
            printf("Consumer: consumed %d\n", item);
        }
        else if (done) {
            break;
        }
    }
}

int main() {

    std::thread t1(producer);
    std::thread t2(consumer);

    t1.join();
    t2.join();

    return 0;
}
