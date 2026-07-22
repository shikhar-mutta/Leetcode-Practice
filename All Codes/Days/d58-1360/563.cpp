// Link: https://leetcode.com/problems/binary-tree-tilt/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// TC: O(n), SC: O(h) for recursion stack
// Approach:
//   1. We perform a depth-first search (DFS) traversal of the binary tree
//   2. For each node, we calculate the sum of values in its left and right subtrees using recursive calls to the dfs function.
//   3. We calculate the tilt of the current node as the absolute difference between the left and right subtree sums, and add it to the total tilt.
//   4. The dfs function returns the sum of values in the subtree rooted at the current node, which is used to calculate the tilt of its parent node.
//   5. The process continues until all nodes have been visited, and the final tilt value is returned as the result
class Solution
{
public:
    int tilt = 0;

    int findTilt(TreeNode *root)
    {
        dfs(root);
        return tilt;
    }

    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        tilt += abs(left - right);
        return left + right + node->val;
    }
};
