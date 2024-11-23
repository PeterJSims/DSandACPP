//
// Created by Peter Sims on 11/21/24.
//

#include <ostream>
#include <print>
#include <utility>

template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    Pair(T first, U second)
        : first(std::move(first)),
          second(std::move(second)) {
    }
};


int main() {
    using namespace std::string_literals;
    Pair p{"one"s, 2};
    Pair p2{52.1,'z'};

    std::println("Pair one: ({}, {})", p.first, p.second);
    std::println("Pair two: ({}, {})", p2.first, p2.second);

    return 0;
}
