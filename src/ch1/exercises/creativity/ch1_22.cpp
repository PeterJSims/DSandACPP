//
// Created by Peter Sims on 11/15/24.
//

#include <print>


template <typename T>
void reverse_array(T* arr, size_t size) {
    int l = 0;
    int r = size - 1;

    while (l <= r) {
        T temp{arr[l]};
        arr[l] = arr[r];
        arr[r] = temp;
        ++l, --r;
    }
}


int main() {
    int arr[]{1, 2, 3, 4, 5};
    reverse_array(arr, std::size(arr));
    std::println("{:n}", arr);

}

