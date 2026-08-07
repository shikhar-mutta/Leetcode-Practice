// Link: https://leetcode.com/problems/sudoku-solver/description/

#include <bits/stdc++.h>
using namespace std;

// TC: exponential worst case, fast in practice for valid puzzles  SC: O(1) extra
// Approach: backtracking, try digits 1-9 at each empty cell, checking row/col/box validity before recursing
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
private:
    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] != '.') continue;
                for (char d = '1'; d <= '9'; d++) {
                    if (valid(board, r, c, d)) {
                        board[r][c] = d;
                        if (solve(board)) return true;
                        board[r][c] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }
    bool valid(vector<vector<char>>& board, int r, int c, char d) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == d) return false;
            if (board[i][c] == d) return false;
            if (board[3*(r/3) + i/3][3*(c/3) + i%3] == d) return false;
        }
        return true;
    }
};
