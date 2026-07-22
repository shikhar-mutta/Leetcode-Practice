// Link: https://leetcode.com/problems/minimum-height-trees/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //   Approach:
    //    1. Use a queue to perform a topological sort on the tree.
    //    2. Start with all the leaves (nodes with degree 1) and remove them from the tree.
    //    3. Update the degree of their neighbors and add any new leaves to the queue.
    //    4. Repeat until there are at most 2 nodes left in the tree, which will be the centroids.
    //    5. Return the remaining nodes as the roots of the minimum height trees.
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        // Finding Tree Centroid
        if (n == 1)
            return {0};
        if (n == 2)
            return {0, 1};
        vector<int> deg(n, 0);
        vector<int> xor_sum(n, 0);

        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            deg[u]++;
            deg[v]++;
            xor_sum[u] ^= v;
            xor_sum[v] ^= u;
        }
        int q[n];
        int head = 0;
        int tail = 0;
        for (int i = 0; i < n; i++)
            if (deg[i] == 1)
                q[tail++] = i;

        int left = n;
        while (left > 2)
        {
            int leaves = tail - head;
            left -= leaves;
            for (int i = 0; i < leaves; i++)
            {
                int leaf = q[head++];
                int nbr = xor_sum[leaf];
                deg[nbr]--;
                xor_sum[nbr] ^= leaf;
                if (deg[nbr] == 1)
                    q[tail++] = nbr;
            }
        }
        vector<int> res;
        res.reserve(tail - head);
        for (int i = head; i < tail; i++)
            res.push_back(q[i]);
        return res;
    }
};