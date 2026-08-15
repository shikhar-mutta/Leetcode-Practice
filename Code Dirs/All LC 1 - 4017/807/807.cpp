// Link: https://leetcode.com/problems/max-increase-to-keep-city-skyline/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
// Approach: compute max per row and per column; each cell can rise to min(rowMax, colMax); sum the increases.
class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rowMax(n, 0), colMax(n, 0);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                rowMax[i] = max(rowMax[i], grid[i][j]);
                colMax[j] = max(colMax[j], grid[i][j]);
            }
        int total = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                total += min(rowMax[i], colMax[j]) - grid[i][j];
        return total;
    }
};
