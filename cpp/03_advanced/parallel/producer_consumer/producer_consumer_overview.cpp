/**
 * Producer–Consumer Overview
 *
 * The producer–consumer pattern is a classic concurrency design used
 * when one group of tasks generates work and another group processes it.
 *
 * Key Concepts:
 *  - Producers create items and push them into a shared queue.
 *  - Consumers remove items and process them.
 *  - A mutex protects the queue.
 *  - A condition_variable signals when new work is available.
 *
 * This overview demonstrates:
 *  - Multiple producers
 *  - Multiple consumers
 *  - Proper shutdown signaling
 *  - Safe queue access
 */

#include <iostream>
#include <thread>
#include <vector>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

std::queue<int> job_queue;
std::mutex queue_mtx;
std::condition_variable queue_cv;

bool producers_done = false;

void producer(int id, int count) {
    for (int i = 0; i < count; i++) {
        {
            std::scoped_lock lock(queue_mtx);
            job_queue.push(i + id * 100);
            printf("Producer %d: produced %d\n", id, i + id * 100);
        }
        queue_cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

void consumer(int id) {
    while (true) {
        std::unique_lock<std::mutex> lock(queue_mtx);

        queue_cv.wait(lock, [] {
            return !job_queue.empty() || producers_done;
        });

        if (!job_queue.empty()) {
            int item = job_queue.front();
            job_queue.pop();
            lock.unlock();
            printf("Consumer %d: processed %d\n", id, item);
        }
        else if (producers_done) {
            break;
        }
    }
}

int main() {

    const int NUM_PRODUCERS = 2;
    const int NUM_CONSUMERS = 3;
    const int ITEMS_PER_PRODUCER = 5;

    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    // Start producers
    for (int i = 0; i < NUM_PRODUCERS; i++) {
        producers.emplace_back(producer, i, ITEMS_PER_PRODUCER);
    }

    // Start consumers
    for (int i = 0; i < NUM_CONSUMERS; i++) {
        consumers.emplace_back(consumer, i);
    }

    // Wait for producers
    for (auto& p : producers) p.join();

    // Signal shutdown
    {
        std::scoped_lock lock(queue_mtx);
        producers_done = true;
    }
    queue_cv.notify_all();

    // Wait for consumers
    for (auto& c : consumers) c.join();

    return 0;
}
