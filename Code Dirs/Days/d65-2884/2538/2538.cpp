// Link: https://leetcode.com/problems/difference-between-maximum-and-minimum-price-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: The problem is to find the maximum difference between the sum of prices of two paths in a tree. We can use depth-first search (DFS) to traverse the tree and calculate the maximum and minimum path sums for each node. We maintain two values for each node: the maximum path sum that includes the node and the maximum path sum that does not include the node. We update the global answer with the maximum difference found during the traversal.
class Solution
{
public:
    long long ans = 0;
    vector<vector<int>> g;
    vector<int> price;

    pair<long long, long long> dfs(int node, int parent)
    {
        long long withLeaf = price[node];
        long long withoutLeaf = 0;
        for (int nbr : g[node])
        {
            if (nbr == parent)
                continue;
            auto [childWithLeaf, childWithoutLeaf] = dfs(nbr, node);
            ans = max(ans, withLeaf + childWithoutLeaf);
            ans = max(ans, withoutLeaf + childWithLeaf);
            withLeaf = max(withLeaf, childWithLeaf + price[node]);
            withoutLeaf = max(withoutLeaf, childWithoutLeaf + price[node]);
        }
        return {withLeaf, withoutLeaf};
    }

    long long maxOutput(int n, vector<vector<int>> &edges,
                        vector<int> &price_)
    {
        price = price_;
        g.resize(n);
        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(0, -1);
        return ans;
    }
};
