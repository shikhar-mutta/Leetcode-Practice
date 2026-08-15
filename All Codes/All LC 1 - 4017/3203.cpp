// Link: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n1+n2)  SC: O(n1+n2)
//  Approach: The diameter of a tree is the longest path between any two nodes. To find the diameter of a tree, we can perform two breadth-first searches (BFS). First, we perform a BFS from an arbitrary node to find the farthest node from it. Then, we perform a second BFS from that farthest node to find the farthest node from it, which gives us the diameter of the tree. To find the minimum diameter after merging two trees, we can calculate the diameters of both trees and then use the formula: min_diameter = max(d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1), where d1 and d2 are the diameters of the two trees. This formula accounts for the case where the two trees are merged by connecting their centers, which minimizes the overall diameter.
class Solution
{
public:
    struct Graph
    {
        vector<int> offset;
        vector<int> adj;
        int n;
    };

    Graph buildGraph(const vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;

        Graph g;
        g.n = n;

        vector<int> deg(n, 0);

        for (auto &e : edges)
        {
            deg[e[0]]++;
            deg[e[1]]++;
        }

        g.offset.resize(n + 1, 0);

        for (int i = 0; i < n; i++)
            g.offset[i + 1] = g.offset[i] + deg[i];

        g.adj.resize(2 * edges.size());

        vector<int> cur = g.offset;

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            g.adj[cur[u]++] = v;
            g.adj[cur[v]++] = u;
        }

        return g;
    }

    pair<int, int> bfs(int src, const Graph &g)
    {
        vector<int> dist(g.n, -1);
        vector<int> q(g.n);

        int head = 0;
        int tail = 0;

        q[tail++] = src;
        dist[src] = 0;

        int farNode = src;
        int farDist = 0;

        while (head < tail)
        {
            int u = q[head++];

            if (dist[u] > farDist)
            {
                farDist = dist[u];
                farNode = u;
            }

            for (int i = g.offset[u]; i < g.offset[u + 1]; i++)
            {
                int v = g.adj[i];

                if (dist[v] == -1)
                {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }

        return {farNode, farDist};
    }

    int diameter(const Graph &g)
    {
        auto p1 = bfs(0, g);

        auto p2 = bfs(p1.first, g);

        return p2.second;
    }

    int minimumDiameterAfterMerge(vector<vector<int>> &edges1,
                                  vector<vector<int>> &edges2)
    {
        Graph g1 = buildGraph(edges1);
        Graph g2 = buildGraph(edges2);

        int d1 = diameter(g1);
        int d2 = diameter(g2);

        return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
    }
};