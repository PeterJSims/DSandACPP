//
// Created by Peter Sims on 1/23/25.
//
#include <print>
#include "../exercise_classes/vector.h"

// see vector.h for random-access iterator additions
// Note -- methods needed to be marked as 'friend' because you are adding a function to ints, not iterators
int main() {
    using namespace dsac::array;
    Vector<int> vec;
    for (int i{0}; i < 10; ++i) {
        vec.insert(vec.end(), i * 2);
    }

    const auto test{5 + vec.begin() };
    std::println("{}", *test);



    return 0;
}
