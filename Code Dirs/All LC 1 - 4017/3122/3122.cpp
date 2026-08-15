// Link: https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> freq(n, vector<int>(10, 0));
        for (int c = 0; c < n; c++)
            for (int r = 0; r < m; r++)
                freq[c][grid[r][c]]++;

        vector<int> dp(10, 0);
        for (int c = 0; c < n; c++) {
            vector<int> ndp(10, INT_MAX);
            for (int v = 0; v < 10; v++) {
                int cost = m - freq[c][v];
                int best = INT_MAX;
                for (int pv = 0; pv < 10; pv++) {
                    if (pv == v) continue;
                    best = min(best, dp[pv]);
                }
                if (c == 0) best = 0;
                ndp[v] = cost + best;
            }
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
