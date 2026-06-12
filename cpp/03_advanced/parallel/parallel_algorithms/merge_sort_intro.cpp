/**
 * Merge Sort — Intro
 *
 * This file introduces the core idea behind merge sort:
 *
 *   - Divide the array into halves
 *   - Recursively sort each half
 *   - Merge the two sorted halves
 *
 * This intro shows:
 *   - A simple sequential merge sort
 *   - A clean merge helper
 *   - No parallelism yet (saved for the overview)
 */

#include <iostream>
#include <algorithm>

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

int main() {
    int arr[10] = {9, 4, 1, 7, 3, 8, 2, 6, 5, 0};

    sequential_merge_sort(arr, 0, 9);

    for (int v : arr) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
