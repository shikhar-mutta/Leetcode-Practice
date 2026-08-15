// Link: https://leetcode.com/problems/longest-line-of-consecutive-one-in-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: DP tracking run length ending at each cell in 4 directions
// (horizontal, vertical, diagonal, anti-diagonal)
class Solution {
public:
    int longestLine(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<array<int,4>>> dp(m, vector<array<int,4>>(n, {0,0,0,0}));
        int best = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) continue;
                dp[i][j][0] = (j > 0 ? dp[i][j-1][0] : 0) + 1; // horizontal
                dp[i][j][1] = (i > 0 ? dp[i-1][j][1] : 0) + 1; // vertical
                dp[i][j][2] = (i > 0 && j > 0 ? dp[i-1][j-1][2] : 0) + 1; // diagonal
                dp[i][j][3] = (i > 0 && j < n - 1 ? dp[i-1][j+1][3] : 0) + 1; // anti-diagonal
                best = max({best, dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]});
            }
        }
        return best;
    }
};
