//
// Created by Peter Sims on 1/15/25.
//
#include <print>

bool is_palindrome(std::string& str, int l, int r) {
    if (l > r) {
        return true;
    }
    return (str[l] == str[r]) && is_palindrome(str, l + 1, r - 1);
}

bool is_palindrome(std::string& str) {
    return is_palindrome(str, 0, str.size() - 1);
}

int main() {
    std::string test{"hello"};
    std::string test2{"gohangasalamiimalasagnahog"};
    std::string test3{"madamimadam"};
    std::println("{}", is_palindrome(test));
    std::println("{}", is_palindrome(test2));
    std::println("{}", is_palindrome(test3));


    return 0;
}
