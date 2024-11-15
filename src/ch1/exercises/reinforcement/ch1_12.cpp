//
// Created by Peter Sims on 11/14/24.
//


#include <print>



/*
 * if n is 8 -> 1000
 * n - 1 would be 0111
 * The & is just flipping all the other bits and none of them will match ONLY if it's a power of 2
 *
 * For example if n is 9 -> 1001
 * n -1 would be 1000
 * n & n - 1 == 8 != 0
 */

bool is_power_of_two(int i) {
    if( i < 0) return false;
    return (i & (i - 1)) == 0;
}

int main() {
    std::println("{}", is_power_of_two(1));
    std::println("{}", is_power_of_two(8));
    std::println("{}", is_power_of_two(9));
    std::println("{}", is_power_of_two(16));
    std::println("{}", is_power_of_two(-16));
}
