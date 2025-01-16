//
// Created by Peter Sims on 1/14/25.
//
#include <print>


// TODO: recurse over each row from 0 to n-1
// TODO: recurse over each column of each row from 0 to n-1
int sum_n_by_n_matrix_iterative(int data[][3], int n) {
    int total{0};
    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
            total += data[i][j];
        }
    }
    return total;
}

int sum_n_by_n_matrix_recursive(int data[][3], int n, int i, int j) {
    std::println("{}{}", i, j);
    if (i == 0 && j == 0) {
        // The algorithm has worked from the bottom right entry to this, the top left
        return data[i][j];
    }
    if (j == 0) {
        // next row
        return data[i][j] + sum_n_by_n_matrix_recursive(data, n, i - 1, n - 1);
    } else {
        // traverse the row right the left
        return data[i][j] + sum_n_by_n_matrix_recursive(data, n, i, j - 1);
    }
}

int sum_n_by_n_matrix_recursive(int data[][3], int n) {
    return sum_n_by_n_matrix_recursive(data, n, n - 1, n - 1);
}

int main() {
    int test_array[3][3]{{1, 2, 3}, {3, 4, 5}, {4, 5, 6}};
    std::println("{}", sum_n_by_n_matrix_iterative(test_array, 3));
    std::println("{}", sum_n_by_n_matrix_recursive(test_array, 3));

    return 0;
}
