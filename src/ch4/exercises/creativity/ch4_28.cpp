//
// Created by Peter Sims on 1/16/25.
//
#include <print>

// the key is that it is sorted -- use linear search with binary search (n log n)

int binary_search(int data[], int target, int low, int high) {
    if (low > high)
        return -1;
    else {
        int mid{(low + high) / 2};
        if (target == data[mid])
            return mid; // found a match
        else if (target < data[mid])
            return binary_search(data, target, low, mid - 1); // recur left of the middle
        else
            return binary_search(data, target, mid + 1, high); // recur right of the middle
    }
}

std::pair<int, int> find_sum(int data[], int target, int n, int idx) {
    if (idx > n) {
        return {-1, -1};
    }
    auto value{data[idx]};
    auto result{binary_search(data, target - value, 0, n - 1)};
    if (result != -1) {
        return {idx, result};
    } else {
        return find_sum(data, target, n, idx + 1);
    }
}
std::pair<int, int> find_sum(int data[], int target, int n) {
    return find_sum(data, target, n, 0);

}

int main() {
    int nums[]{3, 9, 12, 15, 16, 23};

    std::println("{}", find_sum(nums, 25, std::size(nums), 0));
    std::println("{}", find_sum(nums, 43, std::size(nums), 0));


    return 0;
}

