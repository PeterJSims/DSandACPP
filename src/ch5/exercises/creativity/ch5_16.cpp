//
// Created by Peter Sims on 1/22/25.
//
#include "../exercise_classes/unsorted_scoreboard.h"

using namespace std;
using namespace dsac::array;

// see UnsortedScoreboard class linked above for add()/remove()/other adjustments
int main() {
    const int cap{5};
    UnsortedScoreboard highscores(cap);

    const string names[] = {"Rob", "Mike", "Rose", "Jill", "Jack", "Anna", "Paul", "Bob"};
    const int scores[] = {750, 1105, 590, 740, 510, 660, 720, 400};
    const int n = std::size(scores);

    cout << "Using scoreboard with capacity " << cap << endl;
    for (int i = 0; i < n; i++) {
        GameEntry ge{names[i], scores[i]};
        cout << "Adding " << scores[i] << " from " << names[i] << endl;
        highscores.add(scores[i], names[i]);
        cout << " Scoreboard: ";
        int s = highscores.get_num_entries();
        for (int j = 0; j < s; j++) {
            cout << highscores.get_entry(j);
            if (j < s - 1)
                cout << ", ";
            else
                cout << endl;
        }
    }

    int loc[] = {3, 0, 1, 1, 0};
    for (int j : loc) {
        cout << "Removing score at index " << j << endl;
        highscores.remove(j);
        cout << highscores << endl;
    }

    Scoreboard atari(10);

    try {
        atari.remove(0);
    } catch (out_of_range& e) {
        cout << "Intentionally caused and caught exception: " << e.what() << endl;
    }

    vector<Scoreboard> arcade;
    arcade.push_back(highscores);
    arcade.push_back(atari);

    return 0;
}
