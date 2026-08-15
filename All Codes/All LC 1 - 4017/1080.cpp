// Link: https://leetcode.com/problems/insufficient-nodes-in-root-to-leaf-paths/description/

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
    // TC: O(n) where n is the number of nodes in the tree
    // SC: O(n) where n is the number of nodes in the tree
    //  Approach:
    //   1. We will use a recursive helper function to traverse the tree and check if the sum of the values from the root to the leaf is less than the limit.
    //   2. If the sum is less than the limit, we will delete the node and return nullptr.
    //   3. If the sum is greater than or equal to the limit, we will return the node.
    //   4. Finally, we will return the root of the tree after deleting the insufficient nodes.
    TreeNode *sufficientSubset(TreeNode *root, int limit)
    {
        if (!root)
            return nullptr;
        if (!root->left && !root->right)
        {
            return root->val < limit ? nullptr : root;
        }
        if (root->left)
            root->left = sufficientSubset(root->left, limit - root->val);
        if (root->right)
            root->right = sufficientSubset(root->right, limit - root->val);
        if (!root->left && !root->right)
            return nullptr;
        return root;
    }
};
