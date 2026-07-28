// Link: https://leetcode.com/problems/stamping-the-grid/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(rc)  SC: O(rc)
// Approach: prefix sums to check O(1) if a stamp region is empty; for each
// valid top-left position mark via a 2D difference array; final prefix sum
// of diff array tells whether every empty cell got covered by >=1 stamp.
class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> pre(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j] + grid[i][j];
        vector<vector<int>> diff(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i + stampHeight <= m; i++) {
            for (int j = 0; j + stampWidth <= n; j++) {
                int r2 = i + stampHeight, c2 = j + stampWidth;
                int sum = pre[r2][c2] - pre[i][c2] - pre[r2][j] + pre[i][j];
                if (sum == 0) {
                    diff[i][j]++;
                    diff[i][c2]--;
                    diff[r2][j]--;
                    diff[r2][c2]++;
                }
            }
        }
        vector<vector<int>> cover(m + 1, vector<int>(n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int val = diff[i][j];
                if (i > 0) val += cover[i-1][j];
                if (j > 0) val += cover[i][j-1];
                if (i > 0 && j > 0) val -= cover[i-1][j-1];
                cover[i][j] = val;
                if (grid[i][j] == 0 && cover[i][j] == 0) return false;
            }
        }
        return true;
    }
};
