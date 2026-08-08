// Link: https://leetcode.com/problems/score-after-flipping-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        for (int i = 0; i < rows; i++) {
            if (grid[i][0] == 0) {
                for (int j = 0; j < cols; j++) grid[i][j] ^= 1;
            }
        }
        int total = 0;
        for (int j = 0; j < cols; j++) {
            int ones = 0;
            for (int i = 0; i < rows; i++) ones += grid[i][j];
            total += max(ones, rows - ones) * (1 << (cols - 1 - j));
        }
        return total;
    }
};
