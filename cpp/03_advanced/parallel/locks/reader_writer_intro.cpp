#include <iostream>
#include <shared_mutex>
#include <thread>

// Shared Mutex (Reader-Writer)       =   Allows multiple readers OR one writer.
//                                       Readers do not block each other.

// Purpose of Intro                   =   Show the simplest read/write locking pattern.

std::shared_mutex rw_mutex;
int shared_number = 0;

void reader() {
    rw_mutex.lock_shared();                         // read lock
    std::cout << "Read: " << shared_number << "\n";
    rw_mutex.unlock_shared();
}

void writer() {
    rw_mutex.lock();                                // write lock
    shared_number++;
    rw_mutex.unlock();
}

int main() {

    std::thread r1(reader);
    std::thread r2(reader);
    std::thread w(writer);

    r1.join();
    r2.join();
    w.join();

    return 0;
}
