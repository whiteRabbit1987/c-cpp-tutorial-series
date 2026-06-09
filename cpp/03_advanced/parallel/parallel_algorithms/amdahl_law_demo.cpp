#include <iostream>
#include <iomanip>

// Amdahl's Law Demo                  =   Shows theoretical speedup limits based on the
//                                       parallelizable fraction of a program.

// Purpose of Demo                    =   Compute speedup for various processor counts and
//                                       visualize diminishing returns.

double amdahl_speedup(double P, int processors) {
    return 1.0 / ((1.0 - P) + (P / processors));
}

int main() {

    double P = 0.95;                                 // 95% parallelizable

    std::cout << "Amdahl's Law (P = 0.95)\n";
    std::cout << "Processors   Speedup\n";
    std::cout << "----------------------\n";

    for (int n = 1; n <= 1024; n *= 2) {
        double s = amdahl_speedup(P, n);
        std::cout << std::setw(10) << n
                  << "   " << std::fixed << std::setprecision(3)
                  << s << "\n";
    }

    // Show extreme case
    double extreme = amdahl_speedup(P, 1'000'000);
    std::cout << "\nSpeedup with 1,000,000 processors: "
              << extreme << "\n";

    return 0;
}
