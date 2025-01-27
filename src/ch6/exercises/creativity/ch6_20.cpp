//
// Created by Peter Sims on 1/26/25.
//

#include <print>
#include "../exercise_classes/doubly_linked.h"

using namespace dsac::list;

template <typename T>
void concat_in_n(DoublyLinkedList<T>& one, DoublyLinkedList<T>& two) {
    // without private member access, O(n) iteration to concatenate
    for (auto el : two) {
        one.push_back(el);
    }
}

// see doubly_linked.h for class member concat
int main() {
    DoublyLinkedList<int> one;
    DoublyLinkedList<int> two;
    for (int i{0}; i < 5; ++i) {
        one.push_back(i);
        two.push_back(i + 5);
    }
    for (int i : one) { std::print("{} ", i); }
    std::println("");
    for (int i : two) { std::print("{} ", i); }
    concat_in_n(one, two);
    for (int i : one) { std::print("{} ", i); }
    std::println("");

    one.clear();
    two.clear();

    for (int i{0}; i < 5; ++i) {
        one.push_back(i);
        two.push_back(i + 5);
    }
    for (int i : one) { std::print("{} ", i); }
    std::println("");
    for (int i : two) { std::print("{} ", i); }
    std::println("");
    one.concat(two);
    for (int i : one) { std::print("{} ", i); }
    return 0;
}
