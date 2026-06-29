// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/

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
    // TC: O(n), SC: O(n)
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> pos; // value -> index in inorder
        for (int i = 0; i < (int)inorder.size(); i++)
            pos[inorder[i]] = i;
        int pre = 0;
        function<TreeNode *(int, int)> build = [&](int lo, int hi) -> TreeNode *
        {
            if (lo > hi)
                return nullptr;
            int rootVal = preorder[pre++];
            TreeNode *node = new TreeNode(rootVal);
            int mid = pos[rootVal];
            node->left = build(lo, mid - 1);
            node->right = build(mid + 1, hi);
            return node;
        };
        return build(0, (int)inorder.size() - 1);
    }
};
