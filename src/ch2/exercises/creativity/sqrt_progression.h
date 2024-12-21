//
// Created by Peter Sims on 11/21/24.
//

#ifndef SQRT_PROGRESSION_H
#define SQRT_PROGRESSION_H
#include "../reference_classes/progression.h"


class SqrtProgression : public dsac::design::Progression {
    double current_sqr;

public:
    SqrtProgression(double start = 65536): current_sqr(start) {}

    double next_value() {
        const double answer{current_sqr};
        advance(); // this protected call is responsible for advancing the current value
        return answer;
    }

    void advance() override {
        current_sqr = sqrt(current_sqr);
    };

    void print_progression(int n) {
        std::cout << next_value(); // print the first value without leading space
        for (int j = 1; j < n; j++)
            std::cout << " " << next_value(); // print leading space before others
        std::cout << std::endl;
    }
};


#endif //SQRT_PROGRESSION_H
