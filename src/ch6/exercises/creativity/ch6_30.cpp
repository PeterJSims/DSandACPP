//
// Created by Peter Sims on 1/27/25.
//


#include <print>
#include "../exercise_classes/doubly_linked.h"

using namespace dsac::list;

// see doubly_linked.h for (hackish) iterator check
int main() {
    DoublyLinkedList<int> list;
    DoublyLinkedList<int> list2;
    for (int i{0}; i < 20; ++i) {
        list.push_back(-(i * i));
        list2.push_back(i + 1);
    }

    // Insertion still works
    list.insert(list.begin(), 5);
    for (int i : list) std::print("{} ", i);
    std::println("");

    try {
        auto badIterator{list2.begin()};
        ++badIterator;
        ++badIterator;

        list.insert(badIterator, 4);

        for (int i : list) std::print("{} ", i);
        std::println("");
        for (int i : list2) std::print("{} ", i);
        std::println("");
    } catch (...) {
        std::println("{}", "Check has worked");
    }

    return 0;
}
