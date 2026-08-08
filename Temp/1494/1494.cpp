// Link: https://leetcode.com/problems/parallel-courses-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        vector<int> prereq(n, 0);
        for (auto& r : relations) {
            prereq[r[1] - 1] |= (1 << (r[0] - 1));
        }

        int full = 1 << n;
        vector<int> dp(full, INT_MAX);
        dp[0] = 0;

        for (int mask = 0; mask < full; mask++) {
            if (dp[mask] == INT_MAX) continue;
            int candidates = 0;
            for (int c = 0; c < n; c++) {
                if (!(mask & (1 << c)) && (prereq[c] & mask) == prereq[c]) {
                    candidates |= (1 << c);
                }
            }
            if (candidates == 0) continue;

            // enumerate all subsets of candidates
            for (int sub = candidates; sub > 0; sub = (sub - 1) & candidates) {
                if (__builtin_popcount(sub) <= k) {
                    int newMask = mask | sub;
                    dp[newMask] = min(dp[newMask], dp[mask] + 1);
                }
            }
        }
        return dp[full - 1];
    }
};
