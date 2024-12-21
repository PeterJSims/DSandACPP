//
// Created by Peter Sims on 11/21/24.
//

#include "sqrt_progression.h"


int main() {
    SqrtProgression sqrt_progression{};
    sqrt_progression.print_progression(10);
    SqrtProgression sqrt_progression2{10000};
    sqrt_progression2.print_progression(10);
    return 0;
}
