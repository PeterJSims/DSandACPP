//
// Created by Peter Sims on 1/22/25.
//

#include <print>
#include "../exercise_classes/vector.h"

// see vector.h for downsizing
int main() {
    using namespace dsac::array;
    Vector<int> vec;
    for (int i{0}; i < 8; ++i) {
        vec.insert(vec.end(), i);
    }
    std::println("{}", "");
    std::println("Vector size: {}", vec.size());
    std::println("Vector capacity: {}", vec.capacity());

    for (int i{0}; i < 8; ++i) {
        // vec.erase(vec.size() - 1);
        vec.pop_back();
        std::println("{}", "Item removed");
        std::println("Vector size: {}", vec.size());
        std::println("Vector capacity: {}", vec.capacity());
    }
    std::println("****\n\n" );
    for (int i{0}; i < 9; ++i) {
        // vec.erase(vec.size() - 1);
        vec.insert(vec.back(), i);
        std::println("{}", "Item added");
        std::println("Vector size: {}", vec.size());
        std::println("Vector capacity: {}", vec.capacity());
    }


    return 0;
}
