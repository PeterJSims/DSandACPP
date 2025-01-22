//
// Created by Peter Sims on 1/21/25.
//

#include <print>


int main() {
    // 4 x 2
    constexpr int n{4};
    constexpr int m{2};

    constexpr int n_by_m[n][m] = {
        {1, 2}, {3, 4}, {5, 6}, {7, 8}
    };
    int m_by_n[m][n];

    for (int i{0}; i < n; ++i) {
        for (int j{0}; j < m; ++j) {
            m_by_n[j][i] = n_by_m[i][j];
        }
    }

    for (int i{0}; i < m; ++i) {
        for (int j{0}; j < n; ++j) {
            std::print("{}", m_by_n[i][j]);
        }
        std::println("{}", "");
    }


    return 0;
}
