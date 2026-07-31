// Link: https://leetcode.com/problems/count-number-of-possible-root-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: We can use a BFS approach to traverse the tree and keep track of the number of correct guesses for each node. We can then use a DFS approach to traverse the tree and keep track of the number of correct guesses for each node. We can then return the number of nodes that have at least k correct guesses.
class Solution
{
public:
    int rootCount(vector<vector<int>> &edges, vector<vector<int>> &guesses,
                  int k)
    {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        set<pair<int, int>> guessSet;
        for (auto &g : guesses)
            guessSet.insert({g[0], g[1]});

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

        int base = 0;
        for (int v : order)
            if (parent[v] != -1 && guessSet.count({parent[v], v}))
                base++;

        vector<int> count(n, 0);
        count[0] = base;
        for (int u : order)
        {
            for (int v : adj[u])
            {
                if (v == parent[u])
                    continue;
                int c = count[u];
                if (guessSet.count({u, v}))
                    c--;
                if (guessSet.count({v, u}))
                    c++;
                count[v] = c;
            }
        }

        int ans = 0;
        for (int c : count)
            if (c >= k)
                ans++;
        return ans;
    }
};
