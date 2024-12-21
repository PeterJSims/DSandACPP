//
// Created by Peter Sims on 11/21/24.
//

#include <vector>
#include <print>
#include <set>

bool all_unique(const std::vector<int>& ints) {
    std::set<int> seen;
    for (int entry : ints) {
        if (seen.contains(entry)) {
            return false;
        }
        seen.insert(entry);
    }
    return true;
}

int main() {
    std::vector one{1, 2, 3, 4, 5, 2};
    std::vector two{1, 2, 3, 4, 5, 6, 0, -3};
    std::println("{}", all_unique(one));
    std::println("{}", all_unique(two));

    return 0;
}
