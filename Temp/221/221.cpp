// Link: https://leetcode.com/problems/maximal-square/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: DP; dp[i][j] = side length of largest square with bottom-right corner at (i,j),
// = min(top, left, diagonal) + 1 when the cell is '1'
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int best = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (matrix[i-1][j-1] == '1') {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                    best = max(best, dp[i][j]);
                }
            }
        }
        return best * best;
    }
};
