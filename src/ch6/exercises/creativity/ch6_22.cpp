//
// Created by Peter Sims on 1/26/25.
//
#include <print>
#include "../exercise_classes/singly_linked.h"

using namespace dsac::list;


// see singly_linked.h for reverse()
int main() {
    SinglyLinkedList<int> list;
    for (int i{0}; i < 10; ++i) {
        list.push_back(i);
    }
    for (int i : list) std::print("{} ", i);
    std::println("" );
    list.reverse();
    for (int i : list) std::print("{} ", i);


    return 0;
}
