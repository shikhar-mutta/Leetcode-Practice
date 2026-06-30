// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

// TC: O(n), SC: O(n)
class Solution
{
    int idx;
    // Build the next subtree using upper bound; preorder is consumed via idx.
    TreeNode *build(vector<int> &pre, int bound)
    {
        if (idx == (int)pre.size() || pre[idx] > bound)
            return nullptr;
        TreeNode *root = new TreeNode(pre[idx++]);
        root->left = build(pre, root->val);
        root->right = build(pre, bound);
        return root;
    }

public:
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        idx = 0;
        return build(preorder, INT_MAX);
    }
};
