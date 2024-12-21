//
// Created by Peter Sims on 11/22/24.
//
#pragma once

#include <algorithm>

class Polygon {
public:
    virtual ~Polygon() = default;
    virtual double area() = 0;
    virtual double perimiter() = 0;
};

// Triangle, Quadrilateral, Pentagon, Hexagon, and Octagon

class Triangle : public Polygon {
    double a{}, b{}, c{};

public:
    explicit Triangle(double one) :
        a(one), b(one), c(one) {
    }

    Triangle(double one, double two, double three)
        : a(one), b(two), c(three) {
    }

    double area() override {
        double s{(a + b + c) / 2};
        return sqrt(s * (s - a) * (s - b) * (s - c));
    };
    double perimiter() override { return a + b + c; };

    double get_a() const {
        return a;
    }

    void set_a(const double a) {
        this->a = a;
    }

    double get_b() const {
        return b;
    }

    void set_b(const double b) {
        this->b = b;
    }

    double get_c() const {
        return c;
    }

    void set_c(const double c) {
        this->c = c;
    }
};

class IsoscelesTriangle final : public Triangle {
public:
    IsoscelesTriangle(double base, double legs)
        : Triangle(base, legs, legs) {
    }
};

class EquilateralTriangle final : public Triangle {
public:
    explicit EquilateralTriangle(double one)
        : Triangle(one) {
    }
};


class Quadrilateral : public Polygon {
    double b{}, h{};

public:
    Quadrilateral(double base, double height)
        : b(base), h(height) {
    }

    double area() override {
        return b * h;
    };
    double perimiter() override { return 2 * b + 2 * h; };
};

class Square final : public Quadrilateral {
public:
    Square(double side): Quadrilateral(side, side) {
    }
};

class Rectangle final : public Quadrilateral {
public:
    Rectangle(double base, double height): Quadrilateral(base, height) {
    }
};

class RegulardPolygon : public Polygon {
    double side_length;
    int num_sides;

public:
    RegulardPolygon(double side, int num_sides)
        : side_length(side), num_sides(num_sides) {
    }

    double area() override {
        return .5 * perimiter() * apothem();
    };

    double perimiter() override {
        return side_length * num_sides;
    };

    double apothem() {
        return (side_length) / (2 * tan(M_PI / num_sides));
    }
};

class Pentagon final : public RegulardPolygon {
public:
    explicit Pentagon(double side)
        : RegulardPolygon(side, 5) {
    }
};

class Hexagon final : public RegulardPolygon {
public:
    explicit Hexagon(double side)
        : RegulardPolygon(side, 6) {
    }
};

class Octagon final : public RegulardPolygon {
public:
    explicit Octagon(double side)
        : RegulardPolygon(side, 8) {
    }
};
