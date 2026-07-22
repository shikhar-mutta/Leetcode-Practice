// Link: https://leetcode.com/problems/minesweeper/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n), SC: O(1) where m is the number of rows and n is the number of columns in the board
    // SC: O(m*n) in case of recursion stack
    //  Approach:
    //   1. If the clicked cell is a mine ('M'), we change it to 'X' and return the board.
    //   2. If the clicked cell is an empty cell ('E'), we perform a depth-first search (DFS) to reveal the cell and its adjacent cells.
    //   3. In the DFS, we count the number of adjacent mines. If there are adjacent mines, we update the cell with the count. If there are no adjacent mines, we change the cell to 'B' and recursively reveal its adjacent cells.
    //   4. Finally, we return the updated board.
    vector<vector<char>> updateBoard(vector<vector<char>> &board, vector<int> &click)
    {
        int r = click[0], c = click[1];
        if (board[r][c] == 'M')
        {
            board[r][c] = 'X';
            return board;
        }
        dfs(board, r, c);
        return board;
    }

    void dfs(vector<vector<char>> &board, int r, int c)
    {
        int m = board.size(), n = board[0].size();
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'E')
            return;

        static const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        static const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

        int mines = 0;
        for (int d = 0; d < 8; d++)
        {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && board[nr][nc] == 'M')
                mines++;
        }

        if (mines > 0)
        {
            board[r][c] = '0' + mines;
        }
        else
        {
            board[r][c] = 'B';
            for (int d = 0; d < 8; d++)
                dfs(board, r + dr[d], c + dc[d]);
        }
    }
};
