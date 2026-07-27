// Link: https://leetcode.com/problems/twisted-mirror-path-count/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n) SC: O(m * n)
// Approach: push-DP in row-major order. From each reachable non-mirror
// cell, resolve a "right" attempt and a "down" attempt: repeatedly step
// in the current direction, and each time the target is a mirror, flip
// direction and continue from the mirror's position (per the reflection
// chain rule), until landing on a non-mirror cell or going out of bounds.
// Push dp[i][j] forward into both resolved landing cells.
class Solution {
    int m, n;
    pair<int,int> resolve(vector<vector<int>>& grid, int i, int j, int dir) {
        while (true) {
            int ni = i + (dir == 1 ? 1 : 0);
            int nj = j + (dir == 0 ? 1 : 0);
            if (ni >= m || nj >= n) return {-1, -1};
            if (grid[ni][nj] == 0) return {ni, nj};
            i = ni; j = nj; dir = 1 - dir;
        }
    }
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const long long MOD = 1e9 + 7;
        m = grid.size(); n = grid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 || dp[i][j] == 0) continue;
                for (int dir = 0; dir < 2; dir++) {
                    auto [nr, nc] = resolve(grid, i, j, dir);
                    if (nr != -1) dp[nr][nc] = (dp[nr][nc] + dp[i][j]) % MOD;
                }
            }
        }
        return (int)dp[m-1][n-1];
    }
};
