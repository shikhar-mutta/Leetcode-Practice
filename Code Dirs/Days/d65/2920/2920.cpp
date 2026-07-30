// Link: https://leetcode.com/problems/maximum-points-after-collecting-coins-from-all-nodes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * log(max(coins))), SC: O(n * log(max(coins)))
// Approach: We can use dynamic programming to find the maximum points we can collect from all nodes. We define a dp array where dp[i][h] represents the maximum points we can collect from the subtree rooted at node i with h halving operations left. We can use a BFS to get the parent-before-child order of the nodes and then iterate through the nodes in reverse order to fill the dp array. For each node, we can either take all the coins or take half of the coins and add the maximum points we can collect from its children. Finally, we return the value of dp[0][0] which represents the maximum points we can collect from the entire tree with no halving operations left.
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &edges, vector<int> &coins, int k)
    {
        int n = coins.size();
        const int MAXH = 14; // 10^4 < 2^14, so beyond this halving does nothing
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        // Iterative BFS to get parent-before-child order (avoids recursion
        // depth issues on a chain-shaped tree with n up to 1e5).
        vector<int> parent(n, -1), order;
        order.reserve(n);
        vector<bool> visited(n, false);
        vector<int> q = {0};
        visited[0] = true;
        for (int qi = 0; qi < (int)q.size(); qi++)
        {
            int u = q[qi];
            order.push_back(u);
            for (int v : adj[u])
                if (!visited[v])
                {
                    visited[v] = true;
                    parent[v] = u;
                    q.push_back(v);
                }
        }

        vector<array<int, 14>> dp(n);
        for (int i = order.size() - 1; i >= 0; i--)
        {
            int u = order[i];
            for (int h = 0; h < MAXH; h++)
            {
                int val = coins[u] >> h;
                long long takeAll = val - k;
                long long takeHalf = val / 2;
                for (int v : adj[u])
                {
                    if (v == parent[u])
                        continue;
                    takeAll += dp[v][h];
                    takeHalf += dp[v][min(h + 1, MAXH - 1)];
                }
                dp[u][h] = (int)max(takeAll, takeHalf);
            }
        }
        return dp[0][0];
    }
};
