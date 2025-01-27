//
// Created by Peter Sims on 1/26/25.
//

#include <print>
#include "../exercise_classes/singly_linked.h"

using namespace dsac::list;
// see singly_linked.h for iterative_size() method
int main() {
    SinglyLinkedList<int> list;
    for (int i{0}; i < 5; ++i) {
        list.push_back(i);
    }

    std::println("{}", list.iterative_size());
    list.pop_front();
    std::println("{}", list.iterative_size());

    return 0;
}
