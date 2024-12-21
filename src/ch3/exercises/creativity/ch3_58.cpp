//
// Created by Peter Sims on 12/21/24.
//


#include <print>
#include <vector>

#include "vector_generators.h"

long find_max(const std::vector<int>& ints) {
    long max{INT_MIN};
    for (const int i : ints) {
        if (i > max) {
            max = i;
        }
    }
    return max;
}

// the trick for this is to just get the maximum number, double it (as there can be duplicates on the array), and add 1
int main() {
    auto vec{vector_generators::random_int_vector(30)};
    std::println("{}", vec);
    std::println("Number that cannot be summed from this found in O(n): {}", 2 * find_max(vec) + 1);

    return 0;
}
