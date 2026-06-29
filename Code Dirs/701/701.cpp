// Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // TC: O(h). SC: O(h) for recursion stack.
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);
        if (val < root->val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};
