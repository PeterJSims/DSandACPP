//
// Created by Peter Sims on 11/14/24.
//
#include <iostream>

void f(int x){ std::cout << ++x << std::endl; }
void g(int& x){ std::cout << ++x << std::endl; }

int main() {
    int n{5};
    f(n);
    g(n);
    std::cout << n << std::endl;
}
