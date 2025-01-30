//
// Created by Peter Sims on 1/29/25.
//

#include <print>
#include "../exercise_classes/linked_queue.h"

// 17 items remaining -- order does not matter, top() does not affect size, simple arithmetic to determine the solution

int main() {
        LinkedQueue<int> queue;
        for (int i{0}; i < 32; ++i) {
            queue.push(i);
        }
        for (int i{0}; i < 15; ++i) {
            queue.pop();

        }

        std::println("Size: {}", queue.size());
    return 0;
}
