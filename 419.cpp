// Link: https://leetcode.com/problems/battleships-in-a-board/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int n, m;
    vector<vector<bool>> visited;
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '.' || visited[i][j])
            return;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            int ni = i + dx[k], nj = j + dy[k];
            dfs(board,  ni, nj);
        }
    }
    int countBattleships(vector<vector<char>> &board)
    {
        n = board.size(), m = board[0].size();
        visited = vector<vector<bool>>(n, vector<bool>(m, false));
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'X' && !visited[i][j])
                {
                    count++;
                    dfs(board,  i, j);
                }
            }
        }
        return count;
    }
};
