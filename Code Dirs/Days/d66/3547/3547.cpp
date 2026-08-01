// Link: https://leetcode.com/problems/maximum-sum-of-edge-values-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n): DFS traversal of the tree
// SC: O(n): for storing the adjacency list and other arrays
//  Approach: The problem can be solved using a depth-first search (DFS) traversal of the tree. We can start from the root node and traverse the tree recursively. For each node, we can calculate the maximum and minimum values of the subtree rooted at that node. We can also keep track of the sum of the subtree rooted at that node. If we perform an operation on a node, we can invert the values of its subtree and update the maximum and minimum values accordingly. Finally, we can return the maximum value of the subtree rooted at the root node.
class Solution
{
public:
    long long maxScore(int n, vector<vector<int>> &edges)
    {
        // n(n-1) + n(n-2) + (n-1)(n-3) + (n-2)(n-4) + (n-3)(n-5) + ... + 2

        long long ans = ((long long)n) * (n - 1);
        for (int i = 3; i <= n; i++)
        {
            ans += ((long long)i) * (i - 2);
        }
        if (edges.size() == n)
        {
            ans += 2;
        }
        return ans;
    }
};
