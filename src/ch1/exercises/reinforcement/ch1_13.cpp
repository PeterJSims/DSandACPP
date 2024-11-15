//
// Created by Peter Sims on 11/15/24.
//

#include <iostream>

long sum_to_n(int n) {
    if(n < 0) {
        throw std::invalid_argument("N must be a nonnegative number");
    }
    // not using Gauss summation
    long sum{0};
    for (int i{0}; i <= n; ++i) {
        sum += i;
    }
    return sum;

}

int main() {
    std::cout << sum_to_n(5) << '\n';
    std::cout << sum_to_n(8) << '\n';
    std::cout << sum_to_n(100) << '\n';
}
