// Link: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of nodes in the tree.
// SC: O(n) where n is the number of nodes in the tree.
// Approach:
//   1. We will use a queue to perform a BFS traversal of the tree.
//   2. We will keep track of the number of children for each node and the XOR of the children for each node.
//   3. We will prune the tree by removing the leaves that do not have apples and their parents that become leaves after pruning.
//   4. We will keep track of the number of pruned nodes and return the total time taken to collect all apples in the tree, which is (n - pruned - 1) * 2, where n is the number of nodes in the tree and pruned is the number of pruned nodes.

struct Solution
{
    static constexpr int minTime(int n,
                                 const std::vector<std::vector<int>> &edges,
                                 const std::vector<bool> &hasApple)
    {
        if (n == 0)
            return 0;

        auto storage = std::make_unique<int[]>(n * 3);
        int *neighbour_xorsum = storage.get();
        int *neighbour_count = neighbour_xorsum + n;
        int *q_begin = neighbour_count + n;
        int *q_end = q_begin;
        for (const std::vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            ++neighbour_count[u];
            ++neighbour_count[v];
            neighbour_xorsum[u] ^= v;
            neighbour_xorsum[v] ^= u;
        }

        int pruned = 0;

        for (int i = 1; i != n; ++i)
        {
            if (neighbour_count[i] == 1 && !hasApple[i])
            {
                ++pruned;
                *q_end++ = i;
            }
        }

        while (q_begin != q_end)
        {
            int v = *q_begin++;
            int parent = neighbour_xorsum[v];
            neighbour_xorsum[parent] ^= v;
            if (--neighbour_count[parent] == 1 && parent != 0 &&
                !hasApple[parent])
            {
                ++pruned;
                *q_end++ = parent;
            }
        }

        return (n - pruned - 1) * 2;
    }
};