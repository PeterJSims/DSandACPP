//
// Created by Peter Sims on 11/15/24.
//

#include <iostream>

void remove_punctuation(std::string& s ) {
    std::string parsed{};
    for (const char c : s) {
        if(isalnum(c) || isspace(c)) {
            parsed.push_back(c);
        }
    }
    s = parsed;
}


int main() {
    std::string s{"Let's try, Mike."};
    remove_punctuation(s);
    std::cout << s;
}
