// Link: https://leetcode.com/problems/minimum-degree-of-a-connected-trio-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) SC: O(n^2)
//   Approach: Brute Force + Bitset
//   We can use a bitset to store the adjacency matrix of the graph. We can use a degree array to store the degree of each node. We can iterate through all the edges and for each edge, we can check if there is a common neighbor of the two nodes. If there is a common neighbor, we can calculate the degree of the trio and update the minimum degree. We can return -1 if there is no trio in the graph.
class Solution
{
public:
    bitset<405> adj[405];
    int deg[405];
    int minTrioDegree(int n, vector<vector<int>> &edges)
    {
        memset(deg, 0, sizeof(deg));
        for (int i = 1; i <= n; ++i)
        {
            adj[i].reset();
        }
        for (vector<int> &edge : edges)
        {
            int u = edge[0], v = edge[1];
            adj[u][v] = 1;
            adj[v][u] = 1;
            deg[u]++;
            deg[v]++;
        }
        int ans = INT_MAX;
        for (int u = 1; u <= n; ++u)
        {
            for (int v = u + 1; v <= n; ++v)
            {
                if (!adj[u][v])
                    continue;
                bitset<405> b = adj[u] & adj[v];
                for (int w = v + 1; w <= n; ++w)
                {
                    if (!b[w])
                        continue;
                    ans = min(ans, deg[u] + deg[v] + deg[w] - 6);
                }
            }
        }
        if (ans == INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};