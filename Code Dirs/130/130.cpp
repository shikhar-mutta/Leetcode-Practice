// Link: https://leetcode.com/problems/surrounded-regions/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n) where m is the number of rows and n is the number of columns in the board.
// SC: O(m*n) for the recursion stack in the worst case.
class Solution
{
    int m, n;
    // Mark every 'O' reachable from a border cell as safe ('#').
    void dfs(vector<vector<char>> &b, int i, int j)
    {
        if (i < 0 || j < 0 || i >= m || j >= n || b[i][j] != 'O')
            return;
        b[i][j] = '#';
        dfs(b, i + 1, j);
        dfs(b, i - 1, j);
        dfs(b, i, j + 1);
        dfs(b, i, j - 1);
    }

public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        // Protect all border-connected regions first.
        for (int i = 0; i < m; i++)
        {
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        // Remaining 'O's are surrounded -> flip; restore the safe ones.
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
    }
};
