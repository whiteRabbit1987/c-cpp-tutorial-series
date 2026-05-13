#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>

// intro = a process is an executing program
//                      has its own memory space
//                      contains one or more threads

// intro = a thread is an independent path of execution
//                      created inside a process
//                      shares memory with other threads
//                      managed by the operating system

// intro = threads allow concurrency
//                      multiple tasks appear to run at once
//                      scheduler rapidly switches between them

// intro = this example shows
//                      process ID vs thread ID
//                      creating threads
//                      joining threads to wait for completion

void cpu_waster() {
    printf("CPU Waster Process ID: %d\n", getpid());
    printf("CPU Waster Thread ID: %zu\n", std::hash<std::thread::id>{}(std::this_thread::get_id()));
    while (true) { /* waste CPU cycles */ }
}

int main() {
    printf("Main Process ID: %d\n", getpid());
    printf("Main Thread ID: %zu\n", std::hash<std::thread::id>{}(std::this_thread::get_id()));

    std::thread t1(cpu_waster);
    std::thread t2(cpu_waster);

    // keep main thread alive
    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
