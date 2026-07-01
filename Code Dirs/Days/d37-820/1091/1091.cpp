// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2), SC: O(n^2) — BFS over an 8-connected grid
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0)
            return -1;

        int dRow[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dCol[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // reuse grid as visited marker
        int dist = 1;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [r, c] = q.front();
                q.pop();
                if (r == n - 1 && c == n - 1)
                    return dist;

                for (int k = 0; k < 8; k++)
                {
                    int nr = r + dRow[k], nc = c + dCol[k];
                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0)
                    {
                        grid[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
            dist++;
        }

        return -1;
    }
};
