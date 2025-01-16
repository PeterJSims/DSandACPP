//
// Created by Peter Sims on 1/15/25.
//
#include <print>
int product(int n, int m) {
    if (m == 0) {
        return 0;
    }
    return n + product(n, m - 1);
}

int main() {
    std::println("{}", product(3, 2));
    std::println("{}", product(22, 1));
    std::println("{}", product(1, 22));

    return 0;
}
