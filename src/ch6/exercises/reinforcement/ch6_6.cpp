//
// Created by Peter Sims on 1/26/25.
//
#include <print>
#include "../exercise_classes/circularly_linked.h"

using namespace dsac::list;
// see circularly_linked.h for iterative_size() method
int main() {
    CircularlyLinkedList<int> list;
    for (int i{0}; i < 5; ++i) {
        list.push_back(i);
    }

    std::println("{}", list.iterative_size());
    list.pop_front();
    std::println("{}", list.iterative_size());


    CircularlyLinkedList<int> list2;
    for (int i{0}; i < 5; ++i) {
        list2.push_back(1);
    }

    std::println("{}", list2.iterative_size());
    list2.pop_front();
    std::println("{}", list2.iterative_size());

    return 0;
}
