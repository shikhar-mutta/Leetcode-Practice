// Link: https://leetcode.com/problems/find-weighted-median-node-in-tree/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(nlogn + qlogn)
//SC: O(n)
//Approach: Binary Lifting + DFS
// 1. We can use binary lifting to find the LCA of two nodes in O(logn) time.
// 2. We can use DFS to find the depth and path sum of each node in O(n) time.
// 3. For each query, we can find the LCA of the two nodes and the total path sum between them.
// 4. We can then use binary lifting to find the node x that minimizes the maximum path sum from u to x and v to x. 
// 5. The answer for each query is the node x that minimizes the maximum path sum from u to x and v to x.
// 6. If there are multiple nodes that minimize the maximum path sum, we can return any of them.
// 7. If u == v, we can return u as the answer.
class Solution
{
public:
    vector<int> findMedian(int n, vector<vector<int>> &edges,
                           vector<vector<int>> &queries)
    {

        vector<vector<pair<int, int>>> adj(n);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1], w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        int Log = 31 - __builtin_clz(n); // �
        vector<int> up((Log + 1) * n, -1);
        vector<long> pathSum(n), depth(n);

        auto dfs = [&](this auto &&dfs, int u, int p) -> void
        {
            for (auto [v, w] : adj[u])
            {
                if (v == p)
                    continue;
                pathSum[v] = pathSum[u] + w;
                depth[v] = depth[u] + 1;
                up[v] = u;
                dfs(v, u);
            }
        };
        pathSum[0] = 0;
        depth[0] = 0;
        dfs(0, -1);

        for (int j = 1; j <= Log; j++)
        {
            for (int i = 0; i < n; i++)
            {
                int idx = j * n + i;
                int p = up[idx - n]; // (j-1)*n + i;
                if (p != -1)
                    up[idx] =
                        up[(j - 1) * n + p]; // up[j][i] = up[j-1][up[j-1][i]]
            }
        }

        auto LCA = [&](int a, int b)
        {
            if (depth[a] < depth[b])
                swap(a, b);
            int k = depth[a] - depth[b];
            while (k > 0)
            {
                int lg = 31 - __builtin_clz(k);
                a = up[lg * n + a];
                k -= 1 << lg;
            }
            if (a == b)
                return a;
            for (int j = 31 - __builtin_clz(depth[b]); j >= 0; j--)
            {
                if (up[j * n + a] != up[j * n + b])
                {
                    a = up[j * n + a];
                    b = up[j * n + b];
                }
            }
            return up[a];
        };

        vector<int> ans;
        ans.reserve(queries.size());
        for (auto &q : queries)
        {
            int u = q[0], v = q[1];
            if (u == v)
            {
                ans.push_back(u);
                continue;
            }

            int lca = LCA(u, v);
            long ttl = pathSum[u] + pathSum[v] - pathSum[lca] * 2;

            if (pathSum[u] >= pathSum[v])
            { // node x is in path from u <-> LCA
                int A = u;
                for (int j = 31 - __builtin_clz(depth[u] - depth[lca]); j >= 0;
                     j--)
                {
                    int p = up[j * n + A]; // up[j][A]
                    if (p == -1)
                        continue;
                    long sum = pathSum[u] - pathSum[p];
                    if (sum * 2 < ttl)
                        A = p;
                }
                ans.push_back(up[A]);
            }
            else
            { // pathSum[u] < pathSum[v] -> node x is in path from LCA ->
              // V
                int A = v;
                for (int j = 31 - __builtin_clz(depth[v] - depth[lca]); j >= 0;
                     j--)
                {
                    int p = up[j * n + A];
                    if (p == -1)
                        continue;
                    long sum = pathSum[v] - pathSum[p];
                    if (sum * 2 <= ttl)
                        A = p;
                }
                ans.push_back(A);
            }
        }

        return ans;
    }
};