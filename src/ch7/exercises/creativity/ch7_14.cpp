//
// Created by Peter Sims on 1/29/25.
//
#include <print>
#include <stack>

template <typename T, typename Container = std::stack<T>>
class QueueWithStacks {
    Container m_data1;
    Container m_data2;

    static void transfer(Container& one, Container& two) {
        while (!one.empty()) {
            two.push(one.top());
            one.pop();
        }
    }

public:
    void push(const T& elem) {
        m_data1.push(elem);
    }

    void pop() {
        if (m_data2.empty()) {
            transfer(m_data1, m_data2);
        }
        m_data2.pop();
    }

    T& front() {
        if (m_data2.empty()) {
            transfer(m_data1, m_data2);
        }
        return m_data2.top();
    }

    const T& front() const {
        if (m_data2.empty()) {
            transfer(m_data1, m_data2);
        }
        return m_data2.top();
    }

    int size() {
        return m_data1.size() + m_data2.size();
    }

    bool empty() {
        return m_data1.empty() && m_data2.empty();
    }
};

int main() {
    QueueWithStacks<int> queue;
    for (int i{0}; i < 10; ++i) {
        queue.push(i);
    }
    for (int i{0}; i < 10; ++i) {
        std::println("{} ", queue.front());
        queue.pop();
    }
    return 0;
}
