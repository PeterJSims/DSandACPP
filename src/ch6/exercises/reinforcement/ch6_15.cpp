//
// Created by Peter Sims on 1/26/25.
//
#include <print>
#include "../exercise_classes/favorites_list_mtf.h"

using namespace dsac::list;

int main() {
    FavoritesListMTF<char> list;
    for (int i{0}; i < 6; ++i) {
        list.access('a' + i);
    }
    for (int i{0}; i < 5; ++i) {
        list.access('a' + i);
    }
    auto result{list.get_favorites(6)};

    std::println("{:n}", result);

    return 0;
}
