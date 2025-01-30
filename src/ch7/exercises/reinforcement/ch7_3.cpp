//
// Created by Peter Sims on 1/28/25.
//
#include <stack>
#include <print>


template <typename T>
void transfer(std::stack<T>& s, std::stack<T>& t) {
    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }
}


int main() {
    std::stack<int> one;
    std::stack<int> two;
    for (int i{0}; i < 5; ++i) {
        one.push(i);
        two.push(i + 5);
    }
    transfer(one, two);

    while (!two.empty()) {
        std::println("{}", two.top());
        two.pop();

    }
    return 0;
}
