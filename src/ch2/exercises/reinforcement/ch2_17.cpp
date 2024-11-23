//
// Created by Peter Sims on 11/21/24.
//


#include "../reference_classes/geometric_progression.h"

int main() {
    using namespace dsac::design;

    Progression* p = new GeometricProgression;
    std::cout << p->next_value() << " ";
    std::cout << p->next_value() <<"\n";

    p = new Progression{};

    std::cout << p->next_value() << " ";
    std::cout << p->next_value() <<"\n";

    delete p;

    return 0;
}
