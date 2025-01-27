//
// Created by Peter Sims on 1/26/25.
//
#include <print>
#include "../exercise_classes/doubly_linked.h"

using namespace dsac::list;
int main() {
    DoublyLinkedList<int> list;
    DoublyLinkedList<int> list2;
    for (int i{0}; i < 20; ++i) {
        list.push_back(-(i * i));
        list2.push_back(i + 1);
    }
    auto badIterator{list2.begin()};
    ++badIterator;
    ++badIterator;

    // Causes EXC_BAD_ACCESS (code=1, address=0x8) (on M2)
    list.insert(badIterator, 4);

    for (int i : list) std::print ("{} ", i);
    std::println("");
    for (int i : list2) std::print ("{} ", i);
    std::println("");
    return 0;
}
