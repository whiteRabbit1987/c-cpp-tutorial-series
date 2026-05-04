// lambda_accumulator.cpp
// purpose               = demonstrate lambdas as accumulators with different capture modes
// topics                = reference capture, copy capture, init-capture, mutable lambdas
// best practice         = use reference capture for external accumulation; use init-capture
//                         or mutable when internal state is needed

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    std::vector<int> v{1, 2, 3, 4, 5, 6};

    // ------------------------------------------------------------
    // 1. reference capture: [&sum]
    // external sum is modified directly
    // ------------------------------------------------------------
    int sum = 0;

    auto ref_acc = [&sum](int n) {
        sum += n;   // modifies external variable
    };

    std::for_each(v.begin(), v.end(), ref_acc);

    std::cout << "ref_acc sum: " << sum << "\n"; // prints 21


    // ------------------------------------------------------------
    // 2. copy capture: [sum]
    // external sum is NOT modified
    // ------------------------------------------------------------
    sum = 0;

    auto copy_acc = [sum](int n) mutable {
        sum += n;   // modifies internal copy
    };

    std::for_each(v.begin(), v.end(), copy_acc);

    std::cout << "copy_acc sum: " << sum << "\n"; // still 0


    // ------------------------------------------------------------
    // 3. init-capture: [acc = 0]
    // accumulator lives INSIDE the closure object
    // ------------------------------------------------------------
    auto init_acc = [acc = 0](int n) mutable {
        acc += n;
        return acc; // returns running total
    };

    int last = 0;
    std::for_each(v.begin(), v.end(),
        [&](int n) {
            last = init_acc(n);
        }
    );

    std::cout << "init_acc final: " << last << "\n"; // prints 21


    // ------------------------------------------------------------
    // 4. mixed capture: [&, total = 0]
    // external variables by reference, accumulator by value
    // ------------------------------------------------------------
    int count = 0;

    auto mixed = [&, total = 0](int n) mutable {
        total += n; // internal running sum
        count++;    // external counter
        return total;
    };

    int final_total = 0;
    std::for_each(v.begin(), v.end(),
        [&](int n) {
            final_total = mixed(n);
        }
    );

    std::cout << "mixed total: " << final_total << "\n"; // 21
    std::cout << "mixed count: " << count << "\n";       // 6


    return 0;
}
