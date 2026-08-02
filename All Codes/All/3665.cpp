// Link: https://leetcode.com/problems/twisted-mirror-path-count/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<int>>* gridP;
    vector<vector<pair<int,int>>> memo[2]; // 0=R,1=D
    vector<vector<char>> computed[2];

    pair<int,int> resolve(int i, int j, int dir) {
        if (i < 0 || i >= m || j < 0 || j >= n) return {-1, -1};
        auto& grid = *gridP;
        if (grid[i][j] == 0) return {i, j};
        if (computed[dir][i][j]) return memo[dir][i][j];
        computed[dir][i][j] = 1; // guard (no cycles possible since indices strictly increase)
        int ni = i, nj = j, ndir;
        if (dir == 0) { ndir = 1; ni = i + 1; } // was moving Right, reflect Down
        else { ndir = 0; nj = j + 1; } // was moving Down, reflect Right
        auto res = resolve(ni, nj, ndir);
        memo[dir][i][j] = res;
        return res;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size(); n = grid[0].size();
        gridP = &grid;
        for (int d = 0; d < 2; d++) {
            memo[d].assign(m, vector<pair<int,int>>(n, {-1,-1}));
            computed[d].assign(m, vector<char>(n, 0));
        }

        const long long MOD = 1e9 + 7;
        vector<vector<long long>> dp(m, vector<long long>(n, 0));
        dp[0][0] = 1;

        vector<pair<int,int>> cells;
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) if (grid[i][j] == 0) cells.push_back({i,j});
        sort(cells.begin(), cells.end(), [](auto& a, auto& b){ return a.first + a.second < b.first + b.second; });

        for (auto& [i, j] : cells) {
            long long cur = dp[i][j];
            if (cur == 0) continue;
            if (i == m - 1 && j == n - 1) continue;

            auto right = resolve(i, j + 1, 0);
            if (right.first != -1) dp[right.first][right.second] = (dp[right.first][right.second] + cur) % MOD;

            auto down = resolve(i + 1, j, 1);
            if (down.first != -1) dp[down.first][down.second] = (dp[down.first][down.second] + cur) % MOD;
        }

        return (int)dp[m-1][n-1];
    }
};
