//
// Created by Peter Sims on 1/22/25.
//
#include <print>
#include "../exercise_classes/vector.h"


// exercise_classes/vector.h for operator==() method
int main() {
    using namespace dsac::array;
    Vector<int> vec1;
    Vector<int> vec2;
    Vector<int> vec3;
    for (int i{0}; i < 10; ++i) {
        vec1.insert(vec1.end(), i * 2);
        vec2.insert(vec2.end(), i * 2);
        vec3.insert(vec3.end(), i * 3);
    }

    std::println("vec1 == vec1: {}", (vec1 == vec1 ));
    std::println("vec1 == vec2: {}", (vec1 == vec2 ));
    std::println("vec1 == vec3: {}", (vec1 == vec3 ));


    return 0;
}
