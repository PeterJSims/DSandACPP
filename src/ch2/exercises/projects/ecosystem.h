//
// Created by Peter Sims on 11/22/24.
//

#ifndef ANIMAL_H
#define ANIMAL_H

#include <array>
#include <set>
#include <random>
#include "animals.h"


class Ecosystem {
    enum class AnimalTypes { bear, fish };

    static Animal* generate_cell();

    static Bear* random_bear();

    static Fish* random_fish();

public
:
    ~Ecosystem() {
        for (int i{0}; i < ecosystem_cells.size(); ++i) {
            delete ecosystem_cells[i];
        }
    }

    void run_ecosystem();

private
:
    constexpr static int ecosystem_size{30};
    void generate_starting_ecosystem();
    static Animal* generate_animal();
    void turn();
    void place_new_animal(AnimalTypes animal);
    void handle_animal_collision(int starting_idx, int new_idx);
    void print() const;
    bool finished() const;


    std::array<Animal*, ecosystem_size> ecosystem_cells{};
    std::set<int> empty_cells{};
};


#endif //ANIMAL_H
