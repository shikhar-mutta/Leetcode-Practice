// Link: https://leetcode.com/problems/number-of-restricted-paths-from-first-to-last-node/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(ElogV), SC: O(V+E)
    //  Approach: Dijkstra's Algorithm
    //    1. We can use Dijkstra's algorithm to find the shortest distance from the last node to all other nodes.
    //    2. We can then use a priority queue to traverse the graph in order of increasing distance from the last node.
    //    3. For each node, we can count the number of restricted paths to the last node by summing the number of restricted paths from its neighbors that are closer to the last node.
    //    4. Finally, we can return the number of restricted paths from the first node to the last node.
    int countRestrictedPaths(int n, vector<vector<int>> &edges)
    {
        static constexpr int mod = 1'000'000'007;
        static constexpr long long inf = LLONG_MAX / 4;
        vector<int> degree(n + 1);
        for (const auto &e : edges)
        {
            ++degree[e[0]];
            ++degree[e[1]];
        }
        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            graph[i].reserve(degree[i]);
        }
        for (const auto &e : edges)
        {
            int a = e[0];
            int b = e[1];
            int w = e[2];
            graph[a].push_back({b, w});
            graph[b].push_back({a, w});
        }
        vector<long long> dist(n + 1, inf);
        vector<int> ways(n + 1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<>>
            pq;
        dist[n] = 0;
        pq.push({0, n});
        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();
            if (d != dist[u])
            {
                continue;
            }
            int sum = (u == n);
            for (auto [v, w] : graph[u])
            {
                if (dist[v] < d)
                {
                    sum += ways[v];
                    if (sum >= mod)
                    {
                        sum -= mod;
                    }
                }
                long long candidate = d + w;
                if (candidate < dist[v])
                {
                    dist[v] = candidate;
                    pq.push({candidate, v});
                }
            }
            ways[u] = sum;
            if (u == 1)
            {
                return ways[1];
            }
        }
        return ways[1];
    }
};