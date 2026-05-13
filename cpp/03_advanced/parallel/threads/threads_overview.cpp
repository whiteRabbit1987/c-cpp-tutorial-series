#include <iostream>
#include <thread>
#include <chrono>

// overview = threads run concurrently
//                      OS rapidly switches between runnable threads
//                      creates illusion of parallelism on a single core

// overview = thread lifecycle states
//                      NEW        (constructed, not yet running)
//                      RUNNABLE   (eligible for CPU time)
//                      BLOCKED    (waiting for I/O or event)
//                      TERMINATED (finished execution)

// overview = join() blocks until a thread finishes
//                      detach() allows a thread to run independently
//                      joinable() checks if a thread can be joined

// overview = this demonstration shows
//                      thread creation
//                      joinable() transitions
//                      waiting for a worker thread to finish

void slow_task() {
    printf("Worker: starting long task...\n");
    std::this_thread::sleep_for(std::chrono::seconds(2));
    printf("Worker: task complete.\n");
}

int main() {
    printf("Main: launching worker thread.\n");

    std::thread worker(slow_task);
    printf("  worker joinable? %s\n", worker.joinable() ? "true" : "false");

    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    printf("Main: doing other work...\n");
    printf("  worker joinable? %s\n", worker.joinable() ? "true" : "false");

    printf("Main: waiting for worker to finish.\n");
    worker.join();
    printf("  worker joinable? %s\n", worker.joinable() ? "true" : "false");

    printf("Main: all work complete.\n");
    return 0;
}
