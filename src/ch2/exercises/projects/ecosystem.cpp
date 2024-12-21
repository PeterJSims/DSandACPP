//
// Created by Peter Sims on 11/22/24.
//

#include "ecosystem.h"
#include <iostream>
#include <random>
#include <chrono>
#include <algorithm>
#include <typeinfo>


namespace RandomGenerators {
    static std::default_random_engine engine;
    std::uniform_int_distribution<int> fish_strength{1, 5};
    std::uniform_int_distribution<int> bear_strength{15, 100};
    std::uniform_int_distribution<int> cell_choice{0, 2};
    std::uniform_int_distribution<int> animal_choice{0, 1};
    std::bernoulli_distribution gender{0.5};
}

using namespace RandomGenerators;

Animal* Ecosystem::generate_cell() {
    const auto choice{cell_choice(engine)};
    Animal* return_value;
    switch (choice) {
    case 0:
        return_value = nullptr;
        break;
    case 1:
        return_value = random_bear();
        break;
    case 2:
        return_value = random_fish();
        break;
    default:
        return_value = nullptr;
    }
    return return_value;
}

Bear* Ecosystem::random_bear() {
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    return new Bear(gender(engine), bear_strength(engine));
}

Fish* Ecosystem::random_fish() {
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    return new Fish(gender(engine), fish_strength(engine));
}

void Ecosystem::print() const {
    std::cout << "~ ";
    for (const auto& cell : ecosystem_cells) {
        if (dynamic_cast<Bear*>(cell)) {
            std::cout << "B ";
        }
        else if (dynamic_cast<Fish*>(cell)) {
            std::cout << "F ";
        }
        else {
            std::cout << "~ ";
        }
        std::cout << "~ ";
    }
    std::cout << std::endl;
}

void Ecosystem::generate_starting_ecosystem() {
    for (int i{0}; i < ecosystem_cells.size(); ++i) {
        const auto cell{generate_cell()};
        if (cell == nullptr) {
            empty_cells.insert(i);
        }
        ecosystem_cells[i] = cell;
    }
}

Animal* Ecosystem::generate_animal() {
    auto choice{animal_choice(engine)};
    Animal* animal;
    if (choice == 0) {
        animal = random_bear();
    }
    else {
        animal = random_fish();
    }
    return animal;
}


void Ecosystem::turn() {
    print();
    for (int i{0}; i < ecosystem_size; ++i) {
        auto current_cell_contents{ecosystem_cells[i]};
        if (current_cell_contents != nullptr) {
            // 0 - left, 1 - stay, 2- right
            const auto cell_direction_number{cell_choice(engine)};

            if (cell_direction_number == 0 and i > 0) {
                auto left_contents{ecosystem_cells[i - 1]};
                if (left_contents == nullptr) {
                    // Just move the animal
                    ecosystem_cells[i - 1] = current_cell_contents;
                    ecosystem_cells[i] = nullptr;
                    empty_cells.insert(i);
                }
                else {
                    // Handle the two animals interacting
                    handle_animal_collision(i, i - 1);
                }
            }
            else if (cell_direction_number == 1 and i < ecosystem_size - 1) {
                auto right_contents{ecosystem_cells[i + 1]};
                if (right_contents == nullptr) {
                    // Just move the animal
                    ecosystem_cells[i + 1] = current_cell_contents;
                    ecosystem_cells[i] = nullptr;
                    empty_cells.insert(i);
                }
                else {
                    // Handle the two animals interacting
                    handle_animal_collision(i, i + 1);
                }
            }
            else {
                // no movement thus no action
                continue;
            }
        }
    }
}

void Ecosystem::place_new_animal(AnimalTypes animal) {
    if (!finished()) {
        // TODO: Better way to do this? I need a random entry from an ordered set
        // Create a vector of the empty cells to shuffle
        std::vector<int> currently_empty;
        currently_empty.reserve(empty_cells.size());
        for (int empty_cell : empty_cells) {
            currently_empty.push_back(empty_cell);
        }
        // Shuffle the new vector and get a random entry, representing an array index
        std::mt19937 gr(engine());
        std::ranges::shuffle(currently_empty, gr);
        const auto rand_idx{currently_empty[0]};

        // Create and place animal
        Animal* new_animal;
        switch (animal) {
        case AnimalTypes::bear:
            new_animal = random_bear();
            break;
        case AnimalTypes::fish:
            new_animal = random_fish();
            break;
        default:
            new_animal = nullptr;
        }
        ecosystem_cells[rand_idx] = new_animal;

        // Clear index from set of empty cells
        empty_cells.erase(rand_idx);
    }
}

void Ecosystem::handle_animal_collision(const int starting_idx, const int new_idx) {
    auto first_animal(ecosystem_cells[starting_idx]);
    auto second_animal(ecosystem_cells[new_idx]);

    // Mating condition
    if (typeid(first_animal) == typeid(second_animal) && second_animal->is_male != first_animal->is_male) {
        if (dynamic_cast<Bear*>(first_animal)) {
            place_new_animal(AnimalTypes::bear);
        }
        else {
            place_new_animal(AnimalTypes::fish);
        }
    }
    else {
        // Fighting condition -- all
        if (first_animal->strength > second_animal->strength) {
            delete ecosystem_cells[new_idx];
            ecosystem_cells[new_idx] = first_animal;
            ecosystem_cells[starting_idx] = nullptr;
            empty_cells.insert(starting_idx);
        }
        else {
            // Challenging animal loses fight and cell is cleared
            delete ecosystem_cells[starting_idx];
            ecosystem_cells[starting_idx] = nullptr;
            empty_cells.insert(starting_idx);
        }
    }
}

void Ecosystem::run_ecosystem() {
    generate_starting_ecosystem();
    while (!finished()) {
        turn();
    }
    print();
}

bool Ecosystem::finished() const {
    return empty_cells.empty();
}
