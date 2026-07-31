// Link: https://leetcode.com/problems/find-number-of-coins-to-place-in-tree-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: post-order (BFS order reversed) DFS. For each subtree, keep a single merged
// candidate list of only the 2 smallest and 3 largest cost values seen (enough to determine the
// best product of 3, since two negatives paired with the largest positive can beat three
// positives) — merging children's already-trimmed candidate lists avoids double-counting any
// node. If subtree size < 3, coins = 1; else coins = max(0, product of top 3, product of the 2
// smallest * the largest).
class Solution
{
public:
    vector<long long> placedCoins(vector<vector<int>> &edges, vector<int> &cost)
    {
        int n = cost.size();
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), order;
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            order.push_back(u);
            for (int v : adj[u])
                if (!visited[v])
                {
                    visited[v] = true;
                    parent[v] = u;
                    q.push(v);
                }
        }

        vector<long long> ans(n, 0);
        vector<int> subSize(n, 1);
        vector<vector<long long>> cand(n); // up to 5 relevant values: 2 smallest + 3 largest

        for (int i = (int)order.size() - 1; i >= 0; i--)
        {
            int u = order[i];
            vector<long long> vals = {cost[u]};
            for (int v : adj[u])
            {
                if (v == parent[u])
                    continue;
                subSize[u] += subSize[v];
                for (long long x : cand[v])
                    vals.push_back(x);
            }
            sort(vals.begin(), vals.end());
            int m = vals.size();
            if (m <= 4)
            {
                cand[u] = vals;
            }
            else
            {
                cand[u] = {vals[0], vals[1], vals[m - 3], vals[m - 2], vals[m - 1]};
            }

            if (subSize[u] < 3)
            {
            ans[u] = 1;
            }
            else
            {
                int mm = vals.size();
                long long option1 = vals[mm - 1] * vals[mm - 2] * vals[mm - 3];
                long long option2 = vals[0] * vals[1] * vals[mm - 1];
                ans[u] = max(0LL, max(option1, option2));
            }
        }
        return ans;
    }
};
