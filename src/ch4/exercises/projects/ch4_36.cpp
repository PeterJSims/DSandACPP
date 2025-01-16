//
// Created by Peter Sims on 1/16/25.
//

#include <print>

void towers_of_hanoi(int n, char source, char target, char aux) {
    if (n > 0) {
        towers_of_hanoi(n - 1, source, aux, target);
        std::println("Moving disk {} from {} to {}", n, source, target);
        towers_of_hanoi(n - 1, aux, target, source);
    }
}

void towers_of_hanoi(int n) {
    towers_of_hanoi(n, 'A', 'C', 'B');
    std::println("Completed in {} moves", (pow(2, n) - 1));
}

int main() {
    towers_of_hanoi(7);
    return 0;
}
