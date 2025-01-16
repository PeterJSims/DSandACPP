//
// Created by Peter Sims on 1/14/25.
//
#include <print>


int binary_search(int data[], int target, int low, int high) {
    if (low > high)
        return -1;
    else {
        int mid{(low + high) / 2};
        if (target == data[mid])
            return mid;
        else if (target < data[mid])
            return binary_search(data, target, low, mid - 1);
        else
            return binary_search(data, target, mid + 1, high);
    }
}

int binary_search(int data[], int n, int target) {
    return binary_search(data, target, 0, n - 1);
}

int main() {
    int test[]{1, 3, 5, 6, 8, 11};
    std::println("{}", binary_search(test, 6, 3));
    std::println("{}", binary_search(test, 6, 8));
    std::println("{}", binary_search(test, 6, 32));


    return 0;
}
