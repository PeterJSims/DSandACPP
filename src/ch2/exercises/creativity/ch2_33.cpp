//
// Created by Peter Sims on 11/21/24.
//

#include <vector>
#include <iostream>

void print_odds(const std::vector<int> ints) {
    for (int num : ints) {
        if (num % 2 != 0) {
            std::cout << num << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::vector ints1{1, 2, 3, 4, 5, 6, 7};
    std::vector ints2{4, 2, 8, 10, 6};
    print_odds(ints1);
    print_odds(ints2);



    return 0;
}
