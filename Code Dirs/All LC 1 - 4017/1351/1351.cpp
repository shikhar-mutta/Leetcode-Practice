// Link: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0, col = n - 1;
        for (int row = 0; row < m; row++) {
            while (col >= 0 && grid[row][col] < 0) col--;
            count += n - 1 - col;
        }
        return count;
    }
};
