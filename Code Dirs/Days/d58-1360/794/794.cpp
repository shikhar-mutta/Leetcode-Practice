// Link: https://leetcode.com/problems/valid-tic-tac-toe-state/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), as the board size is fixed (3x3).
    // SC: O(1), as we are using a constant amount of space.
    // Approach:
    //  1. We count the number of 'X' and 'O' on the board.
    //  2. We check if the counts are valid: 'X' can be equal to 'O' or one more than 'O'.
    //  3. We check if either player has won the game by checking all possible winning combinations (rows, columns, and diagonals).
    //  4. If both players have won or if the counts are invalid based on the winning conditions, we return false. Otherwise, we return true.
    //  5. The function returns true if the board state is valid, and false otherwise.
    //  Note: The board is represented as a vector of strings, where each string represents a row of the board.
    bool validTicTacToe(vector<string> &board)
    {
        int xCount = 0, oCount = 0;
        for (auto &row : board)
            for (char c : row)
            {
                if (c == 'X')
                    xCount++;
                else if (c == 'O')
                    oCount++;
            }
        if (oCount != xCount && oCount != xCount - 1)
            return false;

        auto wins = [&](char p)
        {
            for (int i = 0; i < 3; i++)
            {
                if (board[i][0] == p && board[i][1] == p && board[i][2] == p)
                    return true;
                if (board[0][i] == p && board[1][i] == p && board[2][i] == p)
                    return true;
            }
            if (board[0][0] == p && board[1][1] == p && board[2][2] == p)
                return true;
            if (board[0][2] == p && board[1][1] == p && board[2][0] == p)
                return true;
            return false;
        };

        bool xWins = wins('X'), oWins = wins('O');
        if (xWins && oWins)
            return false;
        if (xWins && xCount != oCount + 1)
            return false;
        if (oWins && xCount != oCount)
            return false;
        return true;
    }
};
