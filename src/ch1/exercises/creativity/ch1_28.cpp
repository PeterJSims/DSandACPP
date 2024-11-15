//
// Created by Peter Sims on 11/15/24.
//

#include <iostream>

int main() {
    for (int num; std::cin >> num;) {
        long long l{1};
        for (int i{0}; i < num; ++i) {
            l <<= 1l;
        }
        std::cout << l << '\n';
    }
}
