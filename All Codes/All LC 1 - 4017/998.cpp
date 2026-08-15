// Link: https://leetcode.com/problems/maximum-binary-tree-ii/description/

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

// TC: O(n) where n is the number of nodes in the tree.
// SC: O(h) where h is the height of the tree.
// Approach:
// 1. We will check if the root is null or if the value to be inserted is greater than the root's value. If either condition is true, we will create a new node with the value to be inserted and set its left child to the current root. We will then return this new node as the new root of the tree.
// 2. If the value to be inserted is less than or equal to the root's value, we will recursively call the function on the right subtree of the current root. We will set the right child of the current root to the result of this recursive call and return the current root as the new root of the tree.
// 3. This process will continue until we find the appropriate position for the new value in the tree, maintaining the properties of a maximum binary tree.
class Solution
{
public:
    TreeNode *insertIntoMaxTree(TreeNode *root, int val)
    {
        if (!root || val > root->val)
        {
            TreeNode *node = new TreeNode(val);
            node->left = root;
            return node;
        }
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
};
