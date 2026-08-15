// Link: https://leetcode.com/problems/find-distance-in-a-binary-tree/description/

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
    TreeNode* lca(TreeNode* node, int p, int q) {
        if (!node) return nullptr;
        if (node->val == p || node->val == q) return node;
        TreeNode* left = lca(node->left, p, q);
        TreeNode* right = lca(node->right, p, q);
        if (left && right) return node;
        return left ? left : right;
    }

    int depth(TreeNode* node, int val, int d) {
        if (!node) return -1;
        if (node->val == val) return d;
        int left = depth(node->left, val, d + 1);
        if (left != -1) return left;
        return depth(node->right, val, d + 1);
    }

    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* ancestor = lca(root, p, q);
        int dp = depth(ancestor, p, 0);
        int dq = depth(ancestor, q, 0);
        return dp + dq;
    }
};
