//
// Created by Peter Sims on 1/26/25.
//

#include <print>
#include "../exercise_classes/circularly_linked.h"

// see circularly_linked.h for operator== overload
int main() {
    dsac::list::CircularlyLinkedList<int> one;
    dsac::list::CircularlyLinkedList<int> two;
    std::println("{}", one == two);
    for (int i{0}; i < 10; ++i) {
        one.push_front(i);
        two.push_front(i);
    }
    std::println("{}", one == two);
    two.pop_front();
    std::println("{}", one == two);
    two.push_front(33);
    std::println("{}", one == two);
    two.pop_front();
    two.push_front(9);
    std::println("{}", one == two);
    return 0;
}
