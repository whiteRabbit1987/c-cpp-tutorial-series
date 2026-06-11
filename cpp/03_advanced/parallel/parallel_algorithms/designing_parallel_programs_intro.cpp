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
