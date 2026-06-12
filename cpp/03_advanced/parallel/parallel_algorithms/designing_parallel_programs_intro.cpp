#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>

// Designing Parallel Programs Intro  =   Demonstrates the four stages of parallel program
//                                       design: partitioning, communication, agglomeration,
//                                       and mapping.

// Purpose of Intro                   =   Provide small, simple examples of each concept
//                                       without heavy implementation detail.

// ------------------------------------------------------------
// PARTITIONING (Domain + Functional)
// ------------------------------------------------------------

void frost_cupcake(int id) {
    printf("Frosting cupcake %d\n", id);
}

void partitioning_demo() {
    // Domain decomposition: split cupcakes by index
    for (int i = 0; i < 4; i++) {
        frost_cupcake(i);
    }

    // Functional decomposition: separate tasks
    printf("Mixing batter\n");
    printf("Baking cupcakes\n");
    printf("Decorating cupcakes\n");
}

// ------------------------------------------------------------
// COMMUNICATION (simple shared variable)
// ------------------------------------------------------------

std::mutex mtx;
int rainbow_colors[4];

void color_task(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    std::scoped_lock lock(mtx);
    rainbow_colors[id] = id * 10; // pretend color code
}

void communication_demo() {
    std::thread t1(color_task, 0);
    std::thread t2(color_task, 1);
    t1.join();
    t2.join();
}

// ------------------------------------------------------------
// AGGLOMERATION (combine tasks)
// ------------------------------------------------------------

void frost_block(int start, int end) {
    for (int i = start; i < end; i++) {
        frost_cupcake(i);
    }
}

void agglomeration_demo() {
    // Instead of 12 tiny tasks, combine into 2 larger tasks
    std::thread t1(frost_block, 0, 6);
    std::thread t2(frost_block, 6, 12);
    t1.join();
    t2.join();
}

// ------------------------------------------------------------
// MAPPING (conceptual only)
// ------------------------------------------------------------

void mapping_demo() {
    printf("Mapping tasks to processors (conceptual only)\n");
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------

int main() {

    partitioning_demo();
    communication_demo();
    agglomeration_demo();
    mapping_demo();

    return 0;
}
/**
 * Designing Parallel Programs — Intro
 *
 * This file introduces the four major stages of designing a parallel program:
 *
 *   1. Partitioning       — Break the problem into tasks
 *   2. Communication      — Determine how tasks exchange data
 *   3. Agglomeration      — Combine tasks to reduce overhead
 *   4. Mapping            — Assign tasks to processors
 *
 * These stages form a structured workflow for building scalable,
 * efficient parallel algorithms.
 *
 * This intro demonstrates small, simple examples of each idea.
 */

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <chrono>

// ------------------------------------------------------------
// 1. PARTITIONING (Domain + Functional)
// ------------------------------------------------------------

void chop_item(int id) {
    printf("Chopping item %d\n", id);
}

void partitioning_demo() {
    // Domain decomposition: split data into independent chunks
    std::thread t1(chop_item, 0);
    std::thread t2(chop_item, 1);

    // Functional decomposition: separate stages of work
    printf("Mixing ingredients\n");
    printf("Cooking\n");
    printf("Plating\n");

    t1.join();
    t2.join();
}

// ------------------------------------------------------------
// 2. COMMUNICATION (simple shared state)
// ------------------------------------------------------------

std::mutex mtx;
int shared_values[4];

void communication_task(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::scoped_lock lock(mtx);
    shared_values[id] = id * 10;
}

void communication_demo() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 4; i++) {
        threads.emplace_back(communication_task, i);
    }
    for (auto& t : threads) t.join();
}

// ------------------------------------------------------------
// 3. AGGLOMERATION (combine tasks)
// ------------------------------------------------------------

void process_block(int start, int end) {
    for (int i = start; i < end; i++) {
        printf("Processing item %d\n", i);
    }
}

void agglomeration_demo() {
    // Instead of many tiny tasks → combine into two medium tasks
    std::thread t1(process_block, 0, 5);
    std::thread t2(process_block, 5, 10);
    t1.join();
    t2.join();
}

// ------------------------------------------------------------
// 4. MAPPING (conceptual only)
// ------------------------------------------------------------

void mapping_demo() {
    printf("Mapping tasks to processors (conceptual)\n");
    printf(" - Increase concurrency by separating independent tasks\n");
    printf(" - Improve locality by grouping communicating tasks\n");
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------

int main() {

    partitioning_demo();
    communication_demo();
    agglomeration_demo();
    mapping_demo();

    return 0;
}
