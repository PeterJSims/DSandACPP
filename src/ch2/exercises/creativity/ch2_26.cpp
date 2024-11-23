//
// Created by Peter Sims on 11/21/24.
//

#include <iostream>
#include "difference_progression.h"


int main() {
    DifferenceProgression dp{};
    dp.print_progression(25);
    DifferenceProgression dp2{100, 10};
    dp2.print_progression(25);

    return 0;
}
