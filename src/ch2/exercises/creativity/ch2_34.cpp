//
// Created by Peter Sims on 11/21/24.
//

#include <vector>
#include <print>

std::vector<double> product(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size()) {
        throw std::invalid_argument("Vectors must be of equal size");
    }
    std::vector<double> c(a.size());
    for (int i{0}; i < c.size(); ++i) {
        c[i] = a[i] * b[i];
    }
    return c;
}

int main() {
    std::vector a{1.0, 2.02, 3.2, 4.394};
    std::vector b{.30, 5.0, .02, .32};
    auto c{product(a, b)};

    std::println("{:n}", c);
    try {
        std::vector bad{3.0};
        auto x{product(a, bad)};
    }
    catch (std::invalid_argument& e) {
        std::println("{}", e.what());
    }

    return 0;
}
