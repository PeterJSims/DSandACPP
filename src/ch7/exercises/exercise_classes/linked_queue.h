//
// Created by Peter Sims on 1/28/25.
//

#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "../ch6/exercises/exercise_classes/singly_linked.h"

using namespace dsac::list;

template <typename T, typename Container = SinglyLinkedList<T>>
class LinkedQueue {
    Container data;

public:
    void push(const T& elem) { data.push_back(elem); }
    void pop() { data.pop_front(); }
    T& front() { return data.front(); }
    const T& front() const { return data.front(); }
    T& back() { return data.back(); }
    const T& back() const { return data.back(); }
    int size() { return data.size(); }
    bool empty() { return data.empty(); }
};


#endif //LINKEDQUEUE_H
