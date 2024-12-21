//
// Created by Peter Sims on 12/20/24.
//
#include <vector>
using namespace std;
// Returns the sum of the integers in given sequence.
int example1(const vector<int>& seq) {
    int n(seq.size());
    int total{0};
    for (int j = 0; j < n; j++)           // loop from 0 to n-1
        total += seq[j];
    return total;
}

// Returns the sum of the integers with even index in given sequence
int example2(const vector<int>& seq) {
    int n(seq.size());
    int total{0};
    for (int j = 0; j < n; j += 2)        // note the increment of 2
        total += seq[j];
    return total;
}

// Returns the sum of the prefix sums of the given sequence
int example3(const vector<int>& seq) {
    int n(seq.size());
    int total{0};
    for (int j = 0; j < n; j++)           // loop from 0 to n-1
        for (int k = 0; k <= j; k++)      // loop from 0 to j
            total += seq[j];
    return total;
}

// Returns the sum of the prefix sums of the given sequence
int example4(const vector<int>& seq) {
    int n(seq.size());
    int total{0};
    int prefix{0};
    for (int j = 0; j < n; j++) {         // loop from 0 to n-1
        prefix += seq[j];
        total += prefix;
    }
    return total;
}

// Returns how often the second sequence stores sum of prefix sums from first
int example5(const vector<int>& first, const vector<int>& second) {   // assumes equal-length vectors
    int n(first.size());
    int count{0};
    for (int i = 0; i < n; i++) {         // loop from 0 to n-1
        int total{0};
        for (int j = 0; j < n; j++)       // loop from 0 to n-1
            for (int k = 0; k <= j; k++)  // loop from 0 to j
                total += first[k];
        if (second[i] == total) count++;
    }
    return count;
}