//
// Created by Peter Sims on 1/14/25.
//
#include <print>

int stoi(const std::string& s, const int idx, int total) {
    if (idx == s.size()) {
        return total;
    }
    const char c{s[idx]};
    const int n = c - '0';
    total = total * 10 + n; // adding a 10s place + n for each move from left to right in the string
    return stoi(s, idx + 1, total);
}

int stoi(const std::string& s) {
    return stoi(s, 0, 0);
}

int main() {
    std::println("{}", stoi("123"));

    return 0;
}
