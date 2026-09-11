// Link: https://leetcode.com/problems/n-queens/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int row, int n, vector<string> &board, vector<vector<string>> &res,
               vector<bool> &cols, vector<bool> &diag1, vector<bool> &diag2)
    {
        if (row == n) // all queens placed
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < n; col++) // try placing queen at (row, col)
        {
            // (2,0), (1,1), (0,2) are on the same '/' diagonal DELTA row + col = 2
            int d1 = row + col; // '/' diagonal id
            // (0,2),(1,3),(2,4) are on the same '\' diagonal DELTA row - col = -2
            int d2 = row - col + n - 1; // '\' diagonal id (shifted to be >= 0)

            if (cols[col] || diag1[d1] || diag2[d2])
                continue; // square attacked

            cols[col] = diag1[d1] = diag2[d2] = true; // mark column and diagonals as attacked

            board[row][col] = 'Q'; // place queen

            // recurse to place queen in next row
            solve(row + 1, n, board, res, cols, diag1, diag2);

            board[row][col] = '.'; // backtrack (undo every mark)

            cols[col] = diag1[d1] = diag2[d2] = false; // unmark column and diagonals
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> res;              // ans
        vector<string> board(n, string(n, '.')); // empty board
        // track columns and diagonals under attack
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);

        solve(0, n, board, res, cols, diag1, diag2);
        return res;
    }
};
