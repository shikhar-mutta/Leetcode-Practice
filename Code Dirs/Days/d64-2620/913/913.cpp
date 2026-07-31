// Link: https://leetcode.com/problems/cat-and-mouse/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3)  SC: O(n^2)
//  Approach: retrograde analysis (Zermelo's algorithm) over states
//  (mousePos, catPos, turn). Terminal states (mouse at hole=0 -> mouse
//  wins; mouse caught by cat -> cat wins) are seeded first, then
//  propagated backward via BFS: a predecessor state is decided the
//  moment either (a) it's that player's turn and one of the winning
//  moves leads to their win, or (b) every possible move from it leads to
//  the same loss (tracked via a remaining-degree counter). States never
//  resolved after the BFS drains are draws.
class Solution
{
private:
    int n;
    vector<vector<int>> graph;
    vector<uint8_t> color;
    vector<uint8_t> degree;

    inline int id(int m, int c, int t) const { return ((m * n + c) << 1) | t; }

public:
    int catMouseGame(vector<vector<int>> &g)
    {
        graph = g;
        n = graph.size();

        color.assign(n * n * 2, 0);
        degree.assign(n * n * 2, 0);

        for (int m = 0; m < n; ++m)
        {
            for (int c = 0; c < n; ++c)
            {
                degree[id(m, c, 0)] = graph[m].size();

                int catDeg = 0;
                for (int nxt : graph[c])
                {
                    if (nxt != 0)
                        ++catDeg;
                }

                degree[id(m, c, 1)] = catDeg;
            }
        }

        queue<array<int, 3>> q;

        for (int c = 1; c < n; ++c)
        {
            for (int t = 0; t < 2; ++t)
            {
                color[id(0, c, t)] = 1;
                q.push({0, c, t});
            }
        }

        for (int m = 1; m < n; ++m)
        {
            for (int t = 0; t < 2; ++t)
            {
                color[id(m, m, t)] = 2;
                q.push({m, m, t});
            }
        }

        while (!q.empty())
        {
            auto [m, c, t] = q.front();
            q.pop();

            int result = color[id(m, c, t)];
            int prevTurn = t ^ 1;

            if (prevTurn == 0)
            {
                for (int prevM : graph[m])
                {
                    int s = id(prevM, c, 0);

                    if (color[s] != 0)
                        continue;

                    if (result == 1)
                    {
                        color[s] = 1;
                        q.push({prevM, c, 0});
                    }
                    else
                    {
                        if (--degree[s] == 0)
                        {
                            color[s] = 2;
                            q.push({prevM, c, 0});
                        }
                    }
                }
            }
            else
            {
                for (int prevC : graph[c])
                {
                    if (prevC == 0)
                        continue;

                    int s = id(m, prevC, 1);

                    if (color[s] != 0)
                        continue;

                    if (result == 2)
                    {
                        color[s] = 2;
                        q.push({m, prevC, 1});
                    }
                    else
                    {
                        if (--degree[s] == 0)
                        {
                            color[s] = 1;
                            q.push({m, prevC, 1});
                        }
                    }
                }
            }
        }

        return color[id(1, 2, 0)];
    }
};