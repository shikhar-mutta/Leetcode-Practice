// Link: https://leetcode.com/problems/balance-a-binary-search-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void inorder(TreeNode* node, vector<int>& vals) {
        if (!node) return;
        inorder(node->left, vals);
        vals.push_back(node->val);
        inorder(node->right, vals);
    }

    TreeNode* build(vector<int>& vals, int lo, int hi) {
        if (lo > hi) return nullptr;
        int mid = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left = build(vals, lo, mid - 1);
        node->right = build(vals, mid + 1, hi);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> vals;
        inorder(root, vals);
        return build(vals, 0, (int)vals.size() - 1);
    }
};
