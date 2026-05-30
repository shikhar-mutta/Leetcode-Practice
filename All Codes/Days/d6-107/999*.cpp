// Link: https://leetcode.com/problems/available-captures-for-rook/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRookCaptures(vector<vector<char>> &board)
    {
        int rookRow = -1, rookCol = -1;
        // Find the position of the rook on the board
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (board[i][j] == 'R')
                {
                    rookRow = i;
                    rookCol = j;
                    break;
                }
            }
            if (rookRow != -1)
            {
                break;
            }
        }

        int captures = 0;

        // Check upwards from the rook's position
        for (int i = rookRow - 1; i >= 0; i--)
        {
            if (board[i][rookCol] == 'B')
            { // If we encounter a bishop, stop checking in this direction
                break;
            }
            if (board[i][rookCol] == 'p')
            { // If we encounter a pawn, it can be captured
                captures++;
                break; // Stop checking after capturing a pawn
            }
        }

        // Check downwards from the rook's position
        for (int i = rookRow + 1; i < 8; i++)
        {
            if (board[i][rookCol] == 'B')
            { // If we encounter a bishop, stop checking in this direction
                break;
            }
            if (board[i][rookCol] == 'p')
            { // If we encounter a pawn, it can be captured
                captures++;
                break; // Stop checking after capturing a pawn
            }
        }

        // Check leftwards from the rook's position
        for (int j = rookCol - 1; j >= 0; j--)
        {
            if (board[rookRow][j] == 'B')
            { // If we encounter a bishop, stop checking in this direction
                break;
            }
            if (board[rookRow][j] == 'p')
            { // If we encounter a pawn, it can be captured
                captures++;
                break; // Stop checking after capturing a pawn
            }
        }

        // Check rightwards from the rook's position
        for (int j = rookCol + 1; j < 8; j++)
        {
            if (board[rookRow][j] == 'B')
            { // If we encounter a bishop, stop checking in this direction
                break;
            }
            if (board[rookRow][j] == 'p')
            { // If we encounter a pawn, it can be captured
                captures++;
                break; // Stop checking after capturing a pawn
            }
        }

        return captures; // Return the total number of pawns the rook can capture
    }
};
