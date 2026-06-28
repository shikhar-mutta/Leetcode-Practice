// Link: https://leetcode.com/problems/symmetric-tree/description/

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
    // TC: O(n), SC: O(h)
    bool mirror(TreeNode *a, TreeNode *b)
    {
        if (!a && !b)
            return true;
        if (!a || !b || a->val != b->val)
            return false;
        return mirror(a->left, b->right) && mirror(a->right, b->left);
    }
    bool isSymmetric(TreeNode *root)
    {
        return !root || mirror(root->left, root->right);
    }
};
