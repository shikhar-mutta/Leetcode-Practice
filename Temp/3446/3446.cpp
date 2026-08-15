// Link: https://leetcode.com/problems/sort-matrix-by-diagonals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        // bottom-left half + main diagonal: start row from 0..n-1, col=0, sort descending
        for (int startRow = 0; startRow < n; startRow++) {
            vector<int> vals;
            for (int r = startRow, c = 0; r < n; r++, c++) vals.push_back(grid[r][c]);
            sort(vals.rbegin(), vals.rend());
            int idx = 0;
            for (int r = startRow, c = 0; r < n; r++, c++) grid[r][c] = vals[idx++];
        }
        // top-right half (excluding main diagonal): start col from 1..n-1, row=0, sort ascending
        for (int startCol = 1; startCol < n; startCol++) {
            vector<int> vals;
            for (int r = 0, c = startCol; c < n; r++, c++) vals.push_back(grid[r][c]);
            sort(vals.begin(), vals.end());
            int idx = 0;
            for (int r = 0, c = startCol; c < n; r++, c++) grid[r][c] = vals[idx++];
        }
        return grid;
    }
};
