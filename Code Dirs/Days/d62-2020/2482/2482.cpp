// Link: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m * n)
// SC: O(m + n)
// Approach: precompute the count of ones in each row and column. For
// cell (i, j), onesRow[i] + onesCol[j] gives total ones seen, while
// (cols - onesRow[i]) + (rows - onesCol[j]) gives total zeros seen;
// their difference simplifies to 2*onesRow[i] + 2*onesCol[j] - rows - cols.
class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<int> onerows(grid.size(), 0);
        vector<int> onecols(grid[0].size(), 0);
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    onerows[i]++;
                    onecols[j]++;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                grid[i][j] = (2 * onerows[i]) + (2 * onecols[j]) - grid.size() -
                             grid[0].size();
            }
        }
        return grid;
    }
};
