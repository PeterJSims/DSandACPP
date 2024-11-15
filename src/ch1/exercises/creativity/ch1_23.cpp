//
// Created by Peter Sims on 11/15/24.
//


#include <print>


bool can_have_even_product(const int* arr, const size_t n) {
    int evens{0};
    for (int i{0}; i < n; ++i) {
        if (i > 0 && evens > 0) return true;
        if (arr[i] % 2 == 0) {
            ++evens;
        }
    }

    return n > 1 && evens > 0;
}


int main() {
    constexpr int arr[]{1, 2};
    constexpr int arr2[]{1, 1, 3, 5, 9};
    constexpr int arr3[]{2,2};

    std::println("{}", can_have_even_product(arr, std::size(arr)));
    std::println("{}", can_have_even_product(arr2, std::size(arr2)));
    std::println("{}", can_have_even_product(arr3, std::size(arr3)));

}
