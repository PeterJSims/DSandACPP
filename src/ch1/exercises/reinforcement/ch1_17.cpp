//
// Created by Peter Sims on 11/15/24.
//


#include <iostream>

inline int pseudo_log(double n) {
    if(n < 0) {
        throw std::invalid_argument("Number must be nonnegative");
    }

    int count{0};
    while(n > 2) {
        ++count;
        n /=2;
    }
    return count;
}

int main() {
    std::cout << pseudo_log(23.5) << '\n';
    std::cout << pseudo_log(0) << '\n';
    std::cout << pseudo_log(234.42) << '\n';
    std::cout << pseudo_log(2002002020) << '\n';
}
