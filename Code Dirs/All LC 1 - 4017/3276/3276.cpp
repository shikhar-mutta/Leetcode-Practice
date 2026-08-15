// Link: https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int m = grid.size();
        map<int, int> rowsForValue; // value -> bitmask of rows containing it
        for (int i = 0; i < m; i++) {
            for (int v : grid[i]) {
                rowsForValue[v] |= (1 << i);
            }
        }

        int full = 1 << m;
        vector<int> dp(full, 0);

        for (auto& [v, rowMask] : rowsForValue) {
            vector<int> ndp = dp;
            for (int mask = 0; mask < full; mask++) {
                int avail = rowMask & ~mask;
                int r = avail;
                while (r) {
                    int bit = r & (-r);
                    int newMask = mask | bit;
                    ndp[newMask] = max(ndp[newMask], dp[mask] + v);
                    r -= bit;
                }
            }
            dp = ndp;
        }

        int best = 0;
        for (int mask = 0; mask < full; mask++) best = max(best, dp[mask]);
        return best;
    }
};
