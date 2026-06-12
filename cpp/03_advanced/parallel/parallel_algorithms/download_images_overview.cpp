/**
 * Image Downloading — Overview
 *
 * This file demonstrates:
 *
 *   - Sequential downloading of N images
 *   - Parallel downloading using std::async
 *   - Futures for retrieving results
 *   - Benchmarking sequential vs. parallel performance
 *
 * Based directly on the provided solution file.
 */

#include <thread>
#include <cstring>
#include <curl/curl.h>
#include <future>
#include <list>
#include <chrono>
#include <cstdio>

size_t download_image(int image_num);
size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp);

size_t sequential_image_downloader(int num_images) {
    size_t total = 0;
    for (int i = 1; i <= num_images; i++) {
        total += download_image(i);
    }
    return total;
}

size_t parallel_image_downloader(int num_images) {
    size_t total = 0;
    std::list<std::future<size_t>> futures;

    for (int i = 1; i <= num_images; i++) {
        futures.push_back(std::async(std::launch::async, download_image, i));
    }
    for (auto& f : futures) total += f.get();

    return total;
}

size_t download_image(int image_num) {
    char url[128];
    sprintf(url, "http://699340.youcanlearnit.net/image%03d.jpg",
            ((image_num % 50) + 1));

    CURL* curl = curl_easy_init();
    curl_off_t bytes = 0;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
        curl_easy_perform(curl);
        curl_easy_getinfo(curl, CURLINFO_SIZE_DOWNLOAD_T, &bytes);
        curl_easy_cleanup(curl);
    }

    return bytes;
}

size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
    return size * nmemb;
}

int main() {
    const int RUNS = 3;
    const int N = 50;

    std::chrono::duration<double> seq_time(0), par_time(0);

    // Warm-up
    sequential_image_downloader(N);
    parallel_image_downloader(N);

    for (int r = 0; r < RUNS; r++) {
        auto s1 = std::chrono::high_resolution_clock::now();
        sequential_image_downloader(N);
        seq_time += std::chrono::high_resolution_clock::now() - s1;

        auto s2 = std::chrono::high_resolution_clock::now();
        parallel_image_downloader(N);
        par_time += std::chrono::high_resolution_clock::now() - s2;
    }

    seq_time /= RUNS;
    par_time /= RUNS;

    printf("Sequential: %.2f ms\n", seq_time.count() * 1000);
    printf("Parallel:   %.2f ms\n", par_time.count() * 1000);
    printf("Speedup: %.2f\n", seq_time / par_time);
    printf("Efficiency: %.2f%%\n",
           100 * (seq_time / par_time) / std::thread::hardware_concurrency());

    return 0;
}
