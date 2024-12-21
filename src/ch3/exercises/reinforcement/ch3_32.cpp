//
// Created by Peter Sims on 12/20/24.
//

#include <print>


/*
This is an example of the inexact nature of O() notation.

Say that function A's full operations are (n * logn + 9539) whereas
B's is just n^2, this would hold true
*/

int main() {
    double i{0};
    constexpr int constant{9539};

    while (true) {
        double left{i * log(i) + constant};
        double right{i * i};
        if (left < right) {
            break;
        }
        ++i;
    }

    std::println("{}", i);

    return 0;
}
