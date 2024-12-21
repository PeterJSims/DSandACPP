//
// Created by Peter Sims on 12/20/24.
//

// sum of even ints from 0 to 2n is n(n + 1) where n > 0
/* Proof
    0, 2, 4...2n
    2(0, 1, 2, 3, 4... 2n)
    2(0 + 1 + 2 + 3 + 4... n)
    2 * (n * (n + 1) / 2)
    n * (n + 1) -- simplified
 */


#include <print>

int main() {
    constexpr int n{10};
    int sum{0};
    for (int i{0}; i <= 2*n; i += 2) {
        sum += i;
    }

    std::println("{}", sum);

    return 0;
}
