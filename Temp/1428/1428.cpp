// Link: https://leetcode.com/problems/leftmost-column-with-at-least-a-one/description/

#include <bits/stdc++.h>
using namespace std;

class BinaryMatrix {
public:
    vector<vector<int>> grid;
    int get(int row, int col) { return grid[row][col]; }
    vector<int> dimensions() { return {(int)grid.size(), (int)grid[0].size()}; }
};

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        auto dims = binaryMatrix.dimensions();
        int rows = dims[0], cols = dims[1];
        int row = 0, col = cols - 1;
        int result = -1;
        while (row < rows && col >= 0) {
            if (binaryMatrix.get(row, col) == 1) {
                result = col;
                col--;
            } else {
                row++;
            }
        }
        return result;
    }
};
