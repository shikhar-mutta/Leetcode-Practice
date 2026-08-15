// Link: https://leetcode.com/problems/modify-graph-edge-weights/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V), SC: O(V + E)
//  Approach: We can use Dijkstra's algorithm to find the shortest path from the source to the destination. We will run Dijkstra's algorithm twice: once from the destination to find the shortest path to the destination using only positive edges, and once from the source to find the shortest path to the destination using both positive and modifiable edges. During the second run, we will dynamically adjust the weights of the modifiable edges to ensure that the total path length equals the target. If we can achieve the target path length, we will return the modified edges; otherwise, we will return an empty array. The key insight is that we can calculate the exact weight needed for a modifiable edge to achieve the target path length based on the current distances from the source and destination.
class Solution
{
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>> &edges, int source, int destination, int target)
    {
        // A safely large infinity that won't overflow a 64-bit integer
        const long long INF = 2e15;

        // Build the adjacency list once.
        // We store pairs of {neighbor_node, edge_index} so we can modify the original edges array directly.
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < edges.size(); ++i)
        {
            adj[edges[i][0]].push_back({edges[i][1], i});
            adj[edges[i][1]].push_back({edges[i][0], i});
        }

        // ---------------------------------------------------------
        // PASS 1: Dijkstra from Destination (Only Positive Edges)
        // ---------------------------------------------------------
        vector<long long> distR(n, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pqR;

        distR[destination] = 0;
        pqR.push({0, destination});

        while (!pqR.empty())
        {
            auto [d, u] = pqR.top();
            pqR.pop();

            if (d > distR[u])
                continue;

            for (auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                int idx = neighbor.second;
                long long w = edges[idx][2];

                // Ignore modifiable edges entirely for this pass
                if (w == -1)
                    continue;

                if (distR[u] + w < distR[v])
                {
                    distR[v] = distR[u] + w;
                    pqR.push({distR[v], v});
                }
            }
        }

        // If the positive-only path is already faster than the target, it's impossible.
        if (distR[source] < target)
        {
            return {};
        }

        // ---------------------------------------------------------
        // PASS 2: Dijkstra from Source (Dynamic Edge Tuning)
        // ---------------------------------------------------------
        vector<long long> dist(n, INF);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty())
        {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u])
                continue;

            for (auto &neighbor : adj[u])
            {
                int v = neighbor.first;
                int idx = neighbor.second;
                long long w = edges[idx][2];

                if (w == -1)
                {
                    // Mathematically calculate the exact weight needed to hit the target.
                    // If it's negative or 0, we brake as little as possible by choosing 1.
                    w = max(1LL, (long long)target - dist[u] - distR[v]);

                    // Modify the edge permanently globally
                    edges[idx][2] = w;
                }

                if (dist[u] + w < dist[v])
                {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        // ---------------------------------------------------------
        // FINAL CHECK
        // ---------------------------------------------------------
        if (dist[destination] == target)
        {
            // There might be some -1 edges we never visited.
            // We must convert them to valid positive values. 2 * 10^9 is safe and pushes them out of the way.
            for (auto &edge : edges)
            {
                if (edge[2] == -1)
                {
                    edge[2] = 2e9;
                }
            }
            return edges;
        }

        return {};
    }
};
