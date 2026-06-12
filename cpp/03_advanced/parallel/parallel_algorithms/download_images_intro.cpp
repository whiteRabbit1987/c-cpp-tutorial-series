/**
 * Image Downloading — Intro
 *
 * This file introduces the idea of downloading multiple items
 * sequentially vs. in parallel.
 *
 * Concepts:
 *   - Sequential loop
 *   - std::async for parallel tasks
 *   - Futures for retrieving results
 *
 * This intro uses a fake "download" to avoid requiring libcurl.
 */

#include <iostream>
#include <thread>
#include <future>
#include <chrono>

size_t fake_download(int id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    return 1000 + id; // pretend bytes
}

size_t sequential_download(int count) {
    size_t total = 0;
    for (int i = 0; i < count; i++) {
        total += fake_download(i);
    }
    return total;
}

size_t parallel_download(int count) {
    std::vector<std::future<size_t>> futures;
    for (int i = 0; i < count; i++) {
        futures.push_back(std::async(std::launch::async, fake_download, i));
    }
    size_t total = 0;
    for (auto& f : futures) total += f.get();
    return total;
}

int main() {
    const int N = 10;

    auto seq = sequential_download(N);
    auto par = parallel_download(N);

    printf("Sequential bytes: %zu\n", seq);
    printf("Parallel bytes:   %zu\n", par);

    return 0;
}
