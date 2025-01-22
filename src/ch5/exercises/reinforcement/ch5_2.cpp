//
// Created by Peter Sims on 1/21/25.
//

#include <print>

void find_duplicates(int* arr, const int n) {
    for (int i{0}; i < n; ++i) {
        arr[i] = -arr[i];
    }

    for (int i{0}; i < n; ++i) {
        auto current_abs{abs(arr[i])};
        arr[current_abs] = -arr[current_abs];
    }

    for (int i{1}; i < n - 4; ++i) {
        if (arr[i] < 0) {
            std::print("{} ", i);
        }
    }
    std::println("{}", "");
}


int main() {
    int arr1[] = {5, 2, 6, 3, 2, 7, 1, 5, 4, 4, 7, 1}; // 1 2 4 5 7
    int arr2[] = {3, 3, 6, 6, 2, 7, 1, 5, 2, 4, 7, 1}; // 1 2 3 6 7
    find_duplicates(arr1, std::size(arr1));
    find_duplicates(arr2, std::size(arr2));

    return 0;
}
