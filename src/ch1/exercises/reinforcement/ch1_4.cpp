//
// Created by Peter Sims on 11/14/24.
//

#include <iostream>


struct Pair {
    double first;
    double second;
};

int main() {
    Pair p{Pair()};
    p.first = 3.14;
    p.second = 42.0;
    std::cout << p.first;

    return 0;
}
