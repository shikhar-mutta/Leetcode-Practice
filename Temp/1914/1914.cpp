// Link: https://leetcode.com/problems/cyclically-rotating-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size(), cols = grid[0].size();
        int layers = min(rows, cols) / 2;

        for (int layer = 0; layer < layers; layer++) {
            int top = layer, bottom = rows - 1 - layer;
            int left = layer, right = cols - 1 - layer;

            vector<int> elems;
            for (int c = left; c <= right; c++) elems.push_back(grid[top][c]);
            for (int r = top + 1; r <= bottom; r++) elems.push_back(grid[r][right]);
            for (int c = right - 1; c >= left; c--) elems.push_back(grid[bottom][c]);
            for (int r = bottom - 1; r > top; r--) elems.push_back(grid[r][left]);

            int len = elems.size();
            int shift = k % len;
            vector<int> rotated(len);
            for (int i = 0; i < len; i++) rotated[i] = elems[(i + shift) % len];

            int idx = 0;
            for (int c = left; c <= right; c++) grid[top][c] = rotated[idx++];
            for (int r = top + 1; r <= bottom; r++) grid[r][right] = rotated[idx++];
            for (int c = right - 1; c >= left; c--) grid[bottom][c] = rotated[idx++];
            for (int r = bottom - 1; r > top; r--) grid[r][left] = rotated[idx++];
        }
        return grid;
    }
};
