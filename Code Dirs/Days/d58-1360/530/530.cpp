// Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/

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

// TC: O(n), SC: O(h) where n is the number of nodes in the BST and h is the height of the BST
// Approach:
//  1. We perform an inorder traversal of the BST, which gives us the values of the nodes in sorted order.
//  2. During the traversal, we keep track of the previous node's value and calculate the absolute difference between the current node's value and the previous node's value.
//  3. We update the minimum difference whenever we find a smaller absolute difference.
//  4. Finally, we return the minimum difference found during the traversal.
class Solution
{
public:
    int minDiff = INT_MAX;
    int prev = -1;
    bool hasPrev = false;

    int getMinimumDifference(TreeNode *root)
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
