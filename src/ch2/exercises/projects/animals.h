//
// Created by Peter Sims on 11/22/24.
//

#ifndef ANIMALS_H
#define ANIMALS_H

class Animal {

public:
    bool is_male;
    double strength;
    Animal(bool is_male, double strength)
        : is_male(is_male),
          strength(strength) {
    }

    virtual ~Animal() = default;

};

class Bear final : public Animal {
public:
    Bear(bool is_male, double strength)
        : Animal(is_male, strength) {
    }
};

class Fish final : public Animal {
public:
    Fish(bool is_male, double strength)
        : Animal(is_male, strength) {
    }
};
#endif //ANIMALS_H
