//
// Created by Peter Sims on 1/27/25.
//
#include <print>
#include "../exercise_classes/doubly_linked.h"


// see doubly_linked.h for at(int k) method implementation
using namespace dsac::list;
int main() {
    DoublyLinkedList<char> list;
    for (int i{0}; i < 10; ++i) {
        list.push_back('a' + i);
    }

    std::println("{}", list.at(3));

    return 0;
}
