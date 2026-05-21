#include <iostream>
#include <thread>
#include <semaphore>

// Semaphore Intro                    =   A counter-based synchronization primitive that allows
//                                       multiple threads to access a resource simultaneously.

// Purpose of Intro                   =   Show a simple counting semaphore controlling access
//                                       to a limited resource.

std::counting_semaphore<2> sem(2);    // two available permits
int shared_counter = 0;

void worker() {
    sem.acquire();                     // decrement counter, may block
    shared_counter++;
    sem.release();                     // increment counter
}

int main() {

    std::thread t1(worker);
    std::thread t2(worker);
    std::thread t3(worker);

    t1.join();
    t2.join();
    t3.join();

    std::cout << "Final count: " << shared_counter << "\n";
    return 0;
}
