//
// Created by Peter Sims on 12/21/24.
//
#pragma once

#include <vector>
#include <random>
#include <algorithm>

namespace vector_generators {
    inline std::vector<int> random_int_vector(const int length, const int lower_bound = 0, const int upper_bound = 10000) {
        std::random_device engine{};
        std::uniform_int_distribution int_range{lower_bound, upper_bound};
        std::vector<int> random_vector;
        for (int i{0}; i < length; ++i) {
            random_vector.push_back(int_range(engine));
        }
        return random_vector;
    }

    inline std::vector<double> random_double_vector(const double length, const double lower_bound = 0,
                                              const double upper_bound = 10000) {
        std::random_device engine{};
        std::uniform_real_distribution double_range{lower_bound, upper_bound};
        std::vector<double> random_vector;
        for (int i{0}; i < length; ++i) {
            random_vector.push_back(double_range(engine));
        }
        return random_vector;
    }

    inline std::vector<bool> random_bool_vector(const double length) {
        std::random_device engine{};
        std::bernoulli_distribution bernoulli{0.5};
        std::vector<bool> random_vector;
        for (int i{0}; i < length; ++i) {
            random_vector.push_back(bernoulli(engine));
        }
        return random_vector;
    }

    template <typename T>
    void shuffle_vector(std::vector<T>& v) {
        std::random_device rd;
        std::mt19937 gen{rd()};
        std::ranges::shuffle(v, gen);
    }
}
