// Link: https://leetcode.com/problems/count-fertile-pyramids-in-a-land/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(rows*cols)  SC: O(rows*cols)
// Approach: dp[i][j] = max pyramid height with apex at (i,j) growing toward
// increasing rows (base below), computed as
// min(dp[i+1][j-1],dp[i+1][j],dp[i+1][j+1])+1 when grid[i][j]==1. Each cell
// with dp[i][j]=h contributes h-1 valid pyramids (heights 2..h). Repeat with
// rows reversed for inverted pyramids and sum both totals.
class Solution {
    long long countOneDirection(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        long long total = 0;
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 0) { dp[i][j] = 0; continue; }
                if (i == rows - 1 || j == 0 || j == cols - 1) dp[i][j] = 1;
                else dp[i][j] = min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]}) + 1;
                total += dp[i][j] - 1;
            }
        }
        return total;
    }
public:
    int countPyramids(vector<vector<int>>& grid) {
        long long total = countOneDirection(grid);
        reverse(grid.begin(), grid.end());
        total += countOneDirection(grid);
        return (int)total;
    }
};
