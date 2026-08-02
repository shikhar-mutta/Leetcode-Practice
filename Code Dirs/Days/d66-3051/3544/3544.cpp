// Link: https://leetcode.com/problems/subtree-inversion-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n): DFS traversal of the tree
// SC: O(n): for storing the adjacency list and other arrays
// Approach: The problem can be solved using a depth-first search (DFS) traversal of the tree. We can start from the root node and traverse the tree recursively. For each node, we can calculate the maximum and minimum values of the subtree rooted at that node. We can also keep track of the sum of the subtree rooted at that node. If we perform an operation on a node, we can invert the values of its subtree and update the maximum and minimum values accordingly. Finally, we can return the maximum value of the subtree rooted at the root node.

class Solution
{
public:
    using ll = long long;
    ll INF = 1'000'000'000'000;
    ll subtreeInversionSum(vector<vector<int>> &edges, vector<int> &nums,
                           int k)
    {
        int n = nums.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int> p(n, -1);
        vector<ll> sums(n);
        {
            auto fill_meta = [&](auto &&fill_meta, int v) -> void
            {
                sums[v] = nums[v];
                for (int u : adj[v])
                {
                    if (u != p[v])
                    {
                        p[u] = v;
                        fill_meta(fill_meta, u);
                        sums[v] += sums[u];
                    }
                }
            };
            fill_meta(fill_meta, 0);
        }
        vector<vector<int>> kthchildren(n);
        for (int i = 1; i < n; i++)
        {
            int par = i;
            bool to_be_added = true;
            for (int j = 1; j <= k; j++)
            {
                if (par == 0)
                {
                    to_be_added = false;
                    break;
                }
                par = p[par];
            }
            if (to_be_added)
                kthchildren[par].push_back(i);
        }

        // find the maximum and the minimum
        vector<ll> maxx(n, -INF);
        vector<ll> minn(n, INF);
        auto dfs = [&](auto &&dfs, int v) -> void
        {
            maxx[v] = nums[v];
            minn[v] = nums[v];
            // first do with no operation - children are free to do wver they
            // want
            for (int u : adj[v])
            {
                if (u == p[v])
                    continue;
                dfs(dfs, u);
                maxx[v] += maxx[u];
                minn[v] += minn[u];
            }

            // now do with operation
            ll maxx_with_op = -sums[v];
            ll minn_with_op = -sums[v];
            for (int u : kthchildren[v])
            {
                maxx_with_op += sums[u];
                minn_with_op += sums[u];
                maxx_with_op -= minn[u];
                minn_with_op -= maxx[u];
            }
            maxx[v] = max(maxx[v], maxx_with_op);
            minn[v] = min(minn[v], minn_with_op);
        };
        dfs(dfs, 0);
        return maxx[0];
    }
};