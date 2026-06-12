/**
 * Tasks Intro
 *
 * This file introduces the idea of tasks in parallel programming.
 * A task represents a unit of work that can be executed independently.
 *
 * Key Ideas:
 *  - A task is NOT a thread. A thread is a mechanism; a task is work.
 *  - Tasks can be scheduled on threads, thread pools, or executors.
 *  - Tasks allow flexible decomposition of a problem.
 *
 * This intro demonstrates:
 *  - Creating small independent tasks
 *  - Running them in parallel using std::thread
 */

#include <iostream>
#include <thread>
#include <vector>

void simple_task(int id) {
    printf("Task %d running on thread %zu\n",
           id,
           std::hash<std::thread::id>{}(std::this_thread::get_id()));
}

int main() {

    std::vector<std::thread> workers;

    // Create 4 simple tasks
    for (int i = 0; i < 4; i++) {
        workers.emplace_back(simple_task, i);
    }

    for (auto& t : workers) {
        t.join();
    }

    return 0;
}
