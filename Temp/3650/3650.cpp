// Link: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V) SC: O(V + E)
//  Approach: Dijkstra where each directed edge (u,v,w) can be traversed
//  forward at cost w, or effectively reversed (v to u) at cost 2w.
class Solution
{
public:
    long long minCost(int n, vector<vector<int>> &edges)
    {
        int m = edges.size(), idx = 0;
        vector<int> head(n, -1), to(2 * m), w(2 * m), nxt(2 * m);
        auto add = [&](int u, int v, int c)
        {
            to[idx] = v, w[idx] = c, nxt[idx] = head[u], head[u] = idx++;
        };
        for (auto &e : edges)
        {
            add(e[0], e[1], e[2]);
            add(e[1], e[0], 2 * e[2]);
        }
        vector<long long> d(n, LLONG_MAX);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        d[0] = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [du, u] = pq.top();
            pq.pop();
            if (du != d[u])
                continue;
            if (u == n - 1)
                return du;
            for (int i = head[u]; i != -1; i = nxt[i])
            {
                int v = to[i];
                if (d[v] > du + w[i])
                {
                    d[v] = du + w[i];
                    pq.push({d[v], v});
                }
            }
        }
        return -1;
    }
};