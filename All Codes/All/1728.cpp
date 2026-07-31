// Link: https://leetcode.com/problems/cat-and-mouse-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n*turns) SC: O(m*n*turns)
//  Approach: BFS + DP
//   We can use BFS to simulate the game. We can use DP to store the state of the game. We can use a queue to store the state of the game. We can use a 3D array to store the state of the game. The first dimension is the turn, the second dimension is the position of the mouse, and the third dimension is the position of the cat. We can use a 2D array to store the number of incoming edges for each state.
class Solution
{
public:
    int m, n, food, cat, mouse;
    bool outBounds(int x, int y) { return x < 0 || y < 0 || x >= m || y >= n; }

    bool canMouseWin(vector<string> &grid, int cj, int mj)
    {
        m = grid.size(), n = grid[0].size(), food = 0, cat = 0, mouse = 0;
        int dp[2][m * n][m * n], insc[m * n][m * n], ins[m * n], bad[m * n];
        memset(dp, 0, sizeof(dp));
        fill(&insc[0][0], &insc[0][0] + (m * n) * (m * n), 1);
        memset(bad, 0, sizeof(bad));
        memset(ins, 0, sizeof(ins));

        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j] == 'F')
                    food = i * n + j;
                if (grid[i][j] == 'C')
                    cat = i * n + j;
                if (grid[i][j] == 'M')
                    mouse = i * n + j;
                if (grid[i][j] == 'F' || grid[i][j] == '#')
                    bad[i * n + j] = 1;
            }
        }

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int curr = i * n + j;
                if (bad[curr])
                    continue;
                for (auto [a, b] : dir)
                {
                    for (int len = 1; len <= cj; ++len)
                    {
                        int x = len * a + i, y = len * b + j, z = x * n + y;
                        if (outBounds(x, y) || (grid[x][y] != 'F' && bad[z]))
                            break;
                        ++ins[curr];
                    }
                }

                for (int ii = 0; ii < m; ++ii)
                {
                    for (int jj = 0; jj < n; ++jj)
                    {
                        int rruc = ii * n + jj;
                        if (bad[rruc] || rruc == curr)
                            continue;
                        insc[rruc][curr] += ins[curr];
                    }
                }
            }
        }

        queue<tuple<int, int, int>> q;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int curr = i * n + j;
                if (bad[curr])
                    continue;
                dp[0][food][curr] = 1;
                q.emplace(0, food, curr);
            }
        }

        int turns = 0;
        while (!q.empty() && turns < 1000)
        {
            int sz = q.size();
            while (sz--)
            {
                auto [t, x, y] = q.front();
                q.pop();
                if (t)
                {
                    int i = y / n, j = y % n;
                    --insc[x][y];
                    if (insc[x][y] == 0 && !dp[0][x][y])
                    {
                        dp[0][x][y] = 1;
                        q.emplace(0, x, y);
                    }

                    for (auto [a, b] : dir)
                    {
                        for (int len = 1; len <= cj; ++len)
                        {
                            int nx = len * a + i, ny = len * b + j,
                                nz = nx * n + ny;
                            if (outBounds(nx, ny) || bad[nz])
                                break;
                            if (dp[0][x][nz] || x == nz)
                                continue;
                            --insc[x][nz];
                            if (insc[x][nz] == 0)
                            {
                                dp[0][x][nz] = 1;
                                q.emplace(0, x, nz);
                            }
                        }
                    }
                }
                else
                {
                    int i = x / n, j = x % n;
                    for (auto [a, b] : dir)
                    {
                        for (int len = 1; len <= mj; ++len)
                        {
                            int nx = len * a + i, ny = len * b + j,
                                nz = nx * n + ny;
                            if (outBounds(nx, ny) || bad[nz])
                                break;
                            if (dp[1][nz][y] || nz == y)
                                continue;
                            dp[1][nz][y] = 1;
                            q.emplace(1, nz, y);
                        }
                    }
                }
            }

            ++turns;
        }

        return dp[1][mouse][cat];
    }
};
