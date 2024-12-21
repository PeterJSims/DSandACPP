//
// Created by Peter Sims on 11/21/24.
//

#ifndef DIFFERENCE_PROGRESSION_H
#define DIFFERENCE_PROGRESSION_H

#include "../reference_classes/progression.h"

class DifferenceProgression: public dsac::design::Progression{
private:
    long next;

public:
    DifferenceProgression(long start = 2, long next = 200)
        : Progression(start),
          next(next) {
    }

    void advance() override {
        auto t{next};
        next = abs(current - next);
        current = t;
    }
};



#endif //DIFFERENCE_PROGRESSION_H
