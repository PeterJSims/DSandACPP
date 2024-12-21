//
// Created by Peter Sims on 11/22/24.
//

#include "vector.h"
#include "complex.h"

int main() {
    constexpr int size{5};

    // testing Vector operations
    Vector<int> v(size);
    for (int i{0}; i < size; ++i) {
        v[i] = i;
    }

    for (int i{0}; i < size; ++i) {
        std::cout << v[i] << " ";
    }
    std::cout << '\n';

    Vector v2{std::vector{2, 4, 6, 8, 10}};
    for (int i{0}; i < size; ++i) {
        std::cout << v2[i] << " ";
    }
    std::cout << '\n';
    auto added{v + v2};
    auto subtracted = v - v2;
    auto multiplied = v * v2;
    auto scalar{v * 3};


    v.print();
    subtracted.print();
    multiplied.print();
    scalar.print();
    std::cout << "\n\n";
    // testing Complex class
    Complex complex{1.5, -3};
    Complex complex2{-5, 4.8};

    const auto added_complex{complex + complex2};
    const auto added_complex2{complex +3};
    const auto subtracted_complex{complex - complex2};
    const auto subtracted_complex2{complex - 5};
    const auto multiplied_complex{complex * complex2};
    const auto multiplied_complex2{complex * .52};
    std::cout << "Complex " << complex << '\n';
    std::cout << "Complex2 " << complex2 << '\n';
    std::cout << added_complex << "\n";
    std::cout << added_complex2 << "\n";
    std::cout << subtracted_complex << "\n";
    std::cout << subtracted_complex2 << "\n";
    std::cout << multiplied_complex << "\n";
    std::cout << multiplied_complex2 << "\n";
    std::cout << "\n\n";
    //

    // Vector with Complex
    std::vector comp{Complex(3, 2), Complex(4.1, -3)};
    std::vector comp2{Complex(-1.2, 0), Complex(-3.5, .8)};
    Vector complex_vector(comp);
    Vector complex_vector2(comp2);

    auto added_complex_vector{complex_vector + complex_vector2};
    auto subtracted_complex_vector{complex_vector - complex_vector2};
    auto multiplied_complex_vector{complex_vector * complex_vector2};

    added_complex_vector.print();
    subtracted_complex_vector.print();
    multiplied_complex_vector.print();

    return 0;
}
