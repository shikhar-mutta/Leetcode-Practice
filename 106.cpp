// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> pos; // value -> index in inorder
        for (int i = 0; i < (int)inorder.size(); i++)
            pos[inorder[i]] = i;
        int post = (int)postorder.size() - 1; // postorder consumed right-to-left
        function<TreeNode *(int, int)> build = [&](int lo, int hi) -> TreeNode *
        {
            if (lo > hi)
                return nullptr;
            int rootVal = postorder[post--];
            TreeNode *node = new TreeNode(rootVal);
            int mid = pos[rootVal];
            node->right = build(mid + 1, hi); // right before left (postorder reversed)
            node->left = build(lo, mid - 1);
            return node;
        };
        return build(0, (int)inorder.size() - 1);
    }
};
