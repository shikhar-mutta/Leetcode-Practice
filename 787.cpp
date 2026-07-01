// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E + VlogV), SC: O(V) — Dijkstra's algorithm on a graph
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if (stops > k)
                continue;
            for (auto nbr : adj[node])
            {
                int adjnode = nbr.first;
                int addncost = nbr.second;
                if (addncost + cost < dist[adjnode] && stops <= k)
                {
                    dist[adjnode] = addncost + cost;
                    q.push({stops + 1, {adjnode, cost + addncost}});
                }
            }
        }
        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};