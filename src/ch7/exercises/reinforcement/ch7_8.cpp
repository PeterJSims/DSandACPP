//
// Created by Peter Sims on 1/29/25.
//
#include <print>


template <typename T>
class ArrayQueue {

private:
    std::unique_ptr<T[]> data;                            // smart pointer to the underlying array
    int capacity;                                         // capacity of the underlying array
    int sz{0};                                            // current number of elements in the queue

public:
    int f{0};                                             // index of the front of the queue
    // Construct a new queue with given capacity (default 1000)
    ArrayQueue(int cap = 1000) : capacity(cap), data(std::make_unique<T[]>(cap)) { }


    int size() const { return sz; }                       // return number of elements in the queue
    bool empty() const { return sz == 0; }                // return whether the queue is currently empty
    const T& front() const { return data[f]; }            // return const reference to the first element
    T& front() { return data[f]; }                        // return live reference to the first element
    const T& back() const { return data[(f+sz-1)%capacity]; }  // return const reference to last element
    T& back() { return data[(f+sz-1)%capacity]; }         // return live reference to the last element

    void push(const T& elem) {                            // add element to the end of the queue
        if (size() == capacity)
            throw std::overflow_error("Queue overflow");
        int avail{(f + sz) % capacity};                   // compute next available index
        data[avail] = elem;
        sz++;
    }

    void pop() {                                         // remove the first element of the queue
        f = (f + 1) % capacity;                          // advance the front one step (circularly)
        sz--;
    }
};


int main() {
    ArrayQueue<int> queue;
    for (int i{0}; i < 32; ++i) {
        queue.push(i);
    }
    for (int i{0}; i < 15; ++i) {
        queue.pop();

    }

    std::println("instance variable f: {}", queue.f);
    return 0;
}
