// Link: https://leetcode.com/problems/count-fertile-pyramids-in-a-land/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countOrientation(vector<vector<int>>& grid, bool downward) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int total = 0;
        int startRow = downward ? m - 1 : 0;
        int endRow = downward ? -1 : m;
        int step = downward ? -1 : 1;
        for (int r = startRow; r != endRow; r += step) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 0) { dp[r][c] = 0; continue; }
                int nr = downward ? r + 1 : r - 1;
                if (nr < 0 || nr >= m || c - 1 < 0 || c + 1 >= n) {
                    dp[r][c] = 1;
                } else {
                    dp[r][c] = 1 + min({dp[nr][c-1], dp[nr][c], dp[nr][c+1]});
                }
                total += max(0, dp[r][c] - 1);
            }
        }
        return total;
    }

    int countPyramids(vector<vector<int>>& grid) {
        return countOrientation(grid, true) + countOrientation(grid, false);
    }
};
