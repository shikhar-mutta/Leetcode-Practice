// Link: https://leetcode.com/problems/cherry-pickup-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<vector<int>>> memo(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));

        function<int(int,int,int)> dfs = [&](int row, int c1, int c2) -> int {
            if (c1 < 0 || c1 >= cols || c2 < 0 || c2 >= cols) return INT_MIN / 2;
            if (memo[row][c1][c2] != -1) return memo[row][c1][c2];

            int cherries = grid[row][c1];
            if (c1 != c2) cherries += grid[row][c2];

            if (row < rows - 1) {
                int best = INT_MIN;
                for (int d1 = -1; d1 <= 1; d1++) {
                    for (int d2 = -1; d2 <= 1; d2++) {
                        best = max(best, dfs(row + 1, c1 + d1, c2 + d2));
                    }
                }
                cherries += best;
            }
            memo[row][c1][c2] = cherries;
            return cherries;
        };

        return dfs(0, 0, cols - 1);
    }
};
