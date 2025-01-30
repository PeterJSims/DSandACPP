//
// Created by Peter Sims on 1/28/25.
//

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <forward_list>

template <typename T, typename Container=std::forward_list<T>>
class LinkedStack {
    Container m_data;
    int m_size{0};

public:
    void push(const T& elem) {
        m_data.push_front(elem);
        ++m_size;
    }

    void pop() {
        m_data.pop_front();
        --m_size;
    }

    T& top() { return m_data.front(); }

    const T& top() const { return m_data.front(); }
    int size() const { return m_size; }
    bool empty() const { return m_size == 0; };
};

#endif //LINKEDSTACK_H
