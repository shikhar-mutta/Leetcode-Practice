// Link: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        const long long MOD = 1e9 + 7;
        int m = grid.size(), n = grid[0].size();
        vector<pair<int,int>> cells;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) cells.push_back({i, j});
        sort(cells.begin(), cells.end(), [&](auto& a, auto& b) {
            return grid[a.first][a.second] < grid[b.first][b.second];
        });

        vector<vector<long long>> dp(m, vector<long long>(n, 1));
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};
        long long total = 0;
        for (auto& [r, c] : cells) {
            for (int d = 0; d < 4; d++) {
                int nr = r + dr[d], nc = c + dc[d];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (grid[nr][nc] < grid[r][c]) {
                    dp[r][c] = (dp[r][c] + dp[nr][nc]) % MOD;
                }
            }
            total = (total + dp[r][c]) % MOD;
        }
        return (int)total;
    }
};
