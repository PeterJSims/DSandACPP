//
// Created by Peter Sims on 11/21/24.
//

#include <iostream>

int brute_log2(double n) {
    int count{0};
    while(n >= 2) {
        ++count;
        n /= 2;
    }
    return count;
}

int main() {
    for(int i; std::cin >> i;) {
        if(i <= 2) {
            std::cout << "Enter a number larger than 2";
        }
        std::println("{}", brute_log2(i));
    }
    return 0;
}
