//
// Created by Peter Sims on 1/26/25.
//

#include <print>
#include "../exercise_classes/doubly_linked.h"

using namespace dsac::list;
// have a begin and end iterator
// have end move first, check if they are equal, then move left if not
// this will allow for even numbered lists to have the left of center one

template <typename T>
T get_midpoint(const DoublyLinkedList<T>& list) {
    auto left{list.begin()};
    auto right{--list.end()};
    while (left != right) {
        --right;
        if (left == right){break;};
        ++left;
    }
    return *left;
}

int main() {
    DoublyLinkedList<int>list;
    for (int i{0}; i < 8; ++i) {
        list.push_back(i);
    }
    for (int i : list) std::print("{} ", i);
    std::println("" );
    std::println("{}", get_midpoint(list));

    DoublyLinkedList<int>list2;
    for (int i{0}; i < 7; ++i) {
        list2.push_back(i);
    }
    for (int i : list2) std::print("{} ", i);
    std::println("" );
    std::println("{}", get_midpoint(list2));


    return 0;
}
