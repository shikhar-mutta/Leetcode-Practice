// Link: https://leetcode.com/problems/design-graph-with-shortest-path-calculator/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^3) for initialization, O(n^2) for addEdge, O(1) for shortestPath
// SC: O(n^2) for distance matrix
//  Approach: We can use Floyd-Warshall algorithm to find the shortest path between all pairs of vertices. We can store the distance matrix and update it when a new edge is added. The shortestPath function can then return the distance between the source and destination vertices in O(1) time .
class Graph
{
public:
    Graph(int n, const vector<vector<int>> &edges)
        : dist_(n * n, kMaxDist), nVertices_(n)
    {

        for (int i = 0; i < n; i++)
        {
            dist_[i * n + i] = 0;
        }
        for (const auto &e : edges)
        {
            int idx = e[0] * n + e[1];
            dist_[idx] = min(dist_[idx], e[2]);
        }

        // Classic Floyd-Warshall optimized for cache performance
        for (int mid = 0; mid < n; mid++)
        {
            for (int from = 0; from < n; from++)
            {
                int from_mid = dist_[from * n + mid];
                if (from_mid == kMaxDist)
                    continue; // Skip unreachable paths (Prevents overflow)

                int *current_row = &dist_[from * n];
                int *mid_row = &dist_[mid * n];

                for (int to = 0; to < n; to++)
                {
                    if (mid_row[to] != kMaxDist)
                    {
                        current_row[to] =
                            min(current_row[to], from_mid + mid_row[to]);
                    }
                }
            }
        }
    }

    void addEdge(const vector<int> &edge)
    {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // Optimization: If the new edge is worse than what we have, do nothing
        if (weight >= dist_[u * nVertices_ + v])
            return;

        int *v_row = &dist_[v * nVertices_];

        for (int from = 0; from < nVertices_; from++)
        {
            int from_u = dist_[from * nVertices_ + u];
            if (from_u == kMaxDist)
                continue; // Skip if 'u' is unreachable from 'from'

            int base_dist =
                from_u + weight; // Caches the constant part of the addition
            int *current_row = &dist_[from * nVertices_];

            // Micro-optimization: Loop unrolling or SIMD vectorization ready
            for (int to = 0; to < nVertices_; to++)
            {
                if (v_row[to] != kMaxDist)
                {
                    int new_dist = base_dist + v_row[to];
                    if (new_dist < current_row[to])
                    {
                        current_row[to] = new_dist;
                    }
                }
            }
        }
    }

    int shortestPath(int source, int dest)
    {
        int d = dist_[source * nVertices_ + dest];
        return d != kMaxDist ? d : -1;
    }

private:
    static constexpr int kMaxDist =
        1e9; // Safe from overflow with 'continue' checks
    vector<int> dist_;
    int nVertices_;
};