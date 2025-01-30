//
// Created by Peter Sims on 1/30/25.
//

#include <stack>
#include <queue>
#include <print>
#include <unordered_set>

template <typename T>
bool contains(std::stack<T>& stack, T elem) {
    std::queue<T> queue;
    bool found{false};
    int moved{0};

    while (!stack.empty()) {
        auto top{stack.top()};
        if (top == elem) {
            found = true;
            break;
        }
        queue.push(top);
        stack.pop();
        ++moved;
    }

    while (!queue.empty()) {
        auto first{queue.front()};
        stack.push(first);
        queue.pop();
    }
    // one more back and forth to reverse the items
    for (int i{0}; i < moved; ++i) {
        queue.push(stack.top());
        stack.pop();
    }
    for (int i{0}; i < moved; ++i) {
        stack.push(queue.front());
        queue.pop();
    }

    return found;
}


int main() {
    std::stack<int> nums;
    for (int i{0}; i < 10; ++i) {
        nums.push(i * 2);
    }

    std::println("{}", contains(nums, 12));
    std::println("{}", contains(nums, 122));

    while (!nums.empty()) {
        std::print("{} ", nums.top());
        nums.pop();
    }
    return 0;
}
