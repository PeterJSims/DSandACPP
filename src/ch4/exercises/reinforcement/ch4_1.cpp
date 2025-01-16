//
// Created by Peter Sims on 1/14/25.
//


#include <print>

// Time: O(n), Space O(log n)
int binary_max(int data[], int low, int high) {
    if (low >= high) {
        return std::max(data[low], data[high]);
    }
    const int mid{(low + high) / 2};
    return std::max(binary_max(data, low, mid), binary_max(data, mid + 1, high));
}

int binary_max(int data[], int n) {
    return binary_max(data, 0, n - 1);
}

// Time: O(n), Space O(n)
int linear_max(int data[], int n) {
    if (n < 0) {
        return INT_MIN;
    }
    return std::max(data[n], linear_max(data, n - 1));
}


int main() {
    int test[]{1, 3, -2, 5, 11, 32, 94, 11, 6};
    std::println("{}", binary_max(test, sizeof(test) / sizeof(test[0])));
    std::println("{}", linear_max(test, sizeof(test) / sizeof(test[0])));

    return 0;
}
