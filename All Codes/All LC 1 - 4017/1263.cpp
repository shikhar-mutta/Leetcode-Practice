// Link: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*4*4)  SC: O(m*n*4*4)  m = grid.size() n = grid[0].size()
// Approach: BFS over the state of (boxX, boxY, personX, personY). For each state, try to push the box in all 4 directions. For each direction, check if the person can reach the opposite side of the box to push it. If yes, add the new state to the queue and mark it as visited. Return the number of pushes when the box reaches the target.
class Solution
{
public:
    bool canReach(vector<vector<char>> &grid, int sx, int sy, int &tx, int &ty,
                  int &bx, int &by)
    {

        int m = grid.size(), n = grid[0].size();

        if (sx == tx && sy == ty)
            return true;

        queue<pair<int, int>> q;
        bool vis[20][20] = {};

        q.push({sx, sy});
        vis[sx][sy] = true;

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || ny < 0 || nx >= m || ny >= n)
                    continue;
                if (vis[nx][ny])
                    continue;
                if (grid[nx][ny] == '#')
                    continue;
                if (nx == bx && ny == by)
                    continue;

                if (nx == tx && ny == ty)
                    return true;

                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }

        return false;
    }
    int minPushBox(vector<vector<char>> &grid)
    {
        int xb, yb, xs, ys;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 'B')
                {
                    xb = i;
                    yb = j;
                    grid[i][j] = '.';
                }
                if (grid[i][j] == 'S')
                {
                    xs = i;
                    ys = j;
                    grid[i][j] = '.';
                }
            }
        }
        queue<tuple<int, int, int, int>> q;
        // xbox, ybox, xper, yper
        int lv = 0;
        q.push({xb, yb, xs, ys});
        bool vis[20][20][20][20] = {false};
        vis[xb][yb][xs][ys] = true;
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        while (!q.empty())
        {
            int sz = q.size();
            lv++;
            while (sz--)
            {
                auto [ib, jb, is, js] = q.front();
                q.pop();
                for (int k = 0; k < 4; k++)
                {
                    xb = ib + dx[k];
                    yb = jb + dy[k];
                    xs = ib - dx[k];
                    ys = jb - dy[k];
                    if (xb < 0 || yb < 0 || xb >= grid.size() ||
                        yb >= grid[0].size() || xs < 0 || ys < 0 ||
                        xs >= grid.size() || ys >= grid[0].size() ||
                        grid[xb][yb] == '#' || grid[xs][ys] == '#')
                    {
                        continue;
                    }
                    if (vis[xb][yb][ib][jb])
                        continue;
                    if (canReach(grid, is, js, xs, ys, ib, jb))
                    {
                        vis[xb][yb][ib][jb] = true;
                        if (grid[xb][yb] == 'T')
                            return lv;
                        q.push({xb, yb, ib, jb});
                    }
                }
            }
        }
        return -1;
    }
};
