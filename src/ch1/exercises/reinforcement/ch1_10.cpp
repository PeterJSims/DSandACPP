//
// Created by Peter Sims on 11/14/24.
//

#include <print>


bool is_multiple(const long n, const long m) {
    return n % m == 0;
}

int main() {
    std::println("{}", is_multiple(20, 5));
    std::println("{}", is_multiple(20, -4));
    std::println("{}", is_multiple(20, 7));
    std::println("{}", is_multiple(20, 60));

}

