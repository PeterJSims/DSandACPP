//
// Created by Peter Sims on 1/30/25.
//

#include <print>
#include <memory>

// testing with different front (f) settings
template <typename T>
class ArrayQueue {
    std::unique_ptr<T[]> data;
    int capacity;
    int sz{0};
    int f{3};

public:
    ArrayQueue(int cap = 1000) : capacity(cap), data(std::make_unique<T[]>(cap)) {
    }


    int size() const { return sz; }
    bool empty() const { return sz == 0; }
    const T& front() const { return data[f]; }
    T& front() { return data[f]; }
    const T& back() const { return data[(f + sz - 1) % capacity]; }
    T& back() { return data[(f + sz - 1) % capacity]; }

    void push(const T& elem) {
        if (size() == capacity)
            throw std::overflow_error("Queue overflow");
        int avail{(f + sz) % capacity};
        data[avail] = elem;
        sz++;
    }

    void pop() {
        f = (f + 1) % capacity;
        sz--;
    }
};

int main() {
    ArrayQueue<int> array_queue(10);
    for (int i{0}; i < 5; ++i) {
        array_queue.push(i);
    }
    array_queue.pop();
    array_queue.pop();
    array_queue.pop();
    array_queue.push(10);

    while (!array_queue.empty()) {
        std::print("{} ", array_queue.front());
        array_queue.pop();
    }

    // Because the math for ArrayQueue  is dependent on modulo operations,
    // changing its starting front position f does not impact operations
    return 0;
}
