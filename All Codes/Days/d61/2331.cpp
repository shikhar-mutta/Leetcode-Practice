// Link: https://leetcode.com/problems/evaluate-boolean-binary-tree/description/

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

// TC: O(n), where n is the number of nodes in the tree.
// SC: O(h), where h is the height of the tree.
// Approach:
//  1. We use a recursive function to evaluate the tree.
//  2. If the current node is a leaf node, we return true if its value is 1, and false if its value is 0.
//  3. If the current node is an internal node, we recursively evaluate its left and right children.
//  4. If the current node's value is 2, we return the logical OR of the left and right children's evaluations. If the current node's value is 3, we return the logical AND of the left and right children's evaluations.
//  5. The final result is the evaluation of the root node.
class Solution
{
public:
    bool evaluateTree(TreeNode *root)
    {
        if (!root->left && !root->right)
            return root->val == 1;
        bool l = evaluateTree(root->left);
        bool r = evaluateTree(root->right);
        return root->val == 2 ? (l || r) : (l && r);
    }
};
