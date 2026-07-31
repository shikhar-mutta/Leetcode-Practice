// Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(R*C), SC: O(R*C)
//  Approach: 0-1 BFS (deque) — moving into empty cell costs 0, into obstacle costs 1.
class Solution
{
public:
    int minimumObstacles(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        deque<int> dq;

        vector<int> dist(m * n, 1e9);

        dist[0] = 0;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        dq.push_front(0);

        while (!dq.empty())
        {
            int node = dq.front();
            dq.pop_front();

            int r = node / n;
            int c = node - r * n;

            for (auto it : dirs)
            {
                int nr = r + it.first;
                int nc = c + it.second;

                int newNode = nr * n + nc;

                int w = 0;

                if (nr >= 0 && nr < m && nc >= 0 && nc < n)
                {
                    if (grid[nr][nc] == 1)
                        w = 1;

                    if (dist[newNode] > dist[node] + w)
                    {
                        dist[newNode] = dist[node] + w;

                        if (w == 0)
                            dq.push_front(newNode);

                        else
                            dq.push_back(newNode);
                    }
                }
            }
        }

        return dist[m * n - 1] == 1e9 ? 0 : dist[m * n - 1];
    }
};