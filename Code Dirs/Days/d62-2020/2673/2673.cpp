// Link: https://leetcode.com/problems/make-costs-of-paths-equal-in-a-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1) extra (mutates cost in place)
// Approach: process internal nodes bottom-up (1-based heap indices n/2..1).
// At each node, the two child subtree-costs must be equalized: the number of
// +1 ops needed is their absolute difference. Then fold this node's own cost
// upward by adding max(left, right) subtree cost, so its parent sees the true
// (now-equalized) cost of the whole subtree rooted here.
class Solution {
public:
    int minIncrements(int n, vector<int>& cost) {
        int ops = 0;
        // process internal nodes from the deepest to the root (indices are 1-based in a heap layout)
        // internal nodes are those with children: indices 1..n/2
        for (int i = n / 2; i >= 1; --i) {
            int left = 2 * i, right = 2 * i + 1;
            ops += abs(cost[left - 1] - cost[right - 1]);
            // subtree cost from this node = its own cost + max of children's subtree costs
            cost[i - 1] += max(cost[left - 1], cost[right - 1]);
        }
        return ops;
    }
};
