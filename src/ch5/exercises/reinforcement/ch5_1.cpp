//
// Created by Peter Sims on 1/21/25.
//


#include <print>
#include <array>

int find_repeat(const int* arr, int n) {
    const int expected_sum{((n - 1) * (n)) / 2}; // sum from 1 to n-1
    int iterated_sum{0};
    for (int i{0}; i < n; ++i) {
        iterated_sum += arr[i];
    }
    return iterated_sum - expected_sum;
}


int main() {
    const int arr[] = {1, 2, 3, 3, 4}; // 13
    const int arr2[] = {1, 3, 4, 2, 5, 6, 4}; // 13
    std::println("{}", find_repeat(arr, std::size(arr)));
    std::println("{}", find_repeat(arr2, std::size(arr2)));


    return 0;
}
