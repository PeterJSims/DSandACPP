//
// Created by Peter Sims on 11/22/24.
//

#include <map>
#include <iostream>
#include <print>

void clean_string(std::string& str) {
    std::string cleaned{};
    for (const char& c : str) {
        if (isalpha(c)) {
            if (isupper(c)) {
                cleaned.push_back(tolower(c));
            }
            else {
                cleaned.push_back(c);
            }
        }
    }
    str = cleaned;
}

int main() {
    std::map<std::string, int> word_count{};
    std::cout << "Enter words, enter Q/q to quit:\n";
    for (std::string word; std::cin >> word;) {
        clean_string(word);
        if (word == "q") {
            break;
        }
        if (word_count.contains(word)) {
            word_count[word] += 1;
        }
        else {
            word_count[word] = 1;
        }
    }

    for (auto [word, count] : word_count) {
        std::println("{}: {}", word, count);
    }
    return 0;
}
