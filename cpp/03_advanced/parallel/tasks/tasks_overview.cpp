/**
 * Tasks Overview
 *
 * This file provides a deeper look at tasks in parallel programming.
 *
 * A task is a logical unit of work. It may be:
 *   - A function
 *   - A lambda
 *   - A block of computation
 *
 * Tasks are the foundation of:
 *   - Parallel algorithms
 *   - Thread pools
 *   - Futures and async operations
 *   - Divide-and-conquer strategies
 *
 * Concepts Demonstrated:
 *   1. Independent tasks
 *   2. Interdependent tasks
 *   3. Task granularity
 *   4. Task scheduling on threads
 */

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

// ------------------------------------------------------------
// 1. Independent Tasks
// ------------------------------------------------------------

void independent_task(int id) {
    printf("Independent task %d completed.\n", id);
}

void run_independent_tasks() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.emplace_back(independent_task, i);
    }
    for (auto& t : threads) t.join();
}

// ------------------------------------------------------------
// 2. Interdependent Tasks (simple shared state)
// ------------------------------------------------------------

std::mutex mtx;
int shared_values[4];

void interdependent_task(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::scoped_lock lock(mtx);
    shared_values[id] = id * 10;
}

void run_interdependent_tasks() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.emplace_back(interdependent_task, i);
    }
    for (auto& t : threads) t.join();
}

// ------------------------------------------------------------
// 3. Task Granularity
// ------------------------------------------------------------

void fine_task(int id) {
    printf("Fine-grained task %d\n", id);
}

void coarse_task(int start, int end) {
    for (int i = start; i < end; i++) {
        printf("Coarse task processing item %d\n", i);
    }
}

void run_granularity_demo() {
    // Fine-grained: many tiny tasks
    for (int i = 0; i < 8; i++) {
        std::thread(fine_task, i).join();
    }

    // Coarse-grained: fewer, larger tasks
    std::thread t1(coarse_task, 0, 4);
    std::thread t2(coarse_task, 4, 8);
    t1.join();
    t2.join();
}

// ------------------------------------------------------------
// 4. Task Scheduling
// ------------------------------------------------------------

void scheduled_task(int id) {
    printf("Scheduled task %d running on thread %zu\n",
           id,
           std::hash<std::thread::id>{}(std::this_thread::get_id()));
}

void run_scheduling_demo() {
    unsigned int num_threads = std::thread::hardware_concurrency();
    if (num_threads == 0) num_threads = 2;

    std::vector<std::thread> workers;
    workers.reserve(num_threads);

    for (unsigned int i = 0; i < num_threads; i++) {
        workers.emplace_back(scheduled_task, i);
    }

    for (auto& t : workers) t.join();
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------

int main() {

    run_independent_tasks();
    run_interdependent_tasks();
    run_granularity_demo();
    run_scheduling_demo();

    return 0;
}
