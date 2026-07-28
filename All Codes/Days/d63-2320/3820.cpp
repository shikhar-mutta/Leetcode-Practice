// Link: https://leetcode.com/problems/pythagorean-distance-nodes-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) SC: O(n)
// Approach: For each node u, we can compute the distance from x, y, z to u using BFS. Then we can check if the distances satisfy the Pythagorean theorem.
//  We can use BFS to compute the distances from x, y, z to all nodes in O(n) time. Then we can check the Pythagorean theorem for each node in O(nlogn) time.
class Solution
{
    vector<int> bfsDist(int n, vector<vector<int>> &adj, int src)
    {
        vector<int> dist(n, -1);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
            {
                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }

public:
    int specialNodes(int n, vector<vector<int>> &edges, int x, int y, int z)
    {
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> dx = bfsDist(n, adj, x);
        vector<int> dy = bfsDist(n, adj, y);
        vector<int> dz = bfsDist(n, adj, z);

        int ans = 0;
        for (int u = 0; u < n; u++)
        {
            array<long long, 3> d = {dx[u], dy[u], dz[u]};
            sort(d.begin(), d.end());
            if (d[0] * d[0] + d[1] * d[1] == d[2] * d[2])
                ans++;
        }
        return ans;
    }
};
