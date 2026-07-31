// Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(m*n)  SC: O(m*n)
//  Approach: 0-1 BFS. The cost of moving to a neighbor is either 0 or 1, depending on whether the direction of the current cell matches the direction of the move. We can use a deque to perform a 0-1 BFS, where we push neighbors with cost 0 to the front of the deque and neighbors with cost 1 to the back.
//  We keep track of the minimum cost to reach each cell, and when we reach the bottom-right cell, we return the minimum cost.
class Solution
{
public:
    int minCost(vector<vector<int>> &grid)
    {
        static const int INF = 1000000;
        const int m = grid.size();
        const int n = grid[0].size();
        auto index = [&](int i, int j)
        { return i * n + j; };
        auto coordinates = [&](int index)
        {
            return array<int, 2>{index / n, index % n};
        };
        auto on_grid = [&](int i, int j)
        {
            return i >= 0 && i < m && j >= 0 && j < n;
        };
        struct offset
        {
            int i, j, label;
        };
        array<offset, 4> offsets{
            {{0, 1, 1}, {0, -1, 2}, {1, 0, 3}, {-1, 0, 4}}};

        vector<int> d(m * n, INF);
        d[0] = 0;
        vector<int> q0, q1;
        q0.push_back(0);
        int curdist = 0;
        while (true)
        {
            while (!(q0.empty()))
            {
                int v = q0.back();
                q0.pop_back();

                if (d[v] < curdist)
                    continue;
                auto [i, j] = coordinates(v);
                if (i == m - 1 && j == n - 1)
                    return curdist;
                auto val = grid[i][j];
                for (auto [off_i, off_j, label] : offsets)
                {
                    int ni = i + off_i;
                    int nj = j + off_j;
                    if (on_grid(ni, nj))
                    {
                        int u = index(ni, nj);
                        bool w = (label != val);
                        if (d[v] + w < d[u])
                        {
                            d[u] = d[v] + w;
                            (w ? q1 : q0).push_back(u);
                        }
                    }
                }
            }
            swap(q0, q1);
            curdist++;
        }
    }
};
