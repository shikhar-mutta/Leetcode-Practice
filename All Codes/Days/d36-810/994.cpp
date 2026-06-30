// Link: https://leetcode.com/problems/rotting-oranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n), SC: O(m*n)
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        if (fresh == 0)
            return 0;

        int minutes = 0;
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        // BFS level by level; each level is one minute of spreading.
        while (!q.empty() && fresh > 0)
        {
            int sz = q.size();
            while (sz--)
            {
                auto [x, y] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                        continue;
                    if (grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    fresh--;
                    q.push({nx, ny});
                }
            }
            minutes++;
        }
        return fresh == 0 ? minutes : -1;
    }
};
