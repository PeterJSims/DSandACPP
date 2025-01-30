//
// Created by Peter Sims on 1/30/25.
//


#include <stack>
#include <print>

template <typename T, typename Container= std::stack<T>>
class StacksDeque {
    Container m_data1; // back to front
    Container m_data2; // front to back

    static void transfer(std::stack<T>& one, std::stack<T>& two) {
        while (!one.empty()) {
            two.push(one.top());
            one.pop();
        }
    }

public:
    void push_front(const T& elem) {m_data2.push(elem);};

    void push_back(const T& elem) {m_data1.push(elem);}

    void pop_front() {
        if (m_data2.empty()) {
            transfer(m_data1, m_data2);
        }
        m_data2.pop();
    }

    void pop_back() {
        if (m_data1.empty()) {
            transfer(m_data2, m_data1);
        }
        m_data1.pop();
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

    T& back() {
        if (m_data1.empty()) {
            transfer(m_data2, m_data1);
        }
        return m_data1.top();
    }

    const T& back() const {
        if (m_data1.empty()) {
            transfer(m_data2, m_data1);
        }
        return m_data1.top();
    };

    // Because of the frequent transfers, no duplicated entries will exist between the two stacks
    int size() {return m_data1.size() + m_data2.size();}

    bool empty() {return size() == 0;};
};


int main() {
    StacksDeque<int> stacks_deque;
    stacks_deque.push_front(1);
    stacks_deque.push_back(2);

    std::println("{}", stacks_deque.front());
    std::println("{}", stacks_deque.back());
    stacks_deque.pop_back();
    std::println("{}", stacks_deque.back());
    stacks_deque.push_front(0);
    std::println("{}", stacks_deque.front());
    std::println("{}", stacks_deque.size());

    return 0;
}
