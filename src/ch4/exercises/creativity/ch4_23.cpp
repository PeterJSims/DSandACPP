//
// Created by Peter Sims on 1/15/25.
//

#include <print>
#include <sstream>

std::string reverse_string(std::string& str, int l, int r) {
    if (l == r) {
        return str;
    }
    std::swap(str[l], str[r]);
    return reverse_string(str, l + 1, r - 1);
}

std::string reverse_string(std::string& str) {
    return reverse_string(str, 0, str.size() - 1);
}

int main() {
    std::string test{"hello&goodbye"};
    std::println("{}", reverse_string(test));

    return 0;
}
