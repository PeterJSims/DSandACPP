//
// Created by Peter Sims on 11/15/24.
//


#include <iostream>

long sum_to_n(int n) {
    if(n < 0) {
        throw std::invalid_argument("N must be a nonnegative number");
    }
    return (n * (n + 1)) / 2;

}

int main() {
    std::cout << sum_to_n(5) << '\n';
    std::cout << sum_to_n(8) << '\n';
    std::cout << sum_to_n(100) << '\n';
}
