//
// Created by Peter Sims on 11/15/24.
//

#include <print>


bool can_have_odd_product(const int* arr, const size_t n) {
    int odds{0};
    for (int i{0}; i < n; ++i) {
        if(odds == 2) return true;
        if (arr[i] % 2 != 0) {
            ++odds;
        }
    }

    return odds == 2;
}


int main() {
    constexpr int arr[]{1, 2};
    constexpr int arr2[]{1, 1, 3, 5, 9};
    constexpr int arr3[]{2,2};

    std::println("{}", can_have_odd_product(arr, std::size(arr)));
    std::println("{}", can_have_odd_product(arr2, std::size(arr2)));
    std::println("{}", can_have_odd_product(arr3, std::size(arr3)));

}
