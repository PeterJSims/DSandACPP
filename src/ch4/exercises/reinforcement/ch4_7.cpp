//
// Created by Peter Sims on 1/14/25.
//

#include <print>

double harmonic(int n) {
    if (n <= 1) return 1;
    const double k{n * 1.0};
    return 1 / k + harmonic(n - 1);
}

int main() {
    std::println("{}", harmonic(45000));
    return 0;
}
