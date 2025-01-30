//
// Created by Peter Sims on 1/29/25.
//

#include <print>
#include <deque>
#include "../exercise_classes/linked_stack.h"


int main() {
    std::deque dq{1,2,3,4,5,6,7,8};
    LinkedStack<int> stack;

    while (!dq.empty()) {
        stack.push(dq.back());
        dq.pop_back();
    }

    while (!stack.empty()) {
        dq.push_back(stack.top());
        stack.pop();
    }

    for (int i : dq){
        std::print("{} ", i);
    }
    return 0;
}
