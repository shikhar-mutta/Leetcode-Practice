// Link: https://leetcode.com/problems/binary-tree-pruning/description/

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

class Solution
{
public:
    // TC: O(N) SC: O(H)
    //   Approach:
    //   1. We can use a recursive approach to solve this problem. We can start from the root of the tree and check if the left and right child of each node are null. If they are null and the value of the node is 0, we can return null. We can then recursively call the function on the left and right child of the node. We can continue this process until we reach the leaf nodes of the tree. Finally, we can return the root of the pruned tree.
    //   2. We can use a queue to perform a level order traversal of the tree. We can start from the root of the tree and check if the left and right child of each node are null. If they are null and the value of the node is 0, we can return null. We can then add the left and right child of the node to the queue and continue this process until we reach the leaf nodes of the tree. Finally, we can return the root of the pruned tree.
    TreeNode *pruneTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (!root->left && !root->right && root->val == 0)
            return nullptr;
        return root;
    }
};
