// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/description/

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
    unordered_set<TreeNode*> targets;

    TreeNode* dfs(TreeNode* node) {
        if (!node) return nullptr;
        if (targets.count(node)) return node;
        TreeNode* left = dfs(node->left);
        TreeNode* right = dfs(node->right);
        if (left && right) return node;
        return left ? left : right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
        targets = unordered_set<TreeNode*>(nodes.begin(), nodes.end());
        return dfs(root);
    }
};
