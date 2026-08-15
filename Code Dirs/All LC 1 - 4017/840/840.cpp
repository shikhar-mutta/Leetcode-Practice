// Link: https://leetcode.com/problems/magic-squares-in-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (rows < 3 || cols < 3) return 0;
        int count = 0;
        for (int i = 0; i + 2 < rows; i++) {
            for (int j = 0; j + 2 < cols; j++) {
                if (isMagic(grid, i, j)) count++;
            }
        }
        return count;
    }

private:
    bool isMagic(vector<vector<int>>& g, int r, int c) {
        vector<int> seen(10, 0);
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++) {
                int v = g[r+i][c+j];
                if (v < 1 || v > 9 || seen[v]++) return false;
            }
        int diag1 = g[r][c] + g[r+1][c+1] + g[r+2][c+2];
        int diag2 = g[r][c+2] + g[r+1][c+1] + g[r+2][c];
        if (diag1 != diag2) return false;
        int target = diag1;
        for (int i = 0; i < 3; i++)
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != target) return false;
        for (int j = 0; j < 3; j++)
            if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != target) return false;
        return true;
    }
};
