// Link: https://leetcode.com/problems/cherry-pickup-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        dp[0][0][cols - 1] = grid[0][0] + grid[0][cols - 1];
        if (cols == 1) dp[0][0][cols-1] = grid[0][0];
        for (int r = 1; r < rows; r++) {
            for (int c1 = 0; c1 < cols; c1++) {
                for (int c2 = 0; c2 < cols; c2++) {
                    int best = -1;
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int pc1 = c1 + d1, pc2 = c2 + d2;
                            if (pc1 < 0 || pc1 >= cols || pc2 < 0 || pc2 >= cols) continue;
                            if (dp[r-1][pc1][pc2] < 0) continue;
                            best = max(best, dp[r-1][pc1][pc2]);
                        }
                    }
                    if (best < 0) continue;
                    int val = grid[r][c1] + (c1 != c2 ? grid[r][c2] : 0);
                    dp[r][c1][c2] = best + val;
                }
            }
        }
        int ans = 0;
        for (int c1 = 0; c1 < cols; c1++)
            for (int c2 = 0; c2 < cols; c2++)
                ans = max(ans, dp[rows-1][c1][c2]);
        return ans;
    }
};
