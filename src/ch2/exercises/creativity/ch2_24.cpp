//
// Created by Peter Sims on 11/21/24.
//

#include <iostream>

int main() {
    for (int i{0}; i < 30; i += 2) {
        if((i & 1) == 1) {
            // never reached
            return 0;
        }
    }
    std::cout << "Task reached the end" << std::endl;
    return 0;
}
