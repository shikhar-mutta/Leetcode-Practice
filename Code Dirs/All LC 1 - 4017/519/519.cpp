// Link: https://leetcode.com/problems/random-flip-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized flip, O(k) reset  SC: O(k) where k = flips since last reset
// Approach: swap-with-last trick over a virtual array of remaining indices;
// map maintains overrides for indices that have been swapped
class Solution {
    int rows, cols;
    int remaining;
    unordered_map<int, int> mapping;

public:
    Solution(int m, int n) : rows(m), cols(n), remaining(m * n) {}

    vector<int> flip() {
        int idx = rand() % remaining;
        int val = mapping.count(idx) ? mapping[idx] : idx;

        int last = remaining - 1;
        mapping[idx] = mapping.count(last) ? mapping[last] : last;
        remaining--;

        return {val / cols, val % cols};
    }

    void reset() {
        remaining = rows * cols;
        mapping.clear();
    }
};
