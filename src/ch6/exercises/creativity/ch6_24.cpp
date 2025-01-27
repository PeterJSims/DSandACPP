//
// Created by Peter Sims on 1/27/25.
//

#include <print>
#include "../exercise_classes/circularly_linked.h"


using namespace dsac::list;

template <typename T>
std::pair<CircularlyLinkedList<T>, CircularlyLinkedList<T>> split(
    CircularlyLinkedList<T>& source) {

    const int n{source.size()};
    CircularlyLinkedList<T> first;
    CircularlyLinkedList<T> second;
    for (int i{0}; i < n; ++i) {
        if (i % 2 == 0) {
            first.push_back(source.front());
        } else {
            second.push_back(source.front());
        }
        source.pop_front();
    }
    return {first, second};
}


int main() {
    CircularlyLinkedList<char> source;
    for (int i{0}; i < 6; ++i) {
        source.push_back('a' + i);
    }

    auto [first, second]{ split(source)};

    std::println("{}", first.size());

    while (!first.empty()) {
        std::println("{} ", first.front());
        first.pop_front();
    }

    while (!second.empty()) {
        std::println("{} ", second.front());
        second.pop_front();
    }

    return 0;
}
