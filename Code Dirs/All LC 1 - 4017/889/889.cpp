// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return build(preorder, 0, n - 1, postorder, 0, n - 1);
    }

private:
    TreeNode* build(vector<int>& pre, int preL, int preR, vector<int>& post, int postL, int postR) {
        if (preL > preR) return nullptr;
        TreeNode* root = new TreeNode(pre[preL]);
        if (preL == preR) return root;

        int leftRootVal = pre[preL + 1];
        int idx = postL;
        while (post[idx] != leftRootVal) idx++;
        int leftSize = idx - postL + 1;

        root->left = build(pre, preL + 1, preL + leftSize, post, postL, idx);
        root->right = build(pre, preL + leftSize + 1, preR, post, idx + 1, postR - 1);
        return root;
    }
};
