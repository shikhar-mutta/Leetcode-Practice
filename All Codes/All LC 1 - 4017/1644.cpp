// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/description/

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
    bool foundP = false, foundQ = false;

    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q) {
        if (!node) return nullptr;
        TreeNode* left = dfs(node->left, p, q);
        TreeNode* right = dfs(node->right, p, q);
        if (node == p) foundP = true;
        if (node == q) foundQ = true;
        if (node == p || node == q) return node;
        if (left && right) return node;
        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res = dfs(root, p, q);
        if (foundP && foundQ) return res;
        return nullptr;
    }
};
