//
// Created by Peter Sims on 11/14/24.
//

#include <iostream>
#include <print>


int main() {
    std::string s{"abc"};
    std::string t{"cde"};
    s += s + t[1] + s;
    std::cout << s;


    return 0;
}
