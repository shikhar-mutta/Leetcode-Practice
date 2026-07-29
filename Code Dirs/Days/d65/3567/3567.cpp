// Link: https://leetcode.com/problems/minimum-absolute-difference-in-sliding-submatrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int rows = m - k + 1, cols = n - k + 1;
        vector<vector<int>> ans(rows, vector<int>(cols, 0));

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                vector<int> vals;
                for (int i = r; i < r + k; i++)
                    for (int j = c; j < c + k; j++)
                        vals.push_back(grid[i][j]);
                sort(vals.begin(), vals.end());
                int best = INT_MAX;
                for (int i = 1; i < (int)vals.size(); i++) {
                    if (vals[i] != vals[i-1]) best = min(best, vals[i] - vals[i-1]);
                }
                ans[r][c] = (best == INT_MAX) ? 0 : best;
            }
        }

        return ans;
    }
};
