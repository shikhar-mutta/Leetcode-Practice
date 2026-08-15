// Link: https://leetcode.com/problems/minimum-path-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(1) (in-place on grid)
// Approach: DP in place — each cell adds min(cell above, cell to the left), edges only have one option
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) grid[i][j] += grid[i][j-1];
                else if (j == 0) grid[i][j] += grid[i-1][j];
                else grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[m-1][n-1];
    }
};
