//
// Created by Peter Sims on 12/20/24.
//


#include <cmath>
#include <print>
#include <arm/limits.h>
// The infinite sum does converge to 2 BUT finite is always less than 2
int main() {
    double sum{};
    for (unsigned int i{0}; i < UINT_MAX; ++i) {
        sum += i / (pow(2, i));
    }
    std::println("{}", sum);

    return 0;
}
