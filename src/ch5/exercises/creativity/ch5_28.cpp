//
// Created by Peter Sims on 1/23/25.
//
#include <print>
#include "../exercise_classes/vector.h"

// see vector.h for random-access iterator additions
int main() {
    using namespace dsac::array;
    Vector<int> vec;
    for (int i{0}; i < 10; ++i) {
        vec.insert(vec.end(), i * 2);
    }

    auto test{vec.begin() + 8};
    std::println("{}", *test);



    return 0;
}
