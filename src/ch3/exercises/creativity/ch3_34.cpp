//
// Created by Peter Sims on 12/20/24.
//

#include <print>
#include <algorithm>

// Three way set disjoint in O(n log n)
template <typename T>
bool is_disjoint(std::vector<T> one, std::vector<T> two, std::vector<T> three) {
    std::ranges::sort(one);
    std::ranges::sort(two);
    std::ranges::sort(three);

    for (auto a : one) {
        auto found_in_two{std::ranges::binary_search(two, a)};
        if (found_in_two) {
            if (std::ranges::binary_search(three, a)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    std::vector one{3, 9, 11, 23, 45, 4, 94, 85}; // 4
    std::vector two{4, 10, 12, 24, 46, 5, 95, 86}; // 4
    std::vector three{2, 8, 10, 22, 44, 4, 93, 84}; // 4
    std::vector four{-3, -9, -11, -23, -45, -4, -94, -85};
    std::vector five{-4, -10, -12, -24, -46, -5, -95, -86};
    std::println("One, Two, Three Disjoint? {}", is_disjoint(one, two, three));
    std::println("One, Four, Five Disjoint? {}", is_disjoint(one, four, five));


    return 0;
}
