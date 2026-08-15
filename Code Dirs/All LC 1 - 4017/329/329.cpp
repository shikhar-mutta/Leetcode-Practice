// Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
// Approach: DFS with memoization - longest increasing path starting at each
// cell, exploring neighbors with strictly greater value
class Solution {
    vector<vector<int>> memo;
    int m, n;

    int dfs(vector<vector<int>>& matrix, int r, int c) {
        if (memo[r][c]) return memo[r][c];
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int best = 1;
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (matrix[nr][nc] <= matrix[r][c]) continue;
            best = max(best, 1 + dfs(matrix, nr, nc));
        }
        return memo[r][c] = best;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();
        memo.assign(m, vector<int>(n, 0));
        int best = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                best = max(best, dfs(matrix, i, j));
        return best;
    }
};
