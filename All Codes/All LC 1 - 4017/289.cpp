// Link: https://leetcode.com/problems/game-of-life/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n)
    // SC: O(1)
    // Approach:
    //  1. Iterate through the board and for each cell, count the number of live neighbors.
    //  2. If the cell is currently live and has 2 or 3 live neighbors, it stays alive. If the cell is currently dead and has exactly 3 live neighbors, it becomes alive. Otherwise, it dies or stays dead.
    //  3. To avoid modifying the board while counting neighbors, we use the second bit of each cell to store the next state of the cell. The first bit represents the current state, and the second bit represents the next state.
    void gameOfLife(vector<vector<int>> &board)
    {
        int m = board.size(), n = board[0].size();
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int live = 0;
                for (int d = 0; d < 8; d++)
                {
                    int ni = i + dx[d], nj = j + dy[d];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n)
                        live += board[ni][nj] & 1;
                }
                if ((board[i][j] & 1) && (live == 2 || live == 3))
                    board[i][j] |= 2;
                else if (!(board[i][j] & 1) && live == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                board[i][j] >>= 1;
    }
};
