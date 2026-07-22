// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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

// TC: O(n), SC: O(h) where h is the height of the tree
// Approach:
//  1. Perform an inorder traversal of the BST to get the values in sorted order.
//  2. Keep track of the previous node's value and calculate the difference between the current node's value and the previous node's value.
//  3. Update the minimum difference if the current difference is smaller than the previously recorded minimum difference.
//  4. Return the minimum difference after traversing the entire tree.
class Solution
{
public:
    int minDiff = INT_MAX;
    int prev = -1;
    bool hasPrev = false;

    int minDiffInBST(TreeNode *root)
    {
        inorder(root);
        return minDiff;
    }

    void inorder(TreeNode *node)
    {
        if (!node)
            return;
        inorder(node->left);
        if (hasPrev)
            minDiff = min(minDiff, node->val - prev);
        prev = node->val;
        hasPrev = true;
        inorder(node->right);
    }
};
