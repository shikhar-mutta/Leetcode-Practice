// Link: https://leetcode.com/problems/is-graph-bipartite/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(V + E). SC: O(V) — BFS 2-coloring across all components
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        vector<int> color(n, -1); // -1 = uncolored, 0/1 = two sides

        for (int start = 0; start < n; start++)
        {
            if (color[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty())
            {
                int u = q.front();
                q.pop();

                for (int v : graph[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                    {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
