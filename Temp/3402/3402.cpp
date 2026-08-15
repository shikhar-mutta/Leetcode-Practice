// Link: https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int ops = 0;
        for (int c = 0; c < n; c++) {
            int prev = grid[0][c];
            for (int r = 1; r < m; r++) {
                if (grid[r][c] <= prev) {
                    ops += prev + 1 - grid[r][c];
                    prev = prev + 1;
                } else {
                    prev = grid[r][c];
                }
            }
        }
        return ops;
    }
};
