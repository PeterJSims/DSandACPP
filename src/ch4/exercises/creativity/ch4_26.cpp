//
// Created by Peter Sims on 1/15/25.
//

#include <sstream>
#include <vector>

void evens_before_odds(std::vector<int>& ints, int l, int r) {
    if (l > r) {
        return;
    }
    if (ints[r] % 2 != 0) {
        return evens_before_odds(ints, l, r - 1);
    } else {
        std::swap(ints[l], ints[r]);
        return evens_before_odds(ints, l + 1, r);
    }
}

void evens_before_odds(std::vector<int>& ints) {
    evens_before_odds(ints, 0, ints.size() - 1);
}

int main() {
    std::vector ints{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    evens_before_odds(ints);
    std::println("{:n}", ints);

    return 0;
}
