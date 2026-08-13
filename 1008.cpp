// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    unordered_map<int, int> idx;
    int pre = 0;
    TreeNode *build(vector<int> &preorder, int lo, int hi)
    {
        if (lo > hi)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre++]);
        root->left = build(preorder, lo, idx[root->val] - 1);
        root->right = build(preorder, idx[root->val] + 1, hi);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        idx.clear();
        // pre is a member, so it keeps its value from any previous call —
        // without this reset a second call starts reading past the end of
        // preorder (out-of-bounds, builds a garbage tree)
        pre = 0;
        for (int i = 0; i < (int)inorder.size(); i++)
            idx[inorder[i]] = i;
        // cast to int: size() is unsigned, so an empty inorder would make
        // size()-1 wrap to a huge value instead of -1
        return build(preorder, 0, (int)inorder.size() - 1);
    }
    TreeNode *bstFromPreorder(vector<int> &preorder)
    {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());
        return buildTree(preorder, inorder);
    }
};
