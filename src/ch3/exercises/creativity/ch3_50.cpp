//
// Created by Peter Sims on 12/20/24.
//


#include <cmath>
#include <print>

double log_summation(const int n) {
    double total{};
    for (int i{1}; i < n; ++i) {
        total += log(i);
    }
    return total;
}

void print_results() {
    for (int i{10}; i < 1'000'000'000; i *= 10) {
        std::println("n:             {}", i);
        std::println("Log summation: {}", log_summation(i));
        std::println("n * log n:     {}\n", i * log(i));
    }
}

int main() {

    print_results();

    return 0;
}
