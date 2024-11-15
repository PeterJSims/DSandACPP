//
// Created by Peter Sims on 11/15/24.
//

#include <print>
#include <set>

bool are_distinct(int vals[], int n) {
    std::set<int> int_set;
    for (int i{0}; i < n; ++i) {
        if(int_set.contains(vals[i])) {
            return false;
        }
        int_set.insert(vals[i]);
    }
    return true;
}

int main() {
    int arr[]{1, 2, 3, 4};
    int arr2[]{1, 2, 3, 2};

    std::println("{}", are_distinct(arr, std::size(arr)));
    std::println("{}", are_distinct(arr2, std::size(arr2)));

}

