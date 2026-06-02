// Link: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(char board[3][3], char player)
    {
        for (int i = 0; i < 3; i++)
        { // Check rows and columns
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true; // Check rows
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true; // Check columns
        }

        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true; // Check main diagonal
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true; // Check anti-diagonal
        return false;    // No winning condition met
    }

    string tictactoe(vector<vector<int>> &moves)
    {
        char board[3][3] = {};
        char playerA = 'X';
        char playerB = 'O';
        for (int i = 0; i < moves.size(); i++)
        { // Fill the board based on the moves
            int x = moves[i][0];
            int y = moves[i][1];
            if (i % 2 == 0)
                board[x][y] = playerA;
            else
                board[x][y] = playerB;
        }

        if (check(board, playerA))
            return "A";
        if (check(board, playerB))
            return "B";

        if (moves.size() == 9)
            return "Draw"; // If all moves are made and no winner, it's a draw
        return "Pending";  // If there are still moves left and no winner, it's pending
    }
};
