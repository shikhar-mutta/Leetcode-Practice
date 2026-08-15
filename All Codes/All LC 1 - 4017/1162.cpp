// Link: https://leetcode.com/problems/as-far-from-land-as-possible/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) where n is the size of the grid
    // SC: O(n^2) for the queue used in BFS
    //   Approach:
    //    1. Use a multi-source BFS approach starting from all land cells (cells with value 1) and expanding to water cells (cells with value 0).
    //    2. For each level of BFS, increment the distance counter. The last level processed will give the maximum distance from land to water.
    //    3. If there are no land cells or no water cells, return -1 as specified in the problem statement.
    //    4. Return the maximum distance found after processing all levels of BFS.
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();

        queue<pair<int, int>> q;

        // Put all land cells into queue
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    q.push({i, j});
            }
        }

        // No land or no water
        if (q.empty() || q.size() == n * n)
            return -1;

        int dist = -1;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!q.empty())
        {

            int sz = q.size();
            dist++;

            while (sz--)
            {

                auto [x, y] = q.front();
                q.pop();

                for (int k = 0; k < 4; k++)
                {

                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n &&
                        grid[nx][ny] == 0)
                    {

                        grid[nx][ny] = 1; // Mark visited
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};