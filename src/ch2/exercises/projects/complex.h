//
// Created by Peter Sims on 11/22/24.
//

#ifndef COMPLEX_H
#define COMPLEX_H
#include <ostream>


class Complex {
public:
    explicit Complex(const double real = 0.0, const double imaginary = 0.0)
        : real(real),
          imaginary(imaginary) {
    }

    Complex operator+(const Complex& other) const {
        return Complex(this->real + other.real, this->imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const {
        return Complex(this->real - other.real, this->imaginary - other.imaginary);
    }

    Complex operator*(const Complex& other) const {
        return Complex(this->real * other.real, this->imaginary * other.imaginary);
    }

    Complex operator+(const double other) const {
        return Complex(this->real + other, this->imaginary);
    }

    Complex operator-(const double other) const {
        return Complex(this->real - other, this->imaginary);
    }

    Complex operator*(const double other) const {
        return Complex(this->real * other, this->imaginary);
    }


    friend std::ostream& operator<<(std::ostream& os, const Complex& obj) {
        const auto is_negative{obj.imaginary < 0};
        const char sign{is_negative ? '-' : '+'};
        return os
            << obj.real << " " << sign << " " << abs(obj.imaginary) << "i";
    }

private:
    double real;
    double imaginary;
};


#endif //COMPLEX_H
