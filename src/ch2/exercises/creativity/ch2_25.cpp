//
// Created by Peter Sims on 11/21/24.
//

#include <iostream>


class Line {
    double a;
    double b;

public:
    Line(const double a, const double b)
        : a(a),
          b(b) {
    }

    bool are_parallel(const Line& other) const {
        return a == other.a;
    }
    double intersect(const Line& other) const {
        if(are_parallel(other)) {
            throw std::invalid_argument("No intersection exists -- the lines are parallel");
        }

        return (other.b - b) / (a - other.a);

    }

    friend std::ostream& operator<<(std::ostream& os, const Line& obj) {
        return os
            << "y = " << obj.a << "x + " << obj.b;
    }
};


/*
y = 3x + .25
y = .8x - 3
y = .8x +6
 */
int main() {
    Line l{3, .25};
    Line l2{.8, -3};
    Line l3{.8, 6};

    std::cout << l.intersect(l2) << '\n';
    try {
    std::cout << l2.intersect(l3);
    } catch (std::invalid_argument& e) {
        std::cout << e.what() << '\n';
    }
    std::cout << l.intersect(l3) << '\n';


    return 0;
}


