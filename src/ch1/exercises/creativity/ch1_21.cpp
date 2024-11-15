//
// Created by Peter Sims on 11/15/24.
//

#include <iostream>
#include <print>

std::pair<bool, std::string> can_be_used(const int a, const int b, const int c) {
    if (a + b == c || a == b + c) return std::pair(true, "addition");
    if (a - b == c || a == b - c) return std::pair(true, "subtraction");;
    if (a * b == c || a == b * c) return std::pair(true, "multiplication");;

    if ((b != 0 && a / b == c) || (c != 0 && a == b / c)) return std::pair(true, "division");;

    return std::pair(false, "");;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    while (std::cin) {
        auto [result, type]{can_be_used(a, b, c)};

        std::println("{} {} and {} {} be used {}", a, b, c,
                     result ? "can" : "cannot",
                     result ? "with " + type : ""
        );
        std::cin >> a >> b >> c;
    }
}
