//
// Created by Peter Sims on 1/26/25.
//
#include <print>
#include <algorithm>
#include "../exercise_classes/favorites_list_mtf.h"

using namespace dsac::list;

int main() {
    constexpr int n{5};
    FavoritesListMTF<char> list;

    for (int i{0}; i < n; ++i) {
        list.access('a' + i);
    }
    auto result{list.get_favorites(n)};

    int count{0};
    for (char value : result) {
        for (int i{0}; i < count; ++i) {
            list.access(value);
        }
        ++count;
    }
    result = list.get_favorites(n);

    std::println("{}", result);

    return 0;
}
