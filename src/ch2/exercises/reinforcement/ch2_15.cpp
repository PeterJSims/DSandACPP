//
// Created by Peter Sims on 11/21/24.
//

#include <print>
#include "../reference_classes/fibonacci_progression.h"

int main() {
    using namespace dsac::design;

    FibonacciProgression fp{3, 4};

    for (int i{0}; i < 6; ++i) {
        fp.next_value();
    }
    std::cout << fp.next_value();




    return 0;
}
