// Link: https://leetcode.com/problems/sudoku-solver/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(9^(n*n)) where n is the size of the board (9 in this case)
// SC: O(1)
class Solution
{
    // Bitmasking to keep track of the numbers used in each row, column, and box
    vector<int> rows, cols, boxes;

public:
    Solution() : rows(9, 0), cols(9, 0), boxes(9, 0) {}
    bool solve(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                {
                    // Test for each number from '1' to '9'
                    for (char c = '1'; c <= '9'; c++)
                    {
                        int bit = 1 << (c - '1');
                        int mask = !(rows[i] & bit) && !(cols[j] & bit) && !(boxes[3 * (i / 3) + j / 3] & bit);
                        if (mask)
                        {
                            board[i][j] = c;
                            // Mark the current number as used in the corresponding row, column, and box
                            rows[i] |= (1 << (c - '1'));
                            cols[j] |= (1 << (c - '1'));
                            boxes[3 * (i / 3) + j / 3] |= (1 << (c - '1'));
                            if (solve(board))
                                return true;
                            board[i][j] = '.';
                            // Unmark the current number as used in the corresponding row, column, and box
                            rows[i] &= ~(1 << (c - '1'));
                            cols[j] &= ~(1 << (c - '1'));
                            boxes[3 * (i / 3) + j / 3] &= ~(1 << (c - '1'));
                        }
                    }
                    return false;
                }
        return true;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.')
                { // Set the bits for the initial numbers in the board
                    int bit = 1 << (board[i][j] - '1');
                    rows[i] |= bit;
                    cols[j] |= bit;
                    boxes[3 * (i / 3) + j / 3] |= bit;
                }
        solve(board);
    }
};
