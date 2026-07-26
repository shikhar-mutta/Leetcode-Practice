// Link: https://leetcode.com/problems/maximum-score-after-applying-operations-on-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) – single DFS visiting each node once
// SC: O(n) – adjacency list + recursion stack depth O(n) worst case
// Approach: Tree DP via DFS. Each node returns {subtreeSum, bestScore}.
// A node is "healthy" if its value is kept (not scored). At every non-leaf
// node we choose: (take) keep this node's value & score children optimally,
// or (leave) score this node & take the full subtree sum of all children.
// Leaf nodes (non-root) must be kept healthy → return {val, 0}.
// At each internal node: take = values[node] + sum(childScore),
//                        leave = sum(childSum).
// Return max(take, leave) as the node's best score to its parent.
class Solution
{
public:
    pair<long long, long long> dfs(int node, int par, vector<int> &values,
                                   vector<vector<int>> &adj)
    {
        long long subtreeSum = values[node];
        if (par != -1 && adj[node].size() == 1)
            return {subtreeSum, 0};

        long long take = values[node];
        long long leave = 0;

        for (auto it : adj[node])
        {
            if (it == par)
                continue;
            auto [childSum, childScore] = dfs(it, node, values, adj);
            subtreeSum += childSum;
            take += childScore;
            leave += childSum;
        }

        return {subtreeSum, max(take, leave)};
    }

    long long maximumScoreAfterOperations(vector<vector<int>> &edges,
                                          vector<int> &values)
    {
        int n = values.size();
        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        return dfs(0, -1, values, adj).second;
    }
};