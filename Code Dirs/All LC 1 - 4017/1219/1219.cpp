// Link: https://leetcode.com/problems/path-with-maximum-gold/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int dr[] = {-1,1,0,0}, dc[] = {0,0,-1,1};

        function<int(int,int)> dfs = [&](int r, int c) {
            if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == 0) return 0;
            int gold = grid[r][c];
            grid[r][c] = 0;
            int best = 0;
            for (int d = 0; d < 4; d++) best = max(best, dfs(r + dr[d], c + dc[d]));
            grid[r][c] = gold;
            return gold + best;
        };

        int best = 0;
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (grid[i][j] != 0) best = max(best, dfs(i, j));
        return best;
    }
};
