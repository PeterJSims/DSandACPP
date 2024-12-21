//
// Created by Peter Sims on 12/20/24.
//

#include <vector>
#include <print>

int find_missing(const std::vector<int>& ints) {
    auto sum{0};
    auto max{ints[0]};

    for (int i : ints) {
        sum += i;
        if (i > max) {
            max = i;
        }
    }
    auto expected_sum{(max * (max + 1)) / 2};

    return expected_sum - sum;
}

int main() {
    const std::vector single_number_missing{0, 1, 3, 5, 7, 9,  2, 6, 8, 10};
    const std::vector no_number_missing{0, 1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    std::println("{}", find_missing(single_number_missing));
    std::println("{}", find_missing(no_number_missing));

    return 0;
}
