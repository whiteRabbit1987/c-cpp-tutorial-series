#include <iostream>
#include <thread>
#include <chrono>

// overview = threads run concurrently
//                      scheduler time‑slices CPU among runnable threads
//                      rapid switching creates illusion of parallelism

// overview = thread lifecycle
//                      NEW        (constructed but not running)
//                      RUNNABLE   (eligible for CPU scheduling)
//                      BLOCKED    (waiting for I/O or event)
//                      TERMINATED (finished execution)

// overview = join() waits for a thread to finish
//                      detach() lets a thread run independently
//                      joinable() checks if a thread can be joined

// overview = this file demonstrates
//                      thread creation
//                      joinable() state transitions
//                      blocking the main thread until child finishes

void chef_olivia() {
    printf("Olivia started & waiting for sausage to thaw...\n");
    std::this_thread::sleep_for(std::chrono::seconds(3));
    printf("Olivia is done cutting sausage.\n");
}

int main() {
    printf("Barron requests Olivia's help.\n");

    std::thread olivia(chef_olivia);
    printf("  Olivia joinable? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron continues cooking soup...\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    printf("  Olivia joinable? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron waits for Olivia to finish...\n");
    olivia.join();
    printf("  Olivia joinable? %s\n", olivia.joinable() ? "true" : "false");

    printf("Barron and Olivia are both done!\n");
    return 0;
}
