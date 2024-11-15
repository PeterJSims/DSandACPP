//
// Created by Peter Sims on 11/14/24.
//

#include <iostream>

bool is_even(const int n) {
    return (n & 1) == 0;
}


int main() {
    std::cout << std::boolalpha;
    std::cout << is_even(2) << '\n';
    std::cout << is_even(5) << std::endl;
}
