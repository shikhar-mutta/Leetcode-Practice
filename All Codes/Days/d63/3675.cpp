// Link: https://leetcode.com/problems/minimum-operations-to-transform-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: an operation shifts every occurrence of one letter value to
// the next, cyclically. Performing ops in increasing order of "distance
// to a" sweeps every letter forward together (once a letter reaches the
// next one, further ops on that value also carry it along), so the total
// ops needed is just the max cyclic distance to 'a' among letters present.
class Solution {
public:
    int minOperations(string s) {
        int best = 0;
        for (char c : s) {
            int dist = (26 - (c - 'a')) % 26;
            best = max(best, dist);
        }
        return best;
    }
};
