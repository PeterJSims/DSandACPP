//
// Created by Peter Sims on 1/26/25.
//
#include <print>
#include "../exercise_classes/favorites_list.h"

using namespace dsac::list;

int main() {
    constexpr int n{6};

    FavoritesList<char> list;
    for (int i{1}; i < n; ++i) {
        for (int j{0}; j < i; ++j) {
            list.access('a' + i - 1);
        }
    }

    std::println("{}", list.get_favorites(n));
    std::println("{}", list.get_counts());

    list.reset_counts();

    std::println("{}", list.get_favorites(n));
    std::println("{}", list.get_counts());

    return 0;
}
