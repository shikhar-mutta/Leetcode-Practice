// Link: https://leetcode.com/problems/apply-operations-to-make-sum-of-array-greater-than-or-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k), SC: O(1)
// Approach: Starting value 1, if we increase it to v (v-1 increment ops)
// then duplicate it m times (m-1 duplicate ops), the total sum is v*m. For
// each candidate v, the smallest m making v*m >= k is ceil(k/v); minimize
// (v-1)+(m-1) over all v from 1 to k.
class Solution {
public:
    int minOperations(int k) {
        int best = INT_MAX;
        for (int v = 1; v <= k; v++) {
            int m = (k + v - 1) / v; // smallest m such that v*m >= k
            int ops = (v - 1) + (m - 1);
            best = min(best, ops);
        }
        return best;
    }
};
