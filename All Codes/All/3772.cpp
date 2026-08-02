// Link: https://leetcode.com/problems/maximum-subgraph-score-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
//  Approach: The score of a subgraph is the sum of the values of its nodes multiplied by the number of edges in the subgraph. To maximize the score, we want to include as many nodes as possible while minimizing the number of edges. We can use a greedy approach to achieve this. We start by initializing the degree of each node and the parent of each node. We then iterate through the nodes and for each node, we check if it is a leaf node (degree 1). If it is, we add it to the queue and update its parent's degree and parent pointer.
const int N = 1e5;
int pa[N], deg[N], q[N];

class Solution
{
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>> &es, vector<int> &dp)
    {
        memset(pa, 0, sizeof(int) * n), memset(deg, 0, sizeof(int) * n);

        deg[0] = 2; // Prevent root from entering queue too early
        for (auto &e : es)
        {
            int a = e[0], b = e[1];
            deg[a]++, deg[b]++;
            pa[a] ^= b, pa[b] ^= a;
        }
        for (int i = 0; i < n; ++i)
            dp[i] = (dp[i] << 1) - 1; // Map 0 -> -1, 1 -> 1

        int qi = 0;
        for (int s = 0; s < n; ++s)
        {
            // Use XOR property to dynamically remove child and point to grand-parent in the loop update
            for (int i = s, p; deg[i] == 1; pa[p] ^= i, --deg[p], i = p)
            {
                q[qi++] = i;
                deg[i] = 0;
                p = pa[i];
                if (dp[i] > 0)
                    dp[p] += dp[i];
            }
        }

        while (qi--)
        {
            int i = q[qi];
            // Add parent contribution (excluding self impact)
            dp[i] += max(0, dp[pa[i]] - max(0, dp[i]));
        }
        return dp;
    }
};
