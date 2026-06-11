#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <numeric>

// Designing Parallel Programs        =   Demonstrates the four major stages of parallel
//                                       program design with runnable examples.

// Stages                             =   1. Partitioning
//                                       2. Communication
//                                       3. Agglomeration
//                                       4. Mapping (conceptual)

// ------------------------------------------------------------
// 1. PARTITIONING
// ------------------------------------------------------------
// Domain decomposition: split data into partitions.
// Functional decomposition: split work into separate tasks.

void chop_range(int start, int end) {
    for (int i = start; i < end; i++) {
        printf("Chopping vegetable %d\n", i);
    }
}

void mix_batter() { printf("Mixing batter\n"); }
void bake()       { printf("Baking cupcakes\n"); }
void frost()      { printf("Frosting cupcakes\n"); }

void partitioning_demo() {
    // Domain decomposition
    std::thread t1(chop_range, 0, 5);
    std::thread t2(chop_range, 5, 10);

    // Functional decomposition
    mix_batter();
    bake();
    frost();

    t1.join();
    t2.join();
}

// ------------------------------------------------------------
// 2. COMMUNICATION
// ------------------------------------------------------------
// Demonstrates point-to-point communication via shared state.

std::mutex color_mtx;
int cupcake_colors[6];

void assign_color(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(20));
    std::scoped_lock lock(color_mtx);
    cupcake_colors[id] = id * 100; // pretend color code
}

void communication_demo() {
    std::vector<std::thread> threads;
    for (int i = 0; i < 6; i++) {
        threads.emplace_back(assign_color, i);
    }
    for (auto& t : threads) t.join();
}

// ------------------------------------------------------------
// 3. AGGLOMERATION
// ------------------------------------------------------------
// Combine many small tasks into fewer larger tasks to reduce overhead.

void frost_block(int start, int end) {
    for (int i = start; i < end; i++) {
        printf("Frosting cupcake %d\n", i);
    }
}

void agglomeration_demo() {
    // Instead of 12 tiny tasks → 2 medium tasks
    std::thread t1(frost_block, 0, 6);
    std::thread t2(frost_block, 6, 12);
    t1.join();
    t2.join();
}

// ------------------------------------------------------------
// 4. MAPPING
// ------------------------------------------------------------
// Mapping assigns tasks to processors. This is conceptual in C++ threads.

void mapping_demo() {
    printf("Mapping tasks to processors (conceptual only)\n");
    printf(" - Increase concurrency by placing independent tasks on different cores\n");
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
