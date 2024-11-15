//
// Created by Peter Sims on 11/15/24.
//


#include  <print>
#include <iostream>
#include <cstdlib>


template <typename T>
void shuffle(T arr[], const int n) {
    srand(time(nullptr));

    for (int i{0}; i < n; ++i) {
        auto rand_int{rand() % (i + 1)};
        T temp{arr[rand_int]};
        arr[rand_int] = arr[i];
        arr[i] = temp;
    }
}


int main() {
    constexpr int n{52};
    int nums[n];
    for (int i{0}; i < n; ++i) {
        nums[i] = i + 1;
    }

    shuffle(nums, n);

    for (const int num : nums) std::cout << num << " ";
}
