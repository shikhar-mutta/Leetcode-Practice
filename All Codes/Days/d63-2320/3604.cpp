// Link: https://leetcode.com/problems/minimum-time-to-reach-destination-in-directed-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(E log V) SC: O(V + E)
//  Approach: Dijkstra where an edge (u,v,start,end) is only usable if we
//  arrive at u by time <= end; departure is max(arrivalTime, start), and
//  traversal takes 1 unit, so relax dist[v] with max(dist[u],start)+1.
class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges)
    {
        vector<pair<int, pair<int, int>>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back({edges[i][1], {edges[i][2], edges[i][3]}});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> t(n, INT_MAX);
        t[0] = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            int ct = it.first;
            int u = it.second;
            if (t[u] < ct)
                continue;
            if (u == n - 1)
            {
                return ct;
            }

            for (auto it : adj[u])
            {
                int v = it.first;
                int s = it.second.first;
                int e = it.second.second;
                int nt = ct;
                if (s <= ct && ct <= e)
                {
                    nt = ct + 1;
                    if (t[v] > nt)
                    {
                        t[v] = nt;
                        pq.push({nt, v});
                    }
                }
                else if (ct < s)
                {
                    nt = s + 1;
                    if (t[v] > nt)
                    {
                        t[v] = nt;
                        pq.push({nt, v});
                    }
                }
            }
        }

        return -1;
    }
};