// Link: https://leetcode.com/problems/01-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(m*n) where m is the number of rows and n is the number of columns in the matrix.
    // SC: O(m*n) for the distance matrix and the queue used for BFS.
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> dist(m, vector<int>(n, -1));
        queue<pair<int, int>> q;
        // Seed BFS with every 0 cell (distance 0).
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0)
                {
                    dist[i][j] = 0;
                    q.push({i, j});
                }

        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (dist[nx][ny] != -1)
                    continue; // already reached
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return dist;
    }
};
