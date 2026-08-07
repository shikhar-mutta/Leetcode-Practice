// Link: https://leetcode.com/problems/valid-sudoku/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) (fixed 9x9 board)  SC: O(1)
// Approach: track seen digits per row, column, and 3x3 box using boolean arrays
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[9][9] = {}, cols[9][9] = {}, boxes[9][9] = {};
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') continue;
                int d = board[r][c] - '1';
                int b = (r / 3) * 3 + c / 3;
                if (rows[r][d] || cols[c][d] || boxes[b][d]) return false;
                rows[r][d] = cols[c][d] = boxes[b][d] = true;
            }
        }
        return true;
    }
};
