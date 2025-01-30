//
// Created by Peter Sims on 1/29/25.
//

#include <print>
#include <stack>


int main() {
    std::stack<int> r;
    std::stack<int> s;
    std::stack<int> t;

    for (int i{1}; i < 10; ++i) {
        if (i < 4) {
            r.push(i);
        } else if (i > 5) {
            t.push(i);
        } else {
            s.push(i);
        }
    }
    size_t r_starting_size{r.size()};
    size_t s_starting_size{s.size()};
    size_t t_starting_size{t.size()};

    while (!t.empty()) {
        r.push(t.top());
        t.pop();
    }

    while (!s.empty()) {
        t.push(s.top());
        s.pop();
    }
    for (int i{0}; i < t_starting_size; ++i) {
        s.push(r.top());
        r.pop();
    }

    while (!t.empty()) {
        s.push(t.top());
        t.pop();
    }

    std::stack<int> display_stack;

    while (!s.empty()) {
        display_stack.push(s.top());
        s.pop();
    }

    while (!r.empty()) {
        display_stack.push(r.top());
        r.pop();
    }


    while (!display_stack.empty()) {
        std::print("{} ", display_stack.top());
        display_stack.pop();
    }

    return 0;
}
