// Link: https://leetcode.com/problems/fill-a-special-grid/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> grid;

    void fill(int row, int col, int size, long long startVal) {
        if (size == 1) {
            grid[row][col] = (int)startVal;
            return;
        }
        int half = size / 2;
        long long quarter = (long long)half * half;
        fill(row, col + half, half, startVal);              // top-right
        fill(row + half, col + half, half, startVal + quarter);   // bottom-right
        fill(row + half, col, half, startVal + 2 * quarter);       // bottom-left
        fill(row, col, half, startVal + 3 * quarter);               // top-left
    }

    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        grid.assign(size, vector<int>(size, 0));
        fill(0, 0, size, 0);
        return grid;
    }
};
