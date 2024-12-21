//
// Created by Peter Sims on 12/20/24.
//


// find the maximum where 8nlogn is lower than 2n^2
/**
 8nlogn < 2n^2
 8logn < 2n
 4 log n < n

Answer:
 holds true for all numbers >= 10
 */
#include <cmath>
#include <print>

int main() {
    int n{1};
    while (true) {
        ++n;
        // double left{4 * log(i)};
        double left{8 * n * log(static_cast<double>(n))};
        double right{2.0 * (n * n)};
        std::println("n: {}, {} {}", n, left, right);

        if (left < right) {
            break;
        }

    }

    std::println("{}", n);

    return 0;
}
