// Link: https://leetcode.com/problems/number-of-islands/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n) worst-case recursion
// Approach: DFS flood-fill sinking each land cell found, incrementing count once per unvisited island
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<void(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != '1') return;
            grid[r][c] = '0';
            dfs(r+1,c); dfs(r-1,c); dfs(r,c+1); dfs(r,c-1);
        };
        int count = 0;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == '1') { count++; dfs(r, c); }
            }
        }
        return count;
    }
};
