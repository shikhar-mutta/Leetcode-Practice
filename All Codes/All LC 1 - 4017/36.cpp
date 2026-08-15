// Link: https://leetcode.com/problems/valid-sudoku/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // use bitmask of rows, cols and boxes to check if the number is already present in the row, col or box
    // TC: O(n^2) where n is the size of the board (9 in this case)
    // SC: O(n) for the bitmask arrays
    bool isValidSudoku(vector<vector<char>> &board)
    {
        int n = board.size();
        vector<int> rows(n), cols(n), boxes(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == '.') // If the cell is empty, skip it
                    continue;
                int num = board[i][j] - '0'; // Convert char to int (1-9)
                if (rows[i] & (1 << num))    // check in row bitmask num is already set or not
                    return false;
                if (cols[j] & (1 << num)) // check in col bitmask num is already set or not
                    return false;
                int boxIndex = (i / 3) * 3 + (j / 3);
                if (boxes[boxIndex] & (1 << num)) // check in box bitmask num is already set or not
                    return false;
                rows[i] |= (1 << num);
                cols[j] |= (1 << num);
                boxes[boxIndex] |= (1 << num);
            }
        }
        return true;
    }
};
