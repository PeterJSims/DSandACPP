//
// Created by Peter Sims on 11/21/24.
//

#include <vector>
#include <iostream>
int main() {
    std::vector vec{1, 2, 3, 4, 5};
    try {
    std::cout << vec.at(55);

    }
    catch (std::out_of_range&) {
        std::cout << "Out of range";
    }
    return 0;
}
