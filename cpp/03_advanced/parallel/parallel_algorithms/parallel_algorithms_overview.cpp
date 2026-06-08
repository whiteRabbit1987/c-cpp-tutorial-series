#include <iostream>
#include <future>
#include <thread>
#include <chrono>
#include <boost/asio.hpp>

// Parallel Algorithms Overview       =   Demonstrates computational graphs, async tasks,
//                                       thread pools, futures, and divide-and-conquer
//                                       using modern C++20 + Boost where required.

// ------------------------------------------------------------
// COMPUTATIONAL GRAPHS
// ------------------------------------------------------------
// A computational graph models tasks and dependencies.
// Nodes = tasks, edges = dependencies.
// Parallel tasks spawn asynchronously; sync nodes join them.

void chop_lettuce() {
    printf("Ripley chopped lettuce.\n");
}

void chop_tomatoes() {
    printf("Hicks chopped tomatoes.\n");
}

void mix_salad() {
    printf("Ingredients mixed.\n");
}

void computational_graph_demo() {
    auto t1 = std::async(std::launch::async, chop_lettuce);
    auto t2 = std::async(std::launch::async, chop_tomatoes);

    t1.get();
    t2.get();

    mix_salad();
}

// ------------------------------------------------------------
// THREAD POOLS (Boost)
// ------------------------------------------------------------

void chop_item(int id) {
    printf("Thread %zu chopped item %d.\n",
           std::hash<std::thread::id>{}(std::this_thread::get_id()), id);
}

void thread_pool_demo() {
    boost::asio::thread_pool pool(4);

    for (int i = 0; i < 20; i++) {
        boost::asio::post(pool, [i] { chop_item(i); });
    }

    pool.join();
}

// ------------------------------------------------------------
// FUTURES / ASYNC
// ------------------------------------------------------------

int count_items() {
    printf("Ripley is counting items...\n");
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return 42;
}

void future_demo() {
    printf("Hicks asks Ripley for a count.\n");

    std::future<int> result =
        std::async(std::launch::async, count_items);

    printf("Hicks continues working...\n");

    printf("Ripley responded with %d.\n", result.get());
}

// ------------------------------------------------------------
// DIVIDE AND CONQUER
// ------------------------------------------------------------

unsigned long long parallel_sum(unsigned int lo,
                                unsigned int hi,
                                unsigned int depth = 0)
{
    if (depth > 3) {
        unsigned long long sum = 0;
        for (unsigned long long i = lo; i < hi; i++) sum += i;
        return sum;
    }

    unsigned int mid = (lo + hi) / 2;

    auto left = std::async(std::launch::async,
                           parallel_sum, lo, mid, depth + 1);

    auto right = parallel_sum(mid, hi, depth + 1);

    return left.get() + right;
}

void divide_and_conquer_demo() {
    unsigned long long total = parallel_sum(0, 100000000);
    printf("Total: %llu\n", total);
}

// ------------------------------------------------------------
// MAIN
// ------------------------------------------------------------

int main() {

    computational_graph_demo();
    thread_pool_demo();
    future_demo();
    divide_and_conquer_demo();

    return 0;
}
