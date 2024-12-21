//
// Created by Peter Sims on 11/21/24.
//

#include "../reference_classes/arithmetic_progression.h"


int main() {
    dsac::design::ArithmeticProgression ap{128};

    // This would take 72057594037927935 iterations to overflow
    // int count{0};
    // for (long i{ap.next_value()}; i >= 0; ) {
    //     ++count;
    //     ap.next_value();
    // }
    // std::cout << count;

    std::cout << LONG_MAX / 128;


    return 0;
}
