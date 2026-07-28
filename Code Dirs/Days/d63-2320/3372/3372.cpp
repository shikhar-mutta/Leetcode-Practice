// Link: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n1 + n2) SC: O(n1 + n2)
// Approach: Build adjacency lists for both trees, then use DFS to count the number of nodes within a certain distance from each node in both trees. For each node in the first tree, add the count of nodes within distance k from that node and the maximum count of nodes within distance k-1 from any node in the second tree.
class Solution
{
public:
    vector<vector<int>> build(vector<vector<int>> &edges)
    {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto &e : edges)
        {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return g;
    }

    int dfs(vector<vector<int>> &g, int u, int p, int d)
    {
        if (d < 0)
            return 0;
        int cnt = 1;
        for (int v : g[u])
        {
            if (v != p)
                cnt += dfs(g, v, u, d - 1);
        }
        return cnt;
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                               vector<vector<int>> &edges2, int k)
    {
        auto g1 = build(edges1);
        auto g2 = build(edges2);

        int n = g1.size(), m = g2.size();

        int best = 0;
        for (int i = 0; i < m; i++)
            best = max(best, dfs(g2, i, -1, k - 1));

        vector<int> ans(n);
        for (int i = 0; i < n; i++)
            ans[i] = dfs(g1, i, -1, k) + best;

        return ans;
    }
};