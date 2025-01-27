//
// Created by Peter Sims on 1/26/25.
//
#include <print>
#include "../exercise_classes/singly_linked.h"

using namespace dsac::list;
// see singly_linked.h for rotate() method
int main() {
    SinglyLinkedList<int> list;
    for (int i{0}; i < 5; ++i) {
        list.push_back(i);
    }
    for (int i{0}; i < 5; ++i) {
        std::println("Front: {} Back: {}", list.front(), list.back());
        list.rotate();
    }
    std::println("Front: {} Back: {}\n", list.front(), list.back());

    SinglyLinkedList<int> list2;
    list2.push_back(1);
    list2.push_back(2);
    std::println("Front: {} Back: {}", list2.front(), list2.back());
    list2.rotate();
    std::println("Front: {} Back: {}", list2.front(), list2.back());
    list2.rotate();
    std::println("Front: {} Back: {}", list2.front(), list2.back());
    return 0;
}
