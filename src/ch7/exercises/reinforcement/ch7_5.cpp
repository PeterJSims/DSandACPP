//
// Created by Peter Sims on 1/28/25.
//

#include <print>
#include "../exercise_classes/linked_queue.h"


int main() {
    LinedQueue<int> queue;

    queue.push(5);
    queue.push(3);
    queue.push(1);

    queue.pop();
    std::println("Size: {}", queue.size());
    std::println("Top item: {}", queue.front());
    queue.push(-1);
    std::println("Top item: {}", queue.front());
    queue.pop();
    std::println("Size: {}", queue.size());
    std::println("Top item: {}", queue.front());
    queue.pop();
    std::println("Size: {}", queue.size());
    std::println("Top item: {}", queue.front());
    return 0;
}
