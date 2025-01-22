//
// Created by Peter Sims on 1/22/25.
//
#include <print>


template <class T>
concept Numeric = std::is_arithmetic_v<T>;

template <Numeric T>
double sum(const std::vector<T>& vec) {
    double total{0.0};
    for (auto el : vec) { total += el; }
    return total;
}


int main() {
    std::vector one{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector two{1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11};

    std::println("{}", sum(one));
    std::println("{}", sum(two));

    return 0;
}
