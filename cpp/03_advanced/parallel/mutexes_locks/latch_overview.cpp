#include <iostream>
#include <thread>
#include <latch>
#include <vector>
#include <chrono>

// Latch Definition                   =   A one-shot synchronization primitive. Threads wait
//                                       until the latch count reaches zero.

// Latch vs Barrier                   =   Latch is one-time only.
//                                       Barrier can be reused for multiple phases.

// Use Cases                          =   Startup synchronization, ensuring all workers wait
//                                       for initialization to complete.

std::latch start_signal(1);
std::latch done_signal(3);

void worker(int id) {
    start_signal.wait();                            // wait for main thread
    std::cout << "Worker " << id << " running\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(30));
    done_signal.count_down();                       // signal completion
}

int main() {

    std::vector<std::thread> threads;
    for (int i = 0; i < 3; i++) {
        threads.emplace_back(worker, i);
    }

    std::cout << "Main preparing...\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    start_signal.count_down();                      // release all workers
    done_signal.wait();                             // wait for all workers

    for (auto& t : threads) t.join();

    std::cout << "All workers finished.\n";
    return 0;
}
