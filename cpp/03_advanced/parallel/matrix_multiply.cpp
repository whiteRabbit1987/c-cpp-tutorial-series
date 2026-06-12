/**
 * Parallel Matrix Multiplication
 *
 * This file demonstrates a clean, modern implementation of matrix
 * multiplication using domain decomposition and agglomeration.
 *
 * Key Ideas:
 *  - Each output row C[i][*] can be computed independently.
 *  - This makes the problem “embarrassingly parallel.”
 *  - We partition the rows of C into chunks based on the number of
 *    available hardware threads.
 *  - Each worker thread computes a subset of rows.
 *
 * Design Notes:
 *  - Domain decomposition: rows of C are independent tasks.
 *  - Agglomeration: instead of spawning one thread per row, we group
 *    rows into chunks sized according to hardware_concurrency().
 *  - No communication is required between workers.
 *  - This is a textbook example of ideal parallel structure.
 */

#include <thread>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <chrono>

/* ------------------------------------------------------------
 * Sequential Matrix Multiply
 * ------------------------------------------------------------
 * Standard triple‑nested loop:
 *   C[i][j] = sum_k A[i][k] * B[k][j]
 */
void sequential_matrix_multiply(long** A, size_t rowsA, size_t colsA,
                                long** B, size_t rowsB, size_t colsB,
                                long** C)
{
    for (size_t i = 0; i < rowsA; i++) {
        for (size_t j = 0; j < colsB; j++) {
            long sum = 0;
            for (size_t k = 0; k < colsA; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

/* ------------------------------------------------------------
 * Worker Function
 * ------------------------------------------------------------
 * Computes rows [startRow, endRow) of the output matrix C.
 */
void parallel_worker(long** A, size_t rowsA, size_t colsA,
                     long** B, size_t rowsB, size_t colsB,
                     long** C,
                     size_t startRow, size_t endRow)
{
    for (size_t i = startRow; i < endRow; i++) {
        for (size_t j = 0; j < colsB; j++) {
            long sum = 0;
            for (size_t k = 0; k < colsA; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

/* ------------------------------------------------------------
 * Parallel Matrix Multiply
 * ------------------------------------------------------------
 * Uses domain decomposition + agglomeration:
 *  - Determine number of hardware threads.
 *  - Divide rows of C into equal‑sized chunks.
 *  - Launch one worker per chunk.
 */
void parallel_matrix_multiply(long** A, size_t rowsA, size_t colsA,
                              long** B, size_t rowsB, size_t colsB,
                              long** C)
{
    size_t numWorkers = std::thread::hardware_concurrency();
    if (numWorkers == 0) numWorkers = 2; // fallback

    size_t chunkSize = std::ceil((double)rowsA / numWorkers);

    std::vector<std::thread> workers;
    workers.reserve(numWorkers);

    for (size_t w = 0; w < numWorkers; w++) {
        size_t start = w * chunkSize;
        size_t end   = std::min(start + chunkSize, rowsA);

        if (start >= rowsA) break;

        workers.emplace_back(parallel_worker,
                             A, rowsA, colsA,
                             B, rowsB, colsB,
                             C,
                             start, end);
    }

    for (auto& t : workers) {
        t.join();
    }
}

/* ------------------------------------------------------------
 * Main: Demonstration + Timing
 * ------------------------------------------------------------
 * Allocates matrices, fills them with random values, and compares
 * sequential vs. parallel performance.
 */
int main()
{
    const int NUM_EVAL_RUNS = 3;
    const size_t ROWS_A = 1000;
    const size_t COLS_A = 1000;
    const size_t ROWS_B = COLS_A;
    const size_t COLS_B = 1000;

    // Allocate matrices
    auto alloc_matrix = [](size_t rows, size_t cols) {
        long** M = (long**)malloc(rows * sizeof(long*));
        for (size_t i = 0; i < rows; i++) {
            M[i] = (long*)malloc(cols * sizeof(long));
        }
        return M;
    };

    long** A = alloc_matrix(ROWS_A, COLS_A);
    long** B = alloc_matrix(ROWS_B, COLS_B);
    long** C_seq = alloc_matrix(ROWS_A, COLS_B);
    long** C_par = alloc_matrix(ROWS_A, COLS_B);

    // Fill A and B with random values
    for (size_t i = 0; i < ROWS_A; i++) {
        for (size_t j = 0; j < COLS_A; j++) {
            A[i][j] = rand() % 100 + 1;
            B[i][j] = rand() % 100 + 1;
        }
    }

    // Warm‑up
    sequential_matrix_multiply(A, ROWS_A, COLS_A, B, ROWS_B, COLS_B, C_seq);
    parallel_matrix_multiply(A, ROWS_A, COLS_A, B, ROWS_B, COLS_B, C_par);

    // Time sequential
    std::chrono::duration<double> seqTime(0);
    for (int i = 0; i < NUM_EVAL_RUNS; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        sequential_matrix_multiply(A, ROWS_A, COLS_A, B, ROWS_B, COLS_B, C_seq);
        seqTime += std::chrono::high_resolution_clock::now() - start;
    }
    seqTime /= NUM_EVAL_RUNS;

    // Time parallel
    std::chrono::duration<double> parTime(0);
    for (int i = 0; i < NUM_EVAL_RUNS; i++) {
        auto start = std::chrono::high_resolution_clock::now();
        parallel_matrix_multiply(A, ROWS_A, COLS_A, B, ROWS_B, COLS_B, C_par);
        parTime += std::chrono::high_resolution_clock::now() - start;
    }
    parTime /= NUM_EVAL_RUNS;

    // Verify correctness
    for (size_t i = 0; i < ROWS_A; i++) {
        for (size_t j = 0; j < COLS_B; j++) {
            if (C_seq[i][j] != C_par[i][j]) {
                printf("ERROR: mismatch at (%zu, %zu)\n", i, j);
            }
        }
    }

    // Report
    printf("Sequential Time: %.2f ms\n", seqTime.count() * 1000);
    printf("Parallel Time:   %.2f ms\n", parTime.count() * 1000);
    printf("Speedup: %.2f\n", seqTime / parTime);
    printf("Efficiency: %.2f%%\n",
           100.0 * (seqTime / parTime) / std::thread::hardware_concurrency());

    return 0;
}
