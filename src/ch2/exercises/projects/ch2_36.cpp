//
// Created by Peter Sims on 11/21/24.
//

#include <vector>
#include<iostream>
#include <print>

int main() {
    std::vector<std::string> lines{};
    while (std::cin) {
        std::string temp;
        getline(std::cin, temp);
        lines.push_back(temp);
    }

    while (!lines.empty()) {
        auto last{lines.back()};
        std::cout << last << '\n';
        lines.pop_back();
    }
    return 0;
}
