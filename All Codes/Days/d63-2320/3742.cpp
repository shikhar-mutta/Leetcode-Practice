// Link: https://leetcode.com/problems/maximum-path-score-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*k) SC: O(n*k)
// Approach: DP over (row, col, cost used) tracking max score, where cost
// of a cell is 1 for value 1 or 2 (0) for value 0, and score adds the
// cell's value. Roll the row dimension to save space.
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k = min(k, m + n - 1);
        vector<vector<int>> dp(n, vector<int>(k + 1, -1));
        int c0 = grid[0][0] == 0 ? 0 : 1;
        if (c0 <= k) dp[0][c0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            vector<vector<int>> ndp(n, vector<int>(k + 1, -1));
            for (int j = 0; j < n; j++) {
                int cost = grid[i][j] == 0 ? 0 : 1;
                int val = grid[i][j];
                for (int c = cost; c <= k; c++) {
                    int best = -1;
                    if (i == 0 && j == 0) {
                        if (c == cost) best = val;
                    } else {
                        if (i > 0 && dp[j][c - cost] != -1) best = max(best, dp[j][c - cost] + val);
                        if (j > 0 && ndp[j-1][c - cost] != -1) best = max(best, ndp[j-1][c - cost] + val);
                    }
                    ndp[j][c] = best;
                }
            }
            dp = ndp;
        }

        int ans = -1;
        for (int c = 0; c <= k; c++) ans = max(ans, dp[n-1][c]);
        return ans;
    }
};
