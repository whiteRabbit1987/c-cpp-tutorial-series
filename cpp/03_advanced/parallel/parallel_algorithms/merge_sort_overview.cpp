/**
 * Merge Sort — Overview
 *
 * This file demonstrates:
 *
 *   - Sequential merge sort
 *   - Parallel merge sort using recursive task spawning
 *   - Depth limiting based on hardware concurrency
 *   - Benchmarking sequential vs. parallel performance
 *
 * This is a complete, runnable educational example.
 */

#include <iostream>
#include <thread>
#include <cmath>
#include <algorithm>
#include <chrono>

void merge(int* arr, unsigned int left, unsigned int mid, unsigned int right) {
    unsigned int n1 = mid - left + 1;
    unsigned int n2 = right - mid;

    int L[n1], R[n2];
    std::copy(&arr[left], &arr[mid + 1], L);
    std::copy(&arr[mid + 1], &arr[right + 1], R);

    unsigned int i = 0, j = 0, k = left;

    while (i < n1 || j < n2) {
        if (i < n1 && (j >= n2 || L[i] <= R[j])) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
}

void sequential_merge_sort(int* arr, unsigned int left, unsigned int right) {
    if (left < right) {
        unsigned int mid = (left + right) / 2;
        sequential_merge_sort(arr, left, mid);
        sequential_merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void parallel_merge_sort(int* arr, unsigned int left, unsigned int right, unsigned int depth = 0) {
    if (depth >= std::log(std::thread::hardware_concurrency())) {
        sequential_merge_sort(arr, left, right);
        return;
    }

    unsigned int mid = (left + right) / 2;

    std::thread left_thread(parallel_merge_sort, arr, left, mid, depth + 1);
    parallel_merge_sort(arr, mid + 1, right, depth + 1);

    left_thread.join();
    merge(arr, left, mid, right);
}

int main() {
    const int N = 100;
    const int RUNS = 50;

    int original[N], seq[N], par[N];

    for (int i = 0; i < N; i++) original[i] = rand();

    std::chrono::duration<double> seq_time(0), par_time(0);

    // Warm-up
    std::copy(original, original + N, seq);
    sequential_merge_sort(seq, 0, N - 1);

    std::copy(original, original + N, par);
    parallel_merge_sort(par, 0, N - 1);

    // Benchmark sequential
    for (int r = 0; r < RUNS; r++) {
        std::copy(original, original + N, seq);
        auto start = std::chrono::high_resolution_clock::now();
        sequential_merge_sort(seq, 0, N - 1);
        seq_time += std::chrono::high_resolution_clock::now() - start;
    }
    seq_time /= RUNS;

    // Benchmark parallel
    for (int r = 0; r < RUNS; r++) {
        std::copy(original, original + N, par);
        auto start = std::chrono::high_resolution_clock::now();
        parallel_merge_sort(par, 0, N - 1);
        par_time += std::chrono::high_resolution_clock::now() - start;
    }
    par_time /= RUNS;

    // Verify correctness
    for (int i = 0; i < N; i++) {
        if (seq[i] != par[i]) {
            printf("ERROR: mismatch at index %d\n", i);
        }
    }

    printf("Sequential: %.2f ms\n", seq_time.count() * 1000);
    printf("Parallel:   %.2f ms\n", par_time.count() * 1000);
    printf("Speedup: %.2f\n", seq_time / par_time);
    printf("Efficiency: %.2f%%\n",
           100 * (seq_time / par_time) / std::thread::hardware_concurrency());

    return 0;
}
