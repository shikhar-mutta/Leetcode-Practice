// Link: https://leetcode.com/problems/battleships-in-a-board/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // TC: O(m*n), SC: O(1)
    // Approach:
    //  1. Iterate through the board and for each cell, check if it is 'X'.
    //  2. If it is 'X', check if it is the start of a battleship by checking if the cell above it and the cell to the left of it are not 'X'.
    //  3. If it is the start of a battleship, increment the count.
    //  4. Return the count.
public:
    int countBattleships(vector<vector<char>> &board)
    {
        int m = board.size(), n = board[0].size();
        int count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != 'X')
                    continue;
                if (i > 0 && board[i - 1][j] == 'X')
                    continue;
                if (j > 0 && board[i][j - 1] == 'X')
                    continue;
                count++;
            }
        }
        return count;
    }
};
