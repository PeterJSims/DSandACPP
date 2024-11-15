//
// Created by Peter Sims on 11/15/24.
//
#include <iostream>

int num_vowels(const std::string& s) {
    int count{0};
    for (char c : s) {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            ++count;
        }
    }
    return count;
}


int main() {
    std::cout << num_vowels("hello") << '\n';
    std::cout << num_vowels("qrzym") << '\n';
    std::cout << num_vowels("OOoo") << '\n';
}
