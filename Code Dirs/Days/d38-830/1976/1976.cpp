// Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(ElogV) + O(V + E) ~ O(ElogV)
// SC: O(V + E) + O(V) + O(V) ~ O(V + E)
// Approach: Dijkstra's Algorithm
class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        const int MOD = 1e9 + 7;
        vector<vector<pair<int, int>>> adj(n);
        for (auto &it : roads)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>>
            pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            int node = it.second;
            if (dis > dist[node])
                continue;
            for (auto nbr : adj[node])
            {
                int adjNode = nbr.first;
                int wt = nbr.second;
                if (dis + wt < dist[adjNode])
                {
                    dist[adjNode] = dis + wt;
                    ways[adjNode] = ways[node];
                    pq.push({dist[adjNode], adjNode});
                }
                else if (dis + wt == dist[adjNode])
                {
                    ways[adjNode] =
                        (ways[adjNode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1];
    }
};