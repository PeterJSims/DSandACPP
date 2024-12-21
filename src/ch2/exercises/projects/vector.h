//
// Created by Peter Sims on 11/21/24.
//

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <ostream>
#include <vector>

template <typename T>
concept Arithmetic = requires(T a, T b) {
    a + b;
    a - b;
    a * b;
};


template <Arithmetic T>
class Vector {

public:
    explicit Vector(std::vector<T> items)
        : items(std::move(items)) {
    }

    explicit Vector(int size) {
        for (int i{0}; i < size; ++i) {
            items.push_back(T{});
        }
    }

    [[nodiscard]] size_t get_size() const {
        return items.size();
    }

    Vector<T> operator+(const Vector<T>& other)  {
        if (!this->are_equal(other)) {
            std::cout << "Cannot add two unequal vectors";
            return *this;
        }
        std::vector<T> items;
        for (int i{0}; i < this->get_size(); ++i) {
            items.push_back(this->items[i] + other.items[i]);
        }
        return Vector(items);
    }

    Vector<T> operator-(const Vector<T>& other)  {
        if (!this->are_equal(other)) {
            std::cout << "Cannot subtract two unequal vectors";
            return *this;
        }
        std::vector<T> items;
        for (int i{0}; i < this->get_size(); ++i) {
            items.push_back(this->items[i] - other.items[i]);
        }
        return Vector(items);
    }

    Vector<T> operator*(const Vector<T>& other) {
        if (!this->are_equal(other)) {
            std::cout << "Cannot multiply two unequal vectors";
            return *this;
        }
        std::vector<T> items;
        for (int i{0}; i < this->get_size(); ++i) {
            items.push_back(this->items[i] * other.items[i]);
        }
        return Vector(items);
    }

    Vector<T> operator*(const T& scalar)  {
        std::vector<T> items{this->items};
        for (int i{0}; i < this->get_size(); ++i) {
            items[i] *= scalar;
        }
        return Vector(items);
    }


    T& operator[](int i) {
        if (i >= get_size()) {
            throw std::out_of_range("Index is out of range");
        }
        return items[i];
    }

    const T& operator[](int i) const {
        if (i >= get_size()) {
            throw std::out_of_range("Index is out of range");
        }
        return items[i];
    }

    T dot(const Vector<T>& other) {
        if (!this->are_equal(other)) {
            std::cout << "Cannot get dot product two unequal vectors";
            return *this;
        }
        T result{0};
        for (int i{0}; i < get_size(); ++i) {
            result += items[i] * other.items[i];
        }
        return result;
    }


    void print() {
        for (auto item : items) std::cout << item << " ";
        std::cout << '\n';
    }
private:
    std::vector<T> items;

    bool are_equal(const Vector& other) const {
        return this->get_size() == other.get_size();
    }

};


#endif //VECTOR_H
