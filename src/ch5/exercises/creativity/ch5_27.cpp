//
// Created by Peter Sims on 1/23/25.
//

#include <print>
#include <vector>

template <typename T>
void bubble_sort(std::vector<T>& vec) {
    for (int i{0}; i < vec.size() - 1; ++i) {
        for (int j{0}; j < vec.size() - i - 1; ++j) {
            if (vec[j] > vec[j + 1]) {
                std::swap(vec[j], vec[j + 1]);
            }
        }
    }
}


int main() {
    std::vector ints{2, 3, 1, 9, 4, -2};
    bubble_sort(ints);
    std::println("{:n}", ints);
    return 0;
}
