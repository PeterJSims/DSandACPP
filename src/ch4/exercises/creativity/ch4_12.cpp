//
// Created by Peter Sims on 1/15/25.
//


#include <print>

// will cause missed values
int binary_search_iterative(int data[], int n, int target) {
    int low{0};
    int high{n - 1};
    std::println("{:5}{:5}", "Low", "High");

    while (low <= high) {
        int mid{(low + high) / 2};
        if (target <= data[mid])
            high = mid - 1;
        else
            low = mid + 1;
        std::println("{:<5}{:<5}", low, high);
    }
    std::println("");
    return low;
}

int main() {
    int data[]{2, 4, 5, 7, 8, 9, 12, 14, 17, 19, 22, 25, 27, 28, 33, 37};
    // returns 10th position (22)
    std::println("{}",
                 binary_search_iterative(data, 16, 17));

    return 0;
}
