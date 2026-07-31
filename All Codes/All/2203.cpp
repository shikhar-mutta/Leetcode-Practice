// Link: https://leetcode.com/problems/minimum-weighted-subgraph-with-the-required-paths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(ElogV)  SC: O(V + E)
// Approach: We can use Dijkstra's algorithm to find the shortest path from src1 and src2 to all other nodes in the graph. We can also find the shortest path from dest to all other nodes in the graph by reversing the edges. Finally, we can iterate through all nodes and find the minimum weight of the subgraph that contains the required paths from src1 and src2 to dest. If there is no such subgraph, we can return -1.
class Solution
{
    vector<vector<pair<int, int>>> adj;

public:
    void dijkstra(int src, vector<long long> &dist)
    {
        priority_queue<pair<long long, int>,
                       vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;
        dist[src] = 0;
        pq.push(make_pair(0, src));

        while (!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node])
                continue;

            for (auto [i, wt] : adj[node])
            {
                if (d + wt < dist[i])
                {
                    dist[i] = d + wt;
                    pq.push(make_pair(dist[i], i));
                }
            }
        }
    }

    long long minimumWeight(int n, vector<vector<int>> &edges, int src1, int src2, int dest)
    {
        adj.assign(n, {});
        for (vector<int> &e : edges)
            adj[e[0]].push_back(make_pair(e[1], e[2]));

        vector<long long> d1(n, LONG_MAX);
        dijkstra(src1, d1);
        vector<long long> d2(n, LONG_MAX);
        dijkstra(src2, d2);

        for (int i = 0; i < n; i++)
            adj[i].clear();

        for (vector<int> &e : edges)
            adj[e[1]].push_back(make_pair(e[0], e[2]));

        vector<long long> dd(n, LONG_MAX);
        dijkstra(dest, dd);

        long long ans = LONG_MAX;
        for (int i = 0; i < n; i++)
        {
            if (d1[i] == LONG_MAX || d2[i] == LONG_MAX || dd[i] == LONG_MAX)
                continue;
            ans = min(ans, d1[i] + d2[i] + dd[i]);
        }

        return ans == LONG_MAX ? -1 : ans;
    }
};