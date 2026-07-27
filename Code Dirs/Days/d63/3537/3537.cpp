// Link: https://leetcode.com/problems/fill-a-special-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(4^n) SC: O(4^n)
// Approach: recursively fill each quadrant in the order top-right,
// bottom-right, bottom-left, top-left, assigning consecutive numbers via
// a shared running counter — this naturally gives each quadrant its
// correctly-offset block of numbers.
class Solution {
    void fill(vector<vector<int>>& grid, int r, int c, int size, int& cnt) {
        if (size == 1) { grid[r][c] = cnt++; return; }
        int half = size / 2;
        fill(grid, r, c + half, half, cnt);       // top-right
        fill(grid, r + half, c + half, half, cnt); // bottom-right
        fill(grid, r + half, c, half, cnt);        // bottom-left
        fill(grid, r, c, half, cnt);                // top-left
    }
public:
    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        vector<vector<int>> grid(size, vector<int>(size));
        int cnt = 0;
        fill(grid, 0, 0, size, cnt);
        return grid;
    }
};
