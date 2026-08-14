// Link: https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<int> dp = grid[0];
        for (int r = 1; r < m; r++) {
            vector<int> ndp(n, INT_MAX);
            for (int c = 0; c < n; c++) {
                for (int pc = 0; pc < n; pc++) {
                    int cost = dp[pc] + moveCost[grid[r-1][pc]][c] + grid[r][c];
                    ndp[c] = min(ndp[c], cost);
                }
            }
            dp = ndp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
