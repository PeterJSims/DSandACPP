//
// Created by Peter Sims on 1/16/25.
//



#include <print>

template <typename T>
void subsets(const int k, std::vector<T> seq, std::vector<T> unused) {
    if (k == 0) {
        std::println("{}", std::string(seq.begin(), seq.end()));
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
    const std::vector test{'c', 'a', 't', 'd', 'o', 'g'};
    subsets(test);
    std::println("\n");

    return 0;
}
