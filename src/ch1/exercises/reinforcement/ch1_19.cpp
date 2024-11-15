//
// Created by Peter Sims on 11/15/24.
//


#include <iostream>


int main() {
    std::string word{"example"};
    word.erase(0, 2);
    std::cout << word;
}
