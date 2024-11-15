//
// Created by Peter Sims on 11/15/24.
//


#include <iostream>

long sum_squares(int n) {
    if (n < 0) {
        throw std::invalid_argument("N must be a nonnegative number");
    }
    // not using Gauss summation
    return (n * (n + 1) * (2*n + 1))/ 6;
}

int main() {
    // std::cout << sum_squares(-5) << '\n';
    std::cout << sum_squares(4) << '\n';
    std::cout << sum_squares(8) << '\n';
    std::cout << sum_squares(100) << '\n';
}
