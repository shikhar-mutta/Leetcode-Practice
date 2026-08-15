// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/

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
    int idx = 0;
    TreeNode* build(vector<int>& preorder, int bound) {
        if (idx == (int)preorder.size() || preorder[idx] > bound) return nullptr;
        TreeNode* node = new TreeNode(preorder[idx++]);
        node->left = build(preorder, node->val);
        node->right = build(preorder, bound);
        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return build(preorder, INT_MAX);
    }
};
