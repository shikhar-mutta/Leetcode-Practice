// Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m*k)  SC: O(n*m*k)
// Approach: BFS with 3D visited array to track (x,y,obstaclesRemoved) states. Each state is pushed into the queue with the number of obstacles removed so far. If we reach the destination with obstaclesRemoved <= k, we return the path length.
class Solution
{
public:
    vector<vector<int>> directions{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    int shortestPath(vector<vector<int>> &grid, int k)
    {

        int n = grid.size();
        int m = grid[0].size();

        if (k >= n + m - 2)
            return n + m - 2;
        queue<array<int, 3>> q;

        vector<vector<vector<bool>>> vis(
            n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));

        int cnt = (grid[0][0] == 1) ? 1 : 0;
        q.push({0, 0, cnt});
        vis[0][0][cnt] = true;

        int l = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                auto [x, y, c] = q.front();
                q.pop();

                if (x == n - 1 && y == m - 1 && c <= k)
                    return l;

                for (auto &d : directions)
                {
                    int i = x + d[0];
                    int j = y + d[1];

                    if (i >= 0 && j >= 0 && i < n && j < m)
                    {
                        int temp = (grid[i][j] == 1) ? 1 : 0;
                        if (c + temp <= k && !vis[i][j][c + temp])
                        {
                            q.push({i, j, c + temp});
                            vis[i][j][c + temp] = true;
                        }
                    }
                }
            }
            l++;
        }

        return -1;
    }
};