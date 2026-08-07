// Link: https://leetcode.com/problems/out-of-boundary-paths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(maxMove*m*n) SC: O(m*n)
// Approach: DP over moves; dp[r][c] = ways to be at (r,c) after k moves. Each move, out-of-boundary transitions add to answer.
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        const int MOD = 1e9+7;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[startRow][startColumn] = 1;
        long long ans = 0;
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        for (int k = 0; k < maxMove; k++) {
            vector<vector<long long>> ndp(m, vector<long long>(n, 0));
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    if (dp[r][c] == 0) continue;
                    for (int d = 0; d < 4; d++) {
                        int nr = r+dr[d], nc = c+dc[d];
                        if (nr<0||nr>=m||nc<0||nc>=n) ans = (ans + dp[r][c]) % MOD;
                        else ndp[nr][nc] = (ndp[nr][nc] + dp[r][c]) % MOD;
                    }
                }
            }
            dp = ndp;
        }
        return (int)ans;
    }
};
