// Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

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

// TC: O(n) where n is the number of nodes in the tree
// SC: O(h) where h is the height of the tree for the recursion stack
//  Approach:
//  1. We can use a depth-first search (DFS) approach to traverse the tree in reverse in-order (right, root, left).
//  2. We can maintain a running sum of the node values as we traverse the tree.
//  3. For each node, we can update its value to the running sum and then add its original value to the running sum.
//  4. Finally, we can return the root of the modified tree.
class Solution
{
    int sum = 0;

    void dfs(TreeNode *node)
    {
        if (!node)
            return;
        dfs(node->right);
        sum += node->val;
        node->val = sum;
        dfs(node->left);
    }

public:
    TreeNode *bstToGst(TreeNode *root)
    {
        sum = 0;
        dfs(root);
        return root;
    }
};
