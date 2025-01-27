//
// Created by Peter Sims on 1/26/25.
//

#include <print>
#include "../exercise_classes/singly_linked.h"

using namespace dsac::list;

template <typename  T>
T second_to_last(SinglyLinkedList<T> list) {
    auto trailing{list.begin()};
    auto leading{++(++list.begin())};
    while (leading!= nullptr) {
        ++leading;
        ++trailing;
    }
    return *trailing;
}


int main() {
    SinglyLinkedList<int> list;
    for (int i{0}; i < 5; ++i) {
        list.push_back(i * 3);
    }
    for (int i : list) std::print("{} ", i);
    std::println("");
    std::println("{}", second_to_last(list));


    return 0;
}

