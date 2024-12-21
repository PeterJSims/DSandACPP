//
// Created by Peter Sims on 12/21/24.
//
#include <print>
#include <algorithm>
#include "vector_generators.h"


int determine_most_repeated(std::vector<int> ints) {
    if (ints.empty()) {
        throw std::invalid_argument("Cannot find the most repeated number from 0 numbers");
    }

    std::ranges::sort(ints);
    auto max_count_number{ints[0]};
    auto max_count{0};

    auto temp_count{1};
    auto temp_int{ints[0]};

    auto pointer{1};
    while (pointer < ints.size()) {
        auto current{ints[pointer]};

        while (current == temp_int) {
            ++pointer;
            ++temp_count;
            current = ints[pointer];
        }
        // No longer pointing to the same number that has been stored as temp
        // Check to see if it is the new max
        if (temp_count > max_count) {
            max_count = temp_count;
            max_count_number = temp_int;
        }

        // Set counters/temp back to starting and the current number
        temp_count = 1;
        temp_int = current;
    }

    if (temp_count > max_count) {
        max_count_number = temp_int;
    }

    return max_count_number;
    // have to check one more time at the end
}

// should be 14
//[11, 1, 6, 12, 5, 15, 14, 11, 2, 12, 3, 19, 14, 20, 4, 6, 4, 14, 11, 14, 1, 6, 12, 15, 4, 6, 0, 17, 15, 14, 18]
int main() {
    // auto vec{vector_generators::random_int_vector(30, 0, 20)};
    std::vector vec{
        11, 1, 6, 12, 5, 15, 14, 11, 2, 12, 3, 19, 14, 20, 4, 6, 4, 14, 11, 14, 1, 6, 12, 15, 4, 6, 0, 17, 15, 14, 18
    };

    std::println("{}", determine_most_repeated(vec));


    return 0;
}
