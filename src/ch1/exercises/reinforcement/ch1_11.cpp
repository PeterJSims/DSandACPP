//
// Created by Peter Sims on 11/14/24.
//

#include <print>

bool is_power_of_two(const int i) {
    double n = i;
    while (n >= 1) {
        if (n == 1) { return true; }
        n /= 2.0;
    }
    return false;
}

int main() {
    std::println("{}", is_power_of_two(1));
    std::println("{}", is_power_of_two(8));
    std::println("{}", is_power_of_two(9));
    std::println("{}", is_power_of_two(16));
    std::println("{}", is_power_of_two(-16));
}
