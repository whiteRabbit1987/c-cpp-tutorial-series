#include <iostream>
#include <shared_mutex>
#include <thread>
#include <chrono>
#include <vector>

// Reader-Writer Lock                 =   Allows concurrent read access but exclusive write access.
//                                       Improves performance when reads dominate writes.

// Shared (Read) Lock                 =   Multiple threads may acquire simultaneously.
//                                       Writers are blocked until all readers release.

// Exclusive (Write) Lock             =   Only one writer allowed. Blocks both readers and writers.

// Use Cases                          =   Caches, configuration data, read-heavy workloads.

// Considerations                     =   More complex than a standard mutex.
//                                       Reader/writer preference varies by implementation.

std::shared_mutex rw_mutex;
int shared_value = 0;

void reader(int id) {
    for (int i = 0; i < 3; i++) {
        rw_mutex.lock_shared();
        std::cout << "Reader " << id << " sees " << shared_value << "\n";
        rw_mutex.unlock_shared();
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
}

void writer(int id) {
    for (int i = 0; i < 2; i++) {
        rw_mutex.lock();
        shared_value++;
        std::cout << "Writer " << id << " updated value to " << shared_value << "\n";
        rw_mutex.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

int main() {

    std::vector<std::thread> threads;

    threads.emplace_back(reader, 1);
    threads.emplace_back(reader, 2);
    threads.emplace_back(writer, 1);

    for (auto& t : threads) t.join();

    return 0;
}
