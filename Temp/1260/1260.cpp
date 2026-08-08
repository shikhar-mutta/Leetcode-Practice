// Link: https://leetcode.com/problems/shift-2d-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        k %= (m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int pos = (i * n + j + k) % (m * n);
                res[pos / n][pos % n] = grid[i][j];
            }
        }
        return res;
    }
};
