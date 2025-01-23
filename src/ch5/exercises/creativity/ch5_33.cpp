//
// Created by Peter Sims on 1/23/25.
//

#include <print>


int*** array_addition_3D(int*** one, int oneX, int oneY, int oneZ, int*** two, int twoX, int twoY, int twoZ) {
    if (oneX != twoX || oneY != twoY || oneZ != twoZ) {
        throw std::invalid_argument("Arrays must be of the same dimensions");
    }
    const auto returnArr = new int**[oneX];
    for (int i{0}; i < oneX; ++i) {
        returnArr[i] = new int*[oneY];
        for (int j{0}; j < oneY; ++j) {
            returnArr[i][j] = new int[oneZ];
        }
    }

    for (int i{0}; i < oneX; ++i) {
        for (int j{0}; j < oneY; ++j) {
            for (int k{0}; k < oneZ; ++k) {
                returnArr[i][j][k] = one[i][j][k] + two[i][j][k];
            }
        }
    }
    return returnArr;
}

int main() {
    int a{2}, b{3}, c{4};
    auto one = new int**[a];
    auto two = new int**[a];
    for (int i{0}; i < a; ++i) {
        one[i] = new int*[b];
        two[i] = new int*[b];
        for (int j{0}; j < b; ++j) {
            one[i][j] = new int[c];
            two[i][j] = new int[c];
        }
    }
    for (int i{0}; i < a; ++i) {
        for (int j{0}; j < b; ++j) {
            for (int k{0}; k < c; ++k) {
                one[i][j][k] = i * j * k;
                two[i][j][k] = -(i * j * k);
            }
        }
    }
    const auto newArr{array_addition_3D(one, a, b, c, two, a, b, c)};
    for (int i{0}; i < a; ++i) {
        for (int j{0}; j < b; ++j) {
            for (int k{0}; k < c; ++k) {
                std::print("{} ", newArr[i][j][k]);
            }
            std::println("{}", "");
        }
        std::println("{}", "");
    }

    delete[] one;
    delete[] two;
    delete[] newArr;
    return 0;
}
