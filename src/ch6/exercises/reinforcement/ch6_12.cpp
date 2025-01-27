//
// Created by Peter Sims on 1/26/25.
//
#include <print>
#include "../exercise_classes/doubly_linked.h"

// doubly_linked.h for index(T el) method
using namespace dsac::list;
int main() {
    DoublyLinkedList<int> list;
    for (int i{0}; i < 20; ++i) {
        list.push_back(i * i);
    }
    for (int i : list) std::print ("{} ", i);
    std::println("");

    std::println("Index of {}: {}", 64, list.index(64));
    std::println("Index of {}: {}", 33, list.index(33));


    DoublyLinkedList<int> list2;
    std::println("Index of {} on an empty list: {}", 1, list2.index(1));
    list2.push_back(1);
    std::println("Index of {} on a list of just {}: {}", 1, 1, list2.index(1));

    return 0;
}
