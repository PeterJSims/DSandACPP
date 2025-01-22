//
// Created by Peter Sims on 1/22/25.
//
#include <print>
#include "../exercise_classes/vector.h"


// exercise_classes/vector.h for contains() method
int main() {
    using namespace dsac::array;
    Vector<int> vec;
    for (int i{0}; i < 10; ++i) {
        vec.insert(vec.end(), i * 2);
    }
    auto first{vec.contains(3)};
    auto second{vec.contains(8)};
    std::println("Vector contains {}: {}", 3, first);
    std::println("Vector contains {}: {}", 8, second);

    return 0;
}
