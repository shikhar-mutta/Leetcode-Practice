// Link: https://leetcode.com/problems/minimum-number-of-visited-cells-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n), SC: O(m*n)
//  Approach: We can use BFS to find the minimum number of visited cells needed to reach the bottom-right cell from the top-left cell. We can keep track of the maximum reachable row and column for each cell and use a queue to perform BFS. For each cell, we can check the reachable cells in the same row and column and add them to the queue if they are not visited yet. Finally, we can return the minimum number of visited cells needed to reach the bottom-right cell.
class Solution
{
public:
    int minimumVisitedCells(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();

        vector<priority_queue<pair<int, int>, vector<pair<int, int>>,
                              greater<pair<int, int>>>>
            row(m), col(n);

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 1;
        row[0].push({1, 0});
        col[0].push({1, 0});

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                while (!row[i].empty() && row[i].top().second < j)
                    row[i].pop();
                while (!col[j].empty() && col[j].top().second < i)
                    col[j].pop();

                if (i == 0 && j == 0)
                {
                    // already initialized
                }
                else
                {
                    if (!row[i].empty())
                        dist[i][j] = min(dist[i][j], row[i].top().first + 1);
                    if (!col[j].empty())
                        dist[i][j] = min(dist[i][j], col[j].top().first + 1);
                }

                if (dist[i][j] == INT_MAX || grid[i][j] == 0)
                    continue;

                row[i].push({dist[i][j], j + grid[i][j]});
                col[j].push({dist[i][j], i + grid[i][j]});
            }
        }

        return dist[m - 1][n - 1] == INT_MAX ? -1 : dist[m - 1][n - 1];
    }
};
