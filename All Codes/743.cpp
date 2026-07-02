// Link: https://leetcode.com/problems/network-delay-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(E log V), where E is the number of edges and V is the number of vertices.
    // SC: O(V + E)
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // Dijkstra from source k over the directed weighted graph.
        vector<vector<pair<int, int>>> adj(n + 1); // adj[u] = {v, w}
        for (auto &e : times)
            adj[e[0]].push_back({e[1], e[2]});

        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;
        // min-heap of {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d > dist[u])
                continue;
            for (auto &[v, w] : adj[u])
            {
                if (d + w < dist[v])
                {
                    dist[v] = d + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] == INT_MAX)
                return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
