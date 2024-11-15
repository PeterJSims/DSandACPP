//
// Created by Peter Sims on 11/15/24.
//

#include <print>

inline double dot_product(const double a[], const double b[], const int n) {
    double product{};
    for (int i{0}; i < n; ++i) {
        product += (a[i] * b[i]);
    }
    return product;
}

int main() {
    constexpr double arr[]{1.0, 2.0, 3.0};
    constexpr double arr2[]{3.0, 2.0, 1.0};
    std::println("{}", dot_product(arr, arr2, std::size(arr)));
}
