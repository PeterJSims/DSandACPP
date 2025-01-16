//
// Created by Peter Sims on 1/15/25.
//

#include <print>

// linear recursion fine -- the number of calls are not large
int log2(int n) {
    if (n <= 1) {
        return 0;
    }
    return 1 + log2(n / 2);
}


int main() {
    std::println("{}", log2(4));
    std::println("{}", log2(12345678));
    std::println("{}", log2(123456789));
    std::println("{}", log2(123456789));

    return 0;
}
