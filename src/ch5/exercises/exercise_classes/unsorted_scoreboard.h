//
// Created by Peter Sims on 1/22/25.
//

#ifndef UNSORTED_SCOREBOARD_H
#define UNSORTED_SCOREBOARD_H
#include "scoreboard.h"

namespace dsac::array {
    class UnsortedScoreboard final : public Scoreboard {
    public:
        explicit UnsortedScoreboard(const int capacity)
            : Scoreboard(capacity) {
        }

        void add(const int score, const std::string& name) override {
            // find if scoreboard is full.
            if (this->get_num_entries() == this->get_capacity()) {
                // find the lowest item, make sure this is greater than that and replace it if it is
                // if it is not higher than the lowest entry, simply ignore
                if (const auto min_index{get_lowest_entry()}; score > board[min_index].get_score()) {
                    board[min_index] = GameEntry(name, score);
                }
            } else {
                // if it is not: just add it to the last clear index
                board[get_num_entries()] = GameEntry(name, score);
                num_entries++;
            }
        };

        GameEntry remove(const int i) override {
            if (i < 0 || i >= num_entries) throw std::out_of_range("Invalid index");

            // swap the item to be removed with the last item, reduce capacity by 1
            GameEntry entry{board[i]};
            std::swap(board[i], board[num_entries - 1]);
            num_entries--;
            return entry;
        };

    private:
        int get_lowest_entry() const {
            int min_index{0};
            if (Scoreboard::get_num_entries() == 0) {
                return min_index;
            }
            GameEntry min_entry{get_entry(0)};
            for (int i{1}; i < get_num_entries(); ++i) {
                if (get_entry(i).get_score() < min_entry.get_score()) {
                    min_entry = get_entry(i);
                    min_index = i;
                }
            }
            return min_index;
        }
    };
}

#endif //UNSORTED_SCOREBOARD_H
