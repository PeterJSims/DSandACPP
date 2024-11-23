//
// Created by Peter Sims on 11/22/24.
//

#include <iostream>
#include "shapes.h"

int main() {
    while (std::cin) {
        int choice;
        std::cout <<
            "Enter a number from the following:\n 1 - Isosceles Triangle | 2 - Equilateral Triangle | 3 - Square | 4 - Rectangle | 5 - Pentagon | 6 - Hexagon | 7 - Octagon | 0 - Quit\n";
        std::cin >> choice;
        switch (choice) {
        case 0:
            return 0;
        case 1: {
            int base, legs;
            std::cout << "Base: ";
            std::cin >> base;
            std::cout << "Legs: ";
            std::cin >> legs;
            auto isosceles_triangle{IsoscelesTriangle(base, legs)};
            std::cout << "Area: " << isosceles_triangle.area() << '\n';
            std::cout << "Perimeter: " << isosceles_triangle.perimiter() << '\n';
            break;
        }

        case 2: {
            int side;
            std::cout << "Side length: ";
            std::cin >> side;
            auto equilateral_triangle{EquilateralTriangle(side)};
            std::cout << "Area: " << equilateral_triangle.area() << '\n';
            std::cout << "Perimeter: " << equilateral_triangle.perimiter() << '\n';
            break;
        }
        case 3: {
            int side;
            std::cout << "Side length: ";
            std::cin >> side;
            auto square{Square(side)};
            std::cout << "Area: " << square.area() << '\n';
            std::cout << "Perimeter: " << square.perimiter() << '\n';
            break;
        }
        case 4: {
            int base, height;
            std::cout << "Base: ";
            std::cin >> base;
            std::cout << "height: ";
            std::cin >> height;
            auto rectangle{Rectangle(base, height)};
            std::cout << "Area: " << rectangle.area() << '\n';
            std::cout << "Perimeter: " << rectangle.perimiter() << '\n';
            break;
        }
        case 5: {
            int side;
            std::cout << "Side length: ";
            std::cin >> side;
            auto pentagon{Pentagon(side)};
            std::cout << "Area: " << pentagon.area() << '\n';
            std::cout << "Perimeter: " << pentagon.perimiter() << '\n';
            break;
        }
        case 6: {
            int side;
            std::cout << "Side length: ";
            std::cin >> side;
            auto hexagon{Hexagon(side)};
            std::cout << "Area: " << hexagon.area() << '\n';
            std::cout << "Perimeter: " << hexagon.perimiter() << '\n';
            break;
        }
        case 7: {
            int side;
            std::cout << "Side length: ";
            std::cin >> side;
            auto octagon{Octagon(side)};
            std::cout << "Area: " << octagon.area() << '\n';
            std::cout << "Perimeter: " << octagon.perimiter() << '\n';
            break;
        }
        default:
            continue;
        }
        std::cout << '\n';
    }
    return 0;
}
