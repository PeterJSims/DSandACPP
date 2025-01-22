//
// Created by Peter Sims on 1/22/25.
//
#include <iostream>
#include "../exercise_classes/scoreboard.h"

using namespace dsac::array;

int main() {
    constexpr int cap{5};
    Scoreboard highscores(cap);
    const std::string names[] = {"Rob", "Rob", "Rob", "Jack", "Bob", "Steve"};
    const int scores[] = {750, 1105, 590, 740, 510, 200};
    constexpr int n = std::size(scores);

    std::cout << "Using scoreboard with capacity " << cap << std::endl;
    for (int i = 0; i < n; i++) {
        GameEntry ge{names[i], scores[i]};
        std::cout << "Adding " << scores[i] << " from " << names[i] << std::endl;
        highscores.add(scores[i], names[i]);
        std::cout << " Scoreboard: ";
        const int s = highscores.get_num_entries();
        for (int j = 0; j < s; j++) {
            std::cout << highscores.get_entry(j);
            if (j < s - 1)
                std::cout << ", ";
            else
                std::cout << std::endl;
        }
    }

    return 0;
}
