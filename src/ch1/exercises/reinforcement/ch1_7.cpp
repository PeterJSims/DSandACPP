//
// Created by Peter Sims on 11/14/24.
//

#include <iostream>

int main() {
    // array of pointers problem

    // bad
    double* dp[10];
    for (int i{0}; i < 10; ++i) {
        // dp[i] = 0.0;
    }

    // good
    double* dp2[10];
    for (int i{0}; i < 10; ++i) {
        dp2[i] = new double(1.1 * i);

        std::cout << dp2[i] << "\n";
        std::cout << *dp2[i] << "\n";
    }

    for (auto& ptr : dp2) delete ptr;


    return 0;
}
