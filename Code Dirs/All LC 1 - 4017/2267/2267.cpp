// Link: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n - 1) % 2 != 0) return false;
        int maxBal = m + n;
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(maxBal + 1, false)));
        if (grid[0][0] == '(') dp[0][0][1] = true;
        else return false;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) continue;
                int delta = (grid[r][c] == '(') ? 1 : -1;
                for (int b = 0; b <= maxBal; b++) {
                    bool canReach = false;
                    if (r > 0 && b - delta >= 0 && b - delta <= maxBal) canReach = canReach || dp[r-1][c][b - delta];
                    if (c > 0 && b - delta >= 0 && b - delta <= maxBal) canReach = canReach || dp[r][c-1][b - delta];
                    dp[r][c][b] = canReach;
                }
            }
        }
        return dp[m-1][n-1][0];
    }
};
