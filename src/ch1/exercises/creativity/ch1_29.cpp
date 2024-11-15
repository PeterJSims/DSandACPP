//
// Created by Peter Sims on 11/15/24.
//

#include <iostream>

int gcd(const long n, const long m) {
    if(m == 0) {
        return n;
    }
    return gcd(m, n % m);
}

int main() {
    std::cout << gcd(80844, 25320) << '\n';
    std::cout << gcd(1111111, 1234567) << '\n';
}
