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
    int data[]{1, 2, 3, 4, 4, 5, 6, 7, 8, 9, 10};
    int data2[]{1, 2, 3, 4, 4, 5, 6, 7, 7,8, 9, 10};
    std::println("{}", binary_search_iterative(data, std::size(data), 4));
    std::println("{}", binary_search_iterative(data2, std::size(data2), 7));

    return 0;
}
