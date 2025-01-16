//
// Created by Peter Sims on 1/15/25.
//

#include <print>

template <typename T>
void subsets(const int k, std::vector<T> seq, std::vector<T> unused) {
    if (k == 0) {
        std::println("{:n}", seq);
    } else {
        for (int i = unused.size() - 1; i >= 0; --i) {
            seq.push_back(unused[i]);
            unused.erase(unused.begin() + i);
            subsets(k - 1, seq, unused);
            unused.push_back(seq[seq.size() - 1]);
            seq.pop_back();
        }
    }
}

template <typename T>
void subsets(const std::vector<T>& collection) {
    std::vector<T> seq;
    subsets(collection.size(), seq, collection);
}

int main() {
    const std::vector test{'a', 'b', 'c'};
    const std::vector test2{1, 2, 3,4,};
    subsets(test);
    std::println("\n");

    subsets(test2);

    return 0;
}
