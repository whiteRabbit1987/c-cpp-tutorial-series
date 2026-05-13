#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

// intro = a process is an executing program
//                      owns its own virtual address space
//                      contains one or more threads of execution

// intro = a thread is an independent execution path
//                      created inside a process
//                      shares memory with other threads
//                      scheduled by the operating system

// intro = this example demonstrates
//                      process ID vs thread ID
//                      creating threads
//                      observing concurrent execution

void busy_worker() {
    printf("Worker running in process %d\n", getpid());
    printf("Worker thread ID: %zu\n",
           std::hash<std::thread::id>{}(std::this_thread::get_id()));

    // simulate CPU‑bound work
    while (true) { /* burn cycles */ }
}

int main() {
    printf("Main process ID: %d\n", getpid());
    printf("Main thread ID: %zu\n",
           std::hash<std::thread::id>{}(std::this_thread::get_id()));

    std::thread w1(busy_worker);
    std::thread w2(busy_worker);

    // keep main alive while workers run
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
