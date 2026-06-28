// Link: https://leetcode.com/problems/balanced-binary-tree/description/

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

// TC: O(n), SC: O(h) where h is the height of the tree. In worst case, h = n (skewed tree).
class Solution
{
public:
    // Returns height if balanced, -1 if any subtree is unbalanced.
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = height(root->left);
        if (l == -1)
            return -1;
        int r = height(root->right);
        if (r == -1)
            return -1;
        if (abs(l - r) > 1)
            return -1;
        return 1 + max(l, r);
    }
    bool isBalanced(TreeNode *root)
    {
        return height(root) != -1;
    }
};
