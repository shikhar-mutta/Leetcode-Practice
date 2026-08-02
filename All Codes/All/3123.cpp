// Link: https://leetcode.com/problems/find-edges-in-shortest-paths/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(E log V)  SC: O(V+E)
// Approach: Dijkstra from node 0 (dist0[]) and from node n-1 on the same undirected graph (distN[]). Edge (u,v,w) lies on some shortest 0->n-1 path iff dist0[u]+w+distN[v] == dist0[n-1] or dist0[v]+w+distN[u] == dist0[n-1].        
class Solution
{
public:
    vector<bool> findAnswer(int n, vector<vector<int>> &edges)
    {
        vector<bool> ans(edges.size(), false);
        vector<vector<tuple<int, int, int>>> v(n);
        for (int i = 0; i < edges.size(); i++)
        {
            v[edges[i][0]].push_back({edges[i][1], edges[i][2], i});
            v[edges[i][1]].push_back({edges[i][0], edges[i][2], i});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        pq.push({0, 0});
        vector<long long> dis(n, LLONG_MAX);
        dis[0] = 0;
        while (!pq.empty())
        {
            auto [disx, x] = pq.top();
            pq.pop();
            if (x == (n - 1))
            {
                break;
            }
            if (disx > dis[x])
                continue;
            for (auto &[y, disy, index] : v[x])
            {
                if ((disx + disy) < dis[y])
                {
                    dis[y] = disx + disy;
                    pq.push({dis[y], y});
                }
            }
        }
        if (dis[n - 1] == LLONG_MAX)
            return ans;
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(n - 1);
        visited[n - 1] = true;
        while (!q.empty())
        {
            int y = q.front();
            q.pop();
            for (auto &[x, disx, index] : v[y])
            {
                if ((dis[y] - disx) == dis[x])
                {
                    ans[index] = true;
                    if (!visited[x])
                    {
                        q.push(x);
                        visited[x] = true;
                    }
                }
            }
        }

        return ans;
    }
};