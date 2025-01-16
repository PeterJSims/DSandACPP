//
// Created by Peter Sims on 1/14/25.
//
#include <print>

long power(int n, int exp) {
    int total{1};
    while (exp > 0) {
        if (exp % 2 != 0) {
            total *= n; // it will always do this at least once (exp = 1)
        }
        n *= n;
        exp /= 2;
    }
    return total;
}

int main() {
    std::println("{}", power(2, 13));
    std::println("{}", power(16, 2));

    return 0;
}
