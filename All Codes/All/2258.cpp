// Link: https://leetcode.com/problems/escape-the-spreading-fire/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m) where n is the number of rows and m is the number of columns in the grid
// SC: O(n*m) where n is the number of rows and m is the number of columns in the grid
// Approach: We can use a breadth-first search (BFS) approach to solve this problem. We can first find the minimum time it takes for the fire to reach each cell in the grid. Then, we can find the minimum time it takes for the person to reach the bottom-right cell. If the person can reach the bottom-right cell before the fire, we can return the difference between the two times. If the person cannot reach the bottom-right cell before the fire, we can return -1. If the fire cannot reach the bottom-right cell, we can return a large number (1e9) to indicate that the person can wait indefinitely before starting to move. Finally, we can check if the person can wait at the bottom-right cell for a certain amount of time before the fire reaches it. If the person can wait, we can return the difference between the two times. If the person cannot wait, we can return the difference minus one.
class Solution
{
public:
    int maximumMinutes(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<vector<int>> dis(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    dis[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int di[] = {-1, 1, 0, 0};
        int dj[] = {0, 0, -1, 1};
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int r = it.first;
            int c = it.second;
            if (vis[r][c])
                continue;
            vis[r][c] = 1;
            for (int k = 0; k < 4; k++)
            {
                int nr = r + di[k];
                int nc = c + dj[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    grid[nr][nc] != 2)
                {
                    if (!vis[nr][nc] && dis[nr][nc] > dis[r][c] + 1)
                    {
                        dis[nr][nc] = dis[r][c] + 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
        int mini1 = dis[n - 1][m - 1];
        vector<vector<int>> vis1(n, vector<int>(m, 0));
        vector<vector<int>> dis1(n, vector<int>(m, 1e9));
        queue<pair<int, int>> q1;
        q1.push({0, 0});
        dis1[0][0] = 0;
        while (!q1.empty())
        {
            auto it = q1.front();
            q1.pop();
            int r = it.first;
            int c = it.second;
            if (vis1[r][c])
                continue;
            vis1[r][c] = 1;
            for (int k = 0; k < 4; k++)
            {
                int nr = r + di[k];
                int nc = c + dj[k];
                if (nr >= 0 && nc >= 0 && nr < n && nc < m &&
                    grid[nr][nc] == 0)
                {
                    if (!vis1[nr][nc] && dis1[nr][nc] > dis1[r][c] + 1)
                    {
                        dis1[nr][nc] = dis1[r][c] + 1;
                        q1.push({nr, nc});
                    }
                }
            }
        }
        int fire_safe = dis[n - 1][m - 1];
        int person_safe = dis1[n - 1][m - 1];
        if (person_safe == 1e9 || fire_safe < person_safe)
            return -1;
        if (fire_safe == 1e9)
            return 1e9;
        int diff = fire_safe - person_safe;
        bool top_valid = (n - 2 >= 0 && dis1[n - 2][m - 1] != 1e9 &&
                          (dis[n - 2][m - 1] - dis1[n - 2][m - 1] > diff));
        bool left_valid = (m - 2 >= 0 && dis1[n - 1][m - 2] != 1e9 &&
                           (dis[n - 1][m - 2] - dis1[n - 1][m - 2] > diff));
        if (top_valid || left_valid)
        {
            return diff;
        }
        return diff - 1;
    }
};