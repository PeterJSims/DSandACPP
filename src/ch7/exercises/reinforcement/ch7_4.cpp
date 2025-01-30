//
// Created by Peter Sims on 1/28/25.
//

#include <print>
#include "../exercise_classes/linked_stack.h"


// see linked_stack.h for class implementation

int main() {
    LinkedStack<int> stack;
    stack.push(5);
    stack.push(3);
    std::println("Size: {}", stack.size());
    stack.pop();
    std::println("Size: {}", stack.size());
    std::println("Top item: {}", stack.top());
    stack.push(-1);
    std::println("Top item: {}", stack.top());



    return 0;
}
