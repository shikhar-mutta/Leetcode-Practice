// Link: https://leetcode.com/problems/number-of-closed-islands/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<bool(int,int)> dfs = [&](int r, int c) -> bool {
            if (r < 0 || r >= m || c < 0 || c >= n) return false;
            if (grid[r][c] == 1) return true;
            grid[r][c] = 1;
            bool res = true;
            res &= dfs(r+1, c);
            res &= dfs(r-1, c);
            res &= dfs(r, c+1);
            res &= dfs(r, c-1);
            return res;
        };
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    if (dfs(i, j)) count++;
                }
            }
        }
        return count;
    }
};
