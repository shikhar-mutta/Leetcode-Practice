// Link: https://leetcode.com/problems/sum-of-distances-in-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: Use a flat array representation of the graph. First, compute the
//  size of each subtree and the sum of distances from the root to all nodes.
//  Then, reroot the tree at each node, using the previously computed values to
//  compute the sum of distances for the new root in O(1) time. The sum of distances for a child node can be computed from its parent's sum of distances by adding the number of nodes not in the child's subtree and subtracting the number of nodes in the child's subtree.

#pragma GCC optimize("O3,unroll-loops")
class Solution
{
    int edge_cnt = 0;

    void computeSizesAndRoot(int node, int parent, int height,
                             const vector<int> &head, const vector<int> &to,
                             const vector<int> &nxt, vector<int> &sub,
                             int &root_ans)
    {
        sub[node] = 1;
        root_ans += height;

        for (int e = head[node]; e != -1; e = nxt[e])
        {
            int cnode = to[e];
            if (cnode != parent)
            {
                computeSizesAndRoot(cnode, node, height + 1, head, to, nxt, sub,
                                    root_ans);
                sub[node] += sub[cnode];
            }
        }
    }

    void dfsReRoot(int u, int p, int n, const vector<int> &head,
                   const vector<int> &to, const vector<int> &nxt,
                   vector<int> &dp, const vector<int> &sub)
    {
        for (int e = head[u]; e != -1; e = nxt[e])
        {
            int v = to[e];
            if (v != p)
            {
                dp[v] = dp[u] + n - (2 * sub[v]);
                dfsReRoot(v, u, n, head, to, nxt, dp, sub);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges)
    {
        // Untie I/O operations for LeetCode execution environment
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Flat array graph representation
        vector<int> head(n, -1);
        vector<int> to(n * 2);
        vector<int> nxt(n * 2);

        for (const auto &p : edges)
        {
            int u = p[0];
            int v = p[1];

            // Add edge u -> v
            to[edge_cnt] = v;
            nxt[edge_cnt] = head[u];
            head[u] = edge_cnt++;

            // Add edge v -> u
            to[edge_cnt] = u;
            nxt[edge_cnt] = head[v];
            head[v] = edge_cnt++;
        }

        vector<int> sub(n, 0);
        vector<int> dp(n, 0);

        int root_ans = 0;
        computeSizesAndRoot(0, -1, 0, head, to, nxt, sub, root_ans);
        dp[0] = root_ans;

        dfsReRoot(0, -1, n, head, to, nxt, dp, sub);

        return dp;
    }
};