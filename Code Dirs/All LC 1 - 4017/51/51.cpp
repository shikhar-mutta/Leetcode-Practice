// Link: https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n!)  SC: O(n) recursion depth (excluding output)
// Approach: backtracking row by row, tracking used columns and both diagonals
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<int> queenCol(n, -1);
        vector<bool> cols(n, false), diag1(2*n, false), diag2(2*n, false);
        function<void(int)> bt = [&](int row) {
            if (row == n) {
                vector<string> board(n, string(n, '.'));
                for (int r = 0; r < n; r++) board[r][queenCol[r]] = 'Q';
                res.push_back(board);
                return;
            }
            for (int c = 0; c < n; c++) {
                if (cols[c] || diag1[row+c] || diag2[row-c+n]) continue;
                cols[c] = diag1[row+c] = diag2[row-c+n] = true;
                queenCol[row] = c;
                bt(row + 1);
                cols[c] = diag1[row+c] = diag2[row-c+n] = false;
            }
        };
        bt(0);
        return res;
    }
};
