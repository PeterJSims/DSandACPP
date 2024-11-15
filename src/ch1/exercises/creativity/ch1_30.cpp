//
// Created by Peter Sims on 11/15/24.
//

#include <iostream>

double norm(double v[], const int n, const int p = 2) {
    double radicand{0.0};
    for (int i{0}; i < n; ++i) {
        radicand += pow(v[i], p);
    }
    std::cout << radicand << "\n";
    double p_norm{pow(radicand, 1.0 / p)};
    return p_norm;
}


int main() {
    double euclidian[]{4, 3};
    double doubles[]{2.2, 3.3, 4.4, 5.5};


    std::cout << norm(euclidian, std::size(euclidian)) << '\n';
    std::cout << norm(doubles, std::size(doubles), 3) << '\n';
}
