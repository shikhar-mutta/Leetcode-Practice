// Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/

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
    int best = 0;
    void dfs(TreeNode* node, int lo, int hi) {
        if (!node) return;
        best = max({best, abs(node->val - lo), abs(node->val - hi)});
        lo = min(lo, node->val);
        hi = max(hi, node->val);
        dfs(node->left, lo, hi);
        dfs(node->right, lo, hi);
    }
public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, root->val, root->val);
        return best;
    }
};
