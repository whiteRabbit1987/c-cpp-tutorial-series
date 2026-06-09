#include <iostream>
#include <chrono>
#include <thread>

// Speedup & Efficiency Demo          =   Measures sequential vs. parallel execution time,
//                                       then computes speedup and efficiency.

// Purpose of Demo                    =   Show how to empirically evaluate parallel performance.

unsigned long long sum_range(unsigned long long lo,
                             unsigned long long hi)
{
    unsigned long long sum = 0;
    for (unsigned long long i = lo; i < hi; i++) {
        sum += i;
    }
    return sum;
}

int main() {

    const unsigned long long N = 300'000'000;

    // Sequential
    auto t1 = std::chrono::high_resolution_clock::now();
    auto seq = sum_range(0, N);
    auto t2 = std::chrono::high_resolution_clock::now();

    double seq_time =
        std::chrono::duration<double>(t2 - t1).count();

    // Parallel (2 threads)
    auto t3 = std::chrono::high_resolution_clock::now();

    unsigned long long left = 0, right = 0;

    std::thread t_left([&] { left = sum_range(0, N/2); });
    std::thread t_right([&] { right = sum_range(N/2, N); });

    t_left.join();
    t_right.join();

    auto t4 = std::chrono::high_resolution_clock::now();

    double par_time =
        std::chrono::duration<double>(t4 - t3).count();

    double speedup = seq_time / par_time;
    double efficiency = speedup / 2.0;

    std::cout << "Sequential time: " << seq_time << "s\n";
    std::cout << "Parallel time:   " << par_time << "s\n";
    std::cout << "Speedup:         " << speedup << "\n";
    std::cout << "Efficiency:      " << efficiency * 100.0 << "%\n";

    return 0;
}
