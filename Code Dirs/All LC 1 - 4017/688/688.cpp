// Link: https://leetcode.com/problems/knight-probability-in-chessboard/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k*n^2) SC: O(n^2)
// Approach: DP over moves; dp[r][c] = probability of being on board at (r,c) after i moves. Each step, spread probability/8 to each of the 8 knight destinations that stay on board.
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n, 0));
        dp[row][column] = 1;
        int dr[] = {-2,-2,-1,-1,1,1,2,2};
        int dc[] = {-1,1,-2,2,-2,2,-1,1};
        for (int step = 0; step < k; step++) {
            vector<vector<double>> ndp(n, vector<double>(n, 0));
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] == 0) continue;
                    for (int d = 0; d < 8; d++) {
                        int nr = r+dr[d], nc = c+dc[d];
                        if (nr>=0 && nr<n && nc>=0 && nc<n) ndp[nr][nc] += dp[r][c] / 8.0;
                    }
                }
            }
            dp = ndp;
        }
        double total = 0;
        for (int r = 0; r < n; r++) for (int c = 0; c < n; c++) total += dp[r][c];
        return total;
    }
};
