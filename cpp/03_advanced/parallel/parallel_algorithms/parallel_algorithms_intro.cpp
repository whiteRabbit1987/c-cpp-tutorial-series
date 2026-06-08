#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <boost/asio.hpp>

// Parallel Algorithms Intro          =   Demonstrates basic parallel execution using
//                                       computational graphs, async tasks, thread pools,
//                                       and simple divide-and-conquer.

// Purpose of Intro                   =   Show the simplest examples of:
//                                       - thread pool parallelism
//                                       - futures for async tasks
//                                       - recursive divide-and-conquer

// ------------------------------------------------------------
// THREAD POOL (Boost: C++20 has no std::thread_pool)
// ------------------------------------------------------------

void chop_vegetable(int id) {
    printf("Thread %zu chopped vegetable %d.\n",
           std::hash<std::thread::id>{}(std::this_thread::get_id()), id);
}

void thread_pool_demo() {
    boost::asio::thread_pool pool(4);
    for (int i = 0; i < 10; i++) {
        boost::asio::post(pool, [i] { chop_vegetable(i); });
    }
    pool.join();
}

// ------------------------------------------------------------
// FUTURE / ASYNC
// ------------------------------------------------------------

int count_vegetables() {
    printf("Ripley is counting vegetables...\n");
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return 7;
}

void future_demo() {
    printf("Hicks asks Ripley how many vegetables are in the pantry.\n");
    std::future<int> result =
        std::async(std::launch::async, count_vegetables);
    printf("Hicks continues working...\n");
    printf("Ripley responded with %d.\n", result.get());
}

// ------------------------------------------------------------
// DIVIDE AND CONQUER
// ------------------------------------------------------------

unsigned long long recursive_sum(unsigned int lo,
                                 unsigned int hi,
                                 unsigned int depth = 0)
{
    if (depth > 2) {
        unsigned long long sum = 0;
        for (unsigned long long i = lo; i < hi; i++) sum += i;
        return sum;
    }

    unsigned int mid = (lo + hi) / 2;

    auto left = std::async(std::launch::async,
                           recursive_sum, lo, mid, depth + 1);

    auto right = recursive_sum(mid, hi, depth + 1);

    return left.get() + right;
}

void divide_and_conquer_demo() {
    unsigned long long total = recursive_sum(0, 1000000);
    printf("Total: %llu\n", total);
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------

int main() {

    thread_pool_demo();
    future_demo();
    divide_and_conquer_demo();

    return 0;
}
